#include "EnemyEncounter.h"
#include "Enemy.h"
#include "iostream"
#include "Utility.h"
#include "UIManager.h"
#include "Player.h"
#include <algorithm>





EnemyEncounter::EnemyEncounter(Player* player, std::vector < std::string > lines, std::vector<std::unique_ptr<Enemy>> enemiesInEncounter, float escapeChance) 
	: Encounter(player, lines), enemies(std::move(enemiesInEncounter))
{
	currentState = EncounterState::PlayerTurn;
	thePlayer = player;
	escapeChance = escapeChance;
}

bool EnemyEncounter::InitiateEncounter()
{
	CalculateExp();
	DisplayNextEncounterText();
	IntroduceEnemies();
	BattleLoop();
	if (currentState == EncounterState::BattleLost) return false;
	return true;
}

void EnemyEncounter::IntroduceEnemies()
{
	std::string introText = "Prepare yourself, enemies are approaching!";
	Utility::PrintToConsole(true, introText);
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->DisplayEnemyInfo();
	}
}

void EnemyEncounter::BattleLoop()
{
	
	while (true)
	{
		switch (currentState) {
		case EncounterState::PlayerTurn:
		{
			EnumWrapper<BattleOptions>choice = PresentBattleOptions();
			TakePlayerAction(choice);
			break;
		}
		case EncounterState::EnemyTurn:
			TakeEnemyActions();
			break;
		case EncounterState::BattleEscaped:
			return;
		case EncounterState::BattleLost:
			return;
		case EncounterState::BattleWon:
			PresentExpReward();
			return;
		}
	}
	
}

void EnemyEncounter::TakeEnemyActions()
{
	std::vector<ITargetable*> selfList;
	std::vector<ITargetable*> targets;
	targets.push_back(thePlayer);

	for (int i = 0; i < enemies.size(); i++)
	{
		if (thePlayer->IsDead())
		{
			currentState = EncounterState::BattleLost;
			break;
		}
		Enemy* enemy = enemies[i].get();
		selfList.push_back(enemy);
		
		const Attack& attack = enemy->ChooseAttack();
		if (Utility::TestAgainstProb(attack.GetHitChance()))
		{
			Utility::PrintToConsole(true, enemy->GetSpecies(), " performs ", std::get<EnumWrapper<EnemyAttackTypes>>(attack.GetAttackType()));
			for (auto attributeTuple : attack.GetAttributes())
			{
				AttackAttributes attribute = std::get<0>(attributeTuple).get();
				Target target = std::get<1>(attributeTuple).get();
				float value = std::get<2>(attributeTuple);
				switch (attribute)
				{
				case AttackAttributes::Damage:
					if (target == Target::self)
					{
						HandleDamage(selfList, attack.GetDamage(thePlayer->GetStats(), value));
					}
					else {
						HandleDamage(targets, attack.GetDamage(thePlayer->GetStats(), value));
					}
					break;
				case AttackAttributes::Heal:
					if (target == Target::self)
					{
						HandleHeal(selfList, attack.GetDamage(thePlayer->GetStats(), value));
					}
					else
					{
						HandleHeal(targets, attack.GetDamage(thePlayer->GetStats(), value));
					}
				default:
					break;
				}
			}
			
		}
		else 
		{
			Utility::PrintToConsole(true, enemy->GetSpecies(), " tries to perform ", std::get<EnumWrapper<EnemyAttackTypes>>(attack.GetAttackType()), ", but misses...");
		}
		selfList.clear();
	}
	if (enemies.size() > 0)
	{
		currentState = EncounterState::PlayerTurn;
	}
	else 
	{
		currentState = EncounterState::BattleWon;
	}
}

void EnemyEncounter::CalculateExp()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		expReward += enemies[i]->GetExpAwarded();
	}
}

void EnemyEncounter::PresentExpReward()
{
	thePlayer->GainExp(expReward);
}



EnumWrapper<BattleOptions> EnemyEncounter::PresentBattleOptions()
{
	Utility::PrintToConsole(true, "Choose your action!");
	std::vector<EnumWrapper<BattleOptions>> potentialActions = EnumWrapper<BattleOptions>::getAllValues();
	UIManager* ui = UIManager::GetInstance();
	return ui->Choose4Options(potentialActions[0], potentialActions[1], potentialActions[2], potentialActions[3]);
	
}

void EnemyEncounter::TakePlayerAction(EnumWrapper<BattleOptions> playerChoice)
{

	switch (playerChoice.get()) {
	case BattleOptions::UseItem:
		Utility::PrintToConsole(true, "Which item from your inventory will you use?");
		HandleItem(ChooseItem());
		break;  // Exits the switch statement
	case BattleOptions::Fight:
		Utility::PrintToConsole(true, "Which attack will you perform?");
		HandlePlayerAttack(ChooseAttack());
		currentState = EncounterState::EnemyTurn;
		break;
	case BattleOptions::AttemptToRun:
		TryEscape();
		break;
	case BattleOptions::CheckCharacter:
		thePlayer->PrintAllCharacterInfo();
		SetEncounterState(EncounterState::PlayerTurn);
		break;
	}
}

void EnemyEncounter::HandleItem(Item* item)
{

	switch (item->GetItemType())
	{
	default:
		break;
	}
	thePlayer->ItemUsed(item);
}


void EnemyEncounter::HandleDamage(std::vector<ITargetable*>& targets, float amount)
{
	for (auto target : targets)
	{
		if (target->TakeDamage(amount))
		{
			try {
				Enemy* enemyRef = dynamic_cast<Enemy*>(target);
				
				auto it = std::find_if(enemies.begin(), enemies.end(),
					[&enemyRef](const std::unique_ptr<Enemy>& e)
					{
						return e.get() == enemyRef;
					});
				
				if (it != enemies.end()) {
					enemies.erase(it);
				}

				auto itTarget = std::find(targets.begin(), targets.end(), target);
				targets.erase(itTarget);
			}
			catch (const std::bad_cast& e)
			{
				// player is being damaged
			}
		}
	}
}

void EnemyEncounter::HandlePlayerAttack(Attack attack)
{
	int attackTargets = attack.GetNumTargets();
	std::vector<ITargetable*> selfList;
	selfList.push_back(thePlayer);

	std::vector<ITargetable*> targets;
	if (attackTargets != 0)
	{
		
		size_t numTargets = std::min((int)enemies.size(), attackTargets);
		Utility::PrintToConsole(true, "Choose your targets!");
		// make a vector of enumWrappers with their indices corresponding to the indices in the enemy vector
		std::vector<EnumWrapper<EnemySpecies>> enemyEnums;
		std::unordered_map<EnumWrapper<EnemySpecies>*, int> references;
		for (int i = 0; i < enemies.size(); i++)
		{
			enemyEnums.push_back(enemies[i]->GetSpecies());
			references[&enemyEnums[i]] = i;
		}
		std::vector<EnumWrapper<EnemySpecies>*> chosenTargetsEnums = UIManager::GetInstance()->ChooseMultipleOptionsRef(enemyEnums, numTargets);
		for (int i = 0; i < chosenTargetsEnums.size(); i++)
		{
			targets.push_back(enemies[references[chosenTargetsEnums[i]]].get());
		}
	}

	
	// check if the attack succeeds
	float hitChance = attack.GetHitChance();
	if (!Utility::TestAgainstProb(hitChance))
	{
		Utility::PrintToConsole(true, thePlayer->getName(), " tries to perform ", std::get<EnumWrapper<PlayerAttackTypes>>(attack.GetAttackType()), ", but fails...");
		return;
	}

	Utility::PrintToConsole(true, thePlayer->getName(), " performs ", std::get<EnumWrapper<PlayerAttackTypes>>(attack.GetAttackType()));
	// point of seperation between attack being performed an its effects
	
	for (auto attributeTuple : attack.GetAttributes())
	{
		AttackAttributes attribute = std::get<0>(attributeTuple).get();
		Target target = std::get<1>(attributeTuple).get();
		float value = std::get<2>(attributeTuple);
		switch (attribute)
		{
		case AttackAttributes::Damage:
			if (target == Target::self)
			{
				HandleDamage(selfList, attack.GetDamage(thePlayer->GetStats(), value));
			}
			else {
				HandleDamage(targets, attack.GetDamage(thePlayer->GetStats(), value));
			}
			break;
		case AttackAttributes::Heal:
			if (target == Target::self)
			{
				HandleHeal(selfList ,attack.GetDamage(thePlayer->GetStats(), value));
			}
			else 
			{
				HandleHeal(targets, attack.GetDamage(thePlayer->GetStats(), value));
			}
		default:
			break;
		}
	}
}


void EnemyEncounter::HandleHeal(std::vector<ITargetable*>& targets, float amount)
{
	for (auto target : targets)
	{
		target->Heal(amount);
	}
}



// these choice functions could probably me made a template
Attack EnemyEncounter::ChooseAttack()
{
	const std::vector<Attack>& playerAttacks = thePlayer->GetAttacks();
	std::vector<EnumWrapper<PlayerAttackTypes>> options;
	std::unordered_map<PlayerAttackTypes, int> references;
	// I just realized that it would be so much easier to have a enum-to-string mapping in the types I know I will have to represent as choices
	for (int i = 0; i < playerAttacks.size(); i++)
	{
		references[std::get<0>(playerAttacks[i].GetAttackType()).get()] = i;
		options.push_back(std::get<0>(playerAttacks[i].GetAttackType()));
	}
	EnumWrapper<PlayerAttackTypes> chosenAttack = UIManager::GetInstance()->ChooseOptions(options);
	return playerAttacks[references[chosenAttack.get()]];
}

Item* EnemyEncounter::ChooseItem() 
{
	std::vector<Item*>* playerInventory = thePlayer->playerInventory;
	std::vector<EnumWrapper<ItemTypes>> options;
	std::unordered_map<ItemTypes, Item*> references;
	for (Item* item : *playerInventory)
	{
		EnumWrapper<ItemTypes> wrapper(item->GetItemType());
		references[wrapper.get()] = item; // also ensure unique pointer doesn't go out of scope
		options.push_back(wrapper);
		
	}
	EnumWrapper<ItemTypes> itemChoiceWrapper = UIManager::GetInstance()->ChooseOptions(options);
	Item* chosenItem = references[itemChoiceWrapper.get()];
	
	return chosenItem;

}

void EnemyEncounter::TryEscape()
{
	Utility::PrintToConsole(true, thePlayer->getName(), " tries to escape");
	Utility::Wait(500);
	Utility::PrintToConsole(true, " their chance of escaping this encounter is ", escapeChance);
	Utility::PrintToConsole(false, " their attempt .");
	Utility::Wait(1);
	Utility::PrintToConsole(false, " .");
	Utility::Wait(1);
	Utility::PrintToConsole(false, " .");
	Utility::Wait(1);
	if (Utility::TestAgainstProb(escapeChance))
	{
		Utility::PrintToConsole(true, " succeeds!!");
		Utility::PrintToConsole(true, "The encounter was escaped");
		SetEncounterState(EncounterState::BattleEscaped);
	}
	else
	{
		Utility::PrintToConsole(true, " fails");
		SetEncounterState(EncounterState::EnemyTurn);
	}
}


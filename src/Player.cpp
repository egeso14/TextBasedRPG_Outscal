#include "Player.h"
#include "Utility.h"
#include "AttackFactory.h"

std::unordered_map<PlayerClasses, std::unordered_map<int, PlayerAttackTypes>> Player::attacksToLearn =
{
	 { PlayerClasses::Archer, {
		{2, PlayerAttackTypes::DrainingShot},
		{5, PlayerAttackTypes::DelayedShot},
		{8, PlayerAttackTypes::HeadShot}
	}},
	{ PlayerClasses::Warrior, {
		{3, PlayerAttackTypes::Whirlwind},
		{6, PlayerAttackTypes::Tackle},
		{8, PlayerAttackTypes::ChallangeDeath}
	}},
	{ PlayerClasses::Wizard, {
		{2, PlayerAttackTypes::EnhanceSpell},
		{4, PlayerAttackTypes::Eruption},
		{7, PlayerAttackTypes::FireLash}
	}},
	{ PlayerClasses::Paladin, {
		{3, PlayerAttackTypes::Protect},
		{6, PlayerAttackTypes::Smite},
		{8, PlayerAttackTypes::Denounce}
	}}
};

std::unordered_map<PlayerClasses, std::vector<PlayerAttackTypes>> Player::startingAttacks = {
	{ PlayerClasses::Archer,  { PlayerAttackTypes::AimShot, PlayerAttackTypes::SpreadShot } },
	{ PlayerClasses::Warrior, { PlayerAttackTypes::Rage, PlayerAttackTypes::OverheadSlash } },
	{ PlayerClasses::Wizard,  { PlayerAttackTypes::ColdSnap, PlayerAttackTypes::Jolt } },
	{ PlayerClasses::Paladin, { PlayerAttackTypes::Heal, PlayerAttackTypes::Pummel } }
};

std::unordered_map<int, float> Player::levelUpThresholds = {
	{ 1, 20 },
	{ 2, 30 },
	{ 3, 45 },
	{ 4, 60 },
	{ 5, 70 },
	{ 6, 85 },
	{ 7, 100 },
	{ 8, 120 },
	{ 9, 140 },
};

Player::Player(EnumWrapper<PlayerClasses> classChoice, std::string playerName)
{
	name = playerName;
	chosenClass = classChoice;
	currentExp = 0;
	currentLevel = 1;
	stats = new StatSheet(classChoice.get());
	LearnStartingAttacks();
}


void Player::RecalculateStats()
{

}

void Player::LearnStartingAttacks()
{
	for (PlayerAttackTypes startingAttack : startingAttacks[chosenClass.get()])
	{
		knownAttacks.push_back(*AttackFactory::CreateAttack(startingAttack));
	}
}

bool Player::IsDead()
{
	if (stats->currentHP <= 0)
	{
		return true;
	}
	return false;
}

void Player::Equip(Equipment* eq)
{
	EquipmentSlots slot = eq->GetEquipSlot();
	if (equipped.find(slot) != equipped.end())
	{
		Unequip(equipped[slot]);
	}
	equipped[slot] = eq;
	eq->AddModifiers(stats);
}

void Player::Unequip(Equipment* eq)
{
	equipped.erase(eq->GetEquipSlot());
	eq->RemoveModifiers(stats);
}

void Player::PrintEquipmentInfo()
{
	Utility::PrintToConsole(true, "Currently equipped:");
	Utility::PrintToConsole(true, "");
	for (auto itr = equipped.begin(); itr != equipped.end(); ++itr)
	{
		Equipment* e = itr->second;
		e->PrintInfo();
	}
}

void Player::RemoveFromInventory(Item* item)
{
	
	for (auto itr = (*playerInventory).begin(); itr != (*playerInventory).end(); ++itr)
	{
		if (item == *itr)
		{
			(*playerInventory).erase(itr);
			delete item;
		}
	}
	return;
}

void Player::ItemUsed(Item* item)
{
	item->DecrementUses();
	if (item->GetUsesLeft() == 0)
	{
		RemoveFromInventory(item);
	}
}

void Player::LearnAttack(PlayerAttackTypes type)
{
	Attack* newAttack = AttackFactory::CreateAttack(type);
	bool duplicate = false;
	for (Attack attack : knownAttacks)
	{
		if (std::get<0>(newAttack->GetAttackType()).get() == std::get<0>(attack.GetAttackType()).get())
		{
			duplicate = true;
		}
	}
	if (duplicate)
	{
		Utility::PrintToConsole(true, "You already know this attack!");
		return;
	}
	knownAttacks.push_back(*newAttack);
	delete newAttack;
}

void Player::PrintStats()
{
	
	Utility::PrintToConsole(true, "HP: max(", stats->baseHP, "+", stats->currentMaxHP - stats->baseHP, "), current(", stats->currentHP, ")");
	Utility::PrintToConsole(true, "Atk: max(", stats->baseAtk, "+", stats->currentMaxAtk - stats->baseAtk, "), current(", stats->currentAtk, ")");
	Utility::PrintToConsole(true, "Def: max(", stats->baseDef, "+", stats->currentMaxDef - stats->baseDef, "), current(", stats->currentDef, ")");

}

void Player::PrintAttackInfo()
{
	Utility::PrintToConsole(true, "Character Attacks");
	Utility::PrintToConsole(true, "");
	for (int i = 0; i < knownAttacks.size(); i++)
	{
		knownAttacks[i].PrintAttackInfo();
	}
	Utility::PrintToConsole(true, "Weapon Attacks");
	Utility::PrintToConsole(true, "");
	if (weaponAttack)
	{
		weaponAttack->PrintAttackInfo();
	}
}

void Player::GainExp(int exp)
{
	
	if (currentLevel < 10)
	{
		currentExp += exp;
		Utility::PrintToConsole(true, "Gained ", exp, " exp.");
		if (levelUpThresholds[currentLevel] <= currentExp)
		{
			currentExp = currentExp - levelUpThresholds[currentLevel];
			currentLevel++;
			OnLevelUp(currentLevel);
		}
	}
}

void Player::OnLevelUp(int level)
{
	Utility::PrintToConsole(true, "Your level increased to ", level, "!");
	if (attacksToLearn[chosenClass.get()].find(level) != attacksToLearn[chosenClass.get()].end())
	{
		Attack* newAttack = AttackFactory::CreateAttack(attacksToLearn[chosenClass.get()][level]);
		knownAttacks.push_back(*newAttack);
		Utility::PrintToConsole(false, "You gained a new attack: ");
		newAttack->PrintAttackInfo();
		delete newAttack;
	}
	
}

void Player::PrintAllCharacterInfo()
{
	Utility::PrintToConsole(true, name, ": Lv. ", currentLevel, " ", chosenClass);
	PrintStats();
	PrintEquipmentInfo();
	PrintAttackInfo();
}

bool Player::TakeDamage(float damage)
{
	float damageAfterMitigation = (1 - stats->currentDef / 100) * damage;
	stats->currentHP -= damageAfterMitigation;
	if (stats->currentHP <= 0)
	{
		Utility::PrintToConsole(true, name, " takes ", damageAfterMitigation, " damage, and is knocked out...");
		return true;
	}
	Utility::PrintToConsole(true, name, " takes ", damageAfterMitigation, " damage! Remaining health: ", stats->GetStat(Stats::HP), "/", stats->GetMaxStat(Stats::HP));
	return false;
}

void Player::Heal(float healAmount)
{
	float healedHealth = std::min(stats->currentMaxHP - stats->currentHP, healAmount);
	stats->currentHP += healedHealth;
	Utility::PrintToConsole(true, name, " was healed for ", healedHealth, " | CurrentHP: ", stats->currentHP, "/", stats->currentMaxHP);
}



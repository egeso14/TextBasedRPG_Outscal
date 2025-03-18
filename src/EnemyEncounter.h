#pragma once
#include "Encounter.h"
#include "Enemy.h"
#include "BattleOptions.h"
#include "EnumWrapper.h"
#include "Item.h"
#include <vector>

enum class EncounterState {
	PlayerTurn,
	EnemyTurn,
	BattleWon,
	BattleEscaped,
	BattleLost
};


class EnemyEncounter : Encounter
{
public:
	EnemyEncounter(Player* player, std::vector<std::string> lines, std::vector<std::unique_ptr<Enemy>> enemiesInEncounter, float escapeChance);
	bool InitiateEncounter() override;
private:
	std::vector<std::unique_ptr<Enemy>> enemies; // up to 4 enemies per encounter
	EncounterState currentState;
	Player* thePlayer;
	float escapeChance;
	int expReward;
	
	void IntroduceEnemies();
	void BattleLoop();
	EnumWrapper<BattleOptions> PresentBattleOptions();
	void TakePlayerAction(EnumWrapper<BattleOptions> playerChoice);
	Item* ChooseItem();
	void HandleItem(Item* item);
	Attack ChooseAttack();
	
	inline void SetEncounterState(EncounterState newState) { currentState = newState; }
	void TryEscape();
	void TakeEnemyActions();
	void CalculateExp();
	void PresentExpReward();
	void HandlePlayerAttack(Attack attack);
	
	
	
	void HandleHeal(std::vector<ITargetable*>& targets, float healAmount);
	void HandleDamage(std::vector<ITargetable*>& targets, float damage);
	//void HandleStatChange(std::vector<ITargetable*>& targets, )

	
};


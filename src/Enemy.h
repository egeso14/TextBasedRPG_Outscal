#pragma once
#include "EnemySpecies.h"
#include "EnumWrapper.h"
#include "ITargetable.h"
#include "Attack.h"
#include <memory>
#include <unordered_map>

class Enemy: public ITargetable {

public:
	Enemy(EnemySpecies species);
	void DisplayEnemyInfo();
	EnumWrapper<EnemySpecies> GetSpecies() { return *species; }
	int GetLevel() { return level; }
	int GetExpAwarded() { return exp_awarded; }
	bool TakeDamage(float damage);
	void Heal(float healAmount);
	std::string GetReaminingHealthString();
	const StatSheet& GetStats() const { return *stats; }
	const Attack& ChooseAttack();
	void InflictCondition(Condition* condition) {} ;
	void UpdateConditions() {} ;
	~Enemy();
		
private:
	static std::unordered_map<EnemySpecies, float> maxHealthPerSpecies;
	static std::unordered_map<EnemySpecies, int> expAwardedPerSpecies;
	static std::unordered_map<EnemySpecies, std::vector<EnemyAttackTypes>> attackTypePerSpecies;

protected:
	StatSheet* stats; // because there is no default constructor
	int level;
	int exp_awarded;
	std::vector<std::unique_ptr<Attack>> attacks;
	EnumWrapper<EnemySpecies>* species;
};




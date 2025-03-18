#pragma once

#pragma once
#include "EnemyAttackTypes.h"
#include "EnumWrapper.h"
#include "Utility.h"
#include "StatSheet.h"


class EnemyAttack {
private:
	float multiplier;
	float hitChance;
	std::string description;
	EnumWrapper<EnemyAttackTypes>* type;
public:
	Stats scalingStat;
	EnemyAttack(int multiplier, float hitChance, std::string description, EnemyAttackTypes type) : multiplier(multiplier),  hitChance(hitChance), 
		description(description), type(new EnumWrapper<EnemyAttackTypes>(type)) {
	}
	float GetDamage(StatSheet sheet, float multiplier) const;
	const inline void PrintAttackInfo()
	{
		std::string expanded = "Multiplier: " + std::to_string(multiplier) + " | Hit Chance: " + std::to_string(hitChance);
		Utility::PrintToConsole(true, (std::string) *type);
		Utility::PrintToConsole(true, expanded);
		Utility::PrintToConsole(true, description);

	}
	const inline float GetHitChance() const { return hitChance; }
	EnumWrapper<EnemyAttackTypes> GetAttackType() const { return *type; }
	~EnemyAttack() { delete type; }



};
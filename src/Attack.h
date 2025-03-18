#pragma once
#include "Stats.h"
#include "PlayerAttackTypes.h"
#include "EnumWrapper.h"
#include "Utility.h"
#include "AttackAttributes.h"
#include "EnemyAttackTypes.h"
#include "StatSheet.h"
#include <variant>


class Attack {
private:
	Stats scalingStat;
	std::string description;
	std::vector<std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float>> attributes;
	std::variant<EnumWrapper<PlayerAttackTypes>, EnumWrapper<EnemyAttackTypes>> type;
public:
	Attack(std::vector<std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float>> attributes,
		Stats scalingStat, std::string description, PlayerAttackTypes type) :
		attributes(attributes), scalingStat(scalingStat), description(description), type(EnumWrapper<PlayerAttackTypes>(type)) {
	}

	Attack(std::vector<std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float>> attributes,
		Stats scalingStat, std::string description, EnemyAttackTypes type) :
		attributes(attributes), scalingStat(scalingStat), description(description), type(EnumWrapper<EnemyAttackTypes>(type)) {
	}

	float GetDamage(const StatSheet* stats, float multiplier, bool isCrit) const;
	const void PrintAttackInfo();

	const inline int GetNumTargets() const
	{
		int numTargets = 0;
		for (auto attribute : attributes)
		{
			if (std::get<0>(attribute).get() == AttackAttributes::MultiTarget)
			{
				numTargets = std::get<2>(attribute);
			}
			if (numTargets == 0 &&
				std::get<1>(attribute).get() == Target::opponent)
			{
				numTargets = 1;
			}
		}
		return numTargets;
	}
	const inline float GetHitChance() const
	{
		float hitChance = 1;
		for (auto attribute : attributes)
		{
			if (std::get<0>(attribute).get() == AttackAttributes::HitChance)
			{
				hitChance = std::get<2>(attribute);
			}
		}
		return hitChance;
	}
	const inline float GetCritChance() const
	{
		float critChance = 0;
		for (auto attribute : attributes)
		{
			if (std::get<0>(attribute).get() == AttackAttributes::Crit)
			{
				critChance = std::get<2>(attribute);
			}
		}
		return critChance;
	}

	const inline std::vector<std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float>>& GetAttributes() const
	{
		return attributes;
	}

	std::variant<EnumWrapper<PlayerAttackTypes>, EnumWrapper<EnemyAttackTypes>> GetAttackType() const { return type; }
};
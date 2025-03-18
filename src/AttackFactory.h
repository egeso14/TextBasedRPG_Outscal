#pragma once
#include <unordered_map>
#include <tuple>
#include "PlayerAttackTypes.h"
#include "EnemyAttackTypes.h"
#include "Stats.h"
#include "Attack.h"
#include "AttackAttributes.h"
#include <memory>

class AttackFactory
{
	// player attack properties
	static std::unordered_map <PlayerAttackTypes, std::string> p_descriptionPerType;
	static std::unordered_map <PlayerAttackTypes, Stats> p_scalingStatPerType;
	/**
	* @brief A dictionary containing all atribute info for any given attack |
	* key: PlayerAttackType |
	* value: vector of touples which contain (AttackAttribte, Target, value) respectively
	* The last element in the tuple, value, can mean either damage multipllier, healing multiplier, or turn count depending on context
	*/
	static std::unordered_map<PlayerAttackTypes, std::vector<std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float>>> p_attributeValuesPerType;

	// enemy attack properties
	static std::unordered_map <EnemyAttackTypes, std::string> e_descriptionPerType;
	static std::unordered_map <EnemyAttackTypes, Stats> e_scalingStatPerType;
	static std::unordered_map<EnemyAttackTypes, std::vector<std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float>>> e_attributeValuesPerType;
public:
	inline static Attack* CreateAttack(PlayerAttackTypes type) 
	{ return new Attack(p_attributeValuesPerType[type], p_scalingStatPerType[type], p_descriptionPerType[type], type); }
	inline static std::unique_ptr<Attack> CreateAttack(EnemyAttackTypes type)
	{
		return std::make_unique<Attack>(e_attributeValuesPerType[type], e_scalingStatPerType[type], e_descriptionPerType[type], type);
	}

};
#pragma once
#include "GameEvents.h"
#include "Equipment.h"
#include "PlayerClasses.h"
#include "EquipmentSlots.h"
#include "Item.h"
#include "Attack.h"
#include "ITargetable.h"
#include <unordered_map>
#include <array>



class Player : public ITargetable{
friend Equipment;
public:
	static std::unordered_map<PlayerClasses, std::unordered_map<int, PlayerAttackTypes>> attacksToLearn;
	static std::unordered_map<PlayerClasses, std::vector<PlayerAttackTypes>> startingAttacks;

	Player(EnumWrapper<PlayerClasses> classChoice, std::string playerName);
	std::vector<Item*>* playerInventory;

	
	~Player()
	{
		delete stats;
		
	}

	void Equip(Equipment*);
	void Unequip(Equipment*);
	void PrintEquipmentInfo();
	void ItemUsed(Item* item);
	void RemoveFromInventory(Item* item);
	void LearnAttack(PlayerAttackTypes attackType);
	void PrintAllCharacterInfo();
	bool TakeDamage(float damage);
	void Heal(float healAmount);
	void PrintStats();
	void PrintAttackInfo();
	void GainExp(int exp);
	void OnLevelUp(int level);
	void LearnStartingAttacks();
	bool IsDead();
	void InflictCondition(Condition* condition) {};
	void UpdateConditions() {} ;
	inline StatSheet* GetStats() { return stats; }
	const std::vector<Attack>& GetAttacks() { return knownAttacks; }
	const std::string getName() { return name; }
	

private:
	static std::unordered_map<int, float> levelUpThresholds;
	std::string name;
	float currentExp;
	int currentLevel;
	EnumWrapper<PlayerClasses> chosenClass;
	StatSheet* stats;
	std::vector<Attack> knownAttacks;
	Attack* weaponAttack;
	std::unordered_map<EquipmentSlots, Equipment*> equipped;
	

	void RecalculateStats();
	

};


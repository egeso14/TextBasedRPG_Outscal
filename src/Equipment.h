#pragma once
#include "Stats.h"
#include "StatSheet.h"
#include "EquipmentSlots.h"

struct StatSheet;

class Equipment {
public:
	Equipment(std::string name, Stats boostedStat, bool boostIsFlat, int boostAmount, Stats reducedStat, bool reduceIsFlat, int reduceAmount, EquipmentSlots equipSlot) :
		name(name), boostedStat(EnumWrapper<Stats>(boostedStat)), boostIsFlat(boostIsFlat),
		boostAmount(boostAmount), reducedStat(EnumWrapper<Stats>(reducedStat)), reduceIsFlat(reduceIsFlat), 
		reduceAmount(reduceAmount), equipSlot(EnumWrapper<EquipmentSlots>(equipSlot)) {};
	void AddModifiers(StatSheet* stats);
	void RemoveModifiers(StatSheet* stats);
	void PrintInfo();
	EquipmentSlots GetEquipSlot();

protected:
	std::string name;
	EnumWrapper<Stats> boostedStat;
	EnumWrapper<Stats> reducedStat;
	bool boostIsFlat;
	bool reduceIsFlat;
	int boostAmount;
	int reduceAmount;
	EnumWrapper<EquipmentSlots> equipSlot;

};
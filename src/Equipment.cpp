#include "Equipment.h"
#include "Utility.h"



void Equipment::AddModifiers(StatSheet* stats)
{
	switch (boostedStat.get()) {
	case Stats::Attack:
		stats->currentAtk += boostIsFlat ? boostAmount : boostAmount * stats->baseAtk;
		break;
	case Stats::Defense:
		stats->currentDef += boostIsFlat ? boostAmount : boostAmount * stats->baseDef;
		break;
	case Stats::HP:
		stats->currentHP += boostIsFlat ? boostAmount : boostAmount * stats->baseHP;
		break;
	}

	switch (reducedStat.get()) {
	case Stats::Attack:
		stats->currentAtk -= reduceIsFlat ? reduceAmount : reduceAmount * stats->baseAtk;
		break;
	case Stats::Defense:
		stats->currentDef -= reduceIsFlat ? reduceAmount : reduceAmount * stats->baseDef;
		break;
	case Stats::HP:
		stats->currentHP -= reduceIsFlat ? reduceAmount : reduceAmount * stats->baseHP;
		break;
	}
}
	


void Equipment::RemoveModifiers(StatSheet* stats)
{
	switch (boostedStat.get()) {
	case Stats::Attack:
		stats->currentAtk -= boostIsFlat ? boostAmount : boostAmount * stats->baseAtk;
		break;
	case Stats::Defense:
		stats->currentDef -= boostIsFlat ? boostAmount : boostAmount * stats->baseDef;
		break;
	case Stats::HP:
		stats->currentHP -= boostIsFlat ? boostAmount : boostAmount * stats->baseHP;
		break;
	}

	switch (reducedStat.get()) {
	case Stats::Attack:
		stats->currentAtk += reduceIsFlat ? reduceAmount : reduceAmount * stats->baseAtk;
		break;
	case Stats::Defense:
		stats->currentDef += reduceIsFlat ? reduceAmount : reduceAmount * stats->baseDef;
		break;
	case Stats::HP:
		stats->currentHP += reduceIsFlat ? reduceAmount : reduceAmount * stats->baseHP;
		break;
	}
}

void Equipment::PrintInfo()
{
	Utility::PrintToConsole(false, name);
	Utility::PrintToConsole(false, " is for equipment slot: ");
	Utility::PrintToConsole(false, equipSlot);
	Utility::PrintToConsole(false, " and boosts ");
	Utility::PrintToConsole(false, boostedStat);
	Utility::PrintToConsole(false, " by ");
	Utility::PrintToConsole(false, boostAmount);
	if (!boostIsFlat)
	{
		Utility::PrintToConsole(false, "%");
	}
	Utility::PrintToConsole(false, " whilst reducing ", reducedStat, " by ");
	Utility::PrintToConsole(false, reduceAmount);
	if (!reduceAmount)
	{
		Utility::PrintToConsole(false, "%");
	}
	Utility::PrintToConsole(true, ".");
}

EquipmentSlots Equipment::GetEquipSlot()
{
	return equipSlot.get();
}
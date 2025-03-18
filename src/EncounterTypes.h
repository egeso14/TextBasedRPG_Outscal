#pragma once
#include "EnumWrapper.h"

enum class EncounterTypes
{
	EnemyEncounter,
	TreasureEncounter,
	MysteryEncounter
};

DEFINE_ENUM_MAPPING(EncounterTypes, {
	{ EncounterTypes::EnemyEncounter, "Enemy Encounter" },
	{ EncounterTypes::TreasureEncounter, "Treasure Encounter" },
	{ EncounterTypes::MysteryEncounter, "Mystery Encounter" }
	});

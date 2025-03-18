#pragma once
#include "EnumWrapper.h"

enum class BattleOptions{
	AttemptToRun,
	Fight,
	UseItem,
	CheckCharacter
};

DEFINE_ENUM_MAPPING(BattleOptions, {
	{ BattleOptions::AttemptToRun, "Attempt to Run" },
	{ BattleOptions::Fight, "Fight" },
	{ BattleOptions::UseItem, "Use Item" },
	{ BattleOptions::CheckCharacter, "Check Character" }
	});
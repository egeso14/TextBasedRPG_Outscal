#pragma once
#include "EnumWrapper.h"

enum class Stats {
	HP,
	Attack,
	Defense
};

DEFINE_ENUM_MAPPING(Stats, {
    { Stats::HP, "HP" },
    { Stats::Attack, "Attack" },
    { Stats::Defense, "Defense" } 
    });


#pragma once
#include <string>
#include "EnumWrapper.h"

enum class PlayerClasses {
	Warrior,
	Wizard,
	Archer,
    Paladin
};

DEFINE_ENUM_MAPPING(PlayerClasses, {
    { PlayerClasses::Warrior, "Warrior" },
    { PlayerClasses::Wizard, "Wizard" },
    { PlayerClasses::Archer, "Archer" },
    { PlayerClasses::Paladin, "Paladin" }
    });



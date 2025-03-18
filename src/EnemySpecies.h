#pragma once
#include "EnumWrapper.h"

enum class EnemySpecies {
	Slime,
	Skeleton,
	Mercenary,
	Troll,
	Vulture
};



DEFINE_ENUM_MAPPING(EnemySpecies, {
	{ EnemySpecies::Slime, "Slime" },
	{ EnemySpecies::Skeleton, "Skeleton" },
	{ EnemySpecies::Mercenary, "Mercenary" },
	{ EnemySpecies::Troll, "Troll"},
	{ EnemySpecies::Vulture , "Vulture"},
	});

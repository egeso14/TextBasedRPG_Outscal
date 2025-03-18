#pragma once
#include "EnumWrapper.h"

enum class EnemyAttackTypes
{
	Bite,
	Slam,
	BoneBreakingBeak,
	Gut,
	CrossbowShot,
	Stab,
	Kick,
	SuckerPunch,
	FemurSwing,
	Engulf,
	AcidSplash,
	Regenerate,
	Claw,
};

DEFINE_ENUM_MAPPING(EnemyAttackTypes, {
	{ EnemyAttackTypes::Bite, "Bite" },
	{ EnemyAttackTypes::Slam, "Slam" },
	{ EnemyAttackTypes::BoneBreakingBeak, "Bone Breaking Beak" },
	{ EnemyAttackTypes::Gut, "Gut" },
	{ EnemyAttackTypes::CrossbowShot, "Crossbow Shot" },
	{ EnemyAttackTypes::Stab, "Stab" },
	{ EnemyAttackTypes::Kick, "Kick" },
	{ EnemyAttackTypes::SuckerPunch, "Sucker Punch" },
	{ EnemyAttackTypes::FemurSwing, "Femur Swing"},
	{ EnemyAttackTypes::Engulf, "Engulf"},
	{ EnemyAttackTypes::AcidSplash, "Acid Splash"},
	{ EnemyAttackTypes::Regenerate, "Regenerate"},
	{ EnemyAttackTypes::Claw, "Claw"}
	});

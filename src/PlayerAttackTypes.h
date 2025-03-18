#pragma once
#include "EnumWrapper.h"

enum class PlayerAttackTypes {
	// Archer
	AimShot, // starter skill
	SpreadShot, // starter skill
	DrainingShot, // level 2
	DelayedShot, // level 5
	HeadShot, // level 8

	// Warrior
	Rage, // starter skill
	OverheadSlash, // starter skill
	Whirlwind, // level 3
	Tackle, // level 6
	ChallangeDeath, // level 8

	// Wizard 
	ColdSnap, // starter skill
	Jolt, // starter skill
	EnhanceSpell, // level 2
	Eruption, // level 4
	FireLash, // level 7

	// Paladin
	Heal, // starter skill
	Pummel, // starter skill
	Protect, // level 3
	Smite, //level 6
	Denounce // level 8
};

DEFINE_ENUM_MAPPING(PlayerAttackTypes, {
{ PlayerAttackTypes::AimShot, "Aim Shot" },
{ PlayerAttackTypes::SpreadShot, "Spread Shot" },
{ PlayerAttackTypes::DrainingShot, "Draining Shot" },
{ PlayerAttackTypes::DelayedShot, "Delayed Shot" },
{ PlayerAttackTypes::HeadShot, "Head Shot" },
{ PlayerAttackTypes::Rage, "Rage" },
{ PlayerAttackTypes::OverheadSlash, "Overhead Slash" },
{ PlayerAttackTypes::Whirlwind, "Whirlwind" },
{ PlayerAttackTypes::Tackle, "Tackle" },
{ PlayerAttackTypes::ChallangeDeath, "Challenge Death" },
{ PlayerAttackTypes::ColdSnap, "Cold Snap" },
{ PlayerAttackTypes::Jolt, "Jolt" },
{ PlayerAttackTypes::EnhanceSpell, "Enhance Spell" },
{ PlayerAttackTypes::Eruption, "Eruption" },
{ PlayerAttackTypes::FireLash, "Fire Lash" },
{ PlayerAttackTypes::Heal, "Heal" },
{ PlayerAttackTypes::Pummel, "Pummel" },
{ PlayerAttackTypes::Protect, "Protect" },
{ PlayerAttackTypes::Smite, "Smite" },
{ PlayerAttackTypes::Denounce, "Denounce" },
});

 
#pragma once
#include "EnumWrapper.h"

enum class EquipmentSlots {
	Head,
	Shoulders,
	Chest,
	Legs,
	Feet,
	LeftHand,
	Righthand,
	None
};

DEFINE_ENUM_MAPPING(EquipmentSlots, {
	{ EquipmentSlots::Head, "Head" },
	{ EquipmentSlots::Shoulders, "Shoulders" },
	{ EquipmentSlots::Chest, "Chest" },
	{ EquipmentSlots::Legs, "Legs" },
	{ EquipmentSlots::Feet, "Feet" },
	{ EquipmentSlots::LeftHand, "Left Hand" },
	{ EquipmentSlots::Righthand, "Right Hand" },
	{ EquipmentSlots::None, "None" }
	});

#pragma once
#include "EnumWrapper.h"

enum class ItemTypes
{
	Default
};

DEFINE_ENUM_MAPPING(ItemTypes, {
	{ItemTypes::Default, "to-be-filled"}
	});

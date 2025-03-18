#pragma once
#include "EnumWrapper.h"

enum class YesNo
{
	Yes,
	No
};

DEFINE_ENUM_MAPPING(YesNo, {
	{YesNo::Yes, "Yes"},
	{YesNo::No, "No"},
	});
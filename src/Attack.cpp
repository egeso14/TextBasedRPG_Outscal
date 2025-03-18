#include "Attack.h"
#include "StatSheet.h"

float Attack::GetDamage(const StatSheet* stats, float multiplier, bool isCrit) const
{
	return multiplier * stats->GetStat(scalingStat);
}

const void Attack::PrintAttackInfo()
{
	EnumWrapper<Stats> statWrapper(scalingStat);
	std::visit([&statWrapper](auto& val) { Utility::PrintToConsole(true, val, " ", statWrapper); }, type);

	for (std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float> attribute : attributes)
	{
		Utility::PrintToConsole(true, std::get<1>(attribute), std::get<0>(attribute), std::get<2>(attribute));
	}

	Utility::PrintToConsole(true, description);

}
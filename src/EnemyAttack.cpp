#include "EnemyAttack.h"


float EnemyAttack::GetDamage(StatSheet sheet, float multiplier) const
{
	return sheet.GetStat(scalingStat) * multiplier;
}
#pragma once

enum class AttackAttributes
{
	Damage,
	MultiTarget,
	BoostAtk,
	LowerAtk,
	BoostDef,
	LowerDef,
	Heal,
	Stun,
	Crit,
	Burn,
	Freeze,
	Shield,
	Unkillable,
	HitChance,
};

enum class Target {
	self,
	opponent
};

DEFINE_ENUM_MAPPING(AttackAttributes, {
	{ AttackAttributes::Damage, "Damage | Scaling: " },
	{ AttackAttributes::MultiTarget, "Multi-Target | Number: " },
	{ AttackAttributes::BoostAtk, "BoostAtk | Percentage: " },
	{ AttackAttributes::LowerAtk, "LowerAtk | Percentage: " },
	{ AttackAttributes::BoostDef, "BoostDef| Percentage: " },
	{ AttackAttributes::LowerDef, "LowerDef | Percentage: " },
	{ AttackAttributes::Heal, "Heal | Scaling: " },
	{ AttackAttributes::Stun, "Stun | Turns: " },
	{ AttackAttributes::Crit, "Crit | Chance: " },
	{ AttackAttributes::Burn, "Burn | Turns: " },
	{ AttackAttributes::Freeze, "Freeze | Turns: " },
	{ AttackAttributes::Shield, "Shield | Turns: " },
	{ AttackAttributes::Unkillable, "Unkillable | Turns: " },
	{ AttackAttributes::HitChance, "HitChance | Percentage: " }
	});

DEFINE_ENUM_MAPPING(Target, { 
	{Target::self, "Self | "}, 
	{Target::opponent, "Opponent | "} 
	});
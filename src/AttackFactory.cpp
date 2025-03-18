#include "AttackFactory.h"

std::unordered_map<PlayerAttackTypes, std::vector<std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float>>>
AttackFactory::p_attributeValuesPerType = {
	// **Archer Skills**
	{ PlayerAttackTypes::AimShot, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.2 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::HitChance), EnumWrapper<Target>(Target::opponent), 0.75f}
	}},
	{ PlayerAttackTypes::SpreadShot, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.6 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::HitChance), EnumWrapper<Target>(Target::opponent), 0.9f },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::MultiTarget), EnumWrapper<Target>(Target::opponent), 2 }
	}},
	{ PlayerAttackTypes::DrainingShot, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.6 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Heal), EnumWrapper<Target>(Target::self), 1 }
	}},
	{ PlayerAttackTypes::DelayedShot, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.4 },
	}},
	{ PlayerAttackTypes::HeadShot, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 2 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::HitChance), EnumWrapper<Target>(Target::opponent), 0.8},
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Crit), EnumWrapper<Target>(Target::opponent), 0.5 }
	}},
    // **Warrior Skills**
	{ PlayerAttackTypes::Rage, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::BoostAtk), EnumWrapper<Target>(Target::self), 0.25 }
	}},
	{ PlayerAttackTypes::OverheadSlash, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::self), 0.8 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Crit), EnumWrapper<Target>(Target::self), 0.25 }
	}},
	{ PlayerAttackTypes::Whirlwind, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.4 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::MultiTarget), EnumWrapper<Target>(Target::opponent), 4 }
	}},
	{ PlayerAttackTypes::Tackle, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.7 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Stun), EnumWrapper<Target>(Target::opponent), 2 }
	}},
	{ PlayerAttackTypes::ChallangeDeath, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Unkillable), EnumWrapper<Target>(Target::self), 3 }
	}},

	// **Wizard Skills**
	{ PlayerAttackTypes::ColdSnap, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.6 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Freeze), EnumWrapper<Target>(Target::opponent), 1 }
	}},
	{ PlayerAttackTypes::Jolt, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.8 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::LowerDef), EnumWrapper<Target>(Target::opponent), 2 },
	}},
	{ PlayerAttackTypes::EnhanceSpell, {
		
	}},
	{ PlayerAttackTypes::Eruption, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::MultiTarget), EnumWrapper<Target>(Target::opponent), 4}
	}},
	{ PlayerAttackTypes::FireLash, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::self), 1.4 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Burn), EnumWrapper<Target>(Target::self), 3 }
	}},

	// **Paladin Skills**
	{ PlayerAttackTypes::Heal, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Heal), EnumWrapper<Target>(Target::self), 1 }
	}},
	{ PlayerAttackTypes::Pummel, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.9 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Stun), EnumWrapper<Target>(Target::opponent), 1 }
	}},
	{ PlayerAttackTypes::Protect, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Shield), EnumWrapper<Target>(Target::self), 3 },
	}},
	{ PlayerAttackTypes::Smite, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.2},
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Crit), EnumWrapper<Target>(Target::opponent), 0.3f},
	}},
	{ PlayerAttackTypes::Denounce, {
		{ EnumWrapper<AttackAttributes>(AttackAttributes::LowerDef), EnumWrapper<Target>(Target::opponent), 3 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::LowerAtk), EnumWrapper<Target>(Target::opponent), 3 },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::MultiTarget), EnumWrapper<Target>(Target::opponent), 4 }
	}}

};


std::unordered_map<EnemyAttackTypes, std::vector<std::tuple<EnumWrapper<AttackAttributes>, EnumWrapper<Target>, float>>>
AttackFactory::e_attributeValuesPerType =
{
   { EnemyAttackTypes::Bite, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.0 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::HitChance), EnumWrapper<Target>(Target::opponent), 0.8f },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Crit), EnumWrapper<Target>(Target::opponent), 0.15f }
   }},
   { EnemyAttackTypes::Slam, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.2 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::HitChance), EnumWrapper<Target>(Target::opponent), 0.8f }
	  
   }},
   { EnemyAttackTypes::BoneBreakingBeak, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::LowerDef), EnumWrapper<Target>(Target::opponent), 2 }
   }},
   { EnemyAttackTypes::Gut, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.1 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::LowerAtk), EnumWrapper<Target>(Target::opponent), 1 }
   }},
   { EnemyAttackTypes::CrossbowShot, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.9 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::HitChance), EnumWrapper<Target>(Target::opponent), 0.9f }
   }},
   { EnemyAttackTypes::Stab, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Crit), EnumWrapper<Target>(Target::opponent), 0.25 }
   }},
   { EnemyAttackTypes::Kick, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.7 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Stun), EnumWrapper<Target>(Target::opponent), 1 }
   }},
   { EnemyAttackTypes::SuckerPunch, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.4},
   }},
   { EnemyAttackTypes::FemurSwing, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.8 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::BoostAtk), EnumWrapper<Target>(Target::self), 2 }
   }},
   { EnemyAttackTypes::Engulf, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.0 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Stun), EnumWrapper<Target>(Target::self), 1 }
   }},
   { EnemyAttackTypes::AcidSplash, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 0.5 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Burn), EnumWrapper<Target>(Target::opponent), 1 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::LowerDef), EnumWrapper<Target>(Target::opponent), 3 }
   }},
   { EnemyAttackTypes::Regenerate, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Heal), EnumWrapper<Target>(Target::self), 0.5f }
   }},
   { EnemyAttackTypes::Claw, {
	   { EnumWrapper<AttackAttributes>(AttackAttributes::Damage), EnumWrapper<Target>(Target::opponent), 1.0 },
	   { EnumWrapper<AttackAttributes>(AttackAttributes::HitChance), EnumWrapper<Target>(Target::opponent), 0.8f },
		{ EnumWrapper<AttackAttributes>(AttackAttributes::Crit), EnumWrapper<Target>(Target::opponent), 0.25f }
   }},
};

// Initialize Player Attack Types to Scaling Stats
std::unordered_map<PlayerAttackTypes, Stats> AttackFactory::p_scalingStatPerType = {
	{ PlayerAttackTypes::AimShot, Stats::Attack },
	{ PlayerAttackTypes::SpreadShot, Stats::Attack },
	{ PlayerAttackTypes::DrainingShot, Stats::Attack },
	{ PlayerAttackTypes::DelayedShot, Stats::Attack },
	{ PlayerAttackTypes::HeadShot, Stats::Attack },
	{ PlayerAttackTypes::Rage, Stats::Attack },
	{ PlayerAttackTypes::OverheadSlash, Stats::Attack },
	{ PlayerAttackTypes::Whirlwind, Stats::Attack },
	{ PlayerAttackTypes::Tackle, Stats::Attack },
	{ PlayerAttackTypes::ChallangeDeath, Stats::HP },
	{ PlayerAttackTypes::ColdSnap, Stats::Attack },
	{ PlayerAttackTypes::Jolt, Stats::Attack },
	{ PlayerAttackTypes::EnhanceSpell, Stats::Attack },
	{ PlayerAttackTypes::Eruption, Stats::Attack },
	{ PlayerAttackTypes::FireLash, Stats::Attack },
	{ PlayerAttackTypes::Heal, Stats::HP },
	{ PlayerAttackTypes::Pummel, Stats::Attack },
	{ PlayerAttackTypes::Protect, Stats::Defense },
	{ PlayerAttackTypes::Smite, Stats::Attack },
	{ PlayerAttackTypes::Denounce, Stats::Defense }
};

// Initialize Enemy Attack Types to Scaling Stats
std::unordered_map<EnemyAttackTypes, Stats> AttackFactory::e_scalingStatPerType = {
	{ EnemyAttackTypes::Bite, Stats::Attack },
	{ EnemyAttackTypes::Slam, Stats::Attack },
	{ EnemyAttackTypes::BoneBreakingBeak, Stats::Attack },
	{ EnemyAttackTypes::Gut, Stats::Attack },
	{ EnemyAttackTypes::CrossbowShot, Stats::Attack },
	{ EnemyAttackTypes::Stab, Stats::Attack },
	{ EnemyAttackTypes::Kick, Stats::Attack },
	{ EnemyAttackTypes::SuckerPunch, Stats::Defense },
	{ EnemyAttackTypes::FemurSwing, Stats::Attack },
	{ EnemyAttackTypes::Engulf, Stats::Attack },
	{ EnemyAttackTypes::AcidSplash, Stats::Attack },
	{ EnemyAttackTypes::Regenerate, Stats::HP },
	{ EnemyAttackTypes::Claw, Stats::Attack }
};

std::unordered_map<EnemyAttackTypes, std::string> AttackFactory::e_descriptionPerType = {
	{ EnemyAttackTypes::Bite, "A quick bite that deals moderate damage." },
	{ EnemyAttackTypes::Slam, "A powerful slam that can crush opponents." },
	{ EnemyAttackTypes::BoneBreakingBeak, "A piercing beak attack that lowers defense." },
	{ EnemyAttackTypes::Gut, "A strike aimed at the enemy's weak points." },
	{ EnemyAttackTypes::CrossbowShot, "A precise ranged attack with a crossbow." },
	{ EnemyAttackTypes::Stab, "A stabbing attack that has a high chance to critically strike." },
	{ EnemyAttackTypes::Kick, "A strong kick that has a chance to stun the target." },
	{ EnemyAttackTypes::SuckerPunch, "A sneaky punch that catches opponents off guard." },
	{ EnemyAttackTypes::FemurSwing, "A swing using a femur bone, boosting attack power." },
	{ EnemyAttackTypes::Engulf, "A smothering attack that also stuns the enemy." },
	{ EnemyAttackTypes::AcidSplash, "A corrosive splash that weakens defense and causes burning." },
	{ EnemyAttackTypes::Regenerate, "The enemy regenerates a portion of its health." },
	{ EnemyAttackTypes::Claw, "A quick claw swipe that has a chance to land a critical hit." }
};

std::unordered_map<PlayerAttackTypes, std::string> AttackFactory::p_descriptionPerType = {
	// **Archer Skills**
	{ PlayerAttackTypes::AimShot, "A precise shot aimed at a weak point for high damage." },
	{ PlayerAttackTypes::SpreadShot, "Fires multiple arrows, hitting multiple targets." },
	{ PlayerAttackTypes::DrainingShot, "Deals damage and restores health based on damage dealt." },
	{ PlayerAttackTypes::DelayedShot, "A powerful shot that takes time to prepare." },
	{ PlayerAttackTypes::HeadShot, "A well-aimed shot with high critical hit potential." },

	// **Warrior Skills**
	{ PlayerAttackTypes::Rage, "Increases attack power for a few turns." },
	{ PlayerAttackTypes::OverheadSlash, "A strong vertical attack with a chance to land a critical hit." },
	{ PlayerAttackTypes::Whirlwind, "A spinning attack that strikes all nearby enemies." },
	{ PlayerAttackTypes::Tackle, "A full-force tackle that can stun enemies." },
	{ PlayerAttackTypes::ChallangeDeath, "Prevents the user from dying for a few turns." },

	// **Wizard Skills**
	{ PlayerAttackTypes::ColdSnap, "A freezing attack that slows or immobilizes enemies." },
	{ PlayerAttackTypes::Jolt, "A lightning attack that weakens enemy defenses." },
	{ PlayerAttackTypes::EnhanceSpell, "Enhances the next spell for increased power." },
	{ PlayerAttackTypes::Eruption, "An explosive fire spell that hits multiple enemies." },
	{ PlayerAttackTypes::FireLash, "A burning attack that continues to deal damage over time." },

	// **Paladin Skills**
	{ PlayerAttackTypes::Heal, "Restores health to the user or an ally." },
	{ PlayerAttackTypes::Pummel, "A heavy attack with a chance to stun the target." },
	{ PlayerAttackTypes::Protect, "Creates a shield that absorbs damage." },
	{ PlayerAttackTypes::Smite, "A holy strike that deals damage and has a chance to critically hit." },
	{ PlayerAttackTypes::Denounce, "Weakens enemy attack and defense while affecting multiple targets." }
};
#include "Enemy.h"
#include "Utility.h"
#include "AttackFactory.h"

std::unordered_map<EnemySpecies, std::vector<EnemyAttackTypes>> Enemy::attackTypePerSpecies =
{
	{EnemySpecies::Mercenary, {EnemyAttackTypes::CrossbowShot, EnemyAttackTypes::SuckerPunch, EnemyAttackTypes::Stab, EnemyAttackTypes::Kick}},
	{EnemySpecies::Skeleton, {EnemyAttackTypes::Kick, EnemyAttackTypes::SuckerPunch, EnemyAttackTypes::FemurSwing, EnemyAttackTypes::Slam}},
	{EnemySpecies::Slime, {EnemyAttackTypes::Engulf, EnemyAttackTypes::Regenerate, EnemyAttackTypes::AcidSplash}},
	{EnemySpecies::Troll, {EnemyAttackTypes::Gut, EnemyAttackTypes::Bite, EnemyAttackTypes::Kick}},
	{EnemySpecies::Vulture, {EnemyAttackTypes::Gut, EnemyAttackTypes::Claw, EnemyAttackTypes::BoneBreakingBeak} }

};

std::unordered_map<EnemySpecies, int> Enemy::expAwardedPerSpecies =
{
	{EnemySpecies::Mercenary, 10},
	{EnemySpecies::Skeleton, 8},
	{EnemySpecies::Slime, 4},
	{EnemySpecies::Troll, 6},
	{EnemySpecies::Vulture, 6},
};


Enemy::Enemy(EnemySpecies enemy_species)
{
	stats = new StatSheet(enemy_species);
	for (EnemyAttackTypes attackType : attackTypePerSpecies[enemy_species])
	{
		attacks.push_back(std::move(AttackFactory::CreateAttack(attackType)));
	}
	level = 1;
	exp_awarded = expAwardedPerSpecies[enemy_species];
	species = new EnumWrapper<EnemySpecies>(enemy_species);
}

void Enemy::DisplayEnemyInfo()
{
	Utility::PrintToConsole(true, "Level: ", level, " ", *species, " with health: ", stats->currentHP);
}

bool Enemy::TakeDamage(float damage)
{
	float damageAfterMitigation = (1 - stats->currentDef / 100) * damage;
	Utility::PrintToConsole(false, *species, " took ");
	Utility::PrintToConsole(false, damageAfterMitigation);
	
	stats->currentHP -= damageAfterMitigation;
	if (stats->currentHP <= 0)
	{
		Utility::PrintToConsole(true, " damage and was knocked out!!");
		return true;
	}
	Utility::PrintToConsole(true, " damage! They have ", GetReaminingHealthString(), " remaining health!");
	return false;
}

void Enemy::Heal(float healAmount)
{
	float healedHealth = std::min(stats->currentMaxHP - stats->currentHP, healAmount);
	stats->currentHP += healedHealth;
	Utility::PrintToConsole(true, *species, " was healed for ", healedHealth, " | CurrentHP: ", GetReaminingHealthString());
}

std::string Enemy::GetReaminingHealthString()
{
	std::string healthString = std::to_string((int)stats->currentHP) + "/" + std::to_string((int)stats->currentMaxHP);
	return healthString;
}

const Attack& Enemy::ChooseAttack()
{
	int attackIndex = Utility::ChooseInRange(0, attacks.size() - 1);
	return *attacks[attackIndex];
}

Enemy::~Enemy()
{
	delete species;
}
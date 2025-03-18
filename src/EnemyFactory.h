#pragma once
#include <memory>
#include "EnemySpecies.h"
#include "Enemy.h"

class EnemyFactory {
public:
	static Enemy CreateEnemy(EnemySpecies species) { return Enemy(species); }
	static std::vector<std::unique_ptr<Enemy>> CreateEnemies(std::vector<EnemySpecies> listOfSpecies)
	{
		std::vector<std::unique_ptr<Enemy>> listOfEnemies;
		for (auto species : listOfSpecies)
		{
			listOfEnemies.push_back(std::make_unique<Enemy>(species));
		}
		return listOfEnemies;
	}
};
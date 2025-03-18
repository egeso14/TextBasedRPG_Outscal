#pragma once
#include "Level.h"
#include "EnemyEncounter.h"
#include "EnemyFactory.h"
#include <memory>


class LevelManager {
public:

	static std::unique_ptr<Level> CreateLevel(int levelIndex, Player* player)
	{
        switch (levelIndex) {
        case 1:
            
            std::vector<std::unique_ptr<EnemyEncounter>> encounters;
            
            auto listOfEnemies1 = EnemyFactory::CreateEnemies({EnemySpecies::Slime});
            auto listOfEnemies2 = EnemyFactory::CreateEnemies({ EnemySpecies::Skeleton });
            auto listOfEnemies3 = EnemyFactory::CreateEnemies({ EnemySpecies::Slime, EnemySpecies::Slime});

            std::vector<std::string> lines = { "to be filled" };

            encounters.push_back(std::make_unique<EnemyEncounter>(player, lines, std::move(listOfEnemies1), 0.3f));
            encounters.push_back(std::make_unique<EnemyEncounter>(player, lines, std::move(listOfEnemies2), 0.3f));
            encounters.push_back(std::make_unique<EnemyEncounter>(player, lines, std::move(listOfEnemies3), 0.3f));
            return std::make_unique<Level>(player, std::move(encounters), 0.3);
        }
        return nullptr;
	}
};
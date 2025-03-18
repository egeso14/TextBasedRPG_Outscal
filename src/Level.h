#pragma once
#include <vector>
#include "Encounter.h"
#include "EnemyEncounter.h"
#include <memory>

class Player;


class LevelManager;

class Level {

friend LevelManager;

public:
	Level(Player* player, std::vector<std::unique_ptr<EnemyEncounter>> encounterList, int levelNum);
	void PlayLevel(bool& lossToken);
private:
	
	//void CompleteLevel();
	
	Player* playerInstance;
	int levelIndex;
	std::vector<std::unique_ptr<EnemyEncounter>> encounters;



	
};
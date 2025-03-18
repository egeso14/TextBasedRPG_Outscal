#include "Level.h"
#include "Player.h"



Level::Level(Player* player, std::vector<std::unique_ptr<EnemyEncounter>> encounterList ,int levelIndex)
{
	
	playerInstance = player;
	encounters = std::move(encounterList);
}

void Level::PlayLevel(bool& lossToken)
{
	Utility::PrintToConsole(true, "Starting level ", levelIndex, " of 6...");
	Utility::Wait(1);
	Utility::PrintToConsole(true, "You will face a total of ", encounters.size(), " encounters.");
	Utility::WaitForEnter();
	for (int i = 0; i < encounters.size(); i++)
	{
		bool won = encounters[i]->InitiateEncounter();
		if (!won)
		{
			lossToken = true;
			break;
		}
	}
}



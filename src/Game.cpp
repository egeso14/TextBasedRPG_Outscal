#include "Game.h"
#include "Player.h"
#include "LevelManager.h"
#include "UIManager.h"
#include "YesNo.h"

void Game::StartGame() 
{
	bool endGame = false;
	while (!endGame)
	{
		std::string chosenName = ChooseName();

		Utility::Wait(1);

		PlayerClasses chosenClass = ChooseClass();

		Utility::Wait(1);

		currentPlayer = new Player(EnumWrapper<PlayerClasses>(chosenClass), chosenName);
		endGame = PlayGame();
	}
	EndGame();
	
}

bool Game::PlayGame()
{
	bool lossToken = false;
	
	for (int i = 1; i <= numLevels; i++)
	{
		std::unique_ptr<Level> currentLevel = LevelManager::CreateLevel(i, currentPlayer);
		currentLevel->PlayLevel(lossToken); // this will run run the game loop wothin the level

		if (lossToken)
		{
			Utility::PrintToConsole(true, "Game over... Would you like try again?");
			std::vector<EnumWrapper<YesNo>> options;
			options.push_back(EnumWrapper<YesNo>(YesNo::Yes));
			options.push_back(EnumWrapper<YesNo>(YesNo::No));

			YesNo choice = UIManager::GetInstance()->ChooseOptions(options).get();

			if (choice == YesNo::Yes)
			{
				return false;
			}
			break;
		}
	}

	return true;
}

void Game::EndGame()
{
	delete currentPlayer;
}

PlayerClasses Game::ChooseClass()
{
	Utility::PrintToConsole(true, "Choose your class!");

	EnumWrapper<PlayerClasses> wizChoice(PlayerClasses::Wizard);
	EnumWrapper<PlayerClasses> warChoice(PlayerClasses::Warrior);
	EnumWrapper<PlayerClasses> palChoice(PlayerClasses::Paladin);
	EnumWrapper<PlayerClasses> archChoice(PlayerClasses::Archer);

	UIManager* uiManager = UIManager::GetInstance();
	return uiManager->Choose4Options(wizChoice, warChoice, palChoice, archChoice).get();
}

std::string Game::ChooseName()
{
	Utility::PrintToConsole(false, "Please enter your name: ");
	std::string name = Utility::RecieveInput();
	return name;
}

void Game::Lose()
{
	EndGame();
	
	std::vector<EnumWrapper<YesNo>> options;
	options.push_back(EnumWrapper<YesNo>(YesNo::Yes));
	options.push_back(EnumWrapper<YesNo>(YesNo::No));
	
	YesNo choice = UIManager::GetInstance()->ChooseOptions(options).get();

	if (choice == YesNo::Yes)
	{
		StartGame();
	}

}



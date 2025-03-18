// TextBasedRPG_Outscal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"
#include <iostream>
#include <SFML/Config.hpp>

int main()
{
	Game gameInstance;
	gameInstance.StartGame();
	gameInstance.PlayGame();
	gameInstance.EndGame();

	return 0;
}

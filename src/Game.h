#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Level.h"
#include "Player.h"



class Game {
public:
	void StartGame();
	bool PlayGame();
	void EndGame();
	void Lose();
	
private:
	std::string ChooseName();
	PlayerClasses ChooseClass();

	Player* currentPlayer;
	const int numLevels = 6;
	Level* currentLevel;
};


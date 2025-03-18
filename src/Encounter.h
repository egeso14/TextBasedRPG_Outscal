#pragma once
#include "EncounterTypes.h"
#include "Player.h"
#include <string>
#include <vector>




class Encounter
{
public:
	Encounter(Player* player, std::vector<std::string> encounterText);
	virtual bool InitiateEncounter() = 0;


private:

	int encounterTextIndex;
	Player* playerInstance;
	std::vector<std::string> encounterText;

protected:
	void DisplayNextEncounterText();
};
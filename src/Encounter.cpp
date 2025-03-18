#include "Encounter.h"
#include "Enemy.h"
#include "EncounterTypes.h"
#include "Utility.h"

Encounter::Encounter(Player* player, std::vector<std::string> lines)
{
	playerInstance = player;
	encounterText = lines;
}





void Encounter::DisplayNextEncounterText()
{
	if (encounterTextIndex < encounterText.size())
	{
		Utility::PrintToConsole(true, encounterText[encounterTextIndex]);
		encounterTextIndex++;
	}
}


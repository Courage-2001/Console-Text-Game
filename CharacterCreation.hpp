#pragma once
#include <string>
#include "Menu.hpp"

class CharacterCreation {
public:
	bool run();
private:
	struct PlayerData {
		std::string name = "ENTER NAME";
		std::string characterClass = "ENTER CLASS";
		int health = 50;
		int strength = 10;
		int intelligence = 10;
	};
	PlayerData player;
	void processInput(int input, int& selectedOption, bool& running, int optionCount, bool& redraw, PlayerData& player);
	void processClass(PlayerData& player);
	std::vector<std::string> getDetails();

};
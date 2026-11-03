#pragma once
#include <string>
#include "Menu.hpp"
#include <algorithm>
#include <thread>
#include <chrono>

class CharacterCreation {
public:
	bool run();
private:
	struct PlayerData {
		std::string name = "ENTER NAME";
		std::string characterClass = "ENTER CLASS";
		std::vector<std::string> traits = {};
		int health = 50;
		int strength = 10;
		int intelligence = 10;
		int numberOfTraits = 0;
	};
	struct Traits {
		std::string traitName;
		std::string traitDescription;
		int healthModifier;
		int strengthModifier;
		int intelligenceModifier;
	};
	PlayerData player;
	void processInput(int input, int& selectedOption, bool& running, int optionCount, bool& redraw, PlayerData& player, bool& startGame);
	void processClass(PlayerData& player);
	void processTraits(PlayerData& player);
	std::vector<std::string> getDetails();

};
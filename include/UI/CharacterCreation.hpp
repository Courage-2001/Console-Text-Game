#pragma once
#include "UI/Menu.hpp"
#include <string>

class CharacterCreation {
public:
	struct PlayerData {
		std::string name = "ENTER NAME";
		std::string characterClass = "ENTER CLASS";
		std::vector<std::string> traits = {};
		int maxHealth = 50;
		int currentHealth = maxHealth;
		int strength = 10;
		int intelligence = 10;
		int numberOfTraits = 0;
	};

	PlayerData getPlayerData() const;
	bool run();
private:
	// Need to move traits to a character system class or something. 
	struct Traits {
		std::string traitName;
		std::string traitDescription;
		int healthModifier;
		int strengthModifier;
		int intelligenceModifier;
	};
	PlayerData player_;
	void processInput(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& running, size_t optionCount, bool& redraw, PlayerData& player, bool& startGame);
	void processClass(PlayerData& player);
	void processTraits(PlayerData& player);
	std::vector<std::string> getDetails();

};
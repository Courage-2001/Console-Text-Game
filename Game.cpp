#include "Game.hpp"

Game::Game() {
	location_data_ = player_.getCurrentLocationData(player_.getCurrentLocation().locID);
}

Game::Game(const CharacterCreation::PlayerData& playerData) : player_(playerData) {
	location_data_ = player_.getCurrentLocationData(player_.getCurrentLocation().locID);
}

void Game::processInput(Menu::Keyboard& input, int selectedOption, int firstOption, bool& running, size_t optionCount) {
	menu_.navigateOptions(input, selected_option_, optionCount, firstOption, redraw_);
	if (input == Menu::Keyboard::Enter) {
		if (selected_option_ == 5) {
			Travel(input, selectedOption, firstOption);
		}
		else if (selected_option_ == 6) {
			std::vector<std::string> sublocationList = player_.getSubLocationStr(location_data_);
			processLocalAction(input, selectedOption, firstOption, sublocationList);
		}
		else if (selected_option_ == 7) {
			executeAction(input, selectedOption, firstOption);
		}
	}
	if (input == Menu::Keyboard::KeyC) {
		menu_.displayActionMenu(getActionMenu(), player_.generateCharacterSheet(), selectedOption, redraw_);
		redraw_ = false;
	}
	if (input == Menu::Keyboard::Escape) {
		running = false;
	}
}

// Great Plains works as fine, Forest will break due to access violation
// Need to ensure every location has a minimum 1 sublocation
void Game::Travel(Menu::Keyboard& input, int& selectedOption, int& firstOption) {
	selectedOption = 0;
	firstOption = 0;
	bool locationSelected = false;
	std::vector<std::string> travelList = world_.getAvailableDestinations(player_.getCurrentLocation().locID);

	while (locationSelected == false) {
		if (redraw_ == true) {
			menu_.displayActionMenu(travelList, player_.getLocalMap(), selectedOption, redraw_);
		}
		input = menu_.getInput();
		menu_.navigateOptions(input, selectedOption, travelList.size(), firstOption, redraw_);
		if (input == Menu::Keyboard::Enter) {
			for (auto& location : world_.getAllLocations()) {
				if (location.location_name == travelList[selectedOption]) {
					player_.setCurrentLocation(location);
					player_.setCurrentLocalMap(location.locID);
					player_.setCurrentSubLocation(location.subLocations[0]);
					location_data_ = player_.getCurrentLocationData(location.locID);
					locationSelected = true;
				}
			}
		}
	}
}

void Game::processLocalAction(Menu::Keyboard& input, int& selectedOption, int& firstOption, std::vector<std::string>& subLocationList) {
	selectedOption = 0;
	firstOption = 0;
	bool subLocationSeleceted = false;

	while (subLocationSeleceted == false) {
		if (redraw_ == true) {
			menu_.displayActionMenu(subLocationList, player_.getLocalMap(), selectedOption, redraw_);
		}
		input = menu_.getInput();
		menu_.navigateOptions(input, selectedOption, subLocationList.size(), firstOption, redraw_);

		if (input == Menu::Keyboard::Enter) {
			for (auto& location : location_data_.subLocations) {
				if (location.sublocation_name == subLocationList[selectedOption] && location.subID != World::SubLocationID::INVALID) {
					player_.setCurrentSubLocation(location);
				}
			}
			subLocationSeleceted = true;
		}
	}
}

void Game::executeAction(Menu::Keyboard& input, int& selectedOption, int& firstOption) {
	selectedOption = 0;
	firstOption = 0;
	bool actionSelected = false;
	std::vector<std::string> actionList = player_.getCurrentSubLocation().action_list;

	while (actionSelected == false) {
		if (redraw_ == true) {
			menu_.displayActionMenu(actionList, player_.getLocalMap(), selectedOption, redraw_);
		}
		input = menu_.getInput();
		menu_.navigateOptions(input, selectedOption, actionList.size(), firstOption, redraw_);
		if (input == Menu::Keyboard::Enter) {
			if (actionList[selectedOption] == "Explore") {
				actionSelected = true;
			}
			else if(actionList[selectedOption] == "Return to previous menu")
				actionSelected = true;
		}
	}
}

void Game::gameLoop() {
	bool running = true;
	menu_.displayLoadingScreen();

	while (running) {
		menu_.displayActionMenu(getActionMenu(), player_.getLocalMap(), selected_option_, redraw_);
		Menu::Keyboard input = menu_.getInput();
		processInput(input, selected_option_, first_option_, running, getActionMenu().size());
	}
}

std::vector<std::string> Game::getActionMenu() {
	return {
		"You are now at " + player_.getCurrentLocation().location_name,
		player_.getCurrentLocation().description,
		"Currently at " + player_.getCurrentSubLocation().sublocation_name,
		"What would you like to do?",
		"",
		"Adventure to...",
		"Go to...",
		"Action...",
		"Quit"
	};
}
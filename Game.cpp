#include "Game.hpp"

Game::Game() {
	location_data_ = player_.getCurrentLocationData(player_.getCurrentLocationID());
}

void Game::processInput(Menu::Keyboard& input, int selectedOption, int firstOption, bool& running, size_t optionCount, bool& redraw) {
	menu_.navigateOptions(input, selected_option_, optionCount, firstOption, redraw);
	if (input == Menu::Keyboard::Enter) {
		if (selected_option_ == 5) {
			Travel(input, selectedOption, firstOption, redraw);
		}
		else if (selected_option_ == 6) {
			std::vector<std::string> sublocationList;
			for (auto& location : location_data_.subLocations) {
				sublocationList.push_back(location.sublocation_name);
			}
			processLocalAction(input, selectedOption, firstOption, redraw, sublocationList);
		}
		else if (selected_option_ == 7) {
			executeAction(input, selectedOption, firstOption, redraw);
		}
		redraw = true;
	}
	if (input == Menu::Keyboard::Escape) {
		running = false;
	}
}

// Great Plains works as fine, Forest will break due to access violation
// Need to ensure every location has a minimum 1 sublocation
void Game::Travel(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& redraw) {
	selectedOption = 0;
	firstOption = 0;
	bool locationSelected = false;
	std::vector<std::string> travelList = world_.getAvailableDestinations(player_.getCurrentLocationID());

	while (locationSelected == false) {
		if (redraw == true) {
			menu_.displayActionMenu(travelList, player_.getLocalMap(), selectedOption, redraw);
		}
		input = menu_.getInput();
		menu_.navigateOptions(input, selectedOption, travelList.size(), firstOption, redraw);
		if (input == Menu::Keyboard::Enter) {
			for (auto& location : world_.getAllLocations()) {
				if (location.location_name == travelList[selectedOption]) {
					player_.setCurrentLocation(location.id);
					player_.setCurrentLocalMap(location.id);
					player_.setCurrentSubLocation(location.subLocations[0].id);
					locationSelected = true;
				}
			}
		}
	}
}

void Game::processLocalAction(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& redraw, std::vector<std::string>& subLocationList) {
	selectedOption = 0;
	firstOption = 0;
	bool subLocationSeleceted = false;

	while (subLocationSeleceted == false) {
		if (redraw == true) {
			menu_.displayActionMenu(subLocationList, player_.getLocalMap(), selectedOption, redraw);
		}
		input = menu_.getInput();
		menu_.navigateOptions(input, selectedOption, subLocationList.size(), firstOption, redraw);
		if (input == Menu::Keyboard::Enter) {
			auto& sublocation = location_data_.subLocations[selectedOption].id;
			player_.setCurrentSubLocation(sublocation);
			subLocationSeleceted = true;
		}
	}
}

void Game::executeAction(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& redraw) {
	selectedOption = 0;
	firstOption = 0;
	bool actionSelected = false;
	std::vector<std::string> actionList;

	if (player_.getSublocationID() == World::SubLocationID::TOWN_SQUARE) {
		actionList = { "Look at the quest board", "Stand around", "Return to previous menu"};
	}
	else if (player_.getSublocationID() == World::SubLocationID::BLACKSMITH) {
		actionList = { "Forge a weapon", "Chat", "Return to previous menu"};
	}
	else if (player_.getSublocationID() == World::SubLocationID::GENERAL_STORE) {
		actionList = { "Buy", "Sell", "Return to previous menu" };
	}

	while (actionSelected == false) {
		if (redraw == true) {
			menu_.displayActionMenu(actionList, player_.getLocalMap(), selectedOption, redraw);
		}
		input = menu_.getInput();
		menu_.navigateOptions(input, selectedOption, actionList.size(), firstOption, redraw);
		if (input == Menu::Keyboard::Enter) {
			if(selectedOption == 2)
				actionSelected = true;
		}
	}
}

void Game::gameLoop()
{ 
	bool running = true;
	bool redraw = true;

	menu_.displayLoadingScreen();

	while (running) {
		menu_.displayActionMenu(getActionMenu(), player_.getLocalMap(), selected_option_, redraw);
		Menu::Keyboard input = menu_.getInput();
		processInput(input, selected_option_, first_option_, running, getActionMenu().size(), redraw);
	}
}

std::vector<std::string> Game::getActionMenu() {
	return {
		"You are now at " + player_.getCurrentLocationData(player_.getCurrentLocationID()).location_name,
		player_.getCurrentLocationData(player_.getCurrentLocationID()).description,
		"Currently at " + player_.getSubLocation(player_.getSublocationID()),
		"What would you like to do?",
		"",
		"Adventure to...",
		"Go to...",
		"Action...",
		"Quit"
	};
}
#include "Game.hpp"

Game::Game() {

}

void Game::processInput(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& running, size_t optionCount, bool& redraw) {
	Menu menu;
	menu.navigateOptions(input, selectedOption, optionCount, firstOption, redraw);
}

void Game::gameLoop()
{ 
	int selectedOption = 5;
	int firstOption = 5;
	bool running = true;
	bool redraw = true;

	menu_.displayLoadingScreen();

	while (running) {
		menu_.displayActionMenu(getActionMenu(), player_.getCurrentLocation(player_.getCurrentLocationID()).local_map, selectedOption, redraw);
		Menu::Keyboard input = menu_.getInput();
		processInput(input, selectedOption, firstOption, running, getActionMenu().size(), redraw);
	}
}

std::vector<std::string> Game::getActionMenu() {
	return {
		"You are now at " + player_.getCurrentLocation(player_.getCurrentLocationID()).location_name,
		player_.getCurrentLocation(player_.getCurrentLocationID()).description,
		"Currently at " + player_.getSubLocation(player_.getSublocationID()),
		"What would you like to do?",
		"",
		"Exit Town",
		"Go to...",
		"Open Character sheet",
		"Quit"
	};
}
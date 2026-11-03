#include "MainMenu.hpp"

void MainMenu::processInput(int input, int& selectedOption, bool& running, int optionCount, bool& redraw, bool& startCreation) {
    Menu menu;
    menu.navigateOptions(input, selectedOption, optionCount, redraw);
    if (input == 3) { // Enter
        if (selectedOption == 0) {
            startCreation = true;
            running = false;
        }
    }
    if (input == 4) { // Escape
        running = false;
    }
    redraw = true;
}

bool MainMenu::run() {
    const std::vector<std::string> options =
    {
        "Start Game",
        "Quit"
    };

    Menu menu;
    int selectedOption = 0;
    bool running = true;
    bool redraw = true;
    bool startCreation = false;

    while (running) {
        menu.displayMenu(options, selectedOption, redraw);
        int input = menu.getInput();
        processInput(input, selectedOption, running, options.size() - 1, redraw, startCreation);
    }
    return startCreation;
}
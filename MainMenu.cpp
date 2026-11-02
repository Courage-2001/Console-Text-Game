#include "MainMenu.hpp"

void MainMenu::processInput(int input, int& selectedOption, bool& running, int optionCount, bool& redraw, bool& startCreation) {
    switch (input)
    {
    case 0: // Do nothing
        break;
    case 1: // Up
        if (selectedOption > 0) {
            selectedOption--;
            redraw = true;
        }
        else if (selectedOption == 0) {
            selectedOption = optionCount - 1;
            redraw = true;
        }
        break;
    case 2: // Down
        if (selectedOption < optionCount - 1) {
            selectedOption++;
            redraw = true;
        }
        else if (selectedOption == optionCount - 1) {
            selectedOption = 0;
            redraw = true;
        }
        break;
    case 3: // Enter
        if (selectedOption == 0)
            startCreation = true;
            running = false;
        break;
    case 4: // Escape
        running = false;
        break;
    }
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
        processInput(input, selectedOption, running, options.size(), redraw, startCreation);
    }
    return startCreation;
}
#include "MainMenu.hpp"

void MainMenu::processInput(Menu::Keyboard input, int& selectedOption, bool& running, int optionCount, bool& redraw, bool& startCreation) {
    Menu menu;
    menu.navigateOptions(input, selectedOption, optionCount, redraw);
    if (input == Menu::Keyboard::Enter) {
        if (selectedOption == 0) {
            startCreation = true;
            running = false;
        }
        else if (selectedOption == optionCount - 1) {
            running = false;
        }
    }
    if (input == Menu::Keyboard::Escape) {
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
        Menu::Keyboard input = menu.getInput();
        processInput(input, selectedOption, running, options.size(), redraw, startCreation);
    }
    return startCreation;
}
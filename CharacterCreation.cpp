#include "CharacterCreation.hpp"

void CharacterCreation::processInput(int input, int& selectedOption, bool& running, int optionCount, bool& redraw, PlayerData& player) {
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
        if (selectedOption == 0) {
            system("cls");
            std::cout << "Enter a name: ";
            std::getline(std::cin, player.name);
            redraw = true;
        }
        else if (selectedOption == 1) {
            processClass(player);
        }
        redraw = true;
        break;
    case 4: 
        running = false;
        break;
    }
}

void CharacterCreation::processClass(PlayerData& player) {
    bool classSelected = false;
    int selectedClass = 0;
    std::vector<std::string> classList = { "Warrior", "Mage" };
    bool submenuRedraw = true;
    Menu submenu;
    while (classSelected == false) {
        if (submenuRedraw == true) {
            system("cls");
            for (int i = 0; i < classList.size(); i++)
            {
                if (i == selectedClass)
                    std::cout << " > " << classList[i] << '\n';
                else
                    std::cout << "   " << classList[i] << '\n';
            }
            submenuRedraw = false;
        }
        int input = submenu.getInput();
        switch (input)
        {
        case 0:
            break;
        case 1:
            if (selectedClass > 0) {
                selectedClass--;
                submenuRedraw = true;
            }
            else if (selectedClass == 0) {
                selectedClass = classList.size() - 1;
                submenuRedraw = true;
            }
            break;
        case 2:
            if (selectedClass < classList.size() - 1) {
                selectedClass++;
                submenuRedraw = true;
            }
            else if (selectedClass == classList.size() - 1) {
                selectedClass = 0;
                submenuRedraw = true;
            }
            break;
        case 3:
            player.characterClass = classList[selectedClass];
            classSelected = true;
            break;
        }
    }
}

std::vector<std::string> CharacterCreation::getDetails() {
    return {
        "Name: " + player.name,
        "Class: " + player.characterClass,
        "Health: " + std::to_string(player.health),
        "Strength: " + std::to_string(player.strength),
        "Intelligence: " + std::to_string(player.intelligence)
    };
}

bool CharacterCreation::run() {
	Menu menu;
    int selectedOption = 0;
    bool running = true;
    bool redraw = true;
    bool startGame = false;

    while (running) {
        const std::vector<std::string> details = getDetails(); // can be costly once more variables are introduced
        menu.displayMenu(details, selectedOption, redraw);
        int input = menu.getInput();
        processInput(input, selectedOption, running, details.size(), redraw, player);
    }
    return startGame;
}


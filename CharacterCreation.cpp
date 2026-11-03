#include "CharacterCreation.hpp"

void CharacterCreation::processInput(int input, int& selectedOption, bool& running, int optionCount, bool& redraw, PlayerData& player, bool& startGame) {
    Menu menu;
    menu.navigateOptions(input, selectedOption, optionCount, redraw);
    if (input == 3) { // Enter
        if (selectedOption == 0) {
            system("cls");
            std::cout << "Enter a name: ";
            std::getline(std::cin, player.name);
        }
        else if (selectedOption == 1) {
            processClass(player);
        }
        else if (selectedOption == 2) {
            processTraits(player);
        }
        else if (selectedOption == optionCount - 1) {
            if (player.name != "ENTER NAME" && player.characterClass != "ENTER CLASS" && player.numberOfTraits == 2) {
                startGame = true;
                running = false;
            }
            else {
                system("cls");
                std::cout << "You are missing either name, class, or have not selected max number of traits.";
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        }
        redraw = true;
    }
    if (input == 4) { //Escape
        running = false;
    }
}

void CharacterCreation::processClass(PlayerData& player) {
    bool classSelected = false;
    int selectedClass = 0;
    bool submenuRedraw = true;
    Menu submenu;
    std::vector<std::string> classList;
    std::vector<PlayerData> classData = {
        {"NULL", "Warrior", {}, 15, 5, -5},
        {"NULL", "Mage", {}, -10, -5, 15}
    };
    for (auto i : classData) {
        classList.push_back(i.characterClass);
    }

    while (classSelected == false) {
        if (submenuRedraw == true) {
            submenu.displayMenu(classList, selectedClass, submenuRedraw);
        }
        int input = submenu.getInput();
        submenu.navigateOptions(input, selectedClass, classList.size(), submenuRedraw);
        if(input == 3) {
            if (player.characterClass == classList[selectedClass]) {
                system("cls");
                std::cout << "You have already selected this class!";
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            else {
                for (auto i : classData) {
                    if (player.characterClass == i.characterClass) {
                        player.health -= i.health;
                        player.strength -= i.strength;
                        player.intelligence -= i.intelligence;
                    }
                }
                player.characterClass = classData[selectedClass].characterClass;
                player.health += classData[selectedClass].health;
                player.strength += classData[selectedClass].strength;
                player.intelligence += classData[selectedClass].intelligence;
            }
            classSelected = true;
        }
    }
}
//Eventually would like it so player can replace other traits if they change their mind later
void CharacterCreation::processTraits(PlayerData& player) {
    bool traitSelected = false;
    int selectedTrait = 0;
    bool submenuRedraw = true;
    bool exists = false;
    Menu submenu;
    std::vector<std::string> traitList;
    std::vector<Traits> traitData = {
        {"Hearty", "You are more resilient and filled with mental fortitude.", 10, 5, 0},
        {"Scholar", "You took your time educating yourself in the mystic arts.", 0, 0, 10}
    };
    for (auto i : traitData) {
        traitList.push_back(i.traitName + "                  " + i.traitDescription);
    }
    while (traitSelected == false) {
        if (submenuRedraw == true) {
            submenu.displayMenu(traitList, selectedTrait, submenuRedraw);
        }
        int input = submenu.getInput();
        submenu.navigateOptions(input, selectedTrait, traitList.size(), submenuRedraw);
        if (input == 3) {
            exists = std::find(player.traits.begin(), player.traits.end(), traitList[selectedTrait]) != player.traits.end();
            if (!exists && player.numberOfTraits < 2) {
                player.traits.push_back(traitData[selectedTrait].traitName);
                player.health += traitData[selectedTrait].healthModifier;
                player.strength += traitData[selectedTrait].strengthModifier;
                player.intelligence += traitData[selectedTrait].intelligenceModifier;
                player.numberOfTraits++;
            }
            else if (player.numberOfTraits == 2) {
                system("cls");
                std::cout << "You have reached the trait cap!";
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            else if (exists) {
                system("cls");
                std::cout << "You have already selected this trait.";
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            traitSelected = true;
        }
    }
}

std::vector<std::string> CharacterCreation::getDetails() {
    std::string traits;
    for (auto i : player.traits) {
        traits = traits + i + ", ";
    }
    return {
        "Name: " + player.name,
        "Class: " + player.characterClass,
        "Traits: " + traits,
        "Health: " + std::to_string(player.health),
        "Strength: " + std::to_string(player.strength),
        "Intelligence: " + std::to_string(player.intelligence),
        "Start game"
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
        processInput(input, selectedOption, running, details.size(), redraw, player, startGame);
    }
    return startGame;
}


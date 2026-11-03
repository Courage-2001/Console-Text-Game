#include "Menu.hpp"

//Eventually need to pass in variable that dynamically changes menu title depending on which menu is active
void Menu::displayMenu(const std::vector<std::string>& options, int selectedOption, bool& redraw) {
    if (redraw == true) {
        system("cls");
        std::cout << "============================\n";
        std::cout << "       PLACE HOLDER\n";
        std::cout << "============================\n\n";

        for (int i = 0; i < options.size(); i++)
        {
            if (i == selectedOption)
                std::cout << " > " << options[i] << '\n';
            else
                std::cout << "   " << options[i] << '\n';
        }
        redraw = false;
    }
}

Menu::Keyboard Menu::getInput() const {
    int key = _getch();
    if (key == static_cast<int>(Keyboard::SpecialKey) || key == static_cast<int>(Keyboard::ExtendedKey)) {
        key = _getch();
        switch (static_cast<Keyboard>(key)) {
        case Keyboard::UpArrow: return Keyboard::UpArrow;
        case Keyboard::DownArrow: return Keyboard::DownArrow;
        }
    }
    switch (static_cast<Keyboard>(key)) {
    case Keyboard::Enter: return Keyboard::Enter;
    case Keyboard::Escape: return Keyboard::Escape;
    }
    return Keyboard::Null;
}

void Menu::navigateOptions(Keyboard input, int& selectedOption, int optionCount, bool& redraw) {
    switch (input)
    {
    case Keyboard::Null: // Do nothing
        break;
    case Keyboard::UpArrow: // Up
        if (selectedOption > 0) {
            selectedOption--;
            redraw = true;
        }
        else if (selectedOption == 0) {
            selectedOption = optionCount - 1;
            redraw = true;
        }
        break;
    case Keyboard::DownArrow: // Down
        if (selectedOption < optionCount - 1) {
            selectedOption++;
            redraw = true;
        }
        else if (selectedOption == optionCount - 1) {
            selectedOption = 0;
            redraw = true;
        }
        break;
    }
}
#include "Menu.hpp"

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

int Menu::getInput() {
    int key = _getch();
    if (key == static_cast<int>(Keyboard::SpecialKey) || key == static_cast<int>(Keyboard::ExtendedKey)) {
        key = _getch();
        switch (static_cast<Keyboard>(key)) {
        case Keyboard::UpArrow: return 1;
        case Keyboard::DownArrow: return 2;
        }
    }
    switch (static_cast<Keyboard>(key)) {
    case Keyboard::Enter: return 3;
    case Keyboard::Escape: return 4;
    }
    return 0;
}
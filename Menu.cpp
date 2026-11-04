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

void Menu::displayActionMenu(const std::vector<std::string>& menuOptions, const std::vector<std::string>& localmap, int selectedOption, bool& redraw) {
    if (redraw == true) {
        system("cls");
        size_t maxLines = std::max(menuOptions.size(), localmap.size());

        for (size_t i = 0; i < maxLines; i++) {
            std::string left;
            if (i < menuOptions.size())
            {
                if (i == selectedOption)
                    left = " > " + menuOptions[i];
                else
                    left = "   " + menuOptions[i];
            }

            std::string right = i < localmap.size() ? localmap[i] : "";

            std::cout << std::left
                << std::setw(75) << left
                << right << '\n';
        }
    }
}

void Menu::displayLoadingScreen() {
    system("cls");
    for (int i = 0; i < loading_screen_.size(); i++) {
        std::cout << loading_screen_[i] << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
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

void Menu::navigateOptions(Keyboard& input, int& selectedOption, size_t optionCount, int& firstOption, bool& redraw) {
    switch (input)
    {
    case Keyboard::Null: // Do nothing
        break;
    case Keyboard::UpArrow: // Up
        if (selectedOption > firstOption) {
            selectedOption--;
            redraw = true;
        }
        else if (selectedOption == firstOption) {
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
            selectedOption = firstOption;
            redraw = true;
        }
        break;
    }
}
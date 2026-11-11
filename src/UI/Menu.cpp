#include "UI/Menu.hpp"

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

void Menu::displayActionMenu(const std::vector<std::string>& menuOptions, const std::vector<std::string>& localmap, int selectedOption, bool& redraw_) {
    if (redraw_ == true) {
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

void Menu::displayLoadingScreen(const int& loading_screen) {
    system("cls");
    std::vector<std::string> loadingScreen;
    if (loading_screen == 1) {
        loadingScreen = loading_screen_1;
    }
    else if (loading_screen == 2) {
        loadingScreen = loading_screen_2;
    }

    // Gathering Dimensions of rows and columns (in this case how many characters exist in 1 row)
    size_t rows = loadingScreen.size();
    size_t columns = 0;
    for (const auto& line : loadingScreen) {
        columns = std::max(columns, line.length());
    }

    // the command is ESC[row;columnH , \033 represents ESC, signalling beginning of terminal command in ANSI
    // reversed loop so that we properly print ASCII image correctly
    for (size_t col = 0; col < columns; col++) {
        for (size_t row = 0; row < rows; row++) {
            std::cout << "\033[" << row + 1 << ";" << col + 1 << "H";

            if (col < loadingScreen[row].length()) {
                std::cout << loadingScreen[row][col];
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
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
    case Keyboard::KeyC: return Keyboard::KeyC;
    }
    return Keyboard::Null;
}

void Menu::navigateOptions(Keyboard& input, int& selectedOption, size_t optionCount, int& firstOption, bool& redraw_) {
    switch (input)
    {
    case Keyboard::Null: // Do nothing
        break;
    case Keyboard::UpArrow: // Up
        if (selectedOption > firstOption) {
            selectedOption--;
        }
        else if (selectedOption == firstOption) {
            selectedOption = optionCount - 1;
        }
        redraw_ = true;
        break;
    case Keyboard::DownArrow: // Down
        if (selectedOption < optionCount - 1) {
            selectedOption++;
        }
        else if (selectedOption == optionCount - 1) {
            selectedOption = firstOption;
        }
        redraw_ = true;
        break;
    }
}
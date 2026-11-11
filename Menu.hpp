#pragma once
#include <vector>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <thread>
#include <chrono>

class Menu
{
public:
    enum class Keyboard
    {
        Null = -1,
        SpecialKey = 0,
        ExtendedKey = 224,

        UpArrow = 72,
        DownArrow = 80,
        LeftArrow = 75,
        RightArrow = 77,

        Enter = 13,
        Escape = 27,

        KeyC = 99
    };

    void displayMenu(const std::vector<std::string>& options, int selectedOption, bool& redraw);
    void displayActionMenu(const std::vector<std::string>& menuOptions, const std::vector<std::string>& localmap, int selectedOption, bool& redraw);
    void displayLoadingScreen(const int& loading_screen);
    Keyboard getInput() const;
    void navigateOptions(Keyboard& input, int& selectedOption, size_t optionCount, int& firstOption, bool& redraw);

private:
    std::vector<std::string> loading_screen_1 = {
      R"(    |         _______          __          ______       +   |\      |    ___________  )",
      R"(    |        |       |        /  \        |      \          | \     |    |            )",
      R"(    |        |       |       /    \       |       \     |   |  \    |    |            )", 
      R"(    |        |       |      /______\      |       |     |   |   \   |    |     _____  )",
      R"(    |        |       |     /        \     |       |     |   |    \  |    |         |  )", 
      R"(    |        |       |    /          \    |       /     |   |     \ |    |         |  )",
      R"(    |_____   |_______|   /            \   |______/      |   |      \|    |_________|  )"
    };

    std::vector<std::string> loading_screen_2 = {
        R"(                _________________                         _________________                         _________________                   )",
        R"(               |                 \                       |                 \                       |                 \                  )",
        R"(               \___________       \                      \___________       \                      \___________       \                 )",
        R"(                           \      |                                  \      |                                  \      |                 )",
        R"(                            \_____/                                   \_____/                                   \_____/                 )",
        R"(                                                                                                                                        )",
        R"(                  _____                              _____                              _____                              _____        )",
        R"(                 /     \                            /     \                            /     \                            /     \       )",
        R"(    ____________/      |               ____________/      |               ____________/      |               ____________/      |       )",
        R"(   |                  /               |                  /               |                  /               |                  /        )",
        R"(    \________________/                 \________________/                 \________________/                 \________________/         )"
    };
};


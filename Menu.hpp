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
        Escape = 27
    };

    void displayMenu(const std::vector<std::string>& options, int selectedOption, bool& redraw);
    void displayActionMenu(const std::vector<std::string>& menuOptions, const std::vector<std::string>& localmap, int selectedOption, bool& redraw);
    void displayLoadingScreen();
    Keyboard getInput() const;
    void navigateOptions(Keyboard& input, int& selectedOption, size_t optionCount, int& firstOption, bool& redraw);

private:
    std::vector<std::string> loading_screen_ = {
      R"(    |         _______          __          ______       +   |\      |    ___________  )",
      R"(    |        |       |        /  \        |      \          | \     |    |            )",
      R"(    |        |       |       /    \       |       \     |   |  \    |    |            )", 
      R"(    |        |       |      /______\      |       |     |   |   \   |    |     _____  )",
      R"(    |        |       |     /        \     |       |     |   |    \  |    |         |  )", 
      R"(    |        |       |    /          \    |       /     |   |     \ |    |         |  )",
      R"(    |_____   |_______|   /            \   |______/      |   |      \|    |_________|  )"
    };
};


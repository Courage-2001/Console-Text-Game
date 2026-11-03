#pragma once
#include <vector>
#include <iostream>
#include <conio.h>

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
    Keyboard getInput() const;
    void navigateOptions(Keyboard input, int& selectedOption, int optionCount, bool& redraw);
};


#pragma once
#include "Menu.hpp"

class MainMenu {
public:
    bool run();
private: 
	void processInput(Menu::Keyboard input, int& selectedOption, bool& running, int optionCount, bool& redraw, bool& startCreation);
};
#pragma once
#include "UI/Menu.hpp"

class MainMenu {
public:
    bool run();
private: 
	void processInput(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& running, size_t optionCount, bool& redraw, bool& startCreation);
};
#pragma once
#include "World.hpp"
#include "Player.hpp"
#include "Menu.hpp"

class Game {
public:
    Game();
    void gameLoop();
    std::vector<std::string> getActionMenu();
    void processInput(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& running, size_t optionCount, bool& redraw);

private:
    World world_;
    Player player_;
    Menu menu_;
    //void loadStartingArea();
    //void displayAreaMenu();
    //void travel();
    //void performAction();
};
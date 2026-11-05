#pragma once
#include "World.hpp"
#include "Player.hpp"
#include "Menu.hpp"

class Game {
public:
    Game();
    Game(const CharacterCreation::PlayerData& playerData);
    void gameLoop();
    std::vector<std::string> getActionMenu();
    void processInput(Menu::Keyboard& input, int selectedOption, int first_option_, bool& running, size_t optionCount, bool& redraw);
    void Travel(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& redraw);
    void processLocalAction(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& redraw, std::vector<std::string>& subLocationList);
    void executeAction(Menu::Keyboard& input, int& selectedOption, int& firstOption, bool& redraw);
private:
    int selected_option_ = 5;
    int first_option_ = 5;
    World::Location location_data_;
    World world_;
    Player player_;
    Menu menu_;
    //void loadStartingArea();
    //void displayAreaMenu();
};
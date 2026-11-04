#include "MainMenu.hpp"
#include "CharacterCreation.hpp"
#include "Game.hpp"

int main()
{
    MainMenu menu;
    if (menu.run() == true) {
        CharacterCreation create;
        if (create.run() == true) {
            Game startGame;
            startGame.gameLoop();
        }
    }
    return 0;
}



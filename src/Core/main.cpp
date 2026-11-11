#include "UI/MainMenu.hpp"
#include "UI/CharacterCreation.hpp"
#include "Core/Game.hpp"

int main()
{
    MainMenu menu;
    if (menu.run() == true) {
        CharacterCreation create;
        if (create.run() == true) {
            Game startGame(create.getPlayerData());
            startGame.gameLoop();
        }
    }
    return 0;
}



#include "MainMenu.hpp"
#include "CharacterCreation.hpp"

int main()
{
    MainMenu menu;
    if (menu.run() == true) {
        CharacterCreation create;
        create.run();
    }
    return 0;
}



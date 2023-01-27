#include "Game.h"

int main()
{
    
    Game game;

    while (game.getIsWindowOpen())
    {

        game.update();
        game.render();

    }

    return 0;
}
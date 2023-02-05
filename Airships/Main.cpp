#include "Game.h"
#include <time.h>
int main()
{
    
    srand(time(NULL));

    Game game;

    while (game.getIsWindowOpen())
    {

        game.update();
        game.render();

    }

    return 0;
}
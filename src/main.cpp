#define SDL_MAIN_HANDLED

#include <iostream>

#include "Resource/Resource.h"
#include "System/Game.h"

/**
 * Main entry point
 * @return -
 */
int main()
{
    std::cout << Resource::getResourcePath() << std::endl;

    Game game;
    game.run();

    return 0;
}

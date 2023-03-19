#define SDL_MAIN_HANDLED

#include "Resource.h"
#include "Game.h"

#include <iostream>

/**
 * Main entry point
 * @return -
 */
int main(int argc, char** argv)
{
    std::string defaultConfigPath = "../cnfg";
    std::cout << Resource::getResourcePath() << " argc: " <<  argc <<  std::endl;

    Game game;
    game.configure(defaultConfigPath);
    game.run();

    return 0;
}

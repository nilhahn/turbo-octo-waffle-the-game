#define SDL_MAIN_HANDLED

#include <iostream>

#include "Resource/Resource.h"
#include "System/Game.h"

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

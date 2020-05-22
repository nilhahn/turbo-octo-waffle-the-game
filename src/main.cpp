#include <iostream>

#include "Resource/Resource.h"
#include "System/Game.h"

int main()
{
    std::cout << Resource::getResourcePath() << std::endl;

    Game game;
    game.run();

    return 0;
}

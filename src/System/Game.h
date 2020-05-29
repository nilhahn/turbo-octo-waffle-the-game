//
// Created by matze on 11.05.20.
//

#ifndef SFRPG_GAME_H
#define SFRPG_GAME_H

#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "../Resource/Resource.h"
#include "../window/Window.h"
#include "../Resource/TextureManager.h"
#include "../World/WorldObject.h"

class Game {
public:
    Game();
    ~Game();

    void run();
private:
    bool init();
    void render();
    void handleEvents();
    bool isRunning();

    bool running;

    Window* window;
    TextureManager* textureManager;
    std::vector<WorldObject*> objects;

    void initPlayer();
};


#endif //SFRPG_GAME_H

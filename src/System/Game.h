//
// Created by matze on 11.05.20.
//

#ifndef SFRPG_GAME_H
#define SFRPG_GAME_H

#include "Window.h"

class Game {
public:
    Game();
    ~Game() = default;

    void run();
private:
    bool init();
    void render();
    void handleEvents();
    bool isRunning();

    bool running;

    Window* window;
};


#endif //SFRPG_GAME_H

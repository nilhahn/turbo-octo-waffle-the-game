//
// Created by matze on 11.05.20.
//

#ifndef SFRPG_GAME_H
#define SFRPG_GAME_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "../Resource/Resource.h"
#include "../window/Window.h"
#include "../Resource/TextureManager.h"
#include "../World/WorldObject.h"

class Game {
public:
    Game();
    ~Game() = default;

    void run();
private:
    bool init();
    void render();
    void handleEvents(long delta);
    bool isRunning();
    void initPlayer();
    void initMonster(int monster);
    void initSkeleton();
    void inputEvent(WorldObject* object, long deltaMs);
    bool isKeyDown(const Uint8* keyStates, SDL_Scancode key);
    void quit(const char* reason = nullptr);

    bool running;

    const int FPS;

    Window* window;
    TextureManager* textureManager;
    std::map<std::string, std::unique_ptr<WorldObject> > objects;

    void update(long i);
};


#endif //SFRPG_GAME_H

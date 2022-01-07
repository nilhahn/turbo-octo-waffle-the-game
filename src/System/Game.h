#ifndef SFRPG_GAME_H
#define SFRPG_GAME_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "../Resource/Resource.h"
#include "../Window/Window.h"
#include "../Resource/TextureManager.h"
#include "../World/WorldObject.h"
#include "../Window/Camera.h"
#include "Layer/BackgroundLayer.h"

// TODO: create super class state, in order to manage state changes
class Game {
public:
    Game();
    ~Game() = default;

    void run();
private:
    bool init();
    void render(long delta);
    void handleEvents(long delta);
    bool isRunning();

    void inputEvent(WorldObject* object, long deltaMs);
    bool isKeyDown(const Uint8* keyStates, SDL_Scancode key);
    void quit(const char* reason = nullptr);

    void initMonster(int monster);
    void initSkeleton();
    void initPlayer();
    void initMarker();

    bool running;

    const int FPS;

    Window* window;
    Camera camera;
    TextureManager* textureManager;
    BackgroundLayer background;

    std::map<std::string, std::unique_ptr<WorldObject> > objects;

    void update(long delta);
};


#endif //SFRPG_GAME_H

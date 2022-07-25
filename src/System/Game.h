#ifndef SFRPG_GAME_H
#define SFRPG_GAME_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "Context.h"
#include "../Resource/Resource.h"
#include "../Resource/TextureManager.h"
#include "../World/WorldObject.h"
#include "../Window/Camera.h"
#include "Layer/Background/BackgroundLayer.h"
#include "Entity/Entity.h"
#include "Factory/Factories.h"

/**
 * The main game class.
 */

// TODO: create super class state, in order to manage state changes
class Game {
public:
    Game();
    ~Game() = default;

    void run();

    void configure(std::string& configFilePath);

private:
    bool init();
    void render(long delta);
    void handleEvents(long delta);
    bool isRunning();

    void inputEvent(long deltaMs);
    bool isKeyDown(const Uint8* keyStates, SDL_Scancode key);
    void quit(const char* reason = nullptr);

    // Some prototypes in order to test the creation of new entities in the world
    void initMonster(int monster);
    void initSkeleton();
    void initPlayer();
    void initMarker();

    bool running;

    const int FPS;

    Context* context;
    Canvas canvas;
    Camera camera;
    BackgroundLayer background;

    std::map<std::string, std::unique_ptr<WorldObject> > objects;
    std::map<std::string, std::unique_ptr<Entity> > entities;

    void update(long delta);

    void initMage();

    bool isInStateLeftOrDown(EntityState::ObjectState param);

    bool collide(HitBox& hitBox);
};


#endif //SFRPG_GAME_H

#include "Game.h"
#include "../World/Objects/Player.h"
#include "../World/Objects/Skeleton.h"
#include "../World/Objects/Marker.h"

#include <iostream>

#define PLAYER_ID "player"
#define SKELETON_ID "skeleton"
#define MAGE_ID "mage"
#define DEBUG_MARKER_ID "__marker__"
#undef DEBUG_MARKER_ID

Game::Game() : FPS(60) {
    this->running = false;
    this->context = nullptr;
}

bool Game::init() {
    std::string title = "turbo-octo-waffel";

    int windowWidth = 512;
    int windowHeight = 512;
    Vector2D initalCameraPos(0, 0);

    std::string resourcePath = Resource::getResourcePath();
    Window *window = Window::create(title, windowWidth, windowHeight, resourcePath);
    this->context = new Context(window);

    this->camera.init(windowWidth, windowHeight, initalCameraPos);

    this->background.init(*this->context);

    this->initPlayer();
#ifdef DEBUG_MARKER_ID
    this->initMarker();
#endif
    this->initMonster(0);
    this->initMonster(1);

    this->running = this->context->getWindow() != nullptr && this->context->getWindow()->getRenderer() != nullptr;
    return this->running;
}

/**
 * draw stuff to the Window
 */
void Game::render(long delta) {
    SDL_Renderer *renderer = this->context->getWindow()->getRenderer();
    SDL_RenderClear(renderer);;

    this->background.draw(*context, camera, canvas);

    for (auto iter = this->objects.begin(); iter != this->objects.end(); iter++) {
        auto elem = iter->second.get();
        elem->draw(*context, this->camera, this->canvas, delta);
    }

    SDL_RenderPresent(renderer);
}

void Game::handleEvents(long delta) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        this->quit();
    } else {
        auto playerObj = &this->objects.at(PLAYER_ID);
        WorldObject::ObjectState playerState = playerObj->get()->getState();
        this->inputEvent(playerObj->get(), delta);

#ifdef DEBUG_MARKER_ID
        if (playerState != playerObj->get()->getState()) {
            this->objects.at(DEBUG_MARKER_ID)->setState(playerObj->get()->getState());
        }
#endif
    }
}

bool Game::isRunning() {
    return this->running;
}

void Game::run() {
    long frameStart = 0;
    long frameTime = 0;
    long delayTime = static_cast<long>(1000.00f / static_cast<float>(FPS));

    if (this->init()) {
        while (this->isRunning()) {
            frameStart = SDL_GetTicks();
            this->render(frameTime);
            this->handleEvents(frameTime);
            this->update(frameTime);
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < delayTime) {
                SDL_Delay(frameTime - frameTime);
            }
        }
        this->context->getTextureManager()->clear();
    }
}

void Game::initPlayer() {
    InitalizationMapper init;

    init.setObjectId(PLAYER_ID);
    init.setInitalPosition(Vector2D(camera.getCenter()->getX() - 8.5f, camera.getCenter()->getY() - 9.5f));
    
    auto idleDrawable = new Drawable("Player_Idle",  17, 19, 4);

    this->context->getTextureManager()->addTextureAndId("Player_Idle", "Knight_Base_idle.png");

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::LEFT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::RIGHT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::UP, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::DOWN, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(
            std::pair<std::string, std::unique_ptr<WorldObject> >(PLAYER_ID, std::make_unique<Player>(&init)));
}

void Game::inputEvent(WorldObject *object, long deltaMs) {
    int size = 0;

    const Uint8 *keystates = SDL_GetKeyboardState(&size);
    Vector2D vector;

    if (object->getState() != WorldObject::DEAD) {

        if (isKeyDown(keystates, SDL_SCANCODE_W)) {
            object->setState(WorldObject::UP);
            vector.setY(-0.1f * static_cast<float>(deltaMs));
        } else if (isKeyDown(keystates, SDL_SCANCODE_S)) {
            object->setState(WorldObject::DOWN);
            vector.setY(+0.1f * static_cast<float>(deltaMs));
        }

        if (isKeyDown(keystates, SDL_SCANCODE_A)) {
            object->setState(WorldObject::LEFT);
            vector.setX(-0.1f * static_cast<float>(deltaMs));
        } else if (isKeyDown(keystates, SDL_SCANCODE_D)) {
            object->setState(WorldObject::RIGHT);
            vector.setX(+0.1f * static_cast<float>(deltaMs));
        }
    }

    camera.move(vector);
}

bool Game::isKeyDown(const Uint8 *keyStates, SDL_Scancode key) {
    if (keyStates != nullptr) {
        return keyStates[key] == 1;
    }
    return false;
}

void Game::quit(const char *reason) {
    if (reason != nullptr) {
        std::cout << "Application quit due to " << std::endl;
    }
    this->running = false;
}

void Game::initMonster(int monster) {
    if (monster == 0) {
        this->initSkeleton();
    } else if (monster == 1) {
        this->initMage();
    }
}

void Game::initSkeleton() {
    InitalizationMapper init;

    std::string skeletonId = SKELETON_ID;

    init.setObjectId(skeletonId.data());
    init.setInitalPosition(Vector2D(2, 2));

    // TODO: initialisation should be done via file input
    auto idleDrawable = new Drawable("Skeleton_Idle", 17, 19, 1);

    this->context->getTextureManager()->addTextureAndId("Skeleton_Idle", "Skeleton_Base.png");

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::LEFT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::RIGHT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::UP, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::DOWN, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(std::pair<std::string, std::unique_ptr<WorldObject> >(skeletonId.data(),
                                                                               std::make_unique<Skeleton>(&init)));
}


void Game::initMage() {
    InitalizationMapper init;

    std::string mageId = MAGE_ID;

    init.setObjectId(mageId.data());
    init.setInitalPosition(Vector2D(64, 64));

    // TODO: initialisation should be done via file input
    auto idleDrawable = new Drawable("Mage_idle", 17, 19, 4);

    this->context->getTextureManager()->addTextureAndId("Mage_idle", "Mage_Base_Idle.png");

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::LEFT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::RIGHT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::UP, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::DOWN, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(
            std::pair<std::string, std::unique_ptr<WorldObject> >(mageId.data(), std::make_unique<Skeleton>(&init)));
}

void Game::initMarker() {
#ifdef DEBUG_MARKER_ID
    InitalizationMapper init;

    std::string debugMarkerId = DEBUG_MARKER_ID;

    init.setObjectId(debugMarkerId.data());
    init.setInitalPosition(Vector2D(camera.getCenter()->getX() - 64, camera.getCenter()->getY() - 9.5));

    auto drawable = new Drawable("RED_DEBUG_MARKER", "red_arrow.png", 24, 11, 1);

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(std::pair<std::string, std::unique_ptr<WorldObject> >(debugMarkerId.data(),
                                                                               std::make_unique<Marker>(&init)));
#endif
}

void Game::update(long delta) {
    for (auto iter = this->objects.begin(); iter != this->objects.end(); iter++) {
        auto elem = iter->second.get();
        elem->update(delta);
    }
}

void Game::configure(std::string &configFilePath) {

}



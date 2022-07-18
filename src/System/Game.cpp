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
    Vector2Df initalCameraPos(0, 0);

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

    for (auto iter = this->entities.begin(); iter != entities.end(); iter++) {
        auto state = iter->second->getProperty<EntityState>()->getState();
        auto drawable = iter->second->getProperty<StatefulDrawable>()->getDrawable(state);
        auto position = iter->second->getProperty<Hitbox>();
        canvas.draw(*context, position->getCornerSquare(), const_cast<Drawable &>(*drawable), delta,
                    this->isInStateLeftOrDown(state));
    }

    SDL_RenderPresent(renderer);
}

void Game::handleEvents(long delta) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        this->quit();
    } else {
        // TODO remove usage of nullptr
        this->inputEvent(nullptr, delta);

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
    PlayerController controller;

    this->entities.insert(
            std::pair<std::string, std::unique_ptr<Entity> >(PlayerController::entityId,
                                                             std::make_unique<Entity>(controller.createId()))
    );
    controller.createEntity(*this->entities.at(PlayerController::entityId).get(), *context, camera);
}

void Game::inputEvent(WorldObject *object, long deltaMs) {
    int size = 0;

    const Uint8 *keystates = SDL_GetKeyboardState(&size);
    EntityState::ObjectState state{EntityState::IDLE};
    Vector2Df vector;

    if (entities.at(PlayerController::entityId)->getProperty<EntityState>()->getState() != EntityState::DEAD) {

        if (isKeyDown(keystates, SDL_SCANCODE_W)) {
            state = EntityState::UP;
            vector.setY(-0.1f * static_cast<float>(deltaMs));
        } else if (isKeyDown(keystates, SDL_SCANCODE_S)) {
            state = EntityState::DOWN;
            vector.setY(+0.1f * static_cast<float>(deltaMs));
        }

        if (isKeyDown(keystates, SDL_SCANCODE_A)) {
            state = EntityState::DOWN;
            vector.setX(-0.1f * static_cast<float>(deltaMs));
        } else if (isKeyDown(keystates, SDL_SCANCODE_D)) {
            state = EntityState::RIGHT;
            vector.setX(+0.1f * static_cast<float>(deltaMs));
        }
        entities.at(PlayerController::entityId)->getProperty<EntityState>()->setState(state);
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

    SkeletonController controller;

    std::string entityId{controller.createId()};

    this->entities.insert(
            std::pair<std::string, std::unique_ptr<Entity> >(entityId, std::make_unique<Entity>(entityId))
    );
    controller.createEntity(*this->entities.at(entityId).get(), *context, camera);
}

void Game::initMage() {
    InitalizationMapper init;

    std::string mageId = MAGE_ID;

    init.setObjectId(mageId.data());
    init.setInitalPosition(Vector2Df(64, 64));

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

bool Game::isInStateLeftOrDown(EntityState::ObjectState param) {
    return param == EntityState::LEFT || param == EntityState::DOWN;
}

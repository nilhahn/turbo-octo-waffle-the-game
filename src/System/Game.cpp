//
// Created by matze on 11.05.20.
//

#include "Game.h"
#include "../World/Objects/Player.h"

#define PLAYER_ID "player"

Game::Game():FPS(60) {
    this->running = false;
    this->window = nullptr;
    this->textureManager = nullptr;
}

bool Game::init() {
    std::string title = "turbo-octo-waffel";
    this->window = Window::create(title,512,512);
    this->textureManager = TextureManager::instance(Resource::getResourcePath());
    this->initPlayer();

    this->running = this->window != nullptr && this->window->getRenderer() != nullptr;
    return this->running;
}

void Game::render() {
    SDL_Renderer* renderer = this->window->getRenderer();
    //SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderClear(renderer);

    for(auto iter = this->objects.begin(); iter != this->objects.end(); iter++) {
        auto elem = iter->second.get();
        elem->draw(this->textureManager, this->window->getRenderer());
    }

    SDL_RenderPresent(renderer);
}

void Game::handleEvents(long delta) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
        this->quit();
    } else {
        this->inputEvent(this->objects.at(PLAYER_ID).get(), delta);
    }
}

bool Game::isRunning() {
    return this->running;
}

void Game::run() {
    long frameStart = 0;
    long frameTime = 0;
    long delayTime = static_cast<long>(1000.00f / static_cast<float>(FPS));

    if(this->init()) {
        while(this->isRunning()) {
            frameStart = SDL_GetTicks();
            this->render();
            this->handleEvents(frameTime);
            frameTime = SDL_GetTicks() - frameStart;
            if(frameTime < delayTime) {
                SDL_Delay(frameTime - frameTime);
            }
        }
    }
}

void Game::initPlayer() {
    InitalizationMapper init;
    init.setObjectId(PLAYER_ID);
    init.setInitalPosition(Vector2D(0,0));
    auto idleDrawable = new Drawable("Player_Idle","Knight_Base_idle.png",17,19,4 );

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::LEFT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::RIGHT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::UP, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::DOWN, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(std::pair<std::string, std::unique_ptr<WorldObject> >(PLAYER_ID, std::make_unique<Player>(&init)));
}

void Game::inputEvent(WorldObject* object, long deltaMs) {
    int size = 0;
    float x = 0;
    float y = 0;
    const Uint8* keystates = SDL_GetKeyboardState(&size);
    if(object->getState() != WorldObject::DEAD) {
        object->setState(WorldObject::IDLE);

        if(isKeyDown(keystates, SDL_SCANCODE_W)) {
            object->setState(WorldObject::UP);
            y = -0.1f * static_cast<float>(deltaMs);
        } else if(isKeyDown(keystates, SDL_SCANCODE_S)) {
            object->setState(WorldObject::DOWN);
            y = +0.1f * static_cast<float>(deltaMs);
        }

        if(isKeyDown(keystates, SDL_SCANCODE_A)) {
            object->setState(WorldObject::LEFT);
            x = -0.1f * static_cast<float>(deltaMs);
        } else if(isKeyDown(keystates, SDL_SCANCODE_D)) {
            object->setState(WorldObject::RIGHT);
            x = +0.1f * static_cast<float>(deltaMs);
        }
    }
    object->move(Vector2D(x,y));
}

bool Game::isKeyDown(const Uint8* keyStates, SDL_Scancode key) {
    if(keyStates != NULL) {
        return keyStates[key] == 1;
    }
    return false;
}

void Game::quit(const char* reason) {
    if(reason != nullptr) {
        std::cout << "Application quit due to " << std::endl;
    }
    this->running = false;
}



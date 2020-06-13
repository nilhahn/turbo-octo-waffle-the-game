//
// Created by matze on 11.05.20.
//

#include "Game.h"
#include "../World/Objects/Player.h"
#include "../World/InitalizationMapper.h"

#define PLAYER_ID "player"

Game::Game() {
    this->running = false;
    this->window = nullptr;
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
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderClear(renderer);

    for(auto iter = this->objects.begin(); iter < this->objects.end(); iter++) {
        auto elem = iter->get();
        elem->getDrawable()->drawFrameToRenderer(this->textureManager, renderer, &elem->getPositon(), false, 2);
    }

    SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    for(auto iter = this->objects.begin(); iter < this->objects.end(); iter++ ) {
        this->moveEvent(iter->get());
    }

}

bool Game::isRunning() {
    return this->running;
}

void Game::run() {
    if(this->init()) {
        while(this->isRunning()) {
            this->render();
            this->handleEvents();
            SDL_Delay(500);
        }
    }
}

void Game::initPlayer() {
    InitalizationMapper init;
    init.setObjectId(PLAYER_ID);
    init.setInitalPosition(Vector2D(0,0));
    auto idleDrawable = new Drawable("Player_Idle","Knight_Base_idle.png",17,19,4 );

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.push_back(std::make_unique<Player>(&init));
}

void Game::inputEvent(WorldObject* object) {
    int size = 0;
    float x = 0;
    float y = 0;
    const Uint8* keystates = SDL_GetKeyboardState(&size);


    if(isKeyDown(keystates, SDL_SCANCODE_W)) {
        std::cout << "Move up" << std::endl;
        y = -10.;
    } else if(isKeyDown(keystates, SDL_SCANCODE_S)) {
        std::cout << "Move down" << std::endl;
        y = +10.;
    }

    if(isKeyDown(keystates, SDL_SCANCODE_A)) {
        std::cout << "Move left" << std::endl;
        x = -10.;
    } else if(isKeyDown(keystates, SDL_SCANCODE_D)) {
        std::cout << "Move right" << std::endl;
        x = +10.;
    }

    object->move(Vector2D(x,y));
}

bool Game::isKeyDown(const Uint8* keyStates, SDL_Scancode key) {
    if(keyStates != NULL) {
        return keyStates[key] == 1;
    }
    return false;
}

void Game::moveEvent(WorldObject* object) {
    if(object->getId() == PLAYER_ID) {
        this->inputEvent(object);
    }
}



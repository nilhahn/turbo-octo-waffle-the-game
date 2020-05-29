//
// Created by matze on 11.05.20.
//

#include "Game.h"
#include "../World/Objects/Player.h"
#include "../World/InitalizationMapper.h"

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
    init.setInitalPosition(Vector2D(0,0));
    auto idleDrawable = new Drawable("Player_Idle","Knight_Base_idle.png",17,19,4 );

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.push_back(std::make_unique<Player>(&init));
}



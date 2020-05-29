//
// Created by matze on 11.05.20.
//

#include "Game.h"
#include "../World/Objects/Player.h"

Game::Game() {
    this->running = false;
    this->window = nullptr;
    this->player = nullptr;
}

Game::~Game() {
}

bool Game::init() {
    std::string title = "turbo-octo-waffel";
    this->window = Window::create(title,512,512);
    this->textureManager = TextureManager::instance(Resource::getResourcePath());
    this->textureManager->load("Knight_Base_idle.png","Player_Idle",this->window->getRenderer());
    this->player = this->textureManager->getTexture("Player_Idle");
    this->initPlayer();

    this->running = this->window != nullptr && this->window->getRenderer() != nullptr;
    return this->running;
}

void Game::render() {
    SDL_Renderer* renderer = this->window->getRenderer();
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderClear(renderer);
    SDL_Rect sourceRect;
    SDL_Rect destRect;

    sourceRect.x = 17 * static_cast<int>((SDL_GetTicks()/100)%4);
    sourceRect.y = 0;
    SDL_QueryTexture(this->player, nullptr, nullptr, &sourceRect.w, &sourceRect.h);

    destRect.x = 0;
    destRect.y = 0;

    sourceRect.w = 17;
    sourceRect.h = 19;

    destRect.w = 2*sourceRect.w;
    destRect.h = 2*sourceRect.h;
    SDL_RenderCopyEx(renderer, this->player, &sourceRect, &destRect,0 ,0 ,SDL_FLIP_NONE);
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
            SDL_Delay(1000);
        }
    }
}

void Game::initPlayer() {
    InitalizationMapper init;
    init.setInitalPosition(Vector2D(0,0));
    init.addNewTextureForState(WorldObject::ObjectState::IDLE, "Player_Idle", "Knight_Base_idle.png");
    init.setInitalState(WorldObject::ObjectState::IDLE);
    this->objects.push_back(new Player(&init));
}



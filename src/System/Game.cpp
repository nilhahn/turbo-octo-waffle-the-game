//
// Created by matze on 11.05.20.
//

#include "Game.h"

Game::Game() {
    this->running = false;
    this->window = nullptr;
}

bool Game::init() {
    std::string title = "turbo-octo-waffel";
    this->window = Window::create(title,512,512);
    this->running = this->window != nullptr && this->window->getRenderer() != nullptr;
    return this->running;
}

void Game::render() {
    SDL_Renderer* renderer = this->window->getRenderer();
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::handleEvents() {

}

bool Game::isRunning() {
    return this->running;
}

void Game::run() {
    if(this->init()) {
        this->render();
    }
    SDL_Delay(5000);
}



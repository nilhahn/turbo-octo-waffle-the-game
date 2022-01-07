#include <iostream>
#include "Window.h"

Window* Window::window = nullptr;

Window *Window::create(std::string &title, int width, int height) {
    if(window == nullptr) {
        window = new Window();
        if(window->init(title, width, height) == false) {
            delete window;
            window = nullptr;
        }
    }
    return window;
}

Window::Window() {
    this->sdlWindow = nullptr;
    std::cout << "Window create" << std::endl;
}

Window::~Window() {
    std::cout << "Window destroy" << std::endl;
    SDL_Quit();
}

SDL_Renderer *Window::getRenderer() {
    return this->renderer;
}

bool Window::init(std::string &title, int width, int height) {
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        this->sdlWindow = SDL_CreateWindow(title.data(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
        if(this->sdlWindow != nullptr) {
            this->renderer = SDL_CreateRenderer(this->sdlWindow, -1, 0);
        }
        return true;
    }
    return false;
}



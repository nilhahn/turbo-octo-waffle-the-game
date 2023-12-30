#include <iostream>
#include "Window.h"

Window* Window::window = nullptr;

Window *Window::create(std::string &title, int width, int height, std::string& texturePath) {
    if(window == nullptr) {
        window = new Window();
        if(window->init(title, width, height, texturePath) == false) {
            delete window;
            window = nullptr;
        }
    }
    return window;
}

Window::Window() {
    this->sdlWindow = nullptr;
    this->manager = nullptr;
    this->renderer = nullptr;
    std::cout << "Window create" << std::endl;
}

Window::~Window() {
    std::cout << "Window destroy" << std::endl;
    delete this->manager;
    SDL_Quit();
}

SDL_Renderer *Window::getRenderer() const
{
    return this->renderer;
}

bool Window::init(std::string &title, int width, int height, std::string& texturePath) {
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        this->sdlWindow = SDL_CreateWindow(title.data(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
        if(this->sdlWindow != nullptr) {
            this->renderer = SDL_CreateRenderer(this->sdlWindow, -1, 0);
            this->manager = TextureManager::instance(texturePath);
        }
        return true;
    }
    return false;
}

SDL_Window *Window::getSDLWindow() const{
    return this->sdlWindow;
}

TextureManager *Window::getTextureManager() const {
    return this->manager;
}



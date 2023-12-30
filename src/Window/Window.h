#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "SDL.h"

#include "TextureManager.h"

#include <string>

class Window {
public:
    ~Window();

    static Window* create(std::string& title, int width, int height, std::string& texturePath);
    [[nodiscard]] SDL_Renderer* getRenderer() const;
    [[nodiscard]] SDL_Window* getSDLWindow() const;
    [[nodiscard]] TextureManager* getTextureManager() const;

private:
    Window();

    static Window* window;
    SDL_Window* sdlWindow;
    SDL_Renderer* renderer;
    TextureManager* manager;

    bool init(std::string &title, int width, int height, std::string& texturePath);
};

#endif //_WINDOW_H

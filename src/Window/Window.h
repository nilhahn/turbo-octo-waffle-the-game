#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "SDL.h"
#include "../System/Vector2Df.h"
#include "../Resource/TextureManager.h"
#include <string>

class Window {
public:
    ~Window();

    static Window* create(std::string& title, int width, int height, std::string& texturePath);
    SDL_Renderer* getRenderer();
    SDL_Window* getSDLWindow();
    TextureManager* getTextureManager();

private:
    Window();

    static Window* window;
    SDL_Window* sdlWindow;
    SDL_Renderer* renderer;
    TextureManager* manager;

    bool init(std::string &title, int width, int height, std::string& texturePath);
};


#endif //_WINDOW_H

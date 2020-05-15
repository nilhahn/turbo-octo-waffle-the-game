//
// Created by matze on 15.05.20.
//

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "SDL.h"
#include <string>

class Window {
public:
    ~Window();

    static Window* create(std::string& title, int width, int height);
    SDL_Renderer* getRenderer();

private:
    Window();

    static Window* window;
    SDL_Window* sdlWindow;
    SDL_Renderer* renderer;

    bool init(std::string &basicString, int i, int i1);
};


#endif //_WINDOW_H

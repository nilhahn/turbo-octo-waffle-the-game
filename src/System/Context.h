#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CONTEXT_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CONTEXT_H

#include <random>

#include "../Window/Window.h"

class Context {
public:
    explicit Context(Window *window = nullptr);

    virtual ~Context();

    Window *getWindow() const;

    TextureManager *getTextureManager() const;

    int getRand();

private:
    Window *window;
    std::uniform_int_distribution<int> dist;
    std::random_device rd;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_CONTEXT_H

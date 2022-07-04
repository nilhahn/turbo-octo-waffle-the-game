#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CONTEXT_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CONTEXT_H

#include "../Window/Window.h"

class Context {
public:
    explicit Context(Window *window = nullptr);

    virtual ~Context();

    Window *getWindow() const;

    TextureManager *getTextureManager() const;

private:
    Window *window;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_CONTEXT_H

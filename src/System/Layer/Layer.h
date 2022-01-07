#ifndef TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H

#include "../../Resource/TextureManager.h"
#include "../Vector2D.h"
#include "../../Window/Camera.h"

class Layer {
public:
    virtual ~Layer() {}

    virtual void init() = 0;
    virtual void draw(TextureManager const* textureManager, const Camera& camera, SDL_Renderer const* renderer, Vector2D const* position) = 0;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H

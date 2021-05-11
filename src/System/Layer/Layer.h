//
// Created by mheisler on 10.05.21.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H

class Layer {
public:
    virtual ~Layer() {}

    virtual void init() = 0;
    virtual void draw(TextureManager const* textureManager, SDL_Renderer const* renderer, Vector2D const* position) = 0;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H

#include "Vector2D.h"
#include "Context.h"
#include "Canvas.h"
#include "Camera.h"
#include "TextureManager.h"

class Layer {
public:
    virtual ~Layer() {}

    virtual void init(const Context &context, int width, int height) = 0;

    virtual void update(Context &context, const Camera &camera, Canvas &canvas) = 0;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H

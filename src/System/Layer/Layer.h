#ifndef TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H

#include "../Vector2D.h"
#include "../Context.h"
#include "../Drawable/Canvas.h"
#include "../../Window/Camera.h"
#include "../../Resource/TextureManager.h"

class Layer {
public:
    virtual ~Layer() {}

    virtual void init() = 0;

    virtual void draw(Context &context, const Camera &camera, Canvas &canvas) = 0;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_LAYER_H

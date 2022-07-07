#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CANVAS_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CANVAS_H

#include "../../Resource/TextureManager.h"
#include "../Vector2D.h"
#include "Drawable.h"
#include "../Context.h"

class Canvas {
public:
    void draw(Context &context,
              const Vector2D &windowPosition,
              const Drawable &drawable,
              bool flip,
              double angle = 0.0);

private:
    inline SDL_Rect prepareFrame(const Vector2D &position);

    inline void render(SDL_Texture &textureManager,
                       SDL_Renderer &renderer,
                       const SDL_Rect &frame,
                       const SDL_Rect &position,
                       bool flip,
                       double angle);
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_CANVAS_H

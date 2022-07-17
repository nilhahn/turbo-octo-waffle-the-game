#ifndef TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H
#define TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

#include "../../Vector2D.h"

class Hitbox: public Square2D {
private:
    
public:
    explicit Hitbox(float x = 0., float y = 0., float w = 0., float h = 0.): Square2D(x, y, w, h) {}
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

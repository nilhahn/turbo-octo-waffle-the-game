#ifndef TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H
#define TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

#include "../../Vector2D.h"

class HitBox: public Square2D {
private:
    
public:
    explicit HitBox(float x = 0., float y = 0., float w = 0., float h = 0.): Square2D(x, y, w, h) {}

    inline HitBox& cornerX(float x) {
        this->setCornerX(x);
        return *this;
    }

    inline HitBox& cornerY(float y) {
        this->setCornerY(y);
        return *this;
    }
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

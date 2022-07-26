#ifndef TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H
#define TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

#include "../../Vector2D.h"
#include "iostream"

class HitBox : public Square2D {
private:

public:
    explicit HitBox(float x = 0., float y = 0., float w = 0., float h = 0.) : Square2D(x, y, w, h) {}

    inline HitBox &cornerX(float x) {
        this->setCornerX(x);
        return *this;
    }

    inline HitBox &cornerY(float y) {
        this->setCornerY(y);
        return *this;
    }

    bool collision(HitBox &box) {
    // todo: this code doesn't do what it should
        SDL_Rect A{static_cast<int>(this->getCornerX()), static_cast<int>(this->getCornerY()), static_cast<int>(this->getWidth()), static_cast<int>(this->getHeight())};
        SDL_Rect B{static_cast<int>(box.getCornerX()), static_cast<int>(box.getCornerY()), static_cast<int>(box.getWidth()), static_cast<int>(box.getHeight())};
    return SDL_HasIntersection(&A, &B);
    }
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

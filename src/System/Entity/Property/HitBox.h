#ifndef TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H
#define TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

#include "../../Square2D.h"
#include "iostream"

class HitBox : public Square2D {
private:
    bool active;
public:
    explicit HitBox(float x = 0., float y = 0., float w = 0., float h = 0., bool isActive = true) : Square2D(x, y, w,
                                                                                                             h),
                                                                                                    active(isActive) {}

    inline HitBox &cornerX(float x) {
        this->setCornerX(x);
        return *this;
    }

    inline HitBox &cornerY(float y) {
        this->setCornerY(y);
        return *this;
    }

    inline bool isActive() {
        return this->active;
    }

    inline void toggle() {
        this->active = !this->active;
    }

    HitBox &operator=(const HitBox &hitBox) {
        this->setCornerX(hitBox.getCornerX());
        this->setCornerY(hitBox.getCornerY());
        this->setWidth(hitBox.getWidth());
        this->setHeight(hitBox.getHeight());

        return *this;
    }

    bool collision(HitBox &box) {
        if (!box.isActive()) {
            return false;
        }
        SDL_Rect A{static_cast<int>(this->getCornerX()), static_cast<int>(this->getCornerY()),
                   static_cast<int>(this->getWidth()), static_cast<int>(this->getHeight())};
        SDL_Rect B{static_cast<int>(box.getCornerX()), static_cast<int>(box.getCornerY()),
                   static_cast<int>(box.getWidth()), static_cast<int>(box.getHeight())};
        return SDL_HasIntersection(&A, &B);
    }
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

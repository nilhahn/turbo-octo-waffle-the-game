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
        if (this->getCornerX() < box.getCornerX() + box.getWidth() &&
            this->getCornerX() + this->getWidth() > box.getWidth() &&
            this->getCornerY() < box.getCornerY() + box.getHeight() &&
            this->getCornerY() + this->getCornerY() > box.getCornerY()) {
            std::cout << "collision!" << std::endl;
            return true;
        }
        return false;
    }
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_HITBOX_H

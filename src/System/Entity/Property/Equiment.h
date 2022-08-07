#ifndef TURBO_OCTO_WAFFLE_THE_GAME_EQUIMENT_H
#define TURBO_OCTO_WAFFLE_THE_GAME_EQUIMENT_H

#include "../../Drawable/Drawable.h"
#include "HitBox.h"

class Equiment {
private:
    Drawable drawable;
    HitBox hitBox;
public:
    inline void setDrawable(Drawable& drawable_) {
        this->drawable.copyState(drawable_);
    }

    inline Drawable* getDrawable() {
        return &drawable;
    }
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_EQUIMENT_H

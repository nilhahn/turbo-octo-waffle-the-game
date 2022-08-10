#ifndef TURBO_OCTO_WAFFLE_THE_GAME_EQUIPMENT_H
#define TURBO_OCTO_WAFFLE_THE_GAME_EQUIPMENT_H

#include "../../Drawable/Drawable.h"
#include "HitBox.h"
#include "../../../World/Objects/Item.h"

class Equipment {
public:
    inline void setDrawable(Drawable& drawable_) {
        this->drawable.copyState(drawable_);
    }

    inline Drawable* getDrawable() {
        return &drawable;
    }

private:
    Drawable drawable;
    HitBox hitBox;
    Item item;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_EQUIPMENT_H

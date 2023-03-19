#ifndef TURBO_OCTO_WAFFLE_THE_GAME_EQUIPMENT_H
#define TURBO_OCTO_WAFFLE_THE_GAME_EQUIPMENT_H

#include "Drawable.h"
#include "HitBox.h"
#include "Items.h"

class Equipment {
public:
    void setDrawable(Drawable &drawable_);

    const Drawable &getDrawable();

    void setHitBox(HitBox &hitBox);

    const HitBox &getHitBox();

    void setItem(Item& item);

    const Item& getItem();

private:
    Drawable drawable;
    HitBox hitBox;
    Item item;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_EQUIPMENT_H

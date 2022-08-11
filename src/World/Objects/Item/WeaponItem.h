#ifndef TURBO_OCTO_WAFFLE_THE_GAME_WEAPONITEM_H
#define TURBO_OCTO_WAFFLE_THE_GAME_WEAPONITEM_H

#include "../Item.h"

class WeaponItem : public Item {
public:
    WeaponItem(const char* name, int damage,  int value = 0, int weight = 0);

    int getRawDamage();

private:
    int damage;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_WEAPONITEM_H

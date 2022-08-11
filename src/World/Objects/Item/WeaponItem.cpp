#include "WeaponItem.h"

WeaponItem::WeaponItem(const char *name, int damage, int value, int weight) : Item(ItemType::WEAPON) {
    this->name = name;
    this->damage = damage;
    this->value = value;
    this->weight = weight;
}

int WeaponItem::getRawDamage() {
    return this->damage;
}
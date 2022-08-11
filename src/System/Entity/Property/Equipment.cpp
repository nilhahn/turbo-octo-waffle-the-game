#include "Equipment.h"

void Equipment::setDrawable(Drawable &drawable_) {
    this->drawable.copyState(drawable_);
}

const Drawable &Equipment::getDrawable() {
    return drawable;
}

void Equipment::setHitBox(HitBox &hitbox) {
    this->hitBox = hitbox;
}

const HitBox &Equipment::getHitBox() {
    return hitBox;
}

void Equipment::setItem(Item &item) {
// TODO: implement
}

const Item &Equipment::getItem() {
    return item;
}
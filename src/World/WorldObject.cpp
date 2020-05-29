//
// Created by matze on 28.05.20.
//

#include "WorldObject.h"

void WorldObject::setState(WorldObject::ObjectState state_) {
    this->state = state_;
}

WorldObject::ObjectState WorldObject::getState() {
    return this->state;
}

void WorldObject::setPosition(Vector2D position_) {
    this->position = position_;
}

Vector2D& WorldObject::getPositon() {
    return this->position;
}

float WorldObject::distance(WorldObject *object) {
    return (this->getPositon() - object->getPositon()).length();
}

WorldObject::WorldObject() {
    this->state = INIT;

    this->hitbox.y = 0;
    this->hitbox.w = 0;
    this->hitbox.x = 0;
    this->hitbox.h = 0;
}

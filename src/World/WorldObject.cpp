//
// Created by matze on 28.05.20.
//

#include "WorldObject.h"

void WorldObject::setState(WorldObject::ObjectState state_) {
    this->state = state_;
}

std::string WorldObject::getId() {
    return this->objectId;
}

WorldObject::ObjectState WorldObject::getState() {
    return this->state;
}

void WorldObject::setPosition(Vector2D& position_) {
    this->position = position_;
}

void WorldObject::setPosition(float x, float y) {
    this->position.setX(x);
    this->position.setY(y);
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

void WorldObject::setId(const char* id) {
    this->objectId = id;
}

bool WorldObject::isInStateLeftOrDown() {
    return this->state == LEFT || this->state == DOWN;
}

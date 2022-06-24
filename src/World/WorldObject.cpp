#include "WorldObject.h"

void WorldObject::setState(WorldObject::ObjectState state_) {
    if (state_ != this->state) {
        this->state = state_;
    }
}

std::string WorldObject::getId() {
    return this->objectId;
}

WorldObject::ObjectState WorldObject::getState() {
    return this->state;
}

void WorldObject::setPosition(Vector2D &position_) {
    this->position = position_;
}

void WorldObject::setPosition(float x, float y) {
    this->position.setX(x);
    this->position.setY(y);
}

Vector2D &WorldObject::getPosition() {
    return this->position;
}

float WorldObject::distance(WorldObject *object) {
    return (this->getPosition() - object->getPosition()).length();
}

WorldObject::WorldObject() {
    this->state = INIT;

    this->hitbox.y = 0;
    this->hitbox.w = 0;
    this->hitbox.x = 0;
    this->hitbox.h = 0;
}

void WorldObject::setId(const char *id) {
    this->objectId = id;
}

bool WorldObject::isInStateLeftOrDown() {
    return this->state == LEFT || this->state == DOWN;
}

void WorldObject::update(long delta) {}

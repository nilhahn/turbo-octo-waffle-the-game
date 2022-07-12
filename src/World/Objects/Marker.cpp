#include "Marker.h"

Marker::Marker(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setId(init->getId());

    this->state = init->getInitalState();
    this->followState = init->getInitalState();

    auto tex = init->getTextures();

    for (auto &iter: *tex) {
        this->textures.insert({iter.first, std::make_unique<Drawable>(iter.second)});
    }
}

void Marker::setState(WorldObject::ObjectState state) {
    this->followState = state;
}

Vector2Df Marker::move(Vector2Df vector) {
    return this->getPosition() += vector;
}

WorldObject::ObjectState Marker::hit(WorldObject &object) {
    return WorldObject::IDLE;
}

void Marker::setHealth(int health_) {
    // health of the marker can't be changed
}

int Marker::getHealth() {
    return 0;
}

void Marker::draw(Context &context, const Camera &camera, Canvas &canvas, long delta) {
    canvas.draw(context, this->getPosition(), *this->getDrawable(), delta, this->isInStateLeftOrDown(),
                this->getRotation());
}

Drawable *Marker::getDrawable() {
    return this->textures.at(this->getState()).get();
}

double Marker::getRotation() {
    switch (this->followState) {
        case WorldObject::RIGHT:
            return 0.0;
        case WorldObject::UP:
            return 270.0;
        case WorldObject::LEFT:
            return 180.0;
        case WorldObject::DOWN:
            return 90.0;
        default:
            return 0.0;
    }
}

#include "Skeleton.h"

Skeleton::Skeleton(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setId(init->getId());
    WorldObject::setState(init->getInitalState());

    auto tex = init->getTextures();
    this->interFrameTime = 0;

    for (auto &iter: *tex) {
        this->textures.insert({iter.first, std::make_unique<Drawable>(iter.second)});
    }
    rotation = 0.0;
}

void Skeleton::setState(WorldObject::ObjectState state) {
    WorldObject::setState(state);
}

Vector2Df Skeleton::move(Vector2Df vector) {
    return this->getPosition() += vector;
}

WorldObject::ObjectState Skeleton::hit(WorldObject& object) {
    return IDLE;
}

void Skeleton::setHealth(int health_) {
    this->health = health_;
}

int Skeleton::getHealth() {
    return this->health;
}

void
Skeleton::draw(Context &context, const Camera &camera, Canvas &canvas, long delta) {
    if (camera.isObjectVisible(this->getPosition(), 64., 64.)) {
        Vector2Df relPosition = this->getPosition().operator-(*camera.getCoord());
        canvas.draw(context, relPosition, *this->getDrawable(), delta, this->isInStateLeftOrDown(), rotation);
    }
}

Drawable *Skeleton::getDrawable() {
    return this->textures.at(this->getState()).get();
}

void Skeleton::update(long delta) {
    this->interFrameTime += delta;
    if (this->interFrameTime >= 500) {
        rotation += 0.1;
    }
}

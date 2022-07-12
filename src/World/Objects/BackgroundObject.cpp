#include "BackgroundObject.h"

BackgroundObject::BackgroundObject(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->texture = std::make_unique<Drawable>(init->getTextures()->at(WorldObject::ObjectState::IDLE));
}

void BackgroundObject::setState(ObjectState state) {}

Vector2Df BackgroundObject::move(Vector2Df vector) {
    return this->getPosition() += vector;
}

WorldObject::ObjectState BackgroundObject::hit(WorldObject &object) {
    return IDLE;
}

void BackgroundObject::setHealth(int health_) {};

int BackgroundObject::getHealth() {
    return 0;
};

void BackgroundObject::draw(Context& context, const Camera& camera, Canvas& canvas, long delta) {
    Vector2Df relPosition = this->getPosition() - *camera.getCoord();
    canvas.draw(context, relPosition, *this->getDrawable(), delta);
}

Drawable *BackgroundObject::getDrawable() {
    return this->texture.get();
}
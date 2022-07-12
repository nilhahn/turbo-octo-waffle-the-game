#include "Player.h"

Player::Player(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setId(init->getId(nullptr));
    this->state = init->getInitalState();
    this->oldState = this->state;

    this->health = 100;

    std::map<WorldObject::ObjectState, Drawable *> *tex = init->getTextures();
    this->interFrameTime = 0;

    for (auto &iter: *tex) {
        this->textures.insert({iter.first, std::make_unique<Drawable>(iter.second)});
    }
}

Vector2Df Player::move(Vector2Df vector) {
    return this->getPosition() += vector;
}

void Player::setHealth(int health_) {
    this->health = health_;
}

int Player::getHealth() {
    return this->health;
}

WorldObject::ObjectState Player::hit(WorldObject& object) {
    return IDLE;
}

void Player::draw(Context& context, const Camera& camera, Canvas& canvas, long delta) {
    canvas.draw(context, this->getPosition(), *this->getDrawable(), delta, this->isInStateLeftOrDown());
}

Drawable *Player::getDrawable() {
    return this->textures.at(this->getState()).get();
}

void Player::setState(WorldObject::ObjectState state) {
    if (state != this->oldState) {
        WorldObject::setState(state);
    }
}

void Player::update(long delta) {
    this->interFrameTime += delta;
}

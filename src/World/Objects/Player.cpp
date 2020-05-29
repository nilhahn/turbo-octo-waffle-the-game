//
// Created by matze on 29.05.20.
//

#include "Player.h"

Player::Player(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setState(init->getInitalState());
    std::map<WorldObject::ObjectState, std::pair<std::string, std::string> >* tex =
            init->getTextures();
}

Vector2D Player::move(Vector2D vector) {
    return this->getPositon() += vector;
}

void Player::setHealth(int health_) {
    this->health = health_;
}

int Player::getHealth() {
    return this->health;
}

WorldObject::ObjectState Player::hit(WorldObject *object) {
    return IDLE;
}

Drawable* Player::getDrawable() {
    return &this->textures.at(this->getState());
}

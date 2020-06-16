//
// Created by matze on 29.05.20.
//

#include "Player.h"

Player::Player(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setState(init->getInitalState());
    this->setId(init->getId(nullptr));
    this->health = 100;
    this->updateCnt = 0;

    std::map<WorldObject::ObjectState, Drawable* >* tex = init->getTextures();

    for(auto & iter: *tex) {
        this->textures.insert({iter.first, std::make_unique<Drawable>(iter.second)});
    }
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

void Player::draw(TextureManager *textureManager, SDL_Renderer *renderer) {
    this->updateCnt++;
    if(this->updateCnt >= 1000) {
        this->getDrawable()->drawFrameToRenderer(textureManager, renderer, &this->getPositon(), this->isInStateLeftOrDown(), 2);
        this->updateCnt = 0;
    } else {
        this->getDrawable()->drawFrameToRenderer(textureManager, renderer, &this->getPositon(), this->isInStateLeftOrDown(), 2, false);
    }
}

Drawable* Player::getDrawable() {
    return this->textures.at(this->getState()).get();
}

bool Player::isInStateLeftOrDown() {
    return this->state == LEFT || this->state == DOWN;
}

void Player::setState(WorldObject::ObjectState state) {
    WorldObject::setState(state);
}

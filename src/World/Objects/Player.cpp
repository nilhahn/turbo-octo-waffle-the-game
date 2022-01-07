#include "Player.h"

Player::Player(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setId(init->getId(nullptr));
    this->state = init->getInitalState();
    this->oldState = this->state;

    this->health = 100;

    std::map<WorldObject::ObjectState, Drawable* >* tex = init->getTextures();
    this->interFrameTime = 0;

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

void Player::draw(TextureManager const* textureManager, const Camera& camera, SDL_Renderer const* renderer, long delta) {
    bool nextFrame = false;

    this->interFrameTime += delta;
    if(this->interFrameTime >= 500) {
        nextFrame = true;
        this->interFrameTime = 0;
    }

    this->getDrawable()->drawFrameToRenderer(const_cast<TextureManager *>(textureManager),
                                             const_cast<SDL_Renderer *>(renderer),
                                             &this->getPositon(),
                                             this->isInStateLeftOrDown(),
                                             2,
                                             nextFrame);
}

Drawable* Player::getDrawable() {
    return this->textures.at(this->getState()).get();
}


void Player::setState(WorldObject::ObjectState state) {
    if(state != this->oldState) {
        WorldObject::setState(state);
    }
}

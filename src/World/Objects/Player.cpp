#include "Player.h"

Player::Player(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setId(init->getId(nullptr));
    this->state = init->getInitalState();
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

void Player::draw(TextureManager const* textureManager, SDL_Renderer const* renderer) {
    bool nextFrame = false;
    this->updateCnt++;

    /* todo: find better way to do this */
    // delay the time between two frames (maybe use the delta time from the game loop (?))
    // -> may be hard to do at the current state of the development
    if(this->updateCnt >= 1000) {
        nextFrame = true;
        this->updateCnt = 0;
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
    WorldObject::setState(state);
}

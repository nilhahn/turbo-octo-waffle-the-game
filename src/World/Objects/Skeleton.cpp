#include "Skeleton.h"
#include <iostream>

#include <iostream>

Skeleton::Skeleton(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setId(init->getId());
    WorldObject::setState(init->getInitalState());

    auto tex = init->getTextures();
    this->interFrameTime = 0;

    for (auto &iter: *tex) {
        this->textures.insert({iter.first, std::make_unique<Drawable>(iter.second)});
    }
}

void Skeleton::setState(WorldObject::ObjectState state) {
    WorldObject::setState(state);
}

Vector2D Skeleton::move(Vector2D vector) {
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
Skeleton::draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer, long delta) {
    bool nextFrame = false;

    this->updateCnt++;

    if (this->updateCnt >= 1000) {
        nextFrame = true;
        this->updateCnt = 0;
    }

    if (camera.isObjectVisible(this->getPosition(), 64., 64.)) {
        Vector2D relPosition = this->getPosition().operator-(*camera.getCoord());
        this->getDrawable()->drawFrameToRenderer(const_cast<TextureManager *>(textureManager),
                                                 const_cast<SDL_Renderer *>(renderer), &relPosition,
                                                 this->isInStateLeftOrDown(), 1, nextFrame);
    }
}

Drawable *Skeleton::getDrawable() {
    return this->textures.at(this->getState()).get();
}

void Skeleton::update(long delta) {
    this->interFrameTime += delta;
    if (this->interFrameTime >= 500) {
        this->getDrawable()->nextFrame();
        this->interFrameTime = 0;
    }
}

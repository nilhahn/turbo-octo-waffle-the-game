//
// Created by matze on 14.08.20.
//

#include "Skeleton.h"

Skeleton::Skeleton(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setId(init->getId());
    WorldObject::setState(init->getInitalState());

    auto tex = init->getTextures();

    for(auto& iter: *tex) {
        this->textures.insert({iter.first, std::make_unique<Drawable>(iter.second)});
    }
}

void Skeleton::setState(WorldObject::ObjectState state) {
    WorldObject::setState(state);
}

Vector2D Skeleton::move(Vector2D vector) {
    return this->getPositon() += vector;
}

WorldObject::ObjectState Skeleton::hit(WorldObject *object) {
    return IDLE;
}

void Skeleton::setHealth(int health_) {
    this->health = health_;
}

int Skeleton::getHealth() {
    return this->health;
}

void Skeleton::draw(TextureManager *textureManager, SDL_Renderer *renderer) {
    this->updateCnt++;
    if(this->updateCnt >= 1000) {
        this->getDrawable()->drawFrameToRenderer(textureManager, renderer, &this->getPositon(), this->isInStateLeftOrDown(), 2);
        this->updateCnt = 0;
    } else {
        this->getDrawable()->drawFrameToRenderer(textureManager, renderer, &this->getPositon(), this->isInStateLeftOrDown(), 2, false);
    }
}

Drawable *Skeleton::getDrawable() {
    return this->textures.at(this->getState()).get();
}

#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->setId(init->getId());
    WorldObject::setState(init->getInitalState());

    auto tex = init->getTextures();

    for (auto &iter: *tex) {
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

void
Skeleton::draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer, long delta) {
    bool nextFrame = false;

    this->updateCnt++;

    if (this->updateCnt >= 1000) {
        nextFrame = true;
        this->updateCnt = 0;
    }

    if (camera.isObjectVisible(this->getPositon(), 64., 64.)) {
        Vector2D relPosition = this->getPositon().operator+(*camera.getCoord());

        this->getDrawable()->drawFrameToRenderer(const_cast<TextureManager *>(textureManager),
                                                 const_cast<SDL_Renderer *>(renderer), &relPosition,
                                                 this->isInStateLeftOrDown(), 2, nextFrame);
    } else {
        std::cout << "not visible" << std::endl;
    }
}

Drawable *Skeleton::getDrawable() {
    return this->textures.at(this->getState()).get();
}
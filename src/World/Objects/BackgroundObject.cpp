//
// Created by mheisler on 05.05.21.
//

#include "BackgroundObject.h"
BackgroundObject::BackgroundObject(InitalizationMapper *init) {
    this->setPosition(init->getPosition());
    this->texture = std::make_unique<Drawable>(init->getTextures()->at(WorldObject::ObjectState::IDLE));
}

void BackgroundObject::setState(ObjectState state)  {}

Vector2D BackgroundObject::move(Vector2D vector) {
    return this->getPositon() += vector;
}

WorldObject::ObjectState BackgroundObject::hit(WorldObject* object) {
    return IDLE;
}

void BackgroundObject::setHealth(int health_) {};
int BackgroundObject::getHealth() {};

void BackgroundObject::draw(TextureManager* textureManager, SDL_Renderer* renderer) {
    this->getDrawable()->drawFrameToRenderer(textureManager, renderer,&this->getPositon(), false , 0);
}

Drawable* BackgroundObject::getDrawable(){
    return this->texture.get();
};
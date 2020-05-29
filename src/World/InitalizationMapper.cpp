//
// Created by matze on 28.05.20.
//

#include "InitalizationMapper.h"

void InitalizationMapper::setInitalPosition(Vector2D vector) {
    this->initalPosition = vector;
}

Vector2D &InitalizationMapper::getPosition() {
    return this->initalPosition;
}

void InitalizationMapper::setInitalState(WorldObject::ObjectState state) {
    this->initalState = state;
}

WorldObject::ObjectState InitalizationMapper::getInitalState() {
    return this->initalState;
}

void InitalizationMapper::addNewDrawableForState(WorldObject::ObjectState state, Drawable *drawable) {
    this->stateTextures.insert({state, drawable});
}

std::map<WorldObject::ObjectState, Drawable *> *InitalizationMapper::getTextures() {
    return &this->stateTextures;
}

InitalizationMapper::InitalizationMapper() {
    this->initalState = WorldObject::ObjectState::INIT;
}


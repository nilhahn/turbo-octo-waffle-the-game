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

void InitalizationMapper::addNewTextureForState(WorldObject::ObjectState state, const char* textureId, const char* file) {
this->stateTextures.insert({state, std::pair<std::string, std::string>(textureId, file)});
}

std::map<WorldObject::ObjectState, std::pair<std::string, std::string> > *InitalizationMapper::getTextures() {
    return &this->stateTextures;
}

void InitalizationMapper::setInitalState(WorldObject::ObjectState state) {
    this->initalState = state;
}

WorldObject::ObjectState InitalizationMapper::getInitalState() {
    return this->initalState;
}


//
// Created by mheisler on 12.05.21.
//

#include "Chunk.h"

void Chunk::setDimension(SDL_Rect& dimension) {
    this->dimension = dimension;
}

void Chunk::setIdentifier(std::string& identifier) {
    this->identifier = identifier;
}

SDL_Rect const& Chunk::getDimension() {
    return this->dimension;
}

std::string const& Chunk::getIdentifier() {
    return this->identifier;
}
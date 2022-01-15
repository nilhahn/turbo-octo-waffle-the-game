#include "Chunk.h"

void Chunk::setDimension(Square2D& dimension) {
    this->dimension = dimension;
}

void Chunk::setDimension(SDL_Rect& dimension) {
    Vector2D corner(static_cast<float>(dimension.x), static_cast<float>(dimension.y));
    this->dimension.setCorner(corner);
    this->dimension.setHeight(static_cast<float>(dimension.h));
    this->dimension.setWidth(static_cast<float>(dimension.w));
}

void Chunk::setIdentifier(std::string& identifier) {
    this->identifier = identifier;
}

Square2D& Chunk::getDimension() {
    return this->dimension;
}

std::string const& Chunk::getIdentifier() {
    return this->identifier;
}
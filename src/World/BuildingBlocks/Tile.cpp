#include "Tile.h"

Tile::Tile() {}

void Tile::init(Square2D &dimension, std::string &identifier) {
    this->setIdentifier(identifier);
    this->setDimension(dimension);
}

void Tile::setDimension(Square2D &dimension) {
    this->dimension = dimension;
}

void Tile::setIdentifier(std::string &identifier) {
    this->identifier = identifier;
}

void Tile::addNeighbor(Tile::Neighbor position, Tile *tile, bool reversalAdd) {
}

Tile::Neighbor Tile::reverseNeighbor(Neighbor origin) {
    switch (origin) {
        case UPPER:
            return LOWER;
        case RIGHT:
            return LEFT;
        case LOWER:
            return UPPER;
        case LEFT:
            return RIGHT;
    }

}

Square2D const &Tile::getDimension() {
    return this->dimension;
}

std::string const &Tile::getIdentifier() {
    return this->identifier;
}
#ifndef TURBO_OCTO_WAFFLE_THE_GAME_TILE_H
#define TURBO_OCTO_WAFFLE_THE_GAME_TILE_H

#include <string>
#include <memory>
#include "../../System/Square2D.h"

class Tile {
public:
    typedef enum {
        UPPER = 0, RIGHT, LOWER, LEFT
    } Neighbor;

    explicit Tile();

    void init(Square2D &dimension, std::string &identifier);

    void setDimension(Square2D &dimension);

    void setIdentifier(std::string &identifier);

    void addNeighbor(Tile::Neighbor position, Tile *tile, bool reversalAdd = true);

    Square2D const &getDimension();

    std::string const &getIdentifier();

private:
    Neighbor reverseNeighbor(Neighbor origin);

    Tile* neighbors[4];
    std::string identifier;
    Square2D dimension;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_TILE_H

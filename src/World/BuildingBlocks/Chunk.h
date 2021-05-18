//
// Created by mheisler on 12.05.21.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CHUNK_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CHUNK_H

#include <SDL.h>
#include <string>

#include "../../System/Square2D.h"

class Chunk {
public:

    void setDimension(Square2D& dimension);
    void setDimension(SDL_Rect& dimension);
    void setIdentifier(std::string& identifier);

    Square2D const& getDimension();
    std::string const& getIdentifier();
private:
    Square2D dimension;
    std::string identifier;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_CHUNK_H

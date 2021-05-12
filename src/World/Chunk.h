//
// Created by mheisler on 12.05.21.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CHUNK_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CHUNK_H

#include <string>
#include <SDL_rect.h>

class Chunk {
public:

    void setDimension(SDL_Rect& dimension);
    void setIdentifier(std::string& identifier);

    SDL_Rect const& getDimension();
    std::string const& getIdentifier();
private:
    SDL_Rect dimension;
    std::string identifier;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_CHUNK_H

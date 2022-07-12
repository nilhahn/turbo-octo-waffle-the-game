#ifndef TURBO_OCTO_WAFFLE_THE_GAME_POSITION_H
#define TURBO_OCTO_WAFFLE_THE_GAME_POSITION_H

#include "../../Vector2D.h"

class Position: public Vector2Df {
public:
    explicit Position(float x = 0., float y = 0.): Vector2Df(x, y) {}
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_POSITION_H

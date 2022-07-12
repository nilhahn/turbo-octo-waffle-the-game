#ifndef TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2DF_H
#define TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2DF_H

#include <cmath>
#include <string>
#include "Vector2D.h"

class Vector2Df : public Vector2D<float> {
public:
    Vector2Df();

    Vector2Df(float x, float y) : Vector2D<float>(x, y) {};

    float length() override;

    Vector2Df operator*(float scalar);

    Vector2Df operator+(const Vector2Df &vector) const;

    Vector2Df operator-(const Vector2Df &vector) const;

    Vector2Df &operator+=(Vector2Df &vector);

    Vector2Df &operator-=(Vector2Df &vector);

    float absDistance(Vector2Df &vector2D);

    void norm();

    std::string toString();
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2DF_H

//
// Created by matze on 22.05.20.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H
#define TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H

#include <cmath>

class Vector2D {
public:
    Vector2D();
    Vector2D(float x, float y);

    float length();

    float getY();
    float getX();

    Vector2D operator* (float scalar);
    Vector2D operator+ (Vector2D& vector);
    Vector2D operator- (Vector2D& vector);
    Vector2D& operator= (Vector2D vector);
    Vector2D& operator+= (Vector2D& vector);
    Vector2D& operator-= (Vector2D& vector);

    float absDistance(Vector2D& vector2D);
    void norm();

private:
    float x;
    float y;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H

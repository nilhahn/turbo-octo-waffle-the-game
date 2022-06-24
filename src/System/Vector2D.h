#ifndef TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H
#define TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H

#include <cmath>
#include <string>

class Vector2D {
public:
    Vector2D();
    Vector2D(float x, float y);

    float length();

    float getY() const;
    float getX() const;

    void setY(float y);
    void setX(float x);

    Vector2D operator* (float scalar);
    Vector2D operator+ (const Vector2D& vector) const;
    Vector2D operator- (const Vector2D& vector) const;
    Vector2D& operator= (Vector2D& vector);
    Vector2D& operator+= (Vector2D& vector);
    Vector2D& operator-= (Vector2D& vector);

    float absDistance(Vector2D& vector2D);
    void norm();

    std::string toString();
private:
    float x;
    float y;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H


#include "../System/Vector2D.h"
#include "../System/Square2D.h"

class Camera {
public:
    Camera();

    void init(int width, int height, Vector2D &initalPosition);

    void move(Vector2D &delta);

    int getWidth() const;

    int getHeight() const;

    Vector2D const *getCenter();

    const Vector2D *getCoord() const;

    bool isObjectVisible(Vector2D &vector2D, float width, float height) const;

    Square2D getBoundingRect() const;

private:
    Vector2D coord;
    Vector2D center;

    int width;
    int height;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H

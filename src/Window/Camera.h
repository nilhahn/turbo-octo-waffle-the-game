//
// Created by mheisler on 07.05.21.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H


#include "../System/Vector2D.h"

class Camera {
public:
    Camera();

    void init(int width, int height, Vector2D& initalPosition);
    void move(Vector2D& delta);

    int getWidth();
    int getHeight();

    Vector2D const* getCenter();
    const Vector2D* getCoord();

private:
    Vector2D coord;
    Vector2D center;

    int width;
    int height;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H

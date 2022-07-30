#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H


#include "../System/Vector2D.h"
#include "../System/Square2D.h"

class Camera {
public:
    Camera();

    void init(int width, int height, Vector2Df &initalPosition);

    void move(Vector2Df &delta);

    int getWidth() const;

    int getHeight() const;

    Vector2Df const *getCenter();

    const Vector2Df *getCoord() const;

    bool isObjectVisible(Vector2Df &vector2D, float width, float height) const;
    bool isObjectVisible(Square2D *pBox) const;

    Square2D getBoundingRect() const;

private:
    Vector2Df coord;
    Vector2Df center;

    int width;
    int height;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_CAMERA_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_WORLDOBJECT_H
#define TURBO_OCTO_WAFFLE_THE_GAME_WORLDOBJECT_H

#include <string>
#include "SDL.h"

#include "Vector2D.h"
#include "Drawable.h"
#include "Camera.h"
#include "Context.h"
#include "Canvas.h"

class Canvas;

class WorldObject {
public:
    typedef enum {
        INIT = -1, IDLE, UP, DOWN, LEFT, RIGHT, DEAD
    } ObjectState;

    WorldObject();

    virtual void setState(ObjectState state);

    virtual std::string getId();

    ObjectState getState();

    void setPosition(Vector2Df &position_);

    void setPosition(float x, float y);

    virtual Vector2Df move(Vector2Df vector) = 0;

    Vector2Df &getPosition();

    float distance(WorldObject *object);

    virtual ObjectState hit(WorldObject &object) = 0;

    virtual void setHealth(int health) = 0;

    virtual int getHealth() = 0;

    virtual void draw(Context& context, const Camera& camera, Canvas& canvas, long delta) = 0;

    virtual Drawable *getDrawable() = 0;

    virtual void update(long update);

protected:
    bool isInStateLeftOrDown();

    void setId(const char *id);

    std::string objectId;
    ObjectState state;
    Vector2Df position;
    SDL_Rect hitbox;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_WORLDOBJECT_H

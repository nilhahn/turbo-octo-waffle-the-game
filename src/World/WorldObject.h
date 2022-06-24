#ifndef TURBO_OCTO_WAFFLE_THE_GAME_WORLDOBJECT_H
#define TURBO_OCTO_WAFFLE_THE_GAME_WORLDOBJECT_H

#include <string>
#include <SDL.h>

#include "../System/Vector2D.h"
#include "../Drawable/Drawable.h"
#include "../Window/Camera.h"

class WorldObject {
public:
    typedef enum {
        INIT = -1, IDLE, UP, DOWN, LEFT, RIGHT, DEAD
    } ObjectState;

    WorldObject();

    virtual void setState(ObjectState state);

    virtual std::string getId();

    ObjectState getState();

    void setPosition(Vector2D &position_);

    void setPosition(float x, float y);

    virtual Vector2D move(Vector2D vector) = 0;

    Vector2D &getPositon();

    float distance(WorldObject *object);

    virtual ObjectState hit(WorldObject *object) = 0;

    virtual void setHealth(int health) = 0;

    virtual int getHealth() = 0;

    virtual void draw(TextureManager const *textureManager, const Camera& camera,  SDL_Renderer const *renderer, long delta) = 0;

    virtual Drawable *getDrawable() = 0;

    virtual void update(long update);

protected:
    bool isInStateLeftOrDown();

    void setId(const char *id);

    std::string objectId;
    ObjectState state;
    Vector2D position;
    SDL_Rect hitbox;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_WORLDOBJECT_H

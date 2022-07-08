#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PLAYER_H

#include <memory>
#include "../WorldObject.h"
#include "../InitalizationMapper.h"

class Player: public WorldObject{
public:
    explicit Player(InitalizationMapper *init);

    /* TODO: add destructor */

    void setState(ObjectState state) override;

    Vector2D move(Vector2D vector) override;

    ObjectState hit(WorldObject& object) override;

    void setHealth(int health_) override;
    int getHealth() override;

    void draw(Context& context, const Camera& camera, Canvas& canvas, long delta) override;

    Drawable* getDrawable() override;

    void update(long delta) override;
private:

    int health;
    long interFrameTime;
    WorldObject::ObjectState oldState;
    std::map<ObjectState, std::unique_ptr<Drawable> > textures;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_PLAYER_H

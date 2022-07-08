#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDOBJECT_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDOBJECT_H

#include <memory>

#include "../WorldObject.h"
#include "../InitalizationMapper.h"

class BackgroundObject: public WorldObject {
public:
    explicit BackgroundObject(InitalizationMapper *init);

    void setState(ObjectState state) override;

    Vector2D move(Vector2D vector) override;

    ObjectState hit(WorldObject& object) override;

    void setHealth(int health_) override;
    int getHealth() override;

    void draw(Context& context, const Camera& camera, Canvas& canvas, long delta) override;

    Drawable* getDrawable() override;

private:
    std::unique_ptr<Drawable> texture;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDOBJECT_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_MARKER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_MARKER_H

#include <memory>

#include "../WorldObject.h"
#include "../InitalizationMapper.h"

class Marker : public WorldObject {
public:
    explicit Marker(InitalizationMapper *init);

    void setState(ObjectState state) override;

    Vector2Df move(Vector2Df vector) override;

    ObjectState hit(WorldObject& object) override;

    void setHealth(int health_) override;
    int getHealth() override;

    void draw(Context& context, const Camera& camera, Canvas& canvas, long delta) override;

    Drawable* getDrawable() override;

private:
    ObjectState followState;

    std::map<ObjectState, std::unique_ptr<Drawable> > textures;

    double getRotation();
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_MARKER_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_SKELETON_H
#define TURBO_OCTO_WAFFLE_THE_GAME_SKELETON_H


#include <memory>
#include "../WorldObject.h"
#include "../InitalizationMapper.h"

class Skeleton: public WorldObject {
public:
    explicit Skeleton(InitalizationMapper *init);

    /* TODO: add destructor */

    void setState(ObjectState state) override;

    Vector2Df move(Vector2Df vector) override;

    ObjectState hit(WorldObject& object) override;

    void setHealth(int health_) override;
    int getHealth() override;

    void draw(Context &context, const Camera &camera, Canvas &canvas, long delta) override;
    void update(long delta) override;

    Drawable* getDrawable() override;
private:
    double rotation;
    int health;
    int updateCnt;
    long interFrameTime;
    std::map<ObjectState, std::unique_ptr<Drawable> > textures;

    bool isVisible(const Camera &camera);
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_SKELETON_H

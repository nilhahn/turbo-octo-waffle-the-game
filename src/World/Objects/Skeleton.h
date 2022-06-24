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

    Vector2D move(Vector2D vector) override;

    ObjectState hit(WorldObject& object) override;

    void setHealth(int health_) override;
    int getHealth() override;

    void draw(TextureManager const* textureManager, const Camera& camera, SDL_Renderer const* renderer, long delta) override;
    void update(long delta) override;

    Drawable* getDrawable() override;
private:

    int health;
    int updateCnt;
    long interFrameTime;
    std::map<ObjectState, std::unique_ptr<Drawable> > textures;

    bool isVisible(const Camera &camera);
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_SKELETON_H

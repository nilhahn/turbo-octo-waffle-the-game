#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CANVAS_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CANVAS_H

#include <memory>
#include "../../Resource/TextureManager.h"
#include "../Vector2D.h"
#include "Drawable.h"
#include "../Context.h"
#include "../Entity/Entity.h"
#include "../../Window/Camera.h"
#include "../Entity/Property/Properties.h"

class Canvas {
public:
    void draw(Context &context,
              const Vector2Df &windowPosition,
              Drawable &drawable,
              long delta,
              bool flip = false,
              double angle = 0.0);

    void drawScene(Context& context, Camera& camera, long delta);

    inline void addToScene(std::shared_ptr<Entity>& entity) {
        this->scene.push_back(entity);
    }

    inline const std::vector<std::shared_ptr<Entity> >& getScene() {
        return this->scene;
    };

    inline void clearScene() {
        this->scene.clear();
    }

private:
    inline SDL_Rect prepareFrame(const Vector2Df &position, const SDL_Rect& frame);

    inline void render(SDL_Texture *textureManager,
                       SDL_Renderer *renderer,
                       const SDL_Rect &frame,
                       const SDL_Rect &position,
                       bool flip,
                       double angle);

    bool isInStateLeftOrDown(EntityState::ObjectState state);

    std::vector<std::shared_ptr<Entity> > scene;

};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_CANVAS_H

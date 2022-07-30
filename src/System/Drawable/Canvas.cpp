#include "Canvas.h"

void Canvas::draw(Context &context, const Vector2Df &windowPosition,
                  Drawable &drawable, long delta, bool flip, double angle) {
    TextureManager *manager = context.getTextureManager();
    SDL_Renderer *renderer = context.getWindow()->getRenderer();
    SDL_Texture *texture = manager->loadTexture(drawable.getId().data(), *renderer);

    if (nullptr == texture) {
        // Something bad happened
        return;
    }
    SDL_Rect frame = drawable.getFrame(delta);
    SDL_Rect destination = this->prepareFrame(windowPosition, frame);
    this->render(texture, renderer, frame, destination, flip, angle);
}

void Canvas::drawScene(Context& context, Camera& camera, long delta) {
    for (auto iter = this->scene.begin(); iter != scene.end(); iter++) {
        Drawable* drawable;
        auto state = iter->get()->getProperty<EntityState>();

        if(state != nullptr) {
            drawable = iter->get()->getProperty<StatefulDrawable>()->getDrawable(state->getState());
        } else {
            drawable = iter->get()->getProperty<Drawable>();
        }

        if(drawable == nullptr) {
            continue;
        }
        auto position = iter->get()->getProperty<HitBox>();
        if(position == nullptr) {
            continue;
        }
        this->draw(context, position->getCornerSquare() - *camera.getCoord(), const_cast<Drawable &>(*drawable),
                    delta,
                    state == nullptr ? EntityState::ObjectState::IDLE : this->isInStateLeftOrDown(state->getState()));
    }
    this->clearScene();
}

SDL_Rect Canvas::prepareFrame(const Vector2Df &position, const SDL_Rect &frame) {
    return {static_cast<int>(position.getX()), static_cast<int>(position.getY()), frame.w, frame.h};
}

void
Canvas::render(SDL_Texture *texture,
               SDL_Renderer *renderer,
               const SDL_Rect &frame,
               const SDL_Rect &position,
               bool flip,
               double angle) {
    SDL_RenderCopyEx(renderer, texture, &frame, &position, angle, nullptr,
                     flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

bool Canvas::isInStateLeftOrDown(EntityState::ObjectState param) {
    return param == EntityState::LEFT || param == EntityState::DOWN;;
}


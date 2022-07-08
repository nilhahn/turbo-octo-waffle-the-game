#include "Canvas.h"

void Canvas::draw(Context &context, const Vector2D &windowPosition,
                  Drawable &drawable, long delta, bool flip, double angle) {
    TextureManager *manager = context.getTextureManager();
    SDL_Renderer *renderer = context.getWindow()->getRenderer();
    SDL_Texture *texture = manager->getTexture(drawable.getId().data());

    if (nullptr == texture && manager->load(drawable.getFile().data(), drawable.getId().data(), *renderer)) {
        // Something bad happened
        return;
    }
    SDL_Rect destination = this->prepareFrame(windowPosition);
    // TODO: finish
    this->render(texture, renderer, drawable.getFrame(delta), destination, flip, angle);
}

SDL_Rect Canvas::prepareFrame(const Vector2D &position) {
    return {static_cast<int>(position.getX()), static_cast<int>(position.getY())};
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


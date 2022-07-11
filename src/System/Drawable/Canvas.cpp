#include "Canvas.h"

void Canvas::draw(Context &context, const Vector2D &windowPosition,
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

SDL_Rect Canvas::prepareFrame(const Vector2D &position, const SDL_Rect &frame) {
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


#include "StatefulDrawable.h"

Drawable *StatefulDrawable::getDrawable(EntityState::ObjectState state) const{
    auto drawable = this->drawables.find(state);
    if (drawable == drawables.end()) {
        return nullptr;
    }
    return drawable->second.get();
}

void StatefulDrawable::add(EntityState::ObjectState state,
                           const char *id,
                           Vector2Di &frameDimensions,
                           Vector2Di &frameOffset,
                           unsigned int numberOfFrames) {
    auto drawableIter = this->drawables.find(state);
    if (drawableIter == this->drawables.end()) {
        this->drawables.insert(
                std::pair<EntityState::ObjectState, std::unique_ptr<Drawable> >(
                        state,
                        std::make_unique<Drawable>(id, frameOffset.getX(), frameOffset.getY(), frameDimensions.getX(),
                                                   frameDimensions.getY(), numberOfFrames)));
    }
}

void StatefulDrawable::add(EntityState::ObjectState state,
                           const char *id,
                           Vector2Di &frameDimensions,
                           unsigned int numberOfFrames) {
    auto drawableIter = this->drawables.find(state);
    if (drawableIter == this->drawables.end()) {
        this->drawables.insert(
                std::pair<EntityState::ObjectState, std::unique_ptr<Drawable> >(
                        state,
                        std::make_unique<Drawable>(id, frameDimensions.getX(),
                                                   frameDimensions.getY(), numberOfFrames)));
    }
}

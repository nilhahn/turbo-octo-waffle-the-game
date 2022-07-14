#ifndef TURBO_OCTO_WAFFLE_THE_GAME_STATEFULDRAWABLE_H
#define TURBO_OCTO_WAFFLE_THE_GAME_STATEFULDRAWABLE_H

#include <memory>
#include "EntityState.h"
#include "../../Drawable/Drawable.h"
#include "../../../World/WorldObject.h"

class StatefulDrawable {
public:
    const Drawable *getDrawable(EntityState::ObjectState state);

    void add(EntityState::ObjectState state,
             const char *drawableId,
             Vector2Di &frameDimensions,
             Vector2Di &frameOffset,
             unsigned numberOfFrames = 1);

    void add(EntityState::ObjectState state,
             const char *drawableId,
             Vector2Di &frameDimensions,
             unsigned numberOfFrames = 1);

private:
    std::map<EntityState::ObjectState, std::unique_ptr<Drawable> > drawables;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_STATEFULDRAWABLE_H

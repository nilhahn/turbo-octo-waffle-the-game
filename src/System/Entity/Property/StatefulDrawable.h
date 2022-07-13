#ifndef TURBO_OCTO_WAFFLE_THE_GAME_STATEFULDRAWABLE_H
#define TURBO_OCTO_WAFFLE_THE_GAME_STATEFULDRAWABLE_H

#include <memory>
#include "../../Drawable/Drawable.h"
#include "../../../World/WorldObject.h"

class StatefulDrawable {
public:
    const Drawable *getDrawable(WorldObject::ObjectState state);

    void add(WorldObject::ObjectState state,
             const char *drawableId,
             Vector2Di &frameDimensions,
             Vector2Di &frameOffset,
             unsigned numberOfFrames = 1);

    void add(WorldObject::ObjectState state,
             const char *drawableId,
             Vector2Di &frameDimensions,
             unsigned numberOfFrames = 1);

private:
    std::map<WorldObject::ObjectState, std::unique_ptr<Drawable> > drawables;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_STATEFULDRAWABLE_H

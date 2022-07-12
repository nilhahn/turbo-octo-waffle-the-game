#ifndef TURBO_OCTO_WAFFLE_THE_GAME_SATEFULDRAWABLE_H
#define TURBO_OCTO_WAFFLE_THE_GAME_SATEFULDRAWABLE_H


#include <memory>
#include "../../Drawable/Drawable.h"
#include "../../../World/WorldObject.h"

class SatefulDrawable {
public:
    const Drawable* getDrawable(WorldObject::ObjectState state);
    void add(WorldObject::ObjectState state, const char *id, Vector2Df& frameOffset, int widthOfFrame,
             int heightOfFrame, unsigned numberOfFrames = 1));

private:
    std::map<WorldObject::ObjectState, std::unique_ptr<Drawable> > drawables;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_SATEFULDRAWABLE_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_INITALIZATIONMAPPER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_INITALIZATIONMAPPER_H

#include <map>
#include "../System/Vector2D.h"
#include "WorldObject.h"

class InitalizationMapper {
public:
    InitalizationMapper();

    void setInitalPosition(Vector2Df vector);
    Vector2Df& getPosition();

    void setObjectId(const char* id);
    const char* getId(int* size = nullptr);

    void setInitalState(WorldObject::ObjectState state);
    WorldObject::ObjectState getInitalState();

    void addNewDrawableForState(WorldObject::ObjectState state, Drawable* drawable);
    std::map<WorldObject::ObjectState, Drawable* >* getTextures();
private:
    std::string objectId;
    WorldObject::ObjectState initalState;
    Vector2Df initalPosition;
    std::map<WorldObject::ObjectState, Drawable* > stateTextures;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_INITALIZATIONMAPPER_H

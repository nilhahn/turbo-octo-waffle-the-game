//
// Created by matze on 28.05.20.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_INITALIZATIONMAPPER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_INITALIZATIONMAPPER_H


#include <map>
#include "../System/Vector2D.h"
#include "WorldObject.h"

class InitalizationMapper {
public:
    InitalizationMapper() = default;

    void setInitalPosition(Vector2D vector);
    Vector2D& getPosition();

    void setInitalState(WorldObject::ObjectState state);
    WorldObject::ObjectState getInitalState();

    void addNewTextureForState(WorldObject::ObjectState state, const char* textureId, const char* file);
    std::map<WorldObject::ObjectState, std::pair<std::string, std::string> >* getTextures();
private:
    WorldObject::ObjectState initalState;
    Vector2D initalPosition;
    std::map<WorldObject::ObjectState, std::pair<std::string, std::string> > stateTextures;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_INITALIZATIONMAPPER_H

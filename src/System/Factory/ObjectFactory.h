#ifndef TURBO_OCTO_WAFFLE_THE_GAME_OBJECTFACTORY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_OBJECTFACTORY_H

#include "../Entity/BaseProperty.h"
#include "../Entity/Entity.h"
#include "../../Window/Camera.h"
#include "../Entity/Property/Properties.h"

class ObjectFactory {
public:
    ObjectFactory(const ObjectFactory &cpy) = delete;

    ObjectFactory() = default;

    virtual ~ObjectFactory() = default;

    virtual void createEntity(Entity &entity, const Context &context, Camera &camera) = 0;
    virtual std::string createId() = 0;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_OBJECTFACTORY_H

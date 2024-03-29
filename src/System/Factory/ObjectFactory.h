#ifndef TURBO_OCTO_WAFFLE_THE_GAME_OBJECTFACTORY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_OBJECTFACTORY_H

#include "BaseProperty.h"
#include "Entity.h"
#include "Camera.h"
#include "Properties.h"

class ObjectFactory {
public:
    ObjectFactory(const ObjectFactory &cpy) = delete;

    ObjectFactory() = default;

    virtual ~ObjectFactory() = default;

    virtual void createEntity(Entity &entity, const Context &context, Camera &camera) = 0;

    virtual std::string createId() = 0;

    static inline int createRandom(Context &context) {
        int rand = context.getRand();
        if (rand < 0) {
            rand *= -1;
        }
        return rand;
    }
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_OBJECTFACTORY_H

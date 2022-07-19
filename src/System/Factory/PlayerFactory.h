#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PLAYERFACTORY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PLAYERFACTORY_H

#include "ObjectFactory.h"
#include "../Entity/Property/Hitbox.h"
#include "../../Window/Camera.h"

class PlayerFactory : public ObjectFactory {
public:
    static const std::string entityId;

    void createEntity(Entity &entity, const Context &context, Camera &camera) override;

    std::string createId() override;

    void initDrawable(StatefulDrawable *pDrawable, const Context &context);
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_PLAYERFACTORY_H

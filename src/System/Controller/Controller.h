#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H

#include <vector>

#include "../Entity/BaseProperty.h"
#include "../Entity/Entity.h"
#include "../../Window/Camera.h"
#include "../Entity/Property/Properties.h"

class Controller {
public:
    Controller(const Controller &cpy) = delete;

    virtual ~Controller() = default;

    virtual void createEntity(Entity &entity, const Context &context, Camera &camera) = 0;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H

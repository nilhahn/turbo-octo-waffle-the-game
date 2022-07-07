#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H

#include <vector>

#include "../Entity/BaseProperty.h"
#include "../Entity/Entity.h"

class Controller {
public:
    Controller(const Controller &cpy) = delete;

    virtual ~Controller() = default;

    virtual void create(Entity &entity, unsigned objectId) = 0;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PLAYERCONTROLLER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PLAYERCONTROLLER_H

#include "Controller.h"
#include "../Entity/Property/Hitbox.h"
#include "../../Window/Camera.h"

class PlayerController : public Controller {
public:
    static const std::string entityId;

    void createEntity(Entity &entity, const Context &context, Camera &camera) override;

    std::string createId() override;

    void initDrawable(StatefulDrawable *pDrawable, const Context &context);
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_PLAYERCONTROLLER_H

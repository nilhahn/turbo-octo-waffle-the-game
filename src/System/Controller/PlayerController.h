#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PLAYERCONTROLLER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PLAYERCONTROLLER_H

#include "Controller.h"
#include "../Entity/Property/Position.h"
#include "../../Window/Camera.h"

class PlayerController : public Controller {
public:
    Entity* createPlayer(Context& context, Camera& camera);
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_PLAYERCONTROLLER_H

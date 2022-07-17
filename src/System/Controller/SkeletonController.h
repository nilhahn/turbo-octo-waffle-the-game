#ifndef TURBO_OCTO_WAFFLE_THE_GAME_SKELETONCONTROLLER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_SKELETONCONTROLLER_H

#include "Controller.h"

class SkeletonController : public Controller{
public:
    void createEntity(Entity& entity, const Context &context, Camera &camera) override;
    std::string createId() override;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_SKELETONCONTROLLER_H

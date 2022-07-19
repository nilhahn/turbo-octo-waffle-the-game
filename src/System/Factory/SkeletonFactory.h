#ifndef TURBO_OCTO_WAFFLE_THE_GAME_SKELETONFACTORY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_SKELETONFACTORY_H

#include "ObjectFactory.h"

class SkeletonFactory : public ObjectFactory{
public:
    void createEntity(Entity& entity, const Context &context, Camera &camera) override;
    std::string createId() override;
    std::string createId(const Context &context);
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_SKELETONFACTORY_H

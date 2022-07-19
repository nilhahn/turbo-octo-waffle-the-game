#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDFACTORY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDFACTORY_H

#include "ObjectFactory.h"

class BackgroundFactory : public ObjectFactory{
public:
    void createEntity(Entity &entity, const Context &context, Camera &camera) override;
    std::string createId() override;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDFACTORY_H

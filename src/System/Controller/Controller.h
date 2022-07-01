#ifndef TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H

#include <vector>

#include "../Entity/BaseProperty.h"
#include "../Entity/Entity.h"

class Controller {
protected:
    std::vector<BaseProperty::ID> properties;
public:
    explicit Controller(BaseProperty::ID *properties = nullptr, unsigned size = 0);

    Controller(const Controller &cpy) = delete;

    virtual ~Controller() = default;

    virtual void create(Entity &entity, unsigned objectId);

    virtual bool addProperty(BaseProperty::ID property) = 0;

    bool setProperties(BaseProperty::ID *properties, unsigned size = 0);
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_CONTROLLER_H

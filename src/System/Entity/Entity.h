#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

#include <map>
#include <memory>
#include <vector>

#include "Property.h"

class Entity {
private:
    std::map<BaseProperty::ID, std::unique_ptr<BaseProperty> > properties;

public:
    Entity();

    Entity(const Entity &entity) = delete;

    Entity(std::vector<BaseProperty *> &properties);

    ~Entity() = default;

    void addProperty(BaseProperty *property);

    std::map<BaseProperty::ID, std::unique_ptr<BaseProperty> > &getAllProperties() const;

    BaseProperty *getProperty(BaseProperty::ID id) const;

    bool isEmpty();
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

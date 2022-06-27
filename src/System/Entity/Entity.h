#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

#include <map>
#include <memory>

#include "Property.h"

class Entity {
private:
    std::map<int,std::unique_ptr<Property<T>> > properties;

public:
    Entity();
    Entity(const Entity& entity);

    Entity(int length, BaseProperty* properties);

    ~Entity();

    void addProperty(BaseProperty* property);

    bool getAllProperties(std::vector<BaseProperty>& property);

    BaseProperty& getProperty(int id);

    bool isEmpty();
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

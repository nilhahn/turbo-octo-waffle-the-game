#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

#include <map>
#include <memory>
#include <vector>

#include "Property.h"

class Entity {
private:
    std::map<std::string, std::unique_ptr<BaseProperty> > properties;

public:
    Entity();

    Entity(const Entity &entity) = delete;

    ~Entity() = default;

    std::map<std::string, std::unique_ptr<BaseProperty> > &getAllProperties() const;

    template <class T>
    void addProperty(Property<T> *property);

    template <class T>
    const BaseProperty *getProperty();

    bool isEmpty();
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

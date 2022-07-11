#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

#include <map>
#include <memory>
#include <vector>

#include "Property.h"

class Entity {
private:
    unsigned long entityId;
    std::map<std::string, std::unique_ptr<BaseProperty> > properties;
public:
    Entity();

    Entity(const Entity &entity) = delete;

    ~Entity() = default;

    std::map<std::string, std::unique_ptr<BaseProperty> > &getAllProperties() const;

    template<typename T>
    void addProperty(Property<T> *property);

    template<typename T>
    const T *getProperty();

    unsigned long getEntityId() const;

    bool isEmpty();
};

template<typename T>
void Entity::addProperty(Property<T> *property) {
    if (property != nullptr) {
        std::unique_ptr<BaseProperty> prop{property}; // braced initialization
        this->properties.insert(std::make_pair(property->getKey(), std::move(prop)));
    }
}

template<typename T>
const T *Entity::getProperty() {
    auto property = properties.find(typeid(T).name());
    if (property == properties.end()) {
        return nullptr;
    }
    return ((Property<T> *) property->second.get())->getValue();
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

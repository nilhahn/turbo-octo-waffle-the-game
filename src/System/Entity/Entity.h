#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

#include <map>
#include <memory>
#include <vector>

#include "Property.h"
#include "../Exception.h"

class Entity {
private:
    std::string entityId{};
    std::map<std::string, std::shared_ptr<BaseProperty> > properties;
public:
    Entity() = default;

    Entity(std::string entityId) : entityId(entityId) {}

    Entity(const Entity *entity) = delete;

    ~Entity() = default;

    std::map<std::string, std::shared_ptr<BaseProperty> > &getAllProperties() const;

    template<typename T>
    void addProperty(Property<T> *property);

    template<typename T>
    T *getProperty() const;

    std::string getEntityId() const;

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
T *Entity::getProperty() const{
    auto property = properties.find(typeid(T).name());
    if (property == properties.end()) {
        return nullptr;
    }
    return ((Property<T> *) property->second.get())->getValue();
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

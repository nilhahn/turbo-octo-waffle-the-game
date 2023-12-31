#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

#include <map>
#include <memory>

#include "Property.h"
#include "Exception.h"

class Entity {
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

    template<typename T>
    T *getProperty(const char* key) const;

    std::string getEntityId() const;

    bool isEmpty();

private:
    std::string entityId{};
    std::map<std::string, std::shared_ptr<BaseProperty> > properties;
};

template<typename T>
void Entity::addProperty(Property<T> *property) {
    if (property != nullptr) {
        std::shared_ptr<BaseProperty> prop{property}; // braced initialization
        this->properties.insert(std::make_pair(property->getKey(), std::move(prop)));
    }
}

template<typename T>
auto Entity::getProperty() const -> T*{
    return this->getProperty<T>(typeid(T).name());
}

template<typename T>
auto Entity::getProperty(const char* key) const -> T*{
    const auto property = properties.find(key);
    if (property == properties.end()) {
        return nullptr;
    }
    return static_cast<Property<T>*>(property->second.get())->getValue();
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ENTITY_H

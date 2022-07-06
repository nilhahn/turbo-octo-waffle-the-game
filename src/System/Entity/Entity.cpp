#include "Entity.h"

Entity::Entity() {}

std::map<std::string, std::unique_ptr<BaseProperty> > &Entity::getAllProperties() const {
    return const_cast<std::map<std::string, std::unique_ptr<BaseProperty> > & > (this->properties);
}

template <class T>
void Entity::addProperty(Property<T> *property) {
    if (property != nullptr) {
        std::unique_ptr<BaseProperty> prop{property}; // braced initialization
        this->properties.insert(std::make_pair(property->getKey(), std::move(prop)));
    }
}

template<class T>
const BaseProperty *Entity::getProperty() {
    auto property = properties.find(typeid(T).name());
    if (property == properties.end()) {
        return nullptr;
    }
    return property->second.get();
}

bool Entity::isEmpty() {
    return this->properties.empty();
}
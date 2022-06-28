//
// Created by MHeis on 27.06.2022.
//

#include "Entity.h"

Entity::Entity() {

}

void Entity::addProperty(BaseProperty *property) {
    if (property != nullptr) {
        std::unique_ptr<BaseProperty> prop(property);
        this->properties.insert(
                std::pair<BaseProperty::ID, std::unique_ptr<BaseProperty> >(
                        static_cast<const BaseProperty::Property_ID>(property->getId()),
                        prop));
    }
}

std::map<BaseProperty::ID, std::unique_ptr<BaseProperty> > Entity::getAllProperties() const {
    return this->properties;
}

BaseProperty *Entity::getProperty(BaseProperty::ID id) const {
    auto property = properties.find(id);
    if (property == properties.end()) {
        return nullptr;
    }
    return property->second.get();
}

bool Entity::isEmpty() {
    return this->properties.empty();
}

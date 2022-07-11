#include "Entity.h"

Entity::Entity() {}

std::map<std::string, std::unique_ptr<BaseProperty> > &Entity::getAllProperties() const {
    return const_cast<std::map<std::string, std::unique_ptr<BaseProperty> > & > (this->properties);
}

bool Entity::isEmpty() {
    return this->properties.empty();
}

unsigned long Entity::getEntityId() const {
    return this->entityId;
}

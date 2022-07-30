#include "Entity.h"

std::map<std::string, std::shared_ptr<BaseProperty> > &Entity::getAllProperties() const {
    return const_cast<std::map<std::string, std::shared_ptr<BaseProperty> > & > (this->properties);
}

bool Entity::isEmpty() {
    return this->properties.empty();
}

std::string Entity::getEntityId() const {
    return this->entityId;
}

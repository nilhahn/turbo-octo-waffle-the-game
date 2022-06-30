#include "Controller.h"

Controller::Controller(BaseProperty::ID *properties, unsigned int size) {
    this->setProperties(properties, size);
}

bool Controller::setProperties(BaseProperty::ID *properties, unsigned int size) {
    if (this->properties.empty() && properties != nullptr && size > 0) {
        for (int index = 0; index < size; index++) {
            this->properties.push_back(properties[index]);
        }
        return true;
    }
    return false;
}

void Controller::create(Entity &entity, unsigned int objectId) {
    for (auto property: this->properties) {
        switch (property) {
            case BaseProperty::ID::UNSPECIFIED:
            default:
                break;
        }
    }
}

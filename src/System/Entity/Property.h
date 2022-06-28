#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H

#include "BaseProperty.h"

template<class T>
class Property : public BaseProperty {
protected:
    T value;
public:
    explicit Property(BaseProperty::ID propertyId = ID::UNSPECIFIED);

    T &getValue() const;
};

template<class T>
Property<T>::Property(BaseProperty::ID propertyId): BaseProperty(propertyId) {
}

template<class T>
T &Property<T>::getValue() const {
    return this->value;
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H

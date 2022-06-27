#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H

#include "BaseProperty.h"

template<class T>
class Property : public BaseProperty {
protected:
    T value;
public:
    typedef enum Property_ID {
        UNSPECIFIED = 0
    } ID;

    explicit Property(int propertyId = ID::UNSPECIFIED);

    T &getValue() const;
};

template<class T>
Property<T>::Property(int propertyId): BaseProperty(propertyId) {
}

template<class T>
T &Property<T>::getValue() const {
    return this->value;
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H

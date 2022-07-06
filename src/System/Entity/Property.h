#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H

#include "BaseProperty.h"

template<class T>
class Property : public BaseProperty {
protected:
    T value;
public:

    T &getValue() const;

    const char *getKey() override;
};

template<class T>
T &Property<T>::getValue() const {
    return this->value;
}

template<class T>
const char *Property<T>::getKey() {
    return typeid(T).name();
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H

#include "BaseProperty.h"

template<class T>
class Property : public BaseProperty {
protected:
    T value;
public:
    Property() {
        this->key = typeid(T).name();
    };

    explicit Property(T& value);

    T *getValue();

    const char* getKey() override;
};

template<class T>
auto Property<T>::getValue() -> T* {
    return &this->value;
}

template<class T>
const char *Property<T>::getKey() {
    return this->key;
}

template<class T>
Property<T>::Property(T &value) {
    this->key = typeid(T).name();
    this->value = value;
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_PROPERTY_H

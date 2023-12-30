#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H

#include <typeinfo>
#include "Context.h"

class BaseProperty {
public:
    explicit BaseProperty() {
        this->key = nullptr;
    };

    virtual ~BaseProperty() = default;

    virtual const char *getKey() = 0;

    template<class T>
    static const char *getType();
protected:
    const char* key;
};

template<class T>
const char *BaseProperty::getType() {
    return typeid(T).name();
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H

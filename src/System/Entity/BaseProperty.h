#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H

#include "../Context.h"

class BaseProperty {
public:
    explicit BaseProperty() = default;

    virtual ~BaseProperty() = default;

    virtual const char *getKey() = 0;

    template<class T>
    static const char *getType();
};

template<class T>
const char *BaseProperty::getType() {
    return typeid(T).name();
}

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H

#include "../Context.h"

class BaseProperty {
public:
    typedef enum Property_ID {
        UNSPECIFIED = 0, DRAWABLE=1, STATE=2, MOVEMENT=3
    } ID;
private:
    BaseProperty::ID id;
public:
    explicit BaseProperty(BaseProperty::ID id = UNSPECIFIED) : id(id) {};

    BaseProperty(const BaseProperty &prop) {
        this->id = prop.id;
    }

    virtual ~BaseProperty() = default;

    virtual bool update(long delta, const Context* context) = 0;

    BaseProperty::ID getId() const {
        return this->id;
    }
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H

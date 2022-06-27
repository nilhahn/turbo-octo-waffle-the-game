#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H

class BaseProperty {
private:
    unsigned id;
public:
    explicit BaseProperty(unsigned id = 0) : id(id) {};

    BaseProperty(const BaseProperty &prop) {
        this->id = prop.id;
    }

    virtual ~BaseProperty() {};

    unsigned getId() const {
        return this->id;
    }
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BASEPROPERTY_H

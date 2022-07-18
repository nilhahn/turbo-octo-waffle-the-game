#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ENTITYSTATE_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ENTITYSTATE_H

class EntityState {
public:
    typedef enum {
        INIT = -1, IDLE, UP, DOWN, LEFT, RIGHT, DEAD
    } ObjectState;

    explicit EntityState(ObjectState state = INIT) : state(state) {};

    void setState(EntityState::ObjectState state_) {
        this->state = state_;
    }

    EntityState::ObjectState getState() {
        return this->state;
    }

private:
    ObjectState state;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ENTITYSTATE_H

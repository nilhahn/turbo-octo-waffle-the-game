//
// Created by matze on 29.05.20.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_PLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_PLAYER_H

#include <memory>
#include "../WorldObject.h"
#include "../InitalizationMapper.h"

class Player: public WorldObject{
public:
    explicit Player(InitalizationMapper *init);

    /* TODO: add destructor */

    Vector2D move(Vector2D vector) override;

    ObjectState hit(WorldObject* object) override;

    void setHealth(int health_) override;
    int getHealth() override;

    Drawable* getDrawable() override;
private:
    int health{};
    std::map<ObjectState, std::unique_ptr<Drawable> > textures;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_PLAYER_H
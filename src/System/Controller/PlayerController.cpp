#include "PlayerController.h"

const std::string PlayerController::entityId{"game_object_player"};

void PlayerController::createEntity(Entity &entity, const Context &context, Camera &camera) {
    Hitbox initialPos{camera.getCenter()->getX() - 8.5f, camera.getCenter()->getY() - 9.5f};

    entity.addProperty<Hitbox>(new Property<Hitbox>(initialPos));

    entity.addProperty<StatefulDrawable>(new Property<StatefulDrawable>());
    auto drawable = entity.getProperty<StatefulDrawable>();

    Vector2Di frame{17, 19};
    context.getTextureManager()->addTextureAndId("Player_Idle", "Knight_Base_idle.png");

    drawable->add(EntityState::IDLE, "Player_Idle", frame, 4);
    drawable->add(EntityState::LEFT, "Player_Idle", frame, 4);
    drawable->add(EntityState::RIGHT, "Player_Idle", frame, 4);
    drawable->add(EntityState::UP, "Player_Idle", frame, 4);
    drawable->add(EntityState::DOWN, "Player_Idle", frame, 4);

    EntityState initialState{EntityState::IDLE};
    entity.addProperty<EntityState>(new Property<EntityState>(initialState));
}

std::string PlayerController::createId() {
    return PlayerController::entityId;
}

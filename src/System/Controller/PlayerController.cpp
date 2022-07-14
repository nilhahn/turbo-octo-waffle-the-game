#include "PlayerController.h"

const std::string PlayerController::entityId{"game_object_player"};

void PlayerController::createEntity(Entity &entity, const Context &context, Camera &camera) {
    Position initalPos{camera.getCenter()->getX() - 8.5f, camera.getCenter()->getY() - 9.5f};

    entity.addProperty<Position>(new Property<Position>(initalPos));

    entity.addProperty<StatefulDrawable>(new Property<StatefulDrawable>());
    auto drawable = entity.getProperty<StatefulDrawable>();

    Vector2Di frame{17, 19};
    context.getTextureManager()->addTextureAndId("Player_Idle", "Knight_Base_idle.png");

    drawable->add(EntityState::IDLE, "Player_idle", frame, 4);
    drawable->add(EntityState::LEFT, "Player_idle", frame, 4);
    drawable->add(EntityState::RIGHT, "Player_idle", frame, 4);
    drawable->add(EntityState::UP, "Player_idle", frame, 4);
    drawable->add(EntityState::DOWN, "Player_idle", frame, 4);

    EntityState initalState{EntityState::IDLE};
    entity.addProperty<EntityState>(new Property<EntityState>(initalState));
}

std::string PlayerController::createId() {
    return PlayerController::entityId;
}

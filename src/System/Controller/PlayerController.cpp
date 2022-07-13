#include "PlayerController.h"

void PlayerController::createEntity(Entity &entity, const Context &context, Camera &camera) {
    Position initalPos{camera.getCenter()->getX() - 8.5f, camera.getCenter()->getY() - 9.5f};

    entity.addProperty<Position>(new Property<Position>(initalPos));

    Property<StatefulDrawable> *drawable = new Property<StatefulDrawable>();

    Vector2Di frame{17, 19};
    context.getTextureManager()->addTextureAndId("Player_Idle", "Knight_Base_idle.png");

    drawable->getValue().add(WorldObject::IDLE, "Player_idle", frame, 4);
    drawable->getValue().add(WorldObject::LEFT, "Player_idle", frame, 4);
    drawable->getValue().add(WorldObject::RIGHT, "Player_idle", frame, 4);
    drawable->getValue().add(WorldObject::UP, "Player_idle", frame, 4);
    drawable->getValue().add(WorldObject::DOWN, "Player_idle", frame, 4);

    entity.addProperty<StatefulDrawable>(drawable);
}

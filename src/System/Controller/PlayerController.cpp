#include "PlayerController.h"

void PlayerController::createEntity(Entity &entity, const Context &context, Camera &camera) {
    Position initalPos{camera.getCenter()->getX() - 8.5f, camera.getCenter()->getY() - 9.5f};

    entity.addProperty<Position>(new Property<Position>(initalPos));
}

#include "PlayerController.h"

Entity *PlayerController::createPlayer(Context &context, Camera &camera) {
    auto entity = new Entity();
    Position initalPos{camera.getCenter()->getX() - 8.5f, camera.getCenter()->getY() - 9.5f};

    entity->addProperty(new Property<Position>(initalPos));


    return entity;
}

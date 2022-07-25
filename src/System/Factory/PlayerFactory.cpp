#include "PlayerFactory.h"

const std::string PlayerFactory::entityId{"game_object_player"};

void PlayerFactory::createEntity(Entity &entity, const Context &context, Camera &camera) {
    HitBox initialPos{camera.getCenter()->getX() - 8.5f, camera.getCenter()->getY() - 9.5f, 17, 19};

    entity.addProperty<HitBox>(new Property<HitBox>(initialPos));

    entity.addProperty<StatefulDrawable>(new Property<StatefulDrawable>());
    auto drawable = entity.getProperty<StatefulDrawable>();
    initDrawable(drawable, context);

    EntityState initialState{EntityState::IDLE};
    entity.addProperty<EntityState>(new Property<EntityState>(initialState));
}

std::string PlayerFactory::createId() {
    return PlayerFactory::entityId;
}

void PlayerFactory::initDrawable(StatefulDrawable *pDrawable, const Context &context) {
    Vector2Di frame{17, 19};
    context.getTextureManager()->addTextureAndId("Player_Idle", "Knight_Base_idle.png");

    pDrawable->add(EntityState::IDLE, "Player_Idle", frame, 4);
    pDrawable->add(EntityState::LEFT, "Player_Idle", frame, 4);
    pDrawable->add(EntityState::RIGHT, "Player_Idle", frame, 4);
    pDrawable->add(EntityState::UP, "Player_Idle", frame, 4);
    pDrawable->add(EntityState::DOWN, "Player_Idle", frame, 4);
}

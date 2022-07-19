#include "SkeletonFactory.h"

void SkeletonFactory::createEntity(Entity &entity, const Context &context, Camera &camera) {
    Hitbox initialPos{2, 2};

    entity.addProperty<Hitbox>(new Property<Hitbox>(initialPos));
    entity.addProperty<StatefulDrawable>(new Property<StatefulDrawable>());
    auto drawable = entity.getProperty<StatefulDrawable>();

    Vector2Di frame{17, 19};
    std::string drawableId = "Skeleton_Idle";

    context.getTextureManager()->addTextureAndId(drawableId.data(), "Skeleton_Base.png");

    drawable->add(EntityState::IDLE, drawableId.data(), frame);
    drawable->add(EntityState::LEFT, drawableId.data(), frame);
    drawable->add(EntityState::RIGHT, drawableId.data(), frame);
    drawable->add(EntityState::UP, drawableId.data(), frame);
    drawable->add(EntityState::DOWN, drawableId.data(), frame);

    EntityState initialState{EntityState::IDLE};
    entity.addProperty<EntityState>(new Property<EntityState>(initialState));
}

std::string SkeletonFactory::createId() {
    throw Exception("SkeletonFactor::createID is not implemented");
    return "";
}

std::string SkeletonFactory::createId(const Context &context) {
    return "Skeleton_ID";
}
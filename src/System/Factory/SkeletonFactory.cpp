#include "SkeletonFactory.h"

void SkeletonFactory::createEntity(Entity &entity, const Context &context, Camera &camera) {
    HitBox initialPos{2, 2, 17, 19};

    entity.addProperty<HitBox>(new Property<HitBox>(initialPos));
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

std::string SkeletonFactory::createId(Context &context) {
    return "skeleton_"
           + std::to_string(ObjectFactory::createRandom(context))
           + "#"
           + std::to_string(ObjectFactory::createRandom(context));
}

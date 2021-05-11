//
// Created by mheisler on 10.05.21.
//

#include "BackgroundLayer.h"
#include "../../World/Objects/BackgroundObject.h"

BackgroundLayer::BackgroundLayer() {
}

BackgroundLayer::~BackgroundLayer() {
}

void BackgroundLayer::init() {
    InitalizationMapper init;

    init.setObjectId("GRASSLAND");

    auto drawable = new Drawable("Grassland", "Grassland64x64.png", 3*64, 64, 64,64, 1);

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->background.insert(std::pair<std::string, std::unique_ptr<WorldObject> >("GRASSLAND", std::make_unique<BackgroundObject>(&init)));
}

void BackgroundLayer::draw(TextureManager const* textureManager, SDL_Renderer const* renderer,const Vector2D* position = nullptr) {
    auto background= this->background.find("GRASSLAND")->second.get();

    Vector2D incX(64.0, 0.0);
    Vector2D incY(0.0, 64.0);
    Vector2D vector2D = *position;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            background->setPosition(vector2D);
            background->draw(textureManager, renderer);
            vector2D += incX;
        }
        vector2D.setX(const_cast<Vector2D*>(position)->getX());
        vector2D += incY;
    }
}

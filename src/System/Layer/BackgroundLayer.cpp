#include "BackgroundLayer.h"
#include "../../World/Objects/BackgroundObject.h"

#include <iostream>

BackgroundLayer::BackgroundLayer() {
}

BackgroundLayer::~BackgroundLayer() {
}

void BackgroundLayer::init() {
    InitalizationMapper init;

    init.setObjectId("GRASSLAND");

    auto drawable = new Drawable("Grassland", "Grassland.png", 0, 0, 64, 64, 1);

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    int x = 0;
    int y = 0;

    for (int i = 0; i < chunkElem; i++) {
        for (int j = 0; j < chunkElem; j++) {
            SDL_Rect dimension = {.x = x, .y = y, .w = 64, .h = 64};
            std::string identifier = "GRASSLAND";

            chunk[i][j].setDimension(dimension);
            chunk[i][j].setIdentifier(identifier);
            x += 64;
        }
        x = 0;
        y += 64;
    }

    this->background.insert(std::pair<std::string, std::unique_ptr<WorldObject> >("GRASSLAND",
                                                                                  std::make_unique<BackgroundObject>(
                                                                                          &init)));
}

void BackgroundLayer::draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer,
                           const Vector2D *position = nullptr) {
    for (int i = 0; i < chunkElem; i++) {
        for (int j = 0; j < chunkElem; j++) {
            Chunk currentChunk = this->chunk[i][j];
            Vector2D chunkPosition = {currentChunk.getDimension().getCornerX(),
                                      currentChunk.getDimension().getCornerY()};
            if (camera.isObjectVisible(chunkPosition, currentChunk.getDimension().getWidth(),
                                       currentChunk.getDimension().getHeight())) {
                auto backgroundSprite = this->background.find(currentChunk.getIdentifier())->second.get();
                backgroundSprite->setPosition(chunkPosition);
                backgroundSprite->draw(textureManager, camera, renderer, 0);
            }
        }
    }
}

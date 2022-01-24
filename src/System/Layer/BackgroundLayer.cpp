#include "BackgroundLayer.h"
#include "../../World/Objects/BackgroundObject.h"

#include <iostream>

BackgroundLayer::BackgroundLayer() {
}

BackgroundLayer::~BackgroundLayer() {
    // Delete allocated chunks
    for (auto const &elem: this->chunks) {
        delete[] elem.second;
    }

    this->chunks.clear();
}

void BackgroundLayer::init() {
    InitalizationMapper init;

    init.setObjectId("GRASSLAND");

    auto drawable = new Drawable("Grassland", "Grassland.png", 0, 0, 64, 64, 1);

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    Vector2D start(0.f, 0.f);
    this->createNewChunk(start, BackgroundLayer::chunkElem);

    // TODO: remove
    Vector2D second(-2048.f, -2048.f);
    this->createNewChunk(second, BackgroundLayer::chunkElem);

    this->background.insert(std::pair<std::string, std::unique_ptr<WorldObject> >("GRASSLAND",
                                                                                  std::make_unique<BackgroundObject>(
                                                                                          &init)));
}

void BackgroundLayer::draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer,
                           const Vector2D *position = nullptr) {
    Chunk **currentChunk = this->chunks.find(camera.getBoundingRect())->second;
    if(currentChunk != nullptr) {
        this->drawChunk(currentChunk, textureManager, camera, renderer);
    } else {
        std::cout << "currentChunk is null" << std::endl;
    }
}

void BackgroundLayer::createNewChunk(Vector2D &start, int elements) {
    int x = 0;
    int y = 0;

    auto chunk = new Chunk *[elements];
    for (int idx = 0; idx < elements; idx++) {
        chunk[idx] = new Chunk[elements];
    }

    for (int i = 0; i < elements; i++) {
        for (int j = 0; j < elements; j++) {
            SDL_Rect dimension = {.x = x, .y = y, .w = 64, .h = 64};
            std::string identifier = "GRASSLAND";

            chunk[i][j].setDimension(dimension);
            chunk[i][j].setIdentifier(identifier);
            x += 64;
        }
        x = 0;
        y += 64;
    }

    float dimension = static_cast<float>(elements) * 64.f;
    this->chunks.insert(std::pair<Square2D, Chunk **>(Square2D(start, dimension, dimension), chunk));

}

void BackgroundLayer::drawChunk(Chunk **&pChunk, const TextureManager *pManager, const Camera &camera,
                                const SDL_Renderer *pRenderer) {
    for (int i = 0; i < chunkElem; i++) {
        for (int j = 0; j < chunkElem; j++) {
            Vector2D chunkPosition = {pChunk[i][j].getDimension().getCornerX(),
                                      pChunk[i][j].getDimension().getCornerY()};
            if (camera.isObjectVisible(chunkPosition, pChunk[i][j].getDimension().getWidth(),
                                       pChunk[i][j].getDimension().getHeight())) {
                auto backgroundSprite = this->background.find(pChunk[i][j].getIdentifier())->second.get();
                backgroundSprite->setPosition(chunkPosition);
                backgroundSprite->draw(pManager, camera, pRenderer, 0);
            }
        }
    }
}

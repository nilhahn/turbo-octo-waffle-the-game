#include "BackgroundLayer.h"
#include "../../World/Objects/BackgroundObject.h"

#include <iostream>

BackgroundLayer::BackgroundLayer() {
    this->chunks = nullptr;
}

BackgroundLayer::~BackgroundLayer() {
    // Delete allocated chunks
    //for (auto const &elem: this->chunks) {
    //    delete[] elem.second;
    //}

    //this->chunks.clear();
}

void BackgroundLayer::init() {
    InitalizationMapper init;

    init.setObjectId("GRASSLAND");

    auto drawable = new Drawable("Grassland", "Grassland.png", 0, 0, 64, 64, 1);

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    Vector2D start(0.f, 0.f);
    this->createNewChunk(start, BackgroundLayer::chunkElem);

    Vector2D second(-2048.f, 0.f);
    this->createNewChunk(second, BackgroundLayer::chunkElem);

    this->background.insert(std::pair<std::string, std::unique_ptr<WorldObject> >("GRASSLAND",
                                                                                  std::make_unique<BackgroundObject>(
                                                                                          &init)));
}

void BackgroundLayer::draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer,
                           const Vector2D *position = nullptr) {
    if (this->chunks != nullptr) {
        Square2D cameraRect = camera.getBoundingRect();
        Chunk ***leftChunk = this->chunks->find(cameraRect);
        Chunk ***rightChunk = this->chunks->find(
                {cameraRect.getCornerX() + cameraRect.getWidth(),
                 cameraRect.getCornerY(),
                 cameraRect.getWidth(),
                 cameraRect.getHeight()});

        if (leftChunk != nullptr) {
            this->drawChunk(*leftChunk, textureManager, camera, renderer);
        }

        if (rightChunk != nullptr && leftChunk != rightChunk ) {
            this->drawChunk(*rightChunk, textureManager, camera, renderer);
        }
    }
}

void BackgroundLayer::createNewChunk(Vector2D &start, int elements) {
    int initalX = static_cast<int>(start.getX());
    int x = initalX;
    int y =  static_cast<int>(start.getY());

    auto chunk = new Chunk *[elements];

    for (int idx = 0; idx < elements; idx++) {
        chunk[idx] = new Chunk[elements];
        for (int j = 0; j < elements; j++) {
            SDL_Rect dimension = {.x = x, .y = y, .w = 64, .h = 64};
            std::string identifier = "GRASSLAND";

            chunk[idx][j].setDimension(dimension);
            chunk[idx][j].setIdentifier(identifier);
            x += 64;
        }
        x = initalX;
        y += 64;
    }

    float dimension = static_cast<float>(elements) * 64.f;
    // this->chunks.insert(std::pair<Square2D, Chunk **>(Square2D(start, dimension, dimension), chunk));
    Square2D square2D(start, dimension, dimension);
    if (this->chunks == nullptr) {
        this->chunks = new Quadtree<Chunk **>(square2D, chunk);
    } else {
        this->chunks->insert(square2D, chunk);
    }
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

/*Vector2D &BackgroundLayer::getNextPosition(Square2D &square2D) {
    return ;
}*/

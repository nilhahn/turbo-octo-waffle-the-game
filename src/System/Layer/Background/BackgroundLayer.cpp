#include "BackgroundLayer.h"
#include "../../../World/Objects/BackgroundObject.h"

#include <iostream>

BackgroundLayer::BackgroundLayer() : dist(1, std::nextafter(0, 3)) {
    this->chunks = nullptr;

    std::random_device rd;
    this->mt = std::mt19937(rd());
}

BackgroundLayer::~BackgroundLayer() {
    // Delete allocated chunks
    //for (auto const &elem: this->chunks) {
    //    delete[] elem.second;
    //}

    //this->chunks.clear();
}

void BackgroundLayer::init() {
    InitalizationMapper initDefault;
    InitalizationMapper initGrassland01;
    InitalizationMapper initGrassland02;

    initDefault.setObjectId("GRASSLAND_00");
    initGrassland01.setObjectId("GRASSLAND_01");
    initGrassland02.setObjectId("GRASSLAND_02");

    auto drawable00 = new Drawable("Grassland", "Grassland.png", 0, 0, 64, 64, 1);
    auto drawable01 = new Drawable("Grassland_01", "Grassland.png", 64, 64, 64, 64, 1);
    auto drawable02 = new Drawable("Grassland_01", "Grassland.png", 64, 0, 64, 64, 1);

    initDefault.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable00);
    initDefault.setInitalState(WorldObject::ObjectState::IDLE);

    initGrassland01.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable01);
    initGrassland01.setInitalState(WorldObject::ObjectState::IDLE);

    initGrassland02.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable02);
    initGrassland02.setInitalState(WorldObject::ObjectState::IDLE);

    Vector2D start(0.f, 0.f);
    this->createNewChunk(start, BackgroundLayer::chunkElem);

    this->background.insert(std::pair<std::string, std::unique_ptr<WorldObject> >("GRASSLAND_00",
                                                                                  std::make_unique<BackgroundObject>(
                                                                                          &initDefault)));
    this->background.insert(std::pair<std::string, std::unique_ptr<WorldObject> >("GRASSLAND_01",
                                                                                  std::make_unique<BackgroundObject>(
                                                                                          &initGrassland01)));
    this->background.insert(std::pair<std::string, std::unique_ptr<WorldObject> >("GRASSLAND_02",
                                                                                  std::make_unique<BackgroundObject>(
                                                                                          &initGrassland02)));
}

void BackgroundLayer::draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer,
                           const Vector2D *position = nullptr) {
    if (this->chunks != nullptr) {
        Square2D cameraRect = camera.getBoundingRect();
        Chunk ***leftChunk = nullptr;
        Chunk ***rightChunk = nullptr;
        Chunk ***leftBottomChunk = nullptr;
        Chunk ***rightBottomChunk = nullptr;
        Square2D nextChunkBase;
        float cnt = 0;

        do {
            leftChunk = this->chunks->find(cameraRect);

            if (leftChunk == nullptr) {
                Vector2D start = this->determineNextChunkStart(cameraRect, -1.f, -1.f);
                std::cout << "upper left was null; next will be added at x " << start.getX() << " y " << start.getY()
                          << std::endl;
                this->createNewChunk(start, chunkElem);
            }

            nextChunkBase = this->getRectWithUpperRightBase(cameraRect);
            rightChunk = this->chunks->find(nextChunkBase);

            if (rightChunk == nullptr) {
                Vector2D start = this->determineNextChunkStart(nextChunkBase,1.f, -1.f);
                start.setX(start.getX() - 640);
                std::cout << "upper right was null; next will be added at x " << start.getX() << " y " << start.getY()
                          << std::endl;
                this->createNewChunk(start, chunkElem);
            }

            nextChunkBase = this->getRectWithLowerLeftBase(cameraRect);
            leftBottomChunk = this->chunks->find(nextChunkBase);

            if (leftBottomChunk == nullptr) {
                Vector2D start = this->determineNextChunkStart(nextChunkBase,-1.f, 1.f);
                start.setY(start.getY() - 640);
                std::cout << "lower left was null; next will be added at x " << start.getX() << " y " << start.getY()
                          << std::endl;
                this->createNewChunk(start, chunkElem);
            }

            nextChunkBase = this->getRectWithLowerRightBase(cameraRect);
            rightBottomChunk = this->chunks->find(nextChunkBase);

            if (rightBottomChunk == nullptr) {
                Vector2D start = this->determineNextChunkStart(nextChunkBase, 1.f, 1.f);
                start.setX(start.getX() - 640);
                start.setY(start.getY() - 640);
                std::cout << "lower right was null; next will be added at x " << start.getX() << " y " << start.getY()
                          << std::endl;
                this->createNewChunk(start, chunkElem);
            }
            cnt++;
        } while (leftChunk == nullptr || rightChunk == nullptr || leftBottomChunk == nullptr || rightBottomChunk == nullptr);

        if (leftChunk != rightChunk && leftChunk != leftBottomChunk) {
            this->drawChunk(*leftChunk, textureManager, camera, renderer);
        }

        if (rightChunk != rightBottomChunk) {
            this->drawChunk(*rightChunk, textureManager, camera, renderer);
        }

        if (leftBottomChunk != rightBottomChunk) {
            this->drawChunk(*leftBottomChunk, textureManager, camera, renderer);
        }

        this->drawChunk(*rightBottomChunk, textureManager, camera, renderer);
    }
}

void BackgroundLayer::createNewChunk(Vector2D &start, int elements) {
    int initalX = static_cast<int>(start.getX());
    int x = initalX;
    int y = static_cast<int>(start.getY());

    auto chunk = new Chunk *[elements];
    int rand = 0;
    std::string grassland;

    for (int idx = 0; idx < elements; idx++) {
        chunk[idx] = new Chunk[elements];
        for (int j = 0; j < elements; j++) {
            SDL_Rect dimension = {.x = x, .y = y, .w = 64, .h = 64};

            chunk[idx][j].setDimension(dimension);
            rand = this->dist(mt) % 3;
            if (rand == 0) {
                grassland = "GRASSLAND_00";
            } else if (rand == 1) {
                grassland = "GRASSLAND_01";
            } else {
                grassland = "GRASSLAND_02";
            }

            chunk[idx][j].setIdentifier(grassland);

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

#include "BackgroundLayer.h"
#include "../../../World/Objects/BackgroundObject.h"

#include <iostream>

int BackgroundLayer::chunkElem = 10;

BackgroundLayer::BackgroundLayer() : dist(0, 2) {
    this->chunks = nullptr;
    this->surroundingChunks = nullptr;
}

BackgroundLayer::~BackgroundLayer() {
    if (this->surroundingChunks != nullptr) {
        delete this->surroundingChunks;
        this->surroundingChunks = nullptr;
    }
    /* TODO: clear chunks */
}

void BackgroundLayer::init(const Context &context, int width, int height)  {
    context.getTextureManager()->addTextureAndId("Grassland", "Grassland.png");

    Vector2Df start(0.f, 0.f);
    BackgroundLayer::chunkElem = width/64;
    std::cout << BackgroundLayer::chunkElem << std::endl;
    this->createNewChunk(start, BackgroundLayer::chunkElem);

    this->background.insert(std::pair<std::string, std::shared_ptr<Drawable> >("GRASSLAND_00",
                                                                               std::make_shared<Drawable>(
                                                                                       "Grassland", 0, 0, 64, 64, 1)));
    this->background.insert(std::pair<std::string, std::shared_ptr<Drawable> >("GRASSLAND_01",
                                                                               std::make_shared<Drawable>("Grassland",
                                                                                                          64, 64, 64,
                                                                                                          64, 1)));
    this->background.insert(std::pair<std::string, std::shared_ptr<Drawable> >("GRASSLAND_02",
                                                                               std::make_shared<Drawable>("Grassland",
                                                                                                          64, 0, 64, 64, 1)));
}

void BackgroundLayer::update(Context &context, const Camera &camera, Canvas &canvas) {
    if (this->chunks != nullptr) {
        Square2D cameraRect = camera.getBoundingRect();
        Chunk ***leftChunk = nullptr;
        Chunk ***rightChunk = nullptr;
        Chunk ***leftBottomChunk = nullptr;
        Chunk ***rightBottomChunk = nullptr;
        Square2D nextChunkBase;

        do {
            leftChunk = this->chunks->find(cameraRect);

            if (leftChunk == nullptr) {
                Square2D *start = this->determineNextChunkStart(cameraRect);
                if (start != nullptr) {
                    this->createNewChunkStartingAt(*start);
                }
            }

            nextChunkBase = BackgroundLayer::getRectWithUpperRightBase(cameraRect);
            rightChunk = this->chunks->find(nextChunkBase);

            if (rightChunk == nullptr) {
                Square2D *start = this->determineNextChunkStart(nextChunkBase);
                if (start != nullptr) {
                    this->createNewChunkStartingAt(*start);
                }
            }

            nextChunkBase = BackgroundLayer::getRectWithLowerLeftBase(cameraRect);
            leftBottomChunk = this->chunks->find(nextChunkBase);

            if (leftBottomChunk == nullptr) {
                Square2D *start = this->determineNextChunkStart(nextChunkBase);
                if (start != nullptr) {
                    this->createNewChunkStartingAt(*start);
                }
            }

            nextChunkBase = BackgroundLayer::getRectWithLowerRightBase(cameraRect);
            rightBottomChunk = this->chunks->find(nextChunkBase);

            if (rightBottomChunk == nullptr) {
                Square2D *start = this->determineNextChunkStart(nextChunkBase);
                if (start != nullptr) {
                    this->createNewChunkStartingAt(*start);
                }
            }
        } while (leftChunk == nullptr || rightChunk == nullptr || leftBottomChunk == nullptr ||
                 rightBottomChunk == nullptr);

        int entityIdx = 0;

        if (leftChunk != rightChunk && leftChunk != leftBottomChunk) {
            this->addChunkToScene(*leftChunk, context, camera, canvas, entityIdx);
        }

        if (rightChunk != rightBottomChunk) {
            this->addChunkToScene(*rightChunk, context, camera, canvas, entityIdx);
        }

        if (leftBottomChunk != rightBottomChunk) {
            this->addChunkToScene(*leftBottomChunk, context, camera, canvas, entityIdx);
        }

        this->addChunkToScene(*rightBottomChunk, context, camera, canvas, entityIdx);
    }
}

void BackgroundLayer::createNewChunk(Vector2Df &start, int elements) {
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
            //rand = 0; //(*this->distribution)(*mt) % 3 // this section doesn't work on linux -> sigsegv;
            rand = this->dist(rd);
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

    this->determineSurroundingChunk(square2D, dimension);
}

void BackgroundLayer::addChunkToScene(Chunk **&pChunk, Context &context, const Camera &camera, Canvas &canvas, int& entityIdx) {
    for (int i = 0; i < chunkElem; i++) {
        for (int j = 0; j < chunkElem; j++) {
            Vector2Df chunkPosition = {pChunk[i][j].getDimension().getCornerX(),
                                       pChunk[i][j].getDimension().getCornerY()};
            Vector2Df chunkDimension = {    pChunk[i][j].getDimension().getWidth(),
                                            pChunk[i][j].getDimension().getHeight()
                                        };
            if (camera.isObjectVisible(chunkPosition, chunkDimension.getX(), chunkDimension.getY())) {
                auto backgroundSprite = this->background.find(pChunk[i][j].getIdentifier())->second.get();

                Entity* entity;
                if(entityPool.size() < (entityIdx + 1) ) {
                    entity = new Entity("background_object_" + std::to_string(entityIdx));
                    entity->addProperty(new Property<Drawable>(*backgroundSprite));
                    HitBox hitBox{chunkPosition.getX(), chunkPosition.getY(),  chunkDimension.getX(), chunkDimension.getY(),false};
                    entity->addProperty(new Property<HitBox>(hitBox));
                    entityPool.push_back(std::make_shared<Entity>(*entity));
                } else {
                  entity = entityPool.at(entityIdx).get();
                  entity->getProperty<Drawable>()->copyState(*backgroundSprite);
                  entity->getProperty<HitBox>()->positionAt(chunkPosition);
                }

                canvas.addToScene(entityPool.at(entityIdx));
                entityIdx++;
            }
        }
    }
}

void BackgroundLayer::determineSurroundingChunk(Square2D &square2D, float d) {
    Square2D left = {square2D.getCornerX() - d, square2D.getCornerY(), d, d};
    Square2D upper = {square2D.getCornerX(), square2D.getCornerY() - d, d, d};
    Square2D right = {square2D.getCornerX() + d, square2D.getCornerY(), d, d};
    Square2D lower = {square2D.getCornerX(), square2D.getCornerY() + d, d, d};

    if (this->surroundingChunks == nullptr) {
        this->surroundingChunks = new Quadtree<Square2D>(left, left);
    } else {
        if (!this->surroundingChunks->contains(left)) {
            this->surroundingChunks->insert(left, left);
        }
    }

    if (!this->surroundingChunks->contains(upper)) {
        this->surroundingChunks->insert(upper, upper);
    }

    if (!this->surroundingChunks->contains(right)) {
        this->surroundingChunks->insert(right, right);
    }

    if (!this->surroundingChunks->contains(lower)) {
        this->surroundingChunks->insert(lower, lower);
    }
}

Vector2Df BackgroundLayer::createNewChunkStartingAt(Square2D &square2D) {
    Vector2Df chunk = {square2D.getCornerX(), square2D.getCornerY()};
    this->createNewChunk(chunk, chunkElem);
    return chunk;
}

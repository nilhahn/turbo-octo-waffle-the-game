#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

#include <vector>
#include <map>
#include <memory>
#include <cmath>
#include <random>

#include "../Layer.h"

#include "../../Quadtree.h"
#include "../../../World/WorldObject.h"
#include "../../../World/InitalizationMapper.h"
#include "../../../World/BuildingBlocks/Chunk.h"

class BackgroundLayer : public Layer {
public:
    BackgroundLayer();

    ~BackgroundLayer() override;

    void init(const Context &context, int width, int height) override;

    void update(Context &context, const Camera &camera, Canvas &canvas) override;

private:
    static int chunkElem;
    std::uniform_int_distribution<int> dist;
    std::random_device rd;

    void createNewChunk(Vector2Df &start, int elements);

    std::map<std::string, std::shared_ptr<Drawable> > background;
    std::vector<std::shared_ptr<Entity> > entityPool;

    Quadtree<Chunk **> *chunks;
    Quadtree<Square2D> *surroundingChunks;

    void addChunkToScene(Chunk **&pChunk, Context &context, const Camera &camera, Canvas &canvas, int& entityIdx);

    inline Square2D *determineNextChunkStart(Square2D &square2D) {
        Square2D search = {square2D.getCornerX(), square2D.getCornerY(), 0.f, 0.f};
        return this->surroundingChunks->find(search);
    }

    static inline Square2D getRectWithUpperRightBase(Square2D square2D) {
        return {square2D.getCornerX() + square2D.getWidth(), square2D.getCornerY(), square2D.getWidth(),
                square2D.getHeight()};
    };

    static inline Square2D getRectWithLowerLeftBase(Square2D square2D) {
        return {square2D.getCornerX(), square2D.getCornerY() + square2D.getHeight(), square2D.getWidth(),
                square2D.getHeight()};
    };

    static inline Square2D getRectWithLowerRightBase(Square2D square2D) {
        return {square2D.getCornerX() + square2D.getWidth(), square2D.getCornerY() + square2D.getHeight(),
                square2D.getWidth(), square2D.getHeight()};
    };

    void determineSurroundingChunk(Square2D &square2D, float d);

    Vector2Df createNewChunkStartingAt(Square2D &square2D);
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

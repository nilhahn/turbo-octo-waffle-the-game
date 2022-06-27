#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

#include <vector>
#include <map>
#include <memory>
#include <math.h>
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

    void init() override;

    void draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer,
              Vector2D const *position) override;

private:
    static constexpr int chunkElem = 10;
    std::uniform_int_distribution<int> dist;
    std::random_device rd;

    void createNewChunk(Vector2D &start, int elements);

    std::map<std::string, std::unique_ptr<WorldObject> > background;
    Quadtree<Chunk **> *chunks;
    Quadtree<Square2D> *surroundingChunks;

    void
    drawChunk(Chunk **&pChunk, const TextureManager *pManager, const Camera &camera, const SDL_Renderer *pRenderer);

    inline Square2D* determineNextChunkStart(Square2D &square2D) {
        Square2D search = {square2D.getCornerX(), square2D.getCornerY(), 0.f, 0.f};
        return this->surroundingChunks->find(search);
    }

    inline const Square2D getRectWithUpperRightBase(Square2D square2D) {
        return {square2D.getCornerX() + square2D.getWidth(), square2D.getCornerY(), square2D.getWidth(),
                square2D.getHeight()};
    };

    inline const Square2D getRectWithLowerLeftBase(Square2D square2D) {
        return {square2D.getCornerX(), square2D.getCornerY() + square2D.getHeight(), square2D.getWidth(),
                square2D.getHeight()};
    };

    inline const Square2D getRectWithLowerRightBase(Square2D square2D) {
        return {square2D.getCornerX() + square2D.getWidth(), square2D.getCornerY() + square2D.getHeight(),
                square2D.getWidth(), square2D.getHeight()};
    };

    void determineSurroundingChunk(Square2D &square2D, float d);

    Vector2D createNewChunkStartingAt(Square2D& square2D);
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H
#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

#include <vector>
#include <map>
#include <memory>
#include <math.h>

#include "Layer.h"

#include "../Quadtree.h"
#include "../../World/WorldObject.h"
#include "../../World/InitalizationMapper.h"
#include "../../World/BuildingBlocks/Chunk.h"

class BackgroundLayer : public Layer {
public:
    BackgroundLayer();

    ~BackgroundLayer() override;

    void init() override;

    void draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer,
              Vector2D const *position) override;

private:
    static constexpr int chunkElem = 32;

    void createNewChunk(Vector2D &start, int elements, std::string identifier);

    std::map<std::string, std::unique_ptr<WorldObject> > background;
    //std::map<Square2D, Chunk**> chunks;
    Quadtree<Chunk **> *chunks;

    void
    drawChunk(Chunk **&pChunk, const TextureManager *pManager, const Camera &camera, const SDL_Renderer *pRenderer);

    // Vector2D &getNextPosition(Square2D &square2D);
    inline Vector2D determineNextChunkStart(Square2D square2D, float quadrantX, float quadrantY) {
        int multipleX = (static_cast<int>(std::abs(square2D.getCornerX())) / 2048);
        float nextX = static_cast<float>(multipleX + 1) * quadrantX * 2048.f;

        int multipleY = (static_cast<int>(std::abs(square2D.getCornerY())) / 2048);
        float nextY = static_cast<float>(multipleY + 1) * quadrantY * 2048.f;

        return {nextX, nextY};
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
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

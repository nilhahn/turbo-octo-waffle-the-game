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

#include <random>

class BackgroundLayer : public Layer {
public:
    BackgroundLayer();

    ~BackgroundLayer() override;

    void init() override;

    void draw(TextureManager const *textureManager, const Camera &camera, SDL_Renderer const *renderer,
              Vector2D const *position) override;

private:
    static constexpr int chunkElem = 32;
    std::uniform_int_distribution<int> dist;
    std::mt19937 mt;

    void createNewChunk(Vector2D &start, int elements);

    std::map<std::string, std::unique_ptr<WorldObject> > background;
    Quadtree<Chunk **> *chunks;

    void drawChunk(Chunk **&pChunk, const TextureManager *pManager, const Camera &camera, const SDL_Renderer *pRenderer);

    // Vector2D &getNextPosition(Square2D &square2D);
    inline Vector2D determineNextChunkStart(Square2D square2D, float quadrantX, float quadrantY) {
        int multipleX = (static_cast<int>(std::abs(square2D.getCornerX())) / 2048);
        int multipleY = (static_cast<int>(std::abs(square2D.getCornerY())) / 2048);
        int quadrantModifierX = 0;
        int quadrantModifierY = 0;

        if(quadrantX == -1 && quadrantY == -1) {
            quadrantModifierX = 1;
            quadrantModifierY = 1;
        } else if(quadrantX == 1 && quadrantY == -1) {
            quadrantModifierX = 0;
            quadrantModifierY = 1;
        } else if(quadrantX == -1 && quadrantY == 1) {
            quadrantModifierX = 1;
            quadrantModifierY = 0;
        } else if(quadrantX == 1 && quadrantY == 1) {
            // do nothing
        }

        float nextX = static_cast<float>(multipleX + quadrantModifierX) * quadrantX * 2048.f;
        float nextY = static_cast<float>(multipleY + quadrantModifierY) * quadrantY * 2048.f;

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

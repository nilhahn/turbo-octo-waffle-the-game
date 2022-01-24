#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

#include <vector>
#include <map>
#include <memory>

#include "Layer.h"

#include "../../World/WorldObject.h"
#include "../../World/InitalizationMapper.h"
#include "../../World/BuildingBlocks/Chunk.h"

class BackgroundLayer: public Layer {
public:
    BackgroundLayer();
    ~BackgroundLayer() override;

    void init() override;
    void draw(TextureManager const* textureManager, const Camera& camera, SDL_Renderer const* renderer, Vector2D const* position) override;

private:
    static constexpr int chunkElem = 32;

    void createNewChunk(Vector2D& start, int elements);

    std::map<std::string, std::unique_ptr<WorldObject> > background;
    std::map<Square2D, Chunk**> chunks;

    void
    drawChunk(Chunk **&pChunk, const TextureManager *pManager, const Camera &camera, const SDL_Renderer *pRenderer);
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

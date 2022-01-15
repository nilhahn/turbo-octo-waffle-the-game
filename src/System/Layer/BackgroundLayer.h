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

    std::map<std::string, std::unique_ptr<WorldObject> > background;

    Chunk chunk[chunkElem][chunkElem];
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

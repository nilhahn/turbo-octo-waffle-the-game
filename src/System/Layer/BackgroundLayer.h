//
// Created by mheisler on 10.05.21.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

#include <vector>
#include <map>
#include <memory>

#include "../../World/WorldObject.h"
#include "../../World/InitalizationMapper.h"
#include "Layer.h"

class BackgroundLayer: public Layer {
public:
    BackgroundLayer();
    ~BackgroundLayer() override;

    void init() override;
    void draw(TextureManager const* textureManager, SDL_Renderer const* renderer, Vector2D const* position) override;

private:
    std::map<std::string, std::unique_ptr<WorldObject> > background;

    SDL_Rect chunk[8][8];

    int width;
    int height;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_BACKGROUNDLAYER_H

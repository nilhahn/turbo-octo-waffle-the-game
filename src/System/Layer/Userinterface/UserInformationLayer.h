#ifndef TURBO_OCTO_WAFFLE_THE_GAME_USERINFORMATIONLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_USERINFORMATIONLAYER_H

#include "../Layer.h"

class UserInformationLayer: public Layer {
public:
    void init() override;
    void draw(TextureManager const* textureManager, const Camera& camera, SDL_Renderer const* renderer, Vector2D const* position) override;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_USERINFORMATIONLAYER_H

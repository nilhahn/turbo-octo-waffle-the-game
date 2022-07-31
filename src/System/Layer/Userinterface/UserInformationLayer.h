#ifndef TURBO_OCTO_WAFFLE_THE_GAME_USERINFORMATIONLAYER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_USERINFORMATIONLAYER_H

#include "../Layer.h"

class UserInformationLayer : public Layer {
public:
    void init(const Context& context, int width, int height) override;

    void update(Context &context, const Camera &camera, Canvas &canvas) override;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_USERINFORMATIONLAYER_H

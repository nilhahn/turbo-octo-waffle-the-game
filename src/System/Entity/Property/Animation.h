#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H

#include <string>
#include "../BaseProperty.h"
#include "../../../Resource/TextureManager.h"

class Animation : public BaseProperty {
    public:

private:
    std::string id;
    unsigned currentFrame;
    unsigned numberOfFrames;

    void update();
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H

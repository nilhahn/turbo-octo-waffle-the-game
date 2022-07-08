#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H

#include <string>
#include "../../Resource/TextureManager.h"

class Drawable {
public:
    Drawable(const char *id, const char *fileName, int widthOfFrame, int heightOfFrame, unsigned numberOfFrames = 1);

    Drawable(const char *id, const char *fileName, int frameOffsetX, int frameOffsetY, int widthOfFrame,
             int heightOfFrame, unsigned numberOfFrames = 1);

    explicit Drawable(Drawable *drawable);

    std::string getId() const;

    std::string getFile() const;

    const SDL_Rect& getFrame(long delta);

private:
    std::string id;
    std::string file;
    SDL_Rect frameOffset;
    SDL_Rect encapsulatingRect;
    int currentFrame;
    unsigned numberOfFrames;
    long delta;
    long deltaToNextFrame;

    void updateFrameCnt(long deltaMs);

    void prepareDrawable(const char *id, const char *fileName, int widthOfFrame, int heightOfFrame,
                         unsigned numberOfFrames = 1);

    std::string getFileName();

    SDL_Rect getEncapsulatingRect();

    unsigned int getCurrentFrame();

    unsigned int getNumberOfFrames();
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H

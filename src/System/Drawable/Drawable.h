#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H

#include <string>

#include "TextureManager.h"

class Drawable {
public:
    // Default constructor so a Drawable can be used as Property
    Drawable();

    Drawable(const char *id, int widthOfFrame, int heightOfFrame, unsigned numberOfFrames = 1);

    Drawable(const char *id, int frameOffsetX, int frameOffsetY, int widthOfFrame,
             int heightOfFrame, unsigned numberOfFrames = 1);

    explicit Drawable(const Drawable *drawable);

    std::string getId() const;

    void copyState(const Drawable& drawable);

    std::string getFile() const;

    const SDL_Rect &getFrame(long delta);

private:
    std::string id;
    SDL_Rect frameOffset;
    SDL_Rect encapsulatingRect;
    int currentFrame;
    unsigned numberOfFrames;
    long delta;
    long deltaToNextFrame;

    void updateFrameCnt(long deltaMs);

    void prepareDrawable(const char *drawableId, int widthOfFrame, int heightOfFrame,
                         unsigned frameCount = 1);

    SDL_Rect getEncapsulatingRect();

    unsigned int getCurrentFrame();

    unsigned int getNumberOfFrames();
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H

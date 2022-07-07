#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H

#include <string>
#include "../../Resource/TextureManager.h"
#include "../Vector2D.h"

class Drawable {
public:
    Drawable(const char *id, const char *fileName, int widthOfFrame, int heightOfFrame, unsigned numberOfFrames = 1);

    Drawable(const char *id, const char *fileName, int frameOffsetX, int frameOffsetY, int widthOfFrame,
             int heightOfFrame, unsigned numberOfFrames = 1);

    explicit Drawable(Drawable *drawable);

    void
    drawFrameToRenderer(TextureManager *textureManager, SDL_Renderer *renderer, Vector2D *windowPosition, bool flip,
                        unsigned scale, bool increment = true, double angle = 0.0);

    void nextFrame();

    std::string getId() const;

    std::string getFile() const;

private:
    std::string id;
    std::string file;
    SDL_Rect frameOffset;
    SDL_Rect encapsulatingRect;
    int currentFrame;
    unsigned numberOfFrames;

    void updateFrameCnt();

    void prepareDrawable(const char *id, const char *fileName, int widthOfFrame, int heightOfFrame,
                         unsigned numberOfFrames = 1);

    SDL_Rect prepareFrame(Vector2D *position, unsigned scale);

    void renderFrame(SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_Rect *pD, bool flip, double angle = 0.0);

    void scaleFrame(SDL_Rect *pRect, unsigned scale);

    std::string getFileName();

    SDL_Rect getEncapsulatingRect();

    SDL_Rect getFrameOffset();

    unsigned int getCurrentFrame();

    unsigned int getNumberOfFrames();
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ANIMATION_H

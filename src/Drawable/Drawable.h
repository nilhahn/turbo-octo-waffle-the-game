//
// Created by matze on 26.05.20.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_DRAWABLE_H
#define TURBO_OCTO_WAFFLE_THE_GAME_DRAWABLE_H

#include <string>
#include "../Resource/TextureManager.h"
#include "../System/Vector2D.h"

class Drawable {
public:
    Drawable(const char* id, const char* fileName, int widhtOfFrame, int heightOfFrame, unsigned numberOfFrames = 1);

    void drawFrameToRenderer(TextureManager* textureManager, SDL_Renderer* renderer, Vector2D* position, bool flip, unsigned scale);
private:
    std::string id;
    std::string file;
    SDL_Rect encapsulatingRect;
    unsigned currentFrame;
    unsigned numberOfFrames;

    void updateFrameCnt();
    SDL_Rect prepareFrame(Vector2D* position, unsigned scale);

    void renderFrame(SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_Rect* pD, bool );

    void scaleFrame(SDL_Rect *pRect, unsigned scale);
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_DRAWABLE_H

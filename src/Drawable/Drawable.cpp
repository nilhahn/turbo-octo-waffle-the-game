//
// Created by matze on 26.05.20.
//

#include "Drawable.h"

Drawable::Drawable(const char* id, const char* fileName, int widhtOfFrame, int heightOfFrame, unsigned numberOfFrames) {
    this->id = id;
    this->file = fileName;
    this->encapsulatingRect.w = widhtOfFrame;
    this->encapsulatingRect.h = heightOfFrame;
    this->currentFrame = 0;
    this->numberOfFrames = numberOfFrames;
}

void Drawable::drawFrameToRenderer(TextureManager *textureManager, SDL_Renderer *renderer, Vector2D *position, bool flip, unsigned scale) {
    SDL_Texture* texture = textureManager->getTexture(this->id.data());
    if(texture == nullptr && textureManager->load(this->file.data(), this->id.data(), renderer)) {
        // Something bad happened TODO: Decide what should happen here
        return;
    }
    SDL_Rect destinationRect = this->prepareFrame(position, scale);
    this->renderFrame(texture, renderer, &destinationRect, flip);
    this->updateFrameCnt();
}

void Drawable::updateFrameCnt() {
    if(this->numberOfFrames > 1) {
        this->currentFrame = (this->currentFrame + 1) % this->numberOfFrames;
    }
}

SDL_Rect Drawable::prepareFrame(Vector2D* position, unsigned scale) {
    SDL_Rect frameDest;
    this->encapsulatingRect.x = this->encapsulatingRect.w * this->currentFrame;
    this->encapsulatingRect.y = 0;

    frameDest.x = static_cast<int>(position->getX());
    frameDest.y = static_cast<int>(position->getY());

    this->scaleFrame(&frameDest,scale);

    return frameDest;
}

void Drawable::renderFrame(SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_Rect *destination, bool flip) {
    SDL_RenderCopyEx(pRenderer, pTexture, &this->encapsulatingRect, destination, 0, 0, flip ? SDL_FLIP_HORIZONTAL: SDL_FLIP_NONE);
}

void Drawable::scaleFrame(SDL_Rect *pRect, unsigned scale) {
    int width = this->encapsulatingRect.w;
    int height = this->encapsulatingRect.h;

    if(scale > 0) {
        width *= static_cast<int>(scale);
        height *= static_cast<int>(scale);
    }

    pRect->w = width;
    pRect->h = height;
}

std::string Drawable::getId() {
    return this->id;
}

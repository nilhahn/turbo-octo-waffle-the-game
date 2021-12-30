#include "Drawable.h"

Drawable::Drawable(const char* id, const char* fileName, int widhtOfFrame, int heightOfFrame, unsigned numberOfFrames) {
    this->prepareDrawable(id, fileName, widhtOfFrame, heightOfFrame, numberOfFrames);
    this->frameOffset.x = 0;
    this->frameOffset.y = 0;
}

Drawable::Drawable(const char* id, const char* fileName, int frameOffsetX, int frameOffsetY, int widhtOfFrame, int heightOfFrame, unsigned numberOfFrames) {
    this->prepareDrawable(id, fileName, widhtOfFrame, heightOfFrame, numberOfFrames);
    this->frameOffset.x = frameOffsetX;
    this->frameOffset.y = frameOffsetY;
}

Drawable::Drawable(Drawable *drawable) {
    this->id = drawable->getId();
    this->file = drawable->getFileName();
    this->encapsulatingRect = drawable->getEncapsulatingRect();
    this->currentFrame = drawable->getCurrentFrame();
    this->numberOfFrames = drawable->getNumberOfFrames();
    this->frameOffset = drawable->getFrameOffset();
}

void Drawable::drawFrameToRenderer(TextureManager *textureManager, SDL_Renderer *renderer, Vector2D *position, bool flip, unsigned scale, bool increment, double angle) {
    SDL_Texture* texture = textureManager->getTexture(this->id.data());
    if(texture == nullptr && textureManager->load(this->file.data(), this->id.data(), renderer)) {
        // Something bad happened
        // TODO: Decide what should happen here
        return;
    }
    SDL_Rect destinationRect = this->prepareFrame(position, scale);
    this->renderFrame(texture, renderer, &destinationRect, flip, angle);
    if(increment) {
        this->updateFrameCnt();
    }
}

void Drawable::updateFrameCnt() {
    if(this->numberOfFrames > 1) {
        this->currentFrame = (this->currentFrame + 1) % this->numberOfFrames;
    }
}

void Drawable::prepareDrawable(const char *id, const char *fileName, int widhtOfFrame, int heightOfFrame,
                               unsigned int numberOfFrames) {
    this->id = id;
    this->file = fileName;
    this->encapsulatingRect.w = widhtOfFrame;
    this->encapsulatingRect.h = heightOfFrame;
    this->currentFrame = 0;
    this->numberOfFrames = numberOfFrames;
}

SDL_Rect Drawable::prepareFrame(Vector2D* position, unsigned scale) {
    SDL_Rect frameDest;

    this->encapsulatingRect.x = this->frameOffset.x + this->encapsulatingRect.w * this->currentFrame;
    this->encapsulatingRect.y = this->frameOffset.y;

    frameDest.x = static_cast<int>(position->getX());
    frameDest.y = static_cast<int>(position->getY());

    this->scaleFrame(&frameDest,scale);

    return frameDest;
}

void Drawable::renderFrame(SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_Rect *destination, bool flip, double angle) {
    SDL_RenderCopyEx(pRenderer, pTexture, &this->encapsulatingRect, destination, angle, nullptr, flip ? SDL_FLIP_HORIZONTAL: SDL_FLIP_NONE);
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

std::string Drawable::getFileName() {
    return this->file;
}

SDL_Rect Drawable::getEncapsulatingRect() {
    return this->encapsulatingRect;
}

SDL_Rect Drawable::getFrameOffset() {
    return this->frameOffset;
}

unsigned int Drawable::getCurrentFrame() {
    return this->currentFrame;
}

unsigned int Drawable::getNumberOfFrames() {
    return this->numberOfFrames;
}

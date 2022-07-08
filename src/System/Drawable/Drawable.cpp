#include "Drawable.h"

Drawable::Drawable(const char* id, const char* fileName, int widhtOfFrame, int heightOfFrame, unsigned numberOfFrames) {
    this->prepareDrawable(id, fileName, widhtOfFrame, heightOfFrame, numberOfFrames);
    this->frameOffset.x = 0;
    this->frameOffset.y = 0;
    this->delta = 0;
    this->deltaToNextFrame = 500;
}

Drawable::Drawable(const char* id, const char* fileName, int frameOffsetX, int frameOffsetY, int widhtOfFrame, int heightOfFrame, unsigned numberOfFrames) {
    this->prepareDrawable(id, fileName, widhtOfFrame, heightOfFrame, numberOfFrames);
    this->frameOffset.x = frameOffsetX;
    this->frameOffset.y = frameOffsetY;
    this->delta = 0;
    this->deltaToNextFrame = 500;
}

Drawable::Drawable(Drawable *drawable) {
    this->id = drawable->getId();
    this->file = drawable->getFileName();
    this->encapsulatingRect = drawable->getEncapsulatingRect();
    this->currentFrame = drawable->getCurrentFrame();
    this->numberOfFrames = drawable->getNumberOfFrames();
    this->delta = drawable->delta;
    this->deltaToNextFrame = drawable->deltaToNextFrame;
}

void Drawable::prepareDrawable(const char *id, const char *fileName, int widthOfFrame, int heightOfFrame,
                               unsigned int numberOfFrames) {
    this->id = id;
    this->file = fileName;
    this->encapsulatingRect.w = widthOfFrame;
    this->encapsulatingRect.h = heightOfFrame;
    this->currentFrame = 0;
    this->numberOfFrames = numberOfFrames;
}

std::string Drawable::getId() const{
    return this->id;
}

std::string Drawable::getFileName() {
    return this->file;
}

SDL_Rect Drawable::getEncapsulatingRect() {
    return this->encapsulatingRect;
}

unsigned int Drawable::getCurrentFrame() {
    return this->currentFrame;
}

unsigned int Drawable::getNumberOfFrames() {
    return this->numberOfFrames;
}

std::string Drawable::getFile() const {
    return this->file;
}

const SDL_Rect& Drawable::getFrame(long deltaMs) {
    this->updateFrameCnt(deltaMs);
    this->encapsulatingRect.x = this->frameOffset.x + this->encapsulatingRect.w * this->currentFrame;
    this->encapsulatingRect.y = this->frameOffset.y;
    return this->encapsulatingRect;
}

void Drawable::updateFrameCnt(long deltaMs) {
    this->delta += deltaMs;
    if((this->numberOfFrames > 1) && (this->delta >= this->deltaToNextFrame)) {
        this->currentFrame = (this->currentFrame + 1) % this->numberOfFrames;
    }
}

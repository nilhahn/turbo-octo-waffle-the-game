#include "Drawable.h"

Drawable::Drawable() {
    this->id = "";
    this->deltaToNextFrame = 0;
    this->encapsulatingRect= {0,0,0,0};
    this->frameOffset= {0,0,0,0};
    this->delta = 0;
    this->numberOfFrames = 0;
}

Drawable::Drawable(const char *id, int widhtOfFrame, int heightOfFrame, unsigned numberOfFrames) {
    this->prepareDrawable(id, widhtOfFrame, heightOfFrame, numberOfFrames);
    this->frameOffset.x = 0;
    this->frameOffset.y = 0;
    this->delta = 0;
    this->deltaToNextFrame = 500;
}

Drawable::Drawable(const char *id, int frameOffsetX, int frameOffsetY, int widhtOfFrame, int heightOfFrame,
                   unsigned numberOfFrames) {
    this->prepareDrawable(id, widhtOfFrame, heightOfFrame, numberOfFrames);
    this->frameOffset.x = frameOffsetX;
    this->frameOffset.y = frameOffsetY;
    this->delta = 0;
    this->deltaToNextFrame = 500;
}

Drawable::Drawable(const Drawable *drawable) {
    this->copyState(drawable);
}

void Drawable::prepareDrawable(const char *drawableId, int widthOfFrame, int heightOfFrame,
                               unsigned int frameCount) {
    this->id = drawableId;
    this->encapsulatingRect.x = 0;
    this->encapsulatingRect.y = 0;
    this->encapsulatingRect.w = widthOfFrame;
    this->encapsulatingRect.h = heightOfFrame;
    this->currentFrame = 0;
    this->numberOfFrames = frameCount;
}

std::string Drawable::getId() const {
    return this->id;
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

const SDL_Rect &Drawable::getFrame(long deltaMs) {
    this->updateFrameCnt(deltaMs);
    this->encapsulatingRect.x = this->frameOffset.x + this->encapsulatingRect.w * this->currentFrame;
    this->encapsulatingRect.y = this->frameOffset.y;
    return this->encapsulatingRect;
}

void Drawable::updateFrameCnt(long deltaMs) {
    this->delta += deltaMs;
    if ((this->numberOfFrames > 1) && (this->delta >= this->deltaToNextFrame)) {
        this->currentFrame = (this->currentFrame + 1) % this->numberOfFrames;
        this->delta = 0;
    }
}

void Drawable::copyState(const Drawable *drawable) {
    this->id = drawable->getId();
    this->encapsulatingRect = drawable->encapsulatingRect;
    this->currentFrame = drawable->currentFrame;
    this->numberOfFrames = drawable->numberOfFrames;
    this->delta = drawable->delta;
    this->deltaToNextFrame = drawable->deltaToNextFrame;
    this->frameOffset = drawable->frameOffset;
}

#include "Context.h"

Context::Context(Window *window) {
    this->window = window;
}

Context::~Context() {
    if (window != nullptr) {
        delete window;
        window = nullptr;
    }
}

Window *Context::getWindow() const {
    return this->window;
}

TextureManager *Context::getTextureManager() const {
    return this->window->getTextureManager();
}

int Context::getRand() {
    return this->dist(rd);
}

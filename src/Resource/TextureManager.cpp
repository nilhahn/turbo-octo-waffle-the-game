#include "TextureManager.h"

TextureManager* TextureManager::manager = nullptr;

bool TextureManager::load(const char*  fileName, const char* id, SDL_Renderer &renderer) {
    bool result = false;
    std::string filePath = this->resourcePath + fileName;
    if(this->textureContainer.find(id) == textureContainer.end()) {
        SDL_Surface* surface = IMG_Load(filePath.data());
        this->textureContainer.insert({id, SDL_CreateTextureFromSurface(&renderer, surface)});
        SDL_FreeSurface(surface);
        result = true;
    }
    return result;
}

TextureManager::TextureManager(const std::string& baseResourcePath) {
    this->resourcePath = baseResourcePath;
}

SDL_Texture *TextureManager::getTexture(const char* id) {
    if(this->textureContainer.find(id) == this->textureContainer.end()) {
        return nullptr;
    }
    return this->textureContainer.at(id);
}

TextureManager *TextureManager::instance(const std::string& baseResourcePath) {
    if(manager == nullptr) {
        manager = new TextureManager(baseResourcePath);
    }
    return manager;
}


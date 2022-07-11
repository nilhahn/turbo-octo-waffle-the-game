#include "TextureManager.h"

TextureManager *TextureManager::manager = nullptr;

bool TextureManager::load(const std::string& fileName, const std::string& id, SDL_Renderer &renderer) {
    bool result = false;
    std::string filePath = this->resourcePath + fileName;
    if (this->textureContainer.find(id) == textureContainer.end()) {
        SDL_Surface *surface = IMG_Load(filePath.data());
        this->textureContainer.insert({id, SDL_CreateTextureFromSurface(&renderer, surface)});
        SDL_FreeSurface(surface);
        result = true;
    }
    return result;
}

TextureManager::TextureManager(const std::string &baseResourcePath) {
    this->resourcePath = baseResourcePath;
}

SDL_Texture *TextureManager::loadTexture(const char *id, SDL_Renderer &renderer) {
    if (this->textureContainer.find(id) == this->textureContainer.end()) {
        auto path = this->texturePath.find(id);
        if(path == this->texturePath.end()) {
            return nullptr;
        }
        this->load(path->second, path->first, renderer);
    }
    return this->textureContainer.at(id);
}

TextureManager *TextureManager::instance(const std::string &baseResourcePath) {
    if (manager == nullptr) {
        manager = new TextureManager(baseResourcePath);
    }
    return manager;
}

void TextureManager::addTextureAndId(const char *id, const char *textureLocation) {
    if (nullptr != id && nullptr != textureLocation) {
        this->texturePath.insert(std::pair<std::string, std::string>(id, textureLocation));
    }
}

void TextureManager::removeTexture(const std::string &id) {
    auto resource = this->textureContainer.find(id);
    if(this->textureContainer.end() != resource) {
        SDL_DestroyTexture(resource->second);
        this->textureContainer.erase(resource);
    }
}


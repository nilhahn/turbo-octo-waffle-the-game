//
// Created by matze on 18.05.20.
//

#ifndef TURBO_OCTO_WAFFLE_THE_GAME_TEXTUREMANAGER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_TEXTUREMANAGER_H

#include <map>

#include "SDL.h"
#include "SDL_image.h"
#include "../System/Texture.h"

class TextureManager {
public:
    bool load(const char* fileName, const char* id, SDL_Renderer* renderer);
    SDL_Texture* getTexture(const char*  id);

    static TextureManager* instance(const std::string& baseResourcePath = "");
private:
    explicit TextureManager(const std::string& baseResourcePath);

    std::map<std::string, SDL_Texture*> textureContainer;
    std::string resourcePath;

    static TextureManager* manager;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_TEXTUREMANAGER_H

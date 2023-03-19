#ifndef TURBO_OCTO_WAFFLE_THE_GAME_TEXTUREMANAGER_H
#define TURBO_OCTO_WAFFLE_THE_GAME_TEXTUREMANAGER_H

#include <map>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

class TextureManager {
public:
    bool load(const std::string &fileName, const std::string &id, SDL_Renderer &renderer);

    void addTextureAndId(const char *id, const char *textureLocation);

    SDL_Texture *loadTexture(const char *id, SDL_Renderer &renderer);

    void removeTexture(const std::string &id);

    static TextureManager *instance(const std::string &baseResourcePath = "");

    void clear();
private:
    explicit TextureManager(const std::string &baseResourcePath);

    std::map<std::string, SDL_Texture *> textureContainer;
    std::map<std::string, std::string> texturePath;
    std::string resourcePath;

    static TextureManager *manager;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_TEXTUREMANAGER_H

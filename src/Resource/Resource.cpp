#include "Resource.h"

const std::string Resource::PATH_SEP = "\\";

std::string Resource::getResourcePath(const std::string &subDir) {

    static std::string baseRes;
    char *basePath = SDL_GetBasePath();
    if(basePath) {
        baseRes = basePath;
        SDL_free(basePath);
    }else {
        std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
        return "";
    }

    size_t pos = baseRes.rfind("bin");
    baseRes = baseRes.substr(0, pos) + "..\\..\\" "assets" + Resource::PATH_SEP;

    return subDir.empty() ? baseRes : baseRes + subDir + Resource::PATH_SEP;
}
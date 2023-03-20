#include "Resource.h"

#ifdef _WIN32
const std::string Resource::PATH_SEP = "\\";
#else
const std::string Resource::PATH_SEP = "/";
#endif

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
    baseRes = baseRes.substr(0, pos) +
            ".." + Resource::PATH_SEP +
            ".." + Resource::PATH_SEP +
            "assets" + Resource::PATH_SEP;

    return subDir.empty() ? baseRes : baseRes + subDir + Resource::PATH_SEP;
}
#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include "SDL.h"

class Resource
{
public:
    static std::string getResourcePath(const std::string& subDir = "");
    static const std::string PATH_SEP;

private:
    Resource() = default;
};

#endif // RESOURCE_H
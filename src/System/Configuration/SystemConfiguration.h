#ifndef TURBO_OCTO_WAFFLE_THE_GAME_SYSTEMCONFIGURATION_H
#define TURBO_OCTO_WAFFLE_THE_GAME_SYSTEMCONFIGURATION_H

#include <memory>
#include <map>

#include "File/FileReader.h"
#include "Configuration.h"

class SystemConfiguration {
public:
    void load(std::string& load);

private:
    std::map<std::string, std::unique_ptr<Configuration> > configurationStore;
};

#endif

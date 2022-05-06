#include "SystemConfiguration.h"

void SystemConfiguration::load(std::string &configurationPath) {
    FileReader reader(configurationPath.data());
    std::string path;
    std::string line;

    while(reader.getLine(line) > 0) {
       // empty for now
    }
}

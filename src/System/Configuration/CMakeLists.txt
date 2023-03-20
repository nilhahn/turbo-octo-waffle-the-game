set(FILE_LIBRARY ${PROJECT_NAME}-file)

add_subdirectory(File)

set(CONFIGURATION_SOURCES
        Configuration.cpp
        LevelConfiguration.cpp
        SystemConfiguration.cpp)

set(CONFIGURATION_INCLUDES
        "./")

add_library(${CONFIGURATION_LIBRARY} STATIC
        ${CONFIGURATION_SOURCES})
target_include_directories(${CONFIGURATION_LIBRARY} PUBLIC
        ${CONFIGURATION_INCLUDES})
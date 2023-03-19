set(BUILDING_BLOCKS_LIBRARY ${PROJECT_NAME}-building-blocks)
set(OBJECTS_LIBRARY ${PROJECT_NAME}-objects)

add_subdirectory(BuildingBlocks)
add_subdirectory(Objects)

set(WORLD_SOURCES
        InitalizationMapper.cpp
        WorldObject.cpp)

set(WORLD_INCLUDES
        "./")

add_library(${WORLD_LIBRARY} STATIC
        ${WORLD_SOURCES})
target_include_directories(${WORLD_LIBRARY} PUBLIC
        ${WORLD_INCLUDES}
        ${BUILDING_BLOCKS_LIBRARY}
        ${OBJECTS_LIBRARY})
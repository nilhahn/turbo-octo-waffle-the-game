set(BUILDING_BLOCKS_LIBRARY ${PROJECT_NAME}-building-blocks)
set(OBJECTS_LIBRARY ${PROJECT_NAME}-objects)

add_subdirectory(BuildingBlocks)
add_subdirectory(Objects)

message("BuildingBlocksLibrary " ${BUILDING_BLOCKS_LIBRARY})

set(WORLD_SOURCES
        InitalizationMapper.cpp
        WorldObject.cpp)

set(WORLD_INCLUDES
        "./"
        "../Resource"
        "../System"
        "../Window"
        "../System/Drawable"
        "../System/Entity"
        "../System/Entity/Property")

add_library(${WORLD_LIBRARY} STATIC
        ${WORLD_SOURCES})
target_include_directories(${WORLD_LIBRARY} PUBLIC
        ${WORLD_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${WORLD_LIBRARY} PUBLIC
        ${BUILDING_BLOCKS_LIBRARY}
        ${OBJECTS_LIBRARY})
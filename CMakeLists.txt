cmake_minimum_required(VERSION 3.10)
project(turbo-octo-waffle-the-game VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_executable(
        turbo-octo-waffle-the-game
        src/main.cpp
        src/Resource/Resource.cpp src/Resource/Resource.h
        src/System/Game.cpp src/System/Game.h
        src/Window/Window.cpp src/Window/Window.h
        src/Resource/TextureManager.cpp src/Resource/TextureManager.h
        src/System/Vector2D.cpp src/System/Vector2D.h src/Drawable/Drawable.cpp src/Drawable/Drawable.h src/World/WorldObject.cpp src/World/WorldObject.h src/World/InitalizationMapper.cpp src/World/InitalizationMapper.h src/World/Objects/Player.cpp src/World/Objects/Player.h src/World/Objects/Skeleton.cpp src/World/Objects/Skeleton.h src/World/Objects/BackgroundObject.cpp src/World/Objects/BackgroundObject.h src/Window/Camera.cpp src/Window/Camera.h src/System/Layer/BackgroundLayer.cpp src/System/Layer/BackgroundLayer.h src/System/Layer/Layer.h src/World/BuildingBlocks/Chunk.cpp src/World/BuildingBlocks/Chunk.h src/System/Square2D.cpp src/System/Square2D.h src/World/BuildingBlocks/Tile.cpp src/World/BuildingBlocks/Tile.h)

target_include_directories(turbo-octo-waffle-the-game PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/Resource"
        )

target_link_libraries(turbo-octo-waffle-the-game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

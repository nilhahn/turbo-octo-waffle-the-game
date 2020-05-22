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
        src/Entity/BaseEntity.cpp src/Entity/BaseEntity.h src/System/Game.cpp src/System/Game.h src/window/Window.cpp src/window/Window.h src/Resource/TextureManager.cpp src/Resource/TextureManager.h src/System/Vector2D.cpp src/System/Vector2D.h)

target_include_directories(turbo-octo-waffle-the-game PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/Resource"
        )

target_link_libraries(turbo-octo-waffle-the-game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

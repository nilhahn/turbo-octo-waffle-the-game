cmake_minimum_required(VERSION 3.24.2)
project(turbo-octo-waffle-the-game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(FetchContent)
FetchContent_Declare(
        SDL2
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
        GIT_TAG "release-2.32.0"
        EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SDL2)

FetchContent_Declare(
        SDL2_image
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL_image.git"
        GIT_TAG "release-2.8.5"
        EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SDL2_image)

set(EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})

set(RESOURCE_LIBRARY ${PROJECT_NAME}-resource)
set(WORLD_LIBRARY ${PROJECT_NAME}-world)
set(SYSTEM_LIBRARY ${PROJECT_NAME}-system)
set(WINDOW_LIBRARY ${PROJECT_NAME}-window)

add_subdirectory(src)
add_subdirectory(application)
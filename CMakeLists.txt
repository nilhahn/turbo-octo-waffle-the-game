cmake_minimum_required(VERSION 3.24.2)
project(turbo-octo-waffle-the-game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(FindSDL2)
include(FindSDL2_image)

set(EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})

set(RESOURCE_LIBRARY ${PROJECT_NAME}-resource)
set(WORLD_LIBRARY ${PROJECT_NAME}-world)
set(SYSTEM_LIBRARY ${PROJECT_NAME}-system)
set(WINDOW_LIBRARY ${PROJECT_NAME}-window)

message("SDL2_INCLUDE_DIR       " ${SDL2_INCLUDE_DIR})
message("SDL2_LIB               " ${SDL2_LIBRARY})
message("SDL2_IMAGE_INCLUDE_DIR " ${SDL2_IMAGE_INCLUDE_DIR})
message("SDL2_IMAGE_LIB         " ${SDL2_IMAGE_LIBRARY})

add_subdirectory(src)
add_subdirectory(application)
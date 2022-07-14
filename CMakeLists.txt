cmake_minimum_required(VERSION 3.10)
project(turbo-octo-waffle-the-game VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

set(game_source
        src/main.cpp
        src/Resource/Resource.cpp src/Resource/Resource.h
        src/System/Game.cpp src/System/Game.h
        src/Window/Window.cpp src/Window/Window.h
        src/Resource/TextureManager.cpp src/Resource/TextureManager.h
        src/System/Drawable/Drawable.cpp src/System/Drawable/Drawable.h
        src/World/WorldObject.cpp src/World/WorldObject.h
        src/World/InitalizationMapper.cpp src/World/InitalizationMapper.h
        src/World/Objects/Player.cpp src/World/Objects/Player.h
        src/World/Objects/Skeleton.cpp src/World/Objects/Skeleton.h
        src/World/Objects/BackgroundObject.cpp src/World/Objects/BackgroundObject.h
        src/Window/Camera.cpp src/Window/Camera.h
        src/System/Configuration/File/FileReader.cpp src/System/Configuration/File/FileReader.h
        src/System/Quadtree.h
        src/System/Layer/Background/BackgroundLayer.cpp src/System/Layer/Background/BackgroundLayer.h
        src/System/Layer/Layer.h
        src/World/BuildingBlocks/Chunk.cpp src/World/BuildingBlocks/Chunk.h
        src/System/Square2D.cpp src/System/Square2D.h
        src/World/Objects/Marker.cpp src/World/Objects/Marker.h
        src/System/Configuration/SystemConfiguration.cpp
        src/System/Configuration/SystemConfiguration.h
        src/System/Configuration/Configuration.cpp src/System/Configuration/Configuration.h src/System/Configuration/LevelConfiguration.cpp src/System/Configuration/LevelConfiguration.h src/System/Layer/Userinterface/UserInformationLayer.cpp src/System/Layer/Userinterface/UserInformationLayer.h src/System/Entity/Entity.cpp src/System/Entity/Entity.h src/System/Entity/Property.h src/System/Entity/BaseProperty.h src/System/Controller/Controller.h src/System/Controller/PlayerController.cpp src/System/Controller/PlayerController.h src/System/Controller/Controller.cpp src/System/Context.h src/System/Context.cpp src/System/Drawable/Canvas.cpp src/System/Drawable/Canvas.h src/System/Entity/Property/Position.h src/System/Entity/Property/StatefulDrawable.cpp src/System/Entity/Property/StatefulDrawable.h src/System/Vector2D.h src/System/Vector2D.cpp src/System/Entity/Property/Properties.h src/System/Entity/Property/EntityState.h src/System/Controller/Controllers.h src/System/Exception.h)

add_executable(
        turbo-octo-waffle-the-game ${game_source}
)

target_include_directories(turbo-octo-waffle-the-game PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/Resource"
        )

target_link_libraries(turbo-octo-waffle-the-game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

set(LAYER_SOURCES
        BackgroundLayer.cpp
        UserInformationLayer.cpp)

set(LAYER_INCLUDES
        "./"
        "../"
        "../Entity"
        "../Entity/Property"
        "../../Window"
        "../../Resource"
        "../../System/Drawable"
        "../../World/"
        "../../World/BuildingBlocks")

add_library(${LAYER_LIBRARY} STATIC
        ${LAYER_SOURCES})
target_include_directories(${LAYER_LIBRARY} PUBLIC
        ${LAYER_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})

target_link_libraries(${LAYER_LIBRARY} PUBLIC
        turbo-octo-waffle-the-game-building-blocks)
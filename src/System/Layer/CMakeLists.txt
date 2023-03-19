set(LAYER_SOURCES
        BackgroundLayer.cpp
        UserInformationLayer.cpp)

set(LAYER_INCLUDES
        "./")

add_library(${LAYER_LIBRARY} STATIC
        ${LAYER_SOURCES})
target_include_directories(${LAYER_LIBRARY} PUBLIC
        ${LAYER_INCLUDES})
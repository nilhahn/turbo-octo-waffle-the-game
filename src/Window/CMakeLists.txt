set(RESOURCES_SOURCES
        Camera.cpp
        Window.cpp)

set(RESOURCES_INCLUDES
        "./"
        "../System"
        "../Resource")

add_library(${WINDOW_LIBRARY} STATIC
        ${RESOURCES_SOURCES})
target_include_directories(${WINDOW_LIBRARY} PUBLIC
        ${RESOURCES_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
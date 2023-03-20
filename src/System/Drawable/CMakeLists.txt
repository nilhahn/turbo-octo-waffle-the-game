set(DRAWABLE_SOURCES
        Canvas.cpp
        Drawable.cpp)

set(DRAWABLE_INCLUDES
        "./"
        "../"
        "../Entity"
        "../Entity/Property"
        "../../Resource"
        "../../Window"
        "../../World")

add_library(${DRAWABLE_LIBRARY} STATIC
        ${DRAWABLE_SOURCES})
target_include_directories(${DRAWABLE_LIBRARY} PUBLIC
        ${DRAWABLE_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${DRAWABLE_LIBRARY} PUBLIC
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY})
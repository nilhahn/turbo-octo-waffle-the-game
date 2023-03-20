set(PROPERTY_SOURCES
        Equipment.cpp
        StatefulDrawable.cpp)

set(PROPERTY_INCLUDES
        "./"
        "../"
        "../../"
        "../../Drawable"
        "../../../Resource"
        "../../../World"
        "../../../Window"
        "../../../World/Objects")

add_library(${PROPERTY_LIBRARY} STATIC
        ${PROPERTY_SOURCES})
target_include_directories(${PROPERTY_LIBRARY} PUBLIC
        ${PROPERTY_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
set(PROPERTY_SOURCES
        Equipment.cpp
        StatefulDrawable.cpp)

set(PROPERTY_INCLUDES
        "./"
        "../../Drawable"
        "../../../World/Objects")

add_library(${PROPERTY_LIBRARY} STATIC
        ${PROPERTY_SOURCES})
target_include_directories(${PROPERTY_LIBRARY} PUBLIC
        ${PROPERTY_INCLUDES})
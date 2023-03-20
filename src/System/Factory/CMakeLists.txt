set(FACTORY_SOURCES
        BackgroundFactory.cpp
        ObjectFactory.cpp
        PlayerFactory.cpp
        SkeletonFactory.cpp)

set(FACTORY_INCLUDES
        "./"
        "../"
        "../Entity"
        "../Drawable"
        "../Entity/Property"
        "../../Window"
        "../../World"
        "../../Resource")

add_library(${FACTORY_LIBRARY} STATIC
        ${FACTORY_SOURCES})
target_include_directories(${FACTORY_LIBRARY} PUBLIC
        ${FACTORY_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
set(CONFIGURATION_LIBRARY ${PROJECT_NAME}-configuration)
set(DRAWABLE_LIBRARY ${PROJECT_NAME}-drawable)
set(ENTITY_LIBRARY ${PROJECT_NAME}-entity)
set(FACTORY_LIBRARY ${PROJECT_NAME}-factory)
set(LAYER_LIBRARY ${PROJECT_NAME}-layer)

add_subdirectory(Configuration)
add_subdirectory(Drawable)
add_subdirectory(Entity)
add_subdirectory(Factory)
add_subdirectory(Layer)

set(SYSTEM_SOURCES
        Context.cpp
        Game.cpp
        Square2D.cpp
        Vector2D.cpp)

set(SYSTEM_INCLUDES
        "./"
        "../Resource/"
        "../World/"
        "../Window/"
        "./Layer/")

add_library(${SYSTEM_LIBRARY} STATIC
        ${SYSTEM_SOURCES})
target_include_directories(${SYSTEM_LIBRARY} PUBLIC
        ${SYSTEM_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${SYSTEM_LIBRARY} PUBLIC
        ${CONFIGURATION_LIBRARY}
        ${DRAWABLE_LIBRARY}
        ${ENTITY_LIBRARY}
        ${FACTORY_LIBRARY}
        ${LAYER_LIBRARY})
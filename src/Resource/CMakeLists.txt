set(RESOURCES_SOURCES
        Resource.cpp
        TextureManager.cpp)

set(RESOURCES_INCLUDES
        "./")

add_library(${RESOURCE_LIBRARY} STATIC
        ${RESOURCES_SOURCES})
target_include_directories(${RESOURCE_LIBRARY} PUBLIC
        ${RESOURCES_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${RESOURCE_LIBRARY} PUBLIC
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY})
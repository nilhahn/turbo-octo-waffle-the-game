set(PROPERTY_LIBRARY ${PROJECT_NAME}-property)

add_subdirectory(Property)

set(ENTITY_SOURCES
        Entity.cpp)

set(ENTITY_INCLUDES
        "./"
        "../"
        "../../Resource")

add_library(${ENTITY_LIBRARY} STATIC
        ${ENTITY_SOURCES})
target_include_directories(${ENTITY_LIBRARY} PUBLIC
        ${ENTITY_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${ENTITY_LIBRARY} PUBLIC
        ${PROPERTY_LIBRARY})
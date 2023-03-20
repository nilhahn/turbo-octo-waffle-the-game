set(ITEM_LIBRARY ${PROJECT_NAME}-item)

add_subdirectory(Item)

set(OBJECTS_SOURCES
        Item.cpp
        Marker.cpp)

set(OBJECTS_INCLUDES
        "./"
        "../"
        "../../System"
        "../../Resource"
        "../../Window"
        "../../System/Entity"
        "../../System/Entity/Property"
        "../../System/Drawable")

add_library(${OBJECTS_LIBRARY} STATIC
        ${OBJECTS_SOURCES})
target_include_directories(${OBJECTS_LIBRARY} PUBLIC
        ${OBJECTS_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${OBJECTS_LIBRARY} PUBLIC
        ${ITEM_LIBRARY})
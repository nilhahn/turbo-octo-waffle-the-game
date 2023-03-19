set(ITEM_LIBRARY ${PROJECT_NAME}-item)

add_subdirectory(Item)

set(OBJECTS_SOURCES
        Item.cpp
        Marker.cpp)

set(OBJECTS_INCLUDES
        "./")

add_library(${OBJECTS_LIBRARY} STATIC
        ${OBJECTS_SOURCES})
target_include_directories(${OBJECTS_LIBRARY} PUBLIC
        ${OBJECTS_INCLUDES}
        ${ITEM_LIBRARY})
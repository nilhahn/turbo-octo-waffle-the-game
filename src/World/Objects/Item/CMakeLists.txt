set(ITEM_SOURCES
        WeaponItem.cpp)

set(ITEM_INCLUDES
        "./")

add_library(${ITEM_LIBRARY} STATIC
        ${ITEM_SOURCES})
target_include_directories(${ITEM_LIBRARY} PUBLIC
        ${ITEM_INCLUDES})
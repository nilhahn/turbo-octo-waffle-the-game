set(BUILDING_BLOCK_SOURCES
        Chunk.cpp)

set(BUILDING_BLOCK_INCLUDES
        "./"
        "../../System")

add_library(${BUILDING_BLOCKS_LIBRARY} STATIC
        ${BUILDING_BLOCK_SOURCES})
target_include_directories(${BUILDING_BLOCKS_LIBRARY} PUBLIC
        ${BUILDING_BLOCK_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
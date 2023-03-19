set(FILE_SOURCES
        FileReader.cpp)

set(FILE_INCLUDES
        "./")

add_library(${FILE_LIBRARY} STATIC
        ${FILE_SOURCES})
target_include_directories(${FILE_LIBRARY} PUBLIC
        ${FILE_INCLUDES})
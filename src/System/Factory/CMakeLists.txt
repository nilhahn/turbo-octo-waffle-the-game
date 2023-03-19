set(FACTORY_SOURCES
        BackgroundFactory.cpp
        ObjectFactory.cpp
        PlayerFactory.cpp
        SkeletonFactory.cpp)

set(FACTORY_INCLUDES
        "./")

add_library(${FACTORY_LIBRARY} STATIC
        ${FACTORY_SOURCES})
target_include_directories(${FACTORY_LIBRARY} PUBLIC
        ${FACTORY_INCLUDES})
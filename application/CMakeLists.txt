set(APPLICATION_SOURCES
        main.cpp)
set(APPLICATION_INCLUDES
        "./")

message("Executable name    " ${EXECUTABLE_NAME})
message("Resource library   " ${RESOURCE_LIBRARY})
message("System library     " ${SYSTEM_LIBRARY})
message("Window library     " ${WINDOW_LIBRARY})
message("World library      " ${WORLD_LIBRARY})


add_executable(${EXECUTABLE_NAME}
        ${APPLICATION_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC
        ${APPLICATION_INCLUDES}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${RESOURCE_LIBRARY}
        ${WORLD_LIBRARY}
        ${SYSTEM_LIBRARY}
        ${WINDOW_LIBRARY})
cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME Animation)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp Game.cpp Game.h Log.h Line.h)

#include_directories (/usr/include/freetype2)
add_subdirectory(external/SFML)
target_link_libraries(${PROJECT_NAME} sfml-audio)
target_link_libraries(${PROJECT_NAME} sfml-graphics)

include_directories(${PROJECT_NAME} external/SFML/include)

#add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)
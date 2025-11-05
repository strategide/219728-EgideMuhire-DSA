cmake_minimum_required(VERSION 4.0.0)

set(TARGET dsa)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

project(
    ${TARGET} 
    VERSION 0.0.1 
    LANGUAGES CXX
)

set(
    SOURCES
    src/assignment2.cpp
)

add_executable(${TARGET} ${SOURCES})

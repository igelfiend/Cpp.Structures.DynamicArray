cmake_minimum_required(VERSION 2.8)

include_directories(include)

set (CMAKE_CXX_STANDARD 11)

set(SOURCES
    "src/main.cpp"
    "src/dynarraytest.cpp"
)

set(HEADERS
    "include/dynarray.h"
    "include/dynarraytest.h"
)

project(DynamicArray)
add_executable(
    ${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
)


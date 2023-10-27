cmake_minimum_required(VERSION 3.10)
project(demo)

set(LIBRARY_OUTPUT_PATH ${LIBPATH})

include_directories(${HEADPATH})

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/.. *.cpp)
add_library(${PROJECT_NAME} SHARED ${SRC})

# set(CMAKE_BUILD_TYPE "Debug")
cmake_minimum_required(VERSION 3.10)
project(CPPDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DDEBUG)

set(HEADPATH ${PROJECT_SOURCE_DIR}/include)
set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)
set(SRCPATH ${PROJECT_SOURCE_DIR}/src)
set(EXEPATH ${PROJECT_SOURCE_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${EXEPATH})

add_subdirectory(${PROJECT_SOURCE_DIR}/Demo)

include_directories(${HEADPATH})

link_directories(${LIBPATH})
# link_libraries(q)

aux_source_directory(${PROJECT_SOURCE_DIR} SRC)
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
    PUBLIC demo)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS -g}")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

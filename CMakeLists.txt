cmake_minimum_required(VERSION 3.17)
project(pbl)

add_definitions(-fprofile-arcs -ftest-coverage)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")

include_directories(include)
include_directories(tests)

add_subdirectory(include)
add_subdirectory(tests)

target_link_libraries(pbl)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif()
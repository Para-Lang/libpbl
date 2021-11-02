project(pbl)

include(FetchContent)
FetchContent_Declare(
        gc-8.0.6
        URL https://github.com/ivmai/bdwgc/releases/download/v8.0.6/gc-8.0.6.tar.gz
)

FetchContent_Populate(
        gc-8.0.6
)
add_subdirectory(${gc-8.0.6_SOURCE_DIR} ${gc-8.0.6_BINARY_DIR})
target_include_directories(pbl PUBLIC "${gc-8.0.6_SOURCE_DIR}")
target_include_directories(pbl PUBLIC "${gc-8.0.6_SOURCE_DIR}/include")

target_link_libraries(pbl PUBLIC gc-lib)

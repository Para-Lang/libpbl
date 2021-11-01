project(pbl)

include(FetchContent)
FetchContent_Declare(
        gc-8.0.6
        URL https://github.com/ivmai/bdwgc/releases/download/v8.0.6/gc-8.0.6.tar.gz
)
FetchContent_MakeAvailable(
        gc-8.0.6
)
if(NOT gc-8.0.6_POPULATED)
    FetchContent_Populate(gc-8.0.6)
endif()

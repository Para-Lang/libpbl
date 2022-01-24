# Including GTest
FetchContent_Declare(
    gtest-1.11.0
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest-1.11.0)

# Including the gtest headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Defining the directories for source and header files
set(TEST_SOURCE_INCLUDE_DIRECTORY "${libpbl_SOURCE_DIR}/tests")

# Using glob to get all files that should be included
file(GLOB TEST_SOURCE_FILES CONFIGURE_DEPENDS "${TEST_SOURCE_INCLUDE_DIRECTORY}/**/*.cpp")

# Adding the test executable
add_executable(runPblTests ${TEST_SOURCE_FILES})

# Linking the required GTest library
target_link_libraries(runPblTests gtest gtest_main)

# Linking the PBl itself
target_link_libraries(runPblTests pbl)

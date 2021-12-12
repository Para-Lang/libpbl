# Only tested with 3.17
cmake_minimum_required(VERSION 3.17)

# General Project Setup
project(
    libpbl
    VERSION 0.1
    DESCRIPTION "The Para-C Base Library implementing macros, functions and types for the Para-C programming language"
    LANGUAGES C CXX
)

# Adding FetchContent for simplified content installation
include(FetchContent)

# If this is the main project, define additional terms required for testing and such
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # PBL only supports C11 and upwards
  set(CMAKE_C_STANDARD 11)

  # set test flags
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")

  # adding coverage definitions
  add_definitions(-fprofile-arcs -ftest-coverage)

  # Hinting the usage of built-in atomic types (since we use C11 as an enforced base standard)
  add_compile_definitions(GC_BUILTIN_ATOMIC)
endif()

# Enabling windows threads if on windows
if (WIN32)
  option(CMAKE_USE_WIN32_THREADS_INIT "Using WIN32 threads" ON)
  option(gtest_disable_pthreads "Disable uses of pthreads in gtest" ON)
endif (WIN32)

# Hinting the usage of built-in atomic types (since we use C11 as an enforced base standard)
add_compile_definitions(GC_BUILTIN_ATOMIC)

# Adding the src and linking the library
add_subdirectory(src)

# If this is the main project, enable testing
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Including the tests and the testing target
  add_subdirectory(tests)
endif()

# If Debug-Mode is enabled add debug definitions
if (CMAKE_BUILD_TYPE MATCHES Debug)
  add_definitions(-DDEBUG)
endif()
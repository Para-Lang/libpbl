# Only tested with 3.17
cmake_minimum_required(VERSION 3.17)

# General Project Setup
project(
    libpbl
    VERSION 0.1
    DESCRIPTION "The Para Base Library implementing macros, functions and types for the Para programming language"
    LANGUAGES C CXX
)

# Adding FetchContent for simplified content installation
include(FetchContent)

# Enabling the usage of folders and make predefined projects go into their own solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# If this is the main project, define additional terms required for testing and such
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # PBL only supports C11 and upwards
  set(CMAKE_C_STANDARD 11)

  # Setting test flags
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")

  # Adding the examples runtime
  add_subdirectory(examples)
endif()

# Adding the src and linking the library
add_subdirectory(src)

# If this is the main project, enable testing
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Including the tests and the testing target
  add_subdirectory(tests)
endif()

if (DEFINED PBL_DEBUG_VERBOSE)
  add_compile_definitions(PBL_DEBUG)
  add_compile_definitions(PBL_DEBUG_VERBOSE)
endif()

if (DEFINED PBL_COVERAGE)
  # Adding coverage definitions
  add_definitions(-fprofile-arcs -ftest-coverage)
endif()

# If Debug-Mode is enabled add debug definitions
if (CMAKE_BUILD_TYPE MATCHES Debug OR DEFINED PBL_DEBUG)
  # Add default definition for debugging
  add_definitions(-DDEBUG)

  # Sets the PBL_DEBUG to true per default
  set(PBL_DEBUG true)
  add_compile_definitions(PBL_DEBUG)

  # Add macro for the Garbage Collector to allow debugging
  add_compile_definitions(GC_DEBUG)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

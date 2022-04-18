# Only tested with 3.17
cmake_minimum_required(VERSION 3.17)

# General Project Setup
project(
    libpbl
    VERSION 0.1
    DESCRIPTION "The Para Base Library implementing the functionality for the Para programming language"
    LANGUAGES C CXX
)

# Adding FetchContent for simplified content installation
include(FetchContent)

# Enabling the usage of folders and make predefined projects go into their own solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# If this is the main project, define additional terms required for testing and such
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # PBL only supports C11 and upwards
  set(CMAKE_C_STANDARD 11)

  # Adding the examples runtime
  add_subdirectory(examples)

  # Including the tests and the testing target
  add_subdirectory(tests)

  # Verbose cmd option
  option(PBL_DEBUG_VERBOSE "Enable verbose debugging" OFF)
  if (PBL_DEBUG_VERBOSE)
    message("Enabled PBL_DEBUG_VERBOSE successfully.")
    add_compile_definitions(PBL_DEBUG)
    add_compile_definitions(PBL_DEBUG_VERBOSE)
  endif ()

  # Coverage cmd option
  option(PBL_COVERAGE "Enable default coverage reporting" OFF)
  set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
  if (PBL_COVERAGE)
    if (CMAKE_COMPILER_IS_GNUCXX)
      add_definitions(-fprofile-arcs -ftest-coverage)

      # We need to turn off optimization for non-skewed coverage reports
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

      message("Enabled PBL_COVERAGE successfully.")
    else ()
      message("Failed to enable PBL_COVERAGE. Only supported for the GNU Compiler Collection and MingW.")
    endif ()
  endif ()
endif ()

# Adding the external libraries
add_subdirectory(lib)

# Adding the src and linking the library
add_subdirectory(src)

# If Debug-Mode is enabled add debug definitions
if (CMAKE_BUILD_TYPE MATCHES Debug OR DEFINED PBL_DEBUG)
  # Add default definition for debugging
  add_definitions(-DDEBUG)

  # Sets the PBL_DEBUG to true per default
  set(PBL_DEBUG true)
  add_compile_definitions(PBL_DEBUG)

  # Add macro for the Garbage Collector to allow debugging
  add_compile_definitions(GC_DEBUG)
endif ()

# Add libgcc and libstdc++
add_definitions(-static-libgcc -static-libstdc++)

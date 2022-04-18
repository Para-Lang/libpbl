# Defining the directories for source and header files
set(HEADER_INCLUDE_DIRECTORY "${libpbl_SOURCE_DIR}/include")
set(SOURCE_INCLUDE_DIRECTORY "${libpbl_SOURCE_DIR}/src")

# Defining the directories for library source and header files
set(HEADER_EXT_LIB_DIRECTORY "${libpbl_SOURCE_DIR}/lib")
set(SOURCE_EXT_LIB_DIRECTORY "${libpbl_SOURCE_DIR}/lib")

# Logging for debugging purposes the source and header directories
message("SOURCE_INCLUDE_DIRECTORY = ${SOURCE_INCLUDE_DIRECTORY}")
message("HEADER_INCLUDE_DIRECTORY = ${HEADER_INCLUDE_DIRECTORY}")

# Using glob to get all files that should be included
set(SOURCE_FILES
    "${SOURCE_INCLUDE_DIRECTORY}/pbl.c"
    "${SOURCE_INCLUDE_DIRECTORY}/pbl-main.c"
    "${SOURCE_INCLUDE_DIRECTORY}/types/pbl-any.c"
    "${SOURCE_INCLUDE_DIRECTORY}/types/pbl-int.c"
    "${SOURCE_INCLUDE_DIRECTORY}/types/pbl-string.c"
    "${SOURCE_INCLUDE_DIRECTORY}/types/pbl-types.c"
    "${SOURCE_INCLUDE_DIRECTORY}/mem/pbl-mem.c"
    "${SOURCE_INCLUDE_DIRECTORY}/mem/pbl-mem-tools.c"
    "${SOURCE_INCLUDE_DIRECTORY}/pbl-io.c"
    "${SOURCE_INCLUDE_DIRECTORY}/pbl-function.c"
    types/pbl-type-list.c)

set(HEADER_FILES
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/pbl.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/pbl-main.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/types/pbl-any.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/types/pbl-int.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/types/pbl-string.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/types/pbl-types.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/types/pbl-meta-types.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/types/pbl-type-list.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/mem/pbl-mem.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/mem/pbl-mem-tools.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/pbl-io.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/pbl-function.h"
    "${HEADER_INCLUDE_DIRECTORY}/libpbl/pbl-apply-macro.h")

# Adding the static Library
add_library(pbl STATIC ${SOURCE_FILES} ${HEADER_FILES})

# Making the /include/libpbl headers available
include_directories(${HEADER_INCLUDE_DIRECTORY} ${SOURCE_INCLUDE_DIRECTORY})
target_include_directories(pbl PUBLIC ${HEADER_INCLUDE_DIRECTORY} ${SOURCE_INCLUDE_DIRECTORY})

# Linking the garbage collector
target_link_libraries(pbl PUBLIC gc-lib)

# -- Linking external libraries --

# Adding the headers from the '/lib/' folder
target_include_directories(pbl PUBLIC ${HEADER_EXT_LIB_DIRECTORY})

# Linking the va-opt library
target_link_libraries(pbl PUBLIC va-opt)

# Including the Hans Boehm garbage collector
FetchContent_Declare(
    gc-8.0.6
    URL https://github.com/ivmai/bdwgc/releases/download/v8.0.6/gc-8.0.6.tar.gz
)

# Populating the Library
FetchContent_Populate(
    gc-8.0.6
)

# Adding the directories into the local references
add_subdirectory(${gc-8.0.6_SOURCE_DIR} ${gc-8.0.6_BINARY_DIR})
target_include_directories(pbl PUBLIC "${gc-8.0.6_SOURCE_DIR}")
target_include_directories(pbl PUBLIC "${gc-8.0.6_SOURCE_DIR}/include")

# Hinting the usage of built-in atomic types (since we use C11 as an enforced base standard)
add_compile_definitions(GC_BUILTIN_ATOMIC)

# IDEs should put the headers in a nice place
source_group(
    TREE ${HEADER_INCLUDE_DIRECTORY}
    PREFIX "Header Files"
    FILES ${HEADER_FILES}
)

# Defining the directories for source and header files
set(HEADER_EXT_LIB_DIRECTORY "${libpbl_SOURCE_DIR}/lib")
set(SOURCE_EXT_LIB_DIRECTORY "${libpbl_SOURCE_DIR}/lib")

# Logging for debugging purposes the source and header directories
message("HEADER_EXT_LIB_DIRECTORY = ${HEADER_EXT_LIB_DIRECTORY}")
message("SOURCE_EXT_LIB_DIRECTORY = ${SOURCE_EXT_LIB_DIRECTORY}")

# Setting the src files for va-opt
set(
  VA_OPT_HEADER_FILES
    "${HEADER_EXT_LIB_DIRECTORY}/va-opt/va-opt.h"
)

# Adding the va-opt library
add_library(
    va-opt STATIC ${VA_OPT_HEADER_FILES}
)

# Set the linking language, as va-opt only contains headers and is therefore not specifically C or C++
set_target_properties(va-opt PROPERTIES LINKER_LANGUAGE C)
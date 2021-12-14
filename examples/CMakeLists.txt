# Setting all files to compile
set(SOURCE_FILES ./simple-io.c)

# Adding the executable example
add_executable(pbl-examples ${SOURCE_FILES})

# Linking the library into the example
target_link_libraries(pbl-examples PUBLIC pbl)

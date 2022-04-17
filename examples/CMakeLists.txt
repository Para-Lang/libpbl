# Adding the executables for the examples
add_executable(pbl-example-simple-io ./simple-io.c)
add_executable(pbl-example-simple-string ./simple-string.c)

# Linking the library into the example
target_link_libraries(pbl-example-simple-io PUBLIC pbl)
target_link_libraries(pbl-example-simple-string PUBLIC pbl)

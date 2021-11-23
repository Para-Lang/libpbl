project(pbl)

set(HEADER_FILES
        pbl/pbl-io.h
        pbl/pbl.h
        pbl/pbl-types.h
        pbl/pbl-string.h
        pbl/pbl-int.h
        pbl/pbl-function.h
        pbl/pbl-main.h
        pbl/pbl-mem.h
        pbl/pbl-any.h
        pbl/pbl-apply-macro.h)

set(SOURCE_FILES
        pbl/pbl-io.c
        pbl/pbl-types.c
        pbl/pbl-string.c
        pbl/pbl-int.c
        pbl/pbl.c
        pbl/pbl-function.c
        pbl/pbl-main.c
        pbl/pbl-mem.c
        pbl/pbl-any.c)

set(INCLUDED_EXTENSIONS
        pbl/additional/va-opt.h)

add_library(pbl STATIC ${SOURCE_FILES} ${HEADER_FILES} ${INCLUDED_EXTENSIONS})

include_directories(pbl)
include_directories(pbl/additional)

add_subdirectory(pbl)
add_subdirectory(pbl/additional)

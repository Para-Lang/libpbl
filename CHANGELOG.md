# Changelog

All notable changes to the Compiler will be documented in this file. Note that these changes in this file are
specifically for the Compiler. The full summary will be in the CHANGELOG.md file the main folder

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres
to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

*Note that Documentation changes should not appear here!*

## [Unreleased]

### Added

### Changed

### Removed

## [v0.1.dev7] - 2022-01-24

### Added

- `pbl-apply-macro.h` for defining a macro function, which allows for iterating through macro args and apply another
  macro to them.
- Macros `PBL_GET_FUNC_ARGS_IDENTIFIER`, `PBL_GET_FUNC_BASE_IDENTIFIER` and `PBL_GET_FUNC_OVERHEAD_IDENTIFIER` for
  getting standardised macros.
- `PBL_COUNT_VA_ARGS` for counting the amount of arguments passed to this specific macro.
- `PBL_FUNC_ARG` for creating the effect of arguments being `NULL` per default.
- `PBL_CREATE_FUNC_OVERHEAD` for creating overhead of a Para function, which can support default arguments and
  struct-like initialisation.
- `PBL_CALL_FUNC` for calling a Para function and properly handling it.
- Header `pbl-advanced-mem.h` for exception-supported and advanced memory handling with Para types.
- Function `PblMallocUncollectable()` in `pbl-mem.h` for allocating a variable that will not be automatically collected
  aka. will exist until the user deallocates it or the program ends. This will be used for global variables that are
  used throughout the entire program, and are essential to running properly, which means they should not be checked for
  Garbage Collection.
- New Macro for simplified cleanup attribute assignment: `PBL_CLEANUP(func)`.
- New macro `PBL_SIZEOF_ON_RUNTIME(var)` for dynamically fetching the size using `PblType_T.size`.
- New macro `PBL_VAL_REQ_ARG` for validating a required argument aka. it may not be null. This is to make the code more
  verbose when handling Para functions.
- New IO functions `PblInput()`and `PblInputChar()`.
- New type `PblPointer_T` with conversion function `PblGetPointerT(void* val, PblType_T* type)`.
- Inclusion check for C++ to use the `c` prefix in inclusion for C++ to avoid warnings (e.g `#include <cstring>`
  in C++ and `#include <string.h>` in C).
- New type `PblTypeList_T` for local file type and meta-data tracking, with the additional handling functions and
  macros:
  - `PblAddTypeToTypeList()` - Adds a new type to the local type list.
  - `PblCreateNewType()` - Allocates a new type in memory that may be used for type lists.
  - `PblInitTypeList()` - Initialises a local type list and creates the on-runtime constructor for allocating its
    content.
  - `LOCAL_TYPE_LIST_CONSTRUCTOR` - Is replaced with a default constructor function signature for registering new types
    at runtime.
  - `PBL_REGISTER_LOCAL_TYPE` - Registers a local type and adds it to the local type lis.t. Has to be used inside of
    `LOCAL_TYPE_LIST_CONSTRUCTOR` constructor function definitions
  - `PBL_INIT_LOCAL_TYPE_LIST` - Creates and initialises the variables `LOCAL_TYPE_LIST` and 
    `LOCAL_TYPE_TRACKING_INITIALISED`, which are required for utilising type tracking inside a file.
- New Debug Macros: 
  - `PBL_DEBUG_VERBOSE` - Enables Verbose debugging for the library.
  - `PBL_DEBUG` - Enables default debugging for the library.
- New Overwrite Macro `PBL_OVERWRITE_DEFAULT_ALLOC_FUNCTIONS`, which will if set redefine `malloc()`, `realloc()` and
  `free()` to use the PBL-variants using the garbage collector.

### Changed

- Entirely restructured the buildup, and now created separate folders for headers (`include`) and
  source code (`src`), where also CMake has been restructured and simplified.
- Updated macro `PBL_CALL_FUNC`, which handles now also the amount of args properly.
- Renamed the following types:
    - `PblTypeMeta_T` to `PblType_T`
    - `PblMetaVarCtx_T` to `PblVarMetaData_T`
- Renamed the following macros:
    - `PBL_GET_ACTUAL_TYPE_INSTANCE` to `PBL_ASSIGN_TO_VAR`
    - `PBL_ALLOC_DECLARATION` to `PBL_DECLARE_VAR`
    - `PBL_DEFINE_VAR` to `PBL_DEFINE_VAR`
    - `PBL_ALLOC_ARRAY_DEFINITION` to `PBL_CREATE_NEW_ARRAY`
    - `PBL_DECLARATION_CONSTRUCTOR` to `PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR`
    - `PBL_DEFINITION_STRUCT_CONSTRUCTOR` to `PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR`
    - `PBL_DEFINITION_SINGLE_CONSTRUCTOR` to `PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR`
    - `PBL_PASTE_ADDRESS_COPY` to `PBL_WRITE_BACK_ADDRESS_COPY`
- Replaced `size_t *size` property in `PblVarMetaData_T` and replaced it with `PblType_T *type`.
- Renamed `PBL_SIZEOF` to `PBL_SIZEOF_USABLE`.
- Renamed `PBL_C_BASE_EXCEPTION_CATCH_CONSTRUCTOR` to `PBL_BASE_CALL_AND_CATCH_EXCEPTION` (for native C functions) and
  avoided code repetition by utilising the function in `PBL_CALL_FUNC_AND_CATCH` (for Para functions) as well.
- Changed handling of `PBL_SIZEOF_ON_RUNTIME` to return usable memory of a type and renamed the macro to
  `PBL_SIZEOF_USABLE_ON_RUNTIME`.

### Removed

- Outdated macro `PBL_CALL_FUNC_WITH_META_CTX`, which is now replaced by `PBL_CALL_FUNC` as the general method to call
  Para functions.
- Unneeded `PBL_DEFINITION_IF_VA_ARGS_CONSTRUCTOR` macro.
- Parameter `type` in `PBL_WRITE_BACK_ADDRESS_COPY`, which was unnecessary, due to both variables already having been
  defined.
- Unneeded `PblCleanupLocal()`, which was briefly defined in `pbl-mem.c`.
- Unneeded default cleanups, which were replaced by optional opt-in cleanups on declaration / definition.

## [v0.1.dev6] - 2021-11-10

### Changed

- Made the PBL properly fetch-able for the build script `build.py` in [Para](https://github.com/Para-Lang/Para)

## [v0.1.dev5] - 2021-11-09

### Added

- Base types in `pbl-types.h` that wrap the low-level C types, including conversion functions which allow simply
  one-line conversion
- Proper meta-tracking for all Para types using `PblVarMeta_T`
- Default declaration and definition macros for all types in `libpbl`. These are defined using `_DeclDefault` and
  `_DefDefault` for all types
- `PblIOStream_T` and `PblIOFile_T` implementation for stream handling
- Specified Int Types in `pbl-int.h` that wrap the int types in `stdint.h`
- Meta handling for managing a function call context and Exception handling in `pbl-function.h`
- Fallback implementation for `__VA_EXT__`, which has been implemented since C++20 or C23,
  using `./modules/parac-modules/included/va-opt.h`
- Added `pbl-mem.h` for independent memory management and Garbage Collector implementation
  using [Boehm-Demers-Weiser Garbage Collector](https://github.com/ivmai/bdwgc)
- Handler macros `PBL_GET_ACTUAL_TYPE_INSTANCE` (getting type instance), `PBL_ALLOC_DECLARATION` (Para Declarations)
  and `PBL_DEFINE_VAR` (Para Definitions) which standardise the initialisation of Para values

[unreleased]: https://github.com/Para-Lang/Para-Base-Library/tree/dev
[v0.1.dev7]: https://github.com/Para-Lang/Para-Base-Library/compare/v0.1.dev6...v0.1.dev7
[v0.1.dev6]: https://github.com/Para-Lang/Para-Base-Library/compare/v0.1.dev5...v0.1.dev6
[v0.1.dev5]: https://github.com/Para-Lang/Para-Base-Library/tag/v0.1.dev5
# Changelog

All notable changes to the Compiler will be documented in this file.
Note that these changes in this file are specifically for the Compiler.
The full summary will be in the CHANGELOG.md file the main folder

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

*Note that Documentation changes should not appear here!*

## [Unreleased]

### Added

### Changed

### Removed

## [v0.1.dev5] - 2021-11-09

### Added
- Base types in `pbl-types.h` that wrap the low-level C types, including conversion functions which allow simply one-line
  conversion
- Proper meta-tracking for all Para-C types using `PblVarMeta_T`
- Default declaration and definition macros for all types in `libpbl`. These are defined using `_DeclDefault` and
  `_DefDefault` for all types
- `PblStream_T` and `PblFile_T` implementation for stream handling
- Specified Int Types in `pbl-int.h` that wrap the int types in `stdint.h`
- Meta handling for managing a function call context and Exception handling in `pbl-function.h` 
- Fallback implementation for `__VA_EXT__`, which has been implemented since C++20 or C23, using `./modules/parac-modules/included/va-opt.h`
- Added `pbl-mem.h` for independent memory management and Garbage Collector implementation using [Boehm-Demers-Weiser Garbage Collector](https://github.com/ivmai/bdwgc)
- Handler macros `PBL_GET_ACTUAL_TYPE_INSTANCE` (getting type instance), `PBL_ALLOC_DECLARATION` (Para-C Declarations)
  and `PBL_ALLOC_DEFINITION` (Para-C Definitions) which standardise the initialisation of Para-C values

[unreleased]: https://github.com/Para-C/Para-C-Base-Library/tree/dev
[v0.1.dev5]: https://github.com/Para-C/Para-C-Base-Library/tag/v0.1.dev5
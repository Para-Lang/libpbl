![](https://raw.githubusercontent.com/Para-Lang/Para/v0.1.dev7/img/para-language.png)

# `libpbl` - Para Base Library

[![Latest Release](https://img.shields.io/github/v/release/Para-Lang/Para-Base-Library?include_prereleases)](https://github.com/Para-Lang/Para-Base-Library/releases)
[![codecov](https://codecov.io/gh/Para-Lang/libpbl/branch/main/graph/badge.svg?token=DaivYBG7vW)](https://codecov.io/gh/Para-Lang/libpbl)
[![Dr.Memory and GTest](https://github.com/Para-Lang/Para-Base-Library/actions/workflows/drmemory.yml/badge.svg)](https://github.com/Para-Lang/Para-Base-Library/actions/workflows/drmemory.yml)
[![Open Para issues](https://img.shields.io/github/issues/Para-Lang/Para)](https://github.com/Para-Lang/Para/issues)
[![Required GCC version](https://img.shields.io/badge/GCC-%3E%3D8.0-blue)](https://github.com/Para-Lang/Para/discussions/76)
![Required CMake version](https://img.shields.io/badge/CMake-%3E%3D3.17-blue)

This is the repository containing the c-implementation library (Para Core Library, and partly Para Built-In Library)
, which is used for the built-in functions, keywords and items, which are required for the base language.

*For proper documentation and info on Para visit the main repo [here](https://github.com/Para-Lang/Para). This also
includes issues or requesting changes. These should be done on the main branch, while the issues here will be
maintainers-only*

# Testing the library

For testing purposes, [GTest (Google Test)](https://github.com/google/googletest/releases/tag/release-1.11.0)
is used in an C++ environment, which will simply include the C-headers and Object-files.

## Running the default tests using CMake

To build the tests on your system, you will have to use CMake to set up the project and its dependencies:

```bash
cmake -S . -B ./cmake-build-debug
cmake --build ./cmake-build-debug --target pbl-tests
```

This will set up the cmake environment and build the test-executable. 

The executable should be located here (With `.exe` extension on Windows): 

```bash
./cmake-build-debug/tests/pbl-tests
```
 
## Additional optional flags

To pass a flag add it to the project setup command, like this:

```bash
cmake -{FLAG}={VALUE} -S . -B ./cmake-build-debug
```

Example using the verbose, coverage and debug flag:

```bash
cmake -DCMAKE_BUILD_TYPE=Debug -DPBL_COVERAGE=ON -DPBL_DEBUG_VERBOSE=ON -S . -B ./cmake-build-debug
```

### `DCMAKE_BUILD_TYPE=Debug`

Enables debugging features for the test executable. This must be used when
debugging using a graphical IDE, like CLion, Visual Studio Code or Atom. 

### `DPBL_COVERAGE=ON`

Enables gcov coverage reporting. This will automatically generate `.gcda` and `.gcno`
cov-report files for each compiled source file.

These can be converted into proper `.gcov` files using the following command:

```bash
gcov -abcfum PATH_TO_FILE
```

### `DPBL_DEBUG_VERBOSE=ON`

Enables verbose runtime messages.

This will also define the macro `GC_PRINT_VERBOSE_STATS`, allowing for additional GC info.

# Implementation Overview

This section is a work-in-progress and serves as a reference, while the library is being
developed. Don't take functionality listed here as granted, as almost everything will be
likely changed at some point!

## Styling and Formatting

The styling guide for the PBL is as following:

- Structs/Enums: PascalCase with leading `Pbl`
- Struct Properties: snake_case
- Constants and Enum Properties: SCREAMING_SNAKE_CASE
- Typedef: PascalCase with leading `Pbl` and trailing `_T`
- Local Variables: snake_case
- Parameters: snake_case
- Macros: SCREAMING_SNAKE_CASE (exceptions are function definition macros, where PascalCase is applied)
- Functions: PascalCase with leading `Pbl`
- Indention: 2 spaces
- 
## Meta-Data Tracking - `pbl-types.h`

Para implements meta-data tracking using `PblVarMetaData_T` and pre-defined macros, tracking things like:

- If the variable has been defined yet
- Effective space the user has to utilise. Note that effective space does not include actual space that is allocated!
  This is due to meta-data also taking up a bit of memory space.

### `_DefDefault` and `_DeclDefault` for PBL-Types

When declaring a built-in type that should be used inside Para, the style of the general types should be replicated,
to allow for the proper usage of defaults aka. `_DefDefault` and `_DeclDefault`

## Variables - `pbl-types.h`

Variables in Para are specifically handled using a garbage collector, meaning that initialised variables are
going to be represented and accessed using pointers. 

States of a Variable: 
- Only Declared (True C Declaration)
- Technically "Declared" (Technically defined in C, but handled as declared in Para). Two possible 
  scenarios:
  - Allocated, but the meta-Property `.meta.defined` is set to false, since no value was assigned yet
  - The value is NULL, as it's a pointer and there has not been any clear definition.
- Defined Variable that has been written to
- Freed Variable by the Garbage Collector

### Type List

Para keeps a type list of all registered types that were created or imported inside a source file. This list is 
created at startup of the program, meaning all types may be dynamically accessed and used to create new types. 

This means that each file has its own scope with meta-data tracking, which can be also imported into other files. 

Constructor Priority:
- `PBL_CONSTRUCTOR_TYPES_LIST_INIT` - Initialises the local `LOCAL_TYPE_LIST` and `LOCAL_TYPE_TRACKING_INITIALISED` 

### Declared and Defined handling

In Para, there are two different states a variable can exist in; It is either declared or defined.

#### Declared Variable

A declared variable is, unlike in C, can be appearing in two forms:

- Allocated and with a value set, though their meta-property `.meta.defined` is set to `false`, which means the program
  knows it is invalid to be accessed.
- The value is `NULL` aka. this is usually what is passed to a function as args to indicate the value is not set. This
  is in this case a *True `NULL`*, as it is not a pointer set to NULL or a value with their memory set to `NULL`

This must be watched out for when writing PBL code, as both NULL and .meta.defined == false mean a variable is declared.

As a note, a double-pointer (user-created pointer) to a variable is always going to be NULL, aka. there is no way to
properly determine whether the variable is declared or defined, meaning the compiler will work out whether the
user-created variable is declared. This means user-pointers are by default defined in the generated source code.

(This will be changed later, by implementing `PblPointer_T` as a new type and as such pointers will be like variables,
meaning a `PblPointer_T` can be undefined with NULL and declared, but with `.meta.defined == false`)

#### Defined Variable

The defined variables on the other hand will always be initialised with a default value, usually `0`, except for struct
types, which will have all their property-pointers set to NULL, aka. they are also only 'declared' but not initialised.

### Function Return Type Handling

For functions, returns will always be pointers no matter what, since all variables are dynamically allocated and the
actual storage in the stack is the pointer itself.

This means that returning NULL will always be valid in Para aka. it's the `None` (from Python) of Para,

### Global Variable handling

Global Variables are in Para handled a bit differentially, due to the general allocations using `pbl-mem.h`. This
means that any Para file will contain a `static void PBL_INIT_GLOBALS()` function, where all the local globals
are defined and the code is executed that was written before. 

This function will also interpret any left-over other variables, like:

```c
int val = 4;

// -> 
PblInt_T val = 4;
```

This means that in the compiled code the globals will simply be declarations, until they were defined
on runtime (before the execution of main).

## Memory accessing - `pbl-mem.h`

As already stated previously in section [Variables](#variables---pbl-typesh), Para is using a garbage collector to
handle its leftover variables that are not collected at the end of a stack's lifetime. This means that almost all 
variables will be allocated and cleaned up using the [Boehm garbage collector](https://hboehm.info/gc/). The only 
exceptions are for small variables that will likely be allocated in the stack using `alloca()` to preserve speed in
crucial tasks and not add unnecessary memory to the garbage collector.

## Function Meta-Data Tracking - `pbl-function.h`

Inside Para, when calling a Para function, so-called `PblFunctionCallMetaData_T` types are passed as the first
argument to every function, which contain:

- The meta-data of the invocation aka. call context,
- The data necessary to track [exception meta-data](#exceptions---pbl-functionh)

These meta-data variables will be dynamically created for every invocation and will be allocated in the heap. Meaning
they can be accessed outside the context, and used to create crash-tracebacks to get extensive execution info on the
failure of the program.

## Exceptions - `pbl-function.h`

Exceptions in Para are very similarly implemented to the exceptions in Python.

Exceptions can be raised, re-raised with a parent-exception and child-exception, caught using an `except` block and also
used to pre-maturely abort the program.

Inside Para these are though implemented using the `PblFunctionCallMetaData_T` types, which will store the traceback
and exception information. All macros for exceptions have been implemented in this header and should be always used when
implementing higher level functions.

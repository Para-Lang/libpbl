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

- Indention: 2 spaces
- Structs/Enums: PascalCase with leading `Pbl`
- Struct Properties: snake_case
- Constants and Enum Properties: SCREAMING_SNAKE_CASE
- Typedef: PascalCase with leading `Pbl` and trailing `_T`
- Local Variables: snake_case
- Parameters: snake_case
- Macros: SCREAMING_SNAKE_CASE (exceptions are function definition macros, where PascalCase is applied)
- Functions: PascalCase with leading `Pbl`
- Constructor Functions: PascalCase with leading `pre__Pbl`

## Constructors

As Para requires some overhead to run properly, C constructors are used to set up certain features.
The order of constructor evaluation is as following:

- `pre__PblInitialiseGarbageCollection` (Priority `101`) - Calls `GC_INIT()` and sets up memory handling. This must
  always be first, as otherwise memory functions from `mem/pbl-mem.h` can NOT be used.
- `pre__PblInitTypeListTracking` (Priority `102`) - Creates and initialises local type tracking.
- `pre__PblInitGlobals` (Priority `103`) - Initialises globals for a standard file. This constructor is
  created with `PBL_INIT_GLOBALS`, which is a macro that may be used to define local globals before main
  starts execution.

## Variables - `pbl-types.h`

Variables in Para are specifically handled using a garbage collector, meaning that initialised variables are
going to be represented and accessed using pointers.

States of a Variable in Para:

- Only Declared.
- Defined Variable that can be null (`.meta.can_be_null` is true).
- Defined Variable that has been written to (Per default `.meta.can_be_null` is false). 
- Freed/Destroyed Variable that was destroyed explicitly/manually or automatically by the Garbage Collector.

## Variable Base Model

The variable base model (`type var`) consists of two features:

- The `PblVarMetaData_T meta` property that defines meta-data about the variable. This is always defined when creating 
  a new variable.
- The `actual` field, which defines the actual value of the variable. This field can have two different types:
  - Pointer type (`type* actual`). This type is used in case that the type of the variable is struct-based. This may be 
    null if `meta.can_be_null` is set to true. Otherwise, setting it to NULL is an error and null-safety violation.
  - Default type (`type actual`). This type is used in case that the type is a primitive type. This can never be `null`
    and has to be always defined.

Note that the main wrapper/para type that is provided by the library will be defined locally in the stack, and only
if the type is complex, then the `type *actual` property will be allocated in the heap.

## Meta-Data Tracking - `pbl-types.h`

Para implements meta-data tracking using `PblVarMetaData_T` and pre-defined macros, tracking things like:

- If the variable has been destroyed.
- If the variable can be assigned to null. (Only for complex types)
- The type of the variable.

### Definition defaults `_Default` for PBL-Types
 
When defining a new built-in type, there should always be a macro that defines the `_Default` for the variable.
This defines the default values for the variable when defining it. This serves as a basic foundation that the user
can overwrite from.

### Type List - `pbl-type-list.h`

Para keeps a type list of all registered types that were created or imported inside a source file. This list is
created at startup of the program, meaning all types may be dynamically accessed and used to create new types.

This means that each file has its own scope with meta-data tracking, which can be also imported into other files.

To manually init a para-file and register new types, you can call the following macros:

```c
// Actual globals or inclusions of headers
#include <libpbl/pbl.h>

// Para initialisation
P_INIT_FILE;
P_INIT_GLOBALS {
  // Example for a void type
  P_REGISTER_TYPE(&LOCAL_TYPE_LIST, PblNone_T, "void", false, false);
};
```

Inside Para this is very important, as all variables should allow runtime checking of the type 

```c
entry status Main() {
  int var = 4;
  
  // Compile-time 'typeof' which will try to convert this to a direct call to the local type list.
  type var_type = typeof(var); 

  // The above is equal to this, but here it will be executed on runtime.
  type var_type = GetTypeOf(var);
}
```

### Global Variable handling

Global Variables are in Para handled a bit differentially, due to the variable allocations using `pbl-mem.h`. This
means that any Para file will contain a `static void PBL_INIT_GLOBALS()` function, where all the local globals
are defined and the code is executed that was written before.

That means that code will be converted like this:

- Before:
  ```c
  int num = 4;
  string str = "4";
  ```

- After:
  ```c
  PblInt_T num;
  PblString_T str;
  
  P_INIT_FILE;
  P_INIT_GLOBALS {
    // ... type initialisations
    
    num = PblGetIntT(4);
    str = PblString_T_New("4");
  };
  ```

This means that in the compiled code the globals will simply stay declarations until they were defined
using constructors on runtime (before the execution of main).

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

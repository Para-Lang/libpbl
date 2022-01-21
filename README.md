# `libpbl` - Para-C Base Library

[![Codecov](https://github.com/Para-C/Para-C-Base-Library/actions/workflows/codecov.yml/badge.svg)](https://github.com/Para-C/Para-C-Base-Library/actions/workflows/codecov.yml)
[![Dr.Memory and GTest](https://github.com/Para-C/Para-C-Base-Library/actions/workflows/drmemory.yml/badge.svg)](https://github.com/Para-C/Para-C-Base-Library/actions/workflows/drmemory.yml)
[![Open Para-C issues](https://img.shields.io/github/issues/Para-C/Para-C)](https://github.com/Para-C/Para-C/issues)

This is the repository containing the c-implementation library (Para-C Core Library, and partly Para-C Built-In Library)
, which is used for the built-in functions, keywords and items, which are required for the base language.

*For proper documentation and info on Para-C visit the main repo [here](https://github.com/Para-C/Para-C). This also
includes issues or requesting changes. These should be done on the main branch, while the issues here will be
maintainers-only*

# Testing

For testing purposes, [GTest (Google Test)](https://github.com/google/googletest/releases/tag/release-1.11.0)
is used in an C++ environment, which will simply include the C-files and run them.

In actual code usage, the Para-C Compiler will use the code as regular C, and only for testing C++ will/must be used.

# Basic Overview

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
- Startup Constructors: Name with leading `PBL_CONSTRUCTOR`
- Cleanup De-Constructors: Name with leading `PBL_DECONSTRUCTOR`

## Meta-Data Tracking - `pbl-types.h`

Para-C implements meta-data tracking using `PblVarMetaData_T` and pre-defined macros, tracking things like:

- If the variable has been defined yet
- Effective space the user has to utilise. Note that effective space does not include actual space that is allocated!
  This is due to meta-data also taking up a bit of memory space.

### `_DefDefault` and `_DeclDefault` for PBL-Types

When declaring a built-in type that should be used inside Para-C, the style of the general types should be replicated,
to allow for the proper usage of defaults aka. `_DefDefault` and `_DeclDefault`

## Variables - `pbl-types.h`

Variables in Para-C are specifically handled using a garbage collector, meaning that initialised variables are
going to be represented and accessed using pointers. 

States of a Variable: 
- Only Declared (True C Declaration)
- Technically "Declared" (Technically defined in C, but handled as declared in Para-C). Two possible 
  scenarios:
  - Allocated, but the meta-Property `.meta.defined` is set to false, since no value was assigned yet
  - The value is NULL, as it's a pointer and there has not been any clear definition.
- Defined Variable that has been written to
- Freed Variable by the Garbage Collector

### Type List

Para-C keeps a type list of all registered types that were created or imported inside a source file. This list is 
created at startup of the program, meaning all types may be dynamically accessed and used to create new types. 

This means that each file has its own scope with meta-data tracking, which can be also imported into other files. 

Constructor Priority:
- `PBL_CONSTRUCTOR_TYPES_LIST_INIT` - Initialises the local `LOCAL_TYPE_LIST` and `LOCAL_TYPE_TRACKING_INITIALISED` 

### Declared and Defined handling

In Para-C, there are two different states a variable can exist in; It is either declared or defined.

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

This means that returning NULL will always be valid in Para-C aka. it's the `None` (from Python) of Para-C,

### Global Variable handling

Global Variables are in Para-C handled a bit differentially, due to the general allocations using `pbl-mem.h`. This
means that any Para-C file will contain a `static void PBL_INIT_GLOBALS()` function, where all the local globals
are defined and the code is executed that was written before.

This means that in the compiled code the globals will simply be declarations, until they were defined
on runtime (before the execution of main).

### Automatic Cleanup for local variables

When allocating a local variable, the PBL will automatically define the `__cleanup__` attribute of the variable, meaning
when it goes out of scope the generated cleanup function for the type is called (`__<PBL_TYPE>_Cleanup`) and the type is
automatically de-allocated. This is to automatically handle garbage collection / deallocation when possible!

## Memory accessing - `pbl-mem.h`

(Currently in work - to be decided)

## Function Meta-Data Tracking - `pbl-function.h`

Inside Para-C, when calling a Para-C function, so-called `PblFunctionCallMetaData_T` types are passed as the first
argument to every function, which contain:

- The meta-data of the invocation aka. call context,
- The data necessary to track [exception meta-data](#exceptions---pbl-functionh)

These meta-data variables will be dynamically created for every invocation and will be allocated in the heap. Meaning
they can be accessed outside the context, and used to create crash-tracebacks to get extensive execution info on the
failure of the program.

## Exceptions - `pbl-function.h`

Exceptions in Para-C are very similarly implemented to the exceptions in C#.

Exceptions can be raised, re-raised with a parent-exception and child-exception, caught using an `except` block and also
used to pre-maturely abort the program.

Inside Para-C these are though implemented using the `PblFunctionCallMetaData_T` types, which will store the traceback
and exception information. All macros for exceptions have been implemented in this header and should be always used when
implementing higher level functions.

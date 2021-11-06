# `libpbl` - Para-C Base Library  

[![Codecov](https://github.com/Para-C/Para-C-Base-Library/actions/workflows/codecov.yml/badge.svg)](https://github.com/Para-C/Para-C-Base-Library/actions/workflows/codecov.yml)
[![Dr.Memory and GTest](https://github.com/Para-C/Para-C-Base-Library/actions/workflows/drmemory.yml/badge.svg)](https://github.com/Para-C/Para-C-Base-Library/actions/workflows/drmemory.yml)

This is the repository containing the c-implementation library (Para-C Core Library, and partly Para-C Built-In Library),
which is used for the built-in functions, keywords and items, which are required for the base language.

For the Para-C Extension Library, go [to the lib folder](https://github.com/Para-C/Para-C/tree/dev/lib)

*For proper documentation and info on Para-C visit the main repo [here](https://github.com/Para-C/Para-C).
This also includes issues or requesting changes. These should be done on the main branch, while the issues
here will be maintainers-only*

# Testing

For testing purposes, [GTest (Google Test)](https://github.com/google/googletest/releases/tag/release-1.11.0)
is used in an C++ environment, which will simply include the C-files and run them.

In actual code usage, the Para-C Compiler will use the code as regular C, and only for testing C++ will/must be used.

# Basic Concepts

## Meta-Data Tracking - `pbl-types.h`

Para-C implements meta-data tracking using `PblMetaVarCtx_T` and pre-defined macros, tracking things like:
- If the variable has been defined yet
- Effective space the user has to utilise. Note that effective space does not include actual space that is allocated! 
This is due to meta-data also taking up a bit of memory space.

## Declared and Defined handling - `pbl-types.h`

In Para-C, there are two different states a variable can exist in; It is either declared or defined. 

### Declared Variable

A declared variable is, unlike in C, still allocated and has a value set, though with meta-data tracking their 
meta-property 'defined' is set to 'false', which means the program knows it is invalid to be accessed. This is the
default handling for a declared variable, though there are two major differences which are different in the PBL:

- User Pointers (Pointer to PBL Allocated Memory) are always going to be defined when their value is set, aka. they 
  can only be null, as they are pointers and not actual PBL types. This must be watched out for.

This must be watched out for when writing PBL code, as both NULL and .meta.defined == false mean a variable is declared.
As a another note, a double-pointer (user-created pointer) to a variable is always going to be NULL, aka. there is no 
way to properly determine whether the variable is declared or defined, meaning the compiler will work out whether the
user-created variable is declared. This means user-pointers are by default defined in the generated source code.
 
### Defined Variable

The defined variables on the other hand will always be initialised with a default value, usually 0, except for struct
types, which will have all their property-pointers set to NULL, aka. they are also only 'declared' but not initialised.

### Function Return Type Handling

For functions, returns will always be pointers no matter what, since all variables are dynamically allocated and the
actual storage in the stack is the pointer itself. This means that returning NULL will always be valid in Para-C aka.
it's the `None` (from Python) of Para-C.

### Global Variable handling

Global Variables are in Para-C handled a bit differentially, due to the general allocations using `pbl-mem.h`. This means
that any Para-C file will contain a `static void __InitialiseLocalGlobals()` function, where all the local globals are
defined and the code is executed that was written before.

This means that in the compiled code the globals will simply be pointer declarations with no interference. To that,
all declarations will be on runtime set to NULL, unless they have been defined.

## Memory accessing - `pbl-mem.h`

(Currently in work - to be decided)

## Function Meta-Data Tracking - `pbl-function.h`

Inside Para-C, when calling a Para-C function, so-called `PblMetaFunctionCallCtx_T` types are passed
as the first argument to every function, which contain:

- The meta-data of the invocation aka. call context, 
- The data necessary to track [exception meta-data](#exceptions---pbl-functionh)

These meta-data variables will be dynamically created for every invocation and will be allocated in the heap.
Meaning they can be accessed outside of the context, and used to create crash-tracebacks to 
get extensive execution info on the failure of the program.

## Exceptions - `pbl-function.h`

Exceptions in Para-C are very similarly implemented to the exceptions in C#. 

Exceptions can be raised, re-raised with a parent-exception and child-exception, caught using an `except` block
and also used to pre-maturely abort the program. 

Inside Para-C these are though implemented using the `PblMetaFunctionCallCtx_T` types, which will
store the traceback and exception information. All macros for exceptions have been implemented in this header
and should be always used when implementing higher level functions.

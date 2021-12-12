/// @file pbl-io.h
/// @brief IO Implementation based on stdio.h
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#pragma once

// Including the Base <stdio.h> which this header intends to implement
#include <stdio.h>

// General Required Header Inclusion
#include "../types/pbl-string.h"
#include "../types/pbl-types.h"

#ifndef PBL_MODULES_IO_H
#define PBL_MODULES_IO_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- File ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size of the type 'PblFile_T' in bytes
#define PblFile_T_Size sizeof(FILE *)
/// @brief Returns the declaration default for the type 'PblFile_T'
#define PblFile_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblFile_T)
/// @brief Returns the definition default for the type 'PblFile_T', where only value itself has been created
#define PblFile_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblFile_T, NULL)

/// @brief File Descriptor used to perform I/O actions on a file
struct PblFile PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(FILE *);
/// @brief File Descriptor used to perform I/O actions on a file
typedef struct PblFile PblFile_T;

// ---- End of File ---------------------------------------------------------------------------------------------------

// ---- Stream Type ---------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size of the type 'PblStream_T' in bytes
#define PblStream_T_Size (sizeof(PblUInt_T *) + sizeof(PblFile_T *) + sizeof(PblBool_T *) + sizeof(PblString_T *))
/// @brief Returns the declaration default for the type 'PblStream_T'
#define PblStream_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblStream_T)
/// @brief Returns the definition default for the type 'PblStream_T', where the children have not been set yet and only the
/// value itself 'exists' already.
#define PblStream_T_DefDefault                                                                                         \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblStream_T, .fd = NULL, .file = NULL, .open = NULL, .mode = NULL)

/// @brief Base Struct of PblString - avoid using this type
struct PblStream_Base {
  /// @brief The unique integer identifier associated with the file Descriptor
  PblUInt_T *fd;
  /// @brief The FILE pointer, which points to the stream/file - defined if the stream was opened
  PblFile_T *file;
  /// @brief Describes whether the file descriptor is currently in use
  PblBool_T *open;
  /// @brief The mode the FILE* was opened
  PblString_T *mode;
};

/// @brief File Stream used to perform I/O actions on a file
struct PblStream PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(struct PblStream_Base);
/// @brief File Stream used to perform I/O actions on a file
typedef struct PblStream PblStream_T;

/// @brief Standard stream for getting input on the default program console
#define PBL_STREAM_STDIN                                                                                               \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblStream_T, .fd = PblGetUIntT(0), .file = PblGetFileT(stdin),        \
                                                 .open = PblGetBoolT(true), .mode = PblGetStringT("a"))

/// @brief Standard stream for outputting to the default program console
#define PBL_STREAM_STDOUT                                                                                              \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblStream_T, .fd = PblGetUIntT(1), .file = PblGetFileT(stdout),       \
                                                 .open = PblGetBoolT(true), .mode = PblGetStringT("a"))

/// @brief Standard stream for outputting error messages to the default program console
#define PBL_STREAM_STDERR                                                                                              \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblStream_T, .fd = PblGetUIntT(2), .file = PblGetFileT(stderr),       \
                                                 .open = PblGetBoolT(true), .mode = PblGetStringT("a"))

// ---- End of Stream Type --------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/**
 * @brief Converts the low level C-Type to a PBL File type
 * @param val The FILE pointer C-type
 * @return The newly created PBL File type
 * @note This is a C to Para-C type conversion function - args are in C therefore
 */
PblFile_T *PblGetFileT(FILE *val);

/**
 * @brief Converts the low level C-Type to a PBL Stream type. Creates the FILE* pointer as well
 * @param fd The file descriptor that will be converted
 * @param mode The mode that should be used to open the FILE*
 * @return The newly created PBL Stream type
 * @note This is a C to Para-C type conversion function - args are therefore in C
 */
PblStream_T *PblGetStreamT(int fd, const char *mode);

/// Arguments struct for PblPrint (PblPrintOverhead)
struct PblPrint_Args {
  PblString_T *out;
  PblStream_T *stream;
  PblChar_T *end;
};

/**
 * @brief Prints the content of the passed string
 * @param out The string that should be printed out
 * @param stream The stream it should be printed onto
 * @param end The end character that should be printed after 'out'
 * @note This is the base function that is wrapped using 'PblPrintOverhead'
 */
PblVoid_T PblPrint_Base(PblString_T *out, const PblStream_T *stream, const PblChar_T *end);

/**
 * @brief Printing overhead for 'PblPrintBase' - this it the function called by the macro 'PblPrint'
 * @param in The parameter struct
 */
PblVoid_T PblPrint_Overhead(struct PblPrint_Args in);

/**
 * @brief Prints the content of the passed string
 * @param out The string that should be printed out (Pointer)
 * @param stream The stream it should be printed onto
 * @param end The end character that should be printed after 'out'
 */
#define PblPrint(...) PblPrint_Overhead((struct PblPrint_Args){__VA_ARGS__});

// ---- Functions Definitions -----------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_MODULES_IO_H

/// @file pbl-io.h
/// @brief IO Implementation based on stdio.h
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#pragma once

// Including the Base <stdio.h> which this header intends to implement
#ifdef __cplusplus
# include <cstdio>
#else
# include <stdio.h>
#endif


// General Required Header Inclusion
#include "../types/pbl-string.h"
#include "../types/pbl-types.h"
#include "../func/pbl-function.h"

#ifndef PBL_MODULES_IO_H
#define PBL_MODULES_IO_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- File ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size of the type 'PblIOFile_T' in bytes
#define PblFile_T_Size sizeof(FILE *)
/// @brief Returns the declaration default for the type 'PblIOFile_T'
#define PblFile_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblIOFile_T)
/// @brief Returns the definition default for the type 'PblIOFile_T', where only value itself has been created
#define PblFile_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblIOFile_T, NULL)

/// @brief File Descriptor used to perform I/O actions on a file
struct PblIOFile { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(FILE *); };
/// @brief File Descriptor used to perform I/O actions on a file
typedef struct PblIOFile PblIOFile_T;

// ---- End of File ---------------------------------------------------------------------------------------------------

// ---- Stream Type ---------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size of the type 'PblIOStream_T' in bytes
#define PblStream_T_Size (sizeof(PblUInt_T *) + sizeof(PblIOFile_T *) + sizeof(PblBool_T *) + sizeof(PblString_T *))
/// @brief Returns the declaration default for the type 'PblIOStream_T'
#define PblStream_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblIOStream_T)
/// @brief Returns the definition default for the type 'PblIOStream_T', where the children have not been set yet and only the
/// value itself 'exists' already.
#define PblStream_T_DefDefault                                                                                         \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblIOStream_T, .fd = NULL, .file = NULL, .open = NULL, .mode = NULL)

/// @brief Base Struct of PblString - avoid using this type
struct PblStream_Base {
  /// @brief The unique integer identifier associated with the file Descriptor
  PblUInt_T *fd;
  /// @brief The FILE pointer, which points to the stream/file - defined if the stream was opened
  PblIOFile_T *file;
  /// @brief Describes whether the file descriptor is currently in use
  PblBool_T *open;
  /// @brief The mode the FILE* was opened
  PblString_T *mode;
};

/// @brief File Stream used to perform I/O actions on a file
struct PblIOStream { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(struct PblStream_Base); };
/// @brief File Stream used to perform I/O actions on a file
typedef struct PblIOStream PblIOStream_T;

/// @brief Standard stream for getting input on the default program console
#define PBL_STREAM_STDIN                                                                                               \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblIOStream_T, .fd = PblGetUIntT(0), .file = PblGetIOFileT(stdin),    \
                                                 .open = PblGetBoolT(true), .mode = PblGetStringT("a"))

/// @brief Standard stream for outputting to the default program console
#define PBL_STREAM_STDOUT                                                                                              \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblIOStream_T, .fd = PblGetUIntT(1), .file = PblGetIOFileT(stdout),   \
                                                 .open = PblGetBoolT(true), .mode = PblGetStringT("a"))

/// @brief Standard stream for outputting error messages to the default program console
#define PBL_STREAM_STDERR                                                                                              \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblIOStream_T, .fd = PblGetUIntT(2), .file = PblGetIOFileT(stderr),   \
                                                 .open = PblGetBoolT(true), .mode = PblGetStringT("a"))

// ---- End of Stream Type --------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/**
 * @brief Converts the low level C-Type to a PBL File type
 * @param val The FILE pointer C-type
 * @return The newly created PBL File type
 * @note This is a C to Para-C type conversion function - args are in C therefore
 */
PblIOFile_T *PblGetIOFileT(FILE *val);

/**
 * @brief Converts the low level C-Type to a PBL Stream type. Creates the FILE* pointer as well
 * @param fd The file descriptor that will be converted
 * @param mode The mode that should be used to open the FILE*
 * @return The newly created PBL Stream type
 * @note This is a C to Para-C type conversion function - args are therefore in C
 */
PblIOStream_T *PblGetIOStreamT(int fd, const char *mode);

// Creating the overhead and struct type for the Pbl-Function 'PblPrint'
PBL_CREATE_FUNC_OVERHEAD(PblString_T *, PblInput,, PblString_T *display_msg, PblChar_T* end)

/**
 * @brief Takes input and displays the entered message before it
 * @param display The display message
 * @param end The end-character that should be displayed. If per default '\0'. This is the same logic as in Print!
 * @return The input that was given
 */
#define PblInput(args...)  \
  PBL_GET_FUNC_OVERHEAD_IDENTIFIER(PblInput)((struct PBL_GET_FUNC_ARGS_IDENTIFIER(PblInput)){args})

// Creating the overhead and struct type for the Pbl-Function 'PblPrint'
PBL_CREATE_FUNC_OVERHEAD(PblChar_T *, PblInputChar,, PblString_T *display_msg, PblChar_T* end)

/**
 * @brief Takes a single key input and displays the entered message before it
 * @param display The display message
 * @param end The end-character that should be displayed. If per default '\0'. This is the same logic as in Print!
 * @return The character that was fetched
 * @note If the entered char is \n or EOF, then \0 is returned.
 */
#define PblInputChar(args...)  \
  PBL_GET_FUNC_OVERHEAD_IDENTIFIER(PblInputChar)((struct PBL_GET_FUNC_ARGS_IDENTIFIER(PblInputChar)){args})

// Creating the overhead and struct type for the Pbl-Function 'PblPrint'
PBL_CREATE_FUNC_OVERHEAD(__attribute__((unused)) PblVoid_T, PblPrint,, PblString_T *out, PblIOStream_T *stream, PblChar_T *end)

/**
 * @brief Prints the content of the passed string
 * @param out The string that should be printed out (Pointer)
 * @param stream The stream it should be printed onto
 * @param end The end character that should be printed after 'out'
 */
#define PblPrint(args...) \
  PBL_GET_FUNC_OVERHEAD_IDENTIFIER(PblPrint)((struct PBL_GET_FUNC_ARGS_IDENTIFIER(PblPrint)){args})

// ---- Functions Definitions -----------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_MODULES_IO_H

/// @file pbl-io.h
/// @brief IO Implementation based on stdio.h
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

#pragma once

// Including the Base <stdio.h> which this header intends to implement
#ifdef __cplusplus
#include <cstdio>
#else
#include <stdio.h>
#endif

// General Required Header Inclusion
#include "./core/pbl-core.h"
#include "./types/pbl-string.h"
#include "./pbl-function.h"

#ifndef PBL_LIB_IO_H
#define PBL_LIB_IO_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- File ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size of the type 'PblIOFile_T' in bytes
#define PblIOFile_T_Size sizeof(FILE *)
/// @brief Returns the declaration default for the type 'PblIOFile_T'
#define PblIOFile_T_DeclDefault PBL_TYPE_DECL_VAL(PblIOFile_T)
/// @brief Returns the definition default for the type 'PblIOFile_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblIOFile_T_DefDefault PBL_TYPE_DEF_VAL(PblIOFile_T, NULL)

/// @brief File Descriptor used to perform I/O actions on a file
struct PblIOFile {
  PBL_TYPE_DEF_HELPER(FILE *);
};
/// @brief File Descriptor used to perform I/O actions on a file
typedef struct PblIOFile PblIOFile_T;

// ---- End of File ---------------------------------------------------------------------------------------------------

// ---- Stream Type ---------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size of the type 'PblIOStream_T' in bytes
#define PblIOStream_T_Size (sizeof(PblUInt_T *) + sizeof(PblIOFile_T *) + sizeof(PblBool_T *) + sizeof(PblString_T *))
/// @brief Returns the declaration default for the type 'PblIOStream_T'
#define PblIOStream_T_DeclDefault PBL_TYPE_DECL_VAL(PblIOStream_T)
/// @brief Returns the definition default for the type 'PblIOStream_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblIOStream_T_DefDefault PBL_TYPE_DEF_VAL(PblIOStream_T, {.fd = NULL, .file = NULL, .open = NULL, .mode = NULL})

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
struct PblIOStream {
  PBL_TYPE_DEF_HELPER(struct PblStream_Base);
};
/// @brief File Stream used to perform I/O actions on a file
typedef struct PblIOStream PblIOStream_T;

// ---- End of Stream Type --------------------------------------------------------------------------------------------

// ---- Globals -------------------------------------------------------------------------------------------------------

__attribute__((unused)) __attribute__((unused)) extern PblIOStream_T* PBL_STDIN;
__attribute__((unused)) extern PblIOStream_T* PBL_STDOUT;
__attribute__((unused)) extern PblIOStream_T* PBL_STDERR;

// ---- End of Globals ------------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/**
 * @brief Converts the low level C-Type to a PBL File type
 * @param val The FILE pointer C-type
 * @return The newly created PBL File type
 * @note This is a C to Para type conversion function - args are in C therefore
 */
PblIOFile_T *PblGetIOFileT(FILE *val);

/**
 * @brief Converts the low level C-Type to a PBL Stream type. Creates the FILE* pointer as well
 * @param fd The file descriptor that will be converted
 * @param mode The mode that should be used to open the FILE*
 * @return The newly created PBL Stream type
 * @note This is a C to Para type conversion function - args are therefore in C
 */
PblIOStream_T *PblGetIOStreamT(int fd, const char *mode);

// Creating the overhead and struct type for the Pbl-Function 'PblPrint'
PBL_FUNC_OVERHEAD(PblInput, PblString_T *, PblString_T *display_msg, PblChar_T *end)

/**
 * @brief Takes input and displays the entered message before it
 * @param display The display message
 * @param end The end-character that should be displayed. If per default '\0'. This is the same logic as in Print!
 * @return The input that was given
 */
#define PblInput(args...) PblInput_Overhead((struct PblInput_Args){args})

// Creating the overhead and struct type for the Pbl-Function 'PblPrint'
PBL_FUNC_OVERHEAD(PblInputChar, PblChar_T *, PblString_T *display_msg, PblChar_T *end)

/**
 * @brief Takes a single key input and displays the entered message before it
 * @param display The display message
 * @param end The end-character that should be displayed. If per default '\0'. This is the same logic as in Print!
 * @return The character that was fetched
 * @note If the entered char is \n or EOF, then \0 is returned.
 */
#define PblInputChar(args...) PblInputChar_Overhead((struct PblInputChar_Args){args})

// Creating the overhead and struct type for the Pbl-Function 'PblPrint'
PBL_FUNC_OVERHEAD(PblPrint, PblVoid_T, PblString_T *out, PblIOStream_T *stream, PblChar_T *end)

/**
 * @brief Prints the content of the passed string
 * @param out The string that should be printed out (Pointer)
 * @param stream The stream it should be printed onto
 * @param end The end character that should be printed after 'out'
 */
#define PblPrint(args...) PblPrint_Overhead((struct PblPrint_Args){args})

// ---- Functions Definitions -----------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_IO_H

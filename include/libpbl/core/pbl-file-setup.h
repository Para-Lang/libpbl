/**
 * @file pbl-file-setup.h
 * @brief File management setup and initialization.
 * @author Luna Klatzer
 * @copyright Copyright (c) 2021 - 2022
 */

#include "./pbl-type-list.h"

#ifndef PBL_LIB_FILE_SETUP_H
#define PBL_LIB_FILE_SETUP_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- File Helpers --------------------------------------------------------------------------------------------------

/**
 * @brief Initialises a c-source file making it a Para source file, which contains the local type tracking list.
 */
#define PBL_INIT_FILE(file) PBL_INIT_LOCAL_TYPE_LIST(file)

/**
 * @brief Initialises a c-header file making it a Para header file, which contains the external type tracking list
 * declaration.
 * @note This is required for a header if it wants to export Para types to other files!
 */
#define PBL_INIT_HEADER(file) PBL_INIT_HEADER_TYPE_LIST(file)

/**
 * @brief Function signature that is intended to be used to initialise global variables in a single file.
 * @example
 *   PBL_INIT_FILE(FILE_NAME); // Replace FILE_NAME with the actual name of the file. Replace '-' with '_'! \n
 *   PBL_INIT_GLOBALS { \n
 *     PBL_REGISTER_TYPE(&LOCAL_TYPE_LIST, PblAny_T, "any", false, true); \n
 *   };
 * @since 0.1.dev8
 */
#define PBL_INIT_GLOBALS                                                                                               \
  __attribute__((unused)) __attribute__((constructor(103)))                                                            \
  __attribute__((deprecated("Compiler-Only Function - User Call Invalid!"))) static void                               \
  pre__PblInitGlobals()

// ---- End of File Helpers ------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_FILE_SETUP_H

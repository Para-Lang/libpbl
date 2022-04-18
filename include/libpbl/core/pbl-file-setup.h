/// @file pbl-file-setup.h
/// @brief File management setup and initialization.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

#include "./pbl-type-list.h"

#ifndef PBL_LIB_FILE_SETUP_H
#define PBL_LIB_FILE_SETUP_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- File Helpers --------------------------------------------------------------------------------------------------

#define PBL_INIT_FILE PBL_INIT_LOCAL_TYPE_LIST;

#define PBL_INIT_GLOBALS                                                                                               \
  __attribute__((unused)) __attribute__((constructor(103)))                                                            \
  __attribute__((deprecated("Compiler-Only Function - User Call Invalid!"))) static void                               \
  pre__PblInitGlobals()

// ---- End of File Helpers ------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_FILE_SETUP_H

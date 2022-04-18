/// @file pbl.h
/// @brief Main header for the Para Base Library (Static C library)
/// Styling and naming are similar to the Google C++ style guide
/// @see https://google.github.io/styleguide/cppguide.html
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

#pragma once

// Including Headers that are required throughout the entire PBL Library
#ifdef __cplusplus
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#else
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#endif

// Main Header Inclusions
#include "./pbl-main.h"
#include "./mem/pbl-mem.h"
#include "./types/pbl-types.h"

// Included the additional headers
#include <va-opt/va-opt.h>

#ifndef PBL_LIB_H
#define PBL_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Macros --------------------------------------------------------------------------------------------------------

/// @brief The current release identifier
#define PBL_VERSION "0.1.dev6"

/// @brief Indicates the current library version being a development version
#define PBL_DEV true

/// @brief Indicates the current library version being a stable version
#define PBL_STABLE false

// ---- End of Macros -------------------------------------------------------------------------------------------------

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

#endif//PBL_LIB_H

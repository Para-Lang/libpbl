/// @file pbl.h
/// @brief Main header for the Para-C Base Library (Static C library)
/// Styling and naming are similar to the Google C++ style guide
/// @see https://google.github.io/styleguide/cppguide.html
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#pragma once

// Including Headers that are required throughout the entire PBL Library
#ifdef __cplusplus
# include <cstdarg>
# include <cstdio>
# include <cstdlib>
#else
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
#endif

// Main Header Inclusions
#include "./pbl-main.h"

// Included the additional headers
#include "./additional/va-opt.h"

#ifndef PBL_MODULES_LIBRARY_H
#define PBL_MODULES_LIBRARY_H

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

#ifdef __cplusplus
}
#endif

#endif//PBL_MODULES_LIBRARY_H

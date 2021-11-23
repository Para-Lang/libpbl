/// @file pbl.h
/// @brief Main header for the Para-C Base Library (Static C library)
/// Styling and naming are similar to the Google C++ style guide
/// @see https://google.github.io/styleguide/cppguide.html
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

// lib-headers includes
#include "./pbl-int.h"
#include "./pbl-io.h"
#include "./pbl-string.h"
#include "./pbl-types.h"
#include "./pbl-function.h"

#ifndef PBL_MODULES_LIBRARY_H
#define PBL_MODULES_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Macros --------------------------------------------------------------------------------------------------------

/// @brief The current release identifier
#define __parac "0.1.dev6"
/// @brief Indicates the current library version being a development version
#define __parac_dev true
/// @brief Indicates the current library version being a stable version
#define __parac_stable false

#ifdef __cplusplus
}
#endif

#endif //PBL_MODULES_LIBRARY_H

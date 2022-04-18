/// @file pbl.h
/// @brief Main header for the Para Base Library (Static C library)
/// Styling and naming are similar to the Google C++ style guide
/// @see https://google.github.io/styleguide/cppguide.html
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

#pragma once

#ifndef PBL_LIB_H
#define PBL_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

// Main Header Inclusions
#include "./pbl-err.h"
#include "./core/pbl-core.h"

// Included the additional headers
#include <va-opt/va-opt.h>

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

#endif//PBL_LIB_H

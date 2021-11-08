///
/// Main header for the Para-C Base Library (Static C library)
/// Styling and naming are similar to the Google C++ style guide
/// @see https://google.github.io/styleguide/cppguide.html
///
///    Para-C Base Library - Base Library and implementation for the Para-C language
///    Copyright (C) 2021  Luna Klatzer
///
///    This program is free software: you can redistribute it and/or modify
///    it under the terms of the GNU General Public License as published by
///    the Free Software Foundation, either version 3 of the License, or
///    (at your option) any later version.
///
///    This program is distributed in the hope that it will be useful,
///    but WITHOUT ANY WARRANTY; without even the implied warranty of
///    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
///    GNU General Public License for more details.
///
///    You should have received a copy of the GNU General Public License
///    along with this program.  If not, see <https://www.gnu.org/licenses/>.
///
/// @author Luna-Klatzer
/// @note The styling guide for the PBL is as following:
/// - Structs/Enums: PascalCase with leading 'Pbl'
/// - Struct Properties: snake_case
/// - Constants and Enum Properties: PascalCase with leading 'k' (copied from the Google C++ Styling Guide)
/// - Typedef: PascalCase with leading 'Pbl' and trailing '_T'
/// - Local Variables: snake_case
/// - Parameters: snake_case
/// - Macros: SCREAMING_SNAKE_CASE (exceptions are function definition macros, where PascalCase is applied)
/// - Functions: PascalCase
/// - Indention is set to 2 spaces
/// @note When declaring a built-in type that should be used inside Para-C, the style of the general types should
/// be replicated, to allow for the proper usage of defaults aka. `_DefDefault` and `_DeclDefault`

// lib-headers includes
#include "./pbl-int.h"
#include "./pbl-io.h"
#include "./pbl-string.h"
#include "./pbl-types.h"
#include "./pbl-function.h"

#ifndef PARAC_MODULES_LIBRARY_H
#define PARAC_MODULES_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Macros --------------------------------------------------------------------------------------------------------

/// The current release identifier
#define __parac "0.1.dev5"
/// Indicates the current library version being a development version
#define __parac_dev true
/// Indicates the current library version being a stable version
#define __parac_stable false

#ifdef __cplusplus
}
#endif

#endif//PARAC_MODULES_LIBRARY_H

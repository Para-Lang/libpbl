/// @file pbl.c
/// @brief Main file for the Para Base Library (Static C library)
/// Styling and naming are similar to the Google C++ style guide
/// @see https://google.github.io/styleguide/cppguide.html
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

// Parent Header for this file
#include <libpbl/pbl.h>

// ---- Functions Definitions -----------------------------------------------------------------------------------------

void PblAbortWithCriticalError(int exit_code, const char *string, const int line, const char* file_name) {
  fprintf(stderr, "Traceback: \n File \"%s\", line %i", file_name, line);
  fprintf(stderr, "CRITICAL ERR [Para]: %s", string);
  exit(exit_code);
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

/// @file pbl-main.c
/// @brief Main Functions, types and macros used inside the Para. This file includes no other Para headers, and
/// serves as the base for the entire base-lib implementation.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

// Parent Header for this file
#include <libpbl/pbl-main.h>

// ---- Functions Definitions -----------------------------------------------------------------------------------------

void PblThrowCriticalError(int exit_code, const char *string, const int line, const char* file_name) {
  fprintf(stderr, "%s", string);
  exit(exit_code);
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

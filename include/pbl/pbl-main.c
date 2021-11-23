/// @file pbl-main.c
/// @brief Main Functions, types and macros used inside the Para-C. This file includes no other Para-C headers, and
/// serves as the base for the entire base-lib implementation.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#include "pbl-main.h"

void PblAbortWithCriticalError(int exit_code, const char* string) {
  fprintf(stderr, "%s", string);
  exit(exit_code);
}

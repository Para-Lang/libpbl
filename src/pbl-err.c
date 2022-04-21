/**
 * @file pbl-err.c
 * @brief Error handling for runtime errors. This is not the same as exceptions and is purely intended for errors in
 * the C environment.
 * @author Luna Klatzer
 * @date 2021-11-23
 * @copyright Copyright (c) 2021 - 2022
 */

// Parent Header for this file
#include <libpbl/core/pbl-core.h>
#include <libpbl/pbl-err.h>

PBL_INIT_FILE(pbl_err);
PBL_INIT_GLOBALS{};

// ---- Functions Definitions -----------------------------------------------------------------------------------------

void PblThrowCriticalError(int exit_code, const char *string, const int line, const char *file_name) {
  fprintf(stderr, "Traceback: \n File \"%s\", line %i \n", file_name, line);
  fprintf(stderr, "CRITICAL ERR [Para]: %s", string);
  exit(exit_code);
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

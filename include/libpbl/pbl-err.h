/// @file pbl-err.h
/// @brief Error handling for runtime errors. This is not the same as exceptions and is purely intended for errors in
/// the C environment.
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

#ifndef PBL_LIB_MAIN_H
#define PBL_LIB_MAIN_H

// ---- Functions Definitions -----------------------------------------------------------------------------------------
/**
 * @brief Aborts the current program with the specified 'exit_code' and logs the error message
 * @param exit_code The exit code that should be used when exiting the program
 * @param string The string that should be printed out
 * @param line The line where the error happened
 * @param file_name The file where the error happened
 */
void PblThrowCriticalError(int exit_code, const char *string, const int line, const char* file_name);

// ---- End of Function Definitions -----------------------------------------------------------------------------------

#endif//PBL_LIB_MAIN_H

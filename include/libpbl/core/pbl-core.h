/// @file pbl-core.h
/// @brief Para Core headers that are always included when using Para or any specific para header.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022
#pragma once

// Including Headers that are required throughout the entire PBL Library
#ifdef __cplusplus
#include <cstdbool>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#else
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#endif

#include "./pbl-mem.h"
#include "./pbl-meta-types.h"
#include "./pbl-type-list.h"
#include "./pbl-file-setup.h"
#include "./pbl-types.h"

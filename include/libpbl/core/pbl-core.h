/**
 * @file pbl-core.h
 * @brief Para Core headers that are always included when using Para or any specific para header.
 * @author Luna Klatzer
 * @copyright Copyright (c) 2021 - 2022
 */
#pragma once

// Including Headers that are required throughout the entire PBL Library
#ifdef __cplusplus
#include <cstdarg>
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#else
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#endif

#include "./pbl-file-setup.h"
#include "./pbl-mem.h"
#include "./pbl-meta-types.h"
#include "./pbl-type-list.h"
#include "./pbl-types.h"

/**
 * @file pbl-any.h
 * @brief Implementation header for the any type, which allows values to be dynamically allocated and converted using
 * pre-defined conversion functions.
 * @author Luna Klatzer
 * @copyright Copyright (c) 2021 - 2022
 */

#pragma once

// General Required Header Inclusion
#include "../core/pbl-core.h"
#include "./pbl-string.h"

#ifndef PBL_LIB_ANY_H
#define PBL_LIB_ANY_H

#ifdef __cplusplus
extern "C" {
#endif

PBL_INIT_HEADER(pbl_any);

// ---- Exception Implementation --------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space).
 * @returns The usable size in bytes of the PBL Long Double type.
 */
#define PblAny_T_Size (sizeof(void *) + sizeof(PblString_T *) + sizeof(PblSize_T *))
/**
 * @brief Returns the declaration default for the type 'PblAny_T'.
 */
#define PblAny_T_DeclDefault PBL_TYPE_DECL_VAL(PblAny_T)
/**
 * @brief Returns the definition default for the type 'PblAny_T', where the children have not been set yet and only
 * the value itself 'exists' already.
 */
#define PblAny_T_DefDefault PBL_TYPE_DEF_VAL(PblAny_T, {.val = NULL, .type = NULL, .byte_size = NULL})

typedef struct PblAny_Base {
  void *val;
  PblType_T *type;
  PblSize_T *byte_size;
} PblAny_T_Base;

/**
 * @brief Any implementation, which allows for a dynamic allocation, casting and transformation of a type.
 */
typedef struct PblAny {
  PBL_TYPE_DEF_HELPER(PblAny_T_Base);
} PblAny_T;

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/**
 * @brief Allocates and fetches a new PblAny_T and passes the value onto it.
 * @param val The void* value that shall be assigned to the PblAny_T type.
 * @param size The size of the value to properly determine the size and the owned memory.
 * @return The new PblAny_T instance.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblAny_T *PblGetAnyT(void *val, PblType_T *type);

/**
 * @brief Force-deallocates the entire any-type
 */
__attribute__((unused)) PblNone_T PblDeallocateAnyType(PblAny_T *val);

// ---- End of Functions Definitions ----------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_ANY_H

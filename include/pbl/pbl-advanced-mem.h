/// @file pbl-advanced-mem.c
/// @brief Advanced memory handling and management, which is separate from the base pbl-mem.h as that implements only
/// the most basic functions.
/// @author Luna-Klatzer
/// @date 2021-12-09
/// @copyright Copyright (c) 2021

#include "./pbl-mem.h"
#include "./pbl-types.h"
#include "./pbl-any.h"

#ifndef PBL_INCLUDE_ADVANCED_MEM_H_
#define PBL_INCLUDE_ADVANCED_MEM_H_

// TODO! Implement these types

/**
 * @brief Uses 'PblMemCpy()' from 'pbl-mem.h' to copy memory from a type to a destination. This is intended to be used
 * as a safety function, which will always get the size from the appropriate size. This though means this function is
 * only able to be used with Pbl-Types, as it requires the meta-data of the types.
 *
 * This function automatically fetches the types from the any type. This function will though not check for proper value
 * usage, but simply for size as that could cause a segmentation fault. Meaning it is valid to copy a integer onto
 * a string is valid, as long as both have the same effective size.
 * @param dest The destination where the memory should be copied to
 * @param src The source/origin that should be copied
 * @param type The type that should be used for the type checking
 * @param amount The amount that should be copied
 * @return The pointer of the passed dest variable
 * @note This function will raise an exception if either types are of invalid size (both must be equal). For example
 * copying 4 bytes to a 2 byte variable.
 */
__attribute__((unused)) void* PblSafeMemCpy(PblAny_T* dest, PblAny_T* src, PblUInt_T amount);

/**
 * @brief Uses 'PblMemCpy()' from 'pbl-mem.h' to copy memory from a type to a destination. This is intended to be used
 * as a safety function, which will always get the size from the appropriate size. This though means this function is
 * only able to be used with Pbl-Types, as it requires the meta-data of the types.
 * @param dest The destination where the memory should be copied to
 * @param src The source/origin that should be copied
 * @param type The type that should be used for the type checking
 * @param amount The amount that should be copied
 * @return The pointer of the passed dest variable
  * @note This function will raise an exception if either types are of invalid size (both must be equal). For example
  * copying 4 bytes to a 2 byte variable.
 */
__attribute__((unused)) void* PblTypedMemCpy(void* dest, const void * src, PblType_T * dest_type, PblType_T * src_type, PblUInt_T amount);

#endif//PBL_INCLUDE_ADVANCED_MEM_H_

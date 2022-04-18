/// @file pbl-mem.h
/// @brief Para memory management and handling implementation based on `malloc.h` and `gc.h` (Hans-J. Boehm garbage
/// collector)
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

#pragma once

// Including the required Garbage Collector, which this header intends to implement and utilise
#include "gc.h"

// General Required Header Inclusion
#include "libpbl/pbl-err.h"

#ifndef PBL_LIB_MEM_H
#define PBL_LIB_MEM_H

#ifdef __cplusplus
extern "C" {
#endif

// If the overwrite macro is defined, overwrite the default function names
#ifdef PBL_OVERWRITE_DEFAULT_ALLOC_FUNCTIONS
#define malloc(args...) PblMalloc(args)
#define free(args...) PblFree(args)
#define realloc(args...) PblRealloc(args)
#endif

// If debug is defined, print additional GC stats
#ifdef PBL_DEBUG
#define GC_PRINT_STATS
#endif

// If verbose debug is defined, print additional verbose GC stats
#ifdef PBL_DEBUG_VERBOSE
#define GC_PRINT_VERBOSE_STATS
#endif

// ---- Helper Macros -------------------------------------------------------------------------------------------------

/// @brief Logs the entered error / string and aborts the program with the exit status '1'
#define PBL_LOG_MEM_ERR(str, line, file_name) PblThrowCriticalError(1, str, line, file_name)

/// @brief Logs an error for receiving 'NULL' as a return from memory functions.
#define PBL_MEM_OPERATION_RET_NULL_ERR(line, file_name) PBL_LOG_MEM_ERR("Failed to cpy memory (Received NULL)", line, file_name);

/// @brief Logs an error for attempting to copy to an invalid memory address (NULL) and aborts with exit status '1'
#define PBL_NULL_CPY_ERR(line, file_name) PBL_LOG_MEM_ERR("Attempted to copy to an invalid memory address (NULL)", line, file_name);

/// @brief Logs an error for attempting to use an invalid pointer address (NULL) and aborts with exit status '1'
#define PBL_ACCESS_NULL_PTR_ERR(line, file_name) PBL_LOG_MEM_ERR("Attempted to access invalid memory address (NULL)", line, file_name);

/// @brief Logs an error for attempting to free an invalid pointer address (NULL) and aborts with exit status '1'
#define PBL_NULL_FREE_ERR(line, file_name) PBL_LOG_MEM_ERR("Attempted to free invalid memory address (NULL)", line, file_name);

/// @brief Logs an error for attempting to realloc an invalid pointer address (NULL) and aborts with exit status '1'
#define PBL_NULL_REALLOC_ERR(line, file_name) PBL_LOG_MEM_ERR("Attempted to re-allocate invalid memory address (NULL)", line, file_name);

// ---- End of Helper Macro -------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/**
 * @brief This is the Pbl equivalent of memcpy(), but in this case additional checking is applied for safety measures.
 * This may be used to copy bytes from one destination to the other, though it should be watched out the byte sizes are
 * properly fetched using sizeof(PBL_TYPE | C_TYPE), as it **only** copies 1 byte at a time, and as such does NOT check
 * for proper sizing.
 *
 * For proper checking you may use 'PblTypedMemCpy' (from 'pbl-advanced-mem.h'), which will copy a type one at a time,
 * and not allow incomplete ones!
 * @param dest The destination where the memory should be copied to
 * @param src The source/origin that should be copied
 * @param bytes The amount of bytes to be copied
 * @return The pointer of the passed dest variable
 */
void *PblMemCpy(void *dest, const void *src, size_t bytes);

/**
 * @brief Validates the pointer given as parameter and checks whether it's save to access, if it's not safe it will
 * crash the program!
 * @param ptr The pointer to check
 * @return The pointer if the check was successful]
 * @note Only use this function to validate whether the pointer is valid for accessing! This function will count NULL
 * as invalid, meaning this should not be used for pointers that will be defined later!
 */
void *PblValPtr(void *ptr);

/**
 * @brief Frees the passed pointer if it is not NULL. Used as the function for __attribute__ (__cleanup__)
 * @param ptr The double-pointer pointing to the local pointer variable
 */
void PblCleanupLocal(void **ptr);

/**
 * @brief Frees the passed value and applies checks to avoid faulty freeing of memory.
 * @param ptr The actual pointer to the memory that should be freed
 * @note This will crash the program if the pointer is invalid!
 */
void PblFree(void *ptr);

/**
 * @brief Allocates the passed value and applies checks to avoid faulty allocations of memory. The allocated variable
 * will not be checked for garbage collection, meaning it has to be manually de-allocated. This is intended for
 * variables that are used globally and will be needed until the end of the program.
 * @param size The size of the memory to allocate
 * @return he pointer returned by the 'GC_MALLOC_UNCOLLECTABLE' call
 * @note This will crash the program if the size of the value is invalid!
 */
__attribute__((unused)) void *PblMallocUncollectable(size_t size);

/**
 * @brief Allocates the passed value and applies checks to avoid faulty allocations of memory.
 * @param size The size of the memory to allocate
 * @return The pointer returned by the 'GC_MALLOC()' call
 * @note This will crash the program if the size of the value is invalid!
 * @warning It is discouraged to directly use this function to allocate memory, unless for explicit cases. For general
 * usage of allocating a type please use 'PBL_DEF_VAR(to_write, type, cleanup...)', which will safely allocate and
 * initialise the value!
 */
void *PblMalloc(size_t size);

/**
 * @brief Allocates an atomic variable - Objects of atomic types are the only objects that are free from data races;
 * that is, they may be modified by two threads concurrently or modified by one and read by another.
 * @param size The size of the memory to allocate
 * @return The pointer returned by the GC atomic malloc call
 * @note This will crash the program if the size of the value is invalid!
 * @warning It is discouraged to directly use this function to allocate memory, unless for explicit cases. For general
 * usage of allocating a type please use 'PBL_DEF_VAR(to_write, type)', which will safely allocate and
 * initialise the value!
 */
__attribute__((unused)) void *PblMallocAtomic(size_t size);

/**
 * @brief Re-allocates the memory to the size given.
 * @param ptr The actual pointer to the memory
 * @param size The size of the memory to allocate
 * @return The pointer returned by the GC realloc call - this should usually be the same pointer, but you should not
 * count on that
 * @note Unlike the low-level GC realloc(), this may not be used to malloc or free memory and it will raise a critical
 * exception if attempted to secure the memory management process
 */
void *PblRealloc(void *ptr, size_t size);

// ---- End of Functions Definitions ----------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_MEM_H

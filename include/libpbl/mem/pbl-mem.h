/// @file pbl-mem.h
/// @brief Para memory management and handling implementation based on `malloc.h` and `gc.h` (Hans-J. Boehm garbage
/// collector)
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#pragma once

// Including the required Garbage Collector, which this header intends to implement and utilise
#include "gc.h"

// General Required Header Inclusion
#include "../pbl-main.h"

#ifndef PBL_MODULES_MEM_H
#define PBL_MODULES_MEM_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- End of Memory Setup -------------------------------------------------------------------------------------------

// ---- Helper Macros -------------------------------------------------------------------------------------------------

/// @brief Logs the entered error / string and aborts the program with the exit status '1'
#define PBL_LOG_MEM_ERR(...) PblAbortWithCriticalError(1, __VA_ARGS__)

/// @brief Logs an error for attempting to copy from an invalid memory address (NULL) and aborts with exit status '1'
#define PBL_LOG_CPY_FROM_NULL_PTR PBL_LOG_MEM_ERR("Para: Attempted to copy from an invalid memory address (NULL)");

/// @brief Logs an error for attempting to copy to an invalid memory address (NULL) and aborts with exit status '1'
#define PBL_LOG_CPY_TO_NULL_PTR PBL_LOG_MEM_ERR("Para: Attempted to copy to an invalid memory address (NULL)");

/// @brief Logs an error for receiving 'NULL' from the call of the C function 'memcpy' and aborts with exit status '1'
#define PBL_LOG_CPY_RECEIVE_NULL_PTR PBL_LOG_MEM_ERR("Para: Failed to cpy memory (Received NULL)");

/// @brief Logs an error for attempting to use an invalid pointer address (NULL) and aborts with exit status '1'
#define PBL_LOG_ACCESS_ERR_NULL_PTR PBL_LOG_MEM_ERR("Para: Attempted to access invalid memory address (NULL)");

/// @brief Logs an error for attempting to free an invalid pointer address (NULL) and aborts with exit status '1'
#define PBL_LOG_FREE_ERR_NULL_PTR PBL_LOG_MEM_ERR("Para: Attempted to free invalid memory address (NULL)");

/// @brief Logs an error for receiving 'NULL' from the call of the GC function 'GC_MALLOC' or 'GC_MALLOC_ATOMIC' and
/// aborts with exit status '1'
#define PBL_LOG_ALLOC_ERR_RECEIVE_NULL_RET PBL_LOG_MEM_ERR("Para: Failed to allocate memory (Received NULL)");

/// @brief Logs an error for attempting to realloc an invalid pointer address (NULL) and aborts with exit status '1'
#define PBL_LOG_REALLOC_ERR_NULL_PTR PBL_LOG_MEM_ERR("Para: Attempted to re-allocate invalid memory address (NULL)");

/// @brief Logs an error for receiving 'NULL' from the call of the GC function 'GC_REALLOC' and aborts with exit status
/// '1'
#define PBL_LOG_REALLOC_ERR_RECEIVE_NULL_RET PBL_LOG_MEM_ERR("Para: Failed to re-allocate memory (Received NULL)");

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
 * usage of allocating a type please use 'PBL_DEFINE_VAR(to_write, type, cleanup...)', which will safely allocate and
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
 * usage of allocating a type please use 'PBL_DEFINE_VAR(to_write, type)', which will safely allocate and
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

#endif//PBL_MODULES_MEM_H

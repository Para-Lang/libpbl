///
/// Para-GC memory management and handling implementation
///
/// @author Luna-Klatzer

#include "gc.h"
#include "./pbl-main.h"
#include "./pbl-types.h"

#ifndef PARAC_MODULES_MEM_H
#define PARAC_MODULES_MEM_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Helper Macro --------------------------------------------------------------------------------------------------

// Log Mem error
#define PBL_LOG_MEM_ERR(...) PblAbortWithCriticalError(1, __VA_ARGS__)

// Ptr-Access
#define PBL_LOG_ACCESS_ERR_NULL_PTR PBL_LOG_MEM_ERR("PARA-C: Attempted to access invalid memory address (NULL)");

// Free
#define PBL_LOG_FREE_ERR_NULL_PTR PBL_LOG_MEM_ERR("PARA-C: Attempted to free invalid memory address (NULL)");

// Alloc
#define PBL_LOG_ALLOC_ERR_NULL_SZ PBL_LOG_MEM_ERR("PARA-C: Attempted to allocate invalid amounts of memory (0)");
#define PBL_LOG_ALLOC_ERR_RECEIVE_NULL_RET PBL_LOG_MEM_ERR("PARA-C: Failed to allocate memory (Received NULL)");

// Re-Alloc
#define PBL_LOG_REALLOC_ERR_NULL_PTR PBL_LOG_MEM_ERR("PARA-C: Attempted to access invalid memory address (NULL)");
#define PBL_LOG_REALLOC_ERR_NULL_SZ PBL_LOG_MEM_ERR("PARA-C: Attempted to re-allocate invalid amounts of memory (0)");
#define PBL_LOG_REALLOC_ERR_RECEIVE_NULL_RET PBL_LOG_MEM_ERR("PARA-C: Failed to re-allocate memory (Received NULL)");

// ---- Helper functions ----------------------------------------------------------------------------------------------

/**
 * @brief Validates the pointer given as parameter and checks whether it's save to access, if it's not safe it will
 * crash the program!
 * @param ptr The pointer to check
 * @return The pointer if the check was successful]
 * @note Only use this function to validate whether the pointer is valid for accessing! This function will count NULL
 * as invalid, meaning this should not be used for pointers that will be defined later!
 */
void* PblValPtr(void* ptr);

/**
 * @brief Frees the passed value and applies checks to avoid faulty freeing of memory.
 * @param ptr The actual pointer to the memory that should be freed
 * @note This will crash the program if the pointer is invalid!
 */
void PblFree(void *ptr);

/**
 * @brief Allocates the passed value and applies checks to avoid faulty allocations of memory.
 * @param size The size of the memory to allocate
 * @return The pointer returned by the GC malloc call
 * @note This will crash the program if the size of the value is invalid!
 */
void* PblMalloc(PblSize_T size);

/**
 * @brief Allocates an atomic variable - Objects of atomic types are the only objects that are free from data races;
 * that is, they may be modified by two threads concurrently or modified by one and read by another.
 * @param size The size of the memory to allocate
 * @return The pointer returned by the GC atomic malloc call
 * @note This will crash the program if the size of the value is invalid!
 */
void* PblMallocAtomic(PblSize_T size);

/**
 * @brief Re-allocates the memory to the size given.
 * @param ptr The actual pointer to the memory
 * @param size The size of the memory to allocate
 * @return The pointer returned by the GC realloc call - this should usually be the same pointer, but you should not
 * count on that
 * @note Unlike the low-level GC realloc(), this may not be used to malloc or free memory and it will raise a critical
 * exception if attempted to secure the memory management process
 */
void* PblRealloc(void* ptr, PblSize_T size);

#ifdef __cplusplus
}
#endif

#endif//PARAC_MODULES_MEM_H

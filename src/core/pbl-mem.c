/// @file pbl-mem.c
/// @brief Para memory management and handling implementation based on `malloc.h` and `gc.h` (Hans-J. Boehm garbage
/// collector)
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

// General Required Header Inclusion
#include "libpbl/core/pbl-mem.h"
#include "libpbl/pbl.h"

// ---- File Setup ----------------------------------------------------------------------------------------------------

PBL_INIT_FILE;
PBL_INIT_GLOBALS{};

// ---- End of File Setup ---------------------------------------------------------------------------------------------

// ---- Memory Setup --------------------------------------------------------------------------------------------------

__attribute__((unused)) __attribute__((constructor(101)))
__attribute__((deprecated("Compiler-Only Function - User Call Invalid!"))) static void
pre__PblInitialiseGarbageCollection(void) {
  GC_INIT();
}

// ---- End of Memory Setup -------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

void *PblMemCpy(void *dest, const void *src, size_t bytes) {
  if (dest == NULL) { PBL_NULL_CPY_ERR(__LINE__, __FILE__) }
  if (src == NULL) { PBL_NULL_CPY_ERR(__LINE__, __FILE__) }

  void *ret_ptr = memcpy(dest, src, bytes);
  if (ret_ptr == NULL) { PBL_MEM_OPERATION_RET_NULL_ERR(__LINE__, __FILE__) }
  return ret_ptr;
}

void *PblValPtr(void *ptr) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) { PBL_ACCESS_NULL_PTR_ERR(__LINE__, __FILE__) }
  return ptr;
}

void PblFree(void *ptr) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) { PBL_NULL_FREE_ERR(__LINE__, __FILE__) }
  GC_FREE(ptr);

  // old pointer is invalid
  ptr = NULL;
}

__attribute__((unused)) void *PblMallocUncollectable(size_t size) {
  // allocating the memory
  void *ptr = GC_MALLOC_UNCOLLECTABLE(size);
  if (ptr == NULL) { PBL_MEM_OPERATION_RET_NULL_ERR(__LINE__, __FILE__) }
  return ptr;
}

void *PblMalloc(size_t size) {
  // allocating the memory
  void *ptr = GC_MALLOC(size);
  if (ptr == NULL) { PBL_MEM_OPERATION_RET_NULL_ERR(__LINE__, __FILE__) }
  return ptr;
}

__attribute__((unused)) void *PblMallocAtomic(size_t size) {
  // allocating the memory
  void *ptr = GC_MALLOC_ATOMIC(size);
  if (ptr == NULL) { PBL_MEM_OPERATION_RET_NULL_ERR(__LINE__, __FILE__) }
  return ptr;
}

void *PblRealloc(void *ptr, size_t size) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) { PBL_NULL_REALLOC_ERR(__LINE__, __FILE__) }

  // re-allocating the memory
  void *new_ptr = GC_REALLOC(ptr, size);
  if (new_ptr == NULL) { PBL_MEM_OPERATION_RET_NULL_ERR(__LINE__, __FILE__) }

  // old pointer is invalid
  if (new_ptr != ptr) ptr = NULL;
  return new_ptr;
}

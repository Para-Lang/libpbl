/// @file pbl-mem.c
/// @brief Para memory management and handling implementation based on `malloc.h` and `gc.h` (Hans-J. Boehm garbage
/// collector)
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

// Parent Header for this file
#include <libpbl/mem/pbl-mem.h>

// General Required Header Inclusion
#include <libpbl/types/pbl-types.h>

// ---- Memory Setup --------------------------------------------------------------------------------------------------

__attribute__((unused))
__attribute__((constructor))
__attribute__((deprecated("Compiler-Only Function - User Call Invalid!")))
static void PBL_CONSTRUCTOR_MEM_INIT(void) {
  GC_INIT();
}

// ---- End of Memory Setup -------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

void *PblMemCpy(void *dest, const void *src, size_t bytes) {
  if (dest == NULL) {
    PBL_LOG_CPY_FROM_NULL_PTR
  }
  if (src == NULL) {
    PBL_LOG_CPY_TO_NULL_PTR
  }

  void *ret_ptr = memcpy(dest, src, bytes);
  if (ret_ptr == NULL) {
    PBL_LOG_CPY_RECEIVE_NULL_PTR
  }
  return ret_ptr;
}

void *PblValPtr(void *ptr) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) {
    PBL_LOG_ACCESS_ERR_NULL_PTR
  }
  return ptr;
}

void PblFree(void *ptr) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) {
    PBL_LOG_FREE_ERR_NULL_PTR
  }
  GC_FREE(ptr);

  // old pointer is invalid
  ptr = NULL;
}

__attribute__((unused)) void *PblMallocUncollectable(size_t size) {
  // allocating the memory
  void *ptr = GC_MALLOC_UNCOLLECTABLE(size);
  if (ptr == NULL) {
    PBL_LOG_ALLOC_ERR_RECEIVE_NULL_RET
  }
  return ptr;
}

void *PblMalloc(size_t size) {
  // allocating the memory
  void *ptr = GC_MALLOC(size);
  if (ptr == NULL) {
    PBL_LOG_ALLOC_ERR_RECEIVE_NULL_RET
  }
  return ptr;
}

__attribute__((unused)) void *PblMallocAtomic(size_t size) {
  // allocating the memory
  void *ptr = GC_MALLOC_ATOMIC(size);
  if (ptr == NULL) {
    PBL_LOG_ALLOC_ERR_RECEIVE_NULL_RET
  }
  return ptr;
}

void *PblRealloc(void *ptr, size_t size) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) {
    PBL_LOG_REALLOC_ERR_NULL_PTR
  }

  // re-allocating the memory
  void *new_ptr = GC_REALLOC(ptr, size);
  if (new_ptr == NULL) {
    PBL_LOG_REALLOC_ERR_RECEIVE_NULL_RET
  }

  // old pointer is invalid
  if (new_ptr != ptr) ptr = NULL;
  return new_ptr;
}

///
/// Para-C memory management and handling implementation
///
/// @author Luna-Klatzer

#include "./pbl-mem.h"
#include "./pbl-types.h"

void* PblMemCpy(void* dest, const void * src, size_t bytes) {
  if (dest == NULL) { PBL_LOG_CPY_FROM_NULL_PTR }
  if (src == NULL) { PBL_LOG_CPY_TO_NULL_PTR }

  void* ret_ptr = memcpy(dest, src, bytes);
  if (ret_ptr == NULL) { PBL_LOG_CPY_RECEIVE_NULL_PTR }
  return ret_ptr;
}

void *PblValPtr(void *ptr) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) { PBL_LOG_ACCESS_ERR_NULL_PTR }
  return ptr;
}

void PblFree(void *ptr) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) { PBL_LOG_FREE_ERR_NULL_PTR }
  GC_FREE(ptr);

  // old pointer is invalid
  ptr = NULL;
}

void *PblMalloc(size_t size) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (size <= 0) {
    PBL_LOG_ALLOC_ERR_NULL_SZ
  }

  // allocating the memory
  void *ptr = GC_MALLOC(size);
  if (ptr == NULL) { PBL_LOG_ALLOC_ERR_RECEIVE_NULL_RET }
  return ptr;
}

void *PblMallocAtomic(size_t size) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (size <= 0) {
    PBL_LOG_ALLOC_ERR_NULL_SZ
  }

  // allocating the memory
  void *ptr = GC_MALLOC_ATOMIC(size);
  if (ptr == NULL) { PBL_LOG_ALLOC_ERR_RECEIVE_NULL_RET }
  return ptr;
}

void *PblRealloc(void *ptr, size_t size) {
  // Crash on invalid input - Don't bother raising exceptions on this low-level area
  if (ptr == NULL) { PBL_LOG_REALLOC_ERR_NULL_PTR }
  if (size <= 0) { PBL_LOG_REALLOC_ERR_NULL_SZ }

  // re-allocating the memory
  void *new_ptr = GC_REALLOC(ptr, size);
  if (new_ptr == NULL) { PBL_LOG_REALLOC_ERR_RECEIVE_NULL_RET }

  // old pointer is invalid
  if (new_ptr != ptr) ptr = NULL;
  return new_ptr;
}

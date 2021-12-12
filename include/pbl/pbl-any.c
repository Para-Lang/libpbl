/// @file pbl-any.c
/// @brief Implementation for the any type, which allows values to be dynamically allocated and converted using
/// pre-defined conversion functions.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#include "pbl-any.h"

// ---- Helper Functions ----------------------------------------------------------------------------------------------

PblAny_T* PblGetAnyT(void* val, PblType_T * type) {
  // Validate the pointer for safety measures
  val = PblValPtr(val);

  PBL_DEFINE_VAR(ptr, PblAny_T);

  // copying the memory to the destination address (the new type)
  ptr->actual.val = PblMalloc(type->size);
  PblMemCpy(ptr->actual.val, val, type->size);

  // initialising the remaining properties
  ptr->actual.byte_size = PblGetSizeT(type->size);
  ptr->actual.type = type;

  return ptr;
}

PblVoid_T PblDeallocateAnyType(PblAny_T *val) {
  // Validate the pointer for safety measures
  val = PblValPtr(val);

  if (val->actual.val != NULL) {
    PblFree(val->actual.val);
    val->actual.val = NULL;
  }
  if (val->actual.byte_size != NULL) {
    PblFree(val->actual.byte_size);
  }

  // Note, we don't deallocate type, as it's a global pointer which **must** be kept alive

  *val = PblAny_T_DeclDefault;
  PblFree(val);
  return PblVoid_T_DeclDefault;
}

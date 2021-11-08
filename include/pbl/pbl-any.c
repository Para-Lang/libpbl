///
/// The any type, which allows values to be dynamically allocated and converted with ease.
/// The any type, will track it's type, so that direct conversion is easier.
///
/// @author Luna-Klatzer

#include "pbl-any.h"

PblAny_T* PblGetAnyT(void* val, size_t bytes) {
  // Validate the pointer for safety measures
  val = PblValPtr(val);

  PBL_ALLOC_DEFINITION(ptr, PblAny_T);

  // copying the memory to the destination address (the new type)
  ptr->actual.val = PblMalloc(bytes);
  PblMemCpy(ptr->actual.val, val, bytes);

  // initialising the remaining properties
  ptr->actual.byte_size = PblGetSizeT(bytes);
  // NI = not implemented! type-dict in work!
  ptr->actual.type_name = PblGetStringT("NI");

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
  if (val->actual.type_name != NULL) {
    PblDeallocateStringT(val->actual.type_name);
    val->actual.type_name = NULL;
  }

  *val = PblAny_T_DeclDefault;
  PblFree(val);
  return PblVoid_T_DeclDefault;
}

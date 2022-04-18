/// @file pbl-any.c
/// @brief Implementation for the any type, which allows values to be dynamically allocated and converted using
/// pre-defined conversion functions.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

// Parent Header for this file
#include <libpbl/pbl.h>
#include <libpbl/types/pbl-any.h>

// ---- File Setup ----------------------------------------------------------------------------------------------------

PBL_INIT_FILE;
PBL_INIT_GLOBALS { PBL_REGISTER_TYPE(&LOCAL_TYPE_LIST, PblAny_T, "any", false, true); };

// ---- End of File Setup ---------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

__attribute__((unused)) PblAny_T *PblGetAnyT(void *val, PblType_T *type) {
  // Validate the pointer for safety measures
  val = PblValPtr(val);

  PBL_DEF_VAR(ptr, PblAny_T);

  // Copying the memory to the destination address (the new type)
  ptr->actual.val = PblMalloc(type->actual_size);
  PblMemCpy(ptr->actual.val, val, type->actual_size);

  // Initialising the remaining properties
  ptr->actual.byte_size = PblGetSizeT(type->actual_size);
  ptr->actual.type = type;

  return ptr;
}

__attribute__((unused)) PblVoid_T PblDeallocateAnyType(PblAny_T *val) {
  // Validate the pointer for safety measures
  val = PblValPtr(val);

  if (val->actual.val != NULL) {
    PblFree(val->actual.val);
    val->actual.val = NULL;
  }
  if (val->actual.byte_size != NULL) { PblFree(val->actual.byte_size); }

  // Note, we don't deallocate type, as it's a global pointer which **must** be kept alive

  *val = PblAny_T_DeclDefault;
  PblFree(val);
  return PblVoid_T_DeclDefault;
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

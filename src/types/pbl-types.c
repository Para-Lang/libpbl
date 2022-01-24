/// @file pbl-types.c
/// @brief Para Base Types Implementation, which contains handler macros, conversion functions, default declaration,
/// default definition types and default size macros. This also includes meta-data tracking based on the
/// 'PblMetaVarCtx_T' type.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

// Parent Header for this file
#include <libpbl/types/pbl-types.h>

// ---- Initialisation of the global type list ------------------------------------------------------------------------

const PblType_T *PblCreateNewType(const size_t size, const void *type_template, const char *name,
                                  const bool user_defined, const bool definable) {
  PblType_T *type = PblMalloc(sizeof(PblType_T));
  *type = (PblType_T) {
    .actual_size =size,
    .type_template=type_template,
    .name=name,
    .user_defined=user_defined,
    .definable=definable
  };
  return type;
}

void PblInitTypeList(PblTypeList_T* list) {
  // Default size on init is 50
  list->t_items = PblMalloc(sizeof(PblType_T) * 50);
  list->alloc_len = 50;
}

void PblAddTypeToTypeList(PblTypeList_T* list, const PblType_T* type) {
  // If there is not enough space to add a new item, extend the list
  if (list->alloc_len == list->t_amount) {
    list->t_items = PblRealloc(
      list->t_items,
      sizeof(PblType_T *) * (list->alloc_len * 50)
      );
    list->alloc_len += 50;
  }
  list->t_items[list->t_amount] = type;
  list->t_amount++;
}

// ---- End of Initialisation of the global type list -----------------------------------------------------------------

// ---- Initialisation of the Local types -----------------------------------------------------------------------------

PBL_INIT_LOCAL_TYPE_LIST;
LOCAL_TYPE_LIST_CONSTRUCTOR {
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblVoid_T, "void", false, false);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblPointer_T, "ptr", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblSize_T, "size", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblBool_T, "bool", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblChar_T, "char", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblUChar_T, "uchar", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblShort_T, "int", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblUShort_T, "ushort", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblInt_T, "int", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblUInt_T, "uint", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblLong_T, "long", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblULong_T, "ulong", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblLongLong_T, "longlong", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblULongLong_T, "ulonglong", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblFloat_T, "float", false, true);
  PBL_REGISTER_LOCAL_TYPE(&LOCAL_TYPE_LIST, PblDouble_T, "double", false, true);
};

// ---- Functions Definitions -----------------------------------------------------------------------------------------

__attribute__((unused)) PblPointer_T *PblGetPointerT(void* val, PblType_T* type) {
  struct PblPointer_Base struct_type = {
      .p_void = val,
      .p_type = type
  };
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblPointer_T, struct_type, struct PblPointer_Base);
}

PblBool_T *PblGetBoolT(bool val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblBool_T, val, bool);
}

__attribute__((unused)) PblSize_T *PblGetSizeT(size_t val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblSize_T, val, size_t);
}

__attribute__((unused)) PblChar_T *PblGetCharT(signed char val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblChar_T, val, signed char);
}

__attribute__((unused)) PblUChar_T *PblGetUCharT(unsigned char val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUChar_T, val, unsigned char);
}

__attribute__((unused)) PblShort_T *PblGetShortT(signed short val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblShort_T, val, signed short);
}

__attribute__((unused)) PblUShort_T *PblGetUShortT(unsigned short val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUShort_T, val, unsigned short);
}

__attribute__((unused)) PblInt_T *PblGetIntT(signed int val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblInt_T, val, signed int);
}

__attribute__((unused)) PblUInt_T *PblGetUIntT(unsigned int val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUInt_T, val, unsigned int);
}

__attribute__((unused)) PblLong_T *PblGetLongT(signed long val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblLong_T, val, signed long);
}

__attribute__((unused)) PblULong_T *PblGetULongT(unsigned long val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblULong_T, val, unsigned long);
}

__attribute__((unused)) PblLongLong_T *PblGetLongLongT(signed long long val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblLongLong_T, val, signed long long);
}

__attribute__((unused)) PblULongLong_T *PblGetULongLongT(unsigned long long val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblULongLong_T, val, unsigned long long);
}

__attribute__((unused)) PblFloat_T *PblGetFloatT(float val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblFloat_T, val, float);
}

__attribute__((unused)) PblDouble_T *PblGetDoubleT(double val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblDouble_T, val, double);
}

__attribute__((unused)) PblLongDouble_T *PblGetLongDoubleT(long double val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblLongDouble_T, val, long double);
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

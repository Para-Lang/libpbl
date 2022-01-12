/// @file pbl-types.c
/// @brief Para-C Base Types Implementation, which contains handler macros, conversion functions, default declaration,
/// default definition types and default size macros. This also includes meta-data tracking based on the
/// 'PblMetaVarCtx_T' type.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

// Parent Header for this file
#include <libpbl/types/pbl-types.h>

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

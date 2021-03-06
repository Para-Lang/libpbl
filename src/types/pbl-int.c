/// @file pbl-int.c
/// @brief Int Type Implementation based on stdint.h
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

// Parent Header for this file
#include <libpbl/types/pbl-int.h>

// ---- Functions Definitions -----------------------------------------------------------------------------------------

__attribute__((unused)) PblInt8_T *PblGetInt8T(int8_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblInt8_T, val, int8_t)}

__attribute__((unused)) PblUInt8_T *PblGetUInt8T(uint8_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUInt8_T, val, uint8_t)}

__attribute__((unused)) PblInt16_T *PblGetInt16T(int16_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblInt16_T, val, int16_t)}

__attribute__((unused)) PblUInt16_T *PblGetUInt16T(uint16_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUInt16_T, val, uint16_t)}

__attribute__((unused)) PblInt32_T *PblGetInt32T(int32_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblInt32_T, val, int32_t)}

__attribute__((unused)) PblUInt32_T *PblGetUInt32T(uint32_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUInt32_T, val, uint32_t)}

__attribute__((unused)) PblInt64_T *PblGetInt64T(int64_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblInt64_T, val, int64_t)}

__attribute__((unused)) PblUInt64_T *PblGetUInt64T(uint64_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUInt64_T, val, uint64_t)}

__attribute__((unused)) PblLeastInt8_T *PblGetLeastInt8T(int_least8_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblLeastInt8_T, val, int_least8_t)}

__attribute__((unused)) PblULeastInt8_T *PblGetULeastInt8T(uint_least8_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblULeastInt8_T, val, uint_least8_t)}

__attribute__((unused)) PblLeastInt16_T *PblGetLeastInt16T(int_least16_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblLeastInt16_T, val, int_least16_t)}

__attribute__((unused)) PblULeastInt16_T *PblGetULeastInt16T(uint_least16_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblULeastInt16_T, val, uint_least16_t)}

__attribute__((unused)) PblLeastInt32_T *PblGetLeastInt32T(int_least32_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblLeastInt32_T, val, int_least32_t)}

__attribute__((unused)) PblULeastInt32_T *PblGetULeastInt32T(uint_least32_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblULeastInt32_T, val, uint_least32_t)}

__attribute__((unused)) PblLeastInt64_T *PblGetLeastInt64T(int_least64_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblLeastInt64_T, val, int_least64_t)}

__attribute__((unused)) PblULeastInt64_T *PblGetULeastInt64T(uint_least64_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblULeastInt64_T, val, uint_least64_t)}

__attribute__((unused)) PblFastInt8_T *PblGetFastInt8T(int_fast8_t val){PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblFastInt8_T, val, int_fast8_t)}

__attribute__((unused)) PblUFastInt8_T *PblGetUFastInt8T(uint_fast8_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUFastInt8_T, val, uint_fast8_t)}

__attribute__((unused)) PblFastInt16_T *PblGetFastInt16T(int_fast16_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblFastInt16_T, val, int_fast16_t)}

__attribute__((unused)) PblUFastInt16_T *PblGetUFastInt16T(uint_fast16_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUFastInt16_T, val, uint_fast16_t)}

__attribute__((unused)) PblFastInt32_T *PblGetFastInt32T(int_fast32_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblFastInt32_T, val, int_fast32_t)}

__attribute__((unused)) PblUFastInt32_T *PblGetUFastInt32T(uint_fast32_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUFastInt32_T, val, uint_fast32_t)}

__attribute__((unused)) PblFastInt64_T *PblGetFastInt64T(int_fast64_t val){
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblFastInt64_T, val, int_fast64_t)}

__attribute__((unused)) PblUFastInt64_T *PblGetUFastInt64T(uint_fast64_t val) {
  PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(PblUFastInt64_T, val, uint_fast64_t)
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

/**
 * @file pbl-int.h
 * @brief Int Type Implementation based on stdint.h
 * @author Luna Klatzer
 * @copyright Copyright (c) 2021 - 2022
 */

#pragma once

// Including the base <stdint.h> which this header intends to implement
#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

// General Required Header Inclusion
#include "../core/pbl-core.h"

#ifndef PBL_LIB_INT_H
#define PBL_LIB_INT_H

#ifdef __cplusplus
extern "C" {
#endif

PBL_INIT_HEADER(pbl_int);

// ---- Exact Int -----------------------------------------------------------------------------------------------------

// ---- Int8 ----------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Int8 type.
 */
#define PblInt8_T_Size sizeof(int8_t)
/**
 * @brief Returns the declaration default for the type 'PblInt8_T'.
 */
#define PblInt8_T_DeclDefault PBL_TYPE_DECL_VAL(PblInt8_T)
/**
 * @brief Returns the definition default for the type 'PblInt8_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblInt8_T_DefDefault PBL_TYPE_DEF_VAL(PblInt8_T, 0)

/**
 * @brief PBL Int8 implementation.
 */
typedef struct PblInt8 {
  PBL_TYPE_DEF_HELPER(int8_t);
} PblInt8_T;

// ---- End of Int8 ---------------------------------------------------------------------------------------------------

// ---- UInt8 ---------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblUInt8_T_Size sizeof(uint8_t)
/**
 * @brief Returns the declaration default for the type 'PblUInt8_T'.
 */
#define PblUInt8_T_DeclDefault PBL_TYPE_DECL_VAL(PblUInt8_T)
/**
 * @brief Returns the definition default for the type 'PblUInt8_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblUInt8_T_DefDefault PBL_TYPE_DEF_VAL(PblUInt8_T, 0)

/**
 * @brief PBL Unsigned Int8 implementation.
 */
typedef struct PblUInt8 {
  PBL_TYPE_DEF_HELPER(uint8_t);
} PblUInt8_T;

// ---- End of UInt8 --------------------------------------------------------------------------------------------------

// ---- Int16 ---------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Int16 type.
 */
#define PblInt16_T_Size sizeof(int16_t)
/**
 * @brief Returns the declaration default for the type 'PblInt16_T'.
 */
#define PblInt16_T_DeclDefault PBL_TYPE_DECL_VAL(PblInt16_T)
/**
 * @brief Returns the definition default for the type 'PblInt16_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblInt16_T_DefDefault PBL_TYPE_DEF_VAL(PblInt16_T, 0)

/**
 * @brief PBL Int16 implementation.
 */
typedef struct PblInt16 {
  PBL_TYPE_DEF_HELPER(int16_t);
} PblInt16_T;

// ---- End of Int16 --------------------------------------------------------------------------------------------------

// ---- UInt16 --------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblUInt16_T_Size sizeof(uint16_t)
/**
 * @brief Returns the declaration default for the type 'PblUInt16_T'.
 */
#define PblUInt16_T_DeclDefault PBL_TYPE_DECL_VAL(PblUInt16_T)
/**
 * @brief Returns the definition default for the type 'PblUInt16_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblUInt16_T_DefDefault PBL_TYPE_DEF_VAL(PblUInt16_T, 0)

/**
 * @brief PBL UInt16 implementation.
 */
typedef struct PblUInt16 {
  PBL_TYPE_DEF_HELPER(uint16_t);
} PblUInt16_T;

// ---- End of UInt16 -------------------------------------------------------------------------------------------------

// ---- Int32 ---------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Int32 type.
 */
#define PblInt32_T_Size sizeof(int32_t)
/**
 * @brief Returns the declaration default for the type 'PblInt32_T'.
 */
#define PblInt32_T_DeclDefault PBL_TYPE_DECL_VAL(PblInt32_T)
/**
 * @brief Returns the definition default for the type 'PblInt32_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblInt32_T_DefDefault PBL_TYPE_DEF_VAL(PblInt32_T, 0)

/**
 * @brief PBL Int32 implementation.
 */
typedef struct PblInt32 {
  PBL_TYPE_DEF_HELPER(int32_t);
} PblInt32_T;

// ---- End of Int32 --------------------------------------------------------------------------------------------------

// ---- UInt32 --------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblUInt32_T_Size sizeof(uint32_t)
/**
 * @brief Returns the declaration default for the type 'PblUInt32_T'.
 */
#define PblUInt32_T_DeclDefault PBL_TYPE_DECL_VAL(PblUInt32_T)
/**
 * @brief Returns the definition default for the type 'PblUInt32_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblUInt32_T_DefDefault PBL_TYPE_DEF_VAL(PblUInt32_T, 0)

/**
 * @brief PBL UInt32 implementation.
 */
typedef struct PblUInt32 {
  PBL_TYPE_DEF_HELPER(uint32_t);
} PblUInt32_T;

// ---- End of UInt32 -------------------------------------------------------------------------------------------------

// ---- Int64 ---------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Int64 type.
 */
#define PblInt64_T_Size sizeof(int64_t)
/**
 * @brief Returns the declaration default for the type 'PblInt64_T'.
 */
#define PblInt64_T_DeclDefault PBL_TYPE_DECL_VAL(PblInt64_T)
/**
 * @brief Returns the definition default for the type 'PblInt64_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblInt64_T_DefDefault PBL_TYPE_DEF_VAL(PblInt64_T, 0)

/**
 * @brief PBL Int64 implementation.
 */
typedef struct PblInt64 {
  PBL_TYPE_DEF_HELPER(int64_t);
} PblInt64_T;

// ---- End of Int64 --------------------------------------------------------------------------------------------------

// ---- UInt64 --------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblUInt64_T_Size sizeof(uint64_t)
/**
 * @brief Returns the declaration default for the type 'PblUInt64_T'.
 */
#define PblUInt64_T_DeclDefault PBL_TYPE_DECL_VAL(PblUInt64_T)
/**
 * @brief Returns the definition default for the type 'PblUInt64_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblUInt64_T_DefDefault PBL_TYPE_DEF_VAL(PblUInt64_T, 0)

/**
 * @brief PBL UInt64 implementation.
 */
typedef struct PblUInt64 {
  PBL_TYPE_DEF_HELPER(uint64_t);
} PblUInt64_T;

// ---- End of UInt64 -------------------------------------------------------------------------------------------------

// ---- End of Exact Int ----------------------------------------------------------------------------------------------

// ---- Least Int -----------------------------------------------------------------------------------------------------

// ---- LeastInt8 -----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed LeastInt8 type.
 */
#define PblLeastInt8_T_Size sizeof(int_least8_t)
/**
 * @brief Returns the declaration default for the type 'PblLeastInt8_T'.
 */
#define PblLeastInt8_T_DeclDefault PBL_TYPE_DECL_VAL(PblLeastInt8_T)
/**
 * @brief Returns the definition default for the type 'PblLeastInt8_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblLeastInt8_T_DefDefault PBL_TYPE_DEF_VAL(PblLeastInt8_T, 0)

/**
 * @brief PBL LeastInt8 implementation.
 */
typedef struct PblLeastInt8 {
  PBL_TYPE_DEF_HELPER(int_least8_t);
} PblLeastInt8_T;

// ---- End of LeastInt8 ----------------------------------------------------------------------------------------------

// ---- ULeastInt8 ----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblULeastInt8_T_Size sizeof(uint_least8_t)
/**
 * @brief Returns the declaration default for the type 'PblULeastInt8_T'.
 */
#define PblULeastInt8_T_DeclDefault PBL_TYPE_DECL_VAL(PblULeastInt8_T)
/**
 * @brief Returns the definition default for the type 'PblULeastInt8_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblULeastInt8_T_DefDefault PBL_TYPE_DEF_VAL(PblULeastInt8_T, 0)

/**
 * @brief PBL ULeastInt8 implementation.
 */
typedef struct PblULeastInt8 {
  PBL_TYPE_DEF_HELPER(uint_least8_t);
} PblULeastInt8_T;

// ---- End of ULeastInt8 ---------------------------------------------------------------------------------------------

// ---- LeastInt16 ----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed LeastInt16 type.
 */
#define PblLeastInt16_T_Size sizeof(int_least16_t)
/**
 * @brief Returns the declaration default for the type 'PblLeastInt16_T'.
 */
#define PblLeastInt16_T_DeclDefault PBL_TYPE_DECL_VAL(PblLeastInt16_T)
/**
 * @brief Returns the definition default for the type 'PblLeastInt16_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblLeastInt16_T_DefDefault PBL_TYPE_DEF_VAL(PblLeastInt16_T, 0)

/**
 * @brief PBL LeastInt16 implementation.
 */
typedef struct PblLeastInt16 {
  PBL_TYPE_DEF_HELPER(int_least16_t);
} PblLeastInt16_T;

// ---- End of PblLeastInt16 ------------------------------------------------------------------------------------------

// ---- ULeastInt16 ---------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblULeastInt16_T_Size sizeof(uint_least16_t)
/**
 * @brief Returns the declaration default for the type 'PblULeastInt16_T'.
 */
#define PblULeastInt16_T_DeclDefault PBL_TYPE_DECL_VAL(PblULeastInt16_T)
/**
 * @brief Returns the definition default for the type 'PblULeastInt16_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblULeastInt16_T_DefDefault PBL_TYPE_DEF_VAL(PblULeastInt16_T, 0)

/**
 * @brief PBL ULeastInt16 implementation.
 */
typedef struct PblULeastInt16 {
  PBL_TYPE_DEF_HELPER(uint_least16_t);
} PblULeastInt16_T;

// ---- End of PblULeastInt16 -----------------------------------------------------------------------------------------

// ---- LeastInt32 ----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed LeastInt32 type.
 */
#define PblLeastInt32_T_Size sizeof(int_least32_t)
/**
 * @brief Returns the declaration default for the type 'PblLeastInt32_T'.
 */
#define PblLeastInt32_T_DeclDefault PBL_TYPE_DECL_VAL(PblLeastInt32_T)
/**
 * @brief Returns the definition default for the type 'PblLeastInt32_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblLeastInt32_T_DefDefault PBL_TYPE_DEF_VAL(PblLeastInt32_T, 0)

/**
 * @brief PBL LeastInt32 implementation.
 */
typedef struct PblLeastInt32 {
  PBL_TYPE_DEF_HELPER(int_least32_t);
} PblLeastInt32_T;

// ---- End of LeastInt32 ---------------------------------------------------------------------------------------------

// ---- ULeastInt32 ---------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblULeastInt32_T_Size sizeof(uint_least32_t)
/**
 * @brief Returns the declaration default for the type 'PblULeastInt32_T'.
 */
#define PblULeastInt32_T_DeclDefault PBL_TYPE_DECL_VAL(PblULeastInt32_T)
/**
 * @brief Returns the definition default for the type 'PblULeastInt32_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblULeastInt32_T_DefDefault PBL_TYPE_DEF_VAL(PblULeastInt32_T, 0)

/**
 * @brief PBL ULeastInt32 implementation.
 */
typedef struct PblULeastInt32 {
  PBL_TYPE_DEF_HELPER(uint_least32_t);
} PblULeastInt32_T;

// ---- End of ULeastInt32 --------------------------------------------------------------------------------------------

// ---- LeastInt64 ----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed LeastInt64 type.
 */
#define PblLeastInt64_T_Size sizeof(int_least64_t)
/**
 * @brief Returns the declaration default for the type 'PblLeastInt64_T'.
 */
#define PblLeastInt64_T_DeclDefault PBL_TYPE_DECL_VAL(PblLeastInt64_T)
/**
 * @brief Returns the definition default for the type 'PblLeastInt64_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblLeastInt64_T_DefDefault PBL_TYPE_DEF_VAL(PblLeastInt64_T, 0)

/**
 * @brief PBL LeastInt64 implementation.
 */
typedef struct PblLeastInt64 {
  PBL_TYPE_DEF_HELPER(int_least64_t);
} PblLeastInt64_T;

// ---- End of LeastInt64 ---------------------------------------------------------------------------------------------

// ---- ULeastInt64 ---------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblULeastInt64_T_Size sizeof(uint_least64_t)
/**
 * @brief Returns the declaration default for the type 'PblULeastInt64_T'.
 */
#define PblULeastInt64_T_DeclDefault PBL_TYPE_DECL_VAL(PblULeastInt64_T)
/**
 * @brief Returns the definition default for the type 'PblULeastInt64_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblULeastInt64_T_DefDefault PBL_TYPE_DEF_VAL(PblULeastInt64_T, 0)

/**
 * @brief PBL ULeastInt64 implementation.
 */
typedef struct PblULeastInt64 {
  PBL_TYPE_DEF_HELPER(uint_least64_t);
} PblULeastInt64_T;

// ---- End of ULeastInt64 --------------------------------------------------------------------------------------------

// ---- End of Least Int ----------------------------------------------------------------------------------------------

// ---- Fast Int ------------------------------------------------------------------------------------------------------

// ---- FastInt8 ------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed FastInt8 type.
 */
#define PblFastInt8_T_Size sizeof(int_fast8_t)
/**
 * @brief Returns the declaration default for the type 'PblFastInt8_T'.
 */
#define PblFastInt8_T_DeclDefault PBL_TYPE_DECL_VAL(PblFastInt8_T)
/**
 * @brief Returns the definition default for the type 'PblFastInt8_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblFastInt8_T_DefDefault PBL_TYPE_DEF_VAL(PblFastInt8_T, 0)

/**
 * @brief PBL FastInt8 implementation.
 */
typedef struct PblFastInt8 {
  PBL_TYPE_DEF_HELPER(int_fast8_t);
} PblFastInt8_T;

// ---- End of FastInt8 -----------------------------------------------------------------------------------------------

// ---- UFastInt8 -----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblUFastInt8_T_Size sizeof(uint_fast8_t)
/**
 * @brief Returns the declaration default for the type 'PblUFastInt8_T'.
 */
#define PblUFastInt8_T_DeclDefault PBL_TYPE_DECL_VAL(PblUFastInt8_T)
/**
 * @brief Returns the definition default for the type 'PblUFastInt8_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblUFastInt8_T_DefDefault PBL_TYPE_DEF_VAL(PblUFastInt8_T, 0)

/**
 * @brief PBL UFastInt8 implementation.
 */
typedef struct PblUFastInt8 {
  PBL_TYPE_DEF_HELPER(uint_fast8_t);
} PblUFastInt8_T;

// ---- End of UFastInt8 ----------------------------------------------------------------------------------------------

// ---- FastInt16 -----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed FastInt16 type.
 */
#define PblFastInt16_T_Size sizeof(int_fast16_t)
/**
 * @brief Returns the declaration default for the type 'PblFastInt16_T'.
 */
#define PblFastInt16_T_DeclDefault PBL_TYPE_DECL_VAL(PblFastInt16_T)
/**
 * @brief Returns the definition default for the type 'PblFastInt16_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblFastInt16_T_DefDefault PBL_TYPE_DEF_VAL(PblFastInt16_T, 0)

/**
 * @brief PBL FastInt16 implementation.
 */
typedef struct PblFastInt16 {
  PBL_TYPE_DEF_HELPER(int_fast16_t);
} PblFastInt16_T;

// ---- End of FastInt16 ----------------------------------------------------------------------------------------------

// ---- UFastInt16 ----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblUFastInt16_T_Size sizeof(uint_fast16_t)
/**
 * @brief Returns the declaration default for the type 'PblUFastInt16_T'.
 */
#define PblUFastInt16_T_DeclDefault PBL_TYPE_DECL_VAL(PblUFastInt16_T)
/**
 * @brief Returns the definition default for the type 'PblUFastInt16_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblUFastInt16_T_DefDefault PBL_TYPE_DEF_VAL(PblUFastInt16_T, 0)

/**
 * @brief PBL UFastInt16 implementation.
 */
typedef struct PblUFastInt16 {
  PBL_TYPE_DEF_HELPER(uint_fast16_t);
} PblUFastInt16_T;

// ---- End of UFastInt16 ---------------------------------------------------------------------------------------------

// ---- FastInt32 -----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed FastInt32 type.
 */
#define PblFastInt32_T_Size sizeof(int_fast32_t)
/**
 * @brief Returns the declaration default for the type 'PblFastInt32_T'.
 */
#define PblFastInt32_T_DeclDefault PBL_TYPE_DECL_VAL(PblFastInt32_T)
/**
 * @brief Returns the definition default for the type 'PblFastInt32_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblFastInt32_T_DefDefault PBL_TYPE_DEF_VAL(PblFastInt32_T, 0)

/**
 * @brief PBL FastInt32 implementation.
 */
typedef struct PblFastInt32 {
  PBL_TYPE_DEF_HELPER(int_fast32_t);
} PblFastInt32_T;

// ---- End of FastInt32 ----------------------------------------------------------------------------------------------

// ---- UFastInt32 ----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblUFastInt32_T_Size sizeof(uint_fast32_t)
/**
 * @brief Returns the declaration default for the type 'PblUFastInt32_T'.
 */
#define PblUFastInt32_T_DeclDefault PBL_TYPE_DECL_VAL(PblUFastInt32_T)
/**
 * @brief Returns the definition default for the type 'PblUFastInt32_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblUFastInt32_T_DefDefault PBL_TYPE_DEF_VAL(PblUFastInt32_T, 0)

/**
 * @brief PBL UFastInt32 implementation.
 */
typedef struct PblUFastInt32 {
  PBL_TYPE_DEF_HELPER(uint_fast32_t);
} PblUFastInt32_T;

// ---- End of UFastInt32 ---------------------------------------------------------------------------------------------

// ---- FastInt64 -----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed FastInt64 type.
 */
#define PblFastInt64_T_Size sizeof(int_fast64_t)
/**
 * @brief Returns the declaration default for the type 'PblFastInt64_T'.
 */
#define PblFastInt64_T_DeclDefault PBL_TYPE_DECL_VAL(PblFastInt64_T)
/**
 * @brief Returns the definition default for the type 'PblFastInt64_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblFastInt64_T_DefDefault PBL_TYPE_DEF_VAL(PblFastInt64_T, 0)

/**
 * @brief PBL FastInt64 implementation.
 */
typedef struct PblFastInt64 {
  PBL_TYPE_DEF_HELPER(int_fast64_t);
} PblFastInt64_T;

// ---- End of FastInt64 ----------------------------------------------------------------------------------------------

// ---- UFastInt64 ----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type.
 */
#define PblUFastInt64_T_Size sizeof(uint_fast64_t)
/**
 * @brief Returns the declaration default for the type 'PblUFastInt64_T'.
 */
#define PblUFastInt64_T_DeclDefault PBL_TYPE_DECL_VAL(PblUFastInt64_T)
/**
 * @brief Returns the definition default for the type 'PblUFastInt64_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type.
 */
#define PblUFastInt64_T_DefDefault PBL_TYPE_DEF_VAL(PblUFastInt64_T, 0)

/**
 * @brief PBL UFastInt64 implementation.
 */
typedef struct PblUFastInt64 {
  PBL_TYPE_DEF_HELPER(uint_fast64_t);
} PblUFastInt64_T;

// ---- End of UFastInt64 ---------------------------------------------------------------------------------------------

// ---- End of Fast Int -----------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/**
 * @brief Converts the low level C-Type to a PBL Int8 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Int8 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblInt8_T *PblGetInt8T(int8_t val);

/**
 * @brief Converts the low level C-Type to a PBL UInt8 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL UInt8 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUInt8_T *PblGetUInt8T(uint8_t val);

/**
 * @brief Converts the low level C-Type to a PBL Int16 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Int16 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblInt16_T *PblGetInt16T(int16_t val);

/**
 * @brief Converts the low level C-Type to a PBL UInt16 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL UInt16 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUInt16_T *PblGetUInt16T(uint16_t val);

/**
 * @brief Converts the low level C-Type to a PBL Int32 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Int32 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblInt32_T *PblGetInt32T(int32_t val);

/**
 * @brief Converts the low level C-Type to a PBL UInt32 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL UInt32 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUInt32_T *PblGetUInt32T(uint32_t val);

/**
 * @brief Converts the low level C-Type to a PBL Int64 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Int64 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblInt64_T *PblGetInt64T(int64_t val);

/**
 * @brief Converts the low level C-Type to a PBL UInt64 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL UInt64 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUInt64_T *PblGetUInt64T(uint64_t val);

/**
 * @brief Converts the low level C-Type to a PBL LeastInt8 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL LeastInt8 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblLeastInt8_T *PblGetLeastInt8T(int_least8_t val);

/**
 * @brief Converts the low level C-Type to a PBL ULeastInt8 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL ULeastInt8 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblULeastInt8_T *PblGetULeastInt8T(uint_least8_t val);

/**
 * @brief Converts the low level C-Type to a PBL LeastInt16 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL LeastInt16 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblLeastInt16_T *PblGetLeastInt16T(int_least16_t val);

/**
 * @brief Converts the low level C-Type to a PBL ULeastInt16 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL ULeastInt16 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblULeastInt16_T *PblGetULeastInt16T(uint_least16_t val);

/**
 * @brief Converts the low level C-Type to a PBL LeastInt32 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL LeastInt32 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblLeastInt32_T *PblGetLeastInt32T(int_least32_t val);

/**
 * @brief Converts the low level C-Type to a PBL ULeastInt32 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL ULeastInt32 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblULeastInt32_T *PblGetULeastInt32T(uint_least32_t val);

/**
 * @brief Converts the low level C-Type to a PBL LeastInt64 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL LeastInt64 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblLeastInt64_T *PblGetLeastInt64T(int_least64_t val);

/**
 * @brief Converts the low level C-Type to a PBL ULeastInt64 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL ULeastInt64 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblULeastInt64_T *PblGetULeastInt64T(uint_least64_t val);

/**
 * @brief Converts the low level C-Type to a PBL FastInt8 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL FastInt8 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblFastInt8_T *PblGetFastInt8T(int_fast8_t val);

/**
 * @brief Converts the low level C-Type to a PBL UFastInt8 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL UFastInt8 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUFastInt8_T *PblGetUFastInt8T(uint_fast8_t val);

/**
 * @brief Converts the low level C-Type to a PBL FastInt16 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL FastInt16 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblFastInt16_T *PblGetFastInt16T(int_fast16_t val);

/**
 * @brief Converts the low level C-Type to a PBL UFastInt16 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL UFastInt16 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUFastInt16_T *PblGetUFastInt16T(uint_fast16_t val);

/**
 * @brief Converts the low level C-Type to a PBL FastInt32 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL FastInt32 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblFastInt32_T *PblGetFastInt32T(int_fast32_t val);

/**
 * @brief Converts the low level C-Type to a PBL UFastInt32 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL UFastInt32 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUFastInt32_T *PblGetUFastInt32T(uint_fast32_t val);

/**
 * @brief Converts the low level C-Type to a PBL FastInt64 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL FastInt64 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblFastInt64_T *PblGetFastInt64T(int_fast64_t val);

/**
 * @brief Converts the low level C-Type to a PBL UFastInt64 type.
 * @param val The C-type to be converted.
 * @return The newly created PBL UFastInt64 type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUFastInt64_T *PblGetUFastInt64T(uint_fast64_t val);

// ---- End of Functions Definitions ----------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_INT_H

/// @file pbl-int.h
/// @brief Int Type Implementation based on stdint.h
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#include <stdint.h>

#include "./pbl-types.h"

#ifndef PBL_MODULES_INT_H
#define PBL_MODULES_INT_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Exact Int -----------------------------------------------------------------------------------------------------

// ---- Int8 ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Int8 type
#define PblInt8_T_Size sizeof(int8_t)
/// @brief Returns the declaration default for the type 'PblInt8_T'
#define PblInt8_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblInt8_T)
/// @brief Returns the definition default for the type 'PblInt8_T', where only value itself has been created
#define PblInt8_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblInt8_T, 0)

/// @brief PBL Int8 implementation
struct PblInt8 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int8_t)
/// @brief PBL Signed Int8 implementation
typedef struct PblInt8 PblInt8_T;

// ---- UInt8 ---------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblUInt8_T_Size sizeof(uint8_t)
/// @brief Returns the declaration default for the type 'PblUInt8_T'
#define PblUInt8_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblUInt8_T)
/// @brief Returns the definition default for the type 'PblUInt8_T', where only value itself has been created
#define PblUInt8_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblUInt8_T, 0)

/// @brief PBL Unsigned Int8 implementation
struct PblUInt8 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint8_t)
/// @brief PBL Unsigned Int8 implementation
typedef struct PblUInt8 PblUInt8_T;

// ---- Int16 ---------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Int16 type
#define PblInt16_T_Size sizeof(int16_t)
/// @brief Returns the declaration default for the type 'PblInt16_T'
#define PblInt16_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblInt16_T)
/// @brief Returns the definition default for the type 'PblInt16_T', where only value itself has been created
#define PblInt16_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblInt16_T, 0)

/// @brief PBL Int16 implementation
struct PblInt16 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int16_t)
/// @brief PBL Signed Int16 implementation
typedef struct PblInt16 PblInt16_T;

// ---- UInt16 --------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblUInt16_T_Size sizeof(uint16_t)
/// @brief Returns the declaration default for the type 'PblUInt16_T'
#define PblUInt16_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblUInt16_T)
/// @brief Returns the definition default for the type 'PblUInt16_T', where only value itself has been created
#define PblUInt16_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblUInt16_T, 0)

/// @brief PBL UInt16 implementation
struct PblUInt16 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint16_t)
/// @brief PBL UInt16 implementation
typedef struct PblUInt16 PblUInt16_T;

// ---- Int32 ---------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Int32 type
#define PblInt32_T_Size sizeof(int32_t)
/// @brief Returns the declaration default for the type 'PblInt32_T'
#define PblInt32_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblInt32_T)
/// @brief Returns the definition default for the type 'PblInt32_T', where only value itself has been created
#define PblInt32_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblInt32_T, 0)

/// @brief PBL Int32 implementation
struct PblInt32 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int32_t)
/// @brief PBL Signed Int32 implementation
typedef struct PblInt32 PblInt32_T;

// ---- UInt32 --------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblUInt32_T_Size sizeof(uint32_t)
/// @brief Returns the declaration default for the type 'PblUInt32_T'
#define PblUInt32_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblUInt32_T)
/// @brief Returns the definition default for the type 'PblUInt32_T', where only value itself has been created
#define PblUInt32_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblUInt32_T, 0)

/// @brief PBL UInt32 implementation
struct PblUInt32 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint32_t)
/// @brief PBL UInt32 implementation
typedef struct PblUInt32 PblUInt32_T;

// ---- Int64 ---------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Int64 type
#define PblInt64_T_Size sizeof(int64_t)
/// @brief Returns the declaration default for the type 'PblInt64_T'
#define PblInt64_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblInt64_T)
/// @brief Returns the definition default for the type 'PblInt64_T', where only value itself has been created
#define PblInt64_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblInt64_T, 0)

/// @brief PBL Int64 implementation
struct PblInt64 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int64_t)
/// @brief PBL Signed Int64 implementation
typedef struct PblInt64 PblInt64_T;

// ---- UInt64 --------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblUInt64_T_Size sizeof(uint64_t)
/// @brief Returns the declaration default for the type 'PblUInt64_T'
#define PblUInt64_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblUInt64_T)
/// @brief Returns the definition default for the type 'PblUInt64_T', where only value itself has been created
#define PblUInt64_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblUInt64_T, 0)

/// @brief PBL UInt64 implementation
struct PblUInt64 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint64_t)
/// @brief PBL UInt64 implementation
typedef struct PblUInt64 PblUInt64_T;

// ---- Least Int -----------------------------------------------------------------------------------------------------

// ---- LeastInt8 -----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed LeastInt8 type
#define PblLeastInt8_T_Size sizeof(int_least8_t)
/// @brief Returns the declaration default for the type 'PblLeastInt8_T'
#define PblLeastInt8_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblLeastInt8_T)
/// @brief Returns the definition default for the type 'PblLeastInt8_T', where only value itself has been created
#define PblLeastInt8_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblLeastInt8_T, 0)

/// @brief PBL LeastInt8 implementation
struct PblLeastInt8 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int_least8_t)
/// @brief PBL Signed LeastInt8 implementation
typedef struct PblLeastInt8 PblLeastInt8_T;

// ---- ULeastInt8 ----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblULeastInt8_T_Size sizeof(uint_least8_t)
/// @brief Returns the declaration default for the type 'PblULeastInt8_T'
#define PblULeastInt8_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblULeastInt8_T)
/// @brief Returns the definition default for the type 'PblULeastInt8_T', where only value itself has been created
#define PblULeastInt8_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblULeastInt8_T, 0)

/// @brief PBL ULeastInt8 implementation
struct PblULeastInt8 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint_least8_t)
/// @brief PBL ULeastInt8 implementation
typedef struct PblULeastInt8 PblULeastInt8_T;

// ---- LeastInt16 ----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed LeastInt16 type
#define PblLeastInt16_T_Size sizeof(int_least16_t)
/// @brief Returns the declaration default for the type 'PblLeastInt16_T'
#define PblLeastInt16_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblLeastInt16_T)
/// @brief Returns the definition default for the type 'PblLeastInt16_T', where only value itself has been created
#define PblLeastInt16_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblLeastInt16_T, 0)

/// @brief PBL LeastInt16 implementation
struct PblLeastInt16 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int_least16_t)
/// @brief PBL Signed LeastInt16 implementation
typedef struct PblLeastInt16 PblLeastInt16_T;

// ---- ULeastInt16 ---------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblULeastInt16_T_Size sizeof(uint_least16_t)
/// @brief Returns the declaration default for the type 'PblULeastInt16_T'
#define PblULeastInt16_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblULeastInt16_T)
/// @brief Returns the definition default for the type 'PblULeastInt16_T', where only value itself has been created
#define PblULeastInt16_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblULeastInt16_T, 0)

/// @brief PBL ULeastInt16 implementation
struct PblULeastInt16 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint_least16_t)
/// @brief PBL ULeastInt16 implementation
typedef struct PblULeastInt16 PblULeastInt16_T;

// ---- LeastInt32 ----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed LeastInt32 type
#define PblLeastInt32_T_Size sizeof(int_least32_t)
/// @brief Returns the declaration default for the type 'PblLeastInt32_T'
#define PblLeastInt32_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblLeastInt32_T)
/// @brief Returns the definition default for the type 'PblLeastInt32_T', where only value itself has been created
#define PblLeastInt32_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblLeastInt32_T, 0)

/// @brief PBL LeastInt32 implementation
struct PblLeastInt32 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int_least32_t)
/// @brief PBL LeastInt32 implementation
typedef struct PblLeastInt32 PblLeastInt32_T;

// ---- ULeastInt32 ---------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblULeastInt32_T_Size sizeof(uint_least32_t)
/// @brief Returns the declaration default for the type 'PblULeastInt32_T'
#define PblULeastInt32_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblULeastInt32_T)
/// @brief Returns the definition default for the type 'PblULeastInt32_T', where only value itself has been created
#define PblULeastInt32_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblULeastInt32_T, 0)

/// @brief PBL ULeastInt32 implementation
struct PblULeastInt32 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint_least32_t)
/// @brief PBL ULeastInt32 implementation
typedef struct PblULeastInt32 PblULeastInt32_T;

// ---- LeastInt64 ----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed LeastInt64 type
#define PblLeastInt64_T_Size sizeof(int_least64_t)
/// @brief Returns the declaration default for the type 'PblLeastInt64_T'
#define PblLeastInt64_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblLeastInt64_T)
/// @brief Returns the definition default for the type 'PblLeastInt64_T', where only value itself has been created
#define PblLeastInt64_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblLeastInt64_T, 0)

/// @brief PBL LeastInt64 implementation
struct PblLeastInt64 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int_least64_t)
/// @brief PBL Signed LeastInt64 implementation
typedef struct PblLeastInt64 PblLeastInt64_T;

// ---- ULeastInt64 ---------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblULeastInt64_T_Size sizeof(uint_least64_t)
/// @brief Returns the declaration default for the type 'PblULeastInt64_T'
#define PblULeastInt64_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblULeastInt64_T)
/// @brief Returns the definition default for the type 'PblULeastInt64_T', where only value itself has been created
#define PblULeastInt64_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblULeastInt64_T, 0)

/// @brief PBL ULeastInt64 implementation
struct PblULeastInt64 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint_least64_t)
/// @brief PBL ULeastInt64 implementation
typedef struct PblULeastInt64 PblULeastInt64_T;

// ---- Fast Int ------------------------------------------------------------------------------------------------------

// ---- FastInt8 ---------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed FastInt8 type
#define PblFastInt8_T_Size sizeof(int_fast8_t)
/// @brief Returns the declaration default for the type 'PblFastInt8_T'
#define PblFastInt8_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblFastInt8_T)
/// @brief Returns the definition default for the type 'PblFastInt8_T', where only value itself has been created
#define PblFastInt8_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblFastInt8_T, 0)

/// @brief PBL FastInt8 implementation
struct PblFastInt8 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int_fast8_t)
/// @brief PBL FastInt8 implementation
typedef struct PblFastInt8 PblFastInt8_T;

// ---- UFastInt8 --------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblUFastInt8_T_Size sizeof(uint_fast8_t)
/// @brief Returns the declaration default for the type 'PblUFastInt8_T'
#define PblUFastInt8_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblUFastInt8_T)
/// @brief Returns the definition default for the type 'PblUFastInt8_T', where only value itself has been created
#define PblUFastInt8_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblUFastInt8_T, 0)

/// @brief PBL UFastInt8 implementation
struct PblUFastInt8 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint_fast8_t)
/// @brief PBL UFastInt8 implementation
typedef struct PblUFastInt8 PblUFastInt8_T;

// ---- FastInt16 --------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed FastInt16 type
#define PblFastInt16_T_Size sizeof(int_fast16_t)
/// @brief Returns the declaration default for the type 'PblFastInt16_T'
#define PblFastInt16_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblFastInt16_T)
/// @brief Returns the definition default for the type 'PblFastInt16_T', where only value itself has been created
#define PblFastInt16_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblFastInt16_T, 0)

/// @brief PBL FastInt16 implementation
struct PblFastInt16 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int_fast16_t)
/// @brief PBL Signed FastInt16 implementation
typedef struct PblFastInt16 PblFastInt16_T;

// ---- UFastInt16 -------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblUFastInt16_T_Size sizeof(uint_fast16_t)
/// @brief Returns the declaration default for the type 'PblUFastInt16_T'
#define PblUFastInt16_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblUFastInt16_T)
/// @brief Returns the definition default for the type 'PblUFastInt16_T', where only value itself has been created
#define PblUFastInt16_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblUFastInt16_T, 0)

/// @brief PBL UFastInt16 implementation
struct PblUFastInt16 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint_fast16_t)
/// @brief PBL UFastInt16 implementation
typedef struct PblUFastInt16 PblUFastInt16_T;

// ---- FastInt32 --------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed FastInt32 type
#define PblFastInt32_T_Size sizeof(int_fast32_t)
/// @brief Returns the declaration default for the type 'PblFastInt32_T'
#define PblFastInt32_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblFastInt32_T)
/// @brief Returns the definition default for the type 'PblFastInt32_T', where only value itself has been created
#define PblFastInt32_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblFastInt32_T, 0)

/// @brief PBL FastInt32 implementation
struct PblFastInt32 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int_fast32_t)
/// @brief PBL Signed FastInt32 implementation
typedef struct PblFastInt32 PblFastInt32_T;

// ---- UFastInt32 -------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblUFastInt32_T_Size sizeof(uint_fast32_t)
/// @brief Returns the declaration default for the type 'PblUFastInt32_T'
#define PblUFastInt32_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblUFastInt32_T)
/// @brief Returns the definition default for the type 'PblUFastInt32_T', where only value itself has been created
#define PblUFastInt32_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblUFastInt32_T, 0)

/// @brief PBL UFastInt32 implementation
struct PblUFastInt32 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint_fast32_t)
/// @brief PBL UFastInt32 implementation
typedef struct PblUFastInt32 PblUFastInt32_T;

// ---- FastInt64 --------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed FastInt64 type
#define PblFastInt64_T_Size sizeof(int_fast64_t)
/// @brief Returns the declaration default for the type 'PblFastInt64_T'
#define PblFastInt64_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblFastInt64_T)
/// @brief Returns the definition default for the type 'PblFastInt64_T', where only value itself has been created
#define PblFastInt64_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblFastInt64_T, 0)

/// @brief PBL FastInt64 implementation
struct PblFastInt64 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(int_fast64_t)
/// @brief PBL Signed FastInt64 implementation
typedef struct PblFastInt64 PblFastInt64_T;

// ---- UFastInt64 -------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Signed Long type
#define PblUFastInt64_T_Size sizeof(uint_fast64_t)
/// @brief Returns the declaration default for the type 'PblUFastInt64_T'
#define PblUFastInt64_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblUFastInt64_T)
/// @brief Returns the definition default for the type 'PblUFastInt64_T', where only value itself has been created
#define PblUFastInt64_T_DefDefault PBL_DEFINITION_SINGLE_CONSTRUCTOR(PblUFastInt64_T, 0)

/// @brief PBL UFastInt64 implementation
struct PblUFastInt64 PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(uint_fast64_t)
/// @brief PBL UFastInt64 implementation
typedef struct PblUFastInt64 PblUFastInt64_T;

// ---- Cleanup Functions ---------------------------------------------------------------------------------------------

/**
 * @brief Cleanups a local function 'PblInt8_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblInt8_T_Cleanup(PblInt8_T **value);

/**
 * @brief Cleanups a local function 'PblUInt8_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblUInt8_T_Cleanup(PblUInt8_T **value);

/**
 * @brief Cleanups a local function 'PblInt16_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblInt16_T_Cleanup(PblInt16_T **value);

/**
 * @brief Cleanups a local function 'PblUInt16_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblUInt16_T_Cleanup(PblUInt16_T **value);

/**
 * @brief Cleanups a local function 'PblInt32_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblInt32_T_Cleanup(PblInt32_T **value);

/**
 * @brief Cleanups a local function 'PblUInt32_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblUInt32_T_Cleanup(PblUInt32_T **value);

/**
 * @brief Cleanups a local function 'PblInt64_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblInt64_T_Cleanup(PblInt64_T **value);

/**
 * @brief Cleanups a local function 'PblUInt64_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblUInt64_T_Cleanup(PblUInt64_T **value);

/**
 * @brief Cleanups a local function 'PblLeastInt8_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblLeastInt8_T_Cleanup(PblLeastInt8_T **value);

/**
 * @brief Cleanups a local function 'PblULeastInt8_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblULeastInt8_T_Cleanup(PblULeastInt8_T **value);

/**
 * @brief Cleanups a local function 'PblLeastInt16_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblLeastInt16_T_Cleanup(PblLeastInt16_T **value);

/**
 * @brief Cleanups a local function 'PblULeastInt16_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblULeastInt16_T_Cleanup(PblULeastInt16_T **value);

/**
 * @brief Cleanups a local function 'PblLeastInt32_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblLeastInt32_T_Cleanup(PblLeastInt32_T **value);

/**
 * @brief Cleanups a local function 'PblULeastInt32_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblULeastInt32_T_Cleanup(PblULeastInt32_T **value);

/**
 * @brief Cleanups a local function 'PblLeastInt64_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblLeastInt64_T_Cleanup(PblLeastInt64_T **value);

/**
 * @brief Cleanups a local function 'PblULeastInt64_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblULeastInt64_T_Cleanup(PblULeastInt64_T **value);

/**
 * @brief Cleanups a local function 'PblFastInt8_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblFastInt8_T_Cleanup(PblFastInt8_T **value);

/**
 * @brief Cleanups a local function 'PblUFastInt8_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblUFastInt8_T_Cleanup(PblUFastInt8_T **value);

/**
 * @brief Cleanups a local function 'PblFastInt16_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblFastInt16_T_Cleanup(PblFastInt16_T **value);

/**
 * @brief Cleanups a local function 'PblUFastInt16_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblUFastInt16_T_Cleanup(PblUFastInt16_T **value);

/**
 * @brief Cleanups a local function 'PblFastInt32_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblFastInt32_T_Cleanup(PblFastInt32_T **value);

/**
 * @brief Cleanups a local function 'PblUFastInt32_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblUFastInt32_T_Cleanup(PblUFastInt32_T **value);

/**
 * @brief Cleanups a local function 'PblFastInt64_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblFastInt64_T_Cleanup(PblFastInt64_T **value);

/**
 * @brief Cleanups a local function 'PblUFastInt64_T' variable
 * @param value The pointer to the variable wrapper / pointer
 */
__attribute__((unused)) void __PblUFastInt64_T_Cleanup(PblUFastInt64_T **value);

// ---- Helper Functions ----------------------------------------------------------------------------------------------

/**
 * @brief Converts the low level C-Type to a PBL Int8 type
 * @param val The C-type to be converted
 * @return The newly created PBL Int8 type
 * @note This is a C to Para-C type conversion function - args are in C therefore
 */
PblInt8_T* PblGetInt8T(int8_t val);

/**
* @brief Converts the low level C-Type to a PBL UInt8 type
* @param val The C-type to be converted
* @return The newly created PBL UInt8 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblUInt8_T* PblGetUInt8T(uint8_t val);

/**
* @brief Converts the low level C-Type to a PBL Int16 type
* @param val The C-type to be converted
* @return The newly created PBL Int16 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblInt16_T* PblGetInt16T(int16_t val);

/**
* @brief Converts the low level C-Type to a PBL UInt16 type
* @param val The C-type to be converted
* @return The newly created PBL UInt16 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblUInt16_T* PblGetUInt16T(uint16_t val);

/**
* @brief Converts the low level C-Type to a PBL Int32 type
* @param val The C-type to be converted
* @return The newly created PBL Int32 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblInt32_T* PblGetInt32T(int32_t val);

/**
* @brief Converts the low level C-Type to a PBL UInt32 type
* @param val The C-type to be converted
* @return The newly created PBL UInt32 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblUInt32_T* PblGetUInt32T(uint32_t val);

/**
* @brief Converts the low level C-Type to a PBL Int64 type
* @param val The C-type to be converted
* @return The newly created PBL Int64 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblInt64_T* PblGetInt64T(int64_t val);

/**
* @brief Converts the low level C-Type to a PBL UInt64 type
* @param val The C-type to be converted
* @return The newly created PBL UInt64 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblUInt64_T* PblGetUInt64T(uint64_t val);

/**
* @brief Converts the low level C-Type to a PBL LeastInt8 type
* @param val The C-type to be converted
* @return The newly created PBL LeastInt8 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblLeastInt8_T* PblGetLeastInt8T(int_least8_t val);

/**
* @brief Converts the low level C-Type to a PBL ULeastInt8 type
* @param val The C-type to be converted
* @return The newly created PBL ULeastInt8 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblULeastInt8_T* PblGetULeastInt8T(uint_least8_t val);

/**
* @brief Converts the low level C-Type to a PBL LeastInt16 type
* @param val The C-type to be converted
* @return The newly created PBL LeastInt16 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblLeastInt16_T* PblGetLeastInt16T(int_least16_t val);

/**
* @brief Converts the low level C-Type to a PBL ULeastInt16 type
* @param val The C-type to be converted
* @return The newly created PBL ULeastInt16 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblULeastInt16_T* PblGetULeastInt16T(uint_least16_t val);

/**
* @brief Converts the low level C-Type to a PBL LeastInt32 type
* @param val The C-type to be converted
* @return The newly created PBL LeastInt32 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblLeastInt32_T* PblGetLeastInt32T(int_least32_t val);

/**
* @brief Converts the low level C-Type to a PBL ULeastInt32 type
* @param val The C-type to be converted
* @return The newly created PBL ULeastInt32 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblULeastInt32_T* PblGetULeastInt32T(uint_least32_t val);

/**
* @brief Converts the low level C-Type to a PBL LeastInt64 type
* @param val The C-type to be converted
* @return The newly created PBL LeastInt64 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblLeastInt64_T* PblGetLeastInt64T(int_least64_t val);

/**
* @brief Converts the low level C-Type to a PBL ULeastInt64 type
* @param val The C-type to be converted
* @return The newly created PBL ULeastInt64 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblULeastInt64_T* PblGetULeastInt64T(uint_least64_t val);

/**
* @brief Converts the low level C-Type to a PBL FastInt8 type
* @param val The C-type to be converted
* @return The newly created PBL FastInt8 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblFastInt8_T* PblGetFastInt8T(int_fast8_t val);

/**
* @brief Converts the low level C-Type to a PBL UFastInt8 type
* @param val The C-type to be converted
* @return The newly created PBL UFastInt8 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblUFastInt8_T* PblGetUFastInt8T(uint_fast8_t val);

/**
* @brief Converts the low level C-Type to a PBL FastInt16 type
* @param val The C-type to be converted
* @return The newly created PBL FastInt16 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblFastInt16_T* PblGetFastInt16T(int_fast16_t val);

/**
* @brief Converts the low level C-Type to a PBL UFastInt16 type
* @param val The C-type to be converted
* @return The newly created PBL UFastInt16 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblUFastInt16_T* PblGetUFastInt16T(uint_fast16_t val);

/**
* @brief Converts the low level C-Type to a PBL FastInt32 type
* @param val The C-type to be converted
* @return The newly created PBL FastInt32 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblFastInt32_T* PblGetFastInt32T(int_fast32_t val);

/**
* @brief Converts the low level C-Type to a PBL UFastInt32 type
* @param val The C-type to be converted
* @return The newly created PBL UFastInt32 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblUFastInt32_T* PblGetUFastInt32T(uint_fast32_t val);

/**
* @brief Converts the low level C-Type to a PBL FastInt64 type
* @param val The C-type to be converted
* @return The newly created PBL FastInt64 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblFastInt64_T* PblGetFastInt64T(int_fast64_t val);

/**
* @brief Converts the low level C-Type to a PBL UFastInt64 type
* @param val The C-type to be converted
* @return The newly created PBL UFastInt64 type
* @note This is a C to Para-C type conversion function - args are in C therefore
*/
PblUFastInt64_T* PblGetUFastInt64T(uint_fast64_t val);

#ifdef __cplusplus
}
#endif

#endif //PBL_MODULES_INT_H

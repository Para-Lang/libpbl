/**
 * @file pbl-types.h
 * @brief Para Base types that are used throughout the library as the base abstraction and wrappers for the C types.
 * @author Luna Klatzer
 * @copyright Copyright (c) 2021 - 2022
 */

#pragma once

// Including the base <stdbool.h>, <string.h> and <stddef.h> which this header intends to utilise and paritally
// implement
#ifdef __cplusplus
#include <cstddef>
#include <cstring>
#else
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#endif

// Dependencies
#include "./pbl-file-setup.h"
#include "./pbl-mem.h"
#include "./pbl-type-list.h"
#include <va-opt/va-opt.h>

#ifndef PBL_LIB_TYPES_H
#define PBL_LIB_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

PBL_INIT_HEADER(pbl_types);

// ---- General Type Handling Macros ----------------------------------------------------------------------------------

#define PBL_CLEANUP(func) __attribute__((__cleanup__(func)))

/**
 * @brief This macro initialises an actual instance of a type, instead of allocating it, like the GetTypeT functions,
 * and passes it onto the "to_write" variable.
 * @note This should only be used when wanting the actual type itself written onto a variable.
 */
#define PBL_SET_VAL(ptr, type, write_val)                                                                              \
  if (!(ptr)->meta.defined) { *(ptr) = type##_Default; }                                                            \
  (ptr)->actual = write_val;

/**
 * @brief This macro allocates an empty declaration instance of a type, which has no actual value set yet.
 * @note This should only be used when creating a declaration of a Para type.
 */
#define PBL_DECL_VAR(var_identifier, type, cleanup...) type *var_identifier IFN(cleanup)(PBL_CLEANUP(cleanup));

// Use auto with C++
#ifdef __cplusplus

/**
 * @brief This macro allocates an instance of type, which has the default initialisation value set.
 * @note This should only be used when creating a definition that shall be empty - if it's though a conversion from C
 * to Para the defined GetTypeT(...) function should be used, which will properly allocate and write to the variable.
 */
#define PBL_DEF_VAR(var_identifier, type, cleanup...)                                                                  \
  type var_identifier IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) { .meta = PBL_META_DEFAULT };                      \
  var_identifier.actual = PblMalloc(sizeof(type));                                                                     \
  var_identifier.actual = type##_Default;

/**
 * @brief This macro should serve as a helper for writing static arrays that shall be used to store types.
 * @note This should not be used as a replacement to PblIterable_T, but only as a memory-efficient helper for copying
 * or setting memory values.
 */
#define PBL_NEW_STATIC_ARR(to_write, type, length, cleanup...)                                                         \
  auto *to_write IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type) * (length));                     \
  for (int i = 0; i < (length); i++) { (to_write)[i] = type##_Default; }

#else

/**
 * @brief This macro allocates an instance of type, which has the default initialisation value set.
 * @note This should only be used when creating a definition that shall be empty - if it's though a conversion from C
 * to Para the defined GetTypeT(...) function should be used, which will properly allocate and write to the variable.
 */
#define PBL_DEF_VAR(var_identifier, type, cleanup...)                                                                  \
  type *var_identifier IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type));                          \
  *(var_identifier) = type##_Default;

/**
 * @brief This macro should serve as a helper for writing static arrays that shall be used to store types.
 * @note This should not be used as a replacement to PblIterable_T, but only as a memory-efficient helper for copying
 * or setting memory values.
 */
#define PBL_NEW_STATIC_ARR(to_write, type, length, cleanup...)                                                         \
  type *to_write IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type) * (length));                     \
  for (int i = 0; i < (length); i++) { (to_write)[i] = type##_Default; }

#endif

// ---- End of General Type Handling Macros ---------------------------------------------------------------------------

// ---- Constructor Macros --------------------------------------------------------------------------------------------

/**
 * @brief Creates the body for a Para type definition wrapper - the base_type is the actual value/struct.
 */
#define PBL_PRIMITIVE_TYPE_BODY(base_type)                                                                             \
  PblVarMetaData_T meta;                                                                                               \
  base_type actual;

/**
 * @brief Creates the body for a Para type definition wrapper - the base_type is the actual value/struct.
 */
#define PBL_COMPLEX_TYPE_BODY(base_type)                                                                               \
  PblVarMetaData_T meta;                                                                                               \
  base_type *actual;

// ---- End of Constructor Macros -------------------------------------------------------------------------------------

// ---- Local Variable state Saving -----------------------------------------------------------------------------------

/**
 * @brief Copies the passed value to a local state copy - This is designed for pointers losing their addresses
 * @note There may only be a single value copy with this unique_id!
 * @param var The variable to copy from.
 * @param type The POINTER type to assign the address to.
 * @param unique_id The unique_id to separate the local copies from each other.
 */
#define PBL_CREATE_ADDRESS_COPY(var, type, unique_id) type unique_id##_localcpy = var;

/**
 * @brief Writes back to the original variable the state copy - This is designed for pointers losing their addresses.
 * @param var The pointer to the variable that should be written to.
 * @param unique_id The unique id that was used to create the copied instance.
 */
#define PBL_WRITE_BACK_ADDRESS_COPY(var, unique_id)                                                                    \
  (var) = unique_id##_localcpy;                                                                                        \
  unique_id##_localcpy = NULL;

// ---- End of Local Variable state Saving  ---------------------------------------------------------------------------

// ---- Sizeof --------------------------------------------------------------------------------------------------------

/**
 * @brief Returns the usable size of a Para type that can be actually used.
 * @param var The variable to get the size from.
 * @note This type must be a Para type.
 */
#define PBL_SIZEOF_USABLE(type) (type##_WritableSize)

/**
 * @brief Returns the full allocation size of a Para type. This also includes meta data.
 * @param var The variable to get the size from.
 * @note This type must be a Para type.
 */
#define PBL_SIZEOF_FULL(type) (sizeof(type))

// ---- End of Sizeof -------------------------------------------------------------------------------------------------

// ---- Pointer Type --------------------------------------------------------------------------------------------------

#define PblPointer_T_ActualName ptr
#define PblPointer_T_Primitive true
#define PblPointer_T_Complex false
#define PblPointer_T_FullSize sizeof(PblPointer_T)
#define PblPointer_T_WritableSize sizeof(void *)
/**
 * @returns The definition default for the type 'PblPointer_T'.
 */
#define PblPointer_T_Default {.p_type = NULL, .p_void = NULL}
#define PblPointer_T_Properties { "p_type", "p_void" }

/**
 * @brief The base pointer type, implemented with 'PblPointer_T'.
 * @note If the p_void is NULL, then the type is also NULL.
 */
typedef struct PblPointer_Base {
  /**
   * @brief The type of the pointer.
   */
  PblType_T p_type;
  /**
   * @brief The actual pointer to the type.
   */
  void *p_void;
} PblPointer_T_Base;

/**
 * @brief This the general purpose pointer struct, which utilises 'PblType_T' to let the type of the variable be
 * differentiated between instances.
 */
typedef struct PblPointer {
  PBL_PRIMITIVE_TYPE_BODY(PblPointer_T_Base)
} PblPointer_T;

// ---- End of Pointer Type -------------------------------------------------------------------------------------------

// ---- Void Type -----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space).
 * @returns The usable size in bytes of the PBL PblNone_T type.
 */
#define PblNone_T_WritableSize 0
/**
 * @brief Returns the definition default for the type 'PblNone_T'.
 * @note This type does not allow any definition, so using it as such is invalid.
 */
#define PblNone_T_Default

/**
 * @brief None/empty type implementation. This is a simple redefinition of the standard void, so it is still an
 * incomplete type and pbl-macros will not work on it!
 */
typedef void PblNone_T;

// ---- End of Void Type ----------------------------------------------------------------------------------------------

// ---- Numeric Types -------------------------------------------------------------------------------------------------
// All types that are not unsigned are signed by default to ensure consistency
// Note that in those definitions the size is calculated using the C-type (as only one "real" property is there)

// ---- Bool ----------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space).
 * @returns The usable size in bytes of the PBL Bool type.
 */
#define PblBool_T_WritableSize sizeof(bool)
/**
 * @returns The definition default for the type 'PblBool_T'.
 */
#define PblBool_T_Default false

/**
 * @brief PBL Bool implementation.
 */
typedef struct PblBool {
  PBL_PRIMITIVE_TYPE_BODY(bool);
} PblBool_T;

// ---- End of Bool ---------------------------------------------------------------------------------------------------

// ---- Size ----------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space).
 * @returns The usable size in bytes of the PBL Size type.
 */
#define PblSize_T_WritableSize sizeof(size_t)
/**
 * @returns The definition default for the type 'PblSize_T'.
 */
#define PblSize_T_Default 0

/**
 * @brief PBL Byte Size implementation.
 */
typedef struct PblSize {
  PBL_PRIMITIVE_TYPE_BODY(size_t);
} PblSize_T;

// ---- End of Size ---------------------------------------------------------------------------------------------------

// ---- Char ----------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space).
 * @returns The usable size in bytes of the PBL Signed Char type.
 */
#define PblChar_T_WritableSize sizeof(signed char)
/**
 * @returns The definition default for the type 'PblChar_T'.
 */
#define PblChar_T_Default 0

/**
 * @brief PBL Signed Char implementation.
 */
typedef struct PblChar {
  PBL_PRIMITIVE_TYPE_BODY(signed char);
} PblChar_T;

// ---- End of Char ---------------------------------------------------------------------------------------------------

// ---- UChar ---------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space).
 * @returns The usable size in bytes of the PBL Unsigned Char type.
 */
#define PblUChar_T_WritableSize sizeof(unsigned char)
/**
 * @returns The definition default for the type 'PblUChar_T'.
 */
#define PblUChar_T_Default 0

/**
 * @brief PBL Unsigned Char implementation.
 */
typedef struct PblUChar {
  PBL_PRIMITIVE_TYPE_BODY(unsigned char);
} PblUChar_T;

// ---- End of UChar --------------------------------------------------------------------------------------------------

// ---- Short ---------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space).
 * @returns The usable size in bytes of the PBL Signed Short type.
 */
#define PblShort_T_WritableSize sizeof(signed short)
/**
 * @returns The definition default for the type 'PblShort_T'.
 */
#define PblShort_T_Default 0

/**
 * @brief PBL Signed Short implementation.
 */
typedef struct PblShort {
  PBL_PRIMITIVE_TYPE_BODY(signed short);
} PblShort_T;

// ---- End of Short --------------------------------------------------------------------------------------------------

// ---- UShort --------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space).
 * @returns The usable size in bytes of the PBL Unsigned Short type.
 */
#define PblUShort_T_WritableSize sizeof(unsigned short)
/**
 * @returns The definition default for the type 'PblUShort_T'.
 */
#define PblUShort_T_Default 0

/**
 * @brief PBL Unsigned Short implementation.
 */
typedef struct PblUShort {
  PBL_PRIMITIVE_TYPE_BODY(unsigned short);
} PblUShort_T;

// ---- End of UShort -------------------------------------------------------------------------------------------------

// ---- Int -----------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Int type
 */
#define PblInt_T_WritableSize sizeof(signed int)
/**
 * @returns The definition default for the type 'PblInt_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblInt_T_Default 0

/**
 * @brief PBL Signed Int implementation
 */
typedef struct PblInt {
  PBL_PRIMITIVE_TYPE_BODY(signed int);
} PblInt_T;

// ---- End of Int ----------------------------------------------------------------------------------------------------

// ---- UInt ----------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Unsigned Int type */
#define PblUInt_T_WritableSize sizeof(unsigned int)
/**
 * @returns The definition default for the type 'PblUInt_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblUInt_T_Default 0

/**
 * @brief PBL Unsigned Int implementation
 */
typedef struct PblUInt {
  PBL_PRIMITIVE_TYPE_BODY(unsigned int);
} PblUInt_T;

// ---- End of UInt ---------------------------------------------------------------------------------------------------

// ---- Long ----------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long type */
#define PblLong_T_WritableSize sizeof(signed long)
/**
 * @returns The definition default for the type 'PblLong_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblLong_T_Default 0

/**
 * @brief PBL Signed Long implementation
 */
typedef struct PblLong {
  PBL_PRIMITIVE_TYPE_BODY(signed long);
} PblLong_T;

// ---- End of Long --------------------------------------------------------------------------------------------------

// ---- ULong ---------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Unsigned Long type */
#define PblULong_T_WritableSize sizeof(unsigned long)
/**
 * @returns The definition default for the type 'PblULong_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblULong_T_Default 0

/**
 * @brief PBL Unsigned Long implementation
 */
typedef struct PblULong {
  PBL_PRIMITIVE_TYPE_BODY(unsigned long);
} PblULong_T;

// ---- End of ULong --------------------------------------------------------------------------------------------------

// ---- Long Long -----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Signed Long Long type
 */
#define PblLongLong_T_WritableSize sizeof(signed long long)
/**
 * @returns The definition default for the type 'PblLongLong_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblLongLong_T_Default 0

/**
 * @brief PBL Signed Long Long implementation
 */
typedef struct PblLongLong {
  PBL_PRIMITIVE_TYPE_BODY(signed long long);
} PblLongLong_T;

// ---- End of Long Long ----------------------------------------------------------------------------------------------

// ---- ULong Long ----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Unsigned Long Long type */
#define PblULongLong_T_WritableSize sizeof(unsigned long long)
/**
 * @returns The definition default for the type 'PblULongLong_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblULongLong_T_Default 0

/**
 * @brief PBL Unsigned Long Long implementation
 */
typedef struct PblULongLong {
  PBL_PRIMITIVE_TYPE_BODY(unsigned long long);
} PblULongLong_T;

// ---- End of ULong Long ---------------------------------------------------------------------------------------------

// ---- Float ---------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Float type */
#define PblFloat_T_WritableSize sizeof(float)
/**
 * @returns The definition default for the type 'PblFloat_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblFloat_T_Default 0

/**
 * @brief PBL Float implementation
 */
typedef struct PblFloat {
  PBL_PRIMITIVE_TYPE_BODY(float);
} PblFloat_T;

// ---- End of Float --------------------------------------------------------------------------------------------------

// ---- Double --------------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Double type */
#define PblDouble_T_WritableSize sizeof(double)
/**
 * @returns The definition default for the type 'PblDouble_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblDouble_T_Default 0

/**
 * @brief PBL Double implementation
 */
typedef struct PblDouble {
  PBL_PRIMITIVE_TYPE_BODY(double);
} PblDouble_T;

// ---- End of Double -------------------------------------------------------------------------------------------------

// ---- Long Double ---------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Long Double type */
#define PblLongDouble_T_WritableSize sizeof(long double)
/**
 * @returns The definition default for the type 'PblLongDouble_T', where the value/the children have not been set yet
 * and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
 * initialised to 0 or another Definition Default of another type */
#define PblLongDouble_T_Default 0

/**
 * @brief PBL Long Double implementation
 */
typedef struct PblLongDouble {
  PBL_PRIMITIVE_TYPE_BODY(long double);
} PblLongDouble_T;

// ---- End of Numeric Types ------------------------------------------------------------------------------------------

// ---- Helper Function Constructor Macros ----------------------------------------------------------------------------

// Use auto with C++
#ifdef __cplusplus

/**
 * @brief This a macro function definition body constructor, which should be used to directly convert C types into
 * their Para counterparts. This should be only used for Para types that have as actual a single property, as this
 * does not support complex initialisation. 
 */
#define PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(para_type, val, c_type)                                                \
  {                                                                                                                    \
    auto *conv = (para_type *) PblMalloc(sizeof(para_type));                                                           \
    *conv = para_type##_Default;                                                                                    \
    conv->actual = (c_type) (val);                                                                                     \
    return conv;                                                                                                       \
  }

#else

/**
 * @brief This a macro function definition body constructor, which should be used to directly convert C types into
 * their Para counterparts. This should be only used for Para types that have as actual a single property, as this
 * does not support complex initialisation. 
 */
#define PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(para_type, val, c_type)                                                \
  {                                                                                                                    \
    para_type *conv = (para_type *) PblMalloc(sizeof(para_type));                                                      \
    *conv = para_type##_Default;                                                                                    \
    conv->actual = (c_type) (val);                                                                                     \
    return conv;                                                                                                       \
  }

#endif

// ---- End of Helper Function Constructor Macros ---------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/**
 * @brief Converts a void* pointer and type to a Pbl Pointer type.
 * @param val The actual pointer value.
 * @param type The type of the pointer.
 * @return The created pointer.
 */
__attribute__((unused)) PblPointer_T *PblGetPointerT(void *val, PblType_T *type);

/**
 * @brief Converts the low level C-Type to a PBL Bool type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Bool type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblBool_T *PblGetBoolT(bool val);

/**
 * @brief Converts the low level C-Type to a PBL Byte Size type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Byte Size type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblSize_T *PblGetSizeT(size_t val);

/**
 * @brief Converts the low level C-Type to a PBL Char type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblChar_T *PblGetCharT(signed char val);

/**
 * @brief Converts the low level C-Type to a PBL Unsigned Char type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUChar_T *PblGetUCharT(unsigned char val);

/**
 * @brief Converts the low level C-Type to a PBL Short type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblShort_T *PblGetShortT(signed short val);

/**
 * @brief Converts the low level C-Type to a PBL Unsigned Short type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUShort_T *PblGetUShortT(unsigned short val);

/**
 * @brief Converts the low level C-Type to a PBL Int type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblInt_T *PblGetIntT(signed int val);

/**
 * @brief Converts the low level C-Type to a PBL Unsigned Int type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblUInt_T *PblGetUIntT(unsigned int val);

/**
 * @brief Converts the low level C-Type to a PBL Long type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblLong_T *PblGetLongT(signed long val);

/**
 * @brief Converts the low level C-Type to a PBL Unsigned Long type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblULong_T *PblGetULongT(unsigned long val);

/**
 * @brief Converts the low level C-Type to a PBL Long Long type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblLongLong_T *PblGetLongLongT(signed long long val);

/**
 * @brief Converts the low level C-Type to a PBL Unsigned Long Long type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblULongLong_T *PblGetULongLongT(unsigned long long val);

/**
 * @brief Converts the low level C-Type to a PBL Float type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Char type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblFloat_T *PblGetFloatT(float val);

/**
 * @brief Converts the low level C-Type to a PBL Double type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Double type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblDouble_T *PblGetDoubleT(double val);

/**
 * @brief Converts the low level C-Type to a PBL Long Double type.
 * @param val The C-type to be converted.
 * @return The newly created PBL Long Double type.
 * @note This is a C to Para type conversion function - args are in C therefore.
 */
__attribute__((unused)) PblLongDouble_T *PblGetLongDoubleT(long double val);

// ---- End of Functions Definitions ----------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_TYPES_H

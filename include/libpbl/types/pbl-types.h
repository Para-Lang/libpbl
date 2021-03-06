/// @file pbl-types.h
/// @brief Para Base Types Implementation, which contains handler macros, conversion functions, default declaration,
/// default definition types and default size macros. This also includes meta-data tracking based on the
/// 'PblMetaVarCtx_T' type.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#pragma once

// Including the base <stdbool.h>, <string.h> and <stddef.h> which this header intends to utilise and paritally
// implement
#ifdef __cplusplus
# include <cstring>
# include <cstddef>
#else
# include <stdbool.h>
# include <string.h>
# include <stddef.h>
#endif


// General Required Header Inclusion
#include <va-opt/va-opt.h>
#include "../mem/pbl-mem.h"

#ifndef PBL_MODULES_TYPES_H
#define PBL_MODULES_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Meta Types ----------------------------------------------------------------------------------------------------

/// @brief The Type type, which is used as a meta-type for tracking of types in types like 'PblAny_T' and to allow for
/// dynamic casting, conversion and type checking.
struct PblType {
  /// @brief The size of the variable, which is stored *once*. This allows for dynamic size checking on runtime
  /// @note For optimisation always prefer to use the macro 'type##_Size'
  size_t actual_size;
  /// @brief The usable size that may be utilised
  size_t usable_size;
  /// @brief The default template that should be used to initialise a new type from.
  const void *type_template;
  /// @brief The unique identifier for the type, that will be used to compare against. This is null char (\0)
  /// terminated.
  /// @note This is not a mangled identifier
  const char *name;
  /// @brief If the type is user defined and not a built-in
  bool user_defined;
  /// @brief If this type may be defined / converted to
  bool definable;
};

/// @brief The Type type, which is used as a meta-type for tracking of types in types like 'PblAny_T' and to allow for
/// dynamic casting, conversion and type checking.
typedef struct PblType PblType_T;

/// @brief Base Meta Type contained in ALL variables - has no DeclDefault or DefDefault
struct PblVarMetaData {
  /// @brief Is true when the variable is defined (not declared). This variable is used to also validate whether a
  /// variable's memory can be accessed without raising an error!
  bool defined;
  /// @brief The size of the variable, which is defined by the 'PblTypeMeta_T' global type
  PblType_T *type;
};

/// @brief Base Meta Type contained in ALL variables - has no DeclDefault or DefDefault
typedef struct PblVarMetaData PblVarMetaData_T;

// ---- End of Meta Types ---------------------------------------------------------------------------------------------

// ---- Type List -----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Type Dict
#define PblTypeList_T_Size sizeof(void*)
/// @returns The declaration default for the type 'PblTypeList_T'
#define PblTypeList_T_DeclDefault (PblTypeList_T) {}
/// @returns The definition default for the type 'PblTypeList_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblTypeList_T_DefDefault (PblTypeList_T) { .alloc_len=0, .t_amount = 0, .t_items = NULL }

/// @brief A type list storing pointers to data-types
struct PblTypeList {
  /// @brief The actual allocated length
  int alloc_len;
  /// @brief The amount of items stored
  int t_amount;
  /// @brief A list of pointers, which point to the types
  const PblType_T** t_items;
};

/// @brief A type list storing pointers to data-types
/// @note This will be used in each Para file to keep track of all types, and allow for more advanced dynamic type
/// fetching and handling without having to deal with name mangling
typedef struct PblTypeList PblTypeList_T;

/// @brief Allocates and creates a new type signature based on the passed arguments
/// @returns The newly allocated type
const PblType_T *PblCreateNewType(const size_t size, const void *type_template, const char *name,
                                  const bool user_defined, const bool definable);

/// @brief Adds a new type to the type list by adding a new pointer which points to the type
void PblAddTypeToTypeList(PblTypeList_T* list, const PblType_T* type);

void PblInitTypeList(PblTypeList_T* list);

/// @brief Initialises the local types by making the function 'PBL_CONSTRUCTOR_TYPES_INIT' callable on startup
/// @note The function 'PBL_CONSTRUCTOR_TYPES_INIT' must be defined in an object file (included .c source file) and is
/// only called on startup
#define LOCAL_TYPE_LIST_CONSTRUCTOR                                                                                    \
  __attribute__((unused)) __attribute__((constructor(102)))                                                            \
  __attribute__((deprecated("Compiler-Only Function - User Call Invalid!")))                                           \
  static void PBL_CONSTRUCTOR_TYPES_INIT(void)

/// @brief Simple Wrapper for the functions 'PblCreateNewType' and 'PblAddTypeToTypeList', which pre-populates the
/// arguments size and type_template by using 'sizeof()' and '_DefDefault'
/// @note This macro function should only be used inside 'PBL_INIT_LOCAL_TYPES' blocks, as it intends to register types
/// before starting execution
#define PBL_REGISTER_LOCAL_TYPE(list, type, name, user_defined, definable)                                             \
  type *type##_DefaultTemplate = PblMalloc(sizeof(type));                                                              \
  *type##_DefaultTemplate = type##_DefDefault;                                                                         \
  PblAddTypeToTypeList(list, PblCreateNewType(sizeof(type), type##_DefaultTemplate, name, user_defined, definable));

/// @brief Creates the local type list and initialises it for the local file. This also will create a local
/// constructor function for initialising the list on runtime.
#define PBL_INIT_LOCAL_TYPE_LIST                                                                                       \
  __attribute__((unused)) static bool LOCAL_TYPE_TRACKING_INITIALISED = false;                                         \
  __attribute__((unused)) static PblTypeList_T LOCAL_TYPE_LIST = PblTypeList_T_DefDefault;                             \
  __attribute__((unused)) __attribute__((constructor(101)))                                                            \
  __attribute__((deprecated("Compiler-Only Function - User Call Invalid!")))                                           \
  static void PBL_CONSTRUCTOR_TYPES_LIST_INIT(void) {                                                                  \
    PblInitTypeList(&LOCAL_TYPE_LIST); LOCAL_TYPE_TRACKING_INITIALISED = true;                                         \
  }

// ---- End of Type List ----------------------------------------------------------------------------------------------

// ---- General Type Handling Macros ----------------------------------------------------------------------------------

#define PBL_CLEANUP(func) __attribute__((__cleanup__(func)))

/// @brief This macro initialises an actual instance of a type, instead of allocating it, like the GetTypeT functions,
/// and passes it onto the "to_write" variable.
/// @note This should only be used when wanting the actual type itself written onto a variable
#define PBL_ASSIGN_TO_VAR(to_write, type, write_val)                                                                   \
  (to_write) = type##_DefDefault;                                                                                      \
  (to_write).actual = write_val;

// Use auto with C++
#ifdef __cplusplus
/// @brief This macro allocates an empty declaration instance of a type, which has no actual value set yet
/// @note This should only be used when creating a declaration of a Para type
#define PBL_DECLARE_VAR(var_identifier, type, cleanup...)                                                              \
  auto *var_identifier IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type));                          \
  *(var_identifier) = type##_DeclDefault;

/// @brief This macro allocates an instance of type, which has the default initialisation value set
/// @note This should only be used when creating a definition that shall be empty - if it's though a conversion from C
/// to Para the defined GetTypeT(...) function should be used, which will properly allocate and write to the variable
#define PBL_DEFINE_VAR(var_identifier, type, cleanup...)                                                               \
  auto *var_identifier IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type));                          \
  *(var_identifier) = type##_DefDefault;

/// @brief This macro should serve as a helper for writing static arrays that shall be used to store types
/// @note This should not be used as a replacement to PblIterable_T, but only as a memory-efficient helper for copying
/// or setting memory values
#define PBL_CREATE_NEW_ARRAY(to_write, type, length, cleanup...)                                                       \
  auto *to_write IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type) * (length));                     \
  for (int i = 0; i < (length); i++) {                                                                                 \
    (to_write)[i] = type##_DefDefault;                                                                                 \
  }
#else
/// @brief This macro allocates an empty declaration instance of a type, which has no actual value set yet
/// @note This should only be used when creating a declaration of a Para type
#define PBL_DECLARE_VAR(var_identifier, type, cleanup...)                                                              \
  type *var_identifier IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type));                          \
  *(var_identifier) = type##_DeclDefault;

/// @brief This macro allocates an instance of type, which has the default initialisation value set
/// @note This should only be used when creating a definition that shall be empty - if it's though a conversion from C
/// to Para the defined GetTypeT(...) function should be used, which will properly allocate and write to the variable
#define PBL_DEFINE_VAR(var_identifier, type, cleanup...)                                                               \
  type *var_identifier IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type));                          \
  *(var_identifier) = type##_DefDefault;

/// @brief This macro should serve as a helper for writing static arrays that shall be used to store types
/// @note This should not be used as a replacement to PblIterable_T, but only as a memory-efficient helper for copying
/// or setting memory values
#define PBL_CREATE_NEW_ARRAY(to_write, type, length, cleanup...)                                                       \
  type *to_write IFN(cleanup)(PBL_CLEANUP(cleanup)) = (type *) PblMalloc(sizeof(type) * (length));                     \
  for (int i = 0; i < (length); i++) {                                                                                 \
    (to_write)[i] = type##_DefDefault;                                                                                 \
  }
#endif

// ---- End of General Type Handling Macros ---------------------------------------------------------------------------

// ---- Constructor Macros --------------------------------------------------------------------------------------------

/// @brief Declaration constructor which initialised the meta data for the passed type
#define PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(type)                                                                 \
  (type) { .meta = {.defined = false } }

/// @brief Definition constructor, which initialises the meta data for the passed type and passes to '.actual' the args
/// as struct
#define PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(type, ...)                                                      \
  (type) { .meta = {.defined = true}, .actual = { __VA_ARGS__ } }

/// @brief Definition constructor, which initialised the meta data for the passed type and passes to '.actual' the
/// single arg
#define PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(type, var_actual...)                                            \
  (type) { .meta = {.defined = true}, .actual = var_actual }

/// @brief Creates the body for a Para type definition wrapper - the base_type is the actual value/struct
#define PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(base_type)                                                             \
  PblVarMetaData_T meta;                                                                                               \
  base_type actual;                                                                                                    \

// ---- End of Constructor Macros -------------------------------------------------------------------------------------

// ---- Local Variable state Saving -----------------------------------------------------------------------------------

/// @brief Copies the passed value to a local state copy - This is designed for pointers losing their addresses
/// @note There may only be a single value copy with this unique_id!
/// @param var The variable to copy from
/// @param type The POINTER type to assign the address to
/// @param unique_id The unique_id to separate the local copies from each other
#define PBL_CREATE_ADDRESS_COPY(var, type, unique_id) type unique_id##_localcpy = var;

/// @brief Writes back to the original variable the state copy - This is designed for pointers losing their addresses
/// @note If the var is NULL, then the address will be restored
/// @param var The pointer to the variable that should be written to
/// @param type
#define PBL_WRITE_BACK_ADDRESS_COPY(var_pointer, unique_id)                                                            \
  if ((var_pointer) == NULL) {                                                                                           \
    (var_pointer) = unique_id##_localcpy;                                                                                \
    unique_id##_localcpy = NULL;                                                                                       \
  }

// ---- End of Local Variable state Saving  ---------------------------------------------------------------------------

// ---- Sizeof --------------------------------------------------------------------------------------------------------

/// @brief Returns the usable size of a Para type that can be actually used
/// @param var The variable to get the size from
/// @note This type must be a Para type
#define PBL_SIZEOF_USABLE(type) (type##_Size)

/// @brief Returns the full allocation size of a Para type. This also includes meta data
/// @param var The variable to get the size from
/// @note This type must be a Para type
#define PBL_SIZEOF_FULL(type) (sizeof(type))

/// @brief Returns the full allocation size of a Para type, which has been defined dynamically.
/// This also includes meta data
/// @param var The variable to get the size from
/// @note This type must be a Para type
#define PBL_SIZEOF_FULL_ON_RUNTIME(var) var->meta.type->actual_size

/// @brief Returns the usable size of a Para type, which has been defined dynamically
/// @param var The variable to get the size from
/// @note This type must be a Para type
#define PBL_SIZEOF_USABLE_ON_RUNTIME(var) var->meta.type->usable_size

// ---- End of Sizeof -------------------------------------------------------------------------------------------------

// ---- Pointer Type --------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Bool type
#define PblPointer_T_Size sizeof(void*)
/// @returns The declaration default for the type 'PblPointer_T'
#define PblPointer_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblPointer_T)
/// @returns The definition default for the type 'PblPointer_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblPointer_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblPointer_T, {.p_type=NULL,.p_void=NULL})

/// @brief The base pointer type, implemented with 'PblPointer_T'
/// @note If the p_void is NULL, then the type is also NULL
struct PblPointer_Base {
  /// @brief The type of the pointer
  PblType_T* p_type;
  /// @brief The actual pointer to the type
  void* p_void;
};

/// @brief This the general purpose pointer struct, which utilises 'PblType_T' to be differentiated
struct PblPointer { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(struct PblPointer_Base); };

/// @brief This the general purpose pointer type, which utilises 'PblType_T' to be differentiated
typedef struct PblPointer PblPointer_T;

// ---- End of Pointer Type -------------------------------------------------------------------------------------------

// ---- Void Type -----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL PblVoid_T type
#define PblVoid_T_Size 0
/// @brief Returns the declaration default for the type 'PblVoid_T'
#define PblVoid_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblVoid_T)
/// @brief Returns the definition default for the type 'PblVoid_T'
/// @note This type actually does not allow any definition, so using it as such is invalid
#define PblVoid_T_DefDefault PblVoid_T_DeclDefault

/// @brief PBL Void implementation
struct PblVoid {
  /// @brief Meta-data tracking, as this value will never have anything accessible
  PblVarMetaData_T meta;
};
/// @brief PBL Void implementation
typedef struct PblVoid PblVoid_T;

// ---- End of Void Type ----------------------------------------------------------------------------------------------

// ---- Numeric Types -------------------------------------------------------------------------------------------------
// All types that are not unsigned are signed by default to ensure consistency
// Note that in those definitions the size is calculated using the C-type (as only one "real" property is there)

// ---- Bool ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Bool type
#define PblBool_T_Size sizeof(bool)
/// @returns The declaration default for the type 'PblBool_T'
#define PblBool_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblBool_T)
/// @returns The definition default for the type 'PblBool_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblBool_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblBool_T, false)

/// @brief PBL Bool implementation
struct PblBool { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(bool); };
/// @brief PBL Bool implementation
typedef struct PblBool PblBool_T;

// ---- End of Bool ---------------------------------------------------------------------------------------------------

// ---- Size ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Size type
#define PblSize_T_Size sizeof(size_t)
/// @returns The declaration default for the type 'PblSize_T'
#define PblSize_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblSize_T)
/// @returns The definition default for the type 'PblSize_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblSize_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblSize_T, 0)

/// @brief PBL Byte Size implementation
struct PblSize { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(size_t); };
/// @brief PBL Byte Size implementation
typedef struct PblSize PblSize_T;

// ---- End of Size ---------------------------------------------------------------------------------------------------

// ---- Char ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Signed Char type
#define PblChar_T_Size sizeof(signed char)
/// @returns The declaration default for the type 'PblChar_T'
#define PblChar_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblChar_T)
/// @returns The definition default for the type 'PblChar_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblChar_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblChar_T, 0)

/// @brief PBL Signed Char implementation
struct PblChar { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(signed char); };
/// @brief PBL Signed Char implementation
typedef struct PblChar PblChar_T;

// ---- End of Char ---------------------------------------------------------------------------------------------------

// ---- UChar ---------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Unsigned Char type
#define PblUChar_T_Size sizeof(unsigned char)
/// @returns The declaration default for the type 'PblUChar_T_Size'
#define PblUChar_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblUChar_T)
/// @returns The definition default for the type 'PblUChar_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblUChar_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblUChar_T, 0)

/// @brief PBL Unsigned Char implementation
struct PblUChar { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(unsigned char); };
/// @brief PBL Unsigned Char implementation
typedef struct PblUChar PblUChar_T;

// ---- End of UChar --------------------------------------------------------------------------------------------------

// ---- Short ---------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Signed Short type
#define PblShort_T_Size sizeof(signed short)
/// @returns The declaration default for the type 'PblShort_T'
#define PblShort_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblShort_T)
/// @returns The definition default for the type 'PblShort_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblShort_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblShort_T, 0)

/// @brief PBL Signed Short implementation
struct PblShort { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(signed short); };
/// @brief PBL Signed Short implementation
typedef struct PblShort PblShort_T;

// ---- End of Short --------------------------------------------------------------------------------------------------

// ---- UShort --------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Unsigned Short type
#define PblUShort_T_Size sizeof(unsigned short)
/// @returns The declaration default for the type 'PblUShort_T_Size'
#define PblUShort_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblUShort_T)
/// @returns The definition default for the type 'PblUShort_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblUShort_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblUShort_T, 0)

/// @brief PBL Unsigned Short implementation
struct PblUShort { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(unsigned short); };
/// @brief PBL Unsigned Short implementation
typedef struct PblUShort PblUShort_T;

// ---- End of UShort -------------------------------------------------------------------------------------------------

// ---- Int -----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Signed Int type
#define PblInt_T_Size sizeof(signed int)
/// @returns The declaration default for the type 'PblInt_T'
#define PblInt_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblInt_T)
/// @returns The definition default for the type 'PblInt_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblInt_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblInt_T, 0)

/// @brief PBL Signed Int implementation
struct PblInt { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(signed int); };
/// @brief PBL Signed Int implementation
typedef struct PblInt PblInt_T;

// ---- End of Int ----------------------------------------------------------------------------------------------------

// ---- UInt ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Unsigned Int type
#define PblUInt_T_Size sizeof(unsigned int)
/// @returns The declaration default for the type 'PblUInt_T'
#define PblUInt_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblUInt_T)
/// @returns The definition default for the type 'PblUInt_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblUInt_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblUInt_T, 0)

/// @brief PBL Unsigned Int implementation
struct PblUInt { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(unsigned int); };
/// @brief PBL Unsigned Int implementation
typedef struct PblUInt PblUInt_T;

// ---- End of UInt ---------------------------------------------------------------------------------------------------

// ---- Long ----------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Signed Long type
#define PblLong_T_Size sizeof(signed long)
/// @returns The declaration default for the type 'PblLong_T'
#define PblLong_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblLong_T)
/// @returns The definition default for the type 'PblLong_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblLong_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblLong_T, 0)

/// @brief PBL Signed Long implementation
struct PblLong { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(signed long); };
/// @brief PBL Signed Long implementation
typedef struct PblLong PblLong_T;

// ---- End of Long --------------------------------------------------------------------------------------------------

// ---- ULong ---------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Unsigned Long type
#define PblULong_T_Size sizeof(unsigned long)
/// @returns The declaration default for the type 'PblULong_T'
#define PblULong_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblULong_T)
/// @returns The definition default for the type 'PblULong_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblULong_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblULong_T, 0)

/// @brief PBL Unsigned Long implementation
struct PblULong { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(unsigned long); };
/// @brief PBL Unsigned Long implementation
typedef struct PblULong PblULong_T;

// ---- End of ULong --------------------------------------------------------------------------------------------------

// ---- Long Long -----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Signed Long Long type
#define PblLongLong_T_Size sizeof(signed long long)
/// @returns The declaration default for the type 'PblLongLong_T'
#define PblLongLong_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblLongLong_T)
/// @returns The definition default for the type 'PblLongLong_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblLongLong_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblLongLong_T, 0)

/// @brief PBL Signed Long Long implementation
struct PblLongLong { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(signed long long); };
/// @brief PBL Signed Long Long implementation
typedef struct PblLongLong PblLongLong_T;

// ---- End of Long Long ----------------------------------------------------------------------------------------------

// ---- ULong Long ----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Unsigned Long Long type
#define PblULongLong_T_Size sizeof(unsigned long long)
/// @returns The declaration default for the type 'PblULongLong_T'
#define PblULongLong_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblULongLong_T)
/// @returns The definition default for the type 'PblULongLong_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblULongLong_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblULongLong_T, 0)

/// @brief PBL Unsigned Long Long implementation
struct PblULongLong { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(unsigned long long); };
/// @brief PBL Unsigned Long Long implementation
typedef struct PblULongLong PblULongLong_T;

// ---- End of ULong Long ---------------------------------------------------------------------------------------------

// ---- Float ---------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Float type
#define PblFloat_T_Size sizeof(float)
/// @returns The declaration default for the type 'PblFloat_T'
#define PblFloat_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblFloat_T)
/// @returns The definition default for the type 'PblFloat_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblFloat_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblFloat_T, 0)

/// @brief PBL Float implementation
struct PblFloat { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(float); };
/// @brief PBL Float implementation
typedef struct PblFloat PblFloat_T;

// ---- End of Float --------------------------------------------------------------------------------------------------

// ---- Double --------------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Double type
#define PblDouble_T_Size sizeof(double)
/// @returns The declaration default for the type 'PblDouble_T'
#define PblDouble_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblDouble_T)
/// @returns The definition default for the type 'PblDouble_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblDouble_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblDouble_T, 0)

/// @brief PBL Double implementation
struct PblDouble { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(double); };
/// @brief PBL Double implementation
typedef struct PblDouble PblDouble_T;

// ---- End of Double -------------------------------------------------------------------------------------------------

// ---- Long Double ---------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Long Double type
#define PblLongDouble_T_Size sizeof(long double)
/// @returns The declaration default for the type 'PblLongDouble_T'
#define PblLongDouble_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblLongDouble_T)
/// @returns The definition default for the type 'PblLongDouble_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblLongDouble_T_DefDefault PBL_TYPE_DEFINITION_DEFAULT_SIMPLE_CONSTRUCTOR(PblLongDouble_T, 0)

/// @brief PBL Long Double implementation
struct PblLongDouble { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(long double); };
/// @brief PBL Long Double implementation
typedef struct PblLongDouble PblLongDouble_T;

// ---- End of Numeric Types ------------------------------------------------------------------------------------------

// ---- Helper Function Constructor Macros ----------------------------------------------------------------------------

// Use auto with C++
#ifdef __cplusplus
/// @brief This a macro function definition body constructor, which should be used to directly convert C types into
/// their Para counterparts. This should be only used for Para types that have as actual a single property, as this
/// does not support complex initialisation.
#define PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(parac_type, val, c_type)                                               \
  {                                                                                                                    \
    auto *conv = (parac_type*) PblMalloc(sizeof(parac_type));                                                          \
    *conv = parac_type##_DefDefault;                                                                                   \
    conv->actual = (c_type) (val);                                                                                     \
    return conv;                                                                                                       \
  }
#else
/// @brief This a macro function definition body constructor, which should be used to directly convert C types into
/// their Para counterparts. This should be only used for Para types that have as actual a single property, as this
/// does not support complex initialisation.
#define PBL_CONVERSION_FUNCTION_DEF_CONSTRUCTOR(parac_type, val, c_type)                                               \
  {                                                                                                                    \
    parac_type *conv = (parac_type*) PblMalloc(sizeof(parac_type));                                                    \
    *conv = parac_type##_DefDefault;                                                                                   \
    conv->actual = (c_type) (val);                                                                                     \
    return conv;                                                                                                       \
  }
#endif

// ---- End of Helper Function Constructor Macros ---------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/// @brief Converts a void* pointer and type to a Pbl Pointer type
/// @param val The actual pointer value
/// @param type The type of the pointer
/// @return The created pointer
__attribute__((unused)) PblPointer_T *PblGetPointerT(void* val, PblType_T* type);

/// @brief Converts the low level C-Type to a PBL Bool type
/// @param val The C-type to be converted
/// @return The newly created PBL Bool type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblBool_T *PblGetBoolT(bool val);

/// @brief Converts the low level C-Type to a PBL Byte Size type
/// @param val The C-type to be converted
/// @return The newly created PBL Byte Size type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblSize_T *PblGetSizeT(size_t val);

/// @brief Converts the low level C-Type to a PBL Char type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblChar_T *PblGetCharT(signed char val);

/// @brief Converts the low level C-Type to a PBL Unsigned Char type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblUChar_T *PblGetUCharT(unsigned char val);

/// @brief Converts the low level C-Type to a PBL Short type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblShort_T *PblGetShortT(signed short val);

/// @brief Converts the low level C-Type to a PBL Unsigned Short type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblUShort_T *PblGetUShortT(unsigned short val);

/// @brief Converts the low level C-Type to a PBL Int type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblInt_T *PblGetIntT(signed int val);

/// @brief Converts the low level C-Type to a PBL Unsigned Int type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblUInt_T *PblGetUIntT(unsigned int val);

/// @brief Converts the low level C-Type to a PBL Long type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblLong_T *PblGetLongT(signed long val);

/// @brief Converts the low level C-Type to a PBL Unsigned Long type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblULong_T *PblGetULongT(unsigned long val);

/// @brief Converts the low level C-Type to a PBL Long Long type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblLongLong_T *PblGetLongLongT(signed long long val);

/// @brief Converts the low level C-Type to a PBL Unsigned Long Long type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblULongLong_T *PblGetULongLongT(unsigned long long val);

/// @brief Converts the low level C-Type to a PBL Float type
/// @param val The C-type to be converted
/// @return The newly created PBL Char type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblFloat_T *PblGetFloatT(float val);

/// @brief Converts the low level C-Type to a PBL Double type
/// @param val The C-type to be converted
/// @return The newly created PBL Double type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblDouble_T *PblGetDoubleT(double val);

/// @brief Converts the low level C-Type to a PBL Long Double type
/// @param val The C-type to be converted
/// @return The newly created PBL Long Double type
/// @note This is a C to Para type conversion function - args are in C therefore
__attribute__((unused)) PblLongDouble_T *PblGetLongDoubleT(long double val);

// ---- End of Functions Definitions ----------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_MODULES_TYPES_H

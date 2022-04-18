/// @file pbl-type-list.h
/// @brief Implementation of the base type list that keeps track of the locally available types.
/// @author Luna-Klatzer
/// @date 2022-04-16
/// @copyright Copyright (c) 2021 - 2022
#pragma once

#include "./pbl-meta-types.h"

#ifndef PBL_LIB_TYPE_LIST_H
#define PBL_LIB_TYPE_LIST_H

// ---- Type List -----------------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The usable size in bytes of the PBL Type Dict
#define PblTypeList_T_Size sizeof(void *)
/// @returns The declaration default for the type 'PblTypeList_T'
#define PblTypeList_T_DeclDefault                                                                                      \
  (PblTypeList_T) {}
/// @returns The definition default for the type 'PblTypeList_T', where the value/the children have not been set yet
/// and only the value itself 'exists' already. If the type is a struct-type, then the children will likely be NULL,
/// initialised to 0 or another Definition Default of another type
#define PblTypeList_T_DefDefault                                                                                       \
  (PblTypeList_T) { .alloc_len = 0, .t_amount = 0, .t_items = NULL }

/// @brief A type list storing pointers to data-types
struct PblTypeList {
  /// @brief The actual allocated length
  int alloc_len;
  /// @brief The amount of items stored
  int t_amount;
  /// @brief A list of pointers, which point to the types
  PblType_T **t_items;
};

/// @brief A type list storing pointers to data-types
/// @note This will be used in each Para file to keep track of all types, and allow for more advanced dynamic type
/// fetching and handling without having to deal with name mangling
typedef struct PblTypeList PblTypeList_T;

/// @brief Allocates and creates a new type signature based on the passed arguments
/// @returns The newly allocated type
PblType_T *PblCreateNewType(size_t size, void *type_template, char *name, bool user_defined, bool definable);

/// @brief Adds a new type to the type list by adding a new pointer which points to the type
void PblAddTypeToTypeList(PblTypeList_T *list, PblType_T *type);

void PblInitTypeList(PblTypeList_T *list);

/// @brief Simple Wrapper for the functions 'PblCreateNewType' and 'PblAddTypeToTypeList', which pre-populates the
/// arguments size and type_template by using 'sizeof()' and '_DefDefault'
/// @note This macro function should only be used inside 'PBL_INIT_LOCAL_TYPES' blocks, as it intends to register types
/// before starting execution
#define PBL_REGISTER_TYPE(list, type, name, user_defined, definable)                                                     \
  type *type##_DefaultTemplate = PblMalloc(sizeof(type));                                                              \
  *type##_DefaultTemplate = type##_DefDefault;                                                                         \
  PblAddTypeToTypeList(list, PblCreateNewType(sizeof(type), type##_DefaultTemplate, name, user_defined, definable));

/// @brief Creates the local type list and initialises it for the local file. This also will create a local
/// constructor function for initialising the list on runtime.
#define PBL_INIT_LOCAL_TYPE_LIST                                                                                         \
  __attribute__((unused)) static bool LOCAL_TYPE_TRACKING_INITIALISED = false;                                         \
  __attribute__((unused)) static PblTypeList_T LOCAL_TYPE_LIST = PblTypeList_T_DefDefault;                             \
  __attribute__((unused)) __attribute__((constructor(102)))                                                            \
  __attribute__((deprecated("Compiler-Only Function - User Call Invalid!"))) static void                               \
  pre__PblInitTypeListTracking(void) {                                                                                 \
    PblInitTypeList(&LOCAL_TYPE_LIST);                                                                                 \
    LOCAL_TYPE_TRACKING_INITIALISED = true;                                                                            \
  }

// ---- End of Type List ----------------------------------------------------------------------------------------------

#endif//PBL_LIB_TYPE_LIST_H

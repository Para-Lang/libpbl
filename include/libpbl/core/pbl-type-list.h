/**
 * @file pbl-type-list.h
 * @brief Implementation of the base type list that keeps track of the locally available types.
 * @author Luna Klatzer
 * @copyright Copyright (c) 2021 - 2022
 */
#pragma once

#include "./pbl-meta-types.h"
#include "libpbl/core/pbl-mem.h"

#ifndef PBL_LIB_TYPE_LIST_H
#define PBL_LIB_TYPE_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Type List -----------------------------------------------------------------------------------------------------

/**
 * @brief (Never use this for malloc - this only indicates the usable memory space)
 * @returns The usable size in bytes of the PBL Type Dict
 */
#define PblTypeList_T_WritableSize sizeof(void *)
/**
 * @returns The definition default for the type 'PblTypeList_T'.
 */
#define PblTypeList_T_Default                                                                                       \
  (PblTypeList_T) { .alloc_len = 0, .t_amount = 0, .t_items = NULL }

/**
 * @brief A type list storing pointers to data-types
 */
struct PblTypeList {
  /**
   * @brief The actual allocated length
   */
  int alloc_len;
  /**
   * @brief The amount of items stored
   */
  int t_amount;
  /**
   * @brief A list of pointers, which point to the types
   */
  PblType_T **t_items;
};

/**
 * @brief A type list storing pointers to data-types.
 * @note This will be used in each Para file to keep track of all types, and allow for more advanced dynamic type
 * fetching and handling without having to deal with name mangling.
 */
typedef struct PblTypeList PblTypeList_T;

/**
 * @brief Allocates and creates a new type signature based on the passed arguments.
 * @returns The newly allocated type.
 */
PblType_T *PblCreateNewType(size_t size, void *type_template, const char *name, bool user_defined, bool definable,
                            bool primitive);

/**
 * @brief Adds a new type to the type list by adding a new pointer which points to the type.
 */
void PblAddTypeToTypeList(PblTypeList_T *list, PblType_T *type);

/**
 * @brief Initialises the type list for the local file.
 * @param list The type list to initialise and set up.
 */
void PblInitTypeList(PblTypeList_T *list);

/**
 * @brief Simple Wrapper for the functions 'PblCreateNewType' and 'PblAddTypeToTypeList'.
 * @note This macro function should only be used inside 'PBL_INIT_LOCAL_TYPES' blocks, as it intends to register types
 * before starting execution.
 */
#define PBL_REGISTER_TYPE(list, type, name, user_defined, definable, primitive)                                        \
  PblAddTypeToTypeList(list, PblCreateNewType(sizeof(type), type##_Default, name, user_defined, definable, primitive)\
);

/**
 * @brief Creates the local type list and initialises it for the local file. This also will create a local
 * constructor function for initialising the list on runtime.
 */
#define PBL_INIT_LOCAL_TYPE_LIST(file_name)                                                                            \
  static bool LOCAL_TYPE_TRACKING_INITIALISED = false;                                                                 \
  static PblTypeList_T LOCAL_TYPE_LIST = PblTypeList_T_Default;                                                     \
  const PblTypeList_T *file_name##_EXPORT_TYPE_LIST = &LOCAL_TYPE_LIST;                                                \
  __attribute__((constructor(102)))                                                                                    \
  __attribute__((deprecated("Compiler-Only Function - User Call Invalid!"))) static void                               \
  pre__PblInitTypeListTracking(void) {                                                                                 \
    PblInitTypeList(&LOCAL_TYPE_LIST);                                                                                 \
    LOCAL_TYPE_TRACKING_INITIALISED = true;                                                                            \
  }

/**
 * @brief Creates a header type list declaration entry, which is used to allow the export of locally defined types.
 * @note This macro should only be used in headers AND in combination with PBL_INIT_LOCAL_TYPE_LIST/PBL_INIT_FILE, as
 * this macro defines an extern variables that should be located inside a c-source-file!
 */
#define PBL_INIT_HEADER_TYPE_LIST(file_name) extern const PblTypeList_T *file_name##_EXPORT_TYPE_LIST;

// ---- End of Type List ----------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_TYPE_LIST_H

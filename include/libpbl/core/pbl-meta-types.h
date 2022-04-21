/**
 * @file pbl-meta-types.h
 * @brief Implementation of the base meta-types in the Para language.
 * @author Luna Klatzer
 * @copyright Copyright (c) 2021 - 2022
 */
#pragma once

#include <stdbool.h>
#include <stddef.h>

#ifndef PBL_LIB_META_TYPES_H
#define PBL_LIB_META_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Meta Types ----------------------------------------------------------------------------------------------------

/**
 * @brief The Type type, which is used as a meta-type for tracking of types in types like 'PblAny_T' and to allow for
 * dynamic casting, conversion and type checking.
 */
struct PblType {
  /**
   * @brief The size of the variable, which is stored *once*. This allows for dynamic size checking on runtime.
   * @note For optimisation always prefer to use the macro 'type##_Size'.
   */
  size_t actual_size;
  /**
   * @brief The usable size that may be utilised.
   */
  size_t usable_size;
  /**
   * @brief The default template that should be used to initialise a new type from.
   */
  const void *type_template;
  /**
   * @brief The unique identifier for the type, that will be used to compare against. This is null char (\0)
   * terminated.
   * @note This is not a mangled identifier.
   */
  const char *name;
  /**
   * @brief If the type is user defined and not a built-in.
   */
  bool user_defined;
  /**
   * @brief If this type may be defined / converted to.
   */
  bool definable;
};

/**
 * @brief The Type type, which is used as a meta-type for tracking of types in types like 'PblAny_T' and to allow for
 * dynamic casting, conversion and type checking.
 */
typedef struct PblType PblType_T;

/**
 * @brief Base Meta Type contained in ALL variables - has no DeclDefault or DefDefault.
 */
struct PblVarMetaData {
  /**
   * @brief Is true when the variable is defined (not declared). This variable is used to also validate whether a
   * variable's memory can be accessed without raising an error!
   */
  bool defined;
  /**
   * @brief The size of the variable, which is defined by the 'PblTypeMeta_T' global type.
   */
  PblType_T *type;
};

/**
 * @brief Base Meta Type contained in ALL variables - has no DeclDefault or DefDefault
 */
typedef struct PblVarMetaData PblVarMetaData_T;

// ---- End of Meta Types ---------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_META_TYPES_H

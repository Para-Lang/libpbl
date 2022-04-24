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

typedef struct PblComplexField PblComplexField_T;

/**
 * @brief The Type type, which is used as a meta-type for tracking of types in types like 'PblAny_T' and to allow for
 * dynamic casting, conversion and type checking.
 */
typedef struct PblType {
  /**
   * @brief The size of the `actual` property in the variable. This does not include the type wrapper and meta-data.
   */
  const size_t actual_size;
  /**
   * @brief The usable size that may be written to.
   */
  const size_t writable_size;
  /**
   * @brief An array of all properties in this type. (Enables reflection of the type)
   * @note This array is null-terminated. If the entire array is NULL, then the type is primitive.
   */
  const PblComplexField_T *fields;
  /**
   * @brief The default value that should b
   */
  const void *primitive_default;
  /**
   * @brief The unique identifier for the type, that will be used to compare against. This is null char (\0)
   * terminated.
   * @note This is not a mangled identifier.
   */
  const char *name;
  /**
   * @brief If the type is a built-in type.
   */
  const bool is_builtin;
  /**
   * @brief Defines whether this type is complex. If this is false, then the `actual` of the variable must be
   * defined at all times and can not be null. (Only complex types may have a null value - though with null-safety
   * it is usually forbidden due to `can_be_null` being set to false per default.)
   */
  const bool is_complex;
} PblType_T;

/**
 * @brief Defines a property field inside a complex type.
 */
typedef struct PblComplexField {
  /**
   * @brief The identifier of the property
   */
  char *identifier;
  /**
   * @brief The type of the property.
   */
  PblType_T *field_type;
} PblComplexField_T;

/**
 * @brief Base Meta Type contained in ALL variables - has no DeclDefault or DefDefault.
 */
typedef struct PblVarMetaData {
  /**
   * @brief Returns true when the variable has been destroyed.
   */
  bool destroyed;
  /**
   * @brief Returns true if the variable can be null. This is per default false, as all variables should always be
   * defined for safety.
   */
  bool can_be_null;
  /**
   * @brief The type of the variable.
   */
  PblType_T *type;
} PblVarMetaData_T;

/**
 * @brief The default value for the meta property of a variable.
 */
#define PBL_META_DEFAULT                                                                                               \
  (PblVarMetaData_T) { .can_be_null = false, .destroyed = false, .type = NULL }

/**
 * @brief The default value for a complex
 */
#define PBL_COMPLEX_VAR_DEFAULT(type)                                                                                  \
  { .meta = {.can_be_null = false, .destroyed = false, .type = NULL}, .actual = type##_Default }

// ---- End of Meta Types ---------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_LIB_META_TYPES_H

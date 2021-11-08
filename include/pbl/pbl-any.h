///
/// The any type, which allows values to be dynamically allocated and converted with ease.
/// The any type, will track it's type, so that direct conversion is easier.
///
/// @author Luna-Klatzer

#include "./pbl-types.h"
#include "pbl-string.h"

#ifndef PBL_INCLUDE_ANY_H
#define PBL_INCLUDE_ANY_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Exception Implementation --------------------------------------------------------------------------------------

/// (Never use this for malloc - this only indicates the usable memory space)
/// Returns the size in bytes of the PBL Long Double type
#define PblAny_T_Size (sizeof(void *) + sizeof(PblString_T *) + sizeof(PblSize_T *))
/// Returns the declaration default for the type 'PblAny_T'
#define PblAny_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblAny_T)
/// Returns the definition default, for the type 'PblAny_T', where the children have not been set yet and only the
/// value itself 'exists' already.
#define PblAny_T_DefDefault                                                                                            \
  PBL_DEFINITION_STRUCT_CONSTRUCTOR(PblAny_T, .val = NULL, .type_name = NULL, .byte_size = NULL)

struct PblAny_Base {
  void* val;
  PblString_T* type_name;
  PblSize_T* byte_size;
};

/// Any implementation
struct PblAny PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(struct PblAny_Base);
/// Any implementation - This type allows for a dynamic allocation and every type to be passed onto the allocated memory
typedef struct PblAny PblAny_T;

// ---- Helper Functions ----------------------------------------------------------------------------------------------

/**
 * @brief Allocates and fetches a new PblAny_T and passes the value onto it
 * @param val The void* value that shall be assigned to the PblAny_T type
 * @param size The size of the value to properly determine the size and the owned memory
 * @return The new PblAny_T
 * @note This is a C to Para-C type conversion function - args are in C therefore
 */
PblAny_T* PblGetAnyT(void* val, size_t size);

/**
 * @brief Force-deallocates the entire any-type
 */
PblVoid_T PblDeallocateAnyType(PblAny_T *val);

#ifdef __cplusplus
}
#endif

#endif//PBL_INCLUDE_ANY_H

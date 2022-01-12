/// @file pbl-string.h
/// @brief String Implementation based on dynamic memory allocation - This is an optimised form of char[], which is
/// though not equal to PblChar_T[], as it does not contain meta-data tracking for each char, but altogether as an
/// entire type to save memory.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#pragma once

// Including the base <string.h> which this header intends to implement
#ifdef __cplusplus
# include <cstring>
#else
# include <string.h>
#endif

// General Required Header Inclusion
#include "./pbl-types.h"

#ifndef PBL_MODULES_STRING_H
#define PBL_MODULES_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Declaration ---------------------------------------------------------------------------------------------------

/// @brief Size of the type 'PblString_T' in bytes
#define PblString_T_Size (sizeof(PblSize_T *) + sizeof(PblUInt_T *) + sizeof(PblUInt_T *) + sizeof(char *))
/// @brief Returns the declaration default for the type 'PblString_T'
#define PblString_T_DeclDefault PBL_TYPE_DECLARATION_DEFAULT_CONSTRUCTOR(PblString_T)
/// @brief Returns the definition default, for the type 'PblString_T', where the children have not been set yet and
/// only the value itself 'exists' already.
#define PblString_T_DefDefault                                                                                         \
  PBL_TYPE_DEFINITION_DEFAULT_STRUCT_CONSTRUCTOR(PblString_T, .allocated_len = NULL, .len = NULL, .str = NULL)

/// @brief Base Struct of PblString - avoid using this type
struct PblString_Base {
  /// @brief Amount of the chars that can be written to - includes null char (\0). This does not include the meta info
  PblUInt_T *allocated_len;
  /// @brief The length of the string - this is the length that it will take to reach the null character '\0'
  PblUInt_T *len;
  /// @brief The char* pointer to the allocated memory - the entire memory represents the array, meaning it's not an
  /// array of PblChar_T pointers, but an actual block of PblChar_T types being stuck together in memory, meaning array
  /// arithmetics are valid!
  PblChar_T *str;
};

/// @brief PBL String implementation - uses dynamic memory allocation -> located in heap
struct PblString { PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(struct PblString_Base)  };
typedef struct PblString PblString_T;

// ---- End of Declaration --------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

/**
 * @brief Gets the Length of a C string (const char*)
 * @param content The char array (pointer)
 * @return The length as Para-C Int
 */
PblUInt_T *PblGetLengthOfCString(const char *content);

/**
 * @brief Converts the passed char* array to a PblChar_T array
 * @param content The C char array
 * @param len The length that shall be used to initialise the array. This length must be exact!
 * @return The newly allocated string
 * @note This is a C to Para-C type conversion function - args are in C therefore
 */
PblChar_T *PblGetCharTArray(const char *content);

/**
 * @brief This directly converts a char* to a Para-C string type
 * @param content The char array (pointer)
 * @return The new Para-C string type, which was created using 'PblAllocateStringContentT'
 * @note This is a C to Para-C type conversion function - args are in C therefore
 */
PblString_T *PblGetStringT(const char *content);

/**
 * @brief Compares the two passed strings and returns whether they are equal
 * @param str_1 The first string
 * @param str_2 The second string
 * @return True if both strings are equal and the content does not differ, else false
 */
PblBool_T *PblCompareStringT(PblString_T *str_1, PblString_T *str_2);

/**
 * @brief Gets the required minimum array size for the string
 * @param len The length of the string that should be allocated
 * @return The length as PblUInt_T
 */
PblUInt_T *PblGetMinimumArrayLen(PblUInt_T *len);

/**
 * @brief Gets the required byte_size for an allocation based on the passed length of the string.
 * @note The algorithm will always be a multiple of 50 + 1 (for null char '\0').
 * The calculated size is the next biggest multiple of 50 + 1, which is still bigger than the passed length.
 * @param len The length of the actual string content, which will be used to calculate the allocation length.
 * @returns The size as size_t (int)
 */
PblSize_T *PblGetAllocSizeStringT(PblUInt_T *len);

/**
 * @brief Resizes the string by reallocating the memory.
 * @note Automatically calculates the size of the new allocated memory based on the length. The function used for the
 * length calculation is 'PblGetAllocSizeStringT'
 * @param str The string that should be reallocated
 * @param len The length of the string content that is used to calculate the required size
 */
PblVoid_T PblResizeStringT(PblString_T *str, PblUInt_T *len);

/**
 * @brief Converts the passed PblChar_T array into a native C char array
 * @param str The string that should be used
 * @return The char* array
 */
char *PblGetCCharArrayFromCharT(PblChar_T *char_arr, PblUInt_T *len);

/**
 * @brief Converts the passed string into a native C char array
 * @param str The string that should be used
 * @return The char* array
 */
char *PblGetCCharArrayFromString(PblString_T *str);

/**
 * @brief Writes onto the allocated memory the passed string content (PblChar_T)
 * @param len Length of the string (should not include null char)
 * @param content The content of the string that should be written to the allocated memory - C type as this should be
 * used in the back of the program
 */
PblVoid_T PblWriteCharArrayToStringT(PblString_T *str, PblChar_T *content, PblUInt_T *len_to_write);

/**
 * @brief Writes onto the allocated memory the passed string content
 * @param len Length of the string (should not include null char)
 * @param content The content of the string that should be written to the allocated memory - C type as this should be
 * used in the back of the program
 */
PblVoid_T PblWriteStringToStringT(PblString_T *str, PblString_T *content, PblUInt_T *len_to_write);

/**
 * @brief Allocates new memory for a new string
 * @note Default size/len is 50 - will be resized with additional space required using 'PblGetAllocSizeStringT'
 * @param len Length of the string - will be used to calculate allocated memory space (should not include null char)
 * @param content The content of the string that should be written to the allocated memory - C type as this should be
 * used for converting char * and char[] to PblString_T
 * @returns The new string type that was allocated
 */
PblString_T *PblCreateStringT(PblChar_T *content, PblUInt_T *len);

/**
 * @brief Allocates new memory for a new string - this function automatically calculates the minimum allocation size
 * @param byte_size The byte_size that should be allocated
 * @returns The char* pointer to the memory
 */
PblChar_T *PblAllocateStringContentT(PblUInt_T *len);

/**
 * @brief Deallocates the entire memory for the string and resets it's struct properties
 * @note Writes to the string with '\0' before freeing the memory
 * @param lvalue The value that should be de-allocated
 */
PblVoid_T PblDeallocateStringT(PblString_T *lvalue);

// ---- End of Functions Definitions ----------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif//PBL_MODULES_STRING_H

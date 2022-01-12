/// @file pbl-string.c
/// @brief String Implementation based on dynamic memory allocation - This is an optimised form of char[], which is
/// though not equal to PblChar_T[], as it does not contain meta-data tracking for each char, but altogether as an
/// entire type to save memory.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

// Parent Header for this file
#include <libpbl/types/pbl-string.h>

// General Required Header Inclusion
#include <libpbl/types/pbl-types.h>
#include <libpbl/mem/pbl-mem.h>

// ---- Functions Definitions -----------------------------------------------------------------------------------------

PblUInt_T *PblGetLengthOfCString(const char *content) {
  // Validate the pointer for safety measures
  content = PblValPtr((void *) content);

  return PblGetUIntT(strlen(content));
}

PblSize_T *PblGetUsableStrSize(PblString_T *str) {
  // Validate the pointer for safety measures
  str = PblValPtr((void *) str);

  return PblGetSizeT(str->actual.allocated_len->actual * PblChar_T_Size);
}

char *PblGetCCharArrayFromCharT(PblChar_T *char_arr, PblUInt_T *len) {
  // Validate the pointer for safety measures
  char_arr = PblValPtr((void *) char_arr);
  len = PblValPtr((void *) len);

  char *ret_arr = (char *) PblMalloc(sizeof(char) * len->actual);

  for (int i = 0; i < len->actual; i++) {
    PblMemCpy(&(ret_arr[i]), &(char_arr[i].actual), sizeof(char));
  }
  ret_arr[len->actual] = '\0';

  return ret_arr;
}

char *PblGetCCharArrayFromString(PblString_T *str) {
  // Validate the pointer for safety measures
  str = PblValPtr((void *) str);

  char *ret_arr = (char *) PblMalloc(sizeof(char) * str->actual.len->actual);

  for (int i = 0; i < str->actual.len->actual; i++) {
    PblMemCpy(&(ret_arr[i]), &(str->actual.str[i].actual), sizeof(char));
  }
  return ret_arr;
}

PblChar_T *PblGetCharTArray(const char *content) {
  // Validate the pointer for safety measures
  content = PblValPtr((void *) content);

  PblUInt_T *len = PblGetLengthOfCString(content);
  PblChar_T *pbl_chars = PblMalloc(sizeof(PblChar_T) * (len->actual + 1)// Min. size is 1 -> plus end-char: \0
  );
  for (int i = 0; i < len->actual; i++) {
    PBL_ASSIGN_TO_VAR(pbl_chars[i], PblChar_T, content[i]);
  }

  // Adding null character
  PBL_ASSIGN_TO_VAR(pbl_chars[len->actual], PblChar_T, '\0');
  return pbl_chars;
}

PblString_T *PblGetStringT(const char *content) {
  // Validate the pointer for safety measures
  content = PblValPtr((void *) content);

  // Converting the char array into the corresponding PblChar_T type
  PblUInt_T *len = PblGetLengthOfCString(content);

  return PblCreateStringT(PblGetCharTArray(content), len);
}

PblBool_T *PblCompareStringT(PblString_T *str_1, PblString_T *str_2) {
  // Validate the pointer for safety measures
  str_1 = PblValPtr((void *) str_1);
  str_2 = PblValPtr((void *) str_2);

  // Don't bother with comparison if the lengths are the same
  if (str_1->actual.len->actual != str_2->actual.len->actual)
    return PblGetBoolT(false);
  for (int i = 0; i < str_1->actual.len->actual; i++) {
    if (str_1->actual.str[i].actual != str_2->actual.str[i].actual)
      return PblGetBoolT(false);
  }
  return PblGetBoolT(true);
}

PblUInt_T *PblGetMinimumArrayLen(PblUInt_T *len) {
  // Validate the pointer for safety measures
  len = PblValPtr((void *) len);

  unsigned int alloc_len = 0;
  // The size of the allocated memory should always be bigger than the actual content
  // The length DOES NOT include the end byte, but only the actual content
  if (len->actual < 50) {
    alloc_len = 50;
  } else if (len->actual >= 50) {
    while (alloc_len < len->actual) alloc_len += 50;
  }
  return PblGetUIntT((alloc_len + 1));
}

PblSize_T *PblGetAllocSizeStringT(PblUInt_T *len) {
  // Validate the pointer for safety measures
  len = PblValPtr((void *) len);

  PblUInt_T *min_arr_len = PblGetMinimumArrayLen(len);
  PblSize_T *size = PblGetSizeT(min_arr_len->actual * sizeof(PblChar_T));
  // Deallocating early even with a garbage collector to save a small amount of time
  PblFree(min_arr_len);
  return size;
}

PblVoid_T PblResizeStringT(PblString_T *str, PblUInt_T *len) {
  // Validate the pointer for safety measures
  str = PblValPtr((void *) str);
  len = PblValPtr((void *) len);

  PblSize_T *byte_size = PblGetAllocSizeStringT(len);

  // Reallocating the memory with the new length - includes space for '\0' byte
  str->actual.str = PblRealloc(str->actual.str, byte_size->actual);
  // Calculating the size based on the allocation - the allocated memory is split into PblChar_T types
  str->actual.allocated_len = PblGetUIntT(byte_size->actual / sizeof(PblChar_T));
  str->actual.len->actual = len->actual;
  return PblVoid_T_DeclDefault;
}

PblVoid_T PblWriteStringToStringT(PblString_T *str, PblString_T *content, PblUInt_T *len_to_write) {
  // Validate the pointer for safety measures
  str = PblValPtr((void *) str);
  content = PblValPtr((void *) content);
  len_to_write = PblValPtr((void *) len_to_write);

  PBL_CREATE_NEW_ARRAY(char_arr, PblChar_T, len_to_write->actual);
  for (int i = 0; i < len_to_write->actual; i++) {
    // Using MemCpy to properly copy the value, aka. to be certain it is copied properly
    PblMemCpy(&char_arr[i], &content->actual.str[i], sizeof(PblChar_T));
  }

  PblWriteCharArrayToStringT(str, char_arr, len_to_write);
  return PblVoid_T_DeclDefault;
}

PblVoid_T PblWriteCharArrayToStringT(PblString_T *str, PblChar_T *content, PblUInt_T *len_to_write) {
  // Validate the pointer for safety measures
  str = PblValPtr((void *) str);
  content = PblValPtr((void *) content);
  len_to_write = PblValPtr((void *) len_to_write);

  // Don't bother writing when the length to write is 0
  if (len_to_write->actual == 0)
    return PblVoid_T_DeclDefault;

  PblUInt_T *required_size = PblGetMinimumArrayLen(len_to_write);
  // If the required space is bigger that means that the available space is not sufficient
  if (required_size->actual > str->actual.allocated_len->actual)
    PblResizeStringT(str, len_to_write);

  int i = 0;
  for (; i < len_to_write->actual; i++)
    // Copying from the source string to the destination block of memory
    PblMemCpy(&(str->actual.str[i]), &(content[i]), sizeof(PblChar_T));
  // Adding null character
  str->actual.str[i].actual = '\0';
  // Resetting length
  str->actual.len->actual = len_to_write->actual;

  // Updating meta data
  str->meta.defined = true;
  return PblVoid_T_DeclDefault;
}

PblString_T *PblCreateStringT(PblChar_T *content, PblUInt_T *len) {
  // Validate the pointer for safety measures
  content = PblValPtr((void *) content);
  len = PblValPtr((void *) len);

  // Using the DeclDefault to avoid recursion when 'DefDefault' is 'PblGetStringT("")' aka. an empty string
  PBL_DEFINE_VAR(str, PblString_T);

  str->actual.allocated_len = PblGetMinimumArrayLen(len);
  str->actual.len = len;
  str->actual.str = PblAllocateStringContentT(len);

  // Safe writing null char to the beginning
  str->actual.str[0].actual = '\0';

  PblWriteCharArrayToStringT(str, content, len);

  return str;
}

PblChar_T *PblAllocateStringContentT(PblUInt_T *len) {
  // Validate the pointer for safety measures
  len = PblValPtr((void *) len);

  // length = len * sizeof(PblChar_T) + 1 (null character (\0))
  PblSize_T *byte_size = PblGetAllocSizeStringT(len);
  PblChar_T *ptr = PblMalloc(byte_size->actual);
  // Early de-allocating to save a little amount of time
  PblFree(byte_size);
  return ptr;
}

PblVoid_T PblDeallocateStringT(PblString_T *lvalue) {
  // Validate the pointer for safety measures
  lvalue = PblValPtr((void *) lvalue);

  if (lvalue->meta.defined) {
    // Writing \0 onto the entire space of memory
    PBL_CREATE_NEW_ARRAY(nullify, PblChar_T, lvalue->actual.len->actual);
    for (int i = 0; i < lvalue->actual.len->actual; i++)
      nullify[i].actual = '\0';
    PblWriteCharArrayToStringT(lvalue, nullify, lvalue->actual.len);

    if (lvalue->actual.allocated_len != NULL) {
      PblFree(lvalue->actual.allocated_len);
      lvalue->actual.allocated_len = NULL;
    }
    if (lvalue->actual.str != NULL) {
      // Deallocating the str, since it's a pointer to an array of PblChar_T type instances
      PblFree(lvalue->actual.str);
      lvalue->actual.str = NULL;
    }
    if (lvalue->actual.len != NULL) {
      PblFree(lvalue->actual.len);
      lvalue->actual.len = NULL;
    }
    *lvalue = PblString_T_DeclDefault;
    lvalue = NULL;
  }

  return PblVoid_T_DeclDefault;
}

// TODO! Add copy string function

// ---- End of Function Definitions -----------------------------------------------------------------------------------

///
/// String Implementation based on dynamic memory allocation
///
/// @author Luna-Klatzer

#include <stdbool.h>
#include <string.h>

#include "./pbl-string.h"
#include "./pbl-types.h"
#include "./pbl-mem.h"

PblUInt_T PblGetLengthOfCString(const char *content) {
  // Validate the pointer for safety measures
  content = PblValPtr((void*) content);

  return PblGetUIntT(strlen(content));
}

PblSize_T PblGetUsableStrSize(PblString_T* str) {
  return PblGetSizeT(str->actual.allocated_len.actual * PblChar_T_Size);
}

PblChar_T* PblGetCharTArray(const char* content) {
  PblUInt_T len = PblGetLengthOfCString(content);
  PblChar_T* pbl_chars = PblMalloc(
    PblGetSizeT(
      sizeof(PblChar_T) * (len.actual + 1) // Min. size is 1 -> plus end-char: \0
      )
    );
  for (int i = 0; i < len.actual; i++) pbl_chars[i] = PblGetCharT(content[i]);
  // adding null character
  pbl_chars[len.actual] = PblGetCharT('\0');
  return pbl_chars;
}

PblString_T PblGetStringT(const char *content) {
  // Validate the pointer for safety measures
  content = PblValPtr((void*) content);

  // converting the char array into the corresponding PblChar_T type
  PblUInt_T len = PblGetLengthOfCString(content);

  return PblCreateStringT(PblGetCharTArray(content), len);
}

PblBool_T PblCompareStringT(PblString_T* str_1, PblString_T* str_2) {
  for (int i = 0; i < str_1->actual.len.actual; i++) {
    if (str_1->actual.str[i].actual != str_2->actual.str[i].actual) return PblGetBoolT(false);
  }
  return PblGetBoolT(true);
}

PblSize_T PblGetAllocSizeStringT(PblUInt_T len) {
  unsigned int alloc_len = 0;
  // The size of the allocated memory should always be bigger than the actual content
  // The length DOES NOT include the end byte, but only the actual content
  if (len.actual < 50) {
    alloc_len = 50;
  } else if (len.actual >= 50) {
    while (alloc_len <= len.actual) alloc_len += 50;
  }
  return PblGetSizeT((alloc_len + 1) * sizeof(PblChar_T));
}

PblVoid_T PblResizeStringT(PblString_T *str, PblUInt_T len) {
  // Validate the pointer for safety measures
  str = PblValPtr((void*) str);

  PblSize_T byte_size = PblGetAllocSizeStringT(len);

  // Reallocating the memory with the new length - includes space for '\0' byte
  str->actual.str = PblRealloc(str->actual.str, byte_size);
  // Calculating the size based on the allocation - the allocated memory is split into PblChar_T types
  str->actual.allocated_len = PblGetUIntT(byte_size.actual / sizeof(PblChar_T));
  str->actual.len = len;
  return PblVoid_T_DeclDefault;
}

PblVoid_T PblWriteToStringT(PblString_T *str, PblChar_T *content, PblUInt_T len_to_write) {
  // Validate the pointer for safety measures
  str = PblValPtr((void*) str);
  content = PblValPtr((void*) content);

  // Don't bother writing when the length to write is 0
  if (len_to_write.actual == 0) return PblVoid_T_DeclDefault;

  PblSize_T required_size = PblGetAllocSizeStringT(len_to_write);
  // bigger or equal means that the required space is bigger than the actual space available,
  // equal is also included since even if it's equal the null-byte needs to be added as well (+1 byte)
  if (required_size.actual >= str->actual.allocated_len.actual) {
    PblResizeStringT(str, len_to_write);
  }

  int i = 0;
  for (; i < len_to_write.actual; i++) { str->actual.str[i] = (PblChar_T) content[i]; }
  // adding null character
  str->actual.str[i].actual = '\0';

  // updating meta data
  str->meta.defined = true;
  return PblVoid_T_DeclDefault;
}

PblString_T PblCreateStringT(PblChar_T *content, PblUInt_T len) {
  // Validate the pointer for safety measures
  content = PblValPtr((void*) content);

  // allocated memory - length = len * size PblChar_T + 1 (null character (\0))
  PblSize_T byte_size = PblGetAllocSizeStringT(len);
  PblChar_T* alloc_begin = PblAllocateStringContentT(byte_size);

  // Using the DeclDefault to avoid recursion when 'DefDefault' is 'PblGetStringT("")' aka. an empty string
  PblString_T str = PblString_T_DefDefault;
  // Calculating the size based on the allocation - the allocated memory is split into PblChar_T types
  str.actual.allocated_len = PblGetUIntT(byte_size.actual / sizeof(PblChar_T));
  str.actual.len = len;
  str.actual.str = alloc_begin;

  // safe writing null char to the beginning
  str.actual.str[0].actual = '\0';

  PblWriteToStringT(&str, content, len);
  return str;
}

PblChar_T *PblAllocateStringContentT(PblSize_T byte_size) {
  return PblMalloc(byte_size);
}

PblVoid_T PblSafeDeallocateStringT(PblString_T *lvalue) {
  // Validate the pointer for safety measures
  lvalue = PblValPtr((void*) lvalue);

  if (lvalue->meta.defined) {
    // writing \0 onto the entire space of memory
    PblChar_T nullify[lvalue->actual.len.actual];
    for (int i = 0; i < lvalue->actual.len.actual; i++) nullify[i].actual = '\0';
    PblWriteToStringT(lvalue, nullify, lvalue->actual.len);

    PblFree(lvalue->actual.str);
    *lvalue = PblString_T_DeclDefault;
  }

  return PblVoid_T_DeclDefault;
}

// TODO! Add copy string function
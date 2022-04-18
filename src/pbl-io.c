/// @file pbl-io.c
/// @brief IO Implementation based on stdio.h
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021 - 2022

// Parent Header for this file
#include <libpbl/pbl-io.h>

// General Required Header Inclusion
#include "libpbl/core/pbl-mem.h"
#include <libpbl/types/pbl-string.h>

// ---- Globals -------------------------------------------------------------------------------------------------------

__attribute__((unused)) PblIOStream_T* PBL_STDIN = NULL;
__attribute__((unused)) PblIOStream_T* PBL_STDOUT = NULL;
__attribute__((unused)) PblIOStream_T* PBL_STDERR = NULL;

// ---- End of Globals ------------------------------------------------------------------------------------------------

// ---- File Setup ----------------------------------------------------------------------------------------------------

PBL_INIT_FILE;
PBL_INIT_GLOBALS {
  PBL_REGISTER_TYPE(&LOCAL_TYPE_LIST, PblIOFile_T, "IOFile", false, true);
  PBL_REGISTER_TYPE(&LOCAL_TYPE_LIST, PblIOStream_T, "IOStream", false, true);

  // Init global file descriptors
  PBL_STDIN = PblGetIOStreamT(0, "a");
  PBL_STDOUT = PblGetIOStreamT(1, "a");
  PBL_STDERR = PblGetIOStreamT(2, "a");
};

// ---- End of File Setup ---------------------------------------------------------------------------------------------

// ---- Functions Definitions -----------------------------------------------------------------------------------------

PblIOFile_T *PblGetIOFileT(FILE *val) {
  // Validate the pointer for safety measures
  val = PblValPtr(val);

  PblIOFile_T *conv = PblMalloc(sizeof(PblIOFile_T));
  *conv = PblIOFile_T_DefDefault;
  conv->actual = val;
  return conv;
}

PblIOStream_T *PblGetIOStreamT(int fd, const char *mode) {
  // Validate the pointer for safety measures
  mode = PblValPtr((void *) mode);

  PblIOStream_T *conv = PblMalloc(sizeof(PblIOStream_T));
  *conv = PblIOStream_T_DefDefault;
  conv->actual.fd = PblGetUIntT((signed int) fd);
  conv->actual.file = PblGetIOFileT(fdopen(fd, mode));
  conv->actual.mode = PblGetStringT(mode);
  conv->actual.open = PblGetBoolT(true);
  return conv;
}

PblChar_T *PblInputChar_Base(PblString_T *display_msg, PblChar_T *end) {
  PblPrint(display_msg, .end = end);

  char in_char = (char) getchar();
  // Avoid returning \n or EOF by replacing it with \0
  return in_char == '\n' || (int) in_char == EOF ? '\0' : PblGetCharT(in_char);
}

__attribute__((unused)) PblChar_T *PblInputChar_Overhead(struct PblInputChar_Args in) {
  // Validate the pointer for safety measures
  PblString_T *display_msg = PBL_VAL_REQ_ARG(in.display_msg);
  PblChar_T *end = in.end != NULL ? in.end : PblGetCharT('\0');
  return PblInputChar_Base(display_msg, end);
}

PblString_T *PblInput_Base(PblString_T *display_msg, PblChar_T *end) {
  // Printing the initial display message
  PblPrint(display_msg, .end = end);

  // Initial size
  unsigned int length = 100;
  // Allocate mem for 100 chars
  char *in_str = PblMalloc(length * sizeof(char));
  // Keep Track of how many chars where inputted now
  int count = 0;

  char c;
  // Run as long as it's not a newline
  while ((c = (char) getchar()) != '\n') {
    // If the character is EOF, abort immediately
    // (This should not happen though on a console stream, but covering for possible edge cases )
    if (c == EOF) break;

    if (count >= length) {
      // Resize the buffer. We increase each time with 50
      length += 50;
      in_str = PblRealloc(in_str, length * sizeof(char));
    }
    // Writing the char into the name
    in_str[count++] = c;
  }
  return PblGetStringT(in_str);
}

__attribute__((unused)) PblString_T *PblInput_Overhead(struct PblInput_Args in) {
  // Validate the pointer for safety measures
  PblString_T *display_msg = PBL_VAL_REQ_ARG(in.display_msg);
  PblChar_T *end = in.end != NULL ? in.end : PblGetCharT('\0');
  return PblInput_Base(display_msg, end);
}

PblVoid_T PblPrint_Base(PblString_T *out, PblIOStream_T *stream, PblChar_T *end) {
  // Validate the pointer for safety measures
  out = PblValPtr((void *) out);

  for (int i = 0; i < out->actual.len->actual; i++)
    fprintf(stream->actual.file->actual, "%c", (out->actual.str[i].actual));
  fprintf(stream->actual.file->actual, "%c", end->actual);
  return PblVoid_T_DeclDefault;
}

__attribute__((unused)) PblVoid_T PblPrint_Overhead(struct PblPrint_Args in) {
  // Validate the pointer for safety measures
  PblString_T *out = PBL_VAL_REQ_ARG(in.out);

  PblIOStream_T *stream;
  if (in.stream != NULL) {
    stream = in.stream;
  } else {
    stream = PblMalloc(sizeof(PblIOStream_T));
    *stream = *PBL_STDOUT;
  }
  PblChar_T *end = in.end != NULL ? in.end : PblGetCharT('\n');
  return PblPrint_Base(out, stream, end);
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

/// @file pbl-io.c
/// @brief IO Implementation based on stdio.h
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

// Parent Header for this file
#include <libpbl/io/pbl-io.h>

// General Required Header Inclusion
#include <libpbl/mem/pbl-mem.h>
#include <libpbl/types/pbl-string.h>

// ---- Functions Definitions -----------------------------------------------------------------------------------------

PblFile_T *PblGetFileT(FILE *val) {
  // Validate the pointer for safety measures
  val = PblValPtr(val);

  PblFile_T *conv = PblMalloc(sizeof(PblFile_T));
  *conv = PblFile_T_DefDefault;
  conv->actual = val;
  return conv;
}

PblStream_T *PblGetStreamT(int fd, const char *mode) {
  // Validate the pointer for safety measures
  mode = PblValPtr((void *) mode);

  PblStream_T *conv = PblMalloc(sizeof(PblStream_T));
  *conv = PblStream_T_DefDefault;
  conv->actual.fd = PblGetUIntT((signed int) fd);
  conv->actual.file = PblGetFileT(fdopen(fd, mode));
  conv->actual.mode = PblGetStringT(mode);
  conv->actual.open = PblGetBoolT(true);
  return conv;
}

PblVoid_T PblPrint_Base(PblString_T *out, const PblStream_T *stream, const PblChar_T *end) {
  // Validate the pointer for safety measures
  out = PblValPtr((void *) out);

  for (int i = 0; i < out->actual.len->actual; i++)
    fprintf(stream->actual.file->actual, "%c", (out->actual.str[i].actual));
  fprintf(stream->actual.file->actual, "%c", end->actual);
  return PblVoid_T_DeclDefault;
}

PblVoid_T PblPrint_Overhead(struct PblPrint_Args in) {
  // Validate the pointer for safety measures
  PblString_T *out = PblValPtr((void *) in.out);

  PblStream_T *stream;
  if (in.stream != NULL) {
    stream = in.stream;
  } else {
    stream = PblMalloc(sizeof(PblStream_T));
    *stream = PBL_STREAM_STDOUT;
  }
  PblChar_T *end = in.end != NULL ? in.end : PblGetCharT('\n');
  return PblPrint_Base(out, stream, end);
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

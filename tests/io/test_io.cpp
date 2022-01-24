///
/// Testing for the header pbl-io.h
///
/// @author Luna-Klatzer

// Including the required GTest
#include "gtest/gtest.h"

// Including the header to be tested
#define PBL_DEBUG_VERBOSE
#define PBL_OVERWRITE_DEFAULT_ALLOC_FUNCTIONS
#include <libpbl/io/pbl-io.h>

TEST(IOFileTest, ConversionCheck) {
  FILE *val = fdopen(1, "a");
  PblIOFile_T *stream = PblGetIOFileT(val);

  EXPECT_EQ(stream->actual, val);
  EXPECT_EQ(stream->meta.defined, true);
  EXPECT_EQ(PblFile_T_Size, sizeof(FILE *));
}

TEST(IOStreamTest, ConversionCheck) {
  PblIOStream_T *stream = PblGetIOStreamT(1, "a");

  EXPECT_EQ(stream->actual.fd->actual, 1);
  PblString_T *mode = PblGetStringT("a");
  EXPECT_TRUE(PblCompareStringT(stream->actual.mode, mode)->actual);
  EXPECT_EQ(stream->actual.open->actual, true);
  EXPECT_EQ(stream->meta.defined, true);
  EXPECT_EQ(PblStream_T_Size, sizeof(PblString_T *) + sizeof(PblUInt_T *) + sizeof(PblIOFile_T *) + sizeof(PblBool_T *));
}

TEST(IOPrintTest, SimplePrint) {
  PblString_T *str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(11));

  // size is per default 50 + 1 (for null char)
  EXPECT_EQ(str->actual.allocated_len->actual, 51);

  PblPrint(.out = str, .end = PblGetCharT(' '));
  PblPrint(str);

  // deallocating the string
  PblDeallocateStringT(str);
}

TEST(IOPrintTest, SimplePrintWithSetStream) {
  PblString_T *str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(11));

  // size is per default 50 + 1 (for null char)
  EXPECT_EQ(str->actual.allocated_len->actual, 51);

  PblIOStream_T *stream = (PblIOStream_T *) PblMalloc(sizeof(PblIOStream_T));
  *stream = PBL_STREAM_STDOUT;
  PblPrint(.out = str, .stream = stream);

  // deallocating the string
  PblDeallocateStringT(str);
}

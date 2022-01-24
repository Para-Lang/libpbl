///
/// Testing for the macros in the header pbl.h
///
/// @author Luna-Klatzer

// Including the required GTest
#include "gtest/gtest.h"

// Including the header to be tested
#define PBL_DEBUG_VERBOSE
#define PBL_OVERWRITE_DEFAULT_ALLOC_FUNCTIONS
#include <libpbl/pbl.h>
#define PBL_DEBUG_VERBOSE
#define PBL_OVERWRITE_DEFAULT_ALLOC_FUNCTIONS
#include <libpbl/io/pbl-io.h>
#define PBL_DEBUG_VERBOSE
#define PBL_OVERWRITE_DEFAULT_ALLOC_FUNCTIONS
#include <libpbl/types/pbl-string.h>

TEST(BaseFunctionalityTest, SimpleStringPrintCheck) {
  PblString_T *string_1 = PblGetStringT("'PblGetStringT' = This is a simple string inside a test program");
  PblPrint(string_1);

  PblString_T *string_2 = PblGetStringT("'PblGetStringT' = Thus this is a simple string inside a test program");
  PblPrint(string_2);

  if (PblCompareStringT(string_1, string_2))
  {
    PblPrint(PblGetStringT("'PblCompareStringT' = The strings are not equal"));
  }
}

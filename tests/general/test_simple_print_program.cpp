///
/// Testing for the macros in the header pbl.h
///
/// @author Luna-Klatzer

// Including the required GTest
#include "gtest/gtest.h"

// Including the header to be tested
#include <libpbl/pbl.h>
#include <libpbl/io/pbl-io.h>
#include <libpbl/types/pbl-string.h>

TEST(BaseFunctionalityTest, SimpleStringPrintCheck) {
  PblString_T *string1 = PblGetStringT("'PblGetStringT' = This is a simple string inside a test program");
  PblPrint(string1);

  PblString_T *string2 = PblGetStringT("'PblGetStringT' = Thus this is a simple string inside a test program");
  PblPrint(string2);

  if (PblCompareStringT(string1, string2))
  {
    PblPrint(PblGetStringT("'PblCompareStringT' = The strings are not equal"));
  }
}

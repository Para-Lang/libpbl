///
/// Testing for the macros in the header pbl.h
///
/// @author Luna-Klatzer

// Including the required GTest
#include "gtest/gtest.h"

// Including the header to be tested
#include <libpbl/pbl.h>

TEST(MacroTest, SimpleCheckForExistances) {
  EXPECT_TRUE(PBL_VERSION);
  EXPECT_STREQ(PBL_VERSION, "0.1.dev6");
}
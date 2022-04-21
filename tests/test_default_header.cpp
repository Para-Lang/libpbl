/**
 * Testing for the macros in the header pbl.h
 * @author Luna Klatzer
 */

// Including the required GTest
#include "gtest/gtest.h"

// Including the header to be tested
#define PBL_DEBUG_VERBOSE
#define PBL_OVERWRITE_DEFAULT_ALLOC_FUNCTIONS
#include "libpbl/pbl.h"

// ---- File Setup ----------------------------------------------------------------------------------------------------

PBL_INIT_FILE(test_default_header);
PBL_INIT_GLOBALS{};

// ---- End of File Setup ---------------------------------------------------------------------------------------------

TEST(MacroTest, SimpleCheckForExistances) {
  EXPECT_TRUE(PBL_VERSION);
  EXPECT_STREQ(PBL_VERSION, "0.1.dev6");
}
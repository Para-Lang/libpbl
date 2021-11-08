/// Testing for the header pbl-string.h
///
/// @author Luna-Klatzer

#include <pbl/pbl.h>
#include "gtest/gtest.h"

// IMPORTANT! When actually using PblString_T, do NOT use a bigger length than of the actual string

TEST(StringTypesTest, GetLenghtOfCString) {
  EXPECT_EQ(PblGetLengthOfCString("")->actual, 0);
  EXPECT_EQ(PblGetLengthOfCString("1234567890")->actual, 10);
  EXPECT_EQ(PblGetLengthOfCString("12345678901234567890123456789012345678901234567890")->actual, 50);
}

TEST(StringTypesTest, GetStringConversion) {
  PblString_T* string_1 = PblGetStringT("hello");

  EXPECT_EQ(
    PblString_T_Size,
    sizeof(PblSize_T *) + sizeof(PblUInt_T *) + sizeof(PblUInt_T *) + sizeof(char *)
  );
  EXPECT_EQ(string_1->actual.len->actual, 5);
  EXPECT_EQ(string_1->actual.allocated_len->actual, 51);

  PblString_T* string_2 = PblGetStringT("world");

  EXPECT_EQ(
    PblString_T_Size,
    sizeof(PblSize_T *) + sizeof(PblUInt_T *) + sizeof(PblUInt_T *) + sizeof(char *)
  );
  EXPECT_EQ(string_2->actual.len->actual, 5);
  EXPECT_EQ(string_2->actual.allocated_len->actual, 51);

  // deallocating the strings
  PblDeallocateStringT(string_1);
  PblDeallocateStringT(string_2);
}

TEST(StringTypesTest, SimpleAllocation1) {
  PblString_T* str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(15));

  // size is per default 50 + 1 (for null char)
  EXPECT_EQ(str->actual.allocated_len->actual, 51);

  // deallocating the string
  PblDeallocateStringT(str);
}

TEST(StringTypesTest, SimpleAllocation2) {
  PblString_T* str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(60));

  // size is per default 50 + 1 (for null char) - will be resized to 100, since len is 60
  EXPECT_EQ(str->actual.allocated_len->actual, 101);

  // deallocating the string
  PblDeallocateStringT(str);
}

TEST(StringTypesTest, SimpleAllocation3) {
  PblString_T* str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(600));

  // size is per default 50 + 1 (for null char) - will be resized to 100, since len is 60
  EXPECT_EQ(str->actual.allocated_len->actual, 601);

  // deallocating the string
  PblDeallocateStringT(str);
}

TEST(StringTypesTest, ValidateDeallocation) {
  PblString_T* str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(49));

  // size is per default 50 + 1 (for null char) - will be resized to 100, since len is 60
  EXPECT_EQ(str->actual.allocated_len->actual, 51);

  // deallocating the string
  PblDeallocateStringT(str);
}

TEST(StringTypesTest, ValidateAllocation) {
  PblString_T* str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(49));

  // size is per default 50 + 1 (for null char)
  EXPECT_EQ(str->actual.allocated_len->actual, 51);
  EXPECT_EQ(str->actual.len->actual, 49);

  // deallocating the string
  PblDeallocateStringT(str);
}

TEST(StringTypesTest, ValidateOverwrite) {
  PblString_T* str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(11));
  // size is per default 50 + 1 (for null char)
  EXPECT_EQ(str->actual.allocated_len->actual, 51);
  EXPECT_EQ(str->actual.len->actual, 11);

  PblWriteCharArrayToStringT(str, PblGetCharTArray("Hello World!!!!"), PblGetUIntT(15));
  EXPECT_EQ(str->actual.allocated_len->actual, 51);
  EXPECT_EQ(str->actual.len->actual, 15);

  // deallocating the string
  PblDeallocateStringT(str);
}

TEST(StringTypesTest, ValidateReallocOverwrite) {
  PblString_T* str = PblCreateStringT(PblGetCharTArray("hello world"), PblGetUIntT(11));
  // size is per default 50 + 1 (for null char)
  EXPECT_EQ(str->actual.allocated_len->actual, 51);
  EXPECT_EQ(str->actual.len->actual, 11);

  PblWriteCharArrayToStringT(str, PblGetCharTArray("12345678901234567890123456789012345678901234567890"), PblGetUIntT(50));
  EXPECT_EQ(str->actual.allocated_len->actual, 51);
  EXPECT_EQ(str->actual.len->actual, 50);

  // deallocating the string
  PblDeallocateStringT(str);
}

TEST(StringTypesTest, GetMinimumArrayLen) {
  EXPECT_EQ(PblGetMinimumArrayLen(PblGetUIntT(10))->actual, 51);
  EXPECT_EQ(PblGetMinimumArrayLen(PblGetUIntT(100))->actual, 101);
  EXPECT_EQ(PblGetMinimumArrayLen(PblGetUIntT(500))->actual, 501);
}

TEST(StringTypesTest, GetAllocSizeStringT) {
  EXPECT_EQ(PblGetAllocSizeStringT(PblGetUIntT(10))->actual, 51 * sizeof(PblChar_T));
  EXPECT_EQ(PblGetAllocSizeStringT(PblGetUIntT(100))->actual, 101 * sizeof(PblChar_T));
  EXPECT_EQ(PblGetAllocSizeStringT(PblGetUIntT(500))->actual, 501 * sizeof(PblChar_T));
}

TEST(StringTypesTest, PblGetCCharArrayFromCharT) {
  PblChar_T* char_arr_1 = PblGetCharTArray("hello");
  PblChar_T* char_arr_2 = PblGetCharTArray("hello world");
  PblChar_T* char_arr_3 = PblGetCharTArray("hello new world");

  EXPECT_STREQ(PblGetCCharArrayFromCharT(char_arr_1, PblGetUIntT(5)), "hello");
  EXPECT_STREQ(PblGetCCharArrayFromCharT(char_arr_2, PblGetUIntT(11)), "hello world");
  EXPECT_STREQ(PblGetCCharArrayFromCharT(char_arr_3, PblGetUIntT(15)), "hello new world");
}

TEST(StringTypesTest, PblGetCCharArrayFromString) {
  PblString_T* str_1 = PblGetStringT("hello");
  PblString_T* str_2 = PblGetStringT("hello world");
  PblString_T* str_3 = PblGetStringT("hello new world");

  EXPECT_STREQ(PblGetCCharArrayFromString(str_1), "hello");
  EXPECT_STREQ(PblGetCCharArrayFromString(str_2), "hello world");
  EXPECT_STREQ(PblGetCCharArrayFromString(str_3), "hello new world");
}

TEST(StringTypesTest, PblWriteStringToStringT) {
  PblString_T* str_1 = PblGetStringT("hello");
  PblString_T* str_2 = PblGetStringT("hello world");
  PblString_T* str_3 = PblGetStringT("hello new world");
  PblString_T* str_4 = PblGetStringT("hello new world world");

  EXPECT_FALSE(PblCompareStringT(str_1, str_2)->actual);
  EXPECT_FALSE(PblCompareStringT(str_2, str_3)->actual);
  EXPECT_FALSE(PblCompareStringT(str_3, str_4)->actual);

  PblWriteStringToStringT(str_1, PblGetStringT("hello x"), PblGetUIntT(7));
  PblWriteStringToStringT(str_2, PblGetStringT("hello x"), PblGetUIntT(7));
  PblWriteStringToStringT(str_3, PblGetStringT("hello x"), PblGetUIntT(7));
  PblWriteStringToStringT(str_4, PblGetStringT("hello x"), PblGetUIntT(7));

  EXPECT_TRUE(PblCompareStringT(str_1, str_2)->actual);
  EXPECT_TRUE(PblCompareStringT(str_2, str_3)->actual);
  EXPECT_TRUE(PblCompareStringT(str_3, str_4)->actual);
}
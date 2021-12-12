///
/// Testing for the header pbl-exception.h
///
/// @author Luna-Klatzer

// Including the required GTest
#include "gtest/gtest.h"

// Including the header to be tested
#include <libpbl/func/pbl-function.h>

TEST(FunctionMetaTest, PblMetaFunctionCallCtxDefaults) {
  PBL_DECLARE_VAR(v_1, PblFunctionCallMetaData_T);

  EXPECT_EQ(PblFunctionCallMetaData_T_Size, sizeof(PblBool_T *) + sizeof(PblUInt_T *) + sizeof(PblBool_T *) +
                                              2 * sizeof(PblFunctionCallMetaData_T *) + sizeof(NULL));
  EXPECT_EQ(v_1->meta.defined, false);

  PBL_DEFINE_VAR(v_2, PblFunctionCallMetaData_T);

  EXPECT_TRUE(v_2->actual.call_origin_ctx == NULL);
  EXPECT_TRUE(v_2->actual.exception == NULL);
  EXPECT_TRUE(v_2->actual.failure_origin_ctx == NULL);
  EXPECT_TRUE(v_2->actual.is_failure == NULL);
  EXPECT_TRUE(v_2->actual.arg_amount == NULL);
  EXPECT_TRUE(v_2->actual.function_identifier == NULL);
  EXPECT_EQ(PblFunctionCallMetaData_T_Size, sizeof(PblBool_T *) + sizeof(PblUInt_T *) + sizeof(PblBool_T *) +
                                              2 * sizeof(PblFunctionCallMetaData_T *) + sizeof(NULL));
  EXPECT_TRUE(v_2->meta.defined);
}

TEST(ExceptionTest, PblExceptionDefaults) {
  PBL_DECLARE_VAR(v_1, PblException_T);

  EXPECT_EQ(PblException_T_Size, 4 * sizeof(PblString_T *) + sizeof(PblUInt_T *) + 2 * sizeof(void *));
  EXPECT_EQ(v_1->meta.defined, false);

  PBL_DEFINE_VAR(v_2, PblException_T);

  EXPECT_TRUE(v_2->actual.child_exc == NULL);
  EXPECT_TRUE(v_2->actual.parent_exc == NULL);
  EXPECT_TRUE(v_2->actual.name == NULL);
  EXPECT_TRUE(v_2->actual.msg == NULL);
  EXPECT_TRUE(v_2->actual.filename == NULL);
  EXPECT_TRUE(v_2->actual.line_content == NULL);
  EXPECT_TRUE(v_2->actual.line == NULL);
  EXPECT_EQ(PblException_T_Size, 4 * sizeof(PblString_T *) + sizeof(PblUInt_T *) + 2 * sizeof(void *));
  EXPECT_EQ(v_2->meta.defined, true);
}

PblInt_T *NestedTestFunction(PblFunctionCallMetaData_T *this_call_meta, PblUInt_T *i) {
  PblUInt_T *line = PblGetUIntT(__LINE__);
  PblException_T *exception =
    PblGetExceptionT(PblGetStringT("test"), PblGetStringT("TestException"), PblGetStringT(__FILE__), line,
                     PblGetStringT("raise exception"), NULL, NULL);
  PBL_RAISE_EXCEPTION(exception, PblInt_T);
}

PblInt_T *TestFunction(PblFunctionCallMetaData_T *this_call_meta) {
  PBL_DECLARE_VAR(r_1, PblInt_T);

  /// creating a copy of the addr, if the pointer is accidentally set to NULL by the function returning NULL (due to
  /// the exception occurring)
  PBL_CREATE_ADDRESS_COPY(r_1, PblInt_T *, H3);
  PBL_CALL_FUNC_AND_CATCH(NestedTestFunction, r_1, X1, PblGetUIntT(1));

  // if the function failed, treat the return as invalid -> restore previous value
  // in this case the function raises an exception and as such it will never reach this code
  if (this_call_meta->actual.is_failure->actual) {
    // Restore if NULL -> here it should be restored as NULL is returned
    PBL_WRITE_BACK_ADDRESS_COPY(r_1, H3);
  }
  return r_1;
}

TEST(ExceptionTest, OneNestCall) {
  PBL_DECLARE_VAR(r_1, PblInt_T);
  PBL_DEFINE_VAR(this_call_meta, PblFunctionCallMetaData_T);
  this_call_meta->actual.is_failure = PblGetBoolT(false);

  // creating a copy of the addr, if the pointer is accidentally set to NULL by the function returning NULL (due to
  // the exception occurring)
  PBL_CREATE_ADDRESS_COPY(r_1, PblInt_T *, H3);
  /// Call the function and update the local ctx if an exception was raised
  PBL_BASE_CALL_AND_CATCH_EXCEPTION(TestFunction, r_1, H3, PblGetBoolT(false), this_call_meta, );

  // if the function failed, treat the return as invalid -> restore previous value
  if (this_call_meta->actual.is_failure->actual) {
    // Restore if NULL -> here it should be restored as NULL is returned
    PBL_WRITE_BACK_ADDRESS_COPY(r_1, H3);
  }

  // the return should have failed aka. the value should have been set to NULL and then restored by
  // 'PBL_PASTE_ADDRESS_COPY'
  EXPECT_EQ(r_1->meta.defined, false);
  EXPECT_TRUE(this_call_meta->actual.is_failure->actual);
  EXPECT_TRUE(this_call_meta->actual.failure_origin_ctx != NULL);
  EXPECT_TRUE(this_call_meta->actual.exception != NULL);
  EXPECT_TRUE(this_call_meta->actual.call_origin_ctx == NULL);
  PblString_T *default_name = PblGetStringT("test");
  EXPECT_TRUE(
    PblCompareStringT(((PblException_T *) this_call_meta->actual.exception)->actual.msg, default_name)->actual);
  PblString_T *default_msg = PblGetStringT("TestException");
  EXPECT_TRUE(
    PblCompareStringT(((PblException_T *) this_call_meta->actual.exception)->actual.name, default_msg)->actual);
  PblString_T *default_filename = PblGetStringT(__FILE__);
  EXPECT_TRUE(
    PblCompareStringT(((PblException_T *) this_call_meta->actual.exception)->actual.filename, default_filename)
      ->actual);
  PblString_T *default_line_content = PblGetStringT("raise exception");
  EXPECT_TRUE(
    PblCompareStringT(((PblException_T *) this_call_meta->actual.exception)->actual.line_content, default_line_content)
      ->actual);
}

PblInt_T *TestFunction2(PblFunctionCallMetaData_T *this_call_meta) {
  /// Call the block and execute the except block if the exc names match
  PBL_TRY_EXCEPT_BLOCK(
    {
      PBL_DECLARE_VAR(r_1, PblInt_T);
      PBL_CALL_FUNC_IN_TRY_EXCEPT_BLOCK(NestedTestFunction, r_1, PblInt_T *, X1, Y2, PblGetUIntT(1))
      return r_1;
    },
    {PBL_EXCEPT_BLOCK(
      "test", { return PblGetIntT(1); }, Y2)},
    Y2, this_call_meta, PblInt_T);
  // default return is 0 - aka. the exception was raised
  return PblGetIntT(0);
}

TEST(ExceptionTest, TryExceptCall) {
  PBL_DECLARE_VAR(r_1, PblInt_T);
  PBL_DEFINE_VAR(this_call_meta, PblFunctionCallMetaData_T);
  this_call_meta->actual.is_failure = PblGetBoolT(false);

  // creating a copy of the addr, if the pointer is accidentally set to NULL by the function returning NULL (due to
  // the exception occurring)
  PBL_CREATE_ADDRESS_COPY(r_1, PblInt_T *, H3);
  /// Call the function and update the local ctx if an exception was raised
  PBL_BASE_CALL_AND_CATCH_EXCEPTION(TestFunction2, r_1, H3, PblGetBoolT(false), this_call_meta, );

  // if the function failed, treat the return as invalid -> restore previous value
  if (this_call_meta->actual.is_failure->actual) {
    // Restore if NULL -> here it should be restored as NULL is returned
    PBL_WRITE_BACK_ADDRESS_COPY(r_1, H3);
  }

  // Try-except should never if there is a except statement that was executed, log it's exception and throw the results
  // away right after finishing up
  EXPECT_FALSE(this_call_meta->actual.is_failure->actual);
  EXPECT_TRUE(this_call_meta->actual.failure_origin_ctx == NULL);
  EXPECT_TRUE(this_call_meta->actual.exception == NULL);
  EXPECT_TRUE(this_call_meta->actual.call_origin_ctx == NULL);
  EXPECT_EQ(r_1->meta.defined, true);
  EXPECT_EQ(r_1->actual, 1);
}

PblInt_T *TestFunction3(PblFunctionCallMetaData_T *this_call_meta) {
  /// Call the block and execute the except block if the exc names match
  PBL_TRY_EXCEPT_BLOCK(
    {
      PBL_DECLARE_VAR(r_1, PblInt_T);
      PBL_CALL_FUNC_IN_TRY_EXCEPT_BLOCK(NestedTestFunction, r_1, PblInt_T *, X1, Y2, PblGetUIntT(1))
      return r_1;
    },
    {PBL_EXCEPT_BLOCK(
      "test", { return PblGetIntT(1); }, Y2)},
    Y2, this_call_meta, PblInt_T);
  // default return is 0 - aka. the exception was raised
  return PblGetIntT(0);
}

TEST(ExceptionTest, TryExceptCallWithContinuation) {
  PBL_DECLARE_VAR(r_1, PblInt_T);
  PBL_DEFINE_VAR(this_call_meta, PblFunctionCallMetaData_T);
  this_call_meta->actual.is_failure = PblGetBoolT(false);

  // creating a copy of the addr, if the pointer is accidentally set to NULL by the function returning NULL (due to
  // the exception occurring)
  PBL_CREATE_ADDRESS_COPY(r_1, PblInt_T *, H3);
  /// Call the function and update the local ctx if an exception was raised
  PBL_BASE_CALL_AND_CATCH_EXCEPTION(TestFunction3, r_1, H3, PblGetBoolT(false), this_call_meta, );

  // if the function failed, treat the return as invalid -> restore previous value
  if (this_call_meta->actual.is_failure->actual) {
    // Restore if NULL -> here it should be restored as NULL is returned
    PBL_WRITE_BACK_ADDRESS_COPY(r_1, H3);
  }

  EXPECT_FALSE(this_call_meta->actual.is_failure->actual);
  EXPECT_TRUE(this_call_meta->actual.failure_origin_ctx == NULL);
  EXPECT_TRUE(this_call_meta->actual.exception == NULL);
  EXPECT_TRUE(this_call_meta->actual.call_origin_ctx == NULL);
  EXPECT_EQ(r_1->meta.defined, true);
  EXPECT_EQ(r_1->actual, 1);
}
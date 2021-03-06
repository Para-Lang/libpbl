/// @file pbl-function.c
/// @brief Function-related types and exception implementation. This includes meta data tracking for functions calls,
/// function states, exceptions and tracebacks.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#include <libpbl/func/pbl-function.h>

// ---- Functions Definitions -----------------------------------------------------------------------------------------

PblFunctionCallMetaData_T *PblGetMetaFunctionCallCtxT(PblString_T *function_identifier, PblBool_T *is_failure,
                                                      PblUInt_T *arg_amount, PblBool_T *is_threaded,
                                                      PblFunctionCallMetaData_T *failure_origin_ctx,
                                                      PblFunctionCallMetaData_T *call_origin_ctx,
                                                      PblException_T *exception) {
  PBL_DEFINE_VAR(ptr, PblFunctionCallMetaData_T);
  *ptr = PblFunctionCallMetaData_T_DefDefault;

  ptr->actual = (struct PblFunctionCallMetaData_Base){.function_identifier = function_identifier,
                                                      .is_failure = is_failure,
                                                      .arg_amount = arg_amount,
                                                      .is_threaded = is_threaded,
                                                      .failure_origin_ctx = failure_origin_ctx,
                                                      .call_origin_ctx = call_origin_ctx,
                                                      .exception = exception};
  return ptr;
}

__attribute__((unused)) PblVoid_T PblDeallocateMetaFunctionCallCtxT(PblFunctionCallMetaData_T *ctx) {
  // Validate the pointer for safety measures
  ctx = PblValPtr((void *) ctx);

  if (ctx->meta.defined) {
    if (ctx->actual.exception != NULL) PblDeallocateExceptionT(ctx->actual.exception);
    if (ctx->actual.function_identifier != NULL) PblDeallocateStringT(ctx->actual.function_identifier);

    // resetting the values
    *ctx = PblFunctionCallMetaData_T_DeclDefault;
    PblFree(ctx);
    ctx = NULL;
  }
  return PblVoid_T_DeclDefault;
}

PblException_T *PblGetExceptionT(PblString_T *msg, PblString_T *name, PblString_T *filename, PblUInt_T *line,
                                 PblString_T *line_content, PblVoid_T *parent_exc, PblVoid_T *child_exc) {
  PBL_DEFINE_VAR(ptr, PblException_T);

  // Using the Definition Default
  *ptr = PblException_T_DefDefault;
  ptr->actual = (struct PblException_Base){.msg = msg,
                                           .name = name,
                                           .filename = filename,
                                           .line = line,
                                           .line_content = line_content,
                                           .parent_exc = parent_exc,
                                           .child_exc = child_exc};

  return ptr;
}

PblVoid_T PblRaiseNewException(PblFunctionCallMetaData_T *this_call_meta, PblException_T *exception) {
  // Validate the pointer for safety measures
  this_call_meta = PblValPtr((void *) this_call_meta);
  exception = PblValPtr((void *) exception);

  this_call_meta->actual.is_failure = PblGetBoolT(true);
  this_call_meta->actual.failure_origin_ctx = this_call_meta;
  this_call_meta->actual.exception = exception;
  return PblVoid_T_DeclDefault;
}

// TODO! Add Deallocating function for deallocating exception parents and children

PblVoid_T PblDeallocateExceptionT(PblException_T *exc) {
  // Validate the pointer for safety measures
  exc = PblValPtr((void *) exc);

  // only if the exception is still defined
  if (exc->meta.defined) {
    // deallocate if the values are defined -> if not, skip de-allocation

    if (exc->actual.msg != NULL && exc->actual.msg->meta.defined) PblDeallocateStringT(exc->actual.msg);
    if (exc->actual.name != NULL && exc->actual.name->meta.defined) PblDeallocateStringT(exc->actual.name);
    if (exc->actual.filename != NULL && exc->actual.filename->meta.defined) PblDeallocateStringT(exc->actual.filename);
    if (exc->actual.line_content != NULL && exc->actual.line_content->meta.defined)
      PblDeallocateStringT(exc->actual.line_content);

    *exc = PblException_T_DeclDefault;
    PblFree(exc);
    exc = NULL;
  }
  return PblVoid_T_DeclDefault;
}

// ---- End of Function Definitions -----------------------------------------------------------------------------------

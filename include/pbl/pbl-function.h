/// @file pbl-function.c
/// @brief Function-related types and exception implementation. This includes meta data tracking for functions calls,
/// function states, exceptions and tracebacks.
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#include "./additional/va-opt.h"
#include "./pbl-mem.h"
#include "./pbl-string.h"
#include "./pbl-types.h"
#include "./pbl-apply-macro.h"

#ifndef PBL_MODULES_FUNCTION_H
#define PBL_MODULES_FUNCTION_H

#ifdef __cplusplus
extern "C" {
#endif

// ---- Helper Macros -------------------------------------------------------------------------------------------------

/// As reference, this implementation of counting arguments is inspired by https://stackoverflow.com/a/35693080/13076191

/// @brief This macro function get fed 128 named parameters, which are eaten and used to get the off-set aka. N as the
/// true number of args passed.
/// @note This function also officially restricts the usage of functions with more than 127 parameters
#define PBL_COUNT_VA_ARGS_128TH_ARG(                                                                                   \
  _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25,  \
  _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48,   \
  _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71,   \
  _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94,   \
  _95, _96, _97, _98, _99, _100, _101, _102, _103, _104, _105, _106, _107, _108, _109, _110, _111, _112, _113, _114,   \
  _115, _116, _117, _118, _119, _120, _121, _122, _123, _124, _125, _126, _127, N, ...)                                \
  N

/// @brief This macro returns the sequence used in 'PBL_COUNT_VA_ARGS_128TH_ARG' for greeting the offset
/// @note This function also officially restricts the usage of functions with more than 127 parameters
#define PBL_COUNT_VA_ARGS_128_ARG_SEQ()                                                                                \
  127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105,   \
    104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78,   \
    77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50,    \
    49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22,    \
    21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

/// @brief This macro function is fed both the actual '__VA_ARGS__' and the 128 long sequence, which is then used to
/// properly calculate the offset to 128, aka. N - 128 = offset / true amount of args
#define PBL_COUNT_VA_ARGS_WRAP_GET_128TH_LOCATION(...) PBL_COUNT_VA_ARGS_128TH_ARG(__VA_ARGS__)

/// @brief This function returns as integer value the number of arguments that were passed to this macro
/// @note This function also officially restricts the usage of functions with more than 127 parameters
#define PBL_COUNT_VA_ARGS(...) PBL_COUNT_VA_ARGS_WRAP_GET_128TH_LOCATION(__VA_ARGS__, PBL_COUNT_VA_ARGS_128_ARG_SEQ())

// ---- Basic Function Macros -----------------------------------------------------------------------------------------

/// @brief Specifier for a Para-C function, which is then formatted aka. to per default set the value passed to NULL, as
/// in Para-C all values are pointers inherently and only declarations are not valid.
#define PBL_FUNC_ARG(arg, val) IFNE(val)(arg=val, .arg=NULL)

/// @brief Creates based on the passed declaration signature a viable struct child aka. add ';'
#define PBL_CREATE_FUNC_OVERHEAD_CREATE_STRUCT_CHILD(arg) arg;

/// @brief Macro Function to get the standardised identifier for the 'Args' struct of a PBL function
/// @note For this identifier to be valid, the macro function 'PBL_CREATE_FUNC_OVERHEAD' has to be used before
#define PBL_GET_FUNC_ARGS_IDENTIFIER(func_identifier) func_identifier##_Args

/// @brief Macro Function to get the standardised identifier for the 'Base' of a PBL function
/// @note For this identifier to be valid, the macro function 'PBL_CREATE_FUNC_OVERHEAD' has to be used before
#define PBL_GET_FUNC_BASE_IDENTIFIER(func_identifier) func_identifier##_Base

/// @brief Macro Function to get the standardised identifier for the 'Overhead' of a PBL function
/// @note For this identifier to be valid, the macro function 'PBL_CREATE_FUNC_OVERHEAD' has to be used before
#define PBL_GET_FUNC_OVERHEAD_IDENTIFIER(func_identifier) func_identifier##_Overhead

/// @brief This creates the overhead function for the passed new function, by declaring it and generating a struct type,
/// which defines the arguments that may be passed
/// @note At max. 127 args are allowed
/// @note Both the macro for accessing the base and overhead have to be defined yourself!
#define PBL_CREATE_FUNC_OVERHEAD(signature, identifier, _attribute_, args...)                                          \
  struct PBL_GET_FUNC_ARGS_IDENTIFIER(identifier) {                                                                    \
    PBL_APPLY_MACRO(PBL_CREATE_FUNC_OVERHEAD_CREATE_STRUCT_CHILD, args)                                                \
  };                                                                                                                   \
  signature PBL_GET_FUNC_BASE_IDENTIFIER(identifier)(args) _attribute_;                                                \
  signature PBL_GET_FUNC_OVERHEAD_IDENTIFIER(identifier)(struct identifier##_Args in) _attribute_;

/// @brief Calls a function, passes the args and creates the appropriate unique identifier for the function call.
/// @param func The function that should be called with the passed variadic arguments.
/// @param var_to_pass The variable the return of the function should be passed to.
/// @param unique_id The unique id the call ctx should be declared as. It follows the following scheme: unique##_##func.
/// @param is_threaded Whether this macro is invoked in a threaded context. This variable is directly passed to the
/// created context.
/// @param meta_ctx The meta_ctx that should be used as a parent ctx (invocation context) of the child function
/// @param args The arguments to pass to the local function
#define PBL_CALL_FUNC(func, var_to_pass, unique_id, is_threaded, meta_ctx, args)                                       \
  PblMetaFunctionCallCtx_T *unique_id_##func##_CALLCTX = PblGetMetaFunctionCallCtxT(                                   \
    PblGetStringT(#func),                                                                                              \
    PblGetBoolT(false),                                                                                                \
    PblGetUIntT(IFNE(args)(PBL_COUNT_VA_ARGS(args), 0)),                                                               \
    is_threaded,                                                                                                       \
    NULL,                                                                                                              \
    meta_ctx,                                                                                                          \
    NULL);                                                                                                             \
  (var_to_pass) = func(unique_id_##func##_CALLCTX IFN(args)(, args));

// ---- Exception Implementation --------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL Long Double type
#define PblException_T_Size (4 * sizeof(PblString_T *) + sizeof(PblUInt_T *) + 2 * sizeof(void *))
/// @brief Returns the declaration default for the type 'PblException_T'
#define PblException_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblException_T)
/// @brief Returns the definition default for the type 'PblException_T', where the children have not been set yet and only the
/// value itself 'exists' already.
#define PblException_T_DefDefault                                                                                      \
  PBL_DEFINITION_STRUCT_CONSTRUCTOR(PblException_T, .msg = NULL, .name = NULL, .filename = NULL, .line = NULL,         \
                                    .line_content = NULL, .parent_exc = NULL, .child_exc = NULL)

struct PblException_Base {
  /// @brief The message of the exception
  PblString_T *msg;
  /// @brief The name of the exception
  PblString_T *name;
  /// @brief The filename where the exception occurred
  PblString_T *filename;
  /// @brief The line where the exception occurred
  PblUInt_T *line;
  /// @brief The content of the line - macro inserted
  PblString_T *line_content;
  /// @brief The parent exception if it exists
  /// (Reserved for PblException_T)
  void *parent_exc;
  /// @brief The child exception if it exists
  /// (Reserved for PblException_T)
  void *child_exc;
};

/// Exception implementation
struct PblException PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(struct PblException_Base)
/// Exception implementation
typedef struct PblException PblException_T;

// ---- Raise Exception Macros ----------------------------------------------------------------------------------------

/// @brief This a "one-liner" constructor, which will allocate a new exception and raise it (return to the caller of the
/// stack).
/// @param exception The exception that shall be raised.
/// @param call_return_type The return type of the function where this macro is invoked.
/// @note This requires the existence of 'this_call_meta' of type 'PblMetaFunctionCallCtx_T'.
#define PBL_RAISE_EXCEPTION(exception, call_return_type)                                                               \
  PblRaiseNewException(this_call_meta, exception);                                                                     \
  PBL_ALLOC_DECLARATION(raise_exc_ret, call_return_type)                                                               \
  return raise_exc_ret;

// ---- Invoke and Catch Exception handling ---------------------------------------------------------------------------

/// @brief This is a "one-liner" constructor for Para-C functions, which will call the passed function with the args
/// (__VA_ARGS__) and if an exception is raised update the local ctx appropriately
/// @param func The function that should be called with the passed variadic arguments.
/// @param var_to_pass The variable the return of the function should be passed to.
/// @param unique_id The unique id the call ctx should be declared as. It follows the following scheme: unique##_##func.
/// @param is_threaded Whether this macro is invoked in a threaded context. This variable is directly passed to the
/// created context.
/// @param args the arguments to pass to the function, leave empty if none shall be passed.
#define PBL_C_BASE_EXCEPTION_CATCH_CONSTRUCTOR(func, var_to_pass, unique_id, is_threaded, meta_ctx, args)              \
  PBL_CALL_FUNC(func, var_to_pass, unique_id, is_threaded, meta_ctx, IFN(args)(args))                                  \
  if (unique_id_##func##_CALLCTX->actual.is_failure->actual) {                                                         \
    (meta_ctx)->actual.is_failure = PblGetBoolT(true);                                                                 \
    (meta_ctx)->actual.exception = unique_id_##func##_CALLCTX->actual.exception;                                       \
    (meta_ctx)->actual.failure_origin_ctx = unique_id_##func##_CALLCTX->actual.failure_origin_ctx                      \
                                              ? unique_id_##func##_CALLCTX->actual.failure_origin_ctx                  \
                                              : unique_id_##func##_CALLCTX;                                            \
  }

/// @brief This is a "one-liner" constructor for Para-C functions, which will call the passed function with the args
/// (__VA_ARGS__) and return to the caller of the stack, if the called function returns with a raised exception.
/// @param func The function that should be called with the passed variadic arguments.
/// @param var_to_pass The variable the return of the function should be passed to.
/// @param ctx_rtype The return type of the context (function) where this macro is used. If an exception occurs the
/// default value (_DeclDefault) will be returned.
/// @param unique_id The unique id the call ctx should be declared as. It follows the following scheme: unique##_##func.
/// @note This requires the existence of 'this_call_meta' of type 'PblMetaFunctionCallCtx_T'
#define PBL_EXCEPTION_CATCH_FUNC_CONSTRUCTOR(func, var_to_pass, ctx_rtype, unique_id, args...)                         \
  PBL_CALL_FUNC(func, var_to_pass, unique_id, this_call_meta->actual.is_threaded, this_call_meta, IFN(args)(args))                                                                         \
  if (unique_id_##func##_CALLCTX->actual.is_failure->actual) {                                                         \
    this_call_meta->actual.is_failure = PblGetBoolT(true);                                                             \
    this_call_meta->actual.exception = unique_id_##func##_CALLCTX->actual.exception;                                   \
    this_call_meta->actual.failure_origin_ctx = unique_id_##func##_CALLCTX;                                            \
    return NULL;                                                                                                       \
  }

// ---- Exception Catching (try-except) -------------------------------------------------------------------------------

/// @brief Creates a try-except block, which contain the executed code-block and the except-block if an exception is
/// raised
/// @param block The block to execute
/// @param except_block The except block, which should contain checks created by EXCEPTION_CREATE_EXCEPT_BLOCK()
/// @param block_identifier The unique local identifier, which should be passed to all items in the blocks as well to
/// correctly update the information.
/// @param meta_ctx The meta_ctx that should be used as a parent ctx (invocation context) of the child function
/// @param call_return_type The return type of the function where this macro is invoked.
#define PBL_EXCEPTION_TRY_EXCEPT_BLOCK(block, except_block, block_identifier, meta_ctx, call_return_type)              \
  PblException_T block_identifier##_local_catched_exc;                                                                 \
  PblBool_T *block_identifier##_invoke_except = PblGetBoolT(false);                                                    \
  PblBool_T *block_identifier##_except_handled = PblGetBoolT(false);                                                   \
  block;                                                                                                               \
  block_identifier##_except_block : except_block;                                                                      \
  block_identifier##_finish_up : {                                                                                     \
    if (block_identifier##_invoke_except->actual && !block_identifier##_except_handled->actual) { return NULL; }       \
  }

/// @brief This is a "one-liner" constructor for functions that accept arguments and have a return, which will call the
/// passed function with the args (__VA_ARGS__) and if an exception is raised jump to the except blocks.
/// @param func The function that should be called with the passed variadic arguments.
/// @param var_to_pass The variable the return of the function should be passed to.
/// @param ctx_rtype The return type of the context (function) where this macro is used. If an exception occurs the
/// default value (_DeclDefault) will be returned.
/// @param unique_id The unique id the call ctx should be declared as. It follows the following scheme: unique##_##func.
/// @note This requires the existence of 'this_call_meta' of type 'PblMetaFunctionCallCtx_T'
#define PBL_EXCEPTION_TRY_BLOCK_CATCH_FUNC_CONSTRUCTOR(func, var_to_pass, ctx_rtype, unique_id, block_identifier,      \
                                                       args...)                                                        \
  PBL_CALL_FUNC(func, var_to_pass, unique_id, this_call_meta->actual.is_threaded, this_call_meta, IFN(args)(args))     \
  if (unique_id_##func##_CALLCTX->actual.is_failure->actual) {                                                         \
    block_identifier##_local_catched_exc = *((PblException_T *) unique_id_##func##_CALLCTX->actual.exception);         \
    block_identifier##_invoke_except = PblGetBoolT(true);                                                              \
    goto block_identifier##_except_block;                                                                              \
  }

/// @brief Adds an exception clause to the current block - this should be used to create a block statement which then is
/// passed as an argument to EXCEPTION_TRY_EXCEPT_BLOCK()
#define PBL_EXCEPTION_CREATE_EXCEPT_BLOCK(exception_name, block_to_execute, block_identifier)                          \
  if (block_identifier##_invoke_except->actual) {                                                                      \
    block_to_execute;                                                                                                  \
    block_identifier##_except_handled = PblGetBoolT(true);                                                             \
    goto block_identifier##_finish_up;                                                                                 \
  }

// ---- Function Meta Type --------------------------------------------------------------------------------------------

/// @brief (Never use this for malloc - this only indicates the usable memory space)
/// @returns The size in bytes of the PBL MetaFunctionCallCtx type
#define PblMetaFunctionCallCtx_T_Size                                                                                  \
  (sizeof(PblBool*) + sizeof(PblUInt_T*) + sizeof(PblBool_T*) + 2 * sizeof(PblMetaFunctionCallCtx_T *) + sizeof(NULL))
/// @brief Returns the declaration default for the type 'PblMetaFunctionCallCtx_T'
#define PblMetaFunctionCallCtx_T_DeclDefault PBL_DECLARATION_CONSTRUCTOR(PblMetaFunctionCallCtx_T)
/// @brief Returns the definition default for the type 'PblMetaFunctionCallCtx_T', where the children have not been set yet and only the
/// value itself 'exists' already.
#define PblMetaFunctionCallCtx_T_DefDefault                                                                            \
  PBL_DEFINITION_STRUCT_CONSTRUCTOR(PblMetaFunctionCallCtx_T, .function_identifier = NULL, .is_failure = NULL,         \
                                    .arg_amount = NULL, .is_threaded = NULL, .failure_origin_ctx = NULL,               \
                                    .call_origin_ctx = NULL, .exception = NULL)

/// @brief Base Meta Type passed to all functions
struct PblMetaFunctionCallCtx_Base {
  /// @brief The function name - identifier
  PblString_T *function_identifier;
  /// Returns whether the function failed due to an exception occurring
  PblBool_T *is_failure;
  /// @brief The amount of arguments passed
  PblUInt_T *arg_amount;
  /// Returns whether the function is threaded -> in an thread / threaded context
  PblBool_T *is_threaded;
  /// @brief The origin meta variable for the function where the exception occurred
  /// Only available when is_failure is true
  /// (Reserved for PblMetaFunctionCallCtx_T)
  void *failure_origin_ctx;
  /// @brief The call origin ctx, which called the function associated with *this* context
  /// (Reserved for PblMetaFunctionCallCtx_T)
  void *call_origin_ctx;
  /// @brief The exception whether one was raised
  /// Only available when is_failure is true
  /// (Reserved for PblException_T)
  PblException_T *exception;
};

struct PblMetaFunctionCallCtx PBL_TYPE_DEFINITION_WRAPPER_CONSTRUCTOR(struct PblMetaFunctionCallCtx_Base)

/// @brief Base Meta Type passed to all functions
typedef struct PblMetaFunctionCallCtx PblMetaFunctionCallCtx_T;

// ---- Helper Functions ----------------------------------------------------------------------------------------------

/**
 * @brief Gets a new function call ctx, which will be located in the heap
 * @return The newly created function call ctx (pointer)
 */
PblMetaFunctionCallCtx_T *PblGetMetaFunctionCallCtxT(PblString_T *function_identifier, PblBool_T *is_failure,
                                                     PblUInt_T *arg_amount, PblBool_T *is_threaded,
                                                     PblMetaFunctionCallCtx_T *failure_origin_ctx,
                                                     PblMetaFunctionCallCtx_T *call_origin_ctx,
                                                     PblException_T *exception);

/**
 * @brief Deallocates the passed function call ctx and safely resets all values
 * @param ctx The function call ctx to deallocate
 */
PblVoid_T PblDeallocateMetaFunctionCallCtxT(PblMetaFunctionCallCtx_T *ctx);

/**
 * @brief Gets a new Exception Type, which is located in the heap
 * @return The newly created exception (pointer)
 */
PblException_T *PblGetExceptionT(PblString_T *msg, PblString_T *name, PblString_T *filename, PblUInt_T *line,
                                 PblString_T *line_content, PblVoid_T *parent_exc, PblVoid_T *child_exc);

/**
 * @brief Raises a new exception by updating the local context info
 * @param this_call_meta The current context info that should be updated
 * @param exception The exception that was initialised
 */
PblVoid_T PblRaiseNewException(PblMetaFunctionCallCtx_T *this_call_meta, PblException_T *exception);

/**
 * @brief Deallocates the passed exception type and safely resets all values
 * @param exc The exception to deallocate
 * @notes This function will de-allocate the children and parents exceptions as well
 */
PblVoid_T PblDeallocateExceptionT(PblException_T *exc);

/**
 * @brief Cleanups the current exception Context and deallocates the memory that isn't used anymore
 * @param cleanup_ctx The function call ctx that should be cleaned up (including all of it's children)
 */
PblVoid_T PblCleanupExceptionContext(PblMetaFunctionCallCtx_T *cleanup_ctx);


#ifdef __cplusplus
}
#endif

#endif //PBL_MODULES_FUNCTION_H

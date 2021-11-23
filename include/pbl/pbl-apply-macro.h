/// @file pbl-apply-macro.c
/// @brief This file defines the macro 'PBL_APPLY_MACRO', which allows for up to 127 args to be processed using the passed
///// macro function 't'
/// @author Luna-Klatzer
/// @date 2021-11-23
/// @copyright Copyright (c) 2021

#include "./additional/va-opt.h"

#ifndef PBL_INCLUDE_APPLY_MACRO_H
#define PBL_INCLUDE_APPLY_MACRO_H

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Eats the entered args and doesn't apply the macro 't' on any of the passed args
#define PBL_APPLY_MACRO_EAT(t, ...)

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
/// @note Everything passed to the args (__VA_ARGS__) will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_1(t, _1, ...) t(_1) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_EAT(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_2(t, _2, ...) t(_2) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_1(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_3(t, _3, ...) t(_3) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_2(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_4(t, _4, ...) t(_4) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_3(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_5(t, _5, ...) t(_5) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_4(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_6(t, _6, ...) t(_6) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_5(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_7(t, _7, ...) t(_7) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_6(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_8(t, _8, ...) t(_8) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_7(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_9(t, _9, ...) t(_9) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_8(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_10(t, _10, ...) t(_10) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_9(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_11(t, _11, ...) t(_11) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_10(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_12(t, _12, ...) t(_12) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_11(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_13(t, _13, ...) t(_13) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_12(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_14(t, _14, ...) t(_14) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_13(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_15(t, _15, ...) t(_15) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_14(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_16(t, _16, ...) t(_16) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_15(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_17(t, _17, ...) t(_17) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_16(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_18(t, _18, ...) t(_18) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_17(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_19(t, _19, ...) t(_19) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_18(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_20(t, _20, ...) t(_20) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_19(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_21(t, _21, ...) t(_21) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_20(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_22(t, _22, ...) t(_22) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_21(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_23(t, _23, ...) t(_23) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_22(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_24(t, _24, ...) t(_24) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_23(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_25(t, _25, ...) t(_25) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_24(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_26(t, _26, ...) t(_26) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_25(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_27(t, _27, ...) t(_27) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_26(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_28(t, _28, ...) t(_28) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_27(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_29(t, _29, ...) t(_29) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_28(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_30(t, _30, ...) t(_30) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_29(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_31(t, _31, ...) t(_31) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_30(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_32(t, _32, ...) t(_32) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_31(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_33(t, _33, ...) t(_33) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_32(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_34(t, _34, ...) t(_34) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_33(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_35(t, _35, ...) t(_35) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_34(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_36(t, _36, ...) t(_36) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_35(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_37(t, _37, ...) t(_37) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_36(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_38(t, _38, ...) t(_38) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_37(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_39(t, _39, ...) t(_39) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_38(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_40(t, _40, ...) t(_40) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_39(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_41(t, _41, ...) t(_41) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_40(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_42(t, _42, ...) t(_42) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_41(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_43(t, _43, ...) t(_43) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_42(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_44(t, _44, ...) t(_44) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_43(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_45(t, _45, ...) t(_45) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_44(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_46(t, _46, ...) t(_46) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_45(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_47(t, _47, ...) t(_47) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_46(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_48(t, _48, ...) t(_48) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_47(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_49(t, _49, ...) t(_49) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_48(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_50(t, _50, ...) t(_50) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_49(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_51(t, _51, ...) t(_51) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_50(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_52(t, _52, ...) t(_52) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_51(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_53(t, _53, ...) t(_53) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_52(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_54(t, _54, ...) t(_54) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_53(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_55(t, _55, ...) t(_55) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_54(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_56(t, _56, ...) t(_56) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_55(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_57(t, _57, ...) t(_57) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_56(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_58(t, _58, ...) t(_58) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_57(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_59(t, _59, ...) t(_59) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_58(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_60(t, _60, ...) t(_60) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_59(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_61(t, _61, ...) t(_61) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_60(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_62(t, _62, ...) t(_62) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_61(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_63(t, _63, ...) t(_63) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_62(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_64(t, _64, ...) t(_64) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_63(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_65(t, _65, ...) t(_65) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_64(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_66(t, _66, ...) t(_66) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_65(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_67(t, _67, ...) t(_67) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_66(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_68(t, _68, ...) t(_68) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_67(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_69(t, _69, ...) t(_69) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_68(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_70(t, _70, ...) t(_70) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_69(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_71(t, _71, ...) t(_71) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_70(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_72(t, _72, ...) t(_72) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_71(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_73(t, _73, ...) t(_73) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_72(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_74(t, _74, ...) t(_74) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_73(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_75(t, _75, ...) t(_75) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_74(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_76(t, _76, ...) t(_76) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_75(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_77(t, _77, ...) t(_77) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_76(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_78(t, _78, ...) t(_78) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_77(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_79(t, _79, ...) t(_79) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_78(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_80(t, _80, ...) t(_80) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_79(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_81(t, _81, ...) t(_81) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_80(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_82(t, _82, ...) t(_82) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_81(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_83(t, _83, ...) t(_83) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_82(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_84(t, _84, ...) t(_84) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_83(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_85(t, _85, ...) t(_85) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_84(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_86(t, _86, ...) t(_86) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_85(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_87(t, _87, ...) t(_87) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_86(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_88(t, _88, ...) t(_88) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_87(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_89(t, _89, ...) t(_89) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_88(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_90(t, _90, ...) t(_90) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_89(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_91(t, _91, ...) t(_91) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_90(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_92(t, _92, ...) t(_92) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_91(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_93(t, _93, ...) t(_93) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_92(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_94(t, _94, ...) t(_94) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_93(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_95(t, _95, ...) t(_95) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_94(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_96(t, _96, ...) t(_96) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_95(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_97(t, _97, ...) t(_97) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_96(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_98(t, _98, ...) t(_98) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_97(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_99(t, _99, ...) t(_99) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_98(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_100(t, _100, ...) t(_100) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_99(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_101(t, _101, ...) t(_101) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_100(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_102(t, _102, ...) t(_102) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_101(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_103(t, _103, ...) t(_103) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_102(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_104(t, _104, ...) t(_104) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_103(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_105(t, _105, ...) t(_105) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_104(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_106(t, _106, ...) t(_106) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_105(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_107(t, _107, ...) t(_107) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_106(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_108(t, _108, ...) t(_108) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_107(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_109(t, _109, ...) t(_109) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_108(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_110(t, _110, ...) t(_110) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_109(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_111(t, _111, ...) t(_111) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_110(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_112(t, _112, ...) t(_112) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_111(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_113(t, _113, ...) t(_113) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_112(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_114(t, _114, ...) t(_114) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_113(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_115(t, _115, ...) t(_115) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_114(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_116(t, _116, ...) t(_116) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_115(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_117(t, _117, ...) t(_117) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_116(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_118(t, _118, ...) t(_118) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_117(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_119(t, _119, ...) t(_119) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_118(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_120(t, _120, ...) t(_120) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_119(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_121(t, _121, ...) t(_121) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_120(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_122(t, _122, ...) t(_122) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_121(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_123(t, _123, ...) t(_123) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_122(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_124(t, _124, ...) t(_124) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_123(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_125(t, _125, ...) t(_125) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_124(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_126(t, _126, ...) t(_126) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_125(t, __VA_ARGS__))

/// @brief Applies on the first item the passed macro 't', the rest is fed back into until the end is reached
/// @note The max. number of processable args is specified in the name. If more are passed they will be eaten
/// and not processed
#define PBL_APPLY_MACRO_APPLY_127(t, _127, ...) t(_127) IFN(__VA_ARGS__)(PBL_APPLY_MACRO_APPLY_126(t, __VA_ARGS__))

/// @brief Applies the passed macro to every single item passed afterwards as args.
/// @note This has a limit of 127 repetitions! This means afterwards the macros will be eaten
#define PBL_APPLY_MACRO(t, ...) PBL_APPLY_MACRO_APPLY_127(t, __VA_ARGS__)

#ifdef __cplusplus
};
#endif

#endif//PBL_INCLUDE_APPLY_MACRO_H

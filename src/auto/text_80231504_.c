#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "MSL/stdarg.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055F04C;
extern s32 lbl_8055F070;
extern void *lbl_8055B9A8;
extern void fn_80231AF0(void);
extern void fn_80231D84(void);
extern u8 lbl_8055F064;
extern u8 *lbl_8055F068;
extern s32 lbl_8049846C[];
extern s32 fn_802315FC(s32);
extern void fn_802E30C8(const char *);
extern void fn_802E317C(const char *);
extern void *fn_801284F8(s32, const char *);
extern char lbl_8034044C[];
extern char lbl_80340488[];
extern char lbl_803404C0[];
extern s32 stricmp(const char *, const char *);
extern void *fn_8012850C(s32, const char *, ...);
extern char *strcpy(char *, const char *);
extern char lbl_80340440[];
extern void fn_802CAC54(void *);
extern void fn_8012C4D8(void *);
extern void fn_80128670(void *);
extern void *lbl_8055F060;
extern s32 lbl_8055F058;
extern s32 lbl_8055F06C;
extern char lbl_80340614[];
extern void fn_802328D4(s32);
extern u32 strlen(const char *);
s32 fn_80231504(void) {
    return 0;
}

s32 fn_8023150C(const char *arg0) {
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)(lbl_8055F068 + 0x168)) {
        if (stricmp((const char *)(*(void **)(lbl_8055F068 + offset + 4)), arg0) == 0) {
            return i;
        }
        offset += 0xC;
        i++;
    }
    return -1;
}

void fn_8023158C(void *arg0, const char *arg1) {
    s32 count = *(s32 *)(lbl_8055F068 + 0x168);
    s32 offset = count * 0xC;
    *(s32 *)(lbl_8055F068 + 0x168) = count + 1;
    *(void **)(lbl_8055F068 + offset) = arg0;
    *(s32 *)(lbl_8055F068 + offset + 8) = 1;
    strcpy(fn_8012850C(0x40, lbl_80340440, offset, count + 1, lbl_8055F068), arg1);
}

s32 fn_802315FC(s32 arg0) {
    s32 offset = arg0 * 0xC;
    u8 *entry = lbl_8055F068 + offset;
    s32 refCount = *(s32 *)(entry + 8) - 1;
    s32 last;
    s32 lastOffset;
    void *ptr;
    if ((*(s32 *)(entry + 8) = refCount) < 1) {
        ptr = *(void **)entry;
        fn_802CAC54(*(void **)ptr);
        fn_8012C4D8(ptr);
        fn_80128670(*(void **)(entry + 4));
        last = *(s32 *)(lbl_8055F068 + 0x168) - 1;
        lastOffset = last * 0xC;
        *(s32 *)(lbl_8055F068 + 0x168) = last;
        *(void **)entry = *(void **)(lbl_8055F068 + lastOffset);
        *(void **)(entry + 4) = *(void **)(lbl_8055F068 + lastOffset + 4);
        *(s32 *)(entry + 8) = *(s32 *)(lbl_8055F068 + lastOffset + 8);
        return 1;
    }
    return 0;
}

s32 fn_802316A4(void *arg0) {
    s32 i = 0;
    u8 *entry = lbl_8055F068;
    s32 count = *(s32 *)(lbl_8055F068 + 0x168);
    while (i < count) {
        if (*(void **)entry == arg0) return fn_802315FC(i);
        entry += 0xC;
        i++;
    }
    fn_802E30C8(lbl_8034044C);
    return 0;
}

void fn_80231714(void) {}

s32 fn_80231718(s32 arg0) {
    u32 value = (u32)lbl_8055F060;
    return (arg0 & 0xFF000000) | (value & 0x00FF0000) | (value & 0x0000FFFF);
}

extern s32 sprintf(char *, const char *, ...);
extern s32 fn_8012C33C(const char *);
extern s32 fn_80232578(const char *);
extern char lbl_8055B9A0[];
s32 fn_80231730(s32 arg0) {
    char buffer[0x18];
    sprintf(buffer, lbl_8055B9A0, arg0);
    if (fn_8012C33C(buffer) != 0) {
        return fn_80232578(buffer);
    }
    return 0;
}

void fn_80231ADC(void) {
    *(s32 *)(lbl_8049846C + 1) = 0;
}

void fn_80232024(u8 **arg0) {
    u8 *p = *arg0;
    if (*p == 1) *arg0 = p + 1;
}

void fn_802321D8(void) {
    if (lbl_8055F068 != 0) fn_802E317C(lbl_80340488);
    lbl_8055F068 = fn_801284F8(0x16C, lbl_803404C0);
    memset(lbl_8055F068, 0, 0x16C);
}

void fn_80232928(void* hi) {
    lbl_8055F060 = hi;
}

void fn_80232930(void) {
    lbl_8055F060 = (void *)lbl_8055F04C;
}

u8 fn_80232B70(void *arg0) {
    return ((u8 *)arg0)[4];
}

u8 fn_80232B78(void *arg0) {
    return ((u8 *)arg0)[5];
}

void fn_80232B80(s32 arg0) {
    void *value = (void *)fn_80231AF0;
    lbl_8055F070 = arg0;
    if (arg0 == 0) {
        value = (void *)fn_80231D84;
    }
    lbl_8055B9A8 = value;
}

extern int vsprintf(char *, const char *, va_list);
extern f32 lbl_8056368C;
extern f32 lbl_80563684;
extern void fn_80232040(u8 *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void fn_80232BA4(char *, s32, s32, s32, f32, f32, f32, f32, f32);
void fn_80232D3C(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4) {
    s32 sp8 = arg2;
    fn_80231714();
    if ((s8)*arg0 != 0) {
        fn_80232040((u8 *)arg0, arg1, sp8, arg3, arg4, f0, f1, f2, f3, f4, lbl_8056368C);
    }
}

void fn_802335F0(void) {
    fn_80233600((u8 *)-1, 9, lbl_8056368C);
}
void fn_802337A0(f64 a, s32 b, f64 c, s32 d, f64 e, f64 f, s32 g, f64 h, char *fmt, ...) {
    char buffer[0x80];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    fn_80232BA4(buffer, b, d, g, a, c, f, e, h);
}

void fn_8023441C(const char *arg0) {
    s32 value;
    value = (s32)fn_8012850C(0x2100, lbl_80340614);
    lbl_8055F06C = value;
    value = fn_80232578(arg0);
    *(s32 *)((u8 *)&lbl_8055F058 + 4) = 0;
    lbl_8055F058 = value;
}

void fn_80234470(void) {
    fn_802328D4(lbl_8055F058);
    lbl_8055F058 = 0;
    fn_80128670((void *)lbl_8055F06C);
    lbl_8055F06C = 0;
}

extern s32 lbl_8055F06C;
extern s32 lbl_8055F058;
extern void fn_802328D4(s32);
extern char lbl_80340614[];
extern u32 strlen(const char *);
s32 fn_802344B0(void) {
    s32 val = lbl_8055F06C;
    u32 tmp = (u32)(-val) | (u32)val;
    return (s32)(tmp >> 31);
}

void fn_802344C4(u8 arg0) {
    lbl_8055F064 = arg0;
}

s32 fn_80234654(void) {
    s32 temp_r30;
    s32 var_r28;
    s32 var_r29;
    char *var_r31;

    var_r29 = 0;
    var_r28 = 0;
    var_r31 = (char *)lbl_8055F06C;
    temp_r30 = *(s32 *)((u8 *)&lbl_8055F058 + 4);
    while (var_r28 < temp_r30) {
        var_r29 += strlen(var_r31);
        var_r31 += 0x58;
        var_r28++;
    }
    return var_r29;
}
extern s32 fn_802315FC(s32);
extern void fn_802E30C8(const char *);
extern void fn_802E317C(const char *);
extern void *fn_801284F8(s32, const char *);
extern char lbl_8034044C[];
extern char lbl_80340488[];
extern char lbl_803404C0[];

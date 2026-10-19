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

#pragma dont_inline on
void fn_80231714(s32 *arg0) {}
#pragma dont_inline off

s32 fn_80231718(s32 arg0) {
    u32 value = (u32)lbl_8055F060;
    return (arg0 & 0xFF000000) | (value & 0x00FF0000) | (value & 0x0000FFFF);
}

extern s32 sprintf(char *, const char *, ...);
extern s32 fn_8012C33C(const char *);
extern s32 fn_80232578(const char *);
extern char lbl_8055B9A0[];
#pragma small_data on
#pragma small_data off
s32 fn_80231730(s32 arg0) {
    char buffer[0x18];
    sprintf(buffer, lbl_8055B9A0, arg0);
    if (fn_8012C33C(buffer) != 0) return fn_80232578(buffer);
    return 0;
}
#pragma scheduling invalid_target
void fn_80231ADC(void) {
    lbl_8049846C[1] = 0;
}
#pragma scheduling on
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
extern void fn_802C8D74(void);
#pragma scheduling off
void fn_80232D3C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    s32 sp8;

    sp8 = arg2;
    fn_80231714(&sp8);
    if ((s8)*arg0 != 0) {
        fn_80232040(arg0, arg1, sp8, arg3, arg4, farg0, farg1, farg2, farg3, farg4, lbl_8056368C);
    }
}

extern u8 fn_80232B70(void *);
extern void fn_802344CC(s32, s32, s32, s32, f32, f32, f32);
extern f32 fn_8023293C(s32, char *, f32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling off
void fn_80233010(char *arg0, s32 font, s32 color, s32 flags, s32 mode, f32 x, f32 y, f32 width, f32 scale, f32 spacing, f32 extra) {
    char buffer[512];
    char *text = arg0;
    s32 line = 0;
    strlen(text);
    while ((s8)*text) {
        char *start = text;
        s32 length;
        char *saved;
        s32 savedLength;
        s32 i;
        memset(buffer, 0, sizeof(buffer));
        length = 0;
        while (scale * fn_8023293C(font, buffer, extra) < width && *text && (s8)*text != '\n' && (s8)*text != '|') {
            char *next;
            s32 count;
            if (((u8)*text & 0xF0) == 0xE0) next = text + 3;
            else if (((u8)*text & 0xE0) == 0xC0) next = text + 2;
            else next = text + 1;
            count = next - text;
            for (i = 0; i < count; i++) buffer[length++] = *text++;
        }
        saved = text;
        savedLength = length;
        if ((s8)*text) {
            while ((s8)*text != ' ' && text != start && (s8)*text != '\n' && (s8)*text != '|') {
                text--;
                length--;
            }
        }
        if (text == start) { text = saved; length = savedLength; }
        buffer[length] = 0;
        if ((s8)*text == ' ' || (s8)*text == '\n' || (s8)*text == '|') text++;
        for (i = 0; i < length; i++) if ((u8)buffer[i] == '^') buffer[i] = ' ';
        {
            f32 ypos = y - (f32)line * (scale * (f32)(s32)fn_80232B70((void *)font));
            line++;
            if (mode == 0) fn_80232BA4(buffer, font, color, flags, x, ypos, scale, spacing, extra);
            else fn_802344CC((s32)buffer, color, flags, 0, x, ypos, scale);
        }
    }
}
#pragma pop
#pragma scheduling reset

#pragma scheduling reset
extern s32 fn_8022EDC4(void);
extern s32 fn_80230B9C(s32);
extern void fn_8022C8B98(void);
extern void fn_802C8B98(s32, s32);
extern s32 lbl_8055F050;
extern void fn_80232040(u8 *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void fn_80233600(u8 *, s32, s32, s32, f32, f32, f32);
void fn_802335F0(u8 *arg0, s32 arg1, f32 farg0, f32 farg1) {
    fn_80233600(arg0, arg1, -1, 9, farg0, farg1, lbl_8056368C);
}

void fn_80233600(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1, f32 farg2) {
    s32 sp8;

    sp8 = arg2;
    fn_80231714(&sp8);
    if ((s8)*arg0 != 0) {
        fn_80232040(arg0, arg1, sp8, arg3, 0, farg0, farg1, lbl_80563684, farg2, lbl_80563684, lbl_8056368C);
    }
}

void fn_802336AC(s32 arg0, s32 arg1, s32 arg2, const char *fmt, f32 farg0, f32 farg1, f32 farg2, ...) {
    char buffer[0xA8];
    va_list args;
    va_start(args, farg2);
    vsprintf(buffer, fmt, args);
    fn_80233600((u8 *)buffer, arg0, arg1, arg2, farg0, farg1, farg2);
}

void fn_802337A0(f32 a, s32 b, f32 c, s32 d, f32 e, f32 f, s32 g, f32 h, const char *fmt, ...) {
    char buffer[0x80];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    fn_80232BA4(buffer, b, d, g, a, c, f, e, h);
}

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
void fn_8023389C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, const char *fmt, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, ...) {
    char buffer[0x100];
    va_list args;
    va_start(args, farg4);
    vsprintf(buffer, fmt, args);
    fn_80232D3C((u8 *)buffer, arg0, arg1, arg2, arg3, farg0, farg1, farg2, farg3, farg4);
}
#pragma pop

extern void fn_80232DF4(u8 *, s32, s32, s32, f32, f32, f32, f32, f32);
#pragma push
#pragma use_lmw_stmw off
void fn_802339A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, const char *fmt, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, ...) {
    char buffer[0x100];
    va_list args;
    va_start(args, farg4);
    vsprintf(buffer, fmt, args);
    fn_80232DF4((u8 *)buffer, arg0, arg1, arg2, farg0, farg1, farg3, farg2, farg4);
}
#pragma pop
void fn_80233DD8(s32 *arg0, s32 arg1) {
    s32 temp_r31 = fn_8022EDC4();
    lbl_8055F050 = fn_80230B9C(arg1);
    fn_802C8B98(*arg0, (s32)temp_r31);
}
#pragma scheduling reset
void fn_80233E34(s32 *arg0, s32 arg1, s32 arg2) {
    lbl_8055F050 = fn_80230B9C(arg2);
    fn_802C8B98(*arg0, arg1);
}

extern void fn_802C8C04(s32);
void fn_80233E80(s32 *arg0, s32 arg1) {
    lbl_8055F050 = fn_80230B9C(arg1);
    fn_802C8C04(*arg0);
}

void fn_80233EBC(void) {
    fn_802C8D74();
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

extern s32 fn_80231718(s32);
extern void fn_80232024(u8 **);
extern void fn_8023423C(s32, s32);
extern void fn_802346C8(void);
extern f32 lbl_805636A8;
void fn_802344CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1, f32 farg2) {
    s32 sp8 = arg0;
    s32 spC = arg1;
    s32 index;
    u8 *entry;

    fn_80232024((u8 **)&sp8);
    if (lbl_8055F058 >= 0x60) fn_802346C8();
    index = lbl_8055F058;
    entry = (u8 *)(lbl_8055F06C + index * 0x58);
    strncpy((char *)entry, (char *)sp8, 0x40);
    entry[0x3F] = 0;
    *(s32 *)(entry + 0x48) = spC;
    *(s32 *)(entry + 0x4C) = fn_80231718(spC);
    *(f32 *)(entry + 0x40) = farg0;
    *(f32 *)(entry + 0x44) = farg1;
    *(f32 *)(entry + 0x50) = farg2;
    if (arg3 != 0) *(f32 *)(entry + 0x54) = lbl_805636A8 * farg2;
    else *(f32 *)(entry + 0x54) = farg2;
    fn_8023423C(index, arg2);
    lbl_8055F058++;
}

s32 fn_80234654(void) {
    char *str;
    s32 count;
    s32 total;
    s32 i;
    total = 0;
    i = 0;
    str = (char *)lbl_8055F06C;
    count = *(s32 *)((u8 *)&lbl_8055F058 + 4);
    for (; i < count; i++) {
        total += strlen(str);
        str += 0x58;
    }
    return total;
}

void fn_80234AEC(void) {
    *(s32 *)((u8 *)&lbl_8055F058 + 4) = 0;
}

#pragma push
#pragma processor 750
void fn_80234AFC(void *arg0, const char *fmt, f32 farg0, f32 farg1, ...) {
    char buffer[0x80];
    va_list args;
    va_start(args, farg1);
    vsprintf(buffer, fmt, args);
    fn_80232BA4(buffer, *(s32 *)arg0, *(s32 *)((char *)arg0 + 4),
                *(s32 *)((char *)arg0 + 8), farg0, farg1,
                *(f32 *)((char *)arg0 + 0xC), lbl_80563684,
                *(f32 *)((char *)arg0 + 0x10));
}
#pragma pop
extern s32 fn_802315FC(s32);
extern void fn_802E30C8(const char *);
extern void fn_802E317C(const char *);
extern void *fn_801284F8(s32, const char *);
extern char lbl_8034044C[];
extern char lbl_80340488[];
extern char lbl_803404C0[];

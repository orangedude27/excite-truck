#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "MSL/stdarg.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055F04C;
extern s32 lbl_8055F070;
extern void *lbl_8055B9A8;
extern void fn_80231AF0(void);
extern void fn_80231D84(char *, void *, f32, f32, f32, f32, f32, f32, f32);
extern u8 lbl_8055F064;
extern u8 *lbl_8055F068;
extern s32 lbl_8049846C[];
extern s32 fn_8022EDC4(void);
extern s32 fn_80230B9C(s32);
extern void fn_802C8B98(s32, s32);
extern u8 *lbl_80497F14;
extern f32 lbl_80563680;
extern f32 lbl_80563684;
extern f32 lbl_80563688;
extern f32 lbl_8056368C;
extern void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void fn_802C8DBC(s32);
extern void fn_802C8D74(void);
extern void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
extern void fn_802C8E48(void);
static inline void transform_vec(const f32 *matrix, const f32 *src, f32 *dst) {
    f32 x = src[0];
    f32 y = src[1];
    f32 z = src[2];
    f32 outX;
    f32 outY;
    f32 outZ;

    if (src == dst) {
        outX = x * matrix[0] + y * matrix[3] + z * matrix[6];
        outY = x * matrix[1] + y * matrix[4] + z * matrix[7];
        outZ = x * matrix[2] + y * matrix[5] + z * matrix[8];
    } else {
        outX = x * matrix[0] + y * matrix[3];
        outY = outX * matrix[1] + y * matrix[4];
        outZ = outX * matrix[2] + outY * matrix[5];
    }
    dst[0] = outX + matrix[9];
    dst[1] = outY + matrix[10];
    dst[2] = outZ + matrix[11];
}
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

#pragma dont_inline on
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
#pragma dont_inline off

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
#pragma dont_inline on
s32 fn_80231730(s32 arg0) {
    char buffer[0x18];
    sprintf(buffer, lbl_8055B9A0, arg0);
    if (fn_8012C33C(buffer) != 0) return fn_80232578(buffer);
    return 0;
}
#pragma dont_inline off

#pragma push
#pragma processor 750
void fn_80231780(void *arg0) {
    f32 f25;
    f32 f26;
    f32 f27;
    f32 f28;
    f32 f29;
    f32 f30;
    f32 f31;
    f32 sp8;
    f32 spC;
    f32 sp10;
    s32 i;
    s32 offset;
    u8 *record;
    u8 *object;
    s32 index;
    s32 color;

    f31 = lbl_80563680;
    f30 = lbl_80563684;
    f29 = lbl_80563688;
    i = 0;
    offset = 0;
    goto loop_test;

loop_body:
    record = *(u8 **)&lbl_8049846C[0] + offset;
    index = *(s32 *)record;
    object = lbl_80497F14 + index * 0x1C;

    if (object[0x14] != 0)
        color = *(s32 *)(record + 0x18);
    else
        color = fn_80230B9C((*(s32 *)(record + 0x18) & 0xFF000000) | 0x00FFFFFF);

    if (*(s32 *)(object + 0x0C) != 0) {
        sp8 = *(f32 *)(record + 4);
        spC = *(f32 *)(record + 8);
        sp10 = *(f32 *)(record + 0x0C);
        if (arg0 != 0) transform_vec((f32 *)arg0, &sp8, &sp8);
        {
            f32 rate = *(f32 *)((u8 *)fn_8022EDC4() + 0x38);
            f32 ratio;
            f32 width = *(f32 *)(record + 0x14);
            f32 height = *(f32 *)(record + 0x10);
            if (rate > f31) {
            } else {
                rate = f31;
            }
            ratio = f30 / rate;
            fn_802354A0(*(s32 *)(object + 0x0C), *(s32 *)(object + 0x10), color,
                        sp8 - f29 * (ratio * width - width),
                        spC + f29 * (ratio * height - height),
                        sp10, ratio * width, ratio * height);
        }
    } else {
        if (arg0 != 0)
            fn_802C8B98(*(s32 *)(lbl_80497F14 + index * 0x1C + 8), (s32)arg0);
        else
            fn_802C8B98(*(s32 *)(lbl_80497F14 + index * 0x1C + 8), fn_8022EDC4());
        fn_802C8DBC(4);
        f27 = *(f32 *)(record + 4);
        f26 = *(f32 *)(record + 8);
        f25 = f27 + *(f32 *)(record + 0x14);
        f28 = f26 - *(f32 *)(record + 0x10);
        fn_802C8E00(color, 0, f27, f26, *(f32 *)(record + 0x0C), lbl_8056368C, lbl_8056368C);
        fn_802C8E00(color, 0, f25, f26, *(f32 *)(record + 0x0C), lbl_80563684, lbl_8056368C);
        fn_802C8E00(color, 1, f27, f28, *(f32 *)(record + 0x0C), lbl_8056368C, lbl_80563684);
        fn_802C8E00(color, 1, f25, f28, *(f32 *)(record + 0x0C), lbl_80563684, lbl_80563684);
        fn_802C8E48();
        fn_802C8D74();
    }
    offset += 0x1C;
    i += 1;

loop_test:
    if (i < lbl_8049846C[1]) goto loop_body;
    lbl_8049846C[1] = 0;
}
#pragma pop

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

extern void *fn_8012C370(const char *, s32, u32 *, s32 *, u8 *, u8 *);
extern void fn_80028E00(char *, const char *);
extern s32 fn_802CAC34(char *, s32);
extern char lbl_8055B9D4[];
s32 fn_80232578(const char *arg0) {
    s32 index;
    s32 offset;
    u8 *entry;
    u8 *data;
    u8 *record;
    u32 size;
    s32 unused;
    u8 valid;
    u8 swap;
    void *parsed;
    char name[0xC];
    s32 i;
    u8 temp;
    u32 value;

    index = fn_8023150C(arg0);
    if (index >= 0) {
        offset = index * 0xC;
        entry = lbl_8055F068 + offset;
        value = *(u32 *)(entry + 8);
        *(u32 *)(entry + 8) = value + 1;
        value = (u32)fn_80231730((s32)arg0);
        *(u32 *)(*(u32 **)entry + 8) = value;
        return *(s32 *)entry;
    }

    valid = 0;
    swap = 0;
    unused = 0;
    parsed = fn_8012C370(arg0, 0x47544558, &size, &unused, &valid, &swap);
    if (parsed == 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_80340440 + 0x144, arg0);
        return 0;
    }

    if (size != 8) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80340440 + 0xE4, arg0);
    }
    if (valid == 0) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80340440 + 0x108, arg0);
    }

    data = (u8 *)parsed;
    if (swap != 0) {
        temp = data[0xC]; data[0xC] = data[0xD]; data[0xD] = temp;
        temp = data[0x14]; data[0x14] = data[0x17]; data[0x17] = temp;
        temp = data[0x15]; data[0x15] = data[0x16]; data[0x16] = temp;
        temp = data[0x10]; data[0x10] = data[0x13]; data[0x13] = temp;
        temp = data[0x11]; data[0x11] = data[0x12]; data[0x12] = temp;
        temp = data[0x18]; data[0x18] = data[0x1B]; data[0x1B] = temp;
        temp = data[0x19]; data[0x19] = data[0x1A]; data[0x1A] = temp;
        *(u32 *)(data + 0x10) += (u32)data;
        *(u32 *)(data + 0x18) += (u32)data;

        offset = 0;
        for (i = 0; i < *(u16 *)(data + 0xC); i++, offset += 0x1C) {
            record = (u8 *)*(u32 *)(data + 0x10) + offset;
            temp = record[0xC]; record[0xC] = record[0xF]; record[0xF] = temp;
            temp = record[0xD]; record[0xD] = record[0xE]; record[0xE] = temp;
            temp = record[0x10]; record[0x10] = record[0x13]; record[0x13] = temp;
            temp = record[0x11]; record[0x11] = record[0x12]; record[0x12] = temp;
            temp = record[0x14]; record[0x14] = record[0x17]; record[0x17] = temp;
            temp = record[0x15]; record[0x15] = record[0x16]; record[0x16] = temp;
            temp = record[0x18]; record[0x18] = record[0x1B]; record[0x1B] = temp;
            temp = record[0x19]; record[0x19] = record[0x1A]; record[0x1A] = temp;

            temp = record[0]; record[0] = record[3]; record[3] = temp;
            temp = record[1]; record[1] = record[2]; record[2] = temp;
            temp = record[8]; record[8] = record[0xB]; record[0xB] = temp;
            temp = record[9]; record[9] = record[0xA]; record[0xA] = temp;
            temp = record[4]; record[4] = record[7]; record[7] = temp;
            temp = record[5]; record[5] = record[6]; record[6] = temp;
        }
    }

    strncpy(name, arg0, 0xB);
    name[0xB] = 0;
    fn_80028E00(name, lbl_8055B9D4);
    if (strlen(name) > 0x10) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80340440 + 0x15C, name, 0x10, strlen(name));
    }
    index = fn_802CAC34(name, *(s32 *)(data + 0x18));
    if (index == -1) {
        fn_802E30C8(lbl_80340440 + 0x190);
        return 0;
    }
    *(s32 *)data = index;
    *(s32 *)(data + 8) = fn_80231730((s32)arg0);
    fn_8023158C(data, arg0);
    return (s32)data;
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
extern void fn_8022C8B98(void);
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
    #pragma scheduling invalid_target
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
// Matched with the shared variadic wrapper signature and 0x80-byte formatting buffer.
void fn_802339A8(f32 a, s32 b, f32 c, s32 d, f32 e, f32 f, s32 g, f32 h, const char *fmt, ...) {
    #pragma scheduling invalid_target
    char buffer[0x80];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    fn_80232DF4((u8 *)buffer, b, d, g, a, c, f, e, h);
}

extern void fn_80231380(void *, s32, f32, f32, f32, f32, f32);
extern void fn_802C8DB8(void *, s32, u16 *, s32, s32, s32, s32, s32);
extern u16 lbl_802F9FF0[];
void fn_80233AA4(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    u8 *entry;
    u16 values[6];

    if (arg1 != 0x20) {
        entry = *(u8 **)((u8 *)arg0 + 0x10) + arg1 * 0x1C;
        fn_80231380(&values[0], lbl_8055F050, farg0, farg1, farg4,
                    *(f32 *)(entry + 0xC), *(f32 *)(entry + 0x10));
        entry = *(u8 **)((u8 *)arg0 + 0x10) + arg1 * 0x1C;
        fn_80231380(&values[2], lbl_8055F050, farg2, farg3, farg4,
                    *(f32 *)(entry + 0x14), *(f32 *)(entry + 0x10));
        entry = *(u8 **)((u8 *)arg0 + 0x10) + arg1 * 0x1C;
        fn_80231380(&values[4], lbl_8055F050, farg0, farg3, farg4,
                    *(f32 *)(entry + 0xC), *(f32 *)(entry + 0x18));
        entry = *(u8 **)((u8 *)arg0 + 0x10) + arg1 * 0x1C;
        fn_80231380(&values[6], lbl_8055F050, farg2, farg3, farg4,
                    *(f32 *)(entry + 0x14), *(f32 *)(entry + 0x18));
        values[0] = lbl_802F9FF0[0];
        values[1] = lbl_802F9FF0[1];
        values[2] = lbl_802F9FF0[2];
        values[3] = lbl_802F9FF0[3];
        values[4] = lbl_802F9FF0[4];
        values[5] = lbl_802F9FF0[5];
        fn_802C8DB8(&values[0], 4, &values[0], 6,
                    lbl_802F9FF0[1], lbl_802F9FF0[2], lbl_802F9FF0[3], lbl_802F9FF0[4]);
    }
}

extern f32 lbl_80563688;
extern f64 lbl_80563698;
#pragma scheduling invalid_target
void fn_80233BF0(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3, s32 arg4, f32 farg0, f32 farg1) {
    u32 code;
    f32 value;

    if (arg4 & 1) {
        u8 first = arg0[0];
        if ((first & 0xF0) == 0xE0) {
            code = ((first & 0x0F) << 12) | ((arg0[1] & 0x3F) << 6) | (arg0[2] & 0x3F);
        } else if ((first & 0xE0) == 0xC0) {
            code = ((first & 0x1F) << 6) | (arg0[1] & 0x3F);
        } else {
            code = first & 0x7F;
        }
        *arg2 -= *(f32 *)(*(u8 **)(arg1 + 0x10) + (code & 0xFFFF) * 0x1C);
    } else if (arg4 & 2) {
        *arg2 -= farg0 * fn_8023293C((s32)arg1, (char *)arg0, farg1);
    } else if (arg4 & 4) {
        *arg2 -= farg0 * fn_8023293C((s32)arg1, (char *)arg0, farg1) * lbl_80563688;
    }
    value = *(f32 *)((u8 *)fn_8022EDC4() + 0x38);
    if (arg4 & 8) {
        *arg3 -= value * ((f32)arg1[4] * farg0);
    } else if (arg4 & 0x20) {
        *arg3 -= value * ((f32)arg1[6] * farg0);
    } else if (arg4 & 0x10) {
        *arg3 -= value * ((f32)arg1[4] * farg0) * lbl_80563688;
    }
}
#pragma scheduling on
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

extern u16 lbl_802F9FFC[];
void fn_80233EC0(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    register void *object = arg0;
    register s32 font = lbl_8055F050;
    u8 out3[0x18], out2[0x18], out1[0x18], out0[0x18];
    u16 values[6];
    u8 *entry;

    if (arg1 != 0x20) {
        entry = *(u8 **)((u8 *)object + 0x10) + arg1 * 0x1C;
        fn_80231380(out0, font, farg0, farg1, farg2, *(f32 *)(entry + 0xC), *(f32 *)(entry + 0x18));
        entry = *(u8 **)((u8 *)object + 0x10) + arg1 * 0x1C;
        fn_80231380(out1, font, farg3, farg1, farg2, *(f32 *)(entry + 0xC), *(f32 *)(entry + 0x10));
        entry = *(u8 **)((u8 *)object + 0x10) + arg1 * 0x1C;
        fn_80231380(out2, font, farg0, farg4, farg5, *(f32 *)(entry + 0x14), *(f32 *)(entry + 0x18));
        entry = *(u8 **)((u8 *)object + 0x10) + arg1 * 0x1C;
        fn_80231380(out3, font, farg3, farg4, farg5, *(f32 *)(entry + 0x14), *(f32 *)(entry + 0x10));
        values[0] = lbl_802F9FFC[0]; values[1] = lbl_802F9FFC[1];
        values[2] = lbl_802F9FFC[2]; values[3] = lbl_802F9FFC[3];
        values[4] = lbl_802F9FFC[4]; values[5] = lbl_802F9FFC[5];
        fn_802C8DB8(out0, 4, values, 6, lbl_802F9FFC[1], lbl_802F9FFC[2], lbl_802F9FFC[3], lbl_802F9FFC[4]);
    }
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
typedef struct { const char *name; f32 scale; u8 pad[4]; s32 font; s32 glyph; f32 offset; } GlyphCommand;
typedef struct { u8 pad[0x10]; GlyphCommand *glyphs; } DrawContext;

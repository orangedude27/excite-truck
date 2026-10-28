#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "MSL/stdarg.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80232040(u8 *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern f32 fn_8023293C(s32, char *, f32);
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
extern u8 lbl_80497F14[];
extern f32 lbl_80563680;
extern f32 lbl_80563684;
extern f32 lbl_80563688;
extern f32 lbl_8056368C;
extern void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 fn_802C8DBC(s32);
extern void fn_802C8D74(void);
extern void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
extern void fn_802C8E48(void);
static inline void transform_vec_values(const f32 *matrix, const f32 *src, f32 *dst, f32 x, f32 y, f32 z) {
    f32 outX;
    f32 outY;
    f32 outZ;

    if (src == dst) {
        f32 xy3 = y * matrix[3];
        f32 xx0 = x * matrix[0];
        f32 xx1 = x * matrix[1];
        f32 yy4 = y * matrix[4];
        f32 xx2 = x * matrix[2];
        f32 yy5 = y * matrix[5];
        outX = (xx0 + xy3) + z * matrix[6];
        outY = (xx1 + yy4) + z * matrix[7];
        outZ = (xx2 + yy5) + z * matrix[8];
    } else {
        x = src[0];
        y = src[1];
        z = src[2];
        outX = x * matrix[0] + y * matrix[3] + z * matrix[6];
        outY = x * matrix[1] + y * matrix[4] + z * matrix[7];
        outZ = x * matrix[2] + y * matrix[5] + z * matrix[8];
    }
    dst[0] = outX + matrix[9];
    dst[1] = outY + matrix[10];
    dst[2] = outZ + matrix[11];
}
#define transform_vec(matrix, src, dst) transform_vec_values(matrix, src, dst, (src)[0], (src)[1], (src)[2])
extern s32 fn_802315FC(s32);
extern void fn_802E30C8(const char *);
extern void fn_802E317C(const char *);
extern void *fn_801284F8(s32, const char *);
extern char lbl_8034044C[];
extern char lbl_80340488[];
extern char lbl_803404C0[];
extern s32 stricmp(const char *, const char *);
extern void *fn_8012850C(s32, const char *);
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
    s32 offset = 0;
    s32 i = 0;
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

#pragma dont_inline on
void fn_8023158C(void *arg0, const char *arg1) {
    u8 *base;
    s32 count;
    s32 offset;
    u8 *entry;

    base = lbl_8055F068;
    count = *(s32 *)(base + 0x168);
    offset = count * 0xC;
    *(s32 *)(base + 0x168) = count + 1;
    entry = base + offset;
    *(void **)(base + offset) = arg0;
    *(s32 *)(entry + 8) = 1;
    *(char **)(entry + 4) = fn_8012850C(0x40, lbl_80340440);
    strcpy(*(char **)(entry + 4), arg1);
}
#pragma dont_inline off

#pragma push
#pragma scheduling invalid_target
s32 fn_802315FC(s32 arg0) {
    s32 offset = arg0 * 0xC;
    u8 *entry = lbl_8055F068 + offset;

    /* Decrement the entry reference count; replace its slot after releasing an expired entry. */
    if ((*(s32 *)(entry + 8) -= 1) < 1) {
        u8 *destination;
        u8 *source;
        u8 *base;
        s32 last;
        s32 lastOffset;
        fn_802CAC54(*(void **)*(void **)entry);
        fn_8012C4D8(*(void **)entry);
        fn_80128670(*(void **)(entry + 4));
        base = lbl_8055F068;
        destination = base + offset;
        last = *(s32 *)(base + 0x168);
        last -= 1;
        lastOffset = last * 0xC;
        *(s32 *)(base + 0x168) = last;
        source = base + lastOffset;
        *(s32 *)destination = *(s32 *)source;
        *(s32 *)(destination + 4) = *(s32 *)(source + 4);
        *(s32 *)(destination + 8) = *(s32 *)(source + 8);
        return 1;
    }
    return 0;
}
#pragma pop
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
    u32 result = __rlwinm(value, 0, 8, 15);
    result = __rlwimi(result, arg0, 0, 0, 7);
    return result | (value & 0xFFFF);
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
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
void fn_80231780(void *arg0) {
    f32 f25;
    f32 f26;
    f32 f27;
    f32 f28;
    f32 f29;
    f32 f30;
    f32 f31;
    volatile f32 sp10;
    volatile f32 spC;
    volatile f32 sp8;
    f32 x;
    f32 y;
    f32 z;
    u8 *record;
    s32 color;
    s32 offset;
    s32 i;
    u8 *object;
    s32 index;

    f31 = lbl_80563680;
    f30 = lbl_80563684;
    f29 = lbl_80563688;
    i = 0;
    offset = 0;
    goto loop_test;

loop_body:
    record = *(u8 **)&lbl_8049846C[0] + offset;
    index = *(s32 *)record;
    object = *(u8 **)lbl_80497F14 + index * 0x1C;

    if (object[0x14] != 0)
        color = *(s32 *)(record + 0x18);
    else
        color = fn_80230B9C((*(s32 *)(record + 0x18) & 0xFF000000) | 0x00FFFFFF);

    if (*(s32 *)(object + 0x0C) != 0) {
        z = *(f32 *)(record + 0x0C);
        y = *(f32 *)(record + 8);
        x = *(f32 *)(record + 4);
        sp8 = x;
        spC = y;
        sp10 = z;
        if (arg0 != 0) {
            transform_vec_values((f32 *)arg0, (const f32 *)&sp8, (f32 *)&sp8, x, y, z);
        }
        {
            f32 rate = *(f32 *)((u8 *)fn_8022EDC4() + 0x38);
            f32 ratio;
            if (rate <= f31) rate = f31;
            ratio = f30 / rate;
            fn_802354A0(*(s32 *)(object + 0x0C), *(s32 *)(object + 0x10), color,
                        sp8 - f29 * (ratio * *(f32 *)(record + 0x14) - *(f32 *)(record + 0x14)),
                        spC + f29 * (ratio * *(f32 *)(record + 0x10) - *(f32 *)(record + 0x10)),
                        sp10, ratio * *(f32 *)(record + 0x14), ratio * *(f32 *)(record + 0x10));
        }
    } else {
        if (arg0 != 0)
            fn_802C8B98(*(s32 *)(*(u8 **)lbl_80497F14 + *(s32 *)record * 0x1C + 8), (s32)arg0);
        else
            fn_802C8B98(*(s32 *)(*(u8 **)lbl_80497F14 + *(s32 *)record * 0x1C + 8), fn_8022EDC4());
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
#pragma scheduling on
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
    if (lbl_8055F068 != 0) ((void (*)(const char *, ...))fn_802E317C)(lbl_80340488);
    lbl_8055F068 = fn_801284F8(0x16C, lbl_803404C0);
    memset(lbl_8055F068, 0, 0x16C);
}

extern void fn_80235380(void);
#pragma push
#pragma scheduling invalid_target
void fn_8023243C(void) {
    s32 offset = 0;
    s32 i = 0;

    /* Release nonempty record resources and handles, then clear the active count. */
    while (i < *(s32 *)(lbl_80497F14 + 4)) {
        void *resource = *(void **)(*(u8 **)lbl_80497F14 + offset + 0xC);
        if (resource != 0) {
            ((void (*)(void *))fn_80235380)(resource);
        }
        if (*(s32 *)(*(u8 **)lbl_80497F14 + offset + 8) != -1) {
            fn_802CAC54(*(void **)(*(u8 **)lbl_80497F14 + offset + 8));
        }
        offset += 0x1C;
        i++;
    }
    *(s32 *)(lbl_80497F14 + 4) = 0;
}

extern char lbl_803404FC[];
extern void fn_802CB228(void *);
extern void fn_80128668(void);
void fn_802324D8(void) {
    s32 offset = 0;
    s32 i = 0;

    /* Log and release each 12-byte entry, then clear the global list. */
    while (i < *(s32 *)(lbl_8055F068 + 0x168)) {
        u8 *entry = lbl_8055F068 + offset;
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_803404FC, *(s32 *)(entry + 4));
        fn_802CB228(*(void **)*(void **)entry);
        fn_8012C4D8(*(void **)entry);
        fn_80128670(*(void **)(entry + 4));
        offset += 0xC;
        i++;
    }
    fn_80128668();
    lbl_8055F068 = 0;
}

#pragma pop
extern void *fn_8012C370(const char *, s32, u32 *, s32 *, u8 *, u8 *);
extern void fn_80028E00(char *, const char *);
extern s32 fn_802CAC34(char *, s32);
extern u32 lbl_8055B9D4;
#pragma push
#pragma small_data on
s32 fn_80232578(const char *arg0) {
    register char *stringBase = lbl_80340440;
    s32 index;
    s32 offset;
    u8 *data;
    u8 *record;
    u8 *record2;
    s32 tempWide;
    u8 temp2;
    s32 unused;
    u32 size;
    u8 valid;
    u8 swap;
    void *parsed;
    struct { char name[0xC]; s32 pad; } nameBuffer;
    s32 i;
    u8 temp;
    u32 value;

    index = fn_8023150C(arg0);
    if (index >= 0) {
        offset = index * 0xC;
        data = lbl_8055F068 + offset;
        value = *(u32 *)(data + 8);
        *(u32 *)(data + 8) = value + 1;
        value = (u32)fn_80231730((s32)arg0);
        *(u32 *)((u8 *)*(u32 *)data + 8) = value;
        return *(s32 *)data;
    }

    valid = 0;
    swap = 0;
    unused = 0;
    parsed = fn_8012C370(arg0, 0x47544558, &size, &unused, &valid, &swap);
    data = (u8 *)parsed;
    if (parsed != 0) {
        if (size != 8) {
            ((void (*)(const char *, ...))fn_802E317C)(stringBase + 0xE4, arg0, size);
        }
        if (valid == 0) {
            ((void (*)(const char *, ...))fn_802E317C)(stringBase + 0x108, arg0);
        }
    } else {
        ((void (*)(const char *, ...))fn_802E30C8)(stringBase + 0x144, arg0);
        return 0;
    }

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

        i = 0;
        offset = 0;
        for (; i < *(u16 *)(data + 0xC); i++, offset += 0x1C) {
            record = (u8 *)*(u32 *)(data + 0x10) + offset;
            temp = record[0xC]; record[0xC] = record[0xF]; record[0xF] = temp;
            temp = record[0xD]; record[0xD] = record[0xE]; record[0xE] = temp;
            temp = record[0x10]; record[0x10] = record[0x13]; record[0x13] = temp;
            temp = record[0x11]; record[0x11] = record[0x12]; record[0x12] = temp;
            temp = record[0x14]; record[0x14] = record[0x17]; record[0x17] = temp;
            temp = record[0x15]; record[0x15] = record[0x16]; record[0x16] = temp;
            temp = record[0x18]; record[0x18] = record[0x1B]; record[0x1B] = temp;
            temp = record[0x19]; record[0x19] = record[0x1A]; record[0x1A] = temp;

            record2 = (u8 *)*(u32 *)(data + 0x10) + offset;
            tempWide = record2[0]; record2[0] = record2[3]; record2[3] = (u8)tempWide;
            temp2 = record2[1]; record2[1] = record2[2]; record2[2] = temp2;

            record2 = (u8 *)*(u32 *)(data + 0x10) + offset;
            temp2 = record2[8]; record2[8] = record2[0xB]; record2[0xB] = temp2;
            temp2 = record2[9]; record2[9] = record2[0xA]; record2[0xA] = temp2;

            record2 = (u8 *)*(u32 *)(data + 0x10) + offset;
            temp2 = record2[4]; record2[4] = record2[7]; record2[7] = temp2;
            temp2 = record2[5]; record2[5] = record2[6]; record2[6] = temp2;
        }
    }

    strncpy(nameBuffer.name, arg0, 0xB);
    nameBuffer.name[0xB] = 0;
    fn_80028E00(nameBuffer.name, (const char *)&lbl_8055B9D4);
    if (strlen(nameBuffer.name) > 0x10) {
        ((void (*)(const char *, ...))fn_802E317C)(stringBase + 0x15C, nameBuffer.name, 0x10, strlen(nameBuffer.name));
    }
    index = fn_802CAC34(nameBuffer.name, *(s32 *)(data + 0x18));
    if (index == -1) {
        ((void (*)(const char *, ...))fn_802E30C8)(stringBase + 0x190);
        return 0;
    }
    *(s32 *)data = index;
    *(s32 *)(data + 8) = fn_80231730((s32)arg0);
    fn_8023158C(data, arg0);
    return (s32)data;
}

#pragma dont_inline on
void fn_802328D4(s32 arg0) {
    s32 value = *(s32 *)(arg0 + 8);
    if (value != 0 && fn_802316A4((void *)value) != 0) {
        *(s32 *)(arg0 + 8) = 0;
    }
    fn_802316A4((void *)arg0);
}
#pragma dont_inline off

#pragma pop
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

#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_80232BA4(char *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    s32 sp8 = arg2;

    /* Let the debug hook adjust arg2, then render only when the text is nonempty. */
    fn_80231714(&sp8);
    if ((s8)*arg0 != 0) {
        fn_80232040((u8 *)arg0, arg1, sp8, arg3, 0, farg0, farg1, farg2, farg3, farg4, lbl_8056368C);
    }
}

#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_80232C50(char *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    s32 sp8 = arg2;
    f32 spacing = farg3 - farg2 * fn_8023293C(arg1, arg0, farg5);

    spacing /= (f32)strlen(arg0);
    fn_80231714(&sp8);
    if ((s8)*arg0 != 0) {
        fn_80232040((u8 *)arg0, arg1, sp8, arg3, 0, farg0, farg1, farg2, farg4, farg5, spacing);
    }
}
#pragma pop

#pragma pop
#pragma dont_inline off

extern int vsprintf(char *, const char *, va_list);
extern f32 lbl_8056368C;
extern f32 lbl_80563684;
extern void fn_80232040(u8 *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void fn_80232BA4(char *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void fn_802C8D74(void);
#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_80232D3C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    s32 sp8 = arg2;

    fn_80231714(&sp8);
    if ((s8)*arg0 != 0) {
        fn_80232040(arg0, arg1, sp8, arg3, arg4, farg0, farg1, farg2, farg3, farg4, lbl_8056368C);
    }
}
#pragma pop
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

#pragma push
#pragma dont_inline on
void fn_80233600(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1, f32 farg2) {
    #pragma scheduling invalid_target
    s32 sp8;

    sp8 = arg2;
    fn_80231714(&sp8);
    if ((s8)*arg0 != 0) {
        fn_80232040(arg0, arg1, sp8, arg3, 0, farg0, farg1, lbl_80563684, farg2, lbl_80563684, lbl_8056368C);
    }
}
#pragma pop

void fn_802336AC(s32 arg0, s32 arg1, s32 arg2, const char *fmt, f32 farg0, f32 farg1, f32 farg2, ...) {
    #pragma scheduling invalid_target
    char buffer[0x78];
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
void fn_8023389C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, const char *fmt, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, ...) {
    char buffer[0x80];
    va_list args;
    va_start(args, farg4);
    vsprintf(buffer, fmt, args);
    fn_80232D3C((u8 *)buffer, arg0, arg1, arg2, arg3, farg0, farg1, farg3, farg2, farg4);
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
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80233AA4(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    register void *object = arg0;
    register s32 font;
    register s32 offset;
    u8 out3[0x18], out2[0x18], out1[0x18], out0[0x18];
    u16 values[6];
    u8 *entry;

    if (arg1 != 0x20) {
        offset = arg1 * 0x1C;
        entry = *(u8 **)((u8 *)object + 0x10) + offset;
        font = lbl_8055F050;
        fn_80231380(out0, font, farg0, farg1, farg4,
                    *(f32 *)(entry + 0xC), *(f32 *)(entry + 0x10));
        entry = *(u8 **)((u8 *)object + 0x10) + offset;
        fn_80231380(out1, font, farg2, farg1, farg4,
                    *(f32 *)(entry + 0x14), *(f32 *)(entry + 0x10));
        entry = *(u8 **)((u8 *)object + 0x10) + offset;
        fn_80231380(out2, font, farg0, farg3, farg4,
                    *(f32 *)(entry + 0xC), *(f32 *)(entry + 0x18));
        entry = *(u8 **)((u8 *)object + 0x10) + offset;
        fn_80231380(out3, font, farg2, farg3, farg4,
                    *(f32 *)(entry + 0x14), *(f32 *)(entry + 0x18));

        values[0] = lbl_802F9FF0[0];
        values[1] = lbl_802F9FF0[1];
        values[2] = lbl_802F9FF0[2];
        values[3] = lbl_802F9FF0[3];
        values[4] = lbl_802F9FF0[4];
        values[5] = lbl_802F9FF0[5];
        fn_802C8DB8(out0, 4, values, 6,
                    lbl_802F9FF0[4], lbl_802F9FF0[3], lbl_802F9FF0[2], lbl_802F9FF0[1]);
    }
}
#pragma pop

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

typedef struct IndexList_80233EC0 { u16 idx[6]; } IndexList_80233EC0;
extern IndexList_80233EC0 lbl_802F9FFC;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80233EC0(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    struct IndexList {
        u16 idx[6];
    };
    register void *object = arg0;
    register s32 offset;
    register s32 font;
    u8 out3[0x18], out2[0x18], out1[0x18], out0[0x18];
    struct IndexList values;
    u8 *entry;
    if (arg1 != 0x20) {
        offset = arg1 * 0x1C;
        entry = *(u8 **)((u8 *)object + 0x10) + offset;
        font = lbl_8055F050;
        fn_80231380(out0, font, farg0, farg1, farg2,
                    *(f32 *)(entry + 0xC), *(f32 *)(entry + 0x18));
        entry = *(u8 **)((u8 *)object + 0x10) + offset;
        fn_80231380(out1, font, farg3, farg1, farg2,
                    *(f32 *)(entry + 0xC), *(f32 *)(entry + 0x10));
        entry = *(u8 **)((u8 *)object + 0x10) + offset;
        fn_80231380(out2, font, farg0, farg4, farg5,
                    *(f32 *)(entry + 0x14), *(f32 *)(entry + 0x18));
        entry = *(u8 **)((u8 *)object + 0x10) + offset;
        fn_80231380(out3, font, farg3, farg4, farg5,
                    *(f32 *)(entry + 0x14), *(f32 *)(entry + 0x10));
        values = *(struct IndexList *)(void *)&lbl_802F9FFC;
        fn_802C8DB8(out0, 4, values.idx, 6,
                    values.idx[4], values.idx[3], values.idx[2], values.idx[1]);
    }
}
#pragma pop

void fn_8023441C(const char *arg0) {
    lbl_8055F06C = (s32)((void *(*)(s32, const char *))fn_8012850C)(0x2100, lbl_80340614);
    lbl_8055F058 = fn_80232578(arg0);
    *(s32 *)((u8 *)&lbl_8055F058 + 4) = 0;
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

extern s32 fn_8002B1D8(const char *, const char *, s32);
extern f32 fn_80235EF0(s32, s32);
extern f32 fn_80235F64(s32, s32);
extern void fn_802C8BD0(s32);
#pragma cplusplus reset
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802346C8(void) {
register f32 f30 = lbl_80563688;
register f32 f31 = lbl_8056368C;
f32 f28;
f32 f27;
f32 f26;
f32 f25;
f32 f24;
volatile f32 sp8;
register s32 mode;
register s32 i;
register s32 textOffset;
register s32 charIndex;
register s32 nameIndex;
register s32 glyphOffset;
register u32 *colorPtr;
register u8 *object;
register u8 *record;
register u8 *glyphDef;
register u32 fontColor;
register s8 *start;
s32 totalChars;
s32 charStep;
s32 glyphIndex;
u16 decoded;
s32 code;
s32 *queue;
u8 *render;
u8 *glyphs;

s8 *end;

object = (u8 *)lbl_8055F058;
mode = (*(u8 **)(object + 8) != 0) + 1;
goto outer_test;
outer_body:
if (mode == 2) object = *(u8 **)(lbl_8055F058 + 8);
else object = (u8 *)lbl_8055F058;
fn_802C8BD0(*(s32 *)object);
totalChars = fn_80234654();
totalChars <<= 2;
if (totalChars > 0 && fn_802C8DBC(totalChars) != 0) {
i = 0;
textOffset = 0;
goto record_test;
record_body:
record = (u8 *)lbl_8055F06C + textOffset;
f26 = *(f32 *)(record + 0x44);
f28 = (f32)object[4] * *(f32 *)(record + 0x50);
f27 = f28 + f26;
if (mode == 2) colorPtr = (u32 *)(record + 0x4C);
else colorPtr = (u32 *)(record + 0x48);
f25 = *(f32 *)(record + 0x40);
strlen((const char *)((u8 *)lbl_8055F06C + textOffset));
charIndex = 0;
goto char_test;
char_body:
sp8 = f28;
start = (s8 *)(record + charIndex);
fontColor = *colorPtr;
if ((s32)((u8 *)lbl_8055F06C + textOffset)[charIndex] == '\\') {
nameIndex = 0;
glyphOffset = 0;
goto name_test;
name_body:
glyphDef = *(u8 **)lbl_80497F14 + glyphOffset;
if (fn_8002B1D8((const char *)(start + 1),
(const char *)*(u8 **)glyphDef,
strlen((const char *)*(u8 **)glyphDef)) == 0) {
queue = (s32 *)lbl_8049846C;
f24 = lbl_8056368C;
glyphIndex = queue[1];
render = *(u8 **)queue + glyphIndex * 0x1C;
queue[1] = glyphIndex + 1;
*(s32 *)render = nameIndex;
if (*(s32 *)(glyphDef + 0x0C) != 0) {
f24 = f28 / fn_80235F64(*(s32 *)(glyphDef + 0x0C),
*(s32 *)(glyphDef + 0x10));
*(f32 *)(render + 0x10) = f28 * *(f32 *)(glyphDef + 4);
*(f32 *)(render + 0x14) =
f24 * *(f32 *)(glyphDef + 4) *
fn_80235EF0(*(s32 *)(glyphDef + 0x0C),
*(s32 *)(glyphDef + 0x10));
f24 = *(f32 *)(glyphDef + 4) *
(*(f32 *)(glyphDef + 0x18) * f24);
} else {
*(f32 *)(render + 0x14) = f28 * *(f32 *)(glyphDef + 4);
*(f32 *)(render + 0x10) = f28 * *(f32 *)(glyphDef + 4);
}
*(f32 *)(render + 4) = f25;
*(f32 *)(render + 8) =
f27 + f30 * (*(f32 *)(render + 0x10) - f28);
*(f32 *)(render + 0x0C) = f31;
*(s32 *)(render + 0x18) = fontColor;
if (&sp8 != 0) {
sp8 = *(f32 *)(render + 0x14) + f24;
charStep = (s32)strlen((const char *)*(u8 **)glyphDef) + 1;
}
goto icon_found;
} else {
glyphOffset += 0x1C;
nameIndex++;
goto name_test;
}
name_test:
if (nameIndex < ((s32 *)lbl_80497F14)[1]) goto name_body;
}
charStep = 0;
icon_found:
;
if (charStep > 0) {
charIndex += charStep;
f25 += sp8;
goto char_test;
}
if ((start[0] & 0xF0) == 0xE0) {
decoded = ((start[0] & 0x0F) << 12) |
((start[1] & 0x3F) << 6) | (start[2] & 0x3F);
end = start + 3;
} else if ((start[0] & 0xE0) == 0xC0) {
decoded = ((start[0] & 0x1F) << 6) | (start[1] & 0x3F);
end = start + 2;
} else {
decoded = start[0] & 0x7F;
end = start + 1;
}
code = decoded;
glyphOffset = code * 0x1C;
glyphs = *(u8 **)(object + 0x10);
f25 += *(f32 *)(record + 0x54) * *(f32 *)(glyphs += glyphOffset);
f24 = f25 + *(f32 *)(record + 0x50) * *(f32 *)(glyphs + 4);
if (code != 0x20) {
fn_802C8E00(*colorPtr, 0, f25, f27, lbl_8056368C,
*(f32 *)(glyphs + 0x0C), *(f32 *)(glyphs + 0x10));
fn_802C8E00(*colorPtr, 0, f24, f27, lbl_8056368C,
*(f32 *)(glyphs + 0x14), *(f32 *)(glyphs + 0x10));
fn_802C8E00(*colorPtr, 1, f25, f26, lbl_8056368C,
*(f32 *)(glyphs + 0x0C), *(f32 *)(glyphs + 0x18));
fn_802C8E00(*colorPtr, 1, f24, f26, lbl_8056368C,
*(f32 *)(glyphs + 0x14), *(f32 *)(glyphs + 0x18));
}
charIndex += end - start;
f25 += *(f32 *)(record + 0x50) * *(f32 *)(glyphs + 4);
f25 += *(f32 *)(record + 0x54) * *(f32 *)(glyphs + 8);
char_test:
if ((s8)(((u8 *)lbl_8055F06C + textOffset)[charIndex]) != 0) goto char_body;
textOffset += 0x58;
i++;
record_test:
if (i < *(s32 *)((u8 *)lbl_8055F058 + 4)) goto record_body;
fn_802C8E48();
}
fn_802C8D74();
if (mode == 2) fn_80231ADC();
else fn_80231780(0);
mode--;
outer_test:
if (mode > 0) goto outer_body;
*(s32 *)((u8 *)lbl_8055F058 + 4) = 0;
}
#pragma dont_inline off
#pragma scheduling on
#pragma pop

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

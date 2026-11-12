// drgc_tex — GC texture creation ("drgc/tex:", drCreateTexture).
// Recovered TU window 0x802D7564..0x802D98BC+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802D98BC (+ .ctors slot 0x802ED5C8) remains in
// auto/text_802D98BC_.c pending a promotion pass.
#include "types.h"
extern void DCFlushRange(void *, unsigned int);
extern unsigned int GXGetTexBufferSize(unsigned short, unsigned short, unsigned int, int, unsigned char);
extern void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, unsigned int);
extern void GXInitTexObjLOD(void *, int, int, float, float, float, int, int, int);
extern void GXInvalidateTexAll(void);
extern float lbl_80565018;
extern float lbl_8056501C;
extern double lbl_80565020;
extern void GXInitTexObjFilter(void *, int, int);
extern void GXInitTexObjWrapMode(void *, int, int);
extern unsigned int lbl_8055FD2C;
extern void *lbl_8055FE1C;
extern void *lbl_8055FE20;
extern void fn_802CFEEC(void);
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern char lbl_8034C4B0[];
extern void fn_802E317C(const char *, ...);
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_804C5700[12];
extern void GXLoadTexObj(void *, int);
extern void fn_80128670(void *);
extern void *lbl_8055FE28;
extern void *lbl_8055FE18;
extern void fn_802D7564(void);
extern void fn_802E30C8(const char *, ...);
extern void fn_802E317C(const char *, ...);
extern char lbl_8034C460[];
extern char lbl_8034C47C[];
extern char lbl_8034C494[];
extern unsigned short GXGetTexObjWrapS(void *);
extern unsigned short GXGetTexObjWrapT(void *);
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern char lbl_8055D110[];
extern void *fn_8012850C(void *, void *);
extern char lbl_8055D118[4];
extern void *fn_802D7600(void *queue);
extern char lbl_8034C4F8[];
extern char lbl_8034C528[];
extern void fn_801282F4(void);
extern void *fn_801284E8(void *, int);
extern char lbl_8034C4DC[];
extern char lbl_8034C4E8[];
extern void fn_801282EC(int);
extern void GXInitTexObjCI(void *, void *, unsigned short, unsigned short, int, int, int, int, int);
extern void GXInitTlutObj(void *, void *, int, unsigned short);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D7564(void) {
    int offset;
    int i;
    unsigned char *entry;
    unsigned short t;

    fn_802E30C8(lbl_8034C460);
    i = 0;
    offset = 0;
    do {
        entry = (unsigned char *)lbl_8055FE28 + offset;
        if (entry[0x20] != 0) {
            t = GXGetTexObjWrapT(entry + 0x24) & 0xFFFF;
            fn_802E30C8(lbl_8034C47C, i, entry,
                        (unsigned short)GXGetTexObjWrapS(entry + 0x24), t);
        }
        i++;
        offset += 0xF4;
    } while (i < 0x1C2);
}
#pragma pop

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802D7600(void *arg0) {
    unsigned char *entry;
    int i;

    entry = (unsigned char *)lbl_8055FE28;
    for (i = 0; i < 0x1C2; i++) {
        if (entry[0x20] == 0) {
            memset(entry, 0, 0xF4);
            entry[0x20] = 1;
            return entry;
        }
        entry += 0xF4;
    }
    fn_802D7564();
    fn_802E317C(lbl_8034C494, arg0);
    return 0;
}
#pragma pop

#pragma dont_inline on
void fn_802D768C(void *arg0) {
    extern void fn_80128658(s32);
    s32 temp_r0;

    temp_r0 = *(s32 *)((u8 *)arg0 + 0xE8);
    *(s8 *)((u8 *)arg0 + 0x20) = 0;
    if (temp_r0 != 0) {
        fn_80128658(temp_r0);
        *(s32 *)((u8 *)arg0 + 0xE8) = 0;
    }
}
#pragma dont_inline reset

#pragma scheduling invalid_target
#pragma dont_inline on
int fn_802D76DC(int arg0) {
    switch (arg0) {
    case 3:
    case 0x40:
    case 0x41:
    case 0x43:
    case 0x46:
    case 0x47:
    case 0x4A:
    case 0x4B:
        return 1;
    case 2:
    case 0x42:
    case 0x44:
    case 0x45:
    case 0x48:
    case 0x49:
    case 0x4C:
        return 0;
    }
    fn_802E317C(lbl_8034C4B0, arg0);
    return 1;
}
#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
void fn_802D7780(void *arg0, void *arg1) {
    u32 filter = *(u32 *)((u8 *)arg1 + 0x10);
    u32 opts = *(u32 *)((u8 *)arg1 + 0x18);
    int wrapS = filter & 1;
    int wrapT = (filter & 2) != 0;
    u32 firstMode;
    u32 transfer;
    u32 id;

    if ((opts & 2) == 0) {
        GXInitTexObjFilter((u8 *)arg0 + 0x24, 0, 0);
        if (*(u8 *)((u8 *)arg0 + 0xCC) != 0)
            GXInitTexObjFilter((u8 *)arg0 + 0x78, 0, 0);
    }
    GXInitTexObjWrapMode((u8 *)arg0 + 0x24, wrapS, wrapT);
    if (*(u8 *)((u8 *)arg0 + 0xCC) != 0)
        GXInitTexObjWrapMode((u8 *)arg0 + 0x78, wrapS, wrapT);

    firstMode = *(u32 *)((u8 *)arg1 + 0x14);
    transfer = *(u32 *)((u8 *)arg1 + 0x0C);
    *(u32 *)((u8 *)arg0 + 0xDC) = transfer;
    *(u8 *)((u8 *)arg0 + 0xE4) = *(u8 *)((u8 *)arg1 + 0x1C);
    *(u32 *)((u8 *)arg0 + 0xE0) = 0;
    if (firstMode & 1) *(u32 *)((u8 *)arg0 + 0xE0) |= 4;
    if (*(u32 *)((u8 *)arg1 + 0x14) & 2)
        *(u32 *)((u8 *)arg0 + 0xE0) |= 2;
    if (*(u32 *)((u8 *)arg1 + 0x14) == 7)
        *(u32 *)((u8 *)arg0 + 0xE0) |= 8;
    if (*(u32 *)((u8 *)arg1 + 0x18) & 4)
        *(u32 *)((u8 *)arg0 + 0xE0) |= 0x40;
    id = *(u32 *)arg1;
    if (fn_802D76DC(id & 0xFF) != 0)
        *(u32 *)((u8 *)arg0 + 0xE0) |= 0x100;
}
#pragma pop

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_802D78D4(void *arg0, void *arg1, unsigned int arg2, unsigned int arg3) {
    union Pixel { unsigned int word; unsigned char c[4]; };
    unsigned short *rgb = (unsigned short *)arg0;
    unsigned short *alpha = (unsigned short *)arg1;
    unsigned int *src = (unsigned int *)arg2;
    int n = (int)arg3;
    int i;
    for (i = 0; i < n; i++) {
        union Pixel p;
        p.word = src[i];
        rgb[i] = (unsigned short)(((p.c[0] & 0xF8) << 8) | ((p.c[1] & 0xFC) << 3) | ((p.c[2] & 0xF8) >> 3));
        alpha[i] = (unsigned short)(p.c[3] << 8);
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802D7B5C(void *arg0, void *arg1) {
    int isCi4;
    void *texture;
    void *obj = arg0;
    char *name = (char *)arg1;
    int entries;
    int palBytes;
    u32 rawPal;
    int width;
    int height;
    char *texData;
    int count;
    char *dst;
    unsigned char ch;
    int size;
    u32 type;

    type = *(u32 *)obj;
    isCi4 = 1;
    if (type != 0 && type != 0x40) {
        isCi4 = 0;
    }

    texture = *(void **)((char *)obj + 0x30);
    if (texture == 0) {
        texture = fn_802D7600(name);
    }

    count = 0x20;
    dst = (char *)texture;
    goto copy_char;
count_down:
    count--;
    if (count > 0) {
        goto copy_char;
    }
    dst[-1] = 0;
    goto copied_name;
copy_char:
    ch = (unsigned char)*name;
    name++;
    *dst = (char)ch;
    dst++;
    if ((signed char)ch != 0) {
        goto count_down;
    }
copied_name:
    entries = 0x100;
    if (isCi4 != 0) {
        entries = 0x10;
    }
    texData = *(char **)((char *)obj + 0x2C);
    rawPal = *(u32 *)texData;
    fn_801282EC(0x20);
    palBytes = entries * 2;
    *(void **)((char *)texture + 0x70) = fn_8012850C((void *)palBytes, lbl_8034C4DC);
    fn_801282EC(0x20);
    dst = (char *)fn_8012850C((void *)palBytes, lbl_8034C4E8);
    *(void **)((char *)texture + 0xC4) = dst;
    *(char *)((char *)texture + 0xCC) = 1;
    *(u32 *)((char *)texture + 0xD8) = rawPal;
    *(u32 *)((char *)texture + 0x74) = (u32)palBytes;
    fn_802D78D4(*(void **)((char *)texture + 0x70), dst, rawPal, entries);
    DCFlushRange(*(void **)((char *)texture + 0x70), *(u32 *)((char *)texture + 0x74));
    GXInitTlutObj((char *)texture + 0x64, *(void **)((char *)texture + 0x70), 1, (unsigned short)entries);
    *(u32 *)((char *)texture + 0xC8) = (u32)palBytes;
    DCFlushRange(*(void **)((char *)texture + 0xC4), (u32)palBytes);
    GXInitTlutObj((char *)texture + 0xB8, *(void **)((char *)texture + 0xC4), 0, (unsigned short)entries);

    width = *(int *)((char *)obj + 0x24);
    height = *(int *)((char *)obj + 0x28);
    GXGetTexBufferSize((unsigned short)width, (unsigned short)height, (isCi4 != 0) ? 8 : 9, 0, 1);
    texData = *(char **)((char *)obj + 0x2C);
    dst = *(char **)(texData + 4);
    *(char **)((char *)texture + 0xD0) = dst;
    size = (width * height) / ((isCi4 != 0) + 1);
    *(int *)((char *)texture + 0xD4) = size;
    DCFlushRange(dst, size);

    GXInitTexObjCI((char *)texture + 0x24, *(void **)(texData + 4),
                   (unsigned short)width, (unsigned short)height,
                   (isCi4 != 0) ? 8 : 9, 1, 1, 0, 0);
    GXInitTexObjCI((char *)texture + 0x78, *(void **)(texData + 4),
                   (unsigned short)width, (unsigned short)height,
                   (isCi4 != 0) ? 8 : 9, 1, 1, 0, 1);
    GXInvalidateTexAll();
    fn_802D7780(texture, obj);
    return texture;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802D7D98(void *arg0, void *arg1) {
    void *texture;
    void *obj = arg0;
    int format;
    int width;
    int height;
    char *work = (char *)arg1;
    int count;
    char *dst;
    unsigned char ch;
    int mult;
    u32 type;
    u32 lod;

    format = -1;
    type = *(u32 *)obj;
    if (type == 0x47 || type == 3) {
        format = 6;
    } else if (type == 0x45 || type == 2) {
        format = 4;
    } else {
        fn_802E317C(lbl_8034C4F8);
    }

    texture = *(void **)((char *)obj + 0x30);
    if (texture == 0) {
        texture = fn_802D7600(work);
    }

    dst = (char *)texture;
    count = 0x20;
    goto copy_char;
count_down:
    count--;
    if (count > 0) {
        goto copy_char;
    }
    dst[-1] = 0;
    goto copied_name;
copy_char:
    ch = (unsigned char)*work;
    work++;
    *dst = (char)ch;
    dst++;
    if ((signed char)ch != 0) {
        goto count_down;
    }
copied_name:
    width = *(int *)((char *)obj + 0x24);
    *(int *)((char *)texture + 0x70) = 0;
    height = *(int *)((char *)obj + 0x28);
    *(int *)((char *)texture + 0xC4) = 0;
    *(char *)((char *)texture + 0xCC) = 0;
    lod = GXGetTexBufferSize((unsigned short)width, (unsigned short)height, format, 0, 1);
    if (*(u32 *)((char *)obj + 4) == 3) {
        fn_801282F4();
        fn_801282EC(0x80);
        work = (char *)fn_801284E8(lbl_8034C528, (int)lod);
        *(char **)((char *)texture + 0xE8) = work;
    } else {
        work = *(char **)(*(char **)((char *)obj + 0x2C) + 4);
    }
    *(char **)((char *)texture + 0xD0) = work;
    mult = 2;
    if (format == 6) {
        mult = 4;
    }
    mult = mult * (width * height);
    *(int *)((char *)texture + 0xD4) = mult;
    DCFlushRange(*(void **)((char *)texture + 0xD0), mult);

    mult = *(int *)((char *)obj + 0x20);
    lod = (u32)((((mult ^ 2) >> 1) - ((mult ^ 2) & mult))) >> 31;
    GXInitTexObj((char *)texture + 0x24, work, (unsigned short)width,
                 (unsigned short)height, format, 1, 1, lod);
    if (lod != 0) {
        GXInitTexObjLOD((char *)((u32)texture + 0x24), 5, 1, lbl_80565018,
                        (float)(*(int *)((char *)obj + 0x20) - 1), lbl_8056501C, 1, 1, 0);
    }
    GXInvalidateTexAll();
    fn_802D7780(texture, obj);
    return texture;
}

extern int stricmp(const char *, const char *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802D7FA0(void *arg0, void *arg1) {
    char *base = lbl_8034C460;
    void *texture;
    void *obj = arg0;
    char *work = (char *)arg1;
    char *temp;
    int divisor;
    int format;
    int width;
    int height;
    int count;
    char *dst;
    unsigned char ch;
    int size;
    u32 type;
    u32 lod;
    int mult;

    format = -1;
    divisor = -1;
    type = *(u32 *)obj;
    switch (type) {
    case 0x48:
        divisor = 4;
        format = 0;
        break;
    case 0x49:
        divisor = 8;
        format = 1;
        break;
    case 0x4A:
        divisor = 8;
        format = 2;
        break;
    case 0x4B:
        divisor = 16;
        format = 3;
        break;
    case 0x45:
        divisor = 16;
        format = 4;
        break;
    case 0x46:
        divisor = 16;
        format = 5;
        break;
    default:
        fn_802E317C(base + 0xd8, type);
        break;
    }

    texture = *(void **)((char *)obj + 0x30);
    if (texture == 0) {
        goto alloc_texture;
    }
    goto got_texture;
alloc_texture:
    texture = fn_802D7600(work);
got_texture:

    dst = (char *)texture;
    count = 0x20;
    goto copy_char;
count_down:
    count--;
    if (count > 0) {
        goto copy_char;
    }
    dst[-1] = 0;
    goto copied_name;
copy_char:
    ch = (unsigned char)*work;
    work++;
    *dst = (char)ch;
    dst++;
    if ((signed char)ch != 0) {
        goto count_down;
    }
copied_name:
    width = *(int *)((char *)obj + 0x24);
    height = *(int *)((char *)obj + 0x28);
    *(int *)((char *)texture + 0x70) = 0;
    temp = *(char **)((char *)obj + 0x2C);
    *(int *)((char *)texture + 0xC4) = 0;
    *(char *)((char *)texture + 0xCC) = 0;
    size = ((width * height) * 8) / divisor;
    work = *(char **)(temp + 4);
    *(char **)((char *)texture + 0xD0) = work;
    *(int *)((char *)texture + 0xD4) = size;
    DCFlushRange(work, size);

    mult = *(int *)((char *)obj + 0x20);
    lod = (u32)((((mult ^ 2) >> 1) - ((mult ^ 2) & mult))) >> 31;
    GXInitTexObj((char *)texture + 0x24, work, (unsigned short)width,
                 (unsigned short)height, format, 1, 1, lod);
    height = *(int *)((char *)obj + 0x20);
    if (lod != 0) {
        if (stricmp((char *)texture, base + 0x104) == 0) {
            fn_802E30C8(base + 0x114, texture);
            height = 4;
        }
    }
    if (lod != 0) {
        GXInitTexObjLOD((char *)((u32)texture + 0x24), 5, 1, lbl_80565018,
                        (float)(height - 1), lbl_8056501C, 1, 1, 0);
    }
    GXInvalidateTexAll();
    fn_802D7780(texture, obj);
    return texture;
}
#pragma pop

#pragma pop

void fn_802D81C4(void *arg0, int arg1) {
    int width = *(int *)((char *)arg0 + 0x24);
    int height = *(int *)((char *)arg0 + 0x28);
    unsigned char *s2 = *(unsigned char **)((char *)arg0 + 0x2C);
    unsigned char *p = *(unsigned char **)(s2 + 4);
    unsigned char *q;
    unsigned char *d;
    unsigned char *line;
    unsigned char *tmp;
    int n = (width * height) / 2;
    int i, x, y, halfw, size;

    d = p;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            *d = (unsigned char)((*d >> 4) | (*d << 4));
            d++;
        }
    }
    q = *(unsigned char **)s2;
    for (i = 0; i < 0x10; i++) {
        unsigned char t0;
        unsigned char t1;
        t0 = q[0];
        q[0] = q[3];
        q[3] = t0;
        t1 = q[1];
        q[1] = q[2];
        q[2] = t1;
        q += 4;
    }
    halfw = width / 2;
    fn_801282EC(0x20);
    size = halfw * height;
    tmp = fn_8012850C((void *)size, lbl_8055D110);
    memcpy(tmp, p, (unsigned int)size);
    for (y = 0; y < height; y++) {
        line = tmp + y * halfw;
        for (x = 0; x < halfw; x++) {
            p[((y / 8) * (halfw / 4) + x / 4) * 32 + (y % 8) * 4 + x % 4] = *line++;
        }
    }
    fn_80128670(tmp);
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern char lbl_8034C5AC[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D86BC(void *arg0, int arg1) {
    void **data = *(void ***)((char *)arg0 + 0x2c);
    int width = *(int *)((char *)arg0 + 0x24);
    int height = *(int *)((char *)arg0 + 0x28);
    unsigned char *palette = (unsigned char *)data[0];
    unsigned char *image = (unsigned char *)data[1];
    unsigned char *copy;
    unsigned char c;
    int i, x, y, offset;
    for (i = 0; i < 64; i++) {
        c = palette[0]; palette[0] = palette[3]; palette[3] = c;
        c = palette[1]; palette[1] = palette[2]; palette[2] = c;
        c = palette[4]; palette[4] = palette[7]; palette[7] = c;
        c = palette[5]; palette[5] = palette[6]; palette[6] = c;
        c = palette[8]; palette[8] = palette[11]; palette[11] = c;
        c = palette[9]; palette[9] = palette[10]; palette[10] = c;
        c = palette[12]; palette[12] = palette[15]; palette[15] = c;
        c = palette[13]; palette[13] = palette[14]; palette[14] = c;
        palette += 16;
    }
    fn_801282EC(0x20);
    copy = (unsigned char *)fn_8012850C((void *)(width * height), lbl_8034C5AC);
    memcpy(copy, image, width * height);
    for (y = 0, offset = 0; y < height; y++, offset += width) {
        for (x = 0; x < width; x++) {
            image[((y / 4) * (width / 8) + x / 8) * 32 + (y % 4) * 8 + x % 8] = copy[offset + x];
        }
    }
    fn_80128670(copy);
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802D8A84(void *arg0, void *arg1) {
    void *texture;
    void *obj = arg0;
    char *work = (char *)arg1;
    int count;
    char *dst;
    unsigned char ch;
    int width;
    int height;
    int bytes;
    int format;

    texture = *(void **)((char *)obj + 0x30);
    texture = texture != 0 ? texture : fn_802D7600(work);

    dst = (char *)texture;
    count = 0x20;
    goto copy_char;
count_down:
    count--;
    if (count > 0) {
        goto copy_char;
    }
    dst[-1] = 0;
    goto copied_name;
copy_char:
    ch = (unsigned char)*work;
    work++;
    *dst = (char)ch;
    dst++;
    if ((signed char)ch != 0) {
        goto count_down;
    }
copied_name:
    width = *(int *)((char *)obj + 0x24);
    *(int *)((char *)texture + 0x70) = 0;
    height = *(int *)((char *)obj + 0x28);
    *(int *)((char *)texture + 0xC4) = 0;
    GXGetTexBufferSize((unsigned short)width, (unsigned short)height, 0xE, 0, 1);
    bytes = width * height;
    work = *(char **)(*(char **)((char *)obj + 0x2C) + 4);
    *(char **)((char *)texture + 0xD0) = work;
    bytes = (int)((u32)bytes + ((u32)bytes >> 31)) >> 1;
    *(int *)((char *)texture + 0xD4) = bytes;
    DCFlushRange(work, bytes);

    format = *(int *)((char *)obj + 0x20);
    GXInitTexObj((char *)texture + 0x24, work, (unsigned short)width,
                 (unsigned short)height, 0xE, 1, 1,
                 (u32)((((format ^ 2) >> 1) - ((format ^ 2) & format))) >> 31);
    if ((u32)((((format ^ 2) >> 1) - ((format ^ 2) & format))) >> 31) {
        GXInitTexObjLOD((char *)texture + 0x24, 5, 1, lbl_80565018,
                        (float)(*(int *)((char *)obj + 0x20) - 1), lbl_8056501C, 1, 1, 0);
    }
    GXInvalidateTexAll();
    fn_802D7780(texture, obj);
    return texture;
}
#pragma pop

#pragma dont_inline reset

void fn_802D8DA0(void) {
    fn_80128670(lbl_8055FE28);
    lbl_8055FE28 = 0;
}

extern void fn_802D81C4(void *, int);
extern void fn_802D86BC(void *, int);
void fn_802D8DCC(void *arg0, int arg1) {
    unsigned char *p;
    unsigned char t;
    unsigned int kind;
    p = *(unsigned char **)((char *)arg0 + 0x2C);
    t = p[0]; p[0] = p[3]; p[3] = t;
    t = p[1]; p[1] = p[2]; p[2] = t;
    if (*(int *)(p + 0) != 0) *(unsigned char **)(p + 0) = p + *(int *)(p + 0);
    t = p[4]; p[4] = p[7]; p[7] = t;
    t = p[5]; p[5] = p[6]; p[6] = t;
    if (*(int *)(p + 4) != 0) *(unsigned char **)(p + 4) = p + *(int *)(p + 4);
    t = p[8]; p[8] = p[11]; p[11] = t;
    t = p[9]; p[9] = p[10]; p[10] = t;
    if (*(int *)(p + 8) != 0) *(unsigned char **)(p + 8) = p + *(int *)(p + 8);
    kind = *(unsigned int *)arg0;
    if (kind == 0x40 || kind == 0) fn_802D81C4(arg0, arg1);
    else if (kind == 0x41 || kind == 1) fn_802D86BC(arg0, arg1);
}

extern void *fn_802D7B5C(void *, void *);
extern void *fn_802D7D98(void *, void *);
extern void *fn_802D7FA0(void *, void *);
extern void *fn_802D8A84(void *, void *);
extern void *fn_802D8C00(void *, void *);
extern void fn_802D9340(void *);
extern char lbl_8034C5C8[];
#pragma push
#pragma scheduling on
void *fn_802D8E9C(void *arg0, void *arg1) {
    register void *name = arg1;
    register int kind = *(int *)arg0;
    register void *obj = 0;
    if (kind == 0x17) goto use_a84;
    if (kind >= 0x17) goto high_range;
    if (kind == 0x10) goto use_a84;
    if (kind >= 0x10) goto low_mid;
    if (kind >= 0x02) goto low_two;
    if (kind < 0) goto report_error;
    goto use_b5c;
low_two:
    if (kind < 0x04) goto use_d98;
    goto report_error;
low_mid:
    if (kind < 0x12) goto use_c00;
    goto report_error;
high_range:
    if (kind == 0x44) goto use_c00;
    if (kind >= 0x44) goto high_tail;
    if (kind >= 0x42) goto use_a84;
    if (kind < 0x40) goto report_error;
    goto use_b5c;
high_tail:
    if (kind == 0x47) goto use_d98;
    if (kind < 0x47) goto use_fa0;
    if (kind >= 0x4C) goto report_error;
use_fa0:
    obj = fn_802D7FA0(arg0, name);
    goto finish;
use_b5c:
    obj = fn_802D7B5C(arg0, name);
    goto finish;
use_a84:
    obj = fn_802D8A84(arg0, name);
    goto finish;
use_c00:
    obj = fn_802D8C00(arg0, name);
    goto finish;
use_d98:
    obj = fn_802D7D98(arg0, name);
    goto finish;
report_error:
    fn_802E317C(lbl_8034C5C8, kind, name);
finish:
    fn_802D9340(obj);
    return obj;
}
#pragma pop
void fn_802D8FB4(void *texObj) {
    /* Release a texture object: flush pending work, free owned sub-objects, unlink, and clear global references. */
    if (*(unsigned int *)((char *)texObj + 0xF0) != 0 &&
        (unsigned int)(lbl_8055FD2C - *(unsigned int *)((char *)texObj + 0xEC)) >= 0xFFFFFF00U) {
        fn_802CFEEC();
    }
    if (*(unsigned int *)((char *)texObj + 0x70) != 0) {
        fn_80128670((void *)*(unsigned int *)((char *)texObj + 0x70));
    }
    if (*(unsigned int *)((char *)texObj + 0xC4) != 0) {
        fn_80128670((void *)*(unsigned int *)((char *)texObj + 0xC4));
    }
    fn_802D768C(texObj);
    if (lbl_8055FE18 == texObj) {
        lbl_8055FE18 = 0;
    }
    if (lbl_8055FE1C == texObj) {
        lbl_8055FE1C = 0;
    }
    if (lbl_8055FE20 == texObj) {
        lbl_8055FE20 = 0;
    }
}

extern unsigned int lbl_8055FD2C;
extern void *lbl_8055FE1C;
extern void *lbl_8055FE20;
extern void fn_802CFEEC(void);

/* Return 1 if any texture slot in the table has no owner at +0x20, else 0. */
int fn_802D9068(void) {
    unsigned char *slot = (unsigned char *)lbl_8055FE28;
    int slotIndex = 0;
    while (slotIndex < 450) {
        if (slot[0x20] == 0) return 1;
        slot += 0xF4;
        slotIndex++;
    }
    return 0;
}

void fn_802D9154(void) {
    fn_802D7600(lbl_8055D118);
}

extern void fn_802D768C(void *);
void fn_802D915C(void *arg0) {
    fn_802D768C(arg0);
}

extern void fn_802D6C68(void);
extern void fn_802CFF5C(void *);
extern void fn_802CFFA4(unsigned int);
extern void GXLoadTlut(void *, int);
extern unsigned int lbl_8055FD1C;
extern unsigned char lbl_8055FD24;
extern unsigned int lbl_8055FD30;
void fn_802D9160(void *arg0) {
    char *obj = (char *)arg0;
    /* Bind a texture (and optional secondary texture/T LUT) to GX state and record it as the active primary texture. */
    fn_802D6C68();
    lbl_8055FE18 = arg0;
    fn_802CFF5C((void *)(*(unsigned int *)(obj + 0xE0) | (lbl_8055FD1C & ~0x14E)));
    fn_802CFFA4(*(unsigned int *)(obj + 0xDC));
    lbl_8055FD24 = *(unsigned char *)(obj + 0xE4);
    if (*(int *)(obj + 0x70) != 0) GXLoadTlut(obj + 0x64, 0);
    GXLoadTexObj(obj + 0x24, 0);
    if (*(unsigned char *)(obj + 0xCC) != 0) {
        if (*(int *)(obj + 0xC4) != 0) GXLoadTlut(obj + 0xB8, 1);
        GXLoadTexObj(obj + 0x78, 1);
    }
    *(volatile unsigned int *)(obj + 0xEC) = lbl_8055FD30;
    *(unsigned int *)(obj + 0xF0) += 1;
    lbl_804C5700[8] = *(volatile unsigned char *)(obj + 0xCC);
}

extern void *lbl_8055FE1C;
extern void *lbl_8055FE20;
extern char lbl_8034C5F0[];
extern char lbl_8034C620[];
extern char lbl_8034C650[];
extern unsigned char lbl_804C5700[12];
extern void fn_802E317C(const char *, ...);
extern void GXInitTexObjWrapMode(void *, int, int);
extern void GXLoadTexObj(void *, int);
extern void DCFlushRange(void *, unsigned int);
extern unsigned int GXGetTexObjTlut(void *);
extern void fn_802D78D4(void *, void *, unsigned int, unsigned int);
extern void GXInvalidateTexAll(void);
extern void fn_802D9230(void *);
void fn_802D92B0(void) {
    fn_802D9230(lbl_8055FE1C);
}
void fn_802D9230(void *arg0) {
    char *obj;
    lbl_8055FE1C = arg0;
    if (*(unsigned int *)((char *)arg0 + 0x70)) fn_802E317C(lbl_8034C5F0, arg0);
    obj = (char *)arg0;
    GXLoadTexObj(obj + 0x24, 2);
    if (((unsigned char *)arg0)[0xCC]) GXLoadTexObj(obj + 0x78, 4);
    lbl_804C5700[11] = ((unsigned char *)arg0)[0xCC];
}

extern void fn_802CFEEC(void);
extern void fn_80128670(void *);
extern unsigned int lbl_8055FD2C;
void fn_802D92B8(void *arg0) {
    char *obj;
    lbl_8055FE20 = arg0;
    if (((unsigned char *)arg0)[0xCC]) fn_802E317C(lbl_8034C620, arg0);
    if (*(unsigned int *)((char *)arg0 + 0x70)) fn_802E317C(lbl_8034C650, arg0);
    obj = (char *)arg0;
    GXInitTexObjWrapMode(obj + 0x24, 0, 0);
    GXLoadTexObj(obj + 0x24, 3);
}

void fn_802D9340(void *arg0) {
    unsigned int value;
    value = *(unsigned int *)((char *)arg0 + 0xD0);
    if (value != 0 && *(unsigned int *)((char *)arg0 + 0xD4) != 0) {
        DCFlushRange((void *)value, *(unsigned int *)((char *)arg0 + 0xD4));
    }
    if (*(unsigned int *)((char *)arg0 + 0x70) != 0 &&
        *(unsigned int *)((char *)arg0 + 0x74) != 0) {
        fn_802D78D4(*(void **)((char *)arg0 + 0x70),
                    *(void **)((char *)arg0 + 0xC4),
                    *(unsigned int *)((char *)arg0 + 0xD8),
                    GXGetTexObjTlut((char *)arg0 + 0x64) & 0xFFFF);
        DCFlushRange(*(void **)((char *)arg0 + 0x70),
                     *(unsigned int *)((char *)arg0 + 0x74));
    }
    if (*(void **)((char *)arg0 + 0xC4) != 0) {
        DCFlushRange(*(void **)((char *)arg0 + 0xC4),
                     *(unsigned int *)((char *)arg0 + 0xC8));
    }
    GXInvalidateTexAll();
}

extern float lbl_80565018;
float fn_802D93E0(void) {
    return lbl_80565018;
}

extern void fn_802D2614(void);
extern int lbl_8055FE24;
void fn_802D93E8(int arg0) {
    fn_802D2614();
    lbl_8055FE24 = arg0;
}

extern int GXGetTexObjMipMap(void *);
extern void *GXGetTexObjFmt(void *);
extern void GXCopyTex(void *, int);
extern void GXSetTexCopySrc(unsigned short, unsigned short, unsigned short, unsigned short);
extern void GXSetTexCopyDst(unsigned short, unsigned short, int, unsigned char);
extern void GXSetZMode(int, int, int);
extern void GXSetColorUpdate(int);
extern void fn_802CFF50(void);
#pragma scheduling invalid_target
void fn_802D9418(void) {
    void *obj;
    unsigned int s, t;
    int zero = 0;
    fn_802D2614();
    obj = (char *)lbl_8055FE24 + 0x24;
    s = GXGetTexObjWrapS(obj) & 0xFFFF;
    t = GXGetTexObjWrapT(obj) & 0xFFFF;
    GXSetTexCopySrc(zero, zero, s, t);
    GXSetTexCopyDst(s, t, GXGetTexObjMipMap(obj), zero);
    GXSetZMode(1, 7, 1);
    GXSetColorUpdate(1);
    GXCopyTex(GXGetTexObjFmt(obj), 1);
    lbl_8055FE24 = zero;
    fn_802CFF50();
}
#pragma scheduling on
extern void *lbl_8055FE28;
extern char lbl_8034C5B8[];
extern void *fn_8012850C(void *, void *);
void* fn_802D94DC(void) {
    return lbl_8055FE18;
}

extern float lbl_80565028;
#pragma push
#pragma processor 750
#pragma paired off
#pragma paired_single off
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma unroll off
void fn_802D94E4(void *arg0, void *arg1, void *arg2, float farg0) {
    struct TexWrap { u8 pad[0x24]; u8 tex; } *t0 = arg0;
    struct TexWrap *t1 = arg1;
    struct TexWrap *t2 = arg2;
    unsigned int *dst;
    unsigned int *src1;
    unsigned int *src2;
    int wrapS;
    int wrapT;
    int count;
    unsigned int blend;
    unsigned int inv;
    int i;
    unsigned int a;
    unsigned int b;
    unsigned int c0;
    unsigned int c1;
    unsigned int c2;
    unsigned int c3;
    wrapS = GXGetTexObjWrapS(&t0->tex);
    wrapT = GXGetTexObjWrapT(&t0->tex);
    count = (wrapS * wrapT * 16) / 32;
    dst = (unsigned int *)((char *)GXGetTexObjFmt(&t0->tex) - 0x40000000);
    src1 = (unsigned int *)((char *)GXGetTexObjFmt(&t1->tex) - 0x40000000);
    src2 = (unsigned int *)((char *)GXGetTexObjFmt(&t2->tex) - 0x40000000);
    blend = (unsigned int)(lbl_80565028 * farg0);
    inv = 256 - blend;
    for (i = 0; i < count; i++) {
        a = *src1;
        src1++;
        b = *src2;
        src2++;
        c0 = (a & 255) * inv + (b & 255) * blend;
        a >>= 8;
        b >>= 8;
        c1 = (a & 255) * inv + (b & 255) * blend;
        a >>= 8;
        b >>= 8;
        c2 = (a & 255) * inv + (b & 255) * blend;
        c3 = (a >> 8) * inv + (b >> 8) * blend;
        *dst = (c0 >> 8) | (c1 & 0xFFFFFF00) | ((c2 << 8) & 0xFFFF0000) | ((c3 << 16) & 0xFF000000);
        dst++;
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D9628(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    int mip;
    int wrap;
    int base;
    int tile;
    unsigned int ysign;
    unsigned int yoff;
    unsigned int xsign;
    unsigned int xoff;
    int pixel;
    void *saved;
    mip = GXGetTexObjMipMap((char *)arg0 + 0x24);
    saved = arg0;
    wrap = GXGetTexObjWrapS((char *)saved + 0x24) & 0xFFFF;
    GXGetTexObjWrapT((char *)saved + 0x24);
    base = (int)GXGetTexObjFmt((char *)saved + 0x24) - 0x40000000;
    if (mip == 0) {
        tile = arg1 / 8 + (arg2 / 8) * (wrap / 8);
        base += tile << 5;
        ysign = (unsigned int)arg2 >> 31;
        yoff = (arg2 << 29) - ysign;
        xsign = (unsigned int)arg1 >> 31;
        xoff = (arg1 << 29) - xsign;
        pixel = (int)((((xoff << 3) | (xoff >> 29)) + xsign + ((((yoff << 3) | (yoff >> 29)) + ysign) * 8)) * 4) / 8;
        {
            unsigned char value = (unsigned char)arg3;
            if (arg1 & 1) {
                unsigned char old = *(unsigned char *)(base + pixel);
                *(unsigned char *)(base + pixel) = (unsigned char)((value & 0xF0) | (old & 0x0F));
            } else {
                unsigned char old = *(unsigned char *)(base + pixel);
                *(unsigned char *)(base + pixel) = (unsigned char)(((value >> 4) & 0x0F) | (old & 0xF0));
            }
        }
    }
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma opt_common_subs off
int fn_802D972C(register void *arg0, register int arg1, register int arg2) {
    int mip;
    int wrap;
    int pixelFormat;
    int base;
    int tile;
    unsigned int ysign;
    unsigned int yoff;
    unsigned int xsign;
    unsigned int xoff;
    int pixel;
    unsigned int value;
    int doubled;
    mip = GXGetTexObjMipMap((char *)arg0 + 0x24);
    wrap = GXGetTexObjWrapS((char *)arg0 + 0x24) & 0xFFFF;
    GXGetTexObjWrapT((char *)arg0 + 0x24);
    pixelFormat = (int)GXGetTexObjFmt((char *)arg0 + 0x24);
    base = pixelFormat - 0x40000000;
    if (mip == 0) {
        tile = arg1 / 8 + (arg2 / 8) * (wrap / 8);
        base += tile << 5;
        ysign = (unsigned int)arg2 >> 31;
        yoff = (arg2 << 29) - ysign;
        xoff = arg1 << 29;
        xsign = (unsigned int)arg1 >> 31;
        xoff -= xsign;
        pixel = (int)((((xoff << 3) | (xoff >> 29)) + xsign +
                      ((((yoff << 3) | (yoff >> 29)) + ysign) * 8)) * 4) / 8;
        if (arg1 & 1)
            value = *(unsigned char *)(base + pixel) & 0xF;
        else
            value = (*(unsigned char *)(base + pixel) >> 4) & 0xF;
        doubled = value | (value * 0x10);
        return (doubled << 24) | ((doubled << 16) | doubled | (doubled << 8));
    }
    if (mip == 6) {
        tile = arg1 / 4 + (arg2 / 4) * (wrap / 4);
        base += tile << 6;
        ysign = (unsigned int)arg2 >> 31;
        yoff = (arg2 << 30) - ysign;
        xoff = arg1 << 30;
        xsign = (unsigned int)arg1 >> 31;
        xoff -= xsign;
        pixel = (int)((((xoff << 2) | (xoff >> 30)) + xsign +
                      ((((yoff << 2) | (yoff >> 30)) + ysign) * 4)) * 0x10) / 8;
        value = *(unsigned short *)(base + pixel);
        return (*(unsigned short *)(base + pixel + 0x20) & ~0xFFFF0000) | (value << 16);
    }
    return 0;
}
#pragma pop
extern void DCFlushRange(void *, unsigned int);
extern unsigned int GXGetTexBufferSize(unsigned short, unsigned short, unsigned int, int, unsigned char);
extern void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, unsigned int);
extern void GXInitTexObjLOD(void *, int, int, float, float, float, int, int, int);
extern float lbl_80565018;
extern float lbl_8056501C;
extern double lbl_80565020;

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802D8C00(void *arg0, void *arg1) {
    void *obj;
    int w;
    int h;
    unsigned char *p;
    obj = fn_802D8A84(arg0, arg1);
    w = *(int *)((char *)arg0 + 0x24);
    h = *(int *)((char *)arg0 + 0x28);
    *(volatile unsigned char *)((char *)obj + 0xCC) = 1;
    GXGetTexBufferSize((unsigned short)w, (unsigned short)h, 0xE, 0, 1);
    p = *(unsigned char **)(*(unsigned char **)((char *)arg0 + 0x2C) + 8);
    DCFlushRange(p, (w * h) / 2);
    {
        int b = *(int *)((char *)arg0 + 0x20) ^ 2;
        int a = b >> 1;
        u32 lod;
        b = b & *(int *)((char *)arg0 + 0x20);
        lod = (u32)(a - b) >> 31;
        GXInitTexObj((char *)obj + 0x78, p, (unsigned short)w, (unsigned short)h, 0, 1, 1, lod);
        if (lod != 0) {
            float conv = (float)(*(int *)((char *)arg0 + 0x20) - 1);
            GXInitTexObjLOD((char *)((u32)obj + 0x78), 5, 1, lbl_80565018, conv, lbl_8056501C, 0, 1, 0);
        }
    }
    fn_802D7780(obj, arg0);
    return obj;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D8D1C(void) {
    int offset;
    int i;

    lbl_8055FE24 = 0;
    lbl_8055FE20 = 0;
    lbl_8055FE1C = 0;
    lbl_8055FE18 = 0;
    lbl_8055FE28 = fn_8012850C((void *)0x1ACE8, &lbl_8034C5B8);

    i = 0;
    offset = 0;
    do {
        memset((char *)lbl_8055FE28 + offset, 0, 0xF4);
        i++;
        offset += 0xF4;
    } while (i < 0x1C2);
}
#pragma pop


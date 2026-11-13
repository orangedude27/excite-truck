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
extern void fn_80231AF0(char *, void *, f32, f32, f32, f32, f32, f32, f32);
typedef struct {
    const char *name;
    f32 scale;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
} Fn80231AF0_Entry;
typedef struct {
    Fn80231AF0_Entry *entries;
    s32 count;
} Fn80231AF0_Table;
typedef struct {
    s32 unk0, unk4, unk8, unkC;
    f32 *glyphs;
} Fn80231AF0_Ctx;
typedef struct {
    s32 idx;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    f32 w2;
    s32 flag;
} Fn80231D84_Rec;
typedef struct {
    Fn80231D84_Rec *recs;
    s32 count;
} Fn80231D84_Table;
extern s32 lbl_8055F050;
extern volatile u8 lbl_8055F074;
extern f32 lbl_80563690;
extern void fn_80233AA4(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4);
extern void fn_80231D84(char *, void *, f32, f32, f32, f32, f32, f32, f32);
extern u8 lbl_8055F064;
extern u8 *lbl_8055F068;
extern s32 lbl_8049846C[];
extern s32 fn_8022EDC4(void);
extern s32 fn_80230B9C(s32);
extern void fn_802C8B98(s32, s32);
extern u8 lbl_80497F14[];
__declspec(section ".sdata") extern char lbl_8055B9B0[];
__declspec(section ".sdata") extern char lbl_8055B9B8[];
__declspec(section ".sdata") extern char lbl_8055B9BC[];
__declspec(section ".sdata") extern char lbl_8055B9C0[];
__declspec(section ".sdata") extern char lbl_8055B9C8[];
__declspec(section ".sdata") extern char lbl_8055B9CC[];
extern void *fn_80131810(const char *);
extern void fn_80131818(void *);
extern void *fn_8023512C(const char *);
extern void *fn_802CAC28(const char *, s32);
extern s32 fn_8002B1D8(const char *, const char *, s32);
extern f32 fn_80235EF0(s32, s32);
extern f32 fn_80235F64(s32, s32);

typedef struct {
    const char *seq;
    f32 scale;
    s32 handle;
    void *resource;
    s32 artIdx;
    u8 flag;
    u8 pad[3];
    f32 field18;
} Fn80232230_Record;

struct Fn80232230_Entry;

struct Fn80232230_EntryVtable {
    void *slot0;
    void *slot1;
    const char *(*getName)(void *);
    s32 (*hasKey)(void *, const char *);
    void *slot4;
    const char *(*getString)(void *, const char *);
    void *slot6;
    s32 (*getInt)(void *, const char *);
    void *slot8;
    void *slot9;
    f32 (*getFloat)(void *, const char *, f32);
    void *slot11;
    u8 (*getByte)(void *, const char *, s32);
};

struct Fn80232230_Entry {
    struct Fn80232230_EntryVtable *vtable;
};

struct Fn80232230_ListVtable {
    void *slot0;
    void *slot1;
    void *slot2;
    struct Fn80232230_Entry *(*getEntry)(void *, s32);
};

struct Fn80232230_List {
    struct Fn80232230_ListVtable *vtable;
};
extern f32 lbl_80563680;
extern f32 lbl_80563684;
extern f32 lbl_80563688;
extern f32 lbl_8056368C;
extern const f64 lbl_80563698;
extern f32 fn_8023400C(s32);
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
static inline s32 fn_80231AF0_escape(char *text, f32 w, f32 *adv) {
    Fn80231AF0_Table *table = (Fn80231AF0_Table *)lbl_80497F14;
    s32 i;
    *adv = w;
    if (*text == '\\') {
        for (i = 0; i < table->count; i++) {
            Fn80231AF0_Entry *e;
            const char *name = table->entries[i].name;
            if (fn_8002B1D8(text + 1, name, strlen(name)) == 0) {
                e = &table->entries[i];
                if (e->unkC != 0) {
                    f32 r = w / fn_80235F64(e->unkC, e->unk10);
                    *adv = e->scale * (r * fn_80235EF0(e->unkC, e->unk10)) + e->scale * (e->unk18 * r);
                } else {
                    *adv = w * e->scale;
                }
                return strlen(table->entries[i].name) + 1;
            }
        }
    }
    return 0;
}
s32 fn_80231504(void) {
    return 0;
}

#pragma push
#pragma scheduling invalid_target
/* Look up a texture block by name in the global block table and return its index, or -1 if not found. */
s32 fn_8023150C(const char *name) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)(lbl_8055F068 + 0x168)) {
        if (stricmp((const char *)(*(void **)(lbl_8055F068 + offset + 4)), name) == 0) {
            return i;
        }
        offset += 0xC;
        i++;
    }
    return -1;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
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
#pragma pop

#pragma push
#pragma scheduling invalid_target
s32 fn_802315FC(s32 arg0) {
    s32 offset = arg0 * 0xC;
    u8 *entry = lbl_8055F068 + offset;

    /* Decrement the entry reference count; replace its slot after releasing an expired entry. */
    if ((*(s32 *)(entry + 8) -= 1) < 1) {
        u8 *base;
        u8 *destination;
        u8 *source;
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
#pragma scheduling invalid_target
s32 fn_802316A4(void *arg0) {
    u8 *entry = lbl_8055F068;
    s32 i = 0;
    s32 count = *(s32 *)(lbl_8055F068 + 0x168);
    while (i < count) {
        if (*(void **)entry == arg0) return fn_802315FC(i);
        entry += 0xC;
        i++;
    }
    ((void (*)(const char *, ...))fn_802E30C8)(lbl_8034044C, arg0);
    return 0;
}
#pragma scheduling on
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
extern char lbl_8055B9A0;
#pragma push
#pragma scheduling invalid_target
s32 fn_80231730(s32 arg0) {
    char buffer[0x18];
    sprintf(buffer, &lbl_8055B9A0, arg0);
    if (fn_8012C33C(buffer) != 0) return fn_80232578(buffer);
    return 0;
}
#pragma pop

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

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80231AF0(char *text, void *ctx, f32 x, f32 y, f32 z, f32 w, f32 sx, f32 sy, f32 sp) {
    register char *curText;
    f32 spC;
    f32 sp8;
    f32 half;
    curText = text;
    strlen(curText);
    half = lbl_80563690;
    while (*curText != 0) {
        int ch = *(u8 *)curText;
        f64 adv = w;
        s32 skip;
        u16 code;
        char *next;
        u8 c;
        s32 off;

        if (ch == '\\') {
            s32 eo;
            s32 i;
            i = 0;
            eo = 0;
            while (i < ((Fn80231AF0_Table *)lbl_80497F14)->count) {
                Fn80231AF0_Entry *e;
                const char *name = *(const char **)((u8 *)((Fn80231AF0_Table *)lbl_80497F14)->entries + eo);
                if (fn_8002B1D8(curText + 1, name, strlen(name)) == 0) {
                    e = (Fn80231AF0_Entry *)((u8 *)((Fn80231AF0_Table *)lbl_80497F14)->entries + eo);
                    if (e->unkC != 0) {
                        f32 r = w / fn_80235F64(e->unkC, e->unk10);
                        f32 t = r * fn_80235EF0(e->unkC, e->unk10);
                        adv = e->scale * t + e->scale * (e->unk18 * r);
                    } else {
                        adv = w * e->scale;
                    }
                    skip = strlen(((Fn80231AF0_Table *)lbl_80497F14)->entries[i].name) + 1;
                    goto have;
                }
                eo += 0x1C;
                i++;
            }
        }
        skip = 0;
have:
        if (skip > 0) {
            curText += skip;
            x += (f32)adv;
            continue;
        }
        c = *(u8 *)curText;
        if ((c & 0xF0) == 0xE0) {
            next = curText + 3;
            code = ((c & 0xF) << 12) | ((((u8 *)curText)[1] & 0x3F) << 6) | (((u8 *)curText)[2] & 0x3F);
        } else if ((c & 0xE0) == 0xC0) {
            next = curText + 2;
            code = ((u8 *)curText)[1] & ~0xC0;
            code |= (c & 0x1F) << 6;
        } else {
            code = c & 0x7F;
            next = curText + 1;
        }
        off = (unsigned short)code * sizeof(Fn80231AF0_Entry);
        curText += next - curText;
        x += sy * (sx * *(f32 *)((u8 *)((Fn80231AF0_Ctx *)ctx)->glyphs + off));
        if (lbl_8055F074) {
            ((void (*)(f32 *, f32 *, f32, f32))lbl_8055F070)(&spC, &sp8, x - half, half + y);
            spC += half;
            sp8 -= half;
        } else {
            ((void (*)(f32 *, f32 *, f32, f32))lbl_8055F070)(&spC, &sp8, x, y);
        }
        fn_80233AA4(ctx, code, spC, sp8 + w, spC + sx * *(f32 *)((u8 *)((Fn80231AF0_Ctx *)ctx)->glyphs + off + 4), sp8, z);
        x += sx * *(f32 *)((u8 *)((Fn80231AF0_Ctx *)ctx)->glyphs + off + 4);
        x += sp + sy * (sx * *(f32 *)((u8 *)((Fn80231AF0_Ctx *)ctx)->glyphs + off + 8));
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80231D84(char *text, void *ctx, f32 x, f32 y, f32 z, f32 w, f32 sx, f32 sy, f32 sp) {
    f32 sp8;
    register f32 half;
    f32 *out = &sp8;
    strlen(text);
    half = lbl_80563688;
    while (*text != 0) {
        register s32 skip;
        s32 flag;
        u8 c;
        u16 code;
        char *next;
        int off;
        u8 *g;

        sp8 = w;
        flag = lbl_8055F050;
        if (*text == '\\') {
            s32 eo;
            s32 i;
            eo = 0;
            i = 0;
            while (i < ((Fn80231AF0_Table *)lbl_80497F14)->count) {
                Fn80231AF0_Entry *e = (Fn80231AF0_Entry *)((u8 *)((Fn80231AF0_Table *)lbl_80497F14)->entries + eo);
                if (fn_8002B1D8(text + 1, e->name, strlen(*(const char **)((u8 *)((Fn80231AF0_Table *)lbl_80497F14)->entries + eo))) == 0) {
                    Fn80231D84_Table *t = (Fn80231D84_Table *)lbl_8049846C;
                    Fn80231D84_Rec *r;
                    f32 extra = lbl_8056368C;
                    r = &t->recs[t->count++];
                    r->idx = i;
                    if (e->unkC != 0) {
                        f32 q = w / fn_80235F64(e->unkC, e->unk10);
                        r->w = w * e->scale;
                        r->w2 = q * e->scale * fn_80235EF0(e->unkC, e->unk10);
                        extra = e->scale * (e->unk18 * q);
                    } else {
                        r->w2 = w * e->scale;
                        r->w = w * e->scale;
                    }
                    r->x = x;
                    r->y = y + w + half * (r->w - w);
                    r->z = z;
                    r->flag = flag;
                    if (out) {
                        *out = r->w2 + extra;
                    }
                    skip = strlen(e->name) + 1;
                    goto have;
                }
                eo += 0x1C;
                ++i;
            }
        }
        skip = 0;
have:
        if (0 < skip) {
            text += skip;
            x += sp8;
            continue;
        }
        c = *(u8 *)text;
        if ((c & 0xF0) == 0xE0) {
            next = text + 3;
            code = ((c & 0xF) << 12) | ((((u8 *)text)[1] & 0x3F) << 6) | (((u8 *)text)[2] & 0x3F);
        } else if ((c & 0xE0) == 0xC0) {
            next = text + 2;
            code = ((c & 0x1F) << 6) | (((u8 *)text)[1] & ~0xC0);
        } else {
            code = c & 0x7F;
            next = text + 1;
        }
        off = code * 0x1C;
        text += next - text;
        g = (u8 *)((Fn80231AF0_Ctx *)ctx)->glyphs;
        x += sy * (sx * *(f32 *)(g + off));
        fn_80233AA4(ctx, code, x, y + w, x + sx * *(f32 *)(g + off + 4), y, z);
        g = (u8 *)((Fn80231AF0_Ctx *)ctx)->glyphs + off;
        x += sx * *(f32 *)(g + 4);
        x += sp + sy * (sx * *(f32 *)(g + 8));
    }
}
#pragma pop

#pragma pop
void fn_80232024(u8 **arg0) {
    u8 *p = *arg0;
    if (*p == 1) *arg0 = p + 1;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
extern volatile u8 lbl_8055F074;
extern void fn_80233BF0(u8 *, u8 *, f32 *, f32 *, s32, f32, f32);
extern void fn_80233DD8(s32 *, s32);
extern void fn_80233E34(s32 *, s32, s32);
extern void fn_80233EBC(void);
extern void fn_80233EC0(void *, s32, f32, f32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80232040(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                 f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    s32 sp14;
    f32 sp10;
    f32 spC;
    s32 sp8;
    f32 temp_f31;
    f32 rate;
    s32 var_r31;
    s32 temp_r30;
    u8 *var_r29;
    s32 var_r5;
    f32 tmpRate;
    sp8 = (s32)arg0;
    spC = farg0;
    sp10 = farg1;
    sp14 = arg2;
    lbl_8055F074 = (arg2 == (s32)0xFF000000);
    ((void (*)(u8 **, u8 **))fn_80232024)((u8 **)&sp8, (u8 **)&sp14);
    var_r31 = 1;
    if (*(u32 *)((u8 *)arg1 + 8) != 0)
        var_r31 = 2;
    rate = *(f32 *)((u8 *)fn_8022EDC4() + 0x38);
    tmpRate = (f32)((u8 *)arg1)[4] * farg2;
    temp_f31 = tmpRate * rate;
    fn_80233BF0((u8 *)sp8, (u8 *)arg1, &spC, &sp10, arg3, farg2, farg4);
    while (var_r31 > 0) {
        var_r5 = sp14;
        temp_r30 = (var_r31 == 2);
        var_r29 = (u8 *)arg1;
        if (temp_r30 != 0) {
            var_r29 = *(u8 **)((u8 *)arg1 + 8);
            var_r5 = fn_80231718(var_r5);
        }
        if (arg4 != 0) {
            ((void (*)(s32 *, s32))fn_80233E34)((s32 *)var_r29, arg4);
        } else {
            fn_80233DD8((s32 *)var_r29, var_r5);
        }
        rate = *(f32 *)((u8 *)fn_8022EDC4() + 0x38);
        {
            f32 rateProduct = farg2 * rate;
            ((void (*)(u8 *, u8 *, f32, f32, f32, f32, f32, f32, f32))lbl_8055B9A8)(
                (u8 *)sp8, var_r29, spC, sp10, farg3, temp_f31, rateProduct, farg4, farg5);
        }
        fn_80233EBC();
        if (temp_r30 != 0)
            fn_80231ADC();
        else
            fn_80231780((void *)arg4);
        var_r31 -= 1;
    }
}
#pragma dont_inline off
#pragma pop

void fn_802321D8(void) {
    if (lbl_8055F068 != 0) ((void (*)(const char *, ...))fn_802E317C)(lbl_80340488);
    lbl_8055F068 = fn_801284F8(0x16C, lbl_803404C0);
    memset(lbl_8055F068, 0, 0x16C);
}

#pragma push
#pragma scheduling invalid_target
void fn_80232230(void) {
    int i;
    char *stringBase;
    struct Fn80232230_Entry *entry;
    struct Fn80232230_List *list;
    Fn80232230_Record *record;
    s32 count;
    f32 temp_f31;

    *(s32 *)(lbl_80497F14 + 4) = 0;
    stringBase = lbl_80340440;
    list = (struct Fn80232230_List *)fn_80131810(stringBase + 0x94);
    if (list != NULL) {
        temp_f31 = lbl_8056368C;
        for (i = 0; (entry = list->vtable->getEntry(list, i)) != NULL; i++) {
            if (stricmp(entry->vtable->getName(entry), lbl_8055B9B0) == 0) {
                count = *(s32 *)(lbl_80497F14 + 4);
                record = (Fn80232230_Record *)(*(u8 **)lbl_80497F14) + count;
                *(s32 *)(lbl_80497F14 + 4) = count + 1;
                record->seq = entry->vtable->getString(entry, lbl_8055B9B8);
                if (entry->vtable->hasKey(entry, lbl_8055B9BC) != 0 &&
                    entry->vtable->hasKey(entry, lbl_8055B9C0) != 0) {
                    record->resource = fn_8023512C(entry->vtable->getString(entry, lbl_8055B9BC));
                    record->artIdx = entry->vtable->getInt(entry, lbl_8055B9C0);
                    record->field18 = entry->vtable->getFloat(entry, stringBase + 0xA0, lbl_8056368C);
                    record->handle = -1;
                } else {
                    record->resource = 0;
                    record->artIdx = 0;
                    record->field18 = temp_f31;
                    record->handle = (s32)fn_802CAC28(entry->vtable->getString(entry, lbl_8055B9C8), 0);
                }
                record->scale = entry->vtable->getFloat(entry, lbl_8055B9CC, lbl_80563684);
                record->flag = entry->vtable->getByte(entry, stringBase + 0xB0, 0);
            }
        }
        fn_80131818(list);
    }
}
#pragma pop
extern void fn_80235380(void);
#pragma push
#pragma scheduling invalid_target
void fn_8023243C(void) {
    s32 offset = 0;
    s32 i = 0;

    /* Release all active lbl_80497F14 records and clear the count. Each
     * 0x1C-byte record stores a handle at +8 and a resource at +0xC. */
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

/* Readable aliases; the game's own symbols keep their placeholder names. */
#define gTexBlockTable lbl_8055F068 /* the cache of loaded font blocks, see GTexCache below */
#define gTexMessages lbl_80340440   /* gText's block of message strings */
#define gTexExtension lbl_8055B9D4  /* ".tex" */
#define GETX_FOURCC 0x47544558      /* 'GETX': the fourcc of a font texture block */

/* Messages inside the string block at lbl_80340440. */
enum {
    GTEX_MSG_BAD_VERSION = 0xE4,    /* gText: Font "%s" has bad version %d */
    GTEX_MSG_NULL_FONT = 0x108,     /* gText: Null font %s! */
    GTEX_MSG_NO_BLOCK = 0x144,      /* gText: Failed to extract texture with font- returning NULL font. */
    GTEX_MSG_NAME_TOO_LONG = 0x15C, /* gText: Texture name %s is longer than %d, it's %d */
    GTEX_MSG_NO_RESOURCE = 0x190    /* the texture could not be registered */
};

/* Its own symbol inside that string block. */
#define gTexMsgFontGone lbl_803404FC /* gText: font %s gone but not forgotten */

/* A loaded 'GETX' font block, as handed back by the archive manager.
 * records and texture are stored in the file as offsets from the block and are
 * turned into pointers the first time the block is loaded (see swap below). */
typedef struct GTexBlock {
    /* 0x00 */ s32 resourceIndex;          /* texture index in the gTex resource table */
    /* 0x04 */ s32 unk04;
    /* 0x08 */ struct GTexBlock *outline;  /* the "_ol_<name>" variant, 0 when there is none */
    /* 0x0C */ u16 recordCount;            /* 0x1C-byte records at records[] */
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ s32 records;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 texture;                /* the pixels registered as the resource */
} GTexBlock;

/* One slot of the font block cache: the loaded block, the name it is filed
 * under (a 0x40-byte copy of the file name) and how many hold it -
 * fn_8023158C adds to the count and fn_802315FC takes back, releasing the
 * block once the count is gone. */
typedef struct GTexCacheEntry {
    /* 0x00 */ GTexBlock *block;
    /* 0x04 */ char *name;
    /* 0x08 */ s32 useCount;
} GTexCacheEntry;

/* The cache is one 0x16C-byte allocation (fn_802321D8): its slots, then the
 * number of them in use where the next slot would start. */
#define GTEX_CACHE_MAX 30
typedef struct GTexCache {
    /* 0x000 */ GTexCacheEntry entries[GTEX_CACHE_MAX];
    /* 0x168 */ s32 count;
} GTexCache;

extern char lbl_803404FC[];
extern void fn_802CB228(s32 resourceIndex);
extern void fn_80128668();
void fn_802324D8(void) {
    s32 offset = 0;
    s32 i = 0;

    /* gText shutdown: every font block still in the cache at this point was
     * never let go by the code that loaded it, so each is reported by name
     * before its texture resource, the block and its name copy are freed. */
    while (i < ((GTexCache *)gTexBlockTable)->count) {
        u8 *entry = gTexBlockTable + offset;
        ((void (*)(const char *, ...))fn_802E30C8)(gTexMsgFontGone, ((GTexCacheEntry *)entry)->name);
        fn_802CB228(((GTexCacheEntry *)entry)->block->resourceIndex);
        fn_8012C4D8(((GTexCacheEntry *)entry)->block);
        fn_80128670(((GTexCacheEntry *)entry)->name);
        offset += 0xC;
        i++;
    }
    fn_80128668(gTexBlockTable); /* the cache table itself, still in r3 */
    gTexBlockTable = 0;
}

#pragma pop
extern void *fn_8012C370(const char *, s32, u32 *, s32 *, u8 *, u8 *);
extern void fn_80028E00(char *, const char *);
extern s32 fn_802CAC34(char *, s32);
extern u32 lbl_8055B9D4;

#pragma push
#pragma small_data on
s32 fn_80232578(const char *name) {
    /* gText: load a font texture by archive file name (e.g. "bigtext.gtx").
     * Returns the loaded 'GETX' block, or 0.  A name already in the cache table
     * only has its use count bumped and its "_ol_<name>" variant refreshed; a
     * new block is byte-swapped when the archive read it in the other byte
     * order, registered as a "<name>.tex" texture resource and appended to the
     * cache table. */
    register char *stringBase = gTexMessages;
    s32 index;
    s32 offset;
    u8 *data;         /* the cache slot while it is looked up, the block afterwards */
    u8 *record;
    u8 *recordWords;
    s32 swapWide;
    u8 swapByte2;
    s32 dataSize;     /* block size from the archive manager, unused here */
    u32 version;      /* block format version, expected to be 8 */
    u8 firstLoad;     /* the archive manager allocated the block just now */
    u8 swap;          /* the block's bytes are in the other order */
    void *rawBlock;
    struct { char name[0xC]; s32 pad; } nameBuffer;
    s32 i;
    u8 swapByte;
    u32 value;        /* the slot's use count, then the "_ol_" block it points at */

    index = fn_8023150C(name);
    if (index >= 0) {
        /* Already loaded: bump the slot's use count and refresh its outline variant. */
        offset = index * 0xC;
        data = gTexBlockTable + offset;
        value = *(u32 *)(data + 8);
        *(u32 *)(data + 8) = value + 1;
        value = (u32)fn_80231730((s32)name);
        *(u32 *)((u8 *)*(u32 *)data + 8) = value;
        return *(s32 *)data;
    }

    firstLoad = 0;
    swap = 0;
    dataSize = 0;
    rawBlock = fn_8012C370(name, GETX_FOURCC, &version, &dataSize, &firstLoad, &swap);
    data = (u8 *)rawBlock;
    if (rawBlock != 0) {
        if (version != 8) {
            ((void (*)(const char *, ...))fn_802E317C)(stringBase + GTEX_MSG_BAD_VERSION, name, version);
        }
        if (firstLoad == 0) {
            ((void (*)(const char *, ...))fn_802E317C)(stringBase + GTEX_MSG_NULL_FONT, name);
        }
    } else {
        ((void (*)(const char *, ...))fn_802E30C8)(stringBase + GTEX_MSG_NO_BLOCK, name);
        return 0;
    }

    if (swap != 0) {
        /* Flip the header's 32-bit fields... */
        swapByte = data[0xC]; data[0xC] = data[0xD]; data[0xD] = swapByte;
        swapByte = data[0x14]; data[0x14] = data[0x17]; data[0x17] = swapByte;
        swapByte = data[0x15]; data[0x15] = data[0x16]; data[0x16] = swapByte;
        swapByte = data[0x10]; data[0x10] = data[0x13]; data[0x13] = swapByte;
        swapByte = data[0x11]; data[0x11] = data[0x12]; data[0x12] = swapByte;
        swapByte = data[0x18]; data[0x18] = data[0x1B]; data[0x1B] = swapByte;
        swapByte = data[0x19]; data[0x19] = data[0x1A]; data[0x1A] = swapByte;
        /* ...then turn the two sub-block offsets into pointers. */
        ((GTexBlock *)data)->records += (u32)data;
        ((GTexBlock *)data)->texture += (u32)data;

        /* Every record is 0x1C bytes of seven 32-bit words; the last three words
         * are re-read from the record's start, so they swap in their own step. */
        i = 0;
        offset = 0;
        for (; i < ((GTexBlock *)data)->recordCount; i++, offset += 0x1C) {
            record = (u8 *)((GTexBlock *)data)->records + offset;
            swapByte = record[0xC]; record[0xC] = record[0xF]; record[0xF] = swapByte;
            swapByte = record[0xD]; record[0xD] = record[0xE]; record[0xE] = swapByte;
            swapByte = record[0x10]; record[0x10] = record[0x13]; record[0x13] = swapByte;
            swapByte = record[0x11]; record[0x11] = record[0x12]; record[0x12] = swapByte;
            swapByte = record[0x14]; record[0x14] = record[0x17]; record[0x17] = swapByte;
            swapByte = record[0x15]; record[0x15] = record[0x16]; record[0x16] = swapByte;
            swapByte = record[0x18]; record[0x18] = record[0x1B]; record[0x1B] = swapByte;
            swapByte = record[0x19]; record[0x19] = record[0x1A]; record[0x1A] = swapByte;

            recordWords = (u8 *)((GTexBlock *)data)->records + offset;
            swapWide = recordWords[0]; recordWords[0] = recordWords[3]; recordWords[3] = (u8)swapWide;
            swapByte2 = recordWords[1]; recordWords[1] = recordWords[2]; recordWords[2] = swapByte2;

            recordWords = (u8 *)((GTexBlock *)data)->records + offset;
            swapByte2 = recordWords[8]; recordWords[8] = recordWords[0xB]; recordWords[0xB] = swapByte2;
            swapByte2 = recordWords[9]; recordWords[9] = recordWords[0xA]; recordWords[0xA] = swapByte2;

            recordWords = (u8 *)((GTexBlock *)data)->records + offset;
            swapByte2 = recordWords[4]; recordWords[4] = recordWords[7]; recordWords[7] = swapByte2;
            swapByte2 = recordWords[5]; recordWords[5] = recordWords[6]; recordWords[6] = swapByte2;
        }
    }

    /* The texture resource is named after the first 11 characters of the file name. */
    strncpy(nameBuffer.name, name, 0xB);
    nameBuffer.name[0xB] = 0;
    fn_80028E00(nameBuffer.name, (const char *)&gTexExtension);
    if (strlen(nameBuffer.name) > 0x10) {
        ((void (*)(const char *, ...))fn_802E317C)(stringBase + GTEX_MSG_NAME_TOO_LONG, nameBuffer.name, 0x10, strlen(nameBuffer.name));
    }
    index = fn_802CAC34(nameBuffer.name, ((GTexBlock *)data)->texture);
    if (index == -1) {
        ((void (*)(const char *, ...))fn_802E30C8)(stringBase + GTEX_MSG_NO_RESOURCE);
        return 0;
    }
    ((GTexBlock *)data)->resourceIndex = index;
    ((GTexBlock *)data)->outline = (GTexBlock *)fn_80231730((s32)name);
    fn_8023158C(data, name);
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

#pragma push
#pragma scheduling invalid_target
f32 fn_8023293C(s32 font, char *text, f32 extra) {
    register f32 height;
    register f32 width;
    f64 escapeWidth;
    f32 escapeScale;
    register s32 index;
    register u8 *recordCount;
    s32 tokenOffset;
    s32 tokenIndex;
    u8 *character;
    const char *token;
    register u8 *next;
    register u8 *entry;
    register u8 *glyphs;
    register u8 *glyph;
    s32 consumed;
    register u16 codepoint;
    u8 first;

    if (text == NULL) {
        return lbl_8056368C;
    }

    width = lbl_8056368C;
    index = 0;
    height = width;
    strlen(text);
    recordCount = (u8 *)(&((s32 *)lbl_80497F14)[1]);
    goto char_test;

char_body:
    escapeWidth = (f32)*(u8 *)(font + 4);
    escapeScale = (f32)*(u8 *)(font + 4);

    if ((s8)text[index] == '\\') {
        character = (u8 *)text + index + 1;
        for (tokenOffset = 0, tokenIndex = 0; tokenIndex < *(s32 *)recordCount; tokenOffset += 0x1C, tokenIndex++) {
            token = *(const char **)(*(u8 **)lbl_80497F14 + tokenOffset);
            if (fn_8002B1D8((const char *)character, token, strlen(token)) == 0) {
                tokenOffset = tokenIndex * 0x1C;
                entry = *(u8 **)lbl_80497F14 + tokenOffset;
                if (*(s32 *)(entry + 0xC) != 0) {
                    escapeScale /= fn_80235F64(*(s32 *)(entry + 0xC), *(s32 *)(entry + 0x10));
                    escapeWidth = *(f32 *)(entry + 4) * (escapeScale * fn_80235EF0(*(s32 *)(entry + 0xC), *(s32 *)(entry + 0x10)))
                                + *(f32 *)(entry + 4) * (*(f32 *)(entry + 0x18) * escapeScale);
                } else {
                    escapeWidth = escapeScale * *(f32 *)(entry + 4);
                }
                consumed = strlen(*(const char **)(*(u8 **)lbl_80497F14 + tokenIndex * 0x1C)) + 1;
                goto match;
            }
        }
        consumed = 0;
match: ;
    } else {
        consumed = 0;
    }

    if (consumed != 0) {
        index += consumed;
        width += (f32)escapeWidth;
        goto char_test;
    }

    first = text[index];
    character = (u8 *)text + index;
    if ((first & 0xF0) == 0xE0) {
        codepoint = ((first & 0x0F) << 12) | ((character[1] & 0x3F) << 6) | (character[2] & 0x3F);
        next = character + 3;
    } else if ((first & 0xE0) == 0xC0) {
        codepoint = ((first & 0x1F) << 6) | __rlwinm(character[1], 0, 26, 23);
        next = character + 2;
    } else {
        codepoint = first & 0x7F;
        next = character + 1;
    }

    glyphs = *(u8 **)(font + 0x10);
    glyph = glyphs + (u16)codepoint * 0x1C;
    index += next - character;
    width += *(f32 *)(glyph + 4);
    height += *(f32 *)glyph + *(f32 *)(glyph + 8);

char_test:
    if ((s8)text[index] != 0) goto char_body;

    height *= extra;
    return (width + height) * *(f32 *)((u8 *)fn_8022EDC4() + 0x38);
}
#pragma pop
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
void fn_80232BA4(char *text, s32 font, s32 color, s32 x, f32 y, f32 scaleX, f32 scaleY, f32 spacing, f32 alpha) {
    s32 adjustedColor = color;

    /* Let the debug hook adjust the color, then render with default extra spacing when text is non-empty. */
    fn_80231714(&adjustedColor);
    if ((s8)*text != 0) {
        fn_80232040((u8 *)text, font, adjustedColor, x, 0, y, scaleX, scaleY, spacing, alpha, lbl_8056368C);
    }
}

#pragma push
#pragma processor 750
#pragma dont_inline on
/* Measures string width/spacing and draws it (via fn_80232040) when non-empty, after adjusting arg2 via fn_80231714. */
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
extern void fn_80233AA4(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4);
extern void fn_80233BF0(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3, s32 arg4, f32 farg0, f32 farg1);
extern void fn_80233E80(s32 *arg0, s32 arg1);
extern void fn_80233EBC(void);
extern void fn_802C8D74(void);
#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_80232D3C(u8 *text, s32 font, s32 color, s32 x, s32 flags, f32 y, f32 scaleX, f32 scaleY, f32 spacing, f32 alpha) {
    /* Adjust color via debug hook, then draw text with default extra spacing when non-empty. */
    s32 adjustedColor = color;

    fn_80231714(&adjustedColor);
    if ((s8)*text != 0) {
        fn_80232040(text, font, adjustedColor, x, flags, y, scaleX, scaleY, spacing, alpha, lbl_8056368C);
    }
}
void fn_80232DF4(u8 *text, s32 font, s32 color, s32 flags, f32 x, f32 y, f32 scale, f32 spacing, f32 extra) {
    s32 sp10;
    f32 spC;
    f32 sp8;
    sp8 = x;
    spC = y;
    sp10 = color;

    fn_80231714(&sp10);
    if ((s8)*text != 0) {
        f32 rate = *(f32 *)((u8 *)fn_8022EDC4() + 0x34);
        f32 f0 = (f32)*(u8 *)(font + 4) * scale;
        f32 fontHeight = f0 * rate;
        fn_80233BF0(text, (u8 *)font, &sp8, &spC, flags, scale, extra);
        {
            f32 startX = sp8;
            s32 passes;

            strlen((const char *)text);
            passes = (*(void **)(font + 8) != NULL) + 1;
            while (passes > 0) {
                s32 curColor = sp10;
                s32 curFont = font;
                s32 textOffset = 0;

                sp8 = startX;
                if (passes == 2) {
                    curFont = *(s32 *)(font + 8);
                    curColor = fn_80231718(curColor);
                }
                fn_80233E80((s32 *)curFont, curColor);
                while ((s8)text[textOffset] != 0) {
                    u8 first = text[textOffset];
                    u8 *start = text + textOffset;
                    u8 *end;
                    u32 code;
                    s32 offset;

                    if ((first & 0xF0) == 0xE0) {
                        code = ((first & 0x0F) << 12) | ((start[1] & 0x3F) << 6) | (start[2] & 0x3F);
                        end = start + 3;
                    } else if ((first & 0xE0) == 0xC0) {
                        code = ((first & 0x1F) << 6) | __rlwinm(start[1], 0, 26, 23);
                        end = start + 2;
                    } else {
                        code = first & 0x7F;
                        end = start + 1;
                    }
                    code = (u16)code;
                    offset = code * 0x1C;
                    sp8 += scale * *(f32 *)(*(u8 **)(curFont + 0x10) + offset) * extra;
                    fn_80233AA4((void *)curFont, code, sp8, spC - fontHeight, sp8 + scale * *(f32 *)(*(u8 **)(curFont + 0x10) + offset + 4), spC, spacing);
                    textOffset += end - start;
                    sp8 += scale * *(f32 *)(*(u8 **)(curFont + 0x10) + offset + 4);
                    sp8 += extra * (scale * *(f32 *)(*(u8 **)(curFont + 0x10) + offset + 8));
                }
                fn_80233EBC();
                passes--;
            }
        }
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

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80233354(u8 *text, u8 *ctx, s32 arg2, s32 flags, f32 x, f32 y, f32 sx, f32 z) {
    s32 sp8;
    f32 y0;
    f32 charW;
    s32 pass;
    s32 pos;
    u8 *base;

    sp8 = arg2;
    fn_80231714(&sp8);
    y0 = y;
    strlen((char *)text);
    if ((s8)*text != 0) {
        u8 c0 = *text;
        charW = (f32)ctx[4] * sx;
        if ((c0 & 0xF0) == 0xE0) {
        } else if ((c0 & 0xE0) == 0xC0) {
        }
        if (flags & 1) {
        } else if (flags & 2) {
            fn_8023293C((s32)ctx, (char *)text, lbl_80563684);
        } else if (flags & 4) {
            fn_8023293C((s32)ctx, (char *)text, lbl_80563684);
        }
        if (flags & 8) {
            x += (f32)ctx[4] * sx;
        } else if (flags & 0x20) {
            x += (f32)ctx[6] * sx;
        } else if (flags & 0x10) {
            x += (f32)ctx[4] * sx * lbl_80563688;
        }
        pass = (*(u32 *)(ctx + 8) != 0) + 1;
        while (pass > 0) {
            s32 arg;
            y = y0;
            arg = sp8;
            base = ctx;
            pos = 0;
            if (pass == 2) {
                base = *(u8 **)(ctx + 8);
                arg = fn_80231718(arg);
            }
            fn_80233DD8((s32 *)base, arg);
            while ((s8)text[pos] != 0) {
                u8 *p = text + pos;
                u8 ch = text[pos];
                u8 *next;
                u16 code;
                s32 off;
                u8 *g;
                if ((ch & 0xF0) == 0xE0) {
                    next = p + 3;
                    code = ((ch & 0xF) << 12) | ((p[1] & 0x3F) << 6) | (p[2] & 0x3F);
                } else if ((ch & 0xE0) == 0xC0) {
                    next = p + 2;
                    code = ((ch & 0x1F) << 6) | (p[1] & 0x3F);
                } else {
                    code = ch & 0x7F;
                    next = p + 1;
                }
                g = *(u8 **)(base + 0x10);
                off = code * 0x1C;
                y = y - sx * *(f32 *)(g + off);
                fn_80233EC0(base, code, x, y, z, x + charW, y - sx * *(f32 *)(g + off + 4), z);
                pos += next - p;
                g = *(u8 **)(base + 0x10) + off;
                y -= sx * (*(f32 *)(g + 4) + *(f32 *)(g + 8));
            }
            fn_80233EBC();
            pass--;
        }
    }
}
#pragma pop

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
/* Draw text at (x, y) with default vertical scale, alpha, and no extra offset when the string is non-empty. */
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
    /* Format a string with printf-style arguments, then draw it via fn_80233600. */
    #pragma scheduling invalid_target
    char buffer[0x78];
    va_list args;

    va_start(args, farg2);
    vsprintf(buffer, fmt, args);
    fn_80233600((u8 *)buffer, arg0, arg1, arg2, farg0, farg1, farg2);
}

void fn_802337A0(f32 a, s32 b, f32 c, s32 d, f32 e, f32 f, s32 g, f32 h, const char *fmt, ...) {
    /* Formats a string with vsprintf and draws it via fn_80232BA4 with the given font, color, flags, position, scale, spacing, and extra scale. */
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
void fn_8023389C(s32 x, s32 y, s32 color, s32 param, const char *fmt, f32 scaleX, f32 scaleY, f32 unkF2, f32 unkF3, f32 alpha, ...) {
    /* Format a debug text string and draw it if non-empty. */
    char text[0x80];
    va_list args;

    va_start(args, alpha);
    vsprintf(text, fmt, args);
    fn_80232D3C((u8 *)text, x, y, color, param, scaleX, scaleY, unkF3, unkF2, alpha);
}
#pragma pop

extern void fn_80232DF4(u8 *, s32, s32, s32, f32, f32, f32, f32, f32);
#pragma push
#pragma use_lmw_stmw off
// Matched with the shared variadic wrapper signature and 0x80-byte formatting buffer.
void fn_802339A8(f32 x, s32 font, f32 y, s32 color, f32 spacing, f32 scale, s32 flags, f32 extra, const char *fmt, ...) {
    /* Formats a string with vsprintf and draws it via fn_80232DF4 with the given font, color, flags, position, scale, spacing, and extra scale. */
    #pragma scheduling invalid_target
    char buffer[0x80];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    fn_80232DF4((u8 *)buffer, font, color, flags, x, y, scale, spacing, extra);
}

extern void fn_80231380(void *, s32, f32, f32, f32, f32, f32);
extern void fn_802C8DB8(void *, s32, u16 *, s32, s32, s32, s32, s32);
extern u16 lbl_802F9FF0[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80233AA4(void *arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    register void *object = arg0;
    register s32 offset;
    register s32 font;
    u8 out3[0x18], out2[0x18], out1[0x18], out0[0x18];
    u16 values[6];
    u8 *entry;
    u16 t0, t1, t2, t3, t4, t5;
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
        t0 = lbl_802F9FF0[0];
        t1 = lbl_802F9FF0[1];
        t2 = lbl_802F9FF0[2];
        t3 = lbl_802F9FF0[3];
        t4 = lbl_802F9FF0[4];
        t5 = lbl_802F9FF0[5];
        values[0] = t0;
        values[1] = t1;
        values[2] = t2;
        values[3] = t3;
        values[4] = t4;
        values[5] = t5;
        fn_802C8DB8(out0, 4, values, 6, t4, t3, t2, t1);
    }
}
#pragma pop

extern f32 lbl_80563688;
#pragma scheduling invalid_target
void fn_80233BF0(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3, s32 arg4, f32 farg0, f32 farg1) {
    u32 code;
    f32 value;
    if (arg4 & 1) {
        u8 first = arg0[0];
        if ((first & 0xF0) == 0xE0) {
            code = ((first & 0x0F) << 12) | ((arg0[1] & 0x3F) << 6) | (arg0[2] & 0x3F);
        } else if ((first & 0xE0) == 0xC0) {
            code = ((first & 0x1F) << 6) | (arg0[1] & ~0xC0);
        } else {
            code = first & 0x7F;
        }
        *arg2 -= *(f32 *)(*(u8 **)(arg1 + 0x10) + (code & 0xFFFF) * 0x1C);
    } else if (arg4 & 2) {
        *arg2 -= farg0 * fn_8023293C((s32)arg1, (char *)arg0, farg1);
    } else if (arg4 & 4) {
        *arg2 -= (farg0 * fn_8023293C((s32)arg1, (char *)arg0, farg1)) * lbl_80563688;
    }
    value = *(f32 *)((u8 *)fn_8022EDC4() + 0x38);
    if (arg4 & 8) {
        *arg3 -= value * ((f32)arg1[4] * farg0);
    } else if (arg4 & 0x20) {
        *arg3 -= value * ((f32)arg1[6] * farg0);
    } else if (arg4 & 0x10) {
        *arg3 -= (value * ((f32)arg1[4] * farg0)) * lbl_80563688;
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
        values[0] = lbl_802F9FFC.idx[0];
        values[1] = lbl_802F9FFC.idx[1];
        values[2] = lbl_802F9FFC.idx[2];
        values[3] = lbl_802F9FFC.idx[3];
        values[4] = lbl_802F9FFC.idx[4];
        values[5] = lbl_802F9FFC.idx[5];
        fn_802C8DB8(out0, 4, values, 6,
                    lbl_802F9FFC.idx[4], lbl_802F9FFC.idx[3], lbl_802F9FFC.idx[2], lbl_802F9FFC.idx[1]);
    }
}

f32 fn_8023400C(s32 arg0) {
    register f32 width;
    register f32 height;
    f64 escapeWidth;
    f32 escapeScale;
    register s32 offset;
    register s32 index;
    u8 *font;
    char *text;
    register u8 *recordCount;
    register s32 tokenIndex;
    register s32 tokenOffset;
    u8 *character;
    const char *token;
    register u8 *next;
    register u8 *entry;
    register u8 *glyphs;
    register u8 *glyph;
    s32 consumed;
    register u16 codepoint;
    u8 first;

    offset = arg0 * 0x58;
    width = lbl_8056368C;
    index = 0;
    height = width;
    text = (char *)(*(volatile s32 *)&lbl_8055F06C) + offset;
    font = (u8 *)(*(volatile s32 *)&lbl_8055F058);
    strlen(text);
    recordCount = (u8 *)(&((s32 *)lbl_80497F14)[1]);
    goto char_test;

char_body:
    escapeWidth = (f32)*(u8 *)(font + 4);
    escapeScale = (f32)*(u8 *)(font + 4);

    if ((s8)text[index] == '\\') {
        character = (u8 *)text + index + 1;
        for (tokenIndex = 0, tokenOffset = 0; tokenIndex < *(s32 *)recordCount; tokenOffset += 0x1C, tokenIndex++) {
            token = *(const char **)(*(u8 **)lbl_80497F14 + tokenOffset);
            if (fn_8002B1D8((const char *)character, token, strlen(token)) == 0) {
                entry = *(u8 **)lbl_80497F14 + tokenIndex * 0x1C;
                if (*(s32 *)(entry + 0xC) != 0) {
                    escapeScale /= fn_80235F64(*(s32 *)(entry + 0xC), *(s32 *)(entry + 0x10));
                    escapeWidth = *(f32 *)(entry + 4) * (escapeScale * fn_80235EF0(*(s32 *)(entry + 0xC), *(s32 *)(entry + 0x10)))
                                + *(f32 *)(entry + 4) * (*(f32 *)(entry + 0x18) * escapeScale);
                } else {
                    escapeWidth = escapeScale * *(f32 *)(entry + 4);
                }
                consumed = strlen(*(const char **)(*(u8 **)lbl_80497F14 + tokenOffset)) + 1;
                goto match;
            }
        }
        consumed = 0;
match: ;
    } else {
        consumed = 0;
    }

    if (consumed != 0) {
        index += consumed;
        width += (f32)escapeWidth;
        goto char_test;
    }

    first = text[index];
    character = (u8 *)text + index;
    if ((first & 0xF0) == 0xE0) {
        codepoint = ((first & 0x0F) << 12) | ((character[1] & 0x3F) << 6) | (character[2] & 0x3F);
        next = character + 3;
    } else if ((first & 0xE0) == 0xC0) {
        codepoint = ((first & 0x1F) << 6) | __rlwinm(character[1], 0, 26, 23);
        next = character + 2;
    } else {
        codepoint = first & 0x7F;
        next = character + 1;
    }

    glyphs = *(u8 **)(font + 0x10);
    glyph = glyphs + (u16)codepoint * 0x1C;
    index += next - character;
    width += *(f32 *)(glyph + 4);
    height += *(f32 *)glyph + *(f32 *)(glyph + 8);

char_test:
    if ((s8)text[index] != 0) goto char_body;

    text = (char *)(*(volatile s32 *)&lbl_8055F06C) + offset;
    width *= *(f32 *)(text + 0x50);
    height *= *(f32 *)(text + 0x54);
    return width + height;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8023423C(s32 arg0, s32 arg1) {
    register unsigned int offset = arg0 * 0x58;
    u8 *base = (u8 *)lbl_8055F06C;
    u8 *record = base + offset;
    u8 *font = (u8 *)lbl_8055F058;
    register u16 codepoint;
    u8 first;
    u8 *table;
    u8 *metrics;
    f32 speed = *(f32 *)(record + 0x50);
    register f32 scale = *(f32 *)(record + 0x54);

    if (arg1 & 1) {
        first = record[0];
        if ((first & 0xF0) == 0xE0) {
            codepoint = ((first & 0x0F) << 12) | ((record[1] & 0x3F) << 6) | (record[2] & 0x3F);
        } else if ((first & 0xE0) == 0xC0) {
            codepoint = ((first & 0x1F) << 6) | __rlwinm(record[1], 0, 26, 23);
        } else {
            codepoint = first & 0x7F;
        }
        table = *(u8 **)(font + 0x10);
        metrics = table + codepoint * 0x1C;
        {
            f32 glyphRate = *(volatile f32 *)metrics;
            *(volatile f32 *)((s32)base + offset + 0x40) -= scale * glyphRate;
        }
    } else if (arg1 & 2) {
        *(f32 *)((u8 *)lbl_8055F06C + offset + 0x40) -= fn_8023400C(arg0);
    } else if (arg1 & 4) {
        *(f32 *)((u8 *)lbl_8055F06C + offset + 0x40) -= fn_8023400C(arg0) * lbl_80563688;
    }

    if (arg1 & 8) {
        *(f32 *)((u8 *)lbl_8055F06C + offset + 0x44) -= (f32)font[4] * speed;
    } else if (arg1 & 0x20) {
        *(f32 *)((u8 *)lbl_8055F06C + offset + 0x44) -= (f32)font[6] * speed;
    } else if (arg1 & 0x10) {
        {
            f32 delta = (f32)font[4] * speed;
            *(f32 *)((u8 *)lbl_8055F06C + offset + 0x44) -= lbl_80563688 * delta;
        }
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_8023441C(const char *arg0) {
    lbl_8055F06C = (s32)((void *(*)(s32, const char *))fn_8012850C)(0x2100, lbl_80340614);
    lbl_8055F058 = fn_80232578(arg0);
    *(s32 *)((u8 *)&lbl_8055F058 + 4) = 0;
}
#pragma pop
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
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802344CC(s32 text, s32 fontSet, s32 color, s32 fontId, f32 x, f32 y, f32 scale) {
    /* Queues an on-screen text draw: copies the string/font-set pair into the next
       slot, records position/scale/color/font, flushes if the queue is full. */
    s32 resolvedFontSet;
    s32 resolvedText;

    resolvedText = text;
    resolvedFontSet = fontSet;
    ((void (*)(u8 **, u8 **))fn_80232024)((u8 **)&resolvedText, (u8 **)&resolvedFontSet);
    if (*(s32 *)((u8 *)&lbl_8055F058 + 4) >= 0x60)
        fn_802346C8();

    {
        register s32 *queueState = (s32 *)&lbl_8055F058;

        strncpy((char *)((u8 *)lbl_8055F06C + queueState[1] * 0x58), (char *)resolvedText, 0x40);
        *((u8 *)lbl_8055F06C + queueState[1] * 0x58 + 0x3F) = 0;
        *(s32 *)((u8 *)lbl_8055F06C + queueState[1] * 0x58 + 0x48) = resolvedFontSet;
        *(s32 *)((u8 *)lbl_8055F06C + queueState[1] * 0x58 + 0x4C) = fn_80231718(resolvedFontSet);
        *(f32 *)((u8 *)lbl_8055F06C + queueState[1] * 0x58 + 0x40) = x;
        *(f32 *)((u8 *)lbl_8055F06C + queueState[1] * 0x58 + 0x44) = y;
        *(f32 *)((u8 *)lbl_8055F06C + queueState[1] * 0x58 + 0x50) = scale;
        if (fontId != 0)
            *(f32 *)((u8 *)lbl_8055F06C + queueState[1] * 0x58 + 0x54) = lbl_805636A8 * scale;
        else
            *(f32 *)((u8 *)lbl_8055F06C + queueState[1] * 0x58 + 0x54) = scale;
        fn_8023423C(queueState[1], color);
        {
            register s32 *nextQueueState = (s32 *)&lbl_8055F058;
            nextQueueState[1] = nextQueueState[1] + 1;
        }
    }
}
#pragma dont_inline off
#pragma pop
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
f32 f30 = lbl_80563688;
f32 f31 = lbl_8056368C;
f32 f28;
f32 f27;
f32 f26;
f32 f25;
f32 f24;
volatile f32 sp8;
s32 mode;
s32 i;
s32 textOffset;
s32 charIndex;
s32 nameIndex;
s32 glyphOffset;
u32 *colorPtr;
u8 *object;
u8 *record;
u8 *glyphDef;
u32 fontColor;
s8 *start;
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
if (i < *(s32 *)((u8 *)&lbl_8055F058 + 4)) goto record_body;
fn_802C8E48();
}
fn_802C8D74();
if (mode == 2) fn_80231ADC();
else fn_80231780(0);
mode--;
outer_test:
if (mode > 0) goto outer_body;
*(s32 *)((u8 *)&lbl_8055F058 + 4) = 0;
}
#pragma dont_inline off
#pragma scheduling on
#pragma pop

void fn_80234AEC(void) {
    *(s32 *)((u8 *)&lbl_8055F058 + 4) = 0;
}

/* Text draw settings kept inside a HUD/screen object; fn_80234AFC and friends read
   these to draw a formatted string (see fn_80232BA4 for the draw call itself). */
typedef struct {
    s32 font;        /* font context pointer, e.g. the "bigtext.gtx" one at lbl_8055D498 */
    s32 color;       /* RGBA pen colour, 0xFF000000 = shadowed text */
    s32 style;       /* layout flags passed to fn_80233BF0 (wrap/spacing modes) */
    f32 scale;       /* text scale */
    f32 spacing;     /* extra horizontal scale used when measuring the string */
} TextDrawStyle;

#pragma push
#pragma processor 750
/* printf-style text draw for a screen object: formats `fmt` (plus the variadic
   arguments) into a scratch buffer and draws it at (x, y) with fn_80232BA4, using the
   font, colour, style flags, scale and spacing of the text settings record `style`.
   The fixed 1.0f (lbl_80563684) is the pen value fn_80232BA4's callers normally pass
   there. */
void fn_80234AFC(TextDrawStyle *style, const char *fmt, f32 x, f32 y, ...) {
    char buffer[0x80];
    va_list args;

    va_start(args, y);
    vsprintf(buffer, fmt, args);
    fn_80232BA4(buffer, style->font, style->color, style->style, x, y,
                style->scale, lbl_80563684, style->spacing);
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

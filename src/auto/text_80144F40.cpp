#include <types.h>
#include <stdarg.h>

extern "C" f32 lbl_805615D0;
extern "C" s32 fn_801450A0(u32, u32, f32);
extern "C" void fn_80147DC0(void *, s32, s32);
extern "C" void fn_801476D8(void *, s32, s32);
extern "C" s32 fn_80147C50(u32, u32, f32);

extern "C" void *lbl_8032D1E8;
extern "C" void *fn_80148294(const char *, void *);
extern "C" f32 lbl_8055E200;
extern "C" f32 lbl_8055E204;
extern "C" int stricmp(const char *, const char *);
extern "C" void fn_80148334(s32, s32, void *);
extern "C" void fn_801483D4(s32, s32, void *);
extern "C" void *lbl_8032D1D8;
extern "C" f32 fn_801451DC(s32);
extern "C" f32 fn_801452B4(f32);
extern "C" f32 lbl_805615D4;
extern "C" void fn_801470B0(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80148DFC(void *);
extern "C" void fn_80148E6C(void *);
extern "C" void fn_80148EDC(void *);

class ThreadObject80144F40 {
public:
    virtual void destroy(s32);
};

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" {
struct Queue80145D8C {
    void **data;
    s32 count;
    s32 capacity;
};
extern Queue80145D8C lbl_8042FBC0;
extern char lbl_8032CEC8[];
extern char lbl_80559E14[];
void fn_802E30C8(const char *);
extern char lbl_8032D0D0[];
void fn_8000FF88(s32, s32, s32, f32, f32, f32);
extern char lbl_8032CF48[];
extern char lbl_80559DD0[];
s32 fn_8023512C(void);
void fn_802E3AD0(s32, const char *, ...);
}

extern "C" f32 lbl_805615F0;
extern "C" f32 lbl_8055D020;
extern "C" s32 fn_80144F40(const char *arg0, void *arg1) {
    extern char *strstr(const char *, const char *);
    struct Entry { const char *text; s32 flags; };
    Entry *entry = (Entry *)arg1;
    s32 result = 0;
    while (entry->text != 0) {
        if (strstr(arg0, entry->text) != 0)
            result |= entry->flags;
        entry++;
    }
    return result;
}

extern "C" u8 lbl_80559DCC;
extern "C" s32 fn_80144FB0(void *arg0, s32 arg1, s32 arg2, const char *arg3) {
    struct Entry { const char *text; u32 mask; };
    char *dst = (char *)arg0;
    Entry *entry = (Entry *)arg3;
    *dst = 0;
    while (entry->text != 0) {
        if ((entry->mask & (u32)arg2) == entry->mask) {
            if (*dst != 0) {
                s32 left = arg1;
                char *end = dst;
                while (*end != 0) { left--; end++; }
                if (left > 0) {
                    const char *sep = (const char *)&lbl_80559DCC;
                    do {
                        char c = *sep++;
                        *end++ = c;
                        if (c != 0) {
                            left--;
                            if (left <= 0) { end[-1] = 0; break; }
                        } else break;
                    } while (1);
                }
            }
            const char *src = entry->text;
            s32 left2 = arg1;
            char *end2 = dst;
            while (*end2 != 0) { left2--; end2++; }
            if (left2 > 0) {
                do {
                    char c = *src++;
                    *end2++ = c;
                    if (c != 0) {
                        left2--;
                        if (left2 <= 0) { end2[-1] = 0; break; }
                    } else break;
                } while (1);
            }
        }
        entry++;
    }
    return 0;
}

extern "C" s32 fn_801450A0(u32 arg0, u32 arg1, f32 arg2) {
    f32 temp_f1 = (f32)arg0 + arg2 * ((f32)arg1 - (f32)arg0);
    f32 var_f0;
    s32 temp_r3;
    s32 temp_r4;
    s32 var_r0 = 0xFF;
    if (temp_f1 < lbl_805615D4) var_f0 = temp_f1 - lbl_805615D0;
    else var_f0 = lbl_805615D0 + temp_f1;
    temp_r4 = (s32)var_f0;
    temp_r3 = temp_r4 & ((s32)(-temp_r4 & ~temp_r4) >> 31);
    if (temp_r3 < 0xFF) var_r0 = temp_r3;
    return (u8)var_r0;
}

extern "C" s32 fn_80145140(void *arg0, const char *arg1) {
    s32 count = 0;
    s32 index = 0;
    void *item;
loop:
    item = ((void *(*)(void *, s32))(*(void ***)arg0)[3])(arg0, index);
    if (item == 0)
        goto done;
    if (stricmp(((const char *(*)(void *))(*(void ***)item)[2])(item), arg1) == 0)
        count++;
    index++;
    goto loop;
done:
    return count;
}

extern "C" f32 fn_801452A0(s32 arg0, f32 arg1) {
    if (arg0 & 0x20)
        arg1 /= lbl_8055D020;
    return arg1;
}

extern "C" f32 fn_801452B4(f32 arg0) { f32 result = lbl_805615F0 - arg0; result = result + lbl_8055E204; return result; }

extern "C" f32 fn_801452C8(f32 arg0) {
    extern f32 lbl_805615E0;
    return lbl_805615E0 + arg0;
}

extern "C" f32 fn_801452D4(f32 arg0) { return lbl_805615F0 - arg0; }

#pragma push
#pragma dont_inline on
extern "C" f32 fn_801452E0(void *arg0, const char *arg1) {
    extern char *strchr(const char *, int);
    extern double atof(const char *);
    class V { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual const char *get(const char *); };
    f64 temp_f31;
    const char *text = ((V *)arg0)->get(arg1);
    if (strchr(text, '/') != 0) {
        temp_f31 = atof(strchr(text, '/') + 1);
        return (f32)(atof(text) / temp_f31);
    }
    return (f32)atof(text);
}
#pragma dont_inline reset
#pragma pop
extern "C" void fn_80145368(void *arg0, void *arg1) {
    extern char lbl_80559DD0[];
    extern char lbl_80559DD8[];
    extern char lbl_80559DDC[];
    extern char lbl_8032CF18[];
    extern u8 lbl_8055E208;
    extern f32 fn_801452C8(f32);
    extern f32 fn_801452D4(f32);
    *(s32 *)arg0 = ((s32 (*)(void *, const char *))(*(void ***)arg1)[5])(arg1, lbl_80559DD0);
    *(f32 *)((u8 *)arg0 + 4) = ((f32 (*)(void *, const char *))(*(void ***)arg1)[9])(arg1, lbl_80559DD8);
    *(f32 *)((u8 *)arg0 + 8) = ((f32 (*)(void *, const char *))(*(void ***)arg1)[9])(arg1, lbl_80559DDC);
    if (lbl_8055E208) {
        *(f32 *)((u8 *)arg0 + 4) = fn_801452C8(*(f32 *)((u8 *)arg0 + 4));
        *(f32 *)((u8 *)arg0 + 8) = fn_801452D4(*(f32 *)((u8 *)arg0 + 8));
    }
    *(s32 *)((u8 *)arg0 + 0xC) = ((s32 (*)(void *, const char *, s32))(*(void ***)arg1)[8])(arg1, lbl_8032CF18, 0);
}

extern "C" f32 lbl_805615E0;
extern "C" void fn_80145438(void *arg0, void *arg1) {
    extern char lbl_80559DE0[]; extern char lbl_80559DE4[]; extern char lbl_80559DE8[]; extern char lbl_80559DEC[]; extern char lbl_80559DF0[]; extern char lbl_80559DF4[];
    fn_80145368(arg0, arg1);
    *(f32 *)((u8 *)arg0 + 0x10) = ((f32 (*)(void *, const char *))(*(void ***)arg1)[9])(arg1, lbl_80559DE0);
    *(f32 *)((u8 *)arg0 + 0x14) = ((f32 (*)(void *, const char *))(*(void ***)arg1)[9])(arg1, lbl_80559DE4);
    *(f32 *)((u8 *)arg0 + 0x18) = fn_801452E0(arg1, lbl_80559DE8);
    *(f32 *)((u8 *)arg0 + 0x20) = fn_801452E0(arg1, lbl_80559DEC);
    *(f32 *)((u8 *)arg0 + 0x1C) = fn_801452E0(arg1, lbl_80559DF0);
    *(f32 *)((u8 *)arg0 + 0x24) = fn_801452E0(arg1, lbl_80559DF4);
}

extern "C" s32 fn_801454E8(void *arg0) {
    class V { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual const char *f5(); };
    extern char lbl_80559DF8[];
    extern int sscanf(const char *, const char *, ...);
    s32 result;
    const char *text = ((V *)arg0)->f5();
    if (sscanf(text, lbl_80559DF8, &result) != 1)
        result = -1;
    return result;
}

extern "C" void fn_80145538(void *arg0, void *arg1) {
    extern s32 fn_80145368();
    extern s32 fn_801454E8(void *, const char *);
    extern char lbl_80559DE0[];
    extern char lbl_80559DE4[];
    extern char lbl_80559DFC[];
    fn_80145368();
    *(f32 *)((u8 *)arg0 + 0x10) = (*(f32 (**)(void *, const char *))(*(u8 **)arg1 + 0x24))(arg1, lbl_80559DE0);
    *(f32 *)((u8 *)arg0 + 0x14) = (*(f32 (**)(void *, const char *))(*(u8 **)arg1 + 0x24))(arg1, lbl_80559DE4);
    *(s32 *)((u8 *)arg0 + 0x18) = fn_801454E8(arg1, lbl_80559DFC);
}

extern "C" s32 fn_801455B8(void *arg0, void *arg1) {
    struct Obj {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5(const char *);
        virtual s32 f6(const char *, const char *);
        virtual void f7();
        virtual void f8();
        virtual f32 f9(const char *);
    };
    extern char lbl_8032CEC8[];
    extern char lbl_80559E04[];
    extern char lbl_80559E0C[];
    extern char lbl_80559DFC[];
    extern s32 fn_80145368(void);
    extern s32 fn_80144F40(const char *);
    extern s32 fn_801454E8(void *, const char *);
    Obj *obj = (Obj *)arg1;
    fn_80145368();
    obj->f5(lbl_80559E04);
    *(s32 *)((u8 *)arg0 + 0x14) = fn_80144F40(lbl_8032CEC8 + 0x10);
    *(f32 *)((u8 *)arg0 + 0x10) = obj->f9(lbl_80559E0C);
    *(s32 *)((u8 *)arg0 + 0x18) = fn_801454E8(arg1, lbl_80559DFC);
    *(s32 *)((u8 *)arg0 + 0x1C) = obj->f6(lbl_8032CEC8 + 0x5C, lbl_8032CEC8 + 0x70);
    return 0;
}

extern "C" s32 fn_80145670(void *arg0, void *arg1) {
    struct VTable {
        s32 (*unused0)(void);
        s32 (*unused1)(void);
        s32 (*unused2)(void);
        s32 (*unused3)(void);
        s32 (*unused4)(void);
        s32 (*get)(void *, const char *);
    };
    VTable *vtable = *(VTable **)arg1;
    *(s32 *)arg0 = vtable->get(arg1, lbl_80559DD0);
    *(s32 *)((u8 *)arg0 + 4) = vtable->get(arg1, lbl_8032CF48);
    *(s32 *)((u8 *)arg0 + 8) = fn_8023512C();
    return 0;
}

extern "C" s32 fn_8013126C(void *, s32);
extern "C" s32 fn_80144FB0(void *, s32, s32, const char *);
extern "C" void fn_801456E8(void *arg0, s32 arg1, s32 arg2) {
    struct Entry { s32 unk0; f32 unk4; f32 unk8; s32 unkC; f32 unk10; s32 unk14; s32 unk18; s32 unk1C; };
    struct List { Entry *entries; s32 count; };
    List *list = (List *)arg0;
    char pad[0xF0];
    char buffer[0x40];
    char result[0x48];
    s32 value;
    s32 offset = 0;
    s32 i = 0;
    Entry *entry;
    fn_802E3AD0(arg1, lbl_8032CEC8 + 0x90);
    fn_802E3AD0(arg1, lbl_8032CEC8 + 0xA0);
    while (i < list->count) {
        entry = (Entry *)((u8 *)list->entries + offset);
        value = fn_8013126C(result, entry->unk1C);
        fn_80144FB0(buffer, 0x40, entry->unk14, lbl_8032CEC8 + 0x10);
        fn_802E3AD0(arg1, lbl_8032CEC8 + 0xD4, entry->unkC, entry->unk18, buffer,
                    entry->unk0, value, entry->unk4, entry->unk8, entry->unk10);
        offset += 0x20;
        i++;
    }
    fn_802E3AD0(arg1, lbl_80559E14);
}

extern "C" void fn_801457D0(void *arg0, s32 arg1, s32 arg2) {
    char *base = lbl_8032CEC8;
    s32 offset;
    s32 i;
    fn_802E3AD0(arg1, base + 0x104);
    fn_802E3AD0(arg1, base + 0x114);
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        u8 *entry = *(u8 **)arg0 + offset;
        fn_802E3AD0(arg1, base + 0x140,
            *(f32 *)(entry + 4), *(f32 *)(entry + 8),
            *(f32 *)(entry + 0x10), *(f32 *)(entry + 0x14),
            *(f32 *)(entry + 0x18), *(f32 *)(entry + 0x1C),
            *(f32 *)(entry + 0x20), *(f32 *)(entry + 0x24),
            *(s32 *)(entry + 0xC), *(s32 *)entry);
        offset += 0x28;
        i++;
    }
    fn_802E3AD0(arg1, lbl_80559E14);
}

extern "C" void fn_8014589C(void *arg0, s32 arg1, s32 arg2) {
    char *base = lbl_8032CEC8;
    fn_802E3AD0(arg1, base + 0x170);
    fn_802E3AD0(arg1, base + 0x180);
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        u8 *entry = *(u8 **)arg0 + offset;
        fn_802E3AD0(arg1, base + 0x1A8,
            *(f32 *)(entry + 4), *(f32 *)(entry + 8),
            *(f32 *)(entry + 0x10), *(f32 *)(entry + 0x14),
            *(s32 *)(entry + 0x18), *(s32 *)(entry + 0xC), *(s32 *)entry);
        offset += 0x1C;
        i++;
    }
    fn_802E3AD0(arg1, lbl_80559E14);
}

extern "C" void fn_8014595C(void *arg0, const char *arg1) {
    char *base = lbl_8032CEC8;
    fn_802E3AD0((s32)arg1, base + 0x1D0);
    fn_802E3AD0((s32)arg1, base + 0x1E4);
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        void *entry = (void *)(*(u8 **)arg0 + offset);
        fn_802E3AD0((s32)arg1, base + 0x1FC,
            *(s32 *)((u8 *)entry + 4), *(s32 *)entry);
        offset += 0xC;
        i++;
    }
    fn_802E3AD0((s32)arg1, lbl_80559E14);
}

extern "C" f32 fn_80145A08(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    f32 span = farg3 - farg2;
    f32 den = farg1 - farg0;
    f32 num = farg4 - farg0;
    return farg2 + (num / den) * span;
}

extern "C" u32 fn_802C9C38(f64, f64);
extern "C" s32 fn_802C9C48(void);
extern "C" f32 fn_80145A08(f32, f32, f32, f32, f32);
extern "C" f32 lbl_805615F4;
extern "C" f32 lbl_805615F8;
extern "C" f32 lbl_805615FC;
extern "C" f64 lbl_80561600;
extern "C" s32 fn_80145A24(void *arg0) {
    s32 result;
    f32 out0;
    f32 out1;
    f64 v1 = (f64)fn_802C9C48() - lbl_80561600;
    f64 v2 = (f64)fn_802C9C48() - lbl_80561600;
    out0 = fn_80145A08(lbl_805615D4, v1, lbl_805615D4, lbl_805615F4, *(f32 *)((u8 *)arg0 + 4));
    f32 m = lbl_805615F8 * (f32)v1;
    f32 p = m * lbl_805615D0;
    s32 i = fn_802C9C38(v2, v1);
    s32 s = (i >> 31) + i;
    s32 t = (s >> 1) ^ 0x8000;
    f32 q = (f32)((f64)t + (f64)fn_802C9C48() - lbl_80561600 - p);
    out1 = fn_80145A08(q, q + lbl_805615F8 * (f32)v1, lbl_805615D4, lbl_805615FC, *(f32 *)((u8 *)arg0 + 8));
    *(f32 *)((u8 *)arg0 + 8) = out0;
    *(f32 *)((u8 *)arg0 + 0xC) = out1;
    result = *(s32 *)((u8 *)arg0 + 8);
    return result;
}

extern "C" f32 lbl_80561608;
extern "C" void fn_8001027C(s32, s32, void *, u32, f32, f32, f32);
extern "C" f32 fn_801452A0(s32, f32);
extern "C" void fn_802354A0(s32, s32, s32, f32, f32, f32, f32);
extern "C" s32 lbl_80559E1C;
extern "C" void fn_80145B50(void *arg0, s32 arg1) {
    f32 value = (f32)arg1;
    *(f32 *)((u8 *)arg0 + 4) = lbl_805615D4;
    *(f32 *)((u8 *)arg0 + 0xC) = lbl_80561608;
    *(f32 *)((u8 *)arg0 + 8) = lbl_80561608;
    *(f32 *)arg0 = lbl_80561608 * value;
}

#pragma dont_inline on
#pragma push
#pragma processor 750
extern "C" void fn_80145B94(void *arg0, u32 arg1) {
    f32 scale = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 input = *(f32 *)((u8 *)arg0 + 4);
    s32 id = *(s32 *)((u8 *)arg0 + 0xC);
    f32 value = ((f32 (*)(s32, f32))fn_801451DC)(id, input);
    f32 last = *(f32 *)((u8 *)arg0 + 0x10);
    s32 b = *(s32 *)((u8 *)arg0 + 0x14);
    s32 a = *(s32 *)((u8 *)arg0 + 0x18);
    fn_8000FF88(a, b, (s32)arg1, last, value, scale);
}
#pragma pop
#pragma dont_inline reset

extern "C" void fn_80145C7C(void *arg0, u32 arg1) {
    f32 temp_f31 = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 temp_f2 = ((f32 (*)(s32, f32))fn_801451DC)(*(s32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 4));
    fn_8001027C(*(s32 *)((u8 *)arg0 + 0x18), *(s32 *)((u8 *)arg0 + 0x14), &lbl_80559E1C,
        arg1, *(f32 *)((u8 *)arg0 + 0x10), temp_f2, temp_f31);
}

extern "C" void fn_80145CF4(void *arg0, void *arg1, u32 arg2) {
    f32 temp_f30 = fn_801452A0(*(s32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 0x10));
    f32 temp_f31 = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    ((f32 (*)(s32, f32))fn_801451DC)(*(s32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 4));
    fn_802354A0((s32)arg1, arg2, *(s32 *)((u8 *)arg0 + 0x18), temp_f31, lbl_805615D4, temp_f30, *(f32 *)((u8 *)arg0 + 0x14));
}

extern "C" void fn_80145D8C(void *arg0) {
    if (lbl_8042FBC0.count + 1 <= lbl_8042FBC0.capacity) {
        s32 i = lbl_8042FBC0.count;
        lbl_8042FBC0.count = i + 1;
        lbl_8042FBC0.data[i] = arg0;
        return;
    }
    fn_802E30C8(lbl_8032D0D0);
}

extern "C" void *fn_801284F8(u32, void *);
extern "C" void *fn_8012850C(u32, void *);
extern "C" void *fn_8002F37C(void *, s32, s32, s32);
extern "C" s32 fn_80145140(void *, const char *);
extern "C" void fn_80145438(void *, void *);
extern "C" void fn_801460F4(void);
extern "C" char lbl_8032D108[];
extern "C" char lbl_80559E48[];
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_80145FEC(void *arg0, const char *arg1, s32 arg2) {
    struct Result { void *data; s32 count; s32 size; void *end; };
    class Collection { public: virtual void a(); virtual void b(); virtual void *get(s32); };
    class Item { public: virtual void a(); virtual const char *name(); };
    extern void *fn_801284F8(u32, void *);
    extern void *fn_8012850C(u32, void *);
    extern void *fn_8002F37C(s32, void *, s32, s32);
    extern s32 fn_80145140(void *, const char *);
    extern void fn_80145438(void *, void *);
    extern void fn_801460F4(void);
    extern char lbl_8032D108[];
    extern char lbl_80559E48[];
    extern int stricmp(const char *, const char *);
    Result *result;
    s32 size = fn_80145140(arg0, arg1);
    result = (Result *)fn_801284F8(0x10, lbl_8032D108);
    if (result != 0) {
        fn_8012850C(size * 0x28 + 0x10, lbl_80559E48);
        result->data = fn_8002F37C(0, (void *)fn_801460F4, 0x28, size);
        result->size = size;
        result->count = 0;
        result->end = result->data;
    }
    s32 i = 0;
    while (1) {
        void *item = ((Collection *)arg0)->get(i);
        if (item == 0) break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, arg1) == 0) {
            s32 count = result->count;
            void *data = result->data;
            s32 offset = count * 0x28;
            result->count = count + 1;
            fn_80145438((char *)data + offset, item);
        }
        i++;
    }
    return result;
}
#pragma dont_inline reset
#pragma pop
extern "C" void fn_801460F4(void) {
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_801460F8(void *arg0, const char *arg1, s32 arg2) {
    struct Result { void *data; s32 count; s32 size; void *end; };
    extern void *fn_801284F8(u32, void *);
    extern void *fn_8012850C(u32, void *);
    extern void *fn_8002F37C(void *, void *, s32, s32, s32);
    extern s32 fn_80145140(void *, const char *);
    extern void fn_801455B8(void *, void *, s32, s32);
    extern void fn_80146200(void);
    extern char lbl_8032D108[];
    extern char lbl_80559E48[];
    extern int stricmp(const char *, const char *);
    Result *result;
    s32 size = fn_80145140(arg0, arg1);
    result = (Result *)fn_801284F8(0x10, lbl_8032D108);
    if (result != 0) {
        void *arena = fn_8012850C((size << 5) + 0x10, lbl_80559E48);
        result->data = fn_8002F37C(arena, (void *)fn_80146200, 0, 0x20, size);
        result->size = size;
        result->count = 0;
        result->end = result->data;
    }
    s32 i = 0;
    while (1) {
        void *item = ((void *(*)(void *, s32))(*(void ***)arg0)[3])(arg0, i);
        if (item == 0) break;
        const char *name = ((const char *(*)(void *))(*(void ***)item)[2])(item);
        if (stricmp(name, arg1) == 0) {
            s32 count = result->count;
            void *data = result->data;
            s32 offset = count << 5;
            result->count = count + 1;
            fn_801455B8((char *)data + offset, item, count, (s32)data);
        }
        i++;
    }
    return result;
}
#pragma dont_inline reset
#pragma pop

extern "C" void fn_80146200(void) {

}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_80146204(void *arg0, const char *arg1, s32 arg2) {
    extern void fn_8014630C(void);
    struct Result { void *data; s32 count; s32 size; void *end; };
    class Collection { public: virtual void a(); virtual void *get(s32); };
    class Item { public: virtual const char *name(); };
    Result *result;
    s32 size = fn_80145140(arg0, arg1);
    result = (Result *)fn_801284F8(0x10, lbl_8032D108);
    if (result != 0) {
        s32 bytes = size * 0x1C + 0x10;
        s32 allocator = (s32)fn_8012850C(bytes, &lbl_80559E48);
        result->data = ((void *(*)(s32, void *, s32, s32, s32))fn_8002F37C)(allocator, (void *)fn_8014630C, 0, 0x1C, size);
        result->size = size;
        result->count = 0;
        result->end = result->data;
    }
    s32 i = 0;
    while (1) {
        void *item = ((Collection *)arg0)->get(i);
        if (item == 0) break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, arg1) == 0) {
            s32 count = result->count;
            void *data = result->data;
            s32 offset = count * 0x1C;
            result->count = count + 1;
            fn_80145538((char *)data + offset, item);
        }
        i++;
    }
    return result;
}
#pragma dont_inline reset
#pragma pop

extern "C" void fn_8014630C(void) {
}

extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *arg0, s32 arg1) {
    extern void fn_80235380();
    extern void fn_80128668(void *);
    if (arg0 != 0) {
        if (*(s32 *)((char *)arg0 + 8)) fn_80235380();
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8014647C(void *);
extern "C" void fn_8014647C(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[2] = 0;
}

extern "C" void *fn_80146490(void *arg0) {
    if (arg0 != NULL) {
        if (((s32 *)arg0)[10] == 0) {
            if (arg0) {
                volatile void **v = *(volatile void ***)arg0;
                ((void * (*)(void *, s32))v[2])(arg0, 1);
            }
            return NULL;
        }
    }
    return arg0;
}

extern "C" void fn_80128668(void *);
extern "C" void fn_80146584(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80128670(s32);
extern "C" void fn_80131818(void);
extern "C" void fn_80145DD8(void *);
extern "C" void fn_80146584(void *);
extern "C" void fn_801465C8(void *);
extern "C" void fn_80146638(void *);
extern "C" void fn_801466B4(void *);
extern "C" void fn_80146730(void *);
extern "C" void fn_801467AC(void *);
extern "C" void *lbl_8032D1E8;
extern "C" void fn_801465C8(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((s32 *)p)[3]);
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80146638(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            s32 x = ((s32 *)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_801466B4(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            s32 x = ((s32 *)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80146730(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            s32 x = ((s32 *)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" f32 fn_800108C8(const char *, f32);
extern "C" void fn_80235380();
extern "C" void fn_80145B94(void *, u32);
extern "C" void fn_80146BD4(u8 *arg0, const s8 *arg1, s32 arg2) {
    goto copy;
    for (;;) {
        if (--arg2 <= 0) {
            arg0[-1] = 0;
            return;
        }
    copy:
        u8 c = (u8)*arg1;
        arg1++;
        *arg0 = c;
        arg0++;
        if ((s8)c == 0) return;
    }
}

extern "C" void *lbl_8032D214;
extern void lbl_8032D260(void);
extern "C" void fn_80146C1C(void **arg0) {
    *arg0 = (void *)&lbl_8032D260;
}
extern "C" void fn_8002F6AC(s32, void *);
extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *, s32);
extern "C" s32 fn_80147070(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

extern "C" f32 fn_80147204(void *arg0, const char *arg1) {
    if (arg0 != 0) {
        if ((u8)*arg1 == 1)
            arg1++;
        return fn_800108C8(arg1, *(f32 *)((u8 *)arg0 + 0x10));
    }
    return lbl_805615D4;
}

extern "C" int vsprintf(char *, const char *, va_list);
extern "C" unsigned int strlen(const char *);
extern "C" void fn_802E317C(const char *, ...);
  extern "C" char lbl_8032D1A4[];
#pragma scheduling invalid_target
extern "C" void fn_80147230(void *arg0, const char *arg1, ...) {
    char buffer[0x200];
    if (arg0 != 0) {
        va_list args;
        va_start(args, arg1);
        vsprintf(buffer, arg1, args);
        if (strlen(buffer) >= 0x200)
            fn_802E317C(lbl_8032D1A4, strlen(buffer), arg1);
        fn_80145B94(arg0, (u32)buffer);
    }
}
#pragma scheduling on
extern "C" void fn_80145C08(void *arg0, const char *arg1);
extern "C" void fn_80147314(void *arg0, const char *format, ...) {
    char buffer[0x200];
    if (arg0 != 0) {
        va_list args;
        va_start(args, format);
        vsprintf(buffer, format, args);
        if (strlen(buffer) >= 0x200) {
            s32 length = strlen(buffer);
            fn_802E317C(lbl_8032D1A4, length, format);
        }
        fn_80145C08(arg0, buffer);
    }
}

extern int vsprintf(char *, const char *, va_list);
extern unsigned int strlen(const char *);
extern char lbl_8032D1A4[];

void fn_80145B94(void *, const char *);
extern "C" void fn_801473F8(void *arg0, s32 arg1, const char *format, ...) {
    class V {
    public:
        virtual void f0();
        virtual void *f1();
    };
    char buffer[0x200];
    va_list args;
    void *result = ((V *)arg0)->f1();
    if (result != 0) {
        va_start(args, format);
        vsprintf(buffer, format, args);
        va_end(args);
        if (strlen(buffer) >= 0x200) {
            s32 length = strlen(buffer);
            fn_802E317C(lbl_8032D1A4, length, format);
        }
        fn_80145B94(result, (u32)buffer);
    }
}

#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_801474EC(void *arg0, const char *arg1, ...) {
    char buffer[0x200];
    if (arg0 != 0) {
        va_list args;
        va_start(args, arg1);
        vsprintf(buffer, arg1, args);
        if (strlen(buffer) >= 0x200)
            fn_802E317C(lbl_8032D1A4, strlen(buffer), arg1);
        fn_80145C7C(arg0, (u32)buffer);
    }
}
#pragma dont_inline reset
#pragma scheduling on
extern "C" void fn_801475D0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f64 farg0, f64 farg1, f64 farg2, f64 farg3, f64 farg4, f64 farg5, f64 farg6, f64 farg7, const char *format, ...) {
    char buffer[0x200];
    va_list args;
    void **vtable = *(void ***)arg0;
    void *result = ((void *(*)(void *))vtable[3])(arg0);
    if (result != 0) {
        va_start(args, format);
        vsprintf(buffer, format, args);
        if (strlen(buffer) >= 0x200) {
            s32 length = strlen(buffer);
            fn_802E317C(lbl_8032D1A4, length, format);
        }
        fn_80145C7C(result, (u32)buffer);
    }
}

extern "C" void fn_801476C4(void *arg0) {
    if (arg0 != 0)
        fn_80145B94(arg0, *(u32 *)((u8 *)arg0 + 0x1c));
}

extern "C" void fn_8014784C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    class V {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 first();
        virtual s32 second(s32);
    };
    s32 result1;
    s32 result2;
    result1 = ((V *)arg0)->first();
    result2 = ((V *)arg0)->second(arg2);
    if (result1 != 0 && result2 != 0)
        ((void (*)(void *, void *, u32))fn_80145CF4)((void *)result1, (void *)result2, (u32)arg3);
}

#pragma dont_inline on
extern "C" void fn_801478E0(void *arg0, s32 unused, s32 arg1, s32 arg2) {
    s32 result = ((s32 (**)(void *))(*(void ***)arg0))[5](arg0);
    if (result != 0 && arg1 != 0)
        fn_80145CF4((void *)result, (void *)arg1, (u32)arg2);
}
#pragma push
#pragma dont_inline on
extern "C" void fn_80147940(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    class V {
    public:
        virtual void a();
        virtual void b();
        virtual void c();
        virtual void d();
        virtual s32 f(s32);
    };
    s32 result = ((V *)arg0)->f(arg2);
    if (arg1 != 0 && result != 0)
        fn_80145CF4((void *)arg1, (void *)result, (u32)arg3);
}
#pragma dont_inline reset
#pragma pop
  extern "C" void fn_80147CEC(void *, s32, s32, f64);
extern "C" void fn_801479A8(void *arg0, void *arg1, const char *format, f64 value, ...) {
    char text[0x200];
    char buffer[0x20];
    va_list args;
    va_start(args, value);
    vsprintf(text, format, args);
    if (strlen(text) >= 0x200)
        fn_802E317C(lbl_8032D1A4, strlen(text), format);
    fn_80147CEC(buffer, (s32)arg0, (s32)arg1, value);
    fn_80147230(buffer, (const char *)&lbl_80559E1C, text);
}

extern "C" void fn_80147ABC(void *arg0, void *arg1, const char *format, f64 value, ...) {
    char text[0x200];
    char buffer[0x20];
    va_list args;
    va_start(args, value);
    vsprintf(text, format, args);
    if (strlen(text) >= 0x200)
        fn_802E317C(lbl_8032D1A4, strlen(text), format);
    fn_80147CEC(buffer, (s32)arg0, (s32)arg1, value);
    fn_80147314(buffer, (const char *)&lbl_80559E1C, text);
}

  extern "C" void fn_80147BD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    u32 tmp;
    fn_80147DC0(&tmp, arg0, arg1);
    fn_801476D8(&tmp, fn_80147C50(arg2, arg3, arg5), arg4);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_80147C50(u32 arg0, u32 arg1, f32 arg2) {
    s32 a = fn_801450A0(arg0 & 0xFF, arg1 & 0xFF, arg2);
    s32 b = fn_801450A0((arg0 >> 8) & 0xFF, (arg1 >> 8) & 0xFF, arg2);
    s32 c = fn_801450A0((arg0 >> 16) & 0xFF, (arg1 >> 16) & 0xFF, arg2);
    s32 d = fn_801450A0(arg0 >> 24, arg1 >> 24, arg2);
    s32 hi = ((d & 0xFF) << 24) | ((c & 0xFF) << 16);
    s32 lo = (a & 0xFF) | ((b & 0xFF) << 8);
    return hi | lo;
}
#pragma pop
extern "C" void fn_80147CEC(void *arg0, s32 arg1, s32 arg2, f64 arg3) {
    struct Data { u32 w0; f32 f4; f32 f8; u32 wc; f32 f10; u32 w14; u32 w18; u32 w1c; };
    Data *dst = (Data *)arg0;
    Data *src = (Data *)arg1;
    Data *other = (Data *)arg2;
    f32 factor = (f32)arg3;
    f32 f4 = src->f4 + factor * (other->f4 - src->f4);
    f32 f8 = src->f8 + factor * (other->f8 - src->f8);
    f32 f10 = src->f10 + factor * (other->f10 - src->f10);
    *dst = *src;
    dst->f4 = f4;
    dst->f8 = f8;
    dst->f10 = f10;
    dst->w18 = fn_80147C50(src->w18, other->w18, factor);
}

#pragma dont_inline off
extern "C" void fn_80147EE0(void *arg0, f32 scale) {
    f32 x = *(f32 *)((u8 *)arg0 + 0x10);
    f32 decay = lbl_805615D0;
    f32 y = *(f32 *)((u8 *)arg0 + 0x14);
    f32 dx = x * scale;
    f32 gx = x * decay;
    f32 xpos = *(f32 *)((u8 *)arg0 + 4);
    f32 dy = y * scale;
    f32 gy = y * decay;
    f32 ypos = *(f32 *)((u8 *)arg0 + 8);
    *(f32 *)((u8 *)arg0 + 0x14) = dy;
    xpos = xpos + gx;
    scale = dx * decay;
    *(f32 *)((u8 *)arg0 + 0x10) = dx;
    ypos = ypos + gy;
    decay = dy * decay;
    *(f32 *)((u8 *)arg0 + 4) = xpos - scale;
    *(f32 *)((u8 *)arg0 + 8) = ypos - decay;
}

extern "C" void *lbl_8032D1D8;
extern "C" f32 fn_801451DC(s32);
extern "C" f32 fn_801452B4(f32);
extern "C" f32 lbl_805615D4;
extern "C" void fn_801470B0(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80148100(void *arg0) {
    fn_801470B0(*(s32 *)((u8 *)arg0 + 0x18), -1,
        *(s32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 4),
        *(f32 *)((u8 *)arg0 + 8), *(f32 *)((u8 *)arg0 + 0x10),
        *(f32 *)((u8 *)arg0 + 0x14), lbl_805615D4, lbl_805615D4,
        lbl_805615D4, lbl_805615D4);
}

#pragma dont_inline on
extern "C" void fn_80148134(f32 *arg0, f32 *arg1, s32 arg2, f32 unused, f32 value) {
    if (arg0 == 0) goto second;
    *arg0 = fn_801451DC(arg2);
second:
    if (arg1 == 0) goto done;
    *arg1 = fn_801452B4(value);
done:
    return;
}
#pragma dont_inline reset
extern "C" void fn_8014819C(void *arg0, f32 farg0, f32 farg1) {
    *(f32 *)arg0 = lbl_8055E200;
    *(f32 *)((u8 *)arg0 + 4) = lbl_8055E204;
    lbl_8055E200 += farg0;
    lbl_8055E204 += farg1;
}

extern "C" void *fn_80148294(const char *, void *);
extern "C" f32 lbl_8055E200;
extern "C" f32 lbl_8055E204;
extern "C" void *fn_801481C8(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        lbl_8055E200 = *(f32 *)arg0;
        lbl_8055E204 = *(f32 *)((u8 *)arg0 + 4);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80148218(void) {
}

extern "C" s32 fn_8014821C(void) {
    return 0;
}

extern "C" void fn_80148224(void) {
}

extern "C" void fn_80148228(void) {
}

extern "C" void fn_80148244(void) {
}

extern "C" s32 fn_80148248(void) {
    return 0;
}

extern "C" void fn_80148250(void *arg0) {
    struct VTable {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
    };
    VTable *obj = *(VTable **)((u8 *)arg0 + 4);
    obj->f8();
}

extern "C" u32 lbl_80559E68;
extern "C" u32 *fn_80148264(void) {
    return &lbl_80559E68;
}

extern "C" s32 DVDGetCurrentDiskID(void) {
    return 0x40000000;
}

extern "C" s32 fn_80148274(void) {
    return 0xC0C0C0C0;
}

extern "C" void fn_80148280(void) {

}

extern "C" void fn_80148284(void *arg0, s32 arg1) {
    fn_80148294((const char *)arg1, *(void **)((u8 *)arg0 + 0x30));
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_80148294(const char *arg0, void *arg1) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), arg0) == 0) {
            return (void *)(*(u32 *)arg1 + i * 0x20);
        }
        offset += 0x20;
        i++;
    }
    return NULL;
}
#pragma pop
extern "C" void fn_80148334(s32, s32, void *);
extern "C" void fn_80148324(void *arg0, s32 arg1) {
    fn_80148334(arg1, *(s32 *)((u8 *)arg0 + 0x2C), arg0);
}

extern "C" void fn_80148334(s32 arg0, s32 arg1, void *arg2) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), (const char *)arg0) == 0) {
            return;
        }
        offset += 0x28;
        i++;
    }
}

extern "C" void fn_801483C4(void *arg0, s32 arg1) {
    fn_801483D4(arg1, *(s32 *)((u8 *)arg0 + 0x34), arg0);
}

extern "C" void fn_801483D4(s32 arg0, s32 arg1, void *arg2) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), (const char *)arg0) == 0) {
            return;
        }
        offset += 0x1C;
        i++;
    }
}

extern "C" void *fn_801484A4(const char *, void *);
extern "C" s32 fn_80148464(void *arg0, const char *arg1) {
    void *entry = fn_801484A4(arg1, *(void **)((u8 *)arg0 + 0x3C));
    if (entry != NULL) return *(s32 *)((u8 *)entry + 8);
    return 0;
}

extern "C" int stricmp(const char *, const char *);
#pragma scheduling off
extern "C" void *fn_801484A4(const char *arg0, void *arg1) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), arg0) == 0) {
            return (void *)(*(u32 *)arg1 + i * 0xC);
        }
        offset += 0xC;
        i++;
    }
    return NULL;
}
#pragma scheduling on
void fn_80029004(char *, int);
char *strcpy(char *, const char *);
char *strchr(const char *, int);
s32 fn_802E3D68(const char *);
void fn_801457D0(s32, s32);
void fn_801456E8(s32, s32);
void fn_8014589C(s32, s32);
void fn_8014595C(s32, s32);
void fn_802E3734(s32 *);
extern char lbl_80559E70[];
extern char lbl_8032D28C[];
extern "C" void fn_80148534(void *arg0) {
    s32 value;
    char *name;
    fn_80029004((char *)arg0 + 5, '.');
    strcpy((char *)arg0 + 5, lbl_80559E70);
    name = (char *)arg0 + 5;
    if (strchr(name, '/') != 0)
        name = strchr(name, '/') + 1;
    value = fn_802E3D68(name);
    if (value != -1) {
        fn_802E3AD0(0, lbl_8032D28C, 1);
        fn_801457D0(*(s32 *)((u8 *)arg0 + 0x2C), value);
        fn_801456E8(*(s32 *)((u8 *)arg0 + 0x30), value);
        fn_8014589C(*(s32 *)((u8 *)arg0 + 0x34), value);
        fn_8014595C(*(s32 *)((u8 *)arg0 + 0x3C), value);
        fn_802E3AD0(value, lbl_80559E14);
        fn_802E3734(&value);
    }
}

extern "C" void fn_80148610(void *arg0) {
    bool *b = (bool *)((u8 *)arg0 + 4);
    *b = !*b;
}

extern "C" u8 fn_80148624(void *arg0) { return ((u8 *)arg0)[4]; }

extern "C" void fn_80148DFC(void *);
extern "C" void fn_80148DFC(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((s32 *)p)[3]);
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80148E6C(void *);
extern "C" void fn_80148E6C(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((s32 *)p)[3]);
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80148EDC(void *);
extern "C" void fn_80148EDC(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((s32 *)p)[3]);
            if (p != NULL) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void deleteThreads__6SystemFv(void *arg0) {
    ThreadObject80144F40 *p = *(ThreadObject80144F40 **)arg0;
    if (p) {
        if (p)
            p->destroy(1);
        *(ThreadObject80144F40 **)arg0 = 0;
    }
}

extern "C" void fn_8014822C(void) {

}

extern "C" s32 fn_80148230(void) {
    return -1;
}

extern "C" s32 fn_80148238(void) {
    return 0xFF808080;
}


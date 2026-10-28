#include <types.h>
#include <stdarg.h>
extern "C" void *fn_801284F8(u32, void *);
extern "C" void *fn_80131810(s32);
extern "C" void fn_80146BD4(u8 *, const s8 *, s32);
extern "C" void fn_80146C08(void *, s32);
extern "C" void fn_80146C1C(void **);
extern "C" void fn_80146824(void *);
extern "C" void *fn_80145FEC(void *, const char *, s32);
extern "C" void *fn_801460F8(void *, const char *, s32);
extern "C" void *fn_80146204(void *, const char *, s32);
extern "C" void *fn_80146310(void *, const char *, s32);
extern "C" u8 lbl_8055E208;

extern "C" void *fn_801284F8(u32, void *);
extern "C" void *fn_80131810(s32);
extern "C" void fn_80146BD4(u8 *, const s8 *, s32);
extern "C" void fn_80146C08(void *, s32);
extern "C" void fn_80146C1C(void **);
extern "C" void fn_80146824(void *);
extern "C" void *fn_80145FEC(void *, const char *, s32);
extern "C" void *fn_801460F8(void *, const char *, s32);
extern "C" void *fn_80146204(void *, const char *, s32);
extern "C" void *fn_80146310(void *, const char *, s32);
extern "C" void fn_8014647C(void *);
extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *, s32);
extern "C" {
__declspec(section ".sdata") extern char lbl_80559E48[];
}
extern "C" void *fn_80146490(void *);
extern "C" void fn_80145D8C(void *);

extern "C" f32 lbl_805615D0;
extern "C" s32 fn_801450A0(u32, u32, f32);
extern "C" void fn_80147DC0(void *, s32, s32, f32);
extern "C" void fn_801476D8(void *, s32, s32);
extern "C" s32 fn_80147C50(u32, u32, f32);

extern "C" void lbl_8032D214(void);
extern "C" {
__declspec(section ".data") extern void *lbl_8032D1E8;
}
extern "C" void *fn_80148294(const char *, void *);
extern "C" char lbl_8032D0EC[];
extern "C" char lbl_8032D0FC[];
extern "C" {
__declspec(section ".sdata") extern char lbl_80559E20[];
__declspec(section ".sdata") extern char lbl_80559E28[];
__declspec(section ".sdata") extern char lbl_80559E30[];
__declspec(section ".sdata") extern char lbl_80559E34[];
__declspec(section ".sdata") extern char lbl_80559E3C[];
}
extern "C" f32 lbl_8055E200;
extern "C" f32 lbl_8055E204;
extern "C" int stricmp(const char *, const char *);
extern "C" void fn_80148334(s32, s32, void *);
extern "C" void *lbl_8032D1D8;
extern "C" f32 fn_801451DC(s32);
extern "C" f32 fn_801452B4(f32);
extern "C" void fn_800104B0(s32, s32, s32, f32, f32, f32);
extern "C" void fn_80011278(s32, f32, f32, f32, f32);
extern "C" f32 lbl_805615D4;
extern "C" void fn_801470B0(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80148DFC(void *);
  extern "C" void fn_80148E6C(void *);
  extern "C" void fn_80148EDC(void *);
  extern "C" void fn_80235380();
  extern "C" void fn_80128668(void *);
  extern "C" void deleteThreads__6SystemFv(void *);

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
__declspec(section ".sdata") extern char lbl_80559E14[6];
void fn_802E30C8(const char *);
extern char lbl_8032D0D0[];
void fn_8000FF88(s32, s32, s32, f32, f32, f32);
extern char lbl_8032CF48[];
extern __declspec(section ".sdata") char lbl_80559DD0[];
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
#pragma scheduling invalid_target
extern "C" s32 fn_80144FB0(void *arg0, s32 arg1, s32 arg2, const char *arg3) {
    struct Entry { const char *text; u32 mask; };
    Entry *entry = (Entry *)arg3;
    char *dst = (char *)arg0;
    s32 zero = 0;
    const char *separator = (const char *)&lbl_80559DCC;
    const char *src;
    s32 remaining;
    char *cursor;
    *dst = zero;
    while (entry->text != 0) {
        if ((entry->mask & (u32)arg2) == entry->mask) {
            if ((s8)*dst != 0) {
                remaining = arg1;
                cursor = dst;
                while ((s8)*cursor != 0) {
                    --remaining;
                    ++cursor;
                }
                if (remaining > 0) {
                    src = separator;
                    while ((s8)(*cursor++ = *src++) != 0) {
                        if (--remaining <= 0) {
                            cursor[-1] = zero;
                            break;
                        }
                    }
                }
            }
            remaining = arg1;
            cursor = dst;
            while ((s8)*cursor != 0) {
                --remaining;
                ++cursor;
            }
            if (remaining > 0) {
                src = entry->text;
                while ((s8)(*cursor++ = *src++) != 0) {
                    if (--remaining <= 0) {
                        cursor[-1] = zero;
                        break;
                    }
                }
            }
        }
        ++entry;
    }
    return (s32)dst;
}
#pragma scheduling on
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
    struct Container {
        virtual void *v0(s32);
        virtual void *v1(s32);
    };
    struct Item {
        virtual const char *v0();
    };
    s32 count = 0;
    s32 index = 0;
    Item *item;
loop:
    item = (Item *)((Container *)arg0)->v1(index);
    if (item == 0)
        goto done;
    if (stricmp(item->v0(), arg1) == 0)
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

#pragma dont_inline on
extern "C" f32 fn_801452B4(f32 arg0) { f32 result = lbl_805615F0 - arg0; result = result + lbl_8055E204; return result; }
#pragma dont_inline reset

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
#pragma push
#pragma dont_inline on
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
#pragma dont_inline reset
#pragma pop

extern "C" f32 lbl_805615E0;
extern "C" s32 lbl_80559DE0;
extern "C" s32 lbl_80559DE4;
extern "C" s32 lbl_80559DE8;
extern "C" s32 lbl_80559DEC;
extern "C" s32 lbl_80559DF0;
extern "C" s32 lbl_80559DF4;
extern "C" __declspec(section ".sdata") char lbl_80559DFC[];
extern "C" void fn_80145438(void *arg0, void *arg1) {
    class V { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual f32 f7(const char *); };
    V *obj = (V *)arg1;
    fn_80145368(arg0, arg1);
    *(f32 *)((u8 *)arg0 + 0x10) = obj->f7((const char *)&lbl_80559DE0);
    *(f32 *)((u8 *)arg0 + 0x14) = obj->f7((const char *)&lbl_80559DE4);
    *(f32 *)((u8 *)arg0 + 0x18) = fn_801452E0(arg1, (const char *)&lbl_80559DE8);
    *(f32 *)((u8 *)arg0 + 0x20) = fn_801452E0(arg1, (const char *)&lbl_80559DEC);
    *(f32 *)((u8 *)arg0 + 0x1C) = fn_801452E0(arg1, (const char *)&lbl_80559DF0);
    *(f32 *)((u8 *)arg0 + 0x24) = fn_801452E0(arg1, (const char *)&lbl_80559DF4);
}

#pragma push
#pragma dont_inline on
extern "C" s32 fn_801454E8(void *arg0, const char *arg1) {
    class V { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual const char *f5(); };
    extern char lbl_80559DF8[];
    extern int sscanf(const char *, const char *, ...);
    s32 result;
    const char *text = ((V *)arg0)->f5();
    if (sscanf(text, lbl_80559DF8, &result) != 1)
        result = -1;
    return result;
}
#pragma dont_inline reset
#pragma pop

extern "C" void fn_80145538(void *arg0, void *arg1) {
    extern void fn_80145368(void *, void *);
    extern s32 fn_801454E8(void *, const char *);
    class V {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual f32 f7(const char *);
    };
    V *obj = (V *)arg1;
    fn_80145368(arg0, arg1);
    *(f32 *)((u8 *)arg0 + 0x10) = obj->f7((const char *)&lbl_80559DE0);
    *(f32 *)((u8 *)arg0 + 0x14) = obj->f7((const char *)&lbl_80559DE4);
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

extern "C" void fn_80145670(void *arg0, void *arg1) {
    class V {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 get(const char *);
    };
    V *obj = (V *)arg1;
    ((s32 *)arg0)[0] = obj->get((const char *)&lbl_80559DD0);
    ((s32 *)arg0)[1] = obj->get((const char *)&lbl_8032CF48);
    ((s32 *)arg0)[2] = fn_8023512C();
}

extern "C" s32 fn_8013126C(void *, s32);
extern "C" s32 fn_80144FB0(void *, s32, s32, const char *);
#pragma scheduling invalid_target
extern "C" void fn_801456E8(void *arg0, s32 arg1) {
    struct Entry { s32 unk0; f32 unk4; f32 unk8; s32 unkC; f32 unk10; s32 unk14; s32 unk18; s32 unk1C; };
    struct List { Entry *entries; s32 count; };
    char *base = lbl_8032CEC8;
    List *list = (List *)arg0;
    char buffer[0x40];
    char result[0x138];
    fn_802E3AD0(arg1, base + 0x90);
    fn_802E3AD0(arg1, base + 0xA0);
    s32 value;
    Entry *entry;
    s32 offset;
    s32 i;
    i = 0;
    offset = 0;
    while (i < list->count) {
        entry = (Entry *)((u8 *)list->entries + offset);
        value = fn_8013126C(result, entry->unk1C);
        s32 formatted = fn_80144FB0(buffer, 0x40, entry->unk14, base + 0x10);
        fn_802E3AD0(arg1, base + 0xD4, entry->unk4, entry->unk8,
                    entry->unkC, entry->unk18, formatted, entry->unk0, value, entry->unk10);
        offset += 0x20;
        i++;
    }
    fn_802E3AD0(arg1, lbl_80559E14);
}
#pragma scheduling on
extern "C" void fn_801457D0(void *arg0, s32 arg1) {
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
#pragma scheduling on
extern "C" void fn_8014589C(void *arg0, s32 arg1) {
    char *base = lbl_8032CEC8;
    fn_802E3AD0(arg1, base + 0x170);
    fn_802E3AD0(arg1, base + 0x180);
    s32 offset;
    s32 i;
    i = 0;
    offset = 0;
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
#pragma use_lmw_stmw off
extern "C" void fn_8014595C(void *arg0, const char *arg1) {
    char *base = lbl_8032CEC8;
    fn_802E3AD0((s32)arg1, base + 0x1D0);
    fn_802E3AD0((s32)arg1, base + 0x1E4);
    s32 offset;
    s32 i;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        void *entry = (void *)(*(u8 **)arg0 + offset);
        fn_802E3AD0((s32)arg1, base + 0x1FC,
            *(s32 *)((u8 *)entry + 4), *(s32 *)entry);
        offset += 0xC;
        i++;
    }
    fn_802E3AD0((s32)arg1, lbl_80559E14);
}
#pragma use_lmw_stmw reset
#pragma dont_inline on
extern "C" f32 fn_80145A08(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    f32 span = farg3 - farg2;
    f32 den = farg1 - farg0;
    f32 num = farg4 - farg0;
    return farg2 + (num / den) * span;
}
#pragma dont_inline reset

extern "C" s32 fn_802C9C38(void);
extern "C" s32 fn_802C9C48(void);
extern "C" f32 fn_80145A08(f32, f32, f32, f32, f32);
struct FloatPair80145A24 { f32 first; f32 second; };
extern "C" f32 lbl_805615F4;
extern "C" f32 lbl_805615F8;
extern "C" f32 lbl_805615FC;
extern "C" f64 lbl_80561600;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" FloatPair80145A24 fn_80145A24(void *arg0) {
    f32 out0 = fn_80145A08(lbl_805615D4, (f32)fn_802C9C48(),
                           lbl_805615D4, lbl_805615F4,
                           (f32)*(s32 *)((u8 *)arg0 + 4));

    f32 scaled = lbl_805615F8 * (f32)fn_802C9C48();
    f32 correction = scaled * lbl_805615D0;
    u32 converted = (u32)fn_802C9C38();
    s32 half = (s32)((converted >> 31) + converted) >> 1;
    f32 base = (f32)half - correction;

    f32 out1 = fn_80145A08(base,
                           base + lbl_805615F8 * (f32)fn_802C9C48(),
                           lbl_805615D4, lbl_805615FC,
                           (f32)*(s32 *)((u8 *)arg0 + 8));
    FloatPair80145A24 result;
    result.first = out0;
    result.second = out1;
    return result;
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset
#pragma processor reset

extern "C" f32 lbl_80561608;
extern "C" void fn_8001027C(s32, s32, void *, u32, f32, f32, f32);
extern "C" f32 fn_801452A0(s32, f32);
extern "C" void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern "C" s32 lbl_80559E1C;
extern "C" void fn_80145B50(void *arg0, s32 arg1) {
    f32 value = (f32)arg1;
    f32 multiplier = lbl_80561608;
    *(f32 *)((u8 *)arg0 + 4) = lbl_805615D4;
    *(f32 *)((u8 *)arg0 + 0xC) = multiplier;
    *(f32 *)((u8 *)arg0 + 8) = multiplier;
    *(f32 *)arg0 = multiplier * value;
}

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void fn_80145B94(void *arg0, u32 arg1) {
    f32 scale = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 input = *(f32 *)((u8 *)arg0 + 4);
    s32 id = *(s32 *)((u8 *)arg0 + 0xC);
    f32 value = ((f32 (*)(s32, f32))fn_801451DC)(id, input);
    f32 last = *(f32 *)((u8 *)arg0 + 0x10);
    s32 b = *(s32 *)((u8 *)arg0 + 0x14);
    s32 a = *(s32 *)((u8 *)arg0 + 0x18);
    ((void (*)(s32, s32, s32, ...))fn_8000FF88)(a, b, (s32)arg1, last, value, scale);
}

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling on
extern "C" void fn_80145C08(void *arg0, const char *arg1) {
    f32 scale_input = *(f32 *)((u8 *)arg0 + 8);
    f32 scale = fn_801452B4(scale_input);
    f32 input = *(f32 *)((u8 *)arg0 + 4);
    s32 id = *(s32 *)((u8 *)arg0 + 0xC);
    f32 value = ((f32 (*)(s32, f32))fn_801451DC)(id, input);
    f32 last = *(f32 *)((u8 *)arg0 + 0x10);
    s32 b = *(s32 *)((u8 *)arg0 + 0x14);
    s32 a = *(s32 *)((u8 *)arg0 + 0x18);
    ((void (*)(s32, s32, s32, ...))fn_800104B0)(a, b, (s32)arg1, last, value, scale);
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset

#pragma scheduling on
#pragma pop
#pragma dont_inline reset

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void fn_80145C7C(void * __restrict arg0, u32 arg1) {
    f32 scale = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 input = *(f32 *)((u8 *)arg0 + 4);
    s32 id = *(s32 *)((u8 *)arg0 + 0xC);
    f32 value = ((f32 (*)(s32, f32))fn_801451DC)(id, input);
    f32 last = *(f32 *)((u8 *)arg0 + 0x10);
    s32 b = *(s32 *)((u8 *)arg0 + 0x14);
    s32 a = *(s32 *)((u8 *)arg0 + 0x18);
    ((void (*)(s32, s32, s32, ...))fn_8001027C)(a, b, (s32)&lbl_80559E1C, arg1, last, value, scale);
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset

#pragma processor 750
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_80145CF4(void *arg0, void *arg1, u32 arg2) {
    f32 input10 = *(f32 *)((u8 *)arg0 + 0x10);
    f32 temp_f31 = fn_801452A0(*(s32 *)((u8 *)arg0 + 0xC), input10);
    f32 temp_f30 = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 input4 = *(f32 *)((u8 *)arg0 + 4);
    s32 mode = *(s32 *)((u8 *)arg0 + 0xC);
    f32 value = ((f32 (*)(s32, f32))fn_801451DC)(mode, input4);
    ((void (*)(s32, s32, f32, f32, f32, f32, f32, s32))fn_802354A0)(
        (s32)arg1, arg2, value, temp_f30, lbl_805615D4,
        temp_f31, *(f32 *)((u8 *)arg0 + 0x14),
        *(s32 *)((u8 *)arg0 + 0x18));
}
#pragma scheduling on
#pragma dont_inline reset
#pragma processor reset
extern "C" void fn_80145D8C(void *arg0) {
    volatile Queue80145D8C *queue = &lbl_8042FBC0;
    s32 count = queue->count;
    if (count + 1 <= queue->capacity) {
        register s32 i = queue->count;
        void **data = lbl_8042FBC0.data;
        queue->count = i + 1;
        data[i] = arg0;
        return;
    }
    ((void (*)(const char *, ...))fn_802E30C8)(lbl_8032D0D0);
}

extern "C" void fn_80145DD8(void *arg0) {
    s32 i;
    void **item;
    s32 count;

    item = lbl_8042FBC0.data;
    count = lbl_8042FBC0.count;
    i = 0;
    for (; i < count; ) {
        if (*item != arg0) {
            item++;
            i++;
            continue;
        }
        goto found;
    }
    i = -1;
found:
    if ((i >= 0) && (i >= 0) && (i < lbl_8042FBC0.count)) {
        s32 last = lbl_8042FBC0.count - 1;
        if (i != last) {
            lbl_8042FBC0.data[i] = lbl_8042FBC0.data[last];
        }
        lbl_8042FBC0.count = last;
    }
}

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma small_data off
extern "C" void fn_80145E70(s32 arg0) {
    struct Config { virtual void *getObject(const char *); virtual void a1(); virtual s32 has(const char *); };
    struct Properties { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual s32 set(const char *, s32); };
    u8 *object = (u8 *)fn_801284F8(0x50, &lbl_8032D0EC);
    if (object == 0) return;
    fn_80146C1C((void **)object);
    *(void **)object = &lbl_8032D1E8;
    fn_80146C08(object + 0x40, (s32)object);
    *(s32 *)(object + 0x2C) = 0;
    {
        u8 *dst = object + 5;
        const s8 *src = (const s8 *)arg0;
        *(s32 *)(object + 0x30) = 0;
        *(s32 *)(object + 0x34) = 0;
        *(s32 *)(object + 0x3C) = 0;
        *(s32 *)(object + 0x48) = 0;
        *(s32 *)(object + 0x4C) = 0;
        object[4] = 0;
        ((void (*)(u8 *, const s8 *, s32, s32))fn_80146BD4)(dst, src, 0x20, 0);
    }
    *(void **)(object + 0x28) = fn_80131810(arg0);
    if (*(void **)(object + 0x28) != 0) {
        lbl_8055E208 = 1;
        if (((Config *)*(void **)(object + 0x28))->has(lbl_80559E20) != 0) {
            void *properties = ((Config *)*(void **)(object + 0x28))->getObject(lbl_80559E20);
            register s32 transformed = ((Properties *)properties)->set(lbl_80559E28, 1) ^ 1;
            register s32 shifted = transformed >> 1;
            register s32 low = transformed & 1;
            transformed = shifted - low;
            lbl_8055E208 = (s8)((u32)transformed >> 31);
        }
        *(s32 *)(object + 0x2C) = (s32)((void *(*)(void *, const char *))fn_80145FEC)(*(void **)(object + 0x28), lbl_80559E30);
        *(s32 *)(object + 0x30) = (s32)((void *(*)(void *, const char *))fn_801460F8)(*(void **)(object + 0x28), lbl_80559E34);
        *(s32 *)(object + 0x34) = (s32)((void *(*)(void *, const char *))fn_80146204)(*(void **)(object + 0x28), lbl_80559E3C);
        *(s32 *)(object + 0x3C) = (s32)((void *(*)(void *, const char *))fn_80146310)(*(void **)(object + 0x28), lbl_8032D0FC);
        fn_80146824(object);
    }
    fn_80145D8C(object);
    fn_80146490(object);
}
#pragma small_data on
#pragma scheduling on
#pragma pop
#pragma dont_inline reset
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

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_80146310(void *arg0, const char *arg1, s32 arg2) {
    struct Result {
        void *data;
        s32 count;
        s32 size;
        void *end;
    };
    class Collection {
    public:
        virtual void a();
        virtual void *get(s32);
    };
    class Item {
    public:
        virtual const char *name();
    };

    Result *result;
    s32 size = fn_80145140(arg0, arg1);
    result = (Result *)fn_801284F8(0x10, lbl_8032D108);
    if (result != 0) {
        void *arena = fn_8012850C(size * 0xC + 0x10, lbl_80559E48);
        result->data = ((void *(*)(void *, void *, void *, s32, s32))fn_8002F37C)(
            arena, (void *)fn_8014647C,
            (void *)__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C, 0xC, size);
        result->size = size;
        result->count = 0;
        result->end = result->data;
    }

    s32 i = 0;
    while (1) {
        void *item = ((Collection *)arg0)->get(i);
        if (item == 0)
            break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, arg1) == 0) {
            s32 count = result->count;
            void *data = result->data;
            s32 offset = count * 0xC;
            result->count = count + 1;
            fn_80145670((char *)data + offset, item);
        }
        i++;
    }
    return result;
}
#pragma dont_inline reset
#pragma pop

extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        if (*(void**)((u8*)arg0 + sizeof(void*) * 2)) {
            fn_80235380();
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8014647C(void *);
extern "C" void fn_8014647C(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[2] = 0;
}

extern "C" void fn_80128668(void *);
extern "C" void fn_80128670(s32);
extern "C" void fn_80131818(void * = 0);
extern "C" void fn_80145DD8(void *);
extern "C" void fn_80146584(void *);
extern "C" void fn_801465C8(void *);
extern "C" void fn_80146638(void *);
extern "C" void fn_801466B4(void *);
extern "C" void fn_80146730(void *);
extern "C" void fn_801467AC(void *);

extern "C" void *fn_80146490(void *arg0) {
    struct Obj {
        virtual void *v0(s32);
    };
    if (arg0 != NULL) {
        if (((s32 *)arg0)[10] == 0) {
            if (arg0) {
                ((Obj *)arg0)->v0(1);
            }
            return NULL;
        }
    }
    return arg0;
}

extern "C" void *fn_801464DC(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        void *p;
        *(void **)arg0 = &lbl_8032D1E8;
        fn_80145DD8(arg0);
        p = *(void **)((u8 *)arg0 + 0x28);
        if (p != NULL) {
            fn_80131818(p);
            *(void **)((u8 *)arg0 + 0x28) = NULL;
        }
        fn_80146584((u8 *)arg0 + 0x4C);
        fn_801465C8((u8 *)arg0 + 0x48);
        fn_80146638((u8 *)arg0 + 0x2C);
        fn_801466B4((u8 *)arg0 + 0x30);
        fn_80146730((u8 *)arg0 + 0x34);
        fn_801467AC((u8 *)arg0 + 0x3C);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80146584(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}
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

extern "C" char lbl_8032D114[];
extern "C" char lbl_8032D124[];
extern "C" char lbl_8055E20C[];
extern "C" char lbl_8055E210[];
extern "C" char lbl_8055E214[];
extern "C" char lbl_8055E218[];
extern "C" char lbl_8055E220[];
extern "C" f32 lbl_8056160C;
extern "C" f32 lbl_80561610;
extern "C" char lbl_8032D114[];
extern "C" char lbl_8032D124[];
extern "C" __declspec(section ".sdata") char lbl_80559E48[];
extern "C" __declspec(section ".sdata") char lbl_8055E20C[];
extern "C" __declspec(section ".sdata") char lbl_8055E210[];
extern "C" __declspec(section ".sdata") char lbl_8055E214[];
extern "C" __declspec(section ".sdata") char lbl_8055E218[];
extern "C" __declspec(section ".sdata") char lbl_8055E220[];
extern "C" __declspec(section ".sdata") f32 lbl_8056160C;
extern "C" __declspec(section ".sdata") f32 lbl_80561610;
extern "C" __declspec(section ".sdata") f32 lbl_805615D4;
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_80146824(void *arg0) {
    struct Block { s32 base; s32 count; };
    struct Record { f32 f0, f4, f8, fC; s32 value; char *label; };
    struct Data { Record *records; s32 count; volatile s32 capacity; Record *recordsAgain; };
    struct Proxy { s32 a, b; u8 pad8[4]; Data *data; };
    struct Owner {
        u8 pad[0x2C];
        Block *block2C;
        Block *block30;
        Block *block34;
        u8 pad38[0x10];
        Data *data;
        Proxy *proxy;
    };
    typedef void *(*AllocFn)(s32, const char *, s32, s32, s32, s32);
    Owner *owner = (Owner *)arg0;
    register Block *b2C = owner->block2C;
    register Block *b34 = owner->block34;
    register Block *b30 = owner->block30;
    register s32 n2C = b2C->count;
    register s32 n34 = b34->count;
    register s32 n30 = b30->count;
    register s32 size2C = n2C * 2;
    register s32 size30 = n30 * 4 - n30;
    register s32 size34 = n34 * 4 - n34;
    Data *data = (Data *)((AllocFn)fn_801284F8)(0x10, lbl_8032D114,
        n34, n30 * 4, n30, n2C);
    if (data != 0) {
        s32 total = size34 + size2C;
        total = total + size30;
        total = total + 1;
        data->records = (Record *)fn_8012850C(total * 0x18, lbl_80559E48);
        data->capacity = total;
        data->count = 0;
        data->recordsAgain = data->records;
        owner->data = data;
    }
    Proxy *proxy = (Proxy *)fn_801284F8(0x18, lbl_8032D124);
    if (proxy != 0) {
        Data *parent = owner->data;
        proxy->b = 0;
        proxy->a = 0;
        proxy->data = parent;
        owner->proxy = proxy;
    }
    for (s32 i = 0, offset = 0; i < owner->block2C->count; i++, offset += 0x28) {
        Record *r = (Record *)((Data *)owner->proxy->data)->records +
            ((Data *)owner->proxy->data)->count++;
        fn_80145B50(r, 0);
        r->value = owner->block2C->base + offset;
        r->label = lbl_8055E20C;
        r = (Record *)((Data *)owner->proxy->data)->records +
            ((Data *)owner->proxy->data)->count++;
        fn_80145B50(r, 1);
        r->value = owner->block2C->base + offset;
        r->label = lbl_8055E210;
    }
    for (s32 i = 0, offset = 0; i < owner->block30->count; i++, offset += 0x20) {
        Record *r = (Record *)((Data *)owner->proxy->data)->records +
            ((Data *)owner->proxy->data)->count++;
        fn_80145B50(r, 0);
        r->value = owner->block30->base + offset;
        r->label = lbl_8055E20C;
        r = (Record *)((Data *)owner->proxy->data)->records +
            ((Data *)owner->proxy->data)->count++;
        fn_80145B50(r, 1);
        r->value = owner->block30->base + offset;
        r->label = lbl_8055E214;
        r = (Record *)((Data *)owner->proxy->data)->records +
            ((Data *)owner->proxy->data)->count++;
        fn_80145B50(r, 2);
        r->value = owner->block30->base + offset;
        r->label = lbl_8055E218;
    }
    for (s32 i = 0, offset = 0; i < owner->block34->count; i++, offset += 0x1C) {
        Record *r = (Record *)((Data *)owner->proxy->data)->records +
            ((Data *)owner->proxy->data)->count++;
        fn_80145B50(r, 0);
        r->value = owner->block34->base + offset;
        r->label = lbl_8055E20C;
        r = (Record *)((Data *)owner->proxy->data)->records +
            ((Data *)owner->proxy->data)->count++;
        fn_80145B50(r, 1);
        r->value = owner->block34->base + offset;
        r->label = lbl_8055E210;
        r = (Record *)((Data *)owner->proxy->data)->records +
            ((Data *)owner->proxy->data)->count++;
        fn_80145B50(r, 2);
        r->value = owner->block34->base + offset;
        r->label = lbl_8055E220;
    }
    register f32 third;
    register f32 second;
    register f32 first;
    char *label = (char *)arg0 + 0x40;
    s32 zero = 0;
    first = lbl_805615D4;
    Data *queue = owner->proxy->data;
    second = lbl_8056160C;
    Record *records = queue->records;
    s32 count = queue->count;
    s32 byteOffset = count * 0x18;
    third = lbl_80561610;
    queue->count = count + 1;
    Record *last = (Record *)((u8 *)records + byteOffset);
    last->label = label;
    last->value = zero;
    last->f0 = first;
    last->f4 = first;
    last->f8 = second;
    last->fC = third;
}
#pragma pop
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

extern "C" void fn_80146C08(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    *(void **)arg0 = (void *)&lbl_8032D214;
}

extern void lbl_8032D260(void);
extern "C" void fn_80146C1C(void **arg0) {
    *arg0 = (void *)&lbl_8032D260;
}

extern "C" char lbl_8032CEC8[];
extern "C" char lbl_80559E30[];
extern "C" char lbl_80559E34[];
extern "C" __declspec(section ".sdata") char lbl_80559E50[];
extern "C" __declspec(section ".sdata") char lbl_80559E58[];
extern "C" __declspec(section ".sdata") char lbl_80559E60[];
extern "C" __declspec(section ".data") void *lbl_8032D1D8;
extern "C" __declspec(section ".sdata") char lbl_80559DFC[];
#pragma push
#pragma scheduling invalid_target
#pragma small_data on
#pragma use_lmw_stmw off
extern "C" void *fn_80146C2C(s32 arg0, void *arg1, s32 arg2) {
    class Collection {
    public:
        virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3();
        virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7();
        virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11();
        virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15();
        virtual void c16(); virtual void c17(); virtual void c18(); virtual void c19();
        virtual void c20(); virtual void c21();
        virtual void *get(s32);
    };
    class Item {
    public:
        virtual const char *name();
        virtual void i3(); virtual void i4(); virtual void *get(const char *, s32, void *);
        virtual void i6(); virtual void *get2(const char *);
    };
    class ItemShort {
    public:
        virtual const char *name();
        virtual void i3(); virtual void i4(); virtual void *get(const char *);
        virtual void i6(); virtual void i7();
    };
    struct Result {
        void *data;
        s32 count;
        s32 size;
        void *end;
    };
    extern s32 fn_801454E8(void *, const char *);
    register const char *base = lbl_8032CEC8;
    u8 *object = (u8 *)fn_801284F8(0x18, (void *)(base + 0x26C));
    if (object != 0) {
    *(void **)object = (void *)&lbl_8032D1D8;
    object[4] = 0;
    *(s32 *)(object + 8) = arg0;
    *(void **)(object + 0xC) = 0;
    *(void **)(object + 0x10) = 0;
    *(void **)(object + 0x14) = 0;

    register const char *search0 = base + 0x280;
    {
    register s32 count = 0;
    register s32 i = 0;
    while (1) {
        void *item = ((Collection *)arg1)->get(i);
        if (item == 0)
            break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, search0) == 0)
            count++;
        i++;
    }

    register Result *result0 = (Result *)fn_801284F8(0x10, (void *)(base + 0x28C));
    if (result0 != 0) {
        void *data = fn_8012850C(count * 8, lbl_80559E48);
        result0->data = data;
        result0->size = count;
        result0->count = 0;
        result0->end = data;
    }
    i = 0;
    while (1) {
        void *item = ((Collection *)arg1)->get(i);
        if (item == 0)
            break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, search0) == 0) {
            s32 index = result0->count;
            void **data = (void **)result0->data;
            void **record = (void **)((u8 *)data + index * 8);
            result0->count = index + 1;
            record[0] = ((Item *)item)->get(lbl_80559E50, index, data);
            record[1] = ((ItemShort *)item)->get(lbl_80559E34);
        }
        i++;
    }
    *(void **)(object + 0xC) = result0;
    }

    {
    const char *name1 = base + 0x29C;
    register s32 count = 0;
    register s32 i = 0;
    while (1) {
        void *item = ((Collection *)arg1)->get(i);
        if (item == 0)
            break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, name1) == 0)
            count++;
        i++;
    }

    register Result *result1 = (Result *)fn_801284F8(0x10, (void *)(base + 0x28C));
    if (result1 != 0) {
        void *data = fn_8012850C(count * 12, lbl_80559E48);
        result1->data = data;
        result1->size = count;
        result1->count = 0;
        result1->end = data;
    }
    i = 0;
    while (1) {
        void *item = ((Collection *)arg1)->get(i);
        if (item == 0)
            break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, name1) == 0) {
            s32 index = result1->count;
            void **data = (void **)result1->data;
            void **record = (void **)((u8 *)data + index * 12);
            result1->count = index + 1;
            record[0] = ((Item *)item)->get(lbl_80559E50, index, data);
            record[1] = ((ItemShort *)item)->get(lbl_80559E30);
            record[2] = ((Item *)item)->get2(lbl_80559E58);
        }
        i++;
    }
    *(void **)(object + 0x10) = result1;
    }

    {
    const char *name2 = lbl_80559E60;
    register s32 count = 0;
    register s32 i = 0;
    while (1) {
        void *item = ((Collection *)arg1)->get(i);
        if (item == 0)
            break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, name2) == 0)
            count++;
        i++;
    }

    register Result *result2 = (Result *)fn_801284F8(0x10, (void *)(base + 0x28C));
    if (result2 != 0) {
        void *data = fn_8012850C(count * 12, lbl_80559E48);
        result2->data = data;
        result2->size = count;
        result2->count = 0;
        result2->end = data;
    }
    i = 0;
    while (1) {
        void *item = ((Collection *)arg1)->get(i);
        if (item == 0)
            break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, name2) == 0) {
            s32 index = result2->count;
            void **data = (void **)result2->data;
            void **record = (void **)((u8 *)data + index * 12);
            result2->count = index + 1;
            record[0] = ((Item *)item)->get(lbl_80559E50, index, data);
            record[1] = ((ItemShort *)item)->get(lbl_80559E30);
            record[2] = (void *)fn_801454E8(item, lbl_80559DFC);
        }
        i++;
    }
    *(void **)(object + 0x14) = result2;
    }
    }
    return object;
}
#pragma pop
extern "C" void fn_8002F6AC(s32, void *);
extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *, s32);
extern "C" s32 fn_80147070(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

extern "C" void fn_802C8BD0(s32);
extern "C" s32 fn_802C8DBC(s32);
extern "C" void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
extern "C" void fn_802C8E48(void);
extern "C" void fn_802C8D74(void);
#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void fn_801470B0(s32 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5, f32 farg6, f32 farg7) {
    f32 temp;
    fn_802C8BD0(arg1);
    if (fn_802C8DBC(4) != 0) {
        temp = fn_801452B4(farg1);
        fn_802C8E00(arg0, 0, ((f32 (*)(s32, f32))fn_801451DC)(arg2, farg0), temp, lbl_805615D4, farg4, farg5);
        temp = fn_801452B4(farg1);
        fn_802C8E00(arg0, 0, ((f32 (*)(s32, f32))fn_801451DC)(arg2, farg0 + farg2), temp, lbl_805615D4, farg6, farg5);
        temp = fn_801452B4(farg1 + farg3);
        fn_802C8E00(arg0, 1, ((f32 (*)(s32, f32))fn_801451DC)(arg2, farg0), temp, lbl_805615D4, farg4, farg7);
        temp = fn_801452B4(farg1 + farg3);
        fn_802C8E00(arg0, 1, ((f32 (*)(s32, f32))fn_801451DC)(arg2, farg0 + farg2), temp, lbl_805615D4, farg6, farg7);
        fn_802C8E48();
    }
    fn_802C8D74();
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset
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
extern "C" void fn_801475D0(void *arg0, s32 arg1, const char *format, ...) {
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
        fn_80145C7C(result, (u32)buffer);
    }
}

extern "C" void fn_801476C4(void *arg0) {
    if (arg0 != 0)
        fn_80145B94(arg0, *(u32 *)((u8 *)arg0 + 0x1c));
}

void fn_801476D8(void *arg0, s32 arg1, s32 arg2) {
    extern void fn_802C8BD0(s32);
    extern s32 fn_802C8DBC(s32);
    extern void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
    extern void fn_802C8E48(void);
    extern void fn_802C8D74(void);
    extern f32 fn_801452A0(s32, f32);
    f32 x, y, angle, tx;
    s32 mode;
    if (arg0 != 0) {
        x = *(f32 *)((u8 *)arg0 + 4);
        y = *(f32 *)((u8 *)arg0 + 8);
        mode = *(s32 *)((u8 *)arg0 + 0xC);
        fn_802C8BD0(arg2);
        if (fn_802C8DBC(4) != 0) {
            angle = fn_801452B4(y);
            tx = ((f32 (*)(s32, f32))fn_801451DC)(mode, x);
            fn_802C8E00(arg1, 0, tx, angle, lbl_805615D4, *(f32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x1C));
            angle = fn_801452B4(y);
            tx = fn_801452A0(mode, *(f32 *)((u8 *)arg0 + 0x10));
            tx += ((f32 (*)(s32, f32))fn_801451DC)(mode, x);
            fn_802C8E00(arg1, 0, tx, angle, lbl_805615D4, *(f32 *)((u8 *)arg0 + 0x20), *(f32 *)((u8 *)arg0 + 0x1C));
            angle = fn_801452B4(y + *(f32 *)((u8 *)arg0 + 0x14));
            tx = ((f32 (*)(s32, f32))fn_801451DC)(mode, x);
            fn_802C8E00(arg1, 1, tx, angle, lbl_805615D4, *(f32 *)((u8 *)arg0 + 0x18), *(f32 *)((u8 *)arg0 + 0x24));
            angle = fn_801452B4(y + *(f32 *)((u8 *)arg0 + 0x14));
            tx = fn_801452A0(mode, *(f32 *)((u8 *)arg0 + 0x10));
            tx += ((f32 (*)(s32, f32))fn_801451DC)(mode, x);
            fn_802C8E00(arg1, 1, tx, angle, lbl_805615D4, *(f32 *)((u8 *)arg0 + 0x20), *(f32 *)((u8 *)arg0 + 0x24));
            fn_802C8E48();
        }
        fn_802C8D74();
    }
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

#pragma push
#pragma dont_inline on
extern "C" void fn_801478E0(void *arg0, s32 unused, s32 arg1, s32 arg2) {
    class V {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 f3();
    };
    s32 result = ((V *)arg0)->f3();
    if (result != 0 && arg1 != 0)
        fn_80145CF4((void *)result, (void *)arg1, (u32)arg2);
}
#pragma pop
#pragma dont_inline on
#pragma push
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
    s32 temp[12];
    ((void (*)(void *, s32, s32))fn_80147DC0)((u32 *)temp, arg0, arg1);
    fn_801476D8((u32 *)temp, fn_80147C50(arg2, arg3, arg5), arg4);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_80147C50(u32 arg0, u32 arg1, f32 arg2) {
    s32 a = fn_801450A0(arg0 & 0xFF, arg1 & 0xFF, arg2);
    s32 b = fn_801450A0((arg0 >> 8) & 0xFF, (arg1 >> 8) & 0xFF, arg2);
    s32 c = fn_801450A0((arg0 >> 16) & 0xFF, (arg1 >> 16) & 0xFF, arg2);
    s32 d = fn_801450A0(arg0 >> 24, arg1 >> 24, arg2);
    s32 lo = (a & 0xFF) | ((b & 0xFF) << 8);
    s32 hi = ((d & 0xFF) << 24) | ((c & 0xFF) << 16);
    return lo | hi;
}
#pragma scheduling invalid_target
extern "C" void fn_80147CEC(void *arg0, s32 arg1, s32 arg2, f64 arg3) {
    union Pair { struct { f32 x; f32 y; } f; f64 raw; };
    u8 *dst = (u8 *)arg0;
    u8 *src = (u8 *)arg1;
    u8 *other = (u8 *)arg2;
    f32 zSource = *(f32 *)(src + 0x10);
    f32 zOther = *(f32 *)(other + 0x10);
    f32 yOther = *(f32 *)(other + 8);
    f32 ySource = *(f32 *)(src + 8);
    f32 xOther = *(f32 *)(other + 4);
    f32 xSource = *(f32 *)(src + 4);
    yOther = yOther - ySource;
    xOther = xOther - xSource;
    zOther = zOther - zSource;
    f32 factor = (f32)arg3;
    f32 y = ySource + factor * yOther;
    f32 x = xSource + factor * xOther;
    f32 z = zSource + factor * zOther;
    Pair second;
    Pair first;
    first.f.y = y;
    first.f.x = x;
    second.raw = first.raw;
    u32 w1c = *(u32 *)(src + 0x1C);
    u32 w18 = *(u32 *)(src + 0x18);
    u32 w14 = *(u32 *)(src + 0x14);
    u32 wc = *(u32 *)(src + 0xC);
    u32 w0 = *(u32 *)(src + 0);
    u32 w8 = *(u32 *)(src + 8);
    u32 w4 = *(u32 *)(src + 4);
    volatile u32 *d = (volatile u32 *)dst;
    *(volatile f32 *)(dst + 0x10) = zSource;
    d[1] = w4; d[2] = w8; d[0] = w0; d[3] = wc;
    d[5] = w14; d[6] = w18; d[7] = w1c;
    *(volatile f32 *)(dst + 4) = second.f.x;
    *(volatile f32 *)(dst + 8) = second.f.y;
    *(volatile f32 *)(dst + 0x10) = z;
    d[6] = fn_80147C50(w18, *(u32 *)(other + 0x18), factor);
}
#pragma push
#pragma scheduling on
extern "C" void fn_80147DC0(void *dst, s32 srcArg, s32 endArg, f32 t) {
    struct State { u32 m0; f32 m4; f32 m8; u32 mC; f32 m10; f32 m14; f32 m18; f32 m1C; f32 m20; f32 m24; };
    union Pair { struct { f32 x; f32 y; } f; f64 raw; };
    volatile State *src = (volatile State *)srcArg;
    volatile State *end = (volatile State *)endArg;
    f32 end4, src4, end8, src8, diff8, src18, diff4, src10, prod8, src1C;
    f32 prod4, out8, src20, end20, out4, diff20, end18, end1C, diff18;
    f32 end10, diff1C, src14, diff10, prod18, prod20, prod1C, prod10;
    f32 out20, end24, end14, src24, diff24, out18, diff14, out1C;
    f32 prod24, prod14, out10, out24, out14;
    u32 w4, w0, wC, w8;
    end8 = end->m8;
    src8 = src->m8;
    end4 = end->m4;
    src4 = src->m4;
    diff8 = end8 - src8;
    src18 = src->m18;
    diff4 = end4 - src4;
    src10 = src->m10;
    prod8 = t * diff8;
    src1C = src->m1C;
    prod4 = t * diff4;
    out8 = src8 + prod8;
    src20 = src->m20;
    end20 = end->m20;
    out4 = src4 + prod4;
    diff20 = end20 - src20;
    end18 = end->m18;
    end1C = end->m1C;
    diff18 = end18 - src18;
    end10 = end->m10;
    diff1C = end1C - src1C;
    src14 = src->m14;
    diff10 = end10 - src10;
    prod18 = t * diff18;
    w4 = *(u32 *)((u8 *)srcArg + 4);
    prod20 = t * diff20;
    w0 = *(u32 *)((u8 *)srcArg + 0);
    prod1C = t * diff1C;
    prod10 = t * diff10;
    wC = *(u32 *)((u8 *)srcArg + 0xC);
    out20 = src20 + prod20;
    end24 = end->m24;
    end14 = end->m14;
    src24 = src->m24;
    diff24 = end24 - src24;
    w8 = *(u32 *)((u8 *)srcArg + 8);
    out18 = src18 + prod18;
    diff14 = end14 - src14;
    out1C = src1C + prod1C;
    prod24 = t * diff24;
    prod14 = t * diff14;
    out10 = src10 + prod10;
    out24 = src24 + prod24;
    out14 = src14 + prod14;
    Pair first;
    Pair second;
    first.f.x = out4;
    first.f.y = out8;
    second.raw = first.raw;
    volatile State *d = (volatile State *)dst;
    d->m18 = src18;
    d->m1C = src1C;
    d->m10 = src10;
    *(volatile u32 *)((u8 *)dst + 4) = w4;
    *(volatile u32 *)((u8 *)dst + 8) = w8;
    *(volatile u32 *)((u8 *)dst + 0) = w0;
    *(volatile u32 *)((u8 *)dst + 0xC) = wC;
    d->m4 = second.f.x;
    d->m8 = second.f.y;
    d->m18 = out18;
    d->m20 = out20;
    d->m1C = out1C;
    d->m24 = out24;
    d->m10 = out10;
    d->m14 = out14;
}
#pragma pop

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

extern "C" void fn_80011630(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
#pragma dont_inline fn_801452B4
extern "C" void fn_80147F30(s32 arg0, s32 arg1, s32 arg2,
                            f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                            f32 farg4, f32 farg5, f32 farg6, f32 farg7,
                            f32 farg8, f32 farg9) {
    f32 temp_f31 = fn_801452B4(farg1);
    f32 temp_f1 = ((f32 (*)(s32, f32))fn_801451DC)(0, farg0);
    fn_80011630(arg0, arg1, arg2, temp_f1, temp_f31, farg2, farg3,
                farg4, farg5, farg6, farg7, farg8, farg9);
}
extern "C" void fn_80147FF0(void *arg0, s32 arg1) {
    f32 temp_f31;
    f32 temp_f30;
    temp_f30 = fn_801452A0(*(s32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 0x10));
    temp_f31 = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 x = *(f32 *)((u8 *)arg0 + 4);
    s32 id = *(s32 *)((u8 *)arg0 + 0xC);
    f32 temp_f1 = ((f32 (*)(s32, f32))fn_801451DC)(id, x);
    fn_80011278(arg1, temp_f1, temp_f31, temp_f30, *(f32 *)((u8 *)arg0 + 0x14));
}

extern "C" void fn_80011280(s32, s32, f64, f64, f32, f32);
#pragma scheduling invalid_target
extern "C" void fn_80148070(void *arg0, s32 arg1, s32 arg2) {
    f32 temp_f31;
    f32 temp_f30;
    temp_f30 = fn_801452A0(*(s32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 0x10));
    temp_f31 = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 x = *(f32 *)((u8 *)arg0 + 4);
    s32 mode = *(s32 *)((u8 *)arg0 + 0xC);
    ((void (*)(s32, s32, f64, f64, f32, f32))fn_80011280)(
        arg1, arg2,
        ((f64 (*)(s32, f32))fn_801451DC)(mode, x),
        temp_f31, temp_f30, *(f32 *)((u8 *)arg0 + 0x14));
}
#pragma scheduling on

extern "C" void *lbl_8032D1D8;
extern "C" f32 fn_801451DC(s32);
extern "C" f32 fn_801452B4(f32);
extern "C" f32 lbl_805615D4;
extern "C" void fn_801470B0(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80148100(void *arg0) {
    f32 farg0 = *(f32 *)((u8 *)arg0 + 4);
    f32 farg1 = *(f32 *)((u8 *)arg0 + 8);
    f32 farg2 = *(f32 *)((u8 *)arg0 + 0x10);
    f32 farg3 = *(f32 *)((u8 *)arg0 + 0x14);
    s32 arg2 = *(s32 *)((u8 *)arg0 + 0x18);
    s32 arg3 = *(s32 *)((u8 *)arg0 + 0xC);
    fn_801470B0(arg2, -1, arg3, farg0, farg1, farg2, farg3,
        lbl_805615D4, lbl_805615D4, lbl_805615D4, lbl_805615D4);
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

extern "C" void *fn_801483D4(const char *, void *);
extern "C" void fn_801483C4(void *arg0, s32 arg1) {
    fn_801483D4((const char *)arg1, *(void **)((u8 *)arg0 + 0x34));
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_801483D4(const char *arg0, void *arg1) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), arg0) == 0) {
            return (void *)(*(u32 *)arg1 + i * 0x1C);
        }
        offset += 0x1C;
        i++;
    }
    return NULL;
}
#pragma pop

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
extern "C" {
char *fn_80029004(char *, int);
char *strcpy(char *, const char *);
char *strchr(const char *, int);
s32 fn_802E3D68(const char *);
void fn_802E3734(s32 *);
__declspec(section ".sdata") extern char lbl_80559E70[5];
extern char lbl_8032D28C[];
}
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_80148534(void *arg0) {
    strcpy(fn_80029004((char *)arg0 + 5, '.'), lbl_80559E70);
    char *name = (char *)arg0;
    name += 5;
    if (strchr(name, '/') != 0)
        name = strchr(name, '/') + 1;
    s32 value = fn_802E3D68(name);
    if (value != -1) {
        fn_802E3AD0(value, lbl_8032D28C, 1);
        fn_801457D0(*(void **)((u8 *)arg0 + 0x2C), value);
        fn_801456E8(*(void **)((u8 *)arg0 + 0x30), value);
        fn_8014589C(*(void **)((u8 *)arg0 + 0x34), value);
        fn_8014595C(*(void **)((u8 *)arg0 + 0x3C), (const char *)value);
        fn_802E3AD0(value, lbl_80559E14);
        fn_802E3734(&value);
    }
}
#pragma scheduling on
#pragma dont_inline reset
extern "C" void fn_80148610(void *arg0) {
    bool *b = (bool *)((u8 *)arg0 + 4);
    *b = !*b;
}

extern "C" u8 fn_80148624(void *arg0) { return ((u8 *)arg0)[4]; }

extern "C" void *fn_80148D74(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_8032D1D8;
        fn_80148DFC((u8 *)arg0 + 0x14);
        fn_80148E6C((u8 *)arg0 + 0x10);
        fn_80148EDC((u8 *)arg0 + 0xC);
        if (*((u8 *)arg0 + 4) != 0)
            deleteThreads__6SystemFv((u8 *)arg0 + 8);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

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

#pragma push
#pragma dont_inline on
extern "C" void fn_80148FA4(void *object, void *unused) {
    struct VTable {
        virtual void v0();
        virtual s32 v1(u32);
        virtual void *v2(u32);
    };
    u8 *self = (u8 *)object;
    VTable *v = *(VTable **)(self + 8);
    u32 i, offset;
    #pragma unused(unused)
    if (v != 0) {
        i = 0;
        offset = 0;
        do {
            u8 *list = *(u8 **)(self + 0x14);
            u8 *entry = *(u8 **)list + offset;
            void *result = v->v2(*(u32 *)(entry + 4));
            s32 found = v->v1(*(u32 *)entry);
            if (found != 0 && result != 0)
                fn_80148070((void *)found, *(s32 *)(entry + 8), (s32)result);
            offset += 0xC;
            i++;
        } while (i < *(u32 *)(*(u8 **)(self + 0x14) + 4));
        i = 0;
        offset = 0;
        do {
            u8 *list = *(u8 **)(self + 0x10);
            u8 *entry = *(u8 **)list + offset;
            fn_8014784C(v, *(u32 *)entry, *(u32 *)(entry + 4), *(u32 *)(entry + 8));
            offset += 0xC;
            i++;
        } while (i < *(u32 *)(*(u8 **)(self + 0x10) + 4));
        i = 0;
        offset = 0;
        do {
            u8 *list = *(u8 **)(self + 0xC);
            u8 *entry = *(u8 **)list + offset;
            fn_801473F8(v, *(u32 *)entry, (const char *)&lbl_80559E1C, *(u32 *)(entry + 4));
            offset += 8;
            i++;
        } while (i < *(u32 *)(*(u8 **)(self + 0xC) + 4));
    }
}
#pragma pop

extern "C" void fn_8014822C(void) {

}

extern "C" s32 fn_80148230(void) {
    return -1;
}

extern "C" s32 fn_80148238(void) {
    return 0xFF808080;
}


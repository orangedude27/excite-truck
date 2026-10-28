// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern "C" void fn_802E30C8(const char *, ...);
extern "C" s32 fn_80128314(s32);
extern "C" void fn_80127A24(void);
extern "C" void fn_802141A0(void **, void *, s32, s32, s32, s32);
extern "C" void fn_80218D54(void *, s32);
extern "C" void fn_80212340(void *);
extern "C" s32 fn_802168F0(void *);
extern "C" void fn_8021683C(void *);
extern "C" void fn_80236918(void *, void *, void (*)(void));
extern "C" void fn_80236950(void);
extern "C" void fn_802D08C4(s32);
extern "C" void fn_802E3D00(void);
extern "C" void fn_802E47E8(void);
extern "C" char lbl_8033D1E0[];
extern "C" u8 *lbl_8055B6BC;

extern "C" s32 fn_80218C14(s32, s32);
extern "C" s32 fn_802E317C(const char *);
extern "C" s32 fn_80214934(const void *, s32, void *, s32);
extern "C" s32 fn_80029004(const char *, s32);
extern "C" s32 fn_801345D8(void *, s32, const char *, s32, s32, const char *);
extern "C" unsigned long strlen(const char *);
#pragma small_data on
extern "C" const char lbl_8055B808[];
#pragma small_data off
extern "C" s32 fn_802C4F14(s32);
extern "C" s32 fn_802C4C90(s32, s32, s32, s32, s32);
extern "C" s32 fn_8021481C(void *);
extern "C" char lbl_8033D388[];
extern "C" char lbl_8033D268[];
extern "C" char lbl_8055B810[];

extern "C" s32 fn_802168E4(void);
extern "C" s32 fn_802168DC(s32, s32);
extern "C" s32 fn_802168D4(s32);
extern "C" s32 fn_802168CC(s32, float);
extern "C" s32 fn_802168E0(s32, s32, s32);
extern "C" char lbl_8033D2E0[];
extern "C" char lbl_8033D328[];
extern "C" char lbl_8033D2A0[];
extern "C" char lbl_8033D274[];

extern "C" s32 fn_802180E0(s32, s32);
extern "C" char lbl_8033D3B0[];

extern "C" s32 fn_802168DC(s32, s32);
extern "C" s32 fn_802168D4(s32);
extern "C" s32 fn_802168CC(s32, float);
extern "C" s32 fn_802168E0(s32, s32, s32);
extern "C" char lbl_8033D2E0[];
extern "C" char lbl_8033D328[];
extern "C" char lbl_8033D2A0[];
extern "C" char lbl_8033D274[];

class VfObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();     // vtable 0x24
    virtual void vf10();    // vtable 0x28
    virtual void vf11();    // vtable 0x2C
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
      virtual void vf16();
  virtual void vf17();
  virtual void vf18();
  virtual void vf19();
  virtual void vf20();
  virtual void vf21();    // vtable 0x5C
};

extern "C" void fn_8021915C(void *, unsigned int);

extern "C" void fn_80221E7C(void);
extern "C" s32 fn_80215270(s32, s32);
extern "C" void fn_8022E4BC(s32);
extern "C" void fn_8022E960(s32);
extern "C" s32 fn_80211678(u8 *);
#pragma small_data on
extern "C" char lbl_8055B750[];
#pragma small_data off
extern "C" int sprintf(char *, const char *, ...);
extern "C" int stricmp(const char *, const char *);
extern "C" void *memcpy(void *, const void *, unsigned long);
extern u8 lbl_8033CAE8[];
extern "C" s32 fn_80214E10(s32);
extern "C" s32 fn_80214FE0(s32, s32, s32, s32);
extern "C" s32 fn_80206430(void);
extern "C" s32 fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, s32, float);
extern "C" s32 fn_8022AC1C(s32, s32, s32, s32, s32, s32, s32, s32);
extern float lbl_80563450;
extern "C" float fn_80209028(void);
extern "C" int lbl_8055EF5C;
extern "C" unsigned char lbl_80490558[];
extern "C" char *lbl_8055B6B0;

extern "C" s32 fn_80128668(void);
extern "C" s32 (*lbl_8055EF0C)(s32 *);
extern "C" s32 fn_802168BC(s32);
extern "C" void *fn_802115AC(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void *fn_80211604(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" s32 fn_8021165C(s32 arg0, s32 arg1) {
    return fn_80215270(arg0, arg1);
}

extern s32 lbl_8055EF1C;
extern s32 lbl_8055EF20;
extern "C" s32 fn_80211660(s32 arg0) {
    if (arg0 == 0) {
        return lbl_8055EF1C;
    } else {
        return lbl_8055EF20;
    }
}

extern "C" s32 fn_80211678(u8 *arg0) {
    return ((s8) *arg0 - 0x24) == 0;
}

extern "C" int fn_80211690(int);
extern "C" int fn_80211D24(int);
extern "C" int fn_802E2C20(void);
extern "C" int fn_802ECC10(void);
extern "C" int lbl_8055EF14;
extern "C" float lbl_8055EF10;
extern "C" int lbl_8055EF40;
extern "C" float lbl_80563434;
extern "C" float lbl_80563440;
extern "C" float lbl_80563444;
extern "C" double lbl_80563448;
extern "C" void fn_80211F44(void) { fn_80211690(1); }

extern "C" void fn_80211F4C(void) { fn_80211D24(1); }

extern "C" int fn_80211F54(void) { return lbl_8055EF40 == 0; }

extern "C" void fn_80211F64(void) {
    float temp_f0;
    float var_f3;
    int temp_r31;
    temp_r31 = fn_802E2C20();
    if (fn_802ECC10() == 0) {
        var_f3 = lbl_80563444;
        temp_f0 = lbl_80563440 * (float)(temp_r31 - lbl_8055EF14);
        if (var_f3 < temp_f0) {
            var_f3 = var_f3;
        } else {
            var_f3 = temp_f0;
        }
        lbl_8055EF10 = var_f3;
    } else {
        lbl_8055EF10 = lbl_80563434;
    }
    lbl_8055EF14 = temp_r31;
}

#pragma scheduling invalid_target
extern "C" void fn_80211FF0(void) {
    s32 sp8;
    s32 (*cb)(s32 *);
    cb = lbl_8055EF0C;
    sp8 = -2;
    if (cb != 0) {
        if (cb(&sp8) != 0) {
            fn_802168BC(sp8);
        }
    }
}
#pragma scheduling on
extern "C" void *fn_801284F8(s32, const char *);
extern "C" s32 fn_8012C33C(s32);
extern "C" s32 fn_802C49E8(s32);
extern "C" s32 fn_802C2DD4(s32);
extern "C" void *fn_802228B0(void *, s32, s32, s32);
extern "C" void *fn_802226D4(s32);
extern "C" void *fn_8021203C(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern int lbl_8033D528[];
    extern char lbl_8033D504[];
    extern const char lbl_8055B724[], lbl_8055B728[], lbl_8055B720[], lbl_8055B730[];
    extern const char lbl_8055B738[], lbl_8055B73C[], lbl_8055B744[], lbl_8055B748[];
    extern const char lbl_8033CDA4[];
    struct ObjA { void *vtable; void *value; };
    struct ObjB { void *vtable; void *value; s32 count; s32 divisor; };
    char *name = (char *)fn_80029004(arg0, 0x2e);
    ObjA *a;
    ObjB *b;
    void *c;
    if (stricmp(name + 1, lbl_8055B724) == 0) {
        a = (ObjA *)fn_801284F8(8, lbl_8055B728);
        if (a) { a->vtable = lbl_8033D528; a->value = (void *)fn_802C49E8((s32)arg0); }
        return a;
    }
    if (stricmp(name + 1, lbl_8055B720) == 0) {
        b = (ObjB *)fn_801284F8(16, lbl_8055B730);
        if (b) {
            b->vtable = lbl_8033D504;
            if (fn_8012C33C((s32)arg0)) {
                c = (void *)fn_802C2DD4((s32)arg0); b->value = c;
                b->count = *(s32 *)((char *)c + 12) / arg1;
            } else { b->value = 0; b->count = 0; }
            b->divisor = arg1;
        }
        return b;
    }
    if (stricmp(name + 1, lbl_8055B738) == 0) {
        c = fn_801284F8(16, lbl_8055B73C);
        if (c) return fn_802228B0(arg0, arg2, arg3, arg4);
        return c;
    }
    if (stricmp(name + 1, lbl_8055B744) == 0) {
        c = fn_801284F8(8, lbl_8055B748);
        if (c) return fn_802226D4((s32)arg0);
        return c;
    }
    ((s32 (*)(const char *, const char *))fn_802E317C)(lbl_8033CDA4, name + 1);
    return 0;
}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_802121D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern s32 (*lbl_8055EF0C)(s32 *);
extern "C" s32 fn_80212214(s32 arg0) {
    s32 value;
    memcpy(&value, &arg0, 4);
    return value;
}

#pragma dont_inline fn_80212248
extern "C" float fn_80212248(s32 arg0) {
    float value;
    memcpy(&value, &arg0, 4);
    return value;
}

extern "C" void fn_8022E4BC(s32);
extern "C" void fn_8022E960(s32);
extern "C" s32 fn_80211678(u8 *);
extern "C" char lbl_8055B750[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" int stricmp(const char *, const char *);
#pragma small_data on
#pragma small_data off
extern "C" void *fn_8021227C(void *arg0, char *arg1, s32 arg2) {
    char first = *arg1;
    char buf[0x100];
    char *name = arg1;
    void *entry = arg0;

    if (first == '#') {
        name = arg1 + 1;
        sprintf(buf, lbl_8055B750, name);
    }
    for (;;) {
        if (*(s32 *)((char *)entry + 4) == arg2 &&
            *(char **)entry != 0 &&
            (stricmp(*(char **)entry, name) == 0 ||
             stricmp(*(char **)entry, buf) == 0)) {
            return entry;
        }
        entry = (char *)entry + 0x14;
        if (*(s32 *)((char *)entry + 4) == 0x7B) {
            return 0;
        }
    }
}
extern "C" s32 fn_80212338(void) { return 0; }

extern "C" void fn_80212340(void *arg0) {
    s32 first = *(s32 *)((char *)arg0 + 0x10);
    s32 *p = (s32 *)arg0;
    if (first != 0) {
        fn_8022E4BC(first);
        p[4] = 0;
    }
    if (*(s32 *)arg0 != 0) {
        if (fn_80211678((u8 *)arg0) == 0) {
            fn_8022E4BC(p[3]);
        } else {
            fn_8022E960(p[3]);
        }
        p[3] = 0;
    }
}

extern "C" s32 fn_8021B2B0(void *, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021D044(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_802168EC(void *, void *, s32);
extern "C" char lbl_8055B758[];
extern "C" s32 fn_8021B9AC(void *, void *, s32, s32);
extern "C" s32 fn_8022435C(void *, s32, void *, s32, s32);
extern "C" s32 fn_8021A5B8(void *, char *, s32, s32, s32, f32);
extern "C" s32 fn_80129BC4(void);
extern "C" char lbl_8055B770[];
extern "C" char lbl_8055B760[];
extern "C" char lbl_8055B780[];
extern "C" char lbl_8033D54C[];
extern "C" s32 fn_8021D6A0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021B460(void *, void *, s32, s32);
extern "C" void fn_802123B8(void *, void *, void *);
extern "C" s32 fn_802224B4(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_80226630(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" char lbl_8055B778[];
extern "C" char *strstr(const char *, const char *);
extern "C" s32 fn_8021995C(void *, s32, s32, s32, s32, s32);
extern "C" s32 fn_80219A28(void *, void *, s32, s32);
extern "C" s32 fn_80219870(void *, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021A77C(void *, s32, s32, s32, s32, s32);
extern "C" char lbl_8055B788[];
extern "C" char lbl_8055B790[];
extern "C" char lbl_8055B798[];
extern "C" s32 lbl_8055EF48;
extern "C" s32 lbl_8055EF4C;
extern "C" s32 fn_8021B0CC(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_80220778(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8022D1B4(s32);
extern "C" s32 fn_8021F678(void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern "C" s32 fn_8021AF0C(void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern "C" s32 fn_8021BD98(void *, s32, s32, s32, s32, s32, f32, f32);
extern "C" s32 fn_8021CEEC(void *, s32, s32, s32, s32, s32, f32, f32);
extern "C" s32 fn_800241CC(s32);
extern "C" char lbl_8055B7A0[];
extern "C" char lbl_8055B7A8[];
extern "C" s32 lbl_8055EF50;
extern "C" f32 lbl_80558DC4;
extern "C" f32 lbl_80563454;
extern "C" void fn_80215298(s32 *, s32 *, s32 *, s32 *, s32, s32, u32);
extern "C" s32 fn_8021D7C8(void *, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021A808(void *, s32, s32, s32, s32, s32);
extern "C" s32 lbl_8055B754;
extern "C" char lbl_8055B7B8[];
extern "C" s32 lbl_8055EF54;
extern "C" s32 fn_8021BEC0(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021CA0C(void *, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021C97C(void *, s32, s32, s32, s32, s32);
extern "C" char lbl_8055B7B0[];
extern "C" s32 fn_8021EA64(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_80218F34(void *, s32, s32, s32, s32, s32);
extern "C" s32 fn_80222BDC(void *, void *, s32);
extern "C" s32 fn_8021E0C0(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_80220E48(void *, s32, s32, s32, s32, s32, s32);
extern "C" s32 fn_8021B1C4(void *, s32, s32, s32, s32, s32);
extern "C" char lbl_8055B7C0[];
extern "C" char lbl_8055B7C8[];
extern "C" char lbl_8055B7D0[];
extern "C" s32 lbl_8055EF24;
extern "C" char lbl_8033D480[];
extern void *fn_802241C8(void *, void *);
extern void *fn_80224B54(s32, void *);
extern void *fn_8022553C(s32, void *);
extern void *fn_802269A8(void *, void *);
extern void *fn_80226CBC(void *, void *);
extern void *fn_802270DC(void *, void *);
extern void *fn_80227E84(void *, s32, void *, s32);
extern void *fn_80227D00(void *, void *);
extern void *fn_80228418(void *, void *, s32);
extern void *fn_8022855C(void *, void *, s32, s32);
extern void *fn_8021F394(void *, s32, s32, s32, s32, s32);
extern void *fn_802230A4(void *, s32, s32, s32, s32);
extern void *fn_80223AB4(void *, void *, s32);
extern void *fn_80223CF0(void *, void *, s32);
extern f32 fn_80212248(s32);
extern void *fn_8021FF34(void *, void *, s32, s32, f32, f32);
extern "C" float fn_80212248(s32);
#pragma dont_inline fn_80212248
extern "C" char lbl_8055B7E0;
extern "C" char lbl_8055B7E8;
extern "C" char lbl_8055B7F0;
extern "C" float __fabsf(float);
#pragma scheduling invalid_target
extern "C" void fn_802123B8(void *arg0, void *arg1, void *arg2) {
    extern void *lbl_8055EF38;
    extern s32 lbl_8055EF2C;
    extern s32 lbl_80490510[];
    extern s32 lbl_8055EF58;
    extern s32 lbl_8055EF24;
    void *results[4] = { 0 };
    s32 count = 0;
    s32 i;
    s32 type;
    register const char *strings = (const char *)lbl_8033CAE8;
    register const char *data = (const char *)lbl_80490510;
    *(s32 *)&lbl_8055EF38 = *(s32 *)((char *)arg1 + 0x8C);
    type = *(s32 *)((char *)arg1 + 0);
    (void)(type - type);
    switch (type) {
    case 5: {
        void *child = fn_8021227C(arg2, ((char *)arg1) + 0x20, 3);
        void *node;
        if (child) {
            void *child2 = fn_8021227C(arg2, ((char *)arg1) + 0x20, 2);
            node = fn_801284F8(0x368, strings + 0x2FC);
            if (node) {
                s32 value = child2 != 0 ? *(s32 *)((char *)child2 + 8) : 0;
                node = (void *)fn_8021B2B0(node, *(s32 *)((char *)arg1 + 8),
                    *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)child + 8),
                    *(s32 *)((char *)arg1 + 4), value, 0);
            }
        } else {
            child = fn_8021227C(arg2, (char *)arg1 + 0x20, 7);
            node = fn_801284F8(0x2C4, lbl_8055B758);
            if (node != 0) node = (void *)fn_8021D044(node,
                *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
                *(s32 *)((char *)child + 8), *(s32 *)((char *)child + 0xC),
                *(s32 *)((char *)arg1 + 4), 0, 0, 0);
        }
        results[0] = node; count = 1; break;
    }
    case 28: {
        void *primary = 0;
        void *child = 0;
        void *node;
        if (*(u8 *)((char *)arg1 + 0x40) == '#') {
            primary = fn_8021227C(arg2, (char *)arg1 + 0x41, 3);
            if (!primary) {
                child = fn_8021227C(arg2, (char *)arg1 + 0x41, 7);
                if (child != 0) {
                    s32 v1 = fn_80212214(*(s32 *)((char *)arg1 + 0x9C));
                    s32 v2 = fn_80212214(*(s32 *)((char *)arg1 + 0xA0));
                    node = fn_801284F8(0x2C8, strings + 0x308);
                    if (node != 0) node = (void *)fn_8021D6A0(node,
                        *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
                        *(s32 *)((char *)child + 8), *(s32 *)((char *)child + 0xC),
                        (s32)((char *)arg1 + 0x20), *(s32 *)((char *)arg1 + 4), v1, v2);
                    results[0] = node; count = 1;
                    break;
                }
            }
            child = fn_8021227C(arg2, (char *)arg1 + 0x41, 2);
        }
        node = fn_801284F8(0x374, strings + 0x314);
        if (node != 0) {
            s32 v1 = child ? *(s32 *)((char *)child + 8) : 0;
            s32 v2 = primary != 0 && *(s32 *)((char *)primary + 8) != 0 ?
                *(s32 *)((char *)primary + 8) : (s32)((char *)arg1 + 0x40);
            node = (void *)fn_8021B460(node, arg1, v2, v1);
        }
        results[0] = node; count = 1;
        break;
    }
    case 31: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x40, 0xD);
        void *node = fn_801284F8(0x264, lbl_8055B770);
        if (node != 0) node = (void *)fn_8021B9AC(node, arg1,
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF2C,
            child != 0 ? *(s32 *)((char *)child + 0xC) : 0);
        results[0] = node; count = 1; break;
    }
    case 2: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 0);
        void *second = 0;
        if (*(u8 *)((char *)arg1 + 0x40) == '#')
            second = fn_8021227C(arg2, (char *)arg1 + 0x41, 3);
        s32 value1 = first ? *(s32 *)((char *)first + 0xC) : 0;
        s32 value2 = second ? *(s32 *)((char *)second + 8) : (s32)((char *)arg1 + 0x40);
        s32 value3 = first != 0 ? *(s32 *)((char *)first + 8) : (s32)fn_80212338;
        void *inner = fn_801284F8(0xC, strings + 0x32C);
        if (inner != 0) {
            *(void **)inner = lbl_8033D54C;
            *(s32 *)((char *)inner + 8) = *(s32 *)((char *)arg1 + 4);
            *(s32 *)((char *)inner + 4) = value2;
        }
        if (*(u32 *)((char *)arg1 + 0x9C) == 1 || fn_80129BC4() == 0) {
            void *node = fn_801284F8(0x260, lbl_8055B778);
            if (node != 0) node = (void *)fn_802224B4(node, value1,
                *(s32 *)((char *)arg1 + 0x9C), *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x14),
                *(s32 *)((char *)arg1 + 0x18), (s32)inner, 0,
                (*(s32 *)((char *)arg1 + 0x9C) != 0));
            results[0] = node;
        } else {
            void *node = fn_801284F8(0x268, lbl_8055B780);
            if (node != 0) node = (void *)fn_80226630(node, value1,
                *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
                *(s32 *)((char *)arg1 + 0x14), *(s32 *)((char *)arg1 + 0x18),
                (s32)inner, value3);
            results[0] = node;
        }
        count = 1;
        break;
    }
    case 42: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 0);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        s32 value1 = first != 0 ? *(s32 *)((char *)first + 0xC) : 0;
        s32 value2 = first != 0 ? *(s32 *)((char *)first + 8) : (s32)fn_80212338;
        s32 value3 = second != 0 ? *(s32 *)((char *)second + 8) : 0;
        void *node = fn_801284F8(0x28C, strings + 0x338);
        if (node != 0) node = (void *)fn_8022435C(node, value1, arg1, value2, value3);
        results[0] = node; count = 1; break;
    }
    case 3:
        fn_802E30C8(strings + 0x344);
        break;
    case 34: {
        void *node = fn_801284F8(0x258, strings + 0x388);
        if (node != 0) node = (void *)fn_8021A5B8(node, (char *)arg1 + 0x40,
            1, 1, 1, (f32)*(s32 *)((char *)arg1 + 0x10));
        results[0] = node; count = 1; break;
    }
    case 17:
        fn_802E30C8(strings + 0x394);
        break;
    case 33: {
        u32 index = *(u32 *)((char *)arg1 + 4) - 2;
        s32 enabled = index <= 3 && ((1u << index) & 0xD) != 0;
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        char *text = second != 0 ? *(char **)((char *)second + 8) : (char *)arg1 + 0x40;
        s32 extra = enabled ? (s32)((char *)arg1 + 0x20) :
            (first != 0 ? *(s32 *)((char *)first + 8) : 0);
        void *node;
        if (strstr(text, lbl_8055B788) != 0) {
            node = fn_801284F8(0x258, strings + 0x3E4);
            if (node != 0) {
                void *child = fn_801284F8(0x10, lbl_8055B790);
                if (child != 0) child = fn_802228B0(child, (s32)text,
                    *(s32 *)((char *)arg1 + 0x14), *(s32 *)((char *)arg1 + 0x18));
                node = (void *)fn_8021995C(node, *(s32 *)((char *)arg1 + 8),
                    *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x10),
                    (s32)child, extra);
            }
        } else {
            node = fn_801284F8(0x284, strings + 0x3F4);
            if (node != 0) node = (void *)fn_80219A28(node, arg1, (s32)text, extra);
        }
        results[0] = node; count = 1;
        break;
    }
    case 13: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 1);
        void *node = fn_801284F8(0x358, strings + 0x400);
        if (node != 0) node = (void *)fn_80219870(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            (s32)((char *)arg1 + 0x40),
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF48,
            *(s32 *)((char *)arg1 + 4));
        results[0] = node; count = 1;
        break;
    }
    case 14: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x25C, strings + 0x40C);
        if (node != 0) {
            void *inner = fn_801284F8(0xC, lbl_8055B798);
            s32 value = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF4C;
            if (inner != 0) {
                *(void **)inner = lbl_8033D54C;
                *(s32 *)((char *)inner + 8) = *(s32 *)((char *)arg1 + 4);
                *(s32 *)((char *)inner + 4) = (s32)((char *)arg1 + 0x40);
            }
            node = (void *)fn_8021A77C(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x9C), value,
                (s32)inner);
        }
        results[0] = node; count = 1;
        break;
    }
    case 15: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x25C, strings + 0x418);
        if (node != 0) {
            s32 value = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF4C;
            void *extra = fn_8021203C((char *)arg1 + 0x40, 2, -1, -1, 0);
            node = (void *)fn_8021A77C(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x9C),
                value, (s32)extra);
        }
        results[0] = node; count = 1;
        break;
    }
    case 8: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        s32 text;
        s32 value;
        s32 flags;
        if (child != 0) {
            text = *(s32 *)((char *)child + 8);
            value = *(s32 *)((char *)child + 0xC);
            flags = *(s32 *)((char *)child + 0x10);
        } else {
            child = fn_8021227C(arg2, (char *)arg1 + 0x20, 7);
            if (child != 0) {
                text = *(s32 *)((char *)child + 8);
                value = 0;
                flags = fn_8022D1B4(*(s32 *)((char *)child + 0xC));
            } else {
                text = lbl_8055EF4C; value = 0; flags = 5;
            }
        }
        void *node = fn_801284F8(0x264, strings + 0x428);
        if (node != 0) {
            s32 control = ((s32 (*)(s32, s32))fn_80215270)(0, 1);
            node = (void *)fn_8021B0CC(node,
                *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC) + 1,
                text, value, flags, -1, control);
        }
        results[0] = node; count = 1;
        s32 delta = *(s32 *)((char *)arg1 + 0x14) - 0x25;
        if (delta > 10) {
            void *node2 = fn_801284F8(0x264, strings + 0x434);
            if (node2 != 0) node2 = (void *)fn_80220778(node2,
                *(s32 *)((char *)arg1 + 8) + 0x15,
                *(s32 *)((char *)arg1 + 0xC), delta,
                *(s32 *)((char *)arg1 + 0x18), text, value, flags);
            results[1] = node2; count = 2;
        }
        node = fn_801284F8(0x264, strings + 0x428);
        if (node != 0) {
            s32 control = ((s32 (*)(s32, s32))fn_80215270)(1, 1);
            node = (void *)fn_8021B0CC(node,
                *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14) - 0xE,
                *(s32 *)((char *)arg1 + 0xC) + 1,
                text, value, flags, 1, control);
        }
        results[count] = node;
        count++;
        break;
    }
    case 18: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 9);
        f32 value1 = lbl_80563434;
        f32 value2 = lbl_80563450;
        if (child != 0) {
            value1 = *(f32 *)((char *)child + 0xC);
            value2 = *(f32 *)((char *)child + 0x10);
        }
        f32 diff = __fabsf(value1 - value2);
        if (diff > lbl_80558DC4 && *(s32 *)((char *)arg1 + 0x9C) != 0) {
            s32 delta = *(s32 *)((char *)arg1 + 0x14) - 0x25;
            if (delta > 10) {
                void *node = fn_801284F8(0x27C, lbl_8055B7A0);
                if (node != 0) node = (void *)fn_8021F678(node,
                    *(s32 *)((char *)arg1 + 8) + 0x15, *(s32 *)((char *)arg1 + 0xC),
                    delta, *(s32 *)((char *)arg1 + 0x18),
                    child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF50,
                    *(s32 *)((char *)arg1 + 0x9C), value1, value2);
                results[0] = node; count = 1;
            }
            void *node0 = fn_801284F8(0x268, strings + 0x440);
            if (node0 != 0) {
                s32 text = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF50;
                s32 control = ((s32 (*)(s32, s32))fn_80215270)(0, 1);
                s32 state = fn_800241CC(*(s32 *)((char *)arg1 + 0x9C));
                node0 = (void *)fn_8021AF0C(node0,
                    *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC) + 1,
                    text, -1, control, state, value1, value2);
            }
            results[count++] = node0;
            void *node1 = fn_801284F8(0x268, strings + 0x440);
            if (node1 != 0) {
                s32 text = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF50;
                s32 control = ((s32 (*)(s32, s32))fn_80215270)(1, 1);
                s32 state = fn_800241CC(*(s32 *)((char *)arg1 + 0x9C));
                node1 = (void *)fn_8021AF0C(node1,
                    *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14) - 0xE,
                    *(s32 *)((char *)arg1 + 0xC) + 1, text, 1, control, state,
                    value1, value2);
            }
            results[count++] = node1;
        }
        break;
    }
    case 6: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 9);
        void *node = fn_801284F8(0x2B4, lbl_8055B7A8);
        if (node != 0) node = (void *)fn_8021BD98(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF50,
            (s32)((char *)arg1 + 0x40), *(s32 *)((char *)arg1 + 4),
            lbl_80563454, lbl_80563434);
        results[0] = node; count = 1;
        break;
    }
    case 7: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x2B4, strings + 0x44C);
        if (node != 0) node = (void *)fn_8021CEEC(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF4C,
            (s32)((char *)arg1 + 0x40), *(s32 *)((char *)arg1 + 4),
            lbl_80563450, lbl_80563434);
        results[0] = node; count = 1;
        break;
    }
    case 9: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xC);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) :
            *(s32 *)((char *)data + 0x160);
        s32 mode = *(s32 *)((char *)arg1 + 4);
        s32 a, b, c, d;
        if (mode == 4) {
            void *node = fn_801284F8(0x25C, strings + 0x458);
            if (node != 0) node = (void *)fn_8021CA0C(node,
                *(s32 *)((char *)arg1 + 8) + 0xF,
                *(s32 *)((char *)arg1 + 0xC),
                *(s32 *)((char *)arg1 + 0x14) - 0x1E,
                *(s32 *)((char *)arg1 + 0x18), text);
            results[0] = node;
            node = fn_801284F8(0x25C, strings + 0x464);
            if (node != 0) node = (void *)fn_8021C97C(node,
                *(s32 *)((char *)arg1 + 8) + 1,
                *(s32 *)((char *)arg1 + 0xC) + 2,
                ((s32 (*)(s32, s32))fn_80215270)(0, 2), -1, text);
            results[1] = node;
            node = fn_801284F8(0x25C, strings + 0x464);
            if (node != 0) node = (void *)fn_8021C97C(node,
                *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14) - 0xF,
                *(s32 *)((char *)arg1 + 0xC) + 2,
                ((s32 (*)(s32, s32))fn_80215270)(1, 2), 1, text);
            results[2] = node; count = 3;
        } else {
            fn_80215298(&a, &b, &c, &d, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(u32 *)((char *)arg1 + 0x14));
            void *node = fn_801284F8(0x2BC, lbl_8055B7B0);
            if (node != 0) node = (void *)fn_8021BEC0(node, b,
                *(s32 *)((char *)arg1 + 0xC), text,
                mode == 1 ? 0x14 : 0xF, a, c, d);
            results[0] = node; count = 1;
        }
        break;
    }
    case 49: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0x10);
        s32 a, b, c, d;
        fn_80215298(&a, &b, &c, &d, *(s32 *)((char *)arg1 + 8),
            *(s32 *)((char *)arg1 + 0xC), *(u32 *)((char *)arg1 + 0x14));
        void *node = fn_801284F8(0x26C, strings + 0x47C);
        if (node != 0) node = (void *)fn_8021D7C8(node, a, b, c, d,
            *(s32 *)((char *)arg1 + 4),
            child != 0 ? *(s32 *)((char *)child + 0xC) : *(s32 *)((char *)data + 0x18C));
        results[0] = node; count = 1;
        break;
    }
    case 10: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 7);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF4C;
        void *node;
        s32 size = *(s32 *)((char *)arg1 + 0x14);
        if (size > 0 && size - 0x25 > 10) {
            s32 a, b, c, d;
            fn_80215298(&a, &b, &c, &d, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(u32 *)((char *)arg1 + 0x14));
            node = fn_801284F8(0x2C4, lbl_8055B758);
            if (node != 0) node = (void *)fn_8021D044(node, b,
                *(s32 *)((char *)arg1 + 0xC), text, 0xF, a, c, d,
                (s32)((char *)arg1 + 0x40));
        } else {
            node = fn_801284F8(0x2C4, lbl_8055B758);
            if (node != 0) node = (void *)fn_8021D044(node,
                *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
                text, 0, 0, 0, 0, 0);
        }
        results[0] = node; count = 1;
        break;
    }
    case 16: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x25C, strings + 0x48C);
        if (node != 0) {
            s32 value = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF54;
            void *inner = fn_801284F8(0xC, lbl_8055B7B8);
            if (inner != 0) {
                *(void **)inner = lbl_8033D54C;
                *(s32 *)((char *)inner + 8) = *(s32 *)((char *)arg1 + 4);
                *(void **)((char *)inner + 4) = (char *)arg1 + 0x40;
            }
            node = (void *)fn_8021A808(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x9C),
                value, (s32)inner);
        }
        results[0] = node; count = 1;
        break;
    }
    case 27: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x25C, strings + 0x498);
        if (node != 0) {
            s32 value = child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF54;
            void *extra = fn_8021203C((char *)arg1 + 0x40, 1, -1, -1, 0);
            node = (void *)fn_8021A808(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC), *(s32 *)((char *)arg1 + 0x9C),
                value, (s32)extra);
        }
        results[0] = node; count = 1;
        break;
    }
    case 11: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) :
            (s32)((char *)data + 0x1A0);
        s32 color = child != 0 ? *(s32 *)((char *)child + 0xC) : 0x40;
        void *node = fn_801284F8(0xA64, lbl_8055B7C0);
        if (node != 0) node = (void *)fn_8021EA64(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            *(s32 *)((char *)arg1 + 0x14), 0xA, text, color, 1,
            *(s32 *)((char *)arg1 + 4), 0);
        results[0] = node; count = 1;
        break;
    }
    case 26: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 5);
        s32 index = 0;
        void *node;
        s32 *ref;
        if (child != 0) {
            ref = (s32 *)*(s32 *)((char *)child + 8);
        } else {
            extern s32 lbl_8055EF58;
            index = (lbl_8055EF58 + 1) & 0xF;
            lbl_8055EF58 = index;
            ref = (s32 *)((char *)data + 0x200 + index * 0x18);
        }
        node = fn_801284F8(0x248, lbl_8055B7C8);
        if (node != 0) {
            fn_80218F34(node, *(s32 *)((char *)arg1 + 8),
                *(s32 *)((char *)arg1 + 0xC),
                *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14),
                *(s32 *)((char *)arg1 + 0xC) + *(s32 *)((char *)arg1 + 0x18),
                *(s32 *)((char *)arg1 + 0x10));
            *(void **)node = lbl_8033D480;
            *(s32 *)((char *)node + 0x244) = (s32)ref;
            ref[5] = (s32)node;
            ref[1] = *(s32 *)((char *)arg1 + 8);
            ref[2] = *(s32 *)((char *)arg1 + 0xC);
            ref[3] = *(s32 *)((char *)arg1 + 0x14);
            ref[4] = *(s32 *)((char *)arg1 + 0x18);
        }
        results[0] = node; count = 1;
        break;
    }
    case 35: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xA);
        void *node = fn_801284F8(0x258, strings + 0x4A4);
        if (node != 0) node = (void *)fn_80222BDC(node, arg1,
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF24);
        results[0] = node; count = 1;
        break;
    }
    case 23: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xA);
        void *third = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xB);
        void *node = fn_801284F8(0x26C, lbl_8055B7D0);
        if (node != 0) node = (void *)fn_8021E0C0(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            *(s32 *)((char *)arg1 + 0x14), *(s32 *)((char *)arg1 + 0x18),
            third != 0 ? *(s32 *)((char *)third + 8) : (s32)((char *)lbl_8033CAE8 + 0x380),
            first != 0 ? *(s32 *)((char *)first + 8) : lbl_8055EF4C,
            second != 0 ? *(s32 *)((char *)second + 8) : lbl_8055EF24);
        results[0] = node; count = 1;
        break;
    }
    case 20: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xB);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) :
            (s32)((char *)lbl_8033CAE8 + 0x380);
        void *node = fn_801284F8(0x260, strings + 0x4B0);
        if (node != 0) node = (void *)fn_80220E48(node,
            *(s32 *)((char *)arg1 + 8) - 3,
            *(s32 *)((char *)arg1 + 0xC) + 0x15,
            *(s32 *)((char *)arg1 + 0x14),
            *(s32 *)((char *)arg1 + 0x18) - 0x28, text, 0);
        results[0] = node;
        void *second = fn_801284F8(0x25C, strings + 0x4BC);
        if (second) second = (void *)fn_8021B1C4(second,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            text, -1, ((s32 (*)(s32, s32))fn_80215270)(2, 0));
        results[1] = second;
        void *third = fn_801284F8(0x25C, strings + 0x4BC);
        if (third != 0) third = (void *)fn_8021B1C4(third,
            *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x18) - 0x12,
            *(s32 *)((char *)arg1 + 0xC) + 3, text, 1,
            ((s32 (*)(s32, s32))fn_80215270)(3, 0));
        results[2] = third; count = 3;
        break;
    }
    case 21: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xB);
        s32 text = child != 0 ? *(s32 *)((char *)child + 8) :
            (s32)((char *)lbl_8033CAE8 + 0x380);
        void *node = fn_801284F8(0x260, strings + 0x4C8);
        if (node != 0) node = (void *)fn_80220E48(node,
            *(s32 *)((char *)arg1 + 8) + 0x15,
            *(s32 *)((char *)arg1 + 0xC),
            *(s32 *)((char *)arg1 + 0x14) - 0x28,
            *(s32 *)((char *)arg1 + 0x18), text, 1);
        results[0] = node;
        void *second = fn_801284F8(0x25C, strings + 0x4BC);
        if (second != 0) second = (void *)fn_8021B1C4(second,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            text, -1, ((s32 (*)(s32, s32))fn_80215270)(0, 0));
        results[1] = second;
        void *third = fn_801284F8(0x25C, strings + 0x4BC);
        if (third != 0) third = (void *)fn_8021B1C4(third,
            *(s32 *)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 0x14) - 0x12,
            *(s32 *)((char *)arg1 + 0xC) + 3, text, 1,
            ((s32 (*)(s32, s32))fn_80215270)(1, 0));
        results[2] = third; count = 3;
        break;
    }
    case 12: {
        extern char lbl_8055B7D8[];
            void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 4);
        void *node = fn_801284F8(0x274, lbl_8055B7D8);
        if (node != 0) node = (void *)fn_8021F394(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            child != 0 ? *(s32 *)((char *)child + 0xC) : (s32)((char *)lbl_8033CAE8 + 0x4D4),
            child != 0 ? *(s32 *)((char *)child + 8) : (s32)((char *)data + 0x1E0), 6);
        results[0] = node; count = 1; break;
    }
    case 36: {
        extern s32 lbl_8055EF28;
        extern s32 lbl_8055EF4C;
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xA);
        void *node = fn_801284F8(0x420, strings + 0x4E8);
        if (node != 0) node = (void *)fn_8021F394(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            second != 0 ? *(s32 *)((char *)second + 0xC) : lbl_8055EF28,
            first != 0 ? *(s32 *)((char *)first + 8) : lbl_8055EF4C, 6);
        results[0] = node; count = 1; break;
    }
    case 37: {
        extern s32 lbl_8055EF28;
        extern s32 lbl_8055EF4C;
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xA);
        void *node = fn_801284F8(0x424, &lbl_8055B7E0);
        if (node != 0) node = (void *)fn_802230A4(node,
            *(s32 *)((char *)arg1 + 8), *(s32 *)((char *)arg1 + 0xC),
            second != 0 ? *(s32 *)((char *)second + 8) : lbl_8055EF28,
            first != 0 ? *(s32 *)((char *)first + 8) : lbl_8055EF4C);
        results[0] = node; count = 1; break;
    }
    case 38: {
        extern s32 lbl_8055EF30;
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xE);
        void *node = fn_801284F8(0x268, strings + 0x4F4);
        if (node != 0) node = (void *)fn_80223AB4(node, arg1,
            child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF30);
        results[0] = node; count = 1; break;
    }
    case 39: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        void *node;
        if (child != 0) {
            node = fn_801284F8(0x268, strings + 0x500);
            if (node != 0) node = (void *)fn_80223CF0(node, arg1, *(s32 *)((char *)child + 8));
        } else {
            node = fn_801284F8(0x268, strings + 0x500);
            if (node != 0) node = (void *)fn_80223CF0(node, arg1, 0);
        }
        results[0] = node; count = 1; break;
    }
    case 41: {
        void *node = fn_801284F8(0x258, strings + 0x518);
        if (node != 0) node = (void *)fn_802241C8(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 43: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        void *node = fn_801284F8(0x2A0, &lbl_8055B7E8);
        if (node != 0) node = (void *)fn_80224B54(child != 0 ? *(s32 *)((char *)child + 8) : 0, arg1);
        results[0] = node; count = 1; break;
    }
    case 44: {
        extern s32 lbl_8055EF30;
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xE);
        void *node = fn_801284F8(0x284, strings + 0x530);
        if (node != 0) node = (void *)fn_8022553C(child != 0 ? *(s32 *)((char *)child + 8) : lbl_8055EF30, arg1);
        results[0] = node; count = 1; break;
    }
    case 45: {
        void *node = fn_801284F8(0x260, strings + 0x53C);
        if (node != 0) node = (void *)fn_802269A8(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 46: {
        void *node = fn_801284F8(0x264, strings + 0x548);
        if (node != 0) node = (void *)fn_80226CBC(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 47: {
        void *node = fn_801284F8(0x274, strings + 0x558);
        if (node != 0) node = (void *)fn_802270DC(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 48: {
        extern s32 lbl_8055EF34;
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 0xF);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 3);
        s32 value = first != 0 ? *(s32 *)((char *)first + 8) : lbl_8055EF34;
        void *node = fn_801284F8(0x25C, strings + 0x568);
        if (node != 0) node = (void *)fn_80227E84(node, value, arg1,
            second != 0 ? *(s32 *)((char *)second + 8) : 0);
        results[0] = node; count = 1; break;
    }
    case 51: {
        void *node = fn_801284F8(0x248, &lbl_8055B7F0);
        if (node != 0) node = (void *)fn_80227D00(node, arg1);
        results[0] = node; count = 1; break;
    }
    case 50: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 9);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x268, strings + 0x578);
        if (node != 0) {
            f32 height;
            f32 width;
            if (first) height = *(f32 *)((char *)first + 0x10);
            else height = lbl_80563450;
            if (first != 0) width = *(f32 *)((char *)first + 0xC);
            else width = lbl_80563434;
            s32 value = second != 0 ? **(s32 **)((char *)second + 8) : 10;
            node = (void *)fn_8021FF34(node, arg1,
                first != 0 ? *(s32 *)((char *)first + 8) : 0,
                value, width, height);
        }
        results[0] = node; count = 1; break;
    }
    case 52: {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0x11);
        void *node = fn_801284F8(0x24C, strings + 0x588);
        if (node != 0) node = (void *)fn_80228418(node, arg1,
            child != 0 ? *(s32 *)((char *)child + 8) : 0);
        results[0] = node; count = 1; break;
    }
    case 53: {
        void *first = fn_8021227C(arg2, (char *)arg1 + 0x20, 0x12);
        void *second = fn_8021227C(arg2, (char *)arg1 + 0x20, 2);
        void *node = fn_801284F8(0x24C, strings + 0x594);
        if (node != 0) node = (void *)fn_8022855C(node, arg1,
            first != 0 ? *(s32 *)((char *)first + 8) : 0,
            second != 0 ? *(s32 *)((char *)second + 8) : 0);
        results[0] = node; count = 1; break;
    }
    case 54:
        break;
    default:
        ((s32 (*)(const char *, ...))fn_802E317C)(strings + 0x5A4, type);
        break;
    }
    {
        void *child = fn_8021227C(arg2, (char *)arg1 + 0x20, 0x14);
        if (child == 0) child = fn_8021227C(arg2, (char *)arg1 + 0x40, 0x14);
        for (i = 0; i < count; ++i) {
            if (child != 0) *(s32 *)((char *)results[i] + 0x240) = *(s32 *)((char *)child + 8);
            fn_802168EC(arg0, results[i], *(s32 *)((char *)arg1 + 0x88));
        }
    }
    *(s32 *)&lbl_8055EF38 = -1;
}
#pragma scheduling on
extern "C" s32 fn_802ECEEC(void);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" s32 fn_802146BC(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" u8 lbl_8033CAE8[];
extern "C" s32 lbl_80490510[];
extern "C" s32 lbl_802F9EA4[];
extern "C" u8 lbl_8055B860;
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" s32 fn_8021481C(void *arg0) {
    u8 *base = lbl_8033CAE8;
    s32 *values;
    s32 *map;
    s32 args[20];
    if (fn_802ECEEC() == 0) {
        fn_802E30C8((const char *)(base + 0x72C), arg0);
        values = lbl_80490510;
        map = lbl_802F9EA4;
        args[0] = map[0];
        args[1] = 0;
        args[2] = map[2];
        args[3] = map[3];
        args[4] = map[4];
        args[5] = (s32)(base + 0x750);
        args[6] = 3;
        args[7] = (s32)arg0;
        args[8] = 0;
        args[9] = 0;
        args[10] = (s32)&lbl_8055B860;
        args[11] = 6;
        args[12] = 0;
        args[13] = -2;
        args[14] = 0xD;
        args[15] = values[0];
        args[16] = values[1];
        args[17] = values[2];
        args[18] = values[3];
        args[19] = values[4];
        args[1] = (s32)&args[5];
        fn_802146BC(args, -0x3E7, -0x3E7, 1, map[4], map[3], map[2], map[0]);
        fn_802E30C8((const char *)(base + 0x760), arg0);
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset

#pragma push
#pragma small_data on
extern "C" s32 fn_80214934(const void* arg0, s32 arg1, void* arg2, s32 arg3) {
    s32 end = fn_80029004((const char*)arg1, 0x2e);
    if (end == 0) {
        end = (s32)((const char*)arg1 + strlen((const char*)arg1));
    }
    return ((s32 (*)(void*, s32, const char*, ...))fn_801345D8)(arg2, arg3, lbl_8055B808, (s32)arg0, end - arg1, (const char*)arg1);
}
#pragma small_data off
#pragma pop

#pragma push
#pragma dont_inline on
extern "C" void fn_802149C4(s32 arg0) {
    char sp8[0x64];
    register char *buf = sp8;
    fn_80214934(lbl_8055B810, arg0, buf, 0x64);
    fn_8021481C(sp8);
}
#pragma dont_inline reset
#pragma pop
extern "C" s32 fn_80218C14(s32, s32);
extern "C" s32 fn_80214934(const void*, s32, void*, s32);
extern "C" s32 fn_8021481C(void*);
extern "C" char lbl_8033D388[];
extern "C" char lbl_8033D268[];
extern "C" char lbl_8055B810[];
extern "C" void fn_802149FC(s32 arg0) {
    char sp8[0x64];
    fn_80214934(lbl_8033D268, arg0, sp8, 0x64);
    fn_8021481C(sp8);
}

#pragma scheduling invalid_target
extern "C" s32 fn_80214A38(s32 arg0) {
    s32 result = 0;
    s32 check = fn_802168E4();
    if (check != 0) result = ((s32 (*)(s32, s32))fn_802168D4)(check, arg0);
    else ((void (*)(const char *, ...))fn_802E317C)(lbl_8033D274);
    return result;
}
#pragma scheduling on
extern "C" void fn_802192AC(void);
extern "C" void fn_80219354(void);
#pragma scheduling invalid_target
extern "C" void fn_80214A9C(s32 arg0) {
    s32 temp = fn_802168E4();
    if (temp != 0) {
        ((s32 (*)(s32, s32, float))fn_802168CC)(temp, arg0, lbl_80563434);
    } else {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8033D2A0);
    }
}
#pragma scheduling on
extern "C" s32 fn_802168D0(s32, s32, float);
extern "C" char lbl_8033D2C0[];
extern "C" void fn_80214AF0(s32 arg0) {
    s32 temp = fn_802168E4();
    if (temp != 0) {
        ((s32 (*)(s32, s32, float))fn_802168D0)(temp, arg0, lbl_80563434);
    } else {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8033D2C0);
    }
}

#pragma scheduling invalid_target
extern "C" void fn_80214B44(s32 arg0) {
    s32 temp = fn_802168E4();
    if (temp != 0) {
        ((s32 (*)(s32, s32))fn_802168DC)(temp, arg0);
    } else {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8033D2E0);
    }
}
#pragma scheduling on
extern "C" s32 fn_802168D8(s32);
extern "C" char lbl_8033D304[];
extern "C" void fn_80214B94(s32 arg0) {
    s32 temp = fn_802168E4();
    if (temp != 0) {
        ((s32 (*)(s32, s32))fn_802168D8)(temp, arg0);
    } else {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8033D304);
    }
}

extern "C" void fn_80214BE4(s32 arg0, s32 arg1, s32 arg2) {
    s32 obj = fn_802168E4();
    if (obj != 0) {
        ((void (*)(s32, s32, s32, s32))fn_802168E0)(obj, arg0, arg1, arg2);
    } else {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8033D328);
    }
}

extern "C" void fn_80214C54(s32 arg0, s32 arg1) {
    if (fn_802168E4() != 0) {
        fn_80218C14(arg0, arg1);
    } else {
        fn_802E317C(lbl_8033D388);
    }
}

#pragma dont_inline on
extern "C" void fn_80214CB4(s32 arg0) {
    s32 temp = fn_802168E4();
    if (temp != 0) {
        ((s32 (*)(s32, s32))fn_802180E0)(temp, arg0);
    } else {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8033D3B0);
    }
}
#pragma dont_inline reset

extern "C" s32 lbl_80490528[];
extern "C" s32 fn_802168E4(void);
extern "C" s32 fn_80218120(void);
extern "C" s32 fn_802E317C(const char *);
extern "C" char lbl_8033D3D4[];
extern "C" s32 fn_80214D04(void) {
    if (fn_802168E4() != 0) {
        return fn_80218120();
    }
    fn_802E317C(lbl_8033D3D4);
    return 0;
}

extern "C" f32 fn_80214D48(void) {
    return lbl_8055EF10;
}

#pragma use_lmw_stmw off
extern "C" void fn_80214D50(s32 arg0) {
    struct Entry {
        s32 unk0;
        f32 scale;
        void *objects[4];
        s32 unk18;
        s32 unk1C;
    };
    s32 index;
    s32 offset;
    Entry *table;
    Entry *entry;
    void *obj;
    f32 value;

    if (fn_80206430() == 0)
        return;

    index = lbl_8055EF5C + 1;
    lbl_8055EF5C = index;
    if (index >= 4) {
        index = 0;
        lbl_8055EF5C = 0;
    }

    offset = arg0 * 0x18;
    table = (Entry *)lbl_80490558;
    entry = (Entry *)((char *)table + offset);
    obj = entry->objects[index];
    if (obj == 0)
        return;

    value = entry->scale * fn_80209028();
    if (value != *(f32 *)((char *)obj + 8)) {
        *((u8 *)obj + 0x4D) = 1;
        *(f32 *)((char *)obj + 8) = value;
        *((u8 *)obj + 0x49) = 1;
        *((u8 *)obj + 0x4B) = 0;
        *((u8 *)obj + 0x4A) = 0;
    }
}
#pragma use_lmw_stmw reset
extern "C" void fn_80214FD8(s32 arg0, s32 arg1) {
    ((s32 (*)(s32, s32, s32))fn_80214E10)(arg0, arg1, 0);
}

extern "C" s32 fn_80215194(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_802151D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_80214FE0(s32, s32, s32, s32);
extern "C" void fn_80215214(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_80214FE0(arg0, arg1, arg2, 1);
}

extern "C" void fn_8021521C(s32 arg0, s32 arg1, s32 arg2) { fn_80214FE0(arg0, arg1, 0, arg2); }

extern "C" s32 fn_80215228(void) {
    return stricmp((const char *)lbl_8033CAE8, lbl_8055B6B0) == 0;
}

extern void *lbl_8055EF38;
extern "C" void* fn_8021525C(void) {
    return lbl_8055EF38;
}

extern u8 lbl_8033CAE8[];
extern "C" void *fn_80215264(void) {
    return lbl_8033CAE8;
}

extern "C" s32 fn_80215270(s32 arg0, s32 arg1) {
    s32 *row;
    if (arg1 >= 3) {
        arg1 = 1;
    }
    row = lbl_80490528 + (arg1 * 4);
    return row[arg0];
}

extern "C" void fn_80215298(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 arg4, s32 arg5, u32 arg6) {
    *arg0 = arg4;
    *arg2 = arg4 + arg6 - 0x1A;
    *arg1 = arg4 + ((((s32)((u32)arg6 >> 31)) + (s32)arg6) >> 1);
    *arg3 = arg5 + 4;
}

#pragma dont_inline on
extern "C" void fn_802152C8(void) {
}
#pragma dont_inline reset

extern "C" s32 fn_802192A4(void *, s32);
#pragma dont_inline on
extern "C" void fn_802152C8(void);
#pragma dont_inline reset
extern "C" s32 fn_802152CC(void) {
    fn_802152C8();
    return 0;
}
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802152F0(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" s32 __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80215348(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) {
            ((s32 (*)(void *))fn_80128668)(arg0);
        }
    }
    return (s32)arg0;
}

extern "C" void fn_802153A0(void) {
}

extern "C" s32 fn_802168BC(s32);
extern "C" void fn_8021915C(void *, unsigned int);
extern "C" s32 fn_802153A4(void) {
    return 0;
}

extern "C" s32 fn_802153AC(void *arg0, u32 arg1) {
    s32 (*callback)(s32);
    if (arg1 == *(u16 *)((char *)arg0 + 0x244)) {
        callback = *(s32 (**)(s32))((char *)arg0 + 0x248);
        if (callback == 0 || callback(*(s32 *)((char *)arg0 + 0x24C)) != 0) {
            fn_802168BC(*(s32 *)((char *)arg0 + 0x24C));
        }
        return 1;
    }
    return 0;
}

extern "C" void fn_80215414(void) {

}

extern "C" void fn_80215418(void) {

}

extern "C" void fn_8021541C(void) {

}

extern "C" void fn_80215420(void) {

}

extern "C" void fn_80215424(void) {

}

extern "C" void fn_80215428(void *arg0) {
    *(u8 *)((char *)arg0 + 0x19) = 1;
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" void fn_80215444(void *arg0) {
    *(u8 *)((char *)arg0 + 0x19) = 0;
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" void fn_80215464(void) {

}

extern "C" void fn_80215468(void) {

}

extern "C" void fn_8021546C(void) {

}

extern "C" void fn_80215470(void) {

}

extern "C" void fn_80215474(void) {

}

extern "C" void fn_80215478(void* arg0) {
    *(u8*)((char*)arg0 + 0x18) = 1;
}

extern "C" void fn_80215484(void* arg0) {
    *(u8*)((char*)arg0 + 0x18) = 0;
}

extern "C" s32 fn_80215490(void) {
    return 0;
}

extern "C" s32 fn_80215498(void) {
    return 0;
}

extern "C" void fn_802154A0(void *arg0) {
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" u32 fn_802154B8(void) { return 1; }

extern "C" s32 fn_802154C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_80215500(void) {

}

#pragma scheduling off
extern "C" void fn_80215504(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    f32 rate = lbl_80563450;
    s32 value8 = *(s32 *)((u8 *)arg0 + 8);
    s32 value4 = *(s32 *)((u8 *)arg0 + 4);
    fn_8022BAD0(value8, arg1, arg2, 0, arg4, arg5,
                value4, arg6, 0, rate);
}
#pragma scheduling on
extern "C" void fn_80215544(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    fn_8022AC1C(*(s32 *)((char *)arg0 + 8), *(s32 *)((char *)arg0 + 4), arg1, arg2, arg3, arg4, arg5, arg6);
}

extern "C" s32 fn_802155AC(void) {
    return 4;
}

extern "C" void fn_802C4C80(void*);
extern "C" int lbl_8033D528[];
extern "C" void* __dt__14CollisionSpaceFv_802155B4(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_8033D528;
        fn_802C4C80(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_80029004(const char *, s32);
extern "C" s32 fn_801345D8(void *, s32, const char *, s32, s32, const char *);
extern "C" unsigned long strlen(const char *);
extern "C" s32 fn_802C4F14(s32);
extern "C" s32 fn_802C4C90(s32, s32, s32, s32, s32);
extern "C" void fn_80215618(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 rem = arg3 % fn_802C4F14(*(s32 *)((char *)arg0 + 4));
    fn_802C4C90(*(s32 *)((char *)arg0 + 4), arg1, arg2, rem, 0);
}

extern "C" void fn_802C4F2C(s32, s32 *, s32 *);
extern "C" s32 fn_802C4EE4(s32);
extern "C" s32 fn_802C4EFC(s32);
#pragma use_lmw_stmw off
extern "C" void fn_8021568C(void *arg0, s32 arg1, s32 arg2,
                            s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6,
                            s32 arg7) {
    s32 spC = 0;
    s32 sp8 = 0;

    fn_802C4F2C(*(s32 *)((u8 *)arg0 + 4), &spC, &sp8);
    *arg3 = arg1 - spC;
    *arg4 = arg2 - sp8;
    *arg5 = *arg3 + fn_802C4EE4(*(s32 *)((u8 *)arg0 + 4));
    *arg6 = *arg4 + fn_802C4EFC(*(s32 *)((u8 *)arg0 + 4));
}
#pragma use_lmw_stmw reset
extern "C" s32 fn_80215730(void *arg0) {
    return fn_802C4F14(*(s32*)((u8*)arg0 + 4));
}

  void fn_802C2FC4(int);
  s32 fn_80128668(void *);
extern "C" void fn_802C40E8(void *, s32, s32);
void fn_802C4F2C(int, int *, int *);
int fn_802C4EE4(int);
int fn_802C4EFC(int);
extern "C" char lbl_8033D504[];
extern "C" s32 fn_802C2FC4(s32);
extern "C" void *fn_80215738(void *arg0, s32 arg1) {
    s32 old;
    if (arg0 != 0) {
        old = *(s32 *)((char *)arg0 + 4);
        *(char **)arg0 = lbl_8033D504;
        if (old != 0) fn_802C2FC4(old);
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" void fn_802157A8(void *arg0, s32 arg1, s32 arg2, u32 arg3) {
    u32 divisor = *(u32 *)((u8 *)arg0 + 0xC);
    s32 callback = *(s32 *)((u8 *)arg0 + 4);
    u32 remainder = arg3 % divisor;
    if (callback != 0) {
        fn_802C40E8((void *)callback, arg1, arg2 - *(s32 *)((u8 *)arg0 + 8) * remainder);
    }
}

extern "C" void fn_802157DC(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6) {
    s32 var_r0;
    void *temp_r5;

    *arg3 = arg1;
    *arg4 = arg2;
    temp_r5 = *(void **)((u8 *)arg0 + 4);
    if (temp_r5 != 0) {
        var_r0 = *(s32 *)((u8 *)temp_r5 + 8);
    } else {
        var_r0 = 0;
    }
    *arg5 = *arg3 + var_r0;
    *arg6 = *arg4 + *(s32 *)((u8 *)arg0 + 8);
}

extern "C" s32 fn_8021581C(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" void fn_80215824(void) {

}

extern "C" void fn_80215828(void *self, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5, void *arg6) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2(void *, void *, void *, void *);
    };
    ((Obj *)self)->v2(arg1, arg2, arg3, arg6);
}

extern "C" s32 fn_8021583C(void *arg0, s32 unused1, s32 unused2, s32 arg1, s32 arg2) {
    struct Local {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void call(s32, s32, s32*, s32*, s32*, s32*);
    };
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 result;
    ((Local*)arg0)->call(unused1, unused2, &sp14, &sp10, &spC, &sp8);
    result = 0;
    if (arg1 >= sp14 && arg1 < spC && arg2 >= sp10 && arg2 < sp8)
        result = 1;
    return result;
}

extern "C" void fn_802158C8(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf1();
}

class Vf4Obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_802158DC(void *arg0) {
    Vf4Obj *obj = *(Vf4Obj **)((char *)arg0 + 0x244);
    obj->vf2();
}

extern "C" void fn_802158F0(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf3();
}

extern "C" void fn_80215904(void *arg0) {
    fn_802192AC();
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf5();
}

extern "C" void fn_80215944(void *arg0) {
    fn_80219354();
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf6();
}

extern "C" void fn_80215984(void *arg0) {
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf10();
}

extern "C" void fn_80215998(void *arg0) {
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf11();
}

extern "C" void fn_802159AC(void *arg0) {
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf13();
}

extern "C" void fn_802159C0(void *arg0) {
    ((VfObj *)*(void **)((char *)arg0 + 0x244))->vf14();
}

extern "C" void fn_802159D4(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf19();
}

extern "C" void fn_802159E8(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf4();
}

extern "C" void fn_802159FC(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf12();
}

extern "C" void fn_80215A10(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x18) = 1;
    ((VfObj *)*(void **)((u8 *)arg0 + 0x244))->vf15();
}

extern "C" void fn_80215A2C(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
    ((VfObj *)*(void **)((u8 *)arg0 + 0x244))->vf16();
}

extern "C" void fn_80215A48(void *arg0) {
    u8 value = *((u8 *)arg0 + 0x1A);
    *((u8 *)arg0 + 0x19) = 1;
    if (value != 0) *((u8 *)arg0 + 0x234) = 1;
    void *obj = *(void **)((u8 *)arg0 + 0x244);
    void **vt = *(void ***)obj;
    ((void (*)(void *))*(void **)((u8 *)vt + 0x4C))(obj);
}

#pragma dont_inline on
#pragma dont_inline reset
extern "C" s32 fn_80215AA4(void *, s32);
#pragma scheduling invalid_target
extern "C" s32 fn_80215A74(void *arg0, s32 arg1) {
    u8 *self = (u8 *)arg0;
    u8 enabled = self[0x1A];
    self[0x19] = 0;
    if (enabled != 0) {
        self[0x234] = 1;
        ((VfObj *)*(void **)(self + 0x244))->vf18();
    } else {
        return fn_80215AA4(arg0, arg1);
    }
}
#pragma scheduling on
extern "C" s32 fn_80215AA4(void *arg0, s32 arg1) {
    class Callback {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual s32 call();
    };
    Callback *obj = *(Callback **)((u8 *)arg0 + 0x244);
    if (obj->call() != 0) return 1;
    return fn_802192A4(arg0, arg1);
}

extern "C" void fn_80215B08(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf21();
}

extern "C" void fn_80215B1C(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf7();
}

extern "C" void fn_80215B30(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf8();
}

extern "C" void fn_80215B44(void *arg0) {
    VfObj *obj = *(VfObj **)((char *)arg0 + 0x244);
    obj->vf9();
}

extern "C" void fn_802191F0(void);
extern "C" void fn_80215B58(void *arg0, s32 arg1, s32 arg2) {
    fn_802191F0();
    ((void **)*(void ***)((char *)arg0 + 0x244))[1] = (void *)arg1;
    ((void **)*(void ***)((char *)arg0 + 0x244))[2] = (void *)arg2;
}

extern "C" s32 fn_80215BAC(void) {
    return -1;
}

extern "C" void fn_80215BB4(void) {

}

extern "C" void fn_80215BB8(void) {

}

extern "C" void fn_80215BBC(void) {

}

extern "C" s32 fn_80215BC0(void) {
    return 0;
}

extern "C" void fn_80214CB4(s32);
extern "C" void fn_80230E90(s32);
extern "C" s32 fn_80215BC8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_r6;

    var_r6 = 0;
    if (arg1 >= *(s32 *)((char *)arg0 + 4) && arg1 < *(s32 *)((char *)arg0 + 0xC) &&
        arg2 >= *(s32 *)((char *)arg0 + 8) && arg2 < *(s32 *)((char *)arg0 + 0x10)) {
        var_r6 = 1;
    }
    return var_r6;
}

extern "C" s32 fn_80215C08(void *arg0) {
    return *(s32 *)((char *)arg0 + 0xC) - *(s32 *)((char *)arg0 + 4);
}

extern "C" void fn_80215C18(void *arg0) {
    fn_80214CB4(*(u8 *)((char *)arg0 + 0x18) == 0);
}

extern "C" s32 fn_80215C28(s32 arg0, s32 arg1) {
    switch (arg1) {
    case 0x125:
        fn_80214CB4(0);
        fn_80230E90(0);
        goto done;
    case 0x127:
        fn_80214CB4(1);
        fn_80230E90(0);
        goto done;
    case 0x126:
    case 0x128:
        goto done;
    default:
        return 0;
    }
done:
    return 1;
}

extern "C" void fn_80215CA0(void) {

}

extern "C" void fn_80215CA4(void) {

}

extern "C" void fn_80215CA8(void) {
	fn_80221E7C();
}

extern "C" void fn_80215CAC(void) {

}

extern "C" void fn_80215CB0(void) {

}

extern "C" void fn_80215CB4(void) {

}

extern "C" void fn_80215CB8(void) {

}

extern "C" void fn_80215CBC(void) {

}

extern "C" void fn_80215CC0(void) {

}

extern "C" void fn_80215CC8(void) {

}

extern "C" void fn_80215CCC(void) {

}

extern "C" void fn_80215CD0(void) {

}

extern "C" void fn_80215CD4(void) {

}

extern "C" void fn_80215CD8(void) {

}

extern "C" void fn_80215CDC(void) {

}

extern "C" void fn_80215CE0(void) {

}

extern "C" s32 fn_80215CE4(void) {
    return 0;
}

extern "C" s32 fn_80215CEC(void) {
    return 0;
}

extern "C" void fn_80215CC4(void) {

}


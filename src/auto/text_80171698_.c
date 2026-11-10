#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];
extern void fn_80128658(void *);
extern void fn_80128668(void *);
extern void fn_801777D0(void *);
extern void __dt__Q210JASDrumSet5TPercFv(void *, int);
extern char lbl_80330ED8[];
void *fn_80171698(void) {
    extern void *fn_801284F8(int, void *);
    extern void fn_801414A4(void *);
    extern void fn_801777CC(void *);
    extern char lbl_80330EC8[];
    extern char lbl_80330ED8[];
    struct Object {
        void *vtable;
        void *vtable2;
        void *base;
        s32 zero;
        s32 count;
    };
    volatile struct Object *obj;
    s32 diff;
    s32 n;
    s32 m;
    s32 flag;
    s32 check;
    s32 hi;
    s32 valid;
    u32 start;
    u32 end;

    obj = (volatile struct Object *)fn_801284F8(0xA1C, lbl_80330EC8);
    if (obj != 0) {
        obj->vtable = lbl_80330ED8;
        obj->vtable2 = lbl_80330ED8 + 0x10;
        obj->base = (char *)obj + 0x14;
        start = (u32)obj + 0x3C;
        end = (u32)obj + 0xA14;
        valid = start < end;
        obj->count = 0x40;
        obj->zero = 0;
        if (valid) {
            diff = (s32)(end - start);
            n = (diff + 0x27) / 40;
            m = n + 1;
            if (m > 8) {
                check = 0;
                if (start <= end) {
                    flag = 1;
                    if ((diff & (s32)0x80000000) == 0 &&
                        ((diff + 0x27) & (s32)0x80000000) != 0)
                        flag = 0;
                    if (flag != 0) {
                        check = 1;
                        hi = n & (s32)0x80000000;
                        if (hi == 0 && hi != (m & (s32)0x80000000))
                            check = 0;
                    }
                }
                if (check != 0)
                    fn_801414A4((char *)obj + 0xA14);
            }
        }
    }
    if (obj != 0)
        fn_801777CC((char *)obj + 4);
    return (void *)obj;
}

void *fn_801717B4(void *arg0, int arg1) {
    struct Local {
        void *field_00;
        void *field_04;
        unsigned char *field_08;
        int field_0C;
        int field_10;
        char pad[0xA00];
    };
    struct Local *obj = (struct Local *)arg0;
    int i;
    int offset;
    unsigned char *item;
    int zero;

    if (arg0 != 0) {
        obj->field_00 = lbl_80330ED8;
        obj->field_04 = lbl_80330ED8 + 0x10;
        if (arg0 != 0) {
            fn_801777D0(&obj->field_04);
            i = 0;
            offset = 0;
            zero = 0;
            while (i < obj->field_0C) {
                item = obj->field_08 + offset;
                fn_80128658(*(void **)(item + 0x18));
                *(void **)(item + 0x18) = (void *)zero;
                offset += 0x28;
                i++;
            }
            __dt__Q210JASDrumSet5TPercFv((char *)obj + 0xA14, -1);
            if (&obj->field_08 != 0) {
                if (&obj->field_08 != 0) {
                    obj->field_08 = (unsigned char *)zero;
                    obj->field_0C = zero;
                    obj->field_10 = zero;
                }
            }
            if (arg1 > 0)
                fn_80128668(obj);
        }
    }
    return obj;
}

  void fn_8017188C(void *arg0) {
    int i = 0;
    int offset = 0;
    while (i < *(int *)((char *)arg0 + 0xC)) {
        unsigned char *entry = *(unsigned char **)((char *)arg0 + 8) + offset;
        if (entry[0x25] && !entry[0x24] && *(int *)*(void **)(entry + 0x18) > 1)
            ((void (*)(void *, void *, int, const char *))fn_80141558)((char *)arg0 + 0xA14, entry, 2, fn_8000FDF0 + 0x110);
        offset += 0x28;
        i++;
    }
}
#pragma use_lmw_stmw on

void fn_80171930(void) {
}

extern s32 fn_801B2F24(void);
extern s32 fn_801B2F54(s32);
extern void fn_8017960C(s32);
extern s32 fn_80139B5C(s32);
extern void fn_801D488C(s32, s32, s32, f32 *, f32, f32, f32);
extern f32 lbl_80561A30;
#pragma push
#pragma paired off
#pragma paired_single off
void fn_80171934(void *p) {
    s32 outerCount;
    u8 *item;
    s32 off;
    s32 outer;
    s32 inner;
    f32 scale;
    outerCount = fn_801B2F24();
    scale = lbl_80561A30;
    outer = 0;
    while (outer < outerCount) {
        inner = 0;
        off = 0;
        while (inner < *(s32 *)((u8 *)p + 0xC)) {
            item = *(u8 **)((u8 *)p + 8) + off;
            if (item[0x24] == 0 && fn_801B2F54(outer) >= *(s32 *)(item + 0x20)) {
                s32 selection = ((s32 (*)(s32))fn_8017960C)(outer);
                if (((s32 (*)(s32, s32))fn_80139B5C)(selection, *(s32 *)(item + 0x18)) != 0) {
                    f32 vec[3];
                    f32 x, y, z;
                    vec[0] = *(f32 *)(item + 0) + *(f32 *)(item + 0xC);
                    x = vec[0] * scale;
                    vec[1] = *(f32 *)(item + 4) + *(f32 *)(item + 0x10);
                    y = vec[1] * scale;
                    vec[2] = *(f32 *)(item + 8) + *(f32 *)(item + 0x14);
                    vec[1] = y;
                    vec[0] = x;
                    vec[2] *= scale;
                    ((void (*)(s32, s32, s32, f32 *))fn_801D488C)(*(s32 *)(item + 0x1C), 1, 1, vec);
                    item[0x24] = 1;
                }
            }
            off += 0x28;
            inner++;
        }
        outer++;
    }
}
#pragma pop
void fn_80171A4C(void *arg0) {
    int offset;
    int count;

    for (count = 0, offset = 0; count < *(int *)((char *)arg0 + 12); count++, offset += 0x28) {
        unsigned char *base = *(unsigned char **)((char *)arg0 + 8);
        base[offset + 0x24] = 0;
    }
}

#pragma ppc_psq_save off
#pragma push
#pragma cplusplus on
extern "C" s32 *__AXFXGetLfoSinTable_801769CC(void);
extern "C" void *fn_8001285C(s32);
extern "C" void *fn_801399FC(void);
extern "C" s32 fn_801D4888(void);
extern "C" void fn_801E9DC4(void *);
extern "C" void fn_801E9E30(void *, void *);
extern "C" void fn_802E30C8(void *, s32);
extern "C" int strcmp(const char *, const char *);
extern char lbl_80330F18[];
extern char lbl_80330F24[];
__declspec(section ".sdata") extern char lbl_8055A280[];
__declspec(section ".sdata") extern char lbl_8055A288[];
__declspec(section ".sdata") extern char lbl_8055A290[];
__declspec(section ".sdata") extern char lbl_8055A294[];
extern f32 lbl_80561A34;
extern "C" void fn_80171A80(void *arg0) {
    class Node {
    public:
        virtual const char *m0();
        virtual void m1();
        virtual void m2();
        virtual void m3(const char *);
        virtual void m4();
        virtual void m5();
        virtual int m6(const char *, int);
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual char m10(const char *, int);
        virtual void m11();
        virtual void m12();
        virtual void m13();
        virtual void m14();
        virtual void m15();
        virtual void m16();
        virtual void m17();
        virtual void m18();
        virtual void m19();
        virtual void m20();
        virtual void m21(const char *);
    };
    class Mgr {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual void m11();
        virtual void m12();
        virtual void m13();
        virtual void m14();
        virtual void m15();
        virtual void m16();
        virtual void m17();
        virtual void m18();
        virtual void m19();
        virtual void m20();
        virtual void m21();
        virtual Node *get(int);
    };
    char sp8[8];
    f32 v[4];
    f32 *p;
    int k, j;
    char *e;
    int n;
    f32 d1, d2;
    Mgr *mgr = *(Mgr **)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
    int i = 0;
    f32 y = lbl_80561A34;
    Node *node;
    while ((node = mgr->get(i)) != 0) {
        if (strcmp(node->m0(), lbl_8055A280) == 0) {
            n = *(int *)((char *)arg0 + 0xC);
            *(int *)((char *)arg0 + 0xC) = n + 1;
            e = *(char **)((char *)arg0 + 8) + n * 0x28;
            node->m3(lbl_8055A288);
            *(int *)(e + 0x1C) = fn_801D4888();
            *(char *)(e + 0x25) = node->m10(lbl_80330F18, 1);
            *(int *)(e + 0x20) = node->m6(lbl_8055A290, 0);
            node->m21(lbl_8055A294);
            p = (f32 *)fn_801399FC();
            *(f32 **)(e + 0x18) = p;
            k = 2;
            *(char *)(e + 0x24) = 0;
            v[3] = p[3] - p[7];
            v[2] = p[2] - p[6];
            v[1] = p[3] - p[5];
            v[0] = p[2] - p[4];
            d1 = v[2] * v[2] + v[3] * v[3];
            d2 = v[0] * v[0] + v[1] * v[1];
            if (d2 > d1) {
                d1 = d2;
                k = 0;
            }
            v[1] = p[5] - p[7];
            v[0] = p[4] - p[6];
            if (v[0] * v[0] + v[1] * v[1] > d1)
                k = 1;
            fn_801E9DC4(sp8);
            for (j = 0; j < 2; j++) {
                f32 *q = (f32 *)(*(char **)(e + 0x18) + ((k + j) % 3) * 8);
                f32 *o = (f32 *)(e + j * 12);
                o[0] = q[2];
                o[1] = y;
                o[2] = q[3];
                fn_801E9E30(sp8, o);
            }
        }
        i++;
    }
    fn_802E30C8(lbl_80330F24, *(int *)((char *)arg0 + 0xC));
}
#pragma pop

void fn_80171CE0(void) {

}


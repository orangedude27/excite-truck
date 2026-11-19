#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];
extern void fn_80128658(void *);
extern void fn_80128668(void *);
extern void fn_801777D0(void *);
extern void __dt__Q210JASDrumSet5TPercFv(void *, int);
extern char lbl_80330ED8[];
void *fn_80171698(void) {
#pragma scheduling invalid_target
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
    u32 start;
    u32 end;
    s32 valid;
    s32 diff;
    s32 n;
    s32 m;
    s32 flag;
    s32 check;
    s32 hi;

    obj = (volatile struct Object *)fn_801284F8(0xA1C, lbl_80330EC8);
    if (obj != 0) {
        start = (u32)obj + 0x3C;
        end = (u32)obj + 0xA14;
        obj->vtable = lbl_80330ED8;
        obj->vtable2 = lbl_80330ED8 + 0x10;
        obj->base = (char *)obj + 0x14;
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
                        hi = n & (s32)0x80000000;
                        flag = 1;
                        if (hi == 0 && hi != (m & (s32)0x80000000))
                            flag = 0;
                    }
                    check = flag;
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

#pragma push
#pragma use_lmw_stmw off
void *fn_801717B4(void *self, int shouldDelete) {
    // Deleting destructor: install the class vtable, unregister the audio
    // listener, free owned items, destroy the embedded JASDrumSet::TPerc,
    // reset the item array, then optionally free the object itself.
    struct Local {
        void *vtable;         // at 0x0
        void *listener;       // at 0x4: registered listener handle
        unsigned char *items; // at 0x8: array of 0x28-byte owned items
        int numItems;         // at 0xC
        int itemCapacity;     // at 0x10
        char pad[0xA00];      // up to the embedded JASDrumSet::TPerc at 0xA14
    };
    struct Local *obj = (struct Local *)self;
    void *p;
    unsigned char *item;
    int offset;
    int i;
    int zero;

    if (self != 0) {
        obj->vtable = lbl_80330ED8;
        obj->listener = lbl_80330ED8 + 0x10;
        p = self;
        if (self != 0)
            p = &obj->listener;
        fn_801777D0(p);
        i = 0;
        offset = 0;
        zero = 0;
        while (i < obj->numItems) {
            item = obj->items + offset;
            fn_80128658(*(void **)(item + 0x18));
            *(void **)(item + 0x18) = (void *)zero;
            offset += 0x28;
            i++;
        }
        __dt__Q210JASDrumSet5TPercFv((char *)obj + 0xA14, -1);
        if (&obj->items != 0) {
            if (&obj->items != 0) {
                obj->items = (unsigned char *)zero;
                obj->numItems = zero;
                obj->itemCapacity = zero;
            }
        }
        if (shouldDelete > 0)
            fn_80128668(obj);
    }
    return obj;
}
#pragma pop
void fn_8017188C(char *arg0) {
    int offset = 0;
    int i = 0;
    while (i < *(int *)(arg0 + 0xC)) {
        unsigned char *entry = *(unsigned char **)(arg0 + 8) + offset;
        if (entry[0x25] && !entry[0x24] && *(int *)*(void **)(entry + 0x18) > 1)
            ((void (*)(void *, void *, int, unsigned int))fn_80141558)(arg0 + 0xA14, entry, 2, 0x8000FF00);
        offset += 0x28;
        i++;
    }
}

void fn_80171930(void) {
}

extern s32 fn_801B2F24(void);
extern s32 fn_801B2F54(s32);
extern void fn_8017960C(s32);
extern s32 fn_80139B5C(s32);
extern void fn_801D488C(s32, s32, s32, f32 *, f32, f32, f32);
extern f32 lbl_80561A30;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
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
                    f32 x;
                    f32 y;
                    f32 vec[3];
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
/* TriggerMaster reset: clear the "already fired" byte (trigger+0x24) of every
 * trigger in the master's array so fn_80171934 may fire them again.  The array
 * base is at +0x8 and the number of triggers in use at +0xC, each trigger being
 * 0x28 bytes. */
void fn_80171A4C(void *triggerMaster) {
    #pragma scheduling invalid_target
    int offset;
    int count;
    count = 0;
    offset = 0;
    while (count < *(int *)((char *)triggerMaster + 12)) {
        unsigned char *triggers = *(unsigned char **)((char *)triggerMaster + 8);
        count++;
        triggers[offset + 0x24] = 0;
        offset += 0x28;
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
extern "C" void fn_802E30C8(void *, ...);
extern "C" int strcmp(const char *, const char *);
extern char lbl_80330F18[];
extern char lbl_80330F24[];
__declspec(section ".sdata") extern char lbl_8055A280[];
__declspec(section ".sdata") extern char lbl_8055A288[];
__declspec(section ".sdata") extern char lbl_8055A290[];
__declspec(section ".sdata") extern char lbl_8055A294[];
extern f32 lbl_80561A34;
#pragma processor 750
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
    f32 *o;
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
            o = (f32 *)e;
            for (j = 0; j < 2; j++) {
                f32 *q = (f32 *)(*(char **)(e + 0x18) + ((k + j) % 3) * 8);
                o[0] = q[2];
                o[1] = y;
                o[2] = q[3];
                fn_801E9E30(sp8, o);
                o += 3;
            }
        }
        i++;
    }
    fn_802E30C8(lbl_80330F24, *(int *)((char *)arg0 + 0xC));
}
#pragma pop

void fn_80171CE0(void) {

}


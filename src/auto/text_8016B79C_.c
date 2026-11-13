#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#pragma ppc_psq_save off
#pragma cplusplus on
extern "C" char lbl_80330A90[];
extern "C" void fn_80128670(s32);
extern "C" void fn_80131818(s32);
extern "C" void fn_80235380(void *, char *);
extern "C" void fn_802C2930(void *, s32);
extern "C" void *fn_8000AC38(void);
extern "C" void *fn_80131810(void);
extern "C" s32 fn_8016C5F0(void);
extern "C" void fn_8016C55C(void *, void *);
extern "C" void *fn_8016C598(void *, int, int);
extern "C" s8 fn_8016C768(void *, void *, void *);
extern "C" s32 fn_8016CD4C(void *);
extern "C" void *fn_8016CD68(void *, s32, s32);
extern "C" s32 fn_8016CDF8(void *, void *);
extern "C" void fn_8016CE94(void *, f32);
extern "C" int fn_8016C760(void *);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" f32 lbl_8056199C;
#pragma cplusplus reset
extern s32 fn_801284F8(s32, const char *);
extern char lbl_80330A90[];
extern void fn_80144504(void **);
extern void *fn_8016CEC0(void *, s32);
extern void fn_8016CEFC(void *);
extern void *fn_8016CF08(void *);
extern void *fn_8016D024(void *);
extern void fn_8016D278(void *);
extern void fn_8016CE9C(void *, void **);
extern void fn_8016A0B0(void);
extern void fn_8016C328(void *);
extern s32 fn_80207848(void *, s32);
extern char lbl_80330990[];
extern s32 lbl_8055E378;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80161C38(void);
extern u8 *fn_80131234(const char *);
extern s32 fn_801609C4(s32);
int fn_8012850C(int, int);
extern char lbl_80330B7C[];
extern char lbl_80330B8C[];
extern char lbl_8055A248;
extern char lbl_8055A268;
extern void fn_80130978(void *, s32, f32);
extern void fn_8014784C(void *, const char *, const char *, s32);
extern void fn_801475D0(void *, const char *, const char *, ...);
extern void fn_8016A438(void);
extern char lbl_8033072C[];
extern char lbl_803308A0[];
extern f32 lbl_80561980;
extern f32 lbl_80561998;
extern f32 lbl_805619A0;
extern f32 lbl_805619A4;
extern void fn_802AE0E0(s32);
extern char lbl_80330AEC[];
extern char lbl_803306D0[];
extern void fn_801345D8(void *, s32, const char *, ...);
extern void fn_802E317C(const char *, ...);
extern void fn_8001B450(s32);
typedef struct { f32 first; f32 second; } FloatPair8016A6B0;
extern FloatPair8016A6B0 fn_8016A6B0(const char *, s32);
extern s32 fn_8001B308(void *, s32, s32);
extern void fn_8016A15C(char *);
extern void fn_802BAF98(void *, s8);
void *fn_80128668(void *);
void fn_802C6CF8(int);
extern s32 fn_8002F6AC(void *);
extern void *fn_80128668(void *);
extern s32 fn_8002F37C(void *, void *, s32, s32);
extern void fn_8016B4FC(void *);
extern s32 fn_802BAA68(s32, void *);
extern void fn_8016CDE0(void *);
extern void *fn_8016C168(void *, s32);
extern void *fn_8016C29C(void *, int);
extern int fn_8016C25C(int, int);
extern f32 lbl_80561984;
extern int fn_8000DA10();
typedef struct { s32 w[12]; } Blk8016C768;
typedef struct { s32 data; s32 index; s32 count; s32 data2; } List8016C768;
#define VT(obj, off) (*(void ***)(obj))[(off) / 4]
#define VFN(obj, off, ret, args) ((ret (*) args)VT(obj, off))
extern int stricmp(const char *, const char *);
extern int strcmp(const char *, const char *);
extern char lbl_8055A228, lbl_8055A230, lbl_8055A238, lbl_8055A240;
extern s32 fn_802C6FC0(s32, s32);
static inline void SetNodeF8(void *node) {
    if (node != 0) {
        f32 value = lbl_80561984;
        if (value != *(f32 *)((u8 *)node + 8)) {
            *(u8 *)((u8 *)node + 0x4D) = 1;
            *(f32 *)((u8 *)node + 8) = value;
        }
    }
}
#pragma cplusplus on
extern "C" void fn_80131818(s32);
class TObj4C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual int d7();
          virtual int d8(); virtual int d9(); virtual void d10(); virtual void d11();
    virtual f32 d12(); virtual void d13(); virtual f32 d14(); virtual void d15();
    virtual void d16();
    virtual void v4C();
};
#pragma cplusplus reset
void *fn_8016B79C(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 value = *(s32 *)((u8 *)arg0 + 0x10);
        if (value != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(value, fn_8016B4FC);
            *(s32 *)((u8 *)arg0 + 0x10) = 0;
            *(s32 *)((u8 *)arg0 + 0x14) = 0;
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void fn_8016B550(void *);
void *fn_8016B834(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 value = *(s32 *)((u8 *)arg0 + 0x10);
        if (value != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(value, fn_8016B550);
            *(s32 *)((u8 *)arg0 + 0x10) = 0;
            *(s32 *)((u8 *)arg0 + 0x14) = 0;
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void fn_8016AC24(void *);
void *fn_8016B8CC(void *obj, s32 shouldDelete) {
    /* Destroy/clear this object: run element destructor on owned array, reset fields, and optionally delete. */
    if (obj != 0) {
        s32 ownedArray = *(s32 *)((u8 *)obj + 0x10);
        if (ownedArray != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(ownedArray, fn_8016AC24);
            *(s32 *)((u8 *)obj + 0x10) = 0;
            *(s32 *)((u8 *)obj + 0x14) = 0;
            *(s32 *)obj = 0;
            *((s32 *)obj + 1) = 0;
            *((s32 *)obj + 2) = 0;
        }
        if (obj != 0) {
            *(s32 *)obj = 0;
            *((s32 *)obj + 1) = 0;
            *((s32 *)obj + 2) = 0;
        }
        if (shouldDelete > 0) fn_80128668(obj);
    }
    return obj;
}

#pragma cplusplus on
extern "C" s32 strlen(const char *);
extern "C" void fn_801308F4(void *, ...);
extern "C" void fn_80130980(void *, s32, s32, f32);
extern "C" void fn_801312EC(void *, void *);
extern "C" void fn_80131318();
extern "C" void fn_802ADFF4(s32, s32);
extern "C" void fn_802AE02C(s32, s32);
extern "C" void fn_802AE0B8(s32, s32);
extern "C" void fn_802AE168(s32);
extern "C" u8 *__AXGetStackHead(void);
extern "C" u8 lbl_8055A208;
extern "C" u8 lbl_8055A20C, lbl_8055A210;
extern "C" u32 lbl_8055E044;
extern "C" u8 lbl_8055E374;
extern "C" f32 lbl_8055E3C8, lbl_80561984, lbl_80561988;
extern "C" f64 lbl_80561990;
extern "C" u8 lbl_8043036C[];
extern "C" void fn_8016B964(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 f0, f1, f2, f4;
    s32 count, var_r28, var_r6, state;
    u8 *src, *dst;
    u8 c;
    void *obj;
    if (*(s32 *)((u8 *)arg0 + 0xC) == 0) return;
    ((void (*)(void *, s32))fn_801308F4)((u8 *)arg0 + 0x30, 0x14);
    var_r28 = arg3;
    var_r6 = 0;
    if (arg3 != 0) {
        f1 = *(f32 *)((u8 *)arg0 + 4);
        f0 = lbl_80561980;
        if (f1 > f0) {
            f2 = lbl_8055E3C8;
            f4 = lbl_80561984;
            f1 = f2 - f1;
            f0 = f1 - f0;
            f0 = f0 / f4;
            if (f4 < f0) f4 = f0;
            if (f4 > lbl_80561980) f4 = lbl_80561980;
            var_r6 = (s32)(lbl_80561980 + f4 * (lbl_80561988 + (f32)arg3 - lbl_80561980));
            var_r28 = arg3 - var_r6;
        }
    }
    ((void (*)(void *, s32, void *, ...))fn_801345D8)((u8 *)arg0 + 0x44, 0x14, &lbl_8055A208, var_r6);
    if ((s8)lbl_8055E374 == 0) {
        fn_801312EC(lbl_8043036C, lbl_803306D0);
        lbl_8055E374 = 1;
    }
    if (*(u8 *)((u8 *)arg0 + 0x10) != 0) {
        dst = (u8 *)arg0 + 0x9E; src = &lbl_8055A20C; count = 0x14;
        goto copy1;
loop1:
        if (--count > 0) goto copy1;
        dst[-1] = 0;
        goto after1;
copy1:
        c = *src++;
        *dst++ = c;
        if ((s8)c != 0) goto loop1;
after1:
        dst = (u8 *)arg0 + 0x58; src = &lbl_8055A20C; count = 0x14;
        goto copy2;
loop2:
        if (--count > 0) goto copy2;
        dst[-1] = 0;
        goto after2;
copy2:
        c = *src++;
        *dst++ = c;
        if ((s8)c != 0) goto loop2;
after2:
        ;
    } else {
        fn_80130980((u8 *)arg0 + 0x9E, 0x14, 2, (f32)var_r28);
        if (*(u32 *)(lbl_8043036C + 8) != lbl_8055E044) fn_80131318();
        src = *(u8 **)(lbl_8043036C + 4); dst = (u8 *)arg0 + 0x58; count = 0x14;
        goto copy3;
loop3:
        if (--count > 0) goto copy3;
        dst[-1] = 0;
        goto after3;
copy3:
        c = *src++;
        *dst++ = c;
        if ((s8)c != 0) goto loop3;
after3:
        ;
    }
    ((void (*)(void *, s32, s32))fn_801308F4)((u8 *)arg0 + 0x6C, 0x14, arg1);
    ((void (*)(void *, s32, s32))fn_801308F4)((u8 *)arg0 + 0x8A, 0x14, arg1 - arg3);
    if (fn_801609C4(arg1) != -1) {
        src = __AXGetStackHead(); dst = (u8 *)arg0 + 0x80; count = 0xA;
        goto copy4;
loop4:
        if (--count > 0) goto copy4;
        dst[-1] = 0;
        goto after4;
copy4:
        c = *src++;
        *dst++ = c;
        if ((s8)c != 0) goto loop4;
after4:
        ;
    } else {
        src = &lbl_8055A210; dst = (u8 *)arg0 + 0x80; count = 0xA;
        goto copy5;
loop5:
        if (--count > 0) goto copy5;
        dst[-1] = 0;
        goto after5;
copy5:
        c = *src++;
        *dst++ = c;
        if ((s8)c != 0) goto loop5;
after5:
        ;
    }
    if (*(s32 *)((u8 *)arg0 + 0xF8) != 0) *((u8 *)arg0 + 8) = 0;
    state = *(s32 *)arg0;
    switch (state) {
    case 4:
        break;
    case 0:
        fn_802ADFF4(*(s32 *)((u8 *)arg0 + 0xC), *(s32 *)((u8 *)arg0 + 0xF4));
        if (strlen((const char *)arg0 + 0xDA) != 0) {
            obj = *(void **)((u8 *)arg0 + 0x2C);
            if (obj != 0 && *((u8 *)obj + 0x19) == 0) {
                *((u8 *)obj + 0x49) = 1; *((u8 *)obj + 0x4B) = 0; *((u8 *)obj + 0x4A) = 0;
            }
        } else {
            obj = *(void **)((u8 *)arg0 + 0x28);
            if (obj != 0 && *((u8 *)obj + 0x19) == 0) {
                *((u8 *)obj + 0x49) = 1; *((u8 *)obj + 0x4B) = 0; *((u8 *)obj + 0x4A) = 0;
            }
        }
        if (arg3 > 0) {
            obj = *(void **)((u8 *)arg0 + 0x14);
            if (obj != 0) {
                *((u8 *)obj + 0x49) = 1; *((u8 *)obj + 0x4B) = 0; *((u8 *)obj + 0x4A) = 0;
            }
        } else {
            obj = *(void **)((u8 *)arg0 + 0x18);
            if (obj != 0) {
                *((u8 *)obj + 0x49) = 1; *((u8 *)obj + 0x4B) = 0; *((u8 *)obj + 0x4A) = 0;
            }
        }
        *(s32 *)arg0 = 1;
        break;
    case 1:
        if (*(s32 *)((u8 *)arg0 + 0xFC) != 0 && *(f32 *)((u8 *)arg0 + 4) < lbl_80561980)
            *(f32 *)((u8 *)arg0 + 4) = lbl_8055E3C8;
        if (*(s32 *)((u8 *)arg0 + 0xFC) == 2 && *(u8 *)((u8 *)arg0 + 0x20) == 0) {
            obj = *(void **)((u8 *)arg0 + 0x1C); *(u8 *)((u8 *)arg0 + 0x20) = 1;
            if (obj != 0) { *((u8 *)obj + 0x49) = 1; *((u8 *)obj + 0x4B) = 0; *((u8 *)obj + 0x4A) = 0; }
        }
        if (*(s32 *)((u8 *)arg0 + 0x100) != 0) {
            fn_802AE02C(*(s32 *)((u8 *)arg0 + 0xC), *(s32 *)((u8 *)arg0 + 0xF4)); *(s32 *)arg0 = 2;
        }
        break;
    case 2:
        if (*(u8 *)((u8 *)arg0 + 9) != 0) {
            fn_802AE0B8(*(s32 *)((u8 *)arg0 + 0xC), *(s32 *)((u8 *)arg0 + 0xF4));
            obj = *(void **)((u8 *)arg0 + 0x24);
            if (obj != 0) { *((u8 *)obj + 0x49) = 1; *((u8 *)obj + 0x4B) = 0; *((u8 *)obj + 0x4A) = 0; }
            *(s32 *)arg0 = 3;
        }
        break;
    case 3:
        if (*(s32 *)((u8 *)arg0 + 0x104) != 0) {
            fn_802AE02C(*(s32 *)((u8 *)arg0 + 0xC), *(s32 *)((u8 *)arg0 + 0xF4)); *(s32 *)arg0 = 4;
        }
        break;
    }
    fn_802AE168(*(s32 *)((u8 *)arg0 + 0xC));
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void *fn_8016BE60(void *arg0) {
    u8 *object = (u8 *)fn_801284F8(0x1B4, lbl_803306D0 + 0x20);
    char *strings = lbl_803306D0;
    if (object != 0) {
        fn_80144504((void **)object);
        *(void **)object = lbl_80330990;
        fn_8016D278(object + 4);
        fn_8016D024(object + 0x30);
        fn_8016CF08(object + 0xAC);
        lbl_8055E378 = (s32)object;
        fn_8016CEFC(object + 4);
        for (s32 index = 0; index < *(s32 *)((u8 *)arg0 + 0x3E0); index++) {
            void *allocation = (void *)fn_801284F8(0x10, strings + 0x30);
            if (allocation != 0) allocation = fn_8016CEC0(allocation, index);
            void *entry = allocation;
            fn_8016CE9C(object + 4, &entry);
        }
        fn_8016A0B0();
        fn_8016C328(object + 0x30);
        {
            f32 initialValue = lbl_80561998;
            *(s32 *)(object + 0x98) = 0;
            *(u8 *)(object + 0x9C) = 1;
            *(f32 *)(object + 0xA0) = initialValue;
        }
        *(s32 *)(object + 0xA4) = fn_80207848(strings + 0x3C, 1);
        *(u8 *)(object + 0xA8) = 0;
    }
    return object;
}

#pragma cplusplus on
#pragma cplusplus reset
#pragma scheduling on
#pragma cplusplus on
extern "C" void *fn_8016BF74(void *arg0, s32 arg1) {
    class VObj { public: virtual void destroy(int); };
    struct Rec { s32 a, b, c, d; };
    VObj *p;
    Rec *data;
    register void *object = arg0;
    register s32 freeFlag = arg1;

    if (object != 0) {
        *(char **)((u8 *)object + 4) = lbl_80330A90;
        fn_80235380(*(void **)((u8 *)object + 0x20), lbl_80330A90);
        p = *(VObj **)((u8 *)object + 0x4C);
        if (p != 0) { if (p != 0) p->destroy(1); }
        p = *(VObj **)((u8 *)object + 0x54);
        if (p != 0) { if (p != 0) p->destroy(1); }
        p = *(VObj **)((u8 *)object + 0x58);
        if (p != 0) { if (p != 0) p->destroy(1); }
        p = *(VObj **)((u8 *)object + 0x50);
        if (p != 0) { if (p != 0) p->destroy(1); }
        p = *(VObj **)((u8 *)object + 0x5C);
        if (p != 0) { if (p != 0) p->destroy(1); }
        p = *(VObj **)((u8 *)object + 0x60);
        if (p != 0) { if (p != 0) p->destroy(1); }
        p = *(VObj **)((u8 *)object + 0x64);
        if (p != 0) { if (p != 0) p->destroy(1); }

        data = *(Rec **)((u8 *)object + 0x18);
        if (data != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(data->d, fn_8016C168);
            if (data != 0) {
                *(volatile s32 *)&data->a = 0;
                *(volatile s32 *)&data->b = 0;
                *(volatile s32 *)&data->c = 0;
                fn_80128668((void *)data);
            }
        }
        data = *(Rec **)((u8 *)object + 0x1C);
        if (data != 0) {
            fn_80128670(data->d);
            if (data != 0) {
                *(volatile s32 *)&data->a = 0;
                *(volatile s32 *)&data->b = 0;
                *(volatile s32 *)&data->c = 0;
                fn_80128668((void *)data);
            }
        }
        if ((u32)object + 0x14 != 0) fn_80131818(*(s32 *)((u8 *)object + 0x14));
        fn_802C2930(object, 0);
        if (freeFlag > 0) fn_80128668(object);
    }
    return object;
}
#pragma cplusplus reset
#pragma scheduling on

#pragma scheduling on
#pragma pop

#pragma cplusplus reset

void *fn_8016C168(void *arg0, s32 arg1) {
    void *child;
    void *child2;

    /* Destroy this object and its two owned children when initialized, optionally freeing itself. */
    if (arg0 != 0) {
        if (*((u8 *)arg0 + 8) != 0) {
            child = *(void **)arg0;
            *((u8 *)arg0 + 8) = 0;
            if (child != 0) {
                ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)child + 0xC), fn_8016C29C);
                if (child != 0) {
                    *(s32 *)child = 0;
                    *((s32 *)child + 1) = 0;
                    *((s32 *)child + 2) = 0;
                }
                fn_80128668(child);
            }
            child2 = *((void **)arg0 + 1);
            *(void **)arg0 = 0;
            if (child2 != 0) {
                ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)child2 + 0xC), fn_8016C25C);
                if (child2 != 0) {
                    *(s32 *)child2 = 0;
                    *((s32 *)child2 + 1) = 0;
                    *((s32 *)child2 + 2) = 0;
                }
                fn_80128668(child2);
            }
            *((void **)arg0 + 1) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

int fn_8016C25C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) { fn_80128668((void *)arg0); }
    return arg0;
}

void *fn_8016C29C(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (*((unsigned char *)arg0 + 16) != 0) {
            int temp = *(int *)arg0;
            *((unsigned char *)arg0 + 16) = 0;
            if (temp != -1) {
                fn_802C6CF8(temp);
                *(int *)arg0 = -1;
            }
            ((int *)arg0)[1] = 0;
            ((int *)arg0)[2] = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma cplusplus on
#pragma ppc_psq_save off
#pragma paired_single off
extern "C" void fn_8016C328(void *arg0) {
    class Cfg {
    public:
        virtual void s8();
        virtual int has(const char *);
        virtual void s10();
        virtual void enter(const char *);
        virtual void s18();
        virtual void s1C();
        virtual void s20();
        virtual f32 getF(const char *);
    };
    class List {
    public:
        virtual void s8();
        virtual void *get(s32);
    };
    struct Entry { u8 b; s32 w; f32 a; f32 c; };
    const char *base = lbl_803306D0;
    char buf[0x28];
    Cfg *cfg;
    void *obj;
    List *list;
    void *item;
    s32 i;
    cfg = *(Cfg **)((u8 *)fn_8000AC38() + 0x20);
    if (cfg->has(base + 0x50)) {
        fn_8016CE94((u8 *)arg0 + 8, cfg->getF(base + 0x50));
    } else {
        fn_8016CE94((u8 *)arg0 + 8, lbl_8056199C);
    }
    fn_801345D8(buf, 0x1E, base + 0x5C);
    obj = (void *)fn_801284F8(0x10, base + 0x6C);
    if (obj) {
        obj = fn_8016CD68(obj, fn_8016CDF8(arg0, cfg), (s32)(base + 0x80));
    }
    *(void **)((u8 *)arg0 + 0x18) = obj;
    while (!cfg->has(buf)) {
        cfg->enter(buf);
        list = (List *)fn_80131810();
        if (list) {
            i = 0;
            goto get;
            do {
                fn_8016C768((void *)fn_8016CD4C(*(void **)((u8 *)arg0 + 0x18)), item, (u8 *)arg0 + 0x14);
                i++;
get:
                item = list->get(i);
            } while (item);
            fn_80131818((s32)list);
        } else {
            fn_802E30C8(base + 0x90, buf);
            return;
        }
        *(s32 *)((u8 *)arg0 + 0x3C) = *(s32 *)((u8 *)arg0 + 0x3C) + 1;
        fn_801345D8(buf, 0x1E, base + 0xD8, *(s32 *)((u8 *)arg0 + 0x3C));
    }
    *(s32 *)((u8 *)arg0 + 0x3C) = fn_8016C760(*(void **)((u8 *)arg0 + 0x18));
    *(s32 *)((u8 *)arg0 + 0x38) = ((s32 (*)(void *))fn_8016C5F0)(arg0);
    obj = (void *)fn_801284F8(0x10, base + 0xE8);
    if (obj) {
        obj = fn_8016C598(obj, *(s32 *)((u8 *)arg0 + 0x38), (int)(base + 0xE8));
    }
    *(void **)((u8 *)arg0 + 0x1C) = obj;
    {
        f32 zero = lbl_80561998;
        for (i = 0; i < *(s32 *)((u8 *)arg0 + 0x38); i++) {
            Entry e;
            e.b = 0;
            e.w = -1;
            e.a = zero;
            e.c = zero;
            fn_8016C55C(*(void **)((u8 *)arg0 + 0x1C), &e);
        }
    }
}
#pragma cplusplus reset

#pragma ppc_psq_save on
void fn_8016C55C(void *arg0, void *arg1) {
    int index;
    void *dst;
    index = ((int *)arg0)[1];
    ((int *)arg0)[1] = index + 1;
    dst = (void *)((char *)*((void **)arg0) + index * 16);
    *(unsigned char *)dst = *(unsigned char *)arg1;
    *(int *)((char *)dst + 4) = *(int *)((char *)arg1 + 4);
    *(float *)((char *)dst + 8) = *(float *)((char *)arg1 + 8);
    *(float *)((char *)dst + 12) = *(float *)((char *)arg1 + 12);
}

void *fn_8016C598(void *arg0, int arg1, int arg2) {
    int temp = fn_8012850C(arg1 * 16, arg2);
    ((int *)arg0)[0] = temp;
    ((int *)arg0)[3] = temp;
    ((int *)arg0)[2] = arg1;
    ((int *)arg0)[1] = 0;
    return arg0;
}

#pragma cplusplus on
extern "C" void *fn_8000AC38(void);
extern "C" void *fn_80204EA0(const char *);
extern "C" void *fn_80131810(void);
extern "C" void fn_801345D8(void *, s32, const char *, ...);
extern "C" int strcmp(const char *, const char *);
extern "C" char *strstr(const char *, const char *);
extern "C" char lbl_803307C8[];
extern "C" char lbl_803307D8[];
extern "C" __declspec(section ".sdata") char lbl_8055A218[];
extern "C" __declspec(section ".sdata") char lbl_8055A220[];
extern "C" s32 fn_8016C5F0(void) {
    struct Manager {
        virtual void m0();
        virtual void *probe(void *);
        virtual void m2();
        virtual void release(void *);
    };
    struct SourceList {
        virtual void m0();
        virtual void *at(s32);
    };
    struct Entry {
        virtual const char *name();
        virtual void m1();
        virtual void m2();
        virtual const char *search(const char *);
    };
    Manager *manager = *(Manager **)((char *)fn_8000AC38() + 0x20);
    void *resource = fn_80204EA0(lbl_803307C8);
    s32 count = 0;
    char buffer[0x1E];
    if (manager->probe(resource) != 0) {
        manager->release(resource);
        SourceList *list = (SourceList *)fn_80131810();
        if (list != 0) {
            for (;;) {
                s32 found = 0;
                s32 i;
                fn_801345D8(buffer, 0x1E, lbl_8055A218, count);
                for (i = 0; list->at(i) != 0; i++) {
                    if (strcmp(((Entry *)list->at(i))->name(), lbl_803307D8) == 0) {
                        if (strstr(((Entry *)list->at(i))->search(lbl_8055A220), buffer) != 0) {
                            found = 1;
                            count++;
                            break;
                        }
                    }
                }
                if (found == 0) {
                    break;
                }
            }
            fn_80131818((s32)list);
        }
    }
    return count;
}
#pragma cplusplus reset

int fn_8016C760(void *arg0) { return ((int *)arg0)[1]; }

void fn_8016CD10(void *);
void fn_8016CD28(void *);
#pragma cplusplus on
extern "C" void fn_8016CD10(void *);
extern "C" void fn_8016CD28(void *);
#pragma cplusplus on
extern "C" s8 fn_8016C768(void *arg0, void *arg1, void *arg2) {
    struct Blk { s32 w[12]; };
    struct Item {
        virtual const char *name();
        virtual void m1();
        virtual void m2();
        virtual const char *search(const char *);
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual f32 getf(const char *, f32);
        virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
        virtual Blk getblk(const char *);
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20();
        virtual s32 check(const char *);
    };
    struct Doc {
        virtual const char *name();
        virtual Item *byIndex(s32);
        virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
        virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20(); virtual void m21();
        virtual Item *at(s32);
    };
    char *str = lbl_803306D0;
    List8016C768 *list;
    Item *obj;
    s32 count, i, idx;
    s32 ok;
    List8016C768 **out = (List8016C768 **)arg0;
    Doc *doc = (Doc *)arg1;
    Doc **coll = (Doc **)arg2;

    list = (List8016C768 *)fn_801284F8(0x10, str + 0x114);
    if (list != 0) {
        count = 0;
        i = 0;
        while ((obj = doc->at(i)) != 0) {
            if (stricmp(obj->name(), &lbl_8055A228) == 0) {
                if (stricmp(obj->search(&lbl_8055A230), str + 0x120) != 0) count++;
            }
            i++;
        }
        {
            s32 mem = ((s32 (*)(s32, char *))fn_8012850C)(count * 0x44 + 0x10, str + 0x12C);
            s32 r = ((s32 (*)(s32, void *, void *, s32, s32))fn_8002F37C)(mem, (void *)fn_8016CD28, (void *)fn_8016C29C, 0x44, count);
            list->data = r;
            list->count = count;
            list->index = 0;
            list->data2 = r;
        }
    }
    out[0] = list;
    list = (List8016C768 *)fn_801284F8(0x10, str + 0x13C);
    if (list != 0) {
        count = 0;
        i = 0;
        while ((obj = doc->at(i)) != 0) {
            if (stricmp(obj->name(), &lbl_8055A228) == 0) {
                if (stricmp(obj->search(&lbl_8055A230), str + 0x120) == 0) count++;
            }
            i++;
        }
        {
            s32 mem = ((s32 (*)(s32, char *))fn_8012850C)(count * 0x38 + 0x10, str + 0x14C);
            s32 r = ((s32 (*)(s32, void *, void *, s32, s32))fn_8002F37C)(mem, (void *)fn_8016CD10, (void *)fn_8016C25C, 0x38, count);
            list->data = r;
            list->count = count;
            list->index = 0;
            list->data2 = r;
        }
    }
    out[1] = list;
    ok = 1;
    idx = 0;
    while ((obj = doc->at(idx)) != 0) {
        if (strcmp(obj->name(), &lbl_8055A228) == 0) {
            if (strcmp(obj->search(&lbl_8055A230), str + 0x120) != 0) {
                List8016C768 *l = out[0];
                u8 *e = (u8 *)l->data + l->index++ * 0x44;
                const char *nm = obj->search(&lbl_8055A230);
                Item *c;
                s32 j = 0;
                s32 t;
                while ((c = (*coll)->byIndex(j)) != 0) {
                    if (strcmp(c->name(), &lbl_8055A230) == 0 &&
                        strcmp(c->search(lbl_8055A220), nm) == 0) break;
                    j++;
                }
                if (c == 0) fn_802E317C(str + 0x160, nm);
                t = c->check(str + 0x180);
                if ((u32)(-t | t) >> 31) {
                    *(s32 *)(e + 0xC) = 0;
                    *(s32 *)(e + 8) = c->check(str + 0x180);
                } else if (strcmp(nm, str + 0x120) == 0) {
                    *(s32 *)(e + 0xC) = 2;
                } else {
                    *(s32 *)(e + 0xC) = 1;
                    *(s32 *)e = fn_802C6FC0((s32)c->search(&lbl_8055A238), 0);
                }
                *(Blk *)(e + 0x14) = obj->getblk(str + 0x190);
                *(u8 *)(e + 0x10) = 1;
            } else {
                if (strcmp(obj->search(&lbl_8055A230), str + 0x120) == 0) {
                    List8016C768 *l = out[1];
                    u8 *e = (u8 *)l->data + l->index++ * 0x38;
                    if (strcmp(obj->search(&lbl_8055A230), str + 0x120) != 0)
                        fn_802E317C(str + 0x1A0);
                    *(Blk *)e = obj->getblk(str + 0x190);
                    *(f32 *)(e + 0x34) = obj->getf(&lbl_8055A240, lbl_805619A0);
                    *(u8 *)(e + 0x31) = 1;
                }
            }
        }
        idx++;
    }
    *((u8 *)arg0 + 8) = ok;
    return ok;
}
#pragma cplusplus off
extern f32 lbl_805619A0;
#pragma scheduling invalid_target
void fn_8016CD10(void *arg0) {
    f32 value = lbl_805619A0;
    *(u8 *)((u8 *)arg0 + 0x30) = 0;
    *(u8 *)((u8 *)arg0 + 0x31) = 0;
    *(f32 *)((u8 *)arg0 + 0x34) = value;
}
#pragma scheduling on
void fn_8016CD28(void *arg0) {
    int zero = 0;
    int minusOne = -1;
    *((u8 *)arg0 + 0x10) = zero;
    ((int *)arg0)[0] = minusOne;
    ((int *)arg0)[1] = zero;
    ((int *)arg0)[2] = zero;
    ((int *)arg0)[3] = 3;
}

s32 fn_8016CD4C(void *arg0) { s32 *base=*(s32 **)arg0; s32 index=((s32 *)arg0)[1]; ((s32 *)arg0)[1]=index+1; return (s32)base+index*0x14; }

void *fn_8016CD68(void *arg0, s32 arg1, s32 arg2) {
    s32 temp;
    s32 size = arg1 * 0x14;
    void *buffer = (void *)fn_8012850C(size + 0x10, arg2);
    temp = ((s32 (*)(void *, void *, void *, s32, s32))fn_8002F37C)(
        buffer, fn_8016CDE0, fn_8016C168, 0x14, arg1);
    ((s32 *)arg0)[0] = temp;
    ((s32 *)arg0)[3] = temp;
    ((s32 *)arg0)[2] = arg1;
    ((s32 *)arg0)[1] = 0;
    return arg0;
}

void fn_8016CDE0(void *arg0) {
    *(u8 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0) = 0;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

#pragma cplusplus on
extern "C" s32 fn_8016CDF8(void *unused, void *namedObject) {
    /* Counts sequential named entries by probing the object's lookup with a base name, then numbered names, until lookup fails. */
    struct Obj {
        virtual void v0();
        virtual int v1(char *);
    };
    char nameBuffer[0x1E];
    s32 nameCount = 0;
    fn_801345D8(nameBuffer, 0x1E, lbl_8033072C);
    while (((Obj *)namedObject)->v1(nameBuffer) != 0) {
        nameCount++;
        fn_801345D8(nameBuffer, 0x1E, lbl_803308A0, nameCount);
    }
    return nameCount;
}
#pragma cplusplus reset
void fn_8016CE94(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 4) = arg1;
}

extern f32 lbl_80561980;
extern char lbl_8033072C[];
extern char lbl_803308A0[];
void *fn_8016CEC0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    fn_8000DA10();
    *(f32 *)((u8 *)arg0 + 0xC) = lbl_80561980;
    return arg0;
}

void fn_8016CEFC(void *arg0) {
    ((s32 *)arg0)[1] = 0;
}

void *fn_8016CF08(void *obj) {
    // Initialize/clear fields and several fixed-size byte regions of this object.
    register s32 size = 0x30;
    register s32 count = 3;
    s32 zero = 0;
    *(s32 *)((u8 *)obj + 0xC) = zero;
    *(s32 *)((u8 *)obj + 0x14) = zero;
    *(s32 *)((u8 *)obj + 0x18) = zero;
    *(s32 *)((u8 *)obj + 0x1C) = zero;
    *(s32 *)((u8 *)obj + 0x24) = zero;
    *(s32 *)((u8 *)obj + 0x28) = zero;
    *(s32 *)((u8 *)obj + 0x2C) = zero;
    memset((u8 *)obj + 0x30, size, count);
    *((u8 *)obj + 0x33) = 0;
    memset((u8 *)obj + 0x44, size, count);
    *((u8 *)obj + 0x47) = 0;
    memset((u8 *)obj + 0x58, size, count);
    *((u8 *)obj + 0x5B) = 0;
    memset((u8 *)obj + 0x6C, size, count);
    *((u8 *)obj + 0x6F) = 0;
    memset((u8 *)obj + 0x80, size, count);
    *((u8 *)obj + 0x83) = 0;
    memset((u8 *)obj + 0x8A, size, count);
    *((u8 *)obj + 0x8D) = 0;
    memset((u8 *)obj + 0x9E, size, count);
    *((u8 *)obj + 0xA1) = 0;
    memset((u8 *)obj + 0xB2, size, count);
    *((u8 *)obj + 0xB5) = 0;
    memset((u8 *)obj + 0xC6, size, count);
    *((u8 *)obj + 0xC9) = 0;
    memset((u8 *)obj + 0xDA, size, count);
    *((u8 *)obj + 0xDD) = 0;
    return obj;
}

extern char lbl_80330A90[];
extern f32 lbl_80561984;
extern void fn_802C2914(void *);
extern void *fn_80131808(void *);
extern void *fn_8023512C(void *);
extern void *fn_802076A0(void *, s32, s32, s32);
extern s32 fn_80204CF0(void);
void *fn_8016D024(void *a0) {
    char *b = lbl_803306D0;
    void *last;
    void *nfirst;
    fn_802C2914(a0);
    *(void **)((u8 *)a0 + 4) = lbl_80330A90;
    *(void **)((u8 *)a0 + 0x14) = fn_80131808(b + 0x1E0);
    *(void **)((u8 *)a0 + 0x20) = fn_8023512C(b + 0x1F8);
    *(void **)((u8 *)a0 + 0x4C) = fn_802076A0(b + 0x204, 1, 0, 0);
    *(void **)((u8 *)a0 + 0x50) = fn_802076A0(b + 0x210, 1, 0, 0);
    *(void **)((u8 *)a0 + 0x58) = fn_802076A0(b + 0x220, 1, 0, 0);
    *(void **)((u8 *)a0 + 0x54) = fn_802076A0(b + 0x22C, 1, 0, 0);
    *(void **)((u8 *)a0 + 0x5C) = fn_802076A0(b + 0x23C, 1, 0, 0);
    *(void **)((u8 *)a0 + 0x60) = fn_802076A0(b + 0x24C, 1, 0, 0);
    last = fn_802076A0(b + 0x258, 1, 0, 0);
    nfirst = *(void **)((u8 *)a0 + 0x4C);
    *(void **)((u8 *)a0 + 0x64) = last;
    *(s32 *)((u8 *)a0 + 0x24) = -1;
    *(u8 *)((u8 *)a0 + 0x48) = 0;
    *(u8 *)((u8 *)a0 + 0x49) = 0;
    *(u8 *)((u8 *)a0 + 0x4A) = 1;
    *(f32 *)((u8 *)a0 + 0x28) = lbl_80561980;
    *(s32 *)((u8 *)a0 + 0x38) = 0;
    *(s32 *)((u8 *)a0 + 0x3C) = 0;
    SetNodeF8(nfirst);
    SetNodeF8(*(void **)((u8 *)a0 + 0x50));
    SetNodeF8(*(void **)((u8 *)a0 + 0x58));
    SetNodeF8(*(void **)((u8 *)a0 + 0x54));
    SetNodeF8(*(void **)((u8 *)a0 + 0x5C));
    SetNodeF8(*(void **)((u8 *)a0 + 0x60));
    SetNodeF8(*(void **)((u8 *)a0 + 0x64));
    *(s32 *)((u8 *)a0 + 0x40) = fn_80204CF0();
    return a0;
}

#pragma scheduling on
void fn_8016D278(void *arg0) { *(u32 *)arg0=(u32)arg0+0xC; *(u32 *)((u8 *)arg0+8)=8; *(u32 *)((u8 *)arg0+4)=0; }

/* --- RingChallengeMaster (lbl_8055E378) -------------------------------------
 * 0x1B4-byte singleton built by fn_8016BE60 under the heap name "ringchalmaster"
 * (lbl_803306D0 + 0x20).  Its ring-set controller sub-object starts at +0x30
 * (constructed by fn_8016D024), so the fields below are that sub-object's
 * +0x18 .. +0x44; the same sub-object is what fn_8016DE20 / fn_8016DFB8 /
 * fn_8016E06C / fn_8016E1B4 are handed directly.
 *   +0x48  ring-set list: pointer to the array of 0x14-byte ring-set entries
 *   +0x50  map "mapgems.art" object the marker is drawn on
 *   +0x54  queue slot of the pending map marker, -1 when none (fn_8001B308 /
 *          fn_8001B450 reserve and release it)
 *   +0x5C  index of the selected ring set
 *   +0x6C  number of ring sets
 *   +0x74  difficulty selector: 0 = 5 rings, 1 = 10 rings, 2 = 15 rings
 * A ring-set entry (0x14 bytes) is { list of its 0x44-byte gems (+0), active
 * flag (+9), timer (+0xC, lbl_8055E3C8 == 0.0f), counter (+0x10, volatile) }.
 * The three name formats build the set's name, e.g. "set_3_10"; the last
 * string is the error for an out-of-range difficulty.
 */
#define RCM_SET_LIST(o)   (**(u8 ***)((u8 *)(o) + 0x48))
#define RCM_MAP_ART(o)    (*(s32 *)((u8 *)(o) + 0x50))
#define RCM_MAP_MARKER(o) (*(s32 *)((u8 *)(o) + 0x54))
#define RCM_SET_INDEX(o)  (*(s32 *)((u8 *)(o) + 0x5C))
#define RCM_SET_COUNT(o)  (*(s32 *)((u8 *)(o) + 0x6C))
#define RCM_DIFFICULTY(o) (*(s32 *)((u8 *)(o) + 0x74))
#define SET_FMT_5         (strings + 0x264) /* "set_%i_5" */
#define SET_FMT_10        (strings + 0x270) /* "set_%i_10" */
#define SET_FMT_15        (strings + 0x27C) /* "set_%i_15" */
#define SET_BAD_DIFFICULTY (strings + 0x288) /* "Unknown difficulty specification in Ring Challenge mode." */

/* The ring-set controller's gem lists.  Its +0x18 holds the ring-set list
 * { array of 0x14-byte ring-set entries (+0), number of sets (+4) }; each
 * entry's +0 is its gem list { array of 0x44-byte gems (+0), gem count (+4) }.
 * A gem record holds the object fn_802BAA68 built for it (+4), the handle that
 * object is built from (+8), a built flag (+0xC, 0 = not built yet) and the
 * transform data fn_802BAA68 reads (+0x14). */
#define RING_SETS(o)     (*(u8 **)((u8 *)(o) + 0x18))
#define LIST_DATA(l)     (*(u8 **)(l))
#define LIST_COUNT(l)    (*(s32 *)((u8 *)(l) + 4))
#define GEM_OBJECT(g)    (*(s32 *)((u8 *)(g) + 4))
#define GEM_HANDLE(g)    (*(s32 *)((u8 *)(g) + 8))
#define GEM_BUILT(g)     (*(s32 *)((u8 *)(g) + 0xC))
#define GEM_TRANSFORM(g) ((u8 *)(g) + 0x14)

/*
 * Select ring set `setIndex` for the Ring Challenge master (lbl_8055E378).
 * Marks the set active, zeroes its timer and releases every gem object it still
 * holds, resets the gems of its "set_<index>_<5|10|15>" set (fn_8016A15C), then
 * drops the pending map marker and queues a new one for the set: fn_8001B308
 * reserves a slot in the shared 16-entry marker queue and that slot is kept at
 * +0x54 so it can be released again.  Kind 0 is the only request the master
 * handles; any other kind does nothing.
 */
void fn_8016D294(s32 unused, s32 kind, s32 setIndex) {
    char setName[0x20];   /* "set_%i_5" &c., for the gem-set reset */
    char markerName[0x20]; /* the same name, for the marker position lookup */
    register u8 *master = (u8 *)lbl_8055E378;
    register char *strings = lbl_803306D0;
    FloatPair8016A6B0 pos15, pos10, pos5;
    s32 difficulty;

    if (master != 0) {
        switch (kind) {
        case 0:
        RCM_SET_INDEX(master) = setIndex;
        if (setIndex < RCM_SET_COUNT(master)) {
            s32 gemIndex;
            u8 *ringSet;
            s32 gemOffset;
            ringSet = RCM_SET_LIST(master) + setIndex * 0x14; /* 0x14-byte set entry */
            ringSet[9] = 1;                    /* set is active */
            gemIndex = 0;
            *(f32 *)(ringSet + 0xC) = lbl_8055E3C8; /* its timer back to 0.0f */
            gemOffset = 0;
            *(volatile s32 *)(ringSet + 0x10) = 0;  /* and its counter to 0 */
            while (gemIndex < *(s32 *)(*(u8 **)ringSet + 4)) { /* its gems */
                u8 *gems = (u8 *)**(void ***)ringSet;
                void *gem = *(void **)(gems + gemOffset + 4);
                if (gem != 0) {
                    fn_802BAF98(gem, 1);       /* release the gem object */
                }
                gemOffset += 0x44;             /* 0x44 bytes per gem */
                gemIndex += 1;
            }
        }
        difficulty = RCM_DIFFICULTY(master);
        switch (difficulty) {
        case 0:
            fn_801345D8(setName, 0x1E, SET_FMT_5, RCM_SET_INDEX(master));
            break;
        case 1:
            fn_801345D8(setName, 0x1E, SET_FMT_10, RCM_SET_INDEX(master));
            break;
        case 2:
            fn_801345D8(setName, 0x1E, SET_FMT_15, RCM_SET_INDEX(master));
            break;
        default:
            fn_802E317C(SET_BAD_DIFFICULTY);
            break;
        }
        fn_8016A15C(setName);                  /* reset that set's gems */
        if (RCM_MAP_MARKER(master) != -1) {
            if (RCM_MAP_MARKER(master) != -1) {
                fn_8001B450(RCM_MAP_MARKER(master)); /* release the old marker */
                RCM_MAP_MARKER(master) = -1;
            }
        }
        difficulty = RCM_DIFFICULTY(master);
        switch (difficulty) {
        case 0:
            fn_801345D8(markerName, 0x1E, SET_FMT_5, RCM_SET_INDEX(master));
            break;
        case 1:
            fn_801345D8(markerName, 0x1E, SET_FMT_10, RCM_SET_INDEX(master));
            break;
        case 2:
            fn_801345D8(markerName, 0x1E, SET_FMT_15, RCM_SET_INDEX(master));
            break;
        default:
            fn_802E317C(SET_BAD_DIFFICULTY);
            break;
        }
        difficulty = RCM_DIFFICULTY(master);
        switch (difficulty) {
        case 0:
            pos5 = fn_8016A6B0(markerName, 0xC); /* marker position, 5-ring set */
            RCM_MAP_MARKER(master) = fn_8001B308(&pos5, RCM_MAP_ART(master), 2);
            break;
        case 1:
            pos10 = fn_8016A6B0(markerName, 9);  /* 10-ring set */
            RCM_MAP_MARKER(master) = fn_8001B308(&pos10, RCM_MAP_ART(master), 2);
            break;
        case 2:
            pos15 = fn_8016A6B0(markerName, 6);  /* 15-ring set */
            RCM_MAP_MARKER(master) = fn_8001B308(&pos15, RCM_MAP_ART(master), 2);
            break;
        default:
            fn_802E317C(SET_BAD_DIFFICULTY);
            break;
        }
        break;
        default:
            break;
        }
    }
}

s32 fn_8016D544(void *arg0) {
    void **items;
    s32 found;
    s32 outerCount;
    s32 outerOffset;
    s32 innerOffset;
    s32 *list;
    s32 outerIndex;
    s32 total;
    s32 innerCount;
    s32 innerIndex;
    list = *(s32 **)((u8 *)arg0 + 0x18);
    total = 0;
    outerIndex = 0;
    outerCount = *(s32 *)((u8 *)list + 4);
    outerOffset = 0;
    goto outerTest;
outerBody:
    items = *(void ***)list;
    found = 0;
    innerOffset = 0;
    {
        void *entry = *(void **)((u8 *)items + outerOffset);
        innerCount = *(s32 *)((u8 *)entry + 4);
    }
    for (innerIndex = 0; innerIndex < innerCount; innerIndex++, innerOffset += 0x44) {
        volatile void *entry2 = *(volatile void **)((u8 *)items + outerOffset);
        void *data = *(void **)(void *)entry2;
        if (*(s32 *)((u8 *)data + innerOffset + 0xC) == 0) found++;
    }
    total += found;
    outerOffset += 0x14;
    outerIndex++;
outerTest:
    if (outerIndex < outerCount) goto outerBody;
    return total;
}

s32 fn_802BAA68(s32, void *);
#pragma use_lmw_stmw off
void fn_8016D5B8(void *controller) {
    u8 *ctrl = (u8 *)controller;
    u8 *setList;
    u8 *setEntries;
    s32 gemIndex;
    u8 *gem;
    s32 setOffset;
    s32 gemOffset;
    s32 setIndex;
    u8 *gemList;

    /* For every ring set, build the render object of each gem that lacks one. */
    setIndex = 0;
    setOffset = 0;
    goto outer_check;

outer_setup:
    setEntries = LIST_DATA(setList);
    gemIndex = 0;
    gemOffset = 0;
    goto inner_check;

inner_body:
    gem = LIST_DATA(gemList) + gemOffset;
    if (GEM_BUILT(gem) == 0) {
        GEM_OBJECT(gem) =
            fn_802BAA68(GEM_HANDLE(gem), GEM_TRANSFORM(gem));
    }
    gemOffset += 0x44;
    gemIndex++;

inner_check:
    gemList = *(u8 **)(setEntries + setOffset);
    if (gemIndex < LIST_COUNT(gemList)) goto inner_body;
    setOffset += 0x14;
    setIndex++;

outer_check:
    setList = RING_SETS(ctrl);
    if (setIndex < LIST_COUNT(setList)) goto outer_setup;
}
#pragma use_lmw_stmw on
int fn_8000DA10();
#pragma cplusplus on
extern "C" char lbl_80330990[];
extern "C" char lbl_80330A90[];
extern "C" s32 lbl_8055E378;
extern "C" void fn_8016A68C(void);
extern "C" void fn_80128670(s32);
extern "C" void fn_80131818(s32);
extern "C" void fn_80235380(void *, char *);
extern "C" void fn_802C2930(void *, s32);
extern "C" void fn_802ADE60(s32, s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_8016D658(void *arg0, s32 arg1) {
 class VObj { public: virtual void destroy(int); };
 struct List { void *vtable; VObj **items; s32 count; };
 VObj *old; VObj *p; s32 offset, i;
 if (arg0 != 0) {
  old = *(VObj **)((u8 *)arg0 + 0xA4); *(char **)arg0 = lbl_80330990;
  if (old != 0) { if (old != 0) old->destroy(1); }
  i = 0; offset = 0;
  while (i < ((List *)arg0)->count) {
   p = *(VObj **)((u8 *)((List *)arg0)->items + offset);
   if (p != 0) { fn_8000DA10(); fn_80128668(p); }
   offset += 4; i += 1;
  }
  lbl_8055E378 = 0; fn_8016A68C();
  if ((u8 *)arg0 + 0xAC != 0) {
   s32 value = *(s32 *)((u8 *)arg0 + 0xB8);
   if (value != 0) { fn_802ADE60(value, 1); *(s32 *)((u8 *)arg0 + 0xB8) = 0; }
   p = *(VObj **)((u8 *)arg0 + 0xC0); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xC0) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xC4); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xC4) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xC8); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xC8) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xD0); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xD0) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xD4); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xD4) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xD8); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xD8) = 0; }
  }
  if ((u8 *)arg0 + 0x30 != 0) {
   *(char **)((u8 *)arg0 + 0x34) = lbl_80330A90;
   fn_80235380(*(void **)((u8 *)arg0 + 0x50), lbl_80330A90);
   p = *(VObj **)((u8 *)arg0 + 0x7C); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x84); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x88); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x80); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x8C); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x90); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x94); if (p != 0) { if (p != 0) p->destroy(1); }
   p = *(VObj **)((u8 *)arg0 + 0x48);
   if (p != 0) { ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)p + 0xC), fn_8016C168); if (p != 0) { *(s32 *)p = 0; *(s32 *)((u8 *)p + 4) = 0; *(s32 *)((u8 *)p + 8) = 0; fn_80128668(p); } }
   p = *(VObj **)((u8 *)arg0 + 0x4C);
   if (p != 0) { fn_80128670(*(s32 *)((u8 *)p + 0xC)); if (p != 0) { *(s32 *)p = 0; *(s32 *)((u8 *)p + 4) = 0; *(s32 *)((u8 *)p + 8) = 0; fn_80128668(p); } }
   if ((u8 *)arg0 + 0x44 != 0) fn_80131818(*(s32 *)((u8 *)arg0 + 0x44));
   fn_802C2930((u8 *)arg0 + 0x30, 0);
  }
  if ((u8 *)arg0 + 4 != 0) { *(s32 *)((u8 *)arg0 + 4) = 0; *(s32 *)((u8 *)arg0 + 8) = 0; *(s32 *)((u8 *)arg0 + 0xC) = 0; }
  if (arg1 > 0) fn_80128668(arg0);
 }
}
#pragma scheduling on
#pragma cplusplus off

extern s32 fn_8016DD98(void *);
extern s32 fn_8016DE08(void *);
extern s32 fn_8016DE10(s32 *, s32);
extern void fn_8016E06C(void *);
extern void fn_8016DFB8(void *);
extern void fn_8016DE20(void *);
extern void fn_8016E118(void *);
extern void fn_8016E15C(void *, void *);
extern s32 fn_8016E1A4(s32 *, s32);
extern void fn_8016E1B4(void *, s32);
extern void fn_8016E314(void *);
extern void fn_80144C54(s32);
extern void fn_8016A0D4(void);
extern void fn_802E30C8(const char *, ...);
extern char lbl_80330AA4[];
#pragma scheduling invalid_target
extern void fn_8016E15C();
#pragma scheduling invalid_target
void fn_8016DA0C(void *arg0) {
    s32 i, j, n;
    f32 f, zero;
    void *p;

    zero = lbl_80561980;
    for (i = 0; i < M2C_FIELD(arg0, s32 *, 8); i++) {
        p = ((void **) M2C_FIELD(arg0, void **, 4))[i];
        M2C_FIELD(p, s32 *, 0) = 0;
        M2C_FIELD(p, s8 *, 8) = 0;
        M2C_FIELD(p, f32 *, 0xC) = zero;
    }
    fn_8016A0D4();
    if (M2C_FIELD(arg0, s32 *, 0x70) == 0) {
        M2C_FIELD(arg0, s32 *, 0x74) = 0;
    } else {
        M2C_FIELD(arg0, s32 *, 0x74) = 2;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s8 *, 0x78) = 0;
    M2C_FIELD(arg0, s8 *, 0x79) = 0;
    M2C_FIELD(arg0, s8 *, 0x7A) = 1;
    M2C_FIELD(arg0, f32 *, 0x58) = zero;
    if (M2C_FIELD(arg0, s32 *, 0x6C) < M2C_FIELD(arg0, s32 *, 0x68))
        fn_802E30C8(lbl_80330AA4);
    fn_8016E314((u8 *) arg0 + 0x38);
    for (j = 0; j < M2C_FIELD(arg0, s32 *, 0x68); j++)
        fn_8016E1B4((u8 *) arg0 + 0x30, j);
    for (j = 0; j < M2C_FIELD(arg0, s32 *, 0x6C); j++)
        fn_8016E15C((void *) fn_8016E1A4((s32 *) M2C_FIELD(arg0, s32 *, 0x48), j));
    fn_8016E118((u8 *) arg0 + 0x30);
    i = M2C_FIELD(arg0, s32 *, 0x5C);
    if (i >= 0 && i < M2C_FIELD(arg0, s32 *, 0x68)) {
        fn_8016E06C((u8 *) arg0 + 0x30);
        fn_8016DFB8((u8 *) arg0 + 0x30);
        fn_8016DE20((u8 *) arg0 + 0x30);
    }
    f = lbl_80561998;
    for (j = 0; j < fn_8016DE08(M2C_FIELD(arg0, void **, 0x4C)); j++) {
        *(s8 *) fn_8016DE10((s32 *) M2C_FIELD(arg0, void **, 0x4C), j) = 0;
        M2C_FIELD((void *) fn_8016DE10((s32 *) M2C_FIELD(arg0, void **, 0x4C), j), s32 *, 4) = -1;
        M2C_FIELD((void *) fn_8016DE10((s32 *) M2C_FIELD(arg0, void **, 0x4C), j), f32 *, 8) = f;
        M2C_FIELD((void *) fn_8016DE10((s32 *) M2C_FIELD(arg0, void **, 0x4C), j), f32 *, 0xC) = f;
    }
    n = fn_8016DD98((u8 *) arg0 + 0x30);
    M2C_FIELD((void *) fn_8016DE10((s32 *) M2C_FIELD(arg0, void **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)), s32 *, 4) = n;
    if (M2C_FIELD(arg0, s32 *, 0x7C)) fn_80144C54(M2C_FIELD(arg0, s32 *, 0x7C));
    if (M2C_FIELD(arg0, s32 *, 0x84)) fn_80144C54(M2C_FIELD(arg0, s32 *, 0x84));
    if (M2C_FIELD(arg0, s32 *, 0x88)) fn_80144C54(M2C_FIELD(arg0, s32 *, 0x88));
    if (M2C_FIELD(arg0, s32 *, 0x80)) fn_80144C54(M2C_FIELD(arg0, s32 *, 0x80));
    if (M2C_FIELD(arg0, s32 *, 0x8C)) fn_80144C54(M2C_FIELD(arg0, s32 *, 0x8C));
    if (M2C_FIELD(arg0, s32 *, 0x90)) fn_80144C54(M2C_FIELD(arg0, s32 *, 0x90));
    if (M2C_FIELD(arg0, s32 *, 0x94)) fn_80144C54(M2C_FIELD(arg0, s32 *, 0x94));
    M2C_FIELD(arg0, s8 *, 0x9C) = 1;
    M2C_FIELD(arg0, f32 *, 0xA0) = lbl_80561998;
    M2C_FIELD(arg0, s32 *, 0xAC) = 0;
    M2C_FIELD(arg0, f32 *, 0xB0) = lbl_805619A4;
    M2C_FIELD(arg0, s8 *, 0xB4) = 1;
    M2C_FIELD(arg0, s8 *, 0xB5) = 0;
    M2C_FIELD(arg0, s8 *, 0xBC) = 0;
    M2C_FIELD(arg0, s32 *, 0x1A4) = 0;
    M2C_FIELD(arg0, s32 *, 0x1A8) = 0;
    M2C_FIELD(arg0, s32 *, 0x1AC) = 0;
    M2C_FIELD(arg0, s32 *, 0x1B0) = 0;
    if (M2C_FIELD(arg0, s32 *, 0xB8)) fn_802AE0E0(M2C_FIELD(arg0, s32 *, 0xB8));
    p = M2C_FIELD(arg0, void **, 0xC0);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(arg0, void **, 0xC4);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(arg0, void **, 0xC8);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(arg0, void **, 0xD0);
    M2C_FIELD(arg0, s8 *, 0xCC) = 0;
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(arg0, void **, 0xD4);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(arg0, void **, 0xD8);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(arg0, void **, 0xA4);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    M2C_FIELD(arg0, s8 *, 0xA8) = 0;
}
#pragma scheduling on
s32 fn_8016DD98(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    switch (value) {
        case 0: return 5;
        case 1: return 0xA;
        case 2: return 0xF;
        default: {
            void (*report)(const char *, ...) = fn_802E317C;
            report(lbl_80330AEC);
            return 0;
        }
    }
}

s32 fn_8016DE08(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_8016DE10(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x10);
}

/* Refreshes an object's display text/resource handle based on its mode/index.
 * Frees any existing handle, formats mode-specific label text, resolves display
 * metrics for that label, then allocates/updates the active handle; logs an
 * error for unknown modes. */
void fn_8016DE20(void *obj) {
    char textBuffer[0x20];
    register char *formatBase = lbl_803306D0;
    register void *object = obj;
    s32 activeId;
    s32 displayMode;

    activeId = *(s32 *)((u8 *)object + 0x24);
    if (activeId != -1) {
        if (activeId != -1) {
            fn_8001B450(activeId);
            *(s32 *)((u8 *)object + 0x24) = -1;
        }
    }

    displayMode = *(s32 *)((u8 *)object + 0x44);
    switch (displayMode) {
    case 0:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x264, *(s32 *)((u8 *)object + 0x2C));
        break;
    case 1:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x270, *(s32 *)((u8 *)object + 0x2C));
        break;
    case 2:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x27C, *(s32 *)((u8 *)object + 0x2C));
        break;
    default:
        fn_802E317C(formatBase + 0x288);
        break;
    }

    displayMode = *(s32 *)((u8 *)object + 0x44);
    switch (displayMode) {
    case 0: {
        FloatPair8016A6B0 result = fn_8016A6B0(textBuffer, 0xC);
        *(s32 *)((u8 *)object + 0x24) =
            fn_8001B308(&result, *(s32 *)((u8 *)object + 0x20), 2);
        break;
    }
    case 1: {
        FloatPair8016A6B0 result = fn_8016A6B0(textBuffer, 9);
        *(s32 *)((u8 *)object + 0x24) =
            fn_8001B308(&result, *(s32 *)((u8 *)object + 0x20), 2);
        break;
    }
    case 2: {
        FloatPair8016A6B0 result = fn_8016A6B0(textBuffer, 6);
        *(s32 *)((u8 *)object + 0x24) =
            fn_8001B308(&result, *(s32 *)((u8 *)object + 0x20), 2);
        break;
    }
    default:
        fn_802E317C(formatBase + 0x288);
        break;
    }
}

extern f32 lbl_8055E3C8;
extern f32 lbl_80561998;
extern void fn_8001B450(s32);
extern void fn_802BAF98(void *, s8);
void fn_8016DFB8(void *object) {
    /* Formats a mode-specific label for this object's value (+0x2C) based on its
       display mode (+0x44): modes 0/1/2 use format strings at lbl_803306D0+0x264/
       0x270/0x27C, any other logs the error string at +0x288, then passes the
       resulting text buffer to fn_8016A15C. */
    char textBuffer[30];
    char *formatBase = lbl_803306D0;
    switch (*(s32 *)((u8 *)object + 0x44)) {
    case 0:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x264, *(s32 *)((u8 *)object + 0x2C));
        break;
    case 1:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x270, *(s32 *)((u8 *)object + 0x2C));
        break;
    case 2:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x27C, *(s32 *)((u8 *)object + 0x2C));
        break;
    default:
        fn_802E317C(formatBase + 0x288);
        break;
    }
    fn_8016A15C(textBuffer);
}

#pragma scheduling invalid_target
void fn_8016E06C(void *arg0) {
    /* Activate the selected 0x14-byte item entry and enable each of its sub-handles. */
    u8 **baseSlot;
    s32 index = *(s32 *)((u8 *)arg0 + 0x2c);
    if (index < *(s32 *)((u8 *)arg0 + 0x3c)) {
        s32 i = 0;
        u8 *item;
        s32 offset;
        baseSlot = *(u8 ***)((u8 *)arg0 + 0x18);
        item = *baseSlot + index * 0x14;
        item[9] = 1;
        i = 0;
        *(f32 *)(item + 0xc) = lbl_8055E3C8;
        offset = 0;
        *(volatile s32 *)(item + 0x10) = 0;
        while (i < *(s32 *)(*(u8 **)item + 4)) {
            s32 value = *(s32 *)(*(u8 **)*(u8 **)item + offset + 4);
            if (value != 0) {
                fn_802BAF98((void *)value, 1);
            }
            offset += 0x44;
            i += 1;
        }
    }
}
#pragma scheduling on
void fn_8016E118(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x24);
    if (value != -1) {
        fn_8001B450(value);
        *(s32 *)((u8 *)arg0 + 0x24) = -1;
    }
}

void fn_8016E15C(void *arg0) {
    f32 f = lbl_80561998;
    s32 off;
    s32 i;
    *(u8 *)((u8 *)arg0 + 9) = 0;
    i = 0;
    off = 0;
    *(f32 *)((u8 *)arg0 + 0xC) = f;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    while (i < *(s32 *)(*(char **)((u8 *)arg0 + 4) + 4)) {
        *(u8 *)(*(char **)*(char **)((u8 *)arg0 + 4) + off + 0x30) = 0;
        off += 0x38;
        i++;
    }
}

s32 fn_8016E1A4(s32 *arg0, s32 arg1) {
    return *arg0 + (arg1 * 0x14);
}

// Builds a formatted state label for this object, applies it via UI helper, resets the
// selected list entry's runtime fields/child handles when index is valid, and stops its
// active sound handle if one is set.
void fn_8016E1B4(void *arg0, s32 arg1) {
    char sp8[0x28];
    register char *format = lbl_803306D0;
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    switch (value) {
    case 0:
        fn_801345D8(sp8, 0x1e, format + 0x264, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    case 1:
        fn_801345D8(sp8, 0x1e, format + 0x270, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    case 2:
        fn_801345D8(sp8, 0x1e, format + 0x27c, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    default:
        fn_802E317C(format + 0x288);
        break;
    }
    fn_8016A240(sp8);
    if (arg1 < *(s32 *)((u8 *)arg0 + 0x3c)) {
        register s32 i;
        register void **list = *(void ***)((u8 *)arg0 + 0x18);
        s32 delta = arg1 * 0x14;
        register u8 *base = (u8 *)*list;
        register u8 *item = base + delta;
        s32 offset;
        *(u8 *)(item + 9) = 0;
        i = 0;
        offset = 0;
        *(f32 *)(item + 0xc) = lbl_8055E3C8;
        while (i < *(s32 *)((u8 *)*(void **)item + 4)) {
            u8 *entries = (u8 *)*(void **)*(void **)item;
            void *handle = *(void **)(entries + offset + 4);
            if (handle != 0) {
                fn_802BAF98(handle, 0);
            }
            offset += 0x44;
            i += 1;
        }
    }
    if (*(s32 *)((u8 *)arg0 + 0x24) != -1) {
        fn_8001B450(*(s32 *)((u8 *)arg0 + 0x24));
        *(s32 *)((u8 *)arg0 + 0x24) = -1;
    }
}

#pragma dont_inline on
void fn_8016E314(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0) = *(f32 *)((u8 *)arg0 + 4);
}
#pragma dont_inline reset

u8 fn_8016E320(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x9c);
}

#pragma cplusplus on
extern "C" float lbl_80561988, lbl_805619A8, lbl_805619AC, lbl_805619B0, lbl_805619B4, lbl_805619B8, lbl_805619BC;
extern "C" void *fn_801E7E3C(void);
extern "C" int fn_801E866C(int);
extern "C" int fn_80160998(void);
extern "C" void fn_8000FBE4(void), fn_80160A74(void);
extern "C" void fn_8001DF08(int,int);
extern "C" unsigned char *fn_80131234(const char *);
extern "C" float fn_80147204(void *, void *);
extern "C" void fn_801479A8(void *, void *, void *, ...);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" int fn_8016E328(void *arg0, int arg1) {
 struct Rect { int a; float b; int c,d; float e; int f,g,h; };
 struct Manager { virtual void *unused(); virtual void *get(const char *); };
 struct Frame { Rect rect2; char text2[24]; Rect rect1; char text1[20]; } frame;
 struct Manager *mgr; void *one, *two, *panel, *detail;
 float a, time, limit,b,c,d,e, t, blend, value;
 char *base = lbl_803306D0;
 time = *(float *)((char *)fn_801E7E3C()+0x10);
 limit=lbl_805619A8; a=limit-lbl_805619AC; b=a-lbl_805619B0;
 c=b-lbl_805619B4; d=c-lbl_805619AC; e=d-lbl_805619B0;
 mgr=*(struct Manager **)((char *)arg0+0x98);
 one=mgr->get(base+0x458);
 mgr=*(struct Manager **)((char *)arg0+0x98);
 two=mgr->get(base+0x468);
 if (time < e) fn_8000FBE4();
 if (!fn_80161C38()) {
   if (time < limit) {
     t=(time-a)/(b-a); blend=lbl_80561984;
     blend = blend < t ? blend : t;
     blend = blend > lbl_80561980 ? blend : lbl_80561980;
     blend=lbl_80561980+blend*lbl_80561984;
     mgr=*(struct Manager **)((char *)arg0+0x98);
     panel=mgr->get(base+0x478);
     mgr=*(struct Manager **)((char *)arg0+0x98);
     detail=mgr->get(base+0x484);
     fn_8001DF08(fn_801E866C(arg1),0);
     if (one && two && panel && detail) {
       value=lbl_805619A4;
if (blend < value) {} else {
 value=lbl_80561984;
 if (blend > value) {} else {
  if (blend > lbl_80561980) value=(blend*(lbl_805619B8*blend*blend))+(lbl_805619BC*blend*blend);
  else value=(blend*(lbl_805619B8*blend*blend))-(lbl_805619BC*blend*blend);
 }
}
       fn_801479A8(one,two,fn_80131234(base+0x490),value);
       fn_80160A74(); ((void (*)(void *,int,int))fn_801308F4)(frame.text1,0x14,fn_80160998());
       frame.rect1.a=*(int *)panel;
       { int cword=*(int *)((char *)panel+8), bword=*(int *)((char *)panel+4); *(int *)&frame.rect1.b=bword; frame.rect1.c=cword; } frame.rect1.d=*(int *)((char *)panel+12); frame.rect1.e=*(float *)((char *)panel+16); frame.rect1.f=*(int *)((char *)panel+20); frame.rect1.g=*(int *)((char *)panel+24); frame.rect1.h=*(int *)((char *)panel+28);
       frame.rect1.b-=lbl_80561988*fn_80147204(&frame.rect1,frame.text1);
       value=lbl_805619A4;
if (blend < value) {} else {
 value=lbl_80561984;
 if (blend > value) {} else {
  if (blend > lbl_80561980) value=(blend*(lbl_805619B8*blend*blend))+(lbl_805619BC*blend*blend);
  else value=(blend*(lbl_805619B8*blend*blend))-(lbl_805619BC*blend*blend);
 }
}
       fn_801479A8(&frame.rect1,detail,frame.text1,value);
     }
   }
   if (time < c) {
     fn_8014784C(*(void **)((char *)arg0+0x98),base+0x4ac,base+0x4bc,0);
     t=(time-d)/(e-d); blend=lbl_80561984;
     blend = blend < t ? blend : t;
     blend = blend > lbl_80561980 ? blend : lbl_80561980;
     blend=lbl_80561980+blend*lbl_80561984;
     mgr=*(struct Manager **)((char *)arg0+0x98);
     panel=mgr->get(base+0x4d0);
     mgr=*(struct Manager **)((char *)arg0+0x98);
     detail=mgr->get(&lbl_8055A248);
     if (one && two && panel && detail) {
       value=lbl_805619A4;
if (blend < value) {} else {
 value=lbl_80561984;
 if (blend > value) {} else {
  if (blend > lbl_80561980) value=(blend*(lbl_805619B8*blend*blend))+(lbl_805619BC*blend*blend);
  else value=(blend*(lbl_805619B8*blend*blend))-(lbl_805619BC*blend*blend);
 }
}
       fn_801479A8(one,two,fn_80131234(base+0x4dc),value);
       fn_80130978(frame.text2,0x14,*(float *)((char *)arg0+0x38));
       frame.rect2.a=*(int *)panel;
       { int cword=*(int *)((char *)panel+8), bword=*(int *)((char *)panel+4); *(int *)&frame.rect2.b=bword; frame.rect2.c=cword; } frame.rect2.d=*(int *)((char *)panel+12); frame.rect2.e=*(float *)((char *)panel+16); frame.rect2.f=*(int *)((char *)panel+20); frame.rect2.g=*(int *)((char *)panel+24); frame.rect2.h=*(int *)((char *)panel+28);
       frame.rect2.b+=lbl_80561988*fn_80147204(&frame.rect2,frame.text2);
       value=lbl_805619A4;
if (blend < value) {} else {
 value=lbl_80561984;
 if (blend > value) {} else {
  if (blend > lbl_80561980) value=(blend*(lbl_805619B8*blend*blend))+(lbl_805619BC*blend*blend);
  else value=(blend*(lbl_805619B8*blend*blend))-(lbl_805619BC*blend*blend);
 }
}
       fn_801479A8(&frame.rect2,detail,frame.text2,value);
     }
   }
 }
 return 1;
}
#pragma pop
#pragma cplusplus reset

extern f32 lbl_805619C0;
extern f32 fn_8016E878(void);
f32 fn_8016E878(void) {
    return lbl_805619C0;
}

extern char lbl_80330BC8[];
extern char lbl_80330BD8[];
extern void *fn_80145E70(const char *);
extern s32 fn_801284F8(s32, const char *);
extern void *fn_802ADDD8(s32);
extern void fn_8016EA9C(void *);
extern void fn_8016E984(void *);
extern s32 fn_80179650(void);
#pragma scheduling invalid_target
void fn_8016E880(void *arg0, void *arg1) {
    u8 *input = (u8 *)arg0;
    u8 *output = (u8 *)arg1;
    u8 *entry;
    s32 offset;
    s32 index;
    *(s32 *)output = *(s32 *)(input + 8);
    *(s32 *)(output + 4) = fn_80179650();
    *(u8 *)(output + 0xD) = 1;
    *(u8 *)(output + 0xE) = 0;
    index = 0;
    offset = 0;
    entry = output;
    goto check;
loop:
    *(s32 *)(entry + 0x10) = index;
    index++;
    *(u8 *)(entry + 0x20) = 0;
    *(s32 *)(entry + 0x18) = **(s32 **)(*(u32 *)(input + 4) + offset);
    offset += 4;
    *(s32 *)(entry + 0x14) = 1;
    *(u8 *)(output + 0xC) = 1;
    entry += 0x14;
check:
    if (index < *(s32 *)(input + 8)) goto loop;
}
#pragma scheduling on
void fn_8016E918(void *arg0) {
    s32 result;
    *(void **)((u8 *)arg0 + 0x98) = fn_80145E70(lbl_80330BC8);
    result = fn_801284F8(8, lbl_80330BD8);
    if (result == 0) goto skip;
    *(void **)((u8 *)arg0 + 0xB8) = ((void *(*)(s32, s32))fn_802ADDD8)(result, 1);
skip:
    {
        volatile u8 *p = (volatile u8 *)arg0;
        fn_8016EA9C((void *)(p + 0xAC));
        fn_8016E984((void *)(p + 0xAC));
    }
}

extern f32 lbl_805619A4;
#pragma scheduling on
void fn_8016E984(void *arg0) {
      register f32 initial = lbl_805619A4;
      volatile s32 temp = *(s32 *)((u8 *)arg0 + 0xC);
      void *p;
      *(s32 *)arg0 = 0;
      *(f32 *)((u8 *)arg0 + 4) = initial;
      *((u8 *)arg0 + 8) = 1;
      *((u8 *)arg0 + 9) = 0;
      *((u8 *)arg0 + 0x10) = 0;
      *(s32 *)((u8 *)arg0 + 0xF8) = 0;
      *(s32 *)((u8 *)arg0 + 0xFC) = 0;
      *(s32 *)((u8 *)arg0 + 0x100) = 0;
      *(s32 *)((u8 *)arg0 + 0x104) = 0;
      if (temp != 0) fn_802AE0E0(temp);
      p = *(void **)((u8 *)arg0 + 0x14);
      if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
      p = *(void **)((u8 *)arg0 + 0x18);
      if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
      p = *(void **)((u8 *)arg0 + 0x1C);
      if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
      p = *(void **)((u8 *)arg0 + 0x24);
      *((u8 *)arg0 + 0x20) = 0;
      if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
      p = *(void **)((u8 *)arg0 + 0x28);
      if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
      p = *(void **)((u8 *)arg0 + 0x2C);
      if (p) { *((u8 *)p + 0x4A) = 1; *((u8 *)p + 0x4C) = 0; }
  }
#pragma scheduling off
extern void fn_80130980(void *, s32, s32, f32);
extern s32 fn_80207848(void *, s32);
extern s32 fn_802ADF34(void *, char *, s32 *);
extern s32 lbl_802FAA40[3];
extern u8 lbl_8055A250;
extern u8 lbl_8055A258;
extern u8 lbl_8055A25C;
extern u8 lbl_8055A260;
extern f32 lbl_805619C4;
#pragma optimize_for_size on
#pragma scheduling invalid_target
void fn_8016EA9C(void *arg0) {
    union Word { s32 i; void *p; } stack[94];
    register char *base;
    volatile s32 *var_r4;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 temp_r12;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 temp_r8;
    s32 temp_r9;
    register u32 var_ctr;
    s32 var_r24;
    s32 var_r6;
    s32 var_r6_2;
    unsigned char *var_r22;
    unsigned char *var_r4_2;
    unsigned char *var_r5;
    unsigned char *var_r5_2;
    unsigned char *var_r7;
    unsigned char *var_r7_2;
    unsigned char temp_r4_2;
    unsigned char temp_r4_3;
    unsigned char temp_r5_2;
    void *temp_r23;
    void *temp_r24;
    void *temp_r24_2;
    void *temp_r25;
    void *temp_r25_2;
    void *temp_r26;
    void *temp_r26_2;
    void *temp_r27;
    void *temp_r28;
    void *temp_r29;

    base = lbl_803306D0;
    var_r4 = (volatile s32 *)&stack[45].i;
    for (var_ctr = 0; var_ctr < 0x18; var_ctr++) {
        var_r4[1] = 0;
        var_r4 += 2;
        var_r4[0] = 0;
    }
    temp_r0 = (s32)((unsigned char *)arg0 + 0xF8);
    stack[44].i = temp_r0;
    temp_r29 = base + 0x524;
    stack[48].i = temp_r0;
    temp_r26 = base + 0x530;
    temp_r28 = base + 0x518;
    stack[30].i = 1;
    temp_r11 = (s32)((unsigned char *)arg0 + 0xFC);
    temp_r10 = (s32)((unsigned char *)arg0 + 0x100);
    stack[42].i = 3;
    temp_r7 = (s32)((unsigned char *)arg0 + 0x104);
    temp_r25 = base + 0x53C;
    stack[43].p = temp_r28;
    temp_r6 = (s32)((unsigned char *)arg0 + 0x30);
    temp_r5 = (s32)((unsigned char *)arg0 + 0x44);
    stack[46].i = 3;
    temp_r24 = base + 0x548;
    temp_r4 = (s32)((unsigned char *)arg0 + 0x58);
    stack[47].p = temp_r28;
    temp_r0_2 = (s32)((unsigned char *)arg0 + 0x6C);
    stack[39].i = 3;
    temp_r8 = (s32)((unsigned char *)arg0 + 0x80);
    stack[40].p = temp_r29;
    stack[41].i = temp_r11;
    stack[49].i = 3;
    stack[50].p = temp_r29;
    stack[51].i = temp_r11;
    stack[36].i = 3;
    stack[37].p = &lbl_8055A250;
    stack[38].i = temp_r10;
    stack[52].i = 3;
    stack[53].p = &lbl_8055A250;
    stack[54].i = temp_r10;
    stack[33].i = 3;
    stack[34].p = temp_r26;
    stack[35].i = temp_r7;
    stack[55].i = 3;
    stack[56].p = temp_r26;
    stack[57].i = temp_r7;
    stack[31].p = temp_r25;
    stack[32].i = temp_r6;
    stack[58].i = 1;
    stack[59].p = temp_r25;
    stack[60].i = temp_r6;
    stack[27].i = 1;
    stack[28].p = temp_r29;
    stack[29].i = temp_r5;
    stack[61].i = 1;
    stack[62].p = temp_r29;
    stack[63].i = temp_r5;
    stack[24].i = 1;
    stack[25].p = temp_r24;
    stack[26].i = temp_r4;
    stack[64].i = 1;
    stack[65].p = temp_r24;
    stack[66].i = temp_r4;
    stack[21].i = 1;
    stack[22].p = temp_r26;
    stack[23].i = temp_r0_2;
    stack[67].i = 1;
    stack[68].p = temp_r26;
    stack[69].i = temp_r0_2;
    stack[18].i = 1;
    stack[19].p = &lbl_8055A250;
    stack[20].i = temp_r8;
    stack[70].i = 1;
    var_r4_2 = (unsigned char *)arg0 + 0x8A;
    temp_r24_2 = base + 0x560;
    temp_r12 = (s32)((unsigned char *)arg0 + 0x9E);
    temp_r25_2 = base + 0x57C;
    stack[71].p = &lbl_8055A250;
    temp_r11_2 = (s32)((unsigned char *)arg0 + 0xB2);
    temp_r23 = base + 0x594;
    stack[72].i = temp_r8;
    temp_r10_2 = (s32)((unsigned char *)arg0 + 0xC6);
    temp_r26_2 = base + 0x5AC;
    stack[15].i = 1;
    temp_r9 = (s32)((unsigned char *)arg0 + 0xDA);
    temp_r27 = base + 0x5C0;
    stack[16].p = temp_r24_2;
    temp_r7_2 = (s32)((unsigned char *)arg0 + 0xF0);
    stack[74].p = temp_r24_2;
    var_r22 = (unsigned char *)&lbl_8055A258;
    stack[17].p = var_r4_2;
    var_r24 = 0x14;
    stack[73].i = 1;
    stack[75].p = var_r4_2;
    stack[12].i = 1;
    stack[13].p = temp_r28;
    stack[14].i = temp_r12;
    stack[76].i = 1;
    stack[77].p = temp_r28;
    stack[78].i = temp_r12;
    stack[9].i = 1;
    stack[10].p = temp_r25_2;
    stack[11].i = temp_r11_2;
    stack[79].i = 1;
    stack[80].p = temp_r25_2;
    stack[81].i = temp_r11_2;
    stack[6].i = 1;
    stack[7].p = temp_r23;
    stack[8].i = temp_r10_2;
    stack[82].i = 1;
    stack[83].p = temp_r23;
    stack[84].i = temp_r10_2;
    stack[3].i = 1;
    stack[4].p = temp_r26_2;
    stack[5].i = temp_r9;
    stack[85].i = 1;
    stack[86].p = temp_r26_2;
    stack[87].i = temp_r9;
    stack[0].i = 2;
    stack[1].p = temp_r27;
    stack[2].i = temp_r7_2;
    stack[88].i = 2;
    stack[89].p = temp_r27;
    stack[90].i = temp_r7_2;
    stack[91].i = lbl_802FAA40[0];
    stack[92].i = lbl_802FAA40[1];
    stack[93].i = lbl_802FAA40[2];
loop_5:
    temp_r5_2 = *var_r22;
    var_r22 += 1;
    *var_r4_2 = temp_r5_2;
    var_r4_2 += 1;
    if ((signed char)temp_r5_2 != 0) {
        var_r24 -= 1;
        if (var_r24 <= 0) {
            *(signed char *)(var_r4_2 - 1) = 0;
        } else {
            goto loop_5;
        }
    }
    var_r7 = (unsigned char *)arg0 + 0x44;
    var_r5 = (unsigned char *)&lbl_8055A25C;
    var_r6 = 0x14;
loop_9:
    temp_r4_2 = *var_r5;
    var_r5 += 1;
    *var_r7 = temp_r4_2;
    var_r7 += 1;
    if ((signed char)temp_r4_2 != 0) {
        var_r6 -= 1;
        if (var_r6 <= 0) {
            *(signed char *)(var_r7 - 1) = 0;
        } else {
            goto loop_9;
        }
    }
    var_r7_2 = (unsigned char *)arg0 + 0x6C;
    var_r5_2 = (unsigned char *)&lbl_8055A260;
    var_r6_2 = 0x14;
loop_13:
    temp_r4_3 = *var_r5_2;
    var_r5_2 += 1;
    *var_r7_2 = temp_r4_3;
    var_r7_2 += 1;
    if ((signed char)temp_r4_3 != 0) {
        var_r6_2 -= 1;
        if (var_r6_2 <= 0) {
            *(signed char *)(var_r7_2 - 1) = 0;
        } else {
            goto loop_13;
        }
    }
    fn_80130980((unsigned char *)arg0 + 0x9E, 0x14, 2, lbl_805619C4);
    *(s32 *)((unsigned char *)arg0 + 0xF0) = fn_80204CF0() + 1;
    *(s32 *)((unsigned char *)arg0 + 0xF4) = fn_802ADF34(*(void **)((unsigned char *)arg0 + 0xC), base + 0x5D4, &stack[46].i);
    *(s32 *)((unsigned char *)arg0 + 0x14) = fn_80207848(base + 0x5E8, 1);
    *(s32 *)((unsigned char *)arg0 + 0x18) = fn_80207848(base + 0x5FC, 1);
    *(s32 *)((unsigned char *)arg0 + 0x1C) = fn_80207848(base + 0x618, 1);
    *(s32 *)((unsigned char *)arg0 + 0x24) = fn_80207848(base + 0x62C, 1);
    *(s32 *)((unsigned char *)arg0 + 0x28) = fn_80207848(base + 0x24C, 1);
    *(s32 *)((unsigned char *)arg0 + 0x2C) = fn_80207848(base + 0x640, 1);
}
#pragma scheduling on
#pragma optimize_for_size reset
extern void fn_802ADE60(s32, s32);
#pragma cplusplus on
extern "C" void fn_8016EE34(void *arg0) {
    /* Release owned resources and virtual subobjects held by this object. */
    class VObj { public: virtual void destroy(int); };
    VObj *resource;
    s32 handle;

    handle = *(s32 *)((u8 *)arg0 + 0xB8);
    if (handle != 0) {
        fn_802ADE60(handle, 1);
        *(s32 *)((u8 *)arg0 + 0xB8) = 0;
    }
    resource = *(VObj **)((u8 *)arg0 + 0xC0);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)arg0 + 0xC0) = 0; }
    resource = *(VObj **)((u8 *)arg0 + 0xC4);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)arg0 + 0xC4) = 0; }
    resource = *(VObj **)((u8 *)arg0 + 0xC8);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)arg0 + 0xC8) = 0; }
    resource = *(VObj **)((u8 *)arg0 + 0xD0);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)arg0 + 0xD0) = 0; }
    resource = *(VObj **)((u8 *)arg0 + 0xD4);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)arg0 + 0xD4) = 0; }
    resource = *(VObj **)((u8 *)arg0 + 0xD8);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)arg0 + 0xD8) = 0; }
    resource = *(VObj **)((u8 *)arg0 + 0x98);
    if (resource != 0) resource->destroy(1);
}
#pragma cplusplus reset

#pragma scheduling on
extern f32 fn_8016FD58(void);
f32 fn_8016FD58(void) {
    return lbl_8055E3C8;
}

void fn_8016FD60(void *arg0, void *arg1) {
    s32 g;
    s32 d, c, b, a;
    f32 f, e;
    volatile s32 *src = (volatile s32 *)arg1;
    volatile f32 *fsrc = (volatile f32 *)((u8 *)arg1 + 0x10);
    a = src[0]; b = src[1]; c = src[2]; d = src[3];
    e = fsrc[0]; f = fsrc[1]; g = src[6];
    *(s32 *)arg0 = a;
    *((s32 *)arg0 + 1) = b;
    *((s32 *)arg0 + 2) = c;
    *((s32 *)arg0 + 3) = d;
    *(f32 *)((u8 *)arg0 + 0x10) = e;
    *(f32 *)((u8 *)arg0 + 0x14) = f;
    *((s32 *)arg0 + 6) = g;
}

void fn_8016FD9C(f32 *arg0, void *arg1) {
    f32 input = *arg0;
    char sp8[0x20];
    f32 value = lbl_80561980;
    value = (input <= value) ? input : value;
    fn_80130978(sp8, 0x20, value);
    fn_8014784C(arg1, lbl_80330B7C, lbl_80330B8C, 0);
    fn_801475D0(arg1, (const char *)&lbl_8055A248, (const char *)&lbl_8055A268, sp8);
}

#pragma cplusplus on
extern "C" void fn_8016FE1C(void *arg0) {
    ((TObj4C *)arg0)->v4C();
}

extern f32 lbl_80561980, lbl_80561984, lbl_805619A4, lbl_80561A0C, lbl_805619D0, lbl_8055E3C8;
extern "C" void fn_802C744C(s32, void *);
extern "C" void fn_802C9900(void);
extern "C" void fn_802C9904(void);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_8016FE2C(void *arg0, s32 arg1) {
    extern float lbl_80561980;
    extern float lbl_80561984;
    extern float lbl_805619A4;
    extern float lbl_805619D0;
    extern float lbl_80561A0C;
    extern float lbl_8055E3C8;
    extern void fn_802C744C(s32, void *);
    extern void fn_802C9900(void);
    extern void fn_802C9904(void);
    f32 b0 = lbl_80561980;
    f32 b1 = lbl_80561984;
    s32 i = 0;
    f32 b2 = lbl_805619A4;
    f32 b3 = lbl_80561A0C;
    s32 offset = 0;
    f32 b4 = lbl_805619D0;
    u8 *entry;
    s32 j;
    s32 suboff;
    u8 *item;
    f32 t;
    f32 v;
    goto outer_check;
outer_body:
    entry = *(u8 **)*(void **)((u8 *)arg0 + 0x48) + offset;
    if (*(u8 *)(entry + 9) != 0) {
        j = 0;
        suboff = 0;
        goto first_check;
first_body:
        item = *(u8 **)*(void **)entry + suboff;
        if (*(s32 *)(item + 0xC) == 1) {
            fn_802C744C(*(s32 *)item, item + 0x14);
        }
        suboff += 0x44;
        j += 1;
first_check:
        if (j < *(s32 *)((u8 *)*(void **)entry + 4)) {
            goto first_body;
        }
        goto outer_inc;
    }
    if (*(u8 *)(entry + 9) != 0) {
        goto outer_inc;
    }
    t = lbl_8055E3C8 - *(f32 *)(entry + 0xC);
    if (t < b4) {
        v = (t - b0) / b4;
        if (b1 < v) {
            v = b1;
        }
        v = v > b0 ? b0 : v;
        if (b1 + v * b2 > b3) {
            fn_802C9900();
            j = 0;
            suboff = 0;
            goto second_check;
second_body:
            item = *(u8 **)*(void **)entry + suboff;
            if (*(s32 *)(item + 0xC) == 1) {
                fn_802C744C(*(s32 *)item, item + 0x14);
            }
            suboff += 0x44;
            j += 1;
second_check:
            if (j < *(s32 *)((u8 *)*(void **)entry + 4)) {
                goto second_body;
            }
            fn_802C9904();
        }
    }
outer_inc:
    offset += 0x14;
    i += 1;
outer_check:
    if (i < *(s32 *)((u8 *)arg0 + 0x6C)) {
        goto outer_body;
    }
}
#pragma pop

#pragma cplusplus reset
void fn_8016FF98(void *arg0) {
    s32 off;
    s32 found;
    s32 count = *(s32 *)((u8 *)arg0 + 8);
    s32 i;
    found = 0;
    off = 0;
    for (i = 0; i < count; i++, off += 4) {
        void **items = *(void ***)((u8 *)arg0 + 4);
        void *elem = *(void **)((u8 *)items + off);
        if (*(u8 *)((u8 *)elem + 8) != 0) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        fn_8016A438();
    }
}

s32 fn_8016FFE4(void) { return 0x1408; }

extern void *fn_8000AC38(void);
extern char lbl_80330DF4[];
extern char lbl_8055A270[];
extern float lbl_80561980;
s32 fn_8016FFEC(void *arg0, void *arg1, s32 arg2) {
char sp60[16];
char sp40[16];
float sp70[6];
void *manager;
void *obj;
int i;
manager = *(void **)((char *)fn_8000AC38() + 0x20);
if (manager == 0) return 0;
fn_801345D8(sp60, 0x10, lbl_80330DF4, arg2);
obj = ((void *(*)(void *, void *))*(void **)((char *)*(void **)manager + 0x5C))(manager, sp60);
if (obj == 0) return 0;
i = 0;
do {
fn_801345D8(sp40, 0x10, lbl_8055A270, i);
i += 1;
} while (i < 3);
sp70[0] = lbl_80561980;
return 1;
}

#pragma cplusplus on
extern "C" s32 fn_80009C84(void);
extern "C" u8 *fn_80131234(const char *);
extern "C" s32 fn_80141FA0(void);
extern "C" void fn_80142B60(s32);
extern "C" void fn_80144C54(s32);
extern "C" s32 fn_8015A404(s32);
extern "C" s32 fn_801609C4(s32);
extern "C" s32 fn_80161C38(void);
extern "C" s32 fn_8016A30C(void);
extern "C" s32 fn_8016A780(void *, s32);
extern "C" s32 fn_8016A878(void *);
extern "C" void fn_8016B964(void *, s32, s32, s32);
extern "C" void fn_8016DE20(void *);
extern "C" void fn_8016E1B4(void *, s32);
extern "C" f32 fn_8016FD58(void);
extern "C" void fn_80170E98(void *, void *, s32);
extern "C" s32 fn_80179650(void);
extern "C" f32 fn_801B306C(void);
extern "C" void fn_801CB5DC(s32, s32, s32);
extern "C" void fn_801CB648(s32, s32, f32);
extern "C" u8 fn_80170E90(void *);
extern "C" s32 fn_80170E88(void *);
extern "C" f32 fn_80170E80(f32 *);
extern "C" s32 fn_80170E78(void *);
extern "C" void fn_80170DA8(void *, void *);
extern "C" char lbl_803306D0[];
extern "C" u8 lbl_8055A20C;
extern "C" f32 lbl_8055E3C8;
extern "C" f32 lbl_80561980;
extern "C" f32 lbl_80561984;
extern "C" f32 lbl_805619A8;
extern "C" f32 lbl_805619AC;
extern "C" f32 lbl_805619B0;
extern "C" f32 lbl_805619C8;
extern "C" f32 lbl_805619CC;
extern "C" f32 lbl_805619D0;
extern "C" f32 lbl_805619E0;
extern "C" f32 lbl_80561A14;
extern "C" f32 lbl_80561A18;
extern "C" f32 lbl_80561A1C;
#pragma cplusplus on
extern "C" void fn_80170414(void *arg0) {
    u32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f2;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f31;
    f32 var_f29;
    f32 var_f30;
    f32 var_f4;
    f32 var_f7;
    s32 *temp_r3_4;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r22;
    s32 temp_r22_2;
    s32 temp_r23;
    s32 temp_r23_2;
    s32 temp_r23_3;
    s32 temp_r24;
    s32 temp_r3_10;
    s32 temp_r3_11;
    s32 temp_r3_3;
    s32 temp_r3_8;
    s32 temp_r3_9;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_6;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r8;
    s32 var_r0;
    s32 var_r26;
    s32 var_r27;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    u8 *var_r3;
    u8 *var_r3_2;
    u8 *var_r3_3;
    u8 *var_r4;
    u8 *var_r4_2;
    u8 *var_r4_3;
    u8 *var_r6;
    u8 *var_r6_2;
    u8 *var_r6_3;
    u8 *var_r6_4;
    u8 *var_r6_5;
    u8 *var_r6_6;
    u8 temp_r3_5;
    u8 temp_r3_6;
    u8 temp_r3_7;
    u8 temp_r4_3;
    u8 temp_r4_4;
    u8 temp_r4_5;
    void *temp_r3;
    void *temp_r3_12;
    void *temp_r3_13;
    void *temp_r3_2;
    void *temp_r4_7;
    void *temp_r7;

    temp_f1 = fn_801B306C();
    if (((s32) M2C_FIELD(arg0, u8 *, 0xA8) == 0) && (temp_f1 < lbl_805619A8)) {
        M2C_FIELD(arg0, u8 *, 0xA8) = 1U;
        if (((void *) M2C_FIELD(arg0, void **, 0xA4) != 0) && (fn_80161C38() == 0) && (fn_80179650() == 1) && (fn_80009C84() == 0)) {
            temp_r3 = M2C_FIELD(arg0, void **, 0xA4);
            M2C_FIELD(temp_r3, s8 *, 0x49) = 1;
            M2C_FIELD(temp_r3, s8 *, 0x4B) = 0;
            M2C_FIELD(temp_r3, s8 *, 0x4A) = 0;
        }
    }
    temp_f29 = lbl_8055E3C8;
    if ((temp_f29 > ((TObj4C *)arg0)->d12()) && ((s32) M2C_FIELD(arg0, s32 *, 0x68) > 0)) {
        temp_f29_2 = lbl_80561A14;
        var_r26 = 0;
        temp_f31 = lbl_80561980;
        var_r27 = 0;
loop_83:
        if (var_r26 < (s32) M2C_FIELD(arg0, s32 *, 8)) {
            if (((TObj4C *)arg0)->d7() == 0) {
                temp_r3_2 = *(void **)(*(u8 **)((u8 *)arg0 + 4) + var_r27);
                if ((s32) M2C_FIELD(temp_r3_2, u8 *, 8) != 0) {
                    M2C_FIELD(temp_r3_2, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r3_2, f32 *, 0xC) + temp_f29_2);
                }
                temp_r23 = *(s32 *)(*(u8 **)((u8 *)arg0 + 4) + var_r27);
                fn_80170E98((u8 *)arg0 + 0x30, &sp8, 0x1E);
                if ((fn_80170E90((void *)temp_r23) == 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0)) {
                    temp_r22 = fn_80170E88((void *)temp_r23);
                    temp_f30 = fn_80170E80((f32 *)((u8 *)arg0 + 0x38));
                    *(f32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 3) = temp_f30;
                    fn_80170E78((void *)temp_r22);
                    temp_r23_2 = fn_8016A30C();
                    temp_r3_3 = fn_8016A780(&sp8, fn_80170E78((void *)temp_r22));
                    if ((temp_r3_3 == 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x7A) == 0)) {
                        M2C_FIELD(arg0, u8 *, 0x7A) = 1U;
                        fn_8016DFB8((u8 *)arg0 + 0x30);
                    }
                    if (((s32) M2C_FIELD(arg0, u8 *, 0x7A) != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x54) == -1)) {
                        fn_8016DE20((u8 *)arg0 + 0x30);
                    }
                    if (((temp_r23_2 > 0) || (temp_r3_3 == fn_8016A878(&sp8)) || ((temp_r3_3 > 0) && (fn_8015A404(temp_r22) > 1))) && ((s32) M2C_FIELD(arg0, u8 *, 0x7A) != 0)) {
                        temp_f30_2 = fn_8016FD58();
                        *(f32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 2) = temp_f30_2;
                        fn_8016E1B4((u8 *)arg0 + 0x30, M2C_FIELD(arg0, s32 *, 0x5C));
                        if (temp_r23_2 > 0) {
                            *(s8 *)fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) = 1;
                            M2C_FIELD(arg0, s32 *, 0x64) = (s32) M2C_FIELD(arg0, s32 *, 0x60);
                            temp_r5 = *(s32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 1);
                            temp_r0 = M2C_FIELD(arg0, s32 *, 0x74) + 1;
                            M2C_FIELD(arg0, s32 *, 0x74) = temp_r0;
                            M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) + temp_r5);
                            if (temp_r0 > 2) {
                                M2C_FIELD(arg0, s32 *, 0x74) = 2;
                            }
                            if ((s32) M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
                                if (fn_80141FA0() != 0) {
                                    fn_80144C54(M2C_FIELD(arg0, s32 *, 0x7C));
                                }
                                fn_80142B60(M2C_FIELD(arg0, s32 *, 0x7C));
                            }
                            if ((s32) M2C_FIELD(arg0, s32 *, 0x80) != 0) {
                                if (fn_80141FA0() != 0) {
                                    fn_80144C54(M2C_FIELD(arg0, s32 *, 0x80));
                                }
                                fn_80142B60(M2C_FIELD(arg0, s32 *, 0x80));
                            }
                            if (((*(s32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 1) == 0xA) || (*(s32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 1) == 0xF)) && ((void *) M2C_FIELD(arg0, void **, 0x84) != 0)) {
                                fn_80142B60(M2C_FIELD(arg0, s32 *, 0x84));
                            }
                        } else {
                            temp_r0_2 = M2C_FIELD(arg0, s32 *, 0x74) - 1;
                            M2C_FIELD(arg0, s32 *, 0x74) = temp_r0_2;
                            if (temp_r0_2 < 0) {
                                M2C_FIELD(arg0, s32 *, 0x74) = 0;
                            }
                        }
                        temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
                        if (temp_r4 < (s32) (M2C_FIELD(arg0, s32 *, 0x68) - 1)) {
                            M2C_FIELD(arg0, u8 *, 0x7A) = 0U;
                            M2C_FIELD(arg0, s32 *, 0x5C) = (s32) (temp_r4 + 1);
                            temp_r24 = fn_8016DD98((u8 *)arg0 + 0x30);
                            *(s32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 1) = temp_r24;
                            fn_8016E06C((u8 *)arg0 + 0x30);
                        } else {
                            M2C_FIELD(arg0, u8 *, 0x78) = 1U;
                            M2C_FIELD(arg0, u8 *, 0x79) = 1U;
                        }
                    } else {
                        fn_80170DA8((void *)fn_8016E1A4((s32 *)*(void **)((u8 *)arg0 + 0x48), *(s32 *)((u8 *)arg0 + 0x5C)), (void *)temp_r22);
                    }
                } else if ((s32) M2C_FIELD(arg0, s32 *, 0x54) != -1) {
                    fn_8016E118((u8 *)arg0 + 0x30);
                }
            }
            temp_r4_2 = M2C_FIELD(arg0, s32 *, 0x64);
            temp_r3_4 = *(s32 **)(*(u8 **)((u8 *)arg0 + 4) + var_r27);
            if ((s32) *temp_r3_4 != temp_r4_2) {
                *temp_r3_4 = temp_r4_2;
            }
            if (((s32) M2C_FIELD(arg0, u8 *, 0x9C) != 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x79) != 0)) {
                if (M2C_FIELD(arg0, f32 *, 0xA0) < temp_f31) {
                    M2C_FIELD(arg0, f32 *, 0xA0) = (f32) lbl_8055E3C8;
                }
                if ((s32) M2C_FIELD(arg0, u8 *, 0x78) != 0) {
                    var_r3 = fn_80131234(lbl_803306D0 + 0x744);
                    var_r6 = (u8 *)arg0 + 0x15E;
                    var_r5 = 0x14;
loop_59:
                    temp_r4_3 = *var_r3;
                    var_r3 += 1;
                    *var_r6 = temp_r4_3;
                    var_r6 += 1;
                    if ((s8) temp_r4_3 != 0) {
                        var_r5 -= 1;
                        if (var_r5 <= 0) {
                            M2C_FIELD(var_r6, s8 *, -1) = 0;
                        } else {
                            goto loop_59;
                        }
                    }
                    var_r3_2 = fn_80131234(lbl_803306D0 + 0x768);
                    var_r6_2 = (u8 *)arg0 + 0x172;
                    var_r5_2 = 0x14;
loop_63:
                    temp_r4_4 = *var_r3_2;
                    var_r3_2 += 1;
                    *var_r6_2 = temp_r4_4;
                    var_r6_2 += 1;
                    if ((s8) temp_r4_4 != 0) {
                        var_r5_2 -= 1;
                        if (var_r5_2 <= 0) {
                            M2C_FIELD(var_r6_2, s8 *, -1) = 0;
                        } else {
                            goto loop_63;
                        }
                    }
                    var_r6_3 = (u8 *)arg0 + 0x186;
                    var_r4 = (u8 *)&lbl_8055A20C;
                    var_r5_3 = 0x14;
loop_67:
                    temp_r3_5 = *var_r4;
                    var_r4 += 1;
                    *var_r6_3 = temp_r3_5;
                    var_r6_3 += 1;
                    if ((s8) temp_r3_5 != 0) {
                        var_r5_3 -= 1;
                        if (var_r5_3 <= 0) {
                            M2C_FIELD(var_r6_3, s8 *, -1) = 0;
                        } else {
                            goto loop_67;
                        }
                    }
                } else {
                    var_r3_3 = fn_80131234(lbl_803306D0 + 0x78C);
                    var_r6_4 = (u8 *)arg0 + 0x186;
                    var_r5_4 = 0x14;
loop_72:
                    temp_r4_5 = *var_r3_3;
                    var_r3_3 += 1;
                    *var_r6_4 = temp_r4_5;
                    var_r6_4 += 1;
                    if ((s8) temp_r4_5 != 0) {
                        var_r5_4 -= 1;
                        if (var_r5_4 <= 0) {
                            M2C_FIELD(var_r6_4, s8 *, -1) = 0;
                        } else {
                            goto loop_72;
                        }
                    }
                    var_r6_5 = (u8 *)arg0 + 0x15E;
                    var_r4_2 = (u8 *)&lbl_8055A20C;
                    var_r5_5 = 0x14;
loop_76:
                    temp_r3_6 = *var_r4_2;
                    var_r4_2 += 1;
                    *var_r6_5 = temp_r3_6;
                    var_r6_5 += 1;
                    if ((s8) temp_r3_6 != 0) {
                        var_r5_5 -= 1;
                        if (var_r5_5 <= 0) {
                            M2C_FIELD(var_r6_5, s8 *, -1) = 0;
                        } else {
                            goto loop_76;
                        }
                    }
                    var_r6_6 = (u8 *)arg0 + 0x172;
                    var_r4_3 = (u8 *)&lbl_8055A20C;
                    var_r5_6 = 0x14;
loop_80:
                    temp_r3_7 = *var_r4_3;
                    var_r4_3 += 1;
                    *var_r6_6 = temp_r3_7;
                    var_r6_6 += 1;
                    if ((s8) temp_r3_7 != 0) {
                        var_r5_6 -= 1;
                        if (var_r5_6 <= 0) {
                            M2C_FIELD(var_r6_6, s8 *, -1) = 0;
                        } else {
                            goto loop_80;
                        }
                    }
                }
                temp_f0 = M2C_FIELD(arg0, f32 *, 0x38);
                temp_r23_3 = M2C_FIELD(arg0, s32 *, 0x60);
                fn_801CB5DC(var_r26, temp_r23_3 + (s32) temp_f0, fn_801609C4(temp_r23_3 + (s32) temp_f0));
                fn_801CB648(var_r26, 1, M2C_FIELD(arg0, f32 *, 0x38));
                M2C_FIELD(arg0, u8 *, 0x9C) = 0U;
            }
            var_r27 += 4;
            var_r26 += 1;
            goto loop_83;
        }
        if ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0) {
            temp_f1_2 = M2C_FIELD(arg0, f32 *, 0x58) + lbl_80561A14;
            M2C_FIELD(arg0, f32 *, 0x58) = temp_f1_2;
            if (temp_f1_2 > lbl_80561A18) {
                M2C_FIELD(arg0, f32 *, 0x58) = (f32) lbl_80561980;
            }
            if (*(f32 *)((u8 *)arg0 + 0x38) <= lbl_80561980) {
                *(u8 *)((u8 *)arg0 + 0x79) = 1;
            } else if (!(fn_801B306C() <= lbl_80561980)) {
                *(f32 *)((u8 *)arg0 + 0x38) -= lbl_80561A14;
            }
        }
        temp_r3_8 = M2C_FIELD(arg0, s32 *, 0x5C);
        if (temp_r3_8 > 0) {
            var_r5_7 = temp_r3_8 - 1;
            if ((s32) M2C_FIELD(arg0, u8 *, 0x78) != 0) {
                var_r5_7 = temp_r3_8;
            }
            temp_r6 = M2C_FIELD(arg0, s32 *, 0x60);
            temp_r4_6 = M2C_FIELD(arg0, s32 *, 0x64);
            if (temp_r4_6 < temp_r6) {
                temp_r0_3 = var_r5_7 * 0x10;
                temp_r3_9 = *M2C_FIELD(arg0, s32 **, 0x4C);
                temp_r7 = (u8 *)temp_r3_9 + temp_r0_3;
                if ((s32) *(s32 *)((u8 *)temp_r3_9 + temp_r0_3) != 0) {
                    temp_r8 = M2C_FIELD(temp_r7, s32 *, 4);
                    var_f7 = lbl_80561984;
                    temp_f2 = lbl_805619B0 + (lbl_805619CC + (lbl_805619C8 * (f32) temp_r8)) + (lbl_805619C8 * (f32) (temp_r8 - (temp_r6 - temp_r4_6)));
                    temp_f0_2 = ((lbl_8055E3C8 - M2C_FIELD(temp_r7, f32 *, 8)) - temp_f2) / ((lbl_805619D0 + temp_f2) - temp_f2);
                    if (var_f7 < temp_f0_2) {

                    } else {
                        var_f7 = temp_f0_2;
                    }
                    if (var_f7 > lbl_80561980) {

                    } else {
                        var_f7 = lbl_80561980;
                    }
                    temp_r3_10 = (s32) (lbl_80561980 + (var_f7 * lbl_80561984));
                    if (temp_r3_10 != 0) {
                        temp_r4_7 = M2C_FIELD(arg0, void **, 0x88);
                        temp_r3_11 = M2C_FIELD(arg0, s32 *, 0x64) + temp_r3_10;
                        M2C_FIELD(arg0, s32 *, 0x64) = temp_r3_11;
                        if ((temp_r4_7 != 0) && ((s32) M2C_FIELD(temp_r4_7, u8 *, 0x19) == 0) && (temp_r3_11 != (s32) M2C_FIELD(arg0, s32 *, 0x60))) {
                            M2C_FIELD(temp_r4_7, s8 *, 0x4A) = 0;
                            M2C_FIELD(temp_r4_7, s8 *, 0x4B) = 1;
                            M2C_FIELD(temp_r4_7, s8 *, 0x49) = 1;
                        }
                        if ((s32) M2C_FIELD(arg0, s32 *, 0x64) == (s32) M2C_FIELD(arg0, s32 *, 0x60)) {
                            temp_r3_12 = M2C_FIELD(arg0, void **, 0x88);
                            if ((temp_r3_12 != 0) && ((s32) M2C_FIELD(temp_r3_12, u8 *, 0x19) != 0)) {
                                M2C_FIELD(temp_r3_12, s8 *, 0x4A) = 1;
                                M2C_FIELD(temp_r3_12, s8 *, 0x4C) = 0;
                            }
                        }
                    }
                }
            }
            if ((void *) M2C_FIELD(arg0, void **, 0x84) != 0) {
                temp_r22_2 = var_r5_7 * 0x10;
                temp_r0_4 = *M2C_FIELD(arg0, s32 **, 0x4C);
                if ((s32) *(s32 *)((u8 *)temp_r0_4 + temp_r22_2) != 0) {
                    var_f30 = lbl_80561980;
                    temp_r0_5 = M2C_FIELD(((u8 *)temp_r0_4 + temp_r22_2), s32 *, 4);
                    var_f29 = var_f30;
                    switch (temp_r0_5) {
                    case 5:
                        var_r0 = 0;
                        break;
                    case 10:
                        var_r0 = 1;
                        break;
                    case 15:
                        var_r0 = 2;
                        break;
                    default:
                        fn_802E317C(lbl_803306D0 + 0x7A8);
                        var_r0 = 0;
                        break;
                    }
                    switch (var_r0) {
                    case 1:
                        var_f30 = lbl_805619AC;
                        var_f29 = lbl_80561984;
                        break;
                    case 2:
                        var_f30 = lbl_80561984;
                        var_f29 = lbl_805619E0;
                        break;
                    }
                    if (var_f30 != lbl_80561980) {
                        var_f4 = lbl_80561984;
                        temp_f0_3 = ((lbl_8055E3C8 - *(f32 *)((u8 *)*M2C_FIELD(arg0, s32 **, 0x4C) + temp_r22_2 + 8)) - lbl_80561980) / (var_f29 - lbl_80561980);
                        if (var_f4 < temp_f0_3) {

                        } else {
                            var_f4 = temp_f0_3;
                        }
                        if (var_f4 > lbl_80561980) {

                        } else {
                            var_f4 = lbl_80561980;
                        }
                        temp_r3_13 = M2C_FIELD(arg0, void **, 0x84);
                        temp_f1_3 = var_f30 + (var_f4 * (lbl_80561980 - var_f30));
                        if (temp_f1_3 != M2C_FIELD(temp_r3_13, f32 *, 8)) {
                            M2C_FIELD(temp_r3_13, s8 *, 0x4D) = 1;
                            M2C_FIELD(temp_r3_13, f32 *, 8) = temp_f1_3;
                        }
                    }
                }
            }
        }
    }
    if ((((TObj4C *)arg0)->d7() != 0) && !((lbl_8055E3C8 - M2C_FIELD(arg0, f32 *, 0xA0)) < lbl_80561A1C)) {
        temp_r5_2 = M2C_FIELD(arg0, s32 *, 0x60);
        temp_r6_2 = (s32) M2C_FIELD(arg0, f32 *, 0x38);
        fn_8016B964((u8 *)arg0 + 0xAC, temp_r5_2 + temp_r6_2, temp_r5_2, temp_r6_2);
    }
}
#pragma cplusplus off

extern f64 fn_8002F234(f32, f32, f32, f32, f32);
#pragma use_lmw_stmw off
void fn_80170DA8(void *arg0, void *arg1) {
    u8 *base;
    u8 *item;
    s32 index;
    s32 next;
    s32 off;
    volatile f32 sp1C, sp18, sp14, sp10, spC, sp8;
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;
    f32 distance;
    f32 threshold;
    index = *(s32 *)((u8 *)arg0 + 0x10);
    next = index + 1;
    if (next < *(s32 *)(*(u8 **)((u8 *)arg0 + 4) + 4)) {
        off = (index + 1) * 0x38;
        base = *(u8 **)*(void **)((u8 *)arg0 + 4);
        x = *(f32 *)((u8 *)arg1 + 0x60);
        y = *(f32 *)((u8 *)arg1 + 0x68);
        item = base + off;
        dx = *(f32 *)(item + 0x24) - x;
        sp18 = *(f32 *)(item + 0x24);
        dy = *(f32 *)(item + 0x2C) - y;
        sp1C = *(f32 *)(item + 0x2C);
        sp10 = x;
        sp14 = y;
        sp8 = dx;
        spC = dy;
        distance = (f32)fn_8002F234(dx * dx + dy * dy, y, x, dx, dy);
        threshold = *(f32 *)(item + 0x34);
        if (distance < threshold) {
            *(u8 *)(base + index * 0x38 + 0x30) = 0;
            *(s32 *)((u8 *)arg0 + 0x10) = next;
            *(u8 *)(*(u8 **)*(void **)((u8 *)arg0 + 4) + next * 0x38 + 0x30) = 1;
        }
    }
}
#pragma use_lmw_stmw on
s32 fn_80170E78(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x1ec); }

f32 fn_80170E80(f32 *arg0) { return *arg0; }

extern s32 fn_8017960C(s32);
s32 fn_80170E88(void *arg0) {
    return fn_8017960C(*(s32 *)((u8 *)arg0 + 4));
}

u8 fn_80170E90(void *arg0) { return *(u8 *)((u8 *)arg0 + 8); }

extern char lbl_803306D0[];
extern char lbl_80330AEC[];
extern char lbl_8033072C[];
extern char lbl_803308A0[];
extern f32 lbl_80561980;
extern void fn_802E317C(const char *, ...);
void fn_80170E98(void *arg0, void *arg1, s32 arg2) {
    register const char *messages = lbl_803306D0;
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);

    switch (value) {
    case 0:
        ((void (*)(void *, s32, const char *, ...))fn_801345D8)(
            arg1, arg2, messages + 0x264, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    case 1:
        ((void (*)(void *, s32, const char *, ...))fn_801345D8)(
            arg1, arg2, messages + 0x270, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    case 2:
        ((void (*)(void *, s32, const char *, ...))fn_801345D8)(
            arg1, arg2, messages + 0x27c, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    default:
        fn_802E317C((void *)(messages + 0x288));
        break;
    }
}

s32 fn_80170F1C(void *arg0) {
    s32 result = 0;
    if (fn_801B8514() != 0 && *((u8 *)arg0 + 0x79) != 0 && *((u8 *)arg0 + 0x9C) == 0) {
        result = 1;
    }
    return result;
}

#pragma cplusplus on
extern "C" s32 fn_80170F7C(void *arg0) {
    if (((TObj4C *)arg0)->d7() != 0) {
        return *(s32 *)((u8 *)arg0 + 0xAC) == 2;
    }
    return 0;
}
#pragma cplusplus off
u32 fn_80170FD4(void) { return 1; }

extern f32 lbl_80561A1C;
extern s32 fn_802AE220(s32, s32);
extern s32 fn_8001DFCC(void);
#pragma cplusplus on
class Q70FDC {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual s32 query();
};
extern "C" u32 fn_80170FDC(void *arg0) {
    s32 temp_r4;
    if ((lbl_8055E3C8 - *(volatile f32 *)((u8 *)arg0 + 0xA0)) < lbl_80561A1C) {
        ((Q70FDC *)arg0)->f17();
    } else {
        if (*(u8 *)((u8 *)arg0 + 0xB4) != 0)
            ((Q70FDC *)arg0)->f17();
        if (*(s32 *)((u8 *)arg0 + 0xB8) != 0)
            fn_802AE220(*(s32 *)((u8 *)arg0 + 0xB8), 0);
    }
    if (((Q70FDC *)arg0)->query() != 0)
        fn_8001DFCC();
    temp_r4 = *(s32 *)((u8 *)arg0 + 0xAC);
    return (u32)((4 - temp_r4) | (temp_r4 - 4)) >> 31;
}
#pragma cplusplus reset

extern s32 fn_802AE118(void);
#pragma cplusplus on
extern "C" s32 fn_80171094(void *obj, s32 unused, s32 actionId) {
    /* Handle action 0x58 or advance timed state and trigger child activation near timeout. */
    struct Query {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
        virtual s32 query();
    };
    s32 mode;
    f32 startTime;
    f32 currentTime;

    if (((Query *)obj)->query() != 0 && actionId == 0x58) {
        if (*(volatile s32 *)((u8 *)obj + 0xAC) == 2)
            *(u8 *)((u8 *)obj + 0xB5) = 1;
        return 1;
    }
    if (*(volatile s32 *)((u8 *)obj + 0xAC) != 0) {
        currentTime = lbl_8055E3C8;
        mode = *(volatile s32 *)((u8 *)obj + 0xAC);
        if (mode == 1 && *(u8 *)((u8 *)obj + 0xBC) == 0) {
            startTime = *(f32 *)((u8 *)obj + 0xB0);
            if (startTime > lbl_80561980 && currentTime - startTime < lbl_80561984) {
                register void *timerHandle;
                void *child;
                timerHandle = *(void **)((u8 *)obj + 0xB8);
                *(u8 *)((u8 *)obj + 0xBC) = 1;
                if (timerHandle != 0)
                    fn_802AE118();
                child = *(void **)((u8 *)obj + 0xC0);
                if (child != 0) {
                    *(u8 *)((u8 *)child + 0x4A) = 1;
                    *(u8 *)((u8 *)child + 0x4C) = 0;
                }
                child = *(void **)((u8 *)obj + 0xC4);
                if (child != 0) {
                    *(u8 *)((u8 *)child + 0x4A) = 1;
                    *(u8 *)((u8 *)child + 0x4C) = 0;
                }
                child = *(void **)((u8 *)obj + 0xD4);
                if (child != 0) {
                    *(u8 *)((u8 *)child + 0x4A) = 1;
                    *(u8 *)((u8 *)child + 0x4C) = 0;
                }
                child = *(void **)((u8 *)obj + 0xD8);
                if (child != 0) {
                    *(u8 *)((u8 *)child + 0x4A) = 1;
                    *(u8 *)((u8 *)child + 0x4C) = 0;
                }
                {
                    f32 floorValue;
                    f32 finalTime;
                    s32 zero;
                    finalTime = lbl_8055E3C8;
                    zero = 0;
                    floorValue = lbl_80561984;
                    if ((*(volatile u8 *)((u8 *)obj + 0xB4) = zero) == 0)
                        *(f32 *)((u8 *)obj + 0xB0) = finalTime - floorValue;
                }
            }
        }
        return 1;
    }
    return 0;
}
#pragma cplusplus reset
s32 fn_801711F8(void *arg0) {
    return *((u8 *)arg0 + 0x79) == 0;
}

void fn_80171208(void *arg0, s32 arg1) {
    fn_801B0C78((void *)arg1);
}

extern void fn_801B8060(void *, void *);
extern f32 lbl_80561A20;
extern f32 lbl_80561A24;
s32 fn_80171210(void *arg0, s32 arg1, void *arg2) {
    s32 count;
    register f32 reset = lbl_80561980;
    register void *item;
    register void *list;
    register void *entry;
    register void *record;
    s32 index;
    s32 nextIndex;
    f32 x;
    f32 scale;
    f32 scaledX;
    f32 z;

    item = ((void **)M2C_FIELD(arg0, void **, 4))[arg1];
    M2C_FIELD(item, u8 *, 8) = 0;
    M2C_FIELD(item, f32 *, 0xC) = reset;
    count = M2C_FIELD(arg0, s32 *, 0x5C);
    if (count < M2C_FIELD(arg0, s32 *, 0x6C)) {
        list = M2C_FIELD(arg0, void **, 0x48);
        entry = (u8 *)M2C_FIELD(list, void **, 0) + count * 0x14;
        list = M2C_FIELD(entry, void **, 4);
        if (list != 0 && M2C_FIELD(list, s32 *, 4) > 0 &&
            *((u8 *)M2C_FIELD(list, void **, 0) +
              *(volatile s32 *)((u8 *)entry + 0x10) * 0x38 + 0x30) != 0) {
            list = *(void * volatile *)((u8 *)entry + 4);
            index = *(volatile s32 *)((u8 *)entry + 0x10);
            nextIndex = index + 1;
            if (nextIndex < M2C_FIELD(list, s32 *, 4))
                record = (u8 *)M2C_FIELD(list, void * volatile *, 0) + nextIndex * 0x38;
            else
                record = (u8 *)M2C_FIELD(list, void * volatile *, 0) + index * 0x38;
            fn_801B8060(arg2, record);
            x = *(volatile f32 *)((u8 *)record + 0x18);
            scale = lbl_80561A20;
            z = *(volatile f32 *)((u8 *)arg2 + 0x28);
            scaledX = x * scale;
            z = z + *(volatile f32 *)&lbl_80561A24;
            *(f32 *)((u8 *)arg2 + 0x30) = scaledX;
            *(f32 *)((u8 *)arg2 + 0x34) = *(f32 *)((u8 *)record + 0x1C) * scale;
            *(f32 *)((u8 *)arg2 + 0x38) = *(f32 *)((u8 *)record + 0x20) * scale;
            *(f32 *)((u8 *)arg2 + 0x28) = z;
            return 1;
        }
        return 0;
    }
    return 0;
}

extern f32 lbl_80558DC4;
extern f32 lbl_80561A28;
extern f32 PSVECDotProduct(const void *, const void *, f32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
__declspec(section ".data") extern f32 lbl_80558DC4;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 fn_8017133C(void *arg0, s32 arg1, s8 *arg2) {
    class Base {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual f32 f12();
    };
    class Pcr {
    public:
        virtual void p0(); virtual void p1(); virtual void p2();
        virtual s32 m3();
    };
    void *obj;
    s32 index;
    void *holder;
    s32 result;
    s32 r25;
    void *data;
    void *item;
    s32 d;
    s32 r4v;
    s32 cond;
    volatile f32 sp1C, sp18, sp14, sp10, spC, sp8;
    f32 x, y, dx, dy;
    f32 v;

    result = 0;
    v = lbl_8055E3C8;
    if (v > ((Base *)arg0)->f12() && *(u8 *)((u8 *)arg0 + 0x78) == 0) {
        index = arg1 * 4;
        data = (void *)fn_8017960C(*(s32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 4));
        cond = ((f32)__fabs((f64)*(f32 *)((u8 *)data + 0x2690)) <= lbl_80558DC4);
        if (cond) {
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index);
            r4v = *(s32 *)((u8 *)arg0 + 0x5C);
            if (r4v < *(s32 *)((u8 *)arg0 + 0x6C)) {
                holder = (u8 *)(**(s32 ***)((u8 *)arg0 + 0x48)) + r4v * 0x14;
                if (*(void **)((u8 *)holder + 4) != 0 &&
                    *(s32 *)((u8 *)*(void **)((u8 *)holder + 4) + 4) > 0 &&
                    *(u8 *)((u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38 + 0x30) != 0) {
                    data = (void *)fn_8017960C(*(s32 *)((u8 *)obj + 4));
                    item = (u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38;
                    x = *(f32 *)((u8 *)data + 0x60);
                    y = *(f32 *)((u8 *)data + 0x68);
                    dx = *(f32 *)((u8 *)item + 0x24) - x;
                    dy = *(f32 *)((u8 *)item + 0x2C) - y;
                    sp10 = *(f32 *)((u8 *)item + 0x24);
                    sp14 = *(f32 *)((u8 *)item + 0x2C);
                    sp18 = x;
                    sp1C = y;
                    sp8 = dx;
                    spC = dy;
                    r25 = ((f32)fn_8002F234(dx * dx + dy * dy, y, x, dx, dy) > *(f32 *)((u8 *)item + 0x34));
                    d = (PSVECDotProduct((u8 *)item + 0x18, (u8 *)data + 0x54, *(f32 *)((u8 *)item + 0x34)) < lbl_80561980);
                    if (*(s32 *)((u8 *)holder + 0x10) == *(s32 *)((u8 *)*(void **)((u8 *)holder + 4) + 4) - 1 && r25) {
                        *(u8 *)((u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38 + 0x30) = 0;
                        result = 0;
                    } else {
                        if (r25 || d) {
                            if (*(u8 *)((u8 *)obj + 8) == 0) {
                                *(u8 *)((u8 *)obj + 8) = 1;
                                *(f32 *)((u8 *)obj + 0xC) = lbl_80561980;
                            }
                            if (*(f32 *)((u8 *)obj + 0xC) > lbl_80561A28) {
                                *arg2 = 1;
                            } else {
                                *arg2 = 0;
                            }
                        } else {
                            *(u8 *)((u8 *)obj + 8) = 0;
                            *(f32 *)((u8 *)obj + 0xC) = lbl_80561980;
                            *arg2 = 0;
                        }
                        result = 1;
                    }
                } else {
                    result = 0;
                }
            } else {
                result = 0;
            }
        }
        if (result == 0 &&
            *(s32 *)((u8 *)(void *)fn_8017960C(*(s32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 4)) + 0x10) == 0x50434152) {
            data = (void *)fn_8017960C(*(s32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 4));
            if (((Pcr *)*(void **)((u8 *)data + 0x270C))->m3() & 0x10) {
                if (*(u8 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 8) == 0) {
                    *(u8 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 8) = 1;
                    *(f32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 0xC) = lbl_80561980;
                }
            } else {
                if (!(((Pcr *)*(void **)((u8 *)data + 0x270C))->m3() & 0x10)) {
                    if (*(u8 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 8) != 0) {
                        *(u8 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 8) = 0;
                        *(f32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 0xC) = lbl_80561980;
                    }
                }
            }
        }
    }
    return result;
}
extern char lbl_80330BC8[];
extern char lbl_80330BD8[];
extern void *fn_80145E70(const char *);
extern s32 fn_801284F8(s32, const char *);
extern void *fn_802ADDD8(s32);
extern void fn_8016EA9C(void *);
extern void fn_8016E984(void *);
extern s32 fn_80179650(void);

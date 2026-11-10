#include "decomp.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802E317C(void *, ...);
extern char lbl_802FC638[];
extern char lbl_802FC69C[];
extern char lbl_80352AD0[];
extern char lbl_802FC610[];
extern char lbl_802FCB50[];
extern int lbl_8055D51C;
extern int lbl_8055D50C;
extern int lbl_8055D510;
extern int lbl_8055D514;
extern int lbl_80558AD8;
extern int lbl_8055D508;
extern void *lbl_8055D504;
extern int lbl_8055D518;
extern char lbl_8055D500;
extern char lbl_803518C0[];
extern void fn_80013A34(void);
extern void fn_80013618(int);
extern void fn_8013C804(void);
extern void fn_8013C8B8(void);
extern int fn_8019B3C(void);
extern int fn_8019B54(void);
extern void fn_80013724(void);
extern int fn_80007F90(int);
extern int fn_801345D8(void *, int, const char *, ...);
void fn_80012984();
typedef void *(*Vfn_8001335C)();
struct Obj_8001335C;
typedef struct VT_8001335C {
    void *pad0, *pad1;
    char *(*name)(struct Obj_8001335C *);
    struct Obj_8001335C *(*child)(struct Obj_8001335C *, int);
    void *pad4;
    char *(*get)(struct Obj_8001335C *, char *);
    void (*set)(struct Obj_8001335C *, char *, int);
} VT_8001335C;
typedef struct Obj_8001335C { VT_8001335C *vt; } Obj_8001335C;
#define VCALL_8001335C(o, slot) ((Vfn_8001335C)((*(void ***)(o))[slot]))
#pragma scheduling invalid_target
void *fn_800126CC(int arg0) DECOMP_DONT_INLINE {
    volatile int *table = (volatile int *)lbl_802FC638;
    int i = 0;
    if (arg0 != table[0]) {
        i = 1;
        if (arg0 != table[5]) {
            i = 2;
            if (arg0 != table[10]) {
                i = 3;
                if (arg0 != table[15]) {
                    i = 4;
                    if (arg0 != table[20])
                        i = 5;
                }
            }
        }
    }
    if (i >= 5)
        fn_802E317C(lbl_802FC69C, arg0);
    return lbl_802FC638 + i * 0x14;
}
#pragma scheduling on
void fn_80012778(void) { fn_80012984(0x12F); }

void fn_80012780(void) { fn_80012984(0x130); }

void fn_80012788(void) { fn_80012984(0x132); }

void fn_80012790(void) {
    fn_80012984();
}

extern int lbl_80558AD8;
void* fn_80012810(void) {
    return (void*)lbl_80558AD8;
}

extern void *lbl_8055D504;
void* fn_80012818(void) {
    return lbl_8055D504;
}

extern int lbl_8055D508;
void* fn_80012854(void) {
    return (void*)lbl_8055D508;
}

void *fn_8001285C(int arg0) DECOMP_DONT_INLINE {
    return &lbl_80352AD0[arg0 * 0x28];
}

extern char lbl_80352AD0[];
extern char lbl_802FC700[];
extern void fn_80131818(void *);
extern char lbl_8035183C[];
extern char lbl_8055D500;
extern int lbl_8055D514;
#pragma scheduling invalid_target
void fn_80012794(void) {
    void **p;
    void **base = (void **)&lbl_8035183C[0];
    int i = 0;
    p = base;
    lbl_80558AD8 = 0x134;
    while (i < *(int *)((char *)base + 0x80)) {
        fn_80131818(*p);
        p++;
        i++;
    }
    *(int *)((char *)base + 0x80) = 0;
    lbl_8055D500 = 0;
    lbl_8055D514 = 0;
}
#pragma scheduling on
extern char lbl_803518C0[];
extern char lbl_803551E0[];
char *fn_80012820(int arg0) DECOMP_DONT_INLINE {
    if (arg0 >= 0) {
        return &lbl_803518C0[arg0 * 0x84];
    }
    return &lbl_803551E0[(-1 - arg0) * 0x88];
}
#pragma scheduling invalid_target
void *fn_80012870(int arg0, int arg1) {
    unsigned char *p = (unsigned char *)lbl_80352AD0;
    int j = 0;
    unsigned int i = 0;
    int count = lbl_8055D508;
    for (; count > 0; count--, p += 0x28, i++) {
        if (arg0 == *(int *)(p + 4) && p[0x24] != 0) {
            if (j == arg1)
                return &lbl_80352AD0[i * 0x28];
            j++;
        }
    }
    fn_802E317C(lbl_802FC700, arg0, arg1);
    return 0;
}
#pragma scheduling on
extern void *fn_8001285C();
extern char *fn_80012820(int);
extern const char *fn_80007FF0(int);
extern int fn_80012938(float);
extern volatile float lbl_80560358;
void fn_80012910(void) {
    fn_80007FF0(*(int *)((char *)fn_8001285C() + 8));
}

#pragma dont_inline on
int fn_80012938(float f) {
    if (f > lbl_80560358) {
        return 2;
    }
    return 1;
}
#pragma dont_inline reset

#pragma dont_inline fn_80012938
void fn_80012954(void) {
    char *p = fn_80012820(*(int *)((char *)fn_8001285C() + 4));
    fn_80012938(*(float *)(p + 0x78));
}

#pragma use_lmw_stmw off
/* Initialize/load resource data for the given id, append optional extra paths,
 * snapshot counts, format per-entry strings when requested, and finalize setup. */
void fn_80012984(int arg0) {
    char pathBuf[0x80];
    register char *strBase = lbl_802FC610;
    register char *entry;
    register int i;
    void *resourceInfo;
    int extraPath;

    fn_8013C804();
    resourceInfo = fn_800126CC(arg0);
    lbl_8055D514 = 0;
    lbl_80558AD8 = *(int *)resourceInfo;
    lbl_8055D508 = 0;
    lbl_8055D51C = 0;
    lbl_8055D504 = 0;
    lbl_8055D518 = 0;

    extraPath = *(int *)((char *)resourceInfo + 8);
    if (extraPath != 0) {
        fn_80013618(extraPath);
    }
    if (fn_8019B3C() != 0) {
        fn_80013618((int)(strBase + 0x128));
    }
    if (fn_8019B54() != 0) {
        fn_80013618((int)(strBase + 0x138));
    }
    fn_80013724();
    lbl_8055D50C = (int)lbl_8055D504;
    lbl_8055D510 = lbl_8055D508;

    if (*(unsigned char *)((char *)resourceInfo + 0x11) != 0) {
        entry = lbl_80352AD0;
        for (i = 0; i < lbl_8055D510; entry += 0x28, i++) {
            fn_801345D8(pathBuf, 0x80, strBase + 0x144,
                        *(int *)((char *)resourceInfo + 4),
                        lbl_803518C0 + *(int *)(entry + 4) * 0x84 + 8,
                        fn_80007F90(*(int *)(entry + 8)));
        }
    }
    fn_80013A34();
    fn_8013C8B8();
    lbl_8055D500 = 1;
}

#pragma cplusplus on
#pragma dont_inline on
extern "C" int fn_80019B3C(void);
extern int lbl_80558AFC;
extern "C" char *strstr(const char *, const char *);
extern "C" int fn_80012AB4(void *arg0) {
    struct Dummy {
        virtual int f0();
        virtual int f1();
        virtual int f2();
        virtual int f3();
        virtual const char *f4(const char *, int);
    };
    void *entry;
    char *needle;
    int result;
    const char *vr;
    if (fn_80019B3C() != 0)
        return 1;
    entry = fn_800126CC(lbl_80558AD8);
    needle = *(char **)((char *)entry + 4);
    result = *(unsigned char *)((char *)entry + 0x10);
    vr = ((Dummy *)arg0)->f4((const char *)&lbl_80558AFC, 0);
    if (vr != 0) {
        result = 0;
        if (strstr(vr, needle) != 0)
            result = 1;
    }
    return result;
}
#pragma dont_inline reset
#pragma cplusplus reset

extern void fn_8022D0D8(void *arg0, int arg1);
extern void fn_8022D0E8(void *arg0, int arg1, int arg2);
extern int fn_80137C54(int arg0);
extern int fn_800080E8(void *arg0);
extern int fn_8013C9A4(void);
extern int fn_8013C8E8(int arg0);
extern void fn_800135AC(char *arg0, void *arg1, char *arg2);
extern int fn_80008050(void);
extern float lbl_8056035C;
extern char lbl_80558B04[];
extern char lbl_80558B0C[];
extern char lbl_80558B14[];
extern char lbl_80558B1C[];
extern char lbl_80558B24[];
extern char lbl_80558B30[];
extern char lbl_80558B38[];
extern char lbl_80558B40[];
extern char lbl_80558B48[];
extern char lbl_80558B50[];
extern char lbl_80558B58[];
extern char lbl_80558B60[];
extern int sprintf(char *, char *, ...);
extern char lbl_80558B04[4];
extern char lbl_80558B0C[4];
extern char lbl_80558B14[4];
extern char lbl_80558B24[4];
extern char lbl_80558B30[4];
extern char lbl_80558B38[4];
extern char lbl_80558B40[4];
extern char lbl_80558B48[4];
extern char lbl_80558B50[4];
extern char lbl_80558B58[4];
extern char lbl_80558B60[4];
void fn_80012B50(void *arg0, int arg1, void *arg2, void *arg3) {
    register char *base = lbl_802FC610;
    void *a3 = arg3;
    int a1 = arg1;
    void *a2 = arg2;
    char *obj = (char *)arg0;
    char spD0[0x100];
    char buf10[0xC0];
    int spC;
    int sp8;
    int i;
    int sel;
    char *s;
    char *d;
    int n;
    void *list;
    int idx;
    int childVal;
    char *entry;
    int temp;
    int cnt;
    char c;
    char *key04;
    memset(obj, 0, 0x84);
    *(int *)obj = a1;
    fn_8022D0D8(spD0, 0x100);
    i = 0;
    do {
        fn_8022D0E8(spD0, 0x100, fn_80137C54(i) + 8);
        i++;
    } while (i < 4);
    key04 = lbl_80558B04;
    if (((int (*)(void *, char *))*(void **)((char *)*(void **)a2 + 0xC))(a2, key04) != 0) {
        sel = ((int (*)(void *, char *, char *))*(void **)((char *)*(void **)a2 + 0x54))(a2, key04, spD0);
    } else {
        sel = 0;
    }
    *(int *)(obj + 4) = sel;
    s = ((char *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x14))(a2, lbl_80558B0C);
    d = obj + 8;
    n = 0x20;
    while (--n > 0) {
        c = *s++;
        *d++ = c;
        if (c == 0) {
            goto copy_done;
        }
    }
    *(d - 1) = 0;
copy_done:
    if (fn_800080E8(obj + 8) == -1) {
        fn_802E317C(base + 0x168, a3, obj + 0x28);
    }
    *(int *)(obj + 0x6C) = 1;
    *(int *)(obj + 0x68) = 1;
    if (((int (*)(void *, char *))*(void **)((char *)*(void **)a2 + 0xC))(a2, lbl_80558B14) != 0) {
        s = ((char *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x14))(a2, lbl_80558B14);
    } else {
        s = ((char *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x14))(a2, lbl_80558B1C);
    }
    strncpy(obj + 0x28, s, 0x40);
    obj[0x67] = 0;
    if (((int (*)(void *, char *))*(void **)((char *)*(void **)a2 + 0xC))(a2, base + 0x18C) != 0) {
        ((char *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x14))(a2, base + 0x18C);
        temp = fn_8013C9A4();
        *(int *)(obj + 0x74) = temp;
        if (temp == 6) {
            fn_802E317C(base + 0x198, a3, obj + 0x28);
        }
    } else {
        *(int *)(obj + 0x74) = 1;
    }
    *(float *)(obj + 0x78) = lbl_8056035C;
    list = ((void *(*)(void *, char *))*(void **)((char *)*(void **)a2 + 0x5C))(a2, base + 0x1C8);
    *(void **)(obj + 0x7C) = list;
    if (list != 0) {
        idx = 0;
        do {
            if (fn_8013C8E8(spC) == 6) {
                fn_802E317C(base + 0x1D8, obj + 0x28, spC);
            }
            idx++;
        } while (((int (*)(void *, int, int *, int *))*(void **)((char *)*(void **)list + 0x10))(list, idx, &spC, &sp8) != 0);
        if (idx > 7) {
            fn_802E317C(base + 0x208, obj + 0x28, idx, 7);
        }
    }
    *(void **)(obj + 0x80) = a2;
    fn_800135AC(base + 0x244, a2, obj + 0x28);
    fn_800135AC(lbl_80558B24, a2, obj + 0x28);
    fn_800135AC(lbl_80558B30, a2, obj + 0x28);
    fn_800135AC(base + 0x250, a2, obj + 0x28);
    fn_800135AC(base + 0x25C, a2, obj + 0x28);
    fn_800135AC(lbl_80558B38, a2, obj + 0x28);
    if (((int (*)(void *, char *))*(void **)((char *)*(void **)a2 + 0xC))(a2, base + 0x268) != 0 || ((int (*)(void *, char *))*(void **)((char *)*(void **)a2 + 0xC))(a2, base + 0x278) != 0) {
        fn_802E317C(base + 0x284, obj + 0x28);
    }
    cnt = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)a2 + 0x20))(a2, base + 0x2C8, 0);
    idx = 0;
    {
        void *ch = ((void *(*)(void *, int))*(void **)((char *)*(void **)a2 + 0x60))(a2, idx);
        while (ch != 0) {
            ((void (*)(void *))*(void **)((char *)*(void **)ch + 8))(ch);
            if (stricmp(((char *(*)(void *, char *))*(void **)((char *)*(void **)ch + 0xC))(ch, lbl_80558B40), 0) == 0) {
                if (lbl_8055D508 >= 0xFA) {
                    fn_802E317C(base + 0x2D8);
                }
                if (*(int *)(obj + 0x70) >= 0x40) {
                    fn_802E317C(base + 0x31C, obj + 0x28);
                }
                entry = &lbl_80352AD0[lbl_8055D508 * 0x28];
                *(int *)entry = lbl_8055D508;
                *(int *)(entry + 4) = *(int *)obj;
                entry[0x24] = 1;
                if (((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0xC))(ch, base + 0x244, lbl_8055D508) != 0) {
                    ((char *(*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x14))(ch, base + 0x244, lbl_8055D508);
                    temp = fn_80008050();
                    *(int *)(entry + 8) = temp;
                    if (temp == 0) {
                        fn_802E317C(base + 0x360, obj + 0x28, lbl_8055D508 + 1);
                    }
                } else {
                    fn_802E317C(base + 0x388, obj + 0x28, lbl_8055D508 + 1);
                }
                sprintf(buf10, lbl_80558B48, obj + 0x28, fn_80007FF0(*(int *)(entry + 8)));
                *(int *)(entry + 0xC) = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, lbl_80558B24, 0);
                childVal = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, base + 0x25C, 8);
                *(int *)(entry + 0x10) = childVal;
                if (childVal > 8) {
                    fn_802E317C(base + 0x3B0, buf10, childVal, 8);
                }
                temp = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, base + 0x2C8, -1);
                *(int *)(entry + 0x14) = temp;
                if (temp == -1) {
                    int t2 = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, base + 0x250, 0);
                    if (t2 == 0) {
                        *(int *)(entry + 0x14) = 0;
                    } else {
                        *(int *)(entry + 0x14) = 1 << (t2 - 1);
                    }
                }
                *(int *)(entry + 0x14) |= cnt;
                *(int *)(entry + 0x14) &= ~((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, base + 0x3D0, 0);
                *(int *)(entry + 0x18) = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, lbl_80558B50, 1);
                *(int *)(entry + 0x1C) = ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0x20))(ch, lbl_80558B38, 0x3E8);
                *(void **)(entry + 0x20) = ch;
                fn_800135AC(lbl_80558B04, ch, buf10);
                fn_800135AC(lbl_80558B58, ch, buf10);
                fn_800135AC(lbl_80558B60, ch, buf10);
                if (((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0xC))(ch, base + 0x268, 0) != 0 || ((int (*)(void *, char *, int))*(void **)((char *)*(void **)ch + 0xC))(ch, base + 0x278, 0) != 0) {
                    fn_802E317C(base + 0x3E8, buf10);
                }
                if ((*(int *)(entry + 8) & 0x400) != 0 && childVal * 2 > 8) {
                    fn_802E317C(base + 0x428, buf10, childVal, 8);
                }
                lbl_8055D508++;
                *(int *)(obj + 0x70) += 1;
            }
            idx++;
            ch = ((void *(*)(void *, int))*(void **)((char *)*(void **)a2 + 0x60))(a2, idx);
        }
    }
    if (*(int *)(obj + 0x70) <= 0) {
        fn_802E317C(base + 0x468, obj + 0x28);
    }
}

#pragma cplusplus on
extern "C" int fn_800132E4(void *object, int argument, int fallback) {
    struct Dummy {
        virtual int f0();
        virtual int f1();
        virtual int f2();
        virtual int f3();
        virtual int f4();
        virtual int f5(int);
    };
    int result;
    if (((Dummy *)object)->f1()) {
        result = ((Dummy *)object)->f5(argument);
    } else {
        result = fallback;
    }
    return result;
}
#pragma cplusplus reset
extern char lbl_80558B1C[4];
extern char lbl_80558B68[4];
extern char lbl_80558B70[4];
extern char lbl_80558B78[4];
extern int stricmp();
extern int fn_8012C33C();
extern int fn_80012AB4();
extern void fn_80012B50();
void fn_8001335C(int a0, int arg1) {
    Obj_8001335C *arg0 = (Obj_8001335C *)a0;
    Obj_8001335C *obj;
    int i;
    if (arg0 != 0) {
        for (i = 0; (obj = arg0->vt->child(arg0, i)) != 0; i++) {
            if (stricmp(obj->vt->name(obj), lbl_80558B68) == 0) {
                if (fn_8012C33C(obj->vt->get(obj, lbl_80558B1C)) == 0)
                    fn_802E317C(lbl_802FC610 + 0x488, obj->vt->get(obj, lbl_80558B1C));
                obj->vt->set(obj, lbl_80558B1C, 0);
                ((void (*)())fn_80013618)();
            } else if (stricmp(obj->vt->name(obj), lbl_80558B70) == 0) {
                if ((int)lbl_8055D504 >= 0x23)
                    fn_802E317C(lbl_802FC610 + 0x4B4, (int)lbl_8055D504 - 1);
                if (fn_80012AB4(obj) != 0) {
                    fn_80012B50(lbl_803518C0 + (int)lbl_8055D504 * 0x84, (int)lbl_8055D504, obj, arg1);
                    lbl_8055D504 = (void *)((int)lbl_8055D504 + 1);
                }
            } else if (stricmp(obj->vt->name(obj), lbl_80558B78) == 0) {
                if (lbl_8055D518 >= 0x23)
                    fn_802E317C(lbl_802FC610 + 0x4E4, lbl_8055D518 - 1);
                if (fn_80012AB4(obj) != 0) {
                    fn_80012B50(lbl_803551E0 + lbl_8055D518 * 0x88, -1 - lbl_8055D518, obj, arg1);
                    *(int *)(lbl_803551E0 + lbl_8055D518 * 0x88 + 0x84) = 0;
                    lbl_8055D518 += 1;
                }
            } else if (stricmp(obj->vt->name(obj), lbl_802FC610 + 0x524) == 0 && lbl_8055D514 == 0) {
                lbl_8055D514 = (int)obj;
            }
        }
    }
}

#pragma cplusplus on
extern "C" void fn_800135AC(char *arg0, void *arg1, char *arg2) {
    struct Dummy {
        virtual int f0();
        virtual int f1(char *);
    };
    if (((Dummy *)arg1)->f1(arg0) != 0)
        fn_802E317C(lbl_802FCB50, arg2, arg0);
}
#pragma cplusplus reset
extern char lbl_802FCB74[];
extern int fn_8012C33C(void);
extern int fn_80131808(int);
extern void fn_8001335C(int, int);
#pragma scheduling invalid_target
void fn_80013618(int arg0) {
    unsigned int count;
    int result;
    if (arg0 == 0)
        return;
    if (fn_8012C33C() == 0)
        return;
    result = fn_80131808(arg0);
    count = *(unsigned int *)(lbl_8035183C + 0x80);
    *(int *)(lbl_8035183C + count * 4) = result;
    *(unsigned int *)(lbl_8035183C + 0x80) = count + 1;
    fn_8001335C(result, arg0);
}

#pragma scheduling on
#pragma cplusplus on
extern "C" int fn_80013680(void *arg0, void *arg1) {
    struct Dummy {
        virtual int f0();
        virtual int f1();
        virtual int f2();
        virtual int f3();
        virtual int f4();
        virtual int f5();
        virtual int f6(char *, int);
    };
    return ((Dummy *)*(void **)((char *)arg0 + 0x80))->f6(lbl_802FCB74, 0x63)
        - ((Dummy *)*(void **)((char *)arg1 + 0x80))->f6(lbl_802FCB74, 0x63);
}
#pragma cplusplus reset
#pragma scheduling invalid_target
int fn_800136FC(void *arg0, void *arg1) {
    int b = ((int *)arg1)[0x1A];
    int a = ((int *)arg0)[0x1A];
    if (a == b) {
        return ((int *)arg0)[0x1B] - ((int *)arg1)[0x1B];
    }
    return a - b;
}

extern int lbl_8055D518;
#pragma scheduling invalid_target
void fn_80013A34(void) {
    int count = lbl_8055D518;
    char *p = lbl_803551E0;
    int blocks, i;
    if (count > 0) {
        blocks = (unsigned int)count >> 3;
        for (i = 0; i < blocks; i++) {
            *(int *)(p + 0x84) += *(int *)(p + 0x70); *(int *)(p + 0x70) = 0;
            *(int *)(p + 0x10C) += *(int *)(p + 0xF8); *(int *)(p + 0xF8) = 0;
            *(int *)(p + 0x194) += *(int *)(p + 0x180); *(int *)(p + 0x180) = 0;
            *(int *)(p + 0x21C) += *(int *)(p + 0x208); *(int *)(p + 0x208) = 0;
            *(int *)(p + 0x2A4) += *(int *)(p + 0x290); *(int *)(p + 0x290) = 0;
            *(int *)(p + 0x32C) += *(int *)(p + 0x318); *(int *)(p + 0x318) = 0;
            *(int *)(p + 0x3B4) += *(int *)(p + 0x3A0); *(int *)(p + 0x3A0) = 0;
            *(int *)(p + 0x43C) += *(int *)(p + 0x428); *(int *)(p + 0x428) = 0;
            p += 0x440;
        }
        for (i = 0; i < (count & 7); i++) {
            *(int *)(p + 0x84) += *(int *)(p + 0x70);
            *(int *)(p + 0x70) = 0;
            p += 0x88;
        }
    }
    {
        char *entry = lbl_80352AD0;
        int x;
        for (x = 0; x < lbl_8055D508; x++, entry += 0x28) {
            char *q = lbl_803551E0;
            int y;
            for (y = 0; y < count; y++, q += 0x88) {
                if (*(int *)(entry + 4) == *(int *)q)
                    entry[0x24] = 0;
            }
        }
    }
}
#pragma scheduling reset
extern char lbl_802FCB74[];
extern int fn_8012C33C(void);
extern int fn_80131808(int);
extern void fn_8001335C(int, int);

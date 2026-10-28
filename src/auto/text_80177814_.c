#include <types.h>
extern void *lbl_8055E430;
extern char lbl_8055E45D;
extern char lbl_8055E45F;
extern int lbl_8055E450;
extern int lbl_8055E8F8;
#include <revolution/MTX/vec.h>
extern int lbl_8055E43C;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern unsigned char lbl_8055E45E;
extern int lbl_80430870[];
extern int lbl_80430590[];
extern int lbl_80430830[];

extern long fn_80178C1C(long *);
extern float lbl_80561B60;
void fn_80179EE8(void*, unsigned int);
void fn_80128668(void*);
extern unsigned char lbl_8055E46C;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055A304;
void fn_801DCEC8(int arg0, float arg1);
void fn_801DCEDC(int arg0, float arg1);
extern float lbl_804305D4[];
extern float lbl_80430700[];
extern float lbl_80561B48;
void fn_802E8518(int arg0);
extern int lbl_8055E3C0;
extern unsigned char lbl_8055E3BD;
int fn_801CF064(void);
int fn_8018FD38(void);
extern void *lbl_804340C0[];
extern void **lbl_8055E434;
extern int lbl_8055E438;
extern int lbl_8055E468;
extern int lbl_8055E448;
extern unsigned char lbl_8055E44C;
extern long lbl_80331938;
extern long lbl_8033192C;
extern void fn_801AFD20(void *);
extern void fn_8017ACCC(void);
extern void fn_8018A180(void);
int fn_802E2C20(void);
extern int lbl_8055E464;
void fn_80177814(int *arg0) {
    int t;
    t = fn_802E2C20() + lbl_8055E464;
    *arg0 = t % 30000;
    lbl_8055E464 += 0x9947;
    t = fn_802E2C20() + lbl_8055E464;
    arg0[1] = t % 30000;
    lbl_8055E464 += 0x2F1CD;
}

void fn_801778C0(void) {
    void **var_r31 = &lbl_804340C0[0];
    void **var_r28;
    int var_r30 = 0;
    int var_r29 = 0;

    lbl_8055E468 = 0;
    for (; var_r29 < lbl_8055E438; var_r29++, var_r30 += 4) {
        var_r28 = *(void **)(lbl_8055E434 + var_r30);
        if (((int (*)(void **))(*(void ***)*var_r28 + 0x44))(var_r28) != 0 &&
            ((int (*)(void **))(*(void ***)*var_r28 + 0x40))(var_r28) != 0) {
            var_r31[lbl_8055E468] = var_r28;
            lbl_8055E468 += 1;
        }
    }
}

long fn_80177980(void) {
    return 0;
}

long fn_80177988(void) {
    return 1;
}

void fn_80177990(void) {
    double temp_f31 = lbl_80561B48;
    float *var_r31 = &lbl_80430700[0];
    float *var_r30 = &lbl_804305D4[0];
    int var_r29;

    for (var_r29 = 0; var_r29 < 0x4b; var_r29++) {
        *var_r31 = (float)temp_f31;
        *var_r30 = (float)temp_f31;
        fn_801DCEC8(var_r29, (float)temp_f31);
        fn_801DCEDC(var_r29, lbl_80561B48);
        var_r31++;
        var_r30++;
    }
}

#pragma dont_inline on
void fn_80177A18(void) {
    int var_r31;

    var_r31 = 0;
    do {
        fn_802E8518(var_r31);
        var_r31 += 1;
    } while (var_r31 < 4);
}
#pragma dont_inline off

void fn_80177A54(void) {
    if (lbl_8055E3C0 == 2 && fn_801CF064() != 0 && fn_8018FD38() != 0) {
        lbl_8055E3C0 = 0;
    }
    switch (lbl_8055E3C0) {
    case 1:
        if (lbl_8055E3BD == 0) {
            fn_80177A18();
        }
        lbl_8055E3BD = 1;
        break;
    case 2:
        lbl_8055E3BD = 0;
        break;
    default:
        break;
    }
    lbl_8055E3C0 = 0;
}

void fn_80177CEC(void) {
    int index = lbl_8055E43C;
    void *object;
    Vec right;
    Vec up;
    Vec forward;
    float a, b, c, d, e, f;
    if (index >= lbl_8055E438) { index = 0; lbl_8055E43C = 0; }
    object = lbl_8055E434[index];
    if (object != 0 && ((int (*)(void *))(*(void ***)object)[0x40 / 4])(object) != 0) {
        a = *(float *)((char *)object + 0x44);
        b = *(float *)((char *)object + 0x40);
        c = *(float *)((char *)object + 0x3C);
        forward.x = c; forward.y = b; forward.z = a;
        d = *(float *)((char *)object + 0x5C);
        e = *(float *)((char *)object + 0x58);
        f = *(float *)((char *)object + 0x54);
        right.x = f; right.y = e; right.z = d;
        PSVECCrossProduct(&right, &forward, &up);
        PSVECNormalize(&forward, &forward);
        PSVECNormalize(&up, &up);
        PSVECCrossProduct(&forward, &up, &right);
        *(float *)((char *)object + 0x3C) = forward.x;
        *(float *)((char *)object + 0x40) = forward.y;
        *(float *)((char *)object + 0x44) = forward.z;
        *(float *)((char *)object + 0x48) = up.x;
        *(float *)((char *)object + 0x4C) = up.y;
        *(float *)((char *)object + 0x50) = up.z;
        *(float *)((char *)object + 0x54) = right.x;
        *(float *)((char *)object + 0x58) = right.y;
        *(float *)((char *)object + 0x5C) = right.z;
    }
    lbl_8055E43C++;
}

void fn_80177EE4(void) {
    int i;
    if (lbl_8055E44C != 0) {
        for (i = 0; i < 8; i++) {
            if (fn_8017960C(i) != 0) {
                fn_8018A180();
            }
        }
        lbl_8055E44C = 0;
    }
}

extern char jumptable_803318F8[];
#pragma dont_inline off
long fn_801781B8(void) { return 0; }

long fn_801781C0(unsigned int arg0) {
    register char *table = jumptable_803318F8;
    register long r;
    if (arg0 - 0x13 <= 0xC) {
        r = *(long *)(table + (arg0 - 0x13) * 4);
        return r;
    }
    return 0;
}
#pragma dont_inline on
#pragma scheduling invalid_target
unsigned char *fn_801781F4(long arg0) {
    volatile unsigned char *p = &lbl_8055E46C;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    *(volatile long *)p = arg0;
    a = p[0];
    c = p[3];
    b = p[1];
    d = p[2];
    p[0] = c;
    p[3] = a;
    p[1] = d;
    p[2] = b;
    return (unsigned char *)p;
}
#pragma dont_inline off

void fn_80178224(void) {
    if (fn_801284F8(0x2780, &lbl_8055A304) != 0)
        fn_801A6484();
}

#pragma scheduling off
void fn_80178258(void) {
    if (fn_801284F8(0xD0, &lbl_8033192C) != 0) {
        fn_8017ACCC();
    }
}
void fn_80178290(void) {
    if (fn_801284F8(0x1FC, &lbl_80331938) != 0) {
        fn_801AFD20((void *)&lbl_80331938);
    }
}

extern char lbl_80331944[];
extern char lbl_80338400[];
void *fn_8017B0B0(void *);
#pragma scheduling invalid_target
void *fn_801782C8(void) {
    long object = fn_801284F8(0x29C, (void *)&lbl_80331944[0]);
    if (object != 0) {
        fn_8017B0B0((void *)object);
        *(long *)object = (long)&lbl_80338400[0];
    }
    return (void *)object;
}
#pragma scheduling on

#pragma scheduling on
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017831C(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80179EE8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

extern char lbl_80331950[];
#pragma dont_inline on
char *fn_80178374(long arg0) {
    char *var_r4 = lbl_80331950;
    int temp_r0;

    while ((temp_r0 = *(int *)var_r4) != 0) {
        if ((unsigned long)temp_r0 == (unsigned long)arg0) {
            return var_r4;
        }
        var_r4 += 0xC;
    }
    return NULL;
}

#pragma cplusplus on
extern "C" void *lbl_8055E454;
extern "C" void fn_80179D8C(void *, int);
extern "C" long fn_802E317C(const char *, long, ...);
#pragma cplusplus on
extern "C" void **fn_801783A8(int *arg0, int arg1) {
    struct Provider {
        int id;
        int reserved;
        void **(*create)(void);
    };
    struct Handler {
        virtual void run(int *);
    };
    struct Provider *provider;
    char *table;
    void **object;
    object = 0;
    table = jumptable_803318F8;
    lbl_8055E454 = arg0;
    provider = (struct Provider *)fn_80178374(*arg0);
    if (provider != 0) {
        if (provider->create != 0) {
            object = provider->create();
            if (object != 0) {
                fn_80179D8C(object, arg1);
                ((struct Handler *)object)->run(arg0);
            } else {
                fn_802E317C(table + 0xF4, (long)fn_801781F4(*arg0));
            }
        } else {
            fn_802E317C(table + 0x110, (long)fn_801781F4(*arg0));
        }
    } else {
        fn_802E317C(table + 0x134, (long)fn_801781F4(*arg0));
    }
    lbl_8055E454 = 0;
    return object;
}
#pragma cplusplus off

#pragma dont_inline off

void fn_801784AC(void) {
    fn_801E2640(&lbl_804340C0[0], &lbl_8055E468);
}

extern float lbl_80561B64;
#pragma scheduling invalid_target
s32 fn_801784DC(Vec *arg0, f32 *arg1, Vec *arg2, s32 *arg3, s32 arg4) {
    Vec start;
    Vec hit;
    Vec normal;
    s32 value;
    s32 other;
    start.y = arg0->y - lbl_80561B64;
    start.z = arg0->z;
    start.x = arg0->x;
    if (((s32 (*)(Vec *, Vec *, Vec *, Vec *, s32 *, s32 *, s32))fn_801784AC)(arg0, &start, &hit, &normal, &value, &other, arg4)) {
        *arg1 = hit.y;
        if (arg2 != 0) {
            arg2->x = normal.x;
            arg2->y = normal.y;
            arg2->z = normal.z;
        }
        if (arg3 != 0) {
            *arg3 = value;
        }
        return 1;
    }
    return 0;
}
#pragma scheduling on
void fn_801785A4(void **arg0) {
    int index = lbl_8055E438;
    lbl_8055E434[index] = arg0;
    lbl_8055E438 = index + 1;
    if (((int (*)(void *))(*(int **)*(void **)arg0 + 0x40))(*arg0) != 0) {
        fn_801B5318(arg0);
    }
}

int fn_80178604(void *arg0) {
    int result = 0;
    unsigned int magic = *(unsigned int *)arg0;
    if (magic == 0x43415220 || magic == 0x50434152 ||
        magic == 0x41434152 || magic == 0x4e434152) {
        result = 1;
    }
    if (result != 0) return 0;
    if (magic == 0x4f425354 && *(int *)((char *)arg0 + 0x50) == 0x14) return 2;
    return 1;
}

long fn_8017873C(long *arg0, long arg1, long arg2, long arg3, long arg4) {
    if ((unsigned long)(arg3 + *arg0 + 1) < 0x1000) {
        *(unsigned char *)((char *)arg0 + *arg0 + 4) = arg1;
        memcpy((char *)arg0 + *arg0 + 5, (void *)arg2, arg3);
        *arg0 = arg3 + *arg0 + 1;
    }
    return 0;
}

extern void DBPrintf_80179758(const char *fmt, ...);
extern s32 lbl_8055E3C4;
extern u64 fn_802E2C9C(void);
extern s64 __div2i(s64, s64);
extern u8 lbl_804305C0[];
#pragma dont_inline on
s64 fn_80178BBC(s32 *arg0) {
    s32 r4 = lbl_8055E3C4 - arg0[0];
    s64 r31 = *(s64 *)&arg0[2] + (s64)r4 * 0x412b;
    return fn_802E2C9C() - r31;
}
s32 fn_80178C1C(s32 *arg0) {
    s64 r3 = fn_80178BBC(arg0);
    return (s32)__div2i(r3, 0x412b);
}

s32 fn_80178C4C(void *arg0) {
    DBPrintf_80179758((char *)arg0 + 4);
    return *(u16 *)arg0 + 4;
}

#pragma dont_inline off
void fn_80178C88(void) {

}

void fn_80178C8C(void) {

}

void *__AXGetStudio_80178C90(void) {
    return lbl_804305C0;
}

extern void *lbl_8055E414;
void* fn_80178C9C(void) {
    return lbl_8055E414;
}

extern void *lbl_8055E444;
void* fn_80178CA4(void) {
    return lbl_8055E444;
}

void fn_80178DBC(int arg0, float arg1) {
    lbl_804305D4[arg0] = arg1;
    fn_801DCEC8(arg0, arg1);
}

#pragma dont_inline on
void fn_80178DD0(void) {
    fn_80177990();
}

extern char jumptable_803318F8[];
extern int lbl_8055E3CC;
extern int lbl_8055E418;
extern int lbl_8055E420;
extern int lbl_8055E428;
extern int lbl_8055E440;
extern unsigned char lbl_8055E45C;
extern void __AXDSPInitCallback_801D0CF0(void);
extern void __AXDSPInitCallback_801D32D0(void);
extern void __AXFXGetLfoSinTable_801769CC(void);
extern int *fn_801769D8(void);
extern int fn_80127464(void);
extern int fn_801284E8(void *, int);
extern int fn_8012850C(int, void *);
extern void fn_80129C80(int, int, int);
extern int fn_8012F3CC(int);
extern void fn_8012F43C(void *);
extern void fn_8012F418(void *);
extern int fn_80135DC4(int, int, int);
extern int fn_80137C74(void);
extern int fn_80178678(void *, void **, int);
extern void fn_80179320(void);
extern void fn_8017D2CC(int);
extern void fn_80181FEC(void);
extern void fn_80181F30(void);
extern void fn_801A4E28(void);
extern void fn_801AD5EC(void);
extern void fn_801AE4C4(void);
extern void fn_801AFAC8(void);
extern void fn_801B06C8(void);
extern void fn_801B2024(void);
extern void fn_801B2320(void);
extern void fn_801B3448(void);
extern void fn_801B5274(void);
extern void fn_801B52CC(void);
extern void fn_801B5364(int, void *);
extern void fn_801B5FA0(void);
extern void fn_801B8318(void);
extern void fn_801B8B84(void);
extern void fn_801C1B9C(void);
extern void fn_801C4AD0(void);
extern void fn_801C4B10(void);
extern void fn_801CB2D8(void);
extern void fn_801CEC80(void);
extern void fn_801CEFAC(void);
extern void fn_801D0E0C(void);
extern void fn_801D21C0(void);
extern void fn_801D4734(void);
extern void fn_801D47F4(void);
extern void fn_801D9284(void);
extern void fn_801DA6EC(void);
extern void fn_801DE0A4(void);
extern void fn_801DEC18(void);
extern void fn_801DF6FC(void);
extern void fn_801E0710(void);
extern void fn_801E1D38(void *, int);
extern void fn_801E2188(void);
extern void fn_801E21BC(void);
extern void fn_801FA978(void);
extern void fn_8020C41C(void);
extern void fn_80267420(void);
extern void fn_8026B644(void);
#pragma push
#pragma use_lmw_stmw off
void fn_80178DD4(int arg0) {
    register char *table = jumptable_803318F8;
    register char *base = (char *)lbl_80430590;
    register int var_r28;
    register int var_r27;
    register int var_r26;
    register int var_r31;
    register int version;
    int value;
    void *object;

    __AXDSPInitCallback_801D0CF0();
    lbl_8055E8F8 = *fn_801769D8();
    fn_80181FEC(); fn_801DF6FC(); fn_801DA6EC(); fn_801D0E0C();
    fn_80127464(); fn_801CEFAC();
    fn_80177814(&lbl_8055E418); fn_80177814(&lbl_8055E420); fn_80177814(&lbl_8055E428);
    value = fn_801284F8(0x68, table + 0x220);
    if (value != 0) value = fn_80135DC4(value, 0, 0);
    lbl_8055E414 = (void *)value;
    memset(base + 0x32F0, 0, 0x840);
    fn_80129C80(4, lbl_8055E418, *(int *)((char *)&lbl_8055E418 + 4));
    fn_80129C80(3, lbl_8055E420, *(int *)((char *)&lbl_8055E420 + 4));
    fn_80129C80(5, lbl_8055E428, *(int *)((char *)&lbl_8055E428 + 4));

    var_r28 = (int)base;
    var_r27 = (int)(base + 0x10);
    for (var_r26 = 0; var_r26 < 4; ++var_r26, var_r28 += 4, var_r27 += 8) {
        *(int *)var_r28 = -1;
        memset((void *)var_r27, 0, 8);
    }

    lbl_8055E430 = (void *)fn_80137C74();
    var_r31 = 0;
    lbl_8055E43C = var_r31;
    fn_80127464(); fn_801B5274(); fn_801B5FA0(); fn_801B3448();
    fn_801A4E28(); fn_801AFAC8(); fn_801B06C8(); fn_801B8B84();
    fn_801CEC80(); fn_80181F30(); fn_801DE0A4();
    __AXFXGetLfoSinTable_801769CC(); fn_801B2024(); fn_80127464();
    fn_801C4AD0(); fn_8020C41C(); fn_8026B644(); fn_801C1B9C();
    fn_801D21C0(); __AXDSPInitCallback_801D32D0(); fn_801D9284();
    fn_801D4734(); fn_801CB2D8(); fn_801DEC18(); fn_80127464();
    fn_801E0710(); fn_801B8318(); fn_801FA978();
    lbl_8055E434 = (void **)fn_8012850C(0x800, table + 0x230);
    fn_801E2188();
    *(int *)(base + 0x2A0) = var_r31;
    {
        int *field = (int *)(base + 0x2A0);
        field[1] = var_r31; field[2] = var_r31; field[3] = var_r31;
        field[4] = var_r31; field[5] = var_r31; field[6] = var_r31; field[7] = var_r31;
    }
    lbl_8055E45E = var_r31; lbl_8055E45F = var_r31; lbl_8055E45C = var_r31; lbl_8055E45D = var_r31;
    lbl_8055E438 = var_r31;
    *(int *)(base + 0x22E8) = var_r31;
    *(int *)(base + 0x2E0) = var_r31;
    *(int *)(base + 0x12E4) = var_r31;

    var_r26 = fn_8012F3CC(arg0);
    fn_801AE4C4(); fn_80127464();
    var_r27 = 0;
    do {
        fn_8012F43C((void *)var_r26);
        while (fn_80178678((void *)var_r26, &object, var_r27) != 0) {
            if (object != 0) fn_801785A4((void **)object);
        }
        var_r27 += 1;
    } while (var_r27 < 3);

    fn_80127464(); fn_8012F418((void *)var_r26); fn_801B52CC();
    fn_801E21BC(); fn_80127464(); fn_8017D2CC(0x200);
    lbl_8055E448 = 0;
    value = 1;
    version = (int)lbl_8055E430;
    if (version > 1) value = version;
    lbl_8055E440 = value; lbl_8055E444 = (void *)value;
    fn_80267420();
    lbl_8055E450 = fn_801284E8(table + 0x23C, lbl_8055E3CC + 0x2EE8);
    fn_801AD5EC(); fn_80127464(); fn_801B2320(); fn_801C4B10();
    {
        int *field = (int *)(base + 0x2C0);
        field[4] = var_r31;
        *((unsigned char *)field + 0x14) = 1;
        field[7] = var_r31; field[6] = var_r31;
        fn_801E1D38(field, 1);
    }
    fn_801D47F4(); fn_801B5364(9, (void *)fn_80178C4C);
    fn_80129C80(4, lbl_8055E418, *(int *)((char *)&lbl_8055E418 + 4));
    fn_80129C80(3, lbl_8055E420, *(int *)((char *)&lbl_8055E420 + 4));
    fn_80129C80(5, lbl_8055E428, *(int *)((char *)&lbl_8055E428 + 4));
    fn_80127464(); fn_80179320();
}
#pragma pop
extern void fn_801B2C6C(void);
extern void fn_801B5354(void);
void fn_80179110(void) {
    fn_801B2C6C();
    fn_801B5354();
    lbl_8055E448 += 1;
}
extern int fn_802E4C18(int);
extern int fn_801787B4(void *);
extern void fn_80177F40(void);
extern long lbl_80430850[];
void fn_80179140(void) {
    int var_r31;
    int var_r30;
    void **var_r28;

    var_r31 = 0;
    var_r30 = 0;
    do {
        var_r28 = *(void ***)(lbl_8055E434 + var_r31);
        ((void (*)(void **))(*(void ***)*var_r28 + 0x14))(var_r28);
        var_r31 += 4;
        var_r30 += 1;
    } while (var_r30 < lbl_8055E438);
}

#pragma dont_inline off

void fn_801791A4(void) {

}

void fn_801791A8(void) {
    int offset;
    register int i;
    void *object;
    fn_80177A18();
    fn_801B537C(fn_80178C4C);
    fn_801E1D9C(); fn_8026785C(); fn_8017D334();
    fn_80128658(lbl_8055E450);
    lbl_8055E450 = 0;
    offset = 0;
    i = 0;
    while (i < lbl_8055E438) {
        object = *(void **)((char *)lbl_8055E434 + offset);
        if (object != 0) ((void (*)(void *, int))(*(void ***)object)[3])(object, 1);
        offset += 4;
        i++;
    }
    fn_80128670(lbl_8055E434);
    lbl_8055E434 = 0;
    fn_801AE50C(); fn_801E222C(); fn_801E1520(); fn_801DEE3C(); fn_801CB518();
    fn_801D483C(); fn_801D9828(); fn_801D32DC(); fn_801D2210(); fn_801C1BA0();
    fn_8026B69C(); fn_801B228C(); fn_801AFBE8(); fn_801B06CC(); fn_801C4B74();
    fn_8020C45C(); fn_801DE0E8(); fn_80181FC4(); fn_801CECB4(); fn_801B8BBC();
    fn_801A4E54(); fn_801B3B28(); fn_801B60A8(); fn_801B531C();
    if (lbl_8055E414 != 0) ((void (*)(void *, int))(*(void ***)lbl_8055E414)[2])(lbl_8055E414, 1);
    lbl_8055E414 = 0;
    fn_801CEFC4(); fn_80206550(1); fn_801D0E70();
    lbl_8055E8F8 = 0;
    fn_801D0CFC();
}

void fn_801792F4(void) {
    fn_801E21B4();
}

extern void *lbl_8055E454;
void* fn_801792F8(void) {
    return lbl_8055E454;
}

extern void *lbl_8055E458;
void* fn_80179300(void) {
    return lbl_8055E458;
}

void fn_80179308(void) {
    lbl_8055E448 += 1;
}

void* fn_80179318(void) {
    return (void *)lbl_8055E448;
}

void fn_8017952C(void) {
    long count;
    long i;

    fn_802E4C18(1);
    count = fn_801787B4(&lbl_80430850);
    i = 0;
    while (i < count) {
        fn_80177F40();
        i++;
    }
}

void fn_801CEFE8(void);
void fn_801AED5C(void);
void fn_801CB464(void);
void fn_80179588(void) {
    fn_801CEFE8();
    fn_801AED5C();
    fn_801CB464();
}

void fn_801CF01C(void);
void fn_801CB4A0(void);
void fn_801AED68(void);
void fn_801795B0(void) {
    fn_801CF01C();
    fn_801CB4A0();
    fn_801AED68();
}

void fn_801795D8(void *arg0, int arg1) {
    ((void **)lbl_80430830)[arg1] = arg0;
    if (*(int *)((char *)arg0 + 0x1F0) == 0x50) {
        lbl_80430590[(*(unsigned char *)((char *)arg0 + 0x260) & 3)] = arg1;
    }
}

int fn_8017960C(int arg0) {
    if (arg0 < 8) return lbl_80430830[arg0];
    return 0;
}

int fn_80179630(int arg0) {
    if (arg0 < 0) arg0 = 0;
    return lbl_80430590[arg0];
}

extern void *lbl_8055E430;
void* fn_80179650(void) {
    return lbl_8055E430;
}

extern char lbl_8055E45D;
char fn_801796B4(void) {
    return lbl_8055E45D;
}

void fn_801796BC(unsigned char arg0) {
    lbl_8055E45E = arg0;
}

extern char lbl_8055E45F;
char fn_801796C4(void) {
    return lbl_8055E45F;
}

#pragma dont_inline on
long fn_801796CC(long arg0, long arg1, long arg2) {
    return fn_8017873C((long*)&lbl_80430870[0], arg0, arg1, arg2, arg0);
}

extern int lbl_80431874[];
long fn_801796EC(long arg0, long arg1, long arg2) {
    return fn_8017873C((long*)&lbl_80431874, arg0, arg1, arg2, arg0);
}

#pragma dont_inline off
void DBPrintf_80179758(const char *fmt, ...) {
#pragma unused(fmt)
}

void DBPrintf_801797A8(const char *fmt, ...) {
#pragma unused(fmt)
}

extern int lbl_804305A0[];
extern int lbl_8055E450;
void fn_801797F8(int arg0, int arg1, unsigned short arg2) {
    int *p = &lbl_804305A0[arg0 * 2];
    p[0] = (arg1 << 16) + (arg2 & 0xffff);
    p[1] += 1;
}

void *fn_80179824(void) {
    /* initialize the scene state and copy configuration tables */
    return 0;
}

int fn_80179CB0(void) {
    return lbl_8055E450 + 0x2EE8;
}

extern unsigned char lbl_8055E46C;
extern unsigned char lbl_8055A304;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055E45E;
extern long fn_8017873C(long *, long, long, long, long);
extern long lbl_80430850[];
extern long fn_80178C1C(long *);
extern float lbl_80561B60;
extern double lbl_80561B70;
extern char *fn_80178374(long);
extern long fn_802E317C(const char *, long, ...);
extern const char lbl_80331B40[];
#include <revolution/MTX/vec.h>
extern int lbl_8055E43C;

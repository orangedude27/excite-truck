// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_80012158(void);

extern void fn_8000C964(void);
extern void fn_8000CD24(void);
extern u32 fn_8000C7F4(s32);
extern s32 fn_8000C840(void);
extern char lbl_80558A7C[];
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_800109E4(s32, f32, f32, f32, f32);
extern void fn_801345D8(void *, s32, const char *, ...);
extern void fn_80147230(void *, const char *, ...);
extern void fn_801473F8(void *, const char *, ...);
extern void fn_80147940(void *, void *, const char *, s32, ...);
extern void fn_80230F78(u8 *, f32 *, u32 *, s32);
extern void fn_802C9904(void);
extern const char lbl_80558A74[];
extern s32 lbl_80560210, lbl_80560214;
extern f32 lbl_8056021C, lbl_80560220, lbl_80560224, lbl_80560228;
extern f32 lbl_8056022C, lbl_80560230, lbl_80560234, lbl_80560238;

extern const char lbl_80558A70[];
extern s32 fn_80131234(s32);
extern void fn_801476C4(void);
extern void fn_80011A2C(void);

extern s32 lbl_8055D400;
extern u8 lbl_8055D404;
extern u8 lbl_8055D405;
extern u8 lbl_8055D406;
extern u8 lbl_8055D407;
extern s32 lbl_8055D408;
extern s32 lbl_8055D40C;
extern s32 lbl_8055D420;
extern void **lbl_8055D414;
extern void **lbl_8055D418;
extern void **lbl_8055D41C;
extern s32 lbl_8055D410;

void fn_802066C8(void*, u32);
void fn_80128668(void*);
s32 fn_8000CCB8(void);
void fn_80209110(s32);

// Externs for fn_8000CE60
extern u8 lbl_802FC058[];
extern s32 fn_802090D4(void*);
extern void fn_80209190(f32);
extern s32 fn_80145E70(void*);
extern s32 fn_80207848(void*, s32);
extern f32 lbl_80560218;

// Externs for fn_8000D070, fn_8000D100
extern f32 fn_80209028(void);
extern s32 fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206444(void);
extern void fn_80230E90(s32);
extern f32 lbl_80560234;

// Externs for fn_8000D100
extern char lbl_802FC1CC[];
extern void fn_80206454(void);
extern void fn_802E30C8(const char*, ...);
extern void fn_801769EC(void);

// Externs for fn_8000CCB8
extern s32 fn_800075A0(s32);
extern u32 __AXGetStackHead_80137CFC(s32);
extern s32 fn_802E8504(void);
extern s32 fn_80137C74(void);

s32 fn_8000CFA8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802066C8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_8000D000(s32 arg0, s32 arg1, s32 arg2) {
    lbl_8055D408 = arg0;
    lbl_8055D404 = 1;
    lbl_8055D405 = 0;
    lbl_8055D406 = 0;
    lbl_8055D407 = 0;
    lbl_8055D40C = arg1;
    lbl_8055D400 = arg2;
    lbl_8055D420 = fn_8000CCB8();
}
#pragma scheduling on
void fn_8000D000(s32, s32, s32);
void fn_8000D048(void) {
    ((void (*)(void))fn_8000D000)();
    lbl_8055D407 = 1;
}

void fn_8000CE60(void) {
    volatile u8 *p404 = &lbl_8055D404;
    *p404 = 0;
    lbl_8055D405 = 0;
    lbl_8055D407 = 0;
    lbl_8055D400 = 0;
    lbl_8055D408 = 0;
    lbl_8055D40C = 0;
    lbl_8055D410 = fn_802090D4((void*)(lbl_802FC058 + 0x140));
    fn_80209190(lbl_80560218);
    lbl_8055D414 = (void**)fn_80145E70((void*)(lbl_802FC058 + 0x14C));
    lbl_8055D418 = (void**)fn_80207848((void*)(lbl_802FC058 + 0x158), 0);
    lbl_8055D41C = (void**)fn_80207848((void*)(lbl_802FC058 + 0x164), 0);
    lbl_8055D420 = -1;
}

#pragma cplusplus on
extern "C" void fn_8000CEF0(void) {
    class Object {
    public:
        virtual void release(s32);
    };
    Object *p;

    p = (Object *)lbl_8055D418;
    if (p != NULL) {
        if (p != NULL)
            p->release(1);
        lbl_8055D418 = NULL;
    }
    p = (Object *)lbl_8055D41C;
    if (p != NULL) {
        if (p != NULL)
            p->release(1);
        lbl_8055D41C = NULL;
    }
    p = (Object *)lbl_8055D414;
    if (p != NULL) {
        if (p != NULL)
            p->release(1);
        lbl_8055D414 = NULL;
    }
    fn_80209110((s32)&lbl_8055D410);
    lbl_8055D404 = 0;
    lbl_8055D405 = 0;
    lbl_8055D407 = 0;
}
#pragma cplusplus off
void fn_8000D070(void) {
    u8 *base;
    if (lbl_8055D418 != NULL) {
        f32 val = fn_80209028();
        f32 *ptr = (f32*)((u8*)lbl_8055D418 + 8);
        if (val != *ptr) {
            *(u8*)((u8*)lbl_8055D418 + 0x4D) = 1;
            *ptr = val;
        }
        base = (u8*)lbl_8055D418;
        base[0x49] = 1;
        base[0x4B] = 0;
        base[0x4A] = 0;
    }
    if (fn_80265D64() == 0) __AXDSPInitCallback_801769E0();
    fn_80206444();
    lbl_8055D400 = 0;
    ((void (*)(s32, f32))fn_80209190)(lbl_8055D410, lbl_80560234);
    fn_80230E90(1);
}

#pragma scheduling invalid_target
void fn_8000D100(void) {
    u8 *base;
    if (lbl_8055D41C != NULL) {
        f32 val = fn_80209028();
        f32 *ptr = (f32*)((u8*)lbl_8055D41C + 8);
        if (val != *ptr) {
            *(u8*)((u8*)lbl_8055D41C + 0x4D) = 1;
            *ptr = val;
        }
        base = (u8*)lbl_8055D41C;
        base[0x49] = 1;
        base[0x4B] = 0;
        base[0x4A] = 0;
    }
    ((void (*)(s32, f32))fn_80209190)(lbl_8055D410, lbl_80560218);
    fn_80206454();
    if (lbl_8055D404 != 0) {
        fn_802E30C8(lbl_802FC1CC);
        lbl_8055D404 = 0;
        return;
    }
    fn_801769EC();
}
#pragma scheduling on
void fn_8000D19C(void) {
    if (lbl_8055D407 != 0) {
        lbl_8055D420 = fn_8000CCB8();
        if (lbl_8055D420 == -1) {
            lbl_8055D407 = 0;
        }
    }
}

#pragma cplusplus on
__declspec(section ".sdata") extern const char lbl_80558A70[];
__declspec(section ".sdata") extern const char lbl_80558A74[];
__declspec(section ".sdata") extern char lbl_80558A7C[];
extern "C" void fn_8000D1DC(void) {
    struct Dummy {
        virtual void *v0();
        virtual s32 *v1(char *);
        virtual void *v2();
        virtual s32 *v3(char *);
    };
    struct Info {
        u32 a, b, c, d;
        f32 e;
        u32 f, g, h;
    };
    struct Update {
        u32 value;
        f32 x, y;
        u32 flags;
        f32 z, w;
        u32 color;
    };
    f32 matrix[12];
    char name0[0x20], name1[0x20];
    struct Info info;
    struct Update update;
    u8 alpha;
    f32 selectedVal;
    f32 baseVal, scale, factor;
    f32 temp_f0, temp_f1, temp_f1_2, temp_f2, temp_f3, temp_f4, temp_f5, temp_f7;
    s32 temp_r8;
    register u8 *base = lbl_802FC058;
    register s32 i, selected;
    register s32 *obj;

    if (lbl_8055D405 != 0) {
        fn_8000C964();
        goto done;
    }
    if (lbl_8055D40C != 0) {
        ((void (*)(void))lbl_8055D40C)();
    }
    fn_80230B5C(matrix);
    fn_802C8638(matrix);
    fn_802C974C(lbl_80560218, lbl_8056021C, lbl_80560220);
    fn_800109E4(0x7F000000, lbl_80560224, lbl_80560228, lbl_8056022C, lbl_80560230);
    if (lbl_8055D407 != 0) {
        fn_8000CD24();
        goto done;
    }
    if (lbl_8055D414 != 0) {
        fn_801473F8(lbl_8055D414, lbl_80558A7C, lbl_80558A70,
                    fn_80131234((s32)(base + 0x198)));
        factor = lbl_80560234;
        scale = lbl_80560238;
        i = 0;
        baseVal = lbl_80560218;
        do {
            if (fn_8000C7F4(i) != 0) {
                fn_801345D8(name0, 0x20, (const char *)base + 0x94, i);
                fn_801345D8(name1, 0x20, lbl_80558A74, i);
                selected = i == lbl_8055D400;
                obj = ((Dummy *)lbl_8055D414)->v1(name1);
                info.a = (u32)obj[0];
                info.b = (u32)obj[1];
                info.c = (u32)obj[2];
                info.d = (u32)obj[3];
                info.e = ((f32 *)obj)[4];
                info.f = (u32)obj[5];
                info.g = (u32)obj[6];
                info.h = (u32)obj[7];
                alpha = 0xFF;
                selectedVal = factor;
                if (selected != 0) fn_80230F78(&alpha, &selectedVal, &info.g, 1);
                if (((s32 (*)(s32))fn_8000C840)(i) == 0)
                    info.g = (info.g & 0xFFFFFF) | 0x80000000;
                obj = ((Dummy *)lbl_8055D414)->v3(name0);
                if (obj != 0) {
                    if (((s32 (*)(s32))fn_8000C840)(i) == 0)
                        obj[6] = (obj[6] & 0xFFFFFF) | 0x80000000;
                    ((void (*)(void *, void *, const char *, s32))fn_80147940)(
                        lbl_8055D414, obj, (const char *)base + 0xA4,
                        ((-selected | selected) >> 31) + 2);
                    if (selected != 0) {
                        update.value = (u32)obj[0];
                        temp_f0 = baseVal + selectedVal;
                        update.x = ((f32 *)obj)[1];
                        update.y = ((f32 *)obj)[2];
                        temp_f2 = update.y;
                        update.flags = (u32)obj[3];
                        temp_f1 = ((f32 *)obj)[4];
                        update.z = temp_f1;
                        temp_f7 = ((f32 *)obj)[5];
                        temp_f5 = scale * temp_f1 * selectedVal;
                        update.w = temp_f7;
                        temp_r8 = obj[6];
                        temp_f4 = update.x - temp_f5;
                        temp_f3 = scale * temp_f7 * selectedVal;
                        update.z = temp_f1 * temp_f0;
                        temp_f1_2 = temp_f2 - temp_f3;
                        update.x = temp_f4;
                        update.y = temp_f1_2;
                        update.w = temp_f7 * temp_f0;
                        update.color = (temp_r8 & 0x00FF0000) | ((u32)alpha << 24) | (temp_r8 & 0xFFFF);
                        ((void (*)(void *, void *, const char *, s32, u8, s32,
                                   f32, f32, f32, f32, f32, f32, f32))fn_80147940)(
                            lbl_8055D414, &update, (const char *)base + 0xA4,
                            1, alpha, temp_r8, temp_f1_2, temp_f2, temp_f3,
                            temp_f4, temp_f5, selectedVal, temp_f7);
                    }
                }
                fn_80147230(&info, lbl_80558A70, fn_80131234(*(s32 *)(base + 0x40 + i * 4)));
            }
            ++i;
        } while (i < 4);
        ((Dummy *)lbl_8055D414)->v1((char *)base + 0xB0);
        fn_801476C4();
        ((Dummy *)lbl_8055D414)->v1((char *)base + 0xC0);
        fn_801476C4();
    }
done:
    fn_80011A2C();
    fn_802C9904();
}
#pragma cplusplus reset
u8 fn_8000D75C(void) {
    return lbl_8055D404;
}

s32 fn_8000D764(void) {
    if (lbl_8055D404 != 0) {
        return -1;
    }
    return fn_8000CCB8();
}

extern s32 fn_80019BA8(void);
s32 fn_8000C7CC(void) {
    return fn_80019BA8() == 0;
}

#pragma dont_inline on
#pragma scheduling off
u32 fn_8000C7F4(s32 arg0) {
    if (fn_8000C7CC() == 0) {
        return 1;
    }
    return (u32)((2 - arg0) | (arg0 - 2)) >> 31;
}
#pragma scheduling on
#pragma dont_inline off
s32 fn_8000C840(void) {
    return 1;
}

s32 fn_8000C848(s32 arg0) {
    switch (arg0) {
    case 0x126:
        if (lbl_8055D406 == 0) { lbl_8055D406 = 1; fn_80230E90(1); }
        goto done;
    case 0x128:
        if (lbl_8055D406 != 0) { lbl_8055D406 = 0; fn_80230E90(1); }
        goto done;
    case 0x1B:
    case 0x53:
        lbl_8055D406 = 0;
    case 0x58:
    case 0xD:
        if (lbl_8055D406 != 0) {
            if (((s32 (*)(s32))fn_8000C840)(lbl_8055D400) != 0) {
                lbl_8055D404 = 0;
                if (((s32 (*)(s32))lbl_8055D408)(lbl_8055D400) == 0) lbl_8055D404 = 1;
            }
        } else lbl_8055D405 = 0;
        goto done;
    default:
        return 0;
    }
done:
    fn_80012158();
    return 1;
}

extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_800109E4(s32, f32, f32, f32, f32);
extern void fn_801345D8(void *, s32, const char *, ...);
extern void fn_80147230(void *, const char *, ...);
extern void fn_801473F8(void *, const char *, ...);
extern void fn_80147940(void *, void *, const char *, s32, ...);
extern void fn_80230F78(u8 *, f32 *, u32 *, s32);
extern void fn_802C9904(void);
extern const char lbl_80558A74[];
extern s32 lbl_80560210, lbl_80560214;
extern f32 lbl_8056021C, lbl_80560220, lbl_80560224, lbl_80560228;
extern f32 lbl_8056022C, lbl_80560230, lbl_80560234, lbl_80560238;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_pointer_aliasing on
#pragma cplusplus on
extern "C" void fn_8000C964(void) {
    class Dummy { public: virtual void *f2(); virtual s32 *get3(const char *); virtual void *f4(); virtual s32 *get5(const char *); };
    struct Info { u32 a, b, c, d; f32 e; u32 f, g, h; };
    struct Update { u32 value, x, y, flags; f32 z, w; u32 color; };
    f32 matrix[12];
    char name0[0x20], name1[0x20];
    struct Info item;
    struct Update out;
    s32 labels[2];
    register s32 *entries;
    u8 alpha;
    f32 baseVal, scale, factor, selectedVal;
    f32 temp_f0, temp_f1, temp_f1_2, temp_f2, temp_f3, temp_f4, temp_f5, temp_f7;
    s32 temp_r8, drawMode;
    register u8 *base = lbl_802FC058;
    register s32 i, selected;
    register s32 *labelp;
    register s32 *obj;
    fn_80230B5C(matrix);
    fn_802C8638(matrix);
    fn_802C974C(lbl_80560218, lbl_8056021C, lbl_80560220);
    fn_800109E4(0x7F000000, lbl_80560224, lbl_80560228, lbl_8056022C, lbl_80560230);
    if (lbl_8055D414 != 0) {
        labels[0] = lbl_80560210;
        labels[1] = lbl_80560214;
        entries = (s32 *)(base + 0x40);
        fn_801473F8(lbl_8055D414, (const char *)base + 0x68, lbl_80558A70,
                    fn_80131234(entries[lbl_8055D400]));
        fn_801473F8(lbl_8055D414, (const char *)base + 0x78, lbl_80558A70,
                    fn_80131234((s32)(base + 0x84)));
        factor = lbl_80560234;
        labelp = labels;
        scale = lbl_80560238;
        i = 0;
        baseVal = lbl_80560218;
        do {
            fn_801345D8(name0, 0x20, (const char *)base + 0x94, i + 1);
            fn_801345D8(name1, 0x20, lbl_80558A74, i + 1);
            obj = ((Dummy *)lbl_8055D414)->get3(name1);
            selected = 0;
            item.a = obj[0]; item.b = obj[1]; item.c = obj[2]; item.d = obj[3];
            item.e = ((f32 *)obj)[4];
            item.f = obj[5]; item.g = obj[6]; item.h = obj[7];
            alpha = 0xFF;
            selectedVal = factor;
            if ((i == 0 && lbl_8055D406 != 0) || (i == 1 && lbl_8055D406 == 0)) selected = 1;
            if (selected != 0) fn_80230F78(&alpha, &selectedVal, &item.g, 1);
            obj = ((Dummy *)lbl_8055D414)->get5(name0);
            if (obj != 0) {
                if (((s32 (*)(s32))fn_8000C840)(i) == 0) obj[6] = (obj[6] & 0xFFFFFF) | 0x80000000;
                drawMode = ((-selected | selected) >> 31) + 2;
                ((void (*)(void *, void *, const char *, s32))fn_80147940)(lbl_8055D414, obj, (const char *)base + 0xA4, drawMode);
                if (selected != 0) {
                    out.value = obj[0]; out.x = obj[1]; out.y = obj[2]; out.flags = obj[3]; out.z = ((f32 *)obj)[4];
                    temp_f0 = baseVal + selectedVal;
                    temp_f2 = *(f32 *)&out.y;
                    temp_f1 = out.z;
                    temp_f7 = ((f32 *)obj)[5];
                    temp_f5 = scale * temp_f1 * selectedVal;
                    temp_r8 = obj[6];
                    temp_f4 = *(f32 *)&out.x - temp_f5;
                    temp_f3 = scale * temp_f7 * selectedVal;
                    out.z = temp_f1 * temp_f0;
                    temp_f1_2 = temp_f2 - temp_f3;
                    *(f32 *)&out.x = temp_f4;
                    *(f32 *)&out.y = temp_f1_2;
                    out.w = temp_f7 * temp_f0;
                    out.color = (temp_r8 & 0x00FF0000) | ((u32)alpha << 24) | (temp_r8 & 0xFFFF);
                    ((void (*)(void *, void *, const char *, s32, u8, s32, f32, f32, f32, f32, f32, f32, f32))fn_80147940)(
                        lbl_8055D414, &out, (const char *)base + 0xA4, 1, alpha, temp_r8,
                        temp_f1_2, temp_f2, temp_f3, temp_f4, temp_f5, selectedVal, temp_f7);
                }
            }
            fn_80147230(&item, lbl_80558A70, (const char *)fn_80131234(*labelp));
            ++i; ++labelp;
        } while (i < 2);
        ((Dummy *)lbl_8055D414)->get3((const char *)base + 0xB0);
        fn_801476C4();
        ((Dummy *)lbl_8055D414)->get3((const char *)base + 0xC0);
        fn_801476C4();
    }
    fn_80011A2C();
    fn_802C9904();
}
#pragma cplusplus reset
#pragma opt_pointer_aliasing reset
#pragma opt_propagation reset
#pragma scheduling on
s32 fn_8000CCB8(void) {
    s32 i = 0;
    goto compare;
body:
    if (fn_800075A0(i) != 0) {
        __AXGetStackHead_80137CFC(i);
        if (fn_802E8504() == 0) {
            return i;
        }
    }
    i++;
compare:
    if (i < fn_80137C74()) {
        goto body;
    }
    return -1;
}

extern void fn_80148070(void *, s32, s32);
extern void fn_80148134(f32 *, f32 *, s32, f32, f32);
extern s32 fn_80131234(s32);
extern void fn_801476C4(void);
extern void fn_800103B8(s32, s32, f32, f32, f32, f32, const char *, ...);
extern void fn_80011A2C(void);
extern f32 lbl_80560248;
extern s32 lbl_80560240;
extern s32 lbl_80560244;
extern const char lbl_80558A70[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_8000CD24(void) {
    struct ConfigService {
        virtual void slot0();
        virtual void *lookup(const char *);
        virtual void slot2();
        virtual void *open(const char *);
        virtual void *find(const char *);
    };
    ConfigService *service;
    u8 *base = lbl_802FC058;
    void *object;
    void *temp;
    f32 out0;
    f32 out1;
    volatile s32 names[2];

    service = (ConfigService *)lbl_8055D414;
    if (service == 0) return;
    object = service->open((const char *)base + 0xFC);
    if (object != 0) {
        temp = ((ConfigService *)*(volatile void ***)&lbl_8055D414)->find((const char *)base + 0x108);
        fn_80148070(object, 0x96FFFFFF, (s32)temp);
    }
    ((ConfigService *)*(volatile void ***)&lbl_8055D414)->lookup((const char *)base + 0x118);
    fn_801476C4();
    temp = ((ConfigService *)*(volatile void ***)&lbl_8055D414)->lookup((const char *)base + 0x12C);
    if (temp == 0) return;
    names[0] = lbl_80560240;
    names[1] = lbl_80560244;
    fn_80148134(&out0, &out1, *(s32 *)((u8 *)temp + 0xC), *(f32 *)((u8 *)temp + 4), *(f32 *)((u8 *)temp + 8));
    ((void (*)(s32, s32, f32, f32, f32, f32, const char *, ...))fn_800103B8)(
        *(s32 *)((u8 *)temp + 0x18),
        *(s32 *)((u8 *)temp + 0x14),
        *(f32 *)((u8 *)temp + 0x10),
        out0,
        out1,
        *(f32 *)((u8 *)object + 0x10) - lbl_80560248,
        lbl_80558A70,
        fn_80131234(names[lbl_8055D420]));
    fn_80011A2C();
}
#pragma scheduling on
#pragma cplusplus off

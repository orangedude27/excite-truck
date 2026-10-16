// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern "C" void fn_802223C4(void *arg0, s32 arg1);


class TruckIface {
public:
    virtual ~TruckIface();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

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
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual s32 vf31();    // vtable 0x84
    virtual s32 vf32();    // vtable 0x88
};

extern "C" void fn_8023976C(s32);
extern "C" void fn_802168BC(void *);
extern "C" void *fn_8022D97C(s32);
extern "C" void *lbl_8033F90C[];
extern "C" int lbl_8033FA28[];
extern "C" void fn_80218F80(void);
extern "C" void fn_8023986C(s32);
extern "C" void fn_8023967C(s32, s32);
extern "C" void fn_8021915C(void *, u32);
extern "C" s32 fn_80128668(void *);
extern "C" s32 fn_801284F8(s32, const char *);
extern "C" s32 fn_8023964C(void);
extern "C" void fn_80239784(s32, void *);
extern char lbl_8033DDA4[];
extern char lbl_8033DE28[];
extern char lbl_8033DCDC[];


extern "C" void fn_8022BAD0(s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern "C" s32 fn_8012850C(void *, const char *);
extern "C" void *memcpy(void *, const void *, unsigned long);
extern "C" char *strcpy(char *, const char *);
extern "C" void *fn_80219568(void *, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80219718(void *);
extern "C" void fn_80219440(void *, s32, void *, s32);
extern f32 lbl_805634A4;
extern "C" f32 lbl_805634A8;
extern "C" void fn_802C5280(void *, s32, s32, s32, s32, void *);
extern char lbl_8033D878[];
extern char lbl_8033F768[];
extern "C" u32 *fn_80216708(void);
extern "C" s32 fn_80218F34(void *, s32, s32, s32, s32, s32);
extern "C" void fn_8022B91C(s32, s32, s32, s32, s32);
extern "C" s32 fn_802C51AC(s32);
extern "C" s32 fn_802C51C0(s32);
extern "C" s32 fn_802C5220(s32);
extern "C" s32 fn_802C3034(s32);
extern f32 lbl_805634A8;
extern f32 lbl_805634E8;
extern int lbl_8033F6E0[];

extern "C" void fn_80219044(void);
extern "C" void fn_8021AC24(void *, s32, s32, s32, s32);
extern "C" void fn_802C519C(void *);
extern "C" void fn_8021915C(void *, u32);
extern "C" s32 fn_80128668(void *);
extern "C" void *lbl_8033EDC8[];
extern "C" void *lbl_8033ED44[];

extern f32 lbl_805634A0;
extern f32 lbl_805634A4;
extern f32 lbl_805634B0;
extern f32 lbl_805634B4;

extern "C" void fn_802191F0(void *arg0, s32 arg1, s32 arg2) {
    void *obj = arg0;
    void **vt = *(void ***)obj;
    s32 size = ((s32 (*)(void *))vt[30])(obj);
    s32 x = arg1 + size;
    s32 end = arg2 + (*(s32 *)((u8 *)arg0 + 0x10) - *(s32 *)((u8 *)arg0 + 8));
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC) = x;
    *(s32 *)((u8 *)arg0 + 8) = arg2;
    *(s32 *)((u8 *)arg0 + 0x10) = end;
}

extern "C" void fn_80219264(void *arg0, s32 arg1, s32 arg2) {
    void **vtable = *(void ***)arg0;
    ((void (*)(void *, s32, s32))vtable[7])(arg0,
        *(s32 *)((u8 *)arg0 + 4) + arg1,
        *(s32 *)((u8 *)arg0 + 8) + arg2);
}

extern "C" void fn_80219284(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)((u8 *)arg0 + 4) + arg1;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 8) + arg2;
}

void fn_802192A0(void) {

}

extern "C" s32 fn_802192A4(void *, s32) { return 0; }
extern "C" void fn_8021889C(s32, s32, f32);
extern "C" void fn_80218968(s32, s32, f32);

extern "C" void fn_80219354(void) { fn_80219044(); }

extern "C" void fn_80219044();
extern f32 lbl_805634A0;
extern f32 lbl_805634A4;
extern f32 lbl_805634B0;
extern f32 lbl_805634B4;
extern "C" void fn_80219358(void *arg0, f32 value) {
    if (value >= lbl_805634B0) {
        if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
            return;
        *(u8 *)((u8 *)arg0 + 0x1A) = 1;
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
        return;
    }
    if (*(u8 *)((u8 *)arg0 + 0x1A) == 0) {
        if (*(f32 *)((u8 *)arg0 + 0x20) < lbl_805634B4) {
            *(f32 *)((u8 *)arg0 + 0x20) = lbl_805634A4;
            if (value > lbl_805634B0)
                *(f32 *)((u8 *)arg0 + 0x28) = lbl_805634A4 / value;
        }
    }
    *(f32 *)((u8 *)arg0 + 0x1C) = lbl_805634A0;
}

extern "C" void fn_802193C8(void *arg0, f32 value) {
    s32 flag;
    if (value < lbl_805634B0) {
        flag = *(u8 *)((u8 *)arg0 + 0x1A) != 0;
        if (flag) {
            *(u8 *)((u8 *)arg0 + 0x234) = 1;
            *(u8 *)((u8 *)arg0 + 0x1A) = 0;
        }
        return;
    }
    flag = *(u8 *)((u8 *)arg0 + 0x1A) != 0;
    if (flag) {
        if (*(f32 *)((u8 *)arg0 + 0x1C) < lbl_805634B4) {
            *(f32 *)((u8 *)arg0 + 0x1C) = lbl_805634A4;
            if (value <= lbl_805634B0) {
                value = lbl_805634B0;
            }
            *(f32 *)((u8 *)arg0 + 0x24) = lbl_805634A4 / value;
        }
    }
    *(f32 *)((u8 *)arg0 + 0x20) = lbl_805634A0;
}

extern "C" void fn_80219440(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 idx;
    s32 value = fn_8012850C((void *)arg3, lbl_8033D878);
    idx = *(s32 *)((u8 *)arg0 + 0x230);
    *(s32 *)((u8 *)arg0 + idx * 16 + 0x34) = arg1;
    *(s32 *)((u8 *)arg0 + idx * 16 + 0x30) = (s32)arg2;
    *(s32 *)((u8 *)arg0 + idx * 16 + 0x38) = arg3;
    *(s32 *)((u8 *)arg0 + idx * 16 + 0x3C) = value;
    memcpy((void *)value, arg2, (unsigned long)arg3);
    *(s32 *)((u8 *)arg0 + 0x230) = *(s32 *)((u8 *)arg0 + 0x230) + 1;
}

extern void fn_802179A0(s32);
extern void fn_80218198(s32, s32);
extern "C" void fn_802194F4(void* arg0) {
    fn_802179A0(*(s32*)((u8*)arg0 + 0x2C));
}

extern "C" void fn_802194FC(void* arg0) {
    fn_80218198(*(s32*)((u8*)arg0 + 0x2C), 0);
}

extern void fn_80217AC0(s32);
extern "C" void fn_80219508(void* arg0) {
    fn_80217AC0(*(s32*)((u8*)arg0 + 0x2C));
}

extern "C" void fn_80219510(void *arg0, s32 arg1, s32 arg2) {
    s32 neg1 = -arg1;
    s32 neg2 = -arg2;
    *(s32 *)((u8 *)arg0 + 0x244) = neg1;
    *(u8 *)((u8 *)arg0 + 0x24C) = 1;
    *(s32 *)((u8 *)arg0 + 0x248) = neg2;
}

extern "C" void fn_8021952C(void *arg0, s32 arg1, s32 arg2) {
    s32 *ptr = *(s32 **)((u8 *)arg0 + 0x2C);
    if (*(u8 *)((u8 *)arg0 + 0x24C) != 0) {
        *(s32 *)((u8 *)ptr + 0x454) = *(s32 *)((u8 *)arg0 + 0x244) + arg1 + *(s32 *)((u8 *)ptr + 0x454);
        *(s32 *)((u8 *)ptr + 0x458) = *(s32 *)((u8 *)arg0 + 0x248) + arg2 + *(s32 *)((u8 *)ptr + 0x458);
    }
}

extern "C" void *fn_80219568(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    fn_80218F34(arg0, arg1, arg2, arg1 + arg5, arg2 + arg6, arg3);
    *(s32 *)((u8 *)arg0 + 0x244) = 0;
    *(void **)arg0 = lbl_8033FA28;
    *(s32 *)((u8 *)arg0 + 0x248) = 0;
    *(s32 *)((u8 *)arg0 + 0x250) = arg4;
    *(s32 *)((u8 *)arg0 + 0x24C) = arg3;
    return arg0;
}

extern "C" void fn_802195DC(void *arg0, s32 arg1) {
    fn_802C3034(arg1);
    VfObj *obj = (VfObj *)arg0;
    s32 a = obj->vf31();
    s32 b = obj->vf32();
    fn_8022B91C(*(s32 *)((u8 *)arg0 + 0x250), *(s32 *)((u8 *)arg0 + 0x244), *(s32 *)((u8 *)arg0 + 0x248), b, a);
}

extern "C" s32 fn_80219658(void) { return 0; }

extern "C" void fn_80219660(void *arg0, s32 unused) {
    void **vt = *(void ***)arg0;
    s32 a = *(s32 *)((u8 *)arg0 + 8);
    s32 b = *(s32 *)((u8 *)arg0 + 4);
    s32 c = *(s32 *)((u8 *)arg0 + 0x10) - a;
    s32 x = ((s32 (*)(void *))vt[33])(arg0);
    s32 y = ((s32 (*)(void *))vt[34])(arg0);
    s32 z = ((s32 (*)(void *))vt[30])(arg0);
    fn_8022BAD0(*(s32 *)((u8 *)arg0 + 0x250),
                 *(s32 *)((u8 *)arg0 + 0x244) + b,
                 *(s32 *)((u8 *)arg0 + 0x248) + a,
                 *(s32 *)((u8 *)arg0 + 0x24C), z, c, y, x, lbl_805634A4);
}

extern "C" void fn_80219870(void *arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    fn_80219568(arg0, arg1, arg2, 0, arg7, 0, 0, 0);
    *(void **)arg0 = lbl_8033F768;
    strcpy((char *)arg0 + 0x258, arg3);
    *(s32 *)((u8 *)arg0 + 0x254) = arg4;
    fn_80219440(arg0, 0, (void *)arg4, 1);
    fn_80219718(arg0);
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80219900(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802199D0(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_802223C4(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021A650(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8021A910(void *arg0, s32 arg1) {
    u8 *base = (u8 *)arg0;
    s32 *p254 = *(s32 **)(base + 0x254);
    s32 v258 = *(s32 *)(base + 0x258);
    s32 v2c = *(s32 *)(base + 0x2C);
    f32 f;
    if (*p254 == v258) {
        f = (arg1 == 2) ? lbl_805634A8 : lbl_805634E8;
        fn_80218968(v2c, v258, f);
    } else {
        f = (arg1 == 2) ? lbl_805634A8 : lbl_805634E8;
        fn_8021889C(v2c, v258, f);
    }
    ((VfObj *)arg0)->vf21();
}

extern "C" s32 fn_8021A9A4(void *arg0) {
    u8 *base = (u8 *)arg0;
    s32 r4 = 0;
    s32 r5 = 0;
    if (*(u8 *)fn_80216708() != 0)
        r4 = 2;
    s32 *p = *(s32 **)(base + 0x254);
    if (p != 0 && *p == *(s32 *)(base + 0x258))
        r5 = 1;
    return (r5 != 0) | r4;
}

extern "C" s32 fn_8021AB88(void) { return 0; }

extern "C" s32 fn_8021AB90(void *arg0, s32 arg1) {
    u8 *base = (u8 *)arg0;
    s32 ret;
    if (*(u8 *)fn_80216708() != 0 && arg1 != 0x127) {
        if (arg1 < 0x127) {
            if (arg1 < 0x126) {
                ret = fn_802192A4(arg0, arg1);
            } else {
                fn_80217AC0(*(s32 *)(base + 0x2C));
                ret = 1;
            }
        } else {
            if (arg1 < 0x129) {
                fn_802179A0(*(s32 *)(base + 0x2C));
                ret = 1;
            } else {
                ret = fn_802192A4(arg0, arg1);
            }
        }
    } else {
        ret = fn_802192A4(arg0, arg1);
    }
    return ret;
}

extern "C" void fn_8021AC24(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *base = (u8 *)arg0;
    s32 b = fn_802C51C0(arg4);
    s32 a = fn_802C5220(arg4);
    fn_80218F34(arg0, arg1, arg2, arg1 + b, arg2 + a, 0);
    *(f32 *)(base + 0x248) = lbl_805634A8;
    *(f32 *)(base + 0x24C) = lbl_805634E8;
    *(void **)base = lbl_8033F6E0;
    *(s32 *)(base + 0x250) = arg4;
    *(u8 *)(base + 0x244) = 0;
}

extern "C" void fn_8021ACC0(void *arg0, s32 arg1) {
    fn_802C3034(arg1);
    fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250));
    if (fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250)) > 0)
        fn_802C51AC(*(s32 *)((u8 *)arg0 + 0x250));
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021AF9C(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8021915C(void*, u32);
extern "C" s32 fn_80128668(void*);
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8021B404(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8021C974(void) { return 0; }

extern "C" void *fn_8021C97C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    ((void (*)(void *, s32, s32, s32, s32))fn_8021AC24)(arg0, arg1, arg2, arg3, arg5);
    *(s32 *)((u8 *)arg0 + 0x258) = arg4;
    *(u32 *)arg0 = (u32)lbl_8033EDC8;
    *(s32 *)((u8 *)arg0 + 0x254) = arg5;
    return arg0;
}

extern "C" void fn_8021C9D8(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x258) > 0)
        ((void (**)(void *))(*(void ***)((u8 *)arg0 + 0x254)))[5](*(void **)((u8 *)arg0 + 0x254));
    else
        ((void (**)(void *))(*(void ***)((u8 *)arg0 + 0x254)))[6](*(void **)((u8 *)arg0 + 0x254));
}

extern "C" void fn_802C519C(void *);
extern "C" void fn_8021915C(void *, u32);
extern "C" s32 fn_80128668(void *);
extern "C" void *fn_8021CAD4(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033ED44;
        fn_802C519C(*(void **)((u8 *)arg0 + 0x24C));
        fn_802C519C(*(void **)((u8 *)arg0 + 0x250));
        fn_8021915C(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8021E884(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_80221E7C(void *arg0) {
    void *temp = *(void **)((u8 *)arg0 + 0x14);
    if (temp != 0 && *(u8 *)((u8 *)temp + 0x1A) != 0)
        *(u8 *)((u8 *)temp + 0x234) = 1;
}

extern "C" void fn_80221EA0(void *arg0) {
    fn_80219440(*(void **)((u8 *)arg0 + 0x14), 0, 0, 0);
}

extern "C" void fn_80221F94(void *arg0, s32 arg1) {
    fn_802168BC((void *)arg1);
}

extern "C" void fn_80222120(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x248) = 1;
    ((void (**)(void *))(*(void ***)arg0))[19](arg0);
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" void fn_80222178(void *arg0) {
    s32 idx;
    void *obj;
    s32 (*callback)(void *);
    ((void (*)(void *))(*(void ***)arg0)[19])(arg0);
    idx = *(s32 *)((u8 *)arg0 + 0x24C);
    *(u8 *)((u8 *)arg0 + 0x248) = 0;
    if (idx >= 0 && *(s32 *)((u8 *)arg0 + 0x250) >= 0) {
        obj = fn_8022D97C(*(s32 *)(*(s32 *)((u8 *)arg0 + 0x244) + idx * 0x24));
        callback = *(s32 (**)(void *))((u8 *)obj + 0x24);
        if (callback != 0 && callback(*(void **)((u8 *)obj + 0x20)) != 0)
            fn_802168BC(*(void **)((u8 *)obj + 0x20));
    }
    *(s32 *)((u8 *)arg0 + 0x24C) = -1;
    *(s32 *)((u8 *)arg0 + 0x250) = -1;
    if (*(u8 *)((u8 *)arg0 + 0x1A) != 0)
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" void fn_80222340(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    fn_80218F34(arg0, arg1, arg2, arg1 + arg4, arg2 + arg5, arg3);
    *(s32 *)((u8 *)arg0 + 0x248) = arg1;
    *(void **)arg0 = lbl_8033F90C;
    *(s32 *)((u8 *)arg0 + 0x24C) = arg2;
    *(s32 *)((u8 *)arg0 + 0x250) = arg3;
    *(s32 *)((u8 *)arg0 + 0x244) = arg6;
    ((void (*)(void *))(*(void ***)arg0)[33])(arg0);
}

extern "C" void fn_802223C4(void *arg0, s32 arg1) {
    s32 value;
    void *object;
    if (arg0 == 0)
        return;
    value = *(s32 *)((u8 *)arg0 + 0x244);
    *(void **)arg0 = lbl_8033F90C;
    if (value != 0) {
        object = (void *)value;
        ((void (*)(void *, s32))(*(void ***)object)[2])(object, 1);
    }
    fn_8021915C(arg0, 0);
    if (arg1 > 0)
        fn_80128668(arg0);
}

extern "C" void fn_80222450(void *arg0) {
    if (*(u8 *)((char *)arg0 + 0x1A) != 0) {
        *(u8 *)((char *)arg0 + 0x234) = 1;
    }
}

extern "C" void fn_80222468(void *arg0, s32 arg1, s32 arg2) {
    ((void (*)(void))fn_802191F0)();
    *(s32 *)((u8 *)arg0 + 0x248) = arg1;
    *(s32 *)((u8 *)arg0 + 0x24C) = arg2;
}

extern "C" void fn_802328D4(void*);
extern "C" int lbl_8033F9E0[];
extern "C" void* __dt__14CollisionSpaceFv_80222584(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_8033F9E0;
        fn_802328D4(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" int lbl_8033F998[];
extern "C" void* __dt__14CollisionSpaceFv_80222998(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_8033F998;
        fn_802C519C(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" u32 fn_80223AAC(void) { return 1; }

extern "C" void *fn_80228418(void *p,void *q,s32 a){s32 r;fn_80218F80();*(s32*)((u8*)p+0x244)=0;*(void**)p=lbl_8033DE28;*(u8*)((u8*)p+0x248)=0;if(a){*(s32*)((u8*)p+0x244)=a;}else{const char *name=lbl_8033DCDC;r=fn_801284F8(0x18,name);if(r)r=fn_8023964C();*(s32*)((u8*)p+0x244)=r;*(u8*)((u8*)p+0x248)=1;}fn_80239784(*(s32*)((u8*)p+0x244),(u8*)q+0x40);return p;}

extern "C" void *fn_802284BC(void *p,s32 a){if(p){*(void**)p=lbl_8033DE28;fn_8023986C(*(s32*)((u8*)p+0x244));if(*(u8*)((u8*)p+0x248))fn_8023967C(*(s32*)((u8*)p+0x244),1);*(s32*)((u8*)p+0x244)=0;fn_8021915C(p,0);if(a>0)fn_80128668(p);}return p;}

extern "C" void fn_8022854C(void *p){fn_8023976C(*(s32*)((u8*)p+0x244));}

extern "C" void fn_802396BC(s32);
extern "C" void fn_80228554(void *p){fn_802396BC(*(s32*)((u8*)p+0x244));}

extern "C" void *fn_8022855C(void *p,s32 unused,s32 a,s32 b){fn_80218F80();*(s32*)((u8*)p+0x244)=a;*(void**)p=lbl_8033DDA4;*(s32*)((u8*)p+0x248)=b;return p;}

extern "C" void fn_80214D48(void);
extern "C" void fn_80228AEC(s32);
extern "C" void fn_802C86F0(void *, s32, s32, s32, s32);
extern "C" void fn_802C88BC(s32);
extern "C" void fn_802C8750(void *, s32);
extern "C" void fn_80228A38(s32 arg0) {
    fn_80214D48();
    fn_80228AEC(arg0);
}

void fn_80228A6C(void *arg0) {
    void *obj = *(void **)((u8 *)arg0 + 0x268);
    ((VfObj *)obj)->vf6();
}

void fn_80228A80(void) {
}

void fn_80228A84(void *arg0) {
    s32 work[2];
    fn_802C86F0(work, *(s32 *)((u8 *)arg0 + 0x270),
        *(s32 *)((u8 *)arg0 + 0x274), *(s32 *)((u8 *)arg0 + 0x278),
        *(s32 *)((u8 *)arg0 + 0x27C));
    fn_802C88BC(2);
    ((VfObj *)*(void **)((u8 *)arg0 + 0x268))->vf7();
    fn_802C8750(work, -1);
}

extern "C" void fn_80228D90(void *arg0) {
    TruckIface *obj = *(TruckIface **)((u8 *)arg0 + 0x268);
    obj->vf6();
}

extern "C" s32 fn_80228DA4(void) { return 0; }

extern "C" void fn_80228DAC(void *arg0) {
    TruckIface *obj = *(TruckIface **)((u8 *)arg0 + 0x268);
    obj->vf7();
}

extern "C" void fn_80228DC0(void) { }

extern "C" void *fn_80223208(void *, unsigned int);
extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228F4C(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80223208(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228FA4(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_80228FFC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229054(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229168(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802291C4(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229220(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022927C(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802292D8(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802293E0(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8022943C(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229498(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_802294F4(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802295AC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" u32 fn_80229614(void) { return 1; }

extern "C" u32 fn_80229620(void) { return 1; }

extern "C" void fn_8022984C(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x254);
    *p = (u8)((s8)(*p == 0));
}

extern "C" void fn_80229864(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_80229884(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" s32 fn_802298A4(s32 arg0) {
    return arg0 + 0x258;
}

extern "C" int fn_802298DC(void *arg0) {
    int *p = *(int **)((char *)arg0 + 0x254);
    if (p != 0) {
        return *p;
    }
    return 0;
}

extern "C" void fn_802298F8(void) {
}

extern "C" void fn_802298FC(void) {
}

void fn_80229900(void *arg0) {
    ((void (*)(void *, int, int))(*(void ***)arg0)[0x74 / 4])(arg0, 0, 0);
}

extern "C" void fn_80229998(void *arg0) {
    int *p = *(int **)((char *)arg0 + 0x254);
    if (p != 0) {
        *p = *(int *)((char *)arg0 + 0x258);
    }
}

int fn_802299B0(void *arg0) {
    int result = 0;
    if (*(unsigned char *)((char *)arg0 + 0x18)) result = 2;
    int *p = *(int **)((char *)arg0 + 0x254);
    if (p != 0 && *p == *(int *)((char *)arg0 + 0x258)) result |= 1;
    return result;
}

void fn_802299FC(void *arg0) {
    int a = *(int *)((char *)arg0 + 8);
    int diff = *(int *)((char *)arg0 + 0x10) - a;
    int (*get)(void *, int) = *(int (**)(void *, int))(*(int *)arg0 + 0x88);
    int x = get(arg0, a);
    int (*get2)(void *) = *(int (**)(void *))(*(int *)arg0 + 0x78);
    int y = get2(arg0);
    void *p = *(void **)((char *)arg0 + 0x244);
    ((void (*)(void *, int, int, int, int, int, int))(*(int *)p + 0xC))(p,
        *(int *)((char *)arg0 + 0x248), *(int *)((char *)arg0 + 0x24C),
        *(int *)((char *)arg0 + 0x250), y, diff, x);
}

extern "C" void fn_80229AC4(void *arg0) {
    int *p = *(int **)((char *)arg0 + 0x254);
    if (p != 0) {
        *p = *(int *)((char *)arg0 + 0x258);
    }
}

extern "C" u32 fn_80229ADC(void) { return 1; }

extern "C" void fn_80229B0C(void *arg0, s32 arg1, s32 arg2) {
    ((void (*)(void *, s32, s32))fn_80219264)(arg0, arg1, arg2);
    volatile s32 *p1 = (volatile s32 *)((u8 *)arg0 + 0x248);
    volatile s32 *p2 = (volatile s32 *)((u8 *)arg0 + 0x24C);
    s32 a = *p1;
    s32 b = *p2;
    *p1 = a + arg1;
    *p2 = b + arg2;
}

extern "C" s32 fn_80229B68(void) { return 0; }

extern "C" s32 fn_80229B70(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x254);
}

extern "C" char lbl_8033EFF4[];
extern "C" s32 fn_801E4A2C(s32, const char *);
extern "C" void * __dt__Q34Game10MemoryCard8ResourceFv_80229B78(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033EFF4;
        fn_801E4A2C(*(s32 *)((u8 *)arg0 + 0x348), lbl_8033EFF4);
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" s32 fn_80229C9C(s32 arg0) {
    return arg0 + 0x264;
}

extern "C" s32 fn_80229CA4(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" s32 fn_80229CAC(s32);
extern "C" s32 fn_80229CAC(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" void fn_80229CB4(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x244)) = 1;
    (*(f32 *)((u8 *)arg0 + 0x248)) = 0.0f;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}

extern "C" void fn_80229CD8(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x244)) = 0;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}

extern "C" void fn_802C5280(void *, s32, s32, s32, s32, void *);
extern "C" f32 lbl_805634A8;
extern "C" void fn_80229CF8(void *arg0) {
    u8 flag = *(u8 *)((u8 *)arg0 + 0x1A);
    if (flag == 0) {
        *(u8 *)((u8 *)arg0 + 0x18) = 1;
        *(f32 *)((u8 *)arg0 + 0x248) = lbl_805634A8;
        return;
    }
    *(u8 *)((u8 *)arg0 + 0x18) = 1;
    *(f32 *)((u8 *)arg0 + 0x248) = lbl_805634A8;
    *(u8 *)((u8 *)arg0 + 0x234) = 1;
}

extern "C" void fn_80229D1C(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
    if ((s32)*(u8 *)((u8 *)arg0 + 0x1A) != 0) {
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
    }
}

extern "C" void fn_80229D3C(void *arg0, s32 arg1, s32 arg2) {
    s32 value = *(s32 *)((u8 *)arg0 + 4);
    fn_802C5280(*(void **)((u8 *)arg0 + 0x250), arg1 - value,
                arg2 - *(s32 *)((u8 *)arg0 + 8), 0, value, arg0);
}

extern "C" s32 fn_80229D5C(s32);
extern "C" s32 fn_80229D5C(s32 arg0) {
    return arg0 + 0x264;
}

extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80229D64(
    void* this_, s32 flag) {
    if (this_) {
        if (this_ != NULL) {
            fn_8021915C(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_80229DC0(s32 arg0) {
    return arg0 + 0x268;
}

extern "C" void fn_80229DC8(void *arg0) {
    register u32 zero = 0;
    register u32 one = 1;
    *(u32 *)((u8 *)arg0 + 0x260) = zero;
    *(u8 *)((u8 *)arg0 + 0x268) = one;
    ((void (**)(void *))(*(void ***)arg0))[19](arg0);
}

extern "C" void fn_80229DE8(void *arg0, s32 unused, s32 arg2) {
    register u32 zero = 0;
    register u32 one = 1;
    s32 start = *(s32 *)((u8 *)arg0 + 8);
    *(u32 *)((u8 *)arg0 + 0x260) = zero;
    s32 end = *(s32 *)((u8 *)arg0 + 0x10);
    *(u8 *)((u8 *)arg0 + 0x268) = one;
    ((void (**)(void *, s32))(*(void ***)arg0))[19](arg0, arg2 - (end - start) - 3);
}

extern s32 fn_8021E1C8(void *, s32, s32);
extern "C" void fn_80229E1C(void *arg0, s32 unused, s32 arg2) {
    s32 start = *(s32 *)((u8 *)arg0 + 8);
    s32 end = *(s32 *)((u8 *)arg0 + 0x10);
    fn_8021E1C8(arg0, unused, arg2 - (end - start) - 3);
}

extern "C" void fn_80229E34(void *arg0) {
    s32 *data = *(s32 **)((u8 *)arg0 + 0x248);
    s32 value = data[2] + 1;
    data[2] = value;
    s32 limit = data[0] - data[1];
    if (value > limit) {
        data[2] = limit;
    }
    if (data[2] < 0) {
        data[2] = 0;
    }
}

extern "C" void fn_80229E74(void *arg0) {
    s32 *data = *(s32 **)((u8 *)arg0 + 0x248);
    s32 value = data[2] - 1;
    data[2] = value;
    s32 limit = data[0] - data[1];
    if (value > limit) {
        data[2] = limit;
    }
    if (data[2] < 0) {
        data[2] = 0;
    }
}

extern "C" u32 fn_80229EC4(void) { return 1; }

extern "C" u32 fn_80229ECC(void) { return 1; }

extern "C" void fn_80229ED4(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_80229EF4(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" void fn_80229F38(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x18) = 0;
    if ((s32)*(u8 *)((u8 *)arg0 + 0x1A) != 0) {
        *(u8 *)((u8 *)arg0 + 0x234) = 1;
    }
}

extern "C" s32 fn_80229F58(s32);
extern "C" s32 fn_80229F58(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" void fn_8022A014(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 1;
}

extern "C" void fn_8022A034(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
}

extern "C" void *__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8022A0CC(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_8021915C(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" s32 fn_80229CA4(s32);
extern "C" s32 fn_80229C9C(s32);
extern "C" void fn_80229CB4(void *);
extern "C" void fn_80229CD8(void *);
extern void fn_80219044(void *);

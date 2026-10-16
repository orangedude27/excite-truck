#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_80140A6C(void);
extern "C" u8 *fn_8017960C(s32);
extern "C" u32 fn_8013D148(u8 *, f32);
extern "C" void *fn_802C6C34(s32);

// user virtuals start at vtable offset 0x8 (two destructor slots first)
class TObj4C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16();
    virtual void v4C(); // 0x4C
};

class TObj24 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual u8 v24(); // 0x24
};

class TObj10 {
public:
    virtual void d0(); virtual void d1();
    virtual u8 *v10(); // 0x10
};

class TObjC {
public:
    virtual void d0();
    virtual s32 vC(s32); // 0xC
};

extern "C" void fn_8013E338(void) {

}

extern "C" void fn_8013F09C(void) {
    ((void(*)())fn_80140A6C)();
}

extern "C" void fn_8013F434(void) {

}

extern "C" void fn_80141454(void) {

}

extern "C" void fn_80141C84(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C;
    *(s32 *)(p + 0x88) = *(s32 *)(p + 0x10C);
}

extern "C" double floor(double);
extern "C" f32 lbl_805614AC;
extern "C" f32 fn_80141C9C(f32 arg0) {
    return floor(arg0);
}

extern "C" s32 fn_80141E90(f32 *arg0, f32 arg1) {
    return arg1 - *arg0 >= lbl_805614AC;
}

extern "C" void *fn_80141EB0(s32 *arg0) {
    s32 count = arg0[1];
    void *result;
    if ((count + (arg0[2] - arg0[3])) % count <= 0) {
        result = 0;
    } else {
        result = (void *)(arg0[0] + ((count + ((volatile s32 *)arg0)[3]) % count) * 12);
    }
    if (result != 0) {
        arg0[3] = (((volatile s32 *)arg0)[3] + 1) % ((volatile s32 *)arg0)[1];
    }
    return result;
}

extern "C" u8 *fn_8017960C(s32);
extern "C" u32 fn_8013D148(u8 *, f32);
extern "C" void *fn_802C6C34(s32);
extern "C" u8 *fn_80142C9C(u8 *arg0, s32 arg1) {
    u8 *data = *(u8 **)(arg0 + 0x64) + 4;
    s32 index = *(s32 *)(arg0 + 0x68);
    u8 *item = data + index * 0x14;
    u8 *manager = fn_8017960C(arg1);
    u8 *obj = *(u8 **)(manager + 0x270);
    obj = *(u8 **)(*(u8 **)obj + 0x18);
    u32 result = fn_8013D148(item, *(f32 *)(obj + 0x48));
    s32 value = *(s32 *)item;
    u8 *end = *(u8 **)(data + value + 4) + value * 0x24;
    if (result != (u32)(end - 0x24))
        end = (u8 *)result + 0x24;
    return end;
}

extern "C" s32 fn_80142D34(void) { return 0; }

extern "C" u8 *fn_801B2EC0(s32);

extern "C" void fn_80143128(u8 *arg0) {
    ((TObj4C *)arg0)->v4C();
}

#pragma use_lmw_stmw off

extern "C" void fn_80143138(u8 *self, u8 *out) {
    *(s32 *)out = *(s32 *)(self + 0xBC);
    *(s32 *)(out + 4) = *(s32 *)(self + 0x130);
    *(u8 *)(out + 0xD) = ((TObj24 *)self)->v24();
    u8 *p = out + 0x10;
    *(u8 *)(out + 0xC) = 0;
    s32 off = 0;
    s32 i = 0;
    while (i < *(s32 *)(self + 0xBC)) {
        *(u8 *)(p + 0x10) = 0;
        u8 *q = ((TObj10 *)fn_801B2EC0(i))->v10();
        i++;
        *(s32 *)(p + 4) = *(s32 *)(q + 4);
        *(s32 *)(p + 8) = *(s32 *)(*(u8 **)(self + 0xB8) + off + 0x10C);
        off += 0x12C;
        p += 0x14;
    }
}

extern "C" void fn_801431F4(u8 *arg0) {
    *(u8 *)(arg0 + 0x26C) = 1;
}

extern "C" void fn_80143200(u8 *arg0) {
    *(u8 *)(arg0 + 0x26C) = 0;
}

extern "C" s32 fn_8014320C(void) {
    return 0x1008;
}

extern "C" void fn_8013D288(void);

extern "C" void fn_80143214(void) {
    fn_8013D288();
}

extern "C" void fn_801352B8(void *);
extern "C" void fn_80135D60(void *, s32);
extern "C" s32 fn_80156A40(void);
extern "C" void fn_801B8048(void *, void *, void *, f32, f32);
extern "C" void fn_8013530C(void *, s32, f32, f32, f32);
extern "C" f32 lbl_805614A4;
extern "C" f32 lbl_805615A0;
extern "C" f32 lbl_805615A4;
extern "C" f32 lbl_805615A8;
extern "C" s32 fn_80143218(s32 arg0, u8 *arg1) {
    u8 obj[0x38];
    fn_801352B8(obj);
    fn_80135D60(obj, ((TObjC *)fn_80156A40())->vC(0));
    u8 *v = *(u8 **)(obj + 0x2C);
    fn_801B8048(arg1, obj, v, lbl_805614A4,
                (*(f32 *)(v + 8) - lbl_805615A0) - lbl_805615A4);
    f32 fx = *(f32 *)(arg1 + 0x18) * lbl_805615A8;
    f32 fy = *(f32 *)(arg1 + 0x1C) * lbl_805615A8;
    f32 fz = *(f32 *)(arg1 + 0x20) * lbl_805615A8;
    *(f32 *)(arg1 + 0x30) = fx;
    *(f32 *)(arg1 + 0x34) = fy;
    *(s32 *)(arg1 + 0x44) = 1;
    *(f32 *)(arg1 + 0x38) = fz;
    fn_8013530C(obj, -1, fy, fx, lbl_805615A8);
    return 1;
}

extern "C" u32 fn_80143C4C(void) { return 1; }

extern "C" void fn_801442FC(void) {
}

extern "C" void fn_80144300(void) {
}

extern "C" void fn_80144308(void) {
}

extern "C" void fn_80144304(void) {
}

extern "C" void fn_8014430C(void) {
}

extern "C" void fn_80144310(void) {
}

extern "C" void fn_80144334(void) {
}

extern "C" void fn_80144338(void) {
}

extern "C" void fn_8014433C(void) {
}

extern "C" void fn_80144340(void) {
}

extern "C" void fn_8014434C(void) {
}

extern "C" void fn_80144358(void) {
}

extern "C" u32 fn_8014435C(void) { return 1; }

extern "C" u32 fn_801443E8(void) { return 1; }

extern "C" void fn_80144408(void) {

}


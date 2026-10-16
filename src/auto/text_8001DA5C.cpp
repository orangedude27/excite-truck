#include <types.h>
#include <math.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern f32 lbl_8055E3C8;
extern f32 lbl_80560470;
extern f32 lbl_80560474;
extern f32 lbl_80560490;

extern "C" s32 fn_80128668(void);
extern void* lbl_80358680[];

class CollisionEntry {
public:
    virtual void unk0();
    virtual void apply(s32, s32);
};
extern s32 lbl_8055E3C4;
extern f32 lbl_80560460;
extern f32 lbl_80560464;
extern f64 lbl_80560468;
f32 fn_8001DA5C(s32 arg0) {
    f64 bias = lbl_80560468;
    f64 angle;
    f64 fraction;
    s32 quotient = lbl_8055E3C4 / arg0;
    s32 remainder;
    union { f64 d; u32 words[2]; } angle_bits;
    union { f64 d; u32 words[2]; } fraction_bits;
    union { f64 d; u32 words[2]; } integer_bits;
    integer_bits.words[0] = 0x43300000;
    integer_bits.words[1] = arg0 ^ 0x8000;
    angle = integer_bits.d - bias;
    remainder = lbl_8055E3C4 - quotient * arg0;
    fraction_bits.words[0] = 0x43300000;
    fraction_bits.words[1] = remainder ^ 0x8000;
    fraction = fraction_bits.d - bias;
    return lbl_80560464 + lbl_80560464 * (f32)sin((f64)(lbl_80560460 * fraction / angle));
}

extern "C" void fn_8001DAD8(void) { extern int fn_8001DA5C(int); fn_8001DA5C(0x40); }

extern "C" f32 fn_8001DAE8(void) {
    return lbl_8055E3C8;
}

extern "C" s32 fn_8001DD2C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8001DEA8(void) {
    u32 var_r30;
    void ***var_r31;
    
    var_r31 = (void ***)lbl_80358680;
    var_r30 = 0;
    do {
        void **temp = var_r31[0];
        ((void (**)(void *))temp)[4](temp);
        var_r30++;
        var_r31++;
    } while (var_r30 < 6);
}

void fn_8001DF04(void) {

}

extern "C" void fn_8001DF08(s32 arg0, s32 arg1) {
    ((CollisionEntry*)lbl_80358680[0])->apply(arg0, arg1);
    ((CollisionEntry*)lbl_80358680[2])->apply(arg0, arg1);
}

extern "C" void fn_8001DF84(s32 arg0) {
    void* p = lbl_80358680[1];
    ((CollisionEntry*)p)->apply(arg0, 0);
}

extern "C" void fn_8001DFA8(s32 arg0) {
    void* obj = ((void**)&lbl_80358680)[3];
    ((void (**)(void*, s32, s32))*(void**)obj)[3](obj, arg0, 0);
}
#pragma scheduling reset
extern "C" void fn_8001DFCC(void) {
    ((CollisionEntry*)lbl_80358680[4])->apply(9, 17);
}

extern "C" void fn_8001DFF0(void) {
    ((CollisionEntry*)lbl_80358680[5])->apply(0, 0);
}

extern "C" void fn_802CAC54(void*);
extern "C" int lbl_802FDC98[];
extern "C" void* __dt__14CollisionSpaceFv(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_802FDC98;
        fn_802CAC54(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_8001E26C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" f32 fn_8001DA5C(s32);
extern f32 lbl_80560490;
extern "C" void fn_8001E544(void* arg0) {
    f32 b = lbl_80560474;
    f32 a = lbl_80560490;
    ((f32*)arg0)[1] = a;
    ((f32*)arg0)[2] = b;
    ((f32*)arg0)[3] = b;
    ((f32*)arg0)[4] = a;
    ((f32*)arg0)[5] = b;
    ((f32*)arg0)[6] = b;
    ((f32*)arg0)[7] = a;
    ((f32*)arg0)[8] = b;
    ((f32*)arg0)[9] = b;
    ((f32*)arg0)[10] = a;
    ((f32*)arg0)[11] = b;
    ((f32*)arg0)[12] = b;
    ((f32*)arg0)[13] = a;
    ((f32*)arg0)[14] = b;
    ((f32*)arg0)[15] = b;
    ((f32*)arg0)[16] = a;
    ((f32*)arg0)[17] = b;
    ((f32*)arg0)[18] = b;
    ((f32*)arg0)[19] = a;
    ((f32*)arg0)[20] = b;
    ((f32*)arg0)[21] = b;
    ((f32*)arg0)[22] = a;
    ((f32*)arg0)[23] = b;
    ((f32*)arg0)[24] = b;
}

extern s32 lbl_802FDC70;
extern "C" void* fn_8001E5B0(void* arg0, s32 arg1) {
    void* entry;
    if (arg0 != 0) {
        entry = *(void**)((u8*)arg0 + 0x24);
        *(void**)arg0 = &lbl_802FDC70;
        if (entry != 0) {
            ((void (**)(void*, s32))(*(void***)entry))[1](entry, 1);
        }
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8001E964(void* arg0) {
    f32 value = lbl_80560490;
    *(f32*)((u8*)arg0 + 0x34) = value;
    *(f32*)((u8*)arg0 + 0x2C) = value;
}

extern "C" s32 fn_8001E974(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8001ED2C(void* arg0) {
    f32 value = lbl_80560490;
    *(s32*)((u8*)arg0 + 0x04) = 0;
    *(f32*)((u8*)arg0 + 0x08) = value;
    *(s32*)((u8*)arg0 + 0x0C) = 0;
    *(f32*)((u8*)arg0 + 0x10) = value;
    *(s32*)((u8*)arg0 + 0x14) = 0;
    *(f32*)((u8*)arg0 + 0x18) = value;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(f32*)((u8*)arg0 + 0x20) = value;
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(f32*)((u8*)arg0 + 0x28) = value;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *(f32*)((u8*)arg0 + 0x30) = value;
    *(s32*)((u8*)arg0 + 0x34) = 0;
    *(f32*)((u8*)arg0 + 0x38) = value;
    *(s32*)((u8*)arg0 + 0x3C) = 0;
    *(f32*)((u8*)arg0 + 0x40) = value;
}

extern "C" s32 fn_8001ED78(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801E85A4(void);
extern "C" void fn_801476C4(void);
extern "C" void* lbl_802FDE38;
extern "C" void* lbl_802FDE48;
extern "C" void* lbl_802FDE54;
extern "C" void** lbl_8055D5FC;
extern "C" void** lbl_8055D600;
extern "C" void fn_8001EDB8(void) {
    void* object = &lbl_802FDE38;
    void** selected;
    if (fn_801E85A4() == 2) {
        selected = lbl_8055D600;
    } else {
        selected = lbl_8055D5FC;
    }
    ((void (*)(void*, void*))(*(void***)*selected)[3])(*selected, object);
    fn_801476C4();
}

extern "C" s32 fn_8001EE14(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8001EE54(void) {
    void* object = &lbl_802FDE48;
    void** selected;
    if (fn_801E85A4() == 2) {
        selected = lbl_8055D600;
    } else {
        selected = lbl_8055D5FC;
    }
    ((void (*)(void*, void*))(*(void***)*selected)[3])(*selected, object);
    fn_801476C4();

    object = &lbl_802FDE54;
    if (fn_801E85A4() == 2) {
        selected = lbl_8055D600;
    } else {
        selected = lbl_8055D5FC;
    }
    ((void (*)(void*, void*))(*(void***)*selected)[3])(*selected, object);
    fn_801476C4();
}


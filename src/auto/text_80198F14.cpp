// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern int lbl_80333918[64];
extern "C" s32 fn_8019D618(void*, void*, s32, void*);
extern "C" char lbl_80333640[];
extern "C" void* fn_801284F8(s32, const char*);
extern "C" void fn_801A0378(void*, void*);
extern "C" void fn_801A1F44(void*, void*);
extern "C" s32 fn_8019C854(void*, void*);
#include <revolution/MTX/vec.h>

static inline void fn801A1F98Transform(volatile f32 *dst, volatile f32 *src, f32 *matrix) {
    f32 x = src[0];
    f32 y = src[1];
    f32 z = src[2];
    if (dst == src) {
        dst[0] = (x * matrix[0] + y * matrix[3]) + z * matrix[6];
        dst[1] = (x * matrix[1] + y * matrix[4]) + z * matrix[7];
        dst[2] = (x * matrix[2] + y * matrix[5]) + z * matrix[8];
    } else {
        dst[0] = (y * matrix[3] + x * matrix[0]) + z * matrix[6];
        dst[1] = (y * matrix[4] + x * matrix[1]) + z * matrix[7];
        dst[2] = (y * matrix[5] + x * matrix[2]) + z * matrix[8];
    }
}
static inline void fn801A1F98Transform(volatile f32 *dst, volatile f32 *compare, volatile f32 *src, f32 *matrix) {
    f32 x = src[0];
    f32 y = src[1];
    f32 z = src[2];
    if (dst == compare) {
        dst[0] = (x * matrix[0] + y * matrix[3]) + z * matrix[6];
        dst[1] = (x * matrix[1] + y * matrix[4]) + z * matrix[7];
        dst[2] = (x * matrix[2] + y * matrix[5]) + z * matrix[8];
    } else {
        dst[0] = (y * matrix[3] + x * matrix[0]) + z * matrix[6];
        dst[1] = (y * matrix[4] + x * matrix[1]) + z * matrix[7];
        dst[2] = (y * matrix[5] + x * matrix[2]) + z * matrix[8];
    }
}
class VTab1A1E7C {
 public:
 virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
 virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
 virtual void v15(); virtual void v16(); virtual void v17();
 virtual void *Call();
};
class Fn801A401CDispatch {
public:
    virtual void v0(); virtual void v1();
    virtual void Call(void*);
};
class Fn801A4A8CVTable {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void Call(void *, s32, s32);
};
class Fn801A014CDispatch {
public:
    virtual void Dummy0();
    virtual void Call();
};
class Fn8019EA7CDispatch {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual void* Get();
};

#pragma opt_tail_call on
__declspec(section ".data") extern f32 lbl_80558DC4;
extern f32 lbl_805622DC;
extern f32 lbl_805622E8;
extern f32 lbl_805622E0;
extern f32 lbl_805622D0;
extern f32 lbl_8056231C, lbl_80562320, lbl_80562324, lbl_80562328, lbl_80562330, lbl_805622D4, lbl_8056232C;
extern s32 lbl_8055E5A0;
extern "C" s32 fn_801CF080(s32, void*, void*, s32*, s32, f32);
extern "C" void fn_8019A820(void*, void*, s32, s32, s32, f32);
extern "C" s32 fn_801E9F08(void*, void*, void*, s32, s32, f32);
extern "C" void fn_8017B4AC(void*, Vec*);
extern "C" f32 fn_8019DF88(void*, f32*, void*, f32*, f32*, f32, f32);
extern "C" void fn_801B34DC(void*, s32, Vec*, Vec*, Vec*, s32);
extern "C" f32 PSVECMag(const Vec*);
extern "C" f32 PSVECDotProduct(const Vec*, const Vec*);
extern "C" void fn_8017B6D4(s32, Vec*, s32);
extern "C" void fn_8019AC44(void*, void*, void*, f32);
inline void fn_8019AC44_compat(f32* a, f32* b, f32 c) {}
static inline void fn_8019AC44_3(f32* a, f32* b, f32 c) {}
extern char lbl_803339B8[];
extern void fn_8019F03C();
extern "C" s32 fn_8019DDFC(s32, s32, s32, s32, void*, void*, f32);
extern "C" f64 fn_8002F234(f32);
extern "C" void fn_8019ECC4(void);
extern char lbl_80333B48[];
extern f32 lbl_80562370;
extern f32 lbl_8056232C;
extern "C" void** fn_801B83A0(void);
extern "C" f32 fn_8018AE7C(void*);
extern "C" void fn_802C1A0C(void**, s32);

extern "C" void fn_8019CE4C(void*, void*);
extern "C" void fn_8019BD54(void*, void*, s32, s32);
extern "C" void fn_8019D06C(void*, void*, s32, s32);
extern "C" void fn_8019B068(void*, void*, s32, s32);
extern "C" void fn_8019CE3C(void*, s32);
extern "C" void fn_802E317C(const char*, ...);
__declspec(section ".sdata") extern char lbl_8055A4C4[];
extern "C" const char lbl_803335EC[];
extern void fn_801EA1E0(s32, s32, f32, f32);
extern "C" void fn_8019EBC0(void*);
extern "C" void fn_8019F3D0(void);
extern "C" void fn_801A49E8(void*);
extern "C" void fn_801A49FC(s32);
extern "C" void fn_801796EC(s32, s32*, s32);
extern "C" s32 fn_8012C4E4(void*, void*, s32);
extern "C" s32 fn_801CFF18(s32, s32);
extern "C" void fn_801D0650(void);
extern "C" void fn_801CFF14(void);
extern "C" s32 fn_801CF828(s32, s32, s32, s32, s32);
extern s32 lbl_8055E5A0;
extern "C" s32 fn_801CFEAC(void*);
extern s32 lbl_803336EC[];
extern "C" void fn_801A48E4(void*);
extern "C" void fn_801D2414(...);
extern "C" void fn_801D0738(void*, void*, void*, void*);
#pragma push
#pragma small_data off
extern char lbl_803336F8[];
#pragma pop

class VTab19 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void slot0x4C();
};

class VTab12C4 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
};
class VTab1250 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
};

class VTab13 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual void slot0x34(s32);
};
class Fn80199894VTab1C {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void Call(f32*, f32*, s32, void*);
};
class Fn80199894VTab1CWide {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void Call(f32*, f32*, s32, void*, f32, f32, f32);
};
class Fn80199894VTab20 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void Call(void*, f32*, f32*, s32, f32*, void*, f32);
};
class Fn80199894VTab20Wide {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void Call(void*, f32*, f32*, s32, f32*, void*, f32, f32, f32, f32);
};
class Fn80199894GlobalVTab {
public:
    virtual void v0();     virtual void v1();     virtual void v2();     virtual void v3();
    virtual void v4();     virtual void v5();     virtual void v6();     virtual void v7();
    virtual void v8();     virtual void v9();     virtual void v10();     virtual void v11();
    virtual void v12();     virtual void v13();     virtual void v14();     virtual void v15();
    virtual void v16();     virtual void v17();     virtual void v18();     virtual void v19();
    virtual void v20();     virtual void v21();     virtual void v22();     virtual void v23();
    virtual void v24();     virtual void v25();     virtual void v26();     virtual void v27();
    virtual void v28();     virtual void v29();     virtual void v30();     virtual void v31();
    virtual void v32();     virtual void v33();     virtual void v34();     virtual void v35();
    virtual void v36();
    virtual void Call(void*, s32, void*);
};
class Fn80199894TempVTab {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual s32 Get();
    virtual void Set(s32);
};
class Fn80199894VTab30Getter {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void** Get();
};
class Fn80199894VTab30With {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void** Get(f32, f32);
};

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801A4A10(s32, s32, s32, s32 = 0);
  extern "C" void fn_801A44D4(void*);
extern void* lbl_8055A508;
extern void* lbl_8055A510;

void fn_8019F1A4(void) __attribute__((noreturn));

extern "C" s32 fn_80128668(void);
extern "C" void fn_801A5C4C(void*);
extern "C" void fn_8017B6D4(s32, Vec*, s32);
extern f32 lbl_805622D0, lbl_805622E4, lbl_805622E8;
extern "C" f32 PSVECMag(const Vec*);
#pragma dont_inline on
extern "C" void* __dt__Q36PSGame10SoundTable11CategoryMgrFv(void* arg0, s32 arg1) {
    if (arg0 != NULL) {
        if (arg0 != NULL) {
            *(u32*)arg0 = 0;
        }
        if (arg1 > 0) {
            ((void (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_801996BC(Vec* arg0, s32 arg1, Vec* arg2, void* arg3, void* arg4, f32 farg0) {
    Vec a, b, d, p;
    f32 dot, mag, limit;
    if (*(s32*)((u8*)arg3+4)) fn_8017B6D4(*(s32*)((u8*)arg3+4), &a, arg1);
    else a.x=a.y=a.z=lbl_805622D0;
    if (*(s32*)((u8*)arg4+4)) fn_8017B6D4(*(s32*)((u8*)arg4+4), &b, arg1);
    else b.x=b.y=b.z=lbl_805622D0;
    d.x=a.x-b.x; d.y=a.y-b.y; d.z=a.z-b.z;
    dot=PSVECDotProduct(arg2,&d);
    p.x=(d.x-arg2->x*dot)*lbl_805622E4;
    p.y=(d.y-arg2->y*dot)*lbl_805622E4;
    p.z=(d.z-arg2->z*dot)*lbl_805622E4;
    mag=PSVECMag(&p);
    limit=lbl_805622E8*farg0*(*(f32*)((u8*)arg3+0x14)+*(f32*)((u8*)arg4+0x14));
    if (mag>limit) { f32 s=limit/mag; p.x*=s; p.y*=s; p.z*=s; }
    *arg0=p;
}
#pragma dont_inline reset

#pragma dont_inline on
extern "C" void fn_80199870(void* arg0) {
    u32 value = *(u32*)((u8*)arg0 + 0x10);
    if ((u32)(value - 0x50430000) == 0x4152 ||
        (u32)(value - 0x41430000) == 0x4152) {
        fn_801A5C4C(arg0);
    }
}
#pragma dont_inline reset

extern f32 lbl_805622D0, lbl_805622D4, lbl_805622DC, lbl_805622E0, lbl_805622E8, lbl_805622EC, lbl_805622F0, lbl_805622F4, lbl_805622F8, lbl_805622FC, lbl_80562300, lbl_80562304, lbl_80562308, lbl_8056230C, lbl_80562310;
extern f32 fn_8018AE7C(void*);
extern void **fn_801B83A0();
extern void fn_802C1A0C(void**, s32);
extern "C" f32 __fabsf(f32);
#pragma dont_inline on
extern "C" void **fn_801B83A0();
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_80199894(void *arg0, void *arg1, void *arg2_raw, void *arg3_raw, s32 arg4_raw, s32 arg5_raw, f32 farg0, f32 farg1, f32 farg2) {
    f32 stackStorage[80];
    f32 *sp = stackStorage;
    void *temp_r31;
    void *temp_r30;
    void *temp_r29;
    void *temp_r28;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    volatile f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f10;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    volatile f32 temp_f27;
    f32 temp_f27_2;
    f32 temp_f27_3;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f2_10;
    f32 temp_f2_11;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f2_8;
    f32 temp_f2_9;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f3_6;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f5;
    volatile f32 temp_f5_2;
    volatile f32 temp_f7;
    f32 temp_f7_2;
    volatile f32 temp_f8;
    f32 temp_f8_2;
    volatile f32 temp_f9;
    f32 temp_f9_2;
    f32 var_f1;
    f32 var_f1_2;
    volatile f32 var_f28;
    f32 var_f29;
    f32 var_f2;
    f32 var_f30;
    f32 var_f3;
    f32 var_f4;
    f32 var_f5;
    s32 temp_cr0_eq;
    s32 temp_cr0_eq_2;
    s32 temp_cr0_gt;
    s32 temp_r27;
    s32 temp_r26;
    s32 temp_r27_2;
    s32 temp_r30_2;
    s32 temp_r3_2;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r4;
    void **temp_r3;

    temp_r26 = (*(s32 *)((u8 *)(arg1) + (0x20)));
    temp_r27 = (*(s32 *)((u8 *)(arg0) + (0x20)));
    temp_r31 = (*(void **)((u8 *)(arg0) + (0xC)));
    temp_r30 = (*(void **)((u8 *)(arg1) + (0xC)));
    temp_r29 = (*(void **)((u8 *)(arg0) + (4)));
    temp_r28 = (*(void **)((u8 *)(arg1) + (4)));
    if (temp_r26 == 0x3EA) {
        fn_80199870(temp_r29);
        return;
    }
    if (temp_r26 >= 0x3E8) {
        if (temp_r29 != NULL) {
            temp_r4 = (*(s32 *)((u8 *)temp_r29 + 0x10));
            switch (temp_r4) {
            case 0x4E434152:
            case 0x43415220:
            case 0x41434152:
            case 0x50434152:
                var_r0 = 1;
                break;
            default:
                var_r0 = 0;
                break;
            }
            if (var_r0 != 0) {
                ((Fn80199894GlobalVTab *)fn_801B83A0())->Call(temp_r29, temp_r26, arg1);
            }
        }
    }
    if ((temp_r26 >= 0x3E8) || (temp_r27 >= 0x3E8)) {
        sp[1] = lbl_805622D0;
        sp[2] = lbl_805622D0;
        sp[3] = lbl_805622D0;
        ((Fn80199894VTab1C *)arg0)->Call((f32 *)&sp[1], ((f32 *)arg2_raw), temp_r26, temp_r28);
        sp[7] = lbl_805622D0;
        sp[8] = lbl_805622D0;
        sp[9] = lbl_805622D0;
        ((Fn80199894VTab1C *)arg1)->Call((f32 *)&sp[7], ((f32 *)arg2_raw), temp_r27, temp_r29);
        sp[4] = lbl_805622D0;
        sp[5] = lbl_805622D0;
        sp[6] = lbl_805622D0;
        ((Fn80199894VTab20 *)arg1)->Call(arg0, (f32 *)&sp[4], ((f32 *)arg2_raw), temp_r26, ((f32 *)arg2_raw), temp_r29, lbl_805622D4);
        sp[1] = lbl_805622D0;
        sp[2] = lbl_805622D0;
        sp[3] = lbl_805622D0;
        ((Fn80199894VTab20 *)arg0)->Call(arg1, (f32 *)&sp[1], ((f32 *)arg2_raw), temp_r27, ((f32 *)arg2_raw), temp_r28, lbl_805622D4);
        return;
    }
    temp_f2 = (*(f32 *)((u8 *)(((f32 *)arg2_raw)) + (0)));
    temp_f1 = (*(f32 *)((u8 *)(((f32 *)arg2_raw)) + (4)));
    temp_f0 = (*(f32 *)((u8 *)(((f32 *)arg2_raw)) + (8)));
    sp[76] = temp_f2;
    sp[77] = temp_f1;
    sp[78] = temp_f0;
    sp[73] = temp_f2;
    sp[74] = temp_f1;
    sp[75] = temp_f0;
    if ((temp_r29 != NULL) && (temp_r28 != NULL)) {
        var_f3 = lbl_805622EC;
        temp_f0_2 = (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + (0xC)))) + (0x28))) - temp_f1;
        if (var_f3 < temp_f0_2) {
            var_f3 = temp_f0_2;
        }
        if (var_f3 > lbl_805622F0) {
            var_f3 = lbl_805622F0;
        }
        var_f4 = lbl_805622EC;
        temp_f0_3 = (*(f32 *)((u8 *)((*(void **)((u8 *)(arg1) + (0xC)))) + (0x28))) - (*(f32 *)((u8 *)(((f32 *)arg2_raw)) + (4)));
        if (var_f4 < temp_f0_3) {
            var_f4 = temp_f0_3;
        }
        if (var_f4 > lbl_805622F0) {
            var_f4 = lbl_805622F0;
        }
        temp_f2_2 = (*(f32 *)((u8 *)(((f32 *)arg2_raw)) + (4)));
        sp[77] = temp_f2_2 + (lbl_805622F4 * var_f3);
        sp[74] = temp_f2_2 + (lbl_805622F4 * var_f4);
    }
    if (temp_r29 != NULL) {
        fn_8017B6D4((s32)temp_r29, (Vec*)(f32 *)&sp[67], (s32)((f32 *)arg2_raw));
    } else {
        sp[67] = lbl_805622D0;
        sp[68] = lbl_805622D0;
        sp[69] = lbl_805622D0;
    }
    if (temp_r28 != NULL) {
        fn_8017B6D4((s32)temp_r28, (Vec*)(f32 *)&sp[64], (s32)((f32 *)arg2_raw));
    } else {
        sp[64] = lbl_805622D0;
        sp[65] = lbl_805622D0;
        sp[66] = lbl_805622D0;
    }
    temp_f4 = sp[67] - sp[64];
    temp_f2_3 = sp[68] - sp[65];
    sp[61] = temp_f4;
    sp[62] = temp_f2_3;
    sp[63] = sp[69] - sp[66];
    temp_f1_2 = PSVECDotProduct((const Vec*)(f32 *)&sp[61], (const Vec*)((f32 *)arg3_raw));
    temp_f0_4 = (*(f32 *)((u8 *)(arg1) + (0x10)));
    temp_f31 = temp_f1_2;
    var_f2 = (*(f32 *)((u8 *)(arg0) + (0x10)));
    if (var_f2 > temp_f0_4) {

    } else {
        var_f2 = temp_f0_4;
    }
    if (temp_f1_2 > lbl_805622D0) {
        var_f2 *= lbl_805622F8;
    }
    var_f1 = farg0 * var_f2;
    if (var_f1 > lbl_805622FC) {
        var_f1 = lbl_805622FC;
    }
    temp_f5 = lbl_805622E8 * var_f1;
    temp_f4_2 = (*(f32 *)((u8 *)(((f32 *)arg3_raw)) + (0))) * temp_f5;
    temp_f3 = (*(f32 *)((u8 *)(((f32 *)arg3_raw)) + (4))) * temp_f5;
    sp[58] = lbl_805622D0;
    temp_f2_4 = (*(f32 *)((u8 *)(((f32 *)arg3_raw)) + (8))) * temp_f5;
    sp[70] = temp_f4_2;
    sp[71] = temp_f3;
    sp[72] = temp_f2_4;
    sp[59] = lbl_805622D0;
    sp[60] = lbl_805622D0;
    fn_801996BC((Vec*)(f32 *)&sp[58], (s32)((f32 *)arg2_raw), (Vec*)((f32 *)arg3_raw), arg0, arg1, var_f1);
    sp[71] += sp[59];
    temp_f3_2 = (*(f32 *)((u8 *)(((f32 *)arg2_raw)) + (0)));
    sp[72] += sp[60];
    temp_f2_5 = (*(f32 *)((u8 *)(((f32 *)arg2_raw)) + (4)));
    sp[70] += sp[58];
    temp_f1_3 = (*(f32 *)((u8 *)(((f32 *)arg2_raw)) + (8)));
    sp[55] = temp_f3_2 - (*(f32 *)((u8 *)(temp_r31) + (0x24)));
    sp[56] = temp_f2_5 - (*(f32 *)((u8 *)(temp_r31) + (0x28)));
    sp[57] = temp_f1_3 - (*(f32 *)((u8 *)(temp_r31) + (0x2C)));
    sp[52] = temp_f3_2 - (*(f32 *)((u8 *)(temp_r30) + (0x24)));
    sp[53] = temp_f2_5 - (*(f32 *)((u8 *)(temp_r30) + (0x28)));
    sp[54] = temp_f1_3 - (*(f32 *)((u8 *)(temp_r30) + (0x2C)));
    if (temp_f31 < lbl_805622D0) {
        PSVECCrossProduct((const Vec*)(f32 *)&sp[55], (const Vec*)((f32 *)arg3_raw), (Vec*)(f32 *)&sp[46]);
        PSVECCrossProduct((const Vec*)(f32 *)&sp[52], (const Vec*)((f32 *)arg3_raw), (Vec*)(f32 *)&sp[43]);
        if (temp_r29 != NULL) {
            if ((f32 *)&sp[40] == (f32 *)&sp[46]) {
                sp[40] = (sp[48] * (*(f32 *)((u8 *)(temp_r29) + (0x160)))) + ((sp[46] * (*(f32 *)((u8 *)(temp_r29) + (0x148)))) + (sp[47] * (*(f32 *)((u8 *)(temp_r29) + (0x154)))));
                sp[41] = (sp[48] * (*(f32 *)((u8 *)(temp_r29) + (0x164)))) + ((sp[46] * (*(f32 *)((u8 *)(temp_r29) + (0x14C)))) + (sp[47] * (*(f32 *)((u8 *)(temp_r29) + (0x158)))));
                sp[42] = (sp[48] * (*(f32 *)((u8 *)(temp_r29) + (0x168)))) + ((sp[46] * (*(f32 *)((u8 *)(temp_r29) + (0x150)))) + (sp[47] * (*(f32 *)((u8 *)(temp_r29) + (0x15C)))));
            } else {
                sp[40] = (sp[48] * (*(f32 *)((u8 *)(temp_r29) + (0x160)))) + ((sp[46] * (*(f32 *)((u8 *)(temp_r29) + (0x148)))) + (sp[47] * (*(f32 *)((u8 *)(temp_r29) + (0x154)))));
                sp[41] = (sp[48] * (*(f32 *)((u8 *)(temp_r29) + (0x164)))) + ((sp[46] * (*(f32 *)((u8 *)(temp_r29) + (0x14C)))) + (sp[47] * (*(f32 *)((u8 *)(temp_r29) + (0x158)))));
                sp[42] = (sp[48] * (*(f32 *)((u8 *)(temp_r29) + (0x168)))) + ((sp[46] * (*(f32 *)((u8 *)(temp_r29) + (0x150)))) + (sp[47] * (*(f32 *)((u8 *)(temp_r29) + (0x15C)))));
            }
        } else {
            sp[40] = lbl_805622D0;
            sp[41] = lbl_805622D0;
            sp[42] = lbl_805622D0;
        }
        PSVECCrossProduct((const Vec*)(f32 *)&sp[40], (const Vec*)(f32 *)&sp[55], (Vec*)(f32 *)&sp[34]);
        if (temp_r28 != NULL) {
            if ((f32 *)&sp[37] == (f32 *)&sp[43]) {
                sp[37] = (sp[45] * (*(f32 *)((u8 *)(temp_r28) + (0x160)))) + ((sp[43] * (*(f32 *)((u8 *)(temp_r28) + (0x148)))) + (sp[44] * (*(f32 *)((u8 *)(temp_r28) + (0x154)))));
                sp[38] = (sp[45] * (*(f32 *)((u8 *)(temp_r28) + (0x164)))) + ((sp[43] * (*(f32 *)((u8 *)(temp_r28) + (0x14C)))) + (sp[44] * (*(f32 *)((u8 *)(temp_r28) + (0x158)))));
                sp[39] = (sp[45] * (*(f32 *)((u8 *)(temp_r28) + (0x168)))) + ((sp[43] * (*(f32 *)((u8 *)(temp_r28) + (0x150)))) + (sp[44] * (*(f32 *)((u8 *)(temp_r28) + (0x15C)))));
            } else {
                sp[37] = (sp[45] * (*(f32 *)((u8 *)(temp_r28) + (0x160)))) + ((sp[43] * (*(f32 *)((u8 *)(temp_r28) + (0x148)))) + (sp[44] * (*(f32 *)((u8 *)(temp_r28) + (0x154)))));
                sp[38] = (sp[45] * (*(f32 *)((u8 *)(temp_r28) + (0x164)))) + ((sp[43] * (*(f32 *)((u8 *)(temp_r28) + (0x14C)))) + (sp[44] * (*(f32 *)((u8 *)(temp_r28) + (0x158)))));
                sp[39] = (sp[45] * (*(f32 *)((u8 *)(temp_r28) + (0x168)))) + ((sp[43] * (*(f32 *)((u8 *)(temp_r28) + (0x150)))) + (sp[44] * (*(f32 *)((u8 *)(temp_r28) + (0x15C)))));
            }
        } else {
            sp[37] = lbl_805622D0;
            sp[38] = lbl_805622D0;
            sp[39] = lbl_805622D0;
        }
        PSVECCrossProduct((const Vec*)(f32 *)&sp[37], (const Vec*)(f32 *)&sp[52], (Vec*)(f32 *)&sp[31]);
        sp[49] = sp[34] + sp[31];
        sp[50] = sp[35] + sp[32];
        sp[51] = sp[36] + sp[33];
        if (temp_r29 != NULL) {
            var_f30 = lbl_805622E0 / (*(f32 *)((u8 *)(temp_r29) + (0xD4)));
        } else {
            var_f30 = lbl_805622D0;
        }
        if (temp_r28 != NULL) {
            var_f29 = lbl_805622E0 / (*(f32 *)((u8 *)(temp_r28) + (0xD4)));
        } else {
            var_f29 = lbl_805622D0;
        }
        var_f28 = lbl_805622D0;
        if (-temp_f31 < lbl_80562304) {
            var_f28 = lbl_80562300;
        }
        temp_f27 = PSVECDotProduct((const Vec*)((f32 *)arg3_raw), (const Vec*)(f32 *)&sp[49]);
        temp_f0_5 = -temp_f31;
        temp_f9 = (*(f32 *)((u8 *)(((f32 *)arg3_raw)) + (0)));
        temp_f8 = (*(f32 *)((u8 *)(((f32 *)arg3_raw)) + (4)));
        temp_f7 = (*(f32 *)((u8 *)(((f32 *)arg3_raw)) + (8)));
        temp_f5_2 = temp_f9 * temp_f0_5;
        temp_f10 = -(lbl_805622E0 + var_f28) * PSVECDotProduct((const Vec*)(f32 *)&sp[61], (const Vec*)((f32 *)arg3_raw));
        temp_f2_6 = sp[62] + (temp_f8 * temp_f0_5);
        temp_f31_2 = temp_f10 / (var_f30 + var_f29 + temp_f27);
        temp_f9_2 = temp_f9 * temp_f31_2;
        temp_f8_2 = temp_f8 * temp_f31_2;
        temp_f7_2 = temp_f7 * temp_f31_2;
        sp[28] = temp_f9_2;
        temp_f4_3 = sp[61] + temp_f5_2;
        sp[29] = temp_f8_2;
        sp[30] = temp_f7_2;
        temp_f3_3 = (*(f32 *)((u8 *)(arg0) + (0x14)));
        temp_f1_4 = temp_f3_3 + (*(f32 *)((u8 *)(arg1) + (0x14)));
        sp[25] = temp_f4_3;
        sp[26] = temp_f2_6;
        temp_f28 = lbl_805622E8 * temp_f1_4;
        sp[27] = sp[63] + (temp_f7 * temp_f0_5);
        var_f1_2 = PSVECMag((const Vec*)(f32 *)&sp[25]);
        temp_cr0_gt = var_f1_2 > lbl_80562308;
        if (temp_cr0_gt != 0) {
            if (temp_cr0_gt != 0) {

            } else {
                var_f1_2 = lbl_80562308;
            }
            temp_f3_4 = lbl_805622E0 / var_f1_2;
            temp_f2_7 = sp[25] * temp_f3_4;
            temp_f1_5 = sp[26] * temp_f3_4;
            sp[25] = temp_f2_7;
            sp[26] = temp_f1_5;
            sp[27] *= temp_f3_4;
            PSVECCrossProduct((const Vec*)(f32 *)&sp[55], (const Vec*)(f32 *)&sp[25], (Vec*)(f32 *)&sp[19]);
            PSVECCrossProduct((const Vec*)(f32 *)&sp[52], (const Vec*)(f32 *)&sp[25], (Vec*)(f32 *)&sp[16]);
            if (temp_r29 != NULL) {
                if ((f32 *)&sp[13] == (f32 *)&sp[19]) {
                    sp[13] = (sp[21] * (*(f32 *)((u8 *)(temp_r29) + (0x160)))) + ((sp[19] * (*(f32 *)((u8 *)(temp_r29) + (0x148)))) + (sp[20] * (*(f32 *)((u8 *)(temp_r29) + (0x154)))));
                    sp[14] = (sp[21] * (*(f32 *)((u8 *)(temp_r29) + (0x164)))) + ((sp[19] * (*(f32 *)((u8 *)(temp_r29) + (0x14C)))) + (sp[20] * (*(f32 *)((u8 *)(temp_r29) + (0x158)))));
                    sp[15] = (sp[21] * (*(f32 *)((u8 *)(temp_r29) + (0x168)))) + ((sp[19] * (*(f32 *)((u8 *)(temp_r29) + (0x150)))) + (sp[20] * (*(f32 *)((u8 *)(temp_r29) + (0x15C)))));
                } else {
                    sp[13] = (sp[21] * (*(f32 *)((u8 *)(temp_r29) + (0x160)))) + ((sp[19] * (*(f32 *)((u8 *)(temp_r29) + (0x148)))) + (sp[20] * (*(f32 *)((u8 *)(temp_r29) + (0x154)))));
                    sp[14] = (sp[21] * (*(f32 *)((u8 *)(temp_r29) + (0x164)))) + ((sp[19] * (*(f32 *)((u8 *)(temp_r29) + (0x14C)))) + (sp[20] * (*(f32 *)((u8 *)(temp_r29) + (0x158)))));
                    sp[15] = (sp[21] * (*(f32 *)((u8 *)(temp_r29) + (0x168)))) + ((sp[19] * (*(f32 *)((u8 *)(temp_r29) + (0x150)))) + (sp[20] * (*(f32 *)((u8 *)(temp_r29) + (0x15C)))));
                }
            } else {
                sp[13] = lbl_805622D0;
                sp[14] = lbl_805622D0;
                sp[15] = lbl_805622D0;
            }
            PSVECCrossProduct((const Vec*)(f32 *)&sp[13], (const Vec*)(f32 *)&sp[55], (Vec*)(f32 *)&sp[7]);
            if (temp_r28 != NULL) {
                if ((f32 *)&sp[10] == (f32 *)&sp[16]) {
                    sp[10] = (sp[18] * (*(f32 *)((u8 *)(temp_r28) + (0x160)))) + ((sp[16] * (*(f32 *)((u8 *)(temp_r28) + (0x148)))) + (sp[17] * (*(f32 *)((u8 *)(temp_r28) + (0x154)))));
                    sp[11] = (sp[18] * (*(f32 *)((u8 *)(temp_r28) + (0x164)))) + ((sp[16] * (*(f32 *)((u8 *)(temp_r28) + (0x14C)))) + (sp[17] * (*(f32 *)((u8 *)(temp_r28) + (0x158)))));
                    sp[12] = (sp[18] * (*(f32 *)((u8 *)(temp_r28) + (0x168)))) + ((sp[16] * (*(f32 *)((u8 *)(temp_r28) + (0x150)))) + (sp[17] * (*(f32 *)((u8 *)(temp_r28) + (0x15C)))));
                } else {
                    sp[10] = (sp[18] * (*(f32 *)((u8 *)(temp_r28) + (0x160)))) + ((sp[16] * (*(f32 *)((u8 *)(temp_r28) + (0x148)))) + (sp[17] * (*(f32 *)((u8 *)(temp_r28) + (0x154)))));
                    sp[11] = (sp[18] * (*(f32 *)((u8 *)(temp_r28) + (0x164)))) + ((sp[16] * (*(f32 *)((u8 *)(temp_r28) + (0x14C)))) + (sp[17] * (*(f32 *)((u8 *)(temp_r28) + (0x158)))));
                    sp[12] = (sp[18] * (*(f32 *)((u8 *)(temp_r28) + (0x168)))) + ((sp[16] * (*(f32 *)((u8 *)(temp_r28) + (0x150)))) + (sp[17] * (*(f32 *)((u8 *)(temp_r28) + (0x15C)))));
                }
            } else {
                sp[10] = lbl_805622D0;
                sp[11] = lbl_805622D0;
                sp[12] = lbl_805622D0;
            }
            PSVECCrossProduct((const Vec*)(f32 *)&sp[10], (const Vec*)(f32 *)&sp[52], (Vec*)(f32 *)&sp[4]);
            temp_f4_4 = sp[7] + sp[4];
            temp_f2_8 = sp[8] + sp[5];
            sp[22] = temp_f4_4;
            sp[23] = temp_f2_8;
            sp[24] = sp[9] + sp[6];
            temp_f27_2 = PSVECDotProduct((const Vec*)(f32 *)&sp[25], (const Vec*)(f32 *)&sp[22]);
            var_f5 = (lbl_805622DC * PSVECDotProduct((const Vec*)(f32 *)&sp[61], (const Vec*)(f32 *)&sp[25])) / (var_f30 + var_f29 + temp_f27_2);
            temp_f0_6 = (f32) __fabsf(temp_f31_2 * temp_f28);
            if (temp_f0_6 < var_f5) {
                var_f5 = temp_f0_6;
            }
            temp_f0_7 = -temp_f0_6;
            if (var_f5 > temp_f0_7) {

            } else {
                var_f5 = temp_f0_7;
            }
            sp[29] += sp[26] * var_f5;
            sp[28] += sp[25] * var_f5;
            sp[30] += sp[27] * var_f5;
        }
        temp_cr0_eq_2 = temp_r29 == NULL;
        temp_f27_3 = lbl_805622E0;
        if (temp_cr0_eq_2 == 0) {
            if (temp_cr0_eq_2 == 0) {
                temp_r4_2 = (*(s32 *)((u8 *)(temp_r29) + (0x10)));
                if (temp_r4_2 != 0x4E434152) {
                    if (temp_r4_2 < 0x4E434152) {
                        if (temp_r4_2 != 0x43415220) {
                            if (temp_r4_2 < 0x43415220) {
                                if (temp_r4_2 != 0x41434152) {
                                    goto block_98;
                                }
                                goto block_97;
                            }
                            goto block_98;
                        }
                        goto block_97;
                    }
                    if (temp_r4_2 != 0x50434152) {
                        goto block_98;
                    }
                    goto block_97;
                }
block_97:
                var_r0_2 = 1;
            } else {
block_98:
                var_r0_2 = 0;
            }
            if ((var_r0_2 != 0) && ((u32) (temp_r26 - 0x73) <= 1U)) {
                var_r4 = 1;
                if (((s32) (*(u8 *)((u8 *)(temp_r29) + (0x25C8))) == 0) && !(((u32) 0 >> 0x1EU) & 1)) {
                    var_r4 = 0;
                }
                if ((var_r4 != 0) || (temp_r26 == 0x74)) {
                    ;
                    if ((PSVECDotProduct((const Vec*)(f32 *)&sp[28], (const Vec*)(f32 *)&sp[28]) == lbl_8056230C) && ((*(f32 *)((u8 *)(temp_r29) + (0x25D4))) > lbl_80562310) && (((Fn80199894VTab30Getter *)arg1)->Get() != NULL)) {
                        temp_f1_6 = fn_8018AE7C(temp_r29);
                        temp_f3_5 = sp[28] * temp_f1_6;
                        temp_f2_9 = sp[29] * temp_f1_6;
                        sp[28] = temp_f3_5;
                        sp[29] = temp_f2_9;
                        sp[30] *= temp_f1_6;
                        temp_r3 = ((Fn80199894VTab30With *)arg1)->Get(temp_f2_9, temp_f3_5);
                        temp_r27_2 = ((Fn80199894TempVTab *)temp_r3)->Get();
                        fn_802C1A0C(temp_r3, (*(s32 *)((u8 *)(temp_r29) + (0x1EC))));
                        temp_r3_2 = ((Fn80199894TempVTab *)temp_r3)->Get();
                        temp_r30_2 = temp_r3_2;
                        if ((temp_r27_2 != 0) && (temp_r3_2 == 0)) {
                            ((Fn80199894TempVTab *)temp_r3)->Set(temp_r27_2);
                            fn_801A4A10((s32)(*(s32 *)((u8 *)(arg1) + (8))), (s32)((f32 *)arg2_raw), (s32)temp_r29);
                            ((Fn80199894TempVTab *)temp_r3)->Set(temp_r30_2);
                        }
                    }
                }
            }
        }
        ((Fn80199894VTab20 *)arg0)->Call(arg1, (f32 *)&sp[28], (f32 *)&sp[76], (*(s32 *)((u8 *)(arg1) + (0x20))), ((f32 *)arg2_raw), temp_r28, temp_f27_3);
        temp_f3_6 = sp[28] * lbl_805622DC;
        temp_f2_10 = sp[29] * lbl_805622DC;
        sp[28] = temp_f3_6;
        sp[29] = temp_f2_10;
        sp[30] *= lbl_805622DC;
        ((Fn80199894VTab20Wide *)arg1)->Call(arg0, (f32 *)&sp[28], (f32 *)&sp[73], (*(s32 *)((u8 *)(arg0) + (0x20))), ((f32 *)arg2_raw), temp_r29, temp_f27_3, temp_f2_10, temp_f3_6, lbl_805622DC);
        if (((void *)arg4_raw) != NULL) {
            fn_801B34DC(((void *)arg4_raw), (s32)((void *)arg5_raw), (Vec*)((f32 *)arg2_raw), (Vec*)(f32 *)&sp[28], (Vec*)((f32 *)arg3_raw), (s32)(*(s32 *)((u8 *)(arg1) + (0x20))));
        } else {
            fn_801B34DC(arg0, (s32)arg1, (Vec*)((f32 *)arg2_raw), (Vec*)(f32 *)&sp[28], (Vec*)((f32 *)arg3_raw), (s32)(*(s32 *)((u8 *)(arg1) + (0x20))));
        }
    }
    ((Fn80199894VTab1C *)arg0)->Call((f32 *)&sp[70], (f32 *)&sp[76], (*(s32 *)((u8 *)(arg1) + (0x20))), temp_r28);
    temp_f2_11 = sp[70] * lbl_805622DC;
    temp_f1_7 = sp[71] * lbl_805622DC;
    sp[70] = temp_f2_11;
    sp[71] = temp_f1_7;
    sp[72] *= lbl_805622DC;
    ((Fn80199894VTab1CWide *)arg1)->Call((f32 *)&sp[70], (f32 *)&sp[73], (*(s32 *)((u8 *)(arg0) + (0x20))), temp_r29, temp_f1_7, temp_f2_11, lbl_805622DC);
}
#pragma dont_inline reset
#pragma scheduling on
extern "C" s32 fn_8019A780(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

extern "C" void fn_80199894(void*, void*, void*, void*, s32, s32, f32, f32, f32);
#pragma scheduling invalid_target
extern "C" void fn_8019A788(void* arg0, void* arg1, void* arg2,
                                 Vec* arg3, s32 arg4, s32 arg5,
                                 f32 farg0, f32 farg1, f32 farg2) {
    f32 savedFarg1 = farg1;

    if (*(s32*)((u8*)arg0 + 4) != 0 || arg4 != 0) {
        fn_80199894(arg0, arg1, arg2, arg3, arg4, arg5,
                    farg0, savedFarg1, farg2);
    } else {
        register f32 x = arg3->x;
        register f32 scale = lbl_805622DC;
        register f32 sx = x * scale;
        register f32 sy = arg3->y * scale;
        register f32 sz = arg3->z * scale;
        Vec scaled;
        scaled.x = sx;
        scaled.y = sy;
        scaled.z = sz;
        fn_80199894(arg1, arg0, arg2, &scaled, arg5, arg4,
                    farg0, farg2, savedFarg1);
    }
}
#pragma scheduling on
extern "C" void fn_8019A820(void*, void*, s32, s32, s32, f32);
extern "C" void fn_8019AA18(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_8019A820(arg0, (u8*)arg0 + 0x34, arg1, arg2, arg3, *(f32*)((u8*)arg0 + 0x24));
}

extern "C" void fn_8019AC44(void* arg0, void* arg1, void* arg2, f32 farg0) {
    Vec work[64]; s32 count=0x40, sp8; Vec p70,p64,delta,p4c,p34,p28,p40,p1c,p10;
    f32 dot,mag,limit,scale,varf1,f31,f30; void* body=*(void**)((u8*)arg0+4); Vec* out=(Vec*)arg2; f30=farg0;
    if (lbl_8055E5A0!=0) { fn_801CF080((s32)lbl_8055E5A0,arg1,work,&count,0,f30); for(s32 i=0;i<count;++i) fn_8019A820(arg0,arg1,(s32)&work[i],0x6e,0,f30); }
    if (fn_801E9F08((u8*)body+0x6c,arg1,&p70,(s32)&p64,(s32)&sp8,f30)!=0) {
        delta.x=((Vec*)arg1)->x-p70.x; delta.y=((Vec*)arg1)->y-((f32*)&p70)[1]; delta.z=((Vec*)arg1)->z-((f32*)&p70)[2];
        dot=PSVECDotProduct(&p64,&delta); f31=f30-dot; fn_8017B6D4((s32)body,&p4c,(s32)&p70);
        f30=f31* *(f32*)((u8*)arg0+0x10); dot=-PSVECDotProduct(&p4c,&p64);
        p34.x=p4c.x+p64.x*dot; p34.y=p4c.y+p64.y*dot; p34.z=p4c.z+p64.z*dot;
        p40.x=p64.x*f30; p40.y=p64.y*f30; p40.z=p64.z*f30;
        out->x+=p34.x*lbl_8056231C; out->y+=p34.y*lbl_8056231C; out->z+=p34.z*lbl_8056231C;
        mag=PSVECMag(out); if(mag>lbl_80562320){scale=lbl_80562320/mag;out->x*=scale;out->y*=scale;out->z*=scale;}
        p28.x=p34.x*lbl_80562324; p28.y=p34.y*lbl_80562324; p28.z=p34.z*lbl_80562324;
        limit=lbl_80562328* *(f32*)((u8*)body+0xd4); p28.x+=out->x*limit;p28.y+=out->y*limit;p28.z+=out->z*limit;
        mag=PSVECMag(&p28); scale=f30* *(f32*)((u8*)arg0+0x14); if(scale>lbl_80562320)scale=lbl_80562320;
        if(mag>scale){limit=scale/mag;p28.x*=limit;p28.y*=limit;p28.z*=limit;}
        p40.x+=p28.x;p40.y+=p28.y;p40.z+=p28.z;
        dot=-PSVECDotProduct((Vec*)((u8*)body+0x124),&p64)*f30*lbl_8056232C;
        p1c.x=p64.x*dot;p1c.y=p64.y*dot;p1c.z=p64.z*dot;
        fn_8017B4AC(body,&p1c);
        { typedef void(*Call)(void*,Vec*,Vec*,s32,s32); Call call=(Call)(*(u32*)(*(u32*)arg0+0x1c)); call(arg0,&p40,&p70,sp8,0); }
        scale=lbl_80562330*fn_8019DF88((u8*)body+0x60,(f32*)&p4c,(void*)((u8*)body+0x148),(f32*)&p70,(f32*)&p64,*(f32*)((u8*)body+0xd4),lbl_805622D0);
        if(scale>lbl_805622D0){
            p10.x=p64.x*scale;p10.y=p64.y*scale;p10.z=p64.z*scale;
            varf1=lbl_805622D4;if(varf1>f31)varf1=f31;
            typedef void(*Call2)(void*,s32,Vec*,Vec*,s32,s32,s32,f32);
            Call2 c=(Call2)(*(u32*)(*(u32*)arg0+0x20));c(arg0,0,&p10,&p70,sp8,0,0,varf1);
        } else fn_801B34DC(arg0,0,&p70,&p10,&p64,sp8);
    } else {out->x=lbl_805622D0;out->y=lbl_805622D0;out->z=lbl_805622D0;}
}

extern "C" s32 fn_8019AA34(void*, void*, void*, void*, s32, s32, f32, f32);
void fn_8019B068(void* arg0, void* arg1, s32 arg2, s32 arg3) {
    f32 scale = *(f32*)((u8*)arg1 + 0x24);
    typedef s32 (*Call9)(void*, void*, void*, void*, s32, s32, void*, f32, f32);
    ((Call9)fn_8019AA34)(arg0, (u8*)arg0 + 0x34, arg1, (u8*)arg1 + 0x34, arg2, arg3, arg1, *(f32*)((u8*)arg0 + 0x24), scale);
}

extern "C" s32 fn_8019B08C(void* arg0, Vec* arg1, void* arg2, f32 farg0) {
    Vec* m = *(Vec**)((u8*)arg2 + 0xC);
    f32 x = arg1->x - *(f32*)((u8*)m + 0x24);
    f32 y = arg1->y - *(f32*)((u8*)m + 0x28);
    f32 z = arg1->z - *(f32*)((u8*)m + 0x2C);
    f32 a = x * *(f32*)((u8*)m + 0x18) + y * *(f32*)((u8*)m + 0x1C) + z * *(f32*)((u8*)m + 0x20);
    f32 b = x * *(f32*)m + y * *(f32*)((u8*)m + 4) + z * *(f32*)((u8*)m + 8);
    f32 c = x * *(f32*)((u8*)m + 0xC) + y * *(f32*)((u8*)m + 0x10) + z * *(f32*)((u8*)m + 0x14);
    if (a >= *(f32*)((u8*)arg2 + 0x28) || a <= -*(f32*)((u8*)arg2 + 0x28)) return 0;
    f32 mag = (f32)fn_8002F234(b*b + c*c);
    if (__fabsf(mag) == lbl_80558DC4) return 0;
    f32 t = farg0 - mag + *(f32*)((u8*)arg2 + 0x24);
    if (t <= lbl_805622D0) return 0;
    f32 dt = (*(f32*)((u8*)arg2 + 0x24) - t) / mag;
    Vec p, normal, out;
    p.x = (b * dt) * *(f32*)m + (c * dt) * *(f32*)((u8*)m + 0xC) + a * *(f32*)((u8*)m + 0x18);
    p.y = (b * dt) * *(f32*)((u8*)m + 4) + (c * dt) * *(f32*)((u8*)m + 0x10) + a * *(f32*)((u8*)m + 0x1C);
    p.z = (b * dt) * *(f32*)((u8*)m + 8) + (c * dt) * *(f32*)((u8*)m + 0x14) + a * *(f32*)((u8*)m + 0x20);
    p.x += *(f32*)((u8*)m + 0x24); p.y += *(f32*)((u8*)m + 0x28); p.z += *(f32*)((u8*)m + 0x2C);
    normal.x=b; normal.y=c; normal.z=lbl_805622D0;
    PSVECNormalize(&normal, &normal);
    out.x=normal.x * *(f32*)m + normal.y * *(f32*)((u8*)m + 0xC) + normal.z * *(f32*)((u8*)m + 0x18);
    out.y=normal.x * *(f32*)((u8*)m + 4) + normal.y * *(f32*)((u8*)m + 0x10) + normal.z * *(f32*)((u8*)m + 0x1C);
    out.z=normal.x * *(f32*)((u8*)m + 8) + normal.y * *(f32*)((u8*)m + 0x14) + normal.z * *(f32*)((u8*)m + 0x20);
    typedef void (*Call)(void*,void*,Vec*,Vec*,s32,s32,f32,f32,f32);
    ((Call)fn_8019A788)(arg0,arg2,&p,&out,0,0,t,lbl_805622D0,lbl_805622D0);
    return 1;
}

extern "C" s32 fn_8019BD4C(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

#pragma scheduling invalid_target
extern "C" s32 fn_8019C854(void* arg0, void* arg1) {
    Vec local; Vec point; Vec normal; Vec worldPoint; Vec worldNormal;
    void* saved0; void* saved1; f32 radius; f32 otherRadius; f32 halfHeight; f32 depth;
    {
        f32* matrix = *(f32**)((u8*)arg1 + 0xC);
        saved0 = arg0;
        f32 x = *(f32*)((u8*)saved0 + 0x34) - matrix[9];
        f32 y = *(f32*)((u8*)saved0 + 0x38) - matrix[10];
        f32 z = *(f32*)((u8*)saved0 + 0x3C) - matrix[11];
        local.x = (x * matrix[0] + y * matrix[1]) + z * matrix[2];
        local.y = (x * matrix[3] + y * matrix[4]) + z * matrix[5];
        local.z = (x * matrix[6] + y * matrix[7]) + z * matrix[8];
        saved1 = arg1;
    }
    radius = *(f32*)((u8*)saved0 + 0x24);
    halfHeight = *(f32*)((u8*)saved1 + 0x28);
    otherRadius = *(f32*)((u8*)saved1 + 0x24);
    f32 upper = radius + halfHeight;
    if (!(local.z < upper && local.z > -upper))
        return 0;
    {
        f32 distance = (f32)fn_8002F234(local.y * local.y + local.x * local.x);
        depth = (radius + halfHeight) - (f32)__fabs((f64)(distance - otherRadius));
        if (depth <= lbl_805622D0) return 0;
        if (distance > otherRadius + halfHeight) {
            f32 scale = (distance - radius) / distance;
            point.x = local.x * scale; point.y = local.y * scale; point.z = local.z * scale;
        } else if (distance < otherRadius - halfHeight) {
            f32 scale = (distance + radius) / distance;
            point.x = local.x * scale; point.y = local.y * scale; point.z = local.z * scale;
        } else {
            point.x = local.x; point.y = local.y; point.z = local.z;
        }
    }
    normal.z = local.z - lbl_805622D0;
    normal.x = local.x - point.x;
    normal.y = local.y - point.y;
    point.z = lbl_805622D0;
    PSVECNormalize(&normal, &normal);
    {
        f32* matrix = *(f32**)((u8*)saved1 + 0xC);
        volatile f32* dst = (volatile f32*)&worldPoint;
        volatile f32* src = (volatile f32*)&point;
        f32 x = src[0], y = src[1], z = src[2];
        if (dst == src) {
            dst[0] = (x * matrix[0] + y * matrix[3]) + z * matrix[6];
            dst[1] = (x * matrix[1] + y * matrix[4]) + z * matrix[7];
            dst[2] = (x * matrix[2] + y * matrix[5]) + z * matrix[8];
        } else {
            dst[0] = (y * matrix[3] + x * matrix[0]) + z * matrix[6];
            dst[1] = (y * matrix[4] + x * matrix[1]) + z * matrix[7];
            dst[2] = (y * matrix[5] + x * matrix[2]) + z * matrix[8];
        }
        dst[0] += matrix[9]; dst[1] += matrix[10]; dst[2] += matrix[11];
    }
    {
        f32* matrix = *(f32**)((u8*)saved1 + 0xC);
        volatile f32* dst = (volatile f32*)&worldNormal;
        volatile f32* src = (volatile f32*)&normal;
        f32 x = src[0], y = src[1], z = src[2];
        if (dst == src) {
            dst[0] = (x * matrix[0] + y * matrix[3]) + z * matrix[6];
            dst[1] = (x * matrix[1] + y * matrix[4]) + z * matrix[7];
            dst[2] = (x * matrix[2] + y * matrix[5]) + z * matrix[8];
        } else {
            dst[0] = (y * matrix[3] + x * matrix[0]) + z * matrix[6];
            dst[1] = (y * matrix[4] + x * matrix[1]) + z * matrix[7];
            dst[2] = (y * matrix[5] + x * matrix[2]) + z * matrix[8];
        }
    }
    typedef void (*Call)(void*, void*, Vec*, Vec*, s32, s32, f32, f32, f32);
    ((Call)fn_8019A788)(saved0, saved1, &worldPoint, &worldNormal, 0, 0, depth, lbl_805622D0, lbl_805622D0);
    return 1;
}

extern "C" s32 fn_8019CCCC(s32 arg0, s32 arg1, void* arg2, f32 farg0) {
    typedef s32 (*Check)(void);
    if (((Check)fn_8019B08C)() != 0) {
        return 1;
    }
    u32 transXBits, transYBits, transZBits;
    u32 axisXBits, axisYBits, axisZBits;
    Vec neg, pos;
    f32 radius = *(f32*)((u8*)arg2 + 0x24);
    f32 dim = *(f32*)((u8*)arg2 + 0x28);
    register u32* m = (u32*)*(void**)((u8*)arg2 + 0xC);
    axisXBits = m[6];
    axisYBits = m[7];
    axisZBits = m[8];
    transXBits = m[9];
    transYBits = m[10];
    transZBits = m[11];
    f32 negDim = -dim;
    f32 transX = *(f32*)&transXBits;
    f32 transY = *(f32*)&transYBits;
    f32 transZ = *(f32*)&transZBits;
    f32 axisX = *(f32*)&axisXBits;
    f32 axisY = *(f32*)&axisYBits;
    f32 axisZ = *(f32*)&axisZBits;
    pos.x = transX + axisX * dim;
    pos.y = transY + axisY * dim;
    pos.z = transZ + axisZ * dim;
    neg.x = transX + axisX * negDim;
    neg.y = transY + axisY * negDim;
    neg.z = transZ + axisZ * negDim;
    s32 firstHit = fn_8019AA34((void*)arg0, (void*)arg1, arg2, &pos.x, 0, 0, farg0, radius);
    s32 secondHit = fn_8019AA34((void*)arg0, (void*)arg1, arg2, &neg.x, 0, 0, farg0, radius);
    return (firstHit | secondHit) != 0;
}

#pragma scheduling on
extern void fn_8019CCCC(void*, f32, s32);
extern void fn_8019CCCC(void*, void*, s32, f32);
void fn_8019CE3C(void* arg0, s32 arg1) {
    fn_8019CCCC(arg0, (u8*)arg0 + 0x34, arg1, *(f32*)((u8*)arg0 + 0x24));
}

extern "C" void fn_8019CE4C(void *arg0, void *arg1) {
    struct Target { u8 pad[0x34]; Vec point; };
    Target *target = (Target *)arg1;
    Vec *a = (Vec *)((u8 *)arg0 + 0x34);
    f32 delta[3];
    delta[0] = a->x - target->point.x;
    delta[1] = a->y - target->point.y;
    f32 targetZ = target->point.z;
    f32 sourceZ = a->z;
    delta[2] = sourceZ - targetZ;
    f32 distance = PSVECSquareDistance(a, &target->point);
    f32 result;
    if (distance > lbl_8056232C) {
        f32 scale = lbl_805622E0 / (f32)fn_8002F234(distance);
        delta[0] *= scale;
        delta[1] *= scale;
        delta[2] *= scale;
        Vec *axis = (Vec *)((u8 *)*(void **)((u8 *)arg1 + 0xC) + 0xC);
        f32 dot = PSVECDotProduct((Vec *)delta, axis);
        f32 high = *(f32 *)((u8 *)arg1 + 0x58);
        f32 low = *(f32 *)((u8 *)arg1 + 0x54);
        f32 magnitude = (f32)__fabs((f64)dot);
        result = low + magnitude * (high - low);
    } else {
        f32 high = *(f32 *)((u8 *)arg1 + 0x58);
        f32 low = *(f32 *)((u8 *)arg1 + 0x54);
        result = (low > high) ? low : high;
    }
    *(f32 *)((u8 *)arg1 + 0x24) = result;
    fn_8019B068(arg0, arg1, 0, 0);
}

extern "C" void fn_8019CF60(void *arg0, void *arg1) {
    struct Origin { u8 pad[0x24]; Vec point; };
    struct Target { u8 pad[0x34]; Vec point; };
    Origin *origin = (Origin *)*(void **)((u8 *)arg0 + 0xC);
    Target *target = (Target *)arg1;
    f32 delta[3];
    delta[0] = origin->point.x - target->point.x;
    delta[1] = origin->point.y - target->point.y;
    delta[2] = origin->point.z - target->point.z;
    f32 distance = PSVECSquareDistance(&origin->point, &target->point);
    f32 result;
    if (distance > lbl_8056232C) {
        f32 scale = lbl_805622E0 / (f32)fn_8002F234(distance);
        delta[0] *= scale;
        delta[1] *= scale;
        delta[2] *= scale;
        Vec *axis = (Vec *)((u8 *)*(void **)((u8 *)arg1 + 0xC) + 0xC);
        f32 dot = PSVECDotProduct((Vec *)delta, axis);
        f32 high = *(f32 *)((u8 *)arg1 + 0x58);
        f32 low = *(f32 *)((u8 *)arg1 + 0x54);
        f32 magnitude = (f32)__fabs((f64)dot);
        result = low + magnitude * (high - low);
    } else {
        f32 high = *(f32 *)((u8 *)arg1 + 0x58);
        f32 low = *(f32 *)((u8 *)arg1 + 0x54);
        result = (low > high) ? low : high;
    }
    *(f32 *)((u8 *)arg1 + 0x24) = result;
    fn_8019CE3C(arg1, (s32)arg0);
}

extern "C" void fn_8019D06C(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    struct Target { u8 pad[0x34]; Vec point; };
    Target *target = (Target *)arg0;
    Vec position;
    Vec delta;
    fn_801A1F44(&position, arg1);
    delta.x = position.x - target->point.x;
    delta.y = position.y - target->point.y;
    delta.z = position.z - target->point.z;
    f32 distance = PSVECSquareDistance(&position, &target->point);
    f32 result;
    if (distance > lbl_8056232C) {
        f32 root = (f32)fn_8002F234(distance);
        f32 scale = lbl_805622E0 / root;
        delta.x *= scale;
        delta.y *= scale;
        delta.z *= scale;
        Vec *axis = (Vec *)((u8 *)*(void **)((u8 *)arg0 + 0xC) + 0xC);
        f32 dot = PSVECDotProduct(&delta, axis);
        register f32 high;
        register f32 low;
        register f32 magnitude;
        high = *(f32 *)((u8 *)arg0 + 0x58);
        low = *(f32 *)((u8 *)arg0 + 0x54);
        magnitude = (f32)__fabs((f64)dot);
        f32 difference = high - low;
        result = low + magnitude * difference;
    } else {
        f32 high = *(f32 *)((u8 *)arg0 + 0x58);
        f32 low = *(f32 *)((u8 *)arg0 + 0x54);
        if (low > high) result = low;
        else result = high;
    }
    *(f32 *)((u8 *)arg0 + 0x24) = result;
    fn_8019BD54(arg0, arg1, arg2, arg3);
}

extern "C" f32 PSVECSquareDistance(const Vec*, const Vec*);
extern "C" f32 PSVECDotProduct(const Vec*, const Vec*);
extern f32 lbl_8056232C;
extern "C" void fn_8019D19C(void* arg0, void* arg1) {
    f32 sp14, sp18, sp1C;
    f32 sp8, spC, sp10;
    f32 scale, dot, value;
    Vec* v0 = (Vec*)((u8*)arg0 + 0x34);
    Vec* v1 = (Vec*)((u8*)arg1 + 0x34);
    sp14 = v1->x - v0->x;
    sp18 = v1->y - v0->y;
    sp1C = v1->z - v0->z;
    if (PSVECSquareDistance(v1, v0) > lbl_8056232C) {
        scale = lbl_805622E0 / (f32)fn_8002F234(PSVECSquareDistance(v1, v0));
        sp14 *= scale; sp18 *= scale; sp1C *= scale;
        dot = PSVECDotProduct((Vec*)&sp14, (Vec*)((u8*)arg0 + 0x18));
        value = *(f32*)((u8*)arg0 + 0x54) + __fabsf(dot) * (*(f32*)((u8*)arg0 + 0x58) - *(f32*)((u8*)arg0 + 0x54));
    } else {
        value = *(f32*)((u8*)arg0 + 0x54);
        if (value <= *(f32*)((u8*)arg0 + 0x58)) value = *(f32*)((u8*)arg0 + 0x58);
    }
    *(f32*)((u8*)arg0 + 0x24) = value;
    sp8 = v0->x - v1->x; spC = v0->y - v1->y; sp10 = v0->z - v1->z;
    if (PSVECSquareDistance(v0, v1) > lbl_8056232C) {
        scale = lbl_805622E0 / (f32)fn_8002F234(PSVECSquareDistance(v0, v1));
        sp8 *= scale; spC *= scale; sp10 *= scale;
        dot = PSVECDotProduct((Vec*)&sp8, (Vec*)((u8*)arg1 + 0x18));
        value = *(f32*)((u8*)arg1 + 0x54) + __fabsf(dot) * (*(f32*)((u8*)arg1 + 0x58) - *(f32*)((u8*)arg1 + 0x54));
    } else {
        value = *(f32*)((u8*)arg1 + 0x54);
        if (value <= *(f32*)((u8*)arg1 + 0x58)) value = *(f32*)((u8*)arg1 + 0x58);
    }
    *(f32*)((u8*)arg1 + 0x24) = value;
    fn_8019B068(arg0, arg1, 0, 0);
}

extern "C" void fn_8019D378(void *arg0, void *arg1) {
    struct Target { u8 pad[0x34]; Vec point; };
    struct Origin { u8 pad[0x24]; Vec point; };
    Target *target = (Target *)arg0;
    Origin *origin = (Origin *)*(void **)((u8 *)arg1 + 0xC);
    Vec *point = &origin->point;
    f32 delta[3];
    delta[0] = point->x - target->point.x;
    delta[1] = point->y - target->point.y;
    f32 targetZ = target->point.z;
    f32 originZ = point->z;
    delta[2] = originZ - targetZ;
    f32 distance = PSVECSquareDistance(point, &target->point);
    f32 result;
    if (distance > lbl_8056232C) {
        f32 scale = lbl_805622E0 / (f32)fn_8002F234(distance);
        delta[0] *= scale;
        delta[1] *= scale;
        delta[2] *= scale;
        Vec *axis = (Vec *)((u8 *)*(void **)((u8 *)arg0 + 0xC) + 0xC);
        f32 dot = PSVECDotProduct((Vec *)delta, axis);
        f32 high = *(f32 *)((u8 *)arg0 + 0x58);
        f32 low = *(f32 *)((u8 *)arg0 + 0x54);
        f32 magnitude = (f32)__fabs((f64)dot);
        result = low + magnitude * (high - low);
    } else {
        f32 high = *(f32 *)((u8 *)arg0 + 0x58);
        f32 low = *(f32 *)((u8 *)arg0 + 0x54);
        result = (low > high) ? low : high;
    }
    *(f32 *)((u8 *)arg0 + 0x24) = result;
    fn_8019C854(arg0, arg1);
}

extern "C" void PSVECCrossProduct(const Vec *, const Vec *, Vec *);
extern "C" f32 fn_8019D484(const Vec *p0, const Vec *v0, const Vec *p1, const Vec *v1, f32 *out0, f32 *out1) {
    extern f32 lbl_80562348;
    Vec delta, normal;
    f32 den, a, b;
    delta.x = p1->x - p0->x;
    delta.y = p1->y - p0->y;
    delta.z = p1->z - p0->z;
    PSVECCrossProduct(v0, v1, &normal);
    den = PSVECDotProduct(&normal, &normal);
    if (den > lbl_80562348) {
        a = (delta.y * v1->z - delta.z * v1->y) * normal.x
          + (delta.z * v1->x - delta.x * v1->z) * normal.y
          + (delta.x * v1->y - delta.y * v1->x) * normal.z;
        b = (delta.y * v0->z - delta.z * v0->y) * normal.x
          + (delta.z * v0->x - delta.x * v0->z) * normal.y
          + (delta.x * v0->y - delta.y * v0->x) * normal.z;
        *out0 = a / den;
        *out1 = b / den;
        return 1;
    }
    return 0;
}

s32 fn_8019D618(void* arg0, void* arg1, s32 clamp, void* arg3) {
    Vec* a = *(Vec**)((u8*)arg0 + 0xC); Vec* b = *(Vec**)((u8*)arg1 + 0xC);
    Vec cross, mid, da, db, p, q, delta, normal, center;
    f32 h0=*(f32*)((u8*)arg0+0x28), h1=*(f32*)((u8*)arg1+0x28);
    PSVECCrossProduct((Vec*)((u8*)a+0x18),(Vec*)((u8*)b+0x18),&cross);
    f32 den=PSVECDotProduct(&cross,&cross), t0,t1;
    if(den<lbl_8056232C) {
        mid.x=(a->x+b->x)*lbl_805622E8; mid.y=(a->y+b->y)*lbl_805622E8; mid.z=(a->z+b->z)*lbl_805622E8;
        da.x=mid.x-a->x; da.y=mid.y-a->y; da.z=mid.z-a->z;
        t0=PSVECDotProduct((Vec*)((u8*)a+0x18),&da);
        db.x=mid.x-b->x; db.y=mid.y-b->y; db.z=mid.z-b->z;
        t1=PSVECDotProduct((Vec*)((u8*)b+0x18),&db);
    } else { t0=0.0f; t1=0.0f; }
    if(!clamp) { if(t0 < -h0 || t0>h0 || t1 < -h1 || t1>h1) return 0; }
    else { if(t0 < -h0)t0=-h0; if(t0>h0)t0=h0; if(t1 < -h1)t1=-h1; if(t1>h1)t1=h1; }
    p.x=a->x+((Vec*)((u8*)a+0x18))->x*t0; p.y=a->y+((Vec*)((u8*)a+0x18))->y*t0; p.z=a->z+((Vec*)((u8*)a+0x18))->z*t0;
    q.x=b->x+((Vec*)((u8*)b+0x18))->x*t1; q.y=b->y+((Vec*)((u8*)b+0x18))->y*t1; q.z=b->z+((Vec*)((u8*)b+0x18))->z*t1;
    delta.x=q.x-p.x; delta.y=q.y-p.y; delta.z=q.z-p.z;
    f32 dist=PSVECMag(&delta); if(__fabsf(dist)==lbl_80558DC4)return 0;
    f32 depth=*(f32*)((u8*)arg0+0x24)+*(f32*)((u8*)arg1+0x24)-dist; if(depth<lbl_805622D0)return 0;
    f32 scale=lbl_805622DC/dist; normal.x=delta.x*scale; normal.y=delta.y*scale; normal.z=delta.z*scale;
    center.x=(p.x+q.x)*lbl_805622E8; center.y=(p.y+q.y)*lbl_805622E8; center.z=(p.z+q.z)*lbl_805622E8;
    typedef void (*Call)(void*,void*,f32,f32,Vec*,Vec*,s32,s32);
    ((Call)fn_8019A788)(arg3?arg3:arg0,arg1,depth,lbl_805622D0,&center,&normal,0,0);
    return 1;
}

#pragma processor 750
extern "C" s32 fn_8019DAB0(void *arg0, void *arg1) {
    struct Scratch {
        u32 center[3];
        u32 axis[3];
        Vec minus;
        Vec plus;
    };
    s32 check = fn_8019D618(arg0, arg1, 0, 0);
    u32 checkFlag = ((u32)check | (u32)-check) >> 31;
    if (checkFlag) return 1;
    void *shape = *(void **)((u8 *)arg0 + 0xC);
    f32 radius = *(f32 *)((u8 *)arg0 + 0x28);
    Scratch scratch;
    u32 *words = (u32 *)shape;
    scratch.axis[0] = words[6];
    scratch.axis[1] = words[7];
    scratch.axis[2] = words[8];
    scratch.center[0] = words[9];
    scratch.center[1] = words[10];
    scratch.center[2] = words[11];
    f32 width = *(f32 *)((u8 *)arg0 + 0x24);
    f32 *axis = (f32 *)scratch.axis;
    f32 *center = (f32 *)scratch.center;
    f32 negativeRadius = -radius;
    scratch.plus.x = center[0] + axis[0] * radius;
    scratch.plus.y = center[1] + axis[1] * radius;
    scratch.plus.z = center[2] + axis[2] * radius;
    scratch.minus.x = center[0] + axis[0] * negativeRadius;
    scratch.minus.y = center[1] + axis[1] * negativeRadius;
    scratch.minus.z = center[2] + axis[2] * negativeRadius;
    s32 result = fn_8019B08C(arg0, &scratch.plus, arg1, width) | checkFlag;
    result = (result | -result) >> 31;
    result |= fn_8019B08C(arg0, &scratch.minus, arg1, width);
    return (result | -result) >> 31;
}
#pragma processor reset

extern "C" f32 fn_8019DDEC(void *arg0) {
    return *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg0 + 0x28);
}

extern f32 lbl_805622E8;
extern f32 lbl_8056234C;
extern "C" s32 fn_801CF080(s32, void*, void*, s32*, s32, f32);
extern f32 lbl_80562350;
extern f32 lbl_80562354;
extern f32 lbl_80562358;
extern "C" s32 fn_8019DDFC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void* arg4, void* arg5, f32 farg0) {
    f32 sp8, spC, sp10;
    f32 dot1;
    f32 dot2;
    f32 val;
    f32 t;
    f32 mag;
    f32 scale;

    sp8 = *(f32*)arg4 - *(f32*)arg5;
    spC = ((f32*)arg4)[1] - ((f32*)arg5)[1];
    sp10 = ((f32*)arg4)[2] - ((f32*)arg5)[2];
    dot1 = PSVECDotProduct((const Vec*)&sp8, (const Vec*)&sp8);
    dot2 = PSVECDotProduct((const Vec*)&sp8, (const Vec*)&farg0);
    val = lbl_8056234C * dot1;
    t = val * val - lbl_80562350 * (dot2 - farg0 * farg0);
    if (t <= lbl_80562354)
        return 0;
    mag = (f32)fn_8002F234(t);
    scale = lbl_805622E8 * (-val - mag);
    if (scale != lbl_805622D0 || scale >= *(f32*)arg5)
        return 0;
    *(f32*)arg5 = scale;
    ((f32*)arg4)[0] = sp8 + ((f32*)arg5)[0] * scale;
    ((f32*)arg4)[1] = spC + ((f32*)arg5)[1] * scale;
    ((f32*)arg4)[2] = sp10 + ((f32*)arg5)[2] * scale;
    mag = PSVECMag((const Vec*)arg4);
    if (lbl_80562358 > mag)
        mag = lbl_80562358;
    scale = lbl_805622E0 / mag;
    ((f32*)arg4)[0] *= scale;
    ((f32*)arg4)[1] *= scale;
    ((f32*)arg4)[2] *= scale;
    return 1;
}

extern "C" s32 fn_8019E1F4(f32* arg0, f32* arg1, f32 f0, f32 f1, f32 f2) {
    if ((f32)__fabs(f1) <= lbl_80558DC4) {
        if (f0 < -f2) goto ret0;
        if (!(f0 > f2)) goto ret1;
ret0:
        return 0;
ret1:
        return 1;
    }
    f32 diff;
    f32 neg_f2 = -f2;
    diff = f2 - f0;
    f0 = neg_f2 - f0;
    f2 = diff / f1;
    f1 = f0 / f1;
    f32 min_t = (f1 < f2) ? f1 : f2;
    f32 cur_min = *arg0;
    *arg0 = (cur_min > min_t) ? cur_min : min_t;
    f32 max_t = (f1 > f2) ? f1 : f2;
    f32 cur_max = *arg1;
    *arg1 = (cur_max < max_t) ? cur_max : max_t;
    if (*arg0 > *arg1) return 0;
    return !(*arg1 < lbl_805622D0);
}

extern "C" u8 lbl_80435020[];
extern f32 lbl_8056236C;
#pragma scheduling invalid_target
extern "C" s32 fn_8019E500(void* arg0, void* arg1) {
    u32 copied[12];
    f32 rows[3][4];
    f32 output[12];
    f32* matrix = (f32*)((VTab1A1E7C*)arg1)->Call();
    copied[0]=((u32*)matrix)[0]; copied[1]=((u32*)matrix)[1];
    copied[2]=((u32*)matrix)[2]; copied[3]=((u32*)matrix)[3];
    copied[4]=((u32*)matrix)[4]; copied[5]=((u32*)matrix)[5];
    copied[6]=((u32*)matrix)[6]; copied[7]=((u32*)matrix)[7];
    copied[8]=((u32*)matrix)[8]; copied[9]=((u32*)matrix)[9];
    copied[10]=((u32*)matrix)[10]; copied[11]=((u32*)matrix)[11];
    *(f64*)&rows[0][0]=*(f64*)&copied[0];
    *(u32*)&rows[0][2]=copied[2];
    rows[0][3]=*(f32*)((u8*)arg1+0x24);
    *(f64*)&rows[1][0]=*(f64*)&copied[3];
    *(u32*)&rows[1][2]=copied[5];
    rows[1][3]=*(f32*)((u8*)arg1+0x28);
    *(f64*)&rows[2][0]=*(f64*)&copied[6];
    *(u32*)&rows[2][2]=copied[8];
    rows[2][3]=*(f32*)((u8*)arg1+0x2c);
    s32 result=0;
    for (s32 row=0; row<3; row++) {
        if (row!=1) {
            s32 next=(row+1)%3, prev=(row+2)%3;
            f32* current=rows[row];
            f32* arow=rows[next];
            f32* brow=rows[prev];
            output[0]=arow[0]; output[1]=arow[1]; output[2]=arow[2];
            output[3]=brow[0]; output[4]=brow[1]; output[5]=brow[2];
            output[6]=current[0]; output[7]=current[1]; output[8]=current[2];
            output[9]=*(f32*)&copied[9];
            output[10]=*(f32*)&copied[10];
            output[11]=*(f32*)&copied[11];
            f32 d0=arow[3]-lbl_8056236C;
            f32 d1=brow[3]-lbl_8056236C;
            for (s32 i=0;i<4;i++) {
                f32 a=(i&1) ? lbl_805622DC : lbl_805622E0;
                f32 s0=d0*a;
                output[9]+=arow[0]*s0;
                output[10]+=arow[1]*s0;
                output[11]+=arow[2]*s0;
                f32 b=(i&2) ? lbl_805622DC : lbl_805622E0;
                f32 s1=d1*b;
                output[9]+=brow[0]*s1;
                output[10]+=brow[1]*s1;
                output[11]+=brow[2]*s1;
                if (lbl_80435020 != 0) {
                    *(void**)(lbl_80435020+0xc)=output;
                    *(void**)(lbl_80435020+0x4)=*(void**)((u8*)arg1+4);
                    *(s32*)(lbl_80435020+0x8)=0;
                    *(u32*)(lbl_80435020+0x18)=0x54554245;
                    *(f32*)(lbl_80435020+0x10)=*(f32*)((u8*)arg1+0x10);
                    *(f32*)(lbl_80435020+0x14)=*(f32*)((u8*)arg1+0x14);
                    *(s32*)(lbl_80435020+0x20)=0x64;
                    *(s32*)(lbl_80435020+0x1c)=0;
                    *(f32*)(lbl_80435020+0x24)=lbl_8056236C;
                    *(f32*)(lbl_80435020+0x28)=current[3];
                    *(void**)(lbl_80435020+0x0)=lbl_80333918;
                }
                result=(result | fn_8019D618(lbl_80435020,arg0,1,arg1)) != 0;
            }
        }
    }
    return result;
}
#pragma scheduling on
extern "C" s32 fn_8019E834(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_8019E874(void*, void**, void*, f32, f32, f32, f32);
extern void fn_8019AA34(void*, void*, void*, s32, s32, void*, f32, f32);
extern void fn_8019A820(void*, s32, s32, s32, f32);
#pragma scheduling invalid_target
extern "C" s32 fn_8019EA7C(void* arg0, void* arg1) {
    void* temp_r3;
    void* temp_r5;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    volatile f32 sp[9];

    temp_r3 = ((Fn8019EA7CDispatch*)arg1)->Get();
    temp_r5 = *(void**)((u8*)arg0 + 0xC);
    temp_f3 = *(f32*)((u8*)temp_r5 + 0x28);
    temp_f4 = *(f32*)((u8*)temp_r5 + 0x24) - *(f32*)((u8*)temp_r3 + 0x24);
    temp_f1 = *(f32*)((u8*)temp_r5 + 0x2C);
    temp_f2 = temp_f3 - *(f32*)((u8*)temp_r3 + 0x28);
    sp[6] = temp_f4;
    sp[1] = temp_f2;
    sp[5] = temp_f1 - *(f32*)((u8*)temp_r3 + 0x2C);
    return (s32)(bool)fn_8019E874(arg0, (void**)arg1, temp_r5, temp_f1, temp_f2, temp_f3, temp_f4);
}
#pragma scheduling on
extern "C" void fn_8019EB14(s32 arg0_raw, s32 arg1) {
    u8 *arg0 = (u8 *)arg0_raw;
    u32 offset = arg1 * 8;
    u8 *p = arg0 + offset;
    u8 t;

    t = arg0[offset];
    arg0[offset] = p[1];
    p[1] = t;

    t = p[2]; p[2] = p[3]; p[3] = t;
    t = p[4]; p[4] = p[5]; p[5] = t;
    t = p[6]; p[6] = p[7]; p[7] = t;

    if (*(u16 *)(p + 4) != 0) {
        s32 i;
        for (i = 0; i < 4; i++) {
            fn_8019EB14(arg0_raw, *(u16 *)(p + 4) + i);
        }
    }
}

extern "C" void fn_8019EBC0(void* arg0) {
    VTab19* p = *(VTab19**)((u8*)arg0 + 4);
    if (p == NULL) {
        return;
    }
    p->v16();
}

#pragma scheduling invalid_target
extern "C" void fn_8019EBE0(void *self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 v1 = (s32)self;
    s32 v2 = a;
    s32 v3 = b;
    s32 v4 = c;
    s32 v5 = d;
    s32 v6 = e;
    s32 v7 = f;
    s32 obj = *(s32 *)((u8 *)self + 4);

    if (obj != 0) {
        fn_8017B5D4(obj, v1, v2, v3, v4, v5, v6);
    } else {
        obj = *(s32 *)((u8 *)self + 8);
        if (obj != 0) fn_801A4A10(obj, v4, v7, v3);
    }
}
#pragma scheduling on
extern "C" void fn_8019EC84(void* this_) {
    VTab19* p = *(VTab19**)((u8*)this_ + 4);
    if (p == NULL) {
        return;
    }
    p->slot0x4C();
}

extern "C" void fn_8019ECA4(VTab13* this_, s32 arg1) {
    *(s32*)((u8*)this_ + 8) = arg1;
    this_->slot0x34(arg1 + 4);
}

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
  extern "C" void fn_8019ECBC(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0xC) = arg1;
}

#pragma scheduling invalid_target
extern "C" void* fn_8019EDB8(void* arg0, void* arg1, s32 arg2) {
    s32 copyFlag = arg2;
    void *self = arg0;
    u8 second, first, opposite, other;
    fn_8019ECC4();
    *(void **)self = &lbl_80333B48;
    if (copyFlag != 0) {
        first = *(volatile u8 *)((u8 *)self + 0x24);
        opposite = *(volatile u8 *)((u8 *)self + 0x27);
        second = *(volatile u8 *)((u8 *)self + 0x25);
        other = *(volatile u8 *)((u8 *)self + 0x26);
        *(volatile u8 *)((u8 *)self + 0x24) = opposite;
        *(volatile u8 *)((u8 *)self + 0x27) = first;
        *(volatile u8 *)((u8 *)self + 0x25) = other;
        *(volatile u8 *)((u8 *)self + 0x26) = second;
        opposite = *(volatile u8 *)((u8 *)self + 0x28);
        other = *(volatile u8 *)((u8 *)self + 0x2b);
        *(volatile u8 *)((u8 *)self + 0x28) = other;
        *(volatile u8 *)((u8 *)self + 0x2b) = opposite;
        opposite = *(volatile u8 *)((u8 *)self + 0x29);
        other = *(volatile u8 *)((u8 *)self + 0x2a);
        *(volatile u8 *)((u8 *)self + 0x29) = other;
        *(volatile u8 *)((u8 *)self + 0x2a) = opposite;
        opposite = *(volatile u8 *)((u8 *)self + 0x2c);
        other = *(volatile u8 *)((u8 *)self + 0x2f);
        *(volatile u8 *)((u8 *)self + 0x2c) = other;
        *(volatile u8 *)((u8 *)self + 0x2f) = opposite;
        opposite = *(volatile u8 *)((u8 *)self + 0x2d);
        other = *(volatile u8 *)((u8 *)self + 0x2e);
        *(volatile u8 *)((u8 *)self + 0x2d) = other;
        *(volatile u8 *)((u8 *)self + 0x2e) = opposite;
        opposite = *(volatile u8 *)((u8 *)self + 0x30);
        other = *(volatile u8 *)((u8 *)self + 0x33);
        *(volatile u8 *)((u8 *)self + 0x30) = other;
        *(volatile u8 *)((u8 *)self + 0x33) = opposite;
        opposite = *(volatile u8 *)((u8 *)self + 0x31);
        other = *(volatile u8 *)((u8 *)self + 0x32);
        *(volatile u8 *)((u8 *)self + 0x31) = other;
        *(volatile u8 *)((u8 *)self + 0x32) = opposite;
        if (*(volatile s32 *)((u8 *)self + 0x20) == 0x3eb)
            *(f32 *)((u8 *)self + 0x24) += lbl_80562370;
    }
    f32 zero = lbl_805622D0;
    *(volatile u8 *)((u8 *)self + 0x4c) = 0;
    *(f32 *)((u8 *)self + 0x34) = zero;
    *(f32 *)((u8 *)self + 0x38) = zero;
    *(f32 *)((u8 *)self + 0x3c) = zero;
    *(f32 *)((u8 *)self + 0x40) = zero;
    *(f32 *)((u8 *)self + 0x44) = zero;
    *(f32 *)((u8 *)self + 0x48) = zero;
    *(f32 *)((u8 *)self + 0x50) = zero;
    return self;
}
#pragma scheduling on
extern "C" void fn_8019EECC(void* arg0, Vec* arg1) {
    arg1->x += *(f32*)((u8*)arg0 + 0x30);
    arg1->y += *(f32*)((u8*)arg0 + 0x34);
    arg1->z += *(f32*)((u8*)arg0 + 0x38);
}

extern "C" void fn_8019EF00(void* arg0) {
    struct Object {
        char pad0[0xC];
        f32* matrix;
        char pad10[0x18];
        Vec input;
        volatile Vec output;
    };
    Object* self = (Object*)arg0;
    f32* m = self->matrix;
    if (&self->output == (volatile Vec*)&self->input) {
        register f32 y = self->input.y;
        register f32 p03 = y * m[3];
        register f32 p14 = y * m[4];
        register f32 p25 = y * m[5];
        register f32 x = self->input.x;
        register f32 p00 = x * m[0];
        register f32 p11 = x * m[1];
        register f32 p22 = x * m[2];
        register f32 z = self->input.z;
        register f32 p06 = z * m[6];
        register f32 p17 = z * m[7];
        register f32 p28 = z * m[8];
        self->output.x = p00 + p03 + p06;
        self->output.y = p11 + p14 + p17;
        self->output.z = p22 + p25 + p28;
    } else {
        register f32 p03 = self->input.y * m[3];
        register f32 p00 = self->input.x * m[0];
        register f32 p06 = self->input.z * m[6];
        self->output.x = p00 + p03 + p06;
        register f32 p14 = self->input.y * m[4];
        register f32 p11 = self->input.x * m[1];
        register f32 p17 = self->input.z * m[7];
        self->output.y = p11 + p14 + p17;
        register f32 p25 = self->input.y * m[5];
        register f32 p22 = self->input.x * m[2];
        register f32 p28 = self->input.z * m[8];
        self->output.z = p22 + p25 + p28;
    }
    self->output.x += m[9];
    self->output.y += m[10];
    self->output.z += m[11];
}

extern "C" void fn_8019F03C(void* arg0) {
    f32 value = lbl_805622D0;
    *(u8*)((u8*)arg0 + 0x4C) = 0;
    *(f32*)((u8*)arg0 + 0x40) = value;
    *(f32*)((u8*)arg0 + 0x44) = value;
    *(f32*)((u8*)arg0 + 0x48) = value;
    *(f32*)((u8*)arg0 + 0x34) = value;
    *(f32*)((u8*)arg0 + 0x38) = value;
    *(f32*)((u8*)arg0 + 0x3C) = value;
}

extern "C" void fn_8019F064(void *arg0, void *arg1) {
    struct DispatchA { virtual void v0(); virtual void v1(); virtual void Call(void *); };
    struct DispatchB { virtual void u0(); virtual void u1(); virtual void Call(void *); };
    struct DispatchC { virtual void w0(); virtual void w1(); virtual void Call(void *); };
    s32 type = *(s32 *)((u8 *)arg1 + 0x18);
    switch (type) {
    case 'FLSR':
        fn_8019CE4C(arg0, arg1);
        return;
    case 'SPHR':
        fn_8019B068(arg0, arg1, 0, 0);
        return;
    case 'TUBE':
        fn_8019CE3C(arg0, (s32)arg1);
        return;
    case 'BOX ':
        fn_8019BD54(arg0, arg1, 0, 0);
        return;
    case 'GRUP':
        ((DispatchB *)arg1)->Call(arg0);
        return;
    case 'RING':
        fn_8019C854(arg0, arg1);
        return;
    case 'POLY':
        ((DispatchA *)arg1)->Call(arg0);
        return;
    case 'PMSH':
        ((DispatchC *)arg1)->Call(arg0);
        return;
    case 'RAGD':
        break;
    default:
        fn_802E317C(lbl_803335EC, type);
        break;
    }
}

extern "C" void fn_8019F1A4(void* arg0) {
    fn_8019AC44(arg0, (u8*)arg0 + 0x34, (u8*)arg0 + 0x40, *(f32*)((u8*)arg0 + 0x24));
}

extern "C" void fn_8019F1B4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_8019DDFC(arg1, arg2, arg3, arg4, (u8 *)arg0 + 0x34, arg0, *(f32 *)((u8 *)arg0 + 0x24));
}

#pragma scheduling invalid_target
extern "C" void fn_8019F1D4(void* arg0, f32* arg1, f32* arg2) {
    volatile f32 inputA[2];
    volatile f32 inputB[4];
    f32 width = *(f32*)((u8*)arg0 + 0x24);
    f32 scaleA = width * lbl_805622DC;
    f32 left = *(f32*)((u8*)arg0 + 0x34);
    f32 mid = *(f32*)((u8*)arg0 + 0x38);
    f32 scaleB = width * lbl_805622E0;
    f32 right = *(f32*)((u8*)arg0 + 0x3C);
    f32 x0 = left + scaleA;
    inputA[0] = width;
    f32 x1 = mid + scaleA;
    f32 x2 = right + scaleA;
    inputA[1] = width;
    arg1[0] = x0;
    f32 y0 = left + scaleB;
    f32 y1 = mid + scaleB;
    f32 y2 = right + scaleB;
    arg1[1] = x1;
    arg1[2] = x2;
    inputB[0] = width;
    inputB[1] = left;
    inputB[2] = mid;
    inputB[3] = right;
    arg2[0] = y0;
    arg2[1] = y1;
    arg2[2] = y2;
}
#pragma scheduling on
extern "C" void fn_8019F248(void *arg0) {
    extern f32 lbl_80562300;
    extern s32 lbl_8055E598;
    extern void fn_801E3FC8(void*, s32, f32);
    f32 var_f1 = *(f32*)((u8*)arg0 + 0x24);
    if (var_f1 < lbl_80562300) {
        var_f1 = lbl_80562300;
    }
    fn_801E3FC8((u8*)arg0 + 0x34, lbl_8055E598, var_f1);
}

extern "C" void fn_802E30C8(const char *, ...);
extern const char lbl_80333614[];
extern u8 lbl_80562374;
extern u8 lbl_80562375;
extern u8 lbl_80562376;
extern u8 lbl_80562377;
extern u8 lbl_80562378;
extern "C" void fn_8019F26C(s32 arg0, void *arg1) {
    u32 value = *(u32 *)((u8 *)arg1 + 0x18);
    switch (value) {
    case 'FLSR':
        fn_8019D19C((void *)arg0, arg1);
        return;
    case 'SPHR':
        fn_8019CE4C(arg1, (void *)arg0);
        return;
    case 'TUBE':
        fn_8019CF60(arg1, (void *)arg0);
        return;
    case 'BOX ':
        fn_8019D06C((void *)arg0, arg1, 0, 0);
        return;
    case 'GRUP':
    case 'POLY':
        ((Fn801A401CDispatch *)arg1)->Call((void *)arg0);
        return;
    case 'RING':
        fn_8019D378((void *)arg0, arg1);
        return;
    case 'RAGD':
        break;
    default: {
        u8 buffer[5] = {
            lbl_80562374,
            lbl_80562375,
            lbl_80562376,
            lbl_80562377,
            lbl_80562378
        };
        *(u32 *)buffer = *(u32 *)((u8 *)arg1 + 0x18);
        fn_802E30C8(lbl_80333614, buffer);
        return;
    }
    }
}

extern "C" void fn_8019F3D0(void) {

}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_8019F3D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8019F414(void *arg0) {
    extern f32 lbl_8056237C;
    extern void fn_8019EECC(void*, void*);
    extern void fn_8019EF00(void*);
    u32 sp[3];
    void *temp_r6;
    void *temp_r4;
    f32 x;
    f32 y;
    f32 z;
    f32 ybase;

    temp_r6 = *(void **)((u8*)arg0 + 0x54);
    temp_r4 = *(void **)((u8*)arg0 + 4);
    sp[0] = *(u32*)((u8*)temp_r6 + 0x30);
    sp[1] = *(u32*)((u8*)temp_r6 + 0x34);
    sp[2] = *(u32*)((u8*)temp_r6 + 0x38);
    x = ((f32*)sp)[0] - *(f32*)((u8*)temp_r4 + 0x30);
    x += *(f32*)((u8*)arg0 + 0x58);
    y = ((f32*)sp)[1] - *(f32*)((u8*)temp_r4 + 0x34);
    ybase = lbl_8056237C + *(f32*)((u8*)arg0 + 0x24);
    ybase += *(f32*)((u8*)temp_r6 + 0xC);
    y += ybase;
    z = ((f32*)sp)[2] - *(f32*)((u8*)temp_r4 + 0x38);
    ((f32*)sp)[0] = x;
    ((f32*)sp)[1] = y;
    ((f32*)sp)[2] = z;
    *(f32*)((u8*)arg0 + 0x28) = x;
    *(f32*)((u8*)arg0 + 0x2C) = y;
    *(f32*)((u8*)arg0 + 0x30) = z;
    if (temp_r4 != 0) fn_8019EECC(temp_r4, (u8*)arg0 + 0x28);
    fn_8019EF00(arg0);
}

#pragma scheduling invalid_target
extern "C" void fn_8019F4D4(void *arg0, void *arg1) {
    fn_8019EC84(arg0);
    f32 scale = -PSVECDotProduct(
        (const Vec *)((u8 *)*(void **)((u8 *)arg0 + 0xC) + 0xC),
        (const Vec *)arg1);
    void *vector = *(void **)((u8 *)arg0 + 0xC);
    struct Scratch {
        f32 pad0;
        f32 spC;
        f32 pad8[3];
        f32 sp1C;
        f32 sp20;
        f32 tail[3];
    };
    volatile Scratch scratch;
    scratch.sp20 = ((f32 *)arg1)[0] + ((f32 *)vector)[3] * scale;
    scratch.spC = ((f32 *)arg1)[1] + ((f32 *)vector)[4] * scale;
    scratch.sp1C = ((f32 *)arg1)[2] + ((f32 *)vector)[5] * scale;
}
#pragma scheduling on
extern "C" void fn_8019F560(void) {
    fn_8019F1A4();
}

extern "C" void *fn_8019F564(void *arg0,s32 arg1,void *arg2,s32 arg3,f32 a,f32 b,f32 c,f32 d,f32 e,f32 f) {
 extern void* lbl_80333A58;
 f32 z=lbl_805622D0,m=f; if(e>m)m=e;if(d>m)m=d;
 *(s32*)((u8*)arg0+0xC)=arg1;*(s32*)((u8*)arg0+4)=arg3;*(s32*)((u8*)arg0+8)=0;
 *(s32*)((u8*)arg0+0x18)=0x53504852;*(f32*)((u8*)arg0+0x10)=a;*(f32*)((u8*)arg0+0x14)=b;
 *(s32*)((u8*)arg0+0x20)=100;*(s32*)((u8*)arg0+0x1C)=0;*(void**)arg0=&lbl_80333B48;
 *(f32*)((u8*)arg0+0x24)=lbl_805622E8*m;
 *(f32*)((u8*)arg0+0x34)=z;*(f32*)((u8*)arg0+0x38)=z;*(f32*)((u8*)arg0+0x3C)=z;*(f32*)((u8*)arg0+0x40)=z;
 *(f32*)((u8*)arg0+0x44)=z;*(f32*)((u8*)arg0+0x48)=z;*(u8*)((u8*)arg0+0x4C)=0;*(f32*)((u8*)arg0+0x50)=z;
 *(f32*)((u8*)arg0+0x28)=*(f32*)arg2;*(f32*)((u8*)arg0+0x2C)=*(f32*)((u8*)arg2+4);*(f32*)((u8*)arg0+0x30)=*(f32*)((u8*)arg2+8);
 if(arg3)fn_8019EECC((void*)arg3,(Vec*)((u8*)arg0+0x28));
 *(void**)arg0=&lbl_80333A58;*(f32*)((u8*)arg0+0x54)=c;
 *(f32*)((u8*)arg0+0x58)=lbl_805622E8*d;*(f32*)((u8*)arg0+0x5C)=lbl_805622E8*e;*(f32*)((u8*)arg0+0x60)=lbl_805622E8*f;
 *(f32*)((u8*)arg0+0x64)=z;*(f32*)((u8*)arg0+0x68)=z;*(f32*)((u8*)arg0+0x6C)=z;*(f32*)((u8*)arg0+0x70)=z;
 *(f32*)((u8*)arg0+0x74)=z;*(f32*)((u8*)arg0+0x78)=z;*(f32*)((u8*)arg0+0x7C)=z;*(f32*)((u8*)arg0+0x80)=z;
 *(f32*)((u8*)arg0+0x84)=z;*(f32*)((u8*)arg0+0x88)=z;*(f32*)((u8*)arg0+0x8C)=z;*(f32*)((u8*)arg0+0x90)=z;
 *(f32*)((u8*)arg0+0x94)=z;*(f32*)((u8*)arg0+0x98)=z;*(f32*)((u8*)arg0+0x9C)=z;*(f32*)((u8*)arg0+0xA0)=z;
 *(f32*)((u8*)arg0+0xA4)=z;*(f32*)((u8*)arg0+0xA8)=z;*(f32*)((u8*)arg0+0xAC)=z;*(f32*)((u8*)arg0+0xB0)=z;
 *(f32*)((u8*)arg0+0xB4)=z;*(f32*)((u8*)arg0+0xB8)=z;*(f32*)((u8*)arg0+0xBC)=z;*(f32*)((u8*)arg0+0xC0)=z;return arg0;
}

extern "C" void fn_8019F6F0(void *arg0) {
    f32 value;
    fn_8019F03C(arg0);
    value = lbl_805622D0;
    *(f32 *)((u8 *)arg0 + 0x64) = value;
    *(f32 *)((u8 *)arg0 + 0x68) = value;
    *(f32 *)((u8 *)arg0 + 0x6C) = value;
    *(f32 *)((u8 *)arg0 + 0x70) = value;
    *(f32 *)((u8 *)arg0 + 0x74) = value;
    *(f32 *)((u8 *)arg0 + 0x78) = value;
    *(f32 *)((u8 *)arg0 + 0x7C) = value;
    *(f32 *)((u8 *)arg0 + 0x80) = value;
    *(f32 *)((u8 *)arg0 + 0x84) = value;
    *(f32 *)((u8 *)arg0 + 0x88) = value;
    *(f32 *)((u8 *)arg0 + 0x8C) = value;
    *(f32 *)((u8 *)arg0 + 0x90) = value;
    *(f32 *)((u8 *)arg0 + 0x94) = value;
    *(f32 *)((u8 *)arg0 + 0x98) = value;
    *(f32 *)((u8 *)arg0 + 0x9C) = value;
    *(f32 *)((u8 *)arg0 + 0xA0) = value;
    *(f32 *)((u8 *)arg0 + 0xA4) = value;
    *(f32 *)((u8 *)arg0 + 0xA8) = value;
    *(f32 *)((u8 *)arg0 + 0xAC) = value;
    *(f32 *)((u8 *)arg0 + 0xB0) = value;
    *(f32 *)((u8 *)arg0 + 0xB4) = value;
    *(f32 *)((u8 *)arg0 + 0xB8) = value;
    *(f32 *)((u8 *)arg0 + 0xBC) = value;
    *(f32 *)((u8 *)arg0 + 0xC0) = value;
}

extern "C" void fn_8019FF88(void* arg0) {
    ((void (*)(void))fn_8019EBC0)();
}

extern "C" void fn_8019FF8C(void* arg0) {
    fn_8019F03C();
    *(f32*)((u8*)arg0 + 0x28) = *(f32*)((u8*)arg0 + 0x54);
    *(f32*)((u8*)arg0 + 0x2C) = *(f32*)((u8*)arg0 + 0x58);
    *(f32*)((u8*)arg0 + 0x30) = *(f32*)((u8*)arg0 + 0x5C);
    *(u8*)((u8*)arg0 + 0x78) = 0;
}

#pragma small_data off
extern "C" void fn_8019FFD8(void* arg0, s32 arg1, s32 arg2) {
    f32 zeroFloat = lbl_805622D0;
    s32 zero = 0;
    s32 minusOne = -1;
    s32 tag = 0x47525550;
    s32 count = 0x64;
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(s32*)((u8*)arg0 + 4) = arg2;
    *(s32*)((u8*)arg0 + 8) = zero;
    *(s32*)((u8*)arg0 + 0x18) = tag;
    *(f32*)((u8*)arg0 + 0x10) = zeroFloat;
    *(f32*)((u8*)arg0 + 0x14) = zeroFloat;
    *(s32*)((u8*)arg0 + 0x20) = count;
    *(s32*)((u8*)arg0 + 0x1C) = zero;
    *(void**)arg0 = &lbl_803339B8;
    *(f32*)((u8*)arg0 + 0x170) = zeroFloat;
    *(f32*)((u8*)arg0 + 0x178) = zeroFloat;
    *(f32*)((u8*)arg0 + 0x16C) = zeroFloat;
    *(f32*)((u8*)arg0 + 0x168) = zeroFloat;
    *(f32*)((u8*)arg0 + 0x164) = zeroFloat;
    *(s32*)((u8*)arg0 + 0x174) = zero;
    *(s32*)((u8*)arg0 + 0x17C) = zero;
    *(s32*)((u8*)arg0 + 0x180) = minusOne;
}
#pragma small_data on
extern "C" void* fn_801A0040(void* arg0, s32 arg1) {
    struct ItemDummy {
        virtual void m0(s32) = 0;
    };
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_803339B8;
        void* entries = arg0;
        s32 i = 0;
        while (i < *(s32*)((u8*)arg0 + 0x174)) {
            void* item = *(void**)((u8*)entries + 0x24);
            if (item != 0)
                ((ItemDummy*)item)->m0(1);
            entries = (u8*)entries + 4;
            i++;
        }
        void* p = *(void**)((u8*)arg0 + 0x17c);
        if (p != 0)
            ((ItemDummy*)p)->m0(1);
        if (arg1 > 0)
            ((void (*)(void*))fn_80128668)(arg0);
    }
    return arg0;
}

extern "C" s32 fn_801A010C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A014C(void* arg0) {
    Fn801A014CDispatch* item = (Fn801A014CDispatch*)*(void**)((u8*)arg0 + 0x17C);
    item->Call();
}

extern s32 lbl_8055E3C4;
extern "C" void fn_801A0160(void* arg0) {
    s32 value = lbl_8055E3C4;
    if (value != *(s32*)((u8*)arg0 + 0x180)) {
        *(s32*)((u8*)arg0 + 0x180) = value;
        class Dummy {
        public:
            virtual void m0();
            virtual void m1();
            virtual void m2();
            virtual void m3();
        };
        register u8* entry = (u8*)arg0;
        register s32 i = 0;
        goto check;
    loop:
        Dummy* item = *(Dummy**)(entry + 0x24);
        item->m1();
        entry += 4;
        i++;
    check:
        if (i < *(s32*)((u8*)arg0 + 0x174))
            goto loop;
    }
}

extern "C" void fn_801A01E0(void* arg0, void* arg1, void* arg2) {
    volatile f32 inputA[2];
    volatile f32 inputB[4];
    volatile f32* first = (volatile f32*)arg1;
    volatile f32* second = (volatile f32*)arg2;
    f32 value = *(f32*)((u8*)arg0 + 0x178);
    f32 scaleA = value * lbl_805622DC;
    void* base = *(void**)((u8*)arg0 + 0xC);
    f32 x = *(f32*)((u8*)base + 0x24);
    f32 y = *(f32*)((u8*)base + 0x28);
    f32 scaleB = value * lbl_805622E0;
    f32 z = *(f32*)((u8*)base + 0x2C);
    f32 x0 = x + scaleA;
    f32 y0 = y + scaleA;
    inputA[0] = value;
    f32 z0 = z + scaleA;
    first[0] = x0;
    f32 x1 = x + scaleB;
    f32 y1 = y + scaleB;
    first[1] = y0;
    f32 z1 = z + scaleB;
    first[2] = z0;
    inputA[1] = value;
    inputB[0] = value;
    inputB[1] = x;
    inputB[2] = y;
    inputB[3] = z;
    second[0] = x1;
    second[1] = y1;
    second[2] = z1;
}

#pragma processor 750
#pragma optimization_level 2
#pragma scheduling reset
extern "C" void fn_801A0258(void *arg0, void *arg1, f32 farg0, f32 farg1, f32 farg2) {
    struct Object {
        void *vtable; s32 field4; s32 field8; s32 fieldC; f32 field10; f32 field14;
        s32 field18; s32 field1C; s32 field20; f32 field24; f32 field28; f32 field2C;
        f32 field30; f32 field34; f32 field38; f32 field3C; f32 field40; f32 field44;
        f32 field48; u8 field4C; u8 pad4D[3]; f32 field50;
    };
    Object *object = (Object *)fn_801284F8(0x54, lbl_80333640);
    if (object != 0) {
        s32 type = *(s32 *)((u8 *)arg0 + 4);
        object->fieldC = *(s32 *)((u8 *)arg0 + 0xC);
        f32 zero = lbl_805622D0;
        object->field4 = type;
        register f32 z;
        register f32 y;
        register f32 x;
        x = *(volatile f32 *)arg1;
        object->field8 = 0;
        y = *(volatile f32 *)((u8 *)arg1 + 4);
        object->field18 = 0x53504852;
        z = *(volatile f32 *)((u8 *)arg1 + 8);
        object->field10 = farg1;
        object->field14 = farg2;
        object->field20 = 100;
        object->field1C = 0;
        object->vtable = lbl_80333B48;
        object->field24 = farg0;
        object->field34 = zero; object->field38 = zero;
        object->field3C = zero; object->field40 = zero;
        object->field44 = zero; object->field48 = zero;
        object->field4C = 0; object->field50 = zero;
        object->field28 = x; object->field2C = y; object->field30 = z;
        if (type != 0) fn_8019EECC((void *)type, (Vec *)((u8 *)object + 0x28));
    }
    fn_801A0378(arg0, object);
}
#pragma scheduling on
#pragma processor reset
#pragma optimization_level reset

extern "C" void fn_801A0378(void* arg0, void* arg1) {
    extern f32 PSVECMag(const Vec*);
    extern f32 lbl_805622E8;
    struct EffectArg {
        u8 pad[0x24];
        f32 radius;
        Vec position;
    };
    class Dispatch {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual void Call(s32, void*);
    };
    EffectArg* effect = (EffectArg*)arg1;
    *(void**)((u8*)arg0 + (*(s32*)((u8*)arg0 + 0x174) << 2) + 0x24) = arg1;
    u8* record = (u8*)arg0 + (*(s32*)((u8*)arg0 + 0x174) << 4);
    *(f32*)(record + 0x64) = effect->position.x;
    *(f32*)(record + 0x68) = effect->position.y;
    *(f32*)(record + 0x6C) = effect->position.z;
    *(f32*)(record + 0x70) = effect->radius;
    ((Dispatch*)*(void**)((u8*)arg0 + (*(s32*)((u8*)arg0 + 0x174) << 2) + 0x24))->Call(*(s32*)((u8*)arg0 + 0x20), record);
    f32 length = PSVECMag(&effect->position);
    f32 value = length + effect->radius;
    value = lbl_805622E8 + value;
    if (value > *(f32*)((u8*)arg0 + 0x178)) {
        *(f32*)((u8*)arg0 + 0x178) = value;
        *(f32*)((u8*)arg0 + 0x170) = value;
    }
    *(s32*)((u8*)arg0 + 0x174) = *(s32*)((u8*)arg0 + 0x174) + 1;
}

extern "C" void fn_801A0444(void* arg0, void* arg1) {
    *(void**)((u8*)arg0 + 0x17C) = arg1;
    *(f32*)((u8*)arg0 + 0x164) = *(f32*)((u8*)arg1 + 0x24);
    *(f32*)((u8*)arg0 + 0x168) = *(f32*)((u8*)arg1 + 0x28);
    *(f32*)((u8*)arg0 + 0x16C) = *(f32*)((u8*)arg1 + 0x2C);
}

extern "C" void fn_801A0160(void*);
#pragma scheduling invalid_target
extern "C" s32 fn_801A1148(void *arg0, const f32 *vec, s32 arg2, f32 *arg3, s32 arg4) {
    f32 sp[3];
    void *base = *(void **)((u8 *)arg0 + 0xC);
    sp[0] = *(f32 *)((u8 *)base + 0x24) - vec[0];
    sp[1] = *(f32 *)((u8 *)base + 0x28) - vec[1];
    sp[2] = *(f32 *)((u8 *)base + 0x2C) - vec[2];
    f32 dot = PSVECDotProduct((const Vec *)sp, (const Vec *)(u32)arg2);
    f32 radius = *(f32 *)((u8 *)arg0 + 0x178);
    if (dot >= -radius && dot < *arg3 + radius) {
        fn_801A0160(arg0);
        void *entry = arg0;
        s32 found = 0;
        s32 i = 0;
        while (i < *(s32 *)((u8 *)arg0 + 0x174)) {
            void *item = *(void **)((u8 *)entry + 0x24);
            if (fn_8019DDFC((s32)vec, arg2, (s32)arg3, arg4,
                            (u8 *)item + 0x34,
                            *(void **)((u8 *)arg0 + 0xC),
                            *(f32 *)((u8 *)item + 0x24)) != 0) {
                found = 1;
            }
            entry = (u8 *)entry + 4;
            i++;
        }
        return found;
    }
    return 0;
}
#pragma scheduling on
extern "C" void fn_801A1250(void* arg0) {
    VTab1250** entries = (VTab1250**)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x174)) {
        entries[9]->v08();
        entries++;
        i++;
    }
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

extern "C" void fn_801A12C4(void *arg0, s32 arg1) {
    class FirstDispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14();
        virtual void call();
    };
    class EntryDispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14();
        virtual void call(s32);
    };

    *(s32 *)((u8 *)arg0 + 0x1C) = arg1;
    FirstDispatch *first = *(FirstDispatch **)((u8 *)arg0 + 0x17C);
    first->call();
    u8 *entries = (u8 *)arg0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x174)) {
        EntryDispatch *item = *(EntryDispatch **)(entries + 0x24);
        item->call(arg1);
        entries += 4;
        i++;
    }
}

extern "C" void fn_801A1358(void *arg0, s32 arg1) { *(s32 *)((u8 *)arg0 + 0x1C) = arg1; }

extern "C" void fn_801A1360(void* arg0, s32 arg1) {
    class Dispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void set(s32);
    };
    *(s32*)((u8*)arg0 + 0x20) = arg1;
    void* p = *(void**)((u8*)arg0 + 0x17C);
    ((Dispatch*)p)->set(arg1);
    u8* entries = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x174)) {
        void* item = *(void**)(entries + 0x24);
        ((Dispatch*)item)->set(arg1);
        entries += 4;
        i++;
    }
}

extern "C" void fn_801A13F4(void* arg0) {
    class Dispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16();
        virtual void Call();
    };
    void* p = *(void**)((u8*)arg0 + 0x17C);
    ((Dispatch*)p)->Call();
    u8* entries = (u8*)arg0;
    s32 i = 0;
    goto check;
loop:
    ((Dispatch*)*(void**)(entries + 0x24))->Call();
    entries += 4;
    i++;
check:
    if (i < *(s32*)((u8*)arg0 + 0x174)) goto loop;
}

extern "C" void fn_801A1474(void* arg0, f32 scale) {
    f32* src = (f32*)((u8*)arg0 + 0x64);
    u8* object = (u8*)arg0;
    s32 i = 0;
    volatile f32 tmp[3];
    void* dst;

    *(f32*)((u8*)arg0 + 0x178) = *(f32*)((u8*)arg0 + 0x170) * scale;
    goto check;

loop:
    f32 zRaw;
    f32 yRaw;
    f32 xRaw;
    f32 z;
    f32 y;
    f32 x;
    xRaw = src[0];
    i++;
    yRaw = src[1];
    x = xRaw * scale;
    zRaw = src[2];
    dst = *(void**)(object + 0x24);
    y = yRaw * scale;
    z = zRaw * scale;
    *(f32*)((u8*)dst + 0x28) = x;
    *(f32*)((u8*)dst + 0x2c) = y;
    *(f32*)((u8*)dst + 0x30) = z;

    f32 w = src[3] * scale;
    src += 4;
    dst = *(void**)(object + 0x24);
    object += 4;
    tmp[0] = x;
    tmp[1] = y;
    tmp[2] = z;
    *(f32*)((u8*)dst + 0x24) = w;

check:
    if (i < *(s32*)((u8*)arg0 + 0x174)) {
        goto loop;
    }

    dst = *(void**)((u8*)arg0 + 0x17c);
    f32 tailX = *(f32*)((u8*)arg0 + 0x164) * scale;
    f32 tailY = *(f32*)((u8*)arg0 + 0x168) * scale;
    f32 tailZ = *(f32*)((u8*)arg0 + 0x16c) * scale;
    *(f32*)((u8*)dst + 0x24) = tailX;
    *(f32*)((u8*)dst + 0x28) = tailY;
    *(f32*)((u8*)dst + 0x2c) = tailZ;
}

extern "C" void fn_8019ECC4(void);
__declspec(section ".data") extern void* lbl_80333968;
extern f32 lbl_80562370;
#pragma push
#pragma small_data off
extern "C" void* fn_801A1520(void* arg0, void* arg1, s32 arg2) {
    u8 temp_r6;
    u8 temp_r7;
    u8 temp_r8;
    u8 temp_r9;
    fn_8019ECC4();
    *(void**)arg0 = &lbl_80333968;
    if (arg2 != 0) {
        temp_r6 = *(u8*)((u8*)arg0 + 0x24);
        temp_r8 = *(u8*)((u8*)arg0 + 0x25);
        temp_r7 = *(u8*)((u8*)arg0 + 0x28);
        temp_r9 = *(u8*)((u8*)arg0 + 0x29);
        *(u8*)((u8*)arg0 + 0x24) = *(u8*)((u8*)arg0 + 0x27);
        *(u8*)((u8*)arg0 + 0x27) = temp_r6;
        *(u8*)((u8*)arg0 + 0x25) = *(u8*)((u8*)arg0 + 0x26);
        *(u8*)((u8*)arg0 + 0x26) = temp_r8;
        *(u8*)((u8*)arg0 + 0x28) = *(u8*)((u8*)arg0 + 0x2B);
        *(u8*)((u8*)arg0 + 0x2B) = temp_r7;
        *(u8*)((u8*)arg0 + 0x29) = *(u8*)((u8*)arg0 + 0x2A);
        *(u8*)((u8*)arg0 + 0x2A) = temp_r9;
        if (*(s32*)((u8*)arg0 + 0x20) == 0x3EB)
            *(f32*)((u8*)arg0 + 0x24) += lbl_80562370;
    }
    return arg0;
}
#pragma pop
extern f32 lbl_805622D0, lbl_805622D4, lbl_805622E0;
extern "C" s32 fn_801A15CC(void* arg0, Vec* arg1, Vec* arg2, f32* arg3, Vec* arg4) {
    f32 t0 = lbl_805622D0;
    f32 t1 = lbl_805622D0;
    Vec* mat = *(Vec**)((u8*)arg0 + 0xC);
    Vec* axis = (Vec*)((u8*)mat + 0x18);
    Vec* center = (Vec*)((u8*)mat + 0x24);
    if (fn_8019D484(arg1, arg2, center, axis, &t0, &t1) == lbl_805622D0) return 0;
    f32 extent = *(f32*)((u8*)arg0 + 0x28);
    if (extent < t1) extent = t1;
    if (extent > -*(f32*)((u8*)arg0 + 0x28)) extent = -*(f32*)((u8*)arg0 + 0x28);
    t1 = extent;
    if (t0 <= lbl_805622D0 || t0 >= *arg3) return 0;
    Vec p, q;
    p.x = arg1->x + arg2->x * t0;
    p.y = arg1->y + arg2->y * t0;
    p.z = arg1->z + arg2->z * t0;
    f32 t = (f32)extent;
    q.x = center->x + axis->x * t;
    q.y = center->y + axis->y * t;
    q.z = center->z + axis->z * t;
    if (PSVECSquareDistance(&p, &q) >= (*(f32*)((u8*)arg0 + 0x24) * *(f32*)((u8*)arg0 + 0x24))) return 0;
    arg4->x = p.x - q.x;
    arg4->y = p.y - q.y;
    arg4->z = p.z - q.z;
    f32 mag = PSVECMag(arg4);
    if (lbl_805622D4 > mag) mag = lbl_805622D4;
    f32 scale = lbl_805622E0 / mag;
    arg4->x *= scale; arg4->y *= scale; arg4->z *= scale;
    *arg3 = t0;
    return 1;
}

#pragma scheduling invalid_target
extern "C" void fn_801A17B8(void* arg0) {
    extern f32 lbl_8056234C;
    extern void fn_801E41D8(f32*, f32*, s32, f32, f32, void*, void*, f32, f32, f32, f32, f32, f32, f32, f32, f32);
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_r6;
    f32 temp_r7;
    void* temp_r8;

    temp_r8 = *(void**)((u8*)arg0 + 0xC);
    temp_f0 = *(f32*)((u8*)arg0 + 0x28);
    sp20 = *(f32*)((u8*)temp_r8 + 0x18);
    sp24 = *(f32*)((u8*)temp_r8 + 0x1C);
    temp_r7 = *(f32*)((u8*)temp_r8 + 0x24);
    sp28 = *(f32*)((u8*)temp_r8 + 0x20);
    temp_r6 = *(f32*)((u8*)temp_r8 + 0x28);
    sp2C = temp_r7;
    sp30 = temp_r6;
    sp34 = *(f32*)((u8*)temp_r8 + 0x2C);
    sp14 = sp2C + (sp20 * temp_f0);
    sp18 = sp30 + (sp24 * temp_f0);
    sp1C = sp34 + (sp28 * temp_f0);
    temp_f0_2 = -*(f32*)((u8*)arg0 + 0x28);
    temp_f3 = sp2C + (sp20 * temp_f0_2);
    temp_f2 = sp30 + (sp24 * temp_f0_2);
    sp8 = temp_f3;
    spC = temp_f2;
    sp10 = sp34 + (sp28 * temp_f0_2);
    fn_801E41D8(&sp14, &sp8, 0x40FFFF00, temp_r6, temp_r7, temp_r8, arg0,
                lbl_8056234C * *(f32*)((u8*)arg0 + 0x24),
                temp_f2, temp_f3, sp34, sp28, sp30, sp24, sp2C, sp20);
}
#pragma scheduling on
extern int lbl_80333918[64];
extern "C" void* fn_801A1520(void*, void*, s32);
#pragma scheduling off
extern "C" void** fn_801A1898(void** arg0) {
    ((void* (*)(void*))fn_801A1520)(arg0);
    *arg0 = &lbl_80333918;
    return arg0;
}

void fn_801A18D4(void* arg0, f32* arg1, f32* arg2) {
    f32 a, b, c, d, e, f, g, h, i, j, k, l;
    f32 x = *(f32*)((u8*)arg0+0x24);
    void* m = *(void**)((u8*)arg0+0xC);
    a=*(f32*)((u8*)m+0x20); b=*(f32*)((u8*)m+0x2C);
    c=*(f32*)((u8*)m+0x18); d=*(f32*)((u8*)m+0x1C);
    e=*(f32*)((u8*)m+0x24); f=*(f32*)((u8*)m+0x28);
    g=b+a*x; h=b-a*x; i=e+c*x; j=e-c*x; k=f+d*x; l=f-d*x;
    f32 lo0=g-x, lo1=h-x, lo2=i-x, lo3=j-x, lo4=k-x, lo5=l-x;
    f32 minx=lo0, miny=lo4, minz=lo2;
    if (minx>=lo1) minx=lo1;
    if (miny>=lo5) miny=lo5;
    if (minz>=lo3) minz=lo3;
    arg1[0]=minz; arg1[1]=miny; arg1[2]=minx;
    f32 hi0=j+x, hi1=l+x, hi2=h+x, hi3=g+x, hi4=k+x, hi5=i+x;
    f32 maxx=hi0, maxy=hi1, maxz=hi2;
    if (maxx<=hi3) maxx=hi3;
    if (maxy<=hi4) maxy=hi4;
    if (maxz<=hi5) maxz=hi5;
    arg2[0]=maxz; arg2[1]=maxy; arg2[2]=maxx;
}

extern "C" void fn_8019CF60(void*, void*);
extern "C" void fn_8019DC04(void*, void*);
extern "C" void fn_8019CE3C(void*, s32);
extern "C" void fn_802E30C8(const char*, ...);
extern "C" const char lbl_80333650[];
#pragma scheduling on
extern "C" void fn_801A1ABC(void* arg0, void* arg1) {
    s32 value = *(s32*)((u8*)arg1 + 0x18);
    switch (value) {
    case 'RAGD':
    case 'POLY':
    case 'RING':
        break;
    case 'FLSR':
        fn_8019CF60(arg0, arg1);
        break;
    case 'SPHR':
        fn_8019CE3C(arg1, (s32)arg0);
        break;
    case 'BOX ':
        fn_8019EA7C(arg0, arg1);
        break;
    case 'TUBE':
        fn_8019DC04(arg0, arg1);
        break;
    case 'GRUP':
        fn_8019EA7C(arg0, *(void**)((u8*)arg1 + 0x17C));
        break;
    default:
        fn_802E30C8(lbl_80333650, value);
        break;
    }
}
extern "C" void fn_801A1B9C(void* arg0) {
    volatile u32 local[15];
    void* mat = *(void**)((u8*)arg0 + 0xC);
    f32 w = *(f32*)((u8*)arg0 + 0x28);
    f32 neg_w = -w;
    volatile u32* words = (volatile u32*)mat;
    u32 v14 = words[6];
    u32 v18 = words[7];
    local[3] = v14;
    u32 v8 = words[9];
    local[4] = v18;
    u32 v1C = words[8];
    f32 f14 = *(volatile f32*)&local[3];
    local[5] = v1C;
    u32 vC = words[10];
    f32 f18 = *(volatile f32*)&local[4];
    local[0] = v8;
    u32 v10 = words[11];
    f32 f8 = *(volatile f32*)&local[0];
    local[1] = vC;
    f32 fC = *(volatile f32*)&local[1];
    local[2] = v10;
    f32 f10 = *(volatile f32*)&local[2];
    *(volatile f32*)&local[6] = lbl_805622D0;
    *(volatile f32*)&local[7] = lbl_805622D0;
    *(volatile f32*)&local[8] = lbl_805622D0;
    *(volatile f32*)&local[9] = f8 + f14 * neg_w;
    *(volatile f32*)&local[10] = fC + f18 * neg_w;
    *(volatile f32*)&local[11] = f10 + f14 * neg_w;
    *(volatile f32*)&local[12] = f8 + f14 * w;
    *(volatile f32*)&local[13] = fC + f18 * w;
    *(volatile f32*)&local[14] = f10 + f14 * w;
    f32 f = *(f32*)((u8*)arg0 + 0x24);
    fn_8019AC44(arg0, (void*)&local[12], (void*)&local[6], f);
    fn_8019AC44(arg0, (void*)&local[9], (void*)&local[6], f);
}

extern "C" void fn_801E44F4(void*, u32, f32, f32, f32);
#pragma scheduling invalid_target
extern "C" void fn_801A1CA0(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x20) < 1000) {
        f32 x = *(f32*)((u8*)arg0 + 0x24);
        f32 z = *(f32*)((u8*)arg0 + 0x28);
        fn_801E44F4(*(void**)((u8*)arg0 + 0xC), 0x40FFFF00, x, x, z);
    } else {
        f32 x = *(f32*)((u8*)arg0 + 0x24);
        f32 z = *(f32*)((u8*)arg0 + 0x28);
        fn_801E44F4(*(void**)((u8*)arg0 + 0xC), 0x4000FF80, x, x, z);
    }
}
#pragma scheduling on
extern char lbl_803338C0[];
extern "C" void* fn_801A1CE4(void *arg0, s32 arg1, s32 arg2) {
    u8 temp_r12, temp_r22, temp_r23, temp_r24, temp_r25;
    u8 temp_r26, temp_r27, temp_r28, temp_r29, temp_r30;
    fn_8019ECC4();
    *(void**)arg0 = &lbl_803338C0;
    if (arg2 != 0) {
        temp_r12 = *(u8*)((u8*)arg0 + 0x24);
        temp_r26 = *(u8*)((u8*)arg0 + 0x25);
        temp_r30 = *(u8*)((u8*)arg0 + 0x28);
        temp_r25 = *(u8*)((u8*)arg0 + 0x29);
        temp_r29 = *(u8*)((u8*)arg0 + 0x2C);
        temp_r24 = *(u8*)((u8*)arg0 + 0x2D);
        temp_r28 = *(u8*)((u8*)arg0 + 0x30);
        temp_r23 = *(u8*)((u8*)arg0 + 0x31);
        temp_r27 = *(u8*)((u8*)arg0 + 0x34);
        temp_r22 = *(u8*)((u8*)arg0 + 0x35);
        *(u8*)((u8*)arg0 + 0x24) = *(u8*)((u8*)arg0 + 0x27);
        *(u8*)((u8*)arg0 + 0x27) = temp_r12;
        *(u8*)((u8*)arg0 + 0x25) = *(u8*)((u8*)arg0 + 0x26);
        *(u8*)((u8*)arg0 + 0x26) = temp_r26;
        *(u8*)((u8*)arg0 + 0x28) = *(u8*)((u8*)arg0 + 0x2B);
        *(u8*)((u8*)arg0 + 0x2B) = temp_r30;
        *(u8*)((u8*)arg0 + 0x29) = *(u8*)((u8*)arg0 + 0x2A);
        *(u8*)((u8*)arg0 + 0x2A) = temp_r25;
        *(u8*)((u8*)arg0 + 0x2C) = *(u8*)((u8*)arg0 + 0x2F);
        *(u8*)((u8*)arg0 + 0x2F) = temp_r29;
        *(u8*)((u8*)arg0 + 0x2D) = *(u8*)((u8*)arg0 + 0x2E);
        *(u8*)((u8*)arg0 + 0x2E) = temp_r24;
        *(u8*)((u8*)arg0 + 0x30) = *(u8*)((u8*)arg0 + 0x33);
        *(u8*)((u8*)arg0 + 0x33) = temp_r28;
        *(u8*)((u8*)arg0 + 0x31) = *(u8*)((u8*)arg0 + 0x32);
        *(u8*)((u8*)arg0 + 0x32) = temp_r23;
        *(u8*)((u8*)arg0 + 0x34) = *(u8*)((u8*)arg0 + 0x37);
        *(u8*)((u8*)arg0 + 0x37) = temp_r27;
        *(u8*)((u8*)arg0 + 0x35) = *(u8*)((u8*)arg0 + 0x36);
        *(u8*)((u8*)arg0 + 0x36) = temp_r22;
    }
    return arg0;
}

extern "C" void fn_801A1DD4(void* arg0, void* arg1) {
    switch (*(s32*)((u8*)arg1 + 0x18)) {
    case 'FLSR':
        fn_8019D06C(arg1, arg0, 0, 0);
        break;
    case 'SPHR':
        fn_8019BD54(arg1, arg0, 0, 0);
        break;
    case 'TUBE':
        fn_8019EA7C(arg1, arg0);
        break;
    case 'GRUP':
        ((Fn801A401CDispatch*)arg1)->Call(arg0);
        break;
    }
}

extern "C" void fn_8019D06C(void*, void*, s32, s32);
extern "C" s32 fn_8019E2D0(s32, s32, s32, void*, f32, f32, f32);
#pragma paired off
#pragma paired_single off
extern "C" s32 fn_801A1E7C(void* arg0, s32 arg1, s32 arg2, s32 arg3, void* arg4) {
    register f32 c = *(f32*)((u8*)arg0 + 0x2c);
    register f32 b = *(f32*)((u8*)arg0 + 0x28);
    register f32 a = *(f32*)((u8*)arg0 + 0x24);
    void* result = ((VTab1A1E7C*)arg0)->Call();

    if (fn_8019E2D0(arg1, arg2, arg3, result, a, b, c)) {
        f32 middle = lbl_805622E0;
        f32 same = lbl_805622D0;
        *(f32*)arg4 = same;
        *((f32*)arg4 + 1) = middle;
        *((f32*)arg4 + 2) = same;
        return 1;
    }
    return 0;
}
#pragma paired_single reset
#pragma paired reset
extern "C" void fn_801A1F44(void* arg0, void* arg1) {
    struct V {
        virtual void* a0() = 0; virtual void* a1() = 0; virtual void* a2() = 0; virtual void* a3() = 0;
        virtual void* a4() = 0; virtual void* a5() = 0; virtual void* a6() = 0; virtual void* a7() = 0;
        virtual void* a8() = 0; virtual void* a9() = 0; virtual void* a10() = 0; virtual void* a11() = 0;
        virtual void* a12() = 0; virtual void* a13() = 0; virtual void* a14() = 0; virtual void* a15() = 0;
        virtual void* a16() = 0; virtual void* a17() = 0; virtual void* f() = 0;
    };
    void* result = ((V*)arg1)->f();
    volatile u32* words = (volatile u32*)result;
    u32 y = words[10];
    u32 x = words[9];
    *(u32*)arg0 = x;
    *(u32*)((u8*)arg0 + 4) = y;
    *(u32*)((u8*)arg0 + 8) = *(u32*)((u8*)result + 0x2C);
}

#pragma scheduling on
extern "C" void fn_801A1F98(void *arg0, f32 *min, f32 *max) {
    struct Work { volatile f32 point[3]; f32 gap; volatile f32 corners[24]; } workArea;
    register f32 x, y, z;
    z=*(f32 *)((char *)arg0+0x2C);
    VTab1A1E7C *shape=(VTab1A1E7C *)arg0;
    y=*(f32 *)((char *)arg0+0x28);
    x=*(f32 *)((char *)arg0+0x24);
    register f32 nx, ny, nz;
    ny=-y; nx=-x; nz=-z;
    workArea.corners[0]=x; workArea.corners[1]=y; workArea.corners[2]=z;
    workArea.corners[3]=nx; workArea.corners[4]=y; workArea.corners[5]=z;
    workArea.corners[6]=x; workArea.corners[7]=ny; workArea.corners[8]=z;
    workArea.corners[9]=nx; workArea.corners[10]=ny; workArea.corners[11]=z;
    workArea.corners[12]=x; workArea.corners[13]=y; workArea.corners[14]=nz;
    workArea.corners[15]=nx; workArea.corners[16]=y; workArea.corners[17]=nz;
    workArea.corners[18]=x; workArea.corners[19]=ny; workArea.corners[20]=nz;
    workArea.corners[21]=nx; workArea.corners[22]=ny; workArea.corners[23]=nz;
    volatile f32 *corner=workArea.corners;
    volatile f32 * volatile sameCorner=workArea.corners;
    volatile f32 *point=workArea.point;
    f32 *matrix=(f32 *)shape->Call();
    min[0]=matrix[9]; min[1]=matrix[10]; min[2]=matrix[11];
    matrix=(f32 *)shape->Call();
    max[0]=matrix[9]; max[1]=matrix[10]; max[2]=matrix[11];
    for (int i=0;i<8;i++) {
        matrix=(f32 *)shape->Call();
        fn801A1F98Transform(point,sameCorner,corner,matrix);
        point[0]+=matrix[9]; point[1]+=matrix[10]; point[2]+=matrix[11];
        if (min[0]<point[0]) min[0]=point[0];
        if (min[1]<point[1]) min[1]=point[1];
        if (min[2]<point[2]) min[2]=point[2];
        if (max[0]>point[0]) max[0]=point[0];
        if (max[1]>point[1]) max[1]=point[1];
        if (max[2]>point[2]) max[2]=point[2];
        corner+=3; sameCorner+=3;
    }
}

extern "C" void fn_801A22A4(void* arg0) {
    volatile u32* result = (volatile u32*)((VTab1A1E7C*)arg0)->Call();
    volatile u32 words[12];
    u32 value1;
    u32 value0;
    value0 = result[0];
    value1 = result[1];
    words[0] = value0;
    words[1] = value1;
    u32 value3;
    u32 value2;
    value2 = result[2];
    value3 = result[3];
    words[2] = value2;
    words[3] = value3;
    u32 value5;
    u32 value4;
    value4 = result[4];
    value5 = result[5];
    words[4] = value4;
    words[5] = value5;
    u32 value7;
    u32 value6;
    value6 = result[6];
    value7 = result[7];
    words[6] = value6;
    words[7] = value7;
    u32 value8 = result[8];
    words[8] = value8;
    u32 value9 = result[9];
    u32 value10 = result[10];
    words[9] = value9;
    words[10] = value10;
    u32 value11 = result[11];
    words[11] = value11;
    f32 tailZ = *(f32*)((u8*)arg0 + 0x2c);
    f32 tailY = *(f32*)((u8*)arg0 + 0x28);
    f32 tailX = *(f32*)((u8*)arg0 + 0x24);
    typedef void (*Fn801E44F4)(volatile u32*, u32, u32, f32, f32, f32);
    ((Fn801E44F4)fn_801E44F4)(words, 0x50000000, value9, tailX, tailY, tailZ);
}

#pragma scheduling invalid_target
extern "C" void* fn_801A2354(void* arg0, s32 arg1, void* arg2, s32 arg3, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    extern f32 lbl_80562300;
    extern char lbl_80333868[];
    f32 diffX = farg3 - lbl_80562300;
    f32 diffY = farg2 - lbl_80562300;
    f32 diffZ = farg4 - lbl_80562300;
    *(f32*)((u8*)arg0 + 0x10) = farg0;
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(s32*)((u8*)arg0 + 4) = arg3;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(u32*)((u8*)arg0 + 0x18) = 0x424F5820;
    *(f32*)((u8*)arg0 + 0x14) = farg1;
    *(s32*)((u8*)arg0 + 0x20) = 100;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(void**)arg0 = lbl_803338C0;
    *(f32*)((u8*)arg0 + 0x24) = diffY;
    *(f32*)((u8*)arg0 + 0x28) = diffX;
    *(f32*)((u8*)arg0 + 0x2C) = diffZ;
    *(s32*)((u8*)arg0 + 0x34) = 0;
    f32 dist = diffX * diffX + diffY * diffY + diffZ * diffZ;
    f64 distance = fn_8002F234(dist);
    volatile f32* input = (volatile f32*)arg2;
    f32 x = input[0];
    f32 y = input[1];
    f32 radius = lbl_80562300 + (f32)distance;
    f32 z = input[2];
    *(f32*)((u8*)arg0 + 0x38) = x;
    *(f32*)((u8*)arg0 + 0x30) = radius;
    *(void**)arg0 = lbl_80333868;
    *(f32*)((u8*)arg0 + 0x3C) = y;
    *(f32*)((u8*)arg0 + 0x40) = z;
    return arg0;
}
#pragma scheduling on
extern "C" s32 fn_801A2434(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A2474(void *self) {
    float *matrix = *(float **)((char *)self + 0xC);
    volatile float *dst = (float *)((char *)self + 0x68);
    volatile float *src = (float *)((char *)self + 0x38);
    float x, y, z, a, b, c;
    *(float *)((char *)self + 0x44) = matrix[0];
    *(float *)((char *)self + 0x48) = matrix[1];
    *(float *)((char *)self + 0x4C) = matrix[2];
    *(float *)((char *)self + 0x50) = matrix[3];
    *(float *)((char *)self + 0x54) = matrix[4];
    *(float *)((char *)self + 0x58) = matrix[5];
    *(float *)((char *)self + 0x5C) = matrix[6];
    *(float *)((char *)self + 0x60) = matrix[7];
    *(float *)((char *)self + 0x64) = matrix[8];
    if (dst == src) {
        x = *(float *)((char *)self + 0x38); y = *(float *)((char *)self + 0x3C); z = *(float *)((char *)self + 0x40);
        *(float *)((char *)self + 0x68) = (x * matrix[0] + y * matrix[3]) + z * matrix[6];
        *(float *)((char *)self + 0x6C) = (x * matrix[1] + y * matrix[4]) + z * matrix[7];
        *(float *)((char *)self + 0x70) = (x * matrix[2] + y * matrix[5]) + z * matrix[8];
    } else {
        a = *(float *)((char *)self + 0x38); b = *(float *)((char *)self + 0x3C); c = *(float *)((char *)self + 0x40);
        *(float *)((char *)self + 0x68) = (a * matrix[0] + b * matrix[3]) + c * matrix[6];
        *(float *)((char *)self + 0x6C) = (a * matrix[1] + b * matrix[4]) + c * matrix[7];
        *(float *)((char *)self + 0x70) = (a * matrix[2] + b * matrix[5]) + c * matrix[8];
        *(float *)((char *)self + 0x68) += matrix[9];
        *(float *)((char *)self + 0x6C) += matrix[10];
        *(float *)((char *)self + 0x70) += matrix[11];
    }
}

extern "C" char lbl_80333818[];
extern "C" void fn_801A2674(void*, s32, s32, f32);
#pragma scheduling invalid_target
extern "C" void* fn_801A25F8(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(s32*)((u8*)arg0 + 0x30) = arg2;
    *(s32*)((u8*)arg0 + 4) = arg3;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0x18) = 0x52414744;
    *(f32*)((u8*)arg0 + 0x10) = lbl_805622E0;
    *(f32*)((u8*)arg0 + 0x14) = lbl_805622E0;
    *(s32*)((u8*)arg0 + 0x20) = 0x64;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(void**)arg0 = lbl_80333818;
    ((void (*)(void*, s32, s32))fn_801A2674)(arg0, 0, -1);
    return arg0;
}
#pragma scheduling on
extern "C" void fn_801A2674(void* arg0, s32 arg1, s32 arg2, f32 arg3) {
    *(f32*)((u8*)arg0 + 0x24) = arg3;
    *(s32*)((u8*)arg0 + 0x28) = arg1;
    *(s32*)((u8*)arg0 + 0x2C) = arg2;
}

extern f32 lbl_805622E0;
extern "C" void fn_801A2684(void* arg0, f32* arg1, f32* arg2) {
    f32 sp10, spC, sp8;
    f32 temp_f0 = *(f32*)((u8*)arg0 + 0x24);
    void* temp_r3 = *(void**)((u8*)arg0 + 0xC);
    f32 temp_f1 = lbl_805622E0 * temp_f0;
    sp8 = lbl_805622E0;
    f32 temp_f2 = lbl_805622E0 * -temp_f0;
    spC = lbl_805622E0;
    sp10 = lbl_805622E0;
    arg1[0] = *(f32*)((u8*)temp_r3 + 0x24) + temp_f2;
    arg1[1] = *(f32*)((u8*)temp_r3 + 0x28) + temp_f2;
    arg1[2] = *(f32*)((u8*)temp_r3 + 0x2C) + temp_f2;
    arg2[0] = *(f32*)((u8*)temp_r3 + 0x24) + temp_f1;
    arg2[1] = *(f32*)((u8*)temp_r3 + 0x28) + temp_f1;
    arg2[2] = *(f32*)((u8*)temp_r3 + 0x2C) + temp_f1;
}

extern void fn_801C28A8(void*, void*, void*, void*, void*, s32, s32, void*);
void fn_801A26FC(void* arg0, void* arg1) {
    u32 type = *(u32*)((u8*)arg1 + 0x18);
    if ((type - 0x47525500U) == 0x5550U) {
        Vec delta;
        f32* a = *(f32**)((u8*)arg0 + 0xC);
        f32* b = *(f32**)((u8*)arg1 + 0xC);
        delta.x = a[9] - b[9];
        delta.y = a[10] - b[10];
        delta.z = a[11] - b[11];
        f32 d = PSVECDotProduct(&delta, &delta);
        f32 radius = *(f32*)((u8*)arg0 + 0x24) +
            ((f32 (*)(void*))(*(u32*)(*(u32*)arg1 + 0x3C)))(arg1);
        if (d < radius * radius) {
            void* x = *(void**)((u8*)arg1 + 0x17C);
            Vec out;
            fn_801C28A8(*(void**)((u8*)arg0 + 0x30), x, a, b, &out,
                         *(s32*)((u8*)arg0 + 0x28), *(s32*)((u8*)arg0 + 0x2C), 0);
        }
    } else if ((type - 0x424F5800U) == 0x5820U) {
    } else if ((type - 0x504F4C00U) == 0x4C59U) {
    }
}

extern "C" void* fn_801A2C9C(void* arg0) {
    return (u8*)arg0 + 0x44;
}

extern "C" f32 fn_801A2CA4(void* arg0) {
    return *(f32*)((u8*)arg0 + 0x178);
}

extern "C" void fn_801A2CAC(void *arg0) {
    extern s32 lbl_8055E598;
    extern void fn_801E3FC8(s32, s32, s32, f32);
    s32 temp_r5 = *(s32 *)((u8 *)arg0 + 0xC);
    fn_801E3FC8(temp_r5 + 0x24, lbl_8055E598, temp_r5, *(f32 *)((u8 *)arg0 + 0x24));
}

extern void fn_8019ECC4();
extern char lbl_803337C8;
extern void fn_801E3FC8(s32, s32, s32, f32);
extern s32 lbl_8055E598;
__declspec(section ".data") extern char lbl_803337C8;
extern "C" void* fn_801A2CC0(void* arg0, s32 arg1, s32 arg2) {
    u8 temp_r6;
    u8 temp_r7;
    u8 temp_r8;
    u8 temp_r9;
    fn_8019ECC4();
    *(void**)arg0 = &lbl_803337C8;
    if (arg2 != 0) {
        temp_r6 = *(u8*)((u8*)arg0 + 0x24);
        temp_r8 = *(u8*)((u8*)arg0 + 0x25);
        temp_r7 = *(u8*)((u8*)arg0 + 0x28);
        temp_r9 = *(u8*)((u8*)arg0 + 0x29);
        *(u8*)((u8*)arg0 + 0x24) = *(u8*)((u8*)arg0 + 0x27);
        *(u8*)((u8*)arg0 + 0x27) = temp_r6;
        *(u8*)((u8*)arg0 + 0x25) = *(u8*)((u8*)arg0 + 0x26);
        *(u8*)((u8*)arg0 + 0x26) = temp_r8;
        *(u8*)((u8*)arg0 + 0x28) = *(u8*)((u8*)arg0 + 0x2B);
        *(u8*)((u8*)arg0 + 0x2B) = temp_r7;
        *(u8*)((u8*)arg0 + 0x29) = *(u8*)((u8*)arg0 + 0x2A);
        *(u8*)((u8*)arg0 + 0x2A) = temp_r9;
    }
    return arg0;
}

extern "C" void fn_801A2D50(s32 arg0, void *arg1) {
    extern u8 lbl_8055E5A4;
    extern u8 lbl_8055E5A5;
    extern char lbl_80333448[];
    extern char lbl_8055A4C4[];
    char *messages = lbl_80333448;
    s32 kind = *(s32 *)((u8 *)arg1 + 0x18);
    switch (kind) {
    case 0x504F4C59:
        break;
    case 0x53504852:
        fn_8019C854(arg1, (void *)arg0);
        break;
    case 0x47525550: {
        u8 *entry = (u8 *)arg1;
        s32 i = 0;
        while (i < *(s32 *)((u8 *)arg1 + 0x174)) {
            fn_8019C854(*(void **)(entry + 0x24), (void *)arg0);
            entry += 4;
            i++;
        }
        break;
    }
    case 0x424F5820:
        if (!lbl_8055E5A4) {
            lbl_8055E5A4 = 1;
            fn_802E30C8(lbl_8055A4C4, messages + 0x22C);
        }
        break;
    case 0x52414744:
        if (!lbl_8055E5A5) {
            lbl_8055E5A5 = 1;
            fn_802E30C8(lbl_8055A4C4, messages + 0x254);
        }
        break;
    case 0x464C5352:
        fn_8019D378(arg1, (void *)arg0);
        break;
    default:
        fn_802E317C(messages + 0x280, kind);
        break;
    }
}

extern "C" void fn_801A2EC8(void) {

}

void fn_801A2ECC(void *obj, void *min, void *max) {
    float a = *(float *)((char *)obj + 0x24);
    float b = *(float *)((char *)obj + 0x28);
    float c = a + b;
    float x[8] = {-c,-c,-c,-c,c,c,c,c};
    float y[8] = {-c,-c,-c,c,c,c,-c,b};
    float z[8] = {-b,-b,c,c,c,c,c,b};
    float *m = *(float **)((char *)obj + 12);
    float *lo = (float *)min;
    float *hi = (float *)max;
    lo[0]=hi[0]=m[9]; lo[1]=hi[1]=m[10]; lo[2]=hi[2]=m[11];
    for (int i=0;i<8;i++) {
        float px = x[i]*m[0] + y[i]*m[3] + z[i]*m[6] + m[9];
        float py = x[i]*m[1] + y[i]*m[4] + z[i]*m[7] + m[10];
        float pz = x[i]*m[2] + y[i]*m[5] + z[i]*m[8] + m[11];
        if (lo[0] < px) lo[0]=px;
        if (lo[1] < py) lo[1]=py;
        if (lo[2] < pz) lo[2]=pz;
        if (hi[0] > px) hi[0]=px;
        if (hi[1] > py) hi[1]=py;
        if (hi[2] > pz) hi[2]=pz;
    }
}

extern "C" void fn_801A3174(void *arg0) {
    ((void (*)(s32, s32, f32))fn_801E3FC8)(*(s32*)((u8*)arg0 + 0xC) + 0x24, lbl_8055E598, *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg0 + 0x28));
}

extern char lbl_80333778[];
#pragma scheduling invalid_target
extern "C" void fn_801A3190(void *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4, void *arg5, f32 farg0, f32 farg1) {
    *(void**)arg0 = lbl_80333778;
    *(s32*)((u8*)arg0 + 4) = 0;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(f32*)((u8*)arg0 + 0x10) = farg0;
    *(f32*)((u8*)arg0 + 0x14) = farg1;
    *(s32*)((u8*)arg0 + 0x18) = 0x504F4C59;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(s32*)((u8*)arg0 + 0x20) = 100;
    *(s32*)((u8*)arg0 + 0xBC) = arg3;
    *(s32*)((u8*)arg0 + 0xDC) = 0;
    u8 *dst = (u8*)arg0;
    u8 *src = (u8*)arg2;
    for (s32 i = 0; i < *(s32*)((u8*)arg0 + 0xBC); i++) {
        s32 t0 = *(s32*)src;
        s32 t1 = *(s32*)(src + 4);
        *(s32*)(dst + 0x3C) = t0;
        s32 t2 = *(s32*)(src + 8);
        *(s32*)(dst + 0x40) = t1;
        f32 f = *(f32*)(src + 0xC);
        *(s32*)(dst + 0x44) = t2;
        *(f32*)(dst + 0x48) = f;
        src += 0x10;
        dst += 0x10;
    }
    f32 b2 = ((f32*)arg5)[2];
    f32 b1 = ((f32*)arg5)[1];
    f32 b0 = ((f32*)arg5)[0];
    f32 a2 = ((f32*)arg4)[2];
    f32 a1 = ((f32*)arg4)[1];
    f32 a0 = ((f32*)arg4)[0];
    *(f32*)((u8*)arg0 + 0x24) = a0;
    *(f32*)((u8*)arg0 + 0x28) = a1;
    *(f32*)((u8*)arg0 + 0x2C) = a2;
    *(f32*)((u8*)arg0 + 0x30) = b0;
    *(f32*)((u8*)arg0 + 0x34) = b1;
    *(f32*)((u8*)arg0 + 0x38) = b2;
}
#pragma scheduling on
extern "C" void fn_801A34D0(void *arg0, Vec *arg1, Vec *arg2) {
    extern f32 lbl_80562380;
    struct Bounds { u8 pad0[0xC]; f32 *matrix; u8 pad1[0x14]; Vec min; Vec max; };
    Bounds *box = (Bounds *)arg0;
    f32 sp1C;
    f32 sp18;
    f32 sp14[3];
    f32 sp10;
    f32 spC;
    f32 sp8[3];
    f32 *mat = box->matrix;
    if (&sp8[0] == &box->min.x) {
        f32 y = box->min.y;
        f32 x = *&box->min.x;
        f32 z = box->min.z;
        f32 y0 = y * mat[3];
        f32 y1 = y * mat[4];
        f32 x0 = x * mat[0];
        f32 x1 = x * mat[1];
        f32 y2 = y * mat[5];
        f32 x2 = x * mat[2];
        f32 z0 = z * mat[6];
        f32 z1 = z * mat[7];
        f32 z2 = z * mat[8];
        sp8[0] = x0 + y0 + z0;
        sp8[1] = x1 + y1 + z1;
        sp8[2] = x2 + y2 + z2;
    } else {
        sp8[0] = (mat[6] * box->min.z) + ((*&mat[0] * box->min.x) + (mat[3] * box->min.y));
        sp8[1] = (mat[7] * box->min.z) + ((*&mat[1] * box->min.x) + (mat[4] * box->min.y));
        sp8[2] = (mat[8] * box->min.z) + ((*&mat[2] * box->min.x) + (mat[5] * box->min.y));
    }
    sp8[0] += mat[9]; sp8[1] += mat[10]; sp8[2] += mat[11];
    f32 *mat2 = *(f32 * volatile *)((u8 *)box + 0xC);
    if (&sp14[0] == &box->max.x) {
        f32 temp_f6 = box->max.y;
        f32 temp_f0 = *&box->max.x;
        f32 temp_f7 = box->max.z;
        f32 q0 = temp_f0 * mat2[0] + temp_f6 * mat2[3];
        f32 q1 = temp_f0 * mat2[1] + temp_f6 * mat2[4];
        f32 q2 = temp_f0 * mat2[2] + temp_f6 * mat2[5];
        f32 r0 = temp_f7 * mat2[6];
        f32 r1 = temp_f7 * mat2[7];
        f32 r2 = temp_f7 * mat2[8];
        sp14[0] = q0 + r0; sp14[1] = q1 + r1; sp14[2] = q2 + r2;
    } else {
        sp14[0] = (mat2[6] * box->max.z) + ((*&mat2[0] * box->max.x) + (mat2[3] * box->max.y));
        sp14[1] = (mat2[7] * box->max.z) + ((*&mat2[1] * box->max.x) + (mat2[4] * box->max.y));
        sp14[2] = (mat2[8] * box->max.z) + ((*&mat2[2] * box->max.x) + (mat2[5] * box->max.y));
    }
    sp14[0] += mat2[9]; sp14[1] += mat2[10]; sp14[2] += mat2[11];
    f32 var_f4 = sp8[0];
    arg2->x = var_f4;
    arg2->y = sp8[1];
    arg2->z = sp8[2];
    arg1->x = var_f4;
    arg1->y = arg2->y;
    arg1->z = arg2->z;
    if (var_f4 < sp14[0]) var_f4 = sp14[0];
    arg1->x = var_f4;
    f32 var_f1 = arg1->y;
    if (var_f1 < sp14[1]) var_f1 = sp14[1];
    arg1->y = var_f1;
    f32 var_f2 = arg1->z;
    if (var_f2 < sp14[2]) var_f2 = sp14[2];
    arg1->z = var_f2;
    var_f1 = arg2->x;
    if (var_f1 > sp14[0]) var_f1 = sp14[0];
    arg2->x = var_f1;
    var_f1 = arg2->y;
    if (var_f1 > sp14[1]) var_f1 = sp14[1];
    arg2->y = var_f1;
    var_f1 = arg2->z;
    if (var_f1 > sp14[2]) var_f1 = sp14[2];
    arg2->z = var_f1;
    f32 pad = lbl_80562380;
    arg2->x = arg2->x + pad;
    arg2->z = arg2->z + pad;
    arg1->x = arg1->x - pad;
    arg1->z = arg1->z - pad;
}
#pragma fp_contract on
#pragma scheduling invalid_target
extern "C" f32 fn_801A3880(s32 arg0) {
    f32 first = PSVECDotProduct((Vec*)(arg0 + 0x30), (Vec*)(arg0 + 0x30));
    f32 second = PSVECDotProduct((Vec*)(arg0 + 0x24), (Vec*)(arg0 + 0x24));
    f32 selected = second > first ? second : first;
    return (f32)fn_8002F234(selected);
}
#pragma fp_contract off
#pragma scheduling on
extern float lbl_805622D0, lbl_805622DC, lbl_805623C0;
extern float PSVECDotProduct(float *, void *);
extern int fn_80198F64(void *, int, void *, float *, void *, float *, float);
extern int fn_8019A788(void *, int, void *, void *, int, int, float, float, float);
void fn_801A38E4(int arg0, void *arg1) {
    int type = *(int *)((char *)arg1 + 0x18);
    switch (type) {
    case 0x464c5352: {
        float axis[3] = {lbl_805622D0, lbl_805622DC, lbl_805622D0};
        float dot = PSVECDotProduct(axis, *(void **)((char *)arg1 + 0xc));
        float cur = *(float *)((char *)arg1 + 0x54);
        *(float *)((char *)arg1 + 0x24) = cur + dot * (*(float *)((char *)arg1 + 0x58) - cur);
    }
    case 0x53504852: {
        void *owner = *(void **)((char *)arg1 + 4);
        if (owner != 0) {
            void *node = *(void **)((char *)owner + 0xd0);
            while (node != 0) {
                float p[3], out1[3], out2[3], q[3] = {0.0f,0.0f,0.0f};
                float *m = (float *)((char *)owner + 0x3c);
                float *v = (float *)((char *)node + 4);
                q[0] = v[0]*m[0] + v[1]*m[3] + v[2]*m[6] + m[9];
                q[1] = v[0]*m[1] + v[1]*m[4] + v[2]*m[7] + m[10];
                q[2] = v[0]*m[2] + v[1]*m[5] + v[2]*m[8] + m[11];
                fn_80198F64(q,arg0,out1,p,out2,q,lbl_805623C0);
                node = *(void **)node;
            }
        }
        float p[3] = {lbl_805622D0,lbl_805622D0,lbl_805622D0}, a[3], b[3], c[3];
        if (fn_80198F64((char *)arg1+0x34,arg0,a,p,b,c,*(float *)((char *)arg1+0x24)))
            fn_8019A788(arg1,arg0,a,b,0,0,p[0],lbl_805622D0,lbl_805622D0);
        return;
    }
    }
}

extern f32 lbl_80562314;
extern "C" void fn_801E41D8(void*, void*, s32, f32);
void fn_801A3BE0(void* arg0, void* arg1) {
    f32 pos[3];
    f32 out[3];
    f32* entry = (f32*)((u8*)arg0 + 0x3C);
    void* matrix = *(void**)((u8*)arg0 + 0xC);
    s32 count = *(s32*)((u8*)arg0 + 0xBC);
    s32 i;
    pos[0] = *(f32*)((u8*)matrix + 0x24);
    pos[1] = *(f32*)((u8*)matrix + 0x28);
    pos[2] = *(f32*)((u8*)matrix + 0x2C);
    for (i = 0; i < count; i++, entry += 4) {
        f32 w = entry[3];
        f32 x = entry[0] * w;
        f32 y = entry[1] * w;
        f32 z = entry[2] * w;
        out[0] = x * *(f32*)matrix + y * *(f32*)((u8*)matrix + 0xC) + z * *(f32*)((u8*)matrix + 0x18);
        out[1] = x * *(f32*)((u8*)matrix + 4) + y * *(f32*)((u8*)matrix + 0x10) + z * *(f32*)((u8*)matrix + 0x1C);
        out[2] = x * *(f32*)((u8*)matrix + 8) + y * *(f32*)((u8*)matrix + 0x14) + z * *(f32*)((u8*)matrix + 0x20);
        out[0] += *(f32*)((u8*)matrix + 0x24);
        out[1] += *(f32*)((u8*)matrix + 0x28);
        out[2] += *(f32*)((u8*)matrix + 0x2C);
        fn_801E41D8(pos, out, lbl_8055E598, lbl_80562314);
    }
}

extern "C" void *fn_801A3DAC(void *arg0,s32 arg1,s32 arg2,s32 arg3) {
 extern s32 lbl_80333728;
 struct Vec{f32 x,y,z;}; s32 i=1,off=0xC; f32 x,y,z;
 *(s32*)((u8*)arg0+0xC)=arg1;*(s32*)((u8*)arg0+4)=arg3;*(s32*)((u8*)arg0+8)=0;
 *(s32*)((u8*)arg0+0x18)=0x504D5348;*(f32*)((u8*)arg0+0x10)=lbl_805622E0;*(f32*)((u8*)arg0+0x14)=lbl_805622E0;
 *(s32*)((u8*)arg0+0x20)=100;*(s32*)((u8*)arg0+0x1C)=0;*(void**)arg0=&lbl_80333728;
 void *obj=(void*)fn_801CFEAC((void*)arg2);*(void**)((u8*)arg0+0x24)=obj;
 Vec *v=(Vec*)*(void**)((u8*)obj+8);x=v->x;y=v->y;z=v->z;
 *(f32*)((u8*)arg0+0x34)=x;*(f32*)((u8*)arg0+0x38)=y;*(f32*)((u8*)arg0+0x3C)=z;
 *(f32*)((u8*)arg0+0x28)=x;*(f32*)((u8*)arg0+0x2C)=y;*(f32*)((u8*)arg0+0x30)=z;
 for(;i<*(s32*)((u8*)obj+0xC);i++,off+=0xC){Vec*p=(Vec*)((u8*)v+off+0xC);
 if(*(f32*)((u8*)arg0+0x30)<p->z)*(f32*)((u8*)arg0+0x30)=p->z;
 if(*(f32*)((u8*)arg0+0x2C)<p->y)*(f32*)((u8*)arg0+0x2C)=p->y;
 if(*(f32*)((u8*)arg0+0x28)<p->x)*(f32*)((u8*)arg0+0x28)=p->x;
 if(*(f32*)((u8*)arg0+0x3C)>p->z)*(f32*)((u8*)arg0+0x3C)=p->z;
 if(*(f32*)((u8*)arg0+0x38)>p->y)*(f32*)((u8*)arg0+0x38)=p->y;
 if(*(f32*)((u8*)arg0+0x34)>p->x)*(f32*)((u8*)arg0+0x34)=p->x;
 }return arg0;
}

extern "C" void fn_8019ECC4(void);
extern "C" void fn_801CFA48(void*);
__declspec(section ".data") extern s32 lbl_80333728;
extern "C" void* fn_801A3F5C(void* arg0, s32 arg1, s32 arg2) {
    fn_8019ECC4();
    *(void**)arg0 = &lbl_80333728;
    if (arg2 != 0) {
        *(void**)((u8*)arg0 + 0x24) = (u8*)arg0 + 0x40;
        fn_801CFA48((u8*)arg0 + 0x40);
    }
    return arg0;
}

#pragma push
#pragma small_data off
extern "C" void *__dt__Q28PSSystem7SeqHeapFv_801A3FB8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80333728;
        ((void (*)(void *))fn_801CFF14)(*(void **)((u8 *)arg0 + 0x24));
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma pop
extern "C" void fn_801A401C(void *arg0, void *arg1) {
    extern f32 lbl_8056234C;
    struct SPHRArg {
        u8 pad0[0x18];
        s32 tag;
        u8 pad1[8];
        f32 scale;
        u8 pad2[0xC];
        u8 data[1];
    };
    s32 tag = *(s32 *)((u8 *)arg1 + 0x18);
    if ((u32)(tag + 0xB8AE0000) == 0x5550U) {
        ((Fn801A401CDispatch *)arg1)->Call(arg0);
        return;
    }
    if ((u32)(tag + 0xACB00000) == 0x4852U) {
        u8 buffer[0x300];
        register u8 *current;
        register SPHRArg *source = (SPHRArg *)arg1;
        volatile s32 count = 0x40;
        register f32 factor = lbl_8056234C;
        register f32 scale = source->scale;
        fn_801CF080(*(s32 *)((u8 *)arg0 + 0x24), source->data, buffer,
                    (s32 *)&count, *(s32 *)((u8 *)arg0 + 0x0C),
                    factor * scale);
        current = buffer;
        register s32 i = 0;
        while (i < count) {
            fn_8019AA18(source, (s32)current, 0x6E, (s32)arg0);
            current += 0xC;
            i++;
        }
    }
}

#pragma scheduling invalid_target
extern "C" s32 fn_801A40F8(void *arg0, f32 *arg1, f32 *arg2, s32 arg3, f32 *arg4) {
    f32 stack[9];
    const f32 *input = arg1;
    register f32 dx = input[0];
    register f32 dy = input[1];
    f32 *matrix = (f32 *)*(void * volatile *)((u8 *)arg0 + 0xC);
    dx -= matrix[9];
    register f32 dz = input[2];
    stack[6] = dx;
    dy -= matrix[10];
    stack[7] = dy;
    dz -= matrix[11];
    stack[8] = dz;
    f32 vx = dx * matrix[0] + (dy * matrix[1] + dz * matrix[2]);
    f32 vy = dx * matrix[3] + (dy * matrix[4] + dz * matrix[5]);
    f32 vz = dx * matrix[6] + (dy * matrix[7] + dz * matrix[8]);
    stack[6] = vx;
    stack[7] = vy;
    stack[8] = vz;
    f32 *matrix2 = (f32 *)*(void * volatile *)((u8 *)arg0 + 0xC);
    f32 ax;
    f32 ay;
    f32 az;
    if (&stack[3] == arg2) {
        register f32 a = arg2[0];
        register f32 b = arg2[1];
        register f32 c = arg2[2];
        ax = a * matrix2[0] + (b * matrix2[1] + c * matrix2[2]);
        ay = a * matrix2[3] + (b * matrix2[4] + c * matrix2[5]);
        az = a * matrix2[6] + (b * matrix2[7] + c * matrix2[8]);
    } else {
        ax = arg2[0] * matrix2[0] + (arg2[1] * matrix2[1] + arg2[2] * matrix2[2]);
        ay = arg2[0] * matrix2[3] + (arg2[1] * matrix2[4] + arg2[2] * matrix2[5]);
        az = arg2[0] * matrix2[6] + (arg2[1] * matrix2[7] + arg2[2] * matrix2[8]);
    }
    stack[3] = ax;
    stack[4] = ay;
    stack[5] = az;
    typedef s32 (*Call)(s32, f32 *, f32 *, s32, f32 *);
    if (((Call)fn_801CF828)(*(s32 *)((u8 *)arg0 + 0x24), &stack[6], &stack[3], arg3, &stack[0]) != 0) {
        f32 *outMatrix = (f32 *)*(void **)((u8 *)arg0 + 0xC);
        if (arg4 == &stack[0]) {
            register f32 a = stack[0];
            register f32 b = stack[1];
            register f32 c = stack[2];
            vx = a * outMatrix[0] + (b * outMatrix[3] + c * outMatrix[6]);
            vy = a * outMatrix[1] + (b * outMatrix[4] + c * outMatrix[7]);
            vz = a * outMatrix[2] + (b * outMatrix[5] + c * outMatrix[8]);
            arg4[0] = vx;
            arg4[1] = vy;
            arg4[2] = vz;
        } else {
            arg4[0] = stack[0] * outMatrix[0] + (stack[1] * outMatrix[3] + stack[2] * outMatrix[6]);
            arg4[1] = stack[0] * outMatrix[1] + (stack[1] * outMatrix[4] + stack[2] * outMatrix[7]);
            arg4[2] = stack[0] * outMatrix[2] + (stack[1] * outMatrix[5] + stack[2] * outMatrix[8]);
        }
        return 1;
    }
    return 0;
}
#pragma scheduling on
extern "C" void fn_801A442C(void* arg0, void* arg1, void* arg2) {
    f32 z, y, x, c, b, a;
    x = *(f32*)((u8*)arg0 + 0x28);
    y = *(f32*)((u8*)arg0 + 0x2C);
    z = *(f32*)((u8*)arg0 + 0x30);
    *(f32*)((u8*)arg1 + 0x0) = x;
    a = *(f32*)((u8*)arg0 + 0x34);
    *(f32*)((u8*)arg1 + 0x4) = y;
    b = *(f32*)((u8*)arg0 + 0x38);
    *(f32*)((u8*)arg1 + 0x8) = z;
    c = *(f32*)((u8*)arg0 + 0x3C);
    *(f32*)((u8*)arg2 + 0x0) = a;
    *(f32*)((u8*)arg2 + 0x4) = b;
    *(f32*)((u8*)arg2 + 0x8) = c;
}

#pragma scheduling invalid_target
extern "C" f32 fn_801A4460(void* arg0) {
    register void* base = arg0;
    f32 first = PSVECDotProduct((const Vec*)((u8*)base + 0x34), (const Vec*)((u8*)base + 0x34));
    f32 second = PSVECDotProduct((const Vec*)((u8*)base + 0x28), (const Vec*)((u8*)base + 0x28));
    f32 result;
    if (second > first) {
        result = second;
    } else {
        result = first;
    }
    return fn_8002F234(result);
}
#pragma scheduling on
extern "C" void fn_801A44C4(void* arg0) {
    fn_801CFF18(*(s32*)((u8*)arg0 + 0x24), *(s32*)((u8*)arg0 + 0xC));
}

extern "C" void fn_801A44D4(void* arg0) {
    register s32* r29 = (s32*)arg0;
    register s32 r30 = 0;
    register s32 r31 = 0;
    goto check;
loop:
    fn_801A49FC(*(s32*)((u8*)r29[1] + r30));
    r30 += 4;
    r31++;
check:
    if (r31 < r29[0]) goto loop;
}

#pragma scheduling invalid_target
extern "C" void fn_801A4538(void* arg0) {
    fn_8012C4E4(arg0, &fn_801A44D4, 0);
}

extern "C" s32 fn_8012C370(s32, s32*, s32, s32, s32, s32);
extern "C" void fn_8019EB14(s32, s32);
extern "C" void fn_801A4768(s32*, s32);
extern "C" void fn_801A4780(s32*, s32);
extern "C" void fn_801A4798(s32*, s32);
extern "C" void fn_801A47B0(s32*, s32);
extern "C" void fn_801A4B5C(s32);
extern "C" void fn_801A4538(void*);
extern "C" void* fn_801A4548(s32 arg0) {
    s32 size;
    u8 ok = 0;
    u8* p = (u8*)((s32 (*)(s32, s32, s32*, s32, s32, s32))fn_8012C370)(arg0, 0x534F424C, &size, 0, 0, (s32)&ok);
    if (p && ok) {
        u8 t;
        t=p[0]; p[0]=p[3]; p[3]=t;
        t=p[1]; p[1]=p[2]; p[2]=t;
        t=p[8]; p[8]=p[11]; p[11]=t;
        t=p[9]; p[9]=p[10]; p[10]=t;
        t=p[4]; p[4]=p[7]; p[7]=t;
        t=p[5]; p[5]=p[6]; p[6]=t;
        t=p[12]; p[12]=p[15]; p[15]=t;
        t=p[13]; p[13]=p[14]; p[14]=t;
        t=p[16]; p[16]=p[19]; p[19]=t;
        t=p[17]; p[17]=p[18]; p[18]=t;
        fn_801A4768((s32*)(p+4), (s32)p);
        fn_801A4780((s32*)(p+16), (s32)p);
        fn_801A4798((s32*)(p+12), (s32)p);
        for (s32 i=0; i<*(s32*)p; i++) {
            u8* q=(u8*)*(s32*)(p+4)+i*4;
            t=q[0]; q[0]=q[3]; q[3]=t;
            t=q[1]; q[1]=q[2]; q[2]=t;
            fn_801A47B0((s32*)q, (s32)p);
        }
        for (s32 i=0; i<*(s32*)(p+8); i++) {
            u8* q=(u8*)*(s32*)(p+12)+i*2;
            t=q[0]; q[0]=q[1]; q[1]=t;
        }
        fn_8019EB14(*(s32*)(p+16), 0);
        for (s32 i=0; i<*(s32*)p; i++) {
            s32 q=*(s32*)(*(s32*)(p+4)+i*4);
            if (q) fn_801A4B5C(q+0x4c);
        }
        *(void**)(p+20)=(void*)fn_801A4538;
    }
    return p;
}

#pragma scheduling on
extern "C" void fn_801A4768(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

extern "C" void fn_801A4780(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

extern "C" void fn_801A4798(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

extern "C" void fn_801A47B0(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

#pragma opt_tail_call on
extern "C" void fn_801A47C8(void* arg0) {
    s32 limit = *(s32*)arg0;
    volatile s32** ptrs = *(volatile s32***)((u8*)arg0 + 4);
    for (s32 i = 0; i < limit; i++) {
        ((u8*)ptrs[i])[0x40] = 1;
    }
}

#pragma opt_tail_call on
extern "C" void fn_801A47FC(void* arg0) {
    register s32* r29 = (s32*)arg0;
    register s32 r30 = 0;
    register s32 r31 = 0;
    if (!r29) return;
    goto check;
loop:
    fn_801A49E8((void*)(*(s32*)(r29[1] + r31)));
    r31 += 4;
    r30++;
check:
    if (r30 < r29[0]) goto loop;
}

#pragma opt_tail_call on
extern "C" void fn_801A4868(void* arg0, u8 arg1) {
    if (*(u8*)((u8*)arg0 + 0x40) != arg1) {
        struct Local {
            s32 value;
            u8 type;
        } local;
        local.value = *(s32*)((u8*)arg0 + 0x38);
        local.type = arg1;
        fn_801796EC(12, (s32*)&local.value, 8);
        *(u8*)((u8*)arg0 + 0x40) = arg1;
    }
}

extern "C" void fn_801A48C8(void* arg0) {
    struct VTable {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void Call(void*, void*);
    };
    VTable* ptr = *(VTable**)((u8*)arg0 + 0x48);
    ptr->Call(&lbl_8055A508, &lbl_8055A510);
}

extern "C" void fn_801EA1E0(void*, s32, f32, f32);
void fn_801A48E4(void* arg0) {
    struct Matrix { virtual void v0(); virtual void update(); };
    u8* obj = (u8*)arg0;
    s32 type;
    void* mat;
    f32 scale;
    volatile f32 out[3];
    *(u8*)(obj + 0x40) = 1;
    ((Matrix*)*(void**)(obj + 0x3C))->update();
    type = *(s32*)((u8*)*(void**)(obj + 0x3C) + 0x18);
    if (type == 0x53504852) {
        mat = *(void**)(obj + 0x3C);
        fn_801EA1E0((u8*)mat + 0x38, 0, *(f32*)((u8*)mat + 0x34), *(f32*)((u8*)mat + 0x3C));
        fn_801EA1E0(obj + 0x2C, 0, *(f32*)(obj + 0x28), *(f32*)(obj + 0x30));
    }
    if (type == 0x54554245) {
        scale = *(f32*)(obj + 0x20) > lbl_805622D0 ? lbl_805622DC : lbl_805622E0;
        f32 mul = *(f32*)((u8*)*(void**)(obj + 0x3C) + 0x28) * scale;
        f32 x = *(f32*)(obj + 0x28) + *(f32*)(obj + 0x1C) * mul;
        f32 z = *(f32*)(obj + 0x30) + *(f32*)(obj + 0x24) * mul;
        f32 y = *(f32*)(obj + 0x2C) + *(f32*)(obj + 0x20) * mul;
        out[0] = x;
        out[1] = y;
        out[2] = z;
        fn_801EA1E0(obj + 0x2C, 0, x, z);
    }
}

void fn_801A49E8(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x48) != 0) {
        fn_801D0650();
    }
}

extern "C" void fn_801D06C4(void);
extern "C" void fn_8019BD54(void*, void*, s32, s32);
extern "C" void fn_8019D06C(void*, void*, s32, s32);
extern "C" s32 fn_8019EA7C(void*, void*);
extern f32 lbl_8056237C;
extern f32 lbl_80562300;
extern void fn_8019EECC(void*, void*);
extern void fn_8019EF00(void*);
extern void fn_801E3FC8(void*, s32, f32);
void fn_801A49FC(s32 arg0) {
    if (*(s32*)((u8*)arg0 + 0x48) != 0) {
        fn_801D06C4();
    }
}

#pragma scheduling invalid_target
extern "C" void fn_801A4A10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (*(u8*)((u8*)arg0 + 0x40)) {
        fn_801D2414();
        if (*(s32*)((u8*)arg0 + 0x48)) {
            fn_801D0738((void*)arg0, (void*)arg1, (void*)arg2, (void*)arg3);
        }
    }
}
#pragma scheduling on
extern "C" void fn_801A4A8C(void* arg0, s32 arg1, s32 arg2, void* arg3, u32* arg4, s32 arg5, s32 arg6) {
    struct VTable2C {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void Call(void*, s32, s32) = 0;
    };
    register void* vtable = lbl_803336F8;
    s32 t11; s32 t10; s32 t9; s32 t8; s32 t7; s32 t6;
    s32 t5; s32 t4; s32 t3; s32 t2; s32 t1; s32 t0;
    t0 = arg4[0]; t1 = arg4[1]; t2 = arg4[2]; t3 = arg4[3];
    t4 = arg4[4]; t5 = arg4[5]; t6 = arg4[6]; t7 = arg4[7];
    t8 = arg4[8]; t9 = arg4[9]; t10 = arg4[10]; t11 = arg4[11];

    *(void**)arg0 = vtable;
    *(s32*)((u8*)arg0 + 4) = t0;
    *(s32*)((u8*)arg0 + 8) = t1;
    *(s32*)((u8*)arg0 + 0xC) = t2;
    *(s32*)((u8*)arg0 + 0x10) = t3;
    *(s32*)((u8*)arg0 + 0x14) = t4;
    *(s32*)((u8*)arg0 + 0x18) = t5;
    *(s32*)((u8*)arg0 + 0x1C) = t6;
    *(s32*)((u8*)arg0 + 0x20) = t7;
    *(s32*)((u8*)arg0 + 0x24) = t8;
    *(s32*)((u8*)arg0 + 0x28) = t9;
    *(s32*)((u8*)arg0 + 0x2C) = t10;
    *(s32*)((u8*)arg0 + 0x30) = t11;
    *(s32*)((u8*)arg0 + 0x34) = arg2;
    *(s32*)((u8*)arg0 + 0x38) = arg1;
    *(void**)((u8*)arg0 + 0x3C) = arg3;
    *(s32*)((u8*)arg0 + 0x48) = arg5;

    ((VTable2C*)arg3)->Call(arg0, arg2, (s32)arg3);
    fn_801A48E4(arg0);
}

#pragma push
#pragma small_data off
extern "C" void fn_801A4E28(void) {
    lbl_8055E5A0 = fn_801CFEAC(&lbl_803336EC[0]);
}
#pragma pop
extern "C" void fn_801A4E54(void) {
    if (lbl_8055E5A0 != 0) {
        ((void (*)(s32))fn_801CFF14)(lbl_8055E5A0);
        lbl_8055E5A0 = 0;
    }
}

extern "C" void fn_801D0650(void);
extern s32 lbl_8055E5A0;
extern void fn_801CFF14(void);
extern s32 fn_801CF828(s32, s32, s32, s32, s32);
extern "C" s32 fn_801A4E88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32* arg4) {
    register s32 a0 = arg0;
    register s32 a1 = arg1;
    register s32 a2 = arg2;
    register s32* out = arg4;
    s32 result = 0;
    if (lbl_8055E5A0 != 0 && fn_801CF828(lbl_8055E5A0, a0, a1, a2, arg3) != 0) {
        *out = 0x6E;
        result = 1;
    }
    return result;
}

extern "C" s32 fn_801A4F00(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F40(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F80(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4FC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5000(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5040(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5080(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A50C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" f32 fn_801A5100(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" void fn_801A5108(void* arg0) {
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

extern "C" f32 fn_801A5114(void *arg0) {
    return ((f32 *)arg0)[0x30 / 4];
}

extern "C" f32 fn_801A511C(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" float fn_801A5124(void* arg0) {
    return *(float*)((char*)arg0 + 0x28);
}

extern "C" s32 fn_801A512C(void) {
    return 0;
}

extern "C" s32 fn_801A5134(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5174(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x48);
}

extern "C" s32 fn_801A517C(s32 arg0) {
    return arg0 + 0x28;
}

extern "C" u8 fn_801A5184(void *arg0) { return *((u8*)arg0 + 0x40); }

extern "C" void fn_801A4868(void*, u8);

extern "C" void fn_801A518C(void) {
    ((void (*)(void))fn_801A4868)();
}

extern "C" void fn_801A5190(void* arg0) {
    VTab19* p = *(VTab19**)((u8*)arg0 + 0x3C);
    if (p == NULL) {
        return;
    }
    p->v14();
}

extern "C" s32 fn_801A51B0(void* arg0) {
    void* obj = *(void**)((u8*)arg0 + 0x3C);
    if (obj != NULL) {
        return *(s32*)((u8*)obj + 0x20);
    }
    return -1;
}

extern "C" s32 fn_801A51CC(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x34);
}

extern "C" void fn_801A51D4(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0x34) = arg1;
}
extern void fn_8019ECC4(void);
extern void* lbl_80333968;
extern f32 lbl_80562370;
typedef void (*VFunc)(void*);
typedef void (*VFuncArg)(void*, s32);
extern f32 lbl_805622DC;
class Fn8019E874Dispatch {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual Vec* GetVector();
};


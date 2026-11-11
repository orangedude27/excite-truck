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
extern f32 lbl_8056231C, lbl_80562320, lbl_80562324, lbl_80562328, lbl_80562330, lbl_805622D4, lbl_8056232C, lbl_805622D8;
extern s32 lbl_8055E5A0;
extern "C" s32 fn_801CF080(s32, void*, void*, s32*, s32, f32);
extern "C" s32 fn_8019A820(void*, void*, s32, s32, s32, f32);
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
extern f32 lbl_80562314;
extern f32 lbl_80562318;
extern f32 lbl_8056235C, lbl_80562360, lbl_80562364, lbl_80562368;
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
extern "C" void fn_801D2414(void);
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

extern "C" f64 __fabs(f64);
extern "C" int fn_80198F64(void *arg0, int arg1, void *arg2, float *arg3, void *arg4, float *arg5, float farg0) {
    f32 *pt = (f32 *)arg0;
    u8 *obj = (u8 *)arg1;
    f32 *outPos = (f32 *)arg2;
    f32 *outDepth = arg3;
    f32 *outDir = (f32 *)arg4;
    f32 *inVec = (f32 *)arg5;
    f32 radius = farg0;
    f32 *m = *(f32 **)(obj + 0xC);
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp48[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    s32 sp20[3];
    f32 sp14[3];
    f32 sp8[3];
    f32 sp68[8][4];
    f32 x = pt[0] - m[9];
    f32 y = pt[1] - m[10];
    f32 z = pt[2] - m[11];
    f32 nx = z * m[2] + (x * m[0] + y * m[1]);
    f32 ny = z * m[5] + (x * m[3] + y * m[4]);
    f32 nz = z * m[8] + (x * m[6] + y * m[7]);
    sp5C[0] = x; sp5C[1] = y; sp5C[2] = z;
    sp5C[0] = nx; sp5C[1] = ny; sp5C[2] = nz;
    sp44[0] = *(f32 *)(obj + 0x30);
    sp50[0] = *(f32 *)(obj + 0x24);
    sp50[1] = *(f32 *)(obj + 0x28);
    sp50[2] = *(f32 *)(obj + 0x2C);
    sp48[0] = *(f32 *)(obj + 0x34);
    sp48[1] = *(f32 *)(obj + 0x38);
    if (nx > sp44[0] + radius) return 0;
    if (ny > sp48[0] + radius) return 0;
    if (nz > sp48[1] + radius) return 0;
    if (nx < sp50[0] - radius) return 0;
    if (ny < sp50[1] - radius) return 0;
    if (nz < sp50[2] - radius) return 0;

    if ((f32 *)sp38 == inVec) {
        sp38[0] = inVec[2] * m[2] + (inVec[0] * m[0] + inVec[1] * m[1]);
        sp38[1] = inVec[2] * m[5] + (inVec[0] * m[3] + inVec[1] * m[4]);
        sp38[2] = inVec[2] * m[8] + (inVec[0] * m[6] + inVec[1] * m[7]);
    } else {
        sp38[0] = inVec[2] * m[2] + (inVec[0] * m[0] + inVec[1] * m[1]);
        sp38[1] = inVec[2] * m[5] + (inVec[0] * m[3] + inVec[1] * m[4]);
        sp38[2] = inVec[2] * m[8] + (inVec[0] * m[6] + inVec[1] * m[7]);
    }

    {
        f32 var_f31 = lbl_805622D0;
        u8 *var_r24 = obj + 0x3C;
        s32 var_r31 = 0;
        s32 var_r25 = 0;
        s32 var_r23 = 0;
        while (var_r23 < *(s32 *)(obj + 0xBC)) {
            f32 temp_f28 = (f32)__fabs((f64)PSVECDotProduct((Vec *)sp38, (Vec *)var_r24));
            f32 temp_f2 = (PSVECDotProduct((Vec *)sp5C, (Vec *)var_r24) - *(f32 *)(var_r24 + 0xC)) + temp_f28;
            if (temp_f2 >= lbl_805622D4) {
                f32 *dst = (f32 *)((u8 *)sp68 + var_r25);
                dst[0] = *(f32 *)(var_r24 + 0);
                var_r31 += 1;
                dst[1] = *(f32 *)(var_r24 + 4);
                var_r25 += 0x10;
                var_f31 += temp_f2 * temp_f2;
                dst[2] = *(f32 *)(var_r24 + 8);
                dst[3] = temp_f2;
            }
            var_r24 += 0x10;
            var_r23 += 1;
        }
        {
            u8 *var_r24_2 = obj + 0xC0;
            s32 var_r25_2 = var_r31 * 0x10;
            s32 var_r23_2 = 0;
            while (var_r23_2 < *(s32 *)(obj + 0xDC)) {
                f32 t;
                f32 mag;
                sp2C[0] = sp5C[0] - *(f32 *)(var_r24_2 + 0);
                sp2C[1] = sp5C[1] - *(f32 *)(var_r24_2 + 4);
                sp2C[2] = sp5C[2] - *(f32 *)(var_r24_2 + 8);
                t = -PSVECDotProduct((Vec *)sp2C, (Vec *)(var_r24_2 + 0xC));
                sp2C[0] += *(f32 *)(var_r24_2 + 0xC) * t;
                sp2C[1] += *(f32 *)(var_r24_2 + 0x10) * t;
                sp2C[2] += *(f32 *)(var_r24_2 + 0x14) * t;
                mag = PSVECMag((Vec *)sp2C);
                {
                    f32 sep = *(f32 *)(var_r24_2 + 0x18) - mag;
                    if (mag > lbl_805622D8 && sep > lbl_805622D4) {
                        f32 inv = lbl_805622DC / mag;
                        f32 *dst = (f32 *)((u8 *)sp68 + var_r25_2);
                        var_r31 += 1;
                        dst[0] = sp2C[0] * inv;
                        var_r25_2 += 0x10;
                        dst[1] = sp2C[1] * inv;
                        var_f31 += sep * sep;
                        dst[2] = sp2C[2] * inv;
                        dst[3] = sep;
                    }
                }
                var_r24_2 += 0x1C;
                var_r23_2 += 1;
            }
        }
        if (var_r31 == 0) return 0;
        {
            f32 invsum = lbl_805622E0 / var_f31;
            f32 *p = (f32 *)sp68;
            s32 i = var_r31;
            u32 r;
            sp20[0] = *(s32 *)&sp5C[0]; sp20[1] = *(s32 *)&sp5C[1]; sp20[2] = *(s32 *)&sp5C[2];
            if (i > 0) {
                r = (u32)i >> 1;
                if (r != 0) {
                    do {
                        f32 w0 = p[3];
                        f32 w1 = p[7];
                        f32 s0 = -w0 * (invsum * (w0 * w0));
                        f32 s1 = -w1 * (invsum * (w1 * w1));
                        *(f32 *)&sp20[0] = *(f32 *)&sp20[0] + p[0] * s0;
                        *(f32 *)&sp20[1] = *(f32 *)&sp20[1] + p[1] * s0;
                        *(f32 *)&sp20[2] = *(f32 *)&sp20[2] + p[2] * s0;
                        *(f32 *)&sp20[0] = *(f32 *)&sp20[0] + p[4] * s1;
                        *(f32 *)&sp20[1] = *(f32 *)&sp20[1] + p[5] * s1;
                        *(f32 *)&sp20[2] = *(f32 *)&sp20[2] + p[6] * s1;
                        p += 8;
                        r--;
                    } while (r != 0);
                    i = var_r31 & 1;
                    if (i == 0) goto done_acc;
                }
                do {
                    f32 w = p[3];
                    f32 s = -w * (invsum * (w * w));
                    *(f32 *)&sp20[0] += p[0] * s;
                    *(f32 *)&sp20[1] += p[1] * s;
                    *(f32 *)&sp20[2] += p[2] * s;
                    p += 4;
                    i--;
                } while (i != 0);
            }
        done_acc:
            if ((f32 *)sp14 == (f32 *)sp20) {
                sp14[0] = *(f32 *)&sp20[2] * m[6] + (*(f32 *)&sp20[0] * m[0] + *(f32 *)&sp20[1] * m[3]);
                sp14[1] = *(f32 *)&sp20[2] * m[7] + (*(f32 *)&sp20[0] * m[1] + *(f32 *)&sp20[1] * m[4]);
                sp14[2] = *(f32 *)&sp20[2] * m[8] + (*(f32 *)&sp20[0] * m[2] + *(f32 *)&sp20[1] * m[5]);
            } else {
                sp14[0] = *(f32 *)&sp20[2] * m[6] + (*(f32 *)&sp20[0] * m[0] + *(f32 *)&sp20[1] * m[3]);
                sp14[1] = *(f32 *)&sp20[2] * m[7] + (*(f32 *)&sp20[0] * m[1] + *(f32 *)&sp20[1] * m[4]);
                sp14[2] = *(f32 *)&sp20[2] * m[8] + (*(f32 *)&sp20[0] * m[2] + *(f32 *)&sp20[1] * m[5]);
            }
            sp14[0] += m[9];
            sp14[1] += m[10];
            sp14[2] += m[11];
            sp8[0] = sp14[0] - pt[0];
            sp8[1] = sp14[1] - pt[1];
            sp8[2] = sp14[2] - pt[2];
            {
                f32 mag = PSVECMag((Vec *)sp8);
                f32 depth = radius - mag;
                *outDepth = depth;
                if (depth > lbl_805622D0) {
                    f32 inv = lbl_805622DC / mag;
                    outPos[0] = sp14[0];
                    outPos[1] = sp14[1];
                    outPos[2] = sp14[2];
                    outDir[0] = sp8[0] * inv;
                    outDir[1] = sp8[1] * inv;
                    outDir[2] = sp8[2] * inv;
                    return 1;
                }
            }
        }
    }
    return 0;
}

extern "C" void fn_801996BC(Vec* arg0, s32 arg1, Vec* arg2, void* arg3, void* arg4, f32 farg0) {
    Vec proj, d, a, b, p;
    f32 dot, mag, limit;
    s32 pa = *(s32*)((u8*)arg3+4);
    s32 pb = *(s32*)((u8*)arg4+4);
    if (pa) fn_8017B6D4(pa, &a, arg1);
    else { a.x=lbl_805622D0; a.y=lbl_805622D0; a.z=lbl_805622D0; }
    if (pb) fn_8017B6D4(pb, &b, arg1);
    else { b.x=lbl_805622D0; b.y=lbl_805622D0; b.z=lbl_805622D0; }
    d.x=a.x-b.x; d.y=a.y-b.y; d.z=a.z-b.z;
    dot=PSVECDotProduct(arg2,&d);
    proj.x=arg2->x*dot; proj.y=arg2->y*dot; proj.z=arg2->z*dot;
    d.x-=proj.x; d.y-=proj.y; d.z-=proj.z;
    p.x=d.x*lbl_805622E4; p.y=d.y*lbl_805622E4; p.z=d.z*lbl_805622E4;
    mag=PSVECMag(&p);
    limit=lbl_805622E8*farg0*(*(f32*)((u8*)arg3+0x14)+*(f32*)((u8*)arg4+0x14));
    if (mag>limit) { f32 s=limit/mag; p.x*=s; p.y*=s; p.z*=s; }
    *arg0=p;
}
#pragma dont_inline reset

#pragma dont_inline on
extern "C" void fn_80199870(void* arg0) {
    u32 value = *(u32*)((u8*)arg0 + 0x10);
    u32 v2 = value;
    if ((u32)(v2 - 0x50430000) == 0x4152 ||
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
    volatile f32 underflow;
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
    f32 temp_f7;
    f32 temp_f7_2;
    volatile f32 temp_f8;
    f32 temp_f8_2;
    f32 temp_f9;
    f32 temp_f9_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f28;
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

extern "C" s32 fn_8019A820(void* arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    Vec d, dir, v20, delta, v8;
    f32 mag, rem, var4, ret, k, dx, dy, dz;
    s32 obj;
    Vec* a = (Vec*)arg1;
    Vec* b = (Vec*)arg2;
    dx = a->x - b->x;
    dy = a->y - b->y;
    dz = a->z - b->z;
    d.x = dx;
    d.y = dy;
    d.z = dz;
    mag = PSVECMag(&d);
    obj = *(s32*)((u8*)arg0 + 4);
    if (mag > lbl_805622D4 && mag < farg0) {
        rem = farg0 - mag;
        dir.x = d.x * (lbl_805622E0 / mag);
        dir.y = d.y * (lbl_805622E0 / mag);
        dir.z = d.z * (lbl_805622E0 / mag);
        fn_8017B6D4(obj, &v20, arg2);
        k = rem * *(f32*)((u8*)arg0 + 0x10);
        PSVECDotProduct(&v20, &dir);
        delta.x = dir.x * k;
        delta.y = dir.y * k;
        delta.z = dir.z * k;
        ((void (*)(void*, Vec*, s32, s32, s32))(*(void***)arg0)[7])(arg0, &delta, arg2, arg3, 0);
        ret = fn_8019DF88((void*)(obj + 0x60), (f32*)&v20, (void*)(obj + 0x148), (f32*)arg2, (f32*)&dir, *(f32*)(obj + 0xD4), lbl_80562314);
        if (ret > lbl_805622D0) {
            v8.x = dir.x * ret; v8.y = dir.y * ret; v8.z = dir.z * ret;
            var4 = lbl_805622D4;
            if (var4 > rem) var4 = rem;
            ((void (*)(void*, s32, Vec*, s32, s32, s32, s32, f32))(*(void***)arg0)[8])(arg0, arg4, &v8, arg2, arg3, 0, 0, var4);
            fn_801B34DC(arg0, 0, (Vec*)arg2, &v8, &dir, arg3);
        }
        return 1;
    }
    return 0;
}

#pragma scheduling on
extern "C" void fn_8019AA18(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_8019A820(arg0, (u8*)arg0 + 0x34, arg1, arg2, arg3, *(f32*)((u8*)arg0 + 0x24));
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" s32 fn_8019AA34(void *obj, void *pos, void *other, void *otherPos, s32 a, s32 b, f32 radius, f32 otherRadius) {
    Vec delta, normal, point;
    f32 sum = radius + otherRadius;
    const Vec *p = (const Vec *)pos;
    const Vec *q = (const Vec *)otherPos;
    f32 dx = p->x - q->x;
    f32 dz = p->z - q->z;
    f32 dy = p->y - q->y;
    delta.x = dx;
    delta.z = dz;
    delta.y = dy;
    s32 result = 0;
    if ((f32)__fabs((f64)dx) < sum && (f32)__fabs((f64)dz) < sum && (f32)__fabs((f64)dy) < sum) {
        f32 length = PSVECMag(&delta);
        if (!((f32)__fabs((f64)length) <= lbl_80558DC4)) {
            f32 depth = otherRadius + (-length + radius);
            if (depth > lbl_805622D0) {
                f32 scale = lbl_805622E0 / length;
                f32 nx = delta.x * scale;
                f32 ny = delta.y * scale;
                f32 nz = delta.z * scale;
                normal.x = nx;
                normal.z = nz;
                normal.y = ny * lbl_80562300;
                PSVECNormalize(&normal, &normal);
                f32 distance = lbl_80562318 * (radius + length - otherRadius);
                f32 px = p->x + normal.x * distance;
                f32 py = p->y + normal.y * distance;
                f32 pz = p->z + normal.z * distance;
                point.x = px;
                point.y = py;
                point.z = pz;
                if (*(s32 *)((u8 *)obj + 4)) {
                    fn_8019A788(obj, other, &point, &normal, a, b, depth, lbl_805622D0, lbl_805622D0);
                } else {
                    normal.x *= lbl_805622DC;
                    normal.y *= lbl_805622DC;
                    normal.z *= lbl_805622DC;
                    fn_8019A788(other, obj, &point, &normal, a, b, depth, lbl_805622D0, lbl_805622D0);
                }
                result = 1;
            }
        }
    }
    return result;
}
#pragma pop
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_8019AC44(void* arg0, void* arg1, void* arg2, f32 farg0) {
    Vec work[64]; s32 count, sp8; Vec p70,p64,delta,p4c,p40,p34,p28,p1c,p10;
    f32 dot,mag,limit,scale,varf1,f31,dx,dy,dz,tx,ty,tz,ux,uy,uz,vx,vy,vz; void* body=*(void**)((u8*)arg0+4);
    if (lbl_8055E5A0!=0) { count=0x40; fn_801CF080((s32)lbl_8055E5A0,arg1,work,&count,0,farg0); Vec *wp = work; for(s32 i=0;i<count;++i,wp++) fn_8019A820(arg0,arg1,(s32)wp,0x6e,0,farg0); }
    if (fn_801E9F08((u8*)body+0x6c,arg1,&p70,(s32)&p64,(s32)&sp8,farg0)!=0) {
        dx=((Vec*)arg1)->x-p70.x; dy=((Vec*)arg1)->y-p70.y; dz=((Vec*)arg1)->z-p70.z; delta.x=dx; delta.y=dy; delta.z=dz;
        dot=PSVECDotProduct(&p64,&delta); f31=farg0-dot; fn_8017B6D4((s32)body,&p4c,(s32)&p70);
        farg0=f31* *(f32*)((u8*)arg0+0x10); dot=-PSVECDotProduct(&p4c,&p64);
        tx=p64.x*farg0; ty=p64.y*farg0; tz=p64.z*farg0;
        ux=p4c.x+p64.x*dot; uy=p4c.y+p64.y*dot; uz=p4c.z+p64.z*dot;
        vx=ux*lbl_8056231C; vy=uy*lbl_8056231C; vz=uz*lbl_8056231C;
        p40.x=tx; p40.y=ty; p40.z=tz; p34.x=ux; p34.y=uy; p34.z=uz;
        ((Vec*)arg2)->x+=vx; ((Vec*)arg2)->y+=vy; ((Vec*)arg2)->z+=vz;
        mag=PSVECMag((Vec*)arg2); if(mag>lbl_80562320){scale=lbl_80562320/mag;((Vec*)arg2)->x*=scale;((Vec*)arg2)->y*=scale;((Vec*)arg2)->z*=scale;}
        p28.x=p34.x*lbl_80562324; p28.y=p34.y*lbl_80562324; p28.z=p34.z*lbl_80562324;
        limit=lbl_80562328* *(f32*)((u8*)body+0xd4); p28.x+=((Vec*)arg2)->x*limit;p28.y+=((Vec*)arg2)->y*limit;p28.z+=((Vec*)arg2)->z*limit;
        mag=PSVECMag(&p28); scale=farg0* *(f32*)((u8*)arg0+0x14); if(scale>lbl_80562320)scale=lbl_80562320;
        if(mag>scale){limit=scale/mag;p28.x*=limit;p28.y*=limit;p28.z*=limit;}
        p40.x+=p28.x;p40.y+=p28.y;p40.z+=p28.z;
        dot=-PSVECDotProduct((Vec*)((u8*)body+0x124),&p64)*farg0*lbl_8056232C;
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
    } else {((Vec*)arg2)->x=lbl_805622D0;((Vec*)arg2)->y=lbl_805622D0;((Vec*)arg2)->z=lbl_805622D0;}
}
#pragma pop

extern "C" s32 fn_8019AA34(void*, void*, void*, void*, s32, s32, f32, f32);
void fn_8019B068(void* arg0, void* arg1, s32 arg2, s32 arg3) {
    f32 scale = *(f32*)((u8*)arg1 + 0x24);
    typedef s32 (*Call9)(void*, void*, void*, void*, s32, s32, void*, f32, f32);
    ((Call9)fn_8019AA34)(arg0, (u8*)arg0 + 0x34, arg1, (u8*)arg1 + 0x34, arg2, arg3, arg1, *(f32*)((u8*)arg0 + 0x24), scale);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" s32 fn_8019B08C(void* arg0, const Vec* arg1, void* arg2, f32 farg0) {
    f32 f31 = farg0;
    f32 ax = arg1->x;
    f32 az = arg1->z;
    f32 ay = arg1->y;
    f32* m = *(f32**)((u8*)arg2 + 0xC);
    f32 x = ax - m[9];
    f32 y = ay - m[10];
    f32 z = az - m[11];
    Vec local;
    local.x = x * m[0] + y * m[1] + z * m[2];
    local.y = x * m[3] + y * m[4] + z * m[5];
    local.z = x * m[6] + y * m[7] + z * m[8];
    f32 halfHeight = *(f32*)((u8*)arg2 + 0x28);
    if (local.z >= halfHeight || local.z <= -halfHeight) return 0;
    f32 mag = (f32)fn_8002F234(local.y * local.y + local.x * local.x);
    if ((f32)__fabs((f64)mag) <= lbl_80558DC4) return 0;
    f32 radius = *(f32*)((u8*)arg2 + 0x24);
    f31 += radius - mag;
    if (f31 <= lbl_805622D0) return 0;
    volatile f32 px = arg1->x, py = arg1->y, pz = arg1->z;
    f32 dt = (radius - f31) / mag;
    Vec tmp;
    tmp.x = local.x * dt;
    tmp.y = local.y * dt;
    tmp.z = local.z;
    Vec point;
    {
        Vec prod;
        prod.x = tmp.x * m[0] + tmp.y * m[3] + tmp.z * m[6];
        prod.y = tmp.x * m[1] + tmp.y * m[4] + tmp.z * m[7];
        prod.z = tmp.x * m[2] + tmp.y * m[5] + tmp.z * m[8];
        point = prod;
    }
    point.x += m[9]; point.y += m[10]; point.z += m[11];
    Vec normal;
    normal.x = local.x; normal.y = local.y; normal.z = lbl_805622D0;
    PSVECNormalize(&normal, &normal);
    Vec out;
    {
        Vec prod;
        prod.x = normal.x * m[0] + normal.y * m[3] + normal.z * m[6];
        prod.y = normal.x * m[1] + normal.y * m[4] + normal.z * m[7];
        prod.z = normal.x * m[2] + normal.y * m[5] + normal.z * m[8];
        out = prod;
    }
    Vec copy = out;
    fn_8019A788(arg0, arg2, &point, &copy, 0, 0, f31, lbl_805622D0, lbl_805622D0);
    return 1;
}

extern "C" s32 fn_8019B4D8(void *arg0, void *arg1, void *arg2, s32 arg3, f32 farg0) {
    (void)arg0; (void)arg1; (void)arg2; (void)arg3; (void)farg0;
    return 0;
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

extern "C" s32 fn_8019CCCC(void* arg0, Vec* arg1, void* arg2, f32 farg0) {
    if (fn_8019B08C(arg0, arg1, arg2, farg0) != 0) {
        return 1;
    }
    u32 transXBits, transYBits, transZBits;
    u32 axisXBits, axisYBits, axisZBits;
    f32 corners[6];
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
    corners[3] = transX + axisX * dim;
    corners[4] = transY + axisY * dim;
    corners[5] = transZ + axisZ * dim;
    corners[0] = transX + axisX * negDim;
    corners[1] = transY + axisY * negDim;
    corners[2] = transZ + axisZ * negDim;
    s32 firstHit = fn_8019AA34(arg0, arg1, arg2, &corners[3], 0, 0, farg0, *(f32*)((u8*)arg2 + 0x24));
    s32 secondHit = fn_8019AA34(arg0, arg1, arg2, &corners[0], 0, 0, farg0, *(f32*)((u8*)arg2 + 0x24));
    return (firstHit | secondHit) != 0;
}

#pragma scheduling on
extern void fn_8019CCCC(void*, f32, s32);
extern void fn_8019CCCC(void*, void*, s32, f32);
void fn_8019CE3C(void* arg0, s32 arg1) {
    fn_8019CCCC(arg0, (u8*)arg0 + 0x34, arg1, *(f32*)((u8*)arg0 + 0x24));
}

/* Collision objects the influence/collision handlers in this file work on.
   fn_8019F064 and fn_8019F26C choose a handler from the four-character shape tag
   at +0x18 ('SPHR' sphere, 'TUBE', 'BOX ', 'FLSR' floor, 'RING', 'POLY', 'GRUP'). */
struct CollisionObject {
    u32 flags;             /* 0x00: which side fn_8019AA34 reports the hit against */
    u8 pad04[0x8];
    void *axisSource;      /* 0x0C: object whose +0x0C holds the influence axis */
    u8 pad10[0x14];
    f32 radius;            /* 0x24: collision radius the handlers below write and fn_8019AA34 reads */
    u8 pad28[0xC];
    Vec position;          /* 0x34: world position */
    u8 pad40[0x14];
    f32 minRadius;         /* 0x54: radius the directional falloff scales down to */
    f32 maxRadius;         /* 0x58: radius it scales up to */
};

extern "C" void fn_8019CE4C(void *object, void *shape) {
    /* Sphere ('SPHR') influence pass: point this sphere's collision radius at an object.
       The vector from the sphere's centre to the object is normalised (1/distance) and
       projected on the sphere's influence axis; how well the two line up (|dot|, 0..1)
       picks a radius between the sphere's min (+0x54) and max (+0x58).  Objects closer
       than 0.1 (squared) simply get the larger of the two.  The radius is stored at
       +0x24, which the sphere/sphere collision fn_8019B068 then runs with. */
    CollisionObject *sphere = (CollisionObject *)shape;
    Vec *objectPos = (Vec *)((u8 *)object + 0x34);
    f32 push[3];
    push[0] = objectPos->x - sphere->position.x;
    push[1] = objectPos->y - sphere->position.y;
    f32 sphereZ = sphere->position.z;
    f32 objectZ = objectPos->z;
    push[2] = objectZ - sphereZ;
    f32 squareDistance = PSVECSquareDistance(objectPos, &sphere->position);
    f32 radius;
    if (squareDistance > lbl_8056232C /* 0.1f */) {
        f32 invDistance = lbl_805622E0 /* 1.0f */ / (f32)fn_8002F234(squareDistance);
        push[0] *= invDistance;
        push[1] *= invDistance;
        push[2] *= invDistance;
        Vec *axis = (Vec *)((u8 *)sphere->axisSource + 0xC);
        f32 alignment = PSVECDotProduct((Vec *)push, axis);
        f32 maxRadius = sphere->maxRadius;
        f32 minRadius = sphere->minRadius;
        f32 strength = (f32)__fabs((f64)alignment);
        radius = minRadius + strength * (maxRadius - minRadius);
    } else {
        f32 maxRadius = sphere->maxRadius;
        f32 minRadius = sphere->minRadius;
        radius = (minRadius > maxRadius) ? minRadius : maxRadius;
    }
    sphere->radius = radius;
    fn_8019B068(object, shape, 0, 0);
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
    /* Computes a distance/axis-based weight into target+0x24, falling back to max of bounds when very close. */
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

    /* Compute influence from arg1's position toward this object's point, store result at +0x24, then chain to fn_8019BD54. */
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
    Vec sp1, sp2;
    f32 scale, dot, value, dist;
    sp1.x = ((Vec*)((u8*)arg1 + 0x34))->x - ((Vec*)((u8*)arg0 + 0x34))->x;
    sp1.y = ((Vec*)((u8*)arg1 + 0x34))->y - ((Vec*)((u8*)arg0 + 0x34))->y;
    sp1.z = ((Vec*)((u8*)arg1 + 0x34))->z - ((Vec*)((u8*)arg0 + 0x34))->z;
    dist = PSVECSquareDistance((Vec*)((u8*)arg1 + 0x34), (Vec*)((u8*)arg0 + 0x34));
    if (dist > lbl_8056232C) {
        scale = lbl_805622E0 / (f32)fn_8002F234(dist);
        sp1.x *= scale; sp1.y *= scale; sp1.z *= scale;
        dot = PSVECDotProduct(&sp1, (Vec*)(*(u8**)((u8*)arg0 + 0xC) + 0xC));
        value = *(f32*)((u8*)arg0 + 0x54) + (f32)__fabs((f64)dot) * (*(f32*)((u8*)arg0 + 0x58) - *(f32*)((u8*)arg0 + 0x54));
    } else {
        value = *(f32*)((u8*)arg0 + 0x54);
        if (value > *(f32*)((u8*)arg0 + 0x58)) value = *(f32*)((u8*)arg0 + 0x58);
    }
    *(f32*)((u8*)arg0 + 0x24) = value;
    sp2.x = ((Vec*)((u8*)arg0 + 0x34))->x - ((Vec*)((u8*)arg1 + 0x34))->x;
    sp2.y = ((Vec*)((u8*)arg0 + 0x34))->y - ((Vec*)((u8*)arg1 + 0x34))->y;
    sp2.z = ((Vec*)((u8*)arg0 + 0x34))->z - ((Vec*)((u8*)arg1 + 0x34))->z;
    dist = PSVECSquareDistance((Vec*)((u8*)arg0 + 0x34), (Vec*)((u8*)arg1 + 0x34));
    if (dist > lbl_8056232C) {
        scale = lbl_805622E0 / (f32)fn_8002F234(dist);
        sp2.x *= scale; sp2.y *= scale; sp2.z *= scale;
        dot = PSVECDotProduct(&sp2, (Vec*)(*(u8**)((u8*)arg1 + 0xC) + 0xC));
        value = *(f32*)((u8*)arg1 + 0x54) + (f32)__fabs((f64)dot) * (*(f32*)((u8*)arg1 + 0x58) - *(f32*)((u8*)arg1 + 0x54));
    } else {
        value = *(f32*)((u8*)arg1 + 0x54);
        if (value > *(f32*)((u8*)arg1 + 0x58)) value = *(f32*)((u8*)arg1 + 0x58);
    }
    *(f32*)((u8*)arg1 + 0x24) = value;
    fn_8019B068(arg0, arg1, 0, 0);
}

extern "C" void fn_8019D378(void *self, void *context) {
    struct TargetBody { u8 pad[0x34]; Vec point; };
    struct OriginBody { u8 pad[0x24]; Vec point; };
    /* Compute a distance/axis-based weight into self+0x24, falling back to the max of the bounds when very close. */
    TargetBody *target = (TargetBody *)self;
    OriginBody *origin = (OriginBody *)*(void **)((u8 *)context + 0xC);
    Vec *originPoint = &origin->point;
    f32 delta[3];
    delta[0] = originPoint->x - target->point.x;
    delta[1] = originPoint->y - target->point.y;
    f32 targetZ = target->point.z;
    f32 originZ = originPoint->z;
    delta[2] = originZ - targetZ;
    f32 distance = PSVECSquareDistance(originPoint, &target->point);
    f32 result;
    if (distance > lbl_8056232C) {
        f32 scale = lbl_805622E0 / (f32)fn_8002F234(distance);
        delta[0] *= scale;
        delta[1] *= scale;
        delta[2] *= scale;
        Vec *axis = (Vec *)((u8 *)*(void **)((u8 *)self + 0xC) + 0xC);
        f32 dot = PSVECDotProduct((Vec *)delta, axis);
        f32 high = *(f32 *)((u8 *)self + 0x58);
        f32 low = *(f32 *)((u8 *)self + 0x54);
        f32 magnitude = (f32)__fabs((f64)dot);
        result = low + magnitude * (high - low);
    } else {
        f32 high = *(f32 *)((u8 *)self + 0x58);
        f32 low = *(f32 *)((u8 *)self + 0x54);
        result = (low > high) ? low : high;
    }
    *(f32 *)((u8 *)self + 0x24) = result;
    fn_8019C854(self, context);
}

extern "C" void PSVECCrossProduct(const Vec *, const Vec *, Vec *);
extern "C" s32 fn_8019D484(const Vec *p0, const Vec *v0, const Vec *p1, const Vec *v1, f32 *out0, f32 *out1) {
    extern f32 lbl_80562348;
    Vec delta, normal;
    f32 den, a, b, cx;
    delta.x = p1->x - p0->x;
    delta.y = p1->y - p0->y;
    delta.z = p1->z - p0->z;
    PSVECCrossProduct(v0, v1, &normal);
    den = PSVECDotProduct(&normal, &normal);
    if (den > lbl_80562348) {
        cx = normal.y * delta.z - delta.y * normal.z;
        b = normal.x * (delta.y * v0->z - delta.z * v0->y)
          + ((v0->y * normal.z - normal.y * v0->z) * delta.x + cx * v0->x);
        a = normal.x * (delta.y * v1->z - delta.z * v1->y)
          + ((v1->y * normal.z - normal.y * v1->z) * delta.x + cx * v1->x);
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

extern "C" s32 fn_8019DC04(void *arg0, void *arg1) {
    struct Interface {
        virtual ~Interface() {}
        virtual void m0() = 0;
        virtual void m1() = 0;
        virtual void m2() = 0;
        virtual void m3() = 0;
        virtual void m4() = 0;
        virtual void m5() = 0;
        virtual void m6() = 0;
        virtual void m7() = 0;
        virtual void m8() = 0;
        virtual void m9() = 0;
        virtual void m10() = 0;
        virtual void m11() = 0;
        virtual f32 getRadius() = 0;
    };
    register void *object0 = arg0;
    register void *object1 = arg1;
    volatile u32 local[15];

    void *shape1 = *(void **)((u8 *)object1 + 0xC);
    void *shape0 = *(void **)((u8 *)object0 + 0xC);
    *(volatile f32 *)&local[12] = *(f32 *)((u8 *)shape0 + 0x24) - *(f32 *)((u8 *)shape1 + 0x24);
    *(volatile f32 *)&local[13] = *(f32 *)((u8 *)shape0 + 0x28) - *(f32 *)((u8 *)shape1 + 0x28);
    *(volatile f32 *)&local[14] = *(f32 *)((u8 *)shape0 + 0x2C) - *(f32 *)((u8 *)shape1 + 0x2C);

    f32 radius1 = ((Interface *)object1)->getRadius();
    f32 radius0 = ((Interface *)object0)->getRadius();
    f32 radius = radius0 + radius1;
    f32 radiusSquared = radius * radius;
    if (PSVECDotProduct((Vec *)&local[12], (Vec *)&local[12]) < radiusSquared) {
        s32 result = fn_8019DAB0(object0, object1);
        u32 raw = (u32)result;
        u32 found = ((u32)(-result) | raw) >> 31;
        if (found != 0) {
            return 1;
        }

        void *mat = *(void **)((u8 *)object0 + 0xC);
        f32 w = *(f32 *)((u8 *)object0 + 0x28);
        f32 neg_w = -w;
        volatile u32 *words = (volatile u32 *)mat;
        u32 v14 = words[6];
        u32 v18 = words[7];
        local[3] = v14;
        u32 v8 = words[9];
        local[4] = v18;
        u32 v1C = words[8];
        f32 f0 = *(volatile f32 *)&local[3];
        local[5] = v1C;
        u32 vC = words[10];
        f32 f2 = *(volatile f32 *)&local[4];
        local[0] = v8;
        u32 v10 = words[11];
        f32 f5 = *(volatile f32 *)&local[5];
        local[1] = vC;
        f32 f3 = *(volatile f32 *)&local[0];
        local[2] = v10;
        f32 f8 = *(volatile f32 *)&local[1];
        f32 f = *(f32 *)((u8 *)object0 + 0x24);

        f32 f10 = f0 * w;
        f32 f7 = f2 * w;
        f32 f6 = f5 * w;
        f0 = f0 * neg_w;
        f2 = f2 * neg_w;
        f32 f9 = f3 + f10;
        f3 = f3 + f0;
        f32 f5trans = *(volatile f32 *)&local[2];
        f5 = f5 * neg_w;
        f32 fposY = f8 + f7;
        *(volatile f32 *)&local[9] = f9;
        f32 fnegY = f8 + f2;
        f32 fposZ = f5trans + f6;
        *(volatile f32 *)&local[6] = f3;
        f32 fnegZ = f5trans + f5;
        *(volatile f32 *)&local[10] = fposY;
        *(volatile f32 *)&local[11] = fposZ;
        *(volatile f32 *)&local[7] = fnegY;
        *(volatile f32 *)&local[8] = fnegZ;

        s32 first = fn_8019CCCC(object0, (Vec *)&local[9], object1, f);
        s32 combined = (s32)found | first;
        found = ((u32)(-combined) | (u32)combined) >> 31;
        if (found != 0) {
            return 1;
        }
        s32 second = fn_8019CCCC(object0, (Vec *)&local[6], object1, f);
        combined = (s32)found | second;
        return ((u32)(-combined) | (u32)combined) >> 31;
    }
    return 0;
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
#pragma processor 750
#pragma scheduling invalid_target
extern "C" s32 fn_8019DDFC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void * __restrict arg4, void *arg5, f32 farg0) {
    f32 * __restrict vec0 = (f32 *)arg0;
    f32 * __restrict vec2 = (f32 *)arg4;
    register f32 x = vec0[0];
    register f32 y = vec2[0];
    register f32 dx = x - y;
    register f32 a = vec0[1];
    register f32 b = vec2[1];
    register f32 dy = a - b;
    register f32 c = vec0[2];
    register f32 d = vec2[2];
    register f32 dz = c - d;
    f32 delta[3];
    register f32 val;
    register f32 dot2;
    register f32 radiusSq;
    register f32 valueSq;
    register f32 t;
    register f32 mag;
    register f32 scale;
    register f32 norm;
    delta[0] = dx;
    delta[1] = dy;
    delta[2] = dz;
    val = lbl_8056234C * PSVECDotProduct((const Vec *)delta, (const Vec *)delta);
    dot2 = PSVECDotProduct((const Vec *)delta, (const Vec *)delta);
    radiusSq = farg0 * farg0;
    valueSq = val * val;
    t = valueSq - lbl_80562350 * (dot2 - radiusSq);
    if (t > lbl_80562354) {
        mag = (f32)fn_8002F234(t);
        scale = lbl_805622E8 * (-val - mag);
        if (scale >= lbl_805622D0 && scale < *(f32 *)arg2) {
            register f32 x0 = ((f32 *)arg1)[0];
            *(f32 *)arg2 = scale;
            ((f32 *)arg3)[0] = delta[0] + x0 * scale;
            ((f32 *)arg3)[1] = delta[1] + ((f32 *)arg1)[1] * scale;
            ((f32 *)arg3)[2] = delta[2] + ((f32 *)arg1)[2] * scale;
            mag = PSVECMag((const Vec *)arg3);
            if (lbl_80562358 > mag)
                mag = lbl_80562358;
            norm = lbl_805622E0 / mag;
            register f32 o0 = ((f32 *)arg3)[0];
            register f32 o1 = ((f32 *)arg3)[1];
            register f32 o2 = ((f32 *)arg3)[2];
            o0 *= norm;
            o1 *= norm;
            o2 *= norm;
            ((f32 *)arg3)[0] = o0;
            ((f32 *)arg3)[1] = o1;
            ((f32 *)arg3)[2] = o2;
            return 1;
        }
    }
    return 0;
}

#pragma push
#pragma processor 750
extern "C" f32 fn_8019DF88(void *arg0, f32 *arg1, void *arg2, f32 *arg3, f32 *arg4, f32 farg0, f32 farg1) {
    Vec velocity, delta, normalCopy, normal, cross, rotated, result;
    f32 *m = (f32 *)arg2;
    f32 *p = (f32 *)arg0;
    u32 ny = ((u32 *)arg4)[1];
    f32 dx = arg3[0] - p[0];
    f32 dy = arg3[1] - p[1];
    f32 dz = arg3[2] - p[2];
    f32 vz = arg1[2], vy = arg1[1], vx = arg1[0];
    u32 nz = ((u32 *)arg4)[2], nx = ((u32 *)arg4)[0];
    velocity.x = vx; velocity.y = vy; velocity.z = vz;
    delta.x = dx; delta.y = dy; delta.z = dz;
    ((u32 *)&normalCopy)[0] = nx; ((u32 *)&normalCopy)[1] = ny; ((u32 *)&normalCopy)[2] = nz;
    if (PSVECDotProduct(&velocity, (Vec *)arg4) < lbl_805622D0) {
        ((u32 *)&normal)[0] = ((u32 *)&normalCopy)[0];
        ((u32 *)&normal)[1] = ((u32 *)&normalCopy)[1];
        ((u32 *)&normal)[2] = ((u32 *)&normalCopy)[2];
        PSVECNormalize(&normal, &normal);
        PSVECCrossProduct(&delta, &normal, &cross);
        if (&rotated == &cross) {
            rotated.x = cross.z*m[6] + (cross.y*m[3] + cross.x*m[0]);
            rotated.y = cross.z*m[7] + (cross.x*m[1] + cross.y*m[4]);
            rotated.z = cross.z*m[8] + (cross.x*m[2] + cross.y*m[5]);
        } else {
            rotated.x = cross.z*m[6] + (cross.y*m[3] + cross.x*m[0]);
            rotated.y = cross.z*m[7] + (cross.x*m[1] + cross.y*m[4]);
            rotated.z = cross.z*m[8] + (cross.x*m[2] + cross.y*m[5]);
        }
        PSVECCrossProduct(&rotated, &delta, &result);
        f32 denominator = lbl_805622E0 / farg0 + PSVECDotProduct(&normal, &result);
        if ((f32)__fabs((f64)denominator) > lbl_8056235C) {
            f32 impulse = (-(lbl_805622E0 + farg1) * PSVECDotProduct(&velocity, &normal)) / denominator;
            if (lbl_80562360 < impulse) impulse = lbl_80562360;
            return impulse;
        }
    }
    return lbl_805622D0;
}
#pragma pop

extern "C" s32 fn_8019E1F4(f32* minT, f32* maxT, f32 origin, f32 dir, f32 extent) {
    /* Clip a ray parameter interval against one axis-aligned slab; updates [*minT, *maxT] and returns nonzero if it remains valid. */
    if ((f32)__fabs(dir) <= lbl_80558DC4) {
        if (origin < -extent) goto ret0;
        if (!(origin > extent)) goto ret1;
ret0:
        return 0;
ret1:
        return 1;
    }
    f32 diff;
    f32 negExtent = -extent;
    diff = extent - origin;
    origin = negExtent - origin;
    extent = diff / dir;
    dir = origin / dir;
    f32 tNear = (dir < extent) ? dir : extent;
    f32 curMin = *minT;
    *minT = (curMin > tNear) ? curMin : tNear;
    f32 tFar = (dir > extent) ? dir : extent;
    f32 curMax = *maxT;
    *maxT = (curMax < tFar) ? curMax : tFar;
    if (*minT > *maxT) return 0;
    return !(*maxT < lbl_805622D0);
}

#pragma push
#pragma processor 750
extern "C" s32 fn_8019E2D0(s32 arg0, s32 arg1, s32 arg2, void *arg3, f32 f0, f32 f1, f32 f2) {
    Vec origin, direction;
    f32 minimum, maximum;
    f32 *matrix = (f32 *)arg3;

    f32 m1 = matrix[1];
    f32 m4 = matrix[4];
    f32 m3 = matrix[3];
    f32 m6 = matrix[6];
    f32 m7 = matrix[7];
    f32 m8 = matrix[8];
    f32 m2 = matrix[2];
    f32 m5 = matrix[5];
    f32 *p = (f32 *)arg0;
    f32 *v = (f32 *)arg1;
    f32 x = p[0] - matrix[9];
    f32 y = p[1] - matrix[10];
    f32 z = p[2] - matrix[11];
    origin.y = z * m5 + (x * m3 + y * m4);
    origin.x = z * m2 + (x * matrix[0] + y * m1);
    origin.z = z * m8 + (x * m6 + y * m7);
    if ((f32 *)&direction == v) {
        f32 vx = v[0], vy = v[1], vz = v[2];
        direction.x = vz * m2 + (vx * matrix[0] + vy * m1);
        direction.y = vz * m5 + (vx * m3 + vy * m4);
        direction.z = vz * m8 + (vx * m6 + vy * m7);
    } else {
        direction.x = v[2] * m2 + (v[0] * matrix[0] + v[1] * m1);
        direction.y = v[2] * m5 + (v[0] * m3 + v[1] * m4);
        direction.z = v[2] * m8 + (v[0] * m6 + v[1] * m7);
    }
    minimum = lbl_80562364;
    maximum = lbl_80562368;
    if (fn_8019E1F4(&minimum, &maximum, origin.x, direction.x, f0) &&
        fn_8019E1F4(&minimum, &maximum, origin.y, direction.y, f1) &&
        fn_8019E1F4(&minimum, &maximum, origin.z, direction.z, f2) &&
        minimum < *(f32 *)arg2) {
        *(f32 *)arg2 = minimum;
        return 1;
    }
    return 0;
}
#pragma pop

extern "C" u8 lbl_80435020[];
extern f32 lbl_8056236C;
#pragma scheduling invalid_target
extern "C" s32 fn_8019B4D8(void*, void*, void*, s32, f32);
struct Fn8019E874Xf { f32 m[9]; Vec pos; };
class Fn801A0F10Child {
public:
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void Update();
};
extern "C" void fn_801BEAEC(s32, s32, void*);
extern "C" void fn_801BEB44(s32, s32, void*, f32*);
struct Fn801A4548Hdr { s32 count; u8* list; s32 count2; u8* shorts; s32 unk10; void* fn; };
static inline void Fn801A4548Swap2(u8* q) {
    u8 t = q[0]; q[0] = q[1]; q[1] = t;
}
static inline void Fn801A4548Swap4(u8* q) {
    u8 t;
    t=q[0]; q[0]=q[3]; q[3]=t;
    t=q[1]; q[1]=q[2]; q[2]=t;
}
class Fn8019E874Obj {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual Fn8019E874Xf* GetXf();
};
#pragma push
#pragma use_lmw_stmw off
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
            f32 a0=arow[0], a1=arow[1], a2=arow[2];
            f32 b0=brow[0], b1=brow[1], b2=brow[2];
            output[0]=a0; output[1]=a1; output[2]=a2;
            output[3]=b0; output[4]=b1; output[5]=b2;
            output[6]=current[0]; output[7]=current[1]; output[8]=current[2];
            output[9]=*(f32*)&copied[9];
            output[10]=*(f32*)&copied[10];
            output[11]=*(f32*)&copied[11];
            f32 d0=arow[3]-lbl_8056236C;
            f32 d1=brow[3]-lbl_8056236C;
            for (s32 i=0;i<4;i++) {
                f32 a=(i&1) ? lbl_805622DC : lbl_805622E0;
                f32 s0=d0*a;
                output[9]+=a0*s0;
                output[10]+=a1*s0;
                output[11]+=a2*s0;
                f32 b=(i&2) ? lbl_805622DC : lbl_805622E0;
                f32 s1=d1*b;
                output[9]+=b0*s1;
                output[10]+=b1*s1;
                output[11]+=b2*s1;
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
#pragma pop
extern "C" s32 fn_8019E834(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_8019E874(void* arg0, void** arg1, void* arg2, f32 f1, f32 f2, f32 f3, f32 f4) {
    s32 kind = *(s32*)((u8*)arg0 + 0x20);
    Vec p;
    Vec d;
    if (kind == 0x73) goto dispatch;
    if (kind != 0x74) goto main;
dispatch:
    return fn_8019E500(arg0, arg1);
main:
    Fn8019E874Xf b = *((Fn8019E874Obj*)arg1)->GetXf();
    Fn8019E874Xf a = **(Fn8019E874Xf**)((u8*)arg0 + 0xC);
    f32 dx = a.pos.x - b.pos.x;
    f32 dy = a.pos.y - b.pos.y;
    f32 dz = a.pos.z - b.pos.z;
    p.x = a.pos.x;
    p.y = a.pos.y;
    p.z = a.pos.z;
    d.x = dx;
    d.y = dy;
    d.z = dz;
    f32 neg;
    f32 lim = *(f32*)((u8*)arg0 + 0x28);
    neg = -lim;
    f32 t = -PSVECDotProduct((Vec*)&a.m[6], &d);
    lim = (lim < t) ? lim : t;
    lim = (lim > neg) ? lim : neg;
    p.x += a.m[6] * lim;
    p.y += a.m[7] * lim;
    p.z += a.m[8] * lim;
    return fn_8019B4D8(arg0, arg1, &p, 0, *(f32*)((u8*)arg0 + 0x24));
}
#pragma pop
extern "C" s32 fn_8019E874(void*, void**, void*, f32, f32, f32, f32);
extern void fn_8019AA34(void*, void*, void*, s32, s32, void*, f32, f32);
extern void fn_8019A820(void*, s32, s32, s32, f32);
#pragma use_lmw_stmw off
extern "C" s32 fn_8019EA7C(void* arg0, void* arg1) {
    void* temp_r3;
    void* temp_r5;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    volatile f32 sp[9];
    register s32 res;

    temp_r3 = ((Fn8019EA7CDispatch*)arg1)->Get();
    temp_r5 = *(void**)((u8*)arg0 + 0xC);
    temp_f3 = *(f32*)((u8*)temp_r5 + 0x28);
    temp_f4 = *(f32*)((u8*)temp_r5 + 0x24) - *(f32*)((u8*)temp_r3 + 0x24);
    temp_f1 = *(f32*)((u8*)temp_r5 + 0x2C);
    temp_f2 = temp_f3 - *(f32*)((u8*)temp_r3 + 0x28);
    sp[6] = temp_f4;
    sp[1] = temp_f2;
    sp[5] = temp_f1 - *(f32*)((u8*)temp_r3 + 0x2C);
    res = fn_8019E874(arg0, (void**)arg1, temp_r5, temp_f1, temp_f2, temp_f3, temp_f4);
    return res != 0;
}
#pragma use_lmw_stmw on
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
    s32 obj = *(s32 *)((u8 *)self + 4);
    s32 v7 = f;
    s32 v6 = e;
    s32 v5 = d;
    s32 v4 = c;
    s32 v3 = b;
    s32 v2 = a;
    s32 v1 = (s32)self;
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
    /* Dispatch a collision/shape query by the 4-character type tag stored at arg1+0x18. */
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

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8019F1D4(void* arg0, void* arg1, void* arg2) {
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
    *(f32*)arg1 = x0;
    f32 y0 = left + scaleB;
    f32 y1 = mid + scaleB;
    f32 y2 = right + scaleB;
    ((f32*)arg1)[1] = x1;
    ((f32*)arg1)[2] = x2;
    inputB[0] = width;
    inputB[1] = left;
    inputB[2] = mid;
    inputB[3] = right;
    *(f32*)arg2 = y0;
    ((f32*)arg2)[1] = y1;
    ((f32*)arg2)[2] = y2;
}
#pragma pop
extern "C" void fn_8019F248(void *arg0) {
    extern f32 lbl_80562300;
    extern s32 lbl_8055E598;
    extern void fn_801E3FC8(void*, s32, f32);
    f32 var_f1 = *(f32*)((u8*)arg0 + 0x24);
    var_f1 = (var_f1 > lbl_80562300) ? var_f1 : lbl_80562300;
    fn_801E3FC8((u8*)arg0 + 0x34, lbl_8055E598, var_f1);
}

extern "C" void fn_802E30C8(const char *, ...);
extern const char lbl_80333614[];
extern u8 lbl_80562374;
extern u8 lbl_80562375;
extern u8 lbl_80562376;
extern u8 lbl_80562377;
extern u8 lbl_80562378;
extern "C" void fn_8019F26C(s32 context, void *shape) {
    /* Dispatch collision handling for a shape based on its 4-char type tag. */
    u32 shapeType = *(u32 *)((u8 *)shape + 0x18);
    switch (shapeType) {
    case 'FLSR':
        fn_8019D19C((void *)context, shape);
        return;
    case 'SPHR':
        fn_8019CE4C(shape, (void *)context);
        return;
    case 'TUBE':
        fn_8019CF60(shape, (void *)context);
        return;
    case 'BOX ':
        fn_8019D06C((void *)context, shape, 0, 0);
        return;
    case 'GRUP':
    case 'POLY':
        ((Fn801A401CDispatch *)shape)->Call((void *)context);
        return;
    case 'RING':
        fn_8019D378((void *)context, shape);
        return;
    case 'RAGD':
        break;
    default: {
        u8 tagText[5] = {
            lbl_80562374,
            lbl_80562375,
            lbl_80562376,
            lbl_80562377,
            lbl_80562378
        };
        *(u32 *)tagText = *(u32 *)((u8 *)shape + 0x18);
        fn_802E30C8(lbl_80333614, tagText);
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
    extern void fn_8019EECC(void*, Vec*);
    extern void fn_8019EF00(void*);
    u32 sp[3];
    void *temp_r6;
    void *temp_r4;
    f32 ybase;
    f32 x;
    f32 y;
    f32 z;
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
    if (temp_r4 != 0) fn_8019EECC(temp_r4, (Vec*)((u8*)arg0 + 0x28));
    fn_8019EF00(arg0);
}

#pragma scheduling on
extern "C" void fn_8019F4D4(void *arg0, void *arg1) {
    fn_8019EC84(arg0);
    f32 scale = -PSVECDotProduct(
        (const Vec *)((u8 *)*(void **)((u8 *)arg0 + 0xC) + 0xC),
        (const Vec *)arg1);
    void *vector = *(void **)((u8 *)arg0 + 0xC);
    volatile f32 scratch[10];
    scratch[6] = ((f32 *)arg1)[0] + ((f32 *)vector)[3] * scale;
    scratch[1] = ((f32 *)arg1)[1] + ((f32 *)vector)[4] * scale;
    scratch[5] = ((f32 *)arg1)[2] + ((f32 *)vector)[5] * scale;
}
extern "C" void fn_8019F560(void) {
    fn_8019F1A4();
}

#pragma dont_inline on
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
#pragma dont_inline off
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

extern "C" f64 fn_801E9DDC(void*, f32, f32);
extern "C" void fn_801B3B24(void*, Vec*, Vec*);
extern "C" void fn_8017B3A8(s32, Vec*, s32);
extern "C" f64 fn_8002EFB4(f32, f64);
extern "C" f64 sin(f64);
extern f32 lbl_80562380, lbl_80562384, lbl_80562388, lbl_8055E3C8, lbl_8056238C, lbl_80562398, lbl_8056239C, lbl_805623A0, lbl_805623A4, lbl_805623A8, lbl_805623AC, lbl_805623B0, lbl_805623B4, lbl_8056234C;
extern f64 lbl_80562390;
#pragma push
#pragma processor 750
extern "C" void fn_8019F780(void *arg0) {
    u8 *self = (u8 *)arg0;
    u8 *body = *(u8 **)(self + 4);
    Vec q, hit, nrm, c[8], w, g, delta, sp84, sp60, sp54, v48, v3c, v30;
    s32 sp8;
    q.x = *(f32 *)(self + 0x34);
    q.y = *(f32 *)(self + 0x38);
    q.z = *(f32 *)(self + 0x3c);
    if (fn_801E9F08(body + 0x6c, &q, &hit, (s32)&nrm, (s32)&sp8, lbl_80562380 + *(f32 *)(self + 0x24)) != 0) {
        if (sp8 == 7) {
            if (self[0x4c] == 0) {
                fn_8017B6D4((s32)body, &sp84, (s32)&hit);
                fn_801B3B24(arg0, &hit, &sp84);
                self[0x4c] = 1;
            }
            *(f32 *)(self + 0x50) = hit.y;
        } else {
            f32 *pc = (f32 *)c;
            f32 *ps = (f32 *)c;
            f32 *p64 = (f32 *)(self + 0x64);
            f32 *pz = (f32 *)self;
            s32 i;
            f32 hx = *(f32 *)(self + 0x58), hy = *(f32 *)(self + 0x5c), hz = *(f32 *)(self + 0x60);
            f32 k27 = lbl_8056231C, k28 = lbl_80562320, k29 = lbl_805622D0, k30 = lbl_80562384, k31 = lbl_80562388, k24 = lbl_805622D4;
            self[0x4c] = 0;
            c[0].x = -hx; c[0].y = -hy; c[0].z = -hz;
            c[1].x = hx;  c[1].y = -hy; c[1].z = -hz;
            c[2].x = -hx; c[2].y = hy;  c[2].z = -hz;
            c[3].x = hx;  c[3].y = hy;  c[3].z = -hz;
            c[4].x = -hx; c[4].y = -hy; c[4].z = hz;
            c[5].x = hx;  c[5].y = -hy; c[5].z = hz;
            c[6].x = -hx; c[6].y = hy;  c[6].z = hz;
            c[7].x = hx;  c[7].y = hy;  c[7].z = hz;
            for (i = 0; i < 8; i++) {
                f32 *m = *(f32 **)(self + 0xc);
                f32 dist;
                fn801A1F98Transform((volatile f32 *)&w, (volatile f32 *)pc, (volatile f32 *)ps, m);
                w.x += m[9];
                w.y += m[10];
                w.z += m[11];
                g.x = w.x;
                g.z = w.z;
                g.y = (f32)fn_801E9DDC(body + 0x6c, w.x, w.z);
                delta.x = g.x - w.x;
                delta.y = g.y - w.y;
                delta.z = g.z - w.z;
                dist = PSVECDotProduct(&delta, &nrm);
                if (dist > k29) {
                    f32 d2, fac, push, lim, mag;
                    fn_8017B6D4((s32)body, &sp60, (s32)&w);
                    d2 = PSVECDotProduct(&sp60, &nrm);
                    fac = -d2;
                    sp54.x = sp60.x + nrm.x * fac;
                    sp54.y = sp60.y + nrm.y * fac;
                    sp54.z = sp60.z + nrm.z * fac;
                    p64[0] += sp54.x * k27;
                    p64[1] += sp54.y * k27;
                    p64[2] += sp54.z * k27;
                    mag = PSVECMag((Vec *)p64);
                    if (mag > k28) {
                        f32 s = k28 / mag;
                        p64[0] *= s;
                        p64[1] *= s;
                        p64[2] *= s;
                    }
                    push = dist * *(f32 *)(self + 0x10) * (d2 < k29 ? lbl_805622E0 : lbl_80562300);
                    v48.x = nrm.x * push;
                    v48.y = nrm.y * push;
                    v48.z = nrm.z * push;
                    v3c.x = sp54.x * (k30 * *(f32 *)(body + 0xd4));
                    v3c.y = sp54.y * (k30 * *(f32 *)(body + 0xd4));
                    v3c.z = sp54.z * (k30 * *(f32 *)(body + 0xd4));
                    lim = k31 * *(f32 *)(body + 0xd4);
                    v3c.x += p64[0] * lim;
                    v3c.y += p64[1] * lim;
                    v3c.z += p64[2] * lim;
                    mag = PSVECMag(&v3c);
                    lim = push * *(f32 *)(self + 0x54);
                    if (mag > lim) {
                        f32 s = lim / mag;
                        v3c.x *= s;
                        v3c.y *= s;
                        v3c.z *= s;
                    }
                    v48.x += v3c.x;
                    v48.y += v3c.y;
                    v48.z += v3c.z;
                    ((void (*)(void *, Vec *, Vec *, s32, s32))(*(void ***)arg0)[7])(arg0, &v48, &w, sp8, 0);
                    mag = fn_8019DF88(body + 0x60, (f32 *)&sp60, body + 0x148, (f32 *)&w, (f32 *)&nrm, *(f32 *)(body + 0xd4), lbl_805622D0);
                    if (mag > k29) {
                        v30.x = nrm.x * mag;
                        v30.y = nrm.y * mag;
                        v30.z = nrm.z * mag;
                        if (k24 > dist) dist = k24;
                        ((void (*)(void *, s32, Vec *, Vec *, s32, s32, s32, f32))(*(void ***)arg0)[8])(arg0, 0, &v30, &w, sp8, 0, 0, dist);
                    }
                } else {
                    pz[0x19] = k29;
                    pz[0x1a] = k29;
                    pz[0x1b] = k29;
                }
                pc += 3;
                ps += 3;
                p64 += 3;
                pz += 3;
            }
        }
    } else {
        f32 *p = (f32 *)(self + 0x64);
        s32 i;
        for (i = 0; i < 24; i++) p[i] = lbl_805622D0;
    }
    if (self[0x4c] != 0) {
        f32 y, k3, k26, k24, f2, s, t;
        Vec a, b;
        y = (*(f32 *)(self + 0x50) - *(f32 *)(self + 0x38)) + *(f32 *)(self + 0x24);
        fn_8017B6D4((s32)body, &a, (s32)(self + 0x34));
        t = lbl_8056238C * lbl_8055E3C8;
        s = (f32)sin((f64)(f32)fn_8002EFB4(*(f32 *)(self + 0x34) + t * lbl_805622E8, lbl_80562390));
        y += lbl_80562398 * (lbl_805622E0 + s);
        if (y > lbl_805622D0) {
            f32 r = *(f32 *)(self + 0x24);
            f32 r2 = r * r;
            k24 = lbl_8056239C * r2;
            k26 = lbl_805623A0 * (lbl_805623A4 * r * r2);
            k3 = -k24 * (lbl_805623A8 + lbl_805623AC * PSVECMag(&a));
            b.x = a.x * k3;
            b.y = a.y * k3;
            b.z = a.z * k3;
            fn_8017B3A8((s32)body, &b, (s32)(self + 0x34));
            f2 = lbl_8056234C * *(f32 *)(self + 0x24);
            k3 = lbl_805623B0 + lbl_8056232C * y;
            if (!(y < f2)) y = f2;
            b.x = lbl_805622D0;
            b.z = lbl_805622D0;
            b.y = lbl_805623B4 * (k3 * (k26 * y));
            fn_8017B3A8((s32)body, &b, (s32)(self + 0x34));
            return;
        }
        self[0x4c] = 0;
    }
}
#pragma pop

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
    register f32 value = *(f32*)((u8*)arg0 + 0x178);
    f32 scaleA = value * lbl_805622DC;
    void* base = *(void**)((u8*)arg0 + 0xC);
    register f32 x = *(f32*)((u8*)base + 0x24);
    register f32 y = *(f32*)((u8*)base + 0x28);
    f32 scaleB = value * lbl_805622E0;
    register f32 z = *(f32*)((u8*)base + 0x2C);
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

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
extern "C" void fn_801A0F10(void* arg0) {
    s32 count;
    Vec tmp;
    u8 buffer[0x300];
    s32 i;
    u8* ent;
    fn_801A0160(arg0);
    ent = (u8*)arg0;
    i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x174)) {
        ((Fn801A0F10Child*)*(void**)(ent + 0x24))->Update();
        ent += 4;
        i++;
    }
    if (lbl_8055E5A0 != 0) {
        u8* obj = *(u8**)((u8*)arg0 + 4);
        s32 ok;
        if (obj != 0) {
            switch (*(s32*)(obj + 0x10)) {
            case 0x4E434152:
            case 0x43415220:
            case 0x41434152:
            case 0x50434152:
                ok = 1;
                break;
            default:
                ok = 0;
                break;
            }
        } else {
            ok = 0;
        }
        if (ok != 0) {
            s32 e = *(s32*)(obj + 0x1EC);
            s32 k = 0;
            f32 one = lbl_805622E0;
            f32 zero = lbl_805622D4;
            do {
                fn_801BEAEC(e, k, &tmp);
                Vec v = tmp;
                v.x += *(f32*)(obj + 0x48) * one;
                v.y += *(f32*)(obj + 0x4C) * one;
                v.z += *(f32*)(obj + 0x50) * one;
                count = 0x40;
                fn_801CF080(lbl_8055E5A0, &v, buffer, &count, 0, lbl_8056234C);
                Vec* cur = (Vec*)buffer;
                for (i = 0; i < count; i++) {
                    Vec d;
                    d.x = v.x - cur->x;
                    d.y = v.y - cur->y;
                    d.z = v.z - cur->z;
                    f32 mag = PSVECMag(&d);
                    if (mag > zero) {
                        f32 inv = one / mag;
                        d.x *= inv;
                        d.y *= inv;
                        d.z *= inv;
                        fn_801BEB44(e, k, (f32*)cur, (f32*)&d);
                    }
                    cur++;
                }
                k++;
            } while (k < 4);
        }
    }
}
#pragma pop
extern "C" void fn_801A0160(void*);
#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
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
    fn_801E41D8(&sp14, &sp8, 0x40FFFF00, temp_r6, temp_r7, temp_r8, arg0, lbl_8056234C * *(f32*)((u8*)arg0 + 0x24), temp_f2, temp_f3, sp34, sp28, sp30, sp24, sp2C, sp20);
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

extern "C" void fn_801A18D4(void* arg0, f32* arg1, f32* arg2) {
    s32 w20, w2c, w18, w1c, w24, w28;
    f32 x = *(f32*)((u8*)arg0+0x24);
    void* m = *(void**)((u8*)arg0+0xC);
    w20 = *(s32*)((u8*)m+0x20);
    w2c = *(s32*)((u8*)m+0x2C);
    w18 = *(s32*)((u8*)m+0x18);
    w1c = *(s32*)((u8*)m+0x1C);
    w24 = *(s32*)((u8*)m+0x24);
    w28 = *(s32*)((u8*)m+0x28);
    f32 a = *(f32*)&w20, b = *(f32*)&w2c, c = *(f32*)&w18, d = *(f32*)&w1c, e = *(f32*)&w24, f = *(f32*)&w28;
    f32 g=b+a*x, h=b-a*x, i=e+c*x, j=e-c*x, k=f+d*x, l=f-d*x;
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
extern "C" s32 fn_8019DC04(void*, void*);
extern "C" void fn_8019CE3C(void*, s32);
extern "C" void fn_802E30C8(const char*, ...);
extern "C" const char lbl_80333650[];
#pragma scheduling on
extern "C" void fn_801A1ABC(void* object, void* shapeNode) {
    /* Dispatch collision handling by 4-byte shape type tag at shapeNode+0x18.
     * Some types are no-ops; others call the corresponding shape handler.
     * 'GRUP' forwards to its child shape pointer at shapeNode+0x17C.
     * Unknown types report "Unsupported collision type" with the raw tag. */
    s32 shapeType = *(s32*)((u8*)shapeNode + 0x18);
    switch (shapeType) {
    case 'RAGD':
    case 'POLY':
    case 'RING':
        break;
    case 'FLSR':
        fn_8019CF60(object, shapeNode);
        break;
    case 'SPHR':
        fn_8019CE3C(shapeNode, (s32)object);
        break;
    case 'BOX ':
        fn_8019EA7C(object, shapeNode);
        break;
    case 'TUBE':
        fn_8019DC04(object, shapeNode);
        break;
    case 'GRUP':
        fn_8019EA7C(object, *(void**)((u8*)shapeNode + 0x17C));
        break;
    default:
        fn_802E30C8(lbl_80333650, shapeType);
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
#pragma use_lmw_stmw off
extern "C" void* fn_801A1CE4(void *shape, s32 owner, s32 swap) {
    // The ten bytes kept aside while reversing: b24 is the byte at 0x24, and so
    // on. The five first bytes of the words are declared before the five second
    // ones because that declaration order is what gives each of them its own
    // register, so all twenty bytes are read before any is written back.
    u8 b24, b28, b2c, b30, b34;
    u8 b25, b29, b2d, b31, b35;
    fn_8019ECC4();
    *(void**)shape = &lbl_803338C0;
    if (swap != 0) {
        b24 = *(u8*)((u8*)shape + 0x24);
        b25 = *(u8*)((u8*)shape + 0x25);
        b28 = *(u8*)((u8*)shape + 0x28);
        b29 = *(u8*)((u8*)shape + 0x29);
        b2c = *(u8*)((u8*)shape + 0x2C);
        b2d = *(u8*)((u8*)shape + 0x2D);
        b30 = *(u8*)((u8*)shape + 0x30);
        b31 = *(u8*)((u8*)shape + 0x31);
        b34 = *(u8*)((u8*)shape + 0x34);
        b35 = *(u8*)((u8*)shape + 0x35);
        *(u8*)((u8*)shape + 0x24) = *(u8*)((u8*)shape + 0x27);
        *(u8*)((u8*)shape + 0x27) = b24;
        *(u8*)((u8*)shape + 0x25) = *(u8*)((u8*)shape + 0x26);
        *(u8*)((u8*)shape + 0x26) = b25;
        *(u8*)((u8*)shape + 0x28) = *(u8*)((u8*)shape + 0x2B);
        *(u8*)((u8*)shape + 0x2B) = b28;
        *(u8*)((u8*)shape + 0x29) = *(u8*)((u8*)shape + 0x2A);
        *(u8*)((u8*)shape + 0x2A) = b29;
        *(u8*)((u8*)shape + 0x2C) = *(u8*)((u8*)shape + 0x2F);
        *(u8*)((u8*)shape + 0x2F) = b2c;
        *(u8*)((u8*)shape + 0x2D) = *(u8*)((u8*)shape + 0x2E);
        *(u8*)((u8*)shape + 0x2E) = b2d;
        *(u8*)((u8*)shape + 0x30) = *(u8*)((u8*)shape + 0x33);
        *(u8*)((u8*)shape + 0x33) = b30;
        *(u8*)((u8*)shape + 0x31) = *(u8*)((u8*)shape + 0x32);
        *(u8*)((u8*)shape + 0x32) = b31;
        *(u8*)((u8*)shape + 0x34) = *(u8*)((u8*)shape + 0x37);
        *(u8*)((u8*)shape + 0x37) = b34;
        *(u8*)((u8*)shape + 0x35) = *(u8*)((u8*)shape + 0x36);
        *(u8*)((u8*)shape + 0x36) = b35;
    }
    return shape;
}
#pragma use_lmw_stmw on
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
        f32 middle;
        f32 same;
        same = lbl_805622D0;
        middle = lbl_805622E0;
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

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_801A1F98(void *arg0, f32 *min, f32 *max) {
    f32 point[3];
    f32 corners[24];
    register f32 x, y, z;
    z = *(f32 *)((char *)arg0 + 0x2C);
    y = *(f32 *)((char *)arg0 + 0x28);
    x = *(f32 *)((char *)arg0 + 0x24);
    register f32 nx, ny, nz;
    ny = -y; nx = -x; nz = -z;
    corners[0]=x; corners[1]=y; corners[2]=z;
    corners[3]=nx; corners[4]=y; corners[5]=z;
    corners[6]=x; corners[7]=ny; corners[8]=z;
    corners[9]=nx; corners[10]=ny; corners[11]=z;
    corners[12]=x; corners[13]=y; corners[14]=nz;
    corners[15]=nx; corners[16]=y; corners[17]=nz;
    corners[18]=x; corners[19]=ny; corners[20]=nz;
    corners[21]=nx; corners[22]=ny; corners[23]=nz;
    f32 *matrix = (f32 *)((VTab1A1E7C *)arg0)->Call();
    min[0]=matrix[9]; min[1]=matrix[10]; min[2]=matrix[11];
    matrix = (f32 *)((VTab1A1E7C *)arg0)->Call();
    max[0]=matrix[9]; max[1]=matrix[10]; max[2]=matrix[11];
    f32 *dst = point;
    f32 *cur = corners;
    f32 *src = corners;
    int i = 0;
    for (; i < 8; i++) {
        matrix = (f32 *)((VTab1A1E7C *)arg0)->Call();
        if (dst == cur) {
            f32 t0 = (src[0] * matrix[0] + src[1] * matrix[3]) + src[2] * matrix[6];
            f32 t1 = (src[0] * matrix[1] + src[1] * matrix[4]) + src[2] * matrix[7];
            f32 t2 = (src[0] * matrix[2] + src[1] * matrix[5]) + src[2] * matrix[8];
            dst[0] = t0; dst[1] = t1; dst[2] = t2;
        } else {
            f32 sx = src[0], sy = src[1], sz = src[2];
            dst[0] = (sx * matrix[0] + sy * matrix[3]) + sz * matrix[6];
            dst[1] = (sx * matrix[1] + sy * matrix[4]) + sz * matrix[7];
            dst[2] = (sx * matrix[2] + sy * matrix[5]) + sz * matrix[8];
        }
        point[0] += matrix[9]; point[1] += matrix[10]; point[2] += matrix[11];
        if (min[0] < point[0]) min[0] = point[0];
        if (min[1] < point[1]) min[1] = point[1];
        if (min[2] < point[2]) min[2] = point[2];
        if (max[0] > point[0]) max[0] = point[0];
        if (max[1] > point[1]) max[1] = point[1];
        if (max[2] > point[2]) max[2] = point[2];
        cur += 3; src += 3;
    }
}
#pragma pop
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
    f32 dist = diffX * diffX + diffY * diffY + diffZ * diffZ;
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

extern "C" void fn_801A2474(void *arg0) {
    struct Object {
        char pad0[0xC];
        u32 *matrix;
        char pad10[0x28];
        Vec input;
        char pad14[0x24];
        volatile Vec output;
    };
    Object *self = (Object *)arg0;
    register u32 *mw = self->matrix;
    register f32 *m = (f32 *)mw;
    u32 *cache = (u32 *)((char *)self + 0x44);
    u32 m0 = mw[0], m1 = mw[1], m2, m3, m4, m5, m6, m7, m8;
    cache[0] = m0; cache[1] = m1;
    m2 = mw[2]; cache[2] = m2;
    m3 = mw[3]; m4 = mw[4];
    cache[3] = m3; cache[4] = m4;
    m5 = mw[5]; cache[5] = m5;
    m6 = mw[6]; m7 = mw[7];
    cache[6] = m6; cache[7] = m7;
    m8 = mw[8]; cache[8] = m8;
    if (&self->output == (volatile Vec *)&self->input) {
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

struct Fn801A26FCMtx { f32 m[9]; Vec t; };
struct Fn801A26FCObj {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual f32 getRadius();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual f32 *getPos();
    virtual Fn801A26FCMtx *getMtx();
};
#pragma always_inline on
static inline void MtxMulVecPosInl(const f32 *m, const f32 *src, f32 *dst) {
    if (dst == src) {
        f32 x = src[0], y = src[1], z = src[2];
        dst[0] = z * m[6] + (x * m[0] + y * m[3]);
        dst[1] = z * m[7] + (x * m[1] + y * m[4]);
        dst[2] = z * m[8] + (x * m[2] + y * m[5]);
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
}
#pragma always_inline reset
extern f32 lbl_805623AC;
extern f32 lbl_805623C0;
extern "C" int fn_80198F64(void *, int, void *, float *, void *, float *, float);
extern "C" void fn_801C28A8(void*, void*, void*, void*, void*, s32, s32, void* = 0, void* = 0);
extern "C" void fn_801C2BDC(void*, s32*, f32**, s32*);
extern "C" void fn_801A26FC(void* arg0, void* arg1) {
    Fn801A26FCMtx mtx;
    Vec pos;
    f32 vecA[3];
    f32 vecB[3];
    f32 outHit[3];
    f32 outN[3];
    f32 vecA2[3];
    f32 vecB2[3];
    f32 n[3];
    f32 q[3];
    f32 pos68[3];
    f32 up[3];
    f32 pos50[3];
    f32 zero[3];
    Vec delta;
    f32 tmp[3];
    Vec delta2;
    s32 count;
    f32* list;
    s32 pad;
    f32 depth;
    Fn801A26FCObj* other = (Fn801A26FCObj*)arg1;
    u32 type = *(u32*)((u8*)arg1 + 0x18);
    if ((type - 0x47525500U) == 0x5550U) {
        f32* a = *(f32**)((u8*)arg0 + 0xC);
        f32* b = *(f32**)((u8*)arg1 + 0xC);
        delta.x = a[9] - b[9];
        delta.y = a[10] - b[10];
        delta.z = a[11] - b[11];
        f32 d = PSVECDotProduct(&delta, &delta);
        f32 radius = *(f32*)((u8*)arg0 + 0x24) + other->getRadius();
        if (d < radius * radius) {
            Fn801A26FCObj* obj = *(Fn801A26FCObj**)((u8*)arg1 + 0x17C);
            u8* owner;
            pos = *(Vec*)((u8*)obj + 0x38);
            vecA[0] = lbl_805622D0; vecA[1] = lbl_805622D0; vecA[2] = lbl_805622D0;
            vecB[0] = lbl_805622D0; vecB[1] = lbl_805622D0; vecB[2] = lbl_805622D0;
            owner = *(u8**)((u8*)arg1 + 4);
            if (owner != 0) {
                vecA[0] = *(f32*)(owner + 0x118);
                vecA[1] = *(f32*)(owner + 0x11C);
                vecA[2] = *(f32*)(owner + 0x120);
                vecB[0] = *(f32*)(owner + 0x124);
                vecB[1] = *(f32*)(owner + 0x128);
                vecB[2] = *(f32*)(owner + 0x12C);
                pos.x = pos.x + *(f32*)(owner + 0x30);
                pos.y = pos.y + *(f32*)(owner + 0x34);
                pos.z = pos.z + *(f32*)(owner + 0x38);
            }
            mtx = *obj->getMtx();
            MtxMulVecPosInl(mtx.m, (f32*)&pos, tmp);
            mtx.t.x = mtx.t.x + tmp[0];
            mtx.t.y = mtx.t.y + tmp[1];
            mtx.t.z = mtx.t.z + tmp[2];
            pos68[0] = *(f32*)((u8*)obj + 0x24);
            pos68[1] = *(f32*)((u8*)obj + 0x28);
            pos68[2] = *(f32*)((u8*)obj + 0x2C);
            fn_801C28A8(*(void**)((u8*)arg0 + 0x30), &mtx, pos68, vecA, vecB,
                        *(s32*)((u8*)arg0 + 0x28), *(s32*)((u8*)arg0 + 0x2C), outHit, outN);
            if (PSVECDotProduct((Vec*)outN, (Vec*)outN) > lbl_805623AC) {
                up[0] = lbl_805622D0; up[1] = lbl_805622E0; up[2] = lbl_805622D0;
                fn_801B34DC(arg1, 0, (Vec*)outHit, (Vec*)outN, (Vec*)up, *(s32*)((u8*)arg0 + 0x20));
            }
        }
    } else if ((type - 0x424F5800U) == 0x5820U) {
        f32* o = other->getPos();
        f32* p = *(f32**)((u8*)arg0 + 0xC);
        delta2.x = p[9] - o[9];
        delta2.y = p[10] - o[10];
        delta2.z = p[11] - o[11];
        f32 dd = PSVECDotProduct(&delta2, &delta2);
        f32 r = *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg1 + 0x30);
        if (dd < r * r) {
            u8* owner;
            vecA2[0] = lbl_805622D0; vecA2[1] = lbl_805622D0; vecA2[2] = lbl_805622D0;
            vecB2[0] = lbl_805622D0; vecB2[1] = lbl_805622D0; vecB2[2] = lbl_805622D0;
            owner = *(u8**)((u8*)arg1 + 4);
            if (owner != 0) {
                vecA2[0] = *(f32*)(owner + 0x118);
                vecA2[1] = *(f32*)(owner + 0x11C);
                vecA2[2] = *(f32*)(owner + 0x120);
                vecB2[0] = *(f32*)(owner + 0x124);
                vecB2[1] = *(f32*)(owner + 0x128);
                vecB2[2] = *(f32*)(owner + 0x12C);
            }
            pos50[0] = *(f32*)((u8*)arg1 + 0x24);
            pos50[1] = *(f32*)((u8*)arg1 + 0x28);
            pos50[2] = *(f32*)((u8*)arg1 + 0x2C);
            void* r4 = other->getPos();
            fn_801C28A8(*(void**)((u8*)arg0 + 0x30), r4, pos50, vecA2, vecB2, 0, -1, 0, 0);
        }
    } else if ((type - 0x504F4C00U) == 0x4C59U) {
        s32 off;
        s32 i;
        f32 z;
        count = 0;
        fn_801C2BDC(*(void**)((u8*)arg0 + 0x30), &count, &list, &pad);
        z = lbl_805622D0;
        off = 0;
        for (i = 0; i < count; i++, off += 0xC) {
            zero[0] = z; zero[1] = z; zero[2] = z;
            if (fn_80198F64((u8*)list + off, (int)arg1, n, &depth, q, zero, lbl_805623C0)) {
                f32* e = (f32*)((u8*)list + off);
                e[0] = e[0] + q[0] * depth;
                e[1] = e[1] + q[1] * depth;
                e[2] = e[2] + q[2] * depth;
            }
        }
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
    /* Dispatches collision/shape node handling based on the node's 4CC type tag. */
    char *messageBase = lbl_80333448;
    s32 nodeType = *(s32 *)((u8 *)arg1 + 0x18);
    switch (nodeType) {
    case 0x504F4C59:
        break;
    case 0x53504852:
        fn_8019C854(arg1, (void *)arg0);
        break;
    case 0x47525550: {
        u8 *groupEntry = (u8 *)arg1;
        s32 i = 0;
        while (i < *(s32 *)((u8 *)arg1 + 0x174)) {
            fn_8019C854(*(void **)(groupEntry + 0x24), (void *)arg0);
            groupEntry += 4;
            i++;
        }
        break;
    }
    case 0x424F5820:
        if (!lbl_8055E5A4) {
            lbl_8055E5A4 = 1;
            fn_802E30C8(lbl_8055A4C4, messageBase + 0x22C);
        }
        break;
    case 0x52414744:
        if (!lbl_8055E5A5) {
            lbl_8055E5A5 = 1;
            fn_802E30C8(lbl_8055A4C4, messageBase + 0x254);
        }
        break;
    case 0x464C5352:
        fn_8019D378(arg1, (void *)arg0);
        break;
    default:
        fn_802E317C(messageBase + 0x280, nodeType);
        break;
    }
}

#pragma always_inline on
static inline void MtxMulVecInl(const f32 *m, const f32 *src, f32 *dst) {
    if (src == dst) {
        f32 x = src[0], y = src[1], z = src[2];
        dst[0] = z * m[6] + (x * m[0] + y * m[3]);
        dst[1] = z * m[7] + (x * m[1] + y * m[4]);
        dst[2] = z * m[8] + (x * m[2] + y * m[5]);
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
}
static inline void MtxMulVecInl(const f32 *m, const f32 *src, const f32 *srcCmp, f32 *dst) {
    if (srcCmp == dst) {
        f32 x = src[0], y = src[1], z = src[2];
        dst[0] = z * m[6] + (x * m[0] + y * m[3]);
        dst[1] = z * m[7] + (x * m[1] + y * m[4]);
        dst[2] = z * m[8] + (x * m[2] + y * m[5]);
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
}
static inline void MtxMulVecRevInl(const f32 *m, const f32 *src, f32 *dst) {
    if (dst == src) {
        f32 y = src[1], x = src[0], z = src[2];
        f32 rx = z * m[6] + (x * m[0] + y * m[3]);
        f32 ry = z * m[7] + (x * m[1] + y * m[4]);
        f32 rz = z * m[8] + (x * m[2] + y * m[5]);
        dst[0] = rx;
        dst[1] = ry;
        dst[2] = rz;
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
}
#pragma always_inline reset
extern "C" void fn_801A2EC8(void) {

}

extern "C" void fn_801A2ECC(void *arg0, void *arg1, void *arg2) {
    f32 corners[24];
    f32 tmp[3];
    f32 *lo = (f32 *)arg1;
    f32 *hi = (f32 *)arg2;
    f32 b = *(f32 *)((u8 *)arg0 + 0x28);
    f32 c = *(f32 *)((u8 *)arg0 + 0x24) + b;
    f32 nb = -b;
    f32 nc = -c;
    const f32 *m = *(const f32 **)((u8 *)arg0 + 0xC);
    f32 *p;
    int i;
    corners[0] = nc; corners[1] = nc; corners[2] = nb;
    corners[3] = nc; corners[4] = nc; corners[5] = b;
    corners[6] = nc; corners[7] = c; corners[8] = nb;
    corners[9] = nc; corners[10] = c; corners[11] = b;
    corners[12] = c; corners[13] = nc; corners[14] = nb;
    corners[15] = c; corners[16] = nc; corners[17] = b;
    corners[18] = c; corners[19] = c; corners[20] = nb;
    corners[21] = c; corners[22] = c; corners[23] = b;
    lo[0] = m[9]; lo[1] = m[10]; lo[2] = m[11];
    hi[0] = m[9]; hi[1] = m[10]; hi[2] = m[11];
    p = corners;
    for (i = 0; i < 8; i++, p += 3) {
        m = *(const f32 **)((u8 *)arg0 + 0xC);
        MtxMulVecInl(m, p, tmp);
        tmp[0] = tmp[0] + m[9];
        tmp[1] = tmp[1] + m[10];
        tmp[2] = tmp[2] + m[11];
        lo[0] = (lo[0] < tmp[0]) ? lo[0] : tmp[0];
        lo[1] = (lo[1] < tmp[1]) ? lo[1] : tmp[1];
        lo[2] = (lo[2] < tmp[2]) ? lo[2] : tmp[2];
        hi[0] = (hi[0] > tmp[0]) ? hi[0] : tmp[0];
        hi[1] = (hi[1] > tmp[1]) ? hi[1] : tmp[1];
        hi[2] = (hi[2] > tmp[2]) ? hi[2] : tmp[2];
    }
}

extern "C" void fn_801A3174(void *arg0) {
    ((void (*)(s32, s32, f32))fn_801E3FC8)(*(s32*)((u8*)arg0 + 0xC) + 0x24, lbl_8055E598, *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg0 + 0x28));
}

extern char lbl_80333778[];
__declspec(section ".sdata") extern char lbl_8055A4C8[];
__declspec(section ".sdata") extern char lbl_8055A4D0[];
__declspec(section ".sdata") extern char lbl_8055A4D4[];
__declspec(section ".sdata") extern char lbl_8055A4D8[];
__declspec(section ".sdata") extern char lbl_8055A4E0[];
__declspec(section ".sdata") extern char lbl_8055A4E4[];
__declspec(section ".sdata") extern char lbl_8055A4E8[];
__declspec(section ".sdata") extern char lbl_8055A4F0[];
__declspec(section ".sdata") extern char lbl_8055A4F8[];
__declspec(section ".sdata") extern char lbl_8055A500[];
extern "C" int strcmp(const char *, const char *);
struct TagVec3 { f32 x, y, z; };
class TagNode {
public:
    virtual const char *GetName();            // 0x08
    virtual void k1(); virtual void k2(); virtual void k3(); virtual void k4();
    virtual void k5(); virtual void k6();
    virtual f32 GetFloat(const char *);       // 0x24
    virtual void k8(); virtual void k9(); virtual void k10();
    virtual TagVec3 GetVec3(const char *);    // 0x34
};
class TagList {
public:
    virtual TagNode *GetChild(const char *);  // 0x08
    virtual TagNode *GetNth(int);             // 0x0C
};
extern "C" TagList *fn_80131808(void *, void *);
extern "C" void fn_80131818(TagList *);
#pragma scheduling invalid_target
extern "C" void fn_801A3190(void *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4, void *arg5, f32 farg0, f32 farg1) {
    *(s32*)((u8*)arg0 + 4) = 0x0;
    *(void**)arg0 = lbl_80333778;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(f32*)((u8*)arg0 + 0x10) = farg0;
    *(f32*)((u8*)arg0 + 0x14) = farg1;
    *(s32*)((u8*)arg0 + 0x18) = 0x504F4C59;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(s32*)((u8*)arg0 + 0x20) = 0x64;
    *(s32*)((u8*)arg0 + 0xDC) = 0;
    *(s32*)((u8*)arg0 + 0xBC) = arg3;
    u8 *dst = (u8*)arg0;
    u8 *src = (u8*)arg2;
    for (s32 i = 0; i < *(s32*)((u8*)arg0 + 0xBC); i++) {
        u32 t1 = *(s32*)(src + 4);
        s32 t0 = *(s32*)src;
        *(s32*)(dst + 0x3C) = t0;
        register unsigned int t2 = *(s32*)(src + 8);
        *(s32*)(dst + 0x40) = t1;
        f32 f = *(f32*)(src + 0xC);
        *(s32*)(dst + 0x44) = t2;
        *(f32*)(dst + 0x48) = f;
        src += 0x10;
        dst += 0x10;
    }
    f32 b2;
    register f32 b1;
    f32 b0;
    register f32 a2;
    f32 a1;
    register f32 a0;
    a0 = ((f32*)arg4)[0];
    a1 = ((f32*)arg4)[1];
    a2 = ((f32*)arg4)[2];
    b0 = ((f32*)arg5)[0];
    b1 = ((f32*)arg5)[1];
    b2 = ((f32*)arg5)[2];
    *(f32*)((u8*)arg0 + 0x24) = a0;
    *(f32*)((u8*)arg0 + 0x28) = a1;
    *(f32*)((u8*)arg0 + 0x2C) = a2;
    *(f32*)((u8*)arg0 + 0x30) = b0;
    *(f32*)((u8*)arg0 + 0x34) = b1;
    *(f32*)((u8*)arg0 + 0x38) = b2;
}

#pragma use_lmw_stmw off
extern "C" void *fn_801A324C(void *arg0, int arg1, void *arg2, f32 farg0, f32 farg1) {
    u8 *self;
    TagList *list;
    TagNode *node;
    TagNode *child;
    int i;
    *(int *)((u8 *)arg0 + 0xC) = arg1;
    self = (u8 *)arg0;
    *(f32 *)(self + 0x10) = farg0;
    *(int *)((u8 *)arg0 + 4) = 0;
    *(int *)((u8 *)arg0 + 8) = 0;
    *(int *)(self + 0x18) = 0x504F4C59;
    *(f32 *)(self + 0x14) = farg1;
    *(int *)(self + 0x20) = 100;
    *(int *)(self + 0x1C) = 0;
    *(void **)self = lbl_80333778;
    list = fn_80131808(arg2, lbl_80333778);
    *(int *)(self + 0xBC) = 0;
    *(int *)(self + 0xDC) = 0;
    node = list->GetChild(lbl_8055A4C8);
    {
        const TagVec3 &v = node->GetVec3(lbl_8055A4D0);
        *(f32 *)(self + 0x24) = v.x;
        *(f32 *)(self + 0x28) = v.y;
        *(f32 *)(self + 0x2C) = v.z;
    }
    {
        const TagVec3 &v = node->GetVec3(lbl_8055A4D4);
        *(f32 *)(self + 0x30) = v.x;
        *(f32 *)(self + 0x34) = v.y;
        *(f32 *)(self + 0x38) = v.z;
    }
    for (i = 0; (child = list->GetNth(i)) != 0; i++) {
        if (strcmp(child->GetName(), lbl_8055A4D8) == 0) {
            int idx = *(int *)(self + 0xBC);
            u8 *rec;
            *(int *)(self + 0xBC) = idx + 1;
            rec = self + idx * 0x10;
            {
                const TagVec3 &v = child->GetVec3(lbl_8055A4E0);
                *(f32 *)(rec + 0x3C) = v.x;
                *(f32 *)(rec + 0x40) = v.y;
                *(f32 *)(rec + 0x44) = v.z;
            }
            *(f32 *)(rec + 0x48) = child->GetFloat(lbl_8055A4E4);
        } else if (strcmp(child->GetName(), lbl_8055A4E8) == 0) {
            int idx = *(int *)(self + 0xDC);
            u8 *rec;
            *(int *)(self + 0xDC) = idx + 1;
            rec = self + idx * 0x1C;
            {
                const TagVec3 &v = child->GetVec3(lbl_8055A4F0);
                *(f32 *)(rec + 0xC0) = v.x;
                *(f32 *)(rec + 0xC4) = v.y;
                *(f32 *)(rec + 0xC8) = v.z;
            }
            {
                const TagVec3 &v = child->GetVec3(lbl_8055A4F8);
                *(f32 *)(rec + 0xCC) = v.x;
                *(f32 *)(rec + 0xD0) = v.y;
                *(f32 *)(rec + 0xD4) = v.z;
            }
            *(f32 *)(rec + 0xD8) = child->GetFloat(lbl_8055A500);
        }
    }
    fn_80131818(list);
    return arg0;
}
#pragma use_lmw_stmw reset
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
        f32 y, x, z;
        y = box->min.y;
        x = box->min.x;
        z = box->min.z;
        f32 y0 = y * mat[3];
        f32 y1 = y * mat[4];
        f32 x0 = mat[0] * x;
        f32 x1 = mat[1] * x;
        f32 y2 = y * mat[5];
        f32 x2 = mat[2] * x;
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
    var_f4 = var_f4 < sp14[0] ? sp14[0] : var_f4;
    arg1->x = var_f4;
    f32 var_f1 = arg1->y;
    var_f1 = var_f1 < sp14[1] ? sp14[1] : var_f1;
    arg1->y = var_f1;
    f32 var_f2 = arg1->z;
    var_f2 = var_f2 < sp14[2] ? sp14[2] : var_f2;
    arg1->z = var_f2;
    var_f1 = arg2->x;
    var_f1 = var_f1 > sp14[0] ? sp14[0] : var_f1;
    arg2->x = var_f1;
    var_f1 = arg2->y;
    var_f1 = var_f1 > sp14[1] ? sp14[1] : var_f1;
    arg2->y = var_f1;
    var_f1 = arg2->z;
    var_f1 = var_f1 > sp14[2] ? sp14[2] : var_f1;
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
extern int fn_8019A788(void *, int, void *, void *, int, int, float, float, float);
#pragma use_lmw_stmw off
extern "C" void fn_801A38E4(int arg0, void *arg1) {
    u8 *base = (u8 *)arg1;
    f32 q[3];
    f32 n1[3];
    f32 n0[3];
    f32 n3[3];
    f32 n2[3];
    f32 zero0[3];
    f32 zero1[3];
    f32 axis[3];
    f32 depth0;
    f32 depth1;
    switch (*(s32 *)(base + 0x18)) {
    case 0x464c5352: {
        f32 dot;
        f32 a;
        f32 cur;
        f32 hi;
        axis[0] = lbl_805622D0;
        axis[1] = lbl_805622DC;
        axis[2] = lbl_805622D0;
        dot = PSVECDotProduct(axis, (u8 *)*(void **)(base + 0xc) + 0xc);
        a = __fabs(dot);
        hi = *(f32 *)(base + 0x58);
        cur = *(f32 *)(base + 0x54);
        *(f32 *)(base + 0x24) = cur + a * (hi - cur);
    }
    default:
        break;
    case 0x53504852: {
        u8 *owner = *(u8 **)(base + 4);
        if (owner != 0) {
            u8 *node = *(u8 **)(owner + 0xd0);
            if (node != 0) {
                f32 z = lbl_805622D0;
                f32 c = lbl_805623C0;
                while (node != 0) {
                    f32 *v = (f32 *)(node + 4);
                    MtxMulVecRevInl((f32 *)(owner + 0x3c), v, q);
                    q[0] = q[0] + *(f32 *)(owner + 0x60);
                    q[1] = q[1] + *(f32 *)(owner + 0x64);
                    q[2] = q[2] + *(f32 *)(owner + 0x68);
                    q[1] = q[1] + c;
                    zero0[0] = z; zero0[1] = z; zero0[2] = z;
                    if (fn_80198F64(q, arg0, n0, &depth0, n1, zero0, c)) {
                        fn_8019A788(arg1, (void *)arg0, n0, (Vec *)n1, 0, 0, depth0, lbl_805622D0, lbl_805622D0);
                    }
                    node = *(u8 **)node;
                }
            }
        }
        zero1[0] = lbl_805622D0; zero1[1] = lbl_805622D0; zero1[2] = lbl_805622D0;
        if (fn_80198F64(base + 0x34, arg0, n2, &depth1, n3, zero1, *(f32 *)(base + 0x24))) {
            fn_8019A788(arg1, (void *)arg0, n2, (Vec *)n3, 0, 0, depth1, lbl_805622D0, lbl_805622D0);
        }
        break;
    }
    }
}
extern f32 lbl_80562314;
extern "C" void fn_801E41D8(void*, void*, s32, f32);
extern "C" void fn_801A3BE0(void* arg0, void* arg1) {
    f32 pos[3];
    f32 out[3];
    f32 v[3];
    f32* entry = (f32*)((u8*)arg0 + 0x3C);
    void* matrix = *(void**)((u8*)arg0 + 0xC);
    s32 count = *(s32*)((u8*)arg0 + 0xBC);
    s32 i;
    pos[0] = *(f32*)((u8*)matrix + 0x24);
    pos[1] = *(f32*)((u8*)matrix + 0x28);
    pos[2] = *(f32*)((u8*)matrix + 0x2C);
    for (i = 0; i < count; i++, entry += 4) {
        f32 w = entry[3];
        v[0] = entry[0] * w;
        v[1] = entry[1] * w;
        v[2] = entry[2] * w;
        out[0] = v[0] * *(f32*)matrix + v[1] * *(f32*)((u8*)matrix + 0xC) + v[2] * *(f32*)((u8*)matrix + 0x18);
        out[1] = v[0] * *(f32*)((u8*)matrix + 4) + v[1] * *(f32*)((u8*)matrix + 0x10) + v[2] * *(f32*)((u8*)matrix + 0x1C);
        out[2] = v[0] * *(f32*)((u8*)matrix + 8) + v[1] * *(f32*)((u8*)matrix + 0x14) + v[2] * *(f32*)((u8*)matrix + 0x20);
        out[0] += *(f32*)((u8*)matrix + 0x24);
        out[1] += *(f32*)((u8*)matrix + 0x28);
        out[2] += *(f32*)((u8*)matrix + 0x2C);
        fn_801E41D8(pos, out, lbl_8055E598, lbl_80562314);
    }
}

#pragma push
#pragma small_data off
extern s32 lbl_80333728;
extern "C" void *fn_801A3DAC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
#pragma push
#pragma small_data off
    extern s32 lbl_80333728;
#pragma pop
    struct Vec { f32 x, y, z; };
    void *object;
    Vec *vectors;
    volatile Vec maxSpill, minSpill;
    register f32 init = lbl_805622E0;
    register s32 offset;
    register s32 i;
    *(volatile s32 *)((u8 *)arg0 + 0x0C) = arg1;
    *(volatile s32 *)((u8 *)arg0 + 0x04) = arg3;
    *(volatile s32 *)((u8 *)arg0 + 0x08) = 0;
    *(volatile s32 *)((u8 *)arg0 + 0x18) = 0x504D5348;
    *(volatile f32 *)((u8 *)arg0 + 0x10) = init;
    *(volatile f32 *)((u8 *)arg0 + 0x14) = init;
    *(volatile s32 *)((u8 *)arg0 + 0x20) = 100;
    *(volatile s32 *)((u8 *)arg0 + 0x1C) = 0;
    *(volatile void **)arg0 = &lbl_80333728;
    object = (void *)fn_801CFEAC((void *)arg2);
    *(volatile void **)((u8 *)arg0 + 0x24) = object;
    vectors = (Vec *)*(void **)((u8 *)object + 0x08);
    i = 1;
    offset = 0x0C;
    {
        register f32 z;
        register f32 y;
        register f32 x;
        x = vectors[0].x;
        *(volatile f32 *)((u8 *)arg0 + 0x34) = x;
        y = vectors[0].y;
        *(volatile f32 *)((u8 *)arg0 + 0x38) = y;
        z = vectors[0].z;
        *(volatile f32 *)((u8 *)arg0 + 0x3C) = z;
        *(volatile f32 *)((u8 *)arg0 + 0x28) = x;
        *(volatile f32 *)((u8 *)arg0 + 0x2C) = y;
        *(volatile f32 *)((u8 *)arg0 + 0x30) = z;
    }
    while (i < *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x24) + 0x0C)) {
        void *loopObject = *(void **)((u8 *)arg0 + 0x24);
        Vec *base = (Vec *)*(void **)((u8 *)loopObject + 0x08);
        Vec *point = (Vec *)((u8 *)base + offset);
        f32 maxZ = *(volatile f32 *)((u8 *)arg0 + 0x30);
        maxZ = maxZ < point->z ? point->z : maxZ;
        f32 maxY = *(volatile f32 *)((u8 *)arg0 + 0x2C);
        maxY = maxY < point->y ? point->y : maxY;
        f32 maxX = *(volatile f32 *)((u8 *)arg0 + 0x28);
        maxX = maxX < point->x ? point->x : maxX;
        f32 minZ = *(volatile f32 *)((u8 *)arg0 + 0x3C);
        *(volatile f32 *)((u8 *)arg0 + 0x28) = maxX;
        *(volatile f32 *)((u8 *)arg0 + 0x2C) = maxY;
        *(volatile f32 *)((u8 *)arg0 + 0x30) = maxZ;
        maxSpill.x = maxX; maxSpill.y = maxY; maxSpill.z = maxZ;
        void *minLoopObject = *(void **)((u8 *)arg0 + 0x24);
        Vec *minBase = (Vec *)*(void **)((u8 *)minLoopObject + 0x08);
        Vec *minPoint = (Vec *)((u8 *)minBase + offset);
        minZ = minZ > minPoint->z ? minPoint->z : minZ;
        f32 minY = *(volatile f32 *)((u8 *)arg0 + 0x38);
        minY = minY > minPoint->y ? minPoint->y : minY;
        f32 minX = *(volatile f32 *)((u8 *)arg0 + 0x34);
        minX = minX > minPoint->x ? minPoint->x : minX;
        minSpill.x = minX; minSpill.y = minY; minSpill.z = minZ;
        *(volatile f32 *)((u8 *)arg0 + 0x34) = minX;
        *(volatile f32 *)((u8 *)arg0 + 0x38) = minY;
        *(volatile f32 *)((u8 *)arg0 + 0x3C) = minZ;
        offset += 0x0C;
        ++i;
    }
    return arg0;
}
#pragma pop
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
    /* Dispatch by tag at +0x18: 0x47525550 -> virtual Call via Fn801A401CDispatch;
       0x53504852 -> generate up to 0x40 0xC-byte points with fn_801CF080 into a local buffer
       (scaled by lbl_8056234C * source->scale) and call fn_8019AA18 for each point. */
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
        u8 pointBuffer[0x300];
        register u8 *currentPoint;
        register SPHRArg *source = (SPHRArg *)arg1;
        volatile s32 pointCount = 0x40;
        register f32 scaleFactor = lbl_8056234C;
        register f32 sourceScale = source->scale;
        fn_801CF080(*(s32 *)((u8 *)arg0 + 0x24), source->data, pointBuffer,
                    (s32 *)&pointCount, *(s32 *)((u8 *)arg0 + 0x0C),
                    scaleFactor * sourceScale);
        currentPoint = pointBuffer;
        register s32 pointIndex = 0;
        while (pointIndex < pointCount) {
            fn_8019AA18(source, (s32)currentPoint, 0x6E, (s32)arg0);
            currentPoint += 0xC;
            pointIndex++;
        }
    }
}

#pragma scheduling invalid_target
extern "C" s32 fn_801A40F8(void *arg0, f32 *arg1, f32 *arg2, s32 arg3, f32 *arg4) {
    f32 stack[9];
    f32 ix = arg1[0];
    f32 iy = arg1[1];
    f32 *m = (f32 *)*(void * volatile *)((u8 *)arg0 + 0xC);
    f32 dx = ix - m[9];
    f32 iz = arg1[2];
    stack[6] = dx;
    f32 dy = iy - m[10];
    stack[7] = dy;
    f32 dz = iz - m[11];
    stack[8] = dz;
    {
        f32 y0 = dy * m[1];
        f32 x0 = dx * m[0];
        f32 x1 = dx * m[3];
        f32 y1 = dy * m[4];
        f32 x2 = dx * m[6];
        f32 y2 = dy * m[7];
        f32 z0 = dz * m[2];
        f32 z1 = dz * m[5];
        f32 z2 = dz * m[8];
        stack[6] = z0 + (x0 + y0);
        stack[7] = z1 + (x1 + y1);
        stack[8] = z2 + (x2 + y2);
    }
    f32 *m2 = (f32 *)*(void * volatile *)((u8 *)arg0 + 0xC);
    if (&stack[3] == arg2) {
        f32 y = arg2[1];
        f32 x = arg2[0];
        f32 z = arg2[2];
        f32 y0 = y * m2[1];
        f32 x0 = x * m2[0];
        f32 x1 = x * m2[3];
        f32 y1 = y * m2[4];
        f32 x2 = x * m2[6];
        f32 y2 = y * m2[7];
        f32 z0 = z * m2[2];
        f32 z1 = z * m2[5];
        f32 z2 = z * m2[8];
        stack[3] = z0 + (x0 + y0);
        stack[4] = z1 + (x1 + y1);
        stack[5] = z2 + (x2 + y2);
    } else {
        stack[3] = (arg2[2] * m2[2]) + ((arg2[0] * m2[0]) + (arg2[1] * m2[1]));
        stack[4] = (arg2[2] * m2[5]) + ((arg2[0] * m2[3]) + (arg2[1] * m2[4]));
        stack[5] = (arg2[2] * m2[8]) + ((arg2[0] * m2[6]) + (arg2[1] * m2[7]));
    }
    typedef s32 (*Call)(s32, f32 *, f32 *, s32, f32 *);
    if (((Call)fn_801CF828)(*(s32 *)((u8 *)arg0 + 0x24), &stack[6], &stack[3], arg3, &stack[0]) != 0) {
        f32 *m3 = (f32 *)*(void **)((u8 *)arg0 + 0xC);
        if (arg4 == &stack[0]) {
            f32 y = stack[1];
            f32 x = stack[0];
            f32 z = stack[2];
            f32 y0 = y * m3[3];
            f32 y1 = y * m3[4];
            f32 x0 = x * m3[0];
            f32 x1 = x * m3[1];
            f32 x2 = x * m3[2];
            f32 y2 = y * m3[5];
            f32 z0 = z * m3[6];
            f32 z1 = z * m3[7];
            f32 z2 = z * m3[8];
            arg4[0] = z0 + (x0 + y0);
            arg4[1] = z1 + (x1 + y1);
            arg4[2] = z2 + (x2 + y2);
        } else {
            arg4[0] = (stack[2] * m3[6]) + ((stack[0] * m3[0]) + (stack[1] * m3[3]));
            arg4[1] = (stack[2] * m3[7]) + ((stack[0] * m3[1]) + (stack[1] * m3[4]));
            arg4[2] = (stack[2] * m3[8]) + ((stack[0] * m3[2]) + (stack[1] * m3[5]));
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
extern "C" f32 fn_801A4460(s32 arg0) {
    f32 first = PSVECDotProduct((Vec*)(arg0 + 0x34), (Vec*)(arg0 + 0x34));
    f32 second = PSVECDotProduct((Vec*)(arg0 + 0x28), (Vec*)(arg0 + 0x28));
    f32 selected = second > first ? second : first;
    return (f32)fn_8002F234(selected);
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
extern "C" void* fn_801A4B5C(void*, s32, void*);
static inline void Swap4(u8* q) {
    u8 t;
    t = q[0]; q[0] = q[3]; q[3] = t;
    t = q[1]; q[1] = q[2]; q[2] = t;
}
extern "C" void fn_801A4538(void*);
extern "C" void* fn_801A4548(s32 arg0) {
    s32 size;
    u8 ok = 0;
    Fn801A4548Hdr* h = (Fn801A4548Hdr*)((s32 (*)(s32, s32, s32*, s32, s32, s32))fn_8012C370)(arg0, 0x534F424C, &size, 0, 0, (s32)&ok);
    if (h && ok) {
        u8* p = (u8*)h;
        s32* lp = (s32*)&h->list;
        Fn801A4548Swap4(p);
        Fn801A4548Swap4(p+8);
        Fn801A4548Swap4(p+4);
        Fn801A4548Swap4(p+12);
        Fn801A4548Swap4(p+16);
        fn_801A4768(lp, (s32)h);
        fn_801A4780((s32*)&h->unk10, (s32)h);
        fn_801A4798((s32*)&h->shorts, (s32)h);
        for (s32 i=0; i<h->count; i++) {
            Fn801A4548Swap4(h->list+i*4);
            fn_801A47B0((s32*)(h->list+i*4), (s32)h);
        }
        for (s32 i=0; i<h->count2; i++) {
            Fn801A4548Swap2(h->shorts+i*2);
        }
        fn_8019EB14(h->unk10, 0);
        for (s32 i=0; i<h->count; i++) {
            s32 q=*(s32*)(h->list+i*4);
            s32 a2 = q+0x4c;
            u8 okv = ok;
            if (q) ((void (*)(s32, s32, s32))fn_801A4B5C)(q, okv, a2);
        }
        h->fn=(void*)fn_801A4538;
    }
    return h;
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

#pragma push
#pragma unroll off
extern "C" void fn_801A47C8(void* arg0) {
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    while (i < *(s32*)arg0) {
        void** entries = *(void***)((u8*)arg0 + 4);
        i += 1;
        void* p = *(void**)((u8*)entries + off);
        *(u8*)((u8*)p + 0x40) = 1;
        off += 4;
    }
}
#pragma pop
extern "C" void fn_801A47FC(void* arg0) {
    register s32* r29 = (s32*)arg0;
    if (r29 == 0) {
        return;
    }
    register s32 r30;
    register s32 r31;
    r31 = 0;
    r30 = 0;
    goto check;
loop:
    fn_801A49E8((void*)(*(s32*)((u8*)r29[1] + r30)));
    r30 += 4;
    r31++;
check:
    if (r31 < r29[0]) goto loop;
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
    f32 matVal;
    f32 mul;
    f32 x;
    f32 y;
    f32 z;
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
        matVal = *(f32*)((u8*)*(void**)(obj + 0x3C) + 0x28);
        mul = scale * matVal;
        x = *(f32*)(obj + 0x28) + *(f32*)(obj + 0x1C) * mul;
        y = *(f32*)(obj + 0x2C) + *(f32*)(obj + 0x20) * mul;
        z = *(f32*)(obj + 0x30) + *(f32*)(obj + 0x24) * mul;
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
extern "C" void fn_801A4A10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) { if (*(u8*)((u8*)arg0 + 0x40) != 0) { fn_801D2414(); if (*(s32*)((u8*)arg0 + 0x48) != 0) { fn_801D0738((void*)arg0, (void*)arg1, (void*)arg2, (void*)arg3); } } }
#pragma scheduling on
extern "C" void* fn_801A4A8C(void* arg0, s32 arg1, s32 arg2, void* arg3, u32* arg4, s32 arg5, s32 arg6) {
    struct VTable2C {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void Call(void*, s32, s32);
    };
    s32 t11; s32 t10; s32 t9; s32 t8; s32 t7; s32 t6;
    s32 t5; s32 t4; s32 t3; s32 t2; s32 t1; s32 t0;
    t0 = arg4[0]; t1 = arg4[1]; t2 = arg4[2]; t3 = arg4[3];
    t4 = arg4[4]; t5 = arg4[5]; t6 = arg4[6]; t7 = arg4[7];
    t8 = arg4[8]; t9 = arg4[9]; t10 = arg4[10]; t11 = arg4[11];
    void* vtable = lbl_803336F8;
    *(s32*)((u8*)arg0 + 0x38) = arg1;
    *(void**)arg0 = vtable;
    *(s32*)((u8*)arg0 + 0x48) = arg5;
    *(s32*)((u8*)arg0 + 0x34) = arg2;
    *(void**)((u8*)arg0 + 0x3C) = arg3;
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
    ((VTable2C*)arg3)->Call(arg0, arg2, (s32)arg3);
    fn_801A48E4(arg0);
    return arg0;
}

extern "C" void* fn_801A4B5C(void* arg0, s32 arg1, void* arg2) {
    u8* p = (u8*)arg0;
    s32 magic;
    s32 i;
    *(void**)arg0 = lbl_803336F8;
    if (arg1) {
        Swap4(p + 0x34);
        Swap4(p + 0x38);
        for (i = 0; i < 2; i++) {
            u8* q = p + 4 + i * 0x18;
            Swap4(q); Swap4(q + 4); Swap4(q + 8);
            Swap4(q + 0xC); Swap4(q + 0x10); Swap4(q + 0x14);
        }
    }
    *(s32*)(p + 0x48) = 0;
    magic = *(s32*)((u8*)arg2 + 0x18);
    if (arg1) Swap4((u8*)&magic);
    switch (magic) {
    case 0x424F5820:
        if (arg2) arg2 = ((void* (*)(void*, void*, s32))fn_801A1CE4)(arg2, arg0, arg1);
        *(void**)(p + 0x3C) = arg2;
        break;
    case 0x53504852:
        if (arg2) arg2 = ((void* (*)(void*, void*, s32))fn_8019EDB8)(arg2, arg0, arg1);
        *(void**)(p + 0x3C) = arg2;
        break;
    case 0x54554245:
        if (arg2) arg2 = ((void* (*)(void*, void*, s32))fn_801A1898)(arg2, arg0, arg1);
        *(void**)(p + 0x3C) = arg2;
        break;
    case 0x52494E47:
        if (arg2) arg2 = ((void* (*)(void*, void*, s32))fn_801A2CC0)(arg2, arg0, arg1);
        *(void**)(p + 0x3C) = arg2;
        break;
    case 0x504D5348:
        if (arg2) arg2 = ((void* (*)(void*, void*, s32))fn_801A3F5C)(arg2, arg0, arg1);
        *(void**)(p + 0x3C) = arg2;
        break;
    default:
        *(void**)(p + 0x3C) = 0;
        break;
    }
    fn_801A48E4(arg0);
    return arg0;
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
extern "C" s32 fn_801A4E88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    if ((lbl_8055E5A0 != 0) && (fn_801CF828(lbl_8055E5A0, arg0, arg1, arg2, arg3) != 0)) {
        *arg4 = 0x6E;
        return 1;
    }
    return 0;
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


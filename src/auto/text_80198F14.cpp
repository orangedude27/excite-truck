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
struct CornerV3 {
    f32 x, y, z;
};
static inline void CornerV3Copy(CornerV3* d, const CornerV3* s) {
    ((u32*)d)[0] = ((const u32*)s)[0];
    ((u32*)d)[1] = ((const u32*)s)[1];
    ((u32*)d)[2] = ((const u32*)s)[2];
}

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
extern s32 trackMesh;
extern "C" s32 fn_801CF080(s32, void*, void*, s32*, s32, f32);
extern "C" s32 fn_8019A820(void*, void*, s32, s32, s32, f32);
extern "C" s32 fn_801E9F08(void*, void*, void*, s32, s32, f32);
extern "C" void fn_8017B4AC(void*, Vec*);
extern "C" f32 fn_8019DF88(void*, f32*, void*, f32*, f32*, f32, f32);
// 3x3 matrix times vector; the original inlines it with a src == dst check, so both branches are emitted.
#pragma always_inline on
static inline void Fn8019DF88MultVec(const f32 *m, const f32 *src, f32 *dst) {
    if (dst == src) {
        f32 p0 = m[3] * src[1], p1 = m[4] * src[1], p5 = m[5] * src[1];
        f32 p2 = m[0] * src[0], p3 = m[1] * src[0], p4 = m[2] * src[0];
        f32 p6 = m[6] * src[2], p7 = m[7] * src[2], p8 = m[8] * src[2];
        f32 x = p6 + (p2 + p0), y = p7 + (p3 + p1), z = p8 + (p4 + p5);
        dst[0] = x; dst[1] = y; dst[2] = z;
    } else {
        f32 q0 = m[3] * src[1], q1 = m[4] * src[1], q5 = m[5] * src[1];
        f32 q2 = m[0] * src[0], q3 = m[1] * src[0], q4 = m[2] * src[0];
        f32 q6 = m[6] * src[2], q7 = m[7] * src[2], q8 = m[8] * src[2];
        f32 x0 = q6 + (q2 + q0), y0 = q7 + (q3 + q1), z0 = q8 + (q4 + q5);
        dst[0] = x0; dst[1] = y0; dst[2] = z0;
    }
}
#pragma always_inline reset
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
extern "C" void fn_8019ECC4(void*, s32, s32);
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
extern "C" void Abend_Panic(const char*, ...);
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
extern "C" s32 MeshRayCast_801CF828(s32, s32, s32, s32, s32);
extern s32 trackMesh;
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
extern "C" void fn_801A5C4C(void*, u32 = 0);
extern "C" void fn_8017B6D4(s32, Vec*, s32);
extern f32 lbl_805622D0, lbl_805622E4, lbl_805622E8;
extern "C" f32 PSVECMag(const Vec*);
#pragma dont_inline on
/* Deleting destructor for PSGame::SoundTable::CategoryMgr: clear the first word, and free when shouldDelete > 0. */
extern "C" void* __dt__Q36PSGame10SoundTable11CategoryMgrFv(void* thisPtr, s32 shouldDelete) {
    if (thisPtr != NULL) {
        if (thisPtr != NULL) {
            *(u32*)thisPtr = 0;
        }
        if (shouldDelete > 0) {
            ((void (*)(void*))fn_80128668)(thisPtr);
        }
    }
    return thisPtr;
}

extern "C" f64 __fabs(f64);
#pragma push
#pragma ppc_psq_save off
#pragma paired off
#pragma paired_single off
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" int fn_80198F64(void *arg0, int arg1, void *arg2, float *arg3, void *arg4, float *arg5, float farg0) {
    f32 *pt = (f32 *)arg0;
    u8 *obj = (u8 *)arg1;
    f32 *outPos = (f32 *)arg2;
    f32 *outDepth = arg3;
    f32 *outDir = (f32 *)arg4;
    f32 *inVec = (f32 *)arg5;
    f32 radius = farg0;
    f32 *m = *(f32 **)(obj + 0xC);
    f32 sp5C[3], sp50[3], sp48[3], sp44[3], sp38[3], sp2C[3];
    s32 sp20[3];
    f32 sp14[3], sp8[3], sp68[8][4];
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
        s32 var_r31 = 0, var_r25 = 0, var_r23 = 0;
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
                f32 t, mag;
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
                        f32 w0 = p[3], w1 = p[7];
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
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* The slip a contact has to rub off.  For the two shapes that touch, it takes
 * the velocity each one has at the contact point (fn_8017B6D4; a shape with no
 * rigid body at +0x04 counts as still), takes their difference and drops the
 * part of it along the contact normal, leaving how the two surfaces slide over
 * each other.  That tangential slip is turned around and scaled by kSlipScale,
 * then shortened to at most half the two shapes' radii added times `scale`, and
 * written to `out`. */
extern "C" void computeContactSlip(Vec* out, s32 contactPoint, Vec* normal, void* shapeA, void* shapeB, f32 scale) {
    #define kZero      lbl_805622D0 /* 0.0f */
    #define kSlipScale lbl_805622E4 /* -1000.0f */
    #define kHalf      lbl_805622E8 /* 0.5f */
    /* The two shapes of a contact, as fn_80199894 hands them over. */
    struct Collider {
        u8  pad00[0x04];
        s32 body;      /* +0x04: rigid body moving the shape, 0 when it cannot move */
        u8  pad08[0x08];
        f32 push;      /* +0x10: how hard the shape pushes, used by the caller */
        f32 radius;    /* +0x14: how far the contact may move it */
    };
    Vec proj, rel, velA, velB, slip;
    f32 dot, mag, limit;
    s32 bodyA = ((Collider *)shapeA)->body;
    s32 bodyB = ((Collider *)shapeB)->body;
    if (bodyA) fn_8017B6D4(bodyA, &velA, contactPoint);
    else { velA.x=kZero; velA.y=kZero; velA.z=kZero; }
    if (bodyB) fn_8017B6D4(bodyB, &velB, contactPoint);
    else { velB.x=kZero; velB.y=kZero; velB.z=kZero; }
    rel.x=velA.x-velB.x; rel.y=velA.y-velB.y; rel.z=velA.z-velB.z;
    dot=PSVECDotProduct(normal,&rel);
    proj.x=normal->x*dot; proj.y=normal->y*dot; proj.z=normal->z*dot;
    rel.x-=proj.x; rel.y-=proj.y; rel.z-=proj.z;
    slip.x=rel.x*kSlipScale; slip.y=rel.y*kSlipScale; slip.z=rel.z*kSlipScale;
    mag=PSVECMag(&slip);
    {
        f32 k = kHalf * scale;
        f32 radiusB = ((Collider *)shapeB)->radius;
        f32 radiusA = ((Collider *)shapeA)->radius;
        limit = k * (radiusA + radiusB);
    }
    if (mag>limit) { f32 s=limit/mag; slip.x*=s; slip.y*=s; slip.z*=s; }
    out->x = slip.x;
    out->y = slip.y;
    out->z = slip.z;

    #undef kZero
    #undef kSlipScale
    #undef kHalf
}
#pragma pop
extern "C" void fn_80199870(void* car, u32 key = 0) {
    /* Forward a car to fn_801A5C4C only when its +0x10 tag is 'PCAR' (0x50434152) or 'ACAR' (0x41434152). */
    u32 tag = *(u32*)((u8*)car + 0x10);
    if ((u32)(tag - 0x50430000) == 0x4152 ||
        (u32)(tag - 0x41430000) == 0x4152) {
        fn_801A5C4C(car, key);
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
    computeContactSlip((Vec*)(f32 *)&sp[58], (s32)((f32 *)arg2_raw), (Vec*)((f32 *)arg3_raw), arg0, arg1, var_f1);
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
/* Returns the 32-bit field at offset 8 of the given object. */
extern "C" s32 fn_8019A780(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

extern "C" void fn_80199894(void*, void*, void*, void*, s32, s32, f32, f32, f32);
#pragma scheduling invalid_target
/* Wrapper for fn_80199894: passes through when arg0 has a flag at +4 or arg4 is set;
 * otherwise swaps the two object args, negates/scales the direction vector (lbl_805622DC)
 * into a temp, and swaps the index/flag pair and the two float params. */
extern "C" void fn_8019A788(void *first, void *second, void *param3,
                            Vec *direction, s32 flag4, s32 flag5,
                            f32 depth, f32 paramF1, f32 paramF2) {
    f32 savedParamF1 = paramF1;

    if (*(s32 *)((u8 *)first + 4) != 0 || flag4 != 0) {
        fn_80199894(first, second, param3, direction, flag4, flag5,
                    depth, savedParamF1, paramF2);
    } else {
        register f32 x = direction->x;
        register f32 scale = lbl_805622DC;
        register f32 sx = x * scale;
        register f32 sy = direction->y * scale;
        register f32 sz = direction->z * scale;
        Vec scaledDirection;
        scaledDirection.x = sx;
        scaledDirection.y = sy;
        scaledDirection.z = sz;
        fn_80199894(second, first, param3, &scaledDirection, flag5, flag4,
                    depth, paramF2, savedParamF1);
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" s32 fn_8019A820(void* arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    struct VtblObj {
        virtual void unused0() {}
        virtual void unused1() {}
        virtual void unused2() {}
        virtual void unused3() {}
        virtual void unused4() {}
        virtual void slot7(Vec *, s32, s32, s32) {}
        virtual void slot8(s32, Vec *, s32, s32, s32, s32, f32) {}
    };
    Vec d, dir, v20, delta, v8;
    f32 mag, rem, var4, ret, k, dx, dy, dz;
    s32 obj;
    const Vec* a = (const Vec*)arg1;
    const Vec* b = (const Vec*)arg2;
    dx = a->x - b->x;
    dy = a->y - b->y;
    d.x = dx;
    dz = a->z - b->z;
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
        ((VtblObj *)arg0)->slot7(&delta, arg2, arg3, 0);
        ret = fn_8019DF88((void*)(obj + 0x60), (f32*)&v20, (void*)(obj + 0x148), (f32*)arg2, (f32*)&dir, *(f32*)(obj + 0xD4), lbl_80562314);
        if (ret > lbl_805622D0) {
            v8.x = dir.x * ret; v8.y = dir.y * ret; v8.z = dir.z * ret;
            var4 = lbl_805622D4;
            var4 = (var4 > rem) ? var4 : rem;
            ((VtblObj *)arg0)->slot8(arg4, &v8, arg2, arg3, 0, 0, var4);
            fn_801B34DC(arg0, 0, (Vec*)arg2, &v8, &dir, arg3);
        }
        return 1;
    }
    return 0;
}
#pragma pop
extern "C" void fn_8019AA18(void* source, s32 point, s32 type, s32 vehicle) {
    /* Forward a generated SPHR collision point to fn_8019A820, supplying the
     * source's +0x34 vector and +0x24 float alongside the three forwarded args. */
    fn_8019A820(source, (u8*)source + 0x34, point, type, vehicle, *(f32*)((u8*)source + 0x24));
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" s32 fn_8019AA34(void *obj, void *pos, void *other, void *otherPos, s32 a, s32 b, f32 radius, f32 otherRadius) {
    Vec delta, normal, point;
    Vec *p = (Vec *)pos;
    Vec *q = (Vec *)otherPos;
    f32 dx = p->x - q->x;
    f32 dy = p->y - q->y;
    f32 dz = p->z - q->z;
    f64 absdx = __fabs((f64)dx);
    f32 adx = (f32)absdx;
    f32 sum = radius + otherRadius;
    delta.x = dx;
    delta.z = dz;
    delta.y = dy;
    s32 result = 0;
    if (adx < sum && (f32)__fabs((f64)dz) < sum && (f32)__fabs((f64)dy) < sum) {
        f32 length = PSVECMag(&delta);
        if (!((f32)__fabs((f64)length) <= lbl_80558DC4)) {
            f32 depth = otherRadius + (-length + radius);
            if (depth > lbl_805622D0) {
                f32 scale = lbl_805622E0 / length;
                f32 nz, ny, nx;
                nx = delta.x * scale;
                ny = delta.y * scale;
                nz = delta.z * scale;
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
static inline f32 fn_8019AC44_max(f32 a, f32 b) {
    if (a <= b) return b;
    return a;
}

extern "C" void fn_8019AC44(void* arg0, void* arg1, void* arg2, f32 farg0) {
    Vec work[64]; s32 count, sp8; Vec p70,p64,delta,p4c,p40,p34,p28,p1c,p10;
    f32 dot,mag,limit,scale,varf1,f31,dx,dy,dz,tx,ty,tz,ux,uy,uz,vx,vy,vz,px,py,pz; void* body=*(void**)((u8*)arg0+4);
    if (trackMesh!=0) { count=0x40; fn_801CF080((s32)trackMesh,arg1,work,&count,0,farg0); Vec *wp = work; for(s32 i=0;i<count;wp++,++i) fn_8019A820(arg0,arg1,(s32)wp,0x6e,0,farg0); }
    if (fn_801E9F08((u8*)body+0x6c,arg1,&p70,(s32)&p64,(s32)&sp8,farg0)!=0) {
        dx=((Vec*)arg1)->x-p70.x; dy=((Vec*)arg1)->y-p70.y; dz=((Vec*)arg1)->z-p70.z; delta.x=dx; delta.y=dy; delta.z=dz;
        dot=PSVECDotProduct(&p64,&delta); f31=farg0-dot; fn_8017B6D4((s32)body,&p4c,(s32)&p70);
        farg0=f31* *(f32*)((u8*)arg0+0x10); dot=-PSVECDotProduct(&p4c,&p64);
        px=p64.x; pz=p64.z; py=p64.y;
        tx = px * farg0;
        ux = p4c.x + px * dot;
        uz = p4c.z + pz * dot;
        uy = p4c.y + py * dot;
        ty = py * farg0;
        p40.x = tx;
        tz = pz * farg0;
        p40.y = ty;
        vx = ux * lbl_8056231C;
        p34.x = ux;
        vy = uy * lbl_8056231C;
        p40.z = tz;
        vz = uz * lbl_8056231C;
        ((Vec*)arg2)->x+=vx; ((Vec*)arg2)->y+=vy; ((Vec*)arg2)->z+=vz;
        p34.y = uy; p34.z = uz;
        mag=PSVECMag((Vec*)arg2); if(mag>lbl_80562320){scale=lbl_80562320/mag;((Vec*)arg2)->x*=scale;((Vec*)arg2)->y*=scale;((Vec*)arg2)->z*=scale;}
        p28.x=p34.x*lbl_80562324; p28.y=p34.y*lbl_80562324; p28.z=p34.z*lbl_80562324;
        limit=lbl_80562328* *(f32*)((u8*)body+0xd4); p28.x+=((Vec*)arg2)->x*limit;p28.y+=((Vec*)arg2)->y*limit;p28.z+=((Vec*)arg2)->z*limit;
        mag=PSVECMag(&p28); scale=farg0* *(f32*)((u8*)arg0+0x14); scale = (scale > lbl_80562320) ? scale : lbl_80562320;
        if(mag>scale){limit=scale/mag;p28.x*=limit;p28.y*=limit;p28.z*=limit;}
        p40.x+=p28.x;p40.y+=p28.y;p40.z+=p28.z;
        dot=-PSVECDotProduct((Vec*)((u8*)body+0x124),&p64)*farg0*lbl_8056232C;
        p1c.x=p64.x*dot;p1c.y=p64.y*dot;p1c.z=p64.z*dot;
        fn_8017B4AC(body,&p1c);
        { typedef void(*Call)(void*,Vec*,Vec*,s32,s32); Call call=(Call)(*(u32*)(*(u32*)arg0+0x1c)); call(arg0,&p40,&p70,sp8,0); }
        scale=lbl_80562330*fn_8019DF88((u8*)body+0x60,(f32*)&p4c,(void*)((u8*)body+0x148),(f32*)&p70,(f32*)&p64,*(f32*)((u8*)body+0xd4),lbl_805622D0);
        if(scale>lbl_805622D0){
            p10.x=p64.x*scale;p10.y=p64.y*scale;p10.z=p64.z*scale;
            varf1=lbl_805622D4; varf1 = (varf1 > f31) ? varf1 : f31;
            typedef void(*Call2)(void*,s32,Vec*,Vec*,s32,s32,s32,f32);
            Call2 c=(Call2)(*(u32*)(*(u32*)arg0+0x20));c(arg0,0,&p10,&p70,sp8,0,0,varf1);
        } else fn_801B34DC(arg0,0,&p70,&p10,&p64,sp8);
    } else {((Vec*)arg2)->x=lbl_805622D0;((Vec*)arg2)->y=lbl_805622D0;((Vec*)arg2)->z=lbl_805622D0;}
}
#pragma pop

extern "C" s32 fn_8019AA34(void*, void*, void*, void*, s32, s32, f32, f32);
void fn_8019B068(void* objA, void* objB, s32 param0, s32 param1) {
    /* Sphere/sphere collision wrapper: run fn_8019AA34 on the two collision objects'
       world positions (+0x34) and collision radii (+0x24). */
    f32 radiusB = *(f32*)((u8*)objB + 0x24);
    typedef s32 (*Call9)(void*, void*, void*, void*, s32, s32, void*, f32, f32);
    ((Call9)fn_8019AA34)(objA, (u8*)objA + 0x34, objB, (u8*)objB + 0x34, param0, param1, objB, *(f32*)((u8*)objA + 0x24), radiusB);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" s32 fn_8019B08C(void* arg0, const Vec* arg1, void* arg2, f32 farg0) {
    void* objA = arg0;
    const Vec* point = arg1;
    void* objB = arg2;
    f32* m = *(f32**)((u8*)objB + 0xC);
    Vec local, tmp, worldPoint, normal, worldNormal, copy;
    f32 dx = point->x - m[9];
    f32 dy = point->y - m[10];
    f32 dz = point->z - m[11];
    local.z = (dz * m[8] + (dx * m[6] + dy * m[7]));
    local.x = (dz * m[2] + (dx * m[0] + dy * m[1]));
    local.y = (dz * m[5] + (dx * m[3] + dy * m[4]));
    f32 halfHeight = *(f32*)((u8*)objB + 0x28);
    if (local.z < halfHeight && local.z > -halfHeight) {
        f32 mag = (f32)fn_8002F234(local.x * local.x + local.y * local.y);
        if ((f32)__fabs((f64)mag) > lbl_80558DC4) {
            f32 radius = *(f32*)((u8*)objB + 0x24);
            f32 depth = farg0 + (-mag + radius);
            if (depth > lbl_805622D0) {
                f32 scale = (radius - depth) / mag;
                tmp.x = local.x * scale;
                tmp.y = local.y * scale;
                tmp.z = local.z;
                {
                    f32* dst = &worldPoint.x;
                    f32* src = &tmp.x;
                    if (dst == src) {
                        f32 x = src[0], y = src[1], z = src[2];
                        dst[0] = (y*m[3]+x*m[0]) + z*m[6];
                        dst[1] = (y*m[4]+x*m[1]) + z*m[7];
                        dst[2] = (y*m[5]+x*m[2]) + z*m[8];
                    } else {
                        dst[0] = (src[1]*m[3]+src[0]*m[0]) + src[2]*m[6];
                        dst[1] = (src[1]*m[4]+src[0]*m[1]) + src[2]*m[7];
                        dst[2] = (src[1]*m[5]+src[0]*m[2]) + src[2]*m[8];
                    }
                    dst[0] += m[9]; dst[1] += m[10]; dst[2] += m[11];
                }
                normal.x = local.x; normal.y = local.y; normal.z = lbl_805622D0;
                PSVECNormalize(&normal, &normal);
                {
                    f32* mm = *(f32**)((u8*)objB + 0xC);
                    f32* dst = &worldNormal.x;
                    f32* src = &normal.x;
                    if (dst == src) {
                        f32 x = src[0], y = src[1], z = src[2];
                        dst[0] = (y*mm[3]+x*mm[0]) + z*mm[6];
                        dst[1] = (y*mm[4]+x*mm[1]) + z*mm[7];
                        dst[2] = (y*mm[5]+x*mm[2]) + z*mm[8];
                    } else {
                        dst[0] = (src[1]*mm[3]+src[0]*mm[0]) + src[2]*mm[6];
                        dst[1] = (src[1]*mm[4]+src[0]*mm[1]) + src[2]*mm[7];
                        dst[2] = (src[1]*mm[5]+src[0]*mm[2]) + src[2]*mm[8];
                    }
                }
                copy.x = worldNormal.x; copy.y = worldNormal.y; copy.z = worldNormal.z;
                fn_8019A788(objA, objB, &worldPoint, &copy, 0, 0, depth, lbl_805622D0, lbl_805622D0);
                return 1;
            }
        }
    }
    return 0;
}
#pragma pop
extern "C" void fn_802E30C8(const char *, ...);
extern f32 lbl_805622D8, lbl_80562300, lbl_80562334, lbl_80562338, lbl_8056233C;
extern char lbl_80333448[];
extern "C" s32 fn_8019B4D8(void *arg0, void *arg1, void *arg2, s32 arg3, f32 farg0) {
    char *dbg = lbl_80333448;
    f32 *matrix = (f32 *)((VTab1A1E7C *)arg1)->Call();
    f32 m[12];
    s32 *mw = (s32 *)m;
    s32 *src = (s32 *)matrix;
    mw[0] = src[0]; mw[1] = src[1]; mw[2] = src[2]; mw[3] = src[3];
    mw[4] = src[4]; mw[5] = src[5]; mw[6] = src[6]; mw[7] = src[7];
    mw[8] = src[8]; mw[9] = src[9]; mw[10] = src[10]; mw[11] = src[11];
    f32 dx = *(f32 *)arg2 - m[9];
    f32 dy = *(f32 *)((u8 *)arg2 + 4) - m[10];
    f32 dz = *(f32 *)((u8 *)arg2 + 8) - m[11];
    f32 x = dz * m[5] + dx * m[3] + dy * m[4];
    f32 y = dz * m[2] + dx * m[0] + dy * m[1];
    f32 z = dz * m[8] + dx * m[6] + dy * m[7];
    if (arg3 != 0) fn_802E30C8(dbg, *(f32 *)((u8 *)arg1 + 0x24), *(f32 *)((u8 *)arg1 + 0x28), *(f32 *)((u8 *)arg1 + 0x2c));
    f32 lim = *(f32 *)((u8 *)arg1 + 0x24);
    f32 neg = -lim;
    y = (lim < y) ? y : lim;
    y = (y > neg) ? neg : y;
    lim = *(f32 *)((u8 *)arg1 + 0x28);
    neg = -lim;
    x = (lim < x) ? x : lim;
    x = (x > neg) ? neg : x;
    lim = *(f32 *)((u8 *)arg1 + 0x2c);
    neg = -lim;
    z = (lim < z) ? z : lim;
    z = (z > neg) ? neg : z;
    f32 px = z * m[6] + y * m[0] + x * m[3] + m[9];
    f32 py = z * m[7] + y * m[1] + x * m[4] + m[10];
    f32 pz = z * m[8] + y * m[2] + x * m[5] + m[11];
    Vec d;
    d.x = px - *(f32 *)arg2;
    d.y = py - *(f32 *)((u8 *)arg2 + 4);
    d.z = pz - *(f32 *)((u8 *)arg2 + 8);
    f32 dot = PSVECDotProduct(&d, &d);
    f32 f30 = (f32)fn_8002F234(dot);
    f32 f31 = lbl_80562300 + (-f30 + farg0);
    Vec point = { px, py, pz };
    if (f30 < lbl_805622D8) {
        if (arg3 != 0) fn_802E30C8(dbg + 0x28, f30);
        void *r26 = *(void **)((u8 *)arg1 + 4);
        if (r26 != 0) {
            Vec v;
            v.x = *(f32 *)((u8 *)r26 + 0x118) * lbl_805622DC;
            v.y = *(f32 *)((u8 *)r26 + 0x11C) * lbl_805622DC;
            v.z = *(f32 *)((u8 *)r26 + 0x120) * lbl_805622DC;
            f30 = PSVECMag(&v);
            if (arg3 != 0) fn_802E30C8(dbg + 0x58);
            if (f30 < lbl_80562334) {
                if (arg3 != 0) fn_802E30C8(dbg + 0x6C);
                return 0;
            }
            f31 = lbl_80562338;
            if (!(f30 < lbl_805622D8)) goto block67;
            return 0;
        }
        if (arg3 != 0) Abend_Panic(dbg + 0x78);
        Vec vel;
        fn_8017B6D4((s32)r26, &vel, (s32)arg2);
        f32 bx = *(f32 *)arg2 + vel.x * lbl_8056233C;
        f32 by = *(f32 *)((u8 *)arg2 + 4) + vel.y * lbl_8056233C;
        f32 bz = *(f32 *)((u8 *)arg2 + 8) + vel.z * lbl_8056233C;
        f32 ex = bx - m[9];
        f32 ey = by - m[10];
        f32 ez = bz - m[11];
        f32 ax = ez * m[2] + ex * m[0] + ey * m[1];
        f32 ay = ez * m[5] + ex * m[3] + ey * m[4];
        f32 az = ez * m[8] + ex * m[6] + ey * m[7];
        lim = *(f32 *)((u8 *)arg1 + 0x24); neg = -lim;
        ax = (lim < ax) ? ax : lim; ax = (ax > neg) ? neg : ax;
        lim = *(f32 *)((u8 *)arg1 + 0x28); neg = -lim;
        ay = (lim < ay) ? ay : lim; ay = (ay > neg) ? neg : ay;
        lim = *(f32 *)((u8 *)arg1 + 0x2c); neg = -lim;
        az = (lim < az) ? az : lim; az = (az > neg) ? neg : az;
        f32 qx = az * m[6] + ax * m[0] + ay * m[3] + m[9];
        f32 qy = az * m[7] + ax * m[1] + ay * m[4] + m[10];
        f32 qz = az * m[8] + ax * m[2] + ay * m[5] + m[11];
        if (arg3 != 0) fn_802E30C8(dbg, *(f32 *)((u8 *)arg1 + 0x24), *(f32 *)((u8 *)arg1 + 0x28), *(f32 *)((u8 *)arg1 + 0x2c));
        Vec dd;
        dd.x = qx - *(f32 *)arg2;
        dd.y = qy - *(f32 *)((u8 *)arg2 + 4);
        dd.z = qz - *(f32 *)((u8 *)arg2 + 8);
        f30 = PSVECMag(&dd);
        if (arg3 != 0) fn_802E30C8(dbg + 0xB8);
        if (f30 < lbl_805622D8) {
            if (arg3 != 0) fn_802E30C8(dbg + 0xD4);
            return 0;
        }
        f31 = lbl_80562338;
    }
block67:
    if (f31 > lbl_805622D0) {
        f32 inv = lbl_805622DC / f30;
        Vec n;
        n.x = d.x * inv; n.y = d.y * inv; n.z = d.z * inv;
        if (arg3 != 0) {
            fn_802E30C8(dbg + 0x108, *(f32 *)arg0, *(f32 *)((u8 *)arg0 + 4), *(f32 *)((u8 *)arg0 + 0x20));
            void *t4 = *(void **)((u8 *)arg0 + 0xC);
            fn_802E30C8(dbg + 0x12C, *(f32 *)t4, *(f32 *)((u8 *)t4 + 0x24), *(f32 *)((u8 *)t4 + 0x28), *(f32 *)((u8 *)t4 + 0x2C));
            fn_802E30C8(dbg + 0x138, f31);
        }
        fn_8019A788(arg0, arg1, &point, &n, 0, 0, f31, lbl_805622D0, lbl_805622D0);
        if (arg3 != 0) fn_802E30C8(dbg + 0x144);
        return 1;
    }
    if (arg3 != 0) fn_802E30C8(dbg + 0x16C, f31);
    return 0;
}

/* Return the 32-bit field at offset 0xC of the object (physics/collision record). */
extern "C" s32 fn_8019BD4C(void *obj) {
    return ((s32 *)obj)[0xC / 4];
}

extern f32 lbl_80562340, lbl_80562344, lbl_8055A4C0;
extern "C" f32 PSVECSquareDistance(const Vec *, const Vec *);
extern "C" void fn_8019BD54(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    Vec *point = (Vec *)arg2;
    f32 sp8C, sp90, sp94;
    f32 sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4;
    f32 sp68, sp6C, sp70, sp74, sp78, sp7C;
    f32 f1, f0_2, f2, f6, f7, f0;
    void *mat = *(void **)((char *)arg1 + 0);
    void *(*getMat)(void *) = *(void *(*)(void *))((char *)mat + 0x50);
    void *m = getMat(arg1);
    if (arg2 == 0) {
        f1 = PSVECSquareDistance((const Vec *)((char *)arg0 + 0x34), (const Vec *)((char *)m + 0x24));
    } else {
        sp8C = point->z * *(f32 *)((char *)m + 0x18) + (point->x * *(f32 *)((char *)m + 0) + point->y * *(f32 *)((char *)m + 0xC));
        sp90 = point->z * *(f32 *)((char *)m + 0x1C) + (point->x * *(f32 *)((char *)m + 4) + point->y * *(f32 *)((char *)m + 0x10));
        sp94 = point->z * *(f32 *)((char *)m + 0x20) + (point->x * *(f32 *)((char *)m + 8) + point->y * *(f32 *)((char *)m + 0x14));
        sp8C += *(f32 *)((char *)m + 0x24);
        sp90 += *(f32 *)((char *)m + 0x28);
        sp94 += *(f32 *)((char *)m + 0x2C);
        f1 = PSVECSquareDistance((const Vec *)((char *)arg0 + 0x34), (const Vec *)&sp8C);
        (void)sp90; (void)sp94;
    }
    f0_2 = *(f32 *)((char *)arg1 + 0x30) + *(f32 *)((char *)arg0 + 0x24);
    if (f1 > f0_2 * f0_2) return;
    sp98 = *(f32 *)((char *)m + 0); sp9C = *(f32 *)((char *)m + 4); spA0 = *(f32 *)((char *)m + 8);
    spA4 = *(f32 *)((char *)m + 0xC); spA8 = *(f32 *)((char *)m + 0x10); spAC = *(f32 *)((char *)m + 0x14);
    spB0 = *(f32 *)((char *)m + 0x18); spB4 = *(f32 *)((char *)m + 0x1C); spB8 = *(f32 *)((char *)m + 0x20);
    spBC = *(f32 *)((char *)m + 0x24); spC0 = *(f32 *)((char *)m + 0x28); spC4 = *(f32 *)((char *)m + 0x2C);
    sp68 = *(f32 *)((char *)arg0 + 0x34);
    f2 = sp68 - spBC;
    sp6C = *(f32 *)((char *)arg0 + 0x38);
    f6 = sp6C - spC0;
    f7 = *(f32 *)((char *)arg0 + 0x3C) - spC4;
    sp70 = *(f32 *)((char *)arg0 + 0x3C);
    f1 = f7 * spA0 + (f2 * sp98 + f6 * sp9C);
    sp74 = f1;
    sp78 = f7 * spAC + (f2 * spA4 + f6 * spA8);
    sp7C = f7 * spB8 + (f2 * spB0 + f6 * spB4);
    f0 = *(f32 *)((char *)arg1 + 0x24);
    if (sp74 > f0) sp74 = f0; else if (sp74 < -f0) sp74 = -f0;
    f0 = *(f32 *)((char *)arg1 + 0x28);
    if (sp78 > f0) sp78 = f0; else if (sp78 < -f0) sp78 = -f0;
    f0 = *(f32 *)((char *)arg1 + 0x2C);
    if (sp7C > f0) sp7C = f0; else if (sp7C < -f0) sp7C = -f0;
    (void)sp70; (void)sp74; (void)sp78; (void)sp7C; (void)lbl_80562340;
    (void)lbl_80562344; (void)lbl_8055A4C0; (void)fn_8002F234;
}

#pragma push
#pragma processor 750
#pragma ppc_psq_save off
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
    point.z = local.z;
    {
        f32* matrix = *(f32**)((u8*)saved1 + 0xC);
        f32* dst = &worldPoint.x;
        f32* src = &point.x;
        if (dst == src) {
            f32 x = src[0], y = src[1], z = src[2];
            dst[0] = (y * matrix[3] + x * matrix[0]) + z * matrix[6];
            dst[1] = (y * matrix[4] + x * matrix[1]) + z * matrix[7];
            dst[2] = (y * matrix[5] + x * matrix[2]) + z * matrix[8];
        } else {
            dst[0] = (src[1] * matrix[3] + src[0] * matrix[0]) + src[2] * matrix[6];
            dst[1] = (src[1] * matrix[4] + src[0] * matrix[1]) + src[2] * matrix[7];
            dst[2] = (src[1] * matrix[5] + src[0] * matrix[2]) + src[2] * matrix[8];
        }
        dst[0] += matrix[9]; dst[1] += matrix[10]; dst[2] += matrix[11];
    }
    {
        f32* matrix = *(f32**)((u8*)saved1 + 0xC);
        f32* dst = &worldNormal.x;
        f32* src = &normal.x;
        if (dst == src) {
            f32 x = src[0], y = src[1], z = src[2];
            dst[0] = (y * matrix[3] + x * matrix[0]) + z * matrix[6];
            dst[1] = (y * matrix[4] + x * matrix[1]) + z * matrix[7];
            dst[2] = (y * matrix[5] + x * matrix[2]) + z * matrix[8];
        } else {
            dst[0] = (src[1] * matrix[3] + src[0] * matrix[0]) + src[2] * matrix[6];
            dst[1] = (src[1] * matrix[4] + src[0] * matrix[1]) + src[2] * matrix[7];
            dst[2] = (src[1] * matrix[5] + src[0] * matrix[2]) + src[2] * matrix[8];
        }
    }
    fn_8019A788(saved0, saved1, &worldPoint, &worldNormal, 0, 0, depth, lbl_805622D0, lbl_805622D0);
    return 1;
}
extern "C" s32 fn_8019CCCC(void* arg0, Vec* arg1, void* arg2, f32 farg0) {
    if (fn_8019B08C(arg0, arg1, arg2, farg0) != 0) {
        return 1;
    }
    CornerV3 pos, neg;
    u32 axisBits[3];
    u32 transBits[3];
    f32 radius = *(f32*)((u8*)arg2 + 0x24);
    u32* m = *(u32**)((u8*)arg2 + 0xC);
    f32 dim = *(f32*)((u8*)arg2 + 0x28);
    f32 negDim = -dim;
    axisBits[0] = m[6];
    axisBits[1] = m[7];
    axisBits[2] = m[8];
    transBits[0] = m[9];
    transBits[1] = m[10];
    transBits[2] = m[11];
    f32* axis = (f32*)axisBits;
    f32* trans = (f32*)transBits;
    pos.x = trans[0] + axis[0] * dim;
    neg.x = trans[0] + axis[0] * negDim;
    pos.y = trans[1] + axis[1] * dim;
    pos.z = trans[2] + axis[2] * dim;
    neg.y = trans[1] + axis[1] * negDim;
    neg.z = trans[2] + axis[2] * negDim;
    s32 a = fn_8019AA34(arg0, arg1, arg2, &pos, 0, 0, farg0, radius) != 0;
    s32 b = fn_8019AA34(arg0, arg1, arg2, &neg, 0, 0, farg0, radius);
    return (a | b) != 0;
}
#pragma pop

#pragma scheduling on
extern void fn_8019CCCC(void*, f32, s32);
extern void fn_8019CCCC(void*, void*, s32, f32);
void fn_8019CE3C(void *shapeNode, s32 object) {
    /* Collision test: forward the shape node's transform block (+0x34) and
       radius (+0x24) to fn_8019CCCC along with the object. */
    fn_8019CCCC(shapeNode, (u8*)shapeNode + 0x34, object, *(f32*)((u8*)shapeNode + 0x24));
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
/* Floor ('FLSR') influence pass: point the object and the floor shape at each
   other.  For each side the vector toward the other is normalised (1/distance)
   and projected on that side's influence axis; how well the two line up
   (|dot|, 0..1) picks a radius between that side's min (+0x54) and max
   (+0x58).  Sides closer than 0.1 (squared) simply get the larger of the two.
   Both radii are stored at +0x24, which fn_8019B068 then runs the collision
   between the two positions with. */
/* Floor (FLSR) influence pass: for each of the two colliding shapes, pick a collision radius by projecting the normalized vector toward the other shape onto that shape's influence axis and lerping between its min/max radius (or taking the max when very close); store both radii at +0x24, then run the sphere/sphere collision. */ extern "C" void applyFloorInfluence(void *object, void *shape) {
    CollisionObject *obj = (CollisionObject *)object;
    CollisionObject *floorShape = (CollisionObject *)shape;
    {
    Vec toFloor;
    toFloor.x = floorShape->position.x - obj->position.x;
    Vec *floorPos = &floorShape->position;
    toFloor.y = floorPos->y - obj->position.y;
    toFloor.z = floorPos->z - obj->position.z;
    f32 squareDistance = PSVECSquareDistance(floorPos, &obj->position);
    f32 radius;
    if (squareDistance > lbl_8056232C /* 0.1f */) {
        f32 distance = (f32)fn_8002F234(squareDistance);
        f32 invDistance = lbl_805622E0 /* 1.0f */ / distance;
        toFloor.x *= invDistance;
        toFloor.y *= invDistance;
        toFloor.z *= invDistance;
        Vec *axis = (Vec *)((u8 *)obj->axisSource + 0xC);
        f32 alignment = PSVECDotProduct(&toFloor, axis);
        register f32 maxRadius;
        register f32 minRadius;
        register f32 strength;
        maxRadius = obj->maxRadius;
        minRadius = obj->minRadius;
        strength = (f32)__fabs((f64)alignment);
        f32 spread = maxRadius - minRadius;
        radius = minRadius + strength * spread;
    } else {
        f32 maxRadius = obj->maxRadius;
        f32 minRadius = obj->minRadius;
        if (minRadius > maxRadius) radius = minRadius;
        else radius = maxRadius;
    }
    obj->radius = radius;
    }
    {
    Vec toObject;
    toObject.x = obj->position.x - floorShape->position.x;
    toObject.y = obj->position.y - floorShape->position.y;
    toObject.z = obj->position.z - floorShape->position.z;
    f32 squareDistance = PSVECSquareDistance(&obj->position, &floorShape->position);
    f32 radius;
    if (squareDistance > lbl_8056232C /* 0.1f */) {
        f32 distance = (f32)fn_8002F234(squareDistance);
        f32 invDistance = lbl_805622E0 /* 1.0f */ / distance;
        toObject.x *= invDistance;
        toObject.y *= invDistance;
        toObject.z *= invDistance;
        Vec *axis = (Vec *)((u8 *)floorShape->axisSource + 0xC);
        f32 alignment = PSVECDotProduct(&toObject, axis);
        register f32 maxRadius;
        register f32 minRadius;
        register f32 strength;
        maxRadius = floorShape->maxRadius;
        minRadius = floorShape->minRadius;
        strength = (f32)__fabs((f64)alignment);
        f32 spread = maxRadius - minRadius;
        radius = minRadius + strength * spread;
    } else {
        f32 maxRadius = floorShape->maxRadius;
        f32 minRadius = floorShape->minRadius;
        if (minRadius > maxRadius) radius = minRadius;
        else radius = maxRadius;
    }
    floorShape->radius = radius;
    }
    fn_8019B068(object, shape, 0, 0);
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
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" s32 fn_8019D484(const Vec *p0, const Vec *v0, const Vec *p1, const Vec *v1, f32 *out0, f32 *out1)
{
  extern f32 lbl_80562348;
  volatile struct 
  {
    Vec normal;
    Vec delta;
    f32 h[9];
  } s;
  f32 den;
  f32 cx;
  f32 i1;
  f32 temp3;
  f32 i2;
  f32 dx;
  f32 dy;
  f32 dz;
  f32 nx;
  f32 nz;
  f32 v1x;
  f32 ny;
  f32 v1y;
  f32 v1z;
  f32 v0x;
  f32 v0y;
  f32 v0z;
  s.delta.x = p1->x - p0->x;
  s.delta.y = p1->y - p0->y;
  s.delta.z = p1->z - p0->z;
  PSVECCrossProduct(v0, v1, (Vec *) (&s.normal));
  den = PSVECDotProduct((Vec *) (&s.normal), (Vec *) (&s.normal));
  if (den > lbl_80562348)
  {
    f32 temp;
    temp3 = v1->y;
    dy = s.delta.y;
    dx = s.delta.x;
    temp = temp3;
    dz = s.delta.z;
    nx = s.normal.x;
    ny = s.normal.y;
    nz = s.normal.z;
    v1x = v1->x;
    v1y = temp;
    v1z = v1->z;
    s.h[0] = dx;
    s.h[1] = nx;
    s.h[2] = dy;
    s.h[3] = v1x;
    s.h[4] = ny;
    s.h[5] = dz;
    s.h[6] = v1y;
    s.h[7] = v1z;
    s.h[8] = nz;
    {
      f32 q0 = dy * dz;
      f32 q3 = v1y * nz;
      f32 q1 = (dy * dz) * v1z;
      f32 q2 = ny;
      f32 q4 = v1z;
      f32 q5 = (v1y * ny) * nz;
      cx = q2 - q0;
      i1 = q1 - q3;
      i2 = q5 - q4;
    }
    *out0 = ((nx * i1) + ((dx * i2) + (v1x * cx))) / den;
    v0x = v0->x;
    v0y = v0->y;
    v0z = v0->z;
    s.h[3] = v0x;
    s.h[6] = v0y;
    s.h[7] = v0z;
    *out1 = ((nx * ((dy * v0z) - (v0y * dz))) + ((dx * ((v0y * nz) - (ny * v0z))) + (v0x * cx))) / den;
    return 1;
  }
  return 0;
}

s32 fn_8019D618(void* arg0, void* arg1, s32 clamp, void* arg3) {
    f32* aMat = *(f32**)((u8*)arg0 + 0xC);
    f32* bMat = *(f32**)((u8*)arg1 + 0xC);
    Vec aPos, bPos, p, q, aAxis, bAxis, diff, cross, mid, da, db, normal, center, delta;
    f32 den, t0, t1;
    f32 h0 = *(f32*)((u8*)arg0 + 0x28);
    f32 h1 = *(f32*)((u8*)arg1 + 0x28);
    aAxis.x = aMat[6]; aAxis.y = aMat[7]; aAxis.z = aMat[8];
    bAxis.x = bMat[6]; bAxis.y = bMat[7]; bAxis.z = bMat[8];
    aPos.x = aMat[9]; aPos.y = aMat[10]; aPos.z = aMat[11];
    bPos.x = bMat[9]; bPos.y = bMat[10]; bPos.z = bMat[11];
    diff.x = bPos.x - aPos.x; diff.y = bPos.y - aPos.y; diff.z = bPos.z - aPos.z;
    PSVECCrossProduct(&aAxis, &bAxis, &cross);
    den = PSVECDotProduct(&cross, &cross);
    if (den < lbl_8056232C) {
        mid.x = (aPos.x + bPos.x) * lbl_805622E8;
        mid.y = (aPos.y + bPos.y) * lbl_805622E8;
        mid.z = (aPos.z + bPos.z) * lbl_805622E8;
        da.x = mid.x - aPos.x; da.y = mid.y - aPos.y; da.z = mid.z - aPos.z;
        t0 = PSVECDotProduct(&aAxis, &da);
        db.x = mid.x - bPos.x; db.y = mid.y - bPos.y; db.z = mid.z - bPos.z;
        t1 = PSVECDotProduct(&bAxis, &db);
    } else {
        f32 tmp;
        if ((f32)__fabs((f64)den) <= lbl_80558DC4) return 0;
        tmp = cross.y * diff.z - diff.y * cross.z;
        t0 = (cross.x * (diff.y * bAxis.z - bAxis.y * diff.z) + diff.x * (bAxis.y * cross.z - cross.y * bAxis.z) + bAxis.x * tmp) / den;
        t1 = (cross.x * (diff.y * aAxis.z - aAxis.y * diff.z) + diff.x * (aAxis.y * cross.z - cross.y * aAxis.z) + aAxis.x * tmp) / den;
    }
    if (!clamp) {
        if (t0 < -h0 || t0 > h0 || t1 < -h1 || t1 > h1) return 0;
    } else {
        if (t0 < -h0) t0 = -h0;
        if (t0 > h0) t0 = h0;
        if (t1 < -h1) t1 = -h1;
        if (t1 > h1) t1 = h1;
    }
    p.x = aPos.x + aAxis.x * t0; p.y = aPos.y + aAxis.y * t0; p.z = aPos.z + aAxis.z * t0;
    q.x = bPos.x + bAxis.x * t1; q.y = bPos.y + bAxis.y * t1; q.z = bPos.z + bAxis.z * t1;
    delta.x = q.x - p.x; delta.y = q.y - p.y; delta.z = q.z - p.z;
    {
        f32 dist = PSVECMag(&delta);
        f32 depth;
        f32 scale;
        if ((f32)__fabs((f64)dist) <= lbl_80558DC4) return 0;
        depth = *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg1 + 0x24) - dist;
        if (depth < lbl_805622D0) return 0;
        scale = lbl_805622DC / dist;
        normal.x = delta.x * scale; normal.y = delta.y * scale; normal.z = delta.z * scale;
        center.x = (p.x + q.x) * lbl_805622E8; center.y = (p.y + q.y) * lbl_805622E8; center.z = (p.z + q.z) * lbl_805622E8;
        fn_8019A788(arg3 ? arg3 : arg0, arg1, &center, &normal, 0, 0, depth, lbl_805622D0, lbl_805622D0);
    }
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
    s32 check = (u16)fn_8019D618(arg0, arg1, 0, 0);
    u32 checkFlag = ((u32)-check | (u32)check) >> 31;
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
#pragma scheduling invalid_target
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
    struct Scratch {
        u32 center[3];
        u32 axis[3];
        Vec minus;
        Vec plus;
        Vec delta;
    };
    register void *object0 = arg0;
    register void *object1 = arg1;
    Scratch scratch;
    void *shape1 = *(void **)((u8 *)object1 + 0xC);
    void *shape0 = *(void **)((u8 *)object0 + 0xC);
    scratch.delta.x = *(f32 *)((u8 *)shape0 + 0x24) - *(f32 *)((u8 *)shape1 + 0x24);
    scratch.delta.y = *(f32 *)((u8 *)shape0 + 0x28) - *(f32 *)((u8 *)shape1 + 0x28);
    scratch.delta.z = *(f32 *)((u8 *)shape0 + 0x2C) - *(f32 *)((u8 *)shape1 + 0x2C);
    f32 radius1 = ((Interface *)object1)->getRadius();
    f32 radius0 = ((Interface *)object0)->getRadius();
    f32 radius = radius0 + radius1;
    f32 radiusSquared = radius * radius;
    if (PSVECDotProduct(&scratch.delta, &scratch.delta) < radiusSquared) {
        u32 found = 0;
        u32 raw = (u8)(u32)fn_8019DAB0(object0, object1);
        found = ((u32)(-raw) | raw) >> 31;
        if (found != 0) return 1;
        void *shape = *(void **)((u8 *)object0 + 0xC);
        f32 radius2 = *(f32 *)((u8 *)object0 + 0x28);
        f32 width = *(f32 *)((u8 *)object0 + 0x24);
        u32 *words = (u32 *)shape;
        scratch.axis[0] = words[6];
        scratch.axis[1] = words[7];
        scratch.axis[2] = words[8];
        scratch.center[0] = words[9];
        scratch.center[1] = words[10];
        scratch.center[2] = words[11];
        f32 *axis = (f32 *)scratch.axis;
        f32 *center = (f32 *)scratch.center;
        f32 negRadius = -radius2;
        scratch.plus.x = center[0] + axis[0] * radius2;
        scratch.plus.y = center[1] + axis[1] * radius2;
        scratch.plus.z = center[2] + axis[2] * radius2;
        scratch.minus.x = center[0] + axis[0] * negRadius;
        scratch.minus.y = center[1] + axis[1] * negRadius;
        scratch.minus.z = center[2] + axis[2] * negRadius;
        s32 first = fn_8019CCCC(object0, &scratch.plus, object1, width);
        s32 c2 = (s32)found | first;
        found = ((u32)(-c2) | (u32)c2) >> 31;
        if (found != 0) return 1;
        s32 second = fn_8019CCCC(object0, &scratch.minus, object1, width);
        s32 c3 = (s32)found | second;
        return ((u32)(-c3) | (u32)c3) >> 31;
    }
    return 0;
}

#pragma processor reset

extern "C" f32 fn_8019DDEC(void *obj) {
    /* Return the sum of the two float fields at +0x24 and +0x28 of obj. */
    return *(f32*)((u8*)obj + 0x24) + *(f32*)((u8*)obj + 0x28);
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
    val = lbl_8056234C * PSVECDotProduct((const Vec *)delta, (const Vec *)arg1);
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
            norm = lbl_805622E0 / (lbl_80562358 > mag ? lbl_80562358 : mag);
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
#pragma dont_inline off
#pragma scheduling invalid_target
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
        Fn8019DF88MultVec(m, (f32 *)&cross, (f32 *)&rotated);
        PSVECCrossProduct(&rotated, &delta, &result);
        f32 denominator = lbl_805622E0 / farg0 + PSVECDotProduct(&normal, &result);
        if ((f32)__fabs((f64)denominator) > lbl_8056235C) {
            f32 impulse = (-(lbl_805622E0 + farg1) * PSVECDotProduct(&velocity, &normal)) / denominator;
            f32 ret = lbl_80562360 < impulse ? lbl_80562360 : impulse;
            return ret;
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

#pragma scheduling invalid_target
extern "C" s32 fn_8019E2D0(s32 arg0, s32 arg1, s32 arg2, void *arg3, f32 f0, f32 f1, f32 f2)
{
  Vec origin;
  Vec direction;
  f32 minimum;
  f32 new_var;
  f32 maximum;
  f32 *matrix = (f32 *) arg3;
  f32 m1 = matrix[1];
  f32 m4 = matrix[4];
  f32 m3 = matrix[3];
  f32 m6 = matrix[6];
  f32 m7 = matrix[7];
  f32 m2 = matrix[2];
  f32 m5 = matrix[5];
  f32 m8 = matrix[8];
  f32 *p = (f32 *) arg0;
  f32 *v = (f32 *) arg1;
  f32 y = p[1] - matrix[10];
  f32 x = p[0] - matrix[9];
  f32 z = p[2] - matrix[11];
  origin.x = (z * m2) + ((x * matrix[0]) + (y * m1));
  origin.y = (z * m5) + ((x * m3) + (y * m4));
  origin.z = (z * m8) + ((x * m6) + (y * m7));
  if (((f32 *) (&direction)) == v)
  {
    f32 vx = v[0];
    f32 vy = v[1];
    f32 vz = v[2];
    new_var = m1;
    direction.x = (vz * m2) + ((vy * new_var) + (vx * matrix[0]));
    direction.y = (vz * m5) + ((vx * m3) + (vy * m4));
    direction.z = (vz * m8) + ((vy * m7) + (vx * m6));
  }
  else
  {
    direction.x = (v[2] * m2) + ((v[1] * new_var) + (v[0] * matrix[0]));
    direction.y = (v[2] * m5) + ((v[1] * m4) + (v[0] * m3));
    direction.z = (v[2] * m8) + ((v[1] * m7) + (v[0] * m6));
  }
  minimum = lbl_80562364;
  maximum = lbl_80562368;
  if (((fn_8019E1F4(&minimum, &maximum, origin.x, direction.x, f0) && fn_8019E1F4(&minimum, &maximum, origin.y, direction.y, f1)) && fn_8019E1F4(&minimum, &maximum, origin.z, direction.z, f2)) && (minimum < (*((f32 *) arg2))))
  {
    *((f32 *) arg2) = minimum;
    return 1;
  }
  return 0;
}
#pragma scheduling reset

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
extern "C" s32 fn_8019E834(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

#pragma push
#pragma scheduling on
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
    u16 res;

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
extern "C" void fn_8019EB14(s32 baseRaw, s32 index) {
    u8 *base = (u8 *)baseRaw;
    u32 offset = index * 8;
    u8 *node = base + offset;
    u8 temp;

    /* Byte-swap the four 16-bit fields of this 8-byte node, then recurse into
       four children starting at the child index stored in the node's third
       field (offset 4) when it is non-zero. */
    temp = base[offset];
    base[offset] = node[1];
    node[1] = temp;

    temp = node[2]; node[2] = node[3]; node[3] = temp;
    temp = node[4]; node[4] = node[5]; node[5] = temp;
    temp = node[6]; node[6] = node[7]; node[7] = temp;

    if (*(u16 *)(node + 4) != 0) {
        s32 child;
        for (child = 0; child < 4; child++) {
            fn_8019EB14(baseRaw, *(u16 *)(node + 4) + child);
        }
    }
}

extern "C" void fn_8019EBC0(void* owner) {
    /* Invoke the slot-0x48 (v16) hook on the sub-object held at +4 of the owner, if present. */
    VTab19* part = *(VTab19**)((u8*)owner + 4);
    if (part == NULL) {
        return;
    }
    part->v16();
}

#pragma scheduling invalid_target
extern "C" void fn_8019EBE0(void *self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 obj = *(s32 *)((u8 *)self + 4);
    s32 v1 = (s32)self;
    s32 v2 = a;
    s32 v3 = b;
    s32 v4 = c;
    s32 v5 = d;
    s32 v6 = e;
    s32 v7 = f;
    if (obj != 0) {
        fn_8017B5D4(obj, v1, v2, v3, v4, v5, v6);
    } else {
        obj = *(s32 *)((u8 *)self + 8);
        if (obj != 0) fn_801A4A10(obj, v4, v7, v3);
    }
}
#pragma scheduling reset
extern "C" void fn_8019EC84(void* owner) {
    /* Invoke the slot-0x4C hook on the sub-object held at +4 of the owner, if present. */
    VTab19* part = *(VTab19**)((u8*)owner + 4);
    if (part == NULL) {
        return;
    }
    part->slot0x4C();
}

extern "C" void fn_8019ECA4(VTab13* this_, s32 value) {
    /* Store value at +8 and forward value+4 to this object's slot-0x34 virtual method. */
    *(s32*)((u8*)this_ + 8) = value;
    this_->slot0x34(value + 4);
}

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_8019ECBC(void* obj, s32 value) {
    /* Store `value` into the 32-bit field at offset +0xC of `obj`. */
    *(s32*)((u8*)obj + 0xC) = value;
}

extern char lbl_80333B98[];
#pragma use_lmw_stmw off
extern "C" void fn_8019ECC4(void* shape, s32 owner, s32 swapBytes) {
    /* Shared base constructor: install the vtable at +0, optionally byte-swap
     * the five packed 32-bit words at +0x10..+0x23 (endian conversion of data
     * loaded from file), then set +8 = owner, +4 = 0 and +0xC = owner + 4. */
    // Bytes saved aside while reversing each word: b18 is the byte at 0x18,
    // etc. The first byte of each word is declared before its second so each
    // gets its own register and all ten reads happen before any write.
    u8 b18, b10, b14, b20, b1c;
    u8 b19, b11, b15, b21, b1d;
    *(void**)shape = &lbl_80333B98;
    if (swapBytes != 0) {
        b18 = *(u8*)((u8*)shape + 0x18);
        b19 = *(u8*)((u8*)shape + 0x19);
        b10 = *(u8*)((u8*)shape + 0x10);
        b11 = *(u8*)((u8*)shape + 0x11);
        b14 = *(u8*)((u8*)shape + 0x14);
        b15 = *(u8*)((u8*)shape + 0x15);
        b20 = *(u8*)((u8*)shape + 0x20);
        b21 = *(u8*)((u8*)shape + 0x21);
        b1c = *(u8*)((u8*)shape + 0x1c);
        b1d = *(u8*)((u8*)shape + 0x1d);
        *(u8*)((u8*)shape + 0x18) = *(u8*)((u8*)shape + 0x1b);
        *(u8*)((u8*)shape + 0x1b) = b18;
        *(u8*)((u8*)shape + 0x19) = *(u8*)((u8*)shape + 0x1a);
        *(u8*)((u8*)shape + 0x1a) = b19;
        *(u8*)((u8*)shape + 0x10) = *(u8*)((u8*)shape + 0x13);
        *(u8*)((u8*)shape + 0x13) = b10;
        *(u8*)((u8*)shape + 0x11) = *(u8*)((u8*)shape + 0x12);
        *(u8*)((u8*)shape + 0x12) = b11;
        *(u8*)((u8*)shape + 0x14) = *(u8*)((u8*)shape + 0x17);
        *(u8*)((u8*)shape + 0x17) = b14;
        *(u8*)((u8*)shape + 0x15) = *(u8*)((u8*)shape + 0x16);
        *(u8*)((u8*)shape + 0x16) = b15;
        *(u8*)((u8*)shape + 0x20) = *(u8*)((u8*)shape + 0x23);
        *(u8*)((u8*)shape + 0x23) = b20;
        *(u8*)((u8*)shape + 0x21) = *(u8*)((u8*)shape + 0x22);
        *(u8*)((u8*)shape + 0x22) = b21;
        *(u8*)((u8*)shape + 0x1c) = *(u8*)((u8*)shape + 0x1f);
        *(u8*)((u8*)shape + 0x1f) = b1c;
        *(u8*)((u8*)shape + 0x1d) = *(u8*)((u8*)shape + 0x1e);
        *(u8*)((u8*)shape + 0x1e) = b1d;
    }
    *(s32*)((u8*)shape + 8) = owner;
    *(s32*)((u8*)shape + 4) = 0;
    *(s32*)((u8*)shape + 0xC) = owner + 4;
}
 #pragma use_lmw_stmw on
 
 
 
 #pragma scheduling invalid_target
extern "C" void* fn_8019EDB8(void* arg0, void* arg1, s32 arg2) {
    s32 copyFlag = arg2;
    void *self = arg0;
    u8 second, first, opposite, other;
    fn_8019ECC4(self, (s32)arg1, arg2);
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
/* Add the translation vector held in source (+0x30) into the destination Vec,
 * component by component. */
extern "C" void fn_8019EECC(void* source, Vec* vec) {
    vec->x += *(f32*)((u8*)source + 0x30);
    vec->y += *(f32*)((u8*)source + 0x34);
    vec->z += *(f32*)((u8*)source + 0x38);
}

/* Transform the object's input Vec (+0x28) by its orientation matrix and translation
 * (the float matrix at +0xC: m[0..8] are the 3x3 axes, m[9..11] the translation),
 * writing the result to the output Vec (+0x34).  The two branches compute the same
 * transform with different load/multiply scheduling for the in-place case. */
extern "C" void fn_8019EF00(void* object) {
    struct Object {
        char pad0[0xC];
        f32* matrix;
        char pad10[0x18];
        Vec input;
        volatile Vec output;
    };
    Object* self = (Object*)object;
    f32* m = self->matrix;
    if (&self->output == (volatile Vec*)&self->input) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = m[3]; m11 = m[4]; m12 = m[5]; m00 = m[0]; m01 = m[1]; m02 = m[2]; m20 = m[6]; m21 = m[7]; m22 = m[8];
        x = self->input.x; y = self->input.y; z = self->input.z;
        self->output.x = z * m20 + (x * m00 + y * m10);
        self->output.y = z * m21 + (x * m01 + y * m11);
        self->output.z = z * m22 + (x * m02 + y * m12);
    } else {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = m[3]; m00 = m[0]; m20 = m[6];
        x = self->input.x; y = self->input.y; z = self->input.z;
        self->output.x = z * m20 + (x * m00 + y * m10);
        m11 = m[4]; m01 = m[1]; m21 = m[7];
        self->output.y = z * m21 + (x * m01 + y * m11);
        m12 = m[5]; m02 = m[2]; m22 = m[8];
        self->output.z = z * m22 + (x * m02 + y * m12);
    }
    self->output.x += m[9];
    self->output.y += m[10];
    self->output.z += m[11];
}

#define gZeroFloat lbl_805622D0 /* 0.0f, shared constant in .sdata2 */
extern "C" void fn_8019F03C(void* sphereShape) {
    /* Reset a collision shape's cached runtime state: zero the two stored
       contact vectors at +0x34..+0x48 and clear the active flag at +0x4C. */
    f32 zero = gZeroFloat;
    *(u8*)((u8*)sphereShape + 0x4C) = 0;
    *(f32*)((u8*)sphereShape + 0x40) = zero;
    *(f32*)((u8*)sphereShape + 0x44) = zero;
    *(f32*)((u8*)sphereShape + 0x48) = zero;
    *(f32*)((u8*)sphereShape + 0x34) = zero;
    *(f32*)((u8*)sphereShape + 0x38) = zero;
    *(f32*)((u8*)sphereShape + 0x3C) = zero;
}
#undef gZeroFloat

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
        Abend_Panic(lbl_803335EC, type);
        break;
    }
}

/* Forward to the collision-response helper fn_8019AC44, supplying obj's embedded
 * position vector (obj+0x34), its result vector (obj+0x40) and the scale at obj+0x24. */
extern "C" void fn_8019F1A4(void* obj) {
    fn_8019AC44(obj, (u8*)obj + 0x34, (u8*)obj + 0x40, *(f32*)((u8*)obj + 0x24));
}

/* Forward to the collision-response helper fn_8019DDFC, supplying obj's embedded
 * position vector (obj+0x34) and radius/scale (obj+0x24); arg1-arg4 pass through. */
extern "C" void fn_8019F1B4(void *obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_8019DDFC(arg1, arg2, arg3, arg4, (u8 *)obj + 0x34, obj, *(f32 *)((u8 *)obj + 0x24));
}

#pragma scheduling on
extern "C" void fn_8019F1D4(void* arg0, void* arg1, void* arg2) {
    volatile f32* out1 = (volatile f32*)arg1;
    volatile f32* out2 = (volatile f32*)arg2;
    volatile f32 inputA[2];
    volatile f32 inputB[4];
    f32 y2;
    f32 y1;
    f32 y0;
    f32 x2;
    f32 x1;
    f32 x0;
    f32 right;
    f32 mid;
    f32 left;
    f32 scaleA;
    f32 width;
    width = *(f32*)((u8*)arg0 + 0x24);
    scaleA = width * lbl_805622DC;
    left = *(f32*)((u8*)arg0 + 0x34);
    mid = *(f32*)((u8*)arg0 + 0x38);
    right = *(f32*)((u8*)arg0 + 0x3C);
    x0 = left + scaleA;
    x1 = mid + scaleA;
    x2 = right + scaleA;
    y0 = left + width * lbl_805622E0;
    y1 = mid + width * lbl_805622E0;
    y2 = right + width * lbl_805622E0;
    inputA[0] = width;
    inputA[1] = width;
    out1[0] = x0;
    out1[1] = x1;
    out1[2] = x2;
    inputB[0] = width;
    inputB[1] = left;
    inputB[2] = mid;
    inputB[3] = right;
    out2[0] = y0;
    out2[1] = y1;
    out2[2] = y2;
}
extern "C" void fn_8019F248(void *shape) {
    extern f32 lbl_80562300;
    extern s32 lbl_8055E598;
    extern void fn_801E3FC8(void*, s32, f32);
    /* Clamp the shape's +0x24 scale to a minimum of 0.2, then pass its +0x34
       position and the clamped scale to fn_801E3FC8 via handle lbl_8055E598. */
    f32 scale = *(f32*)((u8*)shape + 0x24);
    scale = (scale > lbl_80562300) ? scale : lbl_80562300;
    fn_801E3FC8((u8*)shape + 0x34, lbl_8055E598, scale);
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
        applyFloorInfluence((void *)context, shape);
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
    /* Empty stub (no operation). */
}

extern "C" s32 fn_80128668(void);
/* If ptr is set and count is positive, free the object (fn_80128668 receives
 * ptr in r3); always return ptr unchanged. */
extern "C" s32 fn_8019F3D4(s32 ptr, s32 count) {
    if (ptr != 0 && count > 0) {
        fn_80128668();
    }
    return ptr;
}

extern "C" void fn_8019F414(void *arg0) {
#pragma opt_common_subs off
    extern f32 lbl_8056237C;
    extern void fn_8019EECC(void*, void*);
    extern void fn_8019EF00(void*);
    u32 sp[3];
    void *temp_r4;
    void *temp_r6;
    f32 x, y, z, ybase, xpartial, ypartial;

    temp_r6 = *(void **)((u8*)arg0 + 0x54);
    temp_r4 = *(void **)((u8*)arg0 + 4);
    sp[0] = *(u32*)((u8*)temp_r6 + 0x30);
    sp[1] = *(u32*)((u8*)temp_r6 + 0x34);
    sp[2] = *(u32*)((u8*)temp_r6 + 0x38);
    z = ((f32*)sp)[2] - *(f32*)((u8*)temp_r4 + 0x38);
    ybase = lbl_8056237C + *(f32*)((u8*)arg0 + 0x24);
    ybase += *(f32*)((u8*)temp_r6 + 0xC);
    xpartial = ((f32*)sp)[0] - *(f32*)((u8*)temp_r4 + 0x30);
    ypartial = ((f32*)sp)[1] - *(f32*)((u8*)temp_r4 + 0x34);
    x = xpartial + *(f32*)((u8*)arg0 + 0x58);
    y = ypartial + ybase;
    ((f32*)sp)[0] = x;
    ((f32*)sp)[1] = y;
    ((f32*)sp)[2] = z;
    *(f32*)((u8*)arg0 + 0x28) = x;
    *(f32*)((u8*)arg0 + 0x2C) = y;
    *(f32*)((u8*)arg0 + 0x30) = z;
    if (temp_r4 != 0) fn_8019EECC(temp_r4, (u8*)arg0 + 0x28);
    fn_8019EF00(arg0);
}

#pragma scheduling reset
#pragma opt_lifetimes off
extern "C" void fn_8019F4D4(void *arg0, void *arg1) {
    fn_8019EC84(arg0);
    f32 scale = -PSVECDotProduct(
        (const Vec *)((u8 *)*(void **)((u8 *)arg0 + 0xC) + 0xC),
        (const Vec *)arg1);
    void *vector = *(void **)((u8 *)arg0 + 0xC);
    volatile f32 scratch[10];
    scratch[0] = ((f32 *)arg1)[0] + ((f32 *)vector)[3] * scale;
    scratch[1] = ((f32 *)arg1)[1] + ((f32 *)vector)[4] * scale;
    scratch[2] = ((f32 *)arg1)[2] + ((f32 *)vector)[5] * scale;
}
/* Tail-call thunk: forwards unchanged to fn_8019F1A4, which dispatches to the fn_8019AC44 physics routine. */
extern "C" void fn_8019F560(void) {
    fn_8019F1A4();
}

#pragma scheduling invalid_target
extern "C" void *fn_8019F564(void *arg0,s32 arg1,const void *arg2,s32 arg3,f32 a,f32 b,f32 c,f32 d,f32 e,f32 f) {
 extern char lbl_80333A58[];
 f32 z, z2, e8; f32 m = (e>f) ? e : f; if(d>m)m=d;
 z=0.0f;
 *(s32*)((u8*)arg0+0xC)=arg1;*(s32*)((u8*)arg0+4)=arg3;*(s32*)((u8*)arg0+8)=0;
 *(s32*)((u8*)arg0+0x18)=0x53504852;*(f32*)((u8*)arg0+0x10)=a;*(f32*)((u8*)arg0+0x14)=b;
 *(s32*)((u8*)arg0+0x20)=100;*(s32*)((u8*)arg0+0x1C)=0;*(void**)arg0=&lbl_80333B48;
 *(f32*)((u8*)arg0+0x24)=0.5f*m;
 *(f32*)((u8*)arg0+0x34)=z;*(f32*)((u8*)arg0+0x38)=z;*(f32*)((u8*)arg0+0x3C)=z;*(f32*)((u8*)arg0+0x40)=z;
 *(f32*)((u8*)arg0+0x44)=z;*(f32*)((u8*)arg0+0x48)=z;*(u8*)((u8*)arg0+0x4C)=0;*(f32*)((u8*)arg0+0x50)=z;
 *(f32*)((u8*)arg0+0x28)=*(f32*)arg2;*(f32*)((u8*)arg0+0x2C)=*(f32*)((u8*)arg2+4);*(f32*)((u8*)arg0+0x30)=*(f32*)((u8*)arg2+8);
 if(arg3)fn_8019EECC((void*)arg3,(Vec*)((u8*)arg0+0x28));
 e8=0.5f;
 z2=0.0f;
 *(void**)arg0=&lbl_80333A58;*(f32*)((u8*)arg0+0x54)=c;
 *(f32*)((u8*)arg0+0x58)=e8*d;*(f32*)((u8*)arg0+0x5C)=e8*e;*(f32*)((u8*)arg0+0x60)=e8*f;
 *(f32*)((u8*)arg0+0x64)=z2;*(f32*)((u8*)arg0+0x68)=z2;*(f32*)((u8*)arg0+0x6C)=z2;*(f32*)((u8*)arg0+0x70)=z2;
 *(f32*)((u8*)arg0+0x74)=z2;*(f32*)((u8*)arg0+0x78)=z2;*(f32*)((u8*)arg0+0x7C)=z2;*(f32*)((u8*)arg0+0x80)=z2;
 *(f32*)((u8*)arg0+0x84)=z2;*(f32*)((u8*)arg0+0x88)=z2;*(f32*)((u8*)arg0+0x8C)=z2;*(f32*)((u8*)arg0+0x90)=z2;
 *(f32*)((u8*)arg0+0x94)=z2;*(f32*)((u8*)arg0+0x98)=z2;*(f32*)((u8*)arg0+0x9C)=z2;*(f32*)((u8*)arg0+0xA0)=z2;
 *(f32*)((u8*)arg0+0xA4)=z2;*(f32*)((u8*)arg0+0xA8)=z2;*(f32*)((u8*)arg0+0xAC)=z2;*(f32*)((u8*)arg0+0xB0)=z2;
 *(f32*)((u8*)arg0+0xB4)=z2;*(f32*)((u8*)arg0+0xB8)=z2;*(f32*)((u8*)arg0+0xBC)=z2;*(f32*)((u8*)arg0+0xC0)=z2;return arg0;
}
extern "C" void fn_8019F6F0(void *arg0) {
    /* Reset object fields by reinitializing its base state and zeroing the float block at +0x64..+0xC0. */
    f32 zeroValue;

    fn_8019F03C(arg0);
    zeroValue = lbl_805622D0;
    *(f32 *)((u8 *)arg0 + 0x64) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x68) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x6C) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x70) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x74) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x78) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x7C) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x80) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x84) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x88) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x8C) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x90) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x94) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x98) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x9C) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xA0) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xA4) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xA8) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xAC) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xB0) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xB4) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xB8) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xBC) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0xC0) = zeroValue;
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

extern "C" void fn_8019FF88(void* owner) {
    /* Tail-call thunk that forwards the owner to fn_8019EBC0, which invokes the
       v16 hook on the sub-object held at +4. */
    ((void (*)(void))fn_8019EBC0)();
}

extern "C" void fn_8019FF8C(void* object) {
    /* Reset runtime state (fn_8019F03C clears +0x34..+0x4C) then copy the base
       offset at +0x54..+0x5C into the current offset at +0x28..+0x30 and clear
       the active flag at +0x78. */
    fn_8019F03C();
    *(f32*)((u8*)object + 0x28) = *(f32*)((u8*)object + 0x54);
    *(f32*)((u8*)object + 0x2C) = *(f32*)((u8*)object + 0x58);
    *(f32*)((u8*)object + 0x30) = *(f32*)((u8*)object + 0x5C);
    *(u8*)((u8*)object + 0x78) = 0;
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
/* Destructor: set vtable, destroy owned items/child, and optionally free self. */
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

extern "C" s32 fn_801A010C(s32 item, s32 count) {
    /* Return the item pointer unchanged; if it is non-null and count is
     * positive, free it through fn_80128668 as a side effect. */
    if (item != 0 && count > 0) {
        fn_80128668();
    }
    return item;
}

extern "C" void fn_801A014C(void* parent) {
    /* Invoke Call() on the primary child stored at +0x17C of the parent. */
    Fn801A014CDispatch* child = (Fn801A014CDispatch*)*(void**)((u8*)parent + 0x17C);
    child->Call();
}

extern s32 lbl_8055E3C4;  // current frame counter; fn_80176A34 sets it (and its seconds form lbl_8055E3C8) once per frame
extern "C" void fn_801A0160(void* group) {
    /* Tick the group's children once per frame.  The group keeps at +0x180 the
     * frame counter (lbl_8055E3C4) it last ran on; on a new frame it stores the
     * counter and calls the children's per-frame virtual (vtable slot 0xC) for
     * every child pointer at +0x24 (count at +0x174). */
    s32 frame = lbl_8055E3C4;
    if (frame != *(s32*)((u8*)group + 0x180)) {
        *(s32*)((u8*)group + 0x180) = frame;
        class Child {
        public:
            virtual void v08();
            virtual void Tick();
            virtual void v10();
            virtual void v14();
        };
        register u8* cursor = (u8*)group;
        register s32 index = 0;
        goto check;
    loop:
        Child* child = *(Child**)(cursor + 0x24);
        child->Tick();
        cursor += 4;
        index++;
    check:
        if (index < *(s32*)((u8*)group + 0x174))
            goto loop;
    }
}

typedef struct Arg0_801A01E0 {
    char pad[0x178];
    float value;
} Arg0_801A01E0;
extern "C" void fn_801A01E0(void* arg0, void* arg1, void* arg2) {
    volatile f32 inputA[2];
    volatile f32 inputB[4];
    volatile f32* first = (volatile f32*)arg1;
    volatile f32* second = (volatile f32*)arg2;
    f32 value = *(f32*)((u8*)arg0 + 0x178);
    void* base = *(void**)((u8*)arg0 + 0xC);
    f32 x = *(f32*)((u8*)base + 0x24);
    f32 scaleA = value * lbl_805622DC;
    f32 y = *(f32*)((u8*)base + 0x28);
    f32 scaleB = value * lbl_805622E0;
    f32 z = *(f32*)((u8*)base + 0x2C);
    f32 x0 = x + scaleA;
    f32 y0 = y + scaleA;
    f32 z0 = z + scaleA;
    f32 x1 = x + scaleB;
    f32 y1 = y + scaleB;
    f32 z1 = z + scaleB;
    inputA[0] = value;
    first[0] = x0;
    inputA[1] = value;
    first[1] = y0;
    first[2] = z0;
    inputB[0] = value;
    inputB[1] = x;
    inputB[2] = y;
    inputB[3] = z;
    second[0] = x1;
    second[1] = y1;
    second[2] = z1;
}

#pragma optimization_level reset
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

/* Store an effect in the manager, dispatch its setup callback, and expand the bounding radius. */
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

// Sets a group's primary child and copies the child's center position into the group's cached position.
extern "C" void fn_801A0444(void* group, void* child) {
    *(void**)((u8*)group + 0x17C) = child;
    *(f32*)((u8*)group + 0x164) = *(f32*)((u8*)child + 0x24);
    *(f32*)((u8*)group + 0x168) = *(f32*)((u8*)child + 0x28);
    *(f32*)((u8*)group + 0x16C) = *(f32*)((u8*)child + 0x2C);
}

extern f32 lbl_805623B8;
extern f32 lbl_805623BC;
/* Rotate src by the transpose-indexed 3x3 matrix m (box space back to world space);
 * the dst == &src check stays in the code, so both branches are emitted. */
static inline void fn801A0464RotateVec(Vec *dst, const Vec &src, const f32 *m) {
    f32 x = src.x;
    f32 y = src.y;
    f32 z = src.z;
    if (dst == &src) {
        f32 rx = (x * m[0] + y * m[3]) + z * m[6];
        f32 ry = (x * m[1] + y * m[4]) + z * m[7];
        f32 rz = (x * m[2] + y * m[5]) + z * m[8];
        dst->x = rx;
        dst->y = ry;
        dst->z = rz;
    } else {
        dst->x = (y * m[3] + x * m[0]) + z * m[6];
        dst->y = (y * m[4] + x * m[1]) + z * m[7];
        dst->z = (y * m[5] + x * m[2]) + z * m[8];
    }
}

/* registers are saved with _savegpr */
#pragma use_lmw_stmw off
extern "C" void fn_801A0464(void *arg0, void *arg1) {
    u8 buffer[0x300];
    Vec boxDelta;
    Vec local;
    Vec corner;
    Vec q;
    Vec out;
    Vec diff;
    Vec center;
    Vec polyPoint;
    Vec nrm;
    Vec hit;
    Vec size;
    Vec tmp;
    Vec v;
    Vec meshDelta;
    Vec boxCenter;
    Vec delta;
    f32 depth;
    s32 count;
    u8 *self = (u8 *)arg0;
    u8 *other = (u8 *)arg1;
    u32 tag = *(u32 *)(other + 0x18);

    if (tag == 0x47525550) {
        u8 *otherOwner = *(u8 **)(other + 4);
        if (otherOwner != 0) {
            u8 *selfOwner = *(u8 **)(self + 4);
            if (selfOwner != 0) {
                f32 otherDist = *(f32 *)(otherOwner + 0xD4);
                f32 selfDist = *(f32 *)(selfOwner + 0xD4);
                if (selfDist < otherDist) {
                    ((Fn801A401CDispatch *)other)->Call(self);
                    return;
                }
            }
        }
        f32 *a = *(f32 **)(self + 0xC);
        f32 *b = *(f32 **)(other + 0xC);
        delta.x = a[9] - b[9];
        delta.y = a[10] - b[10];
        delta.z = a[11] - b[11];
        f32 dist2 = PSVECDotProduct(&delta, &delta);
        f32 r = *(f32 *)(self + 0x178) + *(f32 *)(other + 0x178);
        if (dist2 < r * r) {
            ((void (*)(void *))fn_801A0160)(other);
            s32 i = 0;
            u8 *ent = other;
            while (i < *(s32 *)(other + 0x174)) {
                fn_8019BD54(*(void **)(ent + 0x24), *(void **)(self + 0x17C), 0, 0);
                ent += 4;
                i++;
            }
        }
    } else if (tag == 0x424F5820) {
        fn_801A1F44(&boxCenter, other);
        f32 *a = *(f32 **)(self + 0xC);
        boxDelta.x = a[9] - boxCenter.x;
        boxDelta.y = a[10] - boxCenter.y;
        boxDelta.z = a[11] - boxCenter.z;
        f32 dist = (f32)__fabs((f64)PSVECDotProduct(&boxDelta, *(Vec **)(other + 0xC)));
        if (dist < *(f32 *)(other + 0x24) + *(f32 *)(self + 0x178)) {
            dist = (f32)__fabs((f64)PSVECDotProduct(&boxDelta, (Vec *)(*(u8 **)(other + 0xC) + 0x18)));
            if (dist < *(f32 *)(other + 0x2C) + *(f32 *)(self + 0x178)) {
            u8 *owner = *(u8 **)(self + 4);
            f32 *m = *(f32 **)(other + 0xC);
            f32 x, y, z, nx, ny, nz;
            local.x = *(f32 *)(owner + 0x60) - m[9];
            local.y = *(f32 *)(owner + 0x64) - m[10];
            local.z = *(f32 *)(owner + 0x68) - m[11];
            x = local.x;
            y = local.y;
            z = local.z;
            nx = (y * m[1] + x * m[0]) + z * m[2];
            ny = (y * m[4] + x * m[3]) + z * m[5];
            nz = (y * m[7] + x * m[6]) + z * m[8];
            local.x = nx;
            local.y = ny;
            local.z = nz;
            ((void (*)(void *))fn_801A0160)(self);
            u8 *ent = self;
            s32 i = 0;
            while (i < *(s32 *)(self + 0x174)) {
                fn_8019BD54(*(void **)(ent + 0x24), other, 0, (s32)&local);
                ent += 4;
                i++;
            }
            if (*(s32 *)(other + 0x20) < 8) {
                u8 *obj = *(u8 **)(self + 4);
                s32 ok;
                if (obj == 0) goto box_set0;
                switch (*(s32 *)(obj + 0x10)) {
                case 0x4E434152:
                case 0x43415220:
                case 0x41434152:
                case 0x50434152:
                    ok = 1;
                    goto box_done;
                }
            box_set0:
                ok = 0;
            box_done:
                if (ok != 0) {
                    s32 e = *(s32 *)(obj + 0x1EC);
                    f32 eps;
                    f32 one = lbl_805622E0;
                    eps = lbl_805622D8;
                    s32 k = 0;
                    do {
                        f32 *bm;
                        fn_801BEAEC(e, k, &corner);
                        bm = *(f32 **)(other + 0xC);
                        q.x = corner.x - bm[9];
                        q.y = corner.y - bm[10];
                        q.z = corner.z - bm[11];
                        x = q.x;
                        y = q.y;
                        z = q.z;
                        nx = (y * bm[1] + x * bm[0]) + z * bm[2];
                        ny = (y * bm[4] + x * bm[3]) + z * bm[5];
                        nz = (y * bm[7] + x * bm[6]) + z * bm[8];
                        q.x = nx;
                        q.y = ny;
                        q.z = nz;
                        f32 sx = *(f32 *)(other + 0x24);
                        f32 sy = *(f32 *)(other + 0x28);
                        f32 sz = *(f32 *)(other + 0x2C);
                        f32 c = q.x;
                        if (sx < c) c = sx;
                        q.x = (c > -sx) ? c : -sx;
                        c = q.y;
                        if (sy < c) c = sy;
                        q.y = (c > -sy) ? c : -sy;
                        c = q.z;
                        if (sz < c) c = sz;
                        q.z = (c > -sz) ? c : -sz;
                        bm = *(f32 **)(other + 0xC);
                        fn801A0464RotateVec(&out, q, bm);
                        out.x += bm[9];
                        out.y += bm[10];
                        out.z += bm[11];
                        diff.x = corner.x - out.x;
                        diff.y = corner.y - out.y;
                        diff.z = corner.z - out.z;
                        f32 mag = PSVECMag(&diff);
                        if (mag > eps) {
                            f32 inv = one / mag;
                            diff.x *= inv;
                            diff.y *= inv;
                            diff.z *= inv;
                            fn_801BEB44(e, k, &out, (f32 *)&diff);
                        }
                        k++;
                    } while (k < 4);
                }
            }
            }
        }
    } else if (tag == 0x53504852 || tag == 0x464C5352) {
        CornerV3Copy((CornerV3 *)&center, (CornerV3 *)(*(u8 **)(self + 0x17C) + 0x38));
        u8 *owner = *(u8 **)(self + 4);
        if (owner != 0) {
            center.x += *(f32 *)(owner + 0x30);
            center.y += *(f32 *)(owner + 0x34);
            center.z += *(f32 *)(owner + 0x38);
        }
        if (*(u32 *)(other + 0x18) == 0x53504852) {
            fn_8019BD54(other, *(void **)(self + 0x17C), (s32)&center, 0);
        } else {
            fn_8019D06C(other, *(void **)(self + 0x17C), (s32)&center, 0);
        }
    } else if (tag == 0x54554245) {
        fn_8019EA7C(other, *(void **)(self + 0x17C));
    } else if (tag == 0x52494E47) {
        ((void (*)(void *))fn_801A0160)(self);
        u8 *ent = self;
        s32 i = 0;
        while (i < *(s32 *)(self + 0x174)) {
            fn_8019C854(*(void **)(ent + 0x24), other);
            ent += 4;
            i++;
        }
    } else if (tag == 0x52414744) {
        ((Fn801A401CDispatch *)other)->Call(self);
    } else if (tag == 0x504F4C59) {
        ((void (*)(void *))fn_801A0160)(self);
        u8 *ent = self;
        s32 i = 0;
        while (i < *(s32 *)(self + 0x174)) {
            ((Fn801A401CDispatch *)other)->Call(*(void **)(ent + 0x24));
            ent += 4;
            i++;
        }
        u8 *obj = *(u8 **)(self + 4);
        s32 ok;
        if (obj == 0) goto poly_set0;
        switch (*(s32 *)(obj + 0x10)) {
        case 0x4E434152:
        case 0x43415220:
        case 0x41434152:
        case 0x50434152:
            ok = 1;
            goto poly_done;
        }
    poly_set0:
        ok = 0;
    poly_done:
        if (ok != 0) {
            s32 e = *(s32 *)(obj + 0x1EC);
            s32 k = 0;
            f32 scale = lbl_805623B8;
            do {
                fn_801BEAEC(e, k, &polyPoint);
                size.x = *(f32 *)(obj + 0x3C) * scale;
                size.y = *(f32 *)(obj + 0x40) * scale;
                size.z = *(f32 *)(obj + 0x44) * scale;
                if (fn_80198F64(&polyPoint, (int)other, &hit, &depth, &nrm, (float *)&size, lbl_805622E0)) {
                    fn_801BEB44(e, k, &hit, (f32 *)&nrm);
                }
                k++;
            } while (k < 4);
        }
    } else if (tag == 0x504D5348) {
        ((void (*)(void *))fn_801A0160)(self);
        u8 *ent = self;
        s32 i = 0;
        while (i < *(s32 *)(self + 0x174)) {
            ((Fn801A401CDispatch *)other)->Call(*(void **)(ent + 0x24));
            ent += 4;
            i++;
        }
        u8 *obj = *(u8 **)(self + 4);
        s32 ok;
        if (obj == 0) goto mesh_set0;
        switch (*(s32 *)(obj + 0x10)) {
        case 0x4E434152:
        case 0x43415220:
        case 0x41434152:
        case 0x50434152:
            ok = 1;
            goto mesh_done;
        }
    mesh_set0:
        ok = 0;
    mesh_done:
        if (ok != 0) {
            s32 e = *(s32 *)(obj + 0x1EC);
            s32 k = 0;
            f32 push;
            f32 one = lbl_805622E0;
            s32 maxCount = 0x40;
            f32 zero = lbl_805622D4;
            push = lbl_805623BC;
            do {
                s32 j;
                fn_801BEAEC(e, k, &tmp);
                CornerV3Copy((CornerV3 *)&v, (CornerV3 *)&tmp);
                v.x += *(f32 *)(obj + 0x48) * push;
                v.y += *(f32 *)(obj + 0x4C) * push;
                v.z += *(f32 *)(obj + 0x50) * push;
                count = maxCount;
                fn_801CF080(*(s32 *)(other + 0x24), &v, buffer, &count, *(s32 *)(other + 0xC), lbl_8056234C);
                Vec *cur = (Vec *)buffer;
                for (j = 0; j < count; j++) {
                    meshDelta.x = v.x - cur->x;
                    meshDelta.y = v.y - cur->y;
                    meshDelta.z = v.z - cur->z;
                    f32 mag = PSVECMag(&meshDelta);
                    if (mag > zero) {
                        f32 inv = one / mag;
                        meshDelta.x *= inv;
                        meshDelta.y *= inv;
                        meshDelta.z *= inv;
                        fn_801BEB44(e, k, (f32 *)cur, (f32 *)&meshDelta);
                    }
                    cur++;
                }
                k++;
            } while (k < 4);
        }
    }
}

#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
/* Per-frame physics-group pass: tick and update children, then push a driven car's four physics corners out of nearby track-mesh points. */ extern "C" void stepPhysicsGroup(void* group) {
    /* Per-frame pass of a physics group: tick its children, run each child's own
       update, and then -- when the group drives a car and the "track.msh" mesh is
       loaded -- push the car's four physics corners out of the track mesh points
       that lie around them. */
    s32 count;
    Vec corner;
    Vec points[0x40];
    u8* carObj;
    s32 i;
    u8* entry;
    fn_801A0160(group);                                  /* the children's once-per-frame tick */
    entry = (u8*)group;
    for (i = 0; i < *(s32*)((u8*)group + 0x174); i++) {  /* then each child's own update */
        ((Fn801A0F10Child*)*(void**)(entry + 0x24))->Update();
        entry += 4;
    }
    if (trackMesh != 0) {                             /* the cached "track.msh" mesh */
        carObj = *(u8**)((u8*)group + 4);                   /* the object this group drives */
        s32 isCar;
        if (carObj == 0) goto set0;
        switch (*(s32*)(carObj + 0x10)) {                   /* its type tag: NCAR, CAR , ACAR, PCAR */
        case 0x4E434152:
        case 0x43415220:
        case 0x41434152:
        case 0x50434152:
            isCar = 1;
            goto done;
        }
    set0:
        isCar = 0;
    done:
        if (isCar != 0) {
            s32 body = *(s32*)(carObj + 0x1EC);             /* the car's physics body */
            s32 k = 0;                                   /* its four corners */
            f32 one = lbl_805622E0;                      /* 1.0f */
            f32 minDist = lbl_805622D4;                  /* 0.001f: what counts as a hit */
            do {
                fn_801BEAEC(body, k, &corner);           /* where corner k is this frame */
                Vec v = corner;
                v.x += *(f32*)(carObj + 0x48) * one;        /* dragged along by the car's velocity */
                v.y += *(f32*)(carObj + 0x4C) * one;
                v.z += *(f32*)(carObj + 0x50) * one;
                count = 0x40;
                fn_801CF080(trackMesh, &v, points, &count, 0, lbl_8056234C);  /* mesh points near it */
                for (s32 j = 0; j < count; j++) {
                    Vec d;                               /* corner minus that point */
                    d.x = v.x - points[j].x;
                    d.y = v.y - points[j].y;
                    d.z = v.z - points[j].z;
                    f32 mag = PSVECMag(&d);
                    if (mag > minDist) {
                        f32 inv = one / mag;             /* push straight out of it */
                        d.x *= inv;
                        d.y *= inv;
                        d.z *= inv;
                        fn_801BEB44(body, k, (f32*)&points[j], (f32*)&d);
                    }
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
    /* Test a sphere-swept query against the object's children: compute the projected
     * distance from the base position to vec, and if within the radius range check
     * each child entry with fn_8019DDFC, returning 1 if any child is hit. */
    f32 delta[3];
    void *base = *(void **)((u8 *)arg0 + 0xC);
    delta[0] = *(f32 *)((u8 *)base + 0x24) - vec[0];
    delta[1] = *(f32 *)((u8 *)base + 0x28) - vec[1];
    delta[2] = *(f32 *)((u8 *)base + 0x2C) - vec[2];
    f32 dot = PSVECDotProduct((const Vec *)delta, (const Vec *)(u32)arg2);
    f32 radius = *(f32 *)((u8 *)arg0 + 0x178);
    if (dot >= -radius && dot < *arg3 + radius) {
        fn_801A0160(arg0);
        s32 hit = 0;
        s32 i = 0;
        while (i < *(s32 *)((u8 *)arg0 + 0x174)) {
            void *entry = (u8 *)arg0 + i * 4;
            void *item = *(void **)((u8 *)entry + 0x24);
            if (((s32 (*)(s32, s32, s32, s32, void *, f32))fn_8019DDFC)((s32)vec, arg2, (s32)arg3, arg4,
                            (u8 *)item + 0x34,
                            *(f32 *)((u8 *)item + 0x24)) != 0) {
                hit = 1;
            }
            i++;
        }
        return hit;
    }
    return 0;
}
#pragma pop
#pragma scheduling on
/* Call v08 on each child in the list (count at +0x174), then mark the active index at +0x180 as none. */
extern "C" void fn_801A1250(void *container) {
    VTab1250 **childEntries = (VTab1250 **)container;
    s32 childIndex = 0;
    while (childIndex < *(s32 *)((u8 *)container + 0x174)) {
        childEntries[9]->v08();
        childEntries++;
        childIndex++;
    }
    *(s32 *)((u8 *)container + 0x180) = -1;
}

/* Store value at +0x1C, notify the primary child at +0x17C, then broadcast the value
 * to each entry in the child pointer array at +0x24 (count at +0x174). */
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
    FirstDispatch *primaryChild = *(FirstDispatch **)((u8 *)arg0 + 0x17C);
    primaryChild->call();
    u8 *entryPtr = (u8 *)arg0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x174)) {
        EntryDispatch *child = *(EntryDispatch **)(entryPtr + 0x24);
        child->call(arg1);
        entryPtr += 4;
        i++;
    }
}

/* Store a 32-bit value into the field at offset 0x1C of the given object (no child broadcast). */
extern "C" void fn_801A1358(void *object, s32 value) { *(s32 *)((u8 *)object + 0x1C) = value; }

extern "C" void fn_801A1360(void *arg0, s32 arg1) {
    /* Store value and propagate it to the primary child and to each child entry. */
    class Dispatch {
    public:
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6();
        virtual void d7();
        virtual void d8();
        virtual void d9();
        virtual void d10();
        virtual void d11();
        virtual void d12();
        virtual void d13();
        virtual void set(s32);
    };
    *(s32 *)((u8 *)arg0 + 0x20) = arg1;
    void *primary = *(void **)((u8 *)arg0 + 0x17C);
    ((Dispatch *)primary)->set(arg1);
    u8 *cursor = (u8 *)arg0;
    s32 index = 0;

    while (index < *(s32 *)((u8 *)arg0 + 0x174)) {
        void *child = *(void **)(cursor + 0x24);
        ((Dispatch *)child)->set(arg1);
        cursor += 4;
        index++;
    }
}

extern "C" void fn_801A13F4(void* self) {
    class Dispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16();
        virtual void Call();
    };
    /* Invoke Call() on the primary child (+0x17C) and on each entry in the child list (+0x24, count at +0x174). */
    void* primary = *(void**)((u8*)self + 0x17C);
    ((Dispatch*)primary)->Call();
    u8* cursor = (u8*)self;
    s32 index = 0;
    goto check;
loop:
    ((Dispatch*)*(void**)(cursor + 0x24))->Call();
    cursor += 4;
    index++;
check:
    if (index < *(s32*)((u8*)self + 0x174)) goto loop;
}

extern "C" void fn_801A1474(void* self, f32 scale) {
    f32* src = (f32*)((u8*)self + 0x64);
    u8* entrySlot = (u8*)self;
    s32 i = 0;
    volatile f32 tmp[3];
    void* dst;

    /* Scales this object's stored factors/vectors and per-entry values by the given scale. */
    *(f32*)((u8*)self + 0x178) = *(f32*)((u8*)self + 0x170) * scale;
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
    dst = *(void**)(entrySlot + 0x24);
    y = yRaw * scale;
    z = zRaw * scale;
    *(f32*)((u8*)dst + 0x28) = x;
    *(f32*)((u8*)dst + 0x2c) = y;
    *(f32*)((u8*)dst + 0x30) = z;

    f32 w = src[3] * scale;
    src += 4;
    dst = *(void**)(entrySlot + 0x24);
    entrySlot += 4;
    tmp[0] = x;
    tmp[1] = y;
    tmp[2] = z;
    *(f32*)((u8*)dst + 0x24) = w;

check:
    if (i < *(s32*)((u8*)self + 0x174)) {
        goto loop;
    }

    dst = *(void**)((u8*)self + 0x17c);
    f32 tailX = *(f32*)((u8*)self + 0x164) * scale;
    f32 tailY = *(f32*)((u8*)self + 0x168) * scale;
    f32 tailZ = *(f32*)((u8*)self + 0x16c) * scale;
    *(f32*)((u8*)dst + 0x24) = tailX;
    *(f32*)((u8*)dst + 0x28) = tailY;
    *(f32*)((u8*)dst + 0x2c) = tailZ;
}

__declspec(section ".data") extern void* lbl_80333968;
extern f32 lbl_80562370;
#pragma push
#pragma small_data off
extern "C" void* fn_801A1520(void* self, void* unused, s32 doSwap) {
    u8 b24;
    u8 b28;
    u8 b25;
    u8 b29;
    ((void(*)(void*,s32,s32))fn_8019ECC4)(self, (s32)unused, doSwap);
    *(void**)self = &lbl_80333968;
    if (doSwap != 0) {
        b24 = *(u8*)((u8*)self + 0x24);
        b25 = *(u8*)((u8*)self + 0x25);
        b28 = *(u8*)((u8*)self + 0x28);
        b29 = *(u8*)((u8*)self + 0x29);
        *(u8*)((u8*)self + 0x24) = *(u8*)((u8*)self + 0x27);
        *(u8*)((u8*)self + 0x27) = b24;
        *(u8*)((u8*)self + 0x25) = *(u8*)((u8*)self + 0x26);
        *(u8*)((u8*)self + 0x26) = b25;
        *(u8*)((u8*)self + 0x28) = *(u8*)((u8*)self + 0x2B);
        *(u8*)((u8*)self + 0x2B) = b28;
        *(u8*)((u8*)self + 0x29) = *(u8*)((u8*)self + 0x2A);
        *(u8*)((u8*)self + 0x2A) = b29;
        if (*(s32*)((u8*)self + 0x20) == 0x3EB)
            *(f32*)((u8*)self + 0x24) += lbl_80562370;
    }
    return self;
}
#pragma pop
extern f32 lbl_805622D0, lbl_805622D4, lbl_805622E0;
#pragma use_lmw_stmw off
extern "C" s32 fn_801A15CC(void* arg0, Vec* arg1, Vec* arg2, f32* arg3, Vec* arg4) {
    f32 t0 = lbl_805622D0;
    f32 t1 = lbl_805622D0;
    Vec* mat = *(Vec**)((u8*)arg0 + 0xC);
    Vec* axis = (Vec*)((u8*)mat + 0x18);
    Vec* center = (Vec*)((u8*)mat + 0x24);
    if (fn_8019D484(arg1, arg2, center, axis, &t0, &t1) == 0) goto fail;
    f32 extent = *(f32*)((u8*)arg0 + 0x28);
    f32 neg_extent = -*(f32*)((u8*)arg0 + 0x28);
    extent = (extent < t1) ? t1 : extent;
    extent = (extent > neg_extent) ? neg_extent : extent;
    t1 = extent;
    if (!(t0 > lbl_805622D0 && t0 < *arg3)) goto fail;
    Vec p, q;
    f32 bx = arg2->x, by = arg2->y, bz = arg2->z;
    f32 t = (f32)(f64)extent;
    f32 px = bx * t0, py = by * t0, pz = bz * t0;
    f32 ax = arg1->x, ay = arg1->y, az = arg1->z;
    p.x = ax + px; p.y = ay + py; p.z = az + pz;
    q.x = center->x + axis->x * t;
    q.y = center->y + axis->y * t;
    q.z = center->z + axis->z * t;
    if (PSVECSquareDistance(&p, &q) >= (*(f32*)((u8*)arg0 + 0x24) * *(f32*)((u8*)arg0 + 0x24))) goto fail;
    arg4->x = p.x - q.x;
    arg4->y = p.y - q.y;
    arg4->z = p.z - q.z;
    f32 mag = PSVECMag(arg4);
    f32 denom = (lbl_805622D4 > mag) ? lbl_805622D4 : mag;
    f32 scale = lbl_805622E0 / denom;
    arg4->x *= scale; arg4->y *= scale; arg4->z *= scale;
    *arg3 = t0;
    return 1;
fail:
    return 0;
}
/* Draw a solid yellow debug beam along a capsule collision shape's axis, from center - axis*extent to center + axis*extent; the beam width scales with the capsule radius. */
extern "C" void fn_801A17B8(void* capsule) {
    extern f32 lbl_8056234C;
    extern void fn_801E41D8(void*, void*, s32, f32);
    f32 axisAndCenter[6];
    f32 start[3];
    f32 end[3];
    const u32* axisWords;
    f32 extent;
    f32 negExtent;

    axisWords = (const u32*)((u8*)*(void**)((u8*)capsule + 0xC) + 0x18);
    ((u32*)axisAndCenter)[0] = axisWords[0];
    ((u32*)axisAndCenter)[1] = axisWords[1];
    ((u32*)axisAndCenter)[2] = axisWords[2];
    ((u32*)axisAndCenter)[3] = axisWords[3];
    ((u32*)axisAndCenter)[4] = axisWords[4];
    ((u32*)axisAndCenter)[5] = axisWords[5];
    extent = *(f32*)((u8*)capsule + 0x28);
    start[0] = axisAndCenter[3] + axisAndCenter[0] * extent;
    start[1] = axisAndCenter[4] + axisAndCenter[1] * extent;
    start[2] = axisAndCenter[5] + axisAndCenter[2] * extent;
    negExtent = -*(f32*)((u8*)capsule + 0x28);
    end[0] = axisAndCenter[3] + axisAndCenter[0] * negExtent;
    end[1] = axisAndCenter[4] + axisAndCenter[1] * negExtent;
    end[2] = axisAndCenter[5] + axisAndCenter[2] * negExtent;
    fn_801E41D8(start, end, 0x40FFFF00, lbl_8056234C * *(f32*)((u8*)capsule + 0x24));
}
#pragma scheduling on
extern int lbl_80333918[64];
extern "C" void* fn_801A1520(void*, void*, s32);
#pragma scheduling off
extern "C" void** fn_801A1898(void** object) {
#define BaseCtor fn_801A1520
#define DerivedVtable lbl_80333918
    /* Construct a derived object: run the base initializer, then install the derived vtable. */
    ((void* (*)(void*))BaseCtor)(object);
    *object = &DerivedVtable;
    return object;
#undef BaseCtor
#undef DerivedVtable
}

#pragma processor 750
extern "C" void fn_801A18D4(void* arg0, f32* arg1, f32* arg2) {
    volatile u32 local[30];
    void* m = *(void**)((u8*)arg0+0xC);
    f32 x = *(f32*)((u8*)arg0+0x24);
    u32 v0 = *(u32*)((u8*)m+0x20);
    u32 v1 = *(u32*)((u8*)m+0x2c);
    f32 nx = -x;
    local[26] = v0;
    u32 v2 = *(u32*)((u8*)m+0x18);
    local[29] = v1;
    f32 a = *(volatile f32*)&local[26];
    local[24] = v2;
    f32 ax = a*x;
    f32 b = *(volatile f32*)&local[29];
    u32 v3 = *(u32*)((u8*)m+0x1c);
    f32 anx = a*nx;
    u32 v4 = *(u32*)((u8*)m+0x24);
    f32 g = b + ax;
    f32 c = *(volatile f32*)&local[24];
    local[25] = v3;
    f32 h = b + anx;
    u32 v5 = *(u32*)((u8*)m+0x28);
    local[27] = v4;
    f32 cx = c*x;
    f32 lo0 = g - x;
    f32 d = *(volatile f32*)&local[25];
    f32 lo1 = h - x;
    f32 e = *(volatile f32*)&local[27];
    local[28] = v5;
    f32 i = e + cx;
    f32 cnx = c*nx;
    *(volatile f32*)&local[23] = g;
    f32 dx = d*x;
    f32 f = *(volatile f32*)&local[28];
    f32 j = e + cnx;
    f32 dnx = d*nx;
    *(volatile f32*)&local[20] = h;
    f32 k = f + dx;
    f32 lo3 = j - x;
    f32 l = f + dnx;
    f32 lo4 = k - x;
    *(volatile f32*)&local[18] = j;
    f32 lo5 = l - x;
    *(volatile f32*)&local[19] = l;
    f32 lo2 = i - x;
    *(volatile f32*)&local[21] = i;
    *(volatile f32*)&local[22] = k;
    *(volatile f32*)&local[9] = lo3;
    *(volatile f32*)&local[10] = lo5;
    *(volatile f32*)&local[11] = lo1;
    *(volatile f32*)&local[12] = lo2;
    *(volatile f32*)&local[13] = lo4;
    *(volatile f32*)&local[14] = lo0;
    f64 m0 = lo0, m1 = lo1, m2 = lo2, m3 = lo3, m4 = lo4, m5 = lo5;
    m0 = (m0 < m1) ? m0 : m1;
    m4 = (m4 < *(volatile f32*)&local[10]) ? m4 : *(volatile f32*)&local[10];
    m2 = (m2 < *(volatile f32*)&local[9]) ? m2 : *(volatile f32*)&local[9];
    arg1[0] = (f32)m2; arg1[1] = (f32)m4; arg1[2] = (f32)m0;
    f64 M0 = *(volatile f32*)&local[23] + x;
    f64 M1 = *(volatile f32*)&local[20] + x;
    f64 M2 = *(volatile f32*)&local[19] + x;
    f64 M3 = *(volatile f32*)&local[18] + x;
    f64 M4 = *(volatile f32*)&local[22] + x;
    f64 M5 = *(volatile f32*)&local[21] + x;
    M0 = (M0 > M3) ? M0 : M3;
    M1 = (M1 > M4) ? M1 : M4;
    M2 = (M2 > M5) ? M2 : M5;
    arg2[0] = (f32)M2; arg2[1] = (f32)M1; arg2[2] = (f32)M0;
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
    f32 z = lbl_805622D0;
    *(volatile f32*)&local[12] = f8 + f14 * w;
    *(volatile f32*)&local[13] = fC + f18 * w;
    *(volatile f32*)&local[9] = f8 + f14 * neg_w;
    *(volatile f32*)&local[11] = f10 + f14 * neg_w;
    *(volatile f32*)&local[10] = fC + f18 * neg_w;
    *(volatile f32*)&local[14] = f10 + f14 * w;
    f32 f = *(f32*)((u8*)arg0 + 0x24);
    *(volatile f32*)&local[6] = z;
    *(volatile f32*)&local[7] = z;
    *(volatile f32*)&local[8] = z;
    fn_8019AC44(arg0, (void*)&local[12], (void*)&local[6], f);
    fn_8019AC44(arg0, (void*)&local[9], (void*)&local[6], f);
}

extern "C" void fn_801E44F4(void*, u32, f32, f32, f32);
#pragma scheduling invalid_target
extern "C" void fn_801A1CA0(void* arg0) {
    /* Submits this object's transform for debug drawing: uses a yellow tint when its
     * counter at +0x20 is below 1000, otherwise a green tint. */
    if (*(s32*)((u8*)arg0 + 0x20) < 1000) {
        f32 halfExtentX = *(f32*)((u8*)arg0 + 0x24);
        f32 halfExtentZ = *(f32*)((u8*)arg0 + 0x28);
        fn_801E44F4(*(void**)((u8*)arg0 + 0xC), 0x40FFFF00, halfExtentX, halfExtentX, halfExtentZ);
    } else {
        f32 halfExtentX = *(f32*)((u8*)arg0 + 0x24);
        f32 halfExtentZ = *(f32*)((u8*)arg0 + 0x28);
        fn_801E44F4(*(void**)((u8*)arg0 + 0xC), 0x4000FF80, halfExtentX, halfExtentX, halfExtentZ);
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
    ((void(*)(void*,s32,s32))fn_8019ECC4)(shape, owner, swap);
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
/* Dispatch a shape operation by the FourCC type at +0x18, calling the type-specific handler. */
extern "C" void fn_801A1DD4(void* context, void* shape) {
    switch (*(s32*)((u8*)shape + 0x18)) {
    case 'FLSR':
        fn_8019D06C(shape, context, 0, 0);
        break;
    case 'SPHR':
        fn_8019BD54(shape, context, 0, 0);
        break;
    case 'TUBE':
        fn_8019EA7C(shape, context);
        break;
    case 'GRUP':
        ((Fn801A401CDispatch*)shape)->Call(context);
        break;
    }
}

extern "C" void fn_8019D06C(void*, void*, s32, s32);
extern "C" s32 fn_8019E2D0(s32, s32, s32, void*, f32, f32, f32);
#pragma paired off
#pragma paired_single off
extern "C" s32 fn_801A1E7C(void *object, s32 rayOrigin, s32 rayDirection, s32 hitDistance, void *outNormal) {
    /* Tests a ray against the object's oriented bounds using its transform; on hit sets outNormal to (0, 0.5, 0) and returns 1. */
    register f32 extentZ = *(f32 *)((u8 *)object + 0x2c);
    register f32 extentY = *(f32 *)((u8 *)object + 0x28);
    register f32 extentX = *(f32 *)((u8 *)object + 0x24);
    void *transform = ((VTab1A1E7C *)object)->Call();
    if (fn_8019E2D0(rayOrigin, rayDirection, hitDistance, transform, extentX, extentY, extentZ)) {
        f32 middle;
        f32 same;
        same = lbl_805622D0;
        middle = lbl_805622E0;
        *(f32 *)outNormal = same;
        *((f32 *)outNormal + 1) = middle;
        *((f32 *)outNormal + 2) = same;
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
    s32 x = *(s32*)((u8*)result + 0x24);
    s32 y = *(s32*)((u8*)result + 0x28);
    *(s32*)arg0 = x;
    *(s32*)((u8*)arg0 + 4) = y;
    *(s32*)((u8*)arg0 + 8) = *(s32*)((u8*)result + 0x2C);
}

#pragma push
#pragma use_lmw_stmw off
/* Compute the world-space AABB of a box: build its eight local corners from the half-extents at +0x24/0x28/0x2C, transform each through the matrix returned by the object's virtual Call(), translate it, and expand outMin/outMax with the result. */
extern "C" void computeBoxBounds(const void *box, f32 *outMin, f32 *outMax)
{
  f32 worldPoint[3];
  f32 localCorners[24];
  register f32 halfX;
  register f32 halfY;
  register f32 halfZ;
  halfZ = *((f32 *) (((char *) box) + 0x2C));
  halfY = *((f32 *) (((char *) box) + 0x28));
  halfX = *((f32 *) (((char *) box) + 0x24));
  register f32 negHalfX;
  register f32 negHalfY;
  register f32 negHalfZ;
  negHalfY = -halfY;
  negHalfX = -halfX;
  localCorners[1] = halfY;
  negHalfZ = -halfZ;
  localCorners[0] = halfX;
  localCorners[2] = halfZ;
  localCorners[3] = negHalfX;
  localCorners[4] = halfY;
  localCorners[5] = halfZ;
  localCorners[6] = halfX;
  localCorners[7] = negHalfY;
  localCorners[8] = halfZ;
  localCorners[9] = negHalfX;
  localCorners[10] = negHalfY;
  localCorners[11] = halfZ;
  localCorners[12] = halfX;
  localCorners[13] = halfY;
  localCorners[14] = negHalfZ;
  localCorners[15] = negHalfX;
  localCorners[16] = halfY;
  localCorners[17] = negHalfZ;
  localCorners[18] = halfX;
  localCorners[19] = negHalfY;
  localCorners[20] = negHalfZ;
  localCorners[21] = negHalfX;
  localCorners[22] = negHalfY;
  localCorners[23] = negHalfZ;
  f32 *transform = (f32 *) ((VTab1A1E7C *) box)->Call();
  outMin[0] = transform[9];
  outMin[1] = transform[10];
  outMin[2] = transform[11];
  transform = (f32 *) ((VTab1A1E7C *) box)->Call();
  outMax[0] = transform[9];
  outMax[1] = transform[10];
  outMax[2] = transform[11];
  f32 *dst = worldPoint;
  f32 *compare = localCorners;
  f32 *corner = localCorners;
  int cornerIdx = 0;
  for (; cornerIdx < 8; cornerIdx++)
  {
    transform = (f32 *) ((VTab1A1E7C *) box)->Call();
    if (dst == compare)
    {
      f32 cx, cy, cz;
      f32 m0, m3, m6, m1, m4, m7, m2, m5, m8;
      m3 = transform[3]; m4 = transform[4]; m5 = transform[5];
      m0 = transform[0]; m1 = transform[1]; m2 = transform[2];
      m6 = transform[6]; m7 = transform[7]; m8 = transform[8];
      cx = corner[0]; cy = corner[1]; cz = corner[2];
      f32 t0 = cz * m6 + (cx * m0 + cy * m3);
      f32 t1 = cz * m7 + (cx * m1 + cy * m4);
      f32 t2 = cz * m8 + (cx * m2 + cy * m5);
      dst[0] = t0;
      dst[1] = t1;
      dst[2] = t2;
    }
    else
    {
      f32 m3, cx, m0, cy, m6, cz, m4, m1, m7, m5, m2, m8;
      m3 = transform[3];
      cy = corner[1];
      m0 = transform[0];
      cx = corner[0];
      m6 = transform[6];
      cz = corner[2];
      dst[0] = cx * m0 + cy * m3 + cz * m6;
      m4 = transform[4];
      m1 = transform[1];
      m7 = transform[7];
      dst[1] = cx * m1 + cy * m4 + cz * m7;
      m5 = transform[5];
      m2 = transform[2];
      m8 = transform[8];
      dst[2] = cx * m2 + cy * m5 + cz * m8;
    }
    worldPoint[0] += transform[9];
    worldPoint[1] += transform[10];
    worldPoint[2] += transform[11];
    {
      f32 p = worldPoint[0]; f32 m = outMin[0];
      m = (m < p) ? (m) : (p);
      outMin[0] = m;
    }
    {
      f32 p = worldPoint[1]; f32 m = outMin[1];
      m = (m < p) ? (m) : (p);
      outMin[1] = m;
    }
    {
      f32 p = worldPoint[2]; f32 m = outMin[2];
      m = (m < p) ? (m) : (p);
      outMin[2] = m;
    }
    {
      f32 p = worldPoint[0]; f32 m = outMax[0];
      m = (m > p) ? (m) : (p);
      outMax[0] = m;
    }
    {
      f32 p = worldPoint[1]; f32 m = outMax[1];
      m = (m > p) ? (m) : (p);
      outMax[1] = m;
    }
    {
      f32 p = worldPoint[2]; f32 m = outMax[2];
      m = (m > p) ? (m) : (p);
      outMax[2] = m;
    }
    compare += 3;
    corner += 3;
  }
}
#pragma pop
extern "C" void fn_801A22A4(void* obj) {
    /* Copy a 12-word transform from the object's vtable slot 0x50 into a temp buffer and submit it with this object's position (+0x24/28/2C) to fn_801E44F4 (tag 0x50000000). */
    volatile u32* result = (volatile u32*)((VTab1A1E7C*)obj)->Call();
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
    f32 tailZ = *(f32*)((u8*)obj + 0x2c);
    f32 tailY = *(f32*)((u8*)obj + 0x28);
    f32 tailX = *(f32*)((u8*)obj + 0x24);
    typedef void (*Fn801E44F4)(volatile u32*, u32, u32, f32, f32, f32);
    ((Fn801E44F4)fn_801E44F4)(words, 0x50000000, value9, tailX, tailY, tailZ);
}

#pragma scheduling invalid_target
extern "C" void *fn_801A2354(void *arg0, s32 arg1, void *arg2, s32 arg3, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4)
{
  extern char lbl_80333868[];
  f32 diffY = farg2 - 0.2f;
  f32 diffX = farg3 - 0.2f;
  f32 diffZ = farg4 - 0.2f;
  f32 dx2 = (farg3 - 0.2f) * (farg3 - 0.2f);
  f32 dy2;
  f32 dz2 = diffZ * diffZ;
  f32 dist = (dx2 + (diffY * diffY)) + dz2;
  *((f32 *) (((u8 *) arg0) + 0x10)) = farg0;
  *((s32 *) (((u8 *) arg0) + 0xC)) = arg1;
  *((s32 *) (((u8 *) arg0) + 4)) = arg3;
  *((s32 *) (((u8 *) arg0) + 8)) = 0;
  *((u32 *) (((u8 *) arg0) + 0x18)) = 0x424F5820;
  *((f32 *) (((u8 *) arg0) + 0x14)) = farg1;
  *((s32 *) (((u8 *) arg0) + 0x20)) = 100;
  *((s32 *) (((u8 *) arg0) + 0x1C)) = 0;
  *((void **) arg0) = lbl_803338C0;
  *((f32 *) (((u8 *) arg0) + 0x24)) = diffY;
  *((f32 *) (((u8 *) arg0) + 0x28)) = (farg3 - 0.2f);
  *((f32 *) (((u8 *) arg0) + 0x2C)) = diffZ;
  *((s32 *) (((u8 *) arg0) + 0x34)) = 0;
  f32 radius = 0.2f + ((f32) fn_8002F234(dist));
  volatile f32 *input = (volatile f32 *) arg2;
  f32 x = input[0];
  f32 y = input[1];
  *((f32 *) (((u8 *) arg0) + 0x38)) = x;
  *((f32 *) (((u8 *) arg0) + 0x30)) = radius;
  *((void **) arg0) = lbl_80333868;
  f32 z = input[2];
  *((f32 *) (((u8 *) arg0) + 0x3C)) = y;
  *((f32 *) (((u8 *) arg0) + 0x40)) = z;
  return arg0;
}
#pragma scheduling on
extern "C" s32 fn_801A2434(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

#pragma dont_inline off
/* Transform input by the cached matrix (3x3 linear part plus translation) into output; preload all coefficients when input and output alias. */
extern "C" void fn_801A2474(void *obj) {
    struct Row { f32 v[3]; };
    struct MatrixVecTransform {
        char pad0[0xC];
        f32 *matrix;
        char pad10[0x28];
        Vec input;
        Row cache[3];
        volatile Vec output;
    };
    MatrixVecTransform *self = (MatrixVecTransform *)obj;
    f32 *m = self->matrix;
    self->cache[0] = ((Row *)m)[0];
    self->cache[1] = ((Row *)m)[1];
    self->cache[2] = ((Row *)m)[2];
    if (&self->output == (volatile Vec *)&self->input) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = m[3]; m11 = m[4]; m12 = m[5]; m00 = m[0]; m01 = m[1]; m02 = m[2]; m20 = m[6]; m21 = m[7]; m22 = m[8];
        x = self->input.x; y = self->input.y; z = self->input.z;
        self->output.x = z * m20 + (x * m00 + y * m10);
        self->output.y = z * m21 + (x * m01 + y * m11);
        self->output.z = z * m22 + (x * m02 + y * m12);
    } else {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = m[3]; m00 = m[0]; m20 = m[6];
        x = self->input.x; y = self->input.y; z = self->input.z;
        self->output.x = z * m20 + (x * m00 + y * m10);
        m11 = m[4]; m01 = m[1]; m21 = m[7];
        self->output.y = z * m21 + (x * m01 + y * m11);
        m12 = m[5]; m02 = m[2]; m22 = m[8];
        self->output.z = z * m22 + (x * m02 + y * m12);
    }
    self->output.x += m[9];
    self->output.y += m[10];
    self->output.z += m[11];
}
extern "C" char lbl_80333818[];
extern "C" void fn_801A2674(void*, s32, s32, f32);
#pragma scheduling on
extern "C" void* fn_801A25F8(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(void**)arg0 = lbl_80333818;
    f32 init = 1.0f;
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(s32*)((u8*)arg0 + 0x30) = arg2;
    *(s32*)((u8*)arg0 + 4) = arg3;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0x18) = 'RAGD';
    *(f32*)((u8*)arg0 + 0x10) = init;
    *(f32*)((u8*)arg0 + 0x14) = init;
    *(s32*)((u8*)arg0 + 0x20) = 0x64;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(void**)arg0 = lbl_80333818;
    ((void (*)(void*, s32, s32))fn_801A2674)(arg0, 0, -1);
    return arg0;
}
/* Set the tail fields of the object built by fn_801A25F8: an extent/scale float
 * at +0x24 and two integer parameters at +0x28 and +0x2C. */
extern "C" void fn_801A2674(void* obj, s32 param28, s32 param2C, f32 extent) {
    *(f32*)((u8*)obj + 0x24) = extent;
    *(s32*)((u8*)obj + 0x28) = param28;
    *(s32*)((u8*)obj + 0x2C) = param2C;
}

extern f32 lbl_805622E0;
extern "C" void fn_801A2684(void *arg0, f32 *arg1, f32 *arg2)
{
  register f32 pos;
  register f32 neg;
  register f32 scale;
  f32 temp_f0 = *((f32 *) (((u8 *) arg0) + 0x24));
  void *temp_r3 = *((void **) (((u8 *) arg0) + 0xC));
  scale = lbl_805622E0;
  neg = scale * (-temp_f0);
  pos = scale * temp_f0;
  arg1[0] = (*((f32 *) (((u8 *) temp_r3) + 0x24))) + neg;
  arg1[1] = (*((f32 *) (((u8 *) temp_r3) + 0x28))) + neg;
  arg1[2] = (*((f32 *) (((u8 *) temp_r3) + 0x2C))) + neg;
  arg2[0] = (*((f32 *) (((u8 *) temp_r3) + 0x24))) + (scale * temp_f0);
  arg2[1] = (*((f32 *) (((u8 *) temp_r3) + 0x28))) + (scale * temp_f0);
  arg2[2] = (*((f32 *) (((u8 *) temp_r3) + 0x2C))) + (scale * temp_f0);
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
extern "C" void ImpactEffect_calcHitAndNormal(void*, void*, void*, void*, void*, s32, s32, void* = 0, void* = 0);
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
    if (type == 0x47525550U) {
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
            ((u32*)&pos)[0] = ((u32*)((u8*)obj + 0x38))[0];
            ((u32*)&pos)[1] = ((u32*)((u8*)obj + 0x38))[1];
            ((u32*)&pos)[2] = ((u32*)((u8*)obj + 0x38))[2];
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
            ImpactEffect_calcHitAndNormal(*(void**)((u8*)arg0 + 0x30), &mtx, pos68, vecA, vecB,
                        *(s32*)((u8*)arg0 + 0x28), *(s32*)((u8*)arg0 + 0x2C), outHit, outN);
            if (PSVECDotProduct((Vec*)outN, (Vec*)outN) > lbl_805623AC) {
                up[0] = lbl_805622D0; up[1] = lbl_805622E0; up[2] = lbl_805622D0;
                fn_801B34DC(arg1, 0, (Vec*)outHit, (Vec*)outN, (Vec*)up, *(s32*)((u8*)arg0 + 0x20));
            }
        }
    } else if (type == 0x424F5820U) {
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
            ImpactEffect_calcHitAndNormal(*(void**)((u8*)arg0 + 0x30), r4, pos50, vecA2, vecB2, 0, -1, 0, 0);
        }
    } else if (type == 0x504F4C59U) {
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

extern "C" void* fn_801A2C9C(void* node) {
    /* Return a pointer to the embedded field at offset 0x44 of a collision/shape node. */
    return (u8*)node + 0x44;
}

extern "C" f32 fn_801A2CA4(void* object) {
    /* Return this collision shape's bounding radius (stored at +0x178). */
    return *(f32*)((u8*)object + 0x178);
}

extern "C" void fn_801A2CAC(void *shape) {
    extern s32 lbl_8055E598;
    extern void fn_801E3FC8(s32, s32, s32, f32);
    /* Matrix/translation setup via handle lbl_8055E598: pass the child
     * referenced at +0xC (its matrix at +0x24) and this shape's +0x24 scale. */
    s32 child = *(s32 *)((u8 *)shape + 0xC);
    fn_801E3FC8(child + 0x24, lbl_8055E598, child, *(f32 *)((u8 *)shape + 0x24));
}

extern char lbl_803337C8;
extern void fn_801E3FC8(s32, s32, s32, f32);
extern s32 lbl_8055E598;
__declspec(section ".data") extern char lbl_803337C8;
extern "C" void* fn_801A2CC0(void* object, s32 arg1, s32 swapBytes) {
    /* Initialize object (via fn_8019ECC4), set its vtable, and optionally byte-swap the two 4-byte fields at +0x24 and +0x28. */
    u8 byte24;
    u8 byte28;
    u8 byte25;
    u8 byte29;

    ((void(*)(void*,s32,s32))fn_8019ECC4)(object, arg1, swapBytes);
    *(void**)object = &lbl_803337C8;
    if (swapBytes != 0) {
        byte24 = *(u8*)((u8*)object + 0x24);
        byte25 = *(u8*)((u8*)object + 0x25);
        byte28 = *(u8*)((u8*)object + 0x28);
        byte29 = *(u8*)((u8*)object + 0x29);
        *(u8*)((u8*)object + 0x24) = *(u8*)((u8*)object + 0x27);
        *(u8*)((u8*)object + 0x27) = byte24;
        *(u8*)((u8*)object + 0x25) = *(u8*)((u8*)object + 0x26);
        *(u8*)((u8*)object + 0x26) = byte25;
        *(u8*)((u8*)object + 0x28) = *(u8*)((u8*)object + 0x2B);
        *(u8*)((u8*)object + 0x2B) = byte28;
        *(u8*)((u8*)object + 0x29) = *(u8*)((u8*)object + 0x2A);
        *(u8*)((u8*)object + 0x2A) = byte29;
    }
    return object;
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
        Abend_Panic(messageBase + 0x280, nodeType);
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
/* No-op stub in the shape/collision-node code: empty body, no calls and no state
 * touched, reachable only through a function pointer (e.g. a default virtual). */
extern "C" void fn_801A2EC8(void) {

}

#pragma scheduling on
extern "C" void fn_801A2ECC(void *arg0, void *arg1, void *arg2) {
    f32 corners[24];
    f32 tmp[3];
    f32 *lo = (f32 *)arg1;
    f32 *hi = (f32 *)arg2;
    f32 b = *(f32 *)((u8 *)arg0 + 0x28);
    f32 c = *(f32 *)((u8 *)arg0 + 0x24) + b;
    const f32 *m = *(const f32 **)((u8 *)arg0 + 0xC);
    f32 *p, *q;
    int i;
    corners[0] = -c; corners[1] = -c; corners[2] = -b;
    corners[3] = -c; corners[4] = -c; corners[5] = b;
    corners[6] = -c; corners[7] = c; corners[8] = -b;
    corners[9] = -c; corners[10] = c; corners[11] = b;
    corners[12] = c; corners[13] = -c; corners[14] = -b;
    corners[15] = c; corners[16] = -c; corners[17] = b;
    corners[18] = c; corners[19] = c; corners[20] = -b;
    corners[21] = c; corners[22] = c; corners[23] = b;
    lo[0] = m[9]; lo[1] = m[10]; lo[2] = m[11];
    hi[0] = m[9]; hi[1] = m[10]; hi[2] = m[11];
    p = corners;
    q = p;
    for (i = 0; i < 8; i++, p += 3, q += 3) {
        m = *(const f32 **)((u8 *)arg0 + 0xC);
        if (tmp == q) {
            f32 x, y, z;
            f32 m0, m3, m6, m1, m4, m7, m2, m5, m8;
            m3 = m[3]; y = q[1]; m4 = m[4]; m5 = m[5];
            m0 = m[0]; x = q[0]; m1 = m[1]; m2 = m[2];
            m6 = m[6]; z = q[2]; m7 = m[7]; m8 = m[8];
            f32 t0 = z * m6 + (x * m0 + y * m3);
            f32 t1 = z * m7 + (x * m1 + y * m4);
            f32 t2 = z * m8 + (x * m2 + y * m5);
            tmp[0] = t0;
            tmp[1] = t1;
            tmp[2] = t2;
        } else {
            f32 m3, x, m0, y, m6, z, m4, m1, m7, m5, m2, m8;
            m3 = m[3];
            y = q[1];
            m0 = m[0];
            x = q[0];
            m6 = m[6];
            z = q[2];
            tmp[0] = x * m0 + y * m3 + z * m6;
            m4 = m[4];
            m1 = m[1];
            m7 = m[7];
            tmp[1] = x * m1 + y * m4 + z * m7;
            m5 = m[5];
            m2 = m[2];
            m8 = m[8];
            tmp[2] = x * m2 + y * m5 + z * m8;
        }
        tmp[0] = tmp[0] + m[9];
        tmp[1] = tmp[1] + m[10];
        tmp[2] = tmp[2] + m[11];
        lo[0] = (lo[0] < tmp[0]) ? lo[0] : tmp[0];
        lo[1] = (lo[1] < tmp[1]) ? lo[1] : tmp[1];
        lo[2] = (lo[2] < tmp[2]) ? lo[2] : tmp[2];
        f32 first = tmp[0];
        f32 upper = hi[0];
        hi[0] = (upper > first) ? upper : first;
        hi[1] = (hi[1] > tmp[1]) ? hi[1] : tmp[1];
        hi[2] = (hi[2] > tmp[2]) ? hi[2] : tmp[2];
    }
}
extern "C" void fn_801A3174(void *shape) {
    /* Forward to fn_801E3FC8 (matrix/translation setup via handle lbl_8055E598):
     * the child referenced at +0xC (its +0x24 position) and a scale formed by
     * adding the two floats at +0x24 and +0x28 of this shape. */
    ((void (*)(s32, s32, f32))fn_801E3FC8)(*(s32*)((u8*)shape + 0xC) + 0x24, lbl_8055E598, *(f32*)((u8*)shape + 0x24) + *(f32*)((u8*)shape + 0x28));
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
    *(s32*)((u8*)arg0 + 4) = 0;
    *(void**)arg0 = lbl_80333778;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(f32*)((u8*)arg0 + 0x10) = farg0;
    *(f32*)((u8*)arg0 + 0x14) = farg1;
    *(s32*)((u8*)arg0 + 0x18) = 0x504F4C59;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(s32*)((u8*)arg0 + 0x20) = 100;
    *(s32*)((u8*)arg0 + 0xDC) = 0;
    *(s32*)((u8*)arg0 + 0xBC) = arg3;
    u8 *dst = (u8*)arg0;
    u8 *src = (u8*)arg2;
    for (s32 i = 0; i < *(s32*)((u8*)arg0 + 0xBC); i++) {
        s32 t0 = *(volatile s32*)src;
        u32 t1 = *(volatile s32*)(src + 4);
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

struct Obj324C {
    void *vtbl;
    int f4, f8, fc;
    f32 f10, f14;
    int f18, f1c, f20;
    f32 f24, f28, f2c, f30, f34, f38;
    u8 pad[0xBC - 0x3C];
    int bc;
};
#pragma use_lmw_stmw off
extern "C" void *fn_801A324C(void *arg0, int arg1, void *arg2, f32 farg0, f32 farg1) {
    register TagList *list;
    unsigned int i;
    TagNode *child;
    TagNode *node;
    *(int *)((u8 *)arg0 + 0xC) = arg1;
    *(int *)((u8 *)arg0 + 4) = 0;
    *(int *)((u8 *)arg0 + 8) = 0;
    u8 *self = (u8 *)arg0;
    *(f32 *)(self + 0x10) = farg0;
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
            rec = self + idx * 0x10;
            *(int *)(self + 0xBC) = idx + 1;
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
    f32 sp14[3];
    f32 sp8[3];
    f32 *mat = box->matrix;
    if (&sp8[0] == &box->min.x) {
        f32 x, y, z;
        f32 m0, m3, m6, m1, m4, m7, m2, m5, m8;
        m3 = mat[3]; m4 = mat[4]; m5 = mat[5];
        m0 = mat[0]; m1 = mat[1]; m2 = mat[2];
        m6 = mat[6]; m7 = mat[7]; m8 = mat[8];
        x = box->min.x; y = box->min.y; z = box->min.z;
        f32 t0 = z * m6 + (x * m0 + y * m3);
        f32 t1 = z * m7 + (x * m1 + y * m4);
        f32 t2 = z * m8 + (x * m2 + y * m5);
        sp8[0] = t0; sp8[1] = t1; sp8[2] = t2;
    } else {
        f32 nv6 = mat[6];
        {
            f32 m6, m0, m3;
            m3 = mat[3];
            m0 = mat[0];
            m6 = nv6;
            sp8[0] = (box->min.z * m6) + ((box->min.x * m0) + (box->min.y * m3));
        }
        f32 nv7 = mat[7];
        {
            f32 m7, m1, m4;
            m4 = mat[4];
            m1 = mat[1];
            m7 = nv7;
            sp8[1] = (box->min.z * m7) + ((box->min.x * m1) + (box->min.y * m4));
        }
        f32 nv8 = mat[8];
        {
            f32 m8, m2, m5;
            m5 = mat[5];
            m2 = mat[2];
            m8 = nv8;
            sp8[2] = (box->min.z * m8) + ((box->min.x * m2) + (box->min.y * m5));
        }
    }
    sp8[0] += mat[9]; sp8[1] += mat[10]; sp8[2] += mat[11];
    f32 *mat2 = *(f32 * volatile *)((u8 *)box + 0xC);
    if (&sp14[0] == &box->max.x) {
        f32 x, y, z;
        f32 m0, m3, m6, m1, m4, m7, m2, m5, m8;
        m3 = mat2[3]; m4 = mat2[4]; m5 = mat2[5];
        m0 = mat2[0]; m1 = mat2[1]; m2 = mat2[2];
        m6 = mat2[6]; m7 = mat2[7]; m8 = mat2[8];
        x = box->max.x; y = box->max.y; z = box->max.z;
        f32 t0 = z * m6 + (x * m0 + y * m3);
        f32 t1 = z * m7 + (x * m1 + y * m4);
        f32 t2 = z * m8 + (x * m2 + y * m5);
        sp14[0] = t0; sp14[1] = t1; sp14[2] = t2;
    } else {
        f32 nv6 = mat2[6];
        {
            f32 m6, m0, m3;
            m3 = mat2[3];
            m0 = mat2[0];
            m6 = nv6;
            sp14[0] = (box->max.z * m6) + ((box->max.x * m0) + (box->max.y * m3));
        }
        f32 nv7 = mat2[7];
        {
            f32 m7, m1, m4;
            m4 = mat2[4];
            m1 = mat2[1];
            m7 = nv7;
            sp14[1] = (box->max.z * m7) + ((box->max.x * m1) + (box->max.y * m4));
        }
        f32 nv8 = mat2[8];
        {
            f32 m8, m2, m5;
            m5 = mat2[5];
            m2 = mat2[2];
            m8 = nv8;
            sp14[2] = (box->max.z * m8) + ((box->max.x * m2) + (box->max.y * m5));
        }
    }
    sp14[0] += mat2[9]; sp14[1] += mat2[10]; sp14[2] += mat2[11];
    f32 var_f4 = sp8[0];
    arg2->x = var_f4;
    arg2->y = sp8[1];
    arg2->z = sp8[2];
    arg1->x = var_f4;
    arg1->y = arg2->y;
    arg1->z = arg2->z;
    {
        f64 wide = var_f4;
        f32 p = (f32)wide; f32 m = sp14[0];
        p = (p < m) ? m : p;
        arg1->x = p;
    }
    {
        f32 m = sp14[1]; f32 p = arg1->y;
        p = (p < m) ? m : p;
        arg1->y = p;
    }
    {
        f32 m = sp14[2]; f32 p = arg1->z;
        p = (p < m) ? m : p;
        arg1->z = p;
    }
    {
        f32 m = sp14[0]; f32 p = arg2->x;
        p = (p > m) ? m : p;
        arg2->x = p;
    }
    {
        f32 m = sp14[1]; f32 p = arg2->y;
        p = (p > m) ? m : p;
        arg2->y = p;
    }
    {
        f32 m = sp14[2]; f32 p = arg2->z;
        p = (p > m) ? m : p;
        arg2->z = p;
    }
    f32 pad = lbl_80562380;
    arg2->x = arg2->x + pad;
    arg2->z = arg2->z + pad;
    arg1->x = arg1->x - pad;
    arg1->z = arg1->z - pad;
}
#pragma fp_contract on
#pragma scheduling invalid_target
extern "C" f32 fn_801A3880(s32 self) {
    /* Return the length of the larger of the two basis vectors at offsets 0x30 and 0x24. */
    f32 sqLen1 = PSVECDotProduct((Vec *)(self + 0x30), (Vec *)(self + 0x30));
    f32 sqLen2 = PSVECDotProduct((Vec *)(self + 0x24), (Vec *)(self + 0x24));
    f32 maxSqLen = sqLen2 > sqLen1 ? sqLen2 : sqLen1;
    return (f32)fn_8002F234(maxSqLen);
}
#pragma fp_contract off
#pragma scheduling on
extern float lbl_805622D0, lbl_805622DC, lbl_805623C0;
extern float PSVECDotProduct(float *, void *);
extern int fn_8019A788(void *, int, void *, void *, int, int, float, float, float);
#pragma fp_contract off
#pragma scheduling on
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
        f32 cur;
        f32 a;
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
                f32 *m = (f32 *)(owner + 0x3c);
                while (node != 0) {
                    f32 *v = (f32 *)(node + 4);
                    if (q == v) {
                        f32 y = v[1], x = v[0], zz = v[2];
                        f32 rx = y * m[3] + (x * m[0] + zz * m[6]);
                        f32 ry = y * m[4] + (x * m[1] + zz * m[7]);
                        f32 rz = y * m[5] + (x * m[2] + zz * m[8]);
                        q[0] = rx; q[1] = ry; q[2] = rz;
                    } else {
                        q[0] = (m[3] * v[1] + m[0] * v[0]) + m[6] * v[2];
                        q[1] = (m[4] * v[1] + m[1] * v[0]) + m[7] * v[2];
                        q[2] = (m[5] * v[1] + m[2] * v[0]) + m[8] * v[2];
                    }
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
extern "C" void fn_801A3BE0(void *arg0, void *arg1)
{
  f32 pos[3];
  f32 v[3];
  f32 out[3];
  f32 *entry = (f32 *) (((u8 *) arg0) + 0x3C);
  const f32 *m0 = *((const f32 **) (((u8 *) arg0) + 0xC));
  s32 g = lbl_8055E598;
  s32 i = 0;
  u32 t0 = ((u32 *) m0)[9];
  u32 t1 = ((u32 *) m0)[10];
  ((u32 *) pos)[0] = t0;
  ((u32 *) pos)[1] = t1;
  ((u32 *) pos)[2] = ((u32 *) m0)[11];
  for (; i < *((s32 *) (((u8 *) arg0) + 0xBC)); entry += 4, i++)
  {
    f32 w = entry[3];
    v[0] = entry[0] * w;
    v[1] = entry[1] * w;
    v[2] = entry[2] * w;
    const f32 *m = *((const f32 **) (((u8 *) arg0) + 0xC));
    if (out == v)
    {
      float m10 = m[3];
      float m00 = m[0];
      float m11 = m[4];
      float m01 = m[1];
      float m20 = m[6];
      float m21 = m[7];
      float m12 = m[5];
      float m02 = m[2];
      float m22 = m[8];
      float x = v[0];
      float y = v[1];
      float z = v[2];
      out[0] = (z * m20) + ((x * m00) + (y * m10));
      out[1] = (z * m21) + ((x * m01) + (y * m11));
      out[2] = (z * m22) + ((x * m02) + (y * m12));
    }
    else
    {
      float m10 = m[3];
      float m00 = m[0];
      float m20 = m[6];
      float x = v[0];
      float y = v[1];
      float z = v[2];
      out[0] = (z * m20) + ((x * m00) + (y * m10));
      float m11 = m[4];
      float m01 = m[1];
      float m21 = m[7];
      out[1] = (z * m21) + ((x * m01) + (y * m11));
      float m12 = m[5];
      float m02 = m[2];
      float m22 = m[8];
      out[2] = (z * m22) + ((x * m02) + (y * m12));
    }
    out[0] += m[9];
    out[1] += m[10];
    out[2] += m[11];
    fn_801E41D8(pos, out, g, lbl_80562314);
  }

}

#pragma push
#pragma small_data off
extern s32 lbl_80333728;
extern "C" void *fn_801A3DAC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Vec { f32 x, y, z; };
    void *object;
    Vec *vectors;
    volatile Vec maxSpill, minSpill;
    register f32 init = lbl_805622E0;
    register s32 offset;
    register s32 i;
    f32 var_f1;
    f32 var_f3;
    f32 var_f3_2;
    f32 var_f4;
    f32 var_f5;
    f32 var_f6;
    f32 tp;
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
        void *obj = *(void **)((u8 *)arg0 + 0x24);
        Vec *base = (Vec *)*(void **)((u8 *)obj + 0x08);
        Vec *point = (Vec *)((u8 *)base + offset);
        var_f3 = *(volatile f32 *)((u8 *)arg0 + 0x30);
        tp = point->z;
        var_f3 = var_f3 < tp ? var_f3 : tp;
        tp = point->y;
        var_f4 = *(volatile f32 *)((u8 *)arg0 + 0x2C);
        var_f4 = var_f4 < tp ? var_f4 : tp;
        tp = point->x;
        var_f5 = *(volatile f32 *)((u8 *)arg0 + 0x28);
        var_f5 = var_f5 < tp ? var_f5 : tp;
        var_f6 = *(volatile f32 *)((u8 *)arg0 + 0x3C);
        *(volatile f32 *)((u8 *)arg0 + 0x28) = (f32)(f64)var_f5;
        *(volatile f32 *)((u8 *)arg0 + 0x2C) = (f32)(f64)var_f4;
        *(volatile f32 *)((u8 *)arg0 + 0x30) = (f32)(f64)var_f3;
        maxSpill.x = var_f5; maxSpill.y = var_f4; maxSpill.z = var_f3;
        Vec *minPoint = (Vec *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x24) + 0x08) + offset);
        tp = minPoint->z;
        var_f6 = var_f6 > tp ? var_f6 : tp;
        tp = minPoint->y;
        var_f3_2 = *(volatile f32 *)((u8 *)arg0 + 0x38);
        var_f3_2 = var_f3_2 > tp ? var_f3_2 : tp;
        tp = minPoint->x;
        var_f1 = *(volatile f32 *)((u8 *)arg0 + 0x34);
        var_f1 = var_f1 > tp ? var_f1 : tp;
        minSpill.x = var_f1; minSpill.y = var_f3_2; minSpill.z = var_f6;
        *(volatile f32 *)((u8 *)arg0 + 0x34) = (f32)(f64)var_f1;
        *(volatile f32 *)((u8 *)arg0 + 0x38) = (f32)(f64)var_f3_2;
        *(volatile f32 *)((u8 *)arg0 + 0x3C) = (f32)(f64)var_f6;
        offset += 0x0C;
        ++i;
    }
    return arg0;
}
#pragma pop
extern "C" void fn_801CFA48(void*);
__declspec(section ".data") extern s32 lbl_80333728;
/* Initialize a SeqHeap object: set its vtable and, when requested, set up the embedded heap at +0x40. */
extern "C" void* fn_801A3F5C(void* thisPtr, s32 arg1, s32 initEmbeddedHeap) {
    ((void(*)(void*,s32,s32))fn_8019ECC4)(thisPtr, arg1, initEmbeddedHeap);
    *(void**)thisPtr = &lbl_80333728;
    if (initEmbeddedHeap != 0) {
        *(void**)((u8*)thisPtr + 0x24) = (u8*)thisPtr + 0x40;
        fn_801CFA48((u8*)thisPtr + 0x40);
    }
    return thisPtr;
}

#pragma push
#pragma small_data off
extern "C" void *__dt__Q28PSSystem7SeqHeapFv_801A3FB8(void *thisPtr, s32 deleteFlag) {
    /* PSSystem::SeqHeap destructor: install vtable, destroy owned heap object, then optionally free. */
    if (thisPtr != 0) {
        *(void **)thisPtr = &lbl_80333728;
        ((void (*)(void *))fn_801CFF14)(*(void **)((u8 *)thisPtr + 0x24));
        if (deleteFlag > 0)
            ((void (*)(void *))fn_80128668)(thisPtr);
    }
    return thisPtr;
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

#pragma scheduling reset
extern "C" s32 fn_801A40F8(void *arg0, f32 * __restrict arg1, f32 *arg2, s32 arg3, f32 *arg4) {
    f32 stack[9];
    f32 ix = arg1[0];
    f32 iy = arg1[1];
    f32 *m = (f32 *)*(void **)((u8 *)arg0 + 0xC);
    f32 dx = ix - m[9];
    f32 iz = arg1[2];
    stack[6] = dx;
    f32 dy = iy - m[10];
    stack[7] = dy;
    f32 dz = iz - m[11];
    stack[8] = dz;
    f32 m8, m7, m6, m5, m4, m3, m2, m1, m0;
    m0 = m[0];
    m1 = m[1];
    m2 = m[2];
    m3 = m[3];
    m4 = m[4];
    m5 = m[5];
    m6 = m[6];
    m7 = m[7];
    m8 = m[8];
    stack[6] = (dz * m2) + ((dy * m1) + (dx * m0));
    stack[7] = (dz * m5) + ((dy * m4) + (dx * m3));
    stack[8] = (dz * m8) + ((dy * m7) + (dx * m6));
    f32 *m2p = (f32 *)*(void **)((u8 *)arg0 + 0xC);
    if (&stack[3] == arg2) {
        f32 a1 = m2p[1];
        f32 y = arg2[1];
        f32 a0 = m2p[0];
        f32 x = arg2[0];
        f32 a4 = m2p[4];
        f32 a3 = m2p[3];
        f32 a7 = m2p[7];
        f32 z = arg2[2];
        f32 a6 = m2p[6];
        f32 a2, a5;
        a2 = m2p[2];
        a5 = m2p[5];
        f32 a8 = m2p[8];
        stack[3] = (z * a2) + ((x * a0) + (y * a1));
        stack[4] = (z * a5) + ((x * a3) + (y * a4));
        stack[5] = (z * a8) + ((x * a6) + (y * a7));
    } else {
        {
            f32 c2, c0, c1;
            c1 = m2p[1];
            c0 = m2p[0];
            c2 = m2p[2];
            stack[3] = (arg2[2] * c2) + ((arg2[0] * c0) + (arg2[1] * c1));
        }
        {
            f32 c5, c3, c4;
            c4 = m2p[4];
            c3 = m2p[3];
            c5 = m2p[5];
            stack[4] = (arg2[2] * c5) + ((arg2[0] * c3) + (arg2[1] * c4));
        }
        {
            f32 c8, c6, c7;
            c7 = m2p[7];
            c6 = m2p[6];
            c8 = m2p[8];
            stack[5] = (arg2[2] * c8) + ((arg2[0] * c6) + (arg2[1] * c7));
        }
    }
    typedef s32 (*Call)(s32, f32 *, f32 *, s32, f32 *);
    if (((Call)MeshRayCast_801CF828)(*(s32 *)((u8 *)arg0 + 0x24), &stack[6], &stack[3], arg3, &stack[0]) != 0) {
        f32 *m3 = (f32 *)*(void **)((u8 *)arg0 + 0xC);
        if (arg4 == &stack[0]) {
            f32 b3 = m3[3];
            f32 y = stack[1];
            f32 b4 = m3[4];
            f32 b5 = m3[5];
            f32 b0 = m3[0];
            f32 x = stack[0];
            f32 b1 = m3[1];
            f32 b2 = m3[2];
            f32 b6 = m3[6];
            f32 z = stack[2];
            f32 b7 = m3[7];
            f32 b8 = m3[8];
            arg4[0] = (z * b6) + ((x * b0) + (y * b3));
            arg4[1] = (z * b7) + ((x * b1) + (y * b4));
            arg4[2] = (z * b8) + ((x * b2) + (y * b5));
        } else {
            {
                f32 d6, d0, d3;
                d3 = m3[3];
                d0 = m3[0];
                d6 = m3[6];
                arg4[0] = (stack[2] * d6) + ((stack[0] * d0) + (stack[1] * d3));
            }
            {
                f32 d7, d1, d4;
                d4 = m3[4];
                d1 = m3[1];
                d7 = m3[7];
                arg4[1] = (stack[2] * d7) + ((stack[0] * d1) + (stack[1] * d4));
            }
            {
                f32 d8, d2, d5;
                d5 = m3[5];
                d2 = m3[2];
                d8 = m3[8];
                arg4[2] = (stack[2] * d8) + ((stack[0] * d2) + (stack[1] * d5));
            }
        }
        return 1;
    }
    return 0;
}
extern "C" void fn_801A442C(void* source, void* outFirst, void* outSecond) {
    /* Copy the two 3D vectors at offsets 0x28 and 0x34 of source into outFirst and outSecond. */
    f32 firstZ, firstY, firstX, secondZ, secondY, secondX;
    firstX = *(f32*)((u8*)source + 0x28);
    firstY = *(f32*)((u8*)source + 0x2C);
    firstZ = *(f32*)((u8*)source + 0x30);
    *(f32*)((u8*)outFirst + 0x0) = firstX;
    secondX = *(f32*)((u8*)source + 0x34);
    *(f32*)((u8*)outFirst + 0x4) = firstY;
    secondY = *(f32*)((u8*)source + 0x38);
    *(f32*)((u8*)outFirst + 0x8) = firstZ;
    secondZ = *(f32*)((u8*)source + 0x3C);
    *(f32*)((u8*)outSecond + 0x0) = secondX;
    *(f32*)((u8*)outSecond + 0x4) = secondY;
    *(f32*)((u8*)outSecond + 0x8) = secondZ;
}

#pragma scheduling invalid_target
extern "C" f32 fn_801A4460(s32 arg0) {
    f32 firstSqLen = PSVECDotProduct((Vec *)(arg0 + 0x34), (Vec *)(arg0 + 0x34));
    f32 secondSqLen = PSVECDotProduct((Vec *)(arg0 + 0x28), (Vec *)(arg0 + 0x28));
    f32 maxSqLen = secondSqLen > firstSqLen ? secondSqLen : firstSqLen;
    /* Returns the length of the larger of the two basis vectors at offsets 0x34 and 0x28. */
    return (f32)fn_8002F234(maxSqLen);
}
#pragma scheduling on
/* Debug-draw callback: forwards the holder's drawable/mesh pointer (+0x24) and
 * its transform matrix (+0xC, or null for identity) to fn_801CFF18. */
extern "C" void fn_801A44C4(void* object) {
    fn_801CFF18(*(s32*)((u8*)object + 0x24), *(s32*)((u8*)object + 0xC));
}

extern "C" void fn_801A44D4(void* arg0) {
    /* Call fn_801A49FC for each object pointer in the list at [count, arrayPtr]. */
    register s32* list = (s32*)arg0;
    register s32 byteOffset = 0;
    register s32 index = 0;
    goto check;
loop:
    fn_801A49FC(*(s32*)((u8*)list[1] + byteOffset));
    byteOffset += 4;
    index++;
check:
    if (index < list[0]) goto loop;
}

#pragma scheduling invalid_target
extern "C" void fn_801A4538(void* resource) {
    /* Release callback for a loaded SOLB resource: run the release path again with the list-notification callback (fn_801A44D4), which notifies every object in the resource's list. */
    fn_8012C4E4(resource, &fn_801A44D4, 0);
}

extern "C" s32 getResourceData(s32, s32*, s32, s32, s32, s32);
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
#pragma push
#pragma dont_inline off
extern "C" void* fn_801A4548(s32 arg0) {
    s32 size;
    u8 ok = 0;
    Fn801A4548Hdr* h = (Fn801A4548Hdr*)((s32 (*)(s32, s32, s32*, s32, s32, s32))getResourceData)(arg0, 0x534F424C, &size, 0, 0, (s32)&ok);
    if (h && ok) {
        s32* lp = (s32*)&h->list;
        Fn801A4548Swap4((u8*)h);
        Fn801A4548Swap4((u8*)h+8);
        Fn801A4548Swap4((u8*)lp);
        Fn801A4548Swap4((u8*)h+12);
        Fn801A4548Swap4((u8*)h+16);
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
        h->fn=(void*)fn_801A4548;
    }
    return h;
}
#pragma pop
extern "C" void fn_801A4768(s32 *value, s32 delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    s32 cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

/* Relocate a stored offset: add base to *field when it is nonzero (0 is left as null). */
extern "C" void fn_801A4780(s32* field, s32 base) {
    s32 offset = *field;
    if (offset != 0) {
        *field = offset + base;
    }
}

extern "C" void fn_801A4798(s32* pOffset, s32 base) {
    /* Relocate a stored offset: add base to *pOffset, but leave a zero (null) offset untouched. */
    s32 offset = *pOffset;
    if (offset != 0) {
        *pOffset = offset + base;
    }
}

/* Relocate a stored offset into a pointer by adding the resource base address;
 * a zero offset (null entry) is left unchanged. */
extern "C" void fn_801A47B0(s32* offsetPtr, s32 base) {
    s32 offset = *offsetPtr;
    if (offset != 0) {
        *offsetPtr = offset + base;
    }
}

#pragma push
#pragma unroll off
/* CollisionGroup::enableAll: mark every solid in the group active by setting
 * the byte at +0x40 of each entry pointer in the group's array to 1.
 * The group holds a count at +0 and a pointer to the solid array at +4. */
extern "C" void fn_801A47C8(void* group) {
    s32 offset;
    s32 index;
    index = 0;
    offset = 0;
    while (index < *(s32*)group) {
        void** solids = *(void***)((u8*)group + 4);
        index += 1;
        void* solid = *(void**)((u8*)solids + offset);
        *(u8*)((u8*)solid + 0x40) = 1;
        offset += 4;
    }
}
#pragma pop
extern "C" void fn_801A47FC(void* group) {
    /* Iterates a group's entries and calls fn_801A49E8 on each, if the group is non-null. */
    register s32* groupData = (s32*)group;
    if (groupData == 0) {
        return;
    }
    register s32 counter;
    register s32 byteOffset;
    byteOffset = 0;
    counter = 0;
    goto check;
loop:
    fn_801A49E8((void*)(*(s32*)((u8*)groupData[1] + counter)));
    counter += 4;
    byteOffset++;
check:
    if (byteOffset < groupData[0]) goto loop;
}

#pragma opt_tail_call on
extern "C" void fn_801A4868(void* instance, u8 state) {
    /* If the instance's active/state byte at +0x40 changes, post an event (id 12) carrying its value at +0x38 and the new state, then store it. */
    if (*(u8*)((u8*)instance + 0x40) != state) {
        struct Local {
            s32 value;
            u8 type;
        } local;
        local.value = *(s32*)((u8*)instance + 0x38);
        local.type = state;
        fn_801796EC(12, (s32*)&local.value, 8);
        *(u8*)((u8*)instance + 0x40) = state;
    }
}

extern "C" void fn_801A48C8(void* owner) {
    /* Invoke the fifth virtual method (vtable slot 0x18) on the interface object stored at +0x48 of owner, passing the strings "dyno" and "unknown". */
    struct VTable {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void notify(void*, void*);
    };
    VTable* iface = *(VTable**)((u8*)owner + 0x48);
    iface->notify(&lbl_8055A508, &lbl_8055A510);
}

extern "C" void fn_801EA1E0(void*, s32, f32, f32);
void fn_801A48E4(void* arg0) {
    struct Matrix { virtual void v0(); virtual void update(); };
    u8* obj = (u8*)arg0;
    s32 shapeType;
    void* shape;
    f32 scale;
    f32 shapeScale;
    f32 scaledOffset;
    f32 posX;
    f32 posY;
    f32 posZ;
    volatile f32 out[3];

    /* Mark object dirty, update its attached shape, and recompute world position/orientation for sphere (0x53504852) or tube (0x54554245) shapes. */
    *(u8*)(obj + 0x40) = 1;
    ((Matrix*)*(void**)(obj + 0x3C))->update();
    shapeType = *(s32*)((u8*)*(void**)(obj + 0x3C) + 0x18);
    if (shapeType == 0x53504852) {
        shape = *(void**)(obj + 0x3C);
        fn_801EA1E0((u8*)shape + 0x38, 0, *(f32*)((u8*)shape + 0x34), *(f32*)((u8*)shape + 0x3C));
        fn_801EA1E0(obj + 0x2C, 0, *(f32*)(obj + 0x28), *(f32*)(obj + 0x30));
    }
    if (shapeType == 0x54554245) {
        scale = *(f32*)(obj + 0x20) > lbl_805622D0 ? lbl_805622DC : lbl_805622E0;
        shapeScale = *(f32*)((u8*)*(void**)(obj + 0x3C) + 0x28);
        scaledOffset = scale * shapeScale;
        posX = *(f32*)(obj + 0x28) + *(f32*)(obj + 0x1C) * scaledOffset;
        posY = *(f32*)(obj + 0x2C) + *(f32*)(obj + 0x20) * scaledOffset;
        posZ = *(f32*)(obj + 0x30) + *(f32*)(obj + 0x24) * scaledOffset;
        out[0] = posX;
        out[1] = posY;
        out[2] = posZ;
        fn_801EA1E0(obj + 0x2C, 0, posX, posZ);
    }
}

/* If the solid/instance has a notify interface at +0x48, dispatch it to every registered listener (fn_801D0650). */
void fn_801A49E8(void* solid) {
    if (*(s32*)((u8*)solid + 0x48) != 0) {
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
void fn_801A49FC(s32 solid) {
    /* If the solid/instance has a notify interface at +0x48, dispatch it to every listener in the first dispatch list (fn_801D06C4). */
    if (*(s32*)((u8*)solid + 0x48) != 0) {
        fn_801D06C4();
    }
}

#pragma scheduling invalid_target
/* Sound-event trigger hit by a vehicle: when the trigger instance is active
 * (+0x40), runs its sound event (fn_801D2414 = SoeventTrigger_Update, which
 * takes instance/position/object straight from r3-r5) and, if it has
 * listeners (+0x48), tells them too (fn_801D0738). */
extern "C" void fn_801A4A10(s32 instance, s32 position, s32 object, s32 extra) {
    if (*(u8*)((u8*)instance + 0x40) != 0) {
        fn_801D2414();
        if (*(s32*)((u8*)instance + 0x48) != 0) {
            fn_801D0738((void*)instance, (void*)position, (void*)object, (void*)extra);
        }
    }
}
#pragma scheduling on
extern "C" void* fn_801A4A8C(void* arg0, s32 arg1, s32 arg2, void* arg3, u32* arg4, s32 arg5, s32 arg6) {
    struct VTable2C {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void Call(void*, s32, s32);
    };
    s32 t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    void* vtable = lbl_803336F8;
    t0 = *(volatile s32*)((char*)arg4 + 0x00);
    t1 = *(volatile s32*)((char*)arg4 + 0x04);
    t2 = *(volatile s32*)((char*)arg4 + 0x08);
    t3 = *(volatile s32*)((char*)arg4 + 0x0C);
    t4 = *(volatile s32*)((char*)arg4 + 0x10);
    t5 = *(volatile s32*)((char*)arg4 + 0x14);
    t6 = *(volatile s32*)((char*)arg4 + 0x18);
    t8 = *(volatile s32*)((char*)arg4 + 0x20);
    t7 = *(volatile s32*)((char*)arg4 + 0x1C);
    t9 = *(volatile s32*)((char*)arg4 + 0x24);
    t10 = *(volatile s32*)((char*)arg4 + 0x28);
    t11 = *(volatile s32*)((char*)arg4 + 0x2C);
    *(s32*)((u8*)arg0 + 0x38) = arg1;
    *(s32*)((u8*)arg0 + 0x48) = arg5;
    *(void**)((u8*)arg0 + 0x3C) = arg3;
    *(s32*)((u8*)arg0 + 0x34) = arg2;
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
    *(void**)arg0 = vtable;
    ((VTable2C*)arg3)->Call(arg0, arg2, (s32)arg3);
    fn_801A48E4(arg0);
    return arg0;
}

#pragma push
#pragma dont_inline off
#pragma use_lmw_stmw off
extern "C" void* fn_801A4B5C(void* arg0, s32 arg1, void* arg2) {
    u8* p = (u8*)arg0;
    u8* q = p + 4;
    s32 magic;
    *(void**)arg0 = lbl_803336F8;
    if (arg1) {
        s32 i;
        Swap4(p + 0x34);
        Swap4(p + 0x38);
        for (i = 0; i < 2; i++) {
            Swap4(q); Swap4(q + 4); Swap4(q + 8);
            Swap4(q + 0xC); Swap4(q + 0x10); Swap4(q + 0x14);
            q += 0x18;
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
#pragma pop
extern "C" void fn_801A4E28(void) {
    /* Static initializer: load the "track.msh" mesh resource and cache its pointer in trackMesh. */
    trackMesh = fn_801CFEAC(&lbl_803336EC[0]);
}
#pragma pop
/* Release the global subsystem handle trackMesh if set, then clear it. */
extern "C" void fn_801A4E54(void) {
    if (trackMesh != 0) {
        ((void (*)(s32))fn_801CFF14)(trackMesh);
        trackMesh = 0;
    }
}

extern "C" void fn_801D0650(void);
extern s32 trackMesh;
extern void fn_801CFF14(void);
extern s32 MeshRayCast_801CF828(s32, s32, s32, s32, s32);
/* Test the global object for a hit with the given parameters; on hit, store result code 0x6E and return 1. */
extern "C" s32 fn_801A4E88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    if ((trackMesh != 0) && (MeshRayCast_801CF828(trackMesh, arg0, arg1, arg2, arg3) != 0)) {
        *arg4 = 0x6E;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801A4F00(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_801A4F40(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_801A4F80(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_801A4FC0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_801A5000(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* If ptr is set and count is positive, free the object (fn_80128668 receives
 * ptr in r3); always return ptr unchanged. */
extern "C" s32 fn_801A5040(s32 ptr, s32 count) {
    if (ptr != 0 && count > 0) {
        fn_80128668();
    }
    return ptr;
}

extern "C" s32 fn_801A5080(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* If ptr is set and count is positive, free the object (fn_80128668 receives
 * ptr in r3); always return ptr unchanged. */
extern "C" s32 fn_801A50C0(s32 ptr, s32 count) {
    if (ptr != 0 && count > 0) {
        fn_80128668();
    }
    return ptr;
}

/* Returns the object's collision radius, the float stored at +0x24. */
extern "C" f32 fn_801A5100(void *object) {
    return ((f32 *)object)[0x24 / 4];
}

extern "C" void fn_801A5108(void* container) {
    /* Clear this container's active index at +0x180 to -1 (no selection). */
    *(s32*)((u8*)container + 0x180) = -1;
}

extern "C" f32 fn_801A5114(void *object) {
    /* Return the floating-point field at offset 0x30 of object. */
    return ((f32 *)object)[0x30 / 4];
}

extern "C" f32 fn_801A511C(void *object) {
    /* Return the floating-point field at offset 0x24 of object. */
    return ((f32 *)object)[0x24 / 4];
}

extern "C" float fn_801A5124(void* object) {
    /* Return the floating-point field at offset 0x28 of object. */
    return *(float*)((char*)object + 0x28);
}

/* Default vtable method returning the constant 0. */
extern "C" s32 fn_801A512C(void) {
    return 0;
}

extern "C" s32 fn_801A5134(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Getter: return the notify/listener pointer at offset 0x48 of the solid or
 * instance (nonzero means it has a listener interface to dispatch to). */
extern "C" s32 fn_801A5174(void* object) {
    return *(s32*)((u8*)object + 0x48);
}

/* Return the address of the sub-object embedded at +0x28 of the given object. */
extern "C" s32 fn_801A517C(s32 object) {
    return object + 0x28;
}

/* Getter: return the byte flag at offset 0x40 of the given object. */
extern "C" u8 fn_801A5184(void *object) { return *((u8*)object + 0x40); }

extern "C" void fn_801A4868(void*, u8);

/* Zero-argument forwarder to the instance-state change function fn_801A4868.
 * The original calls it through a void(*)() cast, so the instance/state
 * arguments are whatever the caller left in the argument registers. */
extern "C" void fn_801A518C(void) {
    ((void (*)(void))fn_801A4868)();
}

extern "C" void fn_801A5190(void* owner) {
    /* Invoke the slot-0x40 hook on the sub-object held at +0x3C of the owner. */
    VTab19* part = *(VTab19**)((u8*)owner + 0x3C);
    if (part == NULL) {
        return;
    }
    part->v14();
}

extern "C" s32 fn_801A51B0(void* owner) {
    /* Return the +0x20 field of the sub-object held at +0x3C of 'owner', or -1 if absent. */
    void* part = *(void**)((u8*)owner + 0x3C);
    if (part != NULL) {
        return *(s32*)((u8*)part + 0x20);
    }
    return -1;
}

/* Getter for the s32 field at offset 0x34 of the object (paired with the
 * setter fn_801A51D4). */
extern "C" s32 fn_801A51CC(void* object) {
    return *(s32*)((u8*)object + 0x34);
}

/* Setter paired with fn_801A51CC: store a 32-bit value at +0x34 of the object. */
extern "C" void fn_801A51D4(void* object, s32 value) {
    *(s32*)((u8*)object + 0x34) = value;
}
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


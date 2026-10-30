#include <revolution/MTX/vec.h>
#include <revolution/MTX/quat.h>
#include <types.h>
extern "C" void fn_801FEA28(void*);
class SHMainMenu { public: ~SHMainMenu(); };
extern "C" {
extern void* lbl_8055EC98;
extern void* lbl_8055EC94;
extern const char lbl_8033B5D8[];
extern const char lbl_8033B638[];
extern const char lbl_8033B8C8[];
extern const char lbl_8033B8EC[];
extern const char lbl_8033B7F0[];
extern const char lbl_8033B820[];
extern const char lbl_8033B90C[];
void fn_80128668(void*);
void fn_801FEDA4(void*);
float fn_80129DC4(int, void*, float, float);
extern float lbl_80563034;
extern const char lbl_8033B790[];
void* memset(void*, int, unsigned long);
void fn_801FF5D4(void*, void*, float);
void fn_801FCA54(void*, int, int);
void fn_801FF7D4(void*, void*);
void fn_801FF8DC(void*, void*, int);
void fn_802E317C(const char*, ...);
void fn_801FCF18(void*, int, int);
void fn_801FF484(void*, void*);
float fn_801E7E24(void);
extern float lbl_80558DC4;
void fn_801FF6FC(void*, float);
void fn_801FF3AC(void*, float);
    float fabs(float);
    void fn_801FF770(void*);
          void* fn_801FCED8(void*, int);
    void* fn_801284F8(int, const char*);
    void fn_8002F53C(void*, void*, void*, int, int);
    void fn_801FF1C4(void*, int, int);
    void fn_801FF6A4(void*);
    void fn_802CD320(int, void*);
    void fn_801FF2B8(void*, int, int);
    void fn_801FF0D4(void*);
    void fn_801FEF80(void*);
          void* fn_801FCA14(void*, int);
          extern char lbl_8033B608[];
      extern const char lbl_8033B86C[];
    extern const char lbl_8033B898[];
      extern const char lbl_8033B880[];
    extern const char lbl_8033B730[];
  extern const char lbl_8033B5E8[];
        }
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" const char lbl_8033B700[];
extern "C" float lbl_80563030;
extern "C" float lbl_80563034;
extern "C" float lbl_80563038;
extern "C" float lbl_8056303C;
extern "C" float lbl_80563040;
extern "C" float lbl_80563044;
extern "C" void fn_801FD3F0(void);

extern "C" void fn_801FD5E8(void* = 0, float = 0);
extern "C" void fn_801FDF18(void);
extern "C" void fn_802E317C(const char*, ...);
extern "C" const char lbl_8033B618[];
extern "C" float fn_802C99E8(float);
extern "C" void fn_802C744C(void*, void*);
  #pragma scheduling invalid_target
  extern "C" void fn_801FC9CC(void) {
      void *p = fn_801284F8(8, (const char *)&lbl_8033B608);
      if (p != 0) {
          *(void **)p = (void *)&lbl_8033B700[0];
          *(int *)((char *)p + 4) = 0;
      }
  }
#pragma push
#pragma small_data off
extern "C" void* fn_801FE188(void*);
extern "C" void fn_801FC914(void) {
    void *p = fn_801284F8(0x38, lbl_8033B5D8);
    if (p != 0) {
        fn_801FE188(p);
    }
}

extern "C" void fn_801FC94C(void) {
    void *p;
    if ((p = fn_801284F8(8, (const char *)&lbl_8033B5E8)) != 0) {
        *(void **)p = (void *)&lbl_8033B730;
        *(int *)((char *)p + 4) = 0;
    }
}

extern "C" const char lbl_8033B5F8[];
extern "C" void fn_801FE550(void *);
extern "C" void fn_801FC994(void) {
    void *p = fn_801284F8(0x98, lbl_8033B5F8);
    if (p != 0) {
        fn_801FE550(p);
    }
}

#pragma pop

void* fn_801FCA14(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801FCA54(void* arg0, int arg1, int arg2) {
    float zero;
    float one;
    zero = lbl_80563034;
    one = lbl_80563030;
    int value = *(int*)((char*)arg1 + 4);
    *(int*)((char*)arg0 + 0) = arg2;
    *(int*)((char*)arg0 + 4) = 0;
    *(int*)((char*)arg0 + 8) = value;
    *(float*)((char*)arg0 + 0xc) = one;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x18) = zero;
    *(float*)((char*)arg0 + 0x1c) = one;
    *(float*)((char*)arg0 + 0x20) = zero;
    *(float*)((char*)arg0 + 0x24) = zero;
    *(float*)((char*)arg0 + 0x28) = zero;
    *(float*)((char*)arg0 + 0x2c) = one;
    *(float*)((char*)arg0 + 0x30) = zero;
    *(float*)((char*)arg0 + 0x34) = zero;
    *(float*)((char*)arg0 + 0x38) = zero;
    *(int*)((char*)arg0 + 0x3C) = -1;
}

extern "C" void fn_801FCB40(void*, float);
#pragma dont_inline on
extern "C" void fn_801FCAAC(void* arg0, float farg0) {
    if (*(void**)((char*)arg0 + 4) != 0) {
        fn_801FCB40(arg0, farg0);
    }
}
#pragma dont_inline reset

extern "C" void fn_801FCAC0(void* arg0) {
    if (*(void**)((char*)arg0 + 4) != 0) {
        fn_802C744C(*(void**)((char*)arg0 + 8), (char*)arg0 + 0xC);
    }
}

extern "C" void fn_801FCAE0(void* arg0, void* arg1) {
    float zero = lbl_80563034;
    float one = lbl_80563030;
    *(void**)((char*)arg0 + 4) = arg1;
    *(int*)((char*)arg0 + 0x3C) = 0;
    *(float*)((char*)arg0 + 0xC) = one;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x18) = zero;
    *(float*)((char*)arg0 + 0x1C) = one;
    *(float*)((char*)arg0 + 0x20) = zero;
    *(float*)((char*)arg0 + 0x24) = zero;
    *(float*)((char*)arg0 + 0x28) = zero;
    *(float*)((char*)arg0 + 0x2C) = one;
    *(float*)((char*)arg0 + 0x30) = zero;
    *(float*)((char*)arg0 + 0x34) = zero;
    *(float*)((char*)arg0 + 0x38) = zero;
    *(float*)((char*)arg0 + 0x30) = *(float*)((char*)arg1 + 0x10);
    *(float*)((char*)arg0 + 0x34) = *(float*)((char*)arg1 + 0x14);
    *(float*)((char*)arg0 + 0x38) = *(float*)((char*)arg1 + 0x18);
}

extern "C" void fn_801FCB40(void* arg0, float farg0) {
    char* a = (char*)arg0;
    float delta = farg0;
    int count = *(int*)(a + 0x3C);
    char* base = *(char**)(a + 4);
    char* item = base + (count << 5);
    float* q = (float*)(a + 0x30);
    float* q0 = (float*)(item + 0x10);
    float* q1 = (float*)(item + 0x30);
    float dx = q1[0] - q0[0];
    float dy = q1[1] - q0[1];
    float dz = q1[2] - q0[2];
    Vec dir;
    dir.x = dx; dir.y = dy; dir.z = dz;
    float mag = PSVECMag(&dir);
    float inv = lbl_80563030 / mag;
    Quaternion prod;
    PSQUATMultiply((const Quaternion*)(a + 0x30), (const Quaternion*)(item + 0x10), &prod);
    float s = inv * delta * (q0[3] + inv * prod.w * (q0[4] - q0[3]));
    float nx = q[0] + dx * s;
    float ny = q[1] + dy * s;
    float nz = q[2] + dz * s;
    q[0] = nx; q[1] = ny; q[2] = nz;
    Vec d;
    d.x = q1[0] - nx;
    d.y = q1[1] - ny;
    d.z = q1[2] - nz;
    if (PSVECDotProduct(&dir, &d) <= lbl_80563034) {
        count = *(int*)(a + 0x3C) + 1;
        *(int*)(a + 0x3C) = count;
        int max = *(int*)(base + 0x310);
        if (count >= max - 1) {
            fn_801FEA28(arg0);
            *(int*)(a + 4) = 0;
            return;
        }
        item = base + (count << 5);
        q1 = (float*)(item + 0x30);
        dx = q1[0] - q0[0];
        dy = q1[1] - q0[1];
        dz = q1[2] - q0[2];
        dir.x = dx; dir.y = dy; dir.z = dz;
        mag = PSVECMag(&dir);
        inv = lbl_80563030 / mag;
        float k = inv * PSVECMag(&d);
        q[0] = q0[0] + dx * k;
        q[1] = q0[1] + dy * k;
        q[2] = q0[2] + dz * k;
    }
    count = *(int*)(a + 0x3C) + 2;
    if (count < *(int*)(base + 0x310)) {
        item = base + (count << 5);
        float* q2 = (float*)(item + 0x10);
        Vec v;
        v.x = q2[0] - q1[0];
        v.y = q2[1] - q1[1];
        v.z = q2[2] - q1[2];
        PSQUATMultiply((const Quaternion*)(a + 0x30), (const Quaternion*)(item + 0x10), &prod);
        float t = inv * prod.w;
        float* p = (float*)(a + 0xC);
        p[0] = q0[1] + t * (q1[1] - q0[1]);
        p[1] = q0[2] + t * (q1[2] - q0[2]);
        p[2] = q0[3] + t * (q1[3] - q0[3]);
        Vec n;
        n.x = dx + t * (v.x - dx);
        n.y = dy + t * (v.y - dy);
        n.z = dz + t * (v.z - dz);
        PSVECNormalize(&n, (Vec*)(a + 0x24));
    } else {
        float* p = (float*)(a + 0xC);
        p[0] = q0[1];
        p[1] = q0[2];
        p[2] = q0[3];
        *(float*)(a + 0x24) = dx * inv;
        *(float*)(a + 0x28) = dy * inv;
        *(float*)(a + 0x2C) = dz * inv;
    }
    PSVECCrossProduct((const Vec*)(a + 0x24), (const Vec*)(a + 0xC), (Vec*)(a + 0x18));
}

extern "C" void* fn_801FCED8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801FCF18(void* arg0, int arg1, int arg2) {
    float zero;
    float one;
    zero = lbl_80563034;
    one = lbl_80563030;
    int value = *(int*)(arg1 + 4);
    *(int*)((char*)arg0 + 0) = arg2;
    *(int*)((char*)arg0 + 4) = 0;
    *(int*)((char*)arg0 + 8) = value;
    *(float*)((char*)arg0 + 0xc) = one;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x18) = zero;
    *(float*)((char*)arg0 + 0x1c) = one;
    *(float*)((char*)arg0 + 0x20) = zero;
    *(float*)((char*)arg0 + 0x24) = zero;
    *(float*)((char*)arg0 + 0x28) = zero;
    *(float*)((char*)arg0 + 0x2c) = one;
    *(float*)((char*)arg0 + 0x30) = zero;
    *(float*)((char*)arg0 + 0x34) = zero;
    *(float*)((char*)arg0 + 0x38) = zero;
    *(int*)((char*)arg0 + 0x3C) = -1;
    *(float*)((char*)arg0 + 0x40) = zero;
}

extern "C" void fn_801FCF74(void* arg0, float farg0) {
    int obj = *(int *)((char *)arg0 + 4);
    if (obj == 0)
        return;
    int type = *(unsigned short *)((char *)obj + 0x16);
    switch (type) {
    case 0:
        return ((void (*)(void *, int))fn_801FD3F0)(arg0, type);
    case 1:
        return ((void (*)(void *, int, float))fn_801FD5E8)(arg0, type, farg0);
    case 2:
        return ((void (*)(void *, int))fn_801FDF18)(arg0, type);
    default:
        return fn_802E317C((const char *)lbl_8033B618);
    }
}

#pragma push
#pragma paired off
extern "C" void fn_801FCFC8(void* arg0) {
    if (*(int*)((char*)arg0 + 4) != 0) {
        int pad = 0;
        float value = fn_802C99E8(*(float*)((char*)arg0 + 0x6C));
        fn_802C744C(*(void**)((char*)arg0 + 8), (char*)arg0 + 0xC);
        if (pad) value = pad;
        fn_802C99E8(value);
    }
}

extern float lbl_80563030;
extern "C" void fn_801FD024(void* arg0, void* arg1) {
    char* dst = (char*)arg0;
    float initial = lbl_80563034;
    *(void**)(dst + 4) = arg1;
    void* src = *(void**)arg1;
    *(int*)(dst + 0x3C) = 0;
    *(float*)(dst + 0x40) = initial;
    *(float*)(dst + 0x44) = *(float*)((char*)src + 0x1C);
    *(float*)(dst + 0x48) = *(float*)((char*)src + 0x20);
    *(float*)(dst + 0x4C) = *(float*)((char*)src + 0x24);
    *(float*)(dst + 0x50) = *(float*)((char*)src + 0x28);
    *(float*)(dst + 0x54) = *(float*)((char*)src + 0x40);
    *(float*)(dst + 0x58) = *(float*)((char*)src + 0x44);
    *(float*)(dst + 0x5C) = *(float*)((char*)src + 0x48);
    *(float*)(dst + 0x60) = *(float*)((char*)src + 0x4C);
    float w0 = *(float*)((char*)src + 0x2C);
    *(float*)(dst + 0x64) = w0;
    *(float*)(dst + 0x68) = *(float*)((char*)src + 0x50);
    *(float*)(dst + 0x6C) = w0;
    *(float*)(dst + 0x30) = *(float*)((char*)src + 0x10);
    *(float*)(dst + 0x34) = *(float*)((char*)src + 0x14);
    *(float*)(dst + 0x38) = *(float*)((char*)src + 0x18);
    volatile float* quat = (volatile float*)((char*)src + 0x1C);
    float z, y, x;
    x = quat[0];
    y = quat[1];
    z = quat[2];
    float z2, y2, x2;
    x2 = x + x;
    y2 = y + y;
    float w = quat[3];
    z2 = z + z;
    float zz, yy, xx;
    xx = x * x2;
    yy = y * y2;
    zz = z * z2;
    float xw = w * x2;
    float yz = y * z2;
    float one = lbl_80563030;
    float sum0 = yy + zz;
    float sum1 = xx + zz;
    float sum2 = xx + yy;
    float m00 = one - sum0;
    float m11 = one - sum1;
    float m22 = one - sum2;
    float m12 = yz - xw;
    *(float*)(dst + 0xC) = m00;
    float m21 = yz + xw;
    float yw = w * y2;
    float xz = x * z2;
    float zw = w * z2;
    *(float*)(dst + 0x1C) = m11;
    float xy = x * y2;
    float m24 = xz + yw;
    float m14 = xz - yw;
    float m18 = xy - zw;
    float m10 = xy + zw;
    *(float*)(dst + 0x28) = m12;
    *(float*)(dst + 0x24) = m24;
    *(float*)(dst + 0x18) = m18;
    *(float*)(dst + 0x10) = m10;
    *(float*)(dst + 0x14) = m14;
    *(float*)(dst + 0x20) = m21;
    *(float*)(dst + 0x2C) = m22;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801FD144(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, float farg0) {
    struct Vec3 { float x; float y; float z; };
    Vec3 dA;
    Vec3 dB;
    Vec3 *a = (Vec3 *)arg3;
    Vec3 *b = (Vec3 *)arg2;
    if (arg1 != 0) {
        Vec3 *prev = (Vec3 *)arg1;
        dA.x = a->x - prev->x;
        dA.y = a->y - prev->y;
        dA.z = a->z - prev->z;
    } else {
        dA.x = a->x - b->x;
        dA.y = a->y - b->y;
        dA.z = a->z - b->z;
    }
    if (arg4 != 0) {
        Vec3 *next = (Vec3 *)arg4;
        dB.x = next->x - b->x;
        dB.y = next->y - b->y;
        dB.z = next->z - b->z;
    } else {
        dB.x = a->x - b->x;
        dB.y = a->y - b->y;
        dB.z = a->z - b->z;
    }
    float f6 = farg0 * farg0;
    float f10 = farg0 * f6;
    float c38 = lbl_80563038;
    float c3c = lbl_8056303C;
    float c30 = lbl_80563030;
    float c44 = lbl_80563044;
    float c40 = lbl_80563040;
    register float f30 = c3c * f6;
    float t = f10 - c38 * f6;
    float f8 = c40 * (farg0 + t);
    register float f31 = c30 + (c38 * f10 - f30);
    float f7 = c40 * (f10 - f6);
    float f4 = c44 * f10 + f30;
    float px = b->x * f31 + dA.x * f8 + dB.x * f7;
    float py = b->y * f31 + dA.y * f8 + dB.y * f7;
    float pz = b->z * f31 + dA.z * f8 + dB.z * f7;
    ((float *)arg0)[12] = px + a->x * f4;
    ((float *)arg0)[13] = py + a->y * f4;
    ((float *)arg0)[14] = pz + a->z * f4;
}
#pragma pop

#pragma pop
extern "C" double cos(double);
extern "C" double sin(double);
extern "C" double fn_8002F234(float);
extern "C" float fn_80144514(float, float, float, float, float, float);
extern "C" void fn_801FD144(void*, void*, void*, void*, void*, float);
extern "C" float lbl_80563040;
extern "C" double lbl_80563048;

static inline char* GetTrackNode(char* track, int idx) {
    int count = *(int*)(track + 0x6D0);
    if (idx >= count && idx < count * 2) {
        return track + 0x10 + (count * 2 - idx - 1) * 0x24;
    }
    if (idx >= 0) {
        return track + 0x10 + (idx % count) * 0x24;
    }
    return track + 0x10 + (-idx) * 0x24;
}

static inline void MatrixMul801FD5E8(float* dst, const float* left, const float* right) {
    if (dst == right || dst == left) {
        float t0 = fn_80144514(left[0], right[0], left[3], right[1], left[6], right[2]);
        float t3 = fn_80144514(left[0], right[3], left[3], right[4], left[6], right[5]);
        float t6 = fn_80144514(left[0], right[6], left[3], right[7], left[6], right[8]);
        float t1 = fn_80144514(left[1], right[0], left[4], right[1], left[7], right[2]);
        float t4 = fn_80144514(left[1], right[3], left[4], right[4], left[7], right[5]);
        float t7 = fn_80144514(left[1], right[6], left[4], right[7], left[7], right[8]);
        float t2 = fn_80144514(left[2], right[0], left[5], right[1], left[8], right[2]);
        float t5 = fn_80144514(left[2], right[3], left[5], right[4], left[8], right[5]);
        float t8 = fn_80144514(left[2], right[6], left[5], right[7], left[8], right[8]);
        dst[0] = t0;
        dst[3] = t3;
        dst[6] = t6;
        dst[1] = t1;
        dst[4] = t4;
        dst[7] = t7;
        dst[2] = t2;
        dst[5] = t5;
        dst[8] = t8;
    } else {
        dst[0] = fn_80144514(left[0], right[0], left[3], right[1], left[6], right[2]);
        dst[3] = fn_80144514(left[0], right[3], left[3], right[4], left[6], right[5]);
        dst[6] = fn_80144514(left[0], right[6], left[3], right[7], left[6], right[8]);
        dst[1] = fn_80144514(left[1], right[0], left[4], right[1], left[7], right[2]);
        dst[4] = fn_80144514(left[1], right[3], left[4], right[4], left[7], right[5]);
        dst[7] = fn_80144514(left[1], right[6], left[4], right[7], left[7], right[8]);
        dst[2] = fn_80144514(left[2], right[0], left[5], right[1], left[8], right[2]);
        dst[5] = fn_80144514(left[2], right[3], left[5], right[4], left[8], right[5]);
        dst[8] = fn_80144514(left[2], right[6], left[5], right[7], left[8], right[8]);
    }
}

extern "C" void fn_8012F57C(float*, void*, void*, float);
extern "C" float lbl_80563030;
#pragma scheduling invalid_target
extern "C" void fn_801FD320(void* arg0, float t) {
    volatile float q[4];
    fn_8012F57C((float*)q, (char*)arg0 + 0x44, (char*)arg0 + 0x54, t);
    float x = q[0];
    float y = q[1];
    float z = q[2];
    float x2 = x + x;
    float y2 = y + y;
    float w = q[3];
    float z2 = z + z;
    float xx = x * x2;
    float yy = y * y2;
    float zz = z * z2;
    float one = lbl_80563030;
    float wx = w * x2;
    float yz = y * z2;
    float sum0 = yy + zz;
    float sum1 = xx + zz;
    float sum2 = xx + yy;
    float r0 = one - sum0;
    float r1 = one - sum1;
    float r2 = one - sum2;
    float m28 = yz - wx;
    *(float*)((char*)arg0 + 0xC) = r0;
    float m20 = yz + wx;
    float wy = w * y2;
    float xz = x * z2;
    float wz = w * z2;
    *(float*)((char*)arg0 + 0x1C) = r1;
    float xy = x * y2;
    float m24 = xy + wz;
    float m14 = xy - wz;
    float m18 = xz - wy;
    float m10 = xz + wy;
    *(float*)((char*)arg0 + 0x28) = m28;
    *(float*)((char*)arg0 + 0x24) = m24;
    *(float*)((char*)arg0 + 0x18) = m18;
    *(float*)((char*)arg0 + 0x10) = m10;
    *(float*)((char*)arg0 + 0x14) = m14;
    *(float*)((char*)arg0 + 0x20) = m20;
    *(float*)((char*)arg0 + 0x2C) = r2;
}
#pragma scheduling on
extern "C" void fn_801FD5E8(void* arg0, float farg0) {
    char* obj = (char*)arg0;
    char* track = *(char**)(obj + 4);
    int idx = *(int*)(obj + 0x3C);
    char* node = GetTrackNode(track, idx);

    float speed = *(float*)(node + 0x20);
    float t_step = *(float*)(obj + 0x40) + farg0;
    float step = speed * t_step;

    if (step < lbl_80563030) {
        *(float*)(obj + 0x40) = t_step;
    } else {
        step -= lbl_80563030;
        *(float*)(obj + 0x40) = *(float*)(obj + 0x40) + (farg0 - lbl_80563030 / speed);

        int count = *(int*)(track + 0x6D0);
        idx = (*(int*)(obj + 0x3C) + 1) % (count * 2);
        *(int*)(obj + 0x3C) = idx;

        node = GetTrackNode(track, idx);

        *(float*)(obj + 0x44) = *(float*)(obj + 0x54);
        *(float*)(obj + 0x48) = *(float*)(obj + 0x58);
        *(float*)(obj + 0x4C) = *(float*)(obj + 0x5C);
        *(float*)(obj + 0x50) = *(float*)(obj + 0x60);
        *(float*)(obj + 0x64) = *(float*)(obj + 0x68);

        char* next_node = GetTrackNode(track, idx + 1);
        *(float*)(obj + 0x54) = *(float*)(next_node + 0xC);
        *(float*)(obj + 0x58) = *(float*)(next_node + 0x10);
        *(float*)(obj + 0x5C) = *(float*)(next_node + 0x14);
        *(float*)(obj + 0x60) = *(float*)(next_node + 0x18);

        char* next2_node = GetTrackNode(track, idx + 2);
        *(float*)(obj + 0x68) = *(float*)(next2_node + 0x1C);

        int next_idx = *(int*)(obj + 0x3C) + 1;
        if (next_idx >= count && next_idx < count * 2) {
            float qx = *(float*)(obj + 0x54);
            float qy = *(float*)(obj + 0x58);
            float qz = *(float*)(obj + 0x5C);
            float qw = *(float*)(obj + 0x60);

            float y2 = qy + qy;
            float z2 = qz + qz;
            float x2 = qx + qx;
            float yy = qy * y2;
            float xx = qx * x2;
            float zz = qz * z2;
            float wx = qw * x2;
            float yz = qy * z2;

            float m[9];
            m[0] = lbl_80563030 - (yy + zz);
            m[4] = lbl_80563030 - (xx + zz);
            m[8] = lbl_80563030 - (xx + yy);

            float wy = qw * y2;
            float xz = qx * z2;
            float wz = qw * z2;
            float xy = qx * y2;

            m[7] = yz - wx;
            m[5] = yz + wx;
            m[6] = xz + wy;
            m[2] = xz - wy;
            m[1] = xy + wz;
            m[3] = xy - wz;

            float rot[9];
            float cos_val = (float)cos(lbl_80563048);
            float sin_val = (float)sin(lbl_80563048);
            rot[0] = cos_val;
            rot[1] = lbl_80563034;
            rot[2] = -sin_val;
            rot[3] = lbl_80563034;
            rot[4] = lbl_80563030;
            rot[5] = lbl_80563034;
            rot[6] = sin_val;
            rot[7] = lbl_80563034;
            rot[8] = cos_val;

            MatrixMul801FD5E8(m, m, rot);

            float trace = m[8] + (m[0] + m[4]);
            if (trace > lbl_80563034) {
                float root = (float)fn_8002F234(lbl_80563030 + trace);
                float inv_root = lbl_80563040 / root;
                *(float*)(obj + 0x60) = lbl_80563040 * root;
                *(float*)(obj + 0x54) = inv_root * (m[5] - m[7]);
                *(float*)(obj + 0x58) = inv_root * (m[6] - m[2]);
                *(float*)(obj + 0x5C) = inv_root * (m[1] - m[3]);
            } else {
                int i = 0;
                if (m[4] > m[0]) i = 1;
                if (m[8] > m[i * 3 + i]) i = 2;
                int j = (i + 1) % 3;
                int k = (j + 1) % 3;
                float diag_sum = m[j * 3 + j] + m[k * 3 + k];
                float root = (float)fn_8002F234(lbl_80563030 + (m[i * 3 + i] - diag_sum));
                float inv_root = lbl_80563040 / root;
                float* q_out = (float*)(obj + 0x54);
                q_out[i] = lbl_80563040 * root;
                *(float*)(obj + 0x60) = inv_root * (m[j * 3 + k] - m[k * 3 + j]);
                q_out[j] = inv_root * (m[i * 3 + j] + m[j * 3 + i]);
                q_out[k] = inv_root * (m[i * 3 + k] + m[k * 3 + i]);
            }
        }
    }

    int count = *(int*)(track + 0x6D0);
    int cur_idx = *(int*)(obj + 0x3C);
    if (count - 1 != cur_idx % count) {
        char* prev_node = GetTrackNode(track, cur_idx - 1);
        char* next_node = GetTrackNode(track, cur_idx + 1);
        char* next2_node = GetTrackNode(track, cur_idx + 2);
        fn_801FD144(obj, prev_node, node, next_node, next2_node, step);
    }
    fn_801FD320(obj, step);
    float f64_val = *(float*)(obj + 0x64);
    *(float*)(obj + 0x6C) = f64_val + step * (*(float*)(obj + 0x68) - f64_val);
}

extern "C" void fn_801FEDA4(void*);
extern "C" float fn_80129DC4(int, void*, float, float);
extern "C" float fn_801E7E24(void);
extern "C" void* memset(void*, int, unsigned long);
extern "C" const char lbl_8033B790[];
extern "C" void* fn_801FE188(void* arg0) {
    *(const char**)arg0 = lbl_8033B790;
    memset((char*)arg0 + 4, 0, 0x30);
    *(int*)((char*)arg0 + 0x34) = 0;
    return arg0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" void fn_801FE1D8(void* arg0, unsigned char* p) {
    register unsigned char* q = p + 0x3C;
    register unsigned char a=p[0x2C];
    register unsigned char x0=p[0x3B];
    register unsigned char b=p[0x2D];
    register unsigned char x1=p[0x3A];
    register unsigned char c=p[0x2E];
    register unsigned char x2=p[0x39];
    register unsigned char d=p[0x2F];
    register unsigned char x3=p[0x38];
    register unsigned char e=p[0x30];
    register unsigned char x4=p[0x37];
    register unsigned char f=p[0x31];
    register unsigned char x5=p[0x36];
    register unsigned char g=p[0x32];
    register unsigned char x6=p[0x35];
    register unsigned char h=p[0x33];
    register unsigned char x7=p[0x34];
    p[0x2C]=x0; p[0x3B]=a; p[0x2D]=x1; p[0x3A]=b;
    p[0x2E]=x2; p[0x39]=c; p[0x2F]=x3; p[0x38]=d;
    p[0x30]=x4; p[0x37]=e; p[0x31]=x5; p[0x36]=f;
    p[0x32]=x6; p[0x35]=g; p[0x33]=x7; p[0x34]=h;
    for (int i=0; i<32; i++, q+=0x18) {
      unsigned char x;
      x=q[0];q[0]=q[3];q[3]=x; x=q[1];q[1]=q[2];q[2]=x;
      x=q[4];q[4]=q[7];q[7]=x; x=q[5];q[5]=q[6];q[6]=x;
      x=q[8];q[8]=q[11];q[11]=x; x=q[9];q[9]=q[10];q[10]=x;
      x=q[12];q[12]=q[15];q[15]=x; x=q[13];q[13]=q[14];q[14]=x;
      x=q[16];q[16]=q[19];q[19]=x; x=q[17];q[17]=q[18];q[18]=x;
      x=q[20];q[20]=q[23];q[23]=x; x=q[21];q[21]=q[22];q[22]=x;
    }
    volatile unsigned char *v = p;
    unsigned char i0=v[0x33C], i1=v[0x33F];
    unsigned char i2=v[0x33D], i3=v[0x33E];
    unsigned char i4=v[0x340], i5=v[0x343];
    unsigned char i6=v[0x341], i7=v[0x342];
    unsigned char i8=v[0x344], i9=v[0x347];
    unsigned char i10=v[0x345], i11=v[0x346];
    v[0x347]=i8;
    v[0x33C]=i1; v[0x33F]=i0;
    v[0x33D]=i3; v[0x33E]=i2;
    v[0x340]=i5; v[0x343]=i4;
    v[0x341]=i7; v[0x342]=i6;
    v[0x344]=i9; v[0x345]=i11;
    v[0x346]=i10;
}
#pragma pop

extern "C" void fn_801FE3B8(void *arg0, void *arg1) {
    char *source = (char *)arg1 + 0x2C;
    char *item;
    int count;
    float first;
    float second;
    float result;

    count = *(int *)((char *)arg0 + 0x34);
    if (count >= 6) {
        fn_802E317C(lbl_8033B638, 6);
    }
    count = *(int *)((char *)arg0 + 0x34);
    first = *(float *)(source + 0x314);
    item = (char *)arg0 + count * 8;
    second = *(float *)(source + 0x318);
    *(char **)(item + 4) = source;
    result = fn_80129DC4(0, item, first, second);
    count = *(int *)((char *)arg0 + 0x34);
    item = (char *)arg0 + count * 8;
    *(float *)(item + 8) = result;
    count = *(int *)((char *)arg0 + 0x34);
    *(int *)((char *)arg0 + 0x34) = count + 1;
}

extern "C" void fn_801FEB58(void*);
extern "C" float lbl_80558DC4;
#pragma push
#pragma processor 750
extern "C" double __fabs(double);
#pragma push
#pragma processor 750
__declspec(section ".data") extern float lbl_80558DC4;
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801FE448(void *arg0) {
    float delta = fn_801E7E24();
    if (!((float)__fabs((double)delta) <= lbl_80558DC4)) {
        float threshold = lbl_80563034;
        char *item = (char *)arg0 + 4;
        int i = 0;
        while (i < *(int *)((char *)arg0 + 0x34)) {
            float time = *(float *)(item + 4) - delta;
            *(float *)(item + 4) = time;
            if (time <= threshold) {
                fn_801FEB58(*(void **)item);
                void *obj = *(void **)item;
                *(float *)(item + 4) = fn_80129DC4(0, obj, *(float *)((char *)obj + 0x314), *(float *)((char *)obj + 0x318));
            }
            item += 8;
            ++i;
        }
    }
}
#pragma scheduling on
#pragma pop
extern "C" void fn_802C7040(int);
float fn_80129DC4(int, void *, float, float);
extern "C" int fn_801FE88C(void *, void *);
extern const char lbl_8033B638[];
extern const char lbl_8033B654[];
extern char lbl_8033B760[];
extern "C" void fn_801FE510(void *arg0, void *arg1) {
    void *p = arg1;
    while (p != 0) {
        fn_802C7040(*(int *)((char *)p + 4));
        p = *(void **)((char *)p + 0xC);
    }
}

#pragma scheduling invalid_target
extern "C" void fn_801FE550(void *arg0) {
    *(char **)arg0 = lbl_8033B760;
    *(int *)((char *)arg0 + 0x94) = 0;
}
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" void fn_801FE568(void* arg0, unsigned char* p) {
    unsigned char t;
    unsigned char *ptr;
    int i;

    t = p[0x2c]; p[0x2c] = p[0x3b]; p[0x3b] = t;
    t = p[0x2d]; p[0x2d] = p[0x3a]; p[0x3a] = t;
    t = p[0x2e]; p[0x2e] = p[0x39]; p[0x39] = t;
    t = p[0x2f]; p[0x2f] = p[0x38]; p[0x38] = t;
    t = p[0x30]; p[0x30] = p[0x37]; p[0x37] = t;
    t = p[0x31]; p[0x31] = p[0x36]; p[0x36] = t;
    t = p[0x32]; p[0x32] = p[0x35]; p[0x35] = t;
    t = p[0x33]; p[0x33] = p[0x34]; p[0x34] = t;

    ptr = p + 0x3c;
    for (i = 1; i <= 0x48; i++) {
        t = ptr[0]; ptr[0] = ptr[3]; ptr[3] = t;
        t = ptr[1]; ptr[1] = ptr[2]; ptr[2] = t;
        t = ptr[4]; ptr[4] = ptr[7]; ptr[7] = t;
        t = ptr[5]; ptr[5] = ptr[6]; ptr[6] = t;
        t = ptr[8]; ptr[8] = ptr[0xb]; ptr[0xb] = t;
        t = ptr[9]; ptr[9] = ptr[0xa]; ptr[0xa] = t;
        t = ptr[0xc]; ptr[0xc] = ptr[0xf]; ptr[0xf] = t;
        t = ptr[0xd]; ptr[0xd] = ptr[0xe]; ptr[0xe] = t;
        t = ptr[0x10]; ptr[0x10] = ptr[0x13]; ptr[0x13] = t;
        t = ptr[0x11]; ptr[0x11] = ptr[0x12]; ptr[0x12] = t;
        t = ptr[0x14]; ptr[0x14] = ptr[0x17]; ptr[0x17] = t;
        t = ptr[0x15]; ptr[0x15] = ptr[0x16]; ptr[0x16] = t;
        ptr += 0x18;
    }

    t = p[0x6fc]; p[0x6fc] = p[0x6ff]; p[0x6ff] = t;
    t = p[0x6fd]; p[0x6fd] = p[0x6fe]; p[0x6fe] = t;
}
#pragma pop
extern "C" void fn_801FE708(void *arg0, void *arg1) {
    char *p = (char *)arg1 + 0x2C;
    int count = *(int *)((char *)arg0 + 0x94);
    if (count >= 4)
        fn_802E317C(lbl_8033B654);
    count = *(int *)((char *)arg0 + 0x94);
    char *slot = (char *)arg0 + count * 0x24;
    *(char **)(slot + 4) = p;
    fn_801FE88C(arg0, slot + 4);
    ++*(int *)((char *)arg0 + 0x94);
}

extern "C" void fn_801FE77C(void* arg0) {
    char* item = (char*)arg0 + 4;
    int i = 0;
    while (i < *(int*)((char*)arg0 + 0x94)) {
        if (*(unsigned short*)(item + 0x14) == 0)
            fn_801FEDA4(item);
        item += 0x24;
        ++i;
    }
}

#pragma scheduling invalid_target
extern "C" void fn_801FE7E8(void* arg0) {
    float threshold = lbl_80563034;
    char* item = (char*)arg0 + 4;
    int i = 0;
    while (i < *(int*)((char*)arg0 + 0x94)) {
        if (*(unsigned short*)(item + 0x14) == 1) {
            float time = *(float*)(item + 0x20) - fn_801E7E24();
            *(float*)(item + 0x20) = time;
            if (time < threshold) {
                typedef float (*UpdateFn)(int, float, float);
                fn_801FEDA4(item);
                *(float*)(item + 0x20) = ((UpdateFn)fn_80129DC4)(0, *(float*)(item + 0x18), *(float*)(item + 0x1C));
            }
        }
        item += 0x24;
        ++i;
    }
}
#pragma scheduling on
extern const char lbl_8055B3C8[5];
extern const char lbl_8055B3D0[6];
extern const char lbl_8055B3D8[7];
extern "C" void* fn_802AE414(int);
extern "C" char* strncpy(char*, const char*, unsigned long);
#pragma use_lmw_stmw off
extern "C" int fn_801FE88C(void* unused, void* out) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual const char* getName(const char*);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual float getFloat(const char*);
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual unsigned short getUshort(const char*, const char*);
    };
    const char *base = lbl_8033B5D8;
    const char *strA = base + 0xA0;
    const char *strB = base + 0xB0;
    Obj* obj = (Obj*)fn_802AE414(*(int*)out);
    if (obj == 0) {
        fn_802E317C(base + 0xC8);
    }
    strncpy((char*)out + 4, obj->getName(lbl_8055B3C8), 0x10);
    *((char*)out + 0x13) = 0;
    *(unsigned short*)((char*)out + 0x14) = obj->getUshort(lbl_8055B3D0, strA);
    *(unsigned short*)((char*)out + 0x16) = obj->getUshort(lbl_8055B3D8, strB);
    if (*(unsigned short*)((char*)out + 0x14) == 1) {
        float val;
        float zero;
        *(float*)((char*)out + 0x18) = obj->getFloat(base + 0x104);
        val = obj->getFloat(base + 0x114);
        zero = lbl_80563034;
        *(float*)((char*)out + 0x1C) = val;
        *(float*)((char*)out + 0x20) = zero;
    }
}
extern "C" void* fn_801FE9A8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" int stricmp(const char*, const char*);

extern "C" void* fn_801FE9E8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801FEA28(void* arg) {
    char* base = (char*)lbl_8055EC94;
    char* name = *(char**)arg;
    int i = 0;
    char* item = base;
    while (i < *(int*)(base + 0x4C0)) {
        if (stricmp(name, item) == 0) {
            base += i * 0x98;
            goto found;
        }
        item += 0x98;
        i++;
    }
    base = 0;
found:
    if (base == 0) {
        fn_802E317C(lbl_8033B7F0, *(char**)arg);
    }
    int count = *(int*)(base + 0x94);
    int index = 0;
    void* p = base;
    for (int k = count; k > 0; k--) {
        if (*(void**)((char*)p + 0x50) == arg) break;
        p = (char*)p + 4;
        index++;
    }
    if (index >= count) {
        fn_802E317C(lbl_8033B820, count, *(int*)(base + 0x90));
    }
    int* q = (int*)(base + (index + 1) * 4);
    int j = index + 1;
    for (; j < *(int*)(base + 0x94); j++, q++) {
        q[19] = q[20];
    }
    *(int*)(base + 0x94) -= 1;
    int count2 = *(int*)(base + 0x90);
    *(void**)(base + 0x10 + count2 * 4) = arg;
    *(int*)(base + 0x90) = count2 + 1;
}

extern const char lbl_8033B84C[];
extern "C" int stricmp(const char*, const char*);
extern "C" int fn_80129D18(int, int = 0);
void fn_801FCAE0(void*, void*);
void fn_801FD024(void*, void*);
extern "C" void fn_801FEB58(void* value) {
    char* base = (char*)lbl_8055EC94;
    int i = 0;
    char* item = base;
    char* name = (char*)value;
    while (i < *(int*)(base + 0x4C0)) {
        if (stricmp(name, item) == 0) {
            base += i * 0x98;
            goto found;
        }
        item += 0x98;
        i++;
    }
    base = 0;
found:
    if (base == 0) {
        fn_802E317C(lbl_8033B84C, name);
    }
    int count = *(int*)(base + 0x90);
    if (count > 0) {
        int index = fn_80129D18(0, count);
        int selected = *(int*)(base + 0x10 + index * 4);
        int j = index + 1;
        int* p = (int*)(base + j * 4);
        for (; j < *(int*)(base + 0x90); j++, p++) {
            p[3] = p[4];
        }
        *(int*)(base + 0x90) -= 1;
        fn_801FCAE0((void*)selected, name);
        int c2 = *(int*)(base + 0x94);
        *(int*)(base + 0x50 + c2 * 4) = selected;
        *(int*)(base + 0x94) = c2 + 1;
    }
}

extern "C" void fn_801FEC74(void* arg) {
    char* result = (char*)lbl_8055EC98;
    char* name = *(char**)arg;
    int i = 0;
    char* item = result;
    for (;;) {
        if (stricmp(name, item) == 0) {
            result += i * 0x58;
            break;
        }
        item += 0x58;
        i++;
        if (i >= *(int*)(result + 0x2C0)) { result = 0; break; }
    }
    if (result == 0) fn_802E317C(lbl_8033B7F0, *(char**)arg);
    int index = 0;
    void* p = result;
    int count = *(int*)(result + 0x54);
    for (; index < count; p = (char*)p + 4, ++index) {
        if (*(void**)((char*)p + 0x30) == arg) break;
    }
    if (index >= count) fn_802E317C(lbl_8033B820, count, *(int*)(result + 0x50));
    int j = index + 1;
    int* q = (int*)(result + j * 4);
    for (; j < *(int*)(result + 0x54); ++j, ++q) q[11] = q[12];
    *(int*)(result + 0x54) = j - 1;
    int n = *(int*)(result + 0x50);
    *(void**)(result + 0x10 + n * 4) = arg;
    *(int*)(result + 0x50) = n + 1;
}

extern "C" int stricmp(const char *, const char *);
void fn_801FEDA4(void *arg0) {
    struct Obj {
        int unused;
        char name[1];
    };
    Obj *obj = (Obj *)arg0;
    char *base = (char *)lbl_8055EC98;
    int i = 0;
    char *entry = base;

search:
    if (stricmp(obj->name, entry) != 0) goto advance;
    base += i * 0x58;
    goto selected;
advance:
    entry += 0x58;
    i++;
    if (i < *(volatile int *)(base + 0x2C0)) goto search;
    base = 0;
selected:
    if (base == 0) fn_802E317C(lbl_8033B84C, obj->name);
    if (*(int *)(base + 0x50) > 0) {
        int index = fn_80129D18(0);
        int selected = *(int *)(base + 0x10 + index * 4);
        int j = index + 1;
        int *p = (int *)(base + j * 4);
        for (; j < *(int *)(base + 0x50); j++, p++) p[3] = p[4];
        *(int *)(base + 0x50) = j - 1;
        fn_801FD024((void *)selected, arg0);
        {
            int count = *(int *)(base + 0x54);
            *(int *)(base + 0x30 + count * 4) = selected;
            *(int *)(base + 0x54) = count + 1;
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_801FEEC0(void *arg0, int arg1, int arg2, int arg3) {
    void *obj = *(void **)((char *)arg0 + 4);
    int end = arg2 + 0x2C;
    if (obj == 0) {
        obj = fn_801284F8(0x14CC, lbl_8033B86C);
        if (obj != 0) {
            *(void **)obj = (void *)lbl_8033B880;
            fn_8002F53C((char *)obj + 4, (void *)fn_801FEF80, (void *)fn_801FCA14, 0x40, 0x40);
            *(int *)((char *)obj + 0x1004) = 0;
            fn_801FF6A4((char *)obj + 0x1008);
        }
        *(void **)((char *)arg0 + 4) = obj;
        fn_802CD320(arg1, obj);
    }
    fn_801FF2B8(*(void **)((char *)arg0 + 4), arg2, end);
}
#pragma pop
extern "C" void fn_801FEF80(void* arg0) {
    *(int*)arg0 = 0;
    *((int*)arg0 + 1) = 0;
}

extern "C" char* strncpy(char*, const char*, unsigned long);
extern "C" void fn_801FEF90(void* arg0) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v5(int);
    };
    Obj* obj = *(Obj**)((char*)arg0 + 4);
    if (obj != 0) obj->v5(0);
}

extern "C" void fn_801FEFB4(void* arg0) {
    fn_801FF770((char*)arg0 + 0x1008);
}

extern "C" void fn_801FEFBC(void) {

}

extern "C" void fn_801FEFC0(void) {

}

extern "C" void fn_801FF114(void) {

}

extern "C" void fn_801FF118(void) {

}

extern "C" const char lbl_8033B700[];
#pragma scheduling invalid_target
extern "C" void *fn_801FF11C(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(void * volatile *)arg0 = (void *)&lbl_8033B700[0];
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
extern "C" void fn_801FF168(void) {

}

#pragma small_data off
extern "C" void fn_801FF16C(void *arg0) {
    float value = fn_801E7E24();
    if (!((float)__fabs((double)value) <= lbl_80558DC4)) {
        fn_801FF3AC((char *)arg0 + 0xE08, value);
    }
}
extern "C" int fn_801FF1BC(void) { return 3; }

extern "C" void fn_801FF1C4(void* arg0, int arg1, int arg2) {
    char* p = (char*)arg0;
    if (*(int*)(p + 0xE04) >= 0x20) {
        const char* msg = lbl_8033B8C8;
        fn_802E317C(msg);
    }
    fn_801FCF18(p + *(int*)(p + 0xE04) * 0x70 + 4, arg1, arg2);
    fn_801FF484(p + 0xE08, p + *(int*)(p + 0xE04) * 0x70 + 4);
    ++*(int*)(p + 0xE04);
}

extern double __fabs(double);
#pragma push
#pragma small_data off
extern "C" void fn_801FF260(void *arg0) {
    float value = fn_801E7E24();
    if (!((float)__fabs((double)value) <= lbl_80558DC4)) {
        fn_801FF6FC((char *)arg0 + 0x1008, value);
    }
}
#pragma pop
extern "C" int fn_801FF2B0(void) { return 3; }

extern "C" void fn_801FF2B8(void* arg0, int arg1, int arg2) {
 char* p = (char*)arg0;
 if (*(int*)(p + 0x1004) >= 0x40) fn_802E317C(&lbl_8033B8C8[0]);
 fn_801FCA54(p + (*(int*)(p + 0x1004) << 6) + 4, arg1, arg2);
 fn_801FF7D4(p + 0x1008, p + (*(int*)(p + 0x1004) << 6) + 4);
 ++*(int*)(p + 0x1004);
}

extern "C" void fn_801FF354(void* arg0) {
 lbl_8055EC98 = arg0;
 *(int*)((char*)arg0 + 0x2C0) = 0;
}

extern "C" void* fn_801FF364(void* arg0, int arg1) {
 if (arg0 != 0) { lbl_8055EC98 = 0; if (arg1 > 0) fn_80128668(arg0); }
 return arg0;
}

extern "C" void fn_801FF3AC(void* arg0, float arg1) {
 char* entry = (char*)arg0;
 int i = 0;
 while (i < *(int*)((char*)arg0 + 0x2C0)) {
  fn_801FF5D4(arg0, entry, arg1);
  entry += 0x58;
  ++i;
 }
}

extern "C" void fn_801FF644(void*, void*);
void fn_801FF644(void*, void*);
extern "C" void fn_801FF420(void*);
extern "C" void fn_801FF420(void* arg0) {
    char* entry;
    int i;
    i = 0;
    entry = (char*)arg0;
    while (i < *(int*)((char*)arg0 + 0x2C0)) {
        fn_801FF644(arg0, entry);
        entry += 0x58;
        i++;
    }
}

extern "C" void fn_801FF58C(void*, char*, const char*);
#pragma use_lmw_stmw off
extern "C" void fn_801FF484(void *arg0, void *arg1) {
    const char *name = *(const char **)arg1;
    int i = 0;
    char *entry = (char *)arg0;
    while (i < *(int *)((char *)arg0 + 0x2C0)) {
        if (stricmp(name, entry) == 0) {
            entry = (char *)arg0 + i * 0x58;
            goto found;
        }
        entry += 0x58;
        i++;
    }
    entry = 0;
found:
    if (entry == 0) {
        if (*(int *)((char *)arg0 + 0x2C0) >= 8) {
            fn_802E317C(lbl_8033B8EC, 8);
        }
        entry = (char *)arg0 + *(int *)((char *)arg0 + 0x2C0) * 0x58;
        fn_801FF58C(arg0, entry, *(const char **)arg1);
        *(int *)((char *)arg0 + 0x2C0) += 1;
    }
    if (*(int *)(entry + 0x50) + 1 > 8) {
        fn_802E317C(lbl_8033B90C, 8);
    }
    int count = *(int *)(entry + 0x50);
    *(void **)(entry + 0x10 + count * 4) = arg1;
    *(int *)(entry + 0x50) = count + 1;
}
extern "C" void fn_801FF58C(void* unused, char* dst, const char* src) {
    strncpy(dst, src, 0x10);
    dst[0xF] = 0;
    *(int*)(dst + 0x50) = 0;
    *(int*)(dst + 0x54) = 0;
}

void fn_801FF5D4(void* arg0, void* arg1, float farg0) {
    char *entry = (char *)arg1;
    int i = 0;
    while (i < *(int *)((char *)arg1 + 0x54)) {
        ((void (*)(void*, float))fn_801FCF74)(*(void **)(entry + 0x30), farg0);
        entry += 4;
        i++;
    }
}

#pragma dont_inline on
void fn_801FF644(void* arg0, void* arg1) {
    void* entry;
    int i;
    i = 0;
    entry = arg1;
    while (i < *(int*)((char*)arg1 + 0x54)) {
        fn_801FCFC8(*(void**)((char*)entry + 0x30));
        entry = (char*)entry + 4;
        i++;
    }
}
#pragma dont_inline reset
extern "C" void* lbl_8055EC94;
void fn_801FF6A4(void* arg0) {
    lbl_8055EC94 = arg0;
    *(int*)((char*)arg0 + 0x4C0) = 0;
}

extern "C" void* fn_801FF6B4(void* arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055EC94 = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801FF924(void*, void*, float);
void fn_801FF6FC(void* arg0, float farg0) {
    char *entry = (char *)arg0;
    int i = 0;
    while (i < *(int *)((char *)arg0 + 0x4C0)) {
        fn_801FF924(arg0, entry, farg0);
        entry += 0x98;
        i++;
    }
}

extern "C" void fn_801FF994(void*, void*);
extern "C" void fn_801FCAAC(void*, float);
void fn_801FCAC0(void*);
void fn_801FF770(void* arg0) {
    void *entry;
    int i;
    i = 0;
    entry = arg0;
    while (i < *(int *)((char *)arg0 + 0x4C0)) {
        fn_801FF994(arg0, entry);
        entry = (char *)entry + 0x98;
        i++;
    }
}

extern "C" int stricmp(const char *, const char *);
#pragma use_lmw_stmw off
void fn_801FF7D4(void *arg0, void *arg1) {
    const char *name;
    int i;
    char *entry;
    int count;
    name = *(const char **)arg1;
    i = 0;
    entry = (char *)arg0;
    for (;;) {
        if (stricmp(name, entry) == 0) {
            entry = (char *)arg0 + i * 0x98;
            break;
        }
        entry += 0x98;
        i++;
        if (i >= *(volatile int *)((char *)arg0 + 0x4C0)) {
            entry = 0;
            break;
        }
    }
    if (entry == 0) {
        if (*(int *)((char *)arg0 + 0x4C0) >= 8)
            fn_802E317C(lbl_8033B8EC, 8);
        entry = (char *)arg0 + *(int *)((char *)arg0 + 0x4C0) * 0x98;
        fn_801FF8DC(arg0, entry, *(int *)arg1);
        *(int *)((char *)arg0 + 0x4C0) =
            *(int *)((char *)arg0 + 0x4C0) + 1;
    }
    count = *(int *)(entry + 0x90);
    if (count + 1 > 0x10)
        fn_802E317C(lbl_8033B90C, 0x10);
    count = *(int *)(entry + 0x90);
    *(void **)(entry + 0x10 + count * 4) = arg1;
    *(int *)(entry + 0x90) = count + 1;
}
extern "C" void fn_801FF8DC(void *arg0, void *dest, int src) {
    strncpy((char *)dest, (const char *)src, 0x10);
    ((char *)dest)[0xF] = 0;
    *(int *)((char *)dest + 0x90) = 0;
    *(int *)((char *)dest + 0x94) = 0;
}

extern "C" void fn_801FF924(void* arg0, void* arg1, float farg0) {
    char* p;
    int i;
    i = 0;
    p = (char*)arg1;
    goto check;
body:
    fn_801FCAAC(*(void**)(p + 0x50), farg0);
    p += 4;
    i++;
check:
    if (i < *(int*)((char*)arg1 + 0x94))
        goto body;
}

#pragma dont_inline on
extern "C" void fn_801FF994(void* arg0, void* arg1) {
    void* entry;
    int i;
    i = 0;
    entry = arg1;
    while (i < *(int*)((char*)arg1 + 0x94)) {
        fn_801FCAC0(*(void**)((char*)entry + 0x50));
        entry = (char*)entry + 4;
        i++;
    }
}
#pragma dont_inline reset
extern "C" void* fn_8002F634(void*, void*, int, int);
#pragma dont_inline on
SHMainMenu::~SHMainMenu() {
    fn_801FF364((char*)this + 0xE08, -1);
    fn_8002F634((char*)this + 4, (void*)fn_801FCED8, 0x70, 0x20);
}
#pragma dont_inline on
extern "C" void* __dt__10SHMainMenuFv_801FFA68(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_801FF6B4((char*)arg0 + 0x1008, -1);
        fn_8002F634((char*)arg0 + 4, (void*)fn_801FCA14, 0x40, 0x40);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma dont_inline reset
extern "C" void fn_801FEFC4(void) {

}

extern "C" const char lbl_8033B730[];
  void fn_801FC94C(void);
#pragma scheduling invalid_target
extern "C" void* fn_801FEFC8(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(void * volatile *)arg0 = (void *)lbl_8033B730;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_801FF014(void *arg0, int arg1, int arg2, int arg3) {
    void *obj = *(void **)((char *)arg0 + 4);
    int end = arg2 + 0x2C;
    if (obj == 0) {
        obj = fn_801284F8(0x10CC, lbl_8033B86C);
        if (obj != 0) {
            *(void **)obj = (void *)lbl_8033B898;
            fn_8002F53C((char *)obj + 4, (void *)fn_801FF0D4, (void *)fn_801FCED8, 0x70, 0x20);
            *(int *)((char *)obj + 0xE04) = 0;
            fn_801FF354((char *)obj + 0xE08);
        }
        *(void **)((char *)arg0 + 4) = obj;
        fn_802CD320(arg1, obj);
    }
    fn_801FF1C4(*(void **)((char *)arg0 + 4), arg2, end);
}
#pragma pop
extern "C" void fn_801FF0D4(void* arg0) {
    *(int*)arg0 = 0;
    *((int*)arg0 + 1) = 0;
}

extern "C" void fn_801FF0E4(void* arg0) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v5(int);
    };
    Obj* obj = *(Obj**)((char*)arg0 + 4);
    if (obj != 0) obj->v5(0);
}

extern "C" void fn_801FF108(void* arg0) {
    fn_801FF420((char*)arg0 + 0xE08);
}

extern "C" void fn_801FF110(void) {

}
struct Obj_801FEF90 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
};


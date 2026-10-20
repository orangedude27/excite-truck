#include <revolution/MTX/vec.h>
#include <revolution/MTX/quat.h>
#include <types.h>
extern "C" void fn_801FEA28(void*);
class SHMainMenu { public: ~SHMainMenu(); };
extern "C" {
extern void* lbl_8055EC98;
extern void* lbl_8055EC94;
extern const char lbl_8033B5D8[];
extern const char lbl_8033B8C8[];
void fn_80128668(void*);
void fn_801FEDA4(void*);
float fn_80129DC4(int, void*, float, float);
extern float lbl_80563034;
extern const char lbl_8033B790[];
void* memset(void*, int, unsigned long);
void fn_801FF5D4(void*, void*, float);
void fn_801FCA54(void*, int, int);
void fn_801FF7D4(void*, void*);
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
extern "C" void fn_801FC94C(void) {
    void *p;
    if ((p = fn_801284F8(8, (const char *)&lbl_8033B5E8)) != 0) {
        *(void **)p = (void *)&lbl_8033B730;
        *(int *)((char *)p + 4) = 0;
    }
}
#pragma pop

void* fn_801FCA14(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801FCB40(void*, float);
extern "C" void fn_801FCAAC(void* arg0, float farg0) {
    if (*(void**)((char*)arg0 + 4) != 0) {
        fn_801FCB40(arg0, farg0);
    }
}

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

void fn_801FCF74(void* arg0) {
    int obj = *(int*)((char*)arg0 + 4);
    if (!obj) return;
    unsigned short type = *(unsigned short*)((char*)obj + 0x16);
    if (type == 1) fn_801FD5E8();
    else if (type == 0) fn_801FD3F0();
    else if (type > 2) fn_802E317C((const char*)lbl_8033B618);
    else fn_801FDF18();
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
    int offset_idx;
    if (idx >= count && idx < count * 2) {
        offset_idx = count * 2 - idx - 1;
    } else if (idx >= 0) {
        offset_idx = idx % count;
    } else {
        offset_idx = -idx;
    }
    return track + 0x10 + offset_idx * 0x24;
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

extern "C" void fn_8012F57C(float*, void*, void*);
extern "C" float lbl_80563030;
extern "C" void fn_801FD320(void* arg0) {
    float q[4];
    float x2, y2, z2, xx, yy, zz, xy, xz, yz, wx, wy, wz;
    fn_8012F57C(q, (char*)arg0 + 0x44, (char*)arg0 + 0x54);
    x2 = q[0] + q[0]; y2 = q[1] + q[1]; z2 = q[2] + q[2];
    xx = q[0] * x2; yy = q[1] * y2; zz = q[2] * z2;
    wx = q[3] * x2; wy = q[1] * z2;
    *(float*)((char*)arg0 + 0xC) = lbl_80563030 - (yy + zz);
    wz = q[3] * y2; xy = q[1] * z2; yz = q[3] * z2;
    *(float*)((char*)arg0 + 0x1C) = lbl_80563030 - (xx + zz);
    xz = q[0] * y2;
    *(float*)((char*)arg0 + 0x28) = wy - wx;
    *(float*)((char*)arg0 + 0x24) = xy + wz;
    *(float*)((char*)arg0 + 0x18) = xz - yz;
    *(float*)((char*)arg0 + 0x10) = xz + yz;
    *(float*)((char*)arg0 + 0x14) = xy - wz;
    *(float*)((char*)arg0 + 0x20) = wy + wx;
    *(float*)((char*)arg0 + 0x2C) = lbl_80563030 - (xx + yy);
}

extern "C" void fn_801FEDA4(void*);
extern "C" float fn_80129DC4(int, void*, float, float);
extern "C" float fn_801E7E24(void);
extern "C" void* memset(void*, int, unsigned long);
extern "C" const char lbl_8033B790[];
void* fn_801FE188(void* arg0) {
    *(const char**)arg0 = lbl_8033B790;
    memset((char*)arg0 + 4, 0, 0x30);
    *(int*)((char*)arg0 + 0x34) = 0;
    return arg0;
}

extern "C" void fn_801FEB58(void*);
extern "C" float lbl_80558DC4;
#pragma push
#pragma processor 750
extern "C" double __fabs(double);
#pragma push
#pragma processor 750
__declspec(section ".data") extern float lbl_80558DC4;
extern "C" void fn_801FE448(void* arg0) {
    float delta = fn_801E7E24();
    if ((float)__fabs((double)delta) != lbl_80558DC4) {
        float threshold = lbl_80563034;
        char* item = (char*)arg0 + 4;
        int i = 0;
        while (i < *(int*)((char*)arg0 + 0x34)) {
            float time = *(float*)(item + 4) - delta;
            *(float*)(item + 4) = time;
            if (time <= threshold) {
                fn_801FEB58(*(void**)item);
                void* obj = *(void**)item;
                *(float*)(item + 4) = fn_80129DC4(0, obj, *(float*)((char*)obj + 0x314), *(float*)((char*)obj + 0x318));
            }
            item += 8;
            ++i;
        }
    }
}
#pragma pop
extern "C" void fn_802C7040(int);
float fn_80129DC4(int, void *, float, float);
int fn_801FE88C(void *, void *);
extern const char lbl_8033B638[];
extern const char lbl_8033B654[];
extern int lbl_8033B760;
extern "C" void fn_801FE510(void *arg0, void *arg1) {
    void *p = arg1;
    while (p != 0) {
        fn_802C7040(*(int *)((char *)p + 4));
        p = *(void **)((char *)p + 0xC);
    }
}

void fn_801FE550(void *arg0) {
    *(int **)arg0 = &lbl_8033B760;
    *(int *)((char *)arg0 + 0x94) = 0;
}

void fn_801FE708(void *arg0, void *arg1) {
    char *p = (char *)arg1 + 0x2C;
    int count = *(int *)((char *)arg0 + 0x94);
    if (count >= 4)
        fn_802E317C(lbl_8033B654);
    count = *(int *)((char *)arg0 + 0x94);
    char *slot = (char *)arg0 + count * 0x24;
    *(char **)(slot + 4) = p;
    fn_801FE88C(arg0, slot + 8);
    ++*(int *)((char *)arg0 + 0x94);
}

void fn_801FE77C(void* arg0) {
    char* item = (char*)arg0 + 4;
    int i = 0;
    while (i < *(int*)((char*)arg0 + 0x94)) {
        if (*(unsigned short*)(item + 0x14) == 0)
            fn_801FEDA4(item);
        item += 0x24;
        ++i;
    }
}

void fn_801FE7E8(void* arg0) {
    char* item = (char*)arg0 + 4;
    int i = 0;
    while (i < *(int*)((char*)arg0 + 0x94)) {
        if (*(unsigned short*)(item + 0x14) == 1) {
            float time = *(float*)(item + 0x20) - fn_801E7E24();
            *(float*)(item + 0x20) = time;
            if (time < lbl_80563034) {
                fn_801FEDA4(item);
                *(float*)(item + 0x20) = fn_80129DC4(0, item, *(float*)(item + 0x18), *(float*)(item + 0x1C));
            }
        }
        item += 0x24;
        ++i;
    }
}

extern "C" void* fn_801FE9A8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void* fn_801FE9E8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_801FEEC0(void* arg0, int arg1, int arg2, int arg3) {
    void* obj = *(void**)((char*)arg0 + 4);
    if (obj == 0) {
        obj = fn_801284F8(0x14CC, lbl_8033B86C);
        if (obj != 0) {
            *(void**)obj = (void*)lbl_8033B880;
            fn_8002F53C((char*)obj + 4, (void*)fn_801FEF80, (void*)fn_801FCA14, 0x40, 0x40);
            *(int*)((char*)obj + 0x1004) = 0;
            fn_801FF6A4((char*)obj + 0x1008);
        }
        *(void**)((char*)arg0 + 4) = obj;
        fn_802CD320(arg1, obj);
    }
    fn_801FF2B8(*(void**)((char*)arg0 + 4), arg2, arg2 + 0x2C);
}

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

extern "C" void fn_801FF16C(void* arg0) {
    float value = fn_801E7E24();
    if (fabs(value) > lbl_80558DC4) fn_801FF3AC((char*)arg0 + 0xE08, value);
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

extern "C" void fn_801FF260(void* arg0) {
    float value = fn_801E7E24();
    if (fabs(value) > lbl_80558DC4) fn_801FF6FC((char*)arg0 + 0x1008, value);
}

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
void fn_801FF420(void*);
extern "C" void fn_801FF420(void* arg0) {
    int i = 0;
    char* entry = (char*)arg0;
    while (i < *(int*)((char*)arg0 + 0x2C0)) {
        fn_801FF644(arg0, entry);
        entry += 0x58;
        ++i;
    }
}

extern "C" void fn_801FF58C(void* unused, char* dst, const char* src) {
    strncpy(dst, src, 0x10);
    dst[0xF] = 0;
    *(int*)(dst + 0x50) = 0;
    *(int*)(dst + 0x54) = 0;
}

void fn_801FF5D4(void* arg0, void* arg1, float farg0) {
    int var_r30 = 0;
    int* var_r31 = (int*)arg1;
    do {
        ((void (*)(void*, float))fn_801FCF74)((void*)var_r31[0x30 / 4], farg0);
        var_r31++;
        var_r30++;
    } while (var_r30 < *(int*)((char*)arg1 + 0x54));
}

void fn_801FF644(void* arg0, void* arg1) {
    int var_r30 = 0;
    int* var_r31 = (int*)arg1;
    do {
        fn_801FCFC8((void*)var_r31[0x30 / 4]);
        var_r31++;
        var_r30++;
    } while (var_r30 < *(int*)((char*)arg1 + 0x54));
}

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
    int i = 0;
    char* p = (char*)arg0;
    while (i < *(int*)((char*)arg0 + 0x4C0)) {
        fn_801FF924(arg0, p, farg0);
        p += 0x98;
        i++;
    }
}

void fn_801FF994(void*, void*);
void fn_801FCAAC(void*, float);
void fn_801FCAC0(void*);
void fn_801FF770(void* arg0) {
    char* p;
    int i;
    i = 0;
    p = (char*)arg0;
    goto body;
    do {
body:
        fn_801FF994(arg0, p);
        p += 0x98;
        i++;
    } while (i < *(int*)((char*)arg0 + 0x4C0));
}

void fn_801FF8DC(void *arg0, char *dest, const char *src) {
    strncpy(dest, src, 0x10);
    dest[0xF] = 0;
    *(int *)(dest + 0x90) = 0;
    *(int *)(dest + 0x94) = 0;
}

void fn_801FF924(void* arg0, void* arg1, float farg0) {
    char* p;
    int i;
    i = 0;
    p = (char*)arg1;
    goto body2;
    do {
body2:
        fn_801FCAAC(*(void**)(p + 0x50), farg0);
        p += 4;
        i++;
    } while (i < *(int*)((char*)arg1 + 0x94));
}

void fn_801FF994(void* arg0, void* arg1) {
    int i = 0;
    char* p = (char*)arg1;
    do {
        fn_801FCAC0(*(void**)(p + 0x50));
        p += 4;
        i++;
    } while (i < *(int*)((char*)arg1 + 0x94));
}

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
extern "C" void fn_801FF014(void* arg0, int arg1, int arg2, int arg3) {
    void* obj = *(void**)((char*)arg0 + 4);
    if (obj == 0) {
        obj = fn_801284F8(0x10CC, lbl_8033B86C);
        if (obj != 0) {
            *(void**)obj = (void*)lbl_8033B898;
            fn_8002F53C((char*)obj + 4, (void*)fn_801FF0D4, (void*)fn_801FCED8, 0x70, 0x20);
            *(int*)((char*)obj + 0xE04) = 0;
            fn_801FF354((char*)obj + 0xE08);
        }
        *(void**)((char*)arg0 + 4) = obj;
        fn_802CD320(arg1, obj);
    }
    fn_801FF1C4(*(void**)((char*)arg0 + 4), arg2, arg2 + 0x2C);
}

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


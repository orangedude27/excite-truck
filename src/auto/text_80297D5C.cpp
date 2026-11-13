extern "C" int fn_801284F8(int, const char*);
#include <types.h>
#include <math.h>
    /* forward declarations for functions used by fn_802988A4 */
    extern "C" void fn_80298A48(void);
    extern "C" void* fn_80288208(int);
    extern "C" void* fn_802988A4(void*);
    extern "C" void* fn_8029B938(void*);
extern "C" int fn_8029BD14(int);
extern "C" void* fn_8029A6F4(void*);
extern "C" void* fn_801E87A8(void);
extern "C" void fn_80287B38(void*);
extern "C" char lbl_80349408[];
extern "C" char lbl_803494A4[];
extern "C" char lbl_803494B8[];
extern "C" void fn_80298AD8(void *);
extern "C" int fn_8029BA0C(void *);
extern "C" void fn_8029BDB8(void *);
extern "C" void fn_80299504(void *);
extern "C" void fn_802982A8(void *);
extern "C" void fn_80299988(void);
extern "C" void fn_8029A114(void *);
extern "C" void fn_8029A8B8(void *);

struct Fn80299A88Matrix { float v[9]; };
struct Fn80299A88Frame { float temp[6]; Fn80299A88Matrix matrix, rotation; unsigned char config[0x90]; };

struct Entry {
    float f0, f4, f8, f12, f16, f20;
    char f24, f25;
    float f28;
};

struct XformData {
    float m[9];
    float t[3];
    char pad30[0xE8 - 0x30];
    float v0[3];
    char padF4[0x124 - 0xF4];
    float v1[3];
};

struct Locals {
    char pad0[0x58];  // sp8 at offset 0x58
    float sp8, spC, sp10, sp14, sp18, sp1C;
    float sp20, sp24, sp28, sp2C;
};
extern "C" void fn_8029C084(void*, int);
extern "C" u32 lbl_8055CA90;
extern "C" u32 lbl_8055CA98;
extern "C" u32 lbl_8055CA9C;
extern "C" float lbl_8056459C;
extern "C" float lbl_805645B8;
extern "C" void fn_802991BC(void*);
extern "C" void* fn_802974CC(char*);
extern "C" int fn_801EEFDC(void*, int);
extern "C" int fn_8029AEE8(void*);
extern "C" float lbl_805645C8;
extern "C" float lbl_805645E8;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern "C" int fn_8029C190(void*);

  extern "C" int fn_80287B14(void);
  extern "C" void fn_80299830(void*, int);
  extern "C" void fn_802C8BD0(int);
  extern "C" int fn_802C8DBC(int);
  extern "C" void fn_802C8E48(void);
  extern "C" void fn_802C8D74(void);
      extern "C" void* fn_80299FA8(void*, void*);
    extern "C" unsigned int fn_80299A04(void*, unsigned int, float);
          extern "C" void fn_8028E584(void*, void*, float*, float);
      extern "C" void* fn_80288208(int);
extern "C" void fn_8029AAE0(int, int, void*);
  extern "C" void fn_80288A40(void*, float*);
      extern "C" void fn_8028E398(void*);
    extern "C" void* fn_8029A820(void*, int);
    extern "C" int fn_8029C024(int*);
    extern "C" int fn_80287E20(void *, const char *);
    extern "C" void* fn_80287ED0(float*, s32, const char*, const char*);
    extern "C" void fn_80287F90(float*, s32, const char*, const char*, float*, float, float, void*);
    extern "C" void* fn_8002F37C(void*, void(*)(), s32, s32, s32);
    extern "C" void* fn_8012850C(u32, void*);
  extern "C" int fn_8029C054(int*);
  extern "C" int fn_801EF024(void*);
  extern "C" void* fn_802998F4(void*, int);
  extern "C" void* fn_802992C4(void*, int);
  extern "C" void* fn_80298A4C(void*, int);
  extern "C" void* fn_8029BD54(void*, int);
  extern "C" void* fn_8029B9A4(void*, int);
  extern "C" void* __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_80298250(void*, int);
  extern "C" void fn_80128668(void*);
  extern "C" float fn_801E7E24(void);
    extern "C" void fn_80298B48(void*);
    extern "C" void fn_802976DC(void);
    extern "C" void fn_80128670(int);
  extern "C" void fn_80298FBC(void*, void* = 0);
  extern "C" void fn_802CAC54(int);
  extern "C" void fn_8029BDC4(void*);
  extern "C" void fn_80299544(void* = 0);
    extern "C" void fn_802982C0(void *);
    extern "C" void fn_8029998C(void*);
    extern "C" void fn_80299FE0(void *, void *, float);
    extern "C" void fn_80299A88(void *, void *, unsigned int, float);
    extern "C" char lbl_803494D0[];
    extern "C" void fn_8029998C(void*);
    extern "C" void fn_8029A17C(void* = 0);
  extern void* lbl_8055F7CC;
  extern void* lbl_8055F7E0;
  extern void* lbl_8055F7C8;
  extern void* lbl_8055F7DC;
  extern void* lbl_8055F7C4;
  extern void* lbl_8055F7C0;
  extern void* lbl_8055F7D0;
  extern void* lbl_8055F7D8;
  extern void* lbl_8055F7D4;
  extern "C" int fn_8029AF24(int);
    extern "C" float fn_801E7E18(void);
  extern "C" int fn_80287B24(int);
  extern "C" int fn_8029771C(void*, float*, void*, float);
    extern "C" void fn_80298BBC(void*);
  extern "C" void fn_8029BA8C(void*);
      extern "C" void fn_80299628(void*);
  extern "C" void fn_8029871C(void*, void*, float);
    extern "C" void fn_8029840C(void*, int);
    extern "C" double fn_8002F234(float);
  extern "C" float fn_80129DC4(int, float, float);
    extern "C" void fn_802994C0(void*, unsigned int);
    extern "C" void fn_80299338(void*, unsigned int, void*, void*, void*, short);
    extern float lbl_80564590;
    extern float lbl_805645B8;
    extern float lbl_805645BC;
    extern float lbl_8056459C;
    extern float lbl_80564594;
    extern float lbl_80564598;
    extern float lbl_805645A0;
    extern float lbl_805645A4;
    extern float lbl_805645A8;
    extern float lbl_805645AC;
    extern float lbl_805645B0;
    extern float lbl_805645B4;
    extern float lbl_805645E0;
    __declspec(section ".data") extern float lbl_80558DC4;
    #pragma scheduling invalid_target
    extern "C" int fn_80297D5C(void *out, int value) {
        int i;
        for (i = 1; i < 0x10; ++i) {
            if (i * i == value) {
                *(int *)out = i;
                return 1;
            }
        }
        return 0;
    }
    #pragma scheduling on
    extern "C" int fn_80297D90(void *out, int value) {
        int i;
        for (i = 0; i < 10; i++) {
            if ((1 << i) == value) {
                *(int *)out = i;
                return 1;
            }
        }
        return 0;
    }

    extern "C" void fn_80297DC8(void* arg0) {
     float f0=lbl_805645B4,f1=lbl_805645B0,f2=lbl_805645AC,f3=lbl_805645A8,f4=lbl_805645A4,f5=lbl_805645A0,f6=lbl_8056459C,f7=lbl_80564598,f8=lbl_80564594,f9=lbl_80564590;
     float tmp[6];
     *(int*)((char*)arg0+4)=0xC0; *(float*)((char*)arg0+8)=f9; *(float*)((char*)arg0+0xC)=f8; *(int*)arg0=1;
     tmp[0]=f7; tmp[1]=f8; tmp[2]=f7; tmp[3]=f9; tmp[4]=f9; tmp[5]=f9;
     *(float*)((char*)arg0+0x10)=tmp[0]; *(float*)((char*)arg0+0x14)=tmp[1]; *(float*)((char*)arg0+0x18)=tmp[2];
     *(float*)((char*)arg0+0x1C)=tmp[3]; *(float*)((char*)arg0+0x20)=tmp[4]; *(float*)((char*)arg0+0x24)=tmp[5];
     *(float*)((char*)arg0+0x28)=f6; *(float*)((char*)arg0+0x30)=f5; *(float*)((char*)arg0+0x50)=f9;
     *(float*)((char*)arg0+0x54)=f4; *(float*)((char*)arg0+0x58)=f3; *(float*)((char*)arg0+0x5C)=f2;
     *(float*)((char*)arg0+0x70)=f1; *(float*)((char*)arg0+0x68)=f1; *(float*)((char*)arg0+0x60)=f1;
     *(float*)((char*)arg0+0x74)=f0; *(float*)((char*)arg0+0x6C)=f0; *(float*)((char*)arg0+0x64)=f0;
     *(float*)((char*)arg0+0x80)=f9; *(int*)((char*)arg0+0x84)=0x40; *(unsigned char*)((char*)arg0+0x88)=1; *(int*)((char*)arg0+0x44)=2; *(unsigned char*)((char*)arg0+0x89)=1;
    }

    extern "C" void* fn_8028E61C(void*);
    extern "C" void fn_80297DC8(void*);
    extern "C" void* fn_8028E2F8(void*, void*, void*);
    extern "C" char lbl_80349450[];
    extern void* lbl_8055CA80;
    extern "C" void fn_80297E90(void) {
        char sp8[0x98];
        fn_8028E61C(sp8);
        fn_80297DC8(sp8);
        lbl_8055F7E0 = fn_8028E2F8(sp8, lbl_80349450, lbl_8055CA80);
    }

    extern "C" void fn_80297ED4(void) {
    }

#pragma dont_inline on
/* Initialize race visual/effect subsystems and register the per-frame callback. */
extern "C" void fn_80297ED8(void) {
    char *resourceNames = lbl_80349408;
    int allocatedObject;

    allocatedObject = fn_801284F8(0xC, resourceNames + 0x54);
    if (allocatedObject != 0) {
        allocatedObject = (int)fn_802988A4((void *)allocatedObject);
    }
    lbl_8055F7C8 = (void *)allocatedObject;

    allocatedObject = fn_801284F8(0xA4, resourceNames + 0x64);
    if (allocatedObject != 0) {
        allocatedObject = (int)fn_8029B938((void *)allocatedObject);
    }
    lbl_8055F7D8 = (void *)allocatedObject;

    allocatedObject = fn_801284F8(0xA8, resourceNames + 0x70);
    if (allocatedObject != 0) {
        allocatedObject = fn_8029BD14(allocatedObject);
    }
    lbl_8055F7DC = (void *)allocatedObject;

    allocatedObject = fn_801284F8(0x164, resourceNames + 0x80);
    if (allocatedObject != 0) {
        allocatedObject = (int)fn_8029A6F4((void *)allocatedObject);
    }
    lbl_8055F7D4 = (void *)allocatedObject;

    if ((unsigned int)(*(unsigned int *)((char *)fn_801E87A8() + 4) - 0x00180000) == 0x201) {
        fn_80297E90();
    } else {
        lbl_8055F7E0 = 0;
    }

    fn_80287B38((void *)fn_8029C084);
}
#pragma dont_inline reset
extern "C" void fn_80297FA4(void) {
    /* Release/destroy all active UI animation/state objects and clear their global pointers. */
    if (lbl_8055F7E0) { fn_8028E398(lbl_8055F7E0); lbl_8055F7E0 = 0; }
    if (lbl_8055F7D4) { fn_8029A820(lbl_8055F7D4, 1); lbl_8055F7D4 = 0; }
    if (lbl_8055F7D0) { if (lbl_8055F7D0) fn_80128668(lbl_8055F7D0); lbl_8055F7D0 = 0; }
    if (lbl_8055F7CC) { fn_802998F4(lbl_8055F7CC, 1); lbl_8055F7CC = 0; }
    if (lbl_8055F7C4) { fn_802992C4(lbl_8055F7C4, 1); lbl_8055F7C4 = 0; }
    if (lbl_8055F7C0) { __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_80298250(lbl_8055F7C0, 1); lbl_8055F7C0 = 0; }
    fn_8029BD54(lbl_8055F7DC, 1); lbl_8055F7DC = 0;
    fn_8029B9A4(lbl_8055F7D8, 1); lbl_8055F7D8 = 0;
    fn_80298A4C(lbl_8055F7C8, 1); lbl_8055F7C8 = 0;
}

extern "C" void fn_802980A0(void) {
    fn_80298AD8(lbl_8055F7C8);
    fn_8029BA0C(lbl_8055F7D8);
    fn_8029BDB8(lbl_8055F7DC);
    if (lbl_8055F7C4 != 0) {
        fn_80299504(lbl_8055F7C4);
    }
    if (lbl_8055F7C0 != 0) {
        fn_802982A8(lbl_8055F7C0);
    }
    if (lbl_8055F7CC != 0) {
        ((void (*)(void *))fn_80299988)(lbl_8055F7CC);
    }
    if (lbl_8055F7D0 != 0) {
        fn_8029A114(lbl_8055F7D0);
    }
    if (lbl_8055F7D4 != 0) {
        fn_8029A8B8(lbl_8055F7D4);
    }
}

    extern "C" void fn_80298124(void) {
        fn_80298BBC(lbl_8055F7C8);
        fn_8029BA8C(lbl_8055F7D8);
        void* p = lbl_8055F7C4;
        if (p != 0) {
            ((void (*)(void*))fn_80299628)(p);
        }
    }

extern "C" void fn_80298160(void) {
    /* Run per-frame updates for several global subsystems when the global time delta is non-zero. */
    float timeDelta = fn_801E7E24();
    if (!((float)__fabs((double)timeDelta) <= lbl_80558DC4)) {
        fn_80298B48(lbl_8055F7C8);
        fn_8029BDC4(lbl_8055F7DC);
        if (lbl_8055F7C4 != 0) fn_80299544(lbl_8055F7C4);
        if (lbl_8055F7C0 != 0) fn_802982C0(lbl_8055F7C0);
        if (lbl_8055F7CC != 0) fn_8029998C(lbl_8055F7CC);
        if (lbl_8055F7D0 != 0) fn_8029A17C(lbl_8055F7D0);
    }
}

    extern "C" void* fn_802981EC(unsigned int size, float value) {
        return (void*)fn_80299A04(lbl_8055F7CC, size, value);
    }

extern "C" void fn_802981F8(void* self) {
    float sp8 = lbl_8056459C;
    float spC = lbl_80564590;
    float sp10 = sp8;
    fn_8028E584(lbl_8055F7E0, self, &sp8, sp8);
    fn_80288A40(self, &sp8);
}

  void* __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_80298250(void* self, int arg1) {
      if (self != 0) {
          fn_8028E398(*(void**)((char*)self + 0xB0));
          if (arg1 > 0) {
              fn_80128668(self);
          }
      }
      return self;
  }

  extern "C" void fn_802982A8(void *arg0) {
      *(unsigned char *)((unsigned char *)arg0 + 0x28) = 0;
      *(unsigned char *)((unsigned char *)arg0 + 0x54) = 0;
      *(unsigned char *)((unsigned char *)arg0 + 0x80) = 0;
      *(unsigned char *)((unsigned char *)arg0 + 0xAC) = 0;
  }

  extern "C" void fn_80298BBC(void*);
  extern "C" void fn_8029BA8C(void*);
    extern "C" void fn_80299628(void*);
extern void* lbl_8055F7D8;
extern "C" void fn_8029871C(void*, void*, float);
extern "C" void fn_802982C0(void *arg0) {
    float temp_f31 = fn_801E7E24();
    void *var_r31 = arg0;
    int var_r30 = 0;
    do {
        if (*(unsigned char *)((char *)var_r31 + 0x28) != 0) {
            fn_8029871C(arg0, var_r31, temp_f31);
        }
        var_r30 += 1;
        var_r31 = (char *)var_r31 + 0x2c;
    } while (var_r30 < 4);
}

extern "C" void *fn_80298868(void *);
extern "C" int fn_802984D0(void *, void *, void *, void *, void *, void *);
extern "C" void fn_80299338(void *, unsigned int, void *, void *, void *, short);
extern void *lbl_8055F7C4;
#pragma push
#pragma use_lmw_stmw off
extern "C" int fn_8029833C(void *slotPool, void *param1, void *param2, void *param3, short angle, float value) {
    register int slotIndex;
    short localAngle = angle;
    void *slot = fn_80298868(slotPool);
    if (slot == 0 || fn_802984D0(slotPool, slot, param1, param2, param3, &localAngle) == 0) {
        return -1;
    }
    /* Initializes an allocated 0x2C-byte slot and registers it, returning its index or -1 on failure. */
    *(float *)((char *)slot + 0x24) = value;
    *(char *)((char *)slot + 0x28) = 1;
    slotIndex = ((char *)slot - (char *)slotPool) / 44;
    fn_80299338(lbl_8055F7C4, slotIndex, slot, (char *)slot + 0xC, (char *)slot + 0x18, localAngle);
    return slotIndex;
}

extern "C" void fn_8029840C(void *arg0, int arg1) {
    fn_802994C0(lbl_8055F7C4, arg1);
    *(char *)((char *)arg0 + arg1 * 0x2c + 0x28) = 0;
}

#pragma pop
extern "C" int fn_802984D0(void*, void*, void*, void*, void*, void*);
extern "C" void fn_802994C0(void*, unsigned int);
extern "C" void fn_80299338(void*, unsigned int, void*, void*, void*, short);
extern "C" void fn_80298458(int arg0, int arg1, void* arg2, void* arg3, void* arg4, short arg5) {
    short value = arg5;
    int item = arg0 + arg1 * 0x2c;
    if (fn_802984D0((void*)arg0, (void*)item, arg2, arg3, arg4, &value) != 0) {
        fn_802994C0(lbl_8055F7C4, arg1);
        fn_80299338(lbl_8055F7C4, arg1, (void*)item, (void*)(item + 0xc), (void*)(item + 0x18), value);
    }
}

struct Vec3f { float x, y, z; };
extern "C" void fn_801E9DD4(int, int);
extern "C" void fn_801E9DD8(void);
extern "C" int fn_801E9E30(void*, float*);
extern "C" float PSVECDotProduct(const float*, const float*);
extern "C" double fabs(double);
extern int lbl_8055CA70;
extern int lbl_8055CA7C;
extern "C" int fn_802984D0(void* unused, void* arg1, void* arg2, void* arg3, void* arg4, void* ctx) {
    float* out = (float*)arg1;
    float* base = (float*)arg2;
    float* d1 = (float*)arg3;
    float* d2 = (float*)arg4;
    float p0[3];
    float p1[3];
    float p2[3];
    float e1[3];
    float e2[3];
    float l2;
    p0[0] = base[0]; p0[1] = base[1]; p0[2] = base[2];
    p1[0] = p0[0] + d1[0]; p1[1] = p0[1] + d1[1]; p1[2] = p0[2] + d1[2];
    p2[0] = p0[0] + d2[0]; p2[1] = p0[1] + d2[1]; p2[2] = p0[2] + d2[2];
    fn_801E9DD4(lbl_8055CA70, lbl_8055CA7C);
    if (fn_801E9E30(ctx, p0) == 0 || fn_801E9E30(ctx, p1) == 0 || fn_801E9E30(ctx, p2) == 0) {
        fn_801E9DD8();
        return 0;
    }
    fn_801E9DD8();
    e1[0] = p1[0] - p0[0]; e1[1] = p1[1] - p0[1]; e1[2] = p1[2] - p0[2];
    e2[0] = p2[0] - p0[0]; e2[1] = p2[1] - p0[1]; e2[2] = p2[2] - p0[2];
    if ((float)fabs(PSVECDotProduct(e1, e1)) <= lbl_80558DC4 || (float)fabs(PSVECDotProduct(e2, e2)) <= lbl_80558DC4) {
        return 0;
    }
    out[0] = p0[0]; out[1] = p0[1]; out[2] = p0[2];
    l2 = PSVECDotProduct(e2, e2);
    if (PSVECDotProduct(e1, e1) > l2) {
        out[3] = e1[0]; out[4] = e1[1]; out[5] = e1[2];
        out[6] = e2[0]; out[7] = e2[1]; out[8] = e2[2];
    } else {
        out[3] = e2[0]; out[4] = e2[1]; out[5] = e2[2];
        out[6] = e1[0]; out[7] = e1[1]; out[8] = e1[2];
    }
    return 1;
}

#pragma push
#pragma processor 750
extern "C" void fn_8029871C(void *arg0, void *arg1, float deltaTime) {
    char *entry = (char *)arg1;
    float remaining = *(float *)(entry + 0x24);
    if (deltaTime > remaining) {
        int index = ((int)arg1 - (int)arg0) / 0x2C;
        ((void (*)(void *, int))fn_8029840C)(arg0, index);
        return;
    }
    int mode = 0;
    float firstAngle = lbl_805645B8;
    float secondArg = lbl_80564590;
    *(float *)(entry + 0x24) = remaining - deltaTime;
    float angle = fn_80129DC4(mode, firstAngle, secondArg);
    float angle2 = angle * angle;
    float otherAngle = (float)fn_8002F234(lbl_80564590 - angle2);
    float cosine = fn_80129DC4(mode, -otherAngle, otherAngle);
    volatile float target[3];
    volatile float positions[3];
    target[0] = lbl_8056459C;
    target[1] = lbl_8056459C;
    target[2] = lbl_8056459C;
    float x = *(float *)(entry + 0x00) + *(float *)(entry + 0x0C) * angle;
    positions[0] = x;
    float y = *(float *)(entry + 0x04) + *(float *)(entry + 0x10) * angle;
    positions[1] = y;
    float z = *(float *)(entry + 0x08) + *(float *)(entry + 0x14) * angle;
    positions[2] = z;
    float x2 = x + *(float *)(entry + 0x18) * cosine;
    positions[0] = x2;
    float yAdjusted = y + *(float *)(entry + 0x1C) * cosine;
    positions[1] = yAdjusted;
    float zOffset = *(float *)(entry + 0x20);
    float zVelocity = zOffset * cosine;
    positions[1] = yAdjusted + lbl_805645BC;
    float zFinal = z + zVelocity;
    positions[2] = zFinal;
    ((void (*)(void *, float *, float *, float, float, float, float, float))fn_8028E584)(
        *(void **)((char *)arg0 + 0xB0), (float *)positions, (float *)target, zVelocity, zOffset, z, y, x);
    fn_80288A40((float *)positions, (float *)target);
}
#pragma pop

extern "C" void* fn_80298868(void* arg0) {
    char* p = (char*)arg0;
    int i = 0;
    while (i < 4) {
        if (*(unsigned char*)(p + 0x28) == 0) {
            return (char*)arg0 + i * 0x2C;
        }
        p += 0x2C;
        i++;
    }
    return 0;
}

extern "C" void fn_8029B6E4(void *);
extern "C" void fn_8029B824(void *);
extern "C" float fn_802C9A4C(float);
extern float lbl_80564618;
  /* empty function definition - referenced by address in fn_802988A4 */
  extern "C" void fn_80298A48(void) {
  }

extern "C" void* fn_80298A4C(void* self, int shouldDelete) {
    /* Destructor-like cleanup: destroy owned object at +8, release resource at +4,
       free header-buffer at +0 (stored as ptr-0x10), and optionally free self. */
    if (self != 0) {
        void **fields = (void **)self;
        if (fields[2] != 0) {
            ((void (*)(void *))fn_802976DC)(fields[2]);
            fields[2] = 0;
        }
        fn_8028E398(fields[1]);
        if (fields[0] != 0) fn_80128670((int)fields[0] - 0x10);
        fields[0] = 0;
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

extern "C" void fn_80298AD8(void* arg0) {
    int offset = 0;
    int i = 0;
    while (i < fn_80287B14()) {
        i++;
        {
            char* base = (char*)*(void**)arg0;
            *(unsigned char*)(base + offset + 0x19) = 0;
            offset += 0x20;
        }
    }
}

#pragma scheduling invalid_target
extern "C" void fn_80298B48(void* arg0) {
    int offset = 0;
    int i = 0;
    while (i < fn_80287B14()) {
        char* entry = (char*)*(void**)arg0 + offset;
        if ((unsigned char)entry[0x19] != 0) {
            fn_80298FBC(arg0, entry);
        }
        offset += 0x20;
        i++;
    }
}
#pragma scheduling on
#pragma ppc_psq_save off
static inline void XformRot3(const float *m, const float *src, float *dst) {
    if (dst == src) {
        float x = src[0], y = src[1], z = src[2];
        float r0 = z * m[6] + (x * m[0] + y * m[3]);
        float r1 = z * m[7] + (x * m[1] + y * m[4]);
        float r2 = z * m[8] + (x * m[2] + y * m[5]);
        dst[0] = r0;
        dst[1] = r1;
        dst[2] = r2;
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
}
#pragma push
#pragma processor 750
extern "C" void fn_80298BBC(void *arg0) {
    float v[0x3];
    float now;
    float threshold;
    float reset;
    int offset;
    int i;
    now = fn_801E7E18();
    threshold = lbl_8056459C;
    reset = lbl_805645B8;
    i = 0;
    offset = 0;
    goto test;
    do {
        char *items = *(char **)arg0;
        if (*(float *)(items + offset + 28) > threshold) {
            const float *m = (const float *)fn_80287B24(i);
            float *p = (float *)(*(char **)arg0 + offset);
            XformRot3(m, p, v);
            v[0] += m[9];
            v[1] += m[10];
            v[2] += m[11];
            p = (float *)(*(char **)arg0 + offset);
            if (fn_8029771C(*(void **)((char *)arg0 + 8), v, p, now - p[7]) == 0) {
                *(float *)(*(char **)arg0 + offset + 28) = reset;
            }
        }
        offset += 32;
        i += 1;
test:;
    } while (i < fn_80287B14());
}
#pragma pop
extern "C" void fn_80298DE0(void *arg0, void *arg1, int arg2) {
    int off = (int)arg1 << 5;
    char *e1 = *(char **)arg0 + off;
    if ((unsigned)arg2 != (unsigned)(unsigned char)e1[0x19]) {
        if (arg2 != 0) {
            float now = fn_801E7E18();
            char *e2 = *(char **)arg0 + off;
            *(float *)(e2 + 0x1C) = now;
            void *mat = ((void *(*)(int, void *))fn_80287B24)((int)arg1, (void *)e2);
            char *e3 = *(char **)arg0 + off;
            float tmp[3];
            XformRot3((const float *)mat, (const float *)e3, tmp);
            tmp[0] += ((float *)mat)[9];
            tmp[1] += ((float *)mat)[10];
            tmp[2] += ((float *)mat)[11];
        }
        char *e4 = *(char **)arg0 + off;
        e4[0x19] = (char)arg2;
    }
}

#pragma push
#pragma processor 750
void fn_80298FBC(void *arg0, void *arg1) {
    float *m = (float *)fn_80287B24(((char *)arg1 - *(char **)arg0) / 32);
    float *v = (float *)arg1;
    float out[3];

    if (out == v) {
        float y = v[1];
        float x = v[0];
        float z = v[2];
        float a = x * m[0] + y * m[3];
        float b = x * m[1] + y * m[4];
        float c = x * m[2] + y * m[5];
        out[0] = z * m[6] + a;
        out[1] = z * m[7] + b;
        out[2] = z * m[8] + c;
    } else {
        out[0] = m[3] * v[1] + m[0] * v[0] + m[6] * v[2];
        out[1] = m[4] * v[1] + m[1] * v[0] + m[7] * v[2];
        out[2] = m[5] * v[1] + m[2] * v[0] + m[8] * v[2];
    }
    out[0] += m[9];
    out[1] += m[10];
    out[2] += m[11];
    out[0] += fn_80129DC4(0, -v[3], v[3]);
    out[1] += fn_80129DC4(0, -v[4], v[4]);
    out[2] += fn_80129DC4(0, -v[5], v[5]);
    ((void (*)(void *, float *, float *))fn_8028E584)(*(void **)((char *)arg0 + 4), out, m + 13);
}
#pragma pop

extern "C" char lbl_803494C4[];
extern float lbl_805645D4;
extern float lbl_805645CC;
extern float lbl_805645D0;
extern "C" void fn_802991BC(void *out) {
    /* Build an effect descriptor on the stack and create/store the "engine fire"
       effect instance (lbl_803494C4) in the target object. */
    struct Frame {
        float x00, x04, x08, x0C, x10, x14;
        int x18, x1C;
        float x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
        char pad44[4];
        float x48, x4C;
        char pad50[12];
        int x5C;
        char pad60[8];
        float x68, x6C, x70, x74, x78, x7C, x80, x84, x88, x8C;
        char pad90[8];
        float x98;
        int x9C;
        char xa0[8];
    } effectDesc;

    fn_8028E61C(&effectDesc.x18);
    effectDesc.x1C = 0x80;
    effectDesc.x20 = lbl_805645C8;
    effectDesc.x24 = lbl_80564598;
    effectDesc.x18 = 1;
    effectDesc.x5C = 2;
    effectDesc.x0C = lbl_805645C8;
    effectDesc.x10 = lbl_805645C8;
    effectDesc.x14 = lbl_805645C8;
    effectDesc.x28 = lbl_805645C8;
    effectDesc.x2C = lbl_805645C8;
    effectDesc.x30 = lbl_805645C8;
    effectDesc.x00 = lbl_80564590;
    effectDesc.x04 = lbl_80564590;
    effectDesc.x08 = lbl_80564590;
    effectDesc.x34 = lbl_80564590;
    effectDesc.x38 = lbl_80564590;
    effectDesc.x3C = lbl_80564590;
    effectDesc.x40 = lbl_805645CC;
    effectDesc.x48 = lbl_805645D0;
    effectDesc.x4C = lbl_8056459C;
    effectDesc.x68 = lbl_80564594;
    effectDesc.x6C = lbl_80564598;
    effectDesc.x70 = lbl_805645B8;
    effectDesc.x74 = lbl_80564590;
    effectDesc.x88 = lbl_805645B0;
    effectDesc.x80 = lbl_805645B0;
    effectDesc.x78 = lbl_805645B0;
    effectDesc.x8C = lbl_805645D4;
    effectDesc.x84 = lbl_805645D4;
    effectDesc.x7C = lbl_805645D4;
    effectDesc.x98 = lbl_80564598;
    effectDesc.x9C = 0x40;
    effectDesc.xa0[0] = 1;
    effectDesc.xa0[1] = 1;
    *(void **)((char *)out + 4) = fn_8028E2F8(&effectDesc.x18, lbl_803494C4, lbl_8055CA80);
}

extern "C" void* fn_802992C4(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(int*)((char*)arg0 + 0x34) = 0;
        *(int*)((char*)arg0 + 0x74) = 0;
        *(int*)((char*)arg0 + 0xB4) = 0;
        *(int*)((char*)arg0 + 0xF4) = 0;
        fn_802CAC54(*(int*)((char*)arg0 + 0x100));
        *(int*)((char*)arg0 + 0x100) = -1;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern float fn_801E7E18(int);
extern void fn_801E9DD4(int, int, float, float, float, float, float, float, float, float, float, float, float, float, float);
extern void fn_801E9DD8(void);
extern void fn_801E9E30(short *, float *);
extern int fn_802996B0(int *);
extern int lbl_8055CA70, lbl_8055CA7C;
extern float lbl_8056459C, lbl_805645D8, lbl_805645DC;
extern "C" int fn_802996B0(void *, int *);
#pragma paired_single off
#pragma scheduling invalid_target
extern "C" void fn_80299338(void *arg0, unsigned int arg1, void *arg2, void *arg3, void *arg4, short arg5) {
    struct Work {
        short angle;
        char pad[2];
        int index;
        float points[12];
    } work;
    char *dst;
    float result;
    float x, y, z;
    float x3, y3, z3;
    float x4, y4, z4;
    float x34, y34, z34;
    float *src;
    float *out;
    float step;
    int i;

    work.angle = arg5;
    if (fn_802996B0(arg0, &work.index) == 0)
        return;

    dst = (char *)arg0 + (work.index << 6);
    *(unsigned int *)dst = arg1;
    *(int *)(dst + 0x34) = 1;
    result = fn_801E7E18();

    x = ((float *)arg2)[0] + ((float *)arg3)[0];
    y = ((float *)arg2)[1] + ((float *)arg3)[1];
    z = ((float *)arg2)[2] + ((float *)arg3)[2];
    x += ((float *)arg4)[0];
    *(float *)(dst + 0x38) = result;
    y += ((float *)arg4)[1];
    z += ((float *)arg4)[2];
    *(float *)(dst + 0x3C) = lbl_8056459C;
    x3 = x + ((float *)arg3)[0] * lbl_805645D8;
    y3 = y + ((float *)arg3)[1] * lbl_805645D8;
    z3 = z + ((float *)arg3)[2] * lbl_805645D8;
    x4 = x + ((float *)arg4)[0] * lbl_805645D8;
    y4 = y + ((float *)arg4)[1] * lbl_805645D8;
    z4 = z + ((float *)arg4)[2] * lbl_805645D8;
    x34 = x4 + ((float *)arg3)[0] * lbl_805645D8;
    y34 = y4 + ((float *)arg3)[1] * lbl_805645D8;
    z34 = z4 + ((float *)arg3)[2] * lbl_805645D8;

    work.points[0] = x;
    work.points[1] = y;
    work.points[2] = z;
    work.points[3] = x3;
    work.points[4] = y3;
    work.points[5] = z3;
    work.points[6] = x4;
    work.points[7] = y4;
    work.points[8] = z4;
    work.points[9] = x34;
    work.points[10] = y34;
    work.points[11] = z34;

    fn_801E9DD4(lbl_8055CA70, lbl_8055CA7C);

    src = work.points;
    out = (float *)dst;
    step = lbl_805645DC;
    i = 0;
    do {
        fn_801E9E30((void *)&work.angle, src);
        src[1] = src[1] + step;
        out[1] = src[0];
        out[2] = src[1];
        out[3] = src[2];
        src += 3;
        out += 3;
        ++i;
    } while (i < 4);
    fn_801E9DD8();
}
#pragma scheduling on
#pragma paired_single reset
  extern "C" float fn_801E7E18(void);
extern "C" void* fn_802997F4(void*, int);
extern "C" void fn_802994C0(void* arg0, unsigned int arg1) {
    void* ptr = fn_802997F4(arg0, arg1);
    *(int*)ptr = -1;
    *(int*)((char*)ptr + 0x34) = 2;
    *(float*)((char*)ptr + 0x38) = fn_801E7E18();
}

extern "C" void fn_80299504(void* arg0) {
    float value = lbl_8056459C;
    *(int*)arg0 = -1;
    *(int*)((char*)arg0 + 0x34) = 0;
    *(float*)((char*)arg0 + 0x38) = value;
    *(int*)((char*)arg0 + 0x40) = -1;
    *(int*)((char*)arg0 + 0x74) = 0;
    *(float*)((char*)arg0 + 0x78) = value;
    *(int*)((char*)arg0 + 0x80) = -1;
    *(int*)((char*)arg0 + 0xB4) = 0;
    *(float*)((char*)arg0 + 0xB8) = value;
    *(int*)((char*)arg0 + 0xC0) = -1;
    *(int*)((char*)arg0 + 0xF4) = 0;
    *(float*)((char*)arg0 + 0xF8) = value;
}

#pragma scheduling invalid_target
extern "C" void fn_80299544(void* arg0) {
    float dt = fn_801E7E24();
    float f5 = lbl_80564590;
    float f4 = lbl_8056459C;
    float f6 = lbl_80564594;
    float f2 = lbl_805645E0;
    char* p = (char*)arg0;
    for (int i = 0; i < 4; i++, p += 0x40) {
        int state = *(int*)(p + 0x34);
        if (state == 1) {
            float val = *(float*)(p + 0x3C) + dt * f6;
            if (f5 < val) {
                val = f5;
            }
            if (val < f4) {
                val = f4;
            }
            *(float*)(p + 0x3C) = val;
        } else if (state == 2) {
            float val = *(float*)(p + 0x3C) + (-dt * f6);
            if (f5 < val) {
                val = f5;
            }
            if (val < f4) {
                val = f4;
            }
            *(float*)(p + 0x3C) = val;
            if ((int)(f2 * (float)val) < 1) {
                *(int*)(p + 0x34) = 0;
            }
        }
    }
}
#pragma scheduling on
extern "C" void fn_80299628(void *arg0) {
    /* Bind draw state for arg0+0x100, then (if draw-list mode 0x14 is active) draw each of the 4
       0x40-byte slots whose +0x34 value is set, finalize drawing, and tear down draw state. */
    fn_802C8BD0(*(int *)((char *)arg0 + 0x100));
    if (fn_802C8DBC(0x14) != 0) {
        void *slotPtr = arg0;
        int slotIndex = 0;
        do {
            if (*(int *)((char *)slotPtr + 0x34) != 0) fn_80299830(arg0, slotIndex);
            slotPtr = (char *)slotPtr + 0x40;
            slotIndex++;
        } while (slotIndex < 4);
        fn_802C8E48();
    }
    fn_802C8D74();
}

#pragma scheduling invalid_target
extern "C" int fn_802996B0(void *arg0, int *out) {
 int state, best=-1, found=0;
 state=*(int*)((char*)arg0+0x34);
 if(state==0){*out=0;return 1;}
 if(state==2 && (!found || *(float*)((char*)arg0+0x38)<*(float*)((char*)arg0-8))){best=0;found=1;}
 state=*(int*)((char*)arg0+0x74);
 if(state==0){*out=1;return 1;}
 if(state==2 && (!found || *(float*)((char*)arg0+0x78)<*(float*)((char*)arg0+(best<<6)+0x38))){best=1;found=1;}
 state=*(int*)((char*)arg0+0xB4);
 if(state==0){*out=2;return 1;}
 if(state==2 && (!found || *(float*)((char*)arg0+0xB8)<*(float*)((char*)arg0+(best<<6)+0x38))){best=2;found=1;}
 state=*(int*)((char*)arg0+0xF4);
 if(state==0){*out=3;return 1;}
 if(state==2 && (!found || *(float*)((char*)arg0+0xF8)<*(float*)((char*)arg0+(best<<6)+0x38))){best=3;found=1;}
 if(found)*out=best;
 return found;
}
#pragma scheduling on

extern "C" void *fn_802997F4(void *arg0, int arg1) {
    void *p = arg0;
    int i;
    for (i = 0; i < 4; i++) {
        if (arg1 == *(int *)p) {
            return (char *)arg0 + (i << 6);
        }
        p = (char *)p + 0x40;
    }
    return 0;
}

extern "C" void fn_802C8E00(int arg0, int arg1, float farg0, float farg1, float farg2, float farg3, float farg4);
extern float lbl_805645E0;
extern float lbl_80564590, lbl_8056459C, lbl_805645E0;
extern "C" void fn_80299830(void* arg0, int arg1) {
    /* Draw up to 4 elements for an entry when its scaled alpha value is >= 1. */
    char* var_r31 = (char*)arg0 + (arg1 << 6);
    int temp_r0 = (int)(255.0f * *(float*)(var_r31 + 0x3C));
    if (temp_r0 >= 1) {
        int var_r30 = temp_r0 << 24;
        int var_r29 = 0;
        do {
            float var_f4;
            float var_f5;
            if (var_r29 & 1) var_f4 = lbl_80564590;
            else var_f4 = lbl_8056459C;
            if (var_r29 & 2) var_f5 = lbl_8056459C;
            else var_f5 = lbl_80564590;
            int t = var_r29 ^ 1;
            int temp_r3 = t >> 1;
            t &= var_r29;
            t = temp_r3 - t;
            fn_802C8E00(var_r30, (unsigned int)t >> 31,
                *(float*)(var_r31 + 4), *(float*)(var_r31 + 8), *(float*)(var_r31 + 0xC), var_f4, var_f5);
            var_r29++;
            var_r31 += 0xC;
        } while (var_r29 < 4);
    }
}

extern "C" void fn_80299830(void*, int);
extern "C" void fn_802C8BD0(int);
extern "C" int fn_802C8DBC(int);
extern "C" void fn_802C8E48(void);
extern "C" void fn_802C8D74(void);
extern "C" void* fn_80299FA8(void*, void*);
#pragma scheduling invalid_target
extern "C" void *fn_802998F4(void *container, int freeStorage) {
    /* Destroy each owned 0x9C-byte entry (count at +0x138), reset count, and optionally free storage. */
    if (container != 0) {
        void *entry = container;
        int index = 0;
        for (; index < *(int *)((char *)container + 0x138); entry = (char *)entry + 0x9C, index++) {
            fn_80299FA8(container, entry);
        }
        *(int *)((char *)container + 0x138) = 0;
        if (freeStorage > 0) fn_80128668(container);
    }
    return container;
}
#pragma scheduling on
extern "C" void fn_80299988(void) {
}

extern "C" void fn_8029998C(void* arg0) {
    float temp = fn_801E7E18();
    void* entry = arg0;
    int i = 0;
    while (i < *(int*)((char*)arg0 + 0x138)) {
        fn_80299FE0(arg0, entry, temp);
        entry = (char*)entry + 0x9C;
        i++;
    }
}

extern "C" int fn_802E317C(const char *, ...);
extern "C" unsigned int fn_80299A04(void *arg0, unsigned int arg1, float farg0) {
    if (*(int *)((char *)arg0 + 0x138) >= 2) {
        fn_802E317C(lbl_803494D0);
    }
    fn_80299A88(arg0, (char *)arg0 + *(unsigned int *)((char *)arg0 + 0x138) * 0x9C, arg1, farg0);
    unsigned int count = *(unsigned int *)((char *)arg0 + 0x138);
    *(unsigned int *)((char *)arg0 + 0x138) = count + 1;
    return count;
}

extern "C" double cos(double);
extern "C" double sin(double);
extern "C" float fn_80144514(float, float, float, float, float, float);
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
extern "C" char lbl_803494F0[];
extern float lbl_805645E4, lbl_805645E8, lbl_805645EC, lbl_805645F0, lbl_805645F4;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80299A88(void *arg0, void *out, unsigned int unused, float scale) {
    Fn80299A88Frame frame;
    float *q;
    float *m;
    float *init = (float *)((char *)&frame - 8);
    int count;
    (void)arg0;
    fn_8028E61C(&init[0x68/4]);
    *(int *)&init[0x6c/4] = 0xA0; init[0x70/4] = lbl_80564590; init[0x74/4] = lbl_80564590;
    *(int *)&init[0x68/4] = 1;
    init[0x14/4] = lbl_805645E4; init[0x18/4] = lbl_805645E4; init[0x1c/4] = lbl_805645E4;
    init[0x78/4] = lbl_805645E4; init[0x7c/4] = lbl_805645E4; init[0x80/4] = lbl_805645E4;
    init[8/4] = lbl_80564590; init[0xc/4] = lbl_80564590; init[0x10/4] = lbl_80564590;
    init[0x84/4] = lbl_80564590; init[0x88/4] = lbl_80564590; init[0x8c/4] = lbl_80564590;
    init[0x90/4] = lbl_8056459C; init[0x98/4] = lbl_805645A0;
    init[0xb8/4] = lbl_805645E8; init[0xbc/4] = lbl_805645EC;
    init[0xc0/4] = lbl_805645A8; init[0xc4/4] = lbl_805645AC;
    init[0xd8/4] = lbl_805645B0; init[0xd0/4] = lbl_805645B0; init[0xc8/4] = lbl_805645B0;
    init[0xdc/4] = lbl_805645B4; init[0xd4/4] = lbl_805645B4; init[0xcc/4] = lbl_805645B4;
    init[0xe8/4] = lbl_80564590; *(int *)&init[0xec/4] = 0x40; ((unsigned char*)init)[0xf0]=1;
    *(int *)&init[0xac/4] = 2; ((unsigned char*)init)[0xf1]=1;
    void *res = fn_8028E2F8(&init[0x68/4], lbl_803494F0, lbl_8055CA80);
    *(void**)out = res;
    count = (int)(lbl_805645F0 * scale) < 12 ? (int)(lbl_805645F0 * scale) : 12;
    count = count > 1 ? count : 1;
    q = frame.rotation.v;
    float c = (float)cos((double)(lbl_805645F4 / (float)count));
    float s = (float)sin((double)(lbl_805645F4 / (float)count));
    float neg = -s;
    float zero = lbl_8056459C, one = lbl_80564590;
    float *p=(float*)unused;
    u32 *w = (u32 *)p;
    u32 w8,w7,w6,w5,w4,w3,w2,w1,w0;
    w0=w[0];w1=w[1];w2=w[2];w3=w[3];w4=w[4];w5=w[5];w6=w[6];w7=w[7];w8=w[8];
    q[0]=c; q[1]=s; q[2]=zero; q[3]=neg; q[4]=c;
    q[5]=zero; q[6]=zero; q[7]=zero; q[8]=one;
    u32 *d=(u32 *)frame.matrix.v; d[0]=w0;d[1]=w1;d[2]=w2;d[3]=w3;d[4]=w4;d[5]=w5;d[6]=w6;d[7]=w7;d[8]=w8;
    m = frame.matrix.v;
    if (count > 0) {
    char *cursor=(char*)out;
    for (int n=0; n<count; cursor+=0xc, n++) {
       float product=m[3]*scale;
       float b=p[10], a=p[9], c=p[11];
       *(float *)(cursor+4)=a+product;
       *(float *)(cursor+8)=b+m[4]*scale;
       *(float *)(cursor+0xc)=c+m[5]*scale;
       MatrixMul801FD5E8(m, m, q);
    }
    }
    float endzero=lbl_8056459C;
    *(int*)((char*)out+0x94)=count;
    *(float*)((char*)out+0x98)=endzero;
}
#pragma pop
extern "C" void* fn_80299FA8(void* arg0, void* arg1) {
    fn_8028E398(*(void**)arg1);
    *(void**)arg1 = 0;
}

extern "C" float fn_80129DC4(int, float, float);
extern "C" void fn_80288A58(void *, float *);
extern float lbl_80564600;
#pragma scheduling on
extern "C" void fn_80299FE0(void *unused, void *arg1, float unusedTime) {
    float upper = lbl_80564590;
    float time = *(float *)((char *)arg1 + 0x98);
    if (time > upper - lbl_80558DC4) {
        register void *obj = arg1;
        register char *entry = (char *)obj;
        register int i = 0;
        float previous[3];
        float interpolated[3];
        previous[0] = lbl_8056459C;
        previous[1] = lbl_8056459C;
        previous[2] = lbl_8056459C;
        while (i < *(int *)((char *)obj + 0x94)) {
            float amount = fn_80129DC4(0, lbl_8056459C, lbl_80564590);
            int count = *(int *)((char *)obj + 0x94);
            int nextIndex = (i + 1) % count;
            char *next = (char *)obj + nextIndex * 0xC;
            float z = *(float *)(entry + 0xC);
            float y = *(float *)(entry + 8);
            float x = *(float *)(entry + 4);
            float deltaZ = *(float *)(next + 0xC) - z;
            float deltaY = *(float *)(next + 8) - y;
            float deltaX = *(float *)(next + 4) - x;
            float scaledZ = amount * deltaZ;
            float scaledY = amount * deltaY;
            float scaledX = amount * deltaX;
            float resultZ = z + scaledZ;
            float resultY = y + scaledY;
            float resultX = x + scaledX;
            interpolated[0] = resultX;
            interpolated[1] = resultY;
            interpolated[2] = resultZ;
            ((void (*)(int, float *, float *, float, float, float, float, float, float))fn_8028E584)(
                *(int *)obj, interpolated, previous, resultZ, resultY, scaledZ, x, y, z);
            fn_80288A58(interpolated, previous);
            entry += 0xC;
            i += 1;
        }
        *(float *)((char *)obj + 0x98) += lbl_80564600;
    } else {
        *(float *)((char *)arg1 + 0x98) = time + lbl_80564594;
    }
}
extern "C" void fn_8029A114(void* arg0) {
    float value0 = lbl_8056459C;
    float value1 = lbl_80564590;
    volatile float temp[3];
    *(volatile float *)((char *)arg0 + 4) = value0;
    *(volatile float *)((char *)arg0 + 0) = value1;
    *(volatile float *)((char *)arg0 + 8) = value0;
    *(volatile float *)((char *)arg0 + 0xC) = value0;
    *(volatile float *)((char *)arg0 + 0x10) = value1;
    *(volatile float *)((char *)arg0 + 0x14) = value0;
    *(volatile float *)((char *)arg0 + 0x18) = value0;
    *(volatile float *)((char *)arg0 + 0x1C) = value0;
    *(volatile float *)((char *)arg0 + 0x20) = value1;
    *(volatile float *)((char *)arg0 + 0x24) = value0;
    *(volatile float *)((char *)arg0 + 0x28) = value0;
    *(volatile float *)((char *)arg0 + 0x2C) = value0;
    temp[0] = value0;
    temp[1] = value0;
    temp[2] = value0;
    *(volatile float *)((char *)arg0 + 0x30) = value0;
    *(volatile float *)((char *)arg0 + 0x34) = value0;
    *(volatile float *)((char *)arg0 + 0x38) = value0;
    *(volatile int *)((char *)arg0 + 0x3C) = -1;
    *(volatile int *)((char *)arg0 + 0x40) = -1;
}

extern "C" int fn_8029A290(void*, void*);
extern "C" void fn_8029A60C(void*, void*);
/* If this object has a valid slot index, validate the slot is active and, when
 * it matches the target object for arg0+0x3C, apply/update via fn_8029A60C;
 * otherwise clear the slot index to -1. */
extern "C" void fn_8029A17C(void* arg0) {
    int slotIndex = *(int*)((char*)arg0 + 0x40);
    if (slotIndex != -1) {
        if (*((unsigned char*)lbl_8055F7C0 + slotIndex * 0x2C + 0x28) != 0) {
            void* target = (void*)fn_80287B24(*(int*)((char*)arg0 + 0x3C));
            if (fn_8029A290(arg0, target) != 0) {
                fn_8029A60C(arg0, target);
            }
        } else {
            *(int*)((char*)arg0 + 0x40) = -1;
        }
    }
}

extern "C" void fn_8029A4B4(void*, int);
    extern "C" void fn_8029A208(void* arg0, int arg1, int arg2) {
      int index;
      unsigned char* entry;
      if (arg2 != 0 && *(int*)((char*)arg0 + 0x40) == -1) {
          fn_8029A4B4(arg0, arg1);
        return;
    }
    if (arg2 == 0 && arg1 == *(int*)((char*)arg0 + 0x3C)) {
          register int index2 = *(int*)((char*)arg0 + 0x40);
          if (index2 != -1) {
              entry = (unsigned char*)lbl_8055F7C0 + index2 * 0x2C;
              if (entry[0x28] != 0)
                  ((void (*)(void*, int))fn_8029840C)(lbl_8055F7C0, index2);
            *(int*)((char*)arg0 + 0x40) = -1;
        }
    }
}

#pragma push
#pragma processor 750
extern "C" int fn_8029A290(void* arg0, void* arg1) {
    extern float PSVECSquareDistance(const void*, const void*);
    extern float PSVECDotProduct(const void*, const void*);
    extern float lbl_80564604;
    float threshold = lbl_80564594;
    int result = 1;
    if (PSVECSquareDistance((char*)arg0 + 0x24, (char*)arg1 + 0x24) > threshold) {
        goto done;
    }
    {
    int below = PSVECDotProduct(arg0, arg1) < lbl_80564604;
    if (below == 0) {
        result = 0;
    }
    }
done:
    return result;
}
#pragma pop
extern float lbl_805645C8;
extern float lbl_805645E8;
extern "C" void fn_8029A318(float *a, float *b, float *c, float *d, float x, float y, float z) {
    if ((unsigned char *)b == (unsigned char *)a + 0x30) {
        float t12 = a[12];
        float t13 = a[13];
        float t14 = a[14];
        b[0] = t12*a[0] + t13*a[3] + t14*a[6];
        b[1] = t12*a[1] + t13*a[4] + t14*a[7];
        b[2] = t12*a[2] + t13*a[5] + t14*a[8];
    } else {
        b[0] = a[12]*a[0] + a[13]*a[3] + a[14]*a[6];
        b[1] = a[12]*a[1] + a[13]*a[4] + a[14]*a[7];
        b[2] = a[12]*a[2] + a[13]*a[5] + a[14]*a[8];
    }
    b[0] += a[9];
    b[1] += a[10];
    b[2] += a[11];
    c[0] = a[0] * lbl_805645C8;
    c[1] = a[1] * lbl_805645C8;
    c[2] = a[2] * lbl_805645C8;
    d[0] = a[6] * lbl_805645E8;
    d[1] = a[7] * lbl_805645E8;
    d[2] = a[8] * lbl_805645E8;
}

extern "C" int fn_801EE0C8(int);
extern "C" void fn_802C77F0(int, float *);
extern "C" int lbl_80488648[];
extern "C" float lbl_80564608;
#pragma dont_inline on
extern "C" void fn_8029A4B4(void *arg0, int arg1) {
    register void *dest = arg0;
    register int index = arg1;
    register void *data;
    float a[3], b[3], c[3], home[3], screen[6];
    int selector, handle;
    int *src, *dst;
    register int v0, v1;

    data = (void *)fn_80287B24(index);
    if ((unsigned int)index < 8U)
        selector = lbl_80488648[index];
    else
        selector = 0;
    handle = fn_801EE0C8(selector);
    fn_802C77F0(handle, screen);

    src = (int *)data;
    dst = (int *)dest;
    v0=src[0]; v1=src[1]; dst[0]=v0; dst[1]=v1;
    v0=src[2]; v1=src[3]; dst[2]=v0; dst[3]=v1;
    v0=src[4]; v1=src[5]; dst[4]=v0; dst[5]=v1;
    v0=src[6]; v1=src[7]; dst[6]=v0; dst[7]=v1;
    v0=src[8]; v1=src[9]; dst[8]=v0; dst[9]=v1;
    dst[10]=src[10];
    v0=src[11]; dst[11]=v0;

    home[2] = screen[4];
    home[1] = screen[2];
    home[0] = screen[0];
    *(float *)((char *)dest + 0x30) = home[0];
    *(float *)((char *)dest + 0x34) = home[1];
    *(float *)((char *)dest + 0x38) = home[2];
    *(unsigned int *)((char *)dest + 0x3C) = (unsigned int)index;

    a[0] = lbl_8056459C; a[1] = lbl_8056459C; a[2] = lbl_8056459C;
    b[0] = lbl_8056459C; b[1] = lbl_8056459C; b[2] = lbl_8056459C;
    c[0] = lbl_8056459C; c[1] = lbl_8056459C; c[2] = lbl_8056459C;
    ((void (*)(void *, float *, float *, float *, float, float, float))fn_8029A318)
        (dest, a, b, c, home[0], home[1], home[2]);
    *(int *)((char *)dest + 0x40) =
        fn_8029833C(lbl_8055F7C0, a, b, c, *(short *)((char *)data + 0x30), lbl_80564608);
}

extern "C" void fn_8029A318(float*, float*, float*, float*, float, float, float);
#pragma dont_inline on
extern "C" void fn_8029A60C(void* arg0, void* arg1) {
    volatile float vectors[9];
    volatile unsigned int *src = (volatile unsigned int *)arg1;
    unsigned int v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0;
    register float *pMid;
    register float *pLow;
    float value = lbl_8056459C;

    v0 = src[0];
    vectors[6] = value;
    v1 = src[1];
    pMid = (float *)&vectors[3];
    vectors[7] = value;
    pLow = (float *)&vectors[0];
    v2 = src[2];
    vectors[8] = value;
    v3 = src[3];
    vectors[3] = value;
    v4 = src[4];
    vectors[4] = value;
    v5 = src[5];
    vectors[5] = value;
    v6 = src[6];
    vectors[0] = value;
    v7 = src[7];
    vectors[1] = value;
    v8 = src[8];
    vectors[2] = value;
    v9 = src[9];
    v10 = src[10];
    v11 = src[11];

    *(unsigned int *)((char *)arg0 + 0x00) = v0;
    *(unsigned int *)((char *)arg0 + 0x04) = v1;
    *(unsigned int *)((char *)arg0 + 0x08) = v2;
    *(unsigned int *)((char *)arg0 + 0x0C) = v3;
    *(unsigned int *)((char *)arg0 + 0x10) = v4;
    *(unsigned int *)((char *)arg0 + 0x14) = v5;
    *(unsigned int *)((char *)arg0 + 0x18) = v6;
    *(unsigned int *)((char *)arg0 + 0x1C) = v7;
    *(unsigned int *)((char *)arg0 + 0x20) = v8;
    *(unsigned int *)((char *)arg0 + 0x24) = v9;
    *(unsigned int *)((char *)arg0 + 0x28) = v10;
    *(unsigned int *)((char *)arg0 + 0x2C) = v11;

    ((void (*)(void*, float*, float*, float*))fn_8029A318)(arg0, (float *)&vectors[6], pMid, pLow);
    fn_80298458((int)lbl_8055F7C0, *(int *)((char *)arg0 + 0x40), (void *)&vectors[6], (void *)&vectors[3], (void *)&vectors[0], *(short *)((char *)arg1 + 0x30));
}

extern "C" void* memset(void*, int, unsigned long);
extern "C" void fn_8029A8B8(void *);
extern "C" unsigned int lbl_8055CA8C;
extern "C" char lbl_803494FC[];
extern float lbl_805645C0;
extern float lbl_8056460C;
#pragma scheduling invalid_target
extern "C" void *fn_8029A6F4(void *arg0) {
    struct Local {
        volatile float extra[6];
        unsigned char config[0x8C];
    } local;

    fn_8029A8B8(arg0);
    fn_8028E61C(local.config);
    memset(local.config, 0, 0x8C);

    float value90 = lbl_80564590;
    int one = 1;
    float valueB8 = lbl_805645B8;
    int size = 0x1F4;
    float value9C = lbl_8056459C;
    float value98 = lbl_80564598;
    int two = 2;
    float valueC0 = lbl_805645C0;
    int forty = 0x40;
    float value6460C = lbl_8056460C;

    *(int *)local.config = one;
    *(int *)(local.config + 0x04) = size;
    *(float *)(local.config + 0x08) = value98;
    *(float *)(local.config + 0x0C) = value90;
    local.extra[3] = value9C;
    local.extra[4] = value9C;
    local.extra[5] = value9C;
    *(float *)(local.config + 0x10) = value9C;
    *(float *)(local.config + 0x14) = value9C;
    *(float *)(local.config + 0x18) = value9C;
    local.extra[0] = value90;
    local.extra[1] = value90;
    local.extra[2] = value90;
    *(float *)(local.config + 0x1C) = value90;
    *(float *)(local.config + 0x20) = value90;
    *(float *)(local.config + 0x24) = value90;
    *(float *)(local.config + 0x30) = valueB8;
    *(float *)(local.config + 0x34) = valueC0;
    *(int *)(local.config + 0x44) = two;
    *(float *)(local.config + 0x50) = value90;
    *(float *)(local.config + 0x54) = value90;
    *(float *)(local.config + 0x58) = valueB8;
    *(float *)(local.config + 0x5C) = value90;
    *(float *)(local.config + 0x70) = valueB8;
    *(float *)(local.config + 0x68) = valueB8;
    *(float *)(local.config + 0x60) = valueB8;
    *(float *)(local.config + 0x74) = value90;
    *(float *)(local.config + 0x6C) = value90;
    *(float *)(local.config + 0x64) = value90;
    *(float *)(local.config + 0x80) = value6460C;
    *(int *)(local.config + 0x84) = forty;
    local.config[0x88] = (unsigned char)one;
    local.config[0x89] = (unsigned char)one;

    *(void **)((char *)arg0 + 0x160) =
        ((void *(*)(void *, const char *, int, int, int, int,
                    float, float, float, float, float))fn_8028E2F8)(
            local.config, lbl_803494FC, lbl_8055CA8C, two, size, one,
            valueC0, valueB8, value9C, value90, value98);
    fn_801EEFDC((void *)fn_8029C054, 0xE);
    fn_801EEFDC((void *)fn_8029C024, 0xD);
    return arg0;
}
#pragma scheduling on
extern "C" void* fn_8029A820(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_801EF024((void *)fn_8029C024);
        fn_801EF024((void *)fn_8029C054);
        fn_8028E398(*(void **)((char *)arg0 + 0x160));
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8029A890(void *arg0, void *arg1) {
    *(float *)((char *)arg0 + (int)arg1 * 0x2C + 0x24) = lbl_80564590;
}

extern "C" void fn_8029A8A4(void *arg0, void *arg1) {
    *(unsigned char *)((char *)arg0 + (int)arg1 * 0x2C + 0x28) = 1u;
}

extern "C" void fn_8029A8B8(void* arg0) {
    float value = lbl_805645B8;
    *(unsigned char*)((char*)arg0 + 0x28) = 0;
    *(float*)((char*)arg0 + 0x24) = value;
    *(float*)((char*)arg0 + 0x50) = value;
    *(unsigned char*)((char*)arg0 + 0x54) = 0;
    *(float*)((char*)arg0 + 0x7C) = value;
    *(unsigned char*)((char*)arg0 + 0x80) = 0;
    *(float*)((char*)arg0 + 0xA8) = value;
    *(unsigned char*)((char*)arg0 + 0xAC) = 0;
    *(float*)((char*)arg0 + 0xD4) = value;
    *(unsigned char*)((char*)arg0 + 0xD8) = 0;
    *(float*)((char*)arg0 + 0x100) = value;
    *(unsigned char*)((char*)arg0 + 0x104) = 0;
    *(float*)((char*)arg0 + 0x12C) = value;
    *(unsigned char*)((char*)arg0 + 0x130) = 0;
    *(float*)((char*)arg0 + 0x158) = value;
    *(unsigned char*)((char*)arg0 + 0x15C) = 0;
}

extern float lbl_80558DC4;
extern float lbl_80564610;
extern float lbl_80564614;
extern "C" void fn_8029A904(void* arg0, int arg1, void* arg2, float farg0, float farg1) {
    float* var_f31 = (float*)((char*)arg2 + 0x58);
    float var_f1 = *var_f31;
    float var_f2 = farg1;
    int var_r4 = arg1;
    void* var_r28 = (char*)arg0 + (var_r4 * 0x2C);
    float abs_f3 = fabsf(var_f1);
    float temp_f1 = abs_f3;
    
    if (temp_f1 != lbl_80558DC4) {
        *(unsigned char*)((char*)var_r28 + 0x28) = 0;
        *(float*)((char*)var_r28 + 0x24) = lbl_8056459C;
    }
    
    if ((*(unsigned char*)((char*)var_r28 + 0x28) != 0) || (*(float*)((char*)var_r28 + 0x24) > lbl_8056459C)) {
        if (var_f2 < lbl_80564610) {
            fn_8029AAE0((int)arg0, arg1, arg2);
            
            float* var_f0 = (float*)((char*)arg2 + 0x50);
            int var_i = 1;
            int temp_i = (int)(farg0 * (*var_f0));
            if (temp_i > 1) {
                var_i = temp_i;
            }
            
            int var_r30 = 4;
            if (var_i < 4) {
                var_r30 = var_i;
            }
            
            float temp_f25 = lbl_80564614;
            int var_r26 = 0;
            
            while (var_r26 < var_r30) {
                float* base = (float*)((char*)var_r28 + (var_r26 * 0x10));
                float* var_f27 = (float*)((char*)arg2 + 0x34);
                float diff = (float)(-var_r26) * (farg0 / (float)var_r30);
                
                float f3 = var_f27[2] * diff;
                float f2 = var_f27[0] * diff;
                float f1 = var_f27[1] * diff;
                
                float f0 = temp_f25 * (diff * diff);
                f0 = f1 + f0;
                
                float f26 = f2 + f0;
                
                float sp8 = base[0] + f2;
                float sp12 = base[1] + f26;
                float sp16 = base[2] + f3;
                
                fn_8028E584(*(void**)((char*)arg0 + 0x160), arg2, &sp8, farg0);
                
                var_r26++;
            }
        }
        
        *(unsigned char*)((char*)var_r28 + 0x28) = 0;
        float val = *(float*)((char*)var_r28 + 0x24) - farg0;
        *(float*)((char*)var_r28 + 0x24) = val;
    }
}

#pragma push
#pragma scheduling reset
extern "C" void fn_8029AAE0(int arg0, int arg1, void* arg2) {
    float *out = (float *)((char *)arg0 + arg1 * 0x2C);
    XformData *d = (XformData *)arg2;
    fn_80288208(arg1);
    if (out == d->v0) {
        float m3 = d->m[3], y = d->v0[1], m0 = d->m[0], x = d->v0[0], m4 = d->m[4], m1 = d->m[1], m6 = d->m[6], z = d->v0[2], m5 = d->m[5], m2 = d->m[2], m7 = d->m[7], m8 = d->m[8];
        out[0] = y * m3 + x * m0 + z * m6;
        out[1] = y * m4 + x * m1 + z * m7;
        out[2] = y * m5 + x * m2 + z * m8;
    } else {
        {
            float m3 = d->m[3], m0 = d->m[0], m6 = d->m[6];
            out[0] = d->v0[2] * m6 + (d->v0[0] * m0 + d->v0[1] * m3);
        }
        {
            float m4 = d->m[4], m1 = d->m[1], m7 = d->m[7];
            out[1] = d->v0[2] * m7 + (d->v0[0] * m1 + d->v0[1] * m4);
        }
        {
            float m5 = d->m[5], m2 = d->m[2], m8 = d->m[8];
            out[2] = d->v0[2] * m8 + (d->v0[0] * m2 + d->v0[1] * m5);
        }
    }
    {
        float o0 = out[0], t0 = d->t[0], k = lbl_80564598;
        out[0] = t0 + o0;
        float o1 = out[1], t1 = d->t[1];
        float s1 = t1 + o1;
        out[1] = s1;
        float y1 = k + s1;
        float o2 = out[2], t2 = d->t[2];
        out[2] = t2 + o2;
        out[1] = y1;
    }
    out += 3;
    if (out == d->v1) {
        float m3 = d->m[3], y = d->v1[1], m0 = d->m[0], x = d->v1[0], m4 = d->m[4], m1 = d->m[1], m6 = d->m[6], z = d->v1[2], m5 = d->m[5], m2 = d->m[2], m7 = d->m[7], m8 = d->m[8];
        out[0] = y * m3 + x * m0 + z * m6;
        out[1] = y * m4 + x * m1 + z * m7;
        out[2] = y * m5 + x * m2 + z * m8;
    } else {
        {
            float m3 = d->m[3], m0 = d->m[0], m6 = d->m[6];
            out[0] = d->v1[2] * m6 + (d->v1[0] * m0 + d->v1[1] * m3);
        }
        {
            float m4 = d->m[4], m1 = d->m[1], m7 = d->m[7];
            out[1] = d->v1[2] * m7 + (d->v1[0] * m1 + d->v1[1] * m4);
        }
        {
            float m5 = d->m[5], m2 = d->m[2], m8 = d->m[8];
            out[2] = d->v1[2] * m8 + (d->v1[0] * m2 + d->v1[1] * m5);
        }
    }
    {
        float o0 = out[0], t0 = d->t[0], k = lbl_80564598;
        out[0] = t0 + o0;
        float o1 = out[1], t1 = d->t[1];
        float s1 = t1 + o1;
        out[1] = s1;
        float y1 = k + s1;
        float o2 = out[2], t2 = d->t[2];
        out[2] = t2 + o2;
        out[1] = y1;
    }
}
#pragma pop
extern "C" int fn_8029ADCC(void *arg0);
extern "C" void fn_8029B1B8(void *);
extern "C" void *fn_80288208(int);
extern "C" int fn_80287E20(void *, const char *);
extern "C" void *fn_80287E80(void *, const char *);
extern "C" char lbl_80349508[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" int fn_8029ADCC(void *arg0) {
    class Dummy {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float apply(const char *, float);
    };
    int count;
    void *cursor;
    int i;
    void *obj;
    register float defaultSize;
    /* Initializes exhaust/torch sizes per engine: sets each slot's value (at +0x1C0, stride 4) to 1.0, overriding with "exhaust_torch_size" from the "engine" property when present. */
    fn_8029B1B8(arg0);
    count = fn_80287B14();
    defaultSize = lbl_80564590;
    cursor = arg0;
    i = 0;
    while (i < count) {
        obj = fn_80288208(i);
        *(float *)((char *)cursor + 0x1C0) = defaultSize;
        if (fn_80287E20(obj, (const char *)&lbl_8055CA90) != 0) {
            obj = fn_80287E80(obj, (const char *)&lbl_8055CA90);
            *(float *)((char *)cursor + 0x1C0) = ((Dummy *)obj)->apply(lbl_80349508, *(float *)((char *)cursor + 0x1C0));
        }
        cursor = (char *)cursor + 4;
        i += 1;
    }
    fn_8029AEE8(arg0);
    return (int)arg0;
}
#pragma pop

extern "C" void* __dt__Q210JASDrumSet5TPercFv_8029AE88(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_802CAC54(*(int*)((char*)arg0 + 0x1E4));
        fn_802CAC54(*(int*)((char*)arg0 + 0x1E8));
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" int fn_8029AEE8(void *arg0) {
    memset(arg0, 0, 0x1C0);
    *(int *)((char *)arg0 + 0x1E0) = 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" int fn_8029AF24(int arg0) {
    if (*(int *)((char *)arg0 + 0x1E0) >= 1) {
        register void *obj = (void *)arg0;
        register void *entry = obj;
        register int total = 0;
        register int i = 0;
        while (i < fn_80287B14()) {
            if (*(unsigned char *)((char *)entry + 0x35) != 0) {
                void *info = fn_80288208(i);
                total += *(int *)((char *)info + 0x24);
            }
            entry = (char *)entry + 0x38;
            i += 1;
        }
        int value = *(int *)((char *)obj + 0x1EC);
        float ratio = (float)(-value) / lbl_80564618;
        float temp_f31 = ((float (*)(float))fn_802C9A4C)(ratio);
        fn_802C8BD0(*(int *)((char *)obj + 0x1E8));
        if (fn_802C8DBC(total * 4) != 0) {
            fn_8029B6E4(obj);
            fn_802C8E48();
            fn_802C8D74();
        }
        fn_802C8BD0(*(int *)((char *)obj + 0x1E4));
        if (fn_802C8DBC(total * 8) != 0) {
            fn_8029B824(obj);
            fn_802C8E48();
            fn_802C8D74();
        }
        ((float (*)(float))fn_802C9A4C)(temp_f31);
    }
}
#pragma pop
extern "C" int fn_80287B24(int);
extern "C" void fn_801BFD34(void*, void*, int);
extern "C" void fn_80015B20(void*, void*, int);
extern "C" float fn_80287BC8(float, float);
extern "C" int fn_80287B5C(int);
extern float lbl_80564620;
extern float lbl_805645EC;
extern float lbl_8056461C;
extern "C" void fn_8029B044(void* arg0, int arg1, void* arg2) {
    /* Set or clear the slot at arg1 in the 0x38-byte entry table: when arg2 is
     * non-null, copy its data into the slot, compute and store a scaled value and
     * a random byte, and mark the slot active (updating the active count); when
     * arg2 is null, clear the slot's active flag and decrement the count. */
    int value;
    char* item;
    item = (char*)arg0 + arg1 * 0x38;
    if (arg2 != 0) {
        value = fn_80287B24(arg1);
        fn_801BFD34(item + 0x24, (char*)arg2 + 0x24, value);
        fn_80015B20(item, arg2, value);
        float f = lbl_80564590 + fn_80287BC8(lbl_80564620, lbl_805645EC);
        float scaled = lbl_8056461C * *(float*)((char*)arg0 + arg1 * 4 + 0x1C0);
        *(float*)(item + 0x30) = scaled * f;
        *(unsigned char*)(item + 0x34) = (unsigned char)fn_80287B5C(0x10);
        if (*(unsigned char*)(item + 0x35) == 0) {
            *(unsigned char*)(item + 0x35) = 1;
            *(int*)((char*)arg0 + 0x1E0) += 1;
        }
    } else if (*(unsigned char*)(item + 0x35) != 0) {
        *(unsigned char*)(item + 0x35) = 0;
        *(int*)((char*)arg0 + 0x1E0) -= 1;
    }
}

extern "C" void fn_8029B138(void* arg0, int arg1, float* arg2, float* arg3, float* arg4, float* arg5) {
    float temp_f1;
    float temp_f1_2;
    temp_f1 = *(float*)((char*)arg0 + 0x1F8) * (float)(arg1 & (*(int*)((char*)arg0 + 0x1EC) - 1));
    *arg2 = temp_f1;
    *arg3 = temp_f1 + *(float*)((char*)arg0 + 0x1F8);
    temp_f1_2 = *(float*)((char*)arg0 + 0x1F8) * (float)(arg1 >> *(int*)((char*)arg0 + 0x1F0));
    *arg4 = temp_f1_2;
    *arg5 = temp_f1_2 - *(float*)((char*)arg0 + 0x1F8);
}

extern "C" int fn_802CAC28(int, int);
extern "C" int fn_80297D5C(void*, int);
extern "C" int fn_80297D90(void*, int);
extern "C" int fn_802E317C(const char*, ...);
extern "C" int fn_801284F8(int, const char*);
extern "C" int fn_8029ADCC(void*);
extern "C" int fn_8029BA0C(void*);
extern "C" void* fn_80288208(int);
extern "C" void* fn_80288060(void*, int);
extern "C" int fn_801EF024(void*);
extern "C" int fn_8029C190(void*);
extern "C" void* __dt__Q210JASDrumSet5TPercFv_8029AE88(void*, int);
extern "C" int fn_8029BFF8(void*);
extern int lbl_8055CA84;
extern int lbl_8055CA88;
extern const char lbl_8034951C[];
extern const char lbl_80349550[];
extern double lbl_805645F8;
extern int lbl_8055CA84, lbl_8055CA88;
extern const char lbl_8034951C[], lbl_80349550[];
#pragma dont_inline on
/* Initializes backfire texture handles, validates size/shift params, and caches derived constants. */
extern "C" void fn_8029B1B8(void* arg0) {
    char* p = (char*)arg0;
    *(int*)(p + 0x1E4) = fn_802CAC28(lbl_8055CA84, 0); /* "bfface.tex" */
    *(int*)(p + 0x1E8) = fn_802CAC28(lbl_8055CA88, 0); /* "bfedge.tex" */
    if (fn_80297D5C(p + 0x1EC, 0x10) == 0 || fn_80297D90(p + 0x1F0, *(int*)(p + 0x1EC)) == 0) {
        fn_802E317C(lbl_8034951C); /* "fire: numerical error with backfire textures" */
    }
    int v = *(int*)(p + 0x1F0);
    *(float*)(p + 0x1F8) = lbl_80564590 / (float)*(int*)(p + 0x1EC);
    *(int*)(p + 0x1F4) = 0x10 - (v << 1);
}

extern "C" void fn_8029B138(void* arg0, int arg1, float* arg2, float* arg3, float* arg4, float* arg5);
extern "C" void fn_802C8E00(int, int, float, float, float, float, float);
#pragma push
#pragma processor 750
extern "C" void fn_8029B274(void *arg0, float *c, unsigned char arg2, void *arg3, void *arg4, float f, float arg6) {
    struct V3 { float x, y, z; };
    V3 *a = (V3 *)arg3;
    V3 *b = (V3 *)arg4;
    V3 t, s, r, q;
    float sp14, sp10, spC, sp8;
    float neg, h1, h2, px, py, pz;

    fn_8029B138(arg0, arg2, &sp14, &sp10, &spC, &sp8);
    neg = -f;
    px = c[0] + a->x * neg;
    py = c[1] + a->y * neg;
    q.x = px;
    q.y = py;
    h1 = lbl_8056460C * f;
    h2 = lbl_805645D8 * f;
    pz = c[2] + a->z * neg;
    q.x = px + b->x * f;
    q.y = py + b->y * f;
    q.z = pz + b->z * f;
    r.x = q.x + a->x * h1;
    r.y = q.y + a->y * h1;
    r.z = q.z + a->z * h1;
    s.x = q.x + b->x * h2;
    s.y = q.y + b->y * h2;
    s.z = q.z + b->z * h2;
    t.x = r.x + b->x * h2;
    t.y = r.y + b->y * h2;
    t.z = r.z + b->z * h2;
    fn_802C8E00(0xC0FFFFFF, 0, q.x, q.y, q.z, sp14, spC);
    fn_802C8E00(0xC0FFFFFF, 0, r.x, r.y, r.z, sp10, spC);
    fn_802C8E00(0xC0FFFFFF, 1, s.x, s.y, s.z, sp14, sp8);
    fn_802C8E00(0xC0FFFFFF, 1, t.x, t.y, t.z, sp10, sp8);
}
#pragma pop

#pragma push
#pragma processor 750
extern "C" void fn_8029B43C(void *arg0, void *entry, unsigned char arg2, float f, float, float, float, float) {
    float *p = (float *)entry;
    float v[12];
    float sp14, sp10, spC, sp8;
    float neg, h, a, b, c;
    float neg2, h2, a2, b2, c2;

    fn_8029B138(arg0, arg2, &sp14, &sp10, &spC, &sp8);
    neg = -f;
    a = p[6];
    b = p[7];
    c = p[8];
    h = lbl_8056460C * f;
    v[0] = p[9] + a * neg;
    v[1] = p[10] + b * neg;
    v[2] = p[11] + c * neg;
    v[3] = v[0] + p[3] * h;
    v[4] = v[1] + p[4] * h;
    v[5] = v[2] + p[5] * h;
    v[6] = v[0] + a * h;
    v[7] = v[1] + b * h;
    v[8] = v[2] + c * h;
    v[9] = v[3] + a * h;
    v[10] = v[4] + b * h;
    v[11] = v[5] + c * h;
    fn_802C8E00(0xC0FFFFFF, 0, v[0], v[1], v[2], sp14, spC);
    fn_802C8E00(0xC0FFFFFF, 0, v[3], v[4], v[5], sp10, spC);
    fn_802C8E00(0xC0FFFFFF, 1, v[6], v[7], v[8], sp14, sp8);
    fn_802C8E00(0xC0FFFFFF, 1, v[9], v[10], v[11], sp10, sp8);

    neg2 = -f;
    a2 = p[0];
    b2 = p[1];
    c2 = p[2];
    h2 = lbl_8056460C * f;
    v[0] = p[9] + a2 * neg2;
    v[1] = p[10] + b2 * neg2;
    v[2] = p[11] + c2 * neg2;
    v[3] = v[0] + p[3] * h2;
    v[4] = v[1] + p[4] * h2;
    v[5] = v[2] + p[5] * h2;
    v[6] = v[0] + a2 * h2;
    v[7] = v[1] + b2 * h2;
    v[8] = v[2] + c2 * h2;
    v[9] = v[3] + a2 * h2;
    v[10] = v[4] + b2 * h2;
    v[11] = v[5] + c2 * h2;
    fn_802C8E00(0xC0FFFFFF, 0, v[0], v[1], v[2], sp14, spC);
    fn_802C8E00(0xC0FFFFFF, 0, v[3], v[4], v[5], sp10, spC);
    fn_802C8E00(0xC0FFFFFF, 1, v[6], v[7], v[8], sp14, sp8);
    fn_802C8E00(0xC0FFFFFF, 1, v[9], v[10], v[11], sp10, sp8);
}
#pragma pop
/* One 0x38-byte drawing slot per track of the note renderer: the object the
 * fn_8029B6E4 / fn_8029B824 / fn_8029BA0C family walks starts with an array
 * of these, fn_80287B14() of them, one per track. */
struct NoteSlot {
    Vec3f xAxis;          /* 0x00 transform, the note's with the track's applied */
    Vec3f yAxis;          /* 0x0C */
    Vec3f zAxis;          /* 0x18 */
    Vec3f position;       /* 0x24 where the sprite is placed */
    volatile float scale; /* 0x30 sprite size; read again after the calls below */
    unsigned char cell;   /* 0x34 which cell of the sprite sheet to draw */
    unsigned char inUse;  /* 0x35 the track has something to draw */
    unsigned char pad_36[2];
};

/* fn_80288208's track record; only the number of notes it holds is read here. */
struct Track {
    unsigned char pad_0[0x24];
    int noteCount; /* 0x24 */
};

/* fn_80288060's note: the transform the track's own matrix is applied to. */
struct Note {
    Vec3f xAxis;    /* 0x00 */
    Vec3f yAxis;    /* 0x0C */
    Vec3f zAxis;    /* 0x18 */
    Vec3f position; /* 0x24 */
};

extern "C" void *fn_802C86DC(void);
extern "C" void fn_8029B274(void *arg0, float *arg1, unsigned char arg2, void *arg3, void *arg4, float farg0, float arg6);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Draw one sprite per note now playing: for every track that is switched on,
 * copy each note's transform into that track's slot (with the track's own
 * transform applied), place the sprite above the note by the slot's scale and
 * hand it to fn_8029B274, which emits the camera-facing quad into the draw
 * list. */
extern "C" void fn_8029B6E4(void *arg0) {
    float center[3];
    int trackMatrix;
    struct NoteSlot *entry;
    struct NoteSlot *slot;
    float *viewRight;
    float *viewUp;
    int trackIndex;
    struct Track *track;
    int noteCount;
    int noteIndex;
    struct Note *note;
    float sizeFactor;
    float scale;
    float finalScale;
    viewRight = (float *)fn_802C86DC();
    viewUp = (float *)((char *)fn_802C86DC() + 0xC);
    sizeFactor = lbl_805645C8;
    entry = (struct NoteSlot *)arg0;
    slot = (struct NoteSlot *)arg0;
    trackIndex = 0;
    while (trackIndex < fn_80287B14()) {
        if (entry->inUse != 0) {
            track = (struct Track *)fn_80288208(trackIndex);
            noteCount = track->noteCount;
            noteIndex = 0;
            while (noteIndex < noteCount) {
                note = (struct Note *)fn_80288060(track, noteIndex);
                trackMatrix = fn_80287B24(trackIndex);
                fn_801BFD34(&slot->position, &note->position, trackMatrix);
                fn_80015B20(slot, note, trackMatrix);
                scale = entry->scale;
                center[0] = slot->position.x + slot->yAxis.x * scale;
                center[1] = slot->position.y + slot->yAxis.y * scale;
                center[2] = slot->position.z + slot->yAxis.z * scale;
                finalScale = entry->scale;
                fn_8029B274(arg0, center, entry->cell, viewRight, viewUp, sizeFactor * finalScale, scale);
                ++noteIndex;
            }
        }
        entry++;
        slot++;
        ++trackIndex;
    }
}
#pragma pop
extern "C" void* fn_80288060(void*, int);
extern "C" void fn_8029B43C(void*, void*, unsigned char, float, float, float, float, float);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
extern "C" void fn_8029B824(void *arg0) {
    int i = 0;
    char *entry = (char *)arg0;
    char *item = (char *)arg0;
    while (i < fn_80287B14()) {
        if (*(unsigned char *)(entry + 0x35) != 0) {
            void *info = fn_80288208(i);
            int count = *(int *)((char *)info + 0x24);
            int j = 0;
            while (j < count) {
                void *object = fn_80288060(info, j);
                int value = fn_80287B24(i);
                fn_801BFD34(item + 0x24, (char *)object + 0x24, value);
                fn_80015B20(item, object, value);
                float scale = *(float *)(entry + 0x30);
                float x = *(float *)(item + 0x24) + *(float *)(item + 0x0C) * scale;
                float y = *(float *)(item + 0x28) + *(float *)(item + 0x10) * scale;
                float z = *(float *)(item + 0x2C) + *(float *)(item + 0x14) * scale;
                fn_8029B43C(arg0, entry, *(unsigned char *)(entry + 0x34), scale, *(float *)(item + 0x14) * scale, y, x, *(float *)(item + 0x0C) * scale);
                ++j;
            }
        }
        entry += 0x38;
        item += 0x38;
        ++i;
    }
}
#pragma pop
extern "C" void* fn_8029B938(void* arg0) {
    int result = fn_801284F8(0x1FC, lbl_80349550);
    if (result != 0) {
        result = fn_8029ADCC((void*)result);
    }
    *(int*)arg0 = result;
    fn_801EEFDC((void*)fn_8029BFF8, 4);
    fn_8029BA0C(arg0);
    return arg0;
}

extern "C" void fn_8029BEF8(void *);
extern "C" int fn_8029C190(void*);
extern "C" int fn_801EEFDC(void*, int);

void* fn_8029B9A4(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_801EF024((void*)fn_8029BFF8);
        ((void (*)(void*, int))__dt__Q210JASDrumSet5TPercFv_8029AE88)(*(void**)arg0, 1);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" int fn_8029AEE8(void *);
#pragma use_lmw_stmw off
extern "C" int fn_8029BA0C(void *arg0) {
    char *entry = (char *)arg0;
    int i = 0;
    char *base = (char *)arg0;
    int zero = 0;
    int one = 1;
    while (i < fn_80287B14()) {
        void *info = fn_80288208(i);
        if (*(int *)((char *)info + 0x24) > 0) {
            *(int *)(entry + 4) = one;
        } else {
            *(int *)(entry + 4) = zero;
        }
        *(int *)(entry + 0x14) = zero;
        entry += 0x14;
        i++;
    }
    return fn_8029AEE8(*(void **)base);
}
#pragma use_lmw_stmw reset
extern "C" void fn_8029BA8C(void* arg0) {
    fn_8029AF24(*(int*)arg0);
}

extern "C" void *fn_80288060(void *, int);
extern "C" int lbl_802FA9F0[];
extern float lbl_805645C4;
#pragma scheduling invalid_target
extern "C" void fn_8029BA94(void *arg0, void *arg1) {
    struct Args {
        int index;
        float rate;
        int unused;
        int value;
    };
    int count;
    int index;
    char *record;
    int size;
    void *info;
    int value;

    if (((const Args *)arg1)->index < 0)
        return;
    count = fn_80287B14();
    index = ((const Args *)arg1)->index;
    if (index >= count)
        return;
    record = (char *)arg0 + index * 0x14;
    switch (((*(unsigned int *)(record + 4)) & 0xF)) {
    case 1:
        info = fn_80288208(index);
        index = ((const Args *)arg1)->index;
        value = ((const Args *)arg1)->value;
        size = *(int *)((char *)info + 0x24);
        record = (char *)arg0 + index * 0x14;
        if (value < 0) {
            *(int *)(record + 4) = 2;
            *(float *)(record + 8) = ((const Args *)arg1)->rate;
            *(float *)(record + 0xC) = fn_80287BC8(lbl_80564598, lbl_80564590);
            value = fn_80287B5C(size);
            *(int *)(record + 0x10) = value;
            value = ((int *)lbl_802FA9F0)[value] % size;
            *(int *)(record + 0x14) = (int)fn_80288060(info, value);
        } else {
            *(int *)(record + 4) = 0x12;
            *(float *)(record + 8) = ((const Args *)arg1)->rate;
            float result = fn_80287BC8(lbl_805645C4, lbl_805645C0);
            int remainderSource = ((const Args *)arg1)->value;
            int zero = 0;
            *(float *)(record + 0xC) = result;
            value = remainderSource % size;
            *(int *)(record + 0x10) = zero;
            *(int *)(record + 0x14) = (int)fn_80288060(info, value);
        }
        break;
    default:
        break;
    }
}
#pragma scheduling invalid_target
extern "C" void fn_8029BBD4(void *arg0, void *arg1, int arg2) {
    void *base = arg0;
    char *record = (char *)base + (int)arg1 * 0x14;
    int index = (int)arg1;
    unsigned int state;
    if (arg2 == 0) {
        if (*(int *)(record + 4) != 0) *(int *)(record + 4) = 3;
        *(int *)(record + 0x14) = 0;
        goto done;
    }
    state = *(unsigned int *)(record + 4);
    if (state == 3) {
        *(int *)(record + 4) = 1;
        goto done;
    }
    if ((state & 0xF) != 2) goto done;
    float deltaTime = fn_801E7E24();
    float threshold = lbl_8056459C;
    float currentTime = *(float *)(record + 0xC);
    float elapsed = currentTime - deltaTime;
    *(float *)(record + 0xC) = elapsed;
    if (elapsed < threshold) {
        *(int *)(record + 4) = 1;
        *(float *)(record + 0xC) = threshold;
        *(int *)(record + 0x14) = 0;
        goto done;
    }
    if ((*(unsigned int *)(record + 4) & 0x10) != 0) goto done;
    if (fn_80287B5C(0x28) != 0) goto done;
    void *info = fn_80288208(index);
    volatile int *table = (volatile int *)lbl_802FA9F0;
    int size = *(volatile int *)((char *)info + 0x24);
    int sequence = *(int *)(record + 0x10) + 1;
    sequence %= 8;
    int seed = table[sequence];
    *(int *)(record + 0x10) = sequence;
    int value = seed % size;
    *(void **)(record + 0x14) = fn_80288060(info, value);
done:
    fn_8029B044(*(void **)base, index, *(void **)(record + 0x14));
}

#pragma scheduling on

#pragma scheduling off
extern "C" int fn_8029BD14(int arg0) {
    fn_8029BEF8((void*)arg0);
    fn_801EEFDC((void*)fn_8029C190, 9);
    return arg0;
}
#pragma scheduling reset
extern "C" void* fn_8029BD54(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_801EF024((void*)fn_8029C190);
        fn_8028E398(*(void**)arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8029BEF8(void *);
extern "C" int fn_801EEFDC(void*, int);
extern "C" int fn_8029C190(void*);
extern "C" void* fn_80288208(int);
extern "C" int fn_80287B14(void);
extern "C" int fn_8029AEE8(void*);
extern "C" int fn_8029AF24(int);
extern "C" void fn_8029BDB8(void *arg0) {
    *(int *)((char *)arg0 + 0xA4) = 0;
}

extern "C" void fn_80288A58(void*, float*);
extern "C" void fn_8029BEF8(void *);
extern "C" int fn_801EEFDC(void*, int);
extern "C" int fn_8029C190(void*);
extern "C" void* fn_80288208(int);
extern "C" int fn_80287B14(void);
extern "C" int fn_8029AEE8(void*);
#pragma scheduling invalid_target
extern "C" void fn_8029BDC4(void* arg0) {
    float values[3];
    char* entry = (char*)arg0 + 4;
    int i = 0;
    values[0] = lbl_8056459C;
    values[1] = lbl_8056459C;
    values[2] = lbl_8056459C;
    while (i < *(int*)((char*)arg0 + 0xA4)) {
        if (*(unsigned char*)(entry + 0x10)) {
            fn_80288A58(entry, values);
            fn_8028E584(*(void**)arg0, entry, values, 0.0f);
        }
        entry += 0x14;
        i++;
    }
}
#pragma scheduling on
extern "C" void fn_802CAC54(int);
extern float lbl_805645B8;
extern "C" void fn_8029A890(void*, void*);
extern "C" void fn_8029BA94(void*, void*);
extern "C" int fn_8029C024(int*);
extern "C" int fn_8029C054(int*);
extern "C" void* fn_802974CC(char*);
extern "C" void fn_8029BE54(void*, void*);
#pragma scheduling invalid_target
void fn_8029BE54(void* arg0, void* arg1) {
    register char* scan = (char*)arg0;
    register int count = *(int*)((char*)arg0 + 0xA4);
    register unsigned int key;
    register int i = 0;
    for (; i < count; ++i) {
        key = *(volatile unsigned int*)((char*)arg1 + 0xC);
        if (key == *(unsigned int*)(scan + 0x10)) {
            i *= 0x14;
            register unsigned int c;
            register unsigned int b;
            register unsigned int a;
            a = *(volatile unsigned int*)arg1;
            b = *(volatile unsigned int*)((char*)arg1 + 4);
            c = *(volatile unsigned int*)((char*)arg1 + 8);
            char* dst = (char*)arg0;
            dst += i;
            *(unsigned int*)(dst + 4) = a;
            register unsigned char d = *(volatile unsigned char*)((char*)arg1 + 0x10);
            *(unsigned int*)(dst + 8) = b;
            *(unsigned int*)(dst + 0xC) = c;
            *(unsigned int*)(dst + 0x10) = key;
            *(unsigned char*)(dst + 0x14) = d;
            return;
        }
        scan += 0x14;
    }
    key = count * 0x14;
    char* dst = (char*)arg0;
    dst += key;
    register unsigned int c = *(volatile unsigned int*)((char*)arg1 + 8);
    register unsigned int b = *(volatile unsigned int*)((char*)arg1 + 4);
    register unsigned int a = *(volatile unsigned int*)arg1;
    *(unsigned int*)(dst + 4) = a;
    key = *(volatile unsigned int*)((char*)arg1 + 0xC);
    *(unsigned int*)(dst + 8) = b;
    register unsigned char d = *(volatile unsigned char*)((char*)arg1 + 0x10);
    *(unsigned int*)(dst + 0xC) = c;
    *(unsigned int*)(dst + 0x10) = key;
    *(unsigned char*)(dst + 0x14) = d;
    *(int*)((char*)arg0 + 0xA4) = *(int*)((char*)arg0 + 0xA4) + 1;
}
#pragma scheduling invalid_target
/* Build and create the "torch fire" effect (lbl_80349450), storing the result in out. */
extern "C" void fn_8029BEF8(void *out) {
    unsigned char raw[0xA8];
    float b4, b0, g, f, e, d, y, x, c;
    int one, size, size2, count;
    fn_8028E61C(raw + 0x18);
    x = lbl_80564590;
    one = 1;
    y = lbl_805645E4;
    size = 0xC0;
    b0 = lbl_805645B0;
    b4 = lbl_805645B4;
    size2 = 0x40;
    c = lbl_80564598;
    count = 2;
    d = lbl_8056459C;
    e = lbl_805645A0;
    f = lbl_805645A8;
    g = lbl_805645AC;
    *(int*)(raw + 0x18 + 0x04) = size;
    *(float*)(raw + 0x18 + 0x08) = c;
    *(float*)(raw + 0x18 + 0x0C) = x;
    *(int*)(raw + 0x18 + 0x00) = one;
    *(float*)(raw + 0x0C) = y;
    *(float*)(raw + 0x10) = y;
    *(float*)(raw + 0x14) = y;
    *(float*)(raw + 0x18 + 0x10) = y;
    *(float*)(raw + 0x18 + 0x14) = y;
    *(float*)(raw + 0x18 + 0x18) = y;
    *(float*)(raw + 0x00) = x;
    *(float*)(raw + 0x04) = x;
    *(float*)(raw + 0x08) = x;
    *(float*)(raw + 0x18 + 0x1C) = x;
    *(float*)(raw + 0x18 + 0x20) = x;
    *(float*)(raw + 0x18 + 0x24) = x;
    *(float*)(raw + 0x18 + 0x28) = d;
    *(float*)(raw + 0x18 + 0x30) = e;
    *(float*)(raw + 0x18 + 0x50) = c;
    *(float*)(raw + 0x18 + 0x54) = y;
    *(float*)(raw + 0x18 + 0x58) = f;
    *(float*)(raw + 0x18 + 0x5C) = g;
    *(float*)(raw + 0x18 + 0x70) = b0;
    *(float*)(raw + 0x18 + 0x68) = b0;
    *(float*)(raw + 0x18 + 0x60) = b0;
    *(float*)(raw + 0x18 + 0x74) = b4;
    *(float*)(raw + 0x18 + 0x6C) = b4;
    *(float*)(raw + 0x18 + 0x64) = b4;
    *(float*)(raw + 0x18 + 0x80) = x;
    *(int*)(raw + 0x18 + 0x84) = size2;
    raw[0x18 + 0x88] = one;
    *(int*)(raw + 0x18 + 0x44) = count;
    raw[0x18 + 0x89] = one;
    *(void**)out = ((void* (*)(void*, void*, void*))fn_8028E2F8)(raw + 0x18, lbl_80349450, lbl_8055CA80);
}
#pragma scheduling on
int fn_8029BFF8(void* arg0) {
    fn_8029BA94(lbl_8055F7D8, arg0);
    return 0x10;
}

extern void* lbl_8055F7D4;
#pragma dont_inline on
extern "C" int fn_8029C024(int *arg0) {
    int value = *(volatile int *)arg0;
    fn_8029A890(lbl_8055F7D4, (void *)value);
    return 4;
}
#pragma dont_inline reset
extern "C" int fn_8029C054(int* arg0) {
    int value = *(volatile int*)arg0;
    fn_8029A8A4(lbl_8055F7D4, (void*)value);
    return 4;
}

  extern "C" void fn_80298DE0(void*, void*, int);
    extern "C" void fn_8029BBD4(void*, void*, int);
  extern "C" void fn_8029A208(void*, int, int);
extern "C" void fn_8029A904(void* arg0, int arg1, void* arg2, float farg0, float farg1);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Updates per-entry animation/effect state for a batch of entries when delta time is non-zero. */
extern "C" void fn_8029C084(void *arg0, int arg1) {
    float temp_f31 = fn_801E7E24();
    if ((float)__fabs((double)temp_f31) <= lbl_80558DC4) {
        return;
    }
    int i = 0;
    while (i < arg1) {
        void *data = *(void **)arg0;
        void *obj = *(void **)((char *)arg0 + 4);
        unsigned char flag = *(unsigned char *)((char *)arg0 + 0xC);
        void *ctx = lbl_8055F7C8;
        int enabled = (flag != 0 && *(int *)((char *)data + 0x5C) == 0xB) ? 1 : 0;
        fn_80298DE0(ctx, obj, enabled);
        fn_8029BBD4(lbl_8055F7D8, obj, flag);
        if (lbl_8055F7D0 != 0) {
            int enabled2 = (flag != 0 && *(int *)((char *)data + 0x5C) == 0xC) ? 1 : 0;
            ((void (*)(void *, void *, int))fn_8029A208)(lbl_8055F7D0, obj, enabled2);
        }
        if (lbl_8055F7D4 != 0) {
            ((void (*)(void *, void *, void *, float, float))fn_8029A904)(lbl_8055F7D4, obj, data, temp_f31, *(float *)((char *)arg0 + 8));
        }
        arg0 = (char *)arg0 + 0x10;
        i += 1;
    }
}
#pragma pop
int fn_8029C190(void* arg0) {
    fn_8029BE54(lbl_8055F7DC, arg0);
    return 0x14;
}
#include "types.h"
extern "C" float lbl_80564598;
extern "C" float lbl_805645C8;
extern "C" float lbl_805645E8;
extern "C" void* fn_8029A6F4(void*);
extern "C" void* fn_801E87A8(void);

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void* fn_802988A4(void* arg0) {
    struct Local {
        volatile float sp8;
        volatile float spC;
        volatile float sp10;
        volatile int sp14;
        volatile int sp18;
        volatile int sp1C;
        volatile float sp20;
        volatile float sp24;
        volatile float sp28;
        volatile float sp2C;
        volatile float sp30;
        volatile float sp34;
    } frame;
    int i;
    int count;
    int off;
    int* srcPtr;
    float f31v;
    float f30v;
    void* tmp;
    void* info;
    count = fn_80287B14();
    tmp = fn_8012850C((count << 5) + 0x10, &lbl_803494A4);
    *(void**)arg0 = fn_8002F37C(tmp, (void(*)())&fn_80298A48, 0, 0x20, count);
    f30v = lbl_8056459C;
    f31v = lbl_805645B8;
    srcPtr = (int*)(void*)&frame.sp14;
    i = 0;
    off = 0;
    goto test;
loop:
    {
        int tSp10;
        int tSpC;
        int tSp8;
        float t2C;
        float t30;
        float t34;
        info = fn_80288208(i);
        if (fn_80287E20(info, (const char*)&lbl_8055CA90) != 0) {
            ((void(*)(void*, void*, int, int))fn_80287ED0)((void*)&frame.sp2C, info, (int)&lbl_8055CA90, (int)&lbl_8055CA98);
            {
                char* dest = (char*)*(void**)arg0 + off;
                t2C = frame.sp2C;
                frame.sp8 = f30v;
                *(float*)dest = t2C;
                tSp8 = *(volatile int*)(volatile void*)&frame.sp8;
                t30 = frame.sp30;
                frame.spC = f30v;
                *(float*)(dest + 4) = t30;
                tSpC = *(volatile int*)(volatile void*)&frame.spC;
                t34 = frame.sp34;
                frame.sp10 = f30v;
                *(float*)(dest + 8) = t34;
                tSp10 = *(volatile int*)(volatile void*)&frame.sp10;
                frame.sp14 = tSp8;
                frame.sp18 = tSpC;
                frame.sp1C = tSp10;
            }
            ((void(*)(void*, void*, int, int, void*))fn_80287F90)((void*)&frame.sp20, info, (int)&lbl_8055CA90, (int)&lbl_8055CA9C, srcPtr);
            {
                char* d = (char*)*(void**)arg0 + off;
                *(float*)(d + 0xC) = frame.sp20;
                *(float*)(d + 0x10) = frame.sp24;
                *(float*)(d + 0x14) = frame.sp28;
            }
            *(char*)((char*)*(void**)arg0 + off + 0x18) = 1;
        } else {
            *(char*)((char*)*(void**)arg0 + off + 0x18) = 0;
        }
        *(char*)((char*)*(void**)arg0 + off + 0x19) = 0;
        *(float*)((char*)*(void**)arg0 + off + 0x1C) = f31v;
    }
    i++;
    off += 0x20;
test:
    if (i < count) goto loop;
    fn_802991BC(arg0);
    *(void**)((char*)arg0 + 8) = fn_802974CC((char*)&lbl_803494B8);
    return arg0;
}
#pragma pop
extern "C" void fn_80287B38(void*);
extern "C" char lbl_80349408[];

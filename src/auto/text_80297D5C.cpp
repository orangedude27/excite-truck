extern "C" int fn_801284F8(int, const char*);
extern "C" void* fn_802988A4(void*);
extern "C" void* fn_8029B938(void*);
extern "C" int fn_8029BD14(int);
extern "C" void* fn_8029A6F4(void*);
extern "C" void* fn_801E87A8(void);
extern "C" void fn_80287B38(void*);
extern "C" char lbl_80349408[];
extern "C" void fn_8029C084(void*, int);
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
  extern "C" void fn_80288A40(void*, float*);
  extern "C" void fn_8028E398(void*);
  extern "C" void* fn_8029A820(void*, int);
  extern "C" int fn_8029C024(int*);
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
    extern "C" void fn_80298FBC(void*);
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
extern "C" void fn_80297ED8(void) {
    char *data = lbl_80349408;
    int value;

    value = fn_801284F8(0xC, data + 0x54);
    if (value != 0) {
        value = (int)fn_802988A4((void *)value);
    }
    lbl_8055F7C8 = (void *)value;

    value = fn_801284F8(0xA4, data + 0x64);
    if (value != 0) {
        value = (int)fn_8029B938((void *)value);
    }
    lbl_8055F7D8 = (void *)value;

    value = fn_801284F8(0xA8, data + 0x70);
    if (value != 0) {
        value = fn_8029BD14(value);
    }
    lbl_8055F7DC = (void *)value;

    value = fn_801284F8(0x164, data + 0x80);
    if (value != 0) {
        value = (int)fn_8029A6F4((void *)value);
    }
    lbl_8055F7D4 = (void *)value;

    if ((unsigned int)(*(unsigned int *)((char *)fn_801E87A8() + 4) - 0x00180000) == 0x201) {
        fn_80297E90();
    } else {
        lbl_8055F7E0 = 0;
    }

    fn_80287B38((void *)fn_8029C084);
}
#pragma dont_inline reset
    extern "C" void fn_80297FA4(void) {
     if (lbl_8055F7E0) { fn_8028E398(lbl_8055F7E0); lbl_8055F7E0=0; }
     if (lbl_8055F7D4) { fn_8029A820(lbl_8055F7D4,1); lbl_8055F7D4=0; }
     if (lbl_8055F7D0) { if (lbl_8055F7D0) fn_80128668(lbl_8055F7D0); lbl_8055F7D0=0; }
     if (lbl_8055F7CC) { fn_802998F4(lbl_8055F7CC,1); lbl_8055F7CC=0; }
     if (lbl_8055F7C4) { fn_802992C4(lbl_8055F7C4,1); lbl_8055F7C4=0; }
     if (lbl_8055F7C0) { __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_80298250(lbl_8055F7C0,1); lbl_8055F7C0=0; }
     fn_8029BD54(lbl_8055F7DC,1); lbl_8055F7DC=0;
     fn_8029B9A4(lbl_8055F7D8,1); lbl_8055F7D8=0;
     fn_80298A4C(lbl_8055F7C8,1); lbl_8055F7C8=0;
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
    float value = fn_801E7E24();
    if (!((float)__fabs((double)value) <= lbl_80558DC4)) {
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
      float sp10 = lbl_8056459C;
      fn_8028E584(lbl_8055F7E0, self, &sp8, lbl_8056459C);
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
extern "C" int fn_8029833C(void *arg0, void *arg1, void *arg2, void *arg3, short arg4, float farg0) {
    register int index;
    short local = arg4;
    void *obj = fn_80298868(arg0);
    if (obj == 0 || fn_802984D0(arg0, obj, arg1, arg2, arg3, &local) == 0) {
        return -1;
    }
    *(float *)((char *)obj + 0x24) = farg0;
    *(char *)((char *)obj + 0x28) = 1;
    index = ((char *)obj - (char *)arg0) / 44;
    fn_80299338(lbl_8055F7C4, index, obj, (char *)obj + 0xC, (char *)obj + 0x18, local);
    return index;
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
    Vec3f* out = (Vec3f*)arg1;
    Vec3f* base = (Vec3f*)arg2;
    Vec3f* d1 = (Vec3f*)arg3;
    Vec3f* d2 = (Vec3f*)arg4;
    Vec3f p0, p1, p2, e1, e2;
    p0 = *base;
    p1.x = p0.x + d1->x; p1.y = p0.y + d1->y; p1.z = p0.z + d1->z;
    p2.x = p0.x + d2->x; p2.y = p0.y + d2->y; p2.z = p0.z + d2->z;
    fn_801E9DD4(lbl_8055CA70, lbl_8055CA7C);
    if (fn_801E9E30(ctx, &p0.x) == 0 || fn_801E9E30(ctx, &p1.x) == 0 || fn_801E9E30(ctx, &p2.x) == 0) {
        fn_801E9DD8();
        return 0;
    }
    fn_801E9DD8();
    e1.x = p1.x - p0.x; e1.y = p1.y - p0.y; e1.z = p1.z - p0.z;
    e2.x = p2.x - p0.x; e2.y = p2.y - p0.y; e2.z = p2.z - p0.z;
    if ((float)fabs(PSVECDotProduct(&e1.x, &e1.x)) <= lbl_80558DC4 || (float)fabs(PSVECDotProduct(&e2.x, &e2.x)) <= lbl_80558DC4) {
        return 0;
    }
    out[0] = p0;
    float l2 = PSVECDotProduct(&e2.x, &e2.x);
    if (PSVECDotProduct(&e1.x, &e1.x) > l2) {
        out[1] = e1;
        out[2] = e2;
    } else {
        out[1] = e2;
        out[2] = e1;
    }
    return 1;
}

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
extern "C" float fn_802C9A4C(int, float);
extern float lbl_80564618;
extern "C" void fn_80298A48(void) {
}

extern "C" void* fn_80298A4C(void* arg0, int arg1) {
    if (arg0 != 0) {
        void **p = (void **)arg0;
        if (p[2] != 0) {
            ((void (*)(void *))fn_802976DC)(p[2]);
            p[2] = 0;
        }
        fn_8028E398(p[1]);
        if (p[0] != 0) fn_80128670((int)p[0] - 0x10);
        p[0] = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
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
        if (*(volatile unsigned char*)((char*)*(void**)arg0 + offset + 0x19) != 0) {
            fn_80298FBC(arg0);
        }
        offset += 0x20;
        i++;
    }
}
#pragma scheduling on
extern "C" void fn_80298BBC(void *arg0) {
    float sp8, spC, sp10;
    float now=fn_801E7E18();
    float reset=lbl_805645B8, threshold=lbl_8056459C;
    int i=0, offset=0;
    for (;;) {
        if (*(float *)((char *)*(void **)arg0+offset+0x1C)>threshold) {
            void *m=(void *)fn_80287B24(i);
            void *p=(char *)*(void **)arg0+offset;
            if (&sp8==p) {
                float x=*(float *)p, y=*(float *)((char *)p+4), z=*(float *)((char *)p+8);
                sp8=y* *(float *)((char *)m+0xC)+x* *(float *)m+z* *(float *)((char *)m+0x18);
                spC=y* *(float *)((char *)m+0x10)+x* *(float *)((char *)m+4)+z* *(float *)((char *)m+0x1C);
                sp10=y* *(float *)((char *)m+0x14)+x* *(float *)((char *)m+8)+z* *(float *)((char *)m+0x20);
            } else {
                sp8=*(float *)((char *)p+4)* *(float *)((char *)m+0xC)+*(float *)p* *(float *)m+*(float *)((char *)p+8)* *(float *)((char *)m+0x18);
                spC=*(float *)((char *)p+4)* *(float *)((char *)m+0x10)+*(float *)p* *(float *)((char *)m+4)+*(float *)((char *)p+8)* *(float *)((char *)m+0x1C);
                sp10=*(float *)((char *)p+4)* *(float *)((char *)m+0x14)+*(float *)p* *(float *)((char *)m+8)+*(float *)((char *)p+8)* *(float *)((char *)m+0x20);
            }
            sp8+=*(float *)((char *)m+0x24); spC+=*(float *)((char *)m+0x28); sp10+=*(float *)((char *)m+0x2C);
            p=(char *)*(void **)arg0+offset;
            if (fn_8029771C(*(void **)((char *)arg0+8),&sp8,p,now-*(float *)((char *)p+0x1C))==0)
                *(float *)((char *)*(void **)arg0+offset+0x1C)=reset;
        }
        offset+=0x20;i++;
        if(i>=fn_80287B14())break;
    }
}

extern "C" char lbl_803494C4[];
extern float lbl_805645D4;
extern float lbl_805645CC;
extern float lbl_805645D0;
extern "C" void fn_802991BC(void *out) {
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
    } frame;

    fn_8028E61C(&frame.x18);
    frame.x1C = 0x80;
    frame.x20 = lbl_805645C8;
    frame.x24 = lbl_80564598;
    frame.x18 = 1;
    frame.x5C = 2;
    frame.x0C = lbl_805645C8;
    frame.x10 = lbl_805645C8;
    frame.x14 = lbl_805645C8;
    frame.x28 = lbl_805645C8;
    frame.x2C = lbl_805645C8;
    frame.x30 = lbl_805645C8;
    frame.x00 = lbl_80564590;
    frame.x04 = lbl_80564590;
    frame.x08 = lbl_80564590;
    frame.x34 = lbl_80564590;
    frame.x38 = lbl_80564590;
    frame.x3C = lbl_80564590;
    frame.x40 = lbl_805645CC;
    frame.x48 = lbl_805645D0;
    frame.x4C = lbl_8056459C;
    frame.x68 = lbl_80564594;
    frame.x6C = lbl_80564598;
    frame.x70 = lbl_805645B8;
    frame.x74 = lbl_80564590;
    frame.x88 = lbl_805645B0;
    frame.x80 = lbl_805645B0;
    frame.x78 = lbl_805645B0;
    frame.x8C = lbl_805645D4;
    frame.x84 = lbl_805645D4;
    frame.x7C = lbl_805645D4;
    frame.x98 = lbl_80564598;
    frame.x9C = 0x40;
    frame.xa0[0] = 1;
    frame.xa0[1] = 1;
    *(void **)((char *)out + 4) = fn_8028E2F8(&frame.x18, lbl_803494C4, lbl_8055CA80);
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
void fn_80299338(void *arg0, int arg1, float *arg2, float *arg3, float *arg4, short arg5) {
    float sp[12];
    int index;
    short angle = arg5;
    float *dst;
    float x0, x1, x2, y0, y1, y2, z0, z1, z2;
    float t0, t1, t2, t3, t4, t5, t6, t7, t8;
    float step;
    int i;
    if (fn_802996B0(&index) != 0) {
        dst = (float *)((char *)arg0 + (index << 6));
        *(int *)dst = arg1;
        *(int *)((char *)dst + 0x34) = 1;
        *(float *)((char *)dst + 0x38) = fn_801E7E18(index << 6);
        *(float *)((char *)dst + 0x3C) = lbl_8056459C;
        x0 = arg2[0] + arg3[0] + arg4[0];
        y0 = arg2[1] + arg3[1] + arg4[1];
        z0 = arg2[2] + arg3[2] + arg4[2];
        x1 = x0 + arg4[0] * lbl_805645D8;
        y1 = y0 + arg3[1] * lbl_805645D8;
        z1 = z0 + arg4[2] * lbl_805645D8;
        t0 = y0 + arg3[1] * lbl_805645D8;
        t1 = x0 + arg3[0] * lbl_805645D8;
        t2 = x1 + arg3[0] * lbl_805645D8;
        t3 = y1 + arg4[1] * lbl_805645D8;
        t4 = z0 + arg3[2] * lbl_805645D8;
        t5 = z1 + arg4[2] * lbl_805645D8;
        sp[0]=x0; sp[1]=y0; sp[2]=z0; sp[3]=t1; sp[4]=t0; sp[5]=t4;
        sp[6]=x1; sp[7]=y1; sp[8]=z1; sp[9]=t2; sp[10]=t3; sp[11]=t5;
        fn_801E9DD4(lbl_8055CA70,lbl_8055CA7C,t0,t1,t2,t3,t4,t5,x0,x1,y0,y1,z0,z1,0.0f);
        step = lbl_805645DC;
        for (i=0;i<4;i++) {
            float out[3];
            fn_801E9E30(&angle, &sp[i*3]);
            sp[i*3+1] += step;
            ((float *)((char *)dst+4))[i*3] = sp[i*3];
            ((float *)((char *)dst+4))[i*3+1] = sp[i*3+1];
            out[2] = sp[i*3+2];
            ((float *)((char *)dst+4))[i*3+2] = out[2];
        }
        fn_801E9DD8();
    }
}

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
extern "C" void fn_80299628(void* arg0) {
    fn_802C8BD0(*(int*)((char*)arg0 + 0x100));
    if (fn_802C8DBC(0x14) != 0) {
        void* p = arg0;
        int i = 0;
        do {
            if (*(int*)((char*)p + 0x34) != 0) fn_80299830(arg0, i);
            p = (char*)p + 0x40;
            i++;
        } while (i < 4);
        fn_802C8E48();
    }
    fn_802C8D74();
}

extern "C" int fn_802996B0(void *arg0, int *out) {
 register int state, best=-1, found=0, output=0;
 state=*(int*)((char*)arg0+0x34);
 if(state==0){*out=output;return 1;}
 if(state==2 && (!found || *(float*)((char*)arg0+0x38)<*(float*)((char*)arg0-8))){best=0;found=1;}
 output=1; state=*(int*)((char*)arg0+0x74);
 if(state==0){*out=output;return 1;}
 if(state==2 && (!found || *(float*)((char*)arg0+0x78)<*(float*)((char*)arg0+(best<<6)+0x38))){best=1;found=1;}
 output=2; state=*(int*)((char*)arg0+0xB4);
 if(state==0){*out=output;return 1;}
 if(state==2 && (!found || *(float*)((char*)arg0+0xB8)<*(float*)((char*)arg0+(best<<6)+0x38))){best=2;found=1;}
 output=3; state=*(int*)((char*)arg0+0xF4);
 if(state==0){*out=output;return 1;}
 if(state==2 && (!found || *(float*)((char*)arg0+0xF8)<*(float*)((char*)arg0+(best<<6)+0x38))){best=3;found=1;}
 if(found)*out=best;
 return found;
}

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

extern "C" void fn_802C8E00(int, unsigned int, float, float, float, float, float);
extern float lbl_805645E0;
extern float lbl_80564590, lbl_8056459C, lbl_805645E0;
extern "C" void fn_80299830(void* arg0, int arg1) {
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
extern "C" void* fn_802998F4(void* arg0, int arg1) {
    if (arg0 != 0) {
        void* p = arg0;
        int i = 0;
        for (; i < *(int*)((char*)arg0 + 0x138); p = (char*)p + 0x9c, i++) {
            fn_80299FA8(arg0, p);
        }
        *(int*)((char*)arg0 + 0x138) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
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
extern "C" char lbl_803494F0[];
extern float lbl_805645E4, lbl_805645E8, lbl_805645EC, lbl_805645F0, lbl_805645F4;
void fn_80299A88(void *arg0, void *out, unsigned int unused, float scale) {
    float init[0x100/4];
    float rot[9];
    float *q = rot;
    int i, count;
    (void)arg0;
    fn_8028E61C(&init[0x68/4]);
    init[0x6c/4] = 0xA0; init[0x70/4] = lbl_80564590; init[0x74/4] = lbl_80564590;
    init[0x68/4] = 1.0f;
    init[0x14/4] = lbl_805645E4; init[0x18/4] = lbl_805645E4; init[0x1c/4] = lbl_805645E4;
    init[0x78/4] = lbl_805645E4; init[0x7c/4] = lbl_805645E4; init[0x80/4] = lbl_805645E4;
    init[8/4] = lbl_80564590; init[0xc/4] = lbl_80564590; init[0x10/4] = lbl_80564590;
    init[0x84/4] = lbl_80564590; init[0x88/4] = lbl_80564590; init[0x8c/4] = lbl_80564590;
    init[0x90/4] = lbl_8056459C; init[0x98/4] = lbl_805645A0;
    init[0xb8/4] = lbl_805645E8; init[0xbc/4] = lbl_805645EC;
    init[0xc0/4] = lbl_805645A8; init[0xc4/4] = lbl_805645AC;
    init[0xd8/4] = lbl_805645B0; init[0xd0/4] = lbl_805645B0; init[0xc8/4] = lbl_805645B0;
    init[0xdc/4] = lbl_805645B4; init[0xd4/4] = lbl_805645B4; init[0xcc/4] = lbl_805645B4;
    init[0xe8/4] = lbl_80564590; init[0xec/4] = 0x40; ((unsigned char*)init)[0xf0]=1;
    init[0xac/4] = 2; ((unsigned char*)init)[0xf1]=1;
    void *res = ((void *(*)(void*,void*,void*,int,int,float,float,float,float,float,float,float,float,float))fn_8028E2F8)
      (&init[0x68/4], lbl_803494F0, lbl_8055CA80, 0x40, 1, lbl_805645B0,lbl_805645AC,
       lbl_805645A8,lbl_805645EC,lbl_805645E8,lbl_805645A0,lbl_8056459C,lbl_805645E4,lbl_80564590);
    *(void**)out = res;
    count = (int)(lbl_805645F0 * scale);
    if (count >= 12) count = 12;
    if (count < 1) count = 1;
    float c = (float)cos((double)(lbl_805645F4 / (float)count));
    float s = (float)sin((double)(lbl_805645F4 / (float)count));
    q[0]=c; q[1]=s; q[2]=lbl_8056459C; q[3]=-s; q[4]=c;
    q[5]=lbl_8056459C; q[6]=lbl_8056459C; q[7]=lbl_8056459C; q[8]=lbl_80564590;
    float *p=(float*)unused;
    if (count > 0) for (int n=0;n<count;n++) {
       ((float*)out)[1+n*3]=p[9]+p[3]*scale;
       ((float*)out)[2+n*3]=p[10]+p[4]*scale;
       ((float*)out)[3+n*3]=p[11]+p[5]*scale;
       for(i=0;i<9;i++) p[i]=fn_80144514(p[i],q[i],p[i],q[i],p[i],q[i]);
    }
    *(int*)((char*)out+0x94)=count;
    *(float*)((char*)out+0x98)=lbl_8056459C;
}

extern "C" void* fn_80299FA8(void* arg0, void* arg1) {
    fn_8028E398(*(void**)arg1);
    *(void**)arg1 = 0;
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
extern "C" void fn_8029A17C(void* arg0) {
    int temp_r0 = *(int*)((char*)arg0 + 0x40);
    if (temp_r0 != -1) {
        if (*((unsigned char*)lbl_8055F7C0 + temp_r0 * 0x2C + 0x28) != 0) {
            void* temp_r3 = (void*)fn_80287B24(*(int*)((char*)arg0 + 0x3C));
            if (fn_8029A290(arg0, temp_r3) != 0) {
                fn_8029A60C(arg0, temp_r3);
            }
        } else {
            *(int*)((char*)arg0 + 0x40) = -1;
        }
    }
}

extern "C" void fn_8029A4B4(void);
extern "C" void fn_8029840C(void);
extern "C" void fn_8029A208(void* arg0, int arg1, int arg2) {
    int index;
    unsigned char* entry;
    if (arg2 != 0 && *(int*)((char*)arg0 + 0x40) == -1) {
        fn_8029A4B4();
        return;
    }
    if (arg2 == 0 && arg1 == *(int*)((char*)arg0 + 0x3C)) {
        register int index2 = *(int*)((char*)arg0 + 0x40);
        if (index2 != -1) {
            entry = (unsigned char*)lbl_8055F7C0 + index2 * 0x2C;
            if (entry[0x28] != 0)
                fn_8029840C();
            *(int*)((char*)arg0 + 0x40) = -1;
        }
    }
}

#pragma scheduling invalid_target
extern "C" int fn_8029A290(void* arg0, void* arg1) {
    extern float PSVECSquareDistance(const void*, const void*);
    extern float PSVECDotProduct(const void*, const void*);
    extern float lbl_80564604;
    double threshold = lbl_80564594;
    int result = 1;
    if (PSVECSquareDistance((char*)arg0 + 0x24, (char*)arg1 + 0x24) > threshold) {
        goto done;
    }
    int below = PSVECDotProduct(arg0, arg1) < lbl_80564604;
    if (below == 0) {
        result = 0;
    }
done:
    return result;
}
#pragma scheduling on
extern "C" void fn_8029A318(float *a, float *b, float *c, int x, int y, int z, int w) {
 if ((unsigned char *)b==(unsigned char *)a+0x30) {
 b[0]=a[14]*a[3]+a[12]*a[0]+a[14]*a[6]; b[1]=a[14]*a[4]+a[12]*a[1]+a[14]*a[7]; b[2]=a[14]*a[5]+a[12]*a[2]+a[14]*a[8];
 } else {
 b[0]=a[12]*a[3]+a[12]*a[0]+a[14]*a[6]; b[1]=a[12]*a[4]+a[12]*a[1]+a[14]*a[7]; b[2]=a[12]*a[5]+a[12]*a[2]+a[14]*a[8];
 }
 b[0]+=a[9];b[1]+=a[10];b[2]+=a[11];
 c[0]=a[0]*lbl_805645C8;c[1]=a[1]*lbl_805645C8;c[2]=a[2]*lbl_805645C8;
 ((float *)w)[0]=a[6]*lbl_805645E8;((float *)w)[1]=a[7]*lbl_805645E8;((float *)w)[2]=a[8]*lbl_805645E8;
}

extern "C" void fn_8029A318(float*, float*, float*, int, int, int, int);
#pragma dont_inline on
extern "C" void fn_8029A60C(void* arg0, void* arg1) {
    struct Vectors {
        float c[3];
        float b[3];
        float a[3];
    };
    volatile Vectors vectors;
    volatile unsigned int *src = (volatile unsigned int *)arg1;
    unsigned int v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0;
    float value = lbl_8056459C;

    v0 = src[0];
    vectors.a[0] = value;
    v1 = src[1];
    vectors.a[1] = value;
    v2 = src[2];
    vectors.a[2] = value;
    v3 = src[3];
    vectors.b[0] = value;
    v4 = src[4];
    vectors.b[1] = value;
    v5 = src[5];
    vectors.b[2] = value;
    v6 = src[6];
    vectors.c[0] = value;
    v7 = src[7];
    vectors.c[1] = value;
    v8 = src[8];
    vectors.c[2] = value;
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

    ((void (*)(void*, float*, float*, float*))fn_8029A318)(arg0, (float *)&vectors.a[0], (float *)&vectors.b[0], (float *)&vectors.c[0]);
    fn_80298458((int)lbl_8055F7C0, *(int *)((char *)arg0 + 0x40), (void *)&vectors.a[0], (void *)&vectors.b[0], (void *)&vectors.c[0], *(short *)((char *)arg1 + 0x30));
}
#pragma dont_inline reset
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

extern "C" int fn_8029ADCC(void *arg0);
extern "C" void fn_8029B1B8(void *);
extern "C" void *fn_80288208(int);
extern "C" int fn_80287E20(void *, const char *);
extern "C" void *fn_80287E80(void *, const char *);
extern "C" char lbl_80349508[];
extern "C" int lbl_8055CA90;
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma cplusplus on
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

    fn_8029B1B8(arg0);
    count = fn_80287B14();
    cursor = arg0;
    i = 0;
    while (i < count) {
        obj = fn_80288208(i);
        *(float *)((char *)cursor + 0x1C0) = lbl_80564590;
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
#pragma cplusplus reset
#pragma dont_inline reset
#pragma scheduling on

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

extern "C" int fn_80287B24(int);
extern "C" void fn_801BFD34(void*, void*, int);
extern "C" void fn_80015B20(void*, void*, int);
extern "C" float fn_80287BC8(float, float);
extern "C" int fn_80287B5C(int);
extern float lbl_80564620;
extern float lbl_805645EC;
extern float lbl_8056461C;
extern "C" void fn_8029B044(void* arg0, int arg1, void* arg2) {
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
extern "C" void fn_8029B1B8(void* arg0) {
    char* p = (char*)arg0;
    *(int*)(p + 0x1E4) = fn_802CAC28(lbl_8055CA84, 0);
    *(int*)(p + 0x1E8) = fn_802CAC28(lbl_8055CA88, 0);
    if (fn_80297D5C(p + 0x1EC, 0x10) == 0 || fn_80297D90(p + 0x1F0, *(int*)(p + 0x1EC)) == 0) {
        fn_802E317C(lbl_8034951C);
    }
    int v = *(int*)(p + 0x1F0);
    *(float*)(p + 0x1F8) = lbl_80564590 / (float)*(int*)(p + 0x1EC);
    *(int*)(p + 0x1F4) = 0x10 - (v << 1);
}

extern "C" void* fn_80288060(void*, int);
extern "C" void fn_8029B43C(void*, void*, unsigned char, float, float, float, float, float, float = 0.0f, float = 0.0f, float = 0.0f);
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
                fn_8029B43C(arg0, entry, *(unsigned char *)(entry + 0x34), scale,
                            *(float *)(item + 0x14) * scale, y, x,
                            *(float *)(item + 0x0C) * scale);
                ++j;
            }
        }
        entry += 0x38;
        item += 0x38;
        ++i;
    }
}

#pragma dont_inline reset
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
extern "C" void fn_8029BDC4(void* arg0) {
    float values[3];
    int i = 0;
    char* entry = (char*)arg0 + 4;
    values[0] = lbl_8056459C;
    values[1] = lbl_8056459C;
    values[2] = lbl_8056459C;
    do {
        if (*(unsigned char*)(entry + 0x10)) {
            fn_80288A58(entry, values);
            fn_8028E584(*(void**)arg0, entry, values, 0.0f);
        }
        entry += 0x14;
        i++;
    } while (i < *(int*)((char*)arg0 + 0xA4));
}

extern "C" void fn_802CAC54(int);
extern float lbl_805645B8;
extern "C" void fn_8029A890(void*, void*);
extern "C" void fn_8029BA94(void*, void*);
extern "C" int fn_8029C024(int*);
extern "C" int fn_8029C054(int*);
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
extern "C" void fn_8029A904(void*, void*, float, float);
extern "C" void fn_8029C084(void *arg0, int arg1) {
    float temp_f31 = fn_801E7E24();
    if (__fabsf(temp_f31) <= lbl_80558DC4) {
        return;
    }
    int i = 0;
    while (i < arg1) {
        void *data;
        void *obj;
        unsigned char flag;
        int enabled;
        void *ctx;

        flag = *(unsigned char *)((char *)arg0 + 0xC);
        enabled = 0;
        obj = *(void **)((char *)arg0 + 4);
        data = *(void **)arg0;
        ctx = lbl_8055F7C8;
        if (flag != 0 && *(int *)((char *)data + 0x5C) == 0xB) {
            enabled = 1;
        }
        fn_80298DE0(ctx, obj, enabled);
        fn_8029BBD4(lbl_8055F7D8, obj, flag);
        if (lbl_8055F7D0 != 0) {
            int enabled2 = 0;
            if (flag != 0 && *(int *)((char *)data + 0x5C) == 0xC) {
                enabled2 = 1;
            }
            ((void (*)(void *, void *, int))fn_8029A208)(lbl_8055F7D0, obj, enabled2);
        }
        if (lbl_8055F7D4 != 0) {
            ((void (*)(void *, void *, void *, float, float))fn_8029A904)(
                lbl_8055F7D4, obj, data, temp_f31, *(float *)((char *)arg0 + 8));
        }
        arg0 = (char *)arg0 + 0x10;
        i += 1;
    }
}

#pragma dont_inline reset
int fn_8029C190(void* arg0) {
    fn_8029BE54(lbl_8055F7DC, arg0);
    return 0x14;
}
#include <string.h>
extern "C" float lbl_805645C8;
extern "C" float lbl_805645E8;
extern "C" void* fn_802988A4(void*);
extern "C" void* fn_8029A6F4(void*);
extern "C" void* fn_801E87A8(void);
extern "C" void fn_80287B38(void*);
extern "C" char lbl_80349408[];

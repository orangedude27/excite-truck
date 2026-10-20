// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct D_801A520C {
    void **vtable;
    void *pad0; void *pad1; void *pad2; void *pad3; void *pad4; void *pad5; void *pad7; void *pad8; void *pad9;
    int (*d5)(struct D_801A520C *);
} D_801A520C;

void fn_8018B0D8(int *, int *);
void fn_80189CB4(void);
void fn_8018AF00(void);
void fn_80183DF8(void);
void fn_8018381C(void);
extern float lbl_805623C8;
int fn_801E9E30(void *, int *, int *);
void *fn_801B83A0(void);
void fn_80265D3C(void *);
void fn_801836E0(void *, int);
void fn_80128668(void *);
void fn_80182010(void);
void fn_80182074(void);
void fn_8018B09C(void);
int fn_80265D38(void *, int);
extern int lbl_80333C48;
void *fn_801A520C(void *arg0, void *arg1) {
    fn_80182010();
    *(void **)((char *)arg0 + 0x270C) = arg1;
    *(void **)arg0 = (void *)((unsigned long)&lbl_80333C48);
    return arg0;
}

#pragma cplusplus on
struct Dummy_801A5258 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2(void *, void *, void *) {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual void d10(void *) {}
};
extern "C" void fn_801A5258(void *arg0, void *arg1) {
    float zero;
    Dummy_801A5258 *obj;
    fn_80182074();
    fn_80265D38(arg0, *(int *)((char *)arg0 + 0x1EC));
    obj = (Dummy_801A5258 *)*(void **)((char *)arg0 + 0x270C);
    *(int *)((char *)arg0 + 0x2708) = 0;
    *(unsigned char *)((char *)arg0 + 0x2704) = 0;
    *(int *)((char *)arg0 + 0x2700) = 0;
    obj->d2(obj, arg0, arg1);
    obj = (Dummy_801A5258 *)*(void **)((char *)arg0 + 0x270C);
    obj->d10(obj);
    zero = lbl_805623C8;
    *(int *)((char *)arg0 + 0x2714) = 1;
    *(int *)((char *)arg0 + 0x2720) = 0;
    *(float *)((char *)arg0 + 0x271C) = zero;
    *(float *)((char *)arg0 + 0x2718) = zero;
    *(unsigned char *)((char *)arg0 + 0x2710) = 0;
}

void fn_801A5300(void *arg0, void **arg1) {
    void **temp_r0;
    void **temp_r3;
    temp_r0 = *(void ***)((char *)arg0 + 0x270C);
    if (temp_r0 != 0) {
        ((int (**)(void **))(*temp_r0))[10](temp_r0);
    }
    *(void ***)((char *)arg0 + 0x270C) = arg1;
    if (arg1 != 0) {
        ((int (**)(void **, void *))(*arg1))[4](arg1, arg0);
        temp_r3 = *(void ***)((char *)arg0 + 0x270C);
        ((int (**)(void **))(*temp_r3))[9](temp_r3);
    }
}

void *fn_801A538C(void *arg0, int arg1) {
    void *obj;
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80333C48;
        fn_80265D3C(&lbl_80333C48);
        obj = *(void **)((char *)arg0 + 0x270C);
        ((void (*)(void *))(*(void ***)obj)[10])(obj);
        obj = *(void **)((char *)arg0 + 0x270C);
        if (obj != 0)
            ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
        *(void **)((char *)arg0 + 0x270C) = 0;
        fn_801836E0(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

extern void fn_80186DE4(void);
extern void fn_801A5434(void *);
extern void fn_801A56A0(void *, void *, float *);
extern void fn_801A61B0(void *, void *, float);
extern unsigned char lbl_8055A518;
void fn_801A54EC(void *arg0) {
    void *obj;
    void *ret;
    float vec[3];
    unsigned int i;
    char *base = (char *)arg0;
    fn_80186DE4();
    fn_801A5434(arg0);
    obj = *(void **)(base + 0x270C);
    ((void (*)(void *))(*(void ***)*(void **)obj)[11])(obj);
    if (*(unsigned char *)(base + 0x2710) != 0 && lbl_8055A518 != 0) {
        obj = *(void **)(base + 0x270);
        ret = ((void *(*)(void *))(*(void ***)*(void **)obj)[7])(obj);
        fn_801A61B0(base + 0x2714, arg0, *(float *)((char *)*(void **)((char *)ret + 4) + 0x20));
    }
    vec[0] = lbl_805623C8;
    vec[1] = lbl_805623C8;
    vec[2] = lbl_805623C8;
    obj = base + 0x2724;
    i = 0;
    do {
        fn_801A56A0(obj, arg0, vec);
        i++;
        if (i >= 8) break;
        obj = (char *)obj + 0x24;
    } while (1);
}

void fn_801A55BC(void *arg0) {
    void *obj;
    fn_8018381C();
    *(int *)((char *)arg0 + 0x2744) = 0;
    *(int *)((char *)arg0 + 0x2768) = 0;
    *(int *)((char *)arg0 + 0x278C) = 0;
    *(int *)((char *)arg0 + 0x27B0) = 0;
    *(int *)((char *)arg0 + 0x27D4) = 0;
    *(int *)((char *)arg0 + 0x27F8) = 0;
    *(int *)((char *)arg0 + 0x281C) = 0;
    *(int *)((char *)arg0 + 0x2840) = 0;
    *(int *)((char *)arg0 + 0x2714) = 1;
    obj = *(void **)((char *)arg0 + 0x270C);
    *(int *)((char *)arg0 + 0x2720) = 0;
    *(float *)((char *)arg0 + 0x271C) = lbl_805623C8;
    *(float *)((char *)arg0 + 0x2718) = lbl_805623C8;
    ((void (*)(void *, int))(*(void ***)obj)[10])(obj, 0);
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *))(*(void ***)obj)[9])(obj);
    *(int *)((char *)arg0 + 0x2700) = 0;
    *(unsigned char *)((char *)arg0 + 0x2704) = 0;
}

void fn_801A5660(void *arg0) {
    void *obj;
    fn_80183DF8();
    obj = *(void **)((char *)arg0 + 0x270C);
    (*(void (**)(void *))(*(void ***)obj + 13))(obj);
}

void fn_801A5D80(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    void *obj;
    float zero;
    fn_8018B09C();
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *, int, int, int, int))(*(void ***)obj)[14])(obj, arg1, arg2, arg3, arg4);
    if (arg3 == 0x6D) {
        zero = lbl_805623C8;
        *(int *)((char *)arg0 + 0x2714) = 1;
        *(int *)((char *)arg0 + 0x2720) = 0;
        *(float *)((char *)arg0 + 0x271C) = zero;
        *(float *)((char *)arg0 + 0x2718) = zero;
    }
}

void fn_801A5E98(void *arg0) {
    void *obj;
    fn_8018AF00();
    obj = *(void **)((char *)arg0 + 0x270C);
    (*(void (**)(void))(*(void ***)obj + 16))();
}

#pragma cplusplus on
struct Dummy_801A5ED8 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
};
  struct Dummy_801A6088 {
      virtual void g0();
      virtual void g1();
      virtual void g2();
      virtual int g3();
      virtual void g4();
  };
  #pragma cplusplus off
  
  #pragma cplusplus on
  extern "C" void fn_801A5ED8(void *arg0) {
      fn_80189CB4();
      void *obj = *(void **)((char *)arg0 + 0x270C);
      *(unsigned char *)((char *)arg0 + 0x2704) = 1;
      ((Dummy_801A5ED8 *)obj)->f16();
      *(int *)((char *)arg0 + 0x2744) = 0;
      *(int *)((char *)arg0 + 0x2768) = 0;
      *(int *)((char *)arg0 + 0x278C) = 0;
      *(int *)((char *)arg0 + 0x27B0) = 0;
      *(int *)((char *)arg0 + 0x27D4) = 0;
      *(int *)((char *)arg0 + 0x27F8) = 0;
      *(int *)((char *)arg0 + 0x281C) = 0;
      *(int *)((char *)arg0 + 0x2840) = 0;
  }
  #pragma cplusplus off
  
  int fn_801A5F44(void *arg0, int arg1) {
      void *obj = *(void **)((char *)arg0 + 0x270C);
      return ((int (*)(void *, int))(*(void ***)obj)[6])(obj, arg1 + 0x44) + 0x44;
  }
  
  void fn_801A5F7C(void *arg0, int arg1, int arg2, int *arg3, int *arg4, float farg0) {
      int x, y, a, b;
      void *obj;
      fn_8018B0D8(&x, &y);
      obj = *(void **)((char *)arg0 + 0x270C);
      ((void (*)(void *, int, int, int *, int *, float))(*(void ***)obj)[7])(obj, arg1 + x, arg2 + y, &a, &b, farg0);
      *arg3 = x + a;
      *arg4 = y + b;
  }
  
  int fn_801A6024(void *arg0, int arg1) {
      int base;
      void *obj;
      base = arg1 + fn_8018BA54();
      obj = *(void **)((char *)arg0 + 0x270C);
      return base + ((int (*)(void *, int))(*(void ***)obj)[8])(obj, base) - arg1;
  }
  
  void fn_80188E2C(void);
  int fn_8018BA54(void);
  void fn_8018956C(void);
#pragma cplusplus on
extern "C" void fn_801A6088(void *arg0, int arg1) {
    void *obj;
    int offset;
    fn_80188E2C();
    obj = *(void **)((char *)arg0 + 0x270C);
    offset = arg1 + *(int *)((char *)arg0 + 8);
    *(int *)((char *)offset + 0x2C0) =
        ((Dummy_801A6088 *)obj)->g3();
}
#pragma cplusplus off
extern float lbl_80562404;
extern float lbl_80562408;
extern float lbl_8056240C;
extern void fn_8017B3A8(void *, float *, float *, float);
void fn_801A60E0(void *arg0, void *arg1) {
    float sp14[3];
    float sp8[3];
    float f2;
    float f0;
    float f1;
    char *p = (char *)arg1;

    if (*(float *)(p + 0x124) > lbl_80562404) {
        f0 = lbl_80562408 * (lbl_8056240C - *(float *)(p + 0x58));
        f2 = lbl_805623C8;
        if (f0 < f2) {
            f2 = f0;
        } else {
            f2 = f2;
        }
        sp14[0] = *(float *)(p + 0x60) + *(float *)(p + 0x54) * f2;
        sp14[1] = *(float *)(p + 0x64) + *(float *)(p + 0x58) * f2;
        sp14[2] = *(float *)(p + 0x68) + *(float *)(p + 0x5C) * f2;
    } else {
        sp14[0] = *(float *)(p + 0x60);
        sp14[1] = *(float *)(p + 0x64);
        sp14[2] = *(float *)(p + 0x68);
    }
    f1 = *(float *)((char *)arg0 + 4);
    sp8[0] = lbl_805623C8;
    sp8[1] = f1;
    sp8[2] = lbl_805623C8;
    fn_8017B3A8(arg1, sp8, sp14, f1);
}


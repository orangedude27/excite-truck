// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E744;
#pragma cplusplus on
struct Dummy_801B8318 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(void *);
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
          virtual int f17(void *);
    virtual void f18(void *);
    virtual void f19(void *);
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual int f36(void *, int, int);
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
};
#pragma cplusplus off
int fn_801B81E0(void *arg0) {
    extern int fn_8014145C(void);
    extern int fn_8014DE50(void);
    extern int fn_8016BE60(void);
    extern int fn_80172C28(void);
    extern void fn_802E317C(const char *, ...);
    extern char lbl_80336740[];
    int value = *(int *)((char *)arg0 + 0x3E8);
    switch (value) {
    case 0x180201: return fn_8014145C();
    case 0x180302: return fn_8014DE50();
    case 0x180303: return fn_8016BE60();
    case 0x180304: return fn_80172C28();
    default: fn_802E317C(lbl_80336740); return 0;
    }
}

#pragma cplusplus on
extern "C" void fn_801B8318(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f59();
}
#pragma cplusplus on
extern "C" void fn_801B832C(void) {
    extern void fn_801616FC(void);
    extern float lbl_80436D08[];
    extern float lbl_80562744;
    fn_801616FC();
    if (lbl_8055E744 != 0)
        ((Dummy_801B8318 *)lbl_8055E744)->f2();
    lbl_80436D08[0] = lbl_80562744;
    lbl_8055E744 = 0;
    lbl_80436D08[1] = lbl_80562744;
    lbl_80436D08[2] = lbl_80562744;
    lbl_80436D08[3] = lbl_80562744;
    lbl_80436D08[4] = lbl_80562744;
    lbl_80436D08[5] = lbl_80562744;
    lbl_80436D08[6] = lbl_80562744;
    lbl_80436D08[7] = lbl_80562744;
}
#pragma cplusplus off
void* fn_801B83A0(void) {
    return lbl_8055E744;
}

#pragma cplusplus on
extern "C" void fn_801B83A8(void) {
    extern float lbl_80436D08[];
    extern char lbl_8055E748;
    extern float lbl_8055E750;
    extern float lbl_80562744;
    extern void fn_801619A8(void);
    ((Dummy_801B8318 *)lbl_8055E744)->f2();
    lbl_80436D08[0] = lbl_80562744;
    lbl_8055E748 = 0;
    lbl_80436D08[1] = lbl_80562744;
    lbl_80436D08[2] = lbl_80562744;
    lbl_80436D08[3] = lbl_80562744;
    lbl_80436D08[4] = lbl_80562744;
    lbl_80436D08[5] = lbl_80562744;
    lbl_80436D08[6] = lbl_80562744;
    lbl_80436D08[7] = lbl_80562744;
    fn_801619A8();
    lbl_8055E750 = lbl_80562744;
}
#pragma cplusplus off
void fn_801B8418(void) {

}

void fn_801B841C(void) {
    extern void fn_80161A18(void);
    extern float lbl_8055E750;
    extern float lbl_80562744;
    extern float lbl_80562748;
    ((void (*)(void))(*(void ***)lbl_8055E744)[3])();
    fn_80161A18();
    if (((int (*)(void))(*(void ***)lbl_8055E744)[9])() != 0)
        lbl_8055E750 += lbl_80562748;
    else
        lbl_8055E750 = lbl_80562744;
}

void fn_801B8488(void) {

}

#pragma cplusplus on
extern "C" void fn_801B848C(void *arg0) {
    ((Dummy_801B8318 *)lbl_8055E744)->f3(arg0);
}
#pragma cplusplus on
extern "C" void fn_801B84A4(void *arg0) {
    ((Dummy_801B8318 *)lbl_8055E744)->f17(arg0);
}
#pragma cplusplus off
void fn_801B84BC(void) {

}

#pragma cplusplus on
extern "C" void fn_801B84C0(void *arg0) {
    ((Dummy_801B8318 *)lbl_8055E744)->f18(arg0);
}
#pragma cplusplus off
void fn_801B84D8(void* arg0) {
    (*(void (***)(void*, void*))lbl_8055E744)[21](lbl_8055E744, arg0);
}

int fn_801B84F0(void) {
    return 0;
}

void fn_801B84F8(void) {
    extern char lbl_8055E748;
    void *obj;
    void **vt;
    void (*fn)(void *);
    lbl_8055E748 = 1;
    obj = lbl_8055E744;
    vt = *(void ***)obj;
    fn = (void (*)(void *))vt[6];
    fn(obj);
}

extern char lbl_8055E748;
char fn_801B8514(void) {
    return lbl_8055E748;
}

int fn_801B851C(void* arg0) {
    extern int fn_80161BB8(void);
    if (fn_80161BB8() != 0) return 0;
    return (*(int (***)(void *, void *))lbl_8055E744)[10](lbl_8055E744, arg0);
}

int fn_801B8570(int arg0) {
    int result = 0;
    register void *obj = lbl_8055E744;
    register int (**vtable)(void *, int) = *(int (***)(void *, int))obj;
    if (vtable[11](obj, arg0) != 0 && fn_80161B94() == 0) result = 1;
    return result;
}

#pragma cplusplus on
extern "C" void fn_801B85CC(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f7();
}
#pragma cplusplus off
void fn_801B85E0(void *a, void *b, void *c, void *d) {
    (*(void (***)(void *, void *, void *, void *, void *))lbl_8055E744)[36](lbl_8055E744, a, b, c, d);
}

void fn_801B8610(void *a, void *b) {
    register void *obj = lbl_8055E744;
    register void (**vtable)(void *, void *) = *(void (***)(void *, void *))obj;
    vtable[38](a, b);
}

int fn_801B8630(int arg0, int arg1, int arg2) {
    extern int fn_80161BDC(void);
    if (fn_80161BDC() != 0) return 1;
    return (*(int (***)(void *, int, int, int))lbl_8055E744)[40](lbl_8055E744, arg0, arg1, arg2);
}

void fn_801B86A4(void *arg0) {
    (*(void (***)(void *, void *))lbl_8055E744)[43](lbl_8055E744, arg0);
}

void fn_801B86BC(int arg0, void *arg1) {
    extern float lbl_8055A910;
    extern void fn_8027DED8(int, void *, float);
    register float value;
    (*(void (***)(void *, int, void *))lbl_8055E744)[45](lbl_8055E744, arg0, arg1);
    value = *(float *)((char *)arg1 + 0x50);
    *(float *)((char *)arg1 + 0x50) = value * lbl_8055A910;
    fn_8027DED8(arg0, arg1, value);
}

int fn_801B8728(int arg0) {
    register void *obj = lbl_8055E744;
    register int result;
    ((void (*)(void *, int))(*(int (**)(void *, int))(*(void ***)obj + 0xB8)))(obj, arg0);
    result = (*(int (**)(void *))(*(void ***)lbl_8055E744 + 0xE4))(lbl_8055E744);
    return result == 0;
}

#pragma cplusplus on
extern "C" void fn_801B8778(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f46();
}
#pragma cplusplus on
extern "C" void fn_801B878C(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f47();
}
#pragma cplusplus on
extern "C" int fn_801B87A0(int arg0, int arg1) {
    extern int fn_80161B0C(void);
    Dummy_801B8318 *obj = (Dummy_801B8318 *)lbl_8055E744;
    if (fn_80161B0C() != 0) return 1;
    return obj->f36(obj, arg0, arg1);
}
#pragma cplusplus off
int fn_801B8804(void) { return 0; }

#pragma cplusplus on
extern "C" void fn_801B880C(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f31();
}
#pragma cplusplus on
extern "C" void fn_801B8820(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f14();
}
#pragma cplusplus on
extern "C" void fn_801B8834(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f15();
}
#pragma cplusplus on
extern "C" void fn_801B8848(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f11();
}
#pragma cplusplus off
void fn_801B885C(void *arg0) {
    register void *obj = lbl_8055E744;
    register void **vtable = *(void ***)obj;
    ((void (*)(void *, void *))vtable[15])(obj, arg0);
}

int fn_801B8874(void) {
    extern int fn_80161C38(void);
    extern void fn_80161A70(void);
    if (fn_80161C38() == 0) {
        return (*(int (**)(void *))(*(void ***)lbl_8055E744 + 34))(lbl_8055E744);
    }
    fn_80161A70();
    return 1;
}

void fn_801B88BC(void) {
    extern int fn_80161C38(void);
    extern void fn_80161B70(void);
    if (fn_80161C38() != 0) {
        fn_80161B70();
        return;
    }
    ((void (*)(void *))(*(unsigned int *)((char *)*(void **)lbl_8055E744 + 0x38)))(lbl_8055E744);
}

#pragma cplusplus on
extern "C" void fn_801B8900(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f30();
}
#pragma cplusplus on
extern "C" void fn_801B8914(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f10();
}
#pragma cplusplus off
void fn_801B8928(void *a, void *b, void *c) {
    register void *obj = lbl_8055E744;
    register void (**vt)(void *, void *, void *, void *) = *(void (***)(void *, void *, void *, void *))obj;
    vt[44](obj, a, b, c);
}

float fn_801B8950(int arg0) {
    extern float lbl_80436D08[];
    return lbl_80436D08[arg0];
}

extern float lbl_80436D08[];
void fn_801B8964(int arg0, float arg1) {
    lbl_80436D08[arg0] = arg1;
}

#pragma cplusplus on
extern "C" void fn_801B8978(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f25();
}
#pragma cplusplus on
extern "C" void fn_801B898C(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f26();
}
#pragma cplusplus off
extern int fn_80128668(void);
extern void* lbl_8055E744;
#pragma cplusplus on
extern "C" void fn_801B89A0(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f27();
}
#pragma cplusplus on
extern "C" void fn_801B89B4(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f28();
}
#pragma cplusplus off
void fn_801B89C8(void* arg0) {
    register void (**vtable)(void*, void*) = *(void (***)(void*, void*))lbl_8055E744;
    vtable[31](lbl_8055E744, arg0);
}

int fn_801B89E0(void) {
    extern float lbl_8055E750;
    extern float lbl_8056274C;
    return lbl_8055E750 > lbl_8056274C;
}

int fn_801B89F8(void) {
    extern float lbl_8055E750;
    extern float lbl_8056274C;
    return lbl_8055E750 > lbl_8056274C;
}

extern float lbl_8055E750;
extern float lbl_8056274C;
extern void fn_801CB6B4(int, int, int);
void fn_801B8A10(void* arg0, int arg1, int arg2) {
    fn_801CB6B4(arg1, arg2, 2);
}

int fn_801B8A20(void *arg0) {
    extern char lbl_8055E748;
    if (*(volatile unsigned char *)&lbl_8055E748 != 0) {
        return (*(int (***)(void *))arg0)[7](arg0);
    }
    return 0;
}

int fn_801B8A44(void *arg0) {
    if (lbl_8055E748 != 0) {
        volatile void **vt = *(volatile void ***)arg0;
        return ((int (*)(void *))vt[8])(arg0);
    }
    return 0;
}

void fn_801B8A68(void *arg0, int arg1) {
    extern void fn_801B0C78(void *);
    fn_801B0C78((void *)arg1);
}

void fn_801B8A70(void *arg0, int arg1, int arg2) {
    extern void fn_801B0F70(int, int);
    fn_801B0F70(arg1, arg2);
}

void fn_801B8A7C(void *arg0, int arg1) {
    extern void fn_801B2C70(void *);
    fn_801B2C70((void *)arg1);
}

void fn_801B8A84(void) {
    extern void fn_8013C9F4(int);
    fn_8013C9F4(0);
}

int fn_801B8A8C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_801B8ACC(void) { return 1; }

void fn_801B8AD4(void) {

}

void fn_801B8AD8(void) {

}

int fn_801B8ADC(void) { return 1; }

int fn_801B8AE4(void) { return 0; }

void fn_801B8AEC(void) {

}

void fn_801B8AF0(void) {

}

void fn_801B8AF4(void) {

}

void fn_801B8AF8(void) {

}

void fn_801B8AFC(void) {

}

float fn_801B8B00(void) { return lbl_8056274C; }

extern int fn_800167F4(void);
int fn_801B8B08(void) {
    int result;
    if (fn_800167F4() > 1) {
        result = 0x160B;
    } else {
        result = 0x564B;
    }
    return result;
}

int fn_801B8B38(void) { return 1; }

int fn_801B8B40(void) { return 1; }

int fn_801B8B48(void) { return 1; }

int fn_801B8B50(void) { return 0; }


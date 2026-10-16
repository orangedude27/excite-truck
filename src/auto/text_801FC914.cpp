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
void fn_801FF6FC(void*);
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
    void fn_801FCA14(void*);
    extern const char lbl_8033B86C[];
    extern const char lbl_8033B898[];
    extern const char lbl_8033B880[];
    }
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" float lbl_80563030;
extern "C" float lbl_80563034;
extern "C" void fn_801FD3F0(void);
extern "C" void fn_801FD5E8(void);
extern "C" void fn_801FDF18(void);
extern "C" void fn_802E317C(const char*, ...);
extern "C" const char lbl_8033B618[];
extern "C" float fn_802C99E8(float);
extern "C" void fn_802C744C(void*, void*);
void fn_801FCAC0(void* arg0) {
    if (*(int*)((char*)arg0 + 4) != 0)
        fn_802C744C(*(void**)((char*)arg0 + 8), (char*)arg0 + 0xC);
}

void fn_801FCAE0(void* arg0, void* arg1) {
    *(void**)((char*)arg0 + 4) = arg1;
    *(int*)((char*)arg0 + 0x3C) = 0;
    *(float*)((char*)arg0 + 0xC) = lbl_80563030;
    *(float*)((char*)arg0 + 0x10) = lbl_80563034;
    *(float*)((char*)arg0 + 0x14) = lbl_80563034;
    *(float*)((char*)arg0 + 0x18) = lbl_80563034;
    *(float*)((char*)arg0 + 0x1C) = lbl_80563030;
    *(float*)((char*)arg0 + 0x20) = lbl_80563034;
    *(float*)((char*)arg0 + 0x24) = lbl_80563034;
    *(float*)((char*)arg0 + 0x28) = lbl_80563034;
    *(float*)((char*)arg0 + 0x2C) = lbl_80563030;
    *(float*)((char*)arg0 + 0x30) = lbl_80563034;
    *(float*)((char*)arg0 + 0x34) = lbl_80563034;
    *(float*)((char*)arg0 + 0x38) = lbl_80563034;
    *(float*)((char*)arg0 + 0x30) = *(float*)((char*)arg1 + 0x10);
    *(float*)((char*)arg0 + 0x34) = *(float*)((char*)arg1 + 0x14);
    *(float*)((char*)arg0 + 0x38) = *(float*)((char*)arg1 + 0x18);
}

extern "C" void* fn_801FCED8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

void fn_801FCF18(void* arg0, void* arg1, int arg2) {
    *(int*)((char*)arg0 + 0) = arg2;
    *(int*)((char*)arg0 + 4) = 0;
    *(int*)((char*)arg0 + 8) = *(int*)((char*)arg1 + 4);
    *(float*)((char*)arg0 + 0xC) = lbl_80563030;
    *(float*)((char*)arg0 + 0x10) = lbl_80563034;
    *(float*)((char*)arg0 + 0x14) = lbl_80563034;
    *(float*)((char*)arg0 + 0x18) = lbl_80563034;
    *(float*)((char*)arg0 + 0x1C) = lbl_80563030;
    *(float*)((char*)arg0 + 0x20) = lbl_80563034;
    *(float*)((char*)arg0 + 0x24) = lbl_80563034;
    *(float*)((char*)arg0 + 0x28) = lbl_80563034;
    *(float*)((char*)arg0 + 0x2C) = lbl_80563030;
    *(float*)((char*)arg0 + 0x30) = lbl_80563034;
    *(float*)((char*)arg0 + 0x34) = lbl_80563034;
    *(float*)((char*)arg0 + 0x38) = lbl_80563034;
    *(int*)((char*)arg0 + 0x3C) = -1;
    *(float*)((char*)arg0 + 0x40) = lbl_80563034;
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

extern "C" void fn_801FCFC8(void* arg0) {
    if (*(int*)((char*)arg0 + 4) != 0) {
        float value = fn_802C99E8(*(float*)((char*)arg0 + 0x6C));
        fn_802C744C(*(void**)((char*)arg0 + 8), (char*)arg0 + 0xC);
        fn_802C99E8(value);
    }
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

int fn_802C7040(int);
float fn_80129DC4(int, void *, float, float);
int fn_801FE88C(void *, void *);
extern const char lbl_8033B638[];
extern const char lbl_8033B654[];
extern int lbl_8033B760;
void fn_801FE510(void *arg0, void *arg1) {
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

int fn_801FE9A8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        ((void (*)(void))fn_80128668)();
    return arg0;
}

int fn_801FE9E8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        ((void (*)(void))fn_80128668)();
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
    void* obj = *(void**)((char*)arg0 + 4);
    if (obj != 0) {
        register void** vtable = *(void***)obj;
        ((void (*)(void*, int))vtable[5])(obj, 0);
    }
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

extern "C" void fn_801FF168(void) {

}

extern "C" void fn_801FF16C(void* arg0) {
    float value = fn_801E7E24();
    if (fabs(value) > lbl_80558DC4) fn_801FF3AC((char*)arg0 + 0xE08, value);
}

extern "C" int fn_801FF1BC(void) { return 3; }

extern "C" void fn_801FF1C4(void* arg0, int arg1, int arg2) {
    char* p = (char*)arg0;
    if (*(int*)(p + 0xE04) >= 0x20) fn_802E317C(lbl_8033B8C8);
    fn_801FCF18(p + *(int*)(p + 0xE04) * 0x70 + 4, arg1, arg2);
    fn_801FF484(p + 0xE08, p + *(int*)(p + 0xE04) * 0x70 + 4);
    ++*(int*)(p + 0xE04);
}

extern "C" void fn_801FF260(void* arg0) {
    float value = fn_801E7E24();
    if (fabs(value) > lbl_80558DC4) fn_801FF6FC((char*)arg0 + 0x1008);
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

extern "C" void fn_801FEFC4(void) {

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

extern "C" void fn_801FF108(void* arg0) {
    fn_801FF420((char*)arg0 + 0xE08);
}

extern "C" void fn_801FF110(void) {

}


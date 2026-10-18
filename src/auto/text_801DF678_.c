// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804348E8[4];
extern double fn_8002EFB4(void);
extern void fn_801476D8(int, int);
extern void fn_80128668(void*);
extern void* lbl_8055EA04;
extern float lbl_8055AE30;
extern float lbl_80562C1C;
extern float lbl_80562C3C;
extern float lbl_80562C40;
extern float lbl_80562C44;
extern float lbl_80562C48;
extern int lbl_8055E4D0;
extern float PSVECMag(void*);
extern char lbl_8055AE2C;
void* fn_801DF678(void* arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int*)arg0 = 0;
            *((int*)arg0 + 1) = 0;
            *((int*)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801DF6D0(void* arg0) {
    int zero = 0;
    void* ptr = &lbl_8055AE2C;
    *(int*)((char*)arg0 + 0x18) = zero;
    *(void**)((char*)arg0 + 4) = ptr;
    *(void**)((char*)arg0 + 8) = ptr;
    *(char*)arg0 = zero;
    *(int*)((char*)arg0 + 0xC) = zero;
    *(int*)((char*)arg0 + 0x10) = zero;
    *(int*)((char*)arg0 + 0x14) = -1;
}

void fn_801476D8(int, int);
void fn_801DFE44(int a1, int a2) { ((void (*)(int, int, int))fn_801476D8)(a1, -1, a2); }

void fn_801DFE50(void *arg0, int arg1, int arg2) {
    void **v = *(void ***)arg0;
    ((void (*)(void *))v[4])(arg0);
    ((void (*)(int, int))fn_801476D8)(-1, arg2);
}

float fn_801DFE94(void) {
    return (float)fn_8002EFB4();
}

typedef void (*Fn)(void *);
void fn_801DFEB8(void *arg0, int arg1, int arg2, int arg3) {
    Fn volatile *vtable = *(Fn **)arg0;
    Fn call = vtable[4];
    call(arg0);
    fn_801476D8(arg2, arg3);
}

int fn_801DFF08(int index) { return lbl_804348E8[index]; }

void fn_801DFF1C(int arg0) {
    int index = arg0;
    char* entry = (char*)lbl_8055EA04 + index * 0x1C;
    void* vec = ((void**)lbl_804348E8)[index];
    *(float*)(entry + 4) = lbl_80562C3C;
    *(float*)(entry + 0x10) = lbl_80562C1C;
    *(float*)(entry + 8) = lbl_80562C40;
    *(char*)(entry + 0xC) = 0;
    *(float*)(entry + 0x14) = lbl_80562C44 * (lbl_8055AE30 * PSVECMag((char*)vec + 0x118)) / lbl_80562C48;
    *(char*)(entry + 0x18) = 0;
    *(int*)(entry + 0x1C) = -1;
}

void fn_801E02A8(void) {

}

void fn_801E02AC(void) {

}

void fn_801E02B0(void* arg0) {
    float b;
    float a;
    char* entry;
    int i;
    a = lbl_80562C40;
    b = lbl_80562C1C;
    entry = (char*)arg0 + 4;
    i = 0;
    while (i < lbl_8055E4D0) {
        *(char*)(entry + 8) = 0;
        i++;
        *(float*)(entry + 4) = a;
        *(float*)(entry + 0xC) = b;
        *(float*)(entry + 0x10) = b;
        *(char*)(entry + 0x14) = 0;
        *(int*)(entry + 0x18) = -1;
        *(float*)entry = b;
        entry += 0x1C;
    }
}


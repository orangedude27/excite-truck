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

void fn_801DFE44(int a1, int a2) {
    fn_801476D8(-1, a1);
}

float fn_801DFE94(void) {
    return (float)fn_8002EFB4();
}

int fn_801DFF08(int index) { return lbl_804348E8[index]; }

void fn_801E02A8(void) {

}

void fn_801E02AC(void) {

}

void fn_801E02B0(void) {
    volatile float a = lbl_80562C40;
    volatile float b = lbl_80562C1C;
    char* entry = (char*)lbl_8055EA04 + 4;
    int i = 0;
    do {
        *(char*)(entry + 8) = 0;
        i++;
        *(float*)(entry + 4) = a;
        *(float*)(entry + 0xC) = b;
        *(float*)(entry + 0x10) = b;
        *(char*)(entry + 0x14) = 0;
        *(int*)(entry + 0x18) = -1;
        *(float*)entry = b;
        entry += 0x1C;
    } while (i < lbl_8055E4D0);
}


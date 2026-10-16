typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* fn_80016544(s32);
extern s32 fn_800168B0(s32, s32);
extern s32 fn_800167F4(void);
extern void* fn_800167B8(s32);
extern void* fn_80016510(s32);
extern s32 fn_8001786C(s32);
extern char lbl_8055D564;
extern void* lbl_8055D560;
s32 atoi(void);
void fn_800178BC(void* arg0, s32 arg1, s32 arg2) {
    s32 index1;
    s32 index2;
    index1 = *(s32*)((char*)arg0);
    *(s32*)((char*)arg0 + index1 * 4 + 4) = arg1;
    index2 = *(s32*)((char*)arg0 + 0x24);
    *(s32*)((char*)arg0) = index1 + 1;
    *(s32*)((char*)arg0 + index2 * 4 + 0x28) = arg2;
    *(s32*)((char*)arg0 + 0x24) = index2 + 1;
}

int fn_800178F0(void) { return 0; }

void fn_800178F8(s32 arg0, s32 arg1) {
    void* temp = fn_80016544(arg1);
    fn_800168B0(arg0, *(s32*)((char*)temp + (*(s32*)((char*)temp + 0x94) * 4) + 0x64));
}

s32 fn_80017F40(void) {
    return fn_800167F4() == 1;
}

void fn_80018794(void) {
    lbl_8055D560 = (void*)atoi();
}

void fn_800187F8(void) {
    lbl_8055D564 = 1;
}

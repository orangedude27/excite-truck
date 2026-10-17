// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef float f32;
extern s32 lbl_8055E0D4;
extern s32 lbl_8055E0D0;
extern s32 lbl_80559BF8;
extern void fn_80136AA8(void*);
extern void fn_80136A18(s32, s32);
extern s32 fn_801284F8(s32, s32*);
extern s32 fn_801368F8(s32);
void fn_80136E8C(void *arg0, s32 arg1, signed char arg2) {
    *(signed char *)((char *)*(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC) + 0x15) = arg2;
}

float fn_80137850(void *arg0) {
 int index=*(int*)((char*)arg0+0x18)* *(int*)(lbl_8055E0D0+0xC);
 int base=*(int*)(lbl_8055E0D0+0x10);
 float *p=(float*)(base+index);
 return p[0]+(*(float**)arg0)[1]*p[2];
}

void fn_80137884(s32 arg0) {
 s32 var_r3 = fn_801284F8(0x18, &lbl_80559BF8);
 if (var_r3 != 0) var_r3 = fn_801368F8(arg0);
 lbl_8055E0D4 = var_r3; lbl_8055E0D0 = var_r3;
}

void fn_801378D0(void) {
 fn_80136A18(lbl_8055E0D4, 1);
 lbl_8055E0D4 = 0; lbl_8055E0D0 = 0;
}

void fn_80137904(void) { fn_80136AA8((void*)lbl_8055E0D4); }

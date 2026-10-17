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
extern f32 lbl_80561368;
extern s32 lbl_8032BEB4;
extern void fn_801376A8(s32, s32 *, s32, s32, s32 *);
extern void fn_80136D20(void);
void fn_801369EC(void *arg0) {
    f32 value = lbl_80561368;
    *(s32 *)((char *)arg0 + 0x14) = -1;
    *(f32 *)((char *)arg0 + 0x28) = value;
    *(f32 *)((char *)arg0 + 0x24) = value;
    *(f32 *)((char *)arg0 + 0x20) = value;
    *(f32 *)((char *)arg0 + 0x1C) = value;
    *(s32 *)((char *)arg0 + 0xC) = -1;
    *(signed char *)arg0 = 0;
}

void fn_80136CB8(void *arg0, s32 arg1) {
    s32 base;
    f32 value;
    fn_80136D20();
    value = lbl_80561368;
    base = *(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC);
    *(f32 *)((char *)base + 8) = value;
    *(f32 *)((char *)base + 0xC) = value;
    base = *(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC);
    *(f32 *)((char *)base + 0x10) = value;
}

void fn_80136E8C(void *arg0, s32 arg1, signed char arg2) {
    *(signed char *)((char *)*(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC) + 0x15) = arg2;
}

void fn_80136EA4(void *arg0, s32 arg1) {
    s32 values[3];
    s32 stride;
    s32 base;
    s32 index;
    values[0] = *(s32 *)((char *)&lbl_8032BEB4);
    values[1] = *(s32 *)((char *)&lbl_8032BEB4 + 4);
    values[2] = *(s32 *)((char *)&lbl_8032BEB4 + 8);
    stride = *(s32 *)((char *)arg0 + 0xC);
    index = *(s32 *)((char *)arg0);
    base = *(s32 *)((char *)arg0 + 0x10);
    fn_801376A8(base + arg1 * stride + index * 8 + 0x18, (s32 *)((char *)&values[0]), arg1, base, &lbl_8032BEB4);
}

s32 fn_8013705C(f32 arg0, f32 arg1) {
    return arg0 * arg1 >= lbl_80561368;
}

s32 fn_80137140(s32 arg0, s32 arg1) {
    void *p27 = (void *)fn_8017960C(arg0);
    void *p28 = (void *)fn_8017960C(arg1);
    void *p29 = (void *)fn_802C6C34(*(s32 *)((char *)p27 + 0x59C));
    void *p30 = (void *)fn_802C6C34(*(s32 *)((char *)p28 + 0x59C));
    s32 result = 0;
    if (fn_80137078((char *)p27 + 0x3C, (char *)p28 + 0x3C, *(f32 *)((char *)p29 + 0x40), *(f32 *)((char *)p30 + 0x3C))) {
        if (fn_80137078((char *)p28 + 0x3C, (char *)p27 + 0x3C, *(f32 *)((char *)p30 + 0x40), *(f32 *)((char *)p29 + 0x3C))) result = 1;
    }
    return result;
}

void fn_8013776C(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f0 = *(f32 *)((char *)arg0 + 0x20);
    temp_f1 = *(f32 *)((char *)arg0 + 0x1C);
    *(f32 *)((char *)arg0 + 0x18) = temp_f1 * temp_f1 + temp_f0 * temp_f0;
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

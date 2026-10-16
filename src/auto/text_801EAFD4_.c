// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef unsigned char u8;
extern s32 lbl_8033A048;
extern s32 lbl_802F9A08[];
extern s32 lbl_804885E8[];
extern f32 lbl_80562E68;
extern f32 lbl_8055EB98[2];
s32 fn_801EB0E8(void) { return 0; }

s32 fn_801EB0F0(s32 arg0) {
    s32 var_r0 = 0;
    if ((arg0 >= 0) && (arg0 < 0x18)) var_r0 = 1;
    return var_r0;
}

s32 fn_801EB110(void *arg0) {
    return lbl_804885E8[((u32 *)arg0)[4]];
}

void fn_801EB128(void) {
    lbl_8055EB98[0] = lbl_80562E68;
    lbl_8055EB98[1] = lbl_80562E68;
}

void fn_801EB6A4(void) {

}

void fn_801EB800(void *object, s32 arg1, s32 arg2) {
    struct V { void **vtable; };
    struct V *v=(struct V *)object;
    ((void (*)(void *, s32, s32))v->vtable[10])(object,arg2,arg1);
}

void fn_801EB81C(void) {

}

void fn_801EB820(void) {

}

void fn_801EB824(void) {
    s32 sp8=lbl_8033A048;
    fn_801EB000(&sp8);
}

void fn_801EB854(void) {
    s32 *a=lbl_802F9A08;
    s32 *b=lbl_804885E8;
    u32 i=0;
    do {
        fn_801EB96C(b,*((s32 *)a+1));
        i++; a+=2; b++;
    } while(i<0x18);
}

void fn_801EB968(void) {

}

void fn_801EBD14(void) {

}

void fn_801EC19C(void) {

}
extern s32 lbl_802F9A08[];
extern s32 fn_801EB000(s32 *);
extern s32 fn_801EB96C(s32 *, s32);
extern void fn_801EB634(void *, s32);

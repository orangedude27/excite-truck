#include <types.h>

extern char lbl_8055DF88;
extern u8 lbl_8055DF80;
extern s32 *lbl_8055DF84;
extern s32 lbl_8055DF98;
extern char lbl_8041E140[];
extern char lbl_8032A000[];
extern char lbl_8032A068[];
extern char lbl_8032A074[];
extern char lbl_8055DF8C;

s32 fn_801281F4(s32, s32);
void fn_802E30C8(void *, void *, void *);
s32 fn_802E317C(void *, void *);
void fn_8012834C(void *, void *, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80128208(void) {

}

void fn_801282E8(void) {

}

void fn_80128678(void) {
    lbl_8055DF88 = 1;
}

extern char lbl_8055DF88;
void fn_80128684(void) {
    lbl_8055DF88 = 0;
}

s32 fn_80128690(void) {
    u8 val = lbl_8055DF88;
    u32 shifted;
    shifted = __cntlzw(val);
    return shifted >> 5;
}

void fn_80128710(void) {

}

void fn_801291BC(void) {

}

void fn_801291C0(void) {

}

void fn_801291C4(void) {

}

void fn_80129214(void) {

}

void fn_80129218(void) {

}

void fn_80128584(s32, s32);

void fn_80128658(void) {
    fn_80128584(0, 1);
}

void fn_80128660(void) {
    fn_80128584(0, 2);
}

void fn_80128668(void) {
    fn_80128584(0, 3);
}

void fn_80128670(void) {
    fn_80128584(0, 0);
}

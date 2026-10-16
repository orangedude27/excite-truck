// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef float f32;
typedef double f64;

extern f32 fn_8020A5F0(void);
extern void fn_80210444(void);
extern void fn_8020C140(void);

extern s32 lbl_8055EE3C;
extern s8 lbl_8055EE40;
extern s8 lbl_8055EE44;
extern s8 lbl_8055EE45;
extern s8 lbl_8055EE46;
extern f32 lbl_8055EE48;
extern f32 lbl_8055EE4C;
extern f32 lbl_8055EE50;
extern f32 lbl_8055EE54;
extern f32 lbl_805632F0;

void fn_8020C54C(void) {
    fn_80210444();
    lbl_8055EE4C = lbl_805632F0;
    lbl_8055EE50 = lbl_805632F0;
    lbl_8055EE54 = lbl_805632F0;
    lbl_8055EE48 = fn_8020A5F0();
    lbl_8055EE40 = 0;
    lbl_8055EE44 = 0;
    lbl_8055EE3C = 0;
    lbl_8055EE45 = 0;
    lbl_8055EE46 = 0;
}

void fn_8020C8F4(void) {

}

void fn_8020C8F8(void) {

}

void fn_8020C8FC(void) {

}

void fn_8020C900(s8 arg0) {
    lbl_8055EE40 = arg0;
}

void fn_8020C908(f32 arg0) {
    lbl_8055EE48 = arg0;
    fn_8020C140();
}

void fn_8020C910(f32 arg0) {
    lbl_8055EE50 = arg0;
}

void fn_8020C918(void) {

}

void fn_8020C91C(void) {

}


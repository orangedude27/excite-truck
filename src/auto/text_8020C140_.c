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

extern void fn_8021037C(void);
extern s32 fn_80207848(const char *, s32);
extern const char lbl_8033C5FC[];
extern s32 lbl_8055EE38;
#pragma scheduling off
void fn_8020C41C(void) {
    fn_8021037C();
    lbl_8055EE38 = fn_80207848(lbl_8033C5FC, 1);
    lbl_8055EE45 = 0;
    lbl_8055EE46 = 0;
}

extern s32 fn_8012E498(s32 *);
extern s32 fn_802103BC(void);
__declspec(section ".data") extern s32 lbl_80489BE0;
__declspec(section ".data") extern s32 lbl_80489C50;
extern s32 *lbl_8055B5D0;
extern s32 *lbl_8055B5D4;
__declspec(section ".data") extern s32 lbl_80489BE0;
__declspec(section ".data") extern s32 lbl_80489C50;
extern s8 lbl_8055EE41;
extern s8 lbl_8055EE42;
extern s8 lbl_8055EE43;
extern f32 lbl_805632DC;
extern void fn_8012E81C(s32 *);
extern s32 fn_8012E938(s32 *);
extern s32 fn_80128690(void);
extern void fn_80128684(void);
extern void fn_80128678(void);
extern void fn_802064D0(s32 *);
extern s8 lbl_8055EE41;
extern s8 lbl_8055EE42;
extern s8 lbl_8055EE43;
void fn_8020C45C(void) {
    s32 *var_r29;
    s32 var_r28;
    void *temp_r3;
    void *temp_r3_2;
    s32 (**method)(void *, s32);
    temp_r3 = (void *)lbl_8055EE38;
    if (temp_r3 != 0 && temp_r3 != 0) {
        method = (s32 (**)(void *, s32))*(s32 **)temp_r3;
        method[2](temp_r3, 1);
    }
    lbl_8055EE38 = 0;
    fn_802103BC();
    var_r29 = &lbl_80489BE0;
    var_r28 = 0;
    do {
        temp_r3 = *(void **)((u8 *)var_r29 + 0x20);
        if (temp_r3 != 0) {
            *(s8 *)((u8 *)temp_r3 + 0x4A) = 1;
            *(s8 *)((u8 *)temp_r3 + 0x4C) = 0;
            temp_r3_2 = *(void **)((u8 *)var_r29 + 0x20);
            if (temp_r3_2 != 0) {
                method = (s32 (**)(void *, s32))*(s32 **)temp_r3_2;
                method[2](temp_r3_2, 1);
            }
            *(void **)((u8 *)var_r29 + 0x20) = 0;
        }
        var_r28 += 1;
        var_r29 += 9;
    } while (var_r28 < 3);
    fn_8012E498(&lbl_80489C50);
    fn_8012E498(lbl_8055B5D4);
    fn_8012E498(lbl_8055B5D0);
    lbl_8055EE43 = 0;
    lbl_8055EE42 = 0;
    lbl_8055EE41 = 0;
}

#pragma scheduling on
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


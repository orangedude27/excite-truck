#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055D644;
extern char lbl_8055D645;
extern int lbl_8055D638;
extern int lbl_8055D63C;
extern int lbl_8055D640;
extern unsigned char lbl_8055D670;
extern int lbl_8055D64C;
extern unsigned int lbl_8055E044;
extern float lbl_805604A8;
extern float lbl_805604AC;
extern float lbl_805604B0;
extern float lbl_805604B4;
extern float lbl_805604B8;
extern char lbl_802FE138[];
extern int lbl_80558D78;
extern int lbl_80558D7C;
extern int lbl_80558D80;
extern int lbl_80558D84;
extern int lbl_8055D62C;
extern int lbl_8055D650;
extern int lbl_8055D654;
extern int lbl_8055D658;
extern void fn_8012E81C(void*);
extern int fn_80232578(void*);
extern int fn_8023512C(void*);
extern int fn_802CAC28(void*, int);
extern void fn_802CAC54(int);
extern void fn_802328D4(int);
extern void fn_80235380(int);
extern void fn_801345D8(void*, int, void*, int);
struct lbl_8035BAE4_t {
    int unk_0;
    int unk_4;
    unsigned int unk_8;
};
extern struct lbl_8035BAE4_t lbl_8035BAE4;
extern char lbl_802FE1C0[0x100];
int fn_802E2C20(void);
void fn_80176734(void);
int fn_801312EC(void*, void*);
void fn_80131318(void);
int fn_80232BA4(int, int, int, int, float, float, float, float, float);

void fn_8001FE20(void) {
    lbl_8055D62C = 0;
    fn_802CAC54(lbl_80558D84);
    lbl_80558D84 = -2;
    fn_802CAC54(lbl_80558D80);
    lbl_80558D80 = -2;
    fn_802CAC54(lbl_80558D78);
    lbl_80558D78 = -2;
    fn_802CAC54(lbl_80558D7C);
    lbl_80558D7C = -2;
    fn_802328D4(lbl_8055D64C);
    lbl_8055D64C = 0;
    fn_802328D4(lbl_8055D650);
    lbl_8055D650 = 0;
    fn_80235380(lbl_8055D654);
    lbl_8055D654 = 0;
    fn_80235380(lbl_8055D658);
    lbl_8055D658 = 0;
}

void fn_8001FEB8(void) {
    lbl_8055D645 = 1;
    lbl_8055D640 = fn_802E2C20();
    fn_80176734();
}

void fn_8001FEE8(void) {
    int temp_r3;
    int var_r4;

    temp_r3 = fn_802E2C20();
    var_r4 = 0;
    lbl_8055D63C = temp_r3;
    lbl_8055D638 = temp_r3;
    lbl_8055D640 = var_r4;
    lbl_8055D644 = var_r4 + 1;
    lbl_8055D645 = var_r4;
}

#pragma dont_inline on
void fn_8001FF24(void) {
    lbl_8055D644 = 0;
    lbl_8055D645 = 0;
}
#pragma dont_inline off

extern char lbl_802FE138[];
extern int lbl_80558D78;
extern int lbl_80558D7C;
extern int lbl_80558D80;
extern int lbl_80558D84;
extern int lbl_8055D62C;
extern int lbl_8055D650;
extern int lbl_8055D654;
extern int lbl_8055D658;
extern void fn_8012E81C(void*);
extern int fn_80232578(void*);
extern int fn_8023512C(void*);
extern int fn_802CAC28(void*, int);
extern void fn_802CAC54(int);
extern void fn_802328D4(int);
extern void fn_80235380(int);
extern void fn_801345D8(void*, int, void*, int);
void fn_8001FF34(int arg0) {
    struct lbl_8035BAE4_t* tmp;
    if ((char)lbl_8055D670 == 0) {
        fn_801312EC(&lbl_8035BAE4, &lbl_802FE1C0);
        lbl_8055D670 = 1;
    }
    tmp = &lbl_8035BAE4;
    if (tmp->unk_8 != lbl_8055E044) {
        fn_80131318();
    }
    fn_80232BA4(tmp->unk_4, lbl_8055D64C, arg0, 0x12, lbl_805604A8, lbl_805604AC, lbl_805604B0, lbl_805604B4, lbl_805604B8);
}

void fn_8001FFD0(int arg0, int arg1, void* arg2, int arg3) {
    if (arg1 == 0x180303) {
        fn_801345D8(arg2, arg3, &lbl_802FE138[0x98], arg0 + 1);
    } else if (arg1 < 0x180303) {
        if (arg1 == 0x180201) {
            fn_801345D8(arg2, arg3, &lbl_802FE138[0xac], arg0 + 1);
        } else {
            fn_801345D8(arg2, arg3, &lbl_802FE138[0xd4], arg0 + 1);
        }
    } else if (arg1 < 0x180305) {
        fn_801345D8(arg2, arg3, &lbl_802FE138[0xc0], arg0 + 1);
    } else {
        fn_801345D8(arg2, arg3, &lbl_802FE138[0xd4], arg0 + 1);
    }
}

void fn_80020430(void) {
    fn_8001FF24();
}

void fn_8002167C(void) {
    fn_8001FF24();
}

void fn_800216C4(void) {

}

extern char lbl_8055D644;
extern char lbl_8055D645;
extern int lbl_8055D638;
extern int lbl_8055D63C;
extern int lbl_8055D640;
extern unsigned char lbl_8055D670;
extern int lbl_8055D64C;
extern unsigned int lbl_8055E044;
extern float lbl_805604A8;
extern float lbl_805604AC;
extern float lbl_805604B0;
extern float lbl_805604B4;
extern float lbl_805604B8;
int fn_802E2C20(void);
void fn_80176734(void);
int fn_801312EC(void*, void*);
void fn_80131318(void);
int fn_80232BA4(int, int, int, int, float, float, float, float, float);
char fn_800216F4(void) {
    return lbl_8055D644;
}

void fn_800218F4(void) {
    fn_8001FD7C();
}

void fn_800218F8(void) {
    fn_8001FE20();
}


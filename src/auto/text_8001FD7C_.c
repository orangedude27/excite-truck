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
extern char lbl_8035BAE4;
extern char lbl_802FE1C0;
int fn_802E2C20(void);
void fn_80176734(void);
int fn_801312EC(void*, void*);
void fn_80131318(void);
int fn_80232BA4(int, int, int, int, float, float, float, float, float);

void fn_8001FEB8(void) {
    lbl_8055D645 = 1;
    lbl_8055D640 = fn_802E2C20();
    fn_80176734();
}

void fn_8001FEE8(void) {
    int temp_r3;

    temp_r3 = fn_802E2C20();
    lbl_8055D63C = temp_r3;
    lbl_8055D638 = temp_r3;
    lbl_8055D640 = 0;
    lbl_8055D644 = 1;
    lbl_8055D645 = 0;
}

#pragma dont_inline on
void fn_8001FF24(void) {
    lbl_8055D644 = 0;
    lbl_8055D645 = 0;
}
#pragma dont_inline off

void fn_8001FF34(int arg0) {
    if ((char)lbl_8055D670 == 0) {
        fn_801312EC(&lbl_8035BAE4, &lbl_802FE1C0);
        lbl_8055D670 = 1;
    }
    if (*(unsigned int*)((char*)&lbl_8035BAE4 + 8) != lbl_8055E044) {
        fn_80131318();
    }
    fn_80232BA4(*(int*)((char*)&lbl_8035BAE4 + 4), lbl_8055D64C, arg0, 0x12, lbl_805604A8, lbl_805604AC, lbl_805604B0, lbl_805604B4, lbl_805604B8);
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


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055EE74, lbl_8055EE78, lbl_8055EEA0;
extern char lbl_8055EE94;
extern float lbl_8055EE84, lbl_8055EE88, lbl_8055EE8C, lbl_8055EE90, lbl_8055EE98, lbl_8055EE9C;
extern float lbl_8056331C, lbl_80563320;
extern char lbl_8033C6B0, lbl_8033C6BC;
extern void fn_80209190(int, float);
extern void fn_80206454(void);
extern void fn_801769EC(void);
extern void fn_80206444(void);
extern float fn_80209028(void);
extern float fn_8020A5F0(void);
extern int fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80230E90(int);
extern void *fn_802090D4(void *);
extern void *fn_80145E70(void *);
extern void fn_80209110(void *);

void fn_8020CF68(void) {
    fn_802104D0();
}

void fn_8020D224(void) {
    float value;
    lbl_8055EE94 = 1;
    value = fn_80209028();
    lbl_8055EE90 = value;
    lbl_8055EE88 = value;
    value = fn_8020A5F0();
    lbl_8055EE8C = value;
    lbl_8055EE84 = value;
    if (fn_80265D64() == 0)
        __AXDSPInitCallback_801769E0();
    fn_80206444();
    fn_80209190(lbl_8055EE74, lbl_80563320);
    lbl_8055EE78 = 0;
    lbl_8055EE9C = lbl_80563320;
    lbl_8055EE98 = lbl_80563320;
    fn_80230E90(1);
}

void fn_8020D29C(void) {
    lbl_8055EE94 = 0;
    fn_80209190(lbl_8055EE74, lbl_8056331C);
    fn_80206454();
    fn_801769EC();
}

extern void *lbl_8055EE7C;
extern void *lbl_8055EE80;
void AXFXSetHooks_8020DE10(void *arg0, void *arg1) {
    lbl_8055EE7C = arg0;
    lbl_8055EE80 = arg1;
}

extern char lbl_8055EE94;
char fn_8020DE1C(void) {
    return lbl_8055EE94;
}


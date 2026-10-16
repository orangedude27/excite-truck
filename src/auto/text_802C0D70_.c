// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;

extern char lbl_8055FB18[4];
extern void fn_802C0FD4(int *queue);
void fn_802C1018(void) {
    fn_802C0FD4((int *)&lbl_8055FB18);
}

extern void fn_802C6CF8(int);
extern float *fn_802C86DC(float);
extern void fn_802C744C(int, float *);
extern void fn_802A4E08(void);
extern void fn_8029231C(char *);
extern int fn_8012C33C(char (*)[4]);
extern int fn_802B2C34(void *, char (*)[4]);
extern int fn_802C6DC4(char (*)[4], int, int);
extern void fn_802C0E68(int);
extern void fn_802C0F4C(void);
extern void fn_802C6B44(void);
extern char lbl_8055FB14[4];
extern char lbl_8055CF98[4];
extern char lbl_804C0800[4];
extern float lbl_80564E38;
extern float lbl_80564E48;
void fn_802C1020(void) {
    float sp[12];
    float *sp_ptr = sp;
    float *obj;
    if (*(int *)lbl_8055FB14 != -1) {
        sp[1] = lbl_80564E38; sp[0] = lbl_80564E48;
        sp[2] = lbl_80564E38; sp[3] = lbl_80564E38;
        sp[4] = lbl_80564E48; sp[5] = lbl_80564E38;
        sp[6] = lbl_80564E38; sp[7] = lbl_80564E38;
        sp[8] = lbl_80564E48;
        obj = fn_802C86DC(lbl_80564E48);
        sp[9] = obj[9]; sp[10] = obj[10]; sp[11] = obj[11];
        fn_802C744C(*(int *)lbl_8055FB14, sp_ptr);
    }
    fn_802A4E08();
    fn_8029231C((void *)((char *)lbl_804C0800));
}

void fn_802C10B8(void) {
    *(s32 *)lbl_8055FB14 = -1;
    fn_802C0F4C();
}

void fn_802C10C4(void) {
    fn_802C1018();
}

void fn_802C10C8(void) {
    fn_802C1020();
}


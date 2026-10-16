// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055EC18;
extern void *lbl_8055EC14;
extern void *lbl_8055EC10;
extern void *lbl_8055EC1C;
extern void *lbl_8055EC20;
extern char lbl_8033ACE8[32];
extern void fn_801F7160(void *);
extern void fn_801F7220(void *);
extern void *fn_802AE414(void);
extern void fn_802E317C(const char *, ...);
extern void fn_801F7280(void *, void *, void *);
extern void fn_801F70D0(void *, int);
extern void fn_801F6D60(void *, int);
extern void fn_801F6A08(void *, int);
void fn_801F4D64(void) {
    fn_801F70D0(lbl_8055EC18, 1);
    lbl_8055EC18 = 0;
    fn_801F6D60(lbl_8055EC14, 1);
    lbl_8055EC14 = 0;
    fn_801F6A08(lbl_8055EC10, 1);
    lbl_8055EC10 = 0;
    lbl_8055EC1C = 0;
    lbl_8055EC20 = 0;
}

void fn_801F4DC4(void) {
    fn_801F7160(lbl_8055EC18);
}

void fn_801F4DCC(void) {
    fn_801F7220(lbl_8055EC18);
}

void fn_801F4DD4(void *arg0, void *arg1) {
    void *temp_r3;
    temp_r3 = fn_802AE414();
    if (temp_r3 == 0) {
        fn_802E317C(lbl_8033ACE8, arg0);
    }
    fn_801F7280(lbl_8055EC18, temp_r3, arg1);
}

void fn_801F596C(void) {

}

extern void fn_801F6A98(void *);
extern void fn_801F6B98(void *);
extern void fn_801F6DF0(void *);
extern void fn_801F6EC0(void *);
void fn_801F73F8(void) { fn_801F6EC0(lbl_8055EC14); }

void fn_801F78D8(void) {

}

void fn_801F7A00(void) {

}
extern void fn_801F6A98(void *);
extern void fn_801F6B98(void *);
extern void fn_801F6DF0(void *);
extern void fn_801F6EC0(void *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_801FC8D8(void);
extern void fn_801EBBB4(void);
extern void fn_801EBD70(void);
extern void fn_801EBDCC(void);
extern void fn_801EBEF4(float);
extern void fn_801EB9FC(void *);
extern float lbl_80563028;
#pragma push
#pragma small_data off
extern int lbl_8033B5C8;
#pragma pop

extern void fn_801FC8A8(void);
extern void fn_801EBEF4(float);
extern void fn_801EB9FC(void *);
extern float lbl_80563028;
extern int lbl_8033B5C8;
void fn_801FC8A8(void) {
    fn_801EBEF4(lbl_80563028);
    fn_801EB9FC(&lbl_8033B5C8);
}

void fn_801FC8D8(void) {
    fn_801EBBB4();
}

void fn_801FC900(void) {
    fn_801FC8D8();
}

void fn_801FC904(void) {
    fn_801EBD70();
}

void fn_801FC908(void) {
    fn_801EBDCC();
}


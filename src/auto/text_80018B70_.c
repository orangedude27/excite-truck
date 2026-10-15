#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80018B70(void) {
    fn_8027DEAC();
}

void fn_80018E3C(void) {
    fn_80018B74();
}

void fn_80018E40(void) {
    fn_80018B70();
}

void fn_800194C8(void) {
    fn_80019438();
}

extern char lbl_8055D588;
extern void *lbl_802FD404;
void fn_80131234(void *);
void fn_80019708(void) {
    lbl_8055D588 = 0;
}

char fn_80019714(void) {
    return lbl_8055D588;
}

void fn_800196FC(void) {
    lbl_8055D588 = 1;
}

void fn_800196F0(void) {
    fn_80131234(&lbl_802FD404);
}
#include <types.h>

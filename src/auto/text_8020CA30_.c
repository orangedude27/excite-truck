// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8020CA30(void) {

}

void fn_8020CA34(void) {

}

void fn_8020CA38(void) {

}

extern char lbl_8033C650[];
typedef float f32;
extern f32 lbl_80563304;
extern f32 lbl_80563308;
extern f32 lbl_8056330C;
extern void* fn_801D04A8(int);
#pragma scheduling invalid_target
void *fn_8020CC78(void *arg0, int arg1) {
    register void **vtable;
    void *cur;
    int i;

    if (arg0 != 0) {
        *(void **)arg0 = lbl_8033C650;
        cur = arg0;
        i = 0;
        while (i < *(int *)((char *)arg0 + 8)) {
            void *item = *(void **)((char *)cur + 0xC);
            if (item == 0) {
                goto next;
            }
            if (item == 0) {
                goto next;
            }
            vtable = *(void ***)item;
            ((void (*)(void *, int))vtable[2])(item, 1);
        next:
            cur = (char *)cur + 0x24;
            i++;
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma scheduling on


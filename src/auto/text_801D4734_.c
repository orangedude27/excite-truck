// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern char lbl_803388F0[];

void fn_801D47F4(void) {
    fn_801D57F0();
}

void fn_801D4888(void) {
    fn_801D5860();
}

void fn_801D48F4(void) {
    fn_801D58DC();
}

void fn_801D48F8(void) {
    fn_801D592C();
}

void fn_801D48FC(void) {
    fn_801D5A14();
}

void fn_801D4900(void) {
    fn_801D5A1C();
}

void fn_801D4904(void) {
    fn_801D5A24();
}

void fn_801D4908(void) {
    fn_801D5A2C();
}

void fn_801D4F9C(void) {
}

void fn_801D5010(void) {
}

char *fn_801D77AC(void) {
    return lbl_803388F0;
}

s32 fn_801D77B8(s32 arg0) {
    return ((s32 *)arg0)[2];
}

s32 fn_801D77C0(s32 arg0) {
    s32 *ptr = (s32 *)arg0;
    if (ptr[2] == 0) {
        return arg0;
    }
    ptr[2] = 1;
    return arg0;
}

s32 fn_801D77B8(s32 arg0);
s32 fn_801D77C0(s32 arg0);
void fn_80116BCC(void *);
void fn_80127464(void *);
void fn_801D77D8(void *arg0) {
    void **vtable = *(void ***)arg0;
    ((void (*)(void *))vtable[0xD])(arg0);
}

void fn_801D77E8(void) {

}

void fn_801D77EC(void *arg0, s32 arg1) {
    s32 *ptr = (s32 *)arg0;
    s32 count = ptr[0x1D];
    s32 *array = (s32 *)ptr[0x1C];
    s32 r6 = 0;
    s32 r7 = 0;
    
    if (count <= 0) {
        goto post_loop;
    }
    
    for (; r7 < count * 4; r7 += 4, r6++) {
        if (array[r7 / 4] == arg1) {
            goto post_loop;
        }
    }
    
    r6 = -1;
    
post_loop:
    if (r6 == -1) {
        return;
    }
    if (r6 <= 0) {
        return;
    }
    if (r6 >= count) {
        return;
    }
    if (r6 == count - 1) {
        array[r6] = array[count - 1];
        ptr[0x1D] = count - 1;
    }
}

void fn_801D8620(void) {

}

void fn_801D8938(void) {

}

void fn_801D8B50(void) {

}

void fn_801D8B54(void) {

}

void fn_801D8B58(void) {

}

void fn_801D8B5C(void) {

}

void fn_801D8C18(void) {

}

void fn_801D8C94(void) {

}


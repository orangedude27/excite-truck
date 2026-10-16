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

s32 fn_801D4CB8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801D4F9C(void) {
}

void fn_801D5010(void) {
}

void *fn_801D774C(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 val = ((s32)arg0 + 0x24);
        if (val == 0) {
            goto skip;
        }
        if (val == 0) {
            goto skip;
        }
        *(s32 *)((u8 *)arg0 + 0x24) = 0;
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
        *(s32 *)((u8 *)arg0 + 0x2C) = 0;
skip:
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
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
    ((void (*)(void *))vtable[13])(arg0);
}

void fn_801D77E8(void) {

}

void fn_801D77EC(void *arg0, s32 arg1) {
    s32 *ptr = (s32 *)arg0;
    s32 count = ptr[0x1D];
    s32 idx = 0;
    s32 byte_offset = 0;
    
    if (count > 0) {
        s32 *array = (s32 *)ptr[0x1C];
        
        for (; idx < count; idx++) {
            if (array[byte_offset / 4] == arg1) {
                goto post_loop;
            }
            byte_offset += 4;
        }
        
        idx = -1;
    }
    
post_loop:
    if (idx == -1) {
        return;
    }
    if (idx < 0) {
        return;
    }
    if (idx >= count) {
        return;
    }
    if (idx == count - 1) {
        ptr[0x1C] = (s32)((s32 *)ptr[0x1C]);
        ((s32 *)ptr[0x1C])[idx] = ((s32 *)ptr[0x1C])[count - 1];
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


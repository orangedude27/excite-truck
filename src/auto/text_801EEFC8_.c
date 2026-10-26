// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_80488678[];
void *memset(void *, int, unsigned int);
#pragma scheduling off
void fn_801EEFC8(void) {
    memset(lbl_80488678, 0, 0x120);
}
#pragma scheduling on
void fn_801EEFDC(int arg0, unsigned int arg1) {
    int i;
    unsigned int *base = (unsigned int *)(lbl_80488678 + ((arg1 & 0xFF) << 4));
    for (i = 0; i < 4; i++) {
        if (base[i] == 0) {
            base[i] = arg0;
            return;
        }
    }
}
void fn_802E317C(const char *, ...);
extern char lbl_8033A328[];
#pragma scheduling invalid_target
void fn_801EF024(unsigned int arg0) {
    unsigned int *base = (unsigned int *)lbl_80488678;
    unsigned int *p;
    int found = 0;
    int i;
    int j;

    for (i = 0; i < 18; i++, base += 4) {
        p = base;
        for (j = 0; j < 4; p++, j++) {
            if (*p == arg0) {
                *(volatile unsigned int *)((char *)lbl_80488678 + (i << 4) + (j << 2)) = 0;
                found = 1;
                goto done;
            }
        }
    }
done:
    if (!found) {
        fn_802E317C(lbl_8033A328);
    }
}

extern char lbl_8033A354[];
#pragma scheduling invalid_target
#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_801EF0AC(unsigned char *arg0) {
    char buf[0x400];
    unsigned int *slot;
    unsigned char *data;
    int index = 0;
    int ret;
    signed char id;
    unsigned int i;

    while (index < (int)*(unsigned int *)arg0) {
        id = (signed char)arg0[index + 4];
        data = arg0 + index + 5;
        ret = -1;
        slot = (unsigned int *)(lbl_80488678 + id * 16);
        for (i = 0; i < 4; i++, slot++) {
            if (*slot != 0) {
                memcpy(buf, data, 0x400);
                ret = ((int (*)(char *))*slot)(buf);
            }
        }
        if (ret != -1) {
            index = index + ret + 1;
        } else {
            fn_802E317C(lbl_8033A354, *((volatile unsigned char *)arg0 + index + 4));
            return;
        }
    }
}
#pragma pop
#pragma scheduling on
void fn_801EF184(void) {

}

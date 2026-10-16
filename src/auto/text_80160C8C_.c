// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_8056185C;
extern float lbl_8055E3C8;
extern float lbl_80561868;

void fn_8016212C(void) {
    fn_801613E0();
}

void fn_80162170(void) {

}

void fn_80162174(void) {
}

void fn_80162214(void) {
    if (fn_801C5B60() == 0) {
        fn_801DF074(8, 0);
    }
}

int fn_80162248(void) {
    return 0;
}

int fn_80162250(void) {
    return 0;
}

void fn_80162258(void) {

}

void fn_8016225C(void) {
}

int fn_80162260(void) {
    return 0;
}

unsigned char fn_80163F6C(void *arg0) {
    return *((unsigned char *)arg0 + 0x56D);
}

unsigned char fn_80163F74(void *arg0) {
    return *((unsigned char *)arg0 + 0x56D);
}

int fn_801643C8(void *arg0) {
    int var_r30;
    int var_r31;
    void **temp_r3;

    var_r31 = 0;
    var_r30 = 0;
loop_4:
    if (var_r30 < *((int *)((char *)arg0 + 0xE4))) {
        if (*((int *)(*((char **)((char *)arg0 + 0xE0)) + var_r31 + 0x34)) != 0) {
            fn_80128658();
        }
        var_r31 += 0x48;
        var_r30 += 1;
        goto loop_4;
    }
    temp_r3 = *((void ***)((char *)arg0 + 0xDC));
    if (temp_r3 != 0) {
        ((void (*)(void *, int))(*(void ***)temp_r3)[1])(temp_r3, 1);
    }
    fn_802CAC54(*((int *)((char *)arg0 + 0xD0)));
    fn_802C6CF8(*((int *)((char *)arg0 + 0xA0)));
}

int fn_80164468(void *arg0) {
    return *((float *)((char *)arg0 + 0x8C)) < lbl_8056185C;
}

void fn_80164D58(void) {

}

void fn_80164D5C(void) {
}

void fn_80164D60(void) {

}

void fn_80165248(void) {

}

void fn_80165820(void) {
}


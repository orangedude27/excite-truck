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
    void *obj;

    var_r31 = 0;
    var_r30 = 0;
    while (var_r30 < *((int *)((char *)arg0 + 0xE4))) {
        obj = *((void **)((char *)arg0 + 0xE0));
        if (*((int *)((char *)obj + var_r31 + 0x34)) != 0) {
            fn_80128658();
        }
        var_r31 += 0x48;
        var_r30 += 1;
    }
    obj = *((void **)((char *)arg0 + 0xDC));
    if (obj != 0) {
        ((void (*)(int))(*(void ***)obj)[2])(1);
    }
    fn_802CAC54(*((int *)((char *)arg0 + 0xD0)));
    fn_802C6CF8(*((int *)((char *)arg0 + 0xA0)));
}

int fn_80164468(void *arg0) {
    return *((float *)((char *)arg0 + 0x8C)) < lbl_8056185C;
}

void fn_80164480(void *arg0) {
    int sp10[2];
    float sp8;

    if (((int (*)(void *))(*(void ***)arg0)[9])(arg0) != 0) {
        if ((lbl_8055E3C8 - *((float *)((char *)arg0 + 0xC))) > lbl_80561868) {
            fn_80020434(sp10, &sp8);
            fn_8026A2CC(sp10, 0, sp8);
            fn_8000C630(0x15, -1);
            return;
        }
        fn_8000C630(0x20, -1);
    }
}

int fn_80164868(void) {
    return 1;
}

int fn_80164894(void *arg0, void *arg1, int arg2) {
    *(float *)arg1 = *(float *)((char *)arg0 + (arg2 << 2) + 0x14);
    return 1;
}

extern int fn_80128668(void);
int fn_80164CF8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80164D58(void) {

}

void fn_80164D5C(void) {
}

void fn_80164D60(void) {

}

unsigned char fn_80165040(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

unsigned char fn_80165048(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

unsigned char fn_80165050(void *arg0) {
    return *((unsigned char *)arg0 + 5);
}

int fn_80165240(void) {
    return 0;
}

void fn_80165248(void) {

}

int fn_801657D4(void) { return 1; }

void fn_801657DC(void) {
    int sp10[12];
    float sp8;
    fn_80020434(sp10, &sp8);
    fn_8026A2CC(sp10, 0, sp8);
    fn_8000C630(0x15, -1);
}

void fn_80165820(void) {
}

int fn_80165824(void) { return 0; }

int fn_8016582C(void) { return 0; }

int fn_80165900(void) { return 1; }

int fn_80165908(void) { return 0; }


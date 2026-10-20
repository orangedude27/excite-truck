

extern char lbl_803387C8[];
extern char lbl_80338BD0[];
extern int fn_80128668(void);
extern char lbl_8033905C[];
extern char lbl_8033907C[];
extern float lbl_8055E3C8;
extern char lbl_803388D4[];
extern char lbl_8033890C[];
extern void fn_8016A240(const char *arg0);
extern int lbl_8055E3C4;
extern void fn_801D5328(int, int);
void fn_801D4904(void) {
    fn_801D5A24();
}

void fn_801D4908(void) {
    fn_801D5A2C();
}

int fn_801D4CB8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801D4F9C(void) {
}

void fn_801D5010(void) {
}

int fn_801D50A0(void) {
    return 0;
}

void fn_801D50B0(int arg0) {
    fn_801D5328(arg0, 0);
}

int fn_801D544C(void) {
    return 0;
}

int fn_801D6500(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D6508(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[7] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

void fn_801D6600(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D6630(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

int fn_801D67D4(void) {
    return (int)lbl_803387C8;
}

int fn_801D67E0(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D67E8(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

void fn_801D68D0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

void fn_801D68E8(int arg0) {
    ((int *)arg0)[0] = (int)lbl_80338BD0;
    ((int *)arg0)[1] = 0;
}

int fn_801D6900(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

int fn_801D6C28(void) {
    extern char lbl_80338868[];
    return (int)lbl_80338868;
}

int fn_801D6C34(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D6C3C(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

void fn_801D6D68(int arg0) {
    extern char lbl_80338B98[];
    ((char **)arg0)[0] = (char *)lbl_80338B98;
    ((int *)arg0)[1] = 0;
}

int fn_801D6D80(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

extern char lbl_80338868[];
extern char lbl_80338B98[];
extern char lbl_80338878[];
int fn_801D6ED0(void) {
    return (int)lbl_80338878;
}

void fn_801D6FA0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D7034(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void *fn_801D7200(void) {
    return lbl_803388D4;
}

int fn_801D720C(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D7214(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[1] = 2;
        *(float *)((char *)arg0 + 0x2C) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

void fn_801D72D0(int arg0) {
    int p;
    fn_8016A240((char *)arg0 + 8);
    p = ((int *)arg0)[0x38 / 4];
    ((int *)arg0)[1] = 1;
    if (p != 0 && *(char *)(p + 0x19) != 0) {
        *(char *)(p + 0x4A) = 1;
        *(char *)(p + 0x4C) = 0;
    }
    *(char *)(arg0 + 0x34) = 0;
}

int fn_801D7924(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[10] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void *fn_801D7C6C(void) {
    return lbl_8033890C;
}

int fn_801D7C78(int arg0) {
    return ((int *)arg0)[10];
}

void fn_801D7E3C(int arg0) {
    if (((int *)arg0)[10] != 0) {
        ((int *)arg0)[10] = 1;
    }
}

int fn_801D7F5C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern char lbl_80338928[];
void *fn_801D8148(void) {
    return lbl_80338928;
}

int fn_801D8154(void *arg0) {
    return *(int *)((char *)arg0 + 0x40);
}

void fn_801D832C(void *arg0) {
    if (*(int *)((char *)arg0 + 0x40) != 0) {
        *(int *)((char *)arg0 + 0x40) = 1;
    }
}

int fn_801D839C(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x18)) >> 5;
}

int fn_801D83DC(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

int fn_801D8518(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

void fn_801D85D8(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D85F0(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x14)) >> 5;
}

void fn_801D8600(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D8618(void) {
    return 0;
}

void fn_801D8620(void) {

}

void fn_801D8710(int arg0) {
    if (arg0 != 0) {
        arg0 += 4;
    }
    fn_801D05B4(arg0);
}

void *fn_801D8720(void) {
    return lbl_8033905C;
}

int fn_801D872C(int arg0) {
    return ((int *)arg0)[6];
}

int fn_801D8734(void) {
    return 0;
}

int fn_801D873C(int arg0) {
    ((int *)arg0)[6] = 2;
    ((int *)arg0)[8] = 0;
    *(float *)((char *)arg0 + 0x10) = lbl_8055E3C8;
    return 0;
}

void fn_801D8C18(void) {
}

void fn_801D8C94(void) {
}

int fn_801D8CA4(void *arg0) {
    return ((int *)arg0)[1];
}

void fn_801D8DB0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D8DC8(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void fn_801D8FE0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}




  extern char lbl_803387C8[];
  extern char lbl_80338C78[];
extern char lbl_80338BD0[];
extern int fn_80128668(void);
typedef struct { char *name; int state; } UnkStruct_801D701C;
extern char lbl_80339038[];
extern char lbl_8033905C[];
extern char lbl_8033907C[];
extern float lbl_8055E3C8;
extern char lbl_803388D4[];
extern char lbl_803388F0[];
extern char lbl_803389B8[];
extern char lbl_8033890C[];
extern void fn_8016A240(const char *arg0);
extern int lbl_8055E3C4;
extern void fn_801D5328(int, int);
void fn_801D47F4(void) {
    fn_801D57F0();
}

void fn_801D47F8(void* alarm) {
    fn_801D5488(fn_801D5650(alarm));
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

void fn_801D48FC(int arg0) {
    fn_801D5A14(arg0);
}

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

void fn_801D50A8(int arg0) {
    fn_801D5328(arg0, 1);
}

void fn_801D50B0(int arg0) {
    fn_801D5328(arg0, 0);
}

int fn_801D544C(void) {
    return 0;
}

void fn_801D59C8(int, int);
void fn_801D5A1C(int arg0) {
    fn_801D59C8(arg0, 1);
}

void fn_801D628C(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(char **)((char *)arg0 + 0) = lbl_80338C78;
    *(int *)((char *)arg0 + 0x14) = 0;
}

int *__AXFXGetLfoSinTable_801D64F4(void) {
    extern char lbl_803387A8[];
    return (int *)lbl_803387A8;
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

#pragma scheduling invalid_target
void fn_801D6618(UnkStruct_801D701C *arg0) {
    extern char lbl_80338C40[];
    arg0->name = lbl_80338C40;
    arg0->state = 0;
}
#pragma scheduling reset

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

#pragma scheduling invalid_target
void fn_801D6D68(UnkStruct_801D701C *arg0) {
    extern char lbl_80338B98[];
    arg0->name = lbl_80338B98;
    arg0->state = 0;
}
#pragma scheduling reset
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

int fn_801D6EDC(int arg0) {
    return ((int *)arg0)[1];
}

void fn_801D6FA0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

void fn_801D6FB8(int arg0) {
    if (*(unsigned char *)(arg0 + 0x34) == 0) {
        if (fn_8016A15C((char *)arg0 + 8) != 0) {
            int p = ((int *)arg0)[0x38 / 4];
            *(char *)(p + 0x49) = 1;
            *(char *)(p + 0x4B) = 0;
            *(char *)(p + 0x4A) = 0;
        }
        *(char *)(arg0 + 0x34) = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D701C(UnkStruct_801D701C *arg0) {
    extern char lbl_80338B08[];
    arg0->name = lbl_80338B08;
    arg0->state = 0;
}
#pragma scheduling reset
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

int fn_801D76CC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_801D770C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_801D774C(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (((int)arg0 + 0x24) != 0) {
            if (((int)arg0 + 0x24) != 0) {
                *(int *)((char *)arg0 + 0x24) = 0;
                *(int *)((char *)arg0 + 0x28) = 0;
                *(int *)((char *)arg0 + 0x2C) = 0;
            }
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

char *fn_801D77AC(void) {
    return lbl_803388F0;
}

int fn_801D77B8(int arg0) {
    return ((int *)arg0)[2];
}

int fn_801D77C0(int arg0) {
    if (((int *)arg0)[2] == 0) {
        return arg0;
    }
    ((int *)arg0)[2] = 1;
    return arg0;
}

void fn_801D77D8(void *arg0) {
    void **vtable = *(void ***)arg0;
    ((void (*)(void *))vtable[0xD])(arg0);
}

void fn_801D77E8(void) {
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

int fn_801D83BC(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x30)) >> 5;
}

int fn_801D83DC(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void *fn_801D8504(void) {
    return lbl_80339038;
}

int fn_801D8510(void *arg0) {
    return *(int *)((char *)arg0 + 0x4);
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

void fn_801D8938(void) {

}

int fn_801D8AA4(void *arg0) {
    extern float lbl_80562ADC;
    return *(float *)((char *)arg0 + 0x30) < lbl_80562ADC;
}

void fn_801D8B50(void) {
}

void fn_801D8B54(void) {
}

void fn_801D8B58(void) {
}

void fn_801D8B5C(void) {

}

void fn_801D8C0C(void *arg0) {
    *(int *)((char *)arg0 + 0x18) = -1;
}

void fn_801D8C18(void) {
}

void fn_801D8C94(void) {
}

void *fn_801D8C98(void) {
    return lbl_8033907C;
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

char *fn_801D8EF0(void) {
    return lbl_803389B8;
}

int fn_801D8EFC(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_801D8F04(void *arg0) {
    if (*(int *)((char *)arg0 + 4) == 1) {
        *(int *)((char *)arg0 + 4) = 2;
        *(float *)((char *)arg0 + 0x20) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

void fn_801D8FE0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}


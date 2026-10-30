// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef unsigned char u8;
typedef signed int s32;
extern s32 lbl_8055F1B4;
extern s32 lbl_8055F1B8;
extern u8 lbl_8055F1BC;
extern s32 lbl_8055F1C0;
extern u8 lbl_8055F1C4;
extern void *lbl_8055F1B0;
extern s32 fn_802E8D84(void);
extern u8 lbl_80341CC8[];
extern u8 lbl_8055F1AC;
extern s32 lbl_8055F1C8;
extern s32 fn_80214A9C(s32);
extern s32 fn_80214AF0(s32);
extern s32 fn_802E2C20(void);

void *fn_8023E5A8(void) {
    return lbl_80341CC8;
}

extern unsigned char lbl_80341CC8[];
extern unsigned char lbl_8055BCA8, lbl_8055BCB0, lbl_8055BCB8;
extern unsigned char lbl_8055F1AC;
extern int lbl_8055F1C8;
extern unsigned char lbl_8055BAC0, lbl_8055BCA0, lbl_8055BCC0, lbl_8055BCC8, lbl_8055BCD0, lbl_8055BCD8, lbl_8055BCE0, lbl_8055BCE8, lbl_8055BCF0, lbl_8055BCF8, lbl_8055BD00, lbl_8055BD08;
extern unsigned char lbl_804987E0[];
extern unsigned char lbl_802FA294[];
extern unsigned char lbl_80341CF0[];
extern unsigned char lbl_8055F1AC;
extern int fn_802E2C20(void);
extern void fn_802E30C8(const char *);
extern int fn_802146BC(void *, int, int, int);
extern void fn_8023EC94(void);
extern int fn_80236914;
void fn_8023E7A8(unsigned int mode) {
    char name[28] = {0};
    char a[128] = {0}, b[128] = {0}, c[128] = {0};
    switch (mode) {
    case 0: strcpy(name, (char *)lbl_80341CC8 + 0x34); break;
    case 1: strcpy(name, (char *)lbl_80341CC8 + 0x40); break;
    case 2: strcpy(name, (char *)lbl_80341CC8 + 0x4c); break;
    case 3: strcpy(name, (char *)&lbl_8055BCA8); break;
    case 4: strcpy(name, (char *)&lbl_8055BCB0); break;
    case 5: strcpy(name, (char *)lbl_80341CC8 + 0x58); break;
    case 6: strcpy(name, (char *)lbl_80341CC8 + 0x68); break;
    case 7: strcpy(name, (char *)lbl_80341CC8 + 0x74); break;
    case 8:
        strcpy(name, (char *)lbl_80341CC8 + 0x1e8);
        strcpy(a, (char *)lbl_80341CC8 + 0x1f8);
        strcpy(b, (char *)lbl_80341CC8 + 0x21c);
        strcpy(c, (char *)lbl_80341CC8 + 0x238);
        break;
    case 9:
        strcpy(name, (char *)lbl_80341CC8 + 0xc4);
        strcpy(a, (char *)lbl_80341CC8 + 0xd4);
        strcpy(b, (char *)lbl_80341CC8 + 0xf4);
        strcpy(c, (char *)&lbl_8055BCB8);
        break;
    case 10:
        strcpy(name, (char *)lbl_80341CC8 + 0x160);
        strcpy(a, (char *)lbl_80341CC8 + 0x174);
        strcpy(b, (char *)lbl_80341CC8 + 0x198);
        strcpy(c, (char *)&lbl_8055BCB8);
        break;
    }
    lbl_8055F1AC = 0;
    *((char *)&lbl_8055F1AC + 1) = 0;
    *((char *)&lbl_8055F1AC + 2) = 0;
    if (mode == 1) { *((char *)&lbl_8055F1AC + 1)=1; *((char *)&lbl_8055F1AC + 2)=1; }
    if (mode == 2) { *((char *)&lbl_8055F1AC + 1)=1; *((char *)&lbl_8055F1AC + 2)=1; }
    if (mode == 3) {
        lbl_8055F1AC=1;
        fn_802E2C20();
        lbl_8055F1C8=fn_802E2C20()+100;
        fn_802146BC(0, -999, -999, 1);
    }
}

void fn_8023EC94(void) {
    u8 *p;
    s32 i;

    p = &lbl_8055F1AC;
    i = 0;
    do {
        if (*p != 0) {
            fn_80214AF0(i + 1);
        } else {
            fn_80214A9C(i + 1);
        }
        i++;
    } while (i < 3 && (p++, 1));
}

s32 fn_8023ECF8(void) {
    return lbl_8055F1C8 < fn_802E2C20();
}

extern unsigned char lbl_8055B860;
extern int lbl_802FA2A8[5];
void fn_8023ED30(void) {
    int values[50];
    int args[5];

    values[0] = 6;
    values[1] = 6;
    values[2] = 0;
    values[3] = -2;
    values[4] = 13;
    values[5] = (int)&lbl_8055BCA0;
    values[6] = 3;
    values[7] = (int)(lbl_80341CC8 + 0x2A8);
    values[8] = 4;
    values[9] = 0;
    values[10] = (int)&lbl_8055BCD8;
    values[11] = 3;
    values[12] = (int)(lbl_80341CC8 + 0x2C0);
    values[13] = 4;
    values[14] = 0;
    values[15] = (int)&lbl_8055BCE0;
    values[16] = 3;
    values[17] = (int)(lbl_80341CC8 + 0x2DC);
    values[18] = 4;
    values[19] = 0;
    values[20] = (int)&lbl_8055BCE8;
    values[21] = 3;
    values[22] = (int)&lbl_8055BCB8;
    values[23] = 4;
    values[24] = 0;
    values[25] = (int)&lbl_8055BCF0;
    values[26] = 3;
    values[27] = (int)&lbl_8055BCB8;
    values[28] = 4;
    values[29] = 0;
    values[30] = (int)&lbl_8055BCF8;
    values[31] = 3;
    values[32] = (int)&lbl_8055BCB8;
    values[33] = 4;
    values[34] = 0;
    values[35] = (int)&lbl_8055BD08;
    values[36] = 3;
    values[37] = (int)(lbl_80341CC8 + 0x2F4);
    values[38] = 4;
    values[39] = 0;
    values[40] = (int)&lbl_8055BD00;
    values[41] = 3;
    values[42] = (int)&lbl_8055BCB8;
    values[43] = 4;
    values[44] = 0;

    values[45] = *(int *)(lbl_804987E0 + 0);
    values[46] = *(int *)(lbl_804987E0 + 4);
    values[47] = *(int *)(lbl_804987E0 + 8);
    values[48] = *(int *)(lbl_804987E0 + 12);
    values[49] = *(int *)(lbl_804987E0 + 16);
    lbl_8055F1C4 = 0;

    args[0] = lbl_802FA2A8[0];
    args[1] = lbl_802FA2A8[1];
    args[2] = lbl_802FA2A8[2];
    args[3] = lbl_802FA2A8[3];
    args[4] = lbl_802FA2A8[4];
    args[0] = (int)fn_8023E5A8();
    args[1] = (int)values;
    fn_802146BC(args, -999, -999, 1);
}

void fn_8023F870(void) {
}

void fn_8023F874(void) {}

#pragma cplusplus on
extern "C" int fn_8023F878(void) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual int v2();
        virtual void v3();
    };
    int now;
    if (lbl_8055F1C0 != 0) ((void (*)(void))lbl_8055F1C0)();
    now = fn_802E2C20();
    if (lbl_8055F1BC == 0) {
        if (now > lbl_8055F1B8) {
            if (((Obj *)lbl_8055F1B0)->v2() != 0)
                lbl_8055F1BC = 1;
            else
                ((Obj *)lbl_8055F1B0)->v3();
        }
    } else {
        if (now > lbl_8055F1B4) return 1;
    }
    return 0;
}
#pragma cplusplus off
int fn_8023F91C(int *arg0) {
    if (!fn_802E8D84())
        goto zero;
    *arg0 = -2;
    goto done;
zero:
    return 0;
done:
    return 1;
}

int fn_8023F964(int *arg0) {
    if (lbl_8055F1C0 != 0) ((void (*)(void))lbl_8055F1C0)();
    if (fn_802E8D84() == 0) {
        lbl_8055F1C4 = 1;
    } else {
        if (lbl_8055F1C4 != 0 && fn_802E8D84() != 0) {
            *arg0 = -2;
            return 1;
        }
    }
    return 0;
}

extern unsigned char lbl_80342238[];
extern unsigned char lbl_80342248[];
extern void fn_80215214(void *, void *, int);
#pragma scheduling invalid_target
void fn_8023F9E8(void) {
    void *first = lbl_80342238;
    void *second = lbl_80342248;
    fn_80215214(first, second, 0);
}
#pragma scheduling on
extern s32 lbl_8055F1B4;
extern s32 lbl_8055F1B8;
extern u8 lbl_8055F1BC;
extern s32 lbl_8055F1C0;
extern u8 lbl_8055F1C4;
extern void *lbl_8055F1B0;
extern s32 fn_802E8D84(void);

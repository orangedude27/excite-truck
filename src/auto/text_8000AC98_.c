extern char lbl_802FBC90[];
extern void *lbl_8055D3D0;
extern int lbl_80558A50, lbl_80558A58, lbl_80558A60, lbl_80558A68;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8000AC98(void) {
}

int fn_8000AC9C(void) { return 0; }

void fn_8000ACA4(void) {
    return;
}

void fn_8000ACA8(void) {
}

void fn_8000ACAC(void) {
    return;
}

void fn_8000ACB0(void) {
    if (fn_802044E8() == 0) {
        fn_80007238();
    }
}

int fn_802044E8(void);
int fn_80007238();
int fn_80204870(void);
int fn_800074EC(int);
int fn_8000ACDC(int arg0) {
    if (fn_80204870() != 0) {
        return 1;
    }
    return fn_800074EC(arg0);
}

void fn_8000AD20(void) {
}

int fn_8000AD24(void) { return 0; }

int fn_8000AD2C(void) {
 int index = ((char *)lbl_8055D3D0 - lbl_802FBC90) / 0x14;
 if (index == 0x12) goto no;
 if (index >= 0x12) goto yes;
 if (index >= 2) goto yes;
 if (index >= 0) goto no;
yes:
 return 1;
no:
 return 0;
}

int fn_8000AD84(void) {
 int index = ((char *)lbl_8055D3D0 - lbl_802FBC90) / 0x14;
 if (index == 0x12) goto yes;
 if (index >= 0x12) goto check24;
 if (index == 1) goto yes;
 goto no;
check24:
 if (index == 0x18) goto yes;
no:
 return 0;
yes:
 return 1;
}

extern int lbl_8034F5B8, lbl_8034F5D8;
extern int lbl_8055D3D8, lbl_8055D3DC, lbl_8055D3E8;
extern unsigned char lbl_8055D3D4, lbl_8055D3D5;
extern int lbl_8055D3E0;
extern int fn_802E4A10(void);
extern void *lbl_8055D3D0;
extern int lbl_8055D3DC;
extern int lbl_8055D3E4;
extern char lbl_802FBC90[];
void fn_8000ADE0(int arg0) {
    void (*callback)(void);
    if (arg0 != 1 && arg0 != 0x12 && arg0 != 0x18)
        lbl_8055D3DC = arg0;
    if (lbl_8055D3D0 != 0) {
        callback = *(void (**)(void))((char *)lbl_8055D3D0 + 0x10);
        if (callback != 0) callback();
    }
    lbl_8055D3D0 = lbl_802FBC90 + arg0 * 0x14;
    if (lbl_8055D3D0 != 0) {
        callback = *(void (**)(void))((char *)lbl_8055D3D0 + 0xC);
        if (callback != 0) callback();
    }
    lbl_8055D3E4 = fn_802E4A10();
}

int fn_80129374(int, int);
void fn_8000AE78(int arg0) {
    int i = 0;
    do {
        fn_80129374(i, arg0);
        i++;
    } while (i < 2);
}

int fn_800070DC(void);
void fn_8000AEC4(void) {
    fn_800070DC();
}

int fn_8000AEC8(int arg0) {
    int i;
    int *p = &lbl_8034F5D8;
    for (i = lbl_8055D3E0; i > 0; i--) {
        if (arg0 == *p) return 1;
        p++;
    }
    return 0;
}

void fn_8000AF04(void) {
    lbl_8055D3E0 = 1;
    lbl_8034F5D8 = 4;
}

void fn_8000B288(void* alarm) {
    fn_801DF110(fn_8000B210(alarm));
}

int fn_8000B33C(void **arg0, int arg1, int arg2) {
    register void **vtable = (void **)*arg0;
    if (((int (*)(void))((char *)vtable + 0xC))() != 0)
        return ((int (*)(void *, int))((char *)vtable + 0x2C))(arg0, arg1);
    return arg2;
}

void fn_8000B3B4(void) {
    void (*callback)(void);
    callback = *(void (**)(void))(lbl_802FBC90 + lbl_8055D3DC * 0x14);
    if (callback != 0)
        callback();
}

void fn_8000B3DC(unsigned char arg0) {
    extern unsigned char lbl_8055D3EC;
    extern void fn_8000B5A8(void);
    extern void fn_8000B3B4(void);
    extern void AXFXSetHooks_8020DE10(void (*)(void), int, unsigned char);
    lbl_8055D3EC = arg0;
    ((void (*)(int))fn_8000ADE0)(0x12);
    AXFXSetHooks_8020DE10(fn_8000B5A8,
        (int)fn_8000B3B4 & (-(int)lbl_8055D3EC | (int)lbl_8055D3EC) >> 31,
        lbl_8055D3EC);
}

extern int fn_8016212C(void), fn_80265D64(void), fn_80265D6C(void), fn_80265D50(void);
extern int fn_80265D54(int), fn_80176734(void), fn_801CB3F8(void), fn_8001EFB8(void);
extern int fn_802E30C8(void *);
extern void fn_8000B3DC(unsigned char);
extern void fn_8000ADE0(int);
extern unsigned char lbl_8055D3D4, lbl_8055D3D5;
extern int lbl_802FBF80;
int fn_8000B42C(int arg0) {
    int var_r31 = 1;
    if (fn_8016212C() == 0) {
        switch (arg0) {
        case 0: break;
        case 1:
            if (fn_80265D64() == 0) fn_80176734();
            else if (fn_80265D6C() != 0) fn_80265D54(2);
            else fn_802E30C8(&lbl_802FBF80);
            fn_801CB3F8();
            fn_8001EFB8();
            break;
        case 3:
            if (fn_80265D64() == 0) {
                lbl_8055D3D4 = 0;
                lbl_8055D3D5 = 1;
            } else if (fn_80265D6C() != 0) lbl_8055D3D4 = 0;
            else fn_80265D50();
            break;
        case 2:
            var_r31 = 0;
            fn_8000B3DC(1);
            break;
        }
    }
    if (var_r31 != 0) fn_8000ADE0(lbl_8055D3DC);
    return 1;
}

extern int fn_80007554(int, int);
extern int fn_8000BD9C(int, int, int);
extern int fn_801E7DF0(int);
extern int fn_801E7E04(int, int);
extern int fn_801E85A4(void);
extern int fn_801E868C(int, int *, int *);
extern int fn_801E86F8(int);
extern void *fn_801EA9A0(void);
void fn_8000B838(void) {
    extern int lbl_8034F5B8;
    int spC;
    int sp8;
    char *p = (char *)&lbl_8034F5B8;
    int i = 0;
    while (i < fn_801E85A4()) {
        spC = 0;
        sp8 = 0;
        if (fn_801E868C(i, &spC, &sp8)) {
            if (spC == 3) {
                fn_801E86F8(i);
                if (*(int *)((char *)fn_801EA9A0() + 0x30) != 3)
                    fn_801E7E04(i, fn_801E7DF0(i) ? 0 : 3);
            } else if (spC == 0) {
                fn_801E86F8(i);
                if (*(int *)((char *)fn_801EA9A0() + 0x30) != 3)
                    fn_8000BD9C(i, 0, (int)p);
            } else {
                fn_80007554(i, sp8);
            }
        }
        p += 8;
        i++;
    }
}

extern int fn_80019BA8(void);
extern int fn_801298E8(void *, int);
extern int fn_802E2C20(void);
extern int lbl_8055D3D8;
int fn_8000BB08(void) {
    unsigned char sp8[0x68];
    int temp_r31, var_r29, var_r30;
    if (fn_80019BA8() != 0) {
        temp_r31 = fn_802E2C20();
        var_r30 = 0;
        var_r29 = 0;
        do {
            if (fn_801298E8(sp8, var_r29) != 0) {
                if (sp8[0x20]) var_r30 = 1;
                if (sp8[0x21]) var_r30 = 1;
                if (sp8[0x22]) var_r30 = 1;
                if (sp8[0x23]) var_r30 = 1;
                if (sp8[0x24]) var_r30 = 1;
                if (sp8[0x25]) var_r30 = 1;
                if (sp8[0x26]) var_r30 = 1;
                if (sp8[0x27]) var_r30 = 1;
            }
            var_r29++;
        } while (var_r29 < 4);
        if (var_r30 == 0) {
            int old = lbl_8055D3D8;
            if (old != 0 && temp_r31 > old) {
                int elapsed = temp_r31 - old;
                if (elapsed > 0xEA60) return 1;
            }
            if (old == 0) lbl_8055D3D8 = temp_r31;
        }
    }
    return 0;
}

void fn_8000BC44(void) {
    extern int lbl_8034F5B8;
    extern int lbl_802FBFDC, lbl_802FBFF8;
    int i = 0;
    int *p = &lbl_8034F5B8;
    do {
        if (p[1] == 0x22) {
            fn_8026A1F0(p[0], i, 0);
        } else {
            fn_8026A1F0(i, 0, 0);
            p[1] = 0x22;
        }
        p += 2;
        i++;
    } while (i < fn_801E85AC());
    fn_800207B0();
    fn_801E7E48();
    fn_80176BAC();
    fn_8000AE78(fn_8000D75C() == 0);
    if (*(void (**)(void))((char *)lbl_8055D3D0 + 8))
        (*(void (**)(void))((char *)lbl_8055D3D0 + 8))();
    fn_8000B950();
    if (fn_801E89EC() == 3) {
        fn_802E30C8(&lbl_802FBFDC);
        lbl_8055D3D4 = 0;
    } else if (fn_8012742C() != 0) {
        lbl_8055D3D4 = 0;
    }
    if (fn_8000BB08() != 0) {
        fn_802E30C8(&lbl_802FBFF8);
        fn_8017691C();
    }
}

void fn_8000BD98(void) {
    return;
}

int fn_8000BD9C(int arg0, int arg1, int arg2) {
    int i;
    int found;
    int *p;
    int *out = (int *)arg2;

    switch (arg1) {
    case 0:
        p = &lbl_8034F5D8;
        found = 0;
        for (i = 0; i < lbl_8055D3E0; i++) {
            if (*out == *p) {
                *out = (&lbl_8034F5D8)[(i + 1) % lbl_8055D3E0];
                found = 1;
                break;
            }
            p++;
        }
        if (found == 0) *out = lbl_8034F5D8;
        return 1;
    case 0x170: *out = 0; return 1;
    case 0x171: *out = 1; return 1;
    case 0x172: *out = 2; return 1;
    case 0x173: *out = 4; return 1;
    case 0x373: *out = 7; return 1;
    case 0x174: *out = 5; return 1;
    case 0x175: *out = 6; return 1;
    case 0x176: *out = 10; return 1;
    case 0x376: *out = 16; return 1;
    default: return 0;
    }
}

void fn_8000BF10(int arg0, int arg1) { fn_8000BD9C(0, arg0, arg1); }

int fn_8000BD9C(int, int, int);
extern float lbl_805601FC, lbl_80560204;
extern char lbl_8034F5F8, lbl_8034F604;
int fn_80230B5C(int *);
int fn_802C8638(int *);
int fn_802C974C(float, float, float);
int fn_80010074(int, int, int *, float, float, float);
int fn_80011A2C(void);
int fn_802C9904(void);
extern int lbl_80558A48;
extern float lbl_805601F8, lbl_80560200, lbl_80560208, lbl_8056020C;
extern int lbl_8034F5B8;
void fn_8000C630(int arg0, int arg1) {
    int i;
    if (arg1 == -1) {
        for (i = 0; i < 4; i++) fn_8000C630(arg0, i);
    } else {
        *(int *)((char *)&lbl_8034F5B8 + arg1 * 8 + 4) = arg0;
    }
}

int *fn_8000C69C(void) {
    switch (lbl_8055D3DC) {
    case 0: return &lbl_80558A50;
    case 19: return &lbl_80558A58;
    case 20: return &lbl_80558A60;
    default: return &lbl_80558A68;
    }
}

void fn_8000C6E4(void) {
    switch ((int)lbl_8055D3DC) {
    case 0: lbl_8055D3DC = 0x14; return;
    case 20: lbl_8055D3DC = 0x13; return;
    default:
    case 19: lbl_8055D3DC = 0; return;
    }
}

void fn_8000C730(void) {
    switch ((int)lbl_8055D3DC) {
    case 19: lbl_8055D3DC = 0x13; return;
    case 0: lbl_8055D3DC = 0x14; return;
    default: lbl_8055D3DC = 0; return;
    }
}

int fn_8000BD9C(int, int, int);
extern float lbl_805601FC, lbl_80560204;
extern char lbl_8034F5F8, lbl_8034F604;
int fn_80230B5C(int *);
int fn_802C8638(int *);
int fn_802C974C(float, float, float);
int fn_80010074(int, int, int *, float, float, float);
int fn_80011A2C(void);
int fn_802C9904(void);
extern int lbl_80558A48;
extern float lbl_805601F8, lbl_80560200, lbl_80560208, lbl_8056020C;
extern int lbl_8034F5B8;


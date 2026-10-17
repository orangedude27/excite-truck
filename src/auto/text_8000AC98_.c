extern char lbl_802FBC90[];
extern void *lbl_8055D3D0;

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

extern int lbl_8034F5D8;
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

void fn_8000BD98(void) {
    return;
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


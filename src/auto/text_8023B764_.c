// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 fn_80128668(void);
extern void fn_8000BF20(void *);
extern void fn_8000C0E8(void);
extern u8 lbl_803413A8[];
extern s32 atoi(void);
extern void fn_802E317C(const char *);
extern const char lbl_80341354[];
extern s32 lbl_8055BB30;
extern void fn_802054EC(s32, s32, s32);
extern void fn_802ECC18(s32);
extern void fn_802445FC(s32, s32, s32);
extern void fn_8020A634(void);
extern void fn_8027B77C(void);
extern void fn_80211F4C(void);
extern void fn_8023C0EC(void *, s32, s32);
extern void fn_80018318(void *, s32);
extern void fn_800126B4(void *, void *, s32, s32);
extern void fn_80018440(s32 *, s32, void *);
extern void fn_8000AB48(void *, s32 *);
extern s32 fn_802C9A58(void);
extern void fn_802CED50(s32, s32, s32, s32);
extern const s32 lbl_80341308;
void fn_8023B764(s32 arg0, s32 arg1) {
    fn_802054EC((s32)&lbl_80341308, arg0, arg1);
}

void fn_8023B7EC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8[16];

    fn_802ECC18(0);
    fn_802445FC(arg1, arg2, arg3);
    fn_8023B77C();
    fn_8020A634();
    fn_8027B77C();
    fn_80211F4C();
    fn_8023C0EC(arg0, arg1, arg2);
    fn_80018318((u8 *)arg0 + 0x3F8, arg1);
    fn_800126B4(arg0, (u8 *)arg0 + 0x3F8, 0, 1);
    fn_80018440(sp8, *(s32 *)((u8 *)arg0 + 0x3E4), (u8 *)arg0 + 0x3F8);
    fn_8000AB48(arg0, sp8);
}

void fn_8023B8AC(s32 arg0) {
    fn_8000ABE0();
    fn_800126C0(arg0, arg0 + 0x3F8);
    fn_80244738();
    fn_8023B77C();
    fn_80211F44();
    if (fn_80019B3C() == 0) fn_8027B690();
    fn_8020A600();
}

void fn_8023B904(void *arg0, void *dest, s32 flag) {
    if (flag == 0) {
        u8 *p = lbl_803413A8;
        fn_8000BF20(&p);
        if (dest != 0) {
            *(s32 *)((u8 *)dest) = *(s32 *)(p + 0);
            *(s32 *)((u8 *)dest + 4) = *(s32 *)(p + 4);
            *(s32 *)((u8 *)dest + 8) = *(s32 *)(p + 8);
            *(u8 *)((u8 *)dest + 0xC) = p[0xC];
            *(u8 *)((u8 *)dest + 0xD) = p[0xD];
            *(u8 *)((u8 *)dest + 0xE) = p[0xE];
            __builtin_memcpy((u8 *)dest + 0x10, p + 0x10, 0xA0);
        }
    } else fn_8000C0E8();
}

s32 fn_8023B9AC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8023BB0C(void) {
    s32 sp10, spC, sp8;
    s32 temp_r31 = fn_802411CC();
    s32 var_r30;
    s32 temp_r29;
    fn_800167FC();
    for (var_r30 = 0; var_r30 < temp_r31; var_r30++) {
        temp_r29 = *(s32 *)((u8 *)fn_80016464(var_r30) + 4);
        fn_802411D0(var_r30, &sp10, &sp8, &spC);
        fn_80137C84(spC, var_r30);
        fn_80016A44(var_r30);
        fn_80016970(var_r30, temp_r29, sp10, sp8);
    }
}

int fn_8023BC24(int ignored, int arg1, int arg2) {
    int *obj = (int *)fn_8027DB40(1);
    int result = fn_8024DAE0(arg1, arg2, 0, (int)obj, 0, 0);
    if (obj != 0) ((void (*)(int *, int))(*(int **)obj)[2])(obj, 1);
    return result;
}

int fn_8023BCAC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern int fn_80128668(void);
extern int fn_8027DB40(int);
extern int fn_8024DAE0(int, int, int, int, int, int);
extern void fn_802411C8(void);
extern int fn_8023FF1C(int);
extern void fn_8023BB0C(void);
extern void fn_8023B9EC(int, int, int, int, int);
extern void fn_8001EFC8(void);
extern int fn_8024A4CC(int *, int *, int *);
extern int fn_80137C74(void);
extern void fn_80137C80(int);
extern void fn_80137C78(int);
void fn_8023BDEC(void) {
    int i = 0;
    goto check;
body:
    fn_80137C80(i);
    i++;
check:
    if (i < fn_80137C74()) goto body;
    fn_80137C78(1);
}

void fn_8023BE38(int ignored, int flag) {
    fn_80012794();
    fn_80012790(0x130);
    fn_802411C8();
    if (flag != 0) {
        fn_8023BBA8();
    } else {
        do {
            fn_8023BB0C();
            fn_8023B5E0();
        } while (fn_8023FF1C(flag) != 1);
    }
    fn_8023BDEC();
    fn_80012794();
    fn_80012778();
}

void fn_8023BEA8(void) {
    extern const s32 lbl_80341340;
    fn_8023BE38((int)&lbl_80341340, 1);
}

extern void fn_8001285C(void);
extern void *fn_80012820(s32);
extern s32 *fn_80012870(s32, s32);
extern void fn_8023B9EC(s32, s32, s32, s32, s32);
extern void fn_8023BE38(int, int);
extern const s32 lbl_80341340;
void fn_8023BEB8(s32 arg0, s32 arg1, s32 arg2) {
    fn_8023B9EC(arg0, arg1, arg2, 0, 0);
}

void fn_8023BF4C(void *arg0) {
    fn_8023B9EC(*(s32 *)((u8 *)arg0 + 0),
                *(s32 *)((u8 *)arg0 + 4),
                *(s32 *)((u8 *)arg0 + 0xC),
                *(s32 *)((u8 *)arg0 + 8), 0);
}

extern s32 atoi(void);
extern void fn_802E317C(const char *);
extern const char lbl_80341354[];
extern s32 lbl_8055BB30;
void fn_8023BF68(void) {
    s32 value = atoi();
    lbl_8055BB30 = value;
    if (value == 0 || (((value >> 31) ^ value) - (value >> 31)) > 4) {
        fn_802E317C(lbl_80341354);
    }
}

void fn_8023C20C(void) {}

void fn_8023C210(void *dst, void *src) {
    *(s32 *)((u8 *)dst + 4) = *(s32 *)((u8 *)src + 0);
    *(s32 *)((u8 *)dst + 8) = *(s32 *)((u8 *)src + 4);
    *(s32 *)((u8 *)dst + 0xC) = *(s32 *)((u8 *)src + 8);
    *(u8 *)((u8 *)dst + 0x10) = *((u8 *)src + 0xC);
    *(u8 *)((u8 *)dst + 0x11) = *((u8 *)src + 0xD);
    *(u8 *)((u8 *)dst + 0x12) = *((u8 *)src + 0xE);
    __builtin_memcpy((u8 *)dst + 0x14, (u8 *)src + 0x10, 0xA0);
}

void fn_8023C268(void) {}


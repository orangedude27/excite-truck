// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef unsigned char u8;
typedef signed int s32;
extern u8 lbl_80341CC8[];
extern u8 lbl_8055F1AC;
extern s32 lbl_8055F1C8;
extern s32 fn_80214A9C(s32);
extern s32 fn_80214AF0(s32);
extern s32 fn_802E2C20(void);

void *fn_8023E5A8(void) {
    return lbl_80341CC8;
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

void fn_8023F870(void) {
}

void fn_8023F874(void) {}

int fn_8023F91C(int *arg0) {
    if (fn_802E8D84() != 0) {
        *arg0 = -2;
        return 1;
    }
    return 0;
}
extern s32 lbl_8055F1B4;
extern s32 lbl_8055F1B8;
extern u8 lbl_8055F1BC;
extern s32 lbl_8055F1C0;
extern u8 lbl_8055F1C4;
extern void *lbl_8055F1B0;
extern s32 fn_802E8D84(void);

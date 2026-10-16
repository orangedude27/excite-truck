// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void fn_80214A9C(s32);
extern void fn_80214AF0(s32);
extern void fn_80230E90(s32);
extern void fn_80236914(void);
extern u8 lbl_8055F3E9;
extern u8 lbl_8055F3EA;
extern u8 lbl_8055F3EB;
extern u8 lbl_8055F420[];
extern u8 lbl_8055BAC0;
extern u8 lbl_8055BAB8;
void fn_80261A40(s32 arg0) {
    fn_80236914();
    lbl_8055F3E9 = (arg0 - 2) == 0;
}

void fn_80261A7C(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 4) = 8;
    *(void **)((u8 *)arg0) = &lbl_8055BAC0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_80261AA0(void) {
    s32 i = 0;
    do {
        fn_80214A9C(i + 10);
        i++;
    } while (i < *(s32 *)(lbl_8055F420 + 0xC));
}

void fn_80261AE8(s32 *arg0, s32 arg1) { *arg0 = arg1; }

void fn_80262158(void) {
}

void fn_8026215C(void) {
}

s32 fn_80262160(void) {
    return 0;
}

void fn_80262168(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x1E) && lbl_8055F3E9 && !lbl_8055F3EA) {
        fn_80230E90(0);
        *(u8 *)((u8 *)arg0 + 0x1E) = 0;
    }
    if (lbl_8055F3EB && !lbl_8055F3EA) {
        fn_80214AF0(0x1E);
        return;
    }
    fn_80214A9C(0x1E);
}


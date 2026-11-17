// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;
typedef s32 (*UnkFn_80245080)(void);

struct Unk_80245080_Sub {
    u8 pad[0xC];
    UnkFn_80245080 unk_0C;
};

struct Unk_80245080 {
    u8 pad[0x20];
    struct Unk_80245080_Sub* unk_20;
    s32 unk_24;
};

extern volatile struct Unk_80245080* lbl_8055F244;
extern s32 lbl_804988B0[];
#ifndef NULL
#define NULL ((void*)0)
#endif

s32 fn_802E8D7C(s32);
void fn_80236900(void);

#pragma optimization_level 1
s32 fn_80245080(void) {
    s32 fn = *(volatile s32 *)((u8 *)lbl_8055F244->unk_20 + 12);
    s32 ret = 0;
    if (fn != 0 && ((UnkFn_80245080)fn)() == 1) ret = 1;
    return ret;
}
#pragma optimization_level reset
s32 fn_802450D4(s32 status) {
    volatile struct Unk_80245080 *p;
    s32 counter;
    fn_80236900();
    p = lbl_8055F244;
    if ((counter = p->unk_24) > 7) return 1;
    p->unk_24 = counter + 1;
    return 0;
}
#pragma scheduling on
void fn_80245118(void) {
    /* Install the buffer at lbl_804988B0 as the active NAND-save interface object (fn_802E8D7C sets gNandSaveInterface). */
    fn_802E8D7C((s32)&lbl_804988B0);
}

void fn_80245124(void) {
    /* Uninstall the active NAND-save interface: fn_802E8D7C sets gNandSaveInterface, and NULL clears it. */
    fn_802E8D7C(0);
}

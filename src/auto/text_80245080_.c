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
s32 fn_80245080(s32 arg0) {
    void *sub;
    s32 (*fn)();
    s32 ret;
    ret = 0;
    sub = *(void **)((char *)lbl_8055F244 + 0x20);
    fn = *(s32 (**)())((char *)sub + 0xC);
    if (fn != 0 && ((s32 (*)(s32))fn)(arg0) == 1) ret = 1;
    return ret;
}
#pragma scheduling off
s32 fn_802450D4(s32 status) {
    struct Unk_80245080 *p;
    fn_80236900();
    if ((status = (p = (struct Unk_80245080 *)lbl_8055F244)->unk_24) > 7) {
        return 1;
    }
    p->unk_24 = status + 1;
    return 0;
}
void fn_80245118(void) {
    /* Install the buffer at lbl_804988B0 as the active NAND-save interface object (fn_802E8D7C sets gNandSaveInterface). */
    fn_802E8D7C((s32)&lbl_804988B0);
}

void fn_80245124(void) {
    /* Uninstall the active NAND-save interface: fn_802E8D7C sets gNandSaveInterface, and NULL clears it. */
    fn_802E8D7C(0);
}

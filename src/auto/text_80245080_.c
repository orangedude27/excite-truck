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
s32 fn_80245080(s32 object) {
    /* Ask the active save/dialog interface, via its vtable callback, about this object;
       return 1 only if the callback reports 1. */
    void *vtable;
    s32 (*callback)();
    s32 accepted;
    accepted = 0;
    vtable = *(void **)((char *)lbl_8055F244 + 0x20);
    callback = *(s32 (**)())((char *)vtable + 0xC);
    if (callback != 0 && ((s32 (*)(s32))callback)(object) == 1) accepted = 1;
    return accepted;
}
#pragma scheduling off
/* Refresh the save interface, then return 1 if its slot count is past 7 (full); otherwise increment the count and return 0. */
s32 fn_802450D4(s32 status) {
    s32 slotCount;
    s32 iface;
#pragma unused(status)
    fn_80236900();
    iface = (s32)lbl_8055F244;
    slotCount = ((struct Unk_80245080 *)iface)->unk_24;
    if (slotCount > 7) {
        return 1;
    }
    ((struct Unk_80245080 *)iface)->unk_24 = slotCount + 1;
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

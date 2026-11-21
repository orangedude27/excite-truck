// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;

/* Vtable of the active save interface: the callback at +0xC accepts an object for saving. */
typedef struct SaveInterfaceVTable {
    u8 pad[0xC];
    s32 (*acceptObject)(s32);
} SaveInterfaceVTable;

/* Active save/dialog interface: vtable at +0x20, occupied-slot count at +0x24. */
typedef struct SaveInterface {
    u8 pad[0x20];
    SaveInterfaceVTable* vtable;
    s32 slotCount;
} SaveInterface;

extern volatile SaveInterface* lbl_8055F244;
extern s32 lbl_804988B0[];
#define gActiveSaveInterface lbl_8055F244
#define gNandSaveInterfaceObj lbl_804988B0
#ifndef NULL
#define NULL ((void*)0)
#endif

s32 fn_802E8D7C(s32);
void fn_80236900(void);
#define setNandSaveInterface fn_802E8D7C
#define refreshSaveInterface fn_80236900

#pragma optimization_level 1
s32 fn_80245080(s32 object) {
    /* Ask the active save/dialog interface, via its vtable callback, about this object;
       return 1 only if the callback reports 1. */
    void *vtable;
    s32 (*callback)();
    s32 accepted;
    accepted = 0;
    vtable = *(void **)((char *)gActiveSaveInterface + 0x20);
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
    refreshSaveInterface();
    iface = (s32)gActiveSaveInterface;
    slotCount = ((SaveInterface *)iface)->slotCount;
    if (slotCount > 7) {
        return 1;
    }
    ((SaveInterface *)iface)->slotCount = slotCount + 1;
    return 0;
}
void fn_80245118(void) {
    /* Install the NAND-save interface object as the active save interface. */
    setNandSaveInterface((s32)&gNandSaveInterfaceObj);
}

void fn_80245124(void) {
    /* Uninstall the active save interface (NULL clears it). */
    setNandSaveInterface(0);
}

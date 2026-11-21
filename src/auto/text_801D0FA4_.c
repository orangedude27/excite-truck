// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
extern void fn_801D0DDC(void *);
extern void fn_801D0DFC(void *);
extern void fn_80128668(void *);
extern s32 lbl_8055E8FC;
extern u8 lbl_803381C0[16];
extern u8 lbl_803381E0[16];
extern void *lbl_80438858[256];

#pragma scheduling invalid_target
/* Construct an object: set initial/base vtables, register in base and secondary lists, and return it. */
void *fn_801D0FA4(void *object) {
    *(void **)object = lbl_803381C0;
    fn_801D0DDC(object);
    *(void **)object = lbl_803381E0;
    lbl_80438858[lbl_8055E8FC++] = object;
    return object;
}

/* Effect object scalar-deleting destructor: pop from the active list, reset the
   vtable, destroy the base, and conditionally free the object. */
void *fn_801D1008(void *object, s32 shouldDelete) {
    if (object != 0) {
        s32 count = lbl_8055E8FC - 1;
        lbl_8055E8FC = count;
        lbl_80438858[count] = 0;
        if (object != 0) {
            *(void **)object = lbl_803381C0;
            fn_801D0DFC(object);
        }
        if (shouldDelete > 0) fn_80128668(object);
    }
    return object;
}

#pragma cplusplus on
class Listener {
public:
    virtual void onInit(void *);
    virtual void onReset(void *);
    virtual void onUpdate(void *);
    virtual void onExit(void *);
    virtual void onSlot4(void *);
    virtual void onContextStart(void *);
    virtual void onContextEnd(void *);
};

/* Notify every registered listener in the table (in registration order) via
   virtual slot +0x1C that the race/level context is starting. */
extern "C" void fn_801D108C(void *context) {
#define gListenerCount lbl_8055E8FC
#define gListenerTable lbl_80438858
    s32 i;
    for (i = 0; i < gListenerCount; i++) {
        ((Listener *)gListenerTable[i])->onContextStart(context);
    }
#undef gListenerTable
#undef gListenerCount
}

/* Notify every registered listener in lbl_80438858 (in reverse registration
   order) via virtual slot +0x20 that the race/level context is being torn down. */
extern "C" void fn_801D1100(void *context) {
#define gListenerCount lbl_8055E8FC
#define gListenerTable lbl_80438858
    s32 i;
    for (i = gListenerCount - 1; i >= 0; i--) {
        ((Listener *)gListenerTable[i])->onContextEnd(context);
    }
#undef gListenerTable
#undef gListenerCount
}
#pragma cplusplus off

#pragma scheduling on

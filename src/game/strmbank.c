// strmbank — the global stream-bank manager and its null implementation.
// Symbol guide: initStrmBank (fn_802E7578), shutdownStrmBank (destroyStrmBankManager),
// loadStrmBank (fn_802E75E4), bank-unload helpers (unloadStrmBank, unloadStrmBankEx),
// setStrmBankLevel (fn_802E7684), null-manager creation (createNullStrmBank) and the
// null manager's vtable methods (fn_802E76F0..fn_802E7764).
// Recovered TU window 0x802E7578..0x802E7768 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E7768 (+ .ctors slot 0x802ED610) remains in
// auto/text_802E7768_.c pending a promotion pass.
#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *strmBankManager;                 /* global stream-bank manager */
extern s32 fn_802E30C8(const char *, ...); /* debug/log print */
extern char lbl_8034D808[];                /* "+StrmUnloadBank" */
extern char lbl_8034D818[];                /* "-StrmUnloadBank" */
extern s32 fn_80128668(void);              /* free */
extern s32 OSGetConsoleType(void);
extern s32 fn_801284F8(s32, void *);       /* allocate from a named heap */
extern s32 createNullStrmBank(void);              /* creates the null stream-bank manager */
extern char strCreatingNullManager[];                /* "StrmBank: creating 'null' manager" */
extern char strHeapNullStrmBank[];                /* "NullStrmBank" */
extern char vtblNullStrmBank[];                /* null manager vtable */

/* C++ virtual-delete lowering needs this pragma block to match CodeWarrior. */
#pragma cplusplus on
struct StrmBankObject { virtual ~StrmBankObject(); };
#pragma cplusplus reset

/* Install the freshly created "null" stream-bank manager as the global manager. */
void fn_802E7578(void) {
    strmBankManager = (void *)createNullStrmBank();
}

/* Interface of the global stream-bank manager; slots line up with vtblNullStrmBank. */
#pragma cplusplus on
struct StrmBankManager {
    virtual ~StrmBankManager();
    virtual void loadBank(s32 bankName);
    virtual void unloadBank(s32 bankId);
    virtual void unloadBankEx(s32 handle, s32 bankId, s32 flags);
    virtual void method18(s32, s32, s32);
    virtual void method1C(s32);
    virtual void setLevel(s32 level);
};
#pragma cplusplus on
/* Shut down the global stream-bank manager: run its virtual destructor (deleting flag set) and clear the global so a later init builds a fresh one. */
extern "C" void destroyStrmBankManager(void) {
    if (strmBankManager) {
        delete (StrmBankObject *)strmBankManager;
        strmBankManager = 0;
    }
}
/* Load a bank by its "<id>.bnk" filename; the bank handle comes back in r3. */
extern "C" void fn_802E75E4(s32 bankName) {
    ((StrmBankManager*)strmBankManager)->loadBank(bankName);
}

#pragma scheduling invalid_target
/* Log the +StrmUnloadBank/-StrmUnloadBank markers around the global stream-bank
   manager's virtual unloadBank call. */
extern "C" void unloadStrmBank(s32 bankId) {
    fn_802E30C8(lbl_8034D808);
    ((StrmBankManager *)strmBankManager)->unloadBank(bankId);
    fn_802E30C8(lbl_8034D818);
}

#pragma cplusplus reset
/* Forward an unload request with the bank handle, bank id and flags. */
extern "C" void unloadStrmBankEx(s32 bankHandle, s32 bankId, s32 flags) {
    s32 handle = bankHandle;
    s32 id = bankId;
    s32 flagBits = flags;
    ((StrmBankManager*)strmBankManager)->unloadBankEx(handle, id, flagBits);
}
#pragma cplusplus reset
#pragma cplusplus on
/* Set the stream-bank manager's mix level. */
extern "C" void fn_802E7684(s32 level) {
    ((StrmBankManager *)strmBankManager)->setLevel(level);
}
#pragma cplusplus reset
/* Build the "null" stream-bank manager the game falls back on: allocate a
   4-byte object and point it at vtblNullStrmBank, the do-nothing manager's
   vtable.  fn_802E7578 installs the returned pointer globally; the console
   type queried first is unused. */
s32 createNullStrmBank(void) {
    void **manager;
    OSGetConsoleType();
    fn_802E30C8(strCreatingNullManager);
    manager = (void **)fn_801284F8(4, strHeapNullStrmBank);
    if (manager != 0) {
        *manager = (void *)vtblNullStrmBank;
    }
}
#pragma scheduling on
/* Null stream-bank manager's CodeWarrior deleting destructor: when deleting (deleteFlag > 0), free the non-null object with operator delete (fn_80128668) and return the original pointer. */ s32 fn_802E76F0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Null manager's loadBank slot (+0x0C): no bank to load, so report success. */
s32 fn_802E7730(void) {
    return 1;
}

/* Null manager's unloadBank slot (+0x10): nothing to unload. */
void fn_802E7738(void) {
}

/* Null manager's unloadBankEx slot (+0x14): nothing to unload. */
void fn_802E773C(void) {
}

/* Null manager's method18 slot (+0x18): do nothing. */
void fn_802E7740(void) {
}

/* Null manager's method1C slot (+0x1C): do nothing. */
void fn_802E7744(void) {
}

/* Null manager's setLevel slot (+0x20): nothing to mix. */
void fn_802E7748(void) {
}

/* Null manager's query slot (+0x24): no bank, so report 0. */
s32 fn_802E774C(void) {
    return 0;
}

/* Null manager's query slot (+0x28): no value to report, so answer 0. */
s32 fn_802E7754(void) {
    return 0;
}

/* Null manager's slot (+0x2C): do nothing. */
void fn_802E775C(void) {
}

/* Null manager's slot (+0x30): do nothing. */
void fn_802E7760(void) {
}

/* Null manager's slot (+0x34): do nothing. */
void fn_802E7764(void) {
}


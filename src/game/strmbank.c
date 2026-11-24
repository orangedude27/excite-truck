// strmbank — the global stream-bank manager and its null implementation.
// Symbol guide: initStrmBank (fn_802E7578), shutdownStrmBank (fn_802E759C),
// loadStrmBank (fn_802E75E4), bank-unload helpers (unloadStrmBank, fn_802E765C),
// setStrmBankLevel (fn_802E7684), createNullStrmBank (fn_802E769C) and the
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
extern s32 fn_802E769C(void);              /* creates the null stream-bank manager */
extern char lbl_8034D828[];                /* "StrmBank: creating 'null' manager" */
extern char lbl_8034D84C[];                /* "NullStrmBank" */
extern char lbl_8034D860[];                /* null manager vtable */

/* C++ virtual-delete lowering needs this pragma block to match CodeWarrior. */
#pragma cplusplus on
struct StrmBankObject { virtual ~StrmBankObject(); };
#pragma cplusplus reset

/* Install the freshly created "null" stream-bank manager as the global manager. */
void fn_802E7578(void) {
    strmBankManager = (void *)fn_802E769C();
}

/* Interface of the global stream-bank manager; slots line up with lbl_8034D860. */
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
/* Destroy and clear the global stream-bank manager. */
extern "C" void fn_802E759C(void) {
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
/* Log before and after unloading a stream bank. */
/* Log the +StrmUnloadBank/-StrmUnloadBank markers around the global stream-bank manager's virtual unloadBank call. */ /* Log the +StrmUnloadBank/-StrmUnloadBank markers around the global stream-bank manager's virtual unloadBank call. */ extern "C" void unloadStrmBank(s32 bankId) {
    fn_802E30C8(lbl_8034D808);
    ((StrmBankManager *)strmBankManager)->unloadBank(bankId);
    fn_802E30C8(lbl_8034D818);
}

#pragma cplusplus reset
/* Forward an unload request with the bank handle, bank id and flags. */
extern "C" void fn_802E765C(s32 bankHandle, s32 bankId, s32 flags) {
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
/* Allocate the do-nothing "null" manager the game falls back on: a single pointer
   to lbl_8034D860, its vtable. fn_802E7578 installs the returned object globally;
   the console-type query first is unused. */
s32 fn_802E769C(void) {
    void **manager;
    OSGetConsoleType();
    fn_802E30C8(lbl_8034D828);
    manager = (void **)fn_801284F8(4, lbl_8034D84C);
    if (manager != 0) {
        *manager = (void *)lbl_8034D860;
    }
}
#pragma scheduling on
/* Deleting destructor: free the object when deleteFlag > 0, then return it. */
s32 fn_802E76F0(s32 object, s32 deleteFlag) {
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


// strmbank — the global stream-bank manager and its null implementation.
// Recovered TU window 0x802E7578..0x802E7768 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E7768 (+ .ctors slot 0x802ED610) remains in
// auto/text_802E7768_.c pending a promotion pass.
typedef signed long s32;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FFF0;                 /* global stream-bank manager */
extern s32 fn_802E30C8(const char *, ...); /* debug/log print */
extern char lbl_8034D808[];                /* "+StrmUnloadBank" */
extern char lbl_8034D818[];                /* "-StrmUnloadBank" */

/* C++ virtual-delete lowering needs this pragma block to match CodeWarrior. */
#pragma cplusplus on
struct StrmBankObject { virtual ~StrmBankObject(); };
#pragma cplusplus reset

s32 fn_802E769C(void);

/* Install the freshly created "null" stream-bank manager as the global manager. */
void fn_802E7578(void) {
    lbl_8055FFF0 = (void *)fn_802E769C();
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
    if (lbl_8055FFF0) {
        delete (StrmBankObject *)lbl_8055FFF0;
        lbl_8055FFF0 = 0;
    }
}
/* Load a bank by its "<id>.bnk" filename; the bank handle comes back in r3. */
extern "C" void fn_802E75E4(s32 bankName) {
    ((StrmBankManager*)lbl_8055FFF0)->loadBank(bankName);
}

#pragma scheduling invalid_target
/* Log before and after unloading a stream bank. */
extern "C" void fn_802E75FC(s32 bankId) {
    fn_802E30C8(lbl_8034D808);
    ((StrmBankManager *)lbl_8055FFF0)->unloadBank(bankId);
    fn_802E30C8(lbl_8034D818);
}

#pragma cplusplus reset
/* Forward an unload request with the bank handle, bank id and flags. */
extern "C" void fn_802E765C(s32 bankHandle, s32 bankId, s32 flags) {
    s32 handle = bankHandle;
    s32 id = bankId;
    s32 flagBits = flags;
    ((StrmBankManager*)lbl_8055FFF0)->unloadBankEx(handle, id, flagBits);
}
#pragma cplusplus reset
extern s32 fn_80128668(void);             /* free */
extern s32 OSGetConsoleType(void);
extern s32 fn_801284F8(s32, void *);      /* allocate from a named heap */
extern char lbl_8034D828[];               /* "StrmBank: creating 'null' manager" */
extern char lbl_8034D84C[];               /* "NullStrmBank" */
extern char lbl_8034D860[];               /* null manager vtable */
#pragma cplusplus on
/* Set the stream-bank manager's mix level. */
extern "C" void fn_802E7684(s32 level) {
    ((StrmBankManager *)lbl_8055FFF0)->setLevel(level);
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
s32 fn_802E76F0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Vtable method (slot +0x0C) of the "null" stream-bank manager. This do-nothing
 * fallback has no real bank to query, so its status query always reports success (true). */
s32 fn_802E7730(void) {
    return 1;
}

/* Empty stub: vtable slot +0x10 of the "null" stream-bank manager, a do-nothing
   fallback with no bank behind it (see fn_802E7730). */
void fn_802E7738(void) {
}

/* Empty vtable method (slot +0x14) of the "null" stream-bank manager
   (lbl_8034D860); the do-nothing fallback has no work to perform. */
void fn_802E773C(void) {
}

/* Empty stub: vtable slot +0x18 of the "null" stream-bank manager, a do-nothing
   fallback with no bank behind it (see fn_802E7730). */
void fn_802E7740(void) {
}

/* Empty stub: vtable slot +0x1C of the "null" stream-bank manager, a do-nothing
   fallback with no bank behind it (see fn_802E7730). */
void fn_802E7744(void) {
}

/* Empty vtable method (slot +0x20) of the "null" stream-bank manager
   (lbl_8034D860); the do-nothing fallback has no work to perform. */
void fn_802E7748(void) {
}

/* Null stream-bank vtable method (+0x24): a do-nothing query that reports 0 (false). */
s32 fn_802E774C(void) {
    return 0;
}

/* Vtable method (slot +0x28) of the "null" stream-bank manager. The do-nothing
 * fallback has no value to report, so this query answers 0 (none/failure). */
s32 fn_802E7754(void) {
    return 0;
}

/* Empty vtable method (slot +0x2C) of the "null" stream-bank manager
 * (lbl_8034D860); the do-nothing fallback has no work to perform. */
void fn_802E775C(void) {
}

void fn_802E7760(void) {
    /* Null stream-bank vtable method: a do-nothing slot with no state to change. */
}

/* Empty vtable method (slot +0x34) of the "null" stream-bank manager
   (lbl_8034D860); the do-nothing fallback has no work to perform. */
void fn_802E7764(void) {
}


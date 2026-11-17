// strmbank — stream bank unload ("+/-StrmUnloadBank").
// Recovered TU window 0x802E7578..0x802E7768 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E7768 (+ .ctors slot 0x802ED610) remains in
// auto/text_802E7768_.c pending a promotion pass.
typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FFF0;
extern s32 fn_802E30C8(const char*, ...);
extern char lbl_8034D808[];
extern char lbl_8034D818[];
#pragma cplusplus on
struct Dummy { virtual ~Dummy(); };
#pragma cplusplus reset

// fn_802E759C matches via C++ virtual-delete lowering in a C++ pragma block.
s32 fn_802E769C(void);
/* Install the freshly created "null" stream-bank manager as the global manager. */
void fn_802E7578(void) {
#define gStrmBankMgr lbl_8055FFF0
    gStrmBankMgr = (void*)fn_802E769C();
#undef gStrmBankMgr
}

#pragma cplusplus on
  struct Dummy_8055FFF0 {
      virtual ~Dummy_8055FFF0();
             virtual void f4(s32);
             virtual void f8(s32);
              virtual void f12(s32, s32, s32);
      virtual void f16(s32, s32, s32);
      virtual void f20(s32);
      virtual void f24(s32);
  };
#pragma cplusplus on
extern "C" void fn_802E759C(void) {
    /* Destroy and clear the global stream bank manager object (gStrmBankMgr). */
#define gStrmBankMgr lbl_8055FFF0
    if (gStrmBankMgr) {
        delete (Dummy*)gStrmBankMgr;
        gStrmBankMgr = 0;
    }
#undef gStrmBankMgr
}
extern "C" void fn_802E75E4(s32 bankName) {
    /* Loads a stream bank by its "<id>.bnk" filename through the global stream-bank
       manager's virtual load-bank method (vtable slot +0xC); the resulting bank
       handle is returned in r3. */
    ((Dummy_8055FFF0*)lbl_8055FFF0)->f4(bankName);
}

#pragma scheduling invalid_target
/* Logs before/after unloading a stream bank via the global stream bank object. */
extern "C" void fn_802E75FC(s32 bankId) {
    fn_802E30C8(lbl_8034D808);
    ((Dummy_8055FFF0 *)lbl_8055FFF0)->f8(bankId);
    fn_802E30C8(lbl_8034D818);
}

#pragma cplusplus reset
#define gStrmBankMgr lbl_8055FFF0
#define unloadBank f12
/* Forwards a stream-bank unload request to the global stream-bank manager's virtual
   unload-bank method, passing the loaded bank handle, the bank id and the flags. */
extern "C" void fn_802E765C(s32 bankHandle, s32 bankId, s32 flags) {
    s32 handle = bankHandle;
    s32 id = bankId;
    s32 flagBits = flags;
    ((Dummy_8055FFF0*)gStrmBankMgr)->unloadBank(handle, id, flagBits);
}
#pragma cplusplus reset
extern s32 fn_80128668(void);
extern s32 OSGetConsoleType(void);
extern s32 fn_802E30C8(const char*, ...);
extern s32 fn_801284F8(s32, void*);
extern char lbl_8034D828[];
extern char lbl_8034D84C[];
extern char lbl_8034D860[];
#pragma cplusplus on
extern "C" void fn_802E7684(s32 level) {
    /* Set the stream-bank manager's mix level via virtual slot +0x20. */
    ((Dummy_8055FFF0*)lbl_8055FFF0)->f24(level);
}
#pragma cplusplus reset
/* Builds the 'null' stream-bank manager the game falls back on: a bare object --
 * 4 bytes holding the vtable of the do-nothing StrmBank implementation at
 * lbl_8034D860 (+0x08 the deleting destructor fn_802E76F0, +0x0C fn_802E7730,
 * which answers 1, and +0x10..+0x2C the empty methods this file's wrappers call
 * through lbl_8055FFF0).  fn_802E7578 stores what this returns there; the console
 * type read first is left unused and the allocation's pointer is the value the
 * caller takes back in r3. */
s32 fn_802E769C(void) {
#define STR_CREATING_NULL lbl_8034D828 /* "StrmBank: creating 'null' manager" */
#define HEAP_NULL_STRMBANK lbl_8034D84C /* "NullStrmBank" */
#define VTBL_NULL_STRMBANK lbl_8034D860
    void **manager;
    OSGetConsoleType();
    fn_802E30C8(STR_CREATING_NULL);
    manager = (void **)fn_801284F8(4, HEAP_NULL_STRMBANK);
    if (manager != 0) {
        *manager = (void *)VTBL_NULL_STRMBANK;
    }
#undef STR_CREATING_NULL
#undef HEAP_NULL_STRMBANK
#undef VTBL_NULL_STRMBANK
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

void fn_802E7738(void) {
}

void fn_802E773C(void) {
}

void fn_802E7740(void) {
}

void fn_802E7744(void) {
}

void fn_802E7748(void) {
}

s32 fn_802E774C(void) {
    return 0;
}

s32 fn_802E7754(void) {
    return 0;
}

void fn_802E775C(void) {
}

void fn_802E7760(void) {
}

void fn_802E7764(void) {
}


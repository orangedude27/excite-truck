// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Manager list: the game's boot-time subsystem singletons register themselves
 * with fn_801D0DDC (their constructors store the base vtable lbl_803381C0
 * first) and drop out again in their destructors through fn_801D0DFC;
 * lbl_8055E8E8 is the count and lbl_80438818 holds up to 16 of them.
 * fn_801D0E0C..fn_801D0F38 call one virtual of every manager -- init (+0xC),
 * reset (+0x10), update (+0x14) and exit (+0x18) -- and fn_801D0CFC deletes
 * them all at shutdown.  The common base class keeps its virtual destructor
 * at vtable +0x8 and has no data of its own beyond the vtable pointer. */
extern int lbl_8055E8E8;
extern void *lbl_80438818[];
void __AXDSPInitCallback_801D0CF0(void) {
    lbl_8055E8E8 = 0;
}

#pragma cplusplus on
/* Free every manager registered in the boot manager list (fn_801D0DDC appends,
 * up to 16 fit in lbl_80438818): walk the list back to front and delete each
 * object through its virtual destructor, then reset the count.  Run at the end
 * of the game's global shutdown (fn_801791A8). */
extern "C" void fn_801D0CFC(void) {
    class Manager {
    public:
        virtual ~Manager();
    };
    int i;
    Manager *manager;

    for (i = lbl_8055E8E8 - 1; i >= 0; i--) {
        manager = (Manager *)lbl_80438818[i];
        delete manager;
    }
    lbl_8055E8E8 = 0;
}
#pragma cplusplus off
void *__dt__Q34nw4r2ef6EffectFv_801D0D7C(void *arg0, int arg1) {
    extern void fn_801D0DFC(void);
    extern void *lbl_803381C0[];
    extern void *fn_80128668(void *);
    if (arg0) {
        *(void **)arg0 = lbl_803381C0;
        fn_801D0DFC();
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_801D0DDC(void *arg0) {
    lbl_80438818[lbl_8055E8E8++] = arg0;
}

void fn_801D0DFC(void) {
    lbl_8055E8E8--;
}

#pragma cplusplus on
extern "C" void fn_801D0E0C(void) {
    class Dummy_801D0E0C {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
    };
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        Dummy_801D0E0C *obj = (Dummy_801D0E0C *)lbl_80438818[i];
        obj->m1();
    }
}
extern "C" void fn_801D0E70(void) {
    class CallbackObj {
    public:
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
    };
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        CallbackObj *obj = (CallbackObj *)lbl_80438818[i];
        obj->d4();
    }
}
#pragma cplusplus on
extern "C" void fn_801D0ED4(void) {
    class Dummy_801D0ED4 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
    };
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        Dummy_801D0ED4 *obj = (Dummy_801D0ED4 *)lbl_80438818[i];
        obj->m2();
    }
}
extern "C" void fn_801D0F38(void) {
    class Dummy_801D0F38 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
    };
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        Dummy_801D0F38 *obj = (Dummy_801D0F38 *)lbl_80438818[i];
        obj->m3();
    }
}
#pragma cplusplus off


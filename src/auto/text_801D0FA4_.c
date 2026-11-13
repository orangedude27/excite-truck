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
void *fn_801D0FA4(void *arg0) {
    *(void **)arg0 = lbl_803381C0;
    fn_801D0DDC(arg0);
    *(void **)arg0 = lbl_803381E0;
    lbl_80438858[lbl_8055E8FC++] = arg0;
    return arg0;
}

/* Effect object scalar-deleting destructor: pop from active list, reset vtable, destroy base, conditionally free. */
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
extern "C" void fn_801D108C(void *arg0) {
    class Object {
    public:
        virtual void m0(void *);
        virtual void m1(void *);
        virtual void m2(void *);
        virtual void m3(void *);
        virtual void m4(void *);
        virtual void m5(void *);
    };
    s32 i;
    for (i = 0; i < lbl_8055E8FC; i++) {
        ((Object *)lbl_80438858[i])->m5(arg0);
    }
}

#pragma cplusplus on
extern "C" void fn_801D1100(void *arg0) {
    class Object {
    public:
        virtual void m0(void *);
        virtual void m1(void *);
        virtual void m2(void *);
        virtual void m3(void *);
        virtual void m4(void *);
        virtual void m5(void *);
        virtual void m6(void *);
    };
    s32 i;
    for (i = lbl_8055E8FC - 1; i >= 0; i--) {
        ((Object *)lbl_80438858[i])->m6(arg0);
    }
}
#pragma cplusplus off

#pragma cplusplus off

#pragma scheduling on

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E8E8;
extern void *lbl_80438818[];

typedef struct CallbackVTable {
    void *unk[3];
    void (*callback12)(void *);
    void *unk10[2];
    void (*callback24)(void *);
} CallbackVTable;

typedef struct CallbackObject {
    CallbackVTable *vtable;
} CallbackObject;
void __AXDSPInitCallback_801D0CF0(void) {
    lbl_8055E8E8 = 0;
}

void fn_801D0CFC(void) {
    int i;
    for (i = lbl_8055E8E8 - 1; i >= 0; i--) {
        void *obj = lbl_80438818[i];
        if (obj != 0) {
            ((void (*)(void *, int))(*(void **)((char *)*(void **)obj + 8)))(obj, 1);
        }
    }
    lbl_8055E8E8 = 0;
}
#pragma scheduling on
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

void fn_801D0E0C(void) {
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        void *obj = lbl_80438818[i];
        void (*cb)(void *);
        cb = (void (*)(void *))(*(void ***)obj)[3];
        cb(obj);
    }
}
#pragma cplusplus on
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


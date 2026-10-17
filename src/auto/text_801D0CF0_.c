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
            ((void (*)(int))(*(void ***)obj)[2])(1);
        }
    }
    lbl_8055E8E8 = 0;
}

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
    int index = lbl_8055E8E8;
    lbl_80438818[index] = arg0;
    lbl_8055E8E8 = index + 1;
}

void fn_801D0DFC(void) {
    lbl_8055E8E8--;
}

void fn_801D0E0C(void) {
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        void *obj = lbl_80438818[i];
        ((void (*)(void *))(*(void ***)obj)[3])(obj);
    }
}

void fn_801D0E70(void) {
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        void *obj = lbl_80438818[i];
        ((void (*)(void *))(*(void ***)obj)[6])(obj);
    }
}

void fn_801D0ED4(void) {
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        void *obj = lbl_80438818[i];
        ((void (*)(void *))(*(void ***)obj)[4])(obj);
    }
}

void fn_801D0F38(void) {
    int i;
    for (i = 0; i < lbl_8055E8E8; i++) {
        void *obj = lbl_80438818[i];
        ((void (*)(void *))(*(void ***)obj)[5])(obj);
    }
}



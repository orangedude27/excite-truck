// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_8055B4D4;
extern char lbl_80489258[];

extern float lbl_80563230;
extern float lbl_80563234;
extern void fn_80208A50(float *);

extern void *lbl_8055EDA8;
extern int lbl_80489238[4];
extern char lbl_8033BEF8[];
extern char lbl_8033BF08[];
extern void fn_801331C4(int, void *, float *);
extern void fn_8013323C(int, void *, float);
extern void fn_80209030(float);
void fn_80208AC8(int arg0, int arg1) {
    volatile float initial = lbl_80563230;
    float value = initial;
    switch (arg1) {
    case 3:
        fn_801331C4(arg0 + 12, lbl_8033BF08, &value);
        fn_8013323C(4, lbl_8033BEF8, value);
        fn_80209030(value);
        break;
    case 1:
    case 2:
        fn_801331C4(4, lbl_8033BEF8, &value);
        fn_8013323C(arg0 + 12, lbl_8033BF08, value);
        break;
    case 0:
        fn_8013323C(4, lbl_8033BEF8, value);
        fn_80209030(value);
        break;
    }
}

int fn_80208CFC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_80208D3C(void) { return lbl_80489238[6]; }

int fn_80208D4C(int index) { return lbl_80489238[index]; }

void fn_80208D60(int arg0) { lbl_80489238[7] = arg0; }

int fn_80208D70(void) { return lbl_80489238[7]; }

float fn_80209028(void) {
    return lbl_8055B4D4;
}

void fn_80209090(int arg0) {
    if (arg0 >= 0 && arg0 <= 2) {
        lbl_8055EDA8 = (void *)arg0;
        return;
    }
    lbl_8055EDA8 = 0;
}

void* fn_802090B4(void) {
    return lbl_8055EDA8;
}

extern void *lbl_8055B4D8;
void* fn_802090CC(void) {
    return lbl_8055B4D8;
}

void fn_80209190(float *arg0, float arg1) {
    if (arg0 != 0) {
        float value = lbl_80563230 < arg1 ? lbl_80563230 : arg1;
        value = value > lbl_80563234 ? value : lbl_80563234;
        *arg0 = value;
        fn_80208A50(arg0);
    }
}

extern float lbl_80563230;
extern float lbl_80563234;
extern void fn_80208A18(float);
extern void fn_80208A50(float *);
extern int fn_80128668(void);
void fn_802091CC(void) {
    fn_80208A18(lbl_80563230);
}

int fn_802091D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_80209214(void) {
    return 0;
}

int fn_80209260(int arg0) { return arg0 + 4; }

int fn_80209268(void) { return 1; }

int fn_80209270(void) { return 1; }

void fn_80209278(void) {

}

void fn_8020927C(void) {

}

extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
void fn_80209280(void) {
    struct Obj { void *vtable; int pad; int value; };
    struct Obj *obj = (struct Obj *)fn_801284F8(12, lbl_8033C1C0);
    if (obj) {
        obj->vtable = lbl_8033C0E8;
        obj->value = 3;
    }
}

int fn_802092C8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_80209308(void) { return 1; }

extern int fn_802E2C20(void);
void fn_80209310(void *arg0) {
    *(int *)((char *)arg0 + 4) = fn_802E2C20();
    *(int *)((char *)arg0 + 8) = 1;
}

void fn_80209348(void *arg0) {
    *(int *)((char *)arg0 + 4) = fn_802E2C20();
    *(int *)((char *)arg0 + 8) = 1;
}

void fn_80209380(void *arg0) {
    *(int *)((char *)arg0 + 8) = 3;
}

void fn_8020938C(void *arg0) {
    *(int *)((char *)arg0 + 8) = 2;
}

void fn_80209398(void *arg0) {
    *(int *)((char *)arg0 + 8) = 1;
}

int fn_802093A4(void *arg0) {
    if (*(int *)((char *)arg0 + 4) + 0x7D0 < fn_802E2C20()) {
        *(int *)((char *)arg0 + 8) = 3;
    }
    return *(int *)((char *)arg0 + 8);
}

void fn_802093EC(void) {

}

void fn_802093F0(void) {

}

void fn_802093F4(void) {

}

void fn_802093F8(void) {

}

int fn_802093FC(void) {
    return 0;
}

void fn_80209404(void) {

}

void fn_80209408(void) {

}

void fn_8020940C(void) {

}
extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];

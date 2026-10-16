// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F444;
extern void *lbl_8055C458;
extern void fn_80236914(void);
extern void fn_80264098(void *, int);
extern void *fn_80264A54(void);
void fn_80264098(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 4) = arg1;
}

#pragma dont_inline on
#pragma dont_inline off
void fn_802640A0(void *arg0) {
    *(int *)((char *)arg0 + 8) = 0;
    *(void **)arg0 = lbl_8055C458;
    *(int *)((char *)arg0 + 4) = 0x7b;
    *(int *)((char *)arg0 + 0xc) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
}
#pragma dont_inline on
#pragma dont_inline off
void fn_802643B8(void *arg0) {
    *(void **)arg0 = lbl_8055C458;
    fn_80264098(arg0, 8);
    *(void (**)(void))((char *)arg0 + 8) = fn_80236914;
    *(int *)((char *)arg0 + 0xc) = 2;
}
#pragma dont_inline on
#pragma dont_inline off
void fn_80264404(void *arg0) {
    *(void **)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = fn_80264A54();
}

void fn_80264484(void *arg0) {
    extern void *fn_801284F8(unsigned int, void *);
    extern char lbl_803464A8[];
    extern char lbl_803464F8[];
    extern struct {
        void **items;
        int count;
    } lbl_80498F78;
    void *result = fn_801284F8(0x18, lbl_803464A8);
    if (result != 0) {
        *(int *)((char *)result + 0x14) = 0;
        *(void **)result = lbl_803464F8;
    }
    lbl_80498F78.items[lbl_80498F78.count++] = result;
    *(int *)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = result;
}

void fn_8026451C(void *arg0) {
    extern char lbl_803466D8[];
    *(void **)arg0 = lbl_803466D8;
    *(int *)((char *)arg0 + 0x14) = 0;
    lbl_8055F444 = arg0;
}

int fn_80264538(int arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055F444 = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void* fn_80264580(void) {
    return lbl_8055F444;
}

float fn_80264588(void) {
    extern int fn_802645C0(void);
    extern float lbl_80563BF4;
    if (fn_802645C0() != 0) {
        return *(float *)((char *)lbl_8055F444 + 0x20);
    }
    return lbl_80563BF4;
}

extern void *lbl_8055F448;
void* fn_80264A54(void) {
    return lbl_8055F448;
}

extern char lbl_80346558[];
extern float lbl_80563BF0;
extern float lbl_8055C454;
void fn_80265598(void *arg0) {
    lbl_8055C454 = *(float *)((char *)arg0 + 0x1C);
}

int fn_802655C8(int arg0, int arg1) {
    extern void *lbl_8055F44C;
    if (arg0 != 0) {
        lbl_8055F44C = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

typedef float f32;
void fn_80265610(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

extern char lbl_8055C4A8[4];
extern void fn_80236954(void *queue);
void fn_802658FC(void) {
    fn_80236954(lbl_8055C4A8);
}

extern void fn_80236954(void *);
extern int fn_8023695C(void *);
extern void fn_80216CA8(void);
extern void fn_802168BC(int);
#pragma push
#pragma small_data off
extern char lbl_803464EC[4];
#pragma pop
extern void *lbl_8055F44C;
extern unsigned char lbl_8055F450;
int fn_80128668(void);
#pragma push
#pragma small_data off
void fn_80265A28(void) {
    fn_80236954(lbl_803464EC);
}
void fn_80265A34(void) {
    fn_80236914();
    if (fn_8023695C(lbl_803464EC) == 2) {
        fn_80216CA8();
        fn_802168BC(0);
    }
}

int fn_80265B5C(void) {
    register void *p = lbl_8055F44C;
    register int result = 1;
    register int found = 0;

    if (p != 0 && *((unsigned char *)p + 0x20) != 0) {
        found = 1;
    }
    if (found != 0) {
        return result;
    }
    if (lbl_8055F450 != 0) {
        return result;
    }
    return 0;
}

int fn_80265B9C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_80265BDC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_80265C1C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}


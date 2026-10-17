// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_802066C8(void*, unsigned int);
void fn_80206C70(void*);
float fn_8017D378(void) {
    extern float lbl_8055E3C8;
    return lbl_8055E3C8;
}

void fn_8017D380(float *arg0, int arg1) {
    extern void *fn_80178C9C(void);
    extern float lbl_80561BE0;
    extern float lbl_80561BE4;
    extern double lbl_80561BE8;
    void *root = fn_80178C9C();
    void *sub = *(void **)((char *)root + 0x2C);
    int index = arg1;
    float *values;
    arg0[1] = lbl_80561BE0;
    arg0[1] = lbl_80561BE4 + (float)(index * 2);
    values = *(float **)((char *)sub + 0x1C);
    arg0[0] = values[0];
    arg0[2] = values[1];
}

void *fn_8017D688(void) {
    extern void *fn_801284F8(int, void *);
    extern void fn_8017B0B0(void);
    extern int lbl_8055A310;
    extern char lbl_80331D18;
    void *p = fn_801284F8(0x230, &lbl_8055A310);
    if (p != 0) {
        fn_8017B0B0();
        *(void **)p = &lbl_80331D18;
        *(void **)((char *)p + 0x1EC) = (char *)&lbl_80331D18 + 0x54;
    }
    return p;
}

long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017DA34(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_802066C8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80206C70((void*)arg0);
        }
    }
    return arg0;
}

extern float lbl_8055E3C8;
extern void *fn_80178C9C(void);
extern float lbl_80561BE0;
extern float lbl_80561BE4;
extern double lbl_80561BE8;
extern void *fn_801284F8(int, void *);
extern void fn_8017B0B0(void);
extern int lbl_8055A310;
extern char lbl_80331D18;
extern void fn_8017B164(void);
extern void fn_8017A580(void *);
extern void fn_8017D380(float *, int);
extern float fn_8017D378(void);
extern int lbl_8055D430;
extern float lbl_80561C0C;
long fn_8017EAF4(long);
long fn_8017EAFC(long);
long fn_8017EB04(long);
void fn_8017DEE0(void *, long, long, short, float);
void fn_8017DA8C(void *arg0) {
    float sp[3];
    int flags;
    fn_8017B164();
    fn_8017D380(sp, *(int *)((char *)arg0 + 0x1F8));
    *(float *)((char *)arg0 + 0x60) = sp[0];
    *(float *)((char *)arg0 + 0x64) = sp[1];
    *(float *)((char *)arg0 + 0x68) = sp[2];
    fn_8017A580(arg0);
    *((char *)arg0 + 0x1E9) = 0;
    flags = 0;
    if ((lbl_8055D430 & 1) && (lbl_8055D430 & 8)) flags = 1;
    if (flags != 0) {
        *(int *)((char *)arg0 + 0x1F0) = 0;
        *(float *)((char *)arg0 + 0x1F4) = lbl_80561C0C + fn_8017D378();
    }
    *((char *)arg0 + 0x1FC) = 0;
    *((char *)arg0 + 0x1FE) = 0;
}

float fn_8017E380(void) { extern float lbl_80561C2C; return lbl_80561C2C; }

void fn_8017E388(void *arg0) {
 extern float lbl_80561BE0; extern float lbl_80561BF4;
 float a=lbl_80561BE0, b=lbl_80561BF4; float *p=(float*)arg0;
 p[1]=a; p[0]=b; p[2]=a; p[3]=a; p[4]=b; p[5]=a; p[6]=a; p[7]=a; p[8]=b; p[9]=a; p[10]=a; p[11]=a;
}

int fn_8017E930(void *arg0, void *arg1, void *arg2) {
    if (*((unsigned char *)arg0 + 0x1FE) != 0) {
        *((float *)arg1) = *((float *)((char *)arg0 + 0x60));
        *((float *)arg1 + 1) = *((float *)((char *)arg0 + 0x68));
        *((float *)arg2) = *((float *)((char *)arg0 + 0x118));
        *((float *)arg2 + 1) = *((float *)((char *)arg0 + 0x120));
        return 1;
    }
    return 0;
}

extern int lbl_80331DC0;
extern int lbl_8055A318;
extern int lbl_8055A320;
extern int lbl_8055A328;
void fn_8017E96C(void *arg0, int **arg1, signed char *arg2) {
    int state = *(int *)((char *)arg0 + 0x1F0);
    if (state == 2) {
        *arg1 = &lbl_8055A320;
        *arg2 = 1;
    } else if (state >= 2) {
        if (state < 4) {
            *arg1 = &lbl_80331DC0;
            *arg2 = 0;
        } else {
            *arg1 = &lbl_8055A318;
            *arg2 = 0;
        }
    } else if (state == 0) {
        *arg1 = &lbl_8055A328;
        *arg2 = 0;
    } else if (state < 0) {
        *arg1 = &lbl_8055A318;
        *arg2 = 0;
    } else {
        *arg1 = 0;
        *arg2 = 0;
    }
}

long fn_8017EAF4(long arg0) { return arg0 + 0x6C; }

long fn_8017EAFC(long arg0) { return arg0 + 0x118; }

long fn_8017EB04(long arg0) { return arg0 + 0x70; }


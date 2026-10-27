#pragma cplusplus on
struct VObj_8017D93C { virtual void d0(int); };
#pragma cplusplus reset

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma small_data off
extern char lbl_80331D18[];
#pragma small_data on
void fn_802066C8(void*, unsigned int);
void fn_80206C70(void*);
float fn_8017D378(void) {
    extern float lbl_8055E3C8;
    return lbl_8055E3C8;
}

#pragma scheduling invalid_target
void fn_8017D380(float *arg0, int arg1) {
    extern void *fn_80178C9C(void);
    extern float lbl_80561BE0;
    extern float lbl_80561BE4;
    extern double lbl_80561BE8;
    void *root = fn_80178C9C();
    void *sub = *(void **)((char *)root + 0x2C);
    int scaled = arg1 * 2;
    volatile float *values = *(volatile float **)((char *)sub + 0x1C);

    arg0[0] = values[0];
    arg0[1] = lbl_80561BE0;
    arg0[1] = lbl_80561BE4 + (float)scaled;
    arg0[2] = values[1];
}
#pragma scheduling on
void *fn_8017D688(void) {
    extern void *fn_801284F8(int, void *);
    extern void fn_8017B0B0(void);
    extern int lbl_8055A310;
    void *p = fn_801284F8(0x230, &lbl_8055A310);
    if (p != 0) {
        fn_8017B0B0();
        *(void **)p = lbl_80331D18;
        *(void **)((char *)p + 0x1EC) = lbl_80331D18 + 0x54;
    }
    return p;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_8017D93C(void *arg0, int arg1) {
    extern char lbl_80331D18[];
    extern void fn_801D0C84(void *);
    extern void fn_80179EE8(void *, int);
    extern void fn_80128668(void *);
    void *p;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80331D18;
        *(void **)((char *)arg0 + 0x1EC) = lbl_80331D18 + 0x54;
        if (arg0 != 0) fn_801D0C84((char *)arg0 + 0x1EC);
        p = *(void **)((char *)arg0 + 0x220);
        if (p != 0) {
            if (p != 0) ((VObj_8017D93C *)p)->d0(1);
        }
        p = *(void **)((char *)arg0 + 0x21C);
        if (p != 0) {
            if (p != 0) ((VObj_8017D93C *)p)->d0(1);
        }
        p = *(void **)((char *)arg0 + 0x218);
        if (p != 0) {
            if (p != 0) ((VObj_8017D93C *)p)->d0(1);
        }
        if (arg0 != 0) fn_80179EE8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
#pragma cplusplus reset
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
extern char lbl_80331D18[];
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

extern void fn_8017D404(float *, int, float, float, int);
void fn_8017DB34(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    extern int lbl_8055D430;
    extern float lbl_80561BF4, lbl_80561C10, lbl_80561C14;
    extern void fn_801796EC(int, void *, int);
    extern void fn_8017D2C8(void *, int, int, int, int);
    float sp[6];
    float z, x, y;
    int var_r4;
    int flags;
    void *p;
    void *q;
    volatile float *values;
    unsigned char *object = (unsigned char *)arg0;

    if (object[0x1FE] == 0)
        goto done;
    if (object[0x1FD] == 0)
        goto done;
    if (arg3 < 100) {
        flags = lbl_8055D430;
        var_r4 = 0;
        if (flags & 1) {
            if (flags & 0x90)
                var_r4 = 1;
        }
        if (var_r4 == 0)
            goto done;
    }
    if (arg3 >= 1000)
        goto done;

    sp[0] = *(float *)(object + 0x60);
    sp[1] = *(float *)(object + 0x64);
    sp[2] = *(float *)(object + 0x68);
    sp[3] = *(float *)(object + 0x118);
    sp[4] = *(float *)(object + 0x11C);
    sp[5] = *(float *)(object + 0x120);
    fn_801796EC(8, sp, 0x18);
    fn_8017D404((float *)(object + 0x60), arg4,
                lbl_80561C10, lbl_80561C14, *(int *)(object + 0x1F8));

    p = *(void **)(object + 0x21C);
    if (p != 0) {
        *((unsigned char *)p + 0x4A) = 1;
        *((unsigned char *)p + 0x4C) = 0;
    }
    p = *(void **)(object + 0x220);
    if (p != 0) {
        values = (volatile float *)(object + 0x60);
        x = values[0];
        y = values[1];
        z = values[2];
        *(volatile float *)(object + 0x20C) = x;
        x = lbl_80561BF4;
        *(volatile float *)(object + 0x210) = y;
        *(volatile float *)(object + 0x214) = z;
        if (x != *(float *)((char *)p + 8)) {
            *((unsigned char *)p + 0x4D) = 1;
            *(float *)((char *)p + 8) = x;
        }
        q = *(void * volatile *)(object + 0x220);
        *((unsigned char *)q + 0x49) = 1;
        *((unsigned char *)q + 0x4B) = 0;
        *((unsigned char *)q + 0x4A) = 0;
    }
    object[0x1FE] = 0;
    object[0x1FC] = 1;
done:
    fn_8017D2C8(arg0, arg1, arg2, arg3, arg4);
}

void fn_8017DCB4(void *arg0) {
 unsigned char *p=(unsigned char*)arg0; float v[3],a[4],b[4],c[4],d[4]; int mode;
 extern void fn_8017B164(void); extern void fn_8017D380(float*,int); extern void fn_8017A580(void*);
 extern float fn_8017D378(void); extern void *fn_8017960C(int); extern void *fn_801B2EC0(int);
 extern void fn_801602B0(void*); extern void fn_8017E3C4(void*,void*,short*);
 extern void fn_80144DC8(void*); extern void fn_8017E388(void*); extern void fn_80160230(void*,void*);
 extern float fn_8017E380(void); extern void *fn_801602B4(void);
 extern void GXInitLightAttnA_80144B44(float*,float,float,float);
 extern void fn_8017DEE0(void*,long,long,short,float); extern int fn_801E9E30(void*,float*);
 extern void fn_8017B81C(void*);
 if(p[0x1FC]) { fn_8017B164(); fn_8017D380(v,*(int*)(p+0x1F8)); *(float*)(p+0x60)=v[0]; *(float*)(p+0x64)=v[1]; *(float*)(p+0x68)=v[2]; fn_8017A580(arg0); p[0x1E9]=0; p[0x1FC]=0; }
 if(*(int*)(p+0x1F0)==0 && *(float*)(p+0x1F4)<fn_8017D378()) { mode=1; if(*(unsigned int*)((char*)fn_8017960C(*(int*)(p+0x1F8))+0x10)==0x41524352) mode=2; *(int*)(p+0x1F0)=mode; }
 if(!((lbl_8055D430&1)&&(lbl_8055D430&0x88))) { fn_8017D380(v,*(int*)(p+0x1F8)); *(float*)(p+0x60)=v[0]; *(float*)(p+0x64)=v[1]; *(float*)(p+0x68)=v[2]; fn_8017A580(arg0); *(float*)(p+0x118)=lbl_80561BE0; *(float*)(p+0x11C)=lbl_80561BE0; *(float*)(p+0x120)=lbl_80561BE0; }
 if(!p[0x1FE]&&(lbl_8055D430&1)&&(lbl_8055D430&0x80)) { void*obj=fn_801B2EC0(*(int*)(p+0x1F8)); void**vt=*(void***)obj; ((void(*)(void*))vt[4])(obj); if(*(int*)((char*)obj+0x24)==0) { short angle; fn_801602B0(a); fn_8017E3C4(arg0,a,&angle); fn_80144DC8(b); fn_8017E388(b); fn_80160230(c,a); fn_8017E380(); fn_8017960C(*(int*)(p+0x1F8)); GXInitLightAttnA_80144B44(d,lbl_80561BE0,lbl_80561BE0,lbl_80561BE0); fn_8017DEE0(arg0,(long)b,(long)d,angle,lbl_80561BE0); } }
 v[0]=*(float*)(p+0x60);v[1]=*(float*)(p+0x64);v[2]=*(float*)(p+0x68); if(fn_801E9E30(p+0x6C,v)==0)p[0x1FC]=1; fn_8017B81C(arg0);
}

#pragma push
#pragma scheduling on
#pragma dont_inline on
void fn_8017DEE0(register void *arg0, register long arg1, register long arg2, short arg3, float farg0) {
    extern int lbl_8055D430;
    extern float lbl_80561BE0, lbl_80561BF4, lbl_80561C0C;
    extern float lbl_80561C18, lbl_80561C1C, lbl_80561C20;
    extern float lbl_80561C24, lbl_80561C28;
    volatile float point[6];
    volatile unsigned int m[12];
    volatile float *mf;
    register unsigned int *matrix = (unsigned int *)arg1;
    register float *vector = (float *)arg2;
    float x, y, z, scale, t0, t1, t2;
    volatile unsigned int compare_a, compare_b;
    int flags;
    int var_r3;
    int var_r3_2;
    int var_r3_3;
    void *sub;

    fn_8017D378();
    *(float *)((char *)arg0 + 0x124) = lbl_80561BE0;
    *(float *)((char *)arg0 + 0x128) = lbl_80561BE0;
    *(float *)((char *)arg0 + 0x12C) = lbl_80561BE0;
    *(short *)((char *)arg0 + 0x6C) = arg3;
    *((unsigned char *)arg0 + 0x1E9) = 1;
    m[0] = matrix[0];
    m[1] = matrix[1];
    m[2] = matrix[2];
    m[3] = matrix[3];
    m[4] = matrix[4];
    m[5] = matrix[5];
    m[6] = matrix[6];
    m[7] = matrix[7];
    m[8] = matrix[8];
    m[9] = matrix[9];
    m[10] = matrix[10];
    m[11] = matrix[11];
    mf = (volatile float *)m;
    if (&point[3] == (float *)((char *)arg0 + 0x224)) {
        x = *(float *)((char *)arg0 + 0x224) * mf[0]
          + *(float *)((char *)arg0 + 0x228) * mf[3]
          + *(float *)((char *)arg0 + 0x22C) * mf[6];
        y = *(float *)((char *)arg0 + 0x224) * mf[1]
          + *(float *)((char *)arg0 + 0x228) * mf[4]
          + *(float *)((char *)arg0 + 0x22C) * mf[7];
        z = *(float *)((char *)arg0 + 0x224) * mf[2]
          + *(float *)((char *)arg0 + 0x228) * mf[5]
          + *(float *)((char *)arg0 + 0x22C) * mf[8];
    } else {
        x = *(float *)((char *)arg0 + 0x22C) * mf[6]
          + (*(float *)((char *)arg0 + 0x224) * mf[0]
          + *(float *)((char *)arg0 + 0x228) * mf[3]);
        y = *(float *)((char *)arg0 + 0x22C) * mf[7]
          + (*(float *)((char *)arg0 + 0x224) * mf[1]
          + *(float *)((char *)arg0 + 0x228) * mf[4]);
        z = *(float *)((char *)arg0 + 0x22C) * mf[8]
          + (*(float *)((char *)arg0 + 0x224) * mf[2]
          + *(float *)((char *)arg0 + 0x228) * mf[5]);
    }
    point[3] = x + mf[9];
    point[4] = y + mf[10];
    point[5] = z + mf[11];
    *(float *)((char *)arg0 + 0x3C) = mf[0];
    *(float *)((char *)arg0 + 0x40) = mf[1];
    *(float *)((char *)arg0 + 0x44) = mf[2];
    *(float *)((char *)arg0 + 0x48) = mf[3];
    *(float *)((char *)arg0 + 0x4C) = mf[4];
    *(float *)((char *)arg0 + 0x50) = mf[5];
    *(float *)((char *)arg0 + 0x54) = mf[6];
    *(float *)((char *)arg0 + 0x58) = mf[7];
    *(float *)((char *)arg0 + 0x5C) = mf[8];
    *(float *)((char *)arg0 + 0x60) = point[3];
    *(float *)((char *)arg0 + 0x64) = point[4];
    *(float *)((char *)arg0 + 0x68) = point[5];
    fn_8017A580(arg0);

    flags = lbl_8055D430;
    var_r3 = 0;
    if ((flags & 1) && (flags & 0x80)) var_r3 = 1;
    if (var_r3 != 0) {
        *(float *)((char *)arg0 + 0x118) = lbl_80561BE0;
        *(float *)((char *)arg0 + 0x11C) = lbl_80561C18;
        *(float *)((char *)arg0 + 0x120) = lbl_80561BE0;
    } else {
        var_r3_2 = 0;
        if ((flags & 1) && (flags & 0x10)) var_r3_2 = 1;
        if (var_r3_2 != 0) {
            t0 = mf[6] * lbl_80561C1C + mf[5] * lbl_80561C20;
            t1 = mf[7] * lbl_80561C1C + mf[4] * lbl_80561C20;
            t2 = mf[8] * lbl_80561C1C + mf[3] * lbl_80561C20;
            scale = lbl_80561C24 * farg0;
            *(float *)((char *)arg0 + 0x118) = t2 * scale;
            *(float *)((char *)arg0 + 0x11C) = t1 * scale;
            *(float *)((char *)arg0 + 0x120) = t0 * scale;
            *(float *)((char *)arg0 + 0x118) += vector[0];
            *(float *)((char *)arg0 + 0x11C) += vector[1];
            *(float *)((char *)arg0 + 0x120) += vector[2];
        } else {
            scale = lbl_80561C28 * farg0;
            *(float *)((char *)arg0 + 0x118) = vector[0] + *(float *)((char *)arg0 + 0x54) * scale;
            *(float *)((char *)arg0 + 0x11C) = vector[1] + *(float *)((char *)arg0 + 0x58) * scale;
            *(float *)((char *)arg0 + 0x120) = vector[2] + *(float *)((char *)arg0 + 0x5C) * scale;
            var_r3_3 = 0;
            if ((flags & 1) && (flags & 8)) var_r3_3 = 1;
            if (var_r3_3 != 0) {
                *(int *)((char *)arg0 + 0x1F0) = 0;
                *(float *)((char *)arg0 + 0x1F4) = lbl_80561C0C + fn_8017D378();
            }
        }
    }

    *(unsigned char *)((char *)arg0 + 0x1FE) = 1;
    *(unsigned char *)((char *)arg0 + 0x1FC) = 0;
    sub = *(void **)((char *)arg0 + 0x218);
    if (sub != 0) {
        *(float *)((char *)arg0 + 0x200) = point[3];
        *(float *)((char *)arg0 + 0x204) = point[4];
        *(float *)((char *)arg0 + 0x208) = point[5];
        if (lbl_80561BF4 != *(float *)((char *)sub + 8)) {
            *((unsigned char *)sub + 0x4D) = 1;
            *(float *)((char *)sub + 8) = lbl_80561BF4;
        }
        sub = *(void **)((char *)arg0 + 0x218);
        *((unsigned char *)sub + 0x49) = 1;
        *((unsigned char *)sub + 0x4B) = 0;
        *((unsigned char *)sub + 0x4A) = 0;
    }
    sub = *(void **)((char *)arg0 + 0x21C);
    if (sub != 0) {
        if (lbl_80561BF4 != *(float *)((char *)sub + 8)) {
            *((unsigned char *)sub + 0x4D) = 1;
            *(float *)((char *)sub + 8) = lbl_80561BF4;
        }
        sub = *(void **)((char *)arg0 + 0x21C);
        *((unsigned char *)sub + 0x4A) = 0;
        *((unsigned char *)sub + 0x4B) = 1;
        *((unsigned char *)sub + 0x49) = 1;
    }
}
#pragma dont_inline reset
#pragma scheduling on
#pragma pop
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

extern char lbl_80331DC0[];
extern int lbl_8055A318;
extern int lbl_8055A320;
extern int lbl_8055A328;
void fn_8017E96C(void *arg0, int **arg1, signed char *arg2) {
    int state = *(int *)((char *)arg0 + 0x1F0);
    switch (state) {
    case 0:
        *arg1 = &lbl_8055A328;
        *arg2 = 0;
        return;
    case 3:
        *arg1 = (int *)lbl_80331DC0;
        *arg2 = 0;
        return;
    case 1:
        *arg1 = 0;
        *arg2 = 0;
        return;
    case 2:
        *arg1 = &lbl_8055A320;
        *arg2 = 1;
        return;
    default:
        *arg1 = &lbl_8055A318;
        *arg2 = 0;
        return;
    }
}

extern float lbl_80561BF4;
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_8017E9FC(void *arg0, long arg1, unsigned char *arg2) {
    long temp_r31;
    short temp_r30;
    long flags;
    long var_r3;
    long state = *(long *)((char *)arg0 + 0x1F0);
    switch (state) {
    case 1:
        if (*arg2 == 0) *(long *)((char *)arg0 + 0x1F0) = 2;
        break;
    case 2:
        if (*arg2 != 0) {
            temp_r30 = *(short *)fn_8017EAF4(arg1);
            temp_r31 = fn_8017EAFC(arg1);
            fn_8017DEE0(arg0, fn_8017EB04(arg1), temp_r31, temp_r30, lbl_80561BF4);
            flags = lbl_8055D430;
            var_r3 = 0;
            if ((flags & 1) && (flags & 8)) var_r3 = 1;
            if (var_r3 != 0) {
                *(long *)((char *)arg0 + 0x1F0) = 0;
                *(float *)((char *)arg0 + 0x1F4) = lbl_80561C0C + fn_8017D378();
            }
        }
        break;
    }
}
#pragma scheduling on
#pragma dont_inline reset

long fn_8017EAF4(long arg0) { return arg0 + 0x6C; }

long fn_8017EAFC(long arg0) { return arg0 + 0x118; }

long fn_8017EB04(long arg0) { return arg0 + 0x70; }
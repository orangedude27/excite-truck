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

void fn_8017DB34(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    extern int lbl_8055D430;
    extern float lbl_80561BF4, lbl_80561C10, lbl_80561C14;
    extern void fn_801796EC(int, void *, int);
    extern void fn_8017D404(float *, int, int, float, float);
    extern void fn_8017D2C8(void *, int, int, int, int);
    float sp[6];
    void *p;

    if (*(unsigned char *)((char *)arg0 + 0x1FE) != 0 &&
        *(unsigned char *)((char *)arg0 + 0x1FD) != 0 &&
        (arg3 >= 100 || ((lbl_8055D430 & 1) && (lbl_8055D430 & 0x90))) &&
        arg3 < 1000) {
        sp[0] = *(float *)((char *)arg0 + 0x60);
        sp[1] = *(float *)((char *)arg0 + 0x64);
        sp[2] = *(float *)((char *)arg0 + 0x68);
        sp[3] = *(float *)((char *)arg0 + 0x118);
        sp[4] = *(float *)((char *)arg0 + 0x11C);
        sp[5] = *(float *)((char *)arg0 + 0x120);
        fn_801796EC(8, sp, 0x18);
        fn_8017D404((float *)((char *)arg0 + 0x60), arg4,
                    *(int *)((char *)arg0 + 0x1F8), lbl_80561C10, lbl_80561C14);
        p = *(void **)((char *)arg0 + 0x21C);
        if (p != 0) {
            *((unsigned char *)p + 0x4A) = 1;
            *((unsigned char *)p + 0x4C) = 0;
        }
        p = *(void **)((char *)arg0 + 0x220);
        if (p != 0) {
            *(float *)((char *)arg0 + 0x20C) = *(float *)((char *)arg0 + 0x60);
            *(float *)((char *)arg0 + 0x210) = *(float *)((char *)arg0 + 0x64);
            *(float *)((char *)arg0 + 0x214) = *(float *)((char *)arg0 + 0x68);
            if (lbl_80561BF4 != *(float *)((char *)p + 8)) {
                *((unsigned char *)p + 0x4D) = 1;
                *(float *)((char *)p + 8) = lbl_80561BF4;
            }
            *((unsigned char *)p + 0x49) = 1;
            *((unsigned char *)p + 0x4B) = 0;
            *((unsigned char *)p + 0x4A) = 0;
        }
        *((unsigned char *)arg0 + 0x1FE) = 0;
        *((unsigned char *)arg0 + 0x1FC) = 1;
    }
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


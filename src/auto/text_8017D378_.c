#pragma cplusplus on
struct VObj_8017D93C { virtual void d0(int); };
#pragma cplusplus reset

#pragma small_data off
extern float lbl_80558DC4;
#pragma small_data on

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma small_data off
extern char lbl_80331D18[];
#pragma small_data on
extern void *fn_801284F8(int, void *);
extern void fn_8017B0F8(void);
extern void fn_8017A580(void *);
extern void fn_8019EECC(void *, void *);
extern void fn_80179F94(void *, void *);
extern void fn_801D0C58(void *, int, int);
extern int fn_802077A4(void *, int, void *, void *);
extern float lbl_80561BE0;
extern float lbl_80561C04;
extern float lbl_80561C08;
extern char lbl_80331DB4[];
extern char lbl_80333B48[];
extern char lbl_80331DA4[];
extern char lbl_80331D98[];
extern char lbl_80331D8C[];
#pragma cplusplus on
struct VObj_8017D6E0 {
    virtual void f8(); virtual void fC(); virtual void f10(); virtual void f14();
    virtual void f18(); virtual void f1C(); virtual void f20(); virtual void f24();
    virtual void f28(); virtual void f2C(); virtual void f30(); virtual void f34();
    virtual void f38(); virtual void f3C(); virtual void f40(int);
};
#pragma cplusplus reset
void fn_802066C8(void*, unsigned int);
void fn_80206C70(void*);
#pragma push
#pragma dont_inline on
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
    int scaled = arg1 * 2;
    void *sub = *(void **)((char *)root + 0x2C);
    float *values = *(float **)((char *)sub + 0x1C);
    arg0[0] = values[0];
    arg0[1] = lbl_80561BE0;
    arg0[1] = lbl_80561BE4 + (float)scaled;
    arg0[2] = values[1];
}

extern void *fn_8017960C(int);
extern void fn_801B619C(void *, int *, float *);
extern float PSVECDotProduct(float *, float *);
extern void PSVECNormalize(float *, float *);
extern double fn_8002F234(float);
extern float fn_80129DC4(int, float, float);
extern void fn_8017B5D4(void *, int, int, float *, float *, int, int, void *, float);
extern float lbl_80561BF0, lbl_80561BF4, lbl_80561BF8, lbl_80561BFC, lbl_80561C00;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_8017D404(float *pos, int target, float radius, float strength, int arg2) {
    struct V { virtual int a0(); virtual int a1(); virtual int a2(); virtual int a3(); virtual int a4(); virtual int a5(); virtual int a6(); virtual int a7(); virtual int a8(); virtual int a9(); virtual int a10(); virtual int a11(); virtual int a12(); virtual int a13(); virtual int test(); };
    void **lists[5];
    float diff[3], contact[3], impulse[3];
    int count;
    register char *obj;
    register void **node;
    register void ***iter;
    register void *result = fn_8017960C(arg2);
    register int i;
    float dist, rand, px, py, pz;
    float zero;
    float one;
    register float offset;
    float factor;
    count = 5;
    fn_801B619C(lists, &count, pos);
    one = lbl_80561BF4;
    offset = lbl_80561C00;
    zero = lbl_80561BF0;
    iter = lists;
    for (i=0; i<count; ) {
        node = (void **)**iter;
        while (node) {
            obj = (char *)node[0];
            if (((V *)obj)->test()) obj = (char *)node[0];
            else obj = 0;
            if (obj) {
                px = pos[0]; py = pos[1]; pz = pos[2];
                diff[0] = px - *(float *)(obj+0x60);
                diff[1] = py - *(float *)(obj+0x64);
                diff[2] = pz - *(float *)(obj+0x68);
                dist = PSVECDotProduct(diff, diff);
                if (dist < radius*radius && dist > zero) {
                    if ((unsigned int)obj == (unsigned int)target) factor = lbl_80561BF4;
                    else factor = one - (float)fn_8002F234(dist)/radius;
                    PSVECNormalize(diff, diff);
                    contact[0] = *(float *)(obj+0x60) + diff[0];
                    contact[1] = *(float *)(obj+0x64) + diff[1];
                    contact[2] = *(float *)(obj+0x68) + diff[2];
                    rand = fn_80129DC4(3, lbl_80561BF8, lbl_80561BFC);
                    contact[0] += *(float *)(obj+0x3c)*rand;
                    contact[1] += *(float *)(obj+0x40)*rand;
                    contact[2] += *(float *)(obj+0x44)*rand;
                    rand = fn_80129DC4(3, lbl_80561BF8, lbl_80561BFC);
                    contact[0] += *(float *)(obj+0x54)*rand;
                    contact[1] += *(float *)(obj+0x58)*rand;
                    contact[2] += *(float *)(obj+0x5c)*rand;
                    diff[1] -= offset;
                    impulse[0] = diff[0]*(-factor * strength);
                    impulse[1] = diff[1]*(-factor * strength);
                    impulse[2] = diff[2]*(-factor * strength);
                    fn_8017B5D4(obj, 0, 0, impulse, contact, 1001, 0, result, lbl_80561BF4);
                }
            }
            node = (void **)node[1];
        }
        iter++;
        i++;
    }
}
#pragma pop

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

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8017D6E0(void *arg0, void *arg1) {
    char *a = (char *)arg0;
    char *b = (char *)arg1;
    float v[3];
    float pos[3];
    float f31, f30, f29, f5, sq;
    char *obj;
    void *sub;
    fn_8017B0F8();
    f5 = lbl_80561C08 * *(float *)(b + 0x24) / lbl_80561C04;
    f31 = *(float *)(b + 0x2C);
    v[0] = lbl_80561BE0;
    v[1] = lbl_80561BE0;
    v[2] = lbl_80561BE0;
    sq = *(float *)(b + 0x28) * *(float *)(b + 0x28);
    f30 = lbl_80561C04 * *(float *)(b + 0x20);
    *(int *)(a + 0x1F8) = *(int *)(b + 0x18);
    f29 = f5 * sq;
    fn_8017D380(pos, *(int *)(a + 0x1F8));
    *(float *)(a + 0x60) = pos[0];
    *(float *)(a + 0x64) = pos[1];
    *(float *)(a + 0x68) = pos[2];
    fn_8017A580(arg0);
    *(unsigned char *)(a + 0x1FD) = *(unsigned char *)(b + 0x30);
    *(float *)(a + 0x224) = *(float *)(b + 0x34);
    *(float *)(a + 0x228) = *(float *)(b + 0x38);
    *(float *)(a + 0x22C) = *(float *)(b + 0x3C);
    obj = (char *)fn_801284F8(0x54, lbl_80331DB4);
    if (obj != 0) {
        *(void **)(obj + 0xC) = a + 0x3C;
        *(void **)(obj + 4) = arg0;
        *(int *)(obj + 8) = 0;
        *(int *)(obj + 0x18) = 0x53504852;
        *(float *)(obj + 0x10) = f29;
        *(float *)(obj + 0x14) = f31;
        *(int *)(obj + 0x20) = 0x64;
        *(int *)(obj + 0x1C) = 0;
        *(void **)obj = lbl_80333B48;
        *(float *)(obj + 0x24) = f30;
        *(float *)(obj + 0x34) = lbl_80561BE0;
        *(float *)(obj + 0x38) = lbl_80561BE0;
        *(float *)(obj + 0x3C) = lbl_80561BE0;
        *(float *)(obj + 0x40) = lbl_80561BE0;
        *(float *)(obj + 0x44) = lbl_80561BE0;
        *(float *)(obj + 0x48) = lbl_80561BE0;
        *(char *)(obj + 0x4C) = 0;
        *(float *)(obj + 0x50) = lbl_80561BE0;
        *(float *)(obj + 0x28) = v[0];
        *(float *)(obj + 0x2C) = v[1];
        *(float *)(obj + 0x30) = v[2];
        if (arg0 != 0) fn_8019EECC(arg0, obj + 0x28);
    }
    ((VObj_8017D6E0 *)obj)->f40(0x3E9);
    fn_80179F94(arg0, obj);
    *(char *)(a + 0x1E8) = 1;
    *(char *)(a + 0x1E9) = 0;
    sub = arg0;
    *(char *)(a + 0x1FC) = 1;
    *(char *)(a + 0x1FE) = 0;
    if (arg0 != 0) sub = a + 0x1EC;
    fn_801D0C58(sub, *(int *)(a + 0x1F8), 0);
    {
        float x = *(float *)(a + 0x60);
        float y = *(float *)(a + 0x64);
        float z = *(float *)(a + 0x68);
        *(float *)(a + 0x200) = x;
        *(float *)(a + 0x204) = y;
        *(float *)(a + 0x208) = z;
        *(float *)(a + 0x20C) = x;
        *(float *)(a + 0x210) = y;
        *(float *)(a + 0x214) = z;
    }
    *(int *)(a + 0x218) = fn_802077A4(lbl_80331DA4, 5, a + 0x118, a + 0x200);
    *(int *)(a + 0x21C) = fn_802077A4(lbl_80331D98, 8, a + 0x118, a + 0x60);
    *(int *)(a + 0x220) = fn_802077A4(lbl_80331D8C, 5, a + 0x118, a + 0x20C);
}
#pragma cplusplus reset
#pragma scheduling on

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
    float savedPos[6];
    float z, x, y;
    int allow;
    int flags;
    void *node;
    void *node2;
    volatile float *values;
    unsigned char *object = (unsigned char *)arg0;

    /* If active, optionally update position-related state based on global flags/arg3, sync linked nodes, then always forward to fn_8017D2C8. */
    if (object[0x1FE] == 0)
        goto done;
    if (object[0x1FD] == 0)
        goto done;
    if (arg3 < 100) {
        flags = lbl_8055D430;
        allow = 0;
        if (flags & 1) {
            if (flags & 0x90)
                allow = 1;
        }
        if (allow == 0)
            goto done;
    }
    if (arg3 >= 1000)
        goto done;

    savedPos[0] = *(float *)(object + 0x60);
    savedPos[1] = *(float *)(object + 0x64);
    savedPos[2] = *(float *)(object + 0x68);
    savedPos[3] = *(float *)(object + 0x118);
    savedPos[4] = *(float *)(object + 0x11C);
    savedPos[5] = *(float *)(object + 0x120);
    fn_801796EC(8, savedPos, 0x18);
    fn_8017D404((float *)(object + 0x60), arg4,
                lbl_80561C10, lbl_80561C14, *(int *)(object + 0x1F8));

    node = *(void **)(object + 0x21C);
    if (node != 0) {
        *((unsigned char *)node + 0x4A) = 1;
        *((unsigned char *)node + 0x4C) = 0;
    }
    node = *(void **)(object + 0x220);
    if (node != 0) {
        values = (volatile float *)(object + 0x60);
        x = values[0];
        y = values[1];
        z = values[2];
        *(volatile float *)(object + 0x20C) = x;
        x = lbl_80561BF4;
        *(volatile float *)(object + 0x210) = y;
        *(volatile float *)(object + 0x214) = z;
        if (x != *(float *)((char *)node + 8)) {
            *((unsigned char *)node + 0x4D) = 1;
            *(float *)((char *)node + 8) = x;
        }
        node2 = *(void * volatile *)(object + 0x220);
        *((unsigned char *)node2 + 0x49) = 1;
        *((unsigned char *)node2 + 0x4B) = 0;
        *((unsigned char *)node2 + 0x4A) = 0;
    }
    object[0x1FE] = 0;
    object[0x1FC] = 1;
done:
    fn_8017D2C8(arg0, arg1, arg2, arg3, arg4);
}

#pragma push
#pragma processor 750
#pragma ppc_psq_save off
void fn_8017DCB4(void *arg0) {
 unsigned char *p=(unsigned char*)arg0; float a[2]; float d[3]; int v3[3]; float v1[3]; float v2[3]; float b[9]; float c[3]; unsigned tag; int mode; int fl; int x; float z;
 extern void fn_8017B164(void); extern void fn_8017D380(float*,int); extern void fn_8017A580(void*);
 extern float fn_8017D378(void); extern void *fn_8017960C(int); extern void *fn_801B2EC0(int);
 extern void fn_801602B0(void*); extern void fn_8017E3C4(void*,void*,short*);
 extern void fn_80144DC8(void*); extern void fn_8017E388(void*); extern void fn_80160230(void*,void*);
 extern float fn_8017E380(); extern void *fn_801602B4(void);
 extern void GXInitLightAttnA_80144B44(float*,float,float,float);
 extern void fn_8017DEE0(void*,long,long,short,float); extern int fn_801E9E30(void*,int*);
 extern void fn_8017B81C(void*);
 if(p[0x1FC]) { fn_8017B164(); fn_8017D380(v1,*(int*)(p+0x1F8)); *(float*)(p+0x60)=v1[0]; *(float*)(p+0x64)=v1[1]; *(float*)(p+0x68)=v1[2]; fn_8017A580(arg0); p[0x1E9]=0; p[0x1FC]=0; }
 if(*(int*)(p+0x1F0)==0 && *(float*)(p+0x1F4)<fn_8017D378()) { tag=*(unsigned*)((char*)fn_8017960C(*(int*)(p+0x1F8))+0x10); mode=1; if(tag==0x41434152) mode=2; *(int*)(p+0x1F0)=mode; }
 x=lbl_8055D430; fl=0; if((x&1)&&(x&0x88)) fl=1;
 if(fl==0) { fn_8017D380(v2,*(int*)(p+0x1F8)); *(float*)(p+0x60)=v2[0]; *(float*)(p+0x64)=v2[1]; *(float*)(p+0x68)=v2[2]; fn_8017A580(arg0); z=lbl_80561BE0; *(float*)(p+0x118)=z; *(float*)(p+0x11C)=z; *(float*)(p+0x120)=z; }
 if(!p[0x1FE]) { x=lbl_8055D430; fl=0; if((x&1)&&(x&0x80)) fl=1;
 if(fl!=0) { void*obj=fn_801B2EC0(*(int*)(p+0x1F8)); void*r=((void*(*)(void*))(*(void***)obj)[4])(obj); if(*(int*)((char*)r+0x24)==0) { short angle; float f31; fn_801602B0(a); fn_8017E3C4(arg0,a,&angle); fn_80144DC8(b); fn_8017E388(b); fn_80160230(c,a); f31=fn_8017E380(arg0); fn_8017960C(*(int*)(p+0x1F8)); c[1]=*(float*)((char*)fn_801602B4()+0x28)+f31; GXInitLightAttnA_80144B44(d,lbl_80561BE0,lbl_80561BE0,lbl_80561BE0); fn_8017DEE0(arg0,(long)b,(long)d,angle,lbl_80561BE0); } } }
 v3[0]=*(int*)(p+0x60);v3[1]=*(int*)(p+0x64);v3[2]=*(int*)(p+0x68); if(fn_801E9E30(p+0x6C,v3)==0)p[0x1FC]=1; fn_8017B81C(arg0);
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
#pragma dont_inline on
#pragma ppc_psq_save off
void fn_8017DEE0(void *arg0, long arg1, long arg2, short arg3, float farg0) {
    extern int lbl_8055D430;
    extern float lbl_80561BE0, lbl_80561BF4, lbl_80561C0C;
    extern float lbl_80561C18, lbl_80561C1C, lbl_80561C20;
    extern float lbl_80561C24, lbl_80561C28;
    float point[3];
    float tmp[3];
    float m[12];
    float vx, vy, vz;
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
    ((int *)m)[0] = ((int *)arg1)[0];
    ((int *)m)[1] = ((int *)arg1)[1];
    ((int *)m)[2] = ((int *)arg1)[2];
    ((int *)m)[3] = ((int *)arg1)[3];
    ((int *)m)[4] = ((int *)arg1)[4];
    ((int *)m)[5] = ((int *)arg1)[5];
    ((int *)m)[6] = ((int *)arg1)[6];
    ((int *)m)[7] = ((int *)arg1)[7];
    ((int *)m)[8] = ((int *)arg1)[8];
    ((int *)m)[9] = ((int *)arg1)[9];
    ((int *)m)[10] = ((int *)arg1)[10];
    ((int *)m)[11] = ((int *)arg1)[11];
    if (point == (float *)((char *)arg0 + 0x224)) {
        vx = point[0];
        vy = point[1];
        vz = point[2];
        point[0] = vx * m[0] + vy * m[3] + vz * m[6];
        point[1] = vx * m[1] + vy * m[4] + vz * m[7];
        point[2] = vx * m[2] + vy * m[5] + vz * m[8];
    } else {
        point[0] = *(float *)((char *)arg0 + 0x224) * m[0] + *(float *)((char *)arg0 + 0x228) * m[3] + *(float *)((char *)arg0 + 0x22C) * m[6];
        point[1] = *(float *)((char *)arg0 + 0x224) * m[1] + *(float *)((char *)arg0 + 0x228) * m[4] + *(float *)((char *)arg0 + 0x22C) * m[7];
        point[2] = *(float *)((char *)arg0 + 0x224) * m[2] + *(float *)((char *)arg0 + 0x228) * m[5] + *(float *)((char *)arg0 + 0x22C) * m[8];
    }
    point[0] = point[0] + m[9];
    point[1] = point[1] + m[10];
    point[2] = point[2] + m[11];
    m[9] = point[0];
    m[10] = point[1];
    m[11] = point[2];
    *(int *)((char *)arg0 + 0x3C) = ((int *)m)[0];
    *(int *)((char *)arg0 + 0x40) = ((int *)m)[1];
    *(int *)((char *)arg0 + 0x44) = ((int *)m)[2];
    *(int *)((char *)arg0 + 0x48) = ((int *)m)[3];
    *(int *)((char *)arg0 + 0x4C) = ((int *)m)[4];
    *(int *)((char *)arg0 + 0x50) = ((int *)m)[5];
    *(int *)((char *)arg0 + 0x54) = ((int *)m)[6];
    *(int *)((char *)arg0 + 0x58) = ((int *)m)[7];
    *(int *)((char *)arg0 + 0x5C) = ((int *)m)[8];
    *(int *)((char *)arg0 + 0x60) = ((int *)m)[9];
    *(int *)((char *)arg0 + 0x64) = ((int *)m)[10];
    *(int *)((char *)arg0 + 0x68) = ((int *)m)[11];
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
            tmp[0] = m[6] * lbl_80561C1C + m[3] * lbl_80561C20;
            tmp[1] = m[7] * lbl_80561C1C + m[4] * lbl_80561C20;
            tmp[2] = m[8] * lbl_80561C1C + m[5] * lbl_80561C20;
            *(float *)((char *)arg0 + 0x118) = tmp[0] * (lbl_80561C24 * farg0);
            *(float *)((char *)arg0 + 0x11C) = tmp[1] * (lbl_80561C24 * farg0);
            *(float *)((char *)arg0 + 0x120) = tmp[2] * (lbl_80561C24 * farg0);
            *(float *)((char *)arg0 + 0x118) += ((float *)arg2)[0];
            *(float *)((char *)arg0 + 0x11C) += ((float *)arg2)[1];
            *(float *)((char *)arg0 + 0x120) += ((float *)arg2)[2];
        } else {
            *(float *)((char *)arg0 + 0x118) = ((float *)arg2)[0] + *(float *)((char *)arg0 + 0x54) * (lbl_80561C28 * farg0);
            *(float *)((char *)arg0 + 0x11C) = ((float *)arg2)[1] + *(float *)((char *)arg0 + 0x58) * (lbl_80561C28 * farg0);
            *(float *)((char *)arg0 + 0x120) = ((float *)arg2)[2] + *(float *)((char *)arg0 + 0x5C) * (lbl_80561C28 * farg0);
            var_r3_3 = 0;
            if ((flags & 1) && (flags & 8)) var_r3_3 = 1;
            if (var_r3_3 != 0) {
                *(int *)((char *)arg0 + 0x1F0) = 0;
                *(float *)((char *)arg0 + 0x1F4) = lbl_80561C0C + fn_8017D378();
            }
        }
    }
    *((unsigned char *)arg0 + 0x1FE) = 1;
    *((unsigned char *)arg0 + 0x1FC) = 0;
    sub = *(void **)((char *)arg0 + 0x218);
    if (sub != 0) {
        *(float *)((char *)arg0 + 0x200) = point[0];
        *(float *)((char *)arg0 + 0x204) = point[1];
        *(float *)((char *)arg0 + 0x208) = point[2];
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
#pragma ppc_psq_save reset
#pragma dont_inline reset
#pragma scheduling on
#pragma pop
float fn_8017E380(void) { extern float lbl_80561C2C; return lbl_80561C2C; }

void fn_8017E388(void *arg0) {
 extern float lbl_80561BE0; extern float lbl_80561BF4;
 float a=lbl_80561BE0, b=lbl_80561BF4; float *p=(float*)arg0;
 p[1]=a; p[0]=b; p[2]=a; p[3]=a; p[4]=b; p[5]=a; p[6]=a; p[7]=a; p[8]=b; p[9]=a; p[10]=a; p[11]=a;
}

#pragma small_data off
void fn_8017E764(void *arg0, int arg1) {
    extern float lbl_8055E460;
    extern float lbl_80561BF4;
    unsigned char *src = (unsigned char *)arg0;
    unsigned char *dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    float delta = lbl_8055E460 - lbl_80561BF4;
    if ((float)__fabs((double)delta) <= lbl_80558DC4) {
        unsigned int t0 = *(unsigned int *)(src + 0x70);
        unsigned int t1 = *(unsigned int *)(src + 0x74);
        *(unsigned int *)(dst + 0x00) = t0;
        *(unsigned int *)(dst + 0x04) = t1;
        t0 = *(unsigned int *)(src + 0x78);
        t1 = *(unsigned int *)(src + 0x7C);
        *(unsigned int *)(dst + 0x08) = t0;
        *(unsigned int *)(dst + 0x0C) = t1;
        t0 = *(unsigned int *)(src + 0x80);
        t1 = *(unsigned int *)(src + 0x84);
        *(unsigned int *)(dst + 0x10) = t0;
        *(unsigned int *)(dst + 0x14) = t1;
        t0 = *(unsigned int *)(src + 0x88);
        t1 = *(unsigned int *)(src + 0x8C);
        *(unsigned int *)(dst + 0x18) = t0;
        *(unsigned int *)(dst + 0x1C) = t1;
        t0 = *(unsigned int *)(src + 0x90);
        *(unsigned int *)(dst + 0x20) = t0;
        {
            unsigned int u0 = *(unsigned int *)(src + 0x94);
            unsigned int u1 = *(unsigned int *)(src + 0x98);
            *(unsigned int *)(dst + 0x24) = u0;
            *(unsigned int *)(dst + 0x28) = u1;
        }
        t0 = *(unsigned int *)(src + 0x9C);
        *(unsigned int *)(dst + 0x2C) = t0;
    } else {
        float tmp[12];
        float *a = (float *)(src + 0x70);
        float *b = (float *)(src + 0xA0);
        int i;
        for (i = 0; i < 2; i++) {
            float a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3], a4 = a[4], a5 = a[5];
            float b0 = b[0], b1 = b[1], b2 = b[2], b3 = b[3], b4 = b[4], b5 = b[5];
            tmp[i * 6 + 0] = b0 + lbl_8055E460 * (a0 - b0);
            tmp[i * 6 + 1] = b1 + lbl_8055E460 * (a1 - b1);
            tmp[i * 6 + 2] = b2 + lbl_8055E460 * (a2 - b2);
            tmp[i * 6 + 3] = b3 + lbl_8055E460 * (a3 - b3);
            tmp[i * 6 + 4] = b4 + lbl_8055E460 * (a4 - b4);
            tmp[i * 6 + 5] = b5 + lbl_8055E460 * (a5 - b5);
            a += 6;
            b += 6;
        }
        *(unsigned int *)(dst + 0x00) = *(unsigned int *)&tmp[0];
        *(unsigned int *)(dst + 0x04) = *(unsigned int *)&tmp[1];
        *(unsigned int *)(dst + 0x08) = *(unsigned int *)&tmp[2];
        *(unsigned int *)(dst + 0x0C) = *(unsigned int *)&tmp[3];
        *(unsigned int *)(dst + 0x10) = *(unsigned int *)&tmp[4];
        *(unsigned int *)(dst + 0x14) = *(unsigned int *)&tmp[5];
        *(unsigned int *)(dst + 0x18) = *(unsigned int *)&tmp[6];
        *(unsigned int *)(dst + 0x1C) = *(unsigned int *)&tmp[7];
        *(unsigned int *)(dst + 0x20) = *(unsigned int *)&tmp[8];
        *(unsigned int *)(dst + 0x24) = *(unsigned int *)&tmp[9];
        *(unsigned int *)(dst + 0x28) = *(unsigned int *)&tmp[10];
        *(unsigned int *)(dst + 0x2C) = *(unsigned int *)&tmp[11];
    }
    *(short *)(dst + 0x30) = *(short *)(src + 0x6C);
    *(unsigned char *)((unsigned char *)arg1 + *(unsigned int *)(src + 8) + 0x32) = src[0x1FE];
}
#pragma small_data on
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
// Updates this object's sound/trigger state based on the current state and input flag.
void fn_8017E9FC(void *obj, long param, unsigned char *triggerFlag) {
    long shortData;
    short soundId;
    long flags;
    long isEnabled;
    long state = *(long *)((char *)obj + 0x1F0);
    switch (state) {
    case 1:
        if (*triggerFlag == 0) *(long *)((char *)obj + 0x1F0) = 2;
        break;
    case 2:
        if (*triggerFlag != 0) {
            soundId = *(short *)fn_8017EAF4(param);
            shortData = fn_8017EAFC(param);
            fn_8017DEE0(obj, fn_8017EB04(param), shortData, soundId, lbl_80561BF4);
            flags = lbl_8055D430;
            isEnabled = 0;
            if ((flags & 1) && (flags & 8)) isEnabled = 1;
            if (isEnabled != 0) {
                *(long *)((char *)obj + 0x1F0) = 0;
                *(float *)((char *)obj + 0x1F4) = lbl_80561C0C + fn_8017D378();
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
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_802C86DC(void);
extern float fn_801E7E18(void);
extern float PSVECDotProduct(float *, float *);
extern double fn_8002EFB0();
extern void fn_8029231C();
extern void PSVECNormalize(void *, void *);
extern void *fn_801284F8(int, void *);
__declspec(section ".data") extern int lbl_8033A6A0[2];
__declspec(section ".data") extern int lbl_8033A710[2];
#pragma push
#pragma small_data off
#pragma pop
extern int lbl_8033A628, lbl_8033A8C8;
__declspec(section ".data") extern int lbl_8033A610, lbl_8033A684;
extern const char lbl_8033A988[];
extern const char lbl_8033A6E0[];
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_8033A8F8;
#pragma pop
__declspec(section ".data") extern int lbl_8033A644, lbl_8033A868, lbl_8033A928;
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_8033AA90;
#pragma pop
extern int lbl_8055B124, lbl_8055B120;
extern float lbl_80562F40, lbl_80562F44;
extern const char lbl_8033ABA0[];
extern const char lbl_8033AB3C[];
extern const char lbl_8033AAE0[];
extern const char lbl_8033AB80[];
extern int fn_802E317C(const void *, ...);
extern int *fn_801F1CE8(int);
extern const char lbl_8033A9E8[];
extern int lbl_8055B118;
extern const char lbl_8033A740[];
extern int lbl_8055B138;
#pragma dont_inline fn_801F1CE8
#pragma push
#pragma small_data off
#pragma pop
#pragma scheduling invalid_target
#pragma dont_inline on
extern void PSVECCrossProduct(float *, float *, float *);
int fn_801F1C24(void *arg0) {
    extern float lbl_80562F48;
    extern float lbl_80562F4C;
    struct Vec { float x, y, z; };
    struct Frame { struct Vec a, b, c; };
    struct Frame *p = (struct Frame *)arg0;
    char *camera;
    float f1, f0, f2, cameraX;
    camera = (char *)fn_802C86DC();
    f2 = lbl_80562F40;
    f0 = lbl_80562F44;
    *(volatile float *)&p->b.x = f2;
    f1 = lbl_80562F48;
    *(volatile float *)&p->b.y = f0;
    p->b.z = f2;
    cameraX = *(float *)(camera + 0x18);
    p->c.x = cameraX * f1;
    p->c.y = *(float *)(camera + 0x1C) * f1;
    p->c.z = *(float *)(camera + 0x20) * f1;
    PSVECCrossProduct((float *)&p->b, (float *)&p->c, (float *)&p->a);
    if (PSVECDotProduct((float *)&p->a, (float *)&p->a) > lbl_80562F4C) {
        PSVECNormalize((float *)&p->a, (float *)&p->a);
    } else {
        f2 = lbl_80562F40;
        f1 = lbl_80562F44;
        p->a.y = f2;
        p->a.x = f1;
        p->a.z = f2;
    }
    PSVECCrossProduct((float *)&p->c, (float *)&p->a, (float *)&p->b);
}

int *fn_801F1CE8(int arg0) {
    return (int *)(arg0 + 0x2C);
}

int fn_801F1CF0(int arg0) {
    float delta[3];
    void *camera;
    float x, y, z, cx, cy, cz;
    char *base = (char *)arg0;

    camera = fn_802C86DC();
    x = *(float *)(base + 0x24);
    y = *(float *)(base + 0x28);
    cx = *(float *)((char *)camera + 0x24);
    z = *(float *)(base + 0x2C);
    delta[0] = x - cx;
    cy = *(float *)((char *)camera + 0x28);
    delta[1] = y - cy;
    cz = *(float *)((char *)camera + 0x2C);
    delta[2] = z - cz;
    return PSVECDotProduct(delta, (float *)(base + 0x18)) < lbl_80562F40;
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801F1D68(void) {
    void **slot = (void **)fn_801284F8(4, (void *)&lbl_8055B118);
    if (slot != 0) {
        *slot = (void *)&lbl_8033A9E8;
    }
}

void *fn_801F1DA4(void) {
    void **p = (void **)fn_801284F8(4, (void *)&lbl_8033A610);
    if (p != 0) {
        *p = (void *)lbl_8033A988;
    }
    return (void *)p;
}

#pragma scheduling invalid_target
void *fn_801F1DE4(void) {
    extern const char lbl_8033A61C[], lbl_8033A9B8[];
    void **p = (void **)fn_801284F8(4, (void *)lbl_8033A61C);
    if (p != 0) {
        *p = (void *)lbl_8033A9B8;
    }
    return (void *)p;
}
#pragma scheduling on
void fn_801F1E24(void) {
    void *p = fn_801284F8(0x40, &lbl_8055B120);
    if (p != 0) {
        float f1 = lbl_80562F44;
        float f0 = lbl_80562F40;
        *(void **)p = &lbl_8033A928;
        *(int *)((char *)p + 0x3C) = 0;
        *(float *)((char *)p + 0xC) = f1;
        *(float *)((char *)p + 0x10) = f0;
        *(float *)((char *)p + 0x14) = f0;
        *(float *)((char *)p + 0x18) = f0;
        *(float *)((char *)p + 0x1C) = f1;
        *(float *)((char *)p + 0x20) = f0;
        *(float *)((char *)p + 0x24) = f0;
        *(float *)((char *)p + 0x28) = f0;
        *(float *)((char *)p + 0x2C) = f1;
        *(float *)((char *)p + 0x30) = f0;
        *(float *)((char *)p + 0x34) = f0;
        *(float *)((char *)p + 0x38) = f0;
        *(int *)((char *)p + 8) = 1;
    }
}
#pragma push
#pragma small_data off
void fn_801F1EA8(void) {
    void *p = fn_801284F8(0x14, &lbl_8055B124);
    if (p != 0) {
        *(void **)p = &lbl_8033A8F8;
        *(int *)((char *)p + 0x10) = 0;
    }
}
#pragma pop
extern int fn_802CAC28(void *, int);
extern void *fn_802C86DC(void);
extern int lbl_8033A628, lbl_8033A8C8, lbl_8033A660, lbl_8033AC58;
__declspec(section ".data") extern int lbl_8033A660;
__declspec(section ".data") extern int lbl_8033AC58;
extern char lbl_8033A808[];
__declspec(section ".data") extern int lbl_8033A958;
extern int lbl_8055B128;
extern float lbl_80562F40;
#pragma push
#pragma small_data off
extern int lbl_8033A628;
extern int lbl_8033A8C8;
#pragma pop
__declspec(section ".data") extern int lbl_8033A628;
__declspec(section ".data") extern int lbl_8033A8C8;
void fn_801F1EEC(void) {
    void *p = fn_801284F8(12, &lbl_8033A628);
    if (p != 0) {
        *(void **)p = &lbl_8033A8C8;
        *(int *)((char *)p + 8) = 0;
        *(char *)((char *)p + 4) = 0;
    }
}

__declspec(section ".data") extern int lbl_8033A638;
__declspec(section ".data") extern int lbl_8033A898;
void fn_801F1F38(void) {
    void *p = fn_801284F8(12, &lbl_8033A638);
    if (p != 0) {
        *(void **)p = &lbl_8033A898;
        *(int *)((char *)p + 8) = 0;
        *(char *)((char *)p + 4) = 0;
    }
}

void fn_801F1F84(void) {
    void *p = fn_801284F8(0xC, &lbl_8033A644);
    if (p != 0) {
        float f = lbl_80562F40;
        *(void **)p = &lbl_8033A868;
        *(float *)((char *)p + 8) = f;
        *(char *)((char *)p + 4) = 0;
    }
}

__declspec(section ".data") extern int lbl_8033A654;
__declspec(section ".data") extern int lbl_8033A838;
void fn_801F1FD4(void) {
    void *p = fn_801284F8(12, &lbl_8033A654);
    if (p != 0) {
        *(void **)p = &lbl_8033A838;
        *(int *)((char *)p + 8) = 0;
        *(char *)((char *)p + 4) = 0;
    }
}

#pragma push
#pragma small_data off
void fn_801F2020(void) {
    void *p = fn_801284F8(8, &lbl_8055B128);
    if (p != 0) {
        *(void **)p = lbl_8033A808;
        *(int *)((char *)p + 4) = 0;
    }
}
#pragma push
#pragma scheduling invalid_target
void *fn_801F2064(void) {
    void *p = fn_801284F8(8, &lbl_8033A660);
    if (p) { *(void **)p = &lbl_8033A958; *(int *)((char *)p + 4) = fn_802CAC28(&lbl_8033AC58, 0); }
    return p;
}
#pragma pop
extern const char lbl_8033A66C[];
extern const char lbl_8033A7D0[];
#pragma scheduling invalid_target
void *fn_801F20C8(void) {
    void **p = (void **)fn_801284F8(4, (void *)lbl_8033A66C);
    if (p != 0) {
        *p = (void *)lbl_8033A7D0;
    }
    return p;
}
#pragma scheduling on

#pragma push
#pragma small_data off
void fn_801F2108(void) {
    extern int lbl_8055B130;
    extern int lbl_8033A7A0[];
    void *p = fn_801284F8(0xC, &lbl_8055B130);
    if (p != 0) {
        *(void **)p = &lbl_8033A7A0;
        *(int *)((char *)p + 4) = 0;
        *(int *)((char *)p + 8) = 0;
    }
}

extern const char lbl_8033A678[];
extern const char lbl_8033A770[];
#pragma scheduling invalid_target
void *fn_801F2150(void) {
    void **p = (void **)fn_801284F8(4, (void *)lbl_8033A678);
    if (p != 0) {
        *p = (void *)lbl_8033A770;
    }
    return p;
}

void fn_801F2190(void) {
    void **slot = (void **)fn_801284F8(4, (void *)&lbl_8055B138);
    if (slot != 0) {
        *slot = (void *)&lbl_8033A740;
    }
}
#pragma scheduling on
#pragma dont_inline off

void *fn_801F21CC(void) {
    void **p = (void **)fn_801284F8(4, (void *)&lbl_8033A684);
    if (p != 0) {
        *p = (void *)lbl_8033A6E0;
    }
    return (void *)p;
}

#pragma scheduling invalid_target
void *fn_801F220C(void) {
    extern const char lbl_8033A694[], lbl_8033A6B0[];
    void **p = (void **)fn_801284F8(4, (void *)lbl_8033A694);
    if (p != 0) {
        *p = (void *)lbl_8033A6B0;
    }
    return (void *)p;
}
#pragma scheduling on

#pragma scheduling on

#pragma push
#pragma small_data off
void fn_801F224C(void) {
    void *p;
    if ((p = fn_801284F8(8, &lbl_8033A6A0)) != 0) {
        *(void **)p = &lbl_8033A710;
        *(int *)((char *)p + 4) = 0;
    }
}
#pragma pop
int fn_801F2294(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F22D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F2314(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma push
#pragma small_data off
int fn_801F2354(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma push
#pragma small_data off
int fn_801F2394(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F23D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F2414(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F2454(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F2494(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_801F24D4(void *arg0, void *arg1) {
    void *p = arg1;
    while (p != 0) {
        fn_802C7040(*(int *)((char *)p + 4));
        p = *(void **)((char *)p + 0xC);
    }
}

void fn_801F2514(void *arg0, void *arg1) {
    int stack[12];
    fn_801F1C24(&stack[0]);
    fn_802C7730(&stack[0]);
    if (arg1 != 0) {
        fn_801F2570(*(int *)((char *)arg1 + 4));
        fn_802C7040(*(int *)((char *)*(void **)arg1 + 4));
        fn_801F2570(*(int *)((char *)arg1 + 8));
    }
}

void fn_801F2D84(void *unused, void *arg1) {
    extern int fn_801F1C24(void *);
    extern int fn_802C7730(void *);
    int stack[12];
    void *p = arg1;
    fn_801F1C24(&stack[0]);
    fn_802C7730(&stack[0]);
    goto check;
body:
    fn_802C7040(*(int *)((char *)p + 4));
    p = *(void **)((char *)p + 0xC);
check:
    if (p != 0) {
        goto body;
    }
}

void fn_801F2DD4(void *unused, void *arg1) {
    extern int fn_801F1C24(void *);
    extern int fn_802C7730(void *);
    int stack[12];
    void *p = arg1;
    fn_801F1C24(&stack[0]);
    fn_802C7730(&stack[0]);
    goto check;
body:
    fn_802C7040(*(int *)((char *)p + 4));
    p = *(void **)((char *)p + 0xC);
check:
    if (p != 0) {
        goto body;
    }
}

#pragma push
#pragma small_data off
void *__dt__14CollisionSpaceFv_801F2E24(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_8033A958;
        fn_802CAC54(*(void **)((char *)arg0 + 4));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma push
#pragma small_data on
#pragma ppc_psq_save off
void fn_801F2E88(void *arg0, void *arg1) {
    extern float fn_801F3174(void);
    extern void fn_801F3198(void *);
    extern void fn_801F3158(float *,float *);
    extern void fn_801F3124(unsigned int *,unsigned int *);
    extern float lbl_80562F48, lbl_80562F50, lbl_80562F54, lbl_80562F58, lbl_80562F5C, lbl_80562F60, lbl_80562F64;
    extern unsigned short lbl_802F9B20[6];
    extern float *GXInitLightAttnA_80144B44(void *, float, float, float);
    extern unsigned int fn_80144C68(int,int,int,int);
    extern void fn_8001BA68(void *);
    extern void fn_801C0E60(void *,void *,void *);
    extern void fn_80144B54(void *,void *);
    extern int fn_80144DAC();
    extern void fn_801BFD34(void *,void *,void *);
    extern void fn_802C8BD0(int);
    extern void fn_802C8DB8(void *,int,void *,int);
    extern void fn_802C8D74(void);
    unsigned int vertices[4][6];
    float matrix[12];
    unsigned int base[6];
    float t4[3],t3[3],t2[3],t1[3],t0[3];
    unsigned short indices[6];
    float vec[3];
    void *p = arg1;
    while (p != 0) {
        void *camera = fn_802C86DC();
        void *pos;
        int frame;
        float u,v,u1,v1;
        fn_8001BA68(vec);
        pos = (char *)p + 0x20;
        fn_801C0E60(vec,pos,(char *)camera + 0x24);
        fn_801F3198(vec);
        frame = (int)(lbl_80562F50 * (-((float (*)(float,float))fn_801F3174)(vec[0],vec[2]) / lbl_80562F54));
        if (frame < 0) frame += 32;
        u = lbl_80562F58 * (float)(frame % 8);
        v = lbl_80562F5C * (float)(frame / 8);
        u1 = lbl_80562F58 + u;
        v1 = lbl_80562F5C + v;
        fn_801F3158((float *)base,GXInitLightAttnA_80144B44(t0,lbl_80562F40,lbl_80562F40,lbl_80562F40));
        ((float *)base)[4]=u;
        ((float *)base)[5]=v;
        base[3]=fn_80144C68(255,255,255,255);
        fn_801F3124(vertices[0],base);
        fn_801F3124(vertices[1],base);
        fn_801F3124(vertices[2],base);
        fn_801F3124(vertices[3],base);
        indices[0]=lbl_802F9B20[0]; indices[1]=lbl_802F9B20[1];
        indices[2]=lbl_802F9B20[2]; indices[3]=lbl_802F9B20[3];
        indices[4]=lbl_802F9B20[4]; indices[5]=lbl_802F9B20[5];
        ((float *)vertices[3])[4]=u1;
        ((float *)vertices[1])[4]=u1;
        ((float *)vertices[3])[5]=v1;
        ((float *)vertices[2])[5]=v1;
        fn_80144B54(matrix,camera);
        fn_80144DAC(matrix+9,pos);
        fn_801BFD34(vertices[0],GXInitLightAttnA_80144B44(t1,lbl_80562F60,lbl_80562F44,lbl_80562F40),matrix);
        fn_801BFD34(vertices[1],GXInitLightAttnA_80144B44(t2,lbl_80562F64,lbl_80562F44,lbl_80562F40),matrix);
        fn_801BFD34(vertices[2],GXInitLightAttnA_80144B44(t3,lbl_80562F60,lbl_80562F48,lbl_80562F40),matrix);
        fn_801BFD34(vertices[3],GXInitLightAttnA_80144B44(t4,lbl_80562F64,lbl_80562F48,lbl_80562F40),matrix);
        fn_802C8BD0(*(int *)((char *)arg0+4));
        fn_802C8DB8(vertices,4,indices,6);
        fn_802C8D74();
        p=*(void **)((char *)p+12);
    }
}
#pragma pop

#pragma pop
void fn_801F3124(unsigned int *arg0, unsigned int *arg1) {
    unsigned int d, c, b, a;
    float f, e;
    volatile unsigned int *src = (volatile unsigned int *)arg1;
    volatile float *fsrc = (volatile float *)((char *)arg1 + 16);
    a = src[0];
    b = src[1];
    c = src[2];
    d = src[3];
    e = fsrc[0];
    f = fsrc[1];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
    ((float *)arg0)[4] = e;
    ((float *)arg0)[5] = f;
}

void fn_801F3158(float *arg0, float *arg1) {
    float c, b, a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
}

float fn_801F3174(void) {
    return fn_8002EFB0();
}

void fn_801F3198(void *arg0) {
    PSVECNormalize(arg0, arg0);
}

void *fn_801F31A0(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(int *)((char *)arg0 + 0x3C) = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

#pragma unroll off
void fn_801F31E8(int arg0, unsigned char *arg1) {
    unsigned char *p = arg1 + 0x2C;
    int count = 0x20;
    do {
        unsigned char t;
        t = p[0]; p[0] = p[3]; p[3] = t;
        t = p[1]; p[1] = p[2]; p[2] = t;
        t = p[4]; p[4] = p[7]; p[7] = t;
        t = p[5]; p[5] = p[6]; p[6] = t;
        t = p[8]; p[8] = p[11]; p[11] = t;
        t = p[9]; p[9] = p[10]; p[10] = t;
        t = p[12]; p[12] = p[15]; p[15] = t;
        t = p[13]; p[13] = p[14]; p[14] = t;
        p += 0x10;
    } while (--count != 0);
}
#pragma unroll reset
void fn_801F3280(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x3C) = arg1;
}

extern float lbl_80562F64, lbl_80562F70;
extern double cos(double);
extern float fn_801E8738(int);
extern void fn_802C70AC(int, void *, int, int);
void fn_801F3288(void *arg0) {
 float f30,f31; int mask; unsigned int i; void *camera,*planes,*plane;
 *(int *)((char *)arg0+4)=0;
 if (*(void **)((char *)arg0+0x3C)!=0 && *(int *)((char *)arg0+8)!=0) {
 camera=fn_802C86DC(); *(float *)((char *)arg0+0x30)=*(float *)((char *)camera+0x24);
 planes=*(void **)((char *)arg0+0x3C); *(float *)((char *)arg0+0x34)=*(float *)((char *)camera+0x28); planes=(char *)planes+0x2C;
 *(float *)((char *)arg0+0x38)=*(float *)((char *)camera+0x2C);
 if (*(int *)((char *)arg0+8)==1) { mask=1;i=0; f30=lbl_80562F64*(lbl_80562F70*fn_801E8738(-1));plane=planes;
 do { f31=PSVECDotProduct((float *)((char *)camera+0x18),(float *)planes);
 if(f31>cos(f30+*(float *)((char *)plane+0xC))){mask|=1<<i;*(int *)((char *)arg0+4)=*(int *)((char *)arg0+4)+1;}
 i++;planes=(char *)planes+0x10;plane=(char *)plane+0x10;}while(i<0x20);
 } else {*(int *)((char *)arg0+4)=0x20;mask=-1;}
 fn_802C70AC(*(int *)((char *)*(void **)((char *)arg0+0x3C)+4),(char *)arg0+0xC,-1,mask);
 }
}

void fn_801F33BC(void *unused, int arg1) {
    extern int *fn_801F1CE8(int);
    unsigned char *p = (unsigned char *)fn_801F1CE8(arg1);
    unsigned char t;
    t = p[0]; p[0] = p[3]; p[3] = t;
    t = p[1]; p[1] = p[2]; p[2] = t;
    t = p[4]; p[4] = p[7]; p[7] = t;
    t = p[5]; p[5] = p[6]; p[6] = t;
    t = p[8]; p[8] = p[11]; p[11] = t;
    t = p[9]; p[9] = p[10]; p[10] = t;
    t = p[12]; p[12] = p[15]; p[15] = t;
    t = p[13]; p[13] = p[14]; p[14] = t;
}

#pragma small_data off
__declspec(section ".data") extern int lbl_8033A8F8;
void *__dt__Q28PSSystem7SeqHeapFv_801F3460(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_8033A8F8;
        fn_802C9994(-1, &lbl_8033A8F8);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma small_data on
void fn_801F34C4(void *arg0, int arg1) {
    extern int *fn_801F1CE8(int);
    int *p = fn_801F1CE8(arg1);
    *(int *)((char *)arg0 + 0x10) = p[0];
    *(float *)((char *)arg0 + 4) = ((float *)p)[1];
    *(float *)((char *)arg0 + 8) = ((float *)p)[2];
    *(float *)((char *)arg0 + 0xC) = ((float *)p)[3];
}

#pragma pop
void fn_801F371C(int arg0) {
    fn_8029231C(arg0 + 4);
}

int fn_801F3724(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern int *fn_801F1CE8(int);
extern int fn_80128668(void);
extern int *fn_801E1F44(void);
extern int fn_802C9950(int);
void fn_801F3764(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 8) = *fn_801F1CE8(arg1);
    *(char *)((char *)arg0 + 4) = 1;
}

void fn_801F37A4(void) {
    if (*fn_801E1F44() == 1) {
        fn_802C9950(0xFF646464);
        return;
    }
    fn_802C9950(0xFF909090);
}

#pragma scheduling invalid_target
void fn_801F37EC(void) {
    fn_802E317C(lbl_8033ABA0);
}
int fn_801F37FC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_801F383C(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 8) = *fn_801F1CE8(arg1);
    *(char *)((char *)arg0 + 4) = 1;
}

void fn_801F387C(void *unused, int arg1) {
    extern int *fn_801F1CE8(int);
    unsigned char *p = (unsigned char *)fn_801F1CE8(arg1);
    unsigned char t;
    t = p[0]; p[0] = p[3]; p[3] = t;
    t = p[1]; p[1] = p[2]; p[2] = t;
    t = p[4]; p[4] = p[7]; p[7] = t;
    t = p[5]; p[5] = p[6]; p[6] = t;
    t = p[8]; p[8] = p[11]; p[11] = t;
    t = p[9]; p[9] = p[10]; p[10] = t;
    t = p[12]; p[12] = p[15]; p[15] = t;
    t = p[13]; p[13] = p[14]; p[14] = t;
}

void fn_801F3920(void *arg0) {
    extern int fn_80297990(int);
    if (*(unsigned char *)((char *)arg0 + 4) != 0) {
        fn_80297990(*(int *)((char *)arg0 + 8));
    } else {
        fn_80297990(0x80000000);
    }
}

#pragma scheduling invalid_target
void fn_801F393C(void) {
    fn_802E317C(lbl_8033AB80);
}

int fn_801F394C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_801F398C(void *unused, int arg1) {
    extern int *fn_801F1CE8(int);
    unsigned char *p = (unsigned char *)fn_801F1CE8(arg1);
    unsigned char t;
    t = p[0]; p[0] = p[3]; p[3] = t;
    t = p[1]; p[1] = p[2]; p[2] = t;
    t = p[4]; p[4] = p[7]; p[7] = t;
    t = p[5]; p[5] = p[6]; p[6] = t;
    t = p[8]; p[8] = p[11]; p[11] = t;
    t = p[9]; p[9] = p[10]; p[10] = t;
    t = p[12]; p[12] = p[15]; p[15] = t;
    t = p[13]; p[13] = p[14]; p[14] = t;
}

void fn_801F3A30(void *arg0, int arg1) {
    extern int *fn_801F1CE8(int);
    extern float lbl_80562F90;
    float value;
    value = (float)(unsigned char)*fn_801F1CE8(arg1);
    *(unsigned char *)((char *)arg0 + 4) = 1;
    *(float *)((char *)arg0 + 8) = value / lbl_80562F90;
}

float fn_801F3A94(void *arg0) {
    extern float fn_802923EC(float);
    if (*(unsigned char *)((char *)arg0 + 4) != 0) {
        return fn_802923EC(*(float *)((char *)arg0 + 8));
    }
    return fn_802923EC(lbl_80562F44);
}

#pragma scheduling invalid_target
extern const char lbl_8033AB5C[];
int fn_801F3AB0(void) {
    return fn_802E317C(lbl_8033AB5C);
}

int fn_801F3AC0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801F3B00(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 8) = *fn_801F1CE8(arg1);
    *(char *)((char *)arg0 + 4) = 1;
}

void fn_801F3B40(void *unused, int arg1) {
    extern int *fn_801F1CE8(int);
    unsigned char *p = (unsigned char *)fn_801F1CE8(arg1);
    unsigned char t;
    t = p[0]; p[0] = p[3]; p[3] = t;
    t = p[1]; p[1] = p[2]; p[2] = t;
    t = p[4]; p[4] = p[7]; p[7] = t;
    t = p[5]; p[5] = p[6]; p[6] = t;
    t = p[8]; p[8] = p[11]; p[11] = t;
    t = p[9]; p[9] = p[10]; p[10] = t;
    t = p[12]; p[12] = p[15]; p[15] = t;
    t = p[13]; p[13] = p[14]; p[14] = t;
}

void fn_801F3BE4(void *arg0) {
    extern void fn_802C990C(int);
    if (*(unsigned char *)((char *)arg0 + 4) != 0) {
        fn_802C990C(*(int *)((char *)arg0 + 8));
    } else {
        fn_802C990C(0x00C9C9EB);
    }
}

#pragma scheduling invalid_target
void fn_801F3C04(void) {
    fn_802E317C(lbl_8033AB3C);
}

void fn_801F3C14(int unused, unsigned char *arg0) {
    unsigned char *p = arg0 + 0x18;
    int i;
    for (i=0; i<3; i++, p+=0xC) {
        unsigned char t;
        t=p[0]; p[0]=p[3]; p[3]=t;
        t=p[1]; p[1]=p[2]; p[2]=t;
        t=p[4]; p[4]=p[7]; p[7]=t;
        t=p[5]; p[5]=p[6]; p[6]=t;
        t=p[8]; p[8]=p[0xB]; p[0xB]=t;
        t=p[9]; p[9]=p[0xA]; p[0xA]=t;
    }
    {
        unsigned char t=arg0[0x14];
        unsigned char u=arg0[0x15];
        arg0[0x14]=arg0[0x17]; arg0[0x17]=t;
        arg0[0x15]=arg0[0x16]; arg0[0x16]=u;
    }
}

#pragma push
#pragma processor 750
void fn_801F3CAC(void *arg0, void *arg1) {
    extern float fn_801E7E18(void);
    extern void fn_80144DC8(void *);
    extern void fn_80015EB0(void *, float);
    extern void fn_80015B20(void *, void *, void *);
    extern void fn_802C744C(int, void *);
    struct Buffers {
        char sp8[0x24];
        float sp2c[3];
    } buffers;
    void *node;
    float value;
    node = arg1;
    while (node != 0) {
        value = *(float *)((char *)node + 0x30) * fn_801E7E18();
        fn_80144DC8(buffers.sp8);
        fn_80015EB0(buffers.sp8, value);
        fn_80015B20(buffers.sp8, buffers.sp8, (char *)node + 0x34);
        fn_80144DAC(buffers.sp2c, (float *)((char *)node + 0x20));
        fn_802C744C(*(int *)((char *)node + 4), buffers.sp8);
        node = *(void **)((char *)node + 0xC);
    }
}
#pragma pop
extern int lbl_8033AA90, lbl_8033AA18, lbl_8033AA24;
extern void fn_801F3E60(void);
#pragma pop
extern int lbl_8055B158;
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, int, int, int);
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_8033AA90, lbl_8033AA18, lbl_8033AA24;
#pragma push
#pragma small_data off
#pragma pop
#pragma scheduling invalid_target
void fn_801F3D34(void *arg0, void *arg1, void *arg2) {
    float temp_f31;
    int temp_r30;
    void *temp_r31;
    void *temp_r3;

    if (*(void **)((char *)arg0 + 4) == 0) {
        temp_r31 = fn_801284F8(0xC, &lbl_8055B158);
        if (temp_r31 != 0) {
            *(void **)temp_r31 = &lbl_8033AA90;
            temp_r3 = fn_8012850C(0x190, &lbl_8033AA18);
            *(void **)((char *)temp_r31 + 4) =
                fn_8002F37C(temp_r3, fn_801F3E60, 0, 0x18, 0x10);
            *(int *)((char *)temp_r31 + 8) = 0;
        }
        *(void **)((char *)arg0 + 4) = temp_r31;
        fn_802CD320((int)arg1, temp_r31);
    }
    temp_r31 = *(void **)((char *)arg0 + 4);
    temp_f31 = *(float *)((char *)arg2 + 0x30);
    temp_r30 = *(int *)((char *)arg2 + 0x2C);
    if (*(int *)((char *)temp_r31 + 8) >= 0x10) {
        fn_802E317C((const void *)&lbl_8033AA24);
    }
    temp_r3 = *(void **)((char *)temp_r31 + 4);
    temp_r3 = (char *)temp_r3 + *(int *)((char *)temp_r31 + 8) * 0x18;
    *(int *)temp_r3 = temp_r30;
    *(float *)((char *)temp_r3 + 4) = *(float *)((char *)arg2 + 0x20);
    *(float *)((char *)temp_r3 + 8) = *(float *)((char *)arg2 + 0x24);
    *(float *)((char *)temp_r3 + 0xC) = *(float *)((char *)arg2 + 0x28);
    *(void **)((char *)temp_r3 + 0x10) = (char *)arg2 + 0x34;
    *(float *)((char *)temp_r3 + 0x14) = temp_f31;
    (*(int *)((char *)temp_r31 + 8))++;
}
#pragma scheduling on
void fn_801F3E60(void) {

}

void fn_801F3E64(void) {

}

#pragma push
#pragma small_data off
#pragma pop
void fn_801F3E68(int arg0, unsigned char *arg1) {
    unsigned char temp_r6 = arg1[0x2C];
    unsigned char temp_r7 = arg1[0x2D];
    arg1[0x2C] = arg1[0x2F];
    arg1[0x2F] = temp_r6;
    arg1[0x2D] = arg1[0x2E];
    arg1[0x2E] = temp_r7;
    *(unsigned int *)(arg1 + 0x2C) = 1 << (*(unsigned int *)(arg1 + 0x2C) - 1);
}
void fn_801F3EA0(void) {

}

#pragma push
#pragma small_data off
#pragma pop
void fn_801F3EA4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    fn_802CD33C(arg2, arg3, 0);
    fn_802CD33C(arg4, arg5, 0);
}
extern int fn_802CD33C(int, int, int);
extern int lbl_8033A7A0_arr[];
void *fn_801F3EF8(void *arg0, int arg1) {
    extern int lbl_8033A7A0[];
    if (arg0 != 0) {
        *(void * volatile *)arg0 = (void *)&lbl_8033A7A0[0];
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}
void fn_801F3F44(int arg0, volatile unsigned char *arg1) {
    unsigned char t;
    t=arg1[0x2C]; arg1[0x2C]=arg1[0x2F]; arg1[0x2F]=t;
    t=arg1[0x2D]; arg1[0x2D]=arg1[0x2E]; arg1[0x2E]=t;
    t=arg1[0x30]; arg1[0x30]=arg1[0x33]; arg1[0x33]=t;
    t=arg1[0x31]; arg1[0x31]=arg1[0x32]; arg1[0x32]=t;
}
void fn_801F3F88(void) {

}

extern float fn_802C88D4(void *);
extern int fn_802C9900(float);
extern int fn_802C9904(void);
#pragma push
#pragma processor 750
void fn_801F3F8C(void *arg0, void *arg1) {
    float lower = lbl_80562F40;
    float upper = lbl_80562F44;
    void *node;
    do {
        int index = *(int *)((char *)arg1 + 0x14);
        if (index >= 0 && index < 0x30) {
            char *entry = *(char **)((char *)arg0 + 4) + index * 0x18;
            float value = fn_802C88D4(entry);
            float threshold = *(float *)(entry + 0x14);
            if (value > threshold) {
                float amount = *(float *)(entry + 0x10) * (value - threshold);
                if (amount < upper) amount = upper;
                if (amount > lower) amount = lower;
                fn_802C9900(amount);
                fn_802C7040(*(int *)(entry + 0xC));
                fn_802C9904();
            }
        }
        node = *(void **)((char *)arg1 + 0xC);
        arg1 = node;
    } while (node != 0);
}

void fn_801F405C(void *arg0, void *arg1, void *arg2, int arg3) {
    extern void *fn_801284F8(int, void *);
    extern int fn_802CD320(int, void *);
    extern int fn_802E317C(const void *, ...);
    extern void fn_802C77F0(int, float *);
    extern const char lbl_8033AB0C[], lbl_8033AB18[];
    extern int lbl_8033AA78;
    extern float lbl_80562F44, lbl_80562F64;
    void *pool = *(void **)((char *)arg0 + 8);
    int count;
    void *entry;
    float v[8];
    if (pool == 0) {
        pool = fn_801284F8(0x548, (void *)lbl_8033AB0C);
        if (pool != 0) {
            *(int **)pool = &lbl_8033AA78;
            *(int *)((char *)pool + 0x544) = 0;
        }
        *(void **)((char *)arg0 + 8) = pool;
        fn_802CD320((int)arg1, pool);
    }
    count = *(int *)((char *)pool + 0x544);
    if (count >= 0x30) fn_802E317C(lbl_8033AB18);
    entry = (char *)pool + count * 0x1c;
    fn_802C77F0(*(int *)((char *)arg2 + 4), v);
    *(float *)((char *)entry + 4) = *(float *)((char *)arg2 + 0x20) + (v[0] + (v[1] - v[0]) * lbl_80562F64);
    *(float *)((char *)entry + 8) = *(float *)((char *)arg2 + 0x24) + (v[2] + (v[3] - v[2]) * lbl_80562F64);
    *(float *)((char *)entry + 0xc) = *(float *)((char *)arg2 + 0x28) + (v[4] + (v[5] - v[4]) * lbl_80562F64);
    *(int *)((char *)entry + 0x10) = *(int *)((char *)arg2 + 4);
    *(float *)((char *)entry + 0x14) = lbl_80562F44 / (*(float *)((char *)arg2 + 0x2c) - *(float *)((char *)arg2 + 0x30));
    *(float *)((char *)entry + 0x18) = *(float *)((char *)arg2 + 0x30);
    *(int *)((char *)entry + 0x1c) = arg3;
    *(int *)((char *)pool + 0x544) = count + 1;
}

#pragma pop
void fn_801F41CC(int unused, volatile unsigned char *arg0) {
    unsigned char t;
    t = arg0[0x2c]; arg0[0x2c] = arg0[0x2f]; arg0[0x2f] = t;
    t = arg0[0x2d]; arg0[0x2d] = arg0[0x2e]; arg0[0x2e] = t;
    t = arg0[0x30]; arg0[0x30] = arg0[0x33]; arg0[0x33] = t;
    t = arg0[0x31]; arg0[0x31] = arg0[0x32]; arg0[0x32] = t;
    t = arg0[0x34]; arg0[0x34] = arg0[0x37]; arg0[0x37] = t;
    t = arg0[0x35]; arg0[0x35] = arg0[0x36]; arg0[0x36] = t;
    t = arg0[0x38]; arg0[0x38] = arg0[0x3b]; arg0[0x3b] = t;
    t = arg0[0x39]; arg0[0x39] = arg0[0x3a]; arg0[0x3a] = t;
    t = arg0[0x3c]; arg0[0x3c] = arg0[0x3f]; arg0[0x3f] = t;
    t = arg0[0x3d]; arg0[0x3d] = arg0[0x3e]; arg0[0x3e] = t;
}

#pragma scheduling invalid_target
void fn_801F4270(void) {
    fn_802E317C(lbl_8033AAE0);
}

void fn_801F4280(void) {

}

void fn_801F4284(void *unused, void *arg1) {
    extern unsigned char lbl_8033AAB8[];
    volatile unsigned char *p;
    int i;
    fn_802E317C(lbl_8033AAB8);
    p = (volatile unsigned char *)arg1 + 0x2C;
    for (i = 0; i < 3; i++, p += 12) {
        unsigned char t;
        t = p[0]; p[0] = p[3]; p[3] = t;
        t = p[1]; p[1] = p[2]; p[2] = t;
        t = p[4]; p[4] = p[7]; p[7] = t;
        t = p[5]; p[5] = p[6]; p[6] = t;
        t = p[8]; p[8] = p[11]; p[11] = t;
        t = p[9]; p[9] = p[10]; p[10] = t;
    }
}

void fn_801F4330(void) {

}

extern int fn_802C7040(int);
extern int fn_802CD320(int, void *);
extern unsigned char lbl_8033AAB8[];
extern unsigned char lbl_8033AA48[];
extern unsigned char lbl_8055B140[];
int fn_801F4334(int a, int b) { if (a != 0 && b > 0) fn_80128668(); return a; }

void fn_801F4374(void) {

}

extern void *fn_802AE414(void *);
extern int lbl_8033AAA8, lbl_8033AA60, lbl_8055B150, lbl_8055B148;
#pragma small_data off
extern int lbl_8033AAA8, lbl_8033AA60;
#pragma small_data on
extern int lbl_8055B150, lbl_8055B148;
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_8033AAA8, lbl_8033AA60;
#pragma push
#pragma small_data off
#pragma pop
#pragma cplusplus on
extern "C" void fn_801F4378(void *arg0, int arg1, void *arg2, int arg3, int arg4) {
    struct Dummy {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual float get(int) = 0;
    };
    void *path;
    void *obj;
    void *entry;
    void *item;
    float f;
    int count;
    int value;

    obj = *(void **)((char *)arg0 + 4);
    path = (char *)arg2 + 0x2C;
    if (obj == 0) {
        obj = fn_801284F8(0x108, (void *)&lbl_8033AAA8);
        if (obj != 0) {
            *(void **)obj = (void *)&lbl_8033AA60;
            *(int *)((char *)obj + 0x104) = 0;
            *(void **)((char *)arg0 + 4) = obj;
            fn_802CD320(arg1, obj);
        }
    }
    obj = *(void **)((char *)arg0 + 4);
    value = *(int *)((char *)arg2 + 4);
    count = *(int *)((char *)obj + 0x104);
    f = lbl_80562F40;
    entry = (char *)obj + (count << 4);
    *(int *)((char *)entry + 4) = value;
    *(int *)((char *)entry + 8) = arg3;
    *(float *)((char *)entry + 0xC) = f;
    *(float *)((char *)entry + 0x10) = f;
    item = fn_802AE414(path);
    if (item != 0) {
        *(float *)((char *)entry + 0xC) = ((Dummy *)item)->get((int)&lbl_8055B150);
        *(float *)((char *)entry + 0x10) = ((Dummy *)item)->get((int)&lbl_8055B148);
    }
    count = *(int *)((char *)obj + 0x104);
    *(int *)((char *)obj + 0x104) = count + 1;
}
#pragma cplusplus reset
void fn_801F447C(void) {

}

void fn_801F4480(int unused, void *arg1) {
    int v;
    void *p = arg1;
    goto check;
loop:
    v = *(int *)((char *)p + 4);
    if (fn_801F1CF0((int)((char *)p + 0x2C))) fn_802C7040(v);
    p = *(void **)((char *)p + 12);
check:
    if (p != 0) goto loop;
}

#pragma scheduling invalid_target
void fn_801F44DC(int arg1, int arg2, int arg3) {
    int v = arg2 + 0x2C;
    void *p = fn_801284F8(0xC, (void *)lbl_8055B140);
    if (p != 0) {
        *(void **)p = (void *)lbl_8033AA48;
        *(int *)((char *)p + 4) = v;
        *(int *)((char *)p + 8) = arg3;
    }
    fn_802CD320(arg1, p);
}
void fn_801F4550(void) {

}

int fn_801F4554(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F4594(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801F45D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma push
#pragma small_data off
void *fn_801F4614(void *arg0, int arg1) {
    extern int fn_80128670(int);
    int temp_r5;
    if (arg0 != 0) {
        temp_r5 = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = &lbl_8033AA90;
        if (temp_r5 != 0) fn_80128670(temp_r5 - 0x10);
        if (arg1 > 0) ((int (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

extern double sin(double);
extern float fn_80144514(float, float, float, float, float, float);
extern void fn_802CDAB4(int, int, float *);
void fn_801F4684(void *arg0, int arg1) {
    int count = *(int *)((char *)arg0 + 8);
    int i = 0;
    int offset = 0;
    if (count > 0) {
        float zero = lbl_80562F40;
        float one = lbl_80562F44;
        do {
            char *entry = *(char **)((char *)arg0 + 4) + offset;
            float angle = *(float *)(entry + 0x14) * fn_801E7E18();
            float c = (float)cos(angle);
            float s = (float)sin(angle);
            float transform[12];
            float *matrix;
            transform[0] = c; transform[1] = zero; transform[2] = -s;
            transform[3] = zero; transform[4] = one; transform[5] = zero;
            transform[6] = s; transform[7] = zero; transform[8] = c;
            matrix = *(float **)(entry + 0x10);
            if (&transform[0] == &transform[0] || &transform[0] == matrix) {
                float v0 = fn_80144514(matrix[0], transform[0], matrix[3], transform[1], matrix[6], transform[2]);
                float v1 = fn_80144514(matrix[0], transform[3], matrix[3], transform[4], matrix[6], transform[5]);
                float v2 = fn_80144514(matrix[0], transform[6], matrix[3], transform[7], matrix[6], transform[8]);
                float v3 = fn_80144514(matrix[1], transform[0], matrix[4], transform[1], matrix[7], transform[2]);
                float v4 = fn_80144514(matrix[1], transform[3], matrix[4], transform[4], matrix[7], transform[5]);
                float v5 = fn_80144514(matrix[1], transform[6], matrix[4], transform[7], matrix[7], transform[8]);
                float v6 = fn_80144514(matrix[2], transform[0], matrix[5], transform[1], matrix[8], transform[2]);
                float v7 = fn_80144514(matrix[2], transform[3], matrix[5], transform[4], matrix[8], transform[5]);
                float v8 = fn_80144514(matrix[2], transform[6], matrix[5], transform[7], matrix[8], transform[8]);
                transform[0]=v0; transform[3]=v1; transform[6]=v2;
                transform[1]=v3; transform[4]=v4; transform[7]=v5;
                transform[2]=v6; transform[5]=v7; transform[8]=v8;
            } else {
                transform[0] = fn_80144514(matrix[0], transform[0], matrix[3], transform[1], matrix[6], transform[2]);
                transform[3] = fn_80144514(matrix[0], transform[3], matrix[3], transform[4], matrix[6], transform[5]);
                transform[6] = fn_80144514(matrix[0], transform[6], matrix[3], transform[7], matrix[6], transform[8]);
                transform[1] = fn_80144514(matrix[1], transform[0], matrix[4], transform[1], matrix[7], transform[2]);
                transform[4] = fn_80144514(matrix[1], transform[3], matrix[4], transform[4], matrix[7], transform[5]);
                transform[7] = fn_80144514(matrix[1], transform[6], matrix[4], transform[7], matrix[7], transform[8]);
                transform[2] = fn_80144514(matrix[2], transform[0], matrix[5], transform[1], matrix[8], transform[2]);
                transform[5] = fn_80144514(matrix[2], transform[3], matrix[5], transform[4], matrix[8], transform[5]);
                transform[8] = fn_80144514(matrix[2], transform[6], matrix[5], transform[7], matrix[8], transform[8]);
            }
            transform[9] = *(float *)(entry + 4);
            transform[10] = *(float *)(entry + 8);
            transform[11] = *(float *)(entry + 0xC);
            fn_802CDAB4(arg1, *(int *)entry, transform);
            offset += 0x18;
            i++;
        } while (i < count);
    }
}

#pragma pop
void fn_801F49F4(void) {

}

void fn_801F49F8(void *arg0, int arg1) {
    void *selected[0x60];
    char *entry;
    char *next;
    int count;
    int i;
    int j;
    float value;
    float maximum;
    float minimum;
    entry = (char *)arg0;
    next = (char *)arg0 + 4;
    count = 0;
    i = 0;
    j = 0;
    while (j < *(int *)((char *)arg0 + 0x544)) {
        if (fn_802CDB20(arg1, *(int *)(entry + 0x1C)) != 0) {
            selected[i] = next;
            count++;
            i++;
        }
        entry += 0x1C;
        next += 0x1C;
        j++;
    }
    maximum = lbl_80562F44;
    minimum = lbl_80562F40;
    for (j = 0; j < count; j++) {
        void *item = selected[j];
        value = fn_802C88D4(item);
        if (value > *(float *)((char *)item + 0x14)) {
            value = *(float *)((char *)item + 0x10) * (value - *(float *)((char *)item + 0x14));
            if (value > maximum) value = maximum;
            if (value < minimum) value = minimum;
            fn_802C9900(value);
            fn_802C7040(*(int *)((char *)item + 0xC));
            fn_802C9904();
        }
    }
}

int fn_801F4B04(void) { return 4; }

int fn_801F4B0C(void) { return 3; }

void fn_801F4B14(void) {

}

extern int fn_801F1CF0(int);
extern int fn_802CDAFC(int, int);
extern int fn_802CDB20(int, int);
void fn_801F4C34(void *arg0, int arg1) {
    int *p = (int *)arg0;
    if (fn_802CDB20(arg1, p[2]) != 0 && fn_801F1CF0(p[1]) == 0) {
        fn_802CDAFC(arg1, p[2]);
    }
}

int fn_801F4C98(void) { return -1; }

void fn_801F4CA0(void) {

}
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern int fn_802C7040(int);

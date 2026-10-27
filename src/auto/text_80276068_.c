// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern volatile int lbl_8055F598, lbl_8055F59C, lbl_8055F5A0;
__declspec(section ".data") extern unsigned char lbl_8049FD58[];
extern float lbl_8055E3C8, lbl_80564054, lbl_80564060;
extern float lbl_8049FD58_float_dummy;
extern void *fn_80276A44(void);
extern void fn_8026A4A0(int, void *, float *);
extern void fn_80276098(void *, void *, float, float, float, int, int);
extern void *memcpy(void *, const void *, unsigned int);
int fn_80276068(int arg0) {
    unsigned int shift = arg0 - 4;
    int result = 0;
    if (shift > 0x13)
        return result;
    if (((1U << shift) & 0x80027) != 0)
        result = 1;
    return result;
}

extern float lbl_80558DC4, lbl_80564048, lbl_8056404C, lbl_80564050;
extern float fn_8002F234(float);
extern float PSVECSquareDistance(void *, void *);
extern float lbl_80558DC4, lbl_80564048, lbl_8056404C, lbl_80564050, lbl_8055E3C8;
extern float fn_8002F234(float), PSVECSquareDistance(void *, void *), fabsf(float);
void fn_80276098(void *arg0, void *arg1, float arg2, float arg3, float arg4, int arg5, int arg6) {
    float *a=(float*)arg0, *b=(float*)arg1, *out;
    unsigned char *entry;
    float trace, root, inv;
    int i,j,k;
    if ((float)fabsf(arg2-arg3) != lbl_80558DC4 ||
        (float)fabsf(PSVECSquareDistance((char*)arg0+0x24,(char*)arg1+0x24)) != lbl_80558DC4 ||
        (float)fabsf(PSVECSquareDistance(arg0,arg1)) != lbl_80558DC4 ||
        (float)fabsf(PSVECSquareDistance((char*)arg0+0xC,(char*)arg1+0xC)) != lbl_80558DC4 ||
        (float)fabsf(PSVECSquareDistance((char*)arg0+0x18,(char*)arg1+0x18)) != lbl_80558DC4) {
    } else return;
    entry=(unsigned char *)&lbl_8049FD58+arg5*0x50; out=(float*)(entry+4);
    trace=a[0]+a[4]+a[8]; *(float*)(entry+0x44)=arg4; *(float*)(entry+0x48)=lbl_8055E3C8;
    if(trace>lbl_80564048){root=fn_8002F234(lbl_8056404C+trace);inv=lbl_80564050/root;out[0]=lbl_80564050*root;out[1]=inv*(a[5]-a[7]);out[2]=inv*(a[6]-a[2]);out[3]=inv*(a[1]-a[3]);}
    else{i=0;if(a[4]>a[0])i=1;if(a[8]>a[i*3+i])i=2;j=(i+1)%3;k=(j+1)%3;root=fn_8002F234(lbl_8056404C+(a[i*3+i]-(a[j*3+k]+a[k*3+j])));inv=lbl_80564050/root;out[i]=lbl_80564050*root;out[3]=inv*(a[j*3+k]-a[k*3+j]);out[j]=inv*(a[i*3+j]+a[j*3+i]);out[k]=inv*(a[i*3+k]+a[k*3+i]);}
    *(float*)(entry+0x24)=a[9];*(float*)(entry+0x28)=a[10];*(float*)(entry+0x2C)=a[11];*(float*)(entry+0x3C)=arg2;
    trace=b[0]+b[4]+b[8];
    if(trace>lbl_80564048){root=fn_8002F234(lbl_8056404C+trace);inv=lbl_80564050/root;out[4]=lbl_80564050*root;out[5]=inv*(b[5]-b[7]);out[6]=inv*(b[6]-b[2]);out[7]=inv*(b[1]-b[3]);}
    else{i=0;if(b[4]>b[0])i=1;if(b[8]>b[i*3+i])i=2;j=(i+1)%3;k=(j+1)%3;root=fn_8002F234(lbl_8056404C+(b[i*3+i]-(b[j*3+k]+b[k*3+j])));inv=lbl_80564050/root;out[4+i]=lbl_80564050*root;out[7]=inv*(b[j*3+k]-b[k*3+j]);out[4+j]=inv*(b[i*3+j]+b[j*3+i]);out[4+k]=inv*(b[i*3+k]+b[k*3+i]);}
    *(float*)(entry+0x30)=b[9];*(float*)(entry+0x34)=b[10];*(float*)(entry+0x38)=b[11];*(float*)(entry+0x40)=arg3;*(int*)(entry+0x4C)=arg6;*entry=1;
}

unsigned int fn_8027656C(void *arg0, void *arg1, unsigned int arg2) { return 0; }

__declspec(section ".data") extern unsigned char lbl_8049FEE0;
extern char lbl_8055C638, lbl_8055C63C, lbl_8055C644;
extern void fn_80277F84(void *, void *, int);
extern int stricmp(const char *, const char *);
extern char *strncpy(char *, const char *, unsigned int);
void fn_80276ACC(void *arg0, int arg1) {
    struct NameVtable {
        void *reserved[6];
        char *(*GetName)(void *, const char *, int);
    };
    char *name = ((struct NameVtable *)*(void **)arg0)->GetName(
        arg0, &lbl_8055C63C, arg1);
    int i = lbl_8055F5A0;
    unsigned char *entry = &lbl_8049FEE0 + i * 0x48;
    lbl_8055F5A0 = i + 1;
    fn_80277F84(entry, arg0, i + 1);
    strncpy((char *)(entry + 0x38), name, 0x10);
    if (stricmp(name, &lbl_8055C644) == 0) {
        lbl_8055F59C = (int)entry;
        return;
    }
    if (stricmp(name, *(char **)&lbl_8055C638) == 0)
        lbl_8055F598 = (int)entry;
}

#pragma scheduling invalid_target
void fn_80276B8C(void) {
    unsigned char *entry = lbl_8049FD58;
    int i = 0;
    do {
        memset(entry, 0, 0x50);
        i++;
        entry += 0x50;
    } while (i < 4);
}
#pragma scheduling on
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

struct TruckState {
    int unk_00;
    int unk_04;
    float unk_08;
    float unk_0C;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28[12];
    int unk_58[24];
    int unk_B8;
    float unk_BC;
    int unk_C0[27];
    int unk_12C[3];
    unsigned char unk_138;
    unsigned char unk_139;
    unsigned char pad_13A[2];
    float unk_13C;
    void *unk_140;
    int unk_144;
    int unk_148;
    int unk_14C;
    int unk_150;
    float unk_154;
    float unk_158;
    float unk_15C;
    int unk_160[10];
    unsigned char unk_188;
    unsigned char pad_189[3];
    float unk_18C[6];
    int unk_1A4[12];
    float unk_1D4;
    int unk_1D8[5];
    short unk_1EC;
    short pad_1EE;
    int unk_1F0[14];
};

typedef struct Vec {
    float x, y, z;
} Vec;

extern void *fn_802678E4(int);
extern float fn_802704E0(int, float);
extern void PSVECCrossProduct(void *, void *, void *);
extern void PSVECNormalize(void *, void *);
extern void fn_801E9DC4(void *);
extern float PSVECMag(void *);
extern double sin(double);
extern double cos(double);
extern void fn_801BFD34(void *, void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern void fn_801C7254(void *);
extern void fn_80144CD0(void *, void *, void *);
extern float lbl_802FA818[];
extern float lbl_80564064, lbl_80564068, lbl_8056406C;
  u32 fn_8027656C(void *, void *, u32);
  extern u8 lbl_8049FE98[];
void fn_80276BE4(u32 *arg0, f32 *arg1) {
    u32 *src;
    if (*(unsigned char *)&lbl_8049FD58 != 0) {
        fn_8027656C(lbl_8049FE98 + 4, lbl_8049FE98 + 0x34, 0);
    }
    src = (u32 *)(lbl_8049FE98 + 4);
    arg0[0] = src[0]; arg0[1] = src[1];
    arg0[2] = src[2]; arg0[3] = src[3];
    arg0[4] = src[4]; arg0[5] = src[5];
    arg0[6] = src[6]; arg0[7] = src[7];
    arg0[8] = src[8]; arg0[9] = src[9];
    arg0[10] = src[10]; arg0[11] = src[11];
    *arg1 = *(f32 *)(lbl_8049FE98 + 0x34);
}

void fn_80276CB0(void *arg0, int arg1) {
    unsigned char *p;

    p = (unsigned char *)fn_80276A44();
    if (p == 0)
        p = (unsigned char *)lbl_8055F598;
    if (arg1 != 0) {
        fn_80276098(lbl_8049FE98 + 4, p + 4,
                    *(float *)(lbl_8049FE98 + 0x34), *(float *)(p + 0x34),
                    lbl_8056404C, 0, 0x22);
    } else {
        memcpy(lbl_8049FE98, p, 0x48);
        *(unsigned char *)&lbl_8049FD58 = 0;
    }
}

void fn_80276D3C(int unused, int arg) {
    unsigned char sp10[0x38];
    float sp8;
    unsigned char *p = (unsigned char *)fn_80276A44();
    if (arg == 1) {
        fn_8026A4A0(0, sp10, &sp8);
        fn_80276098(sp10, p + 4, sp8, *(float *)(p + 0x34), lbl_80564060, 0, 0x22);
    } else {
        memcpy(lbl_8049FE98, p, 0x48);
        *(unsigned char *)&lbl_8049FD58 = 0;
    }
}

void fn_80276DC8(int arg0) {
    struct TruckState *dst;
    struct TruckState *src;
    Vec v[4];
    Vec v_right, v_up, v_fwd, v_pos;
    Vec input, axis;
    float rot[3][3];
    float trans[3][3];
    void *target;
    float mag;

    src = (struct TruckState *)fn_802678E4(arg0);
    dst = (struct TruckState *)((char *)&lbl_8049FD58 + 0xF08) + arg0;
    *dst = *src;
    ((float *)((char *)&lbl_8049FD58 + 0x1868))[arg0] = lbl_80564048;

    v[0] = *(Vec *)((char *)dst + 0x58);
    v[1] = *(Vec *)((char *)dst + 0x64);
    v[2] = *(Vec *)((char *)dst + 0x70);
    v[3] = *(Vec *)((char *)dst + 0x7C);

    if (fn_80276068(dst->unk_14) == 0 || *(int *)((char *)src->unk_140 + 0x24) == 0) {
        float t;
        float *dir, *pos;
        dst->unk_14 = 4;
        t = fn_802704E0(4, lbl_80564048);
        dir = (float *)((char *)dst + 0xD8);
        pos = (float *)((char *)dst + 0xE4);
        v[3].x = pos[0] + dir[0] * t;
        v[3].y = pos[1] + dir[1] * t;
        v[3].z = pos[2] + dir[2] * t;
        v[2] = *(Vec *)dir;
        v[1].x = lbl_80564048;
        v[1].y = lbl_8056404C;
        v[1].z = lbl_80564048;
        PSVECCrossProduct(&v[1], &v[2], &v[0]);
        PSVECNormalize(&v[0], &v[0]);
        PSVECCrossProduct(&v[2], &v[0], &v[1]);
        PSVECNormalize(&v[1], &v[1]);
    }

    v_right = *(Vec *)((char *)dst + 0xC0);
    v_up.x = lbl_80564048;
    v_up.y = lbl_8056404C;
    v_up.z = lbl_80564048;
    v_fwd = *(Vec *)((char *)dst + 0xD8);
    v_pos = *(Vec *)((char *)dst + 0xE4);

    if (lbl_8056404C - ((float *)((char *)dst + 0xD8))[1] < lbl_80564064) {
        v_fwd.x = lbl_80564048;
        v_fwd.y = lbl_80564048;
        v_fwd.z = lbl_8056404C;
    }
    PSVECCrossProduct(&v_up, &v_fwd, &v_right);
    PSVECNormalize(&v_right, &v_right);
    PSVECCrossProduct(&v_right, &v_up, &v_fwd);
    PSVECNormalize(&v_fwd, &v_fwd);

    fn_801E9DC4((int *)((char *)dst + 0x1EC));

    input.x = lbl_80564068 * lbl_802FA818[3];
    input.y = lbl_80564068 * lbl_802FA818[4];
    input.z = lbl_80564068 * lbl_802FA818[5];

    axis.x = lbl_802FA818[0] * *(float *)((char *)src->unk_140 + 0x5E4);
    axis.y = lbl_802FA818[1] * *(float *)((char *)src->unk_140 + 0x5E4);
    axis.z = lbl_802FA818[2] * *(float *)((char *)src->unk_140 + 0x5E4);

    mag = PSVECMag(&input);
    if (mag > lbl_8056406C) {
        float inv = lbl_8056404C / mag;
        float x = input.x * inv;
        float y = input.y * inv;
        float z = input.z * inv;
        float s = (float)sin(mag);
        float c = (float)cos(mag);
        float t = lbl_8056404C - c;
        rot[0][0] = c + t * x * x;
        rot[0][1] = t * x * y + s * z;
        rot[0][2] = t * x * z - s * y;
        rot[1][0] = t * x * y - s * z;
        rot[1][1] = c + t * y * y;
        rot[1][2] = t * y * z + s * x;
        rot[2][0] = t * x * z + s * y;
        rot[2][1] = t * y * z - s * x;
        rot[2][2] = c + t * z * z;
    } else {
        rot[0][0] = lbl_8056404C; rot[0][1] = lbl_80564048; rot[0][2] = lbl_80564048;
        rot[1][0] = lbl_80564048; rot[1][1] = lbl_8056404C; rot[1][2] = lbl_80564048;
        rot[2][0] = lbl_80564048; rot[2][1] = lbl_80564048; rot[2][2] = lbl_8056404C;
    }

    target = (char *)&lbl_8049FD58 + 0x17A8 + arg0 * 0x30;
    fn_801BFD34((char *)target + 0x24, &axis, &v_right);
    fn_80015B20(target, rot, &v_right);

    trans[0][0] = v[0].x; trans[0][1] = v[0].y; trans[0][2] = v[0].z;
    trans[1][0] = v[1].x; trans[1][1] = v[1].y; trans[1][2] = v[1].z;
    trans[2][0] = v[2].x; trans[2][1] = v[2].y; trans[2][2] = v[2].z;
    fn_801C7254(trans);
    fn_80015B20(target, target, trans);
    fn_80144CD0((char *)target + 0x24, (char *)target + 0x24, &v[0]);

    fn_80276098((char *)src + 0x58, rot, src->unk_BC, lbl_80564068 * lbl_802FA818[6], lbl_80564060, arg0, 0x22);
}

float fn_80277704(int i) {
    volatile unsigned char *base = (volatile unsigned char *)&lbl_8049FD58;
    int offset = i * 0x50;
    if (base[offset] != 0) {
        float *p = (float *)((unsigned char *)base + offset);
        return (lbl_8055E3C8 - *(float *)((unsigned char *)p + 0x48)) /
               *(float *)((unsigned char *)p + 0x44);
    }
    return lbl_80564054;
}

void fn_80277740(void) {
    lbl_8055F5A0 = 0;
    lbl_8055F598 = 0;
    lbl_8055F59C = 0;
}

extern char lbl_8055C650;
extern char lbl_803473B8[], lbl_803473C4[];
#pragma push
#pragma dont_inline on
#pragma cplusplus on
extern "C" int fn_80277754(void *arg0) {
    class NameGetter {
    public:
        virtual char *getName();
    };
    char *name;
    name = ((NameGetter *)arg0)->getName();
    if (stricmp(name, &lbl_8055C650) == 0) {
        fn_80276ACC(arg0, *(int *)&lbl_8055C638);
        goto done;
    }
    name = ((NameGetter *)arg0)->getName();
    if (stricmp(name, &lbl_8055C644) == 0) {
        fn_80276ACC(arg0, (int)&lbl_8055C644);
        goto done;
    }
    name = ((NameGetter *)arg0)->getName();
    if (stricmp(name, lbl_803473B8) == 0) {
        fn_80276ACC(arg0, (int)lbl_803473C4);
        goto done;
    }
    return 0;
done:
    return 1;
}

extern float lbl_80564070, lbl_80564074;
extern "C" int sprintf(char*, const char*, ...);
extern "C" char *strcpy(char*, const char*);
extern "C" void fn_80277828(void) {
    unsigned char* def = lbl_8049FE98;
    *(float*)(def + 4) = lbl_8056404C;
    *(float*)(def + 8) = lbl_80564048;
    *(float*)(def + 0xC) = lbl_80564048;
    *(float*)(def + 0x10) = lbl_80564048;
    *(float*)(def + 0x14) = lbl_8056404C;
    *(float*)(def + 0x18) = lbl_80564048;
    *(float*)(def + 0x1C) = lbl_80564048;
    *(float*)(def + 0x20) = lbl_80564048;
    *(float*)(def + 0x24) = lbl_8056404C;
    *(float*)(def + 0x28) = lbl_80564048;
    *(float*)(def + 0x2C) = lbl_80564048;
    *(float*)(def + 0x30) = lbl_80564048;
    *(float*)(def + 0x34) = lbl_80564070;
    def[0x38] = 0;
    lbl_8049FE98[0] = 1;
    if (lbl_8055F598 == 0) {
        char *fmt = *(char**)&lbl_8055C638;
        int i = lbl_8055F5A0;
        unsigned char* entry = &lbl_8049FEE0 + i * 0x48;
        *(float*)(entry + 4) = lbl_8056404C;
        *(float*)(entry + 8) = lbl_80564048;
        *(float*)(entry + 0xC) = lbl_80564048;
        *(float*)(entry + 0x10) = lbl_80564048;
        *(float*)(entry + 0x14) = lbl_8056404C;
        *(float*)(entry + 0x18) = lbl_80564048;
        *(float*)(entry + 0x1C) = lbl_80564048;
        *(float*)(entry + 0x20) = lbl_80564048;
        *(float*)(entry + 0x24) = lbl_8056404C;
        *(float*)(entry + 0x28) = lbl_80564048;
        *(float*)(entry + 0x2C) = lbl_80564048;
        *(float*)(entry + 0x30) = lbl_80564048;
        *(float*)(entry + 0x34) = lbl_80564070;
        entry[0x38] = 0;
        lbl_8055F5A0 = i + 1;
        lbl_8055F598 = (int)entry;
        entry[0] = 1;
        sprintf((char*)entry + 0x38, fmt);
    }
    if (lbl_8055F59C == 0) {
        int i = lbl_8055F5A0;
        unsigned char* entry = &lbl_8049FEE0 + i * 0x48;
        lbl_8055F59C = (int)entry;
        lbl_8055F5A0 = i + 1;
        entry[0] = 1;
        *(float*)(entry + 0x34) = lbl_80564074;
        strcpy((char*)*(volatile int*)&lbl_8055F59C + 0x38, &lbl_8055C644);
    }
}

#pragma cplusplus off
#pragma pop
int fn_80277960(void *arg0, void *arg1, float *arg2) {
    unsigned char *p = (unsigned char *)fn_80276A44();
    if (p != 0) {
        unsigned int *dst = (unsigned int *)arg1;
        unsigned int *src = (unsigned int *)(p + 4);
        unsigned int a;
        unsigned int b;

        b = src[0]; a = src[1]; dst[0] = b; dst[1] = a;
        a = src[2]; b = src[3]; dst[2] = a; dst[3] = b;
        a = src[4]; b = src[5]; dst[4] = a; dst[5] = b;
        a = src[6]; b = src[7]; dst[6] = a; dst[7] = b;
        a = src[8]; dst[8] = a;
        b = src[9]; a = src[10]; dst[9] = b; dst[10] = a;
        b = src[11]; dst[11] = b;
        *arg2 = *(float *)(p + 0x34);
        return 1;
    }
    return 0;
}
#pragma cplusplus on
struct Fn80277F84Dummy {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual char *v6(const char *, const char *); virtual void v7(); virtual void v8();
    virtual float v9(const char *);
};
#pragma cplusplus reset

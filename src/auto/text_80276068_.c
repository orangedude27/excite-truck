// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F598, lbl_8055F59C, lbl_8055F5A0;
extern unsigned char lbl_8049FD58;
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
    entry=&lbl_8049FD58+arg5*0x50; out=(float*)(entry+4);
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

extern unsigned char lbl_8049FEE0;
extern char lbl_8055C638, lbl_8055C63C, lbl_8055C644;
extern void fn_80277F84(void *, void *, int);
extern int stricmp(const char *, const char *);
extern char *strncpy(char *, const char *, unsigned int);
void fn_80276ACC(void *arg0, int arg1) {
    char *name = (*(char * (**)(void *, const char *, int))((char *)*(void **)arg0 + 0x18))(arg0, &lbl_8055C63C, arg1);
    int i = lbl_8055F5A0;
    unsigned char *entry = &lbl_8049FEE0 + i * 0x48;
    lbl_8055F5A0 = i + 1;
    fn_80277F84(entry, arg0, i + 1);
    strncpy((char *)(entry + 0x38), name, 0x10);
    if (stricmp(name, &lbl_8055C644) == 0) {
        lbl_8055F59C = (int)entry;
        return;
    }
    if (stricmp(name, &lbl_8055C638) == 0)
        lbl_8055F598 = (int)entry;
}

void fn_80276B8C(void) {
    unsigned char *entry = &lbl_8049FD58;
    int i = 0;
    do {
        memset(entry, 0, 0x50);
        i++;
        entry += 0x50;
    } while (i < 4);
}

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
extern u8 lbl_8049FD58;
extern u8 lbl_8049FE98[];
__declspec(section ".data") extern u8 lbl_8049FD58;
void fn_80276BE4(u32 *arg0, f32 *arg1) {
    u32 *src;
    if (lbl_8049FD58 != 0) {
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

void fn_80276D3C(int unused, int arg) {
    unsigned char sp10[0x38];
    float sp8;
    unsigned char *p = (unsigned char *)fn_80276A44();
    if (arg == 1) {
        fn_8026A4A0(0, sp10, &sp8);
        fn_80276098(sp10, p + 4, sp8, *(float *)(p + 0x34), lbl_80564060, 0, 0x22);
    } else {
        memcpy(lbl_8049FE98, p, 0x48);
        lbl_8049FD58 = 0;
    }
}

float fn_80277704(int i) {
    unsigned char *p = (unsigned char *)&lbl_8049FD58 + i * 0x50;
    if (*p != 0) {
        float *f = (float *)p;
        return (lbl_8055E3C8 - f[0x48 / 4]) / f[0x44 / 4];
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
#pragma dont_inline on
int fn_80277754(void *arg0) {
    char *name;
    name = (*(char * (**)(void *))((char *)*(void **)arg0 + 8))(arg0);
    if (stricmp(name, &lbl_8055C650) == 0) {
        fn_80276ACC(arg0, *(int *)&lbl_8055C638);
        goto done;
    }
    name = (*(char * (**)(void *))((char *)*(void **)arg0 + 8))(arg0);
    if (stricmp(name, &lbl_8055C644) == 0) {
        fn_80276ACC(arg0, (int)&lbl_8055C644);
        goto done;
    }
    name = (*(char * (**)(void *))((char *)*(void **)arg0 + 8))(arg0);
    if (stricmp(name, lbl_803473B8) == 0) {
        fn_80276ACC(arg0, (int)lbl_803473C4);
        goto done;
    }
    return 0;
done:
    return 1;
}
#pragma dont_inline reset
int fn_80277960(void *arg0, void *arg1, float *arg2) {
    unsigned char *p = (unsigned char *)fn_80276A44();
    if (p != 0) {
        unsigned int *dst = (unsigned int *)arg1;
        unsigned int *src = (unsigned int *)(p + 4);
        dst[0] = src[0]; dst[1] = src[1];
        dst[2] = src[2]; dst[3] = src[3];
        dst[4] = src[4]; dst[5] = src[5];
        dst[6] = src[6]; dst[7] = src[7];
        dst[8] = src[8]; dst[9] = src[9];
        dst[10] = src[10]; dst[11] = src[11];
        *arg2 = *(float *)(p + 0x34);
        return 1;
    }
    return 0;
}


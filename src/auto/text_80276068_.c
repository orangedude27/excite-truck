// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern volatile int lbl_8055F598, lbl_8055F59C, lbl_8055F5A0;
__declspec(section ".data") extern unsigned char lbl_8049FEE0;
extern int stricmp(const char *, const char *);
__declspec(section ".data") extern unsigned char lbl_8049FD58[];
extern float lbl_8055E3C8, lbl_80564054, lbl_80564060;
extern float lbl_8049FD58_float_dummy;
extern void *fn_80276A44();
extern void fn_8026A4A0(int, void *, float *);
extern void fn_80276098(void *, void *, float, float, float, int, int);
extern void *memcpy(void *, const void *, unsigned int);
#pragma scheduling invalid_target
int fn_80276068(int arg0) {
    unsigned int shift = arg0 - 4;
    int result = 0;
    if (shift > 0x13)
        goto done;
    if (!((1U << shift) & 0x80027))
        goto done;
    result = 1;
done:
    return result;
}
#pragma scheduling on
extern float lbl_80558DC4[], lbl_80564048, lbl_8056404C, lbl_80564050;
extern double fn_8002F234(float);
extern float PSVECSquareDistance(void *, void *);
extern float lbl_80558DC4[], lbl_80564048, lbl_8056404C, lbl_80564050, lbl_8055E3C8;
extern float PSVECSquareDistance(void *, void *), fabsf(float);
extern float lbl_80564054, lbl_80564058, lbl_8056405C;
extern char lbl_80347384[];
extern float fn_80277704(int);
extern void fn_8026A49C(int, int, float *, float *);
extern void fn_8012F57C(float *, float *, float *, float);
extern void fn_802E30C8(const char *, ...);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80276098(void *arg0, void *arg1, float arg2, float arg3, float arg4, int arg5, int arg6) {
    unsigned char *entry;
    float *out;
    float trace, root, inv;
    int i,j,k;
    if ((float)__fabs(arg2-arg3) > lbl_80558DC4[0] ||
        (float)__fabs(PSVECSquareDistance((char*)arg0+0x24,(char*)arg1+0x24)) > lbl_80558DC4[0] ||
        (float)__fabs(PSVECSquareDistance(arg0,arg1)) > lbl_80558DC4[0] ||
        (float)__fabs(PSVECSquareDistance((char*)arg0+0xC,(char*)arg1+0xC)) > lbl_80558DC4[0] ||
        (float)__fabs(PSVECSquareDistance((char*)arg0+0x18,(char*)arg1+0x18)) > lbl_80558DC4[0]) {
    } else return;
    entry=(unsigned char *)&lbl_8049FD58+arg5*0x50; out=(float*)(entry+4);
    trace=((float*)arg0)[0]+((float*)arg0)[4]+((float*)arg0)[8]; *(float*)(entry+0x44)=arg4; *(float*)(entry+0x48)=lbl_8055E3C8;
    if(trace>lbl_80564048){root=fn_8002F234(lbl_8056404C+trace);inv=lbl_80564050/root;out[0]=lbl_80564050*root;out[1]=inv*(((float*)arg0)[5]-((float*)arg0)[7]);out[2]=inv*(((float*)arg0)[6]-((float*)arg0)[2]);out[3]=inv*(((float*)arg0)[1]-((float*)arg0)[3]);}
    else{i=0;if(((float*)arg0)[4]>((float*)arg0)[0])i=1;if(((float*)arg0)[8]>((float*)arg0)[i*3+i])i=2;j=(i+1)%3;k=(j+1)%3;root=fn_8002F234(lbl_8056404C+(((float*)arg0)[i*3+i]-(((float*)arg0)[j*3+k]+((float*)arg0)[k*3+j])));inv=lbl_80564050/root;out[i]=lbl_80564050*root;out[3]=inv*(((float*)arg0)[j*3+k]-((float*)arg0)[k*3+j]);out[j]=inv*(((float*)arg0)[i*3+j]+((float*)arg0)[j*3+i]);out[k]=inv*(((float*)arg0)[i*3+k]+((float*)arg0)[k*3+i]);}
    *(float*)(entry+0x24)=((float*)arg0)[9];*(float*)(entry+0x28)=((float*)arg0)[10];*(float*)(entry+0x2C)=((float*)arg0)[11];*(float*)(entry+0x3C)=arg2;
    trace=((float*)arg1)[0]+((float*)arg1)[4]+((float*)arg1)[8];
    if(trace>lbl_80564048){root=fn_8002F234(lbl_8056404C+trace);inv=lbl_80564050/root;out[4]=lbl_80564050*root;out[5]=inv*(((float*)arg1)[5]-((float*)arg1)[7]);out[6]=inv*(((float*)arg1)[6]-((float*)arg1)[2]);out[7]=inv*(((float*)arg1)[1]-((float*)arg1)[3]);}
    else{i=0;if(((float*)arg1)[4]>((float*)arg1)[0])i=1;if(((float*)arg1)[8]>((float*)arg1)[i*3+i])i=2;j=(i+1)%3;k=(j+1)%3;root=fn_8002F234(lbl_8056404C+(((float*)arg1)[i*3+i]-(((float*)arg1)[j*3+k]+((float*)arg1)[k*3+j])));inv=lbl_80564050/root;out[4+i]=lbl_80564050*root;out[7]=inv*(((float*)arg1)[j*3+k]-((float*)arg1)[k*3+j]);out[4+j]=inv*(((float*)arg1)[i*3+j]+((float*)arg1)[j*3+i]);out[4+k]=inv*(((float*)arg1)[i*3+k]+((float*)arg1)[k*3+i]);}
    *(float*)(entry+0x30)=((float*)arg1)[9];*(float*)(entry+0x34)=((float*)arg1)[10];*(float*)(entry+0x38)=((float*)arg1)[11];*(float*)(entry+0x40)=arg3;*(int*)(entry+0x4C)=arg6;*entry=1;
}
#pragma pop
extern float lbl_80564054, lbl_80564058, lbl_8056405C;
extern char lbl_80347384[];
extern float fn_80277704(int);
extern void fn_8026A49C(int, int, float *, float *);
extern void fn_8012F57C(float *, float *, float *, float);
extern void fn_802E30C8(const char *, ...);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
unsigned int fn_8027656C(void *arg0, void *arg1, unsigned int arg2) {
    float t;
    unsigned char *base;
    int off;
    float mat[12];
    float quat[4];
    float scalar;
    float trace, root, inv;
    int i, j, k;
    float s;
    float x, y, z, w;
    float x2, y2, z2;
    float xx, yy, zz, wx, yz;
    float *outm;
    float *m;
    t = fn_80277704(arg2);
    base = lbl_8049FD58;
    off = arg2 * 0x50;
    if (*(int *)(base + off + 0x4C) != 0x22) {
        m = mat;
        fn_8026A49C(arg2, *(int *)(base + off + 0x4C), mat, &scalar);
        trace = mat[0] + mat[4] + mat[8];
        if (trace > lbl_80564048) {
            root = (float)fn_8002F234(lbl_8056404C + trace);
            inv = lbl_80564050 / root;
            *(float *)(base + off + 0x14 + 12) = lbl_80564050 * root;
            *(float *)(base + off + 0x14) = inv * (mat[5] - mat[7]);
            *(float *)(base + off + 0x18) = inv * (mat[6] - mat[2]);
            *(float *)(base + off + 0x1C) = inv * (mat[1] - mat[3]);
        } else {
            i = 0;
            if (mat[4] > mat[0]) i = 1;
            if (mat[8] > mat[i * 3 + i]) i = 2;
            j = (i + 1) % 3;
            k = (j + 1) % 3;
            root = (float)fn_8002F234(lbl_8056404C + (m[i * 3 + i] - (m[j * 3 + k] + m[k * 3 + j])));
            inv = lbl_80564050 / root;
            *(float *)(base + off + 0x14 + i * 4) = lbl_80564050 * root;
            *(float *)(base + off + 0x20) = inv * (m[j * 3 + k] - m[k * 3 + j]);
            *(float *)(base + off + 0x14 + j * 4) = inv * (m[i * 3 + j] + m[j * 3 + i]);
            *(float *)(base + off + 0x14 + k * 4) = inv * (m[i * 3 + k] + m[k * 3 + i]);
        }
        *(float *)(base + off + 0x30) = mat[9];
        *(float *)(base + off + 0x34) = mat[10];
        *(float *)(base + off + 0x38) = mat[11];
        *(float *)(base + off + 0x40) = scalar;
    }
    if (t >= lbl_8056404C || t < lbl_80564048) {
        if (t < lbl_80564048) {
            fn_802E30C8(lbl_80347384);
        }
        x = *(float *)(base + off + 0x14);
        y = *(float *)(base + off + 0x18);
        z = *(float *)(base + off + 0x1C);
        w = *(float *)(base + off + 0x20);
        x2 = x + x;
        y2 = y + y;
        z2 = z + z;
        xx = x * x2;
        yy = y * y2;
        zz = z * z2;
        wx = w * x2;
        yz = y * z2;
        outm = (float *)arg0;
        outm[0] = lbl_8056404C - (yy + zz);
        outm[4] = lbl_8056404C - (xx + zz);
        outm[8] = lbl_8056404C - (xx + yy);
        outm[7] = yz - wx;
        outm[5] = yz + wx;
        outm[6] = x * z2 + w * y2;
        outm[3] = x * y2 - w * z2;
        outm[1] = x * y2 + w * z2;
        outm[2] = x * z2 - w * y2;
        outm[9] = *(float *)(base + off + 0x30);
        outm[10] = *(float *)(base + off + 0x34);
        outm[11] = *(float *)(base + off + 0x38);
        *(float *)arg1 = *(float *)(base + off + 0x40);
        base[off] = 0;
    } else {
        if (t < lbl_80564054) {
            s = lbl_80564054;
        } else if (t > lbl_8056404C) {
            s = lbl_8056404C;
        } else if (t <= lbl_80564048) {
            s = lbl_80564058 * t * t * t - lbl_8056405C * t * t;
        } else {
            s = lbl_80564058 * t * t * t + lbl_8056405C * t * t;
        }
        fn_8012F57C(quat, (float *)(base + off + 4), (float *)(base + off + 0x14), s);
        x = quat[0];
        y = quat[1];
        z = quat[2];
        w = quat[3];
        x2 = x + x;
        y2 = y + y;
        z2 = z + z;
        xx = x * x2;
        yy = y * y2;
        zz = z * z2;
        wx = w * x2;
        yz = y * z2;
        outm = (float *)arg0;
        outm[0] = lbl_8056404C - (yy + zz);
        outm[4] = lbl_8056404C - (xx + zz);
        outm[8] = lbl_8056404C - (xx + yy);
        outm[7] = yz - wx;
        outm[5] = yz + wx;
        outm[6] = x * z2 + w * y2;
        outm[3] = x * y2 - w * z2;
        outm[1] = x * y2 + w * z2;
        outm[2] = x * z2 - w * y2;
        outm[9] = *(float *)(base + off + 0x24) + s * (*(float *)(base + off + 0x30) - *(float *)(base + off + 0x24));
        outm[10] = *(float *)(base + off + 0x28) + s * (*(float *)(base + off + 0x34) - *(float *)(base + off + 0x28));
        outm[11] = *(float *)(base + off + 0x2C) + s * (*(float *)(base + off + 0x38) - *(float *)(base + off + 0x2C));
        *(float *)arg1 = *(float *)(base + off + 0x3C) + s * (*(float *)(base + off + 0x40) - *(float *)(base + off + 0x3C));
    }
}

#pragma dont_inline on
void *fn_80276A44(void *arg) {
    unsigned char *current = &lbl_8049FEE0;
    int i = 0;
    goto check;
loop:
    if (stricmp((const char *)current + 0x38, (const char *)arg) == 0)
        return &lbl_8049FEE0 + i * 0x48;
    current += 0x48;
    i++;
check:
    if (i < lbl_8055F5A0) goto loop;
    return 0;
}
#pragma dont_inline off

#pragma pop
__declspec(section ".data") extern unsigned char lbl_8049FEE0;
extern char lbl_8055C638, lbl_8055C63C, lbl_8055C644;
extern void fn_80277F84(void *, void *, int);
extern int stricmp(const char *, const char *);
extern char *strncpy(char *, const char *, unsigned int);

/* One camera record of the table at lbl_8049FEE0 (lbl_8055F5A0 of them, each
 * filled from a camera object's named parameters by fn_80277F84). The record
 * just before the table, at lbl_8049FE98, is the fallback all others blend from. */
struct CameraEntry {
    unsigned char inUse;   /* set once the record holds a camera */
    float rot[3][3];       /* camera rotation matrix */
    float pos[3];          /* camera position */
    float fov;             /* field of view, the "fov" parameter */
    char name[16];         /* fn_80276A44 looks records up by this name */
};

#pragma cplusplus on
extern "C" void fn_80276ACC(void *arg0, int arg1) {
    struct Iface {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual char *GetName(const char *, int);
    };
    char *name = ((Iface *)arg0)->GetName(&lbl_8055C63C, arg1);
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
#pragma cplusplus reset
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
void fn_80276BE4(void *arg0, void *arg1) {
    u32 *dst = (u32 *)arg0;
    u32 *src;
    unsigned int a;
    unsigned int b;
    if (*(unsigned char *)&lbl_8049FD58 != 0) {
        fn_8027656C(lbl_8049FE98 + 4, lbl_8049FE98 + 0x34, 0);
    }
    src = (u32 *)(lbl_8049FE98 + 4);
    b = src[0]; a = src[1]; dst[0] = b; dst[1] = a;
    a = src[2]; b = src[3]; dst[2] = a; dst[3] = b;
    a = src[4]; b = src[5]; dst[4] = a; dst[5] = b;
    a = src[6]; b = src[7]; dst[6] = a; dst[7] = b;
    a = src[8]; dst[8] = a;
    b = src[9]; a = src[10]; dst[9] = b; dst[10] = a;
    b = src[11]; dst[11] = b;
    *(f32 *)arg1 = *(f32 *)(lbl_8049FE98 + 0x34);
}

void fn_80276CB0(void *arg0, int arg1) {
    unsigned char *p;

    p = (unsigned char *)fn_80276A44(arg0);
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
    unsigned char *p = (unsigned char *)fn_80276A44((void *)unused);
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
extern "C" int fn_80277754(void *camera) {
    class NameGetter {
    public:
        virtual char *getName();
    };
    char *name;

    /* Match known camera names and register the camera entry. */
    name = ((NameGetter *)camera)->getName();
    if (stricmp(name, &lbl_8055C650) == 0) {
        fn_80276ACC(camera, *(int *)&lbl_8055C638);
        goto done;
    }
    name = ((NameGetter *)camera)->getName();
    if (stricmp(name, &lbl_8055C644) == 0) {
        fn_80276ACC(camera, (int)&lbl_8055C644);
        goto done;
    }
    name = ((NameGetter *)camera)->getName();
    if (stricmp(name, lbl_803473B8) == 0) {
        fn_80276ACC(camera, (int)lbl_803473C4);
        goto done;
    }
    return 0;
done:
    return 1;
}
#pragma cplusplus off
#pragma pop

extern float lbl_80564070, lbl_80564074;
extern int sprintf(char*, const char*, ...);
extern char *strcpy(char*, const char*);
void fn_80277828(void) {
    struct CameraEntry *def = (struct CameraEntry *)lbl_8049FE98;
    def->rot[0][0] = lbl_8056404C;
    def->rot[0][1] = lbl_80564048;
    def->rot[0][2] = lbl_80564048;
    def->rot[1][0] = lbl_80564048;
    def->rot[1][1] = lbl_8056404C;
    def->rot[1][2] = lbl_80564048;
    def->rot[2][0] = lbl_80564048;
    def->rot[2][1] = lbl_80564048;
    def->rot[2][2] = lbl_8056404C;
    def->pos[0] = lbl_80564048;
    def->pos[1] = lbl_80564048;
    def->pos[2] = lbl_80564048;
    def->fov = lbl_80564070;
    def->name[0] = 0;
    ((struct CameraEntry *)lbl_8049FE98)->inUse = 1;

    if (lbl_8055F598 == 0) {
        char *fmt = *(char**)&lbl_8055C638;
        int i = lbl_8055F5A0;
        struct CameraEntry *entry = (struct CameraEntry *)&lbl_8049FEE0 + i;
        entry->rot[0][0] = lbl_8056404C;
        entry->rot[0][1] = lbl_80564048;
        entry->rot[0][2] = lbl_80564048;
        entry->rot[1][0] = lbl_80564048;
        entry->rot[1][1] = lbl_8056404C;
        entry->rot[1][2] = lbl_80564048;
        entry->rot[2][0] = lbl_80564048;
        entry->rot[2][1] = lbl_80564048;
        entry->rot[2][2] = lbl_8056404C;
        entry->pos[0] = lbl_80564048;
        entry->pos[1] = lbl_80564048;
        entry->pos[2] = lbl_80564048;
        entry->fov = lbl_80564070;
        ((volatile char *)entry->name)[0] = 0;
        lbl_8055F5A0 = i + 1;
        lbl_8055F598 = (int)entry;
        entry->inUse = 1;
        sprintf(entry->name, fmt);
    }
    if (lbl_8055F59C == 0) {
        int i = lbl_8055F5A0;
        struct CameraEntry *entry = (struct CameraEntry *)&lbl_8049FEE0 + i;
        lbl_8055F59C = (int)entry;
        lbl_8055F5A0 = i + 1;
        entry->inUse = 1;
        entry->fov = lbl_80564074;
        strcpy(((struct CameraEntry *)lbl_8055F59C)->name, &lbl_8055C644);
    }
}
int fn_80277960(void *arg0, void *arg1, float *arg2) {
    unsigned char *p = (unsigned char *)fn_80276A44(arg0);
    if (p != 0) {
        int *dst = (int *)arg1;
        int *src = (int *)(p + 4);
        int a;
        int b;
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

void fn_80277A14(void *arg0, int arg1) {
    return;
}

#pragma cplusplus on
extern "C" void fn_80277F84(void *arg0, void *arg1, int arg2) {
    /* Initialize a camera/entry record by reading named float fields and a name string from a config object. */
    class FloatDummy {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual float get(const char *);
    };
    class NameDummy {
    public:
        virtual void n0();
        virtual void n1();
        virtual void n2();
        virtual void n3();
        virtual char *getName(const char *, const char *);
    };
    extern unsigned char lbl_80347378[];
    extern unsigned char lbl_8055C658;
    extern char lbl_8055C65C;
    FloatDummy *config = (FloatDummy *)arg1;
    char *entryName;

    *(float *)((char *)arg0 + 0x28) = config->get((char *)lbl_80347378 + 0x178);
    *(float *)((char *)arg0 + 0x2C) = config->get((char *)lbl_80347378 + 0x184);
    *(float *)((char *)arg0 + 0x30) = config->get((char *)lbl_80347378 + 0x190);
    *(float *)((char *)arg0 + 0x04) = config->get((char *)lbl_80347378 + 0x19C);
    *(float *)((char *)arg0 + 0x08) = config->get((char *)lbl_80347378 + 0x1A8);
    *(float *)((char *)arg0 + 0x0C) = config->get((char *)lbl_80347378 + 0x1B4);
    *(float *)((char *)arg0 + 0x10) = config->get((char *)lbl_80347378 + 0x1C0);
    *(float *)((char *)arg0 + 0x14) = config->get((char *)lbl_80347378 + 0x1CC);
    *(float *)((char *)arg0 + 0x18) = config->get((char *)lbl_80347378 + 0x1D8);
    *(float *)((char *)arg0 + 0x1C) = config->get((char *)lbl_80347378 + 0x1E4);
    *(float *)((char *)arg0 + 0x20) = config->get((char *)lbl_80347378 + 0x1F0);
    *(float *)((char *)arg0 + 0x24) = config->get((char *)lbl_80347378 + 0x1FC);
    *(float *)((char *)arg0 + 0x34) = config->get((char *)&lbl_8055C658);
    entryName = ((NameDummy *)arg1)->getName(&lbl_8055C63C, &lbl_8055C65C);
    strncpy((char *)arg0 + 0x38, entryName, 0x10);
    *(unsigned char *)arg0 = 1;
}
#pragma cplusplus reset

#pragma cplusplus on
struct Fn80277F84Dummy {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual char *v6(const char *, const char *); virtual void v7(); virtual void v8();
    virtual float v9(const char *);
};
#pragma cplusplus reset

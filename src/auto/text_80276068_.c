// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern volatile int lbl_8055F598, lbl_8055F59C, lbl_8055F5A0;
__declspec(section ".data") extern unsigned char lbl_8049FEE0;
extern int stricmp(const char *, const char *);
__declspec(section ".data") extern unsigned char lbl_8049FD58[];
extern float lbl_8055E3C8, lbl_80564054, lbl_80564060;
extern float lbl_8049FD58_float_dummy;
// Four 0x50-byte camera-blend records, and the blend elapsed-time / no-blend (-1.0f) result.
#define gCameraBlends lbl_8049FD58
#define gBlendTime    lbl_8055E3C8
#define BLEND_NONE    lbl_80564054
extern void *fn_80276A44();
extern void fn_8026A4A0(int, void *, float *);
extern void fn_80276098(void *, void *, float, float, float, int, int);
extern void *memcpy(void *, const void *, unsigned int);
#pragma dont_inline fn_80276068
#pragma dont_inline fn_80277704
#pragma dont_inline fn_80276098
#pragma scheduling invalid_target
/* Returns 1 when the camera mode is one of the chase/replay modes fn_80276DC8
 * keeps as-is (4, 5, 6, 9 and 23); 0 for a mode that needs the default fallback. */
int fn_80276068(int cameraMode) {
    unsigned int modeBit = cameraMode - 4;
    int isValid = 0;
    if (modeBit > 0x13)
        goto done;
    if (!((1U << modeBit) & 0x80027))
        goto done;
    isValid = 1;
done:
    return isValid;
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
    float (*a)[3] = (float (*)[3])arg0;
    float (*b)[3] = (float (*)[3])arg1;
    float trace, root, inv;
    int i, j, k, eq;
    unsigned int off;
    if ((float)__fabs(arg2-arg3) <= lbl_80558DC4[0]) {
        eq = (float)__fabs(PSVECSquareDistance((char*)arg0+0x24,(char*)arg1+0x24)) <= lbl_80558DC4[0];
        if (eq) eq = (float)__fabs(PSVECSquareDistance(arg0,arg1)) <= lbl_80558DC4[0];
        if (eq) eq = (float)__fabs(PSVECSquareDistance((char*)arg0+0xC,(char*)arg1+0xC)) <= lbl_80558DC4[0];
        if (eq) eq = (float)__fabs(PSVECSquareDistance((char*)arg0+0x18,(char*)arg1+0x18)) <= lbl_80558DC4[0];
        if (eq) return;
    }
    off = arg5 * 0x50;
    trace=a[2][2]+(a[0][0]+a[1][1]);
    *(float*)&lbl_8049FD58[off+0x44]=arg4;
    *(float*)&lbl_8049FD58[off+0x48]=lbl_8055E3C8;
    if(trace>lbl_80564048){
        float d0,d1,d2,w;
        root=fn_8002F234(lbl_8056404C+trace); inv=lbl_80564050/root;
        d0=a[1][2]-a[2][1]; w=lbl_80564050*root;
        d1=a[2][0]-a[0][2]; d2=a[0][1]-a[1][0];
        *(float*)&lbl_8049FD58[off+0x10]=w;
        *(float*)&lbl_8049FD58[off+0x4]=inv*d0;
        *(float*)&lbl_8049FD58[off+0x8]=inv*d1;
        *(float*)&lbl_8049FD58[off+0xc]=inv*d2;
    }
    else {
        float *o=(float*)&lbl_8049FD58[off+4];
        float t0,t1,t2,w;
        i=0; if(a[1][1]>a[0][0])i=1; if(a[2][2]>a[i][i])i=2;
        j=(i+1)%3; k=(j+1)%3;
        root=fn_8002F234(lbl_8056404C+(a[i][i]-(a[j][j]+a[k][k])));
        inv=lbl_80564050/root;
        t0=a[j][k]-a[k][j]; w=lbl_80564050*root;
        t1=a[i][j]+a[j][i]; t2=a[i][k]+a[k][i];
        o[i]=w;
        o[3]=inv*t0;
        o[j]=inv*t1;
        o[k]=inv*t2;
    }
    *(float*)&lbl_8049FD58[off+0x24]=a[3][0];
    *(float*)&lbl_8049FD58[off+0x28]=a[3][1];
    *(float*)&lbl_8049FD58[off+0x2C]=a[3][2];
    *(float*)&lbl_8049FD58[off+0x3C]=arg2;
    trace=b[2][2]+(b[0][0]+b[1][1]);
    if(trace>lbl_80564048){
        float d0,d1,d2,w;
        root=fn_8002F234(lbl_8056404C+trace); inv=lbl_80564050/root;
        d0=b[1][2]-b[2][1]; w=lbl_80564050*root;
        d1=b[2][0]-b[0][2]; d2=b[0][1]-b[1][0];
        *(float*)&lbl_8049FD58[off+0x20]=w;
        *(float*)&lbl_8049FD58[off+0x14]=inv*d0;
        *(float*)&lbl_8049FD58[off+0x18]=inv*d1;
        *(float*)&lbl_8049FD58[off+0x1c]=inv*d2;
    }
    else {
        float *o=(float*)&lbl_8049FD58[off+0x14];
        float t0,t1,t2,w;
        i=0; if(b[1][1]>b[0][0])i=1; if(b[2][2]>b[i][i])i=2;
        j=(i+1)%3; k=(j+1)%3;
        root=fn_8002F234(lbl_8056404C+(b[i][i]-(b[j][j]+b[k][k])));
        inv=lbl_80564050/root;
        t0=b[j][k]-b[k][j]; w=lbl_80564050*root;
        t1=b[i][j]+b[j][i]; t2=b[i][k]+b[k][i];
        o[i]=w;
        o[3]=inv*t0;
        o[j]=inv*t1;
        o[k]=inv*t2;
    }
    *(float*)&lbl_8049FD58[off+0x30]=b[3][0];
    *(float*)&lbl_8049FD58[off+0x34]=b[3][1];
    *(float*)&lbl_8049FD58[off+0x38]=b[3][2];
    *(float*)&lbl_8049FD58[off+0x40]=arg3;
    *(int*)&lbl_8049FD58[off+0x4C]=arg6;
    lbl_8049FD58[off]=1;
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
    int i, j, k;
    float mat[4][3];
    float quat[4];
    float tmp[3];
    int off;
    float t, scalar, trace, root, inv, s;
    float pf;
    float *outm;
    t = fn_80277704(arg2);
    off = arg2 * 0x50;
    outm = (float *)arg0;
    if (*(int *)&lbl_8049FD58[off + 0x4C] != 0x22) {
        float (*m)[3];
        fn_8026A49C(arg2, *(int *)&lbl_8049FD58[off + 0x4C], (float *)mat, &scalar);
        m = mat;
        trace = m[0][0] + m[1][1] + m[2][2];
        if (trace > lbl_80564048) {
            root = (float)fn_8002F234(lbl_8056404C + trace);
            inv = lbl_80564050 / root;
            *(float *)&lbl_8049FD58[off + 0x20] = lbl_80564050 * root;
            *(float *)&lbl_8049FD58[off + 0x14] = inv * (m[1][2] - m[2][1]);
            *(float *)&lbl_8049FD58[off + 0x18] = inv * (m[2][0] - m[0][2]);
            *(float *)&lbl_8049FD58[off + 0x1C] = inv * (m[0][1] - m[1][0]);
        } else {
            int k;
            float *q = (float *)&lbl_8049FD58[off + 0x14];
            i = 0;
            if (m[1][1] > m[0][0]) i = 1;
            if (m[2][2] > m[i][i]) i = 2;
            j = (i + 1) % 3;
            k = (j + 1) % 3;
            root = (float)fn_8002F234(lbl_8056404C + (m[i][i] - (m[j][j] + m[k][k])));
            inv = lbl_80564050 / root;
            q[i] = lbl_80564050 * root;
            q[3] = inv * (m[j][k] - m[k][j]);
            q[j] = inv * (m[i][j] + m[j][i]);
            q[k] = inv * (m[i][k] + m[k][i]);
        }
        *(float *)&lbl_8049FD58[off + 0x30] = m[3][0];
        *(float *)&lbl_8049FD58[off + 0x34] = m[3][1];
        *(float *)&lbl_8049FD58[off + 0x38] = m[3][2];
        *(float *)&lbl_8049FD58[off + 0x40] = scalar;
    }
    if (t >= lbl_8056404C || t < lbl_80564048) {
        float x, y, z, w, x2, y2, z2, xx, yy, zz, wx, yz;
        if (t < lbl_80564048) fn_802E30C8(lbl_80347384);
        x = *(float *)&lbl_8049FD58[off + 0x14];
        y = *(float *)&lbl_8049FD58[off + 0x18];
        z = *(float *)&lbl_8049FD58[off + 0x1C];
        w = *(float *)&lbl_8049FD58[off + 0x20];
        x2 = x + x; y2 = y + y; z2 = z + z;
        xx = x * x2; yy = y * y2; zz = z * z2; wx = w * x2; yz = y * z2;
        outm[0] = lbl_8056404C - (yy + zz);
        outm[4] = lbl_8056404C - (xx + zz);
        outm[8] = lbl_8056404C - (xx + yy);
        outm[7] = yz - wx; outm[5] = yz + wx;
        outm[6] = x * z2 + w * y2; outm[3] = x * y2 - w * z2;
        outm[1] = x * y2 + w * z2; outm[2] = x * z2 - w * y2;
        outm[9] = *(float *)&lbl_8049FD58[off + 0x30];
        outm[10] = *(float *)&lbl_8049FD58[off + 0x34];
        outm[11] = *(float *)&lbl_8049FD58[off + 0x38];
        *(float *)arg1 = *(float *)&lbl_8049FD58[off + 0x40];
        lbl_8049FD58[off] = 0;
    } else {
        float x, y, z, w, x2, y2, z2, xx, yy, zz, wx, yz;
        if (t < lbl_80564054) s = lbl_80564054;
        else if (t > lbl_8056404C) s = lbl_8056404C;
        else if (t > lbl_80564048) s = lbl_80564058 * t * t * t + lbl_8056405C * t * t;
        else s = lbl_80564058 * t * t * t - lbl_8056405C * t * t;
        fn_8012F57C(quat, (float *)&lbl_8049FD58[off + 4], (float *)&lbl_8049FD58[off + 0x14], s);
        x = quat[0]; y = quat[1]; z = quat[2]; w = quat[3];
        x2 = x + x; y2 = y + y; z2 = z + z;
        xx = x * x2; yy = y * y2; zz = z * z2; wx = w * x2; yz = y * z2;
        outm[0] = lbl_8056404C - (yy + zz);
        outm[4] = lbl_8056404C - (xx + zz);
        outm[8] = lbl_8056404C - (xx + yy);
        outm[7] = yz - wx; outm[5] = yz + wx;
        outm[6] = x * z2 + w * y2; outm[3] = x * y2 - w * z2;
        outm[1] = x * y2 + w * z2; outm[2] = x * z2 - w * y2;
        tmp[2] = *(float *)&lbl_8049FD58[off + 0x2C] + s * (*(float *)&lbl_8049FD58[off + 0x38] - *(float *)&lbl_8049FD58[off + 0x2C]);
        tmp[1] = *(float *)&lbl_8049FD58[off + 0x28] + s * (*(float *)&lbl_8049FD58[off + 0x34] - *(float *)&lbl_8049FD58[off + 0x28]);
        tmp[0] = *(float *)&lbl_8049FD58[off + 0x24] + s * (*(float *)&lbl_8049FD58[off + 0x30] - *(float *)&lbl_8049FD58[off + 0x24]);
        outm[11] = tmp[2]; outm[10] = tmp[1]; outm[9] = tmp[0];
        pf = *(float *)&lbl_8049FD58[off + 0x3C];
        *(float *)arg1 = pf + s * (*(float *)&lbl_8049FD58[off + 0x40] - pf);
    }
}

#pragma dont_inline on
/* Find a camera/entry record by case-insensitively matching its name at offset
 * 0x38 in a table of 0x48-byte entries; return the matching entry or 0. */
void *fn_80276A44(void *name) {
    unsigned char *entry = &lbl_8049FEE0;
    int i = 0;
    goto check;
loop:
    if (stricmp((const char *)entry + 0x38, (const char *)name) == 0)
        return &lbl_8049FEE0 + i * 0x48;
    entry += 0x48;
    i++;
check:
    if (i < lbl_8055F5A0) goto loop;
    return 0;
}
#pragma dont_inline off

#pragma pop
__declspec(section ".data") extern unsigned char lbl_8049FEE0;
extern char lbl_8055C638, lbl_8055C63C, lbl_8055C644;
extern void initCameraEntryFromConfig(void *, void *, int);
extern int stricmp(const char *, const char *);
extern char *strncpy(char *, const char *, unsigned int);

/* One camera record of the table at lbl_8049FEE0 (lbl_8055F5A0 of them, each
 * filled from a camera object's named parameters by initCameraEntryFromConfig). The record
 * just before the table, at lbl_8049FE98, is the fallback all others blend from. */
struct CameraEntry {
    unsigned char inUse;   /* set once the record holds a camera */
    float rot[3][3];       /* camera rotation matrix */
    float pos[3];          /* camera position */
    float fov;             /* field of view, the "fov" parameter */
    char name[16];         /* fn_80276A44 looks records up by this name */
};

/* One running blend between two cameras, of the four at lbl_8049FD58 (0x50
 * bytes each, all cleared by fn_80276B8C and started by fn_80276098). The
 * camera setters here only ever use the first one. */
struct CameraBlend {
    unsigned char active;  /* fn_80276098 sets it; a snap-to-camera clears it */
    float quatFrom[4];     /* 0x04: rotation taken from the first camera */
    float quatTo[4];       /* 0x14: rotation taken from the second camera */
    float posFrom[3];      /* 0x24 */
    float posTo[3];        /* 0x30 */
    float fovFrom;         /* 0x3C */
    float fovTo;           /* 0x40 */
    float unk_44;
    float unk_48;
    int mode;              /* 0x4C: 0x22 for the camera setters here */
};

#define currentCamera (*(struct CameraEntry *)&lbl_8049FE98) /* camera in use */
#define blendRecord0 (*(struct CameraBlend *)&lbl_8049FD58)  /* the one blend */
#define pDefaultCamera lbl_8055F598 /* the record of the camera "rddefault" */

#pragma cplusplus on
/* Adds a record for a camera object to the table of CameraEntry records at
 * lbl_8049FEE0 (lbl_8055F5A0 of them): takes the camera's "name" parameter,
 * defaultName when it has none, fills the next record from the camera's
 * parameters and remembers it as the house camera ("house") or the default
 * camera ("rddefault") one. */
extern "C" void fn_80276ACC(void *camera, int defaultName) {
    struct CameraParams {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        /* the object's parameter called key, or defaultValue when it has none */
        virtual char *getString(const char *key, int defaultValue);
    };
    char *name = ((CameraParams *)camera)->getString(&lbl_8055C63C /* "name" */, defaultName);
    int i = lbl_8055F5A0;
    struct CameraEntry *entry = (struct CameraEntry *)&lbl_8049FEE0 + i;
    lbl_8055F5A0 = i + 1;
    initCameraEntryFromConfig(entry, camera, i + 1);
    strncpy(entry->name, name, 0x10);
    if (stricmp(name, &lbl_8055C644 /* "house" */) == 0) {
        lbl_8055F59C = (int)entry;
        return;
    }
    if (stricmp(name, *(char **)&lbl_8055C638 /* "rddefault" */) == 0)
        lbl_8055F598 = (int)entry;
}
#pragma cplusplus reset
/* Clears all camera blend records (4 entries of 0x50 bytes at lbl_8049FD58). */
void fn_80276B8C(void) {
    unsigned char *blend = lbl_8049FD58;
    int index = 0;
    do {
        memset(blend, 0, 0x50);
        index++;
        blend += 0x50;
    } while (index < 4);
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

struct TruckStateArray {
    char pad[0xF08];
    struct TruckState states[1];
};

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
/* Refresh the current camera from running blend record 0 if a blend is active,
 * then copy its 3x4 transform (rotation matrix + position, 0x30 bytes) into
 * outTransform and its field of view into outFov. */
void fn_80276BE4(u32 *outTransform, f32 *outFov) {
    struct Pair2 { u32 x, y; };
    unsigned char *out = (unsigned char *)outTransform;
    if (*(unsigned char *)&lbl_8049FD58 != 0) {
        fn_8027656C(lbl_8049FE98 + 4, lbl_8049FE98 + 0x34, 0);
    }
    *(struct Pair2 *)(out + 0x00) = *(struct Pair2 *)(lbl_8049FE98 + 0x04);
    *(struct Pair2 *)(out + 0x08) = *(struct Pair2 *)(lbl_8049FE98 + 0x0c);
    *(struct Pair2 *)(out + 0x10) = *(struct Pair2 *)(lbl_8049FE98 + 0x14);
    *(struct Pair2 *)(out + 0x18) = *(struct Pair2 *)(lbl_8049FE98 + 0x1c);
    *(u32 *)(out + 0x20) = *(u32 *)(lbl_8049FE98 + 0x24);
    *(struct Pair2 *)(out + 0x24) = *(struct Pair2 *)(lbl_8049FE98 + 0x28);
    *(u32 *)(out + 0x2c) = *(u32 *)(lbl_8049FE98 + 0x30);
    *outFov = *(f32 *)(lbl_8049FE98 + 0x34);
}

/* Points the current camera at the record named `name` - at the "rddefault"
 * camera when the table holds no such record. With `blend` it starts a blend
 * from the current camera into that one (blend record 0, mode 0x22, its own
 * fov as the target scale); without, it copies the record over the current
 * camera and cancels whatever blend record 0 was running. */
void fn_80276CB0(char *name, int blend) {
    struct CameraEntry *entry = (struct CameraEntry *)fn_80276A44(name);

    if (entry == 0)
        entry = (struct CameraEntry *)pDefaultCamera;
    if (blend != 0) {
        fn_80276098(&currentCamera.rot[0][0], &entry->rot[0][0],
                    currentCamera.fov, entry->fov,
                    lbl_8056404C, 0, 0x22);
    } else {
        memcpy(&currentCamera, entry, sizeof(struct CameraEntry));
        blendRecord0.active = 0;
    }
}

void fn_80276D3C(int unused, int mode) {
    /* Dispatch to either initialize/copy a 0x48-byte entry or apply a transformed setup. */
    unsigned char transformParams[0x38];
    float scale;
    unsigned char *entry = (unsigned char *)fn_80276A44((void *)unused);
    if (mode == 1) {
        fn_8026A4A0(0, transformParams, &scale);
        fn_80276098(transformParams, entry + 4, scale, *(float *)(entry + 0x34), lbl_80564060, 0, 0x22);
    } else {
        memcpy(lbl_8049FE98, entry, 0x48);
        *(unsigned char *)&lbl_8049FD58 = 0;
    }
}

#pragma opt_propagation off
void fn_80276DC8(int arg0) {
    struct TruckState *dst;
    struct TruckState *src;
    char *base;
    Vec v[4];
    Vec v_right, v_up, v_fwd, v_pos;
    Vec input, axis;
    float rot[3][3];
    float trans[3][3];
    void *target;
    float mag;
    volatile int *first;

    base = (char *)&lbl_8049FD58;
    src = (struct TruckState *)fn_802678E4(arg0);
    dst = (struct TruckState *)(base + 0xF08 + arg0 * 0x228);
    first = (volatile int *)(base + 0xF08);
    first[arg0 * 0x8A] = src->unk_00;
    dst->unk_04 = src->unk_04;
    dst->unk_08 = src->unk_08;
    dst->unk_0C = src->unk_0C;
    dst->unk_10 = src->unk_10;
    dst->unk_14 = src->unk_14;
    dst->unk_18 = src->unk_18;
    dst->unk_1C = src->unk_1C;
    dst->unk_20 = src->unk_20;
    dst->unk_24 = src->unk_24;
    dst->unk_28[0] = src->unk_28[0];
    dst->unk_28[1] = src->unk_28[1];
    dst->unk_28[2] = src->unk_28[2];
    dst->unk_28[3] = src->unk_28[3];
    dst->unk_28[4] = src->unk_28[4];
    dst->unk_28[5] = src->unk_28[5];
    dst->unk_28[6] = src->unk_28[6];
    dst->unk_28[7] = src->unk_28[7];
    dst->unk_28[8] = src->unk_28[8];
    dst->unk_28[9] = src->unk_28[9];
    dst->unk_28[10] = src->unk_28[10];
    dst->unk_28[11] = src->unk_28[11];
    dst->unk_58[0] = src->unk_58[0];
    dst->unk_58[1] = src->unk_58[1];
    dst->unk_58[2] = src->unk_58[2];
    dst->unk_58[3] = src->unk_58[3];
    dst->unk_58[4] = src->unk_58[4];
    dst->unk_58[5] = src->unk_58[5];
    dst->unk_58[6] = src->unk_58[6];
    dst->unk_58[7] = src->unk_58[7];
    dst->unk_58[8] = src->unk_58[8];
    dst->unk_58[9] = src->unk_58[9];
    dst->unk_58[10] = src->unk_58[10];
    dst->unk_58[11] = src->unk_58[11];
    dst->unk_58[12] = src->unk_58[12];
    dst->unk_58[13] = src->unk_58[13];
    dst->unk_58[14] = src->unk_58[14];
    dst->unk_58[15] = src->unk_58[15];
    dst->unk_58[16] = src->unk_58[16];
    dst->unk_58[17] = src->unk_58[17];
    dst->unk_58[18] = src->unk_58[18];
    dst->unk_58[19] = src->unk_58[19];
    dst->unk_58[20] = src->unk_58[20];
    dst->unk_58[21] = src->unk_58[21];
    dst->unk_58[22] = src->unk_58[22];
    dst->unk_58[23] = src->unk_58[23];
    dst->unk_B8 = src->unk_B8;
    dst->unk_BC = src->unk_BC;
    dst->unk_C0[0] = src->unk_C0[0];
    dst->unk_C0[1] = src->unk_C0[1];
    dst->unk_C0[2] = src->unk_C0[2];
    dst->unk_C0[3] = src->unk_C0[3];
    dst->unk_C0[4] = src->unk_C0[4];
    dst->unk_C0[5] = src->unk_C0[5];
    dst->unk_C0[6] = src->unk_C0[6];
    dst->unk_C0[7] = src->unk_C0[7];
    dst->unk_C0[8] = src->unk_C0[8];
    dst->unk_C0[9] = src->unk_C0[9];
    dst->unk_C0[10] = src->unk_C0[10];
    dst->unk_C0[11] = src->unk_C0[11];
    dst->unk_C0[12] = src->unk_C0[12];
    dst->unk_C0[13] = src->unk_C0[13];
    dst->unk_C0[14] = src->unk_C0[14];
    dst->unk_C0[15] = src->unk_C0[15];
    dst->unk_C0[16] = src->unk_C0[16];
    dst->unk_C0[17] = src->unk_C0[17];
    dst->unk_C0[18] = src->unk_C0[18];
    dst->unk_C0[19] = src->unk_C0[19];
    dst->unk_C0[20] = src->unk_C0[20];
    dst->unk_C0[21] = src->unk_C0[21];
    dst->unk_C0[22] = src->unk_C0[22];
    dst->unk_C0[23] = src->unk_C0[23];
    dst->unk_C0[24] = src->unk_C0[24];
    dst->unk_C0[25] = src->unk_C0[25];
    dst->unk_C0[26] = src->unk_C0[26];
    dst->unk_12C[0] = src->unk_12C[0];
    dst->unk_12C[1] = src->unk_12C[1];
    dst->unk_12C[2] = src->unk_12C[2];
    dst->unk_138 = src->unk_138;
    dst->unk_139 = src->unk_139;
    dst->unk_13C = src->unk_13C;
    dst->unk_140 = src->unk_140;
    dst->unk_144 = src->unk_144;
    dst->unk_148 = src->unk_148;
    dst->unk_14C = src->unk_14C;
    dst->unk_150 = src->unk_150;
    dst->unk_154 = src->unk_154;
    dst->unk_158 = src->unk_158;
    dst->unk_15C = src->unk_15C;
    dst->unk_160[0] = src->unk_160[0];
    dst->unk_160[1] = src->unk_160[1];
    dst->unk_160[2] = src->unk_160[2];
    dst->unk_160[3] = src->unk_160[3];
    dst->unk_160[4] = src->unk_160[4];
    dst->unk_160[5] = src->unk_160[5];
    dst->unk_160[6] = src->unk_160[6];
    dst->unk_160[7] = src->unk_160[7];
    dst->unk_160[8] = src->unk_160[8];
    dst->unk_160[9] = src->unk_160[9];
    dst->unk_188 = src->unk_188;
    dst->unk_18C[0] = src->unk_18C[0];
    dst->unk_18C[1] = src->unk_18C[1];
    dst->unk_18C[2] = src->unk_18C[2];
    dst->unk_18C[3] = src->unk_18C[3];
    dst->unk_18C[4] = src->unk_18C[4];
    dst->unk_18C[5] = src->unk_18C[5];
    dst->unk_1A4[0] = src->unk_1A4[0];
    dst->unk_1A4[1] = src->unk_1A4[1];
    dst->unk_1A4[2] = src->unk_1A4[2];
    dst->unk_1A4[3] = src->unk_1A4[3];
    dst->unk_1A4[4] = src->unk_1A4[4];
    dst->unk_1A4[5] = src->unk_1A4[5];
    dst->unk_1A4[6] = src->unk_1A4[6];
    dst->unk_1A4[7] = src->unk_1A4[7];
    dst->unk_1A4[8] = src->unk_1A4[8];
    dst->unk_1A4[9] = src->unk_1A4[9];
    dst->unk_1A4[10] = src->unk_1A4[10];
    dst->unk_1A4[11] = src->unk_1A4[11];
    dst->unk_1D4 = src->unk_1D4;
    dst->unk_1D8[0] = src->unk_1D8[0];
    dst->unk_1D8[1] = src->unk_1D8[1];
    dst->unk_1D8[2] = src->unk_1D8[2];
    dst->unk_1D8[3] = src->unk_1D8[3];
    dst->unk_1D8[4] = src->unk_1D8[4];
    dst->unk_1EC = src->unk_1EC;
    dst->unk_1F0[0] = src->unk_1F0[0];
    dst->unk_1F0[1] = src->unk_1F0[1];
    dst->unk_1F0[2] = src->unk_1F0[2];
    dst->unk_1F0[3] = src->unk_1F0[3];
    dst->unk_1F0[4] = src->unk_1F0[4];
    dst->unk_1F0[5] = src->unk_1F0[5];
    dst->unk_1F0[6] = src->unk_1F0[6];
    dst->unk_1F0[7] = src->unk_1F0[7];
    dst->unk_1F0[8] = src->unk_1F0[8];
    dst->unk_1F0[9] = src->unk_1F0[9];
    dst->unk_1F0[10] = src->unk_1F0[10];
    dst->unk_1F0[11] = src->unk_1F0[11];
    dst->unk_1F0[12] = src->unk_1F0[12];
    dst->unk_1F0[13] = src->unk_1F0[13];

    ((float *)(base + 0x1868))[arg0] = lbl_80564048;

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
        float x = inv * input.x;
        float y = inv * input.y;
        float z = inv * input.z;
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

    target = (char *)base + 0x17A8 + arg0 * 0x30;
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
/* Return a camera blend's interpolation factor (elapsed / duration), or -1.0f if it is inactive. */
float fn_80277704(int blendIndex) {
    volatile unsigned char *blends = (volatile unsigned char *)&gCameraBlends;
    int byteOffset = blendIndex * 0x50;
    if (blends[byteOffset] != 0) {
        float *blend = (float *)((unsigned char *)blends + byteOffset);
        return (gBlendTime - *(float *)((unsigned char *)blend + 0x48)) /
               *(float *)((unsigned char *)blend + 0x44);
    }
    return BLEND_NONE;
}

/* Resets the camera table: record count (lbl_8055F5A0), the "rddefault" camera
   (lbl_8055F598) and the "house" camera (lbl_8055F59C) all back to zero. */
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
#pragma push
#pragma scheduling 603
void fn_80277828(void) {
    register struct CameraEntry *entry;
    register int i;
    register int one;
    register int zero;
    zero = 0;
    one = 1;
    ((struct CameraEntry *)lbl_8049FE98)->rot[0][0] = 1.0f;
    ((struct CameraEntry *)lbl_8049FE98)->rot[0][1] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->rot[0][2] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->rot[1][0] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->rot[1][1] = 1.0f;
    ((struct CameraEntry *)lbl_8049FE98)->rot[1][2] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->rot[2][0] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->rot[2][1] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->rot[2][2] = 1.0f;
    ((struct CameraEntry *)lbl_8049FE98)->pos[0] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->pos[1] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->pos[2] = 0.0f;
    ((struct CameraEntry *)lbl_8049FE98)->fov = 1.5707964f;
    ((struct CameraEntry *)lbl_8049FE98)->name[0] = zero;
    ((struct CameraEntry *)lbl_8049FE98)->inUse = one;

    if (lbl_8055F598 == 0) {
        char *fmt = *(char**)&lbl_8055C638;
        i = lbl_8055F5A0;
        entry = (struct CameraEntry *)&lbl_8049FEE0 + i;
        entry->rot[0][0] = 1.0f;
        entry->rot[0][1] = 0.0f;
        entry->rot[0][2] = 0.0f;
        entry->rot[1][0] = 0.0f;
        entry->rot[1][1] = 1.0f;
        entry->rot[1][2] = 0.0f;
        entry->rot[2][0] = 0.0f;
        entry->rot[2][1] = 0.0f;
        entry->rot[2][2] = 1.0f;
        entry->pos[0] = 0.0f;
        entry->pos[1] = 0.0f;
        entry->pos[2] = 0.0f;
        entry->fov = 1.5707964f;
        ((volatile char *)entry->name)[0] = zero;
        lbl_8055F5A0 = i + 1;
        lbl_8055F598 = (int)entry;
        entry->inUse = one;
        sprintf(entry->name, fmt);
    }
    if (lbl_8055F59C == 0) {
        i = lbl_8055F5A0;
        entry = (struct CameraEntry *)&lbl_8049FEE0 + i;
        lbl_8055F59C = (int)entry;
        lbl_8055F5A0 = i + 1;
        entry->inUse = 1;
        entry->fov = 1.4835298f;
        strcpy(((struct CameraEntry *)lbl_8055F59C)->name, &lbl_8055C644);
    }
}
#pragma pop
int fn_80277960(void *name, void *outCamera, float *outParam) {
    /* Look up the named camera record and copy its matrix, translation vector
     * and trailing float into the caller's outputs; return whether it was found. */
    struct Matrix { unsigned int words[9]; };
    struct Vector { unsigned int words[3]; };
    unsigned char *entry = (unsigned char *)fn_80276A44(name);
    if (entry != 0) {
        *(struct Matrix *)outCamera = *(struct Matrix *)(entry + 4);
        *(struct Vector *)((unsigned char *)outCamera + 0x24) = *(struct Vector *)(entry + 0x28);
        *outParam = *(float *)(entry + 0x34);
        return 1;
    }
    return 0;
}

void fn_80277A14(void *arg0, int arg1) {
    extern unsigned char lbl_804A0C60[];
    extern float lbl_804A15C0[];
    extern float lbl_80564048, lbl_8056404C, lbl_80564050, lbl_80564054, lbl_80564058, lbl_8056405C, lbl_80564060;
    extern float lbl_80564078, lbl_8056407C, lbl_80564080, lbl_80564084, lbl_80564088, lbl_8056408C;
    extern float lbl_80564090, lbl_80564094, lbl_80564098, lbl_8056409C;
    extern float PSVECMag(void *);
    extern double atan(double), cos(double), sin(double);
    extern void fn_80015A20();
    extern void fn_80015B20(void *, void *, void *);
    extern void fn_80020434(void *, void *);
    extern double fn_8002EF30(double, double, double);
    extern double fn_8002EFB0(double, double);
    extern int fn_80178CA4(void *, float);
    extern void *getRegisteredObject(int);
    extern int fn_801B89F8(void);
    extern float fn_801EA0E8(float, float, float, float, float, float, float, float);
    extern void fn_8026A51C(void *, signed char *, int);
    extern void fn_8026E22C(void *, void *, void *, float);
    extern void fn_8026E688(void *, void *, void *, void *, float);
    extern float fn_80277704(int);
    float sp90[9], spB4[3], sp3C[3], sp30[3], sp24[3], sp18[3], spC[3];
    float spC0[12];
    signed char sp8;
    float *cam = (float *)arg0;
    unsigned char *rec = lbl_804A0C60 + arg1 * 0x228;
    void *truck;
    float f2, f29, f30, f31, f0, f1, f3, f4, f5, f6, f7;
    int i;

    *(int *)(rec + 0x20) = *(int *)(rec + 0x24);
    *(int *)(rec + 0x10) = *(int *)(rec + 0x14);
    truck = getRegisteredObject(*(int *)(rec + 0x20));
    *(void **)(rec + 0x140) = truck;
    sp8 = 0;
    fn_8026A51C(rec, &sp8, arg1);
    if (fn_801B89F8() != 0) {
        fn_80020434((char *)arg0 + 0x58, (char *)arg0 + 0xBC);
        return;
    }
    f1 = fn_80277704(arg1);
    f2 = lbl_8056404C;
    if (f2 >= f1) f2 = f1;
    if (f2 <= lbl_80564048) f2 = lbl_80564048;
    f31 = lbl_80564054;
    if (!(f2 < f31)) {
        f31 = lbl_8056404C;
        if (f2 <= f31) {
            if (f2 > lbl_80564048)
                f31 = f2 * (lbl_80564058 * f2 * f2) + (lbl_8056405C * f2 * f2);
            else
                f31 = f2 * (lbl_80564058 * f2 * f2) - (lbl_8056405C * f2 * f2);
        }
    }
    spB4[0] = cam[0x3C];
    spB4[1] = cam[0x3A];
    spB4[2] = cam[0x3B];
    f30 = (float)fn_8002EFB0(cam[0x36], cam[0x38]);
    f29 = (float)cos(f30);
    f4 = (float)sin(f30);
    f2 = -f4;
    sp90[0] = f29; sp90[1] = lbl_80564048; sp90[2] = f2;
    sp90[3] = lbl_80564048; sp90[4] = lbl_8056404C; sp90[5] = lbl_80564048;
    sp90[6] = f4; sp90[7] = lbl_80564048; sp90[8] = f29;
    sp3C[0] = lbl_80564048; sp3C[1] = f31 * lbl_80564078; sp3C[2] = lbl_80564048;
    ((void (*)(void *, void *, float, float, float, float))fn_80015A20)(spC0, sp3C, lbl_8056404C, f2, lbl_80564048, f4);
    fn_80015B20(sp90, spC0, sp90);
    sp30[0] = lbl_80564048; sp30[1] = lbl_8056407C; sp30[2] = lbl_80564048;
    ((void (*)(void *, void *, float))fn_80015A20)(spC0, sp30, lbl_8056407C);
    fn_80015B20(sp90, spC0, sp90);
    sp24[0] = lbl_80564048; sp24[1] = lbl_80564048; sp24[2] = lbl_80564080;
    spC[0] = lbl_80564080 * sp90[6] + lbl_80564048 * sp90[0] + lbl_80564048 * sp90[3];
    spC[1] = lbl_80564080 * sp90[7] + lbl_80564048 * sp90[1] + lbl_80564048 * sp90[4];
    spC[2] = lbl_80564080 * sp90[8] + lbl_80564048 * sp90[2] + lbl_80564048 * sp90[5];
    spB4[0] += spC[0];
    spB4[1] += spC[1];
    spB4[2] += spC[2];
    f1 = PSVECMag((char *)truck + 0x118);
    f0 = lbl_8056404C;
    if (f0 < f1) f0 = f1;
    f29 = *(float *)((char *)truck + 0x118 + 4) / f0;
    if (*(int *)((char *)truck + 0x2620) == 0 && *(float *)((char *)truck + 0x118 + 4) < lbl_80564048) {
        f3 = lbl_8056404C;
        f0 = (-(cam[0x3A] - fn_801EA0E8(cam[0x39], cam[0x3B], 0,0,0,0,0,0)) / *(float *)((char *)truck + 0x118 + 4) - f29) / (lbl_80564048 - f29);
        if (f3 >= f0) f3 = f0;
        if (f3 <= lbl_80564048) f3 = lbl_80564048;
        f29 = lbl_80564084 + f3 * lbl_80564054;
    }
    i = arg1 * 4;
    f7 = lbl_804A15C0[i];
    f6 = f29 - f7;
    f5 = f7 + lbl_80564088 * f6;
    f4 = lbl_80564090 * f5;
    lbl_804A15C0[i] = f5;
    f3 = lbl_8056408C * f4;
    spB4[1] += f3;
    f0 = lbl_80564094 + fn_801EA0E8(lbl_804A15C0[0], spB4[0], spB4[2], f3, f4, f5, f6, f7);
    if (spB4[1] <= f0) spB4[1] = f0;
    sp18[0] = lbl_80564048; sp18[1] = lbl_8056404C; sp18[2] = lbl_80564048;
    fn_8026E688(sp90, spB4, (char *)arg0 + 0xE4, sp18, lbl_80564048);
    f29 = lbl_80564098;
    fn_8026E22C(spC0, (char *)rec + 0x58, sp90, f31);
    f1 = *(float *)(rec + 0xBC);
    f29 = f1 + f31 * (f29 - f1);
    if (fn_80178CA4(rec, f1) == 2) {
        f3 = f31 * lbl_8056409C;
        f29 = lbl_80564060 * (float)atan((lbl_8056404C + f3) * (float)fn_8002EF30(f29 * lbl_80564050, lbl_8056404C, f3));
    }
    for (i = 0; i < 12; i++) *(int *)((char *)arg0 + 0x58 + i * 4) = *(int *)&spC0[i];
    *(float *)((char *)arg0 + 0xBC) = f29;
}

#pragma cplusplus on
extern "C" void initCameraEntryFromConfig(void *arg0, void *arg1, int arg2) {
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

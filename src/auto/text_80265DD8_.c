extern char lbl_80499080[];
typedef struct { int w[0x8A]; } Rec_80269BB0;
typedef struct {
    int w0, w4; float f8, fc;
    int w10, w14, w18, w1c, w20, w24, w28, w2c, w30, w34, w38, w3c, w40, w44, w48, w4c;
    int w50, w54, w58, w5c, w60, w64, w68, w6c, w70, w74, w78;
    int w7c, w80, w84, w88, w8c, w90, w94, w98, w9c, wa0, wa4, wa8, wac, wb0, wb4, wb8;
    float fbc;
    int wc0, wc4, wc8, wcc, wd0, wd4, wd8, wdc, we0;
    int we4, we8, wec, wf0, wf4, wf8, wfc, w100, w104, w108, w10c, w110, w114, w118, w11c;
    int w120, w124, w128, w12c, w130, w134;
    unsigned char b138, b139;
    float f13c;
    int w140, w144, w148, w14c, w150;
    float f154, f158, f15c;
    int w160, w164, w168;
    float f16c, f170, f174;
    int w178, w17c;
    float f180, f184, pad188, f18c, f190, f194, f198, f19c, f1a0;
    int w1a4, w1a8, w1ac, w1b0, w1b4, w1b8, w1bc, w1c0, w1c4, w1c8, w1cc, w1d0;
    float f1d4;
    int w1d8, w1dc, w1e0, w1e4, w1e8;
    short h1ec;
    float f1f0, f1f4;
    int w1f8, w1fc, w200, w204, w208, w20c, w210, w214, w218, w21c, w220, w224;
} Rec2_80269BB0;
extern void fn_8027445C(void *);
extern void fn_80273BD0(void *);
extern void fn_802704D4(int, void *);
extern void fn_80274268(void *);
extern void fn_802E30C8(const char *, ...);
extern char lbl_803468F8[];
typedef struct { float x, y, z; } V3_80267EF8;
typedef struct { V3_80267EF8 r[4]; } M34_80267EF8;
typedef struct { float m[9]; } R9_80267EF8;
typedef struct { float m[9]; V3_80267EF8 pos; } MP_80267EF8;

/* One camera of the game's four-camera array.  The module keeps the
 * transform it used last frame next to the one it just built so
 * fn_802678E8 can blend between the two, and hands the result to the
 * renderer as rotation + position + field of view.  Fields no matched
 * function has named yet keep their raw w/f names. */
typedef struct Camera {
    int index;                    /* 0x000: which record this is (0..3) */
    int command;                  /* 0x004: request for the mode handler (0x15 from fn_80269BB0) */
    float f008, f00C;             /* 0x008 */
    int mode;                     /* 0x010: camera mode in use, 0..0x21 (10 = nothing yet) */
    int wantedMode;               /* 0x014: mode asked for; out-of-range falls back to 4 */
    int w018;                     /* 0x018 */
    int w01C;                     /* 0x01C: passed through to the renderer's frame */
    int subject;                  /* 0x020: index of the object the camera follows */
    int wantedSubject;            /* 0x024 */
    V3_80267EF8 up;               /* 0x028: up vector, (0,1,0) */
    V3_80267EF8 v034;             /* 0x034 */
    V3_80267EF8 v040;             /* 0x040 */
    int w04C[3];                  /* 0x04C */
    MP_80267EF8 transform;        /* 0x058: rotation + position in use */
    MP_80267EF8 prevTransform;    /* 0x088: the same, as of the last scene change */
    int scene;                    /* 0x0B8: scene stamp prevTransform belongs to */
    float fov;                    /* 0x0BC: field of view */
    MP_80267EF8 xform0C0;         /* 0x0C0: second transform (fn_802682B0 builds it from the track) */
    MP_80267EF8 xform0F0;         /* 0x0F0: third transform */
    float v120[6];                /* 0x120: two points handed to fn_8020655C */
    unsigned char reset;          /* 0x138: 1 = just (re)set; the next frame takes it whole */
    unsigned char b139;           /* 0x139: second one-shot flag, cleared with reset */
    float f13C;                   /* 0x13C */
    void *subjectObject;          /* 0x140: the followed object, looked up from subject */
    int w144;                     /* 0x144 */
    int w148;                     /* 0x148 */
    int w14C;                     /* 0x14C */
    int w150;                     /* 0x150 */
    float volume;                 /* 0x154: sound level this camera may ask for */
    float startTime;              /* 0x158: time that level was last raised */
    float f15C;                   /* 0x15C */
    int w160[3];                  /* 0x160: path cursor (fn_80265E08) */
    float f16C[3];                /* 0x16C */
    int w178[2];                  /* 0x178: spline cursor (fn_80266150) */
    float f180[2];                /* 0x180 */
    int pad188;                   /* 0x188 */
    float f18C[6];                /* 0x18C */
    float viewMatrix[12];         /* 0x1A4: 4x3 view matrix handed in by fn_8026A2CC */
    float angle;                  /* 0x1D4: view angle that goes with it */
    int w1D8[5];                  /* 0x1D8 */
    short h1EC;                   /* 0x1EC */
    short pad1EE;                 /* 0x1EE */
    float f1F0[2];                /* 0x1F0 */
    int w1F8[12];                 /* 0x1F8 */
} Camera;                        /* 0x228 bytes */

#define CAMERA_COUNT      4
#define CAMERA_SIZE       0x228
#define CAMERA_MODE_NONE  10      /* nothing chosen yet */
#define sCameras          lbl_80499080 /* Camera[CAMERA_COUNT] */
#define FLOAT_ZERO        lbl_80563C20 /* 0.0f */
#define FLOAT_ONE         lbl_80563C2C /* 1.0f */
#define CAMERA_VIEW_ANGLE lbl_80563C54 /* 1.1781f = 3*pi/8, the default view angle */
#define STR_CRASH_VOL     lbl_803467D0 /* "crash_vol" */
#define STR_CHEER3_SFX    lbl_803467DC /* "cheer3.sfx" */
#define sCrashVolume      lbl_8055F494 /* volume slot of STR_CRASH_VOL */
#define sCheerSound       lbl_8055F490 /* sound object of STR_CHEER3_SFX */
#define sound_volume_open fn_802090D4  /* name -> {float volume; int name} slot */
#define sound_volume_set  fn_80209190  /* slot, level (clamped to 0..1) */
#define sound_object_create fn_80207848 /* name, arg -> 0x70-byte sound object */
#define callback_install  fn_801EEFDC  /* fn, category -> first free of 4 slots */
extern float lbl_80563C80, lbl_80563C84, lbl_80563C88, lbl_80563C64;
extern float lbl_8055F48C;
extern int fn_802E2C20(void);
extern void fn_80209190(int, float);
extern int fn_8000D75C(void);
extern void fn_801769EC(void);
extern void fn_8022FF10(void *, void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int lbl_80499E50[];
extern double lbl_80563C38;
extern int lbl_8055C4B4;
extern int lbl_8055C4B8;
extern float lbl_8055C4BC;
extern float lbl_80563C30;
extern void fn_80135DC4(void *, int, int);
extern float fn_80134E34(float);
extern void fn_80136468(int *, void *, float);
extern float lbl_80563C28;
extern float lbl_80563C9C;
extern char lbl_80499950[];
extern void fn_80128670(void);
extern void fn_8013530C(void *, int);
extern void fn_80268BD4(void *, int, float, float);

extern char lbl_8055F488;
extern float lbl_8055F484;
extern float lbl_80499980[8];
extern float lbl_80563C6C;
extern float lbl_80563C20;
typedef struct { int w[12]; } W12_802693F4;
void fn_802693F4(char *p, unsigned char *flag, int arg);
extern void fn_80265E08(void*);
extern float lbl_80563C24;
extern float lbl_80563C44;
extern float lbl_80563C48;
extern float lbl_80563C2C;
extern float lbl_80563C34;
extern float lbl_80563C4C;
extern float lbl_80563C50;
extern float lbl_80563C98;
extern char lbl_80499920[];
extern float lbl_8055C4E0;
extern float lbl_8055C4E4;
extern int lbl_8055C4E8;
extern int lbl_8055C4EC;
extern int lbl_804999A0[];
extern float fn_80129DC4(int, float, float);
extern int fn_80129D90(int, int, int);
extern float PSVECMag(void*);
extern float fn_80144514(float,float,float,float,float,float);
extern float lbl_8055C4CC, lbl_8055C4D0, lbl_8055C4D4, lbl_8055C4D8, lbl_8055C4DC, lbl_8055F49C;
extern unsigned char lbl_8055C4C8, lbl_8055F498;
extern float lbl_80563C40;
extern double cos(float);
extern double sin(float);
extern float PSVECSquareDistance(void *, void *);
typedef struct { float *p; float f; } Res_80266388;
extern void fn_80136594(Res_80266388 *, void *, void *);
extern void *fn_801B2EC0(int);
typedef double (*DblFn_80266388)(int, float, float);
void fn_8026A2C8(void);
extern void fn_80274F74(void);
extern int fn_801769F8(void);
struct VObj_80266388;
typedef struct VTab_80266388 {
    void *pad[6];
    void *(*m18)(struct VObj_80266388 *);
    void *pad2[1];
    void *(*m20)(struct VObj_80266388 *);
} VTab_80266388;
typedef struct VObj_80266388 { VTab_80266388 *vt; } VObj_80266388;
static inline void fn_80266388_multiply(float *out, const float *a, const float *b) {
 float t0,t1,t2,t3,t4,t5,t6,t7,t8;
 if (out == a || out == b) {
 t0 = fn_80144514(b[0], a[0], b[3], a[1], b[6], a[2]);
 t3 = fn_80144514(b[0], a[3], b[3], a[4], b[6], a[5]);
 t6 = fn_80144514(b[0], a[6], b[3], a[7], b[6], a[8]);
 t1 = fn_80144514(b[1], a[0], b[4], a[1], b[7], a[2]);
 t4 = fn_80144514(b[1], a[3], b[4], a[4], b[7], a[5]);
 t7 = fn_80144514(b[1], a[6], b[4], a[7], b[7], a[8]);
 t2 = fn_80144514(b[2], a[0], b[5], a[1], b[8], a[2]);
 t5 = fn_80144514(b[2], a[3], b[5], a[4], b[8], a[5]);
 t8 = fn_80144514(b[2], a[6], b[5], a[7], b[8], a[8]);
 out[0] = t0; out[3] = t3; out[6] = t6;
 out[1] = t1; out[4] = t4; out[7] = t7;
 out[2] = t2; out[5] = t5; out[8] = t8;
 } else {
 out[0] = fn_80144514(b[0], a[0], b[3], a[1], b[6], a[2]);
 out[3] = fn_80144514(b[0], a[3], b[3], a[4], b[6], a[5]);
 out[6] = fn_80144514(b[0], a[6], b[3], a[7], b[6], a[8]);
 out[1] = fn_80144514(b[1], a[0], b[4], a[1], b[7], a[2]);
 out[4] = fn_80144514(b[1], a[3], b[4], a[4], b[7], a[5]);
 out[7] = fn_80144514(b[1], a[6], b[4], a[7], b[7], a[8]);
 out[2] = fn_80144514(b[2], a[0], b[5], a[1], b[8], a[2]);
 out[5] = fn_80144514(b[2], a[3], b[5], a[4], b[8], a[5]);
 out[8] = fn_80144514(b[2], a[6], b[5], a[7], b[8], a[8]);
 }
}
void* fn_80265DD8(void* arg0) {
    fn_80265E08(arg0);
    return arg0;
}

#pragma dont_inline on
void fn_80265E08(void* arg0) {
    float zero = lbl_80563C20;
    *(int*)((char*)arg0 + 0) = 0;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0xC) = zero;
    *(int*)((char*)arg0 + 4) = 0;
    *(int*)((char*)arg0 + 8) = 0;
}
#pragma dont_inline reset

#pragma dont_inline on
void fn_80265E2C(void) {
    #pragma scheduling invalid_target
    struct Record { float x; float y; int value; };
    float scale = lbl_80563C24;
    struct Record *record = (struct Record *)lbl_804999A0;
    int count = 0;

    do {
        record->x = scale * fn_80129DC4(6, -lbl_8055C4E0, lbl_8055C4E0);
        record->y = scale * fn_80129DC4(6, -lbl_8055C4E4, lbl_8055C4E4);
        {
            int value = fn_80129D90(6, lbl_8055C4E8, lbl_8055C4EC);
            count++;
            record->value = value;
        }
        record++;
    } while (count < 0x64);
}
#pragma dont_inline reset

#pragma scheduling invalid_target
void fn_80265EC4(void *arg0, int arg1, int arg2) {
    struct Record { float first; float second; int duration; };
    int *state = (int *)arg0;
    int index;
    int elapsed;
    int duration;
    int nextIndex;
    int updatedElapsed;
    float ratio;
    float weight;
    struct Record *current;
    struct Record *next;

    if (arg2 != 0) {
        state[2] = arg1;
        return;
    }
    state[1] = state[1] + (arg1 - state[2]);
    state[2] = arg1;
    goto check;

advance:
    index = *(volatile int *)arg0;
    elapsed = *(volatile int *)((char *)arg0 + 4);
    nextIndex = (index + 1) % 100;
    updatedElapsed = elapsed - duration;
    *(volatile int *)((char *)arg0 + 4) = updatedElapsed;
    *(volatile int *)arg0 = nextIndex;

check:
    index = *(volatile int *)arg0;
    elapsed = *(volatile int *)((char *)arg0 + 4);
    duration = ((struct Record *)lbl_804999A0)[index].duration;
    if (elapsed > duration) {
        goto advance;
    }

    ratio = (float)elapsed / (float)duration;
    if (ratio < lbl_80563C28) {
        weight = lbl_80563C28;
        goto weight_done;
    }
    if (ratio > lbl_80563C2C) {
        weight = lbl_80563C2C;
    } else if (ratio > lbl_80563C20) {
        weight = (((lbl_80563C30 * ratio) * ratio) * ratio) +
                 ((lbl_80563C34 * ratio) * ratio);
    } else {
        weight = (((lbl_80563C30 * ratio) * ratio) * ratio) -
                 ((lbl_80563C34 * ratio) * ratio);
    }
weight_done:
    *(float *)((char *)arg0 + 0xC) = weight;
    index = *(volatile int *)arg0;
    nextIndex = (index + 1) % 100;
    current = &((struct Record *)lbl_804999A0)[index];
    next = &((struct Record *)lbl_804999A0)[nextIndex];
    *(float *)((char *)arg0 + 0x10) =
        current->first + (float)(double)weight * (next->first - current->first);
    *(float *)((char *)arg0 + 0x14) =
        current->second + (float)(double)weight * (next->second - current->second);
}
#pragma scheduling on
void fn_80266070(void *arg0, void *arg1, void *arg2, void *arg3) {
    volatile float scaled[3];
    float mag;
    float f;
    float y;
    float xOut;
    float yOut;
    float zOut;
    float *out = (float *)arg1;
    float *base = (float *)arg2;
    float scale = *(float *)((char *)arg0 + 0x10);
    scaled[0] = *(float *)((char *)arg3 + 0) * scale;
    scaled[1] = *(float *)((char *)arg3 + 4) * scale;
    scaled[2] = *(float *)((char *)arg3 + 8) * scale;
    mag = PSVECMag(arg3);
    f = *(float *)((char *)arg0 + 0x14) * mag;
    y = scaled[1] + f;
    xOut = base[0] + scaled[0];
    yOut = base[1] + y;
    zOut = base[2] + scaled[2];
    out[0] = xOut;
    out[1] = yOut;
    out[2] = zOut;
}

extern float lbl_8055C4C0;
extern float lbl_80563C2C;
extern float lbl_8055C4C4;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
void fn_80266150(void *arg0);
int fn_80178CA4(void);
float PSQUATMultiply(float *arg0, int arg1);
void *fn_80266120(void *arg0) {
    fn_80266150(arg0);
    return arg0;
}

#pragma dont_inline on
void fn_80266150(void *arg0) {
    *(float *)((char *)arg0 + 0xC) = lbl_80563C2C;
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0) = 0;
    *(float *)((char *)arg0 + 8) = lbl_8055C4C0;
}
#pragma dont_inline reset

void fn_80266170(void *arg0, int arg1, int arg2, int arg3, float farg0) {
    float temp_f0;
    float temp_f0_2;
    float var_f3;
    float temp_f4;
    float var_f0;
    register float var_f4;
    int temp_r0_2;
    int temp_r0;

    if (arg3 != 0) {
        register float reset_scale;
        register float reset_limit;
        *(int *)((char *)arg0 + 0) = arg1;
        *(int *)((char *)arg0 + 4) = 0;
        reset_scale = lbl_8055C4BC;
        reset_limit = lbl_8055C4C0;
        var_f0 = reset_scale * farg0;
        var_f0 = (var_f0 < reset_limit) ? var_f0 : reset_limit;
        *(float *)((char *)arg0 + 8) = var_f0;
    }
    if (arg2 != 0) {
        *(int *)((char *)arg0 + 0) = arg1;
        return;
    }
    temp_r0 = *(int *)((char *)arg0 + 0);
    temp_r0_2 = *(int *)((char *)arg0 + 4);
    temp_r0 = arg1 - temp_r0;
    *(int *)((char *)arg0 + 0) = arg1;
    temp_r0 = temp_r0_2 + temp_r0;
    *(int *)((char *)arg0 + 4) = temp_r0;
    var_f4 = lbl_80563C2C;
    temp_f0 = (float)lbl_8055C4B4;
    temp_f0_2 = ((float)temp_r0 - temp_f0) / ((float)lbl_8055C4B8 - temp_f0);
    var_f4 = (var_f4 < temp_f0_2) ? var_f4 : temp_f0_2;
    var_f4 = (var_f4 > lbl_80563C20) ? var_f4 : lbl_80563C20;
    var_f3 = lbl_80563C28;
    temp_f4 = lbl_80563C20 + (var_f4 * lbl_80563C2C);
    if (temp_f4 < var_f3) {
    } else if (temp_f4 > lbl_80563C2C) {
        var_f3 = lbl_80563C2C;
    } else if (temp_f4 > lbl_80563C20) {
        var_f3 = (temp_f4 * (lbl_80563C30 * temp_f4 * temp_f4)) +
                 (lbl_80563C34 * temp_f4 * temp_f4);
    } else {
        var_f3 = (temp_f4 * (lbl_80563C30 * temp_f4 * temp_f4)) -
                 (lbl_80563C34 * temp_f4 * temp_f4);
    }
    *(float *)((char *)arg0 + 0xC) = var_f3;
}

void fn_802662D8(float *arg0, float *arg1, float *arg2, float *arg3, int arg4) {
    float t;
    float weight;
    float factor;
    float x;
    float y;
    float z;

    t = PSQUATMultiply(arg2, arg4) - lbl_8055C4C4;
    weight = arg0[3];
    t = t - lbl_80563C20;
    factor = lbl_80563C20 + weight * t;
    x = arg2[0] + arg3[0] * factor;
    y = arg2[1] + arg3[1] * factor;
    z = arg2[2] + arg3[2] * factor;
    arg1[0] = x;
    arg1[1] = y;
    arg1[2] = z;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80266388(int unused, int mode, float *matrix, void *pos, void *owner) {
    float *opos;
    void *cam;
    char *sel;
    int i, count;
    char *o;
    float zero, base, best, s1, s2, ka, kb, d, t, u, a, b;
    float rot[9];
    Res_80266388 r;
    Res_80266388 r2;
    volatile float w[3];
    float v[3];
    float p2[2];
    float q[2];
    if (mode == 0) {
        VObj_80266388 *camobj = *(VObj_80266388 **)((char *)owner + 0x270);
        cam = camobj->vt->m18(camobj);
        p2[0] = matrix[9];
        p2[1] = matrix[11];
        fn_80136594(&r, cam, p2);
        base = lbl_8055C4CC + (r.p[7] + r.p[6] * r.f);
        count = ((int (*)(void))fn_8026A2C8)();
        best = lbl_8055F49C;
        zero = lbl_80563C20;
        sel = 0;
        for (i = 0; i < count; i++) {
            VObj_80266388 *ob = (VObj_80266388 *)fn_801B2EC0(i);
            o = (char *)ob->vt->m20(ob);
            opos = (float *)(o + 0x60);
            q[0] = opos[0];
            q[1] = opos[2];
            fn_80136594(&r2, cam, q);
            d = (r2.p[7] + r2.p[6] * r2.f) - base;
            if (d < zero) {
                void *c4 = *(void **)((char *)cam + 4);
                int idx = c4 ? *((unsigned char *)c4 + 0x34) : 3;
                d += *(float *)(*(char **)((char *)cam + 0x2C) + idx * 4 + 8);
            }
            if (d * d < lbl_8055F49C) {
                float sq = PSVECSquareDistance(pos, opos);
                if (sq < best) {
                    best = sq;
                    sel = o;
                }
            }
        }
        if (sel != 0) {
            t = (*(float *)(sel + 0x25CC) - lbl_8055C4D0) / (lbl_8055C4D4 - lbl_8055C4D0);
            a = lbl_80563C2C;
            if (a < t) {
            } else {
                a = t;
            }
            if (a > lbl_80563C20) {
            } else {
                a = lbl_80563C20;
            }
            u = (best - lbl_8055F49C) / (lbl_80563C20 - lbl_8055F49C);
            ka = lbl_80563C20 + a * lbl_80563C2C;
            b = lbl_80563C2C;
            if (b < u) {
            } else {
                b = u;
            }
            if (b > lbl_80563C20) {
            } else {
                b = lbl_80563C20;
            }
            kb = lbl_80563C20 + b * lbl_80563C2C;
            s1 = lbl_8055C4D8 * (ka * kb);
            s2 = lbl_8055C4DC * (ka * kb);
            if (lbl_8055F498 != 0) {
                double c1 = ((DblFn_80266388)fn_80129DC4)(6, -s1, s1);
                double c2 = ((DblFn_80266388)fn_80129DC4)(6, -s1, s1);
                double c3 = ((DblFn_80266388)fn_80129DC4)(6, -s1, s1);
                w[0] = c3; w[1] = c2; w[2] = c1;
                matrix[9] = matrix[9] + (float)c3;
                matrix[10] = matrix[10] + (float)c2;
                matrix[11] = matrix[11] + (float)c1;
            }
            if (lbl_8055C4C8 != 0) {
                float mag, x, y, z, sn, cs, one, scale;
                double c1 = ((DblFn_80266388)fn_80129DC4)(6, -s2, s2);
                double c2 = ((DblFn_80266388)fn_80129DC4)(6, -s2, s2);
                double c3 = ((DblFn_80266388)fn_80129DC4)(6, -s2, s2);
                v[0] = c3; v[1] = c2; v[2] = c1;
                mag = PSVECMag(&v[0]);
                if (mag > lbl_80563C40) {
                    scale = lbl_80563C2C / mag;
                    x = scale * v[0]; y = scale * v[1]; z = scale * v[2];
                    sn = sin(mag); cs = cos(mag); one = lbl_80563C2C - cs;
                    rot[0] = cs + one * (x * x); rot[1] = y * (one * x) + sn * z; rot[2] = z * (one * x) - sn * y;
                    rot[3] = y * (one * x) - sn * z; rot[4] = cs + one * (y * y); rot[5] = z * (one * y) + sn * x;
                    rot[6] = z * (one * x) + sn * y; rot[7] = z * (one * y) - sn * x; rot[8] = cs + one * (z * z);
                } else {
                    rot[0] = lbl_80563C2C; rot[1] = lbl_80563C20; rot[2] = lbl_80563C20;
                    rot[3] = lbl_80563C20; rot[4] = lbl_80563C2C; rot[5] = lbl_80563C20;
                    rot[6] = lbl_80563C20; rot[7] = lbl_80563C20; rot[8] = lbl_80563C2C;
                }
                fn_80266388_multiply(matrix, matrix, rot);
            }
        }
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80266A0C(float *fs, int unused, void *pos) {
    float *opos;
    void *cam;
    char *sel;
    int i, count;
    char *o;
    float zero, base, best, s1, s2, ka, kb, d, t, u, a, b;
    float rot[9];
    Res_80266388 r;
    Res_80266388 r2;
    volatile float w[3];
    float v[3];
    float p2[2];
    float q[2];
    fn_80274F74();
    if (fn_801769F8() == 0) {
        VObj_80266388 *camobj = *(VObj_80266388 **)(*(char **)((char *)fs + 0x140) + 0x270);
        cam = camobj->vt->m18(camobj);
        p2[0] = fs[0x7C / 4];
        p2[1] = fs[0x84 / 4];
        fn_80136594(&r, cam, p2);
        base = lbl_8055C4CC + (r.p[7] + r.p[6] * r.f);
        count = ((int (*)(void))fn_8026A2C8)();
        best = lbl_8055F49C;
        zero = lbl_80563C20;
        sel = 0;
        for (i = 0; i < count; i++) {
            VObj_80266388 *ob = (VObj_80266388 *)fn_801B2EC0(i);
            o = (char *)ob->vt->m20(ob);
            opos = (float *)(o + 0x60);
            q[0] = opos[0];
            q[1] = opos[2];
            fn_80136594(&r2, cam, q);
            d = (r2.p[7] + r2.p[6] * r2.f) - base;
            if (d < zero) {
                void *c4 = *(void **)((char *)cam + 4);
                int idx = c4 ? *((unsigned char *)c4 + 0x34) : 3;
                d += *(float *)(*(char **)((char *)cam + 0x2C) + idx * 4 + 8);
            }
            if (d * d < lbl_8055F49C) {
                float sq = PSVECSquareDistance(pos, opos);
                if (sq < best) {
                    best = sq;
                    sel = o;
                }
            }
        }
        if (sel != 0) {
            t = (*(float *)(sel + 0x25CC) - lbl_8055C4D0) / (lbl_8055C4D4 - lbl_8055C4D0);
            a = lbl_80563C2C;
            if (a < t) {
            } else {
                a = t;
            }
            if (a > lbl_80563C20) {
            } else {
                a = lbl_80563C20;
            }
            u = (best - lbl_8055F49C) / (lbl_80563C20 - lbl_8055F49C);
            ka = lbl_80563C20 + a * lbl_80563C2C;
            b = lbl_80563C2C;
            if (b < u) {
            } else {
                b = u;
            }
            if (b > lbl_80563C20) {
            } else {
                b = lbl_80563C20;
            }
            kb = lbl_80563C20 + b * lbl_80563C2C;
            s1 = lbl_8055C4D8 * (ka * kb);
            s2 = lbl_8055C4DC * (ka * kb);
            if (lbl_8055F498 != 0) {
                double c1 = ((DblFn_80266388)fn_80129DC4)(6, -s1, s1);
                double c2 = ((DblFn_80266388)fn_80129DC4)(6, -s1, s1);
                double c3 = ((DblFn_80266388)fn_80129DC4)(6, -s1, s1);
                w[0] = c3; w[1] = c2; w[2] = c1;
                fs[0x7C / 4] = fs[0x7C / 4] + (float)c3;
                fs[0x80 / 4] = fs[0x80 / 4] + (float)c2;
                fs[0x84 / 4] = fs[0x84 / 4] + (float)c1;
            }
            if (lbl_8055C4C8 != 0) {
                float mag, x, y, z, sn, cs, one, scale;
                double c1 = ((DblFn_80266388)fn_80129DC4)(6, -s2, s2);
                double c2 = ((DblFn_80266388)fn_80129DC4)(6, -s2, s2);
                double c3 = ((DblFn_80266388)fn_80129DC4)(6, -s2, s2);
                v[0] = c3; v[1] = c2; v[2] = c1;
                mag = PSVECMag(&v[0]);
                if (mag > lbl_80563C40) {
                    scale = lbl_80563C2C / mag;
                    x = scale * v[0]; y = scale * v[1]; z = scale * v[2];
                    sn = sin(mag); cs = cos(mag); one = lbl_80563C2C - cs;
                    rot[0] = cs + one * (x * x); rot[1] = y * (one * x) + sn * z; rot[2] = z * (one * x) - sn * y;
                    rot[3] = y * (one * x) - sn * z; rot[4] = cs + one * (y * y); rot[5] = z * (one * y) + sn * x;
                    rot[6] = z * (one * x) + sn * y; rot[7] = z * (one * y) - sn * x; rot[8] = cs + one * (z * z);
                } else {
                    rot[0] = lbl_80563C2C; rot[1] = lbl_80563C20; rot[2] = lbl_80563C20;
                    rot[3] = lbl_80563C20; rot[4] = lbl_80563C2C; rot[5] = lbl_80563C20;
                    rot[6] = lbl_80563C20; rot[7] = lbl_80563C20; rot[8] = lbl_80563C2C;
                }
                fn_80266388_multiply(fs + 0x58 / 4, fs + 0x58 / 4, rot);
            }
        }
    }
}
#pragma pop

#pragma pop

#pragma dont_inline on
void fn_802670A0(int *arg0, int arg1) {
    int count;
    int cols;
    int div;
    int a;
    int b;

    count = fn_80178CA4();
    cols = (count > 1) ? 2 : 1;
    div = (count + cols - 1) / cols;
    a = lbl_8055CFF0 / cols;
    b = lbl_8055CFF4 / div;
    arg0[16] = a;
    arg0[17] = b;
    arg0[14] = a * (arg1 / div);
    arg0[15] = b * (arg1 % div);
}

#pragma scheduling invalid_target
void fn_80267130(void *arg0) {
    float value;
    float clamp;
    clamp = lbl_80563C2C;
    value = (*(float *)((char *)arg0 + 0x30) - lbl_80563C44) / lbl_80563C48;
    clamp = clamp < value ? value : clamp;
    clamp = clamp > lbl_80563C20 ? lbl_80563C20 : clamp;
    *(float *)((char *)arg0 + 0x48) = lbl_80563C34 + clamp * lbl_80563C4C;
    if (fn_80178CA4() == 1) value = lbl_80563C2C;
    else value = lbl_80563C50;
    *(float *)((char *)arg0 + 0x4C) = lbl_8055F484 * value;
}
#pragma scheduling on
extern float lbl_8055D020;
extern double lbl_80563C38;
extern float fn_801EA0E8(float, float);
#pragma push
#pragma ppc_psq_save off
void fn_802671CC(void *arg0, int arg1) {
    union IntDouble {
        double value;
        unsigned int word[2];
    };
    struct Scratch {
        float output[3];
        float input[3];
        union IntDouble width;
        union IntDouble height;
    } scratch;
    float *in = scratch.input;
    float *out = scratch.output;
    float *matrix;
    unsigned int widthBits;
    unsigned int heightBits;
    float z;
    float delta;
    float xstep;
    float widthValue;
    float heightValue;
    float ystep;
    float best;
    double bias;
    int i;

    widthBits = *(unsigned int *)((char *)arg0 + 0x44) ^ 0x80000000;
    heightBits = *(unsigned int *)((char *)arg0 + 0x40) ^ 0x80000000;
    scratch.width.word[0] = 0x43300000;
    scratch.width.word[1] = widthBits;
    matrix = (float *)arg0;
    z = *(float *)((char *)arg0 + 0x48);
    delta = z * *(float *)((char *)arg0 + 0x34);
    xstep = delta / lbl_8055D020;
    scratch.height.word[1] = heightBits;
    scratch.height.word[0] = 0x43300000;
    bias = lbl_80563C38;
    widthValue = (float)(scratch.width.value - bias);
    heightValue = (float)(scratch.height.value - bias);
    ystep = widthValue * delta / heightValue;
    best = lbl_80563C20;
    i = 0;

    for (; i < 4; i++) {
        float x;
        float y;
        float heightDiff;

        if ((i & 1) != 0) x = xstep;
        else x = -xstep;
        if ((i & 2) != 0) y = ystep;
        else y = -ystep;

        in[0] = x;
        in[1] = y;
        in[2] = z;
        if (out == in) {
            out[0] = x * matrix[0] + y * matrix[3] + z * matrix[6];
            out[1] = x * matrix[1] + y * matrix[4] + z * matrix[7];
            out[2] = x * matrix[2] + y * matrix[5] + z * matrix[8];
        } else {
            out[0] = in[0] * matrix[0] + in[1] * matrix[3] + in[2] * matrix[6];
            out[1] = in[0] * matrix[1] + in[1] * matrix[4] + in[2] * matrix[7];
            out[2] = in[0] * matrix[2] + in[1] * matrix[5] + in[2] * matrix[8];
        }
        out[0] += matrix[9];
        out[1] += matrix[10];
        out[2] += matrix[11];
        heightDiff = fn_801EA0E8(out[0], out[2]) - out[1];
        if (best > heightDiff) best = heightDiff;
    }

    if (*(int *)((char *)arg0 + 0x58) != 0x11 &&
        *(int *)((char *)arg0 + 0x58) != 0x15) {
        *(float *)((char *)arg0 + 0x28) += best;
    }
    (void)arg1;
}
#pragma pop
#pragma dont_inline reset

extern int fn_8026A554(int *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* fn_80267420 - camera module init, run once at boot.
 *
 * Clears each of the CAMERA_COUNT camera records in sCameras and gives it
 * its starting state: its index, mode and subject CAMERA_MODE_NONE (nothing
 * to follow yet), an up vector of (0,1,0), identity rotations for the
 * current transform, its saved copy and the two helper transforms, zeroed
 * blend points, the reset flag set so the first frame is taken whole, and
 * the view matrix the game feeds in from outside identity with the default
 * view angle.  Then the camera helpers in the 0x8026E870..0x80278214 units
 * are initialised, the two ambience sounds the cameras drive are opened -
 * a volume slot for "crash_vol" and a sound object for "cheer3.sfx" - the
 * module installs its category-13 callback (fn_8026A554), and fn_80267680
 * lays the per-frame defaults on top.
 */
void fn_80267420(void) {
    extern void *__AXFXGetLfoSinTable_801769CC(void);
    extern float FLOAT_ZERO, FLOAT_ONE, CAMERA_VIEW_ANGLE;
    extern int sCrashVolume;
    extern void *sCheerSound;
    extern char STR_CRASH_VOL[], STR_CHEER3_SFX[];
    extern void fn_80276B8C(void), fn_80278214(void), fn_80273354(void), fn_8027045C(void);
    extern void fn_80267680(void), fn_80268D94(void), fn_80268E00(void);
    extern int sound_volume_open(void *);
    extern void *sound_object_create(void *, int);
    extern void callback_install(void *, int);
    extern void *memset(void *, int, unsigned long);
    char *p;
    float angle, one, zero;
    int i;

    __AXFXGetLfoSinTable_801769CC(); /* game-state object; result unused */
    zero = FLOAT_ZERO;
    one = FLOAT_ONE;
    p = sCameras;
    angle = CAMERA_VIEW_ANGLE;
    for (i = 0; i < CAMERA_COUNT; i++, p += CAMERA_SIZE) {
        Camera *cam = (Camera *)p;

        memset(p, 0, CAMERA_SIZE);
        cam->index = i;
        cam->f008 = zero;
        cam->f00C = zero;
        cam->wantedSubject = 0;
        cam->subject = 0;
        cam->wantedMode = CAMERA_MODE_NONE;
        cam->mode = CAMERA_MODE_NONE;
        cam->up.x = zero;
        cam->up.y = one;
        cam->up.z = zero;
        cam->v034.x = zero;
        cam->v034.y = zero;
        cam->v034.z = zero;
        cam->reset = 1;
        cam->transform.m[0] = one;
        cam->transform.m[1] = zero;
        cam->transform.m[2] = zero;
        cam->transform.m[3] = zero;
        cam->transform.m[4] = one;
        cam->transform.m[5] = zero;
        cam->transform.m[6] = zero;
        cam->transform.m[7] = zero;
        cam->transform.m[8] = one;
        cam->transform.pos.x = zero;
        cam->transform.pos.y = zero;
        cam->transform.pos.z = zero;
        *(R9_80267EF8 *)&cam->prevTransform = *(R9_80267EF8 *)&cam->transform;
        cam->prevTransform.pos = cam->transform.pos;
        cam->v120[0] = zero;
        cam->v120[1] = zero;
        cam->v120[2] = zero;
        cam->v120[3] = zero;
        cam->v120[4] = zero;
        cam->v120[5] = zero;
        cam->xform0F0.m[0] = one;
        cam->xform0F0.m[1] = zero;
        cam->xform0F0.m[2] = zero;
        cam->xform0F0.m[3] = zero;
        cam->xform0F0.m[4] = one;
        cam->xform0F0.m[5] = zero;
        cam->xform0F0.m[6] = zero;
        cam->xform0F0.m[7] = zero;
        cam->xform0F0.m[8] = one;
        cam->xform0F0.pos.x = zero;
        cam->xform0F0.pos.y = zero;
        cam->xform0F0.pos.z = zero;
        cam->xform0C0.m[0] = one;
        cam->xform0C0.m[1] = zero;
        cam->xform0C0.m[2] = zero;
        cam->xform0C0.m[3] = zero;
        cam->xform0C0.m[4] = one;
        cam->xform0C0.m[5] = zero;
        cam->xform0C0.m[6] = zero;
        cam->xform0C0.m[7] = zero;
        cam->xform0C0.m[8] = one;
        cam->xform0C0.pos.x = zero;
        cam->xform0C0.pos.y = zero;
        cam->xform0C0.pos.z = zero;
        cam->subjectObject = 0;
        cam->w144 = 0;
        cam->command = CAMERA_MODE_NONE;
        cam->w01C = CAMERA_MODE_NONE;
        cam->viewMatrix[0] = one;
        cam->viewMatrix[1] = zero;
        cam->viewMatrix[2] = zero;
        cam->viewMatrix[3] = zero;
        cam->viewMatrix[4] = one;
        cam->viewMatrix[5] = zero;
        cam->viewMatrix[6] = zero;
        cam->viewMatrix[7] = zero;
        cam->viewMatrix[8] = one;
        cam->viewMatrix[9] = zero;
        cam->viewMatrix[10] = zero;
        cam->viewMatrix[11] = zero;
        cam->angle = angle;
    }
    fn_80276B8C();
    fn_80268D94();
    fn_80268E00();
    fn_80278214();
    fn_80273354();
    fn_8027045C();
    sCrashVolume = sound_volume_open(STR_CRASH_VOL);
    sCheerSound = sound_object_create(STR_CHEER3_SFX, 0);
    callback_install((void *)fn_8026A554, 0xD);
    fn_80267680();
}
#pragma pop

#pragma scheduling invalid_target
#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw on
void fn_80267680(void) {
    extern float lbl_80563C54, lbl_80563C58, lbl_80563C5C, lbl_80563C60, lbl_80563C64;
    extern int lbl_8055F494;
    extern float lbl_8055F48C;
    extern void fn_802733C8(void);
    extern int fn_80276BE4(int, int);
    extern void fn_801E9DC4(int *);
    extern void fn_80209190(int, float);
    extern void fn_80268B94(int);
    extern void fn_80270484(void);
    struct StackData {
        float matrix[12];
        union { double d; unsigned int word[2]; } value;
    };
    char *p;
    volatile struct StackData temp;
    unsigned int high;
    int oneInt, minusOne, zeroInt, i;
    float bottom, limit;
    double conversionConstant;
    float start, angle, one, zero;
    fn_802733C8();
    zero = lbl_80563C20;
    one = lbl_80563C2C;
    p = lbl_80499080;
    angle = lbl_80563C54;
    i = 0;
    start = lbl_80563C58;
    conversionConstant = lbl_80563C38;
    zeroInt = 0;
    limit = lbl_80563C5C;
    minusOne = -1;
    bottom = lbl_80563C60;
    oneInt = 1;
    high = 0x43300000;
    do {
        *(float *)(p + 8) = zero;
        *(float *)(p + 0xC) = zero;
        *(int *)(p + 0x144) = zeroInt;
        *(int *)(p + 0xB8) = minusOne;
        *(unsigned char *)(p + 0x138) = (unsigned char)oneInt;
        *(unsigned char *)(p + 0x139) = (unsigned char)oneInt;
        *(float *)(p + 0x13C) = zero;
        *(float *)(p + 0x40) = zero;
        *(float *)(p + 0x44) = zero;
        *(float *)(p + 0x48) = zero;
        *(float *)(p + 0x28) = zero;
        *(float *)(p + 0x2C) = one;
        *(float *)(p + 0x30) = zero;
        *(int *)(p + 0x148) = zeroInt;
        *(float *)(p + 0x194) = angle;
        fn_80265E08(p + 0x160);
        fn_80266150(p + 0x178);
        temp.value.word[0] = high;
        temp.value.word[1] = ((unsigned int)i) ^ 0x80000000;
        *(float *)(p + 0x158) = start;
        *(float *)(p + 0x15C) = temp.value.d - conversionConstant;
        *(float *)(p + 0x198) = zero;
        *(float *)(p + 0x19C) = zero;
        *(int *)(p + 0x14C) = minusOne;
        *(int *)(p + 0x150) = minusOne;
        if (fn_801796B4() == 0) {
            temp.matrix[0] = one;
            temp.matrix[1] = zero;
            temp.matrix[2] = zero;
            temp.matrix[3] = zero;
            temp.matrix[4] = one;
            temp.matrix[5] = zero;
            temp.matrix[6] = zero;
            temp.matrix[7] = zero;
            temp.matrix[8] = one;
            temp.matrix[9] = zero;
            temp.matrix[10] = zero;
            temp.matrix[11] = zero;
            fn_80276BE4((int)(p + 0x1A4), (int)(p + 0x1D4));
        }
        fn_801E9DC4((int *)(p + 0x1EC));
        *(float *)(p + 0x1F8) = one;
        ++i;
        *(float *)(p + 0x1FC) = zero;
        *(float *)(p + 0x200) = zero;
        *(float *)(p + 0x204) = zero;
        *(float *)(p + 0x208) = one;
        *(float *)(p + 0x20C) = zero;
        *(float *)(p + 0x210) = zero;
        *(float *)(p + 0x214) = zero;
        *(float *)(p + 0x218) = one;
        *(float *)(p + 0x21C) = zero;
        *(float *)(p + 0x220) = zero;
        *(float *)(p + 0x224) = zero;
        *(float *)(p + 0x1F4) = limit;
        *(float *)(p + 0x1F0) = bottom;
        p += 0x228;
    } while (i < 4);
    lbl_8055F488 = 0;
    lbl_8055F48C = lbl_80563C64;
    fn_80209190(lbl_8055F494, lbl_80563C2C);
    fn_80265E2C();
    fn_80268B94(0);
    fn_80270484();
    zero = lbl_80563C20;
    {
        float *out = lbl_80499980;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma pop
extern void *lbl_8055F490;
extern int lbl_8055F494;
extern void *fn_80267EE4(int);
extern void fn_801EF024(void *);
extern void fn_80278288(void);
extern void fn_802733F0(void);
extern void fn_80209110(void *);
extern float lbl_8055E3C8;
void *fn_802678E4(int arg0) {
    return fn_80267EE4(arg0);
}

extern void fn_80267EE0(void);
extern int fn_801C5B68(void *, int);
extern void fn_8026B768(int, int), fn_80268E94(void *, int), fn_8020655C(void *, int);
extern void *fn_8017960C(int);
extern int fn_801769F8(void), fn_8026B734(int, float *);
extern float fn_801B8950(int), PSVECDotProduct(void *, void *);
extern double fn_8002EF30(float), fabs(double);
extern int lbl_8055E3C4;
extern char lbl_8055F480;
extern float lbl_8055E460, lbl_80563C68, lbl_80563C70, lbl_80563C74, lbl_80563C78, lbl_80563C7C;
#pragma push
#pragma inline off
extern double fn_8002EF30(float), __fabs(double);
#pragma push
#pragma unroll_loops off
void fn_802678E8(void *arg0, int arg1) {
 struct Frame { unsigned char flag; char gap0[3]; float height; char gap1[4]; float y; char gap2[12]; float z; int object; void *matrix; void *extra; float x; char gap3[8]; MP_80267EF8 transform; } frame;
 char *p, *entity; int flags, i; float height, t;
 fn_802670A0(arg0, arg1);
 if (fn_801C5B68(arg0,arg1)) { fn_80267130(arg0); return; }
 p = fn_80267EE4(arg1);
 *(float *)(p+0x1a0) = lbl_80563C28;
 fn_8026B768(*(int *)(p+0x20), arg1);
 if (lbl_8055E3C4 != *(int *)(p+0xb8)) {
   *(R9_80267EF8 *)(p+0x88) = *(R9_80267EF8 *)(p+0x58);
   *(V3_80267EF8 *)(p+0xac) = *(V3_80267EF8 *)(p+0x7c);
   *(int *)(p+0xb8) = lbl_8055E3C4;
 }
 if (*(int *)(p+0x14) < 0 || *(int *)(p+0x14) >= 0x22) *(int *)(p+0x14) = 4;
 *(int *)((char *)arg0+0x5c) = *(int *)(p+0x1c);
 lbl_8055F480 = 0;
 *(int *)(p+0x20) = *(int *)(p+0x24);
 *(int *)(p+0x10) = *(int *)(p+0x14);
 *(float *)(p+0xbc) = lbl_80563C68;
 *(void **)(p+0x140) = fn_8017960C(*(int *)(p+0x20));
 { float x = *(float *)(p+0x7c), y = *(float *)(p+0x80), z = *(float *)(p+0x84);
 frame.x = x; frame.flag = 0; entity = *(char **)(p+0x140); frame.y = y; frame.z = z; }
 if (entity) {
   ((void (*)(void *, void *, int))fn_802693F4)(p, &frame.flag, arg1);
   flags = ((int (*)(int))fn_80267EE0)(*(int *)(p+0x10));
   if (*(unsigned char *)(*(char **)(p+0x140)+0x260c)) flags |= 0x20;
 } else flags = ((int (*)(int))fn_80267EE0)(*(int *)(p+0x10));
 fn_80268E94(p,arg1);
 frame.object = *(int *)(p+0x20); frame.matrix = p+0x58; frame.extra = p+0x120;
 fn_8020655C(&frame.object,arg1);
 if (*(int *)(p+0x10) != 0x11) {
   float scale = lbl_8055E460;
   float *cur = (float *)(p+0x58);
   float *prev = (float *)(p+0x88);
   float *out = (float *)&frame.transform;
   for (i=0;i<2;i++) {
     out[0]=prev[0]+scale*(cur[0]-prev[0]); out[1]=prev[1]+scale*(cur[1]-prev[1]);
     out[2]=prev[2]+scale*(cur[2]-prev[2]); out[3]=prev[3]+scale*(cur[3]-prev[3]);
     out[4]=prev[4]+scale*(cur[4]-prev[4]); out[5]=prev[5]+scale*(cur[5]-prev[5]);
     out+=6; cur+=6; prev+=6;
   }
   *(R9_80267EF8 *)arg0 = *(R9_80267EF8 *)&frame.transform;
   *(V3_80267EF8 *)((char *)arg0+0x24) = frame.transform.pos;
 } else { *(R9_80267EF8 *)arg0 = *(R9_80267EF8 *)(p+0x58);
   *(V3_80267EF8 *)((char *)arg0+0x24) = *(V3_80267EF8 *)(p+0x7c); }
 *(float *)((char *)arg0+0x30) = *(float *)(p+0xbc);
 *(float *)((char *)arg0+0x34) = fn_8002EF30(lbl_80563C6C * *(float *)(p+0xbc));
 if (fn_801769F8() == 0) {
   if (fn_8026B734(*(int *)(p+0x20), &frame.height)) height = frame.height;
   else {
     int mode = *(int *)(p+0x10);
     int valid = 0;
     if ((mode >= 0 && mode < 10) || mode == 14) valid = 1;
     if (valid) {
       frame.height = fn_801B8950(*(int *)(p+0x20));
       t = ((float)__fabs(PSVECDotProduct(p+0x70,p+0xd8))-lbl_80563C70)/lbl_80563C74;
       if (lbl_80563C2C < t) t = lbl_80563C2C;
       if (t < lbl_80563C20) t = lbl_80563C20;
       height = frame.height * (lbl_80563C2C + t*lbl_80563C78);
     } else height = lbl_80563C20;
   }
 } else height = lbl_80563C20;
 *(float *)((char *)arg0+0x50) = height;
 *(float *)((char *)arg0+0x54) = *(float *)(p+0x1a0);
 if (*(unsigned char *)(p+0x138)) flags |= 0x10;
 *(char *)(p+0x138)=0; *(char *)(p+0x139)=0;
 *(int *)((char *)arg0+0x58)=*(int *)(p+0x10);
 *(int *)((char *)arg0+0x60)=*(int *)(p+0x20);
 *(int *)((char *)arg0+0x68)=flags;
 if (frame.flag) *(short *)((char *)arg0+0x64)=*(short *)(p+0x1ec);
 else *(short *)((char *)arg0+0x64)=*(short *)(*(char **)(p+0x140)+0x6c);
 if (!fn_801769F8()) {
   float *q=lbl_80499980; float dec=lbl_80563C7C, zero=lbl_80563C20;
   i=0; do {
     t=q[0]-dec; if (zero>t) t=zero; q[0]=t;
     t=q[1]-dec; if (zero>t) t=zero; q[1]=t;
     t=q[2]-dec; if (zero>t) t=zero; q[2]=t;
     t=q[3]-dec; if (zero>t) t=zero; q[3]=t;
     q+=4; i+=3;
   } while (i<6);
 }
 fn_80267130(arg0); ((void (*)(void *))fn_802671CC)(arg0);
}
#pragma pop
void fn_80267E40(unsigned int arg0, float arg1, int arg2) {
    float temp_f29;
    float temp_f30;
    float temp_f31;
    int i;
    void *p;
    temp_f29 = lbl_8055E3C8;
    temp_f30 = lbl_80563C6C;
    temp_f31 = lbl_80563C2C;
    for (i = 0; i < 4; i++) {
        p = fn_80267EE4(i);
        if (*(unsigned int *)((char *)p + 0x140) == arg0) {
            if (arg1 > *(float *)((char *)p + 0x154) * (temp_f31 - ((temp_f29 - *(float *)((char *)p + 0x158)) / temp_f30))) {
                *(float *)((char *)p + 0x158) = temp_f29;
                *(float *)((char *)p + 0x154) = arg1;
                return;
            }
        }
    }
}

extern void fn_802734F0(void);
extern char lbl_80499080[];
extern float lbl_80499050[];
extern float lbl_8055F47C;
extern void fn_801BFD34(void *, void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern int lbl_8055F4A0;
extern int lbl_8055F4A4;
extern int lbl_8055F4A8;
extern void fn_801E9DC4(int *);
void fn_80267EE0(void) {
    fn_802734F0();
}

void *fn_80267EE4(int arg0) {
    return lbl_80499080 + arg0 * 0x228;
}

#pragma push
#pragma processor 750
void fn_80267EF8(void *arg0) {
    char *p = (char *)arg0;
    float t = lbl_80563C80 * (float)fn_802E2C20() - lbl_8055F48C;
    if (t > lbl_80563C34) {
        lbl_8055F488 = 0;
        lbl_8055F48C = lbl_80563C64;
        fn_80209190(lbl_8055F494, lbl_80563C2C);
        if (fn_8000D75C() == 0) {
            fn_801769EC();
        }
    } else {
        float ratio = t / lbl_80563C34;
        float f = lbl_80563C20;
        float w;
        float s;
        MP_80267EF8 a, b, c;
        V3_80267EF8 axis;
        char tmp[0x24];
        if (t < lbl_80563C6C) {
            float q = t / lbl_80563C6C;
            f = lbl_80563C2C + q * lbl_80563C28;
        } else if (t > lbl_80563C84) {
            float q = (t - lbl_80563C84) / lbl_80563C6C;
            f += q * lbl_80563C2C;
        }
        fn_80209190(lbl_8055F494, f);
        s = lbl_80563C2C - f;
        {
            char *o = (char *)lbl_8055F490;
            if (s != *(float *)(o + 8)) {
                *(char *)(o + 0x4d) = 1;
                *(float *)(o + 8) = s;
            }
        }
        if (ratio < lbl_80563C28) {
            w = lbl_80563C28;
        } else if (ratio > lbl_80563C2C) {
            w = lbl_80563C2C;
        } else if (ratio > lbl_80563C20) {
            w = (((lbl_80563C30 * ratio) * ratio) * ratio) + ((lbl_80563C34 * ratio) * ratio);
        } else {
            w = (((lbl_80563C30 * ratio) * ratio) * ratio) - ((lbl_80563C34 * ratio) * ratio);
        }
        *(R9_80267EF8 *)&a = *(R9_80267EF8 *)(p + 0x58);
        a.pos = *(V3_80267EF8 *)(p + 0x7c);
        w = lbl_80563C24 * (lbl_80563C20 + w * lbl_80563C88);
        *(R9_80267EF8 *)&b = *(R9_80267EF8 *)(p + 0xc0);
        b.pos = *(V3_80267EF8 *)(p + 0xe4);
        f = PSQUATMultiply((float *)&b.pos, (int)&a.pos);
        ((double *)&c)[0] = ((double *)&a)[0];
        ((double *)&c)[1] = ((double *)&a)[1];
        ((double *)&c)[2] = ((double *)&a)[2];
        ((double *)&c.m[6])[0] = ((double *)&a.m[6])[0];
        *(int *)&c.m[8] = *(int *)&a.m[8];
        ((double *)&c.pos)[0] = ((double *)&a.pos)[0];
        *(int *)&c.pos.z = *(int *)&a.pos.z;
        c.pos.x = c.pos.x + c.m[6] * f;
        c.pos.y = c.pos.y + c.m[7] * f;
        c.pos.z = c.pos.z + c.m[8] * f;
        axis.x = lbl_80563C20;
        axis.y = w;
        axis.z = lbl_80563C20;
        fn_8022FF10(tmp, &axis);
        fn_80015B20(&c, &c, tmp);
        f = -f;
        c.pos.x = c.pos.x + c.m[6] * f;
        c.pos.y = c.pos.y + c.m[7] * f;
        c.pos.z = c.pos.z + c.m[8] * f;
        *(R9_80267EF8 *)(p + 0x58) = *(R9_80267EF8 *)&c;
        *(V3_80267EF8 *)(p + 0x7c) = c.pos;
    }
}
#pragma pop
extern char lbl_803467E8[];
extern float lbl_8055E3C8;
extern float lbl_8055C4F0;
extern float lbl_8055C4F4;
extern void fn_801E9E78(void *, void *, void *, void *);
extern void fn_8026E850(void *, void *, void *, void *);
extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
static inline void fn_80268358_vecmat(float *out, float *v, float *m) {
    if (out == v) {
        float t0 = m[3] * v[1] + m[0] * v[0] + m[6] * v[2];
        float t1 = m[4] * v[1] + m[1] * v[0] + m[7] * v[2];
        float t2 = m[5] * v[1] + m[2] * v[0] + m[8] * v[2];
        out[0] = t0;
        out[1] = t1;
        out[2] = t2;
    } else {
        out[0] = m[3] * v[1] + m[0] * v[0] + m[6] * v[2];
        out[1] = m[4] * v[1] + m[1] * v[0] + m[7] * v[2];
        out[2] = m[5] * v[1] + m[2] * v[0] + m[8] * v[2];
    }
}
void fn_802682B0(void *arg0) {
    char *p = (char *)arg0;
    float *base;
    if (*(unsigned char *)(p + 0x138) != 0) {
        float b;
        float a;
        float *q;
        a = lbl_80563C2C;
        q = lbl_80499050 - 1;
        b = lbl_80563C20;
        *++q = a;
        q[1] = b; q[2] = b; q[3] = b;
        q[4] = a;
        q[5] = b; q[6] = b; q[7] = b;
        q[8] = a;
        q[9] = b; q[10] = b; q[11] = b;
    }
    base = lbl_80499050;
    fn_801BFD34(p + 0x7c, base + 9, p + 0xc0);
    fn_80015B20(p + 0x58, base, p + 0xc0);
    *(float *)(p + 0xbc) = lbl_8055F47C;
}

void fn_80268358(void *arg0) {
    struct Obj {
        int w0;
        void *ptr;
        float frac;
        int wC;
        float f10;
        float f14;
        char pad[0x38];
        int resource;
        char pad2[0x14];
    };
    struct Sp8 {
        int zero;
        int pad;
        float x;
        float y;
    };
    struct Frame {
        struct Sp8 sp8;
        float v18[3];
        float v24[3];
        float v30[3];
        float v3C[3];
        float v48[3];
        float v54[3];
        float v60[3];
        float v6C[3];
        float pos[3];
        char gap[4];
        float entries[12];
        struct Obj obj;
        float mats[24];
        float acc[18];
    } frame;
    float *matPtr;
    void *p;
    void *b;
    float x;
    float y;
    float *e0;
    float *e1;
    float t;
    float ratio;
    unsigned char flag;
    float a;
    float b2;
    int outer;
    int inner;
    int i;
    int k;
    float w;
    float w2;
    float zeroF;
    float halfF;
    float *accPtr;
    float *entryPtr;
    zeroF = lbl_80563C20;
    halfF = lbl_80563C6C;
    e0 = (float *)(lbl_803467E8 + (lbl_8055F4A0 << 5));
    e1 = (float *)(lbl_803467E8 + (lbl_8055F4A4 << 5));
    frame.entries[1] = e0[1];
    frame.entries[0] = e0[0];
    frame.entries[3] = e0[3];
    frame.entries[2] = e0[2];
    frame.entries[5] = e0[5];
    frame.entries[4] = e0[4];
    frame.entries[6] = e1[0];
    frame.entries[7] = e1[1];
    frame.entries[8] = e1[2];
    frame.entries[9] = e1[3];
    frame.entries[10] = e1[4];
    frame.entries[11] = e1[5];
    accPtr = frame.acc;
    entryPtr = frame.entries;
    outer = 0;
    do {
        matPtr = frame.mats;
        for (k = 0; k < 9; k++) {
            accPtr[k] = zeroF;
        }
        inner = 0;
        do {
            fn_80135DC4(&frame.obj, 0, 0);
            p = frame.obj.ptr;
            b = *(void **)((char *)p + 0x14);
            x = *(float *)p + frame.obj.frac * (*(float *)b - *(float *)p);
            y = *(float *)((char *)p + 4) + frame.obj.frac * (*(float *)((char *)b + 4) - *(float *)((char *)p + 4));
            frame.pos[0] = x;
            frame.pos[1] = zeroF;
            frame.pos[2] = y;
            frame.sp8.zero = 0;
            frame.sp8.x = x;
            frame.sp8.y = y;
            fn_801E9E78(&lbl_8055F4A8, frame.pos, frame.v6C, &frame.sp8);
            matPtr[6] = frame.obj.f10;
            matPtr[7] = zeroF;
            matPtr[8] = frame.obj.f14;
            PSVECNormalize(matPtr + 6, matPtr + 6);
            PSVECCrossProduct(frame.v6C, matPtr + 6, matPtr);
            PSVECNormalize(matPtr, matPtr);
            PSVECCrossProduct(matPtr + 6, matPtr, matPtr + 3);
            PSVECNormalize(matPtr + 3, matPtr + 3);
            matPtr[9] = frame.pos[0];
            matPtr[10] = frame.pos[1];
            matPtr[11] = frame.pos[2];
            if (frame.obj.resource != 0) {
                fn_80128670();
            }
            frame.obj.resource = 0;
            fn_8013530C(&frame.obj, 0);
            inner++;
            matPtr += 12;
        } while (inner < 2);
        matPtr = frame.mats;
        for (i = 0; i < 2; i++) {
            frame.v60[0] = entryPtr[0];
            frame.v60[1] = entryPtr[1];
            frame.v60[2] = entryPtr[2];
            fn_80268358_vecmat(frame.v54, frame.v60, matPtr);
            frame.v54[0] += matPtr[9];
            frame.v54[1] += matPtr[10];
            frame.v54[2] += matPtr[11];
            accPtr[0] += frame.v54[0] * halfF;
            accPtr[1] += frame.v54[1] * halfF;
            accPtr[2] += frame.v54[2] * halfF;
            matPtr += 12;
        }
        matPtr = frame.mats;
        for (i = 0; i < 2; i++) {
            frame.v48[0] = entryPtr[3];
            frame.v48[1] = entryPtr[4];
            frame.v48[2] = entryPtr[5];
            fn_80268358_vecmat(frame.v3C, frame.v48, matPtr);
            frame.v3C[0] += matPtr[9];
            frame.v3C[1] += matPtr[10];
            frame.v3C[2] += matPtr[11];
            accPtr[3] += frame.v3C[0] * halfF;
            accPtr[4] += frame.v3C[1] * halfF;
            accPtr[5] += frame.v3C[2] * halfF;
            matPtr += 12;
        }
        accPtr[6] += frame.mats[3] * halfF;
        accPtr[7] += frame.mats[4] * halfF;
        accPtr[8] += frame.mats[5] * halfF;
        accPtr[6] += frame.mats[15] * halfF;
        accPtr[7] += frame.mats[16] * halfF;
        accPtr[8] += frame.mats[17] * halfF;
        outer++;
        entryPtr += 6;
        accPtr += 9;
    } while (outer < 2);
    t = lbl_8055E3C8 - *(float *)((char *)arg0 + 0x1E8);
    flag = *(unsigned char *)(lbl_803467E8 + (lbl_8055F4A0 << 5) + 0x1C);
    if (flag != 0) {
        ratio = t / lbl_8055C4F0;
        if (ratio < lbl_80563C28) {
            w = lbl_80563C28;
        } else if (ratio > lbl_80563C2C) {
            w = lbl_80563C2C;
        } else if (ratio > lbl_80563C20) {
            w = ratio * ((lbl_80563C30 * ratio) * ratio) + (lbl_80563C34 * ratio) * ratio;
        } else {
            w = ratio * ((lbl_80563C30 * ratio) * ratio) - (lbl_80563C34 * ratio) * ratio;
        }
    } else {
        w = t / lbl_8055C4F0;
    }
    if (flag != 0) {
        ratio = t / lbl_8055C4F4;
        if (ratio < lbl_80563C28) {
            w2 = lbl_80563C28;
        } else if (ratio > lbl_80563C2C) {
            w2 = lbl_80563C2C;
        } else if (ratio > lbl_80563C20) {
            w2 = ratio * ((lbl_80563C30 * ratio) * ratio) + (lbl_80563C34 * ratio) * ratio;
        } else {
            w2 = ratio * ((lbl_80563C30 * ratio) * ratio) - (lbl_80563C34 * ratio) * ratio;
        }
    } else {
        w2 = t / lbl_8055C4F4;
    }
    frame.v24[1] = frame.acc[1] + w2 * (frame.acc[10] - frame.acc[1]);
    frame.v24[0] = frame.acc[0] + w2 * (frame.acc[9] - frame.acc[0]);
    frame.v24[2] = frame.acc[2] + w2 * (frame.acc[11] - frame.acc[2]);
    frame.v30[1] = frame.acc[4] + w * (frame.acc[13] - frame.acc[4]);
    frame.v30[0] = frame.acc[3] + w * (frame.acc[12] - frame.acc[3]);
    frame.v30[2] = frame.acc[5] + w * (frame.acc[14] - frame.acc[5]);
    frame.v18[0] = frame.acc[6] + w * (frame.acc[15] - frame.acc[6]);
    frame.v18[1] = frame.acc[7] + w * (frame.acc[16] - frame.acc[7]);
    frame.v18[2] = frame.acc[8] + w * (frame.acc[17] - frame.acc[8]);
    PSVECNormalize(frame.v18, frame.v18);
    a = *(float *)(lbl_803467E8 + (lbl_8055F4A0 << 5) + 0x18);
    b2 = *(float *)(lbl_803467E8 + (lbl_8055F4A4 << 5) + 0x18);
    *(float *)((char *)arg0 + 0xBC) = a + w * (b2 - a);
    fn_8026E850(frame.v30, frame.v24, arg0, frame.v18);
}

void fn_80268B94(int arg0) {
    lbl_8055F4A0 = arg0;
    lbl_8055F4A4 = arg0;
    fn_801E9DC4(&lbl_8055F4A8);
}

extern char lbl_80499920[];
extern float lbl_80563C44, lbl_80563C48, lbl_80563C2C, lbl_80563C34, lbl_80563C4C, lbl_80563C50;
extern float lbl_80563C98;
extern int fn_80178CA4(void);
#pragma dont_inline on
int fn_80268BA4(int arg0) {
    unsigned int shift = arg0 - 4;
    int result = 0;
    if (shift > 0x13)
        goto done;
    if (!((1U << shift) & 0x80037))
        goto done;
    result = 1;
done:
    return result;
}
#pragma dont_inline reset

extern float lbl_80563C20, lbl_80563C2C, lbl_80563C8C, lbl_80563C90, lbl_80563C94;
extern float fn_8002F234(void*, float, float, float, float, float, float, float, float);
extern void fn_801EA140(void*, float, float, float, float, float, float, float);
extern void PSVECCrossProduct(void*, void*, void*);
extern double cos(float);
extern double sin(float);
#pragma push
#pragma processor 750
void fn_80268BD4(void *out, int arg1, float t, float angle) {
    float *inp = (float *)arg1;
    float *b = *(float **)((char *)inp + 0x14);
    volatile float sp[4];
    float x;
    float y;
    float z;
    float w;
    float scale;
    float xScaled;
    float yScaled;
    float rotation;
    float cosine;
    float sine;

    x = inp[2] + t * (b[2] - inp[2]);
    sp[0] = x;
    y = inp[3] + t * (b[3] - inp[3]);
    sp[1] = y;
    z = inp[0] + t * (b[0] - inp[0]);
    w = inp[1] + t * (b[1] - inp[1]);
    sp[2] = z;
    sp[3] = w;

    scale = lbl_80563C2C /
        (float)((double (*)(void *, float, float, float, float, float, float, float, float))fn_8002F234)(
            out, x * x + y * y, x * x, t * (b[1] - inp[1]),
            z, inp[0], inp[1], y, x);
    xScaled = sp[0] * scale;
    yScaled = sp[1] * scale;
    sp[0] = yScaled;
    sp[1] = -xScaled;

    *(float *)((char *)out + 0x28) = lbl_80563C20;
    rotation = lbl_80563C8C * inp[10] - lbl_80563C90;
    *(float *)((char *)out + 0x24) = sp[2] + yScaled * rotation;
    *(float *)((char *)out + 0x2C) = sp[3] + sp[1] * rotation;
    fn_801EA140((char *)out + 0x24, sp[3],
                sp[2] + yScaled * rotation, yScaled * rotation,
                rotation, sp[1], yScaled, xScaled);
    *(float *)((char *)out + 0x28) += lbl_80563C94;

    cosine = (float)cos(angle);
    sine = (float)sin(angle);
    *(float *)((char *)out + 0xC) = lbl_80563C20;
    *(float *)((char *)out + 0x10) = lbl_80563C2C;
    *(float *)((char *)out + 0x14) = lbl_80563C20;
    *(float *)((char *)out + 0x18) = yScaled * cosine - sp[1] * sine;
    *(float *)((char *)out + 0x1C) = lbl_80563C20;
    *(float *)((char *)out + 0x20) = yScaled * sine + sp[1] * cosine;
    PSVECCrossProduct((char *)out + 0xC, (char *)out + 0x18, out);
}
#pragma pop
void fn_80268D94(void) {
    struct {
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
        int g;
        int h;
        int i;
        int j;
        int k;
        int l;
        int m;
        int n;
        int o;
        int p;
        int q;
        int r;
        int s;
    } sp8;
    int sp58;
    fn_80135DC4(&sp8, 0, 0);
    fn_80268BD4(lbl_80499920, *(int *)&sp8 + 0x1c, lbl_80563C20, lbl_80563C98);
    if (sp58 != 0) {
        fn_80128670();
    }
    sp58 = 0;
    fn_8013530C(&sp8, 0);
}

void fn_80268E00(void) {
    #pragma scheduling invalid_target
    struct Result {
        int value;
        float fraction;
        int mode;
        int padding;
    } result;
    struct Object {
        char pad2c[0x2C];
        void *context;
        char pad30[0x20];
        int resource;
        int field54;
        int field58;
    } object;

    fn_80135DC4(&object, 0, 0);
    fn_80136468((int *)&result, &object, fn_80134E34(lbl_80563C28));
    if (result.value == 0) {
        result.value = *(int *)((char *)object.context + 0x1C);
    }
    fn_80268BD4(lbl_80499950, result.value, result.fraction, lbl_80563C9C);
    if (object.resource != 0) {
        ((void (*)(int))fn_80128670)(object.resource);
    }
    object.resource = 0;
    fn_8013530C(&object, 0);
}

#pragma push
#pragma processor 750
extern int fn_8026B0C0(int);
extern float lbl_80563C40, lbl_80563CA0, lbl_80563CA4, lbl_80563CA8, lbl_80563CAC, lbl_80563CB0, lbl_80563CB4, lbl_80563CB8;
extern float fn_80144514(float,float,float,float,float,float);
extern float fn_80144514(float,float,float,float,float,float);
static inline void fn_80268E94_multiply(float *out, const float *a, const float *b) {
 float t0,t1,t2,t3,t4,t5,t6,t7,t8;
 if (out == a || out == b) {
 t0 = fn_80144514(b[0], a[0], b[3], a[1], b[6], a[2]);
 t3 = fn_80144514(b[0], a[3], b[3], a[4], b[6], a[5]);
 t6 = fn_80144514(b[0], a[6], b[3], a[7], b[6], a[8]);
 t1 = fn_80144514(b[1], a[0], b[4], a[1], b[7], a[2]);
 t4 = fn_80144514(b[1], a[3], b[4], a[4], b[7], a[5]);
 t7 = fn_80144514(b[1], a[6], b[4], a[7], b[7], a[8]);
 t2 = fn_80144514(b[2], a[0], b[5], a[1], b[8], a[2]);
 t5 = fn_80144514(b[2], a[3], b[5], a[4], b[8], a[5]);
 t8 = fn_80144514(b[2], a[6], b[5], a[7], b[8], a[8]);
 out[0] = t0;
 out[3] = t3;
 out[6] = t6;
 out[1] = t1;
 out[4] = t4;
 out[7] = t7;
 out[2] = t2;
 out[5] = t5;
 out[8] = t8;
 } else {
 out[0] = fn_80144514(b[0], a[0], b[3], a[1], b[6], a[2]);
 out[3] = fn_80144514(b[0], a[3], b[3], a[4], b[6], a[5]);
 out[6] = fn_80144514(b[0], a[6], b[3], a[7], b[6], a[8]);
 out[1] = fn_80144514(b[1], a[0], b[4], a[1], b[7], a[2]);
 out[4] = fn_80144514(b[1], a[3], b[4], a[4], b[7], a[5]);
 out[7] = fn_80144514(b[1], a[6], b[4], a[7], b[7], a[8]);
 out[2] = fn_80144514(b[2], a[0], b[5], a[1], b[8], a[2]);
 out[5] = fn_80144514(b[2], a[3], b[5], a[4], b[8], a[5]);
 out[8] = fn_80144514(b[2], a[6], b[5], a[7], b[8], a[8]);
 }
}
#pragma push
#pragma processor 750
void fn_80268E94(void *arg0, int arg1) {
 float *matrix; float v[3], rot[9];
 float strength, elapsed, weight, phase, mag, x,y,z, sn,cs,one;
 int valid, mode;
 if (fn_8026B0C0(arg1) == 0 && fn_801769F8() == 0) {
 mode = *(int *)((char *)arg0+0x10); valid = 0;
 if ((mode >= 0 && mode < 10) || mode == 14) valid = 1;
 if (valid) {
 elapsed = lbl_8055E3C8 - *(float *)((char *)arg0+0x158);
 if (elapsed < lbl_80563C6C) {
 phase = (lbl_80563C6C - elapsed)/lbl_80563C6C;
 if (phase < lbl_80563C28) weight = lbl_80563C28;
 else if (phase > lbl_80563C2C) weight = lbl_80563C2C;
 else if (phase > lbl_80563C20) weight = phase*(lbl_80563C30*phase*phase) + lbl_80563C34*phase*phase;
 else weight = phase*(lbl_80563C30*phase*phase) - lbl_80563C34*phase*phase;
 strength = *(float *)((char *)arg0+0x154) * weight;
 if (strength > lbl_80563CA0) {
 one = lbl_80563CA4;
 sn = sin(lbl_80563CA8 * (lbl_80563CAC * elapsed) * one);
 z = strength * (fn_80129DC4(0,lbl_80563CB0,lbl_80563CB4) + sn*lbl_80563CB8);
 sn = sin(lbl_80563C50 * (lbl_80563CAC * elapsed) * one);
 y = strength * (fn_80129DC4(0,lbl_80563CB0,lbl_80563CB4) + sn*lbl_80563CB8);
 v[1] = y; v[2] = z;
 sn = sin((lbl_80563CAC * elapsed) * one);
 v[0] = strength * (fn_80129DC4(0,lbl_80563CB0,lbl_80563CB4) + sn*lbl_80563CB8);
 mag = PSVECMag(&v[0]);
 if (mag > lbl_80563C40) {
   float scale = lbl_80563C2C / mag;
   x=scale*v[0]; y=scale*v[1]; z=scale*v[2];
   sn=sin(mag); cs=cos(mag); one=lbl_80563C2C-cs;
   rot[0]=cs+one*(x*x); rot[1]=y*(one*x)+sn*z; rot[2]=z*(one*x)-sn*y;
   rot[3]=y*(one*x)-sn*z; rot[4]=cs+one*(y*y); rot[5]=z*(one*y)+sn*x;
   rot[6]=z*(one*x)+sn*y; rot[7]=z*(one*y)-sn*x; rot[8]=cs+one*(z*z);
 } else {
   rot[0]=lbl_80563C2C; rot[1]=lbl_80563C20; rot[2]=lbl_80563C20;
   rot[3]=lbl_80563C20; rot[4]=lbl_80563C2C; rot[5]=lbl_80563C20;
   rot[6]=lbl_80563C20; rot[7]=lbl_80563C20; rot[8]=lbl_80563C2C;
 }
 matrix=(float *)((char *)arg0+0x58);
 fn_80268E94_multiply(matrix, matrix, rot);
 } } } }
}

extern float lbl_80563CBC, lbl_80563CA0, lbl_80563CC0, lbl_80563CC4, lbl_80563CC8, lbl_80563CCC, lbl_80563CD0, lbl_80563CD4, lbl_80563CD8, lbl_80563CDC, lbl_80563CE0, lbl_80563CE4, lbl_80563CE8, lbl_80563CEC, lbl_80563CF0, lbl_8055C4B0;
extern char lbl_80346848[];
extern void fn_802733F4(void *);
extern int fn_8026A698(void *, int);
extern void fn_80278360(void *);
extern void fn_80267EF8(void *);
extern void fn_802704E4(void *);
extern void fn_80274660(int, void *);
extern void fn_80274460(void *);
extern void fn_8027847C(void *);
extern void fn_8026DAA8(void *);
extern void fn_802682B0(void *);
extern void fn_80275FC0(void *);
extern void fn_80276044(void *);
extern void fn_80276054(void *);
extern int fn_801769A8(void);
extern void fn_80268358(void *);
extern void fn_80273490(int, void *);
extern void fn_80273604(void *, int);
extern void fn_80275B9C(void *, float, float, float);
extern void fn_80277A14(void *, int);
extern void fn_802E317C(char *, ...);
extern int fn_80268BA4(int);
extern float lbl_80563CBC, lbl_80563CA0, lbl_80563CC0, lbl_80563CC4, lbl_80563CC8, lbl_80563CCC, lbl_80563CD0, lbl_80563CD4, lbl_80563CD8, lbl_80563CDC, lbl_80563CE0, lbl_80563CE4, lbl_80563CE8, lbl_80563CEC, lbl_80563CF0, lbl_8055C4B0, lbl_80563CA4;
void fn_802693F4(char *p, unsigned char *flag, int arg) {
    char *ent = *(char **)(p + 0x140);
    float v[3];
    float *d = (float *)(ent + 0x30);
    float t, f2, f3, f4, f30, f31, f29, m;
    float gz, gy, gx;
    *(R9_80267EF8 *)(p + 0xc0) = *(R9_80267EF8 *)(ent + 0x3c);
    *(V3_80267EF8 *)(p + 0xe4) = *(V3_80267EF8 *)(ent + 0x60);
    gx = *(float *)(ent + 0x118);
    *(float *)(p + 0x12c) = gx;
    gy = *(float *)(ent + 0x11c);
    *(float *)(p + 0x130) = gy;
    gz = *(float *)(ent + 0x120);
    *(float *)(p + 0x134) = gz;
    *(float *)(p + 0x120) = gx;
    *(float *)(p + 0x124) = gy;
    *(float *)(p + 0x128) = gz;
    {
        float *mm = (float *)(p + 0xc0);
        if (v == d) {
            float t0 = mm[3] * d[1] + mm[0] * d[0] + mm[6] * d[2];
            float t1 = mm[4] * d[1] + mm[1] * d[0] + mm[7] * d[2];
            float t2 = mm[5] * d[1] + mm[2] * d[0] + mm[8] * d[2];
            v[0] = t0;
            v[1] = t1;
            v[2] = t2;
        } else {
            v[0] = mm[3] * d[1] + mm[0] * d[0] + mm[6] * d[2];
            v[1] = mm[4] * d[1] + mm[1] * d[0] + mm[7] * d[2];
            v[2] = mm[5] * d[1] + mm[2] * d[0] + mm[8] * d[2];
        }
    }
    *(float *)(p + 0xe4) = *(float *)(p + 0xe4) + v[0];
    *(float *)(p + 0xe8) = *(float *)(p + 0xe8) + v[1];
    *(float *)(p + 0xec) = *(float *)(p + 0xec) + v[2];
    if (*(int *)(p + 0x10) != *(int *)(p + 4) && (*(int *)(p + 0x10) != 4 || *(int *)(p + 4) != 0x19) && (*(int *)(p + 4) != 4 || *(int *)(p + 0x10) != 0x19))
        *(unsigned char *)(p + 0x138) = 1;
    fn_802733F4(p);
    if (*(unsigned int *)(p + 0x144) != *(unsigned int *)(p + 0x140)) {
        *(int *)(p + 0x144) = *(int *)(p + 0x140);
        *(unsigned char *)(p + 0x139) = 1;
        *(unsigned char *)(p + 0x138) = 1;
    }
    if (*(unsigned char *)(p + 0x138) != 0)
        fn_801E9DC4((int *)(p + 0x1ec));
    *(float *)(p + 0x40) = *(float *)(p + 0xe4);
    *(float *)(p + 0x44) = *(float *)(p + 0xe8);
    *(float *)(p + 0x48) = *(float *)(p + 0xec);
    if (fn_801769F8() == 0) {
        t = lbl_80563CBC * *(float *)(*(char **)(p + 0x140) + 0x25d4);
        f3 = lbl_80563C2C;
        f3 = (f3 < t) ? f3 : t;
        if (*(unsigned char *)(p + 0x138) == 0 && *(unsigned char *)(p + 0x139) == 0)
            *(float *)(p + 0x13c) = *(float *)(p + 0x13c) + lbl_80563CA0 * (f3 - *(float *)(p + 0x13c));
        else
            *(float *)(p + 0x13c) = f3;
    }
    if (fn_8026A698(p, arg) == 0) {
        int mode = *(int *)(p + 0x10);
        switch (mode) {
        case 0: fn_80273BD0(p); break;
        case 1: fn_8027445C(p); break;
        case 2: fn_80274268(p); break;
        case 3: fn_80274460(p); break;
        case 24: fn_8027847C(p); break;
        case 4: case 5: case 6: case 7: case 8: case 23:
            fn_802704D4(mode, p);
            if (*(unsigned char *)&lbl_8055F488 != 0) fn_80267EF8(p);
            break;
        case 9: fn_802704E4(p); break;
        case 10: case 16: fn_80274660(mode, p); break;
        case 17: fn_8026DAA8(p); *flag = 1; break;
        case 18: fn_802682B0(p); *flag = 1; break;
        case 21:
            fn_80275FC0(p);
            m = lbl_80563C20;
            *(float *)(p + 0x120) = m;
            *(float *)(p + 0x124) = m;
            *(float *)(p + 0x128) = m;
            *flag = 1;
            break;
        case 25: fn_80276044(p); *flag = 1; break;
        case 22: fn_80276054(p); break;
        case 26:
            if ((fn_801769A8() >> 8) & 1) fn_80268358(p);
            else fn_8027445C(p);
            break;
        case 11: fn_80273490(mode, p); *flag = 1; break;
        case 12: fn_80273604(p, 1); break;
        case 13: fn_80273604(p, 2); break;
        case 14: fn_80273604(p, 3); break;
        case 15: fn_80273604(p, 4); break;
        case 19: { int *s = (int *)lbl_80499920; int *q = (int *)(p + 0x58); int a, b;
            a=s[0]; b=s[1]; q[0]=a; q[1]=b;
            a=s[2]; b=s[3]; q[2]=a; q[3]=b;
            a=s[4]; b=s[5]; q[4]=a; q[5]=b;
            a=s[6]; b=s[7]; q[6]=a; q[7]=b;
            a=s[8]; q[8]=a;
            a=s[9]; b=s[10]; q[9]=a; q[10]=b;
            a=s[11]; q[11]=a; } break;
        case 20: { int *s = (int *)lbl_80499950; int *q = (int *)(p + 0x58); int a, b;
            a=s[0]; b=s[1]; q[0]=a; q[1]=b;
            a=s[2]; b=s[3]; q[2]=a; q[3]=b;
            a=s[4]; b=s[5]; q[4]=a; q[5]=b;
            a=s[6]; b=s[7]; q[6]=a; q[7]=b;
            a=s[8]; q[8]=a;
            a=s[9]; b=s[10]; q[9]=a; q[10]=b;
            a=s[11]; q[11]=a; } break;
        case 27: fn_80275B9C(p, lbl_80563CC0, lbl_80563CC4, lbl_80563CC8); break;
        case 28:
            m = lbl_80563C20;
            fn_80275B9C(p, lbl_80563CDC + m * lbl_80563CE0, lbl_80563CD4 + m * lbl_80563CD8, lbl_80563CCC + m * lbl_80563CD0);
            break;
        case 29: fn_802704D4(7, p); break;
        case 30: fn_80275B9C(p, lbl_80563CA4, lbl_80563CE4, lbl_80563CC8); break;
        case 31: fn_802704D4(7, p); break;
        case 32: fn_80277A14(p, arg); break;
        case 33:
        default: fn_802E317C(lbl_80346848, mode, arg); break;
        }
    }
    fn_80278360(p);
    *(int *)(p + 4) = *(int *)(p + 0x10);
    *(float *)(p + 0x194) = *(float *)(p + 0xbc);
    if (fn_80268BA4(*(int *)(p + 0x10)) != 0 && *(unsigned char *)(p + 0x138) == 0 && *(unsigned char *)(p + 0x139) == 0) {
        f31 = lbl_8055E3C8;
        f2 = (*(float *)(p + 0x1f0) - f31) / ((f31 - lbl_80563CEC) - f31);
        f29 = lbl_80563CE8 * lbl_8055C4B0;
        f4 = lbl_80563C2C;
        f4 = (f4 < f2) ? f4 : f2;
        f4 = (f4 > lbl_80563C20) ? f4 : lbl_80563C20;
        f30 = lbl_80563C20 + f4 * lbl_80563C2C;
        t = f29 * PSVECMag(*(char **)(p + 0x140) + 0x26b4);
        f4 = lbl_80563CEC;
        f4 = (f4 < t) ? f4 : t;
        f4 = f30 * f4;
        f2 = (lbl_80563C6C - (f31 - *(float *)(p + 0x158))) / lbl_80563C6C;
        f3 = (f2 < lbl_80563C28) ? lbl_80563C28
           : (f2 > lbl_80563C2C) ? lbl_80563C2C
           : (f2 > lbl_80563C20) ? f2 * (lbl_80563C30 * f2 * f2) + lbl_80563C34 * f2 * f2
           : f2 * (lbl_80563C30 * f2 * f2) - lbl_80563C34 * f2 * f2;
        if (f4 > lbl_80563CF0 && f4 > *(float *)(p + 0x154) * f3) {
            *(float *)(p + 0x158) = f31;
            *(float *)(p + 0x154) = f4;
        }
    } else {
        *(float *)(p + 0x158) = lbl_80563C20;
        *(float *)(p + 0x154) = lbl_80563C20;
    }
}

void fn_80269BB0(int idx, unsigned int sel, int *out, float *outf) {
    Rec2_80269BB0 r;
    Rec2_80269BB0 *p = (Rec2_80269BB0 *)lbl_80499080 + idx;
    r.w0 = p->w0; r.w4 = p->w4; r.f8 = p->f8; r.fc = p->fc;
    r = *p;
    r.w4 = 0x15;
    r.w10 = sel;
    r.b138 = 1;
    switch (sel) {
    case 0: fn_80273BD0(&r); break;
    case 1: fn_8027445C(&r); break;
    case 2: fn_80274268(&r); break;
    case 4:
    case 5: fn_802704D4(sel, &r); break;
    case 11:
    case 17: fn_802E30C8(lbl_803468F8); break;
    default: break;
    }
    out[0] = r.w58; out[1] = r.w5c; out[2] = r.w60;
    out[3] = r.w64; out[4] = r.w68; out[5] = r.w6c;
    out[6] = r.w70; out[7] = r.w74; out[8] = r.w78;
    out[9] = r.w7c; out[10] = r.w80; out[11] = r.w84;
    *outf = r.fbc;
}

#pragma pop

#pragma dont_inline on
void fn_8026A248(int arg0, int arg1) {
    *(int *)((char *)fn_80267EE4(arg1) + 0x24) = arg0;
}
extern void fn_802735F4(int, int);
extern void fn_80135DC4(void *, int, int);
extern float fn_80134E34(float);
extern void fn_80136468(int *, void *, float);
extern void fn_80128670(void);
extern void fn_8013530C(void *, int);
extern void fn_80268BD4(void *, int, float, float);
extern float lbl_80563C28;
extern float lbl_80563C9C;
extern char lbl_80499950[];
#pragma push
#pragma scheduling invalid_target
int fn_8026A27C(int arg0) {
    int value = lbl_80499E50[arg0];
    lbl_80499E50[arg0] = 0;
    return value;
}
#pragma pop
void fn_8026A298(int arg0) {
    lbl_80499E50[arg0] = -1;
}

extern void fn_801EA994(void);
extern int lbl_80499E50[];
void fn_8026A2B0(int arg0) {
    lbl_80499E50[arg0] = 1;
}

void fn_8026A2C8(void) {
    fn_801EA994();
}

#pragma scheduling invalid_target
#pragma scheduling on
void fn_8026A2CC(int *arg0, int arg1, float arg2) {
    int *dst = (int *)((char *)lbl_80499080 + arg1 * 0x228 + 0x1a4);
    int *src = arg0;
    int a = src[0];
    int b = src[1];
    int c = src[2];
    int d = src[3];
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];
    dst[9] = src[9];
    dst[10] = src[10];
    dst[11] = src[11];
    *(float *)(dst + 12) = arg2;
}
int fn_8026A344(int arg0) {
    return *(int *)((char *)fn_80267EE4(arg0) + 0x20);
}
void *fn_80267EE4();
int fn_8026A368(void) {
    return *(int *)((char *)fn_80267EE4() + 0x10);
}
int fn_802678C0(void) {
    return (int)fn_80267EE4() + 0x58;
}
char fn_8026A38C(void) {
    return lbl_8055F488;
}

extern float lbl_80563CBC, lbl_80563C2C, lbl_80563C20, lbl_8055E3C8;
#pragma scheduling invalid_target
void fn_8026A394(void *arg0) {
 int i = 0;
 while (i < 4) {
  char *p = (char *)fn_80267EE4(i);
  if (*(void **)(p + 0x140) == arg0) {
   char *q;
   volatile unsigned int *src;
   volatile unsigned int *dst;
   unsigned int one;
   float factor;
   float scale;
   float threshold;
   float zero;
   float copy;
   unsigned int value1;
   unsigned int value0;
   unsigned int value3;
   unsigned int value2;
   unsigned int value5;
   unsigned int value4;
   unsigned int value7;
   unsigned int value6;
   unsigned int value8;
   unsigned int value10;
   unsigned int value9;
   unsigned int value11;
   one = 1;
   factor = *(volatile float *)&lbl_80563CBC;
   *(volatile unsigned char *)(p + 0x139) = one;
   threshold = lbl_80563C2C;
   *(volatile unsigned char *)(p + 0x138) = one;
   q = *(char * volatile *)(p + 0x140);
   scale = *(float *)(q + 0x25d4);
   factor = factor * scale;
   *(volatile float *)(p + 0x13c) = threshold < factor ? factor : threshold;
   zero = lbl_80563C20;
   *(float *)(p + 0x154) = zero;
   *(float *)(p + 0x158) = zero;
   src = (volatile unsigned int *)(p + 0x58);
   dst = (volatile unsigned int *)(p + 0x1f8);
   value0 = src[0];
   value1 = src[1];
   dst[0] = value0;
   dst[1] = value1;
   src = (volatile unsigned int *)(p + 0x60);
   dst = (volatile unsigned int *)(p + 0x200);
   value2 = src[0];
   value3 = src[1];
   dst[0] = value2;
   dst[1] = value3;
   src = (volatile unsigned int *)(p + 0x68);
   dst = (volatile unsigned int *)(p + 0x208);
   value4 = src[0];
   value5 = src[1];
   dst[0] = value4;
   dst[1] = value5;
   src = (volatile unsigned int *)(p + 0x70);
   dst = (volatile unsigned int *)(p + 0x210);
   value6 = src[0];
   value7 = src[1];
   dst[0] = value6;
   dst[1] = value7;
   src = (volatile unsigned int *)(p + 0x78);
   dst = (volatile unsigned int *)(p + 0x218);
   value8 = src[0];
   dst[0] = value8;
   src = (volatile unsigned int *)(p + 0x7c);
   dst = (volatile unsigned int *)(p + 0x21c);
   value9 = src[0];
   value10 = src[1];
   dst[0] = value9;
   dst[1] = value10;
   src = (volatile unsigned int *)(p + 0x84);
   dst = (volatile unsigned int *)(p + 0x224);
   value11 = src[0];
   dst[0] = value11;
   copy = *(float *)(p + 0xbc);
   *(float *)(p + 0x1f4) = copy;
   copy = lbl_8055E3C8;
   *(float *)(p + 0x1f0) = copy;
   return;
  }
  i++;
 }
}
#pragma scheduling on
    extern void fn_80269BB0(int, unsigned int, int *, float *);
    void fn_8026A49C(int a, unsigned int b, int *c, float *d) {
      fn_80269BB0(a, b, c, d);
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8026A4A0(int arg0, int *arg1, float *arg2) {
    char *base = (char *)lbl_80499080 + arg0 * 0x228;
    arg1[0] = *(int *)(base + 0x58);
    arg1[1] = *(int *)(base + 0x5c);
    arg1[2] = *(int *)(base + 0x60);
    arg1[3] = *(int *)(base + 0x64);
    arg1[4] = *(int *)(base + 0x68);
    arg1[5] = *(int *)(base + 0x6c);
    arg1[6] = *(int *)(base + 0x70);
    arg1[7] = *(int *)(base + 0x74);
    arg1[8] = *(int *)(base + 0x78);
    arg1[9] = *(int *)(base + 0x7c);
    arg1[10] = *(int *)(base + 0x80);
    arg1[11] = *(int *)(base + 0x84);
    *arg2 = *(float *)(base + 0xbc);
}
#pragma pop
extern float lbl_8055F484;
extern float lbl_80563C6C;
extern float lbl_80499980[8];
extern float lbl_80563C20;
void fn_8026A51C(void) {
    ((void (*)(void))fn_802693F4)();
}

float fn_8026A520(int arg0) {
    if (arg0 >= 0 && (unsigned int)arg0 < 8U) {
        return lbl_80499980[arg0];
    }
    return lbl_80563C20;
}

void fn_8026A54C(float arg0) {
    lbl_8055F484 = arg0;
}

int fn_8026A554(int *arg0) {
    int index = *arg0;
    if (index >= 0 && (unsigned int)index < 8U) {
        lbl_80499980[index] = lbl_80563C6C;
    }
    return 4;
}
extern float lbl_80563C20;
extern int lbl_80499E50[];


#include <types.h>
extern int lbl_8055D668, lbl_8055D66C;
extern int lbl_80558DA4, lbl_8055D65C, lbl_8055D660, lbl_8055D664;
extern unsigned char lbl_8055D646;
extern signed char lbl_8055D647;
extern struct lbl_8035BAD8_t { float f0; int f4; int f8; } lbl_8035BAD8;
extern char lbl_8035BB18[];
extern int fn_80012820(int);
extern void fn_800081BC(int);
extern int fn_80008188(void);
extern int fn_80012910(int);
typedef struct KObj KObj;
struct KVt {
    char pad0[0xC];
    unsigned char (*f0C)(KObj *, void *);
    char pad1[8];
    int (*f18)(KObj *, void *, int);
    char pad2[0x40];
    int (*f5C)(KObj *, int);
};
struct KObj { struct KVt *vt; };
typedef struct KArg {
    int f0;
    int f4;
    int f8;
    int fC;
    char pad[0x10];
    KObj *obj;
} KArg;
extern KArg *fn_8001285C(int);
extern int fn_80131234(void *);
extern int fn_80131264(void *);
extern int getDifficultyProperty(void *, int, int);
extern void fn_8001D884(void *, int);
extern int fn_8027DED0(void);
extern int fn_8001DA48(void *, int);
extern float fn_8014E7DC(int, int);
extern int fn_80129D18(int, int);
extern char *lbl_80558D8C;
extern int fn_8000DA10(void);
extern int fn_8001BA90(int, int, int, int, int);
extern void fn_8001BA70(int, int, unsigned char *, int);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055D644;
extern unsigned char lbl_8055D645;
extern int lbl_8055D638;
extern int lbl_8055D63C;
extern int lbl_8055D640;
/* Tips/results overlay state, started by fn_8001FEE8 and advanced by fn_800207B0. */
#define TIPS_START_MS  lbl_8055D63C /* overlay start time, drives the fade-in */
#define TIPS_CAMERA_MS lbl_8055D638 /* time the current tips camera entry began */
#define TIPS_WAIT_MS   lbl_8055D640 /* last tick while the overlay is paused */
#define OVERLAY_ON     lbl_8055D644 /* the overlay is being shown */
#define OVERLAY_PAUSED lbl_8055D645 /* overlay waits for a pause/jump condition to clear */
#define TIPS_ZOOM_ACTIVE lbl_8055D648 /* timed tips camera zoom is in progress */
#define GetTimeMs      KERNEL_GetTimeMs
#define RestartPhysics fn_80176734 /* reset the physics fader / pending command to restart the race */
extern unsigned char lbl_8055D670;
extern int lbl_8055D64C;
extern unsigned int lbl_8055E044;
extern float lbl_805604A8;
extern float lbl_805604AC;
extern float lbl_805604B0;
extern float lbl_805604B4;
extern float lbl_805604B8;
extern char lbl_802FE138[];
extern int lbl_80558D78;
extern int lbl_80558D7C;
extern int lbl_80558D80;
extern int lbl_80558D84;
extern int lbl_8055D62C;
extern int lbl_8055D650;
extern int lbl_8055D654;
extern int lbl_8055D658;
extern void fn_8012E81C(void*);
extern int loadFontTexture(void*);
extern int ArtSetGet(void*);
extern int RegisterTextureByName(void*, int);
extern void fn_802CAC54(int);
extern void fn_802328D4(int);
extern void fn_80235380(int);
extern void fn_801345D8(void*, ...);
  extern void fn_8000B3DC(s32);
  extern unsigned char lbl_8055D648;
  extern void fn_80230AD8(void*);
  extern void fn_80230B38(void*);
  extern void fn_80230B5C(void*);
  extern void fn_800209A0(int, float);
void fn_8001FD7C(void);
void fn_8001FF34(int);
struct cfg_t {
    char f0[0xc];
    char f1[0xc];
    char f2[0x10];
    char f3[0x10];
    char f4[0x10];
    char f5[0x10];
    char f6[0x10];
    char f7[0x10];
};
struct lbl_8035BAE4_t {
    int unk_0;
    int unk_4;
    unsigned int unk_8;
};
extern struct lbl_8035BAE4_t lbl_8035BAE4;
struct lbl_8035BAF0_t { float f0; int f4; int f8; };
extern struct lbl_8035BAF0_t lbl_8035BAF0;
extern char lbl_802FE1C0[0x100];
int KERNEL_GetTimeMs(void);
extern int lbl_8055D630;
extern int lbl_8055D634;
extern char lbl_8035B758[];
extern float lbl_805604BC;
extern float lbl_805604C0;
extern float lbl_805604C4;
extern float lbl_805604C8;
extern float lbl_805604CC;
extern float lbl_805604D0;
extern float lbl_805604D4;
extern float lbl_805604D8;
extern float lbl_805604DC;
extern float lbl_805604E0;
extern void fn_802A1120(float*, float*, float);
extern double cos(double);
extern float fn_801EA0E8(float, float, float, float, float, float, float);
extern void fn_8026E22C(float*, void*, void*, float);
extern void fn_80020070(float*);
extern double lbl_805604E8;
void fn_80176734(void);
int fn_801312EC(void*, void*);
void fn_80131318();
int fn_80232BA4(int, int, int, int, float, float, float, float, float);
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern int fn_80277960(void *, void *, void *);
extern void fn_802E30C8(const char *, ...);
extern void Abend_Panic(const char *, ...);
extern int fn_80019B84(void);
extern int fn_80019B90(void);
extern int fn_80019B3C(void);
extern int strcmp(const char *, const char *);
extern char lbl_80558D90;
extern char lbl_80558D98;
typedef void *(*VF_pp)(void *, void *);
typedef void *(*VF_pi)(void *, int);
typedef void *(*VF_p)(void *);
typedef int (*VF_ip)(void *, void *);
typedef float (*VF_fp)(void *, void *);
typedef char (*VF_cpi)(void *, void *, int);
#define VSLOT(o, off, T) ((T)(*(void ***)(o))[(off) / 4])
#pragma cplusplus on
struct VList_800201F0 {
    virtual void *f8(const char *);
    virtual void *fC();
    virtual int f10(const char *);
};
struct VObj_800201F0 {
    virtual const char *f8();
    virtual void *fC();
    virtual int f10(const char *);
    virtual void *f14(const char *);
    virtual void *f18();
    virtual void *f1C();
    virtual void *f20();
    virtual float f24(const char *);
    virtual void *f28();
    virtual void *f2C();
    virtual char f30(const char *, int);
    virtual void *f34();
    virtual void *f38();
    virtual void *f3C();
    virtual void *f40();
    virtual void *f44();
    virtual void *f48();
    virtual void *f4C();
    virtual void *f50();
    virtual void *f54();
    virtual void *f58();
    virtual void *f5C();
    virtual VObj_800201F0 *f60(int);
};
#pragma cplusplus reset
extern void fn_8001FEE8(void);

#pragma scheduling invalid_target
void fn_8001FD7C(void) {
    struct cfg_t* p = (struct cfg_t*) lbl_802FE138;
    fn_8012E81C(p);
    lbl_8055D64C = loadFontTexture(p->f1);
    lbl_8055D650 = loadFontTexture(p->f2);
    lbl_8055D654 = ArtSetGet(p->f3);
    lbl_8055D658 = ArtSetGet(p->f4);
    lbl_80558D78 = RegisterTextureByName(p->f5, 0);
    lbl_80558D7C = RegisterTextureByName(p->f6, 0);
    lbl_80558D80 = RegisterTextureByName(p->f7, 0);
    lbl_80558D84 = RegisterTextureByName(&p->f7[0x10], 0);
}
#pragma scheduling on

/* Tear down UI resources: clear init state, release four texture handles (set to -2) and free font/resource handles. */
void fn_8001FE20(void) {
    lbl_8055D62C = 0;
    fn_802CAC54(lbl_80558D84);
    lbl_80558D84 = -2;
    fn_802CAC54(lbl_80558D80);
    lbl_80558D80 = -2;
    fn_802CAC54(lbl_80558D78);
    lbl_80558D78 = -2;
    fn_802CAC54(lbl_80558D7C);
    lbl_80558D7C = -2;
    fn_802328D4(lbl_8055D64C);
    lbl_8055D64C = 0;
    fn_802328D4(lbl_8055D650);
    lbl_8055D650 = 0;
    fn_80235380(lbl_8055D654);
    lbl_8055D654 = 0;
    fn_80235380(lbl_8055D658);
    lbl_8055D658 = 0;
}

/* Restart action on the tips/results overlay: pause it, stamp the pause time, then request a physics restart. */
void fn_8001FEB8(void) {
    OVERLAY_PAUSED = 1;
    TIPS_WAIT_MS = GetTimeMs();
    RestartPhysics();
}

#pragma dont_inline on
/* Start/reset the tips overlay: stamp both timers with the current time, clear the pause timer, mark the overlay active and not paused. */
void fn_8001FEE8(void) {
#pragma scheduling off
    int now;
    now = GetTimeMs();
    TIPS_START_MS = now;
    TIPS_CAMERA_MS = now;
    TIPS_WAIT_MS = 0;
    OVERLAY_ON = 1;
    OVERLAY_PAUSED = 0;
#pragma scheduling on
}
#pragma dont_inline off

#pragma dont_inline on
void fn_8001FF24(void) {
    /* Reset the tips/results overlay: turn it off and clear any pending pause. */
    OVERLAY_ON = 0;
    OVERLAY_PAUSED = 0;
}
#pragma dont_inline off

extern char lbl_802FE138[];
extern int lbl_80558D78;
extern int lbl_80558D7C;
extern int lbl_80558D80;
extern int lbl_80558D84;
extern int lbl_8055D62C;
extern int lbl_8055D650;
extern int lbl_8055D654;
extern int lbl_8055D658;
extern void fn_8012E81C(void*);
extern int loadFontTexture(void*);
extern int ArtSetGet(void*);
extern int RegisterTextureByName(void*, int);
extern void fn_802CAC54(int);
extern void fn_802328D4(int);
extern void fn_80235380(int);

void fn_8001FFD0(int index, int formatId, void *buffer, int bufferSize) {
    /* Format a 1-based index into the buffer, selecting a format string by ID from lbl_802FE138 offsets. */
    char *base = lbl_802FE138;
    switch (formatId) {
        case 0x180303:
            ((void (*)(void *, int, char *, ...))fn_801345D8)(buffer, bufferSize, base + 0x98, index + 1);
            return;
        case 0x180201:
            ((void (*)(void *, int, char *, ...))fn_801345D8)(buffer, bufferSize, base + 0xAC, index + 1);
            return;
        case 0x180304:
            ((void (*)(void *, int, char *, ...))fn_801345D8)(buffer, bufferSize, base + 0xC0, index + 1);
            return;
        default:
            ((void (*)(void *, int, char *, ...))fn_801345D8)(buffer, bufferSize, base + 0xD4, index + 1);
            return;
    }
}

extern void PSVECCrossProduct();
extern void PSVECNormalize(float *, float *);
typedef void (*Cross3)(float *, float *, float *);
typedef void (*Cross4)(float *, float *, float *, float);
typedef void (*Cross5)(float *, float *, float *, float, float);
typedef void (*Cross7)(float *, float *, float *, float, float, float, float);
#pragma scheduling invalid_target
/* Rebuilds and orthonormalizes a 3x3 basis matrix in-place using the world up axis (0,1,0)
 * and the basis's third vector, producing three mutually perpendicular unit vectors. */
void fn_80020070(float *basis) {
    float worldUp[3];
    float tempZ[3];
    float tempY[3];
    float tempX[3];
    float x, y, z, a, b, c;

    worldUp[0] = 0.0f;
    worldUp[1] = 1.0f;
    worldUp[2] = 0.0f;
    ((Cross3)PSVECCrossProduct)(worldUp, basis + 6, basis);
    ((Cross3)PSVECCrossProduct)(basis + 6, basis, basis + 3);

    z = basis[2];
    y = basis[1];
    x = basis[0];
    tempX[0] = x;
    tempX[1] = y;
    tempX[2] = z;
    c = basis[8];
    b = basis[7];
    a = basis[6];
    tempZ[0] = a;
    tempZ[1] = b;
    tempZ[2] = c;
    ((Cross3)PSVECCrossProduct)(tempZ, tempX, tempY);
    PSVECNormalize(tempX, tempX);
    PSVECNormalize(tempY, tempY);
    ((Cross3)PSVECCrossProduct)(tempX, tempY, tempZ);

    basis[0] = tempX[0];
    basis[1] = tempX[1];
    basis[2] = tempX[2];
    basis[3] = tempY[0];
    basis[4] = tempY[1];
    basis[5] = tempY[2];
    basis[6] = tempZ[0];
    basis[7] = tempZ[1];
    basis[8] = tempZ[2];
}
/* Disable the AXFX audio hooks by requesting the disabled state (enabled = 0). */
void fn_8002017C(void) {
    fn_8000B3DC(0);
}

int fn_80020184(void) {
    /* Return a fade alpha (0xFF down to 0x00) based on time since lbl_8055D63C,
       starting 0x12C ticks after it and ramping over ~1000 ticks. */
    s32 clamped;
    u32 scaled;

    scaled = (((KERNEL_GetTimeMs() - lbl_8055D63C) - 0x12C) << 8) / 1000;
    clamped = scaled & ((s32) (-(s32) scaled & ~scaled) >> 0x1F);
    clamped = (clamped < 0xFF) ? clamped : 0xFF;
    return 0xFF - clamped;
}

/* Names and messages the tips loader uses; they sit in .data right after this
   module's config block (lbl_802FE138), so they are reached as offsets from it. */
#define TIPS_VAL_FILE     (base + 0xE4)  /* "camera3.val" */
#define TIPS_SEQ_NAME     (base + 0xF0)  /* "tips_sequence" */
#define TIPS_MSG_GOT_SEQ  (base + 0x100) /* "tips: got tips sequence" */
#define TIPS_PROP_START   (base + 0x118) /* "start_camera" */
#define TIPS_PROP_END     (base + 0x128) /* "end_camera" */
#define TIPS_MSG_NO_CAM1  (base + 0x134) /* "tips: can't find camera1 %s" */
#define TIPS_MSG_NO_CAM2  (base + 0x150) /* "tips: can't find camera2 %s" */
#define TIPS_PROP_TIME    (base + 0x16C) /* "duration" */
#define TIPS_MSG_NO_SEQ   (base + 0x178) /* "tips: camera3 does not contain tips sequence" */
#define TIPS_ITEM_CAMERA  (&lbl_80558D90) /* item type read here: "camera" */
#define TIPS_PROP_HERMITE (&lbl_80558D98) /* "hermite" */

/* One "camera" entry of the tips sequence (0x70 bytes; up to 8 of them live in
   the array at lbl_8035B758, their count is lbl_8055D630 and the one being
   shown lbl_8055D634).  fn_80277960 fills the two camera records by name, each
   with the extra float its lookup returns. */
struct TipsCamera_8035B758 {
    unsigned char startCamera[0x30]; /* the "start_camera" record */
    unsigned char endCamera[0x30];   /* the "end_camera" record */
    float startCameraParam;          /* float that came with the first record */
    float endCameraParam;            /* ... and with the second */
    float duration;                  /* the item's "duration" */
    char hermite;                    /* the item's "hermite" flag */
};
#pragma cplusplus on
#pragma use_lmw_stmw off
/* Loads the tip camera sequence at start-up: opens the "camera3.val" parameter
   archive, walks the items of its "tips_sequence" list and turns every "camera"
   item into one TipsCamera_8035B758 entry - the two cameras it names looked up
   by name, plus its duration and hermite flag.  Afterwards it (re)arms the tips
   flag lbl_8055D644 from the game-option bits, unless lbl_8055D646 forces tips
   off. */
extern "C" void fn_800201F0(void) {
    int tipOptions;
    char *base = lbl_802FE138;
    VList_800201F0 *valFile;
    VObj_800201F0 *sequence;
    VObj_800201F0 *item;
    int i;
    fn_8001FEE8();
    lbl_8055D630 = 0; /* number of entries in the sequence */
    lbl_8055D634 = 0; /* entry being shown */
    valFile = (VList_800201F0 *)fn_80131810(TIPS_VAL_FILE);
    if (valFile != 0) {
        if (valFile->f10(TIPS_SEQ_NAME) != 0) {
            sequence = (VObj_800201F0 *)valFile->f8(TIPS_SEQ_NAME);
            fn_802E30C8(TIPS_MSG_GOT_SEQ);
            for (i = 0; (item = sequence->f60(i)) != 0; i++) {
                if (strcmp(item->f8(), TIPS_ITEM_CAMERA) == 0) {
                    void *startName = item->f14(TIPS_PROP_START);
                    void *endName = item->f14(TIPS_PROP_END);
                    struct TipsCamera_8035B758 *entry =
                        (struct TipsCamera_8035B758 *)(lbl_8035B758 + lbl_8055D630 * 0x70);
                    lbl_8055D630 += 1;
                    if (fn_80277960(startName, entry->startCamera, &entry->startCameraParam) == 0) {
                        Abend_Panic(TIPS_MSG_NO_CAM1, startName);
                    }
                    /* the game reports the start camera's name here, too */
                    if (fn_80277960(endName, entry->endCamera, &entry->endCameraParam) == 0) {
                        Abend_Panic(TIPS_MSG_NO_CAM2, startName);
                    }
                    entry->duration = item->f24(TIPS_PROP_TIME);
                    entry->hermite = item->f30(TIPS_PROP_HERMITE, 0);
                }
            }
        } else {
            fn_802E30C8(TIPS_MSG_NO_SEQ);
        }
        fn_80131818(valFile);
    }
    tipOptions = 0;
    lbl_8055D648 = 0;
    if (fn_80019B84() != 0 || fn_80019B90() != 0 || fn_80019B3C() != 0) {
        tipOptions = 1;
    }
    /* __cntlzw(x) >> 5 is just "x != 0", written as a 0/1 byte */
    *(signed char *)&lbl_8055D644 = (unsigned int)__cntlzw(tipOptions) >> 5;
    if (lbl_8055D646 != 0) {
        lbl_8055D644 = 0;
        lbl_8055D648 = 1;
    }
}
#pragma cplusplus reset
/* RealName: Tips_HideOverlay
 * Thunk for the race teardown: take the tips/results overlay off screen and
 * clear the pause it may be waiting on (fn_8001FF24). */
void fn_80020430(void) {
    fn_8001FF24();
}

#pragma push
#pragma processor 750
#pragma scheduling on
int fn_80020434(void* arg0, float* arg1) {
    float out1[2], out2[2];
    float mat[12];
    float var_f1;
    float var_f3;
    float var_f31;
    float temp_f0;
    float temp_f1;
    float temp_f2;
    float temp_f3;
    float temp_f4;
    float temp_f5;
    float temp_f6;
    float temp_f7;
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r6;
    s32 temp_r0;
    void* temp_r28;

    mat[0] = 1.0f;
    mat[1] = 0.0f;
    mat[2] = 0.0f;
    mat[3] = 0.0f;
    mat[4] = 1.0f;
    mat[5] = 0.0f;
    mat[6] = 0.0f;
    mat[7] = 0.0f;
    mat[8] = 1.0f;
    mat[9] = 0.0f;
    mat[10] = 0.0f;
    mat[11] = 0.0f;
    fn_802A1120(out1, out2, lbl_805604B8);
    mat[9] = out1[0];
    mat[10] = lbl_805604B4;
    mat[11] = out1[1];
    mat[6] = out2[0];
    mat[7] = lbl_805604B4;
    mat[8] = out2[1];
    ((Cross7)PSVECCrossProduct)(&mat[3], &mat[6], &mat[0], out2[0], out1[1], lbl_805604B4, out1[0]);
    temp_r3 = KERNEL_GetTimeMs();
    temp_r6 = temp_r3 - lbl_8055D63C;
    temp_r0 = temp_r6 / 50000;
    temp_r0 = temp_r6 - temp_r0 * 50000;
    temp_f2 = (float)temp_r0 / lbl_805604BC * lbl_805604C0;
    temp_f7 = lbl_805604C4 + (lbl_805604C8 * (-(float)cos(temp_f2) + lbl_805604B8));
    temp_f5 = mat[9];
    temp_f3 = mat[10];
    temp_f6 = mat[6] * temp_f7;
    temp_f4 = mat[7] * temp_f7;
    temp_f1 = temp_f5 + temp_f6;
    temp_f2 = mat[11] + (mat[8] * temp_f7);
    mat[9] = temp_f1;
    mat[10] = temp_f3 + temp_f4;
    mat[11] = temp_f2;
    mat[10] = lbl_805604CC + fn_801EA0E8(temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6, temp_f7);
    var_f1 = lbl_805604D0;
    if (lbl_8055D630 > 0) {
        temp_r28 = &lbl_8035B758[lbl_8055D634 * 0x70];
        var_f31 = lbl_805604D4 * (float)(KERNEL_GetTimeMs() - lbl_8055D638);
        if (var_f31 > *(float*)&((char*)temp_r28)[0x68]) {
            temp_r4 = lbl_8055D634 + 1;
            lbl_8055D634 = (lbl_8055D634 + 1) % lbl_8055D630;
            lbl_8055D638 = KERNEL_GetTimeMs();
        }
        var_f3 = lbl_805604B8;
        temp_f0 = (var_f31 - lbl_805604B4) / (*(float*)&((char*)temp_r28)[0x68] - lbl_805604B4);
        var_f3 = var_f3 > temp_f0 ? temp_f0 : var_f3;
        var_f3 = var_f3 < lbl_805604B4 ? lbl_805604B4 : var_f3;
        var_f31 = lbl_805604B4 + var_f3 * lbl_805604B8;
        if (*(unsigned char*)&((char*)temp_r28)[0x6C] != 0) {
            var_f1 = lbl_805604D8;
            if (var_f31 < var_f1) {
            } else if (var_f31 > lbl_805604B8) {
                var_f1 = lbl_805604B8;
            } else if (var_f31 > lbl_805604B4) {
                var_f1 = var_f31 * (lbl_805604DC * var_f31 * var_f31) + lbl_805604E0 * var_f31 * var_f31;
            } else {
                var_f1 = var_f31 * (lbl_805604DC * var_f31 * var_f31) - lbl_805604E0 * var_f31 * var_f31;
            }
            var_f31 = var_f1;
        }
        fn_8026E22C(mat, temp_r28, (char*)temp_r28 + 0x30, var_f31);
        fn_80020070(mat);
        temp_f1 = *(float*)&((char*)temp_r28)[0x60];
        var_f1 = temp_f1 + var_f31 * (*(float*)&((char*)temp_r28)[0x64] - temp_f1);
    }
    ((s32*)arg0)[0] = ((s32*)mat)[0];
    ((s32*)arg0)[1] = ((s32*)mat)[1];
    ((s32*)arg0)[2] = ((s32*)mat)[2];
    ((s32*)arg0)[3] = ((s32*)mat)[3];
    ((s32*)arg0)[4] = ((s32*)mat)[4];
    ((s32*)arg0)[5] = ((s32*)mat)[5];
    ((s32*)arg0)[6] = ((s32*)mat)[6];
    ((s32*)arg0)[7] = ((s32*)mat)[7];
    ((s32*)arg0)[8] = ((s32*)mat)[8];
    ((s32*)arg0)[9] = ((s32*)mat)[9];
    ((s32*)arg0)[10] = ((s32*)mat)[10];
    ((s32*)arg0)[11] = ((s32*)mat)[11];
    *arg1 = var_f1;
}
#pragma pop
extern int fn_80020434(void*, float*);
extern int Camera_SetViewMatrix(void*, int, float);
extern int fn_8000C630(int, int);
/* Update timed overlay state and, while active, draw it and trigger sound 0x15. */
void fn_800207B0(void) {
    char overlayData[0x30];
    float overlayScale;

    if ((lbl_8055D644 != 0) && (lbl_8055D645 == 0)) {
        KERNEL_GetTimeMs();
    }
    if ((lbl_8055D644 != 0) && (lbl_8055D645 != 0) && ((fn_801E8838() > 0xF0) || ((KERNEL_GetTimeMs() - lbl_8055D640) > 0x4B0))) {
        lbl_8055D645 = 0;
        lbl_8055D644 = 0;
    }
    if (lbl_8055D644 != 0) {
        fn_80020434(&overlayData, &overlayScale);
        Camera_SetViewMatrix(&overlayData, 0, overlayScale);
        fn_8000C630(0x15, -1);
    }
}

extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern double lbl_805604E8;
extern float lbl_805604F0;
extern float lbl_805604F4;
extern float lbl_805604F8;
extern float lbl_805604FC;
extern int drawPictureScaled(int, int, s32, f32, f32, f32, f32, f32);
#pragma push
#pragma dont_inline on
void fn_80020860(int arg0) {
    f32 t4;
    f32 t5;

    t4 = lbl_805604F0 * (f32)lbl_8055CFF0 / lbl_805604F4;
    t5 = (f32)lbl_8055CFF4;
    drawPictureScaled(lbl_8055D654, 0, (arg0 << 24) | 0xFF0000 | 0xFFFF,
                lbl_805604F8 * t4,
                lbl_805604FC * t5,
                lbl_805604B4,
                t4,
                t5);
}

#pragma push
#pragma scheduling invalid_target
void fn_800208F0(int arg0, unsigned char *arg1, int arg2) {
    /* Look up a string/value for arg0 via fn_8001BA90(fn_8000DA10(), arg0, lbl_8055D668,
     * lbl_8055D66C, -1). If found, copy it with fn_8001BA70; otherwise copy the
     * fallback string at lbl_80558D8C into the output buffer, truncating to arg2. */
    char ch;
    int remaining;
    unsigned char *dst;
    char *src;
    int index;

    remaining = arg2;
    dst = arg1;
    index = fn_8001BA90(fn_8000DA10(), arg0, lbl_8055D668, lbl_8055D66C, -1);
    if ((unsigned int)((s32)index + 0x10000) != 0xFFFF) {
        fn_8001BA70(arg0, index, dst, remaining);
        return;
    }
    src = lbl_80558D8C;
    goto loop_body;
count_check:
    remaining -= 1;
    if (remaining > 0) {
        goto loop_body;
    }
    dst[-1] = 0;
    return;
loop_body:
    ch = *src;
    src += 1;
    *dst = ch;
    dst += 1;
    if (ch != 0) {
        goto count_check;
    }
}

extern int fn_802C9A58(void);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
extern int lbl_8055CFF4, lbl_8055D66C;
extern unsigned char lbl_8055D646;
extern float lbl_805604B8, lbl_805604F8, lbl_805604FC, lbl_80560500, lbl_80560504;
extern float lbl_80560508, lbl_8056050C, lbl_80560510, lbl_80560514, lbl_80560518;
extern float lbl_8056051C, lbl_80560520, lbl_80560524, lbl_80560528, lbl_8056052C;
extern float lbl_80560530, lbl_80560534, lbl_80560538, lbl_8056053C, lbl_80560540;
extern float lbl_80560544, lbl_80560548, lbl_8056054C, lbl_80560550;
extern void fn_80148134(float, float, float *, float *, int);
extern void fn_80011280(int, int, float, float, float);
extern void fn_8023293C(int, int, float);
extern void Text_drawWordWrapped(int, int, int, int, int, float, float, float, float, float, float);
extern int fn_800167F4(void);
extern void fn_80130FCC(void *, int, int);
extern void fn_80130980(void *, int, int, float);
extern void *fn_8001BB58();
extern char *__AXGetStackHead(void);
extern int fn_8001BA6C(int);
extern signed char lbl_8055D671;
extern int lbl_802ED850[3];
extern int lbl_80558DA0;
#pragma processor 750
#pragma ppc_psq_save off
void fn_800209A0(int arg0, float arg1)
{
  int color2;
  int textId;
  int color;
  int colorTable[3];
  float f5;
  float t0;
  float t1;
  int n = 0x40;
  float f25;
  float f26;
  float f27;
  float f28;
  float f29;
  float outA;
  float outB;
  float outC;
  float outD;
  float g;
  float u;
  float v;
  int alpha;
  float f25b;
  float f26b;
  float f24;
  int i;
  int svals[3];
  void *res;
  char ch;
  char *base = lbl_802FE138;
  f5 = (fn_802C9A58() != 0) ? (lbl_80560500) : (lbl_805604B4);
  t1 = (f32) lbl_8055CFF4;
  f27 = lbl_805604FC * t1;
  t0 = (f32) lbl_8055CFF0;
  f25 = (lbl_805604F8 * t0) + f5;
  f28 = f27 - lbl_80560504;
  f26 = lbl_80560504 + f25;
  f29 = f28 - lbl_80560504;
  color = (((arg0 << 16) << 8) | 0xFF0000) | 0xFFFF;
  colorTable[0] = 0xff259327;
  colorTable[1] = 0xffb71b00;
  colorTable[2] = 0xff003fa8;
  color2 = colorTable[lbl_8055D66C];
  if (lbl_8055D646 == 0)
  {
    color2 = 0;
  }
  fn_80231220(lbl_80558D80, color2, f25, f27, f26 - f25, f27 - f28, lbl_805604B4, lbl_805604B4, lbl_805604B8, lbl_805604B8);
  fn_80231220(lbl_80558D84, color2, f25, f28, f26 - f25, f28 - f29, lbl_805604B4, lbl_805604B4, (float) lbl_805604B8, lbl_805604B8);
  fn_80231220(lbl_80558D78, color, f25, f27, f26 - f25, f27 - f28, lbl_805604B4, lbl_805604B4, lbl_805604B8, lbl_805604B8);
  fn_80231220(lbl_80558D7C, color, f25, f28, f26 - f25, f28 - f29, lbl_805604B4, lbl_805604B4, lbl_805604B8, lbl_805604B8);
  fn_80148134(lbl_80560508, lbl_8056050C, &outA, &outB, 2);
  fn_80148134(lbl_80560508, lbl_80560510, &outC, &outD, 2);
  fn_80232BA4(lbl_8055D660, lbl_8055D64C, color, 9, outA, outB, lbl_80560514, lbl_805604B4, lbl_805604B8);
  fn_80232BA4(lbl_8055D664, lbl_8055D64C, color, 9, outC, outD, lbl_80560518, lbl_805604B4, lbl_805604B8);
  if ((lbl_8055D646 == 0) && (lbl_8055D647 != 0))
  {
    g = lbl_805604D8;
    if (arg1 < lbl_805604D8)
    {
      goto g1done;
    }
    g = lbl_805604B8;
    if (arg1 <= lbl_805604B8)
    {
      goto g1b;
    }
    goto g1done;
    g1b:
    u = lbl_805604DC * arg1;

    v = lbl_805604E0 * arg1;
    u = u * arg1;
    v = v * arg1;
    u = arg1 * u;
    g = lbl_805604B4;
    if (arg1 > lbl_805604B4)
    {
      g = v + u;
    }
    else
    {
      g = u - ((unsigned char) ((unsigned long) v));
    }
    g1done:
    alpha = ((arg0 * 0xC0) / 255) << 24;

    alpha |= 0xFF0000 | 0xFFFF;
    f25b = (lbl_805604FC * lbl_80560520) - lbl_80560524;
    f26b = (((f32) lbl_8055CFF0) * (g * lbl_8056051C)) - lbl_80560528;
    fn_80011280(alpha, lbl_8055D658, f26b, f25b, lbl_8056052C);
    if (lbl_8055D671 == 0)
    {
      fn_801312EC(&lbl_8035BAF0, &base[0x1a8]);
      lbl_8055D671 = 1;
    }
    if (lbl_8035BAF0.f8 != lbl_8055E044)
    {
      fn_80131318();
    }
    fn_8023293C(lbl_8055D64C, lbl_8035BAF0.f4, lbl_805604B8);
    Text_drawWordWrapped(lbl_8055D65C, lbl_8055D64C, -1, 0x11, 0, lbl_805604C8 + f26b, f25b - lbl_80560530, lbl_80560534, lbl_80560538, lbl_805604B4, lbl_805604B8);
  }
  if (((lbl_8055D646 == 0) && ((((((lbl_8055D647 & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) == 0)) && (fn_800167F4() == 1))
  {
    g = lbl_805604D8;
    if (arg1 < lbl_805604D8)
    {
      goto g2done;
    }
    g = lbl_805604B8;
    if (arg1 > lbl_805604B8)
    {
      goto g2done;
    }
    u = lbl_805604DC * arg1;
    v = lbl_805604E0 * arg1;
    u = u * arg1;
    v = v * arg1;
    u = u * arg1;
    g = lbl_805604B4;
    if (arg1 > lbl_805604B4)
    {
      g = v + u;
    }
    else
      if (t0)
    {
      g = u - v;
    }
    else
    {
      g = u - v;
    }
    g2done:
    f24 = (((f32) lbl_8055CFF4) * ((0, lbl_8056051C * g))) - lbl_8056053C;

    alpha = ((arg0 * 0xC0) / 255) << 24;
    alpha |= 0xFF0000 | 0xFFFF;
    fn_80011280(alpha, lbl_8055D658, f24, lbl_8056050C, lbl_80560540);
    svals[0] = lbl_802ED850[0];
    svals[1] = lbl_802ED850[1];
    svals[2] = lbl_802ED850[2];
    for (i = 0; i < 3; i++)
    {
      char buf[0x40] = {0};
      textId = (int) (&lbl_80558DA0);
      switch (svals[i])
      {
        case 0:
          textId = fn_8001BA6C(0x22205);
          fn_800208F0(0x22205, (unsigned char *) buf, 0x40);
          break;

        case 1:
          textId = fn_8001BA6C(0x40901);
          fn_800208F0(0x40901, (unsigned char *) buf, 0x40);
          break;

        case 2:
          textId = fn_8001BA6C(0x40902);
          fn_800208F0(0x40902, (unsigned char *) buf, 0x40);
          break;

        case 3:
          textId = fn_8001BA6C(0x41206);
          fn_800208F0(0x41206, (unsigned char *) buf, 0x40);
          break;

        case 4:
          textId = fn_8001BA6C(0x20507);
          fn_800208F0(0x20507, (unsigned char *) buf, 0x40);
          break;

        case 5:
          buf[0] = 0;
          break;

        case 6:
          textId = fn_80131234(&base[0x1b4]);
          fn_80130FCC(buf, 0x40, lbl_8035BAD8.f8);
          break;

        case 7:
          if (fn_800167F4() != 1)
        {
          if (arg1 || buf)
          {
            buf[0] = 0;
          }
          else
          {
            buf[0] = 0;
          }
        }
        else
        {
          textId = fn_80131234(&base[((((((((0x1c4 & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu]);
          fn_80130FCC(buf, 0x40, lbl_8035BAD8.f4);
        }
          break;

        case 8:
          if (fn_800167F4() == 1)
        {
          textId = fn_80131234(&base[0x1d4]);
          fn_80130980(buf, 0x40, 2, lbl_8035BAD8.f0);
        }
        else
        {
          buf[0] = 0;
        }
          break;

        case 9:
          res = fn_8001BB58(fn_8000DA10(), lbl_8055D668, lbl_8055D66C, 0);
        {
          char *d = buf;
          char *s;
          if ((res != 0) && (((*((int *) (((char *) res) + 8))) + 1) >= (0 + 1)))
          {
            s = __AXGetStackHead();
          }
          else
          {
            int n = 0x40;
            s = lbl_80558D8C;
          }
          do
          {
            ch = *(s++);
            *(d++) = ch;
            if (ch == 0)
            {
              break;
            }
            n--;
          }
          while (n > 0);
          if ((n - 1) <= (0 - 1))
          {
            d[-1] = 0;
          }
        }
          textId = fn_80131234(&base[0x1e8]);
          break;

        case 10:
          res = fn_8001BB58(fn_8000DA10(), lbl_8055D668, lbl_8055D66C, 0);
          if ((res != 0) && ((*((int *) (((char *) res) + 4))) >= 0))
        {
          fn_80130FCC(buf, 0x40, *((int *) (((char *) res) + 4)));
        }
        else
        {
          char *d = buf;
          char *s = lbl_80558D8C;
          do
          {
            ch = *(s++);
            *(d++) = ch;
            if (ch == 0)
            {
              break;
            }
            n--;
          }
          while (n > 0);
          if (n <= 0)
          {
            d[-1] = 0;
          }
        }
          textId = fn_80131234(&base[0x1fc]);
          break;

        default:
          buf[0] = lbl_805604B4 * 0;
          break;

      }

      {
        float f23;
        f23 = f27 - (f26 * (((f32) i) - f25));
        fn_80232BA4(textId, lbl_8055D64C, color, 0x11, f29 + f24, f23, lbl_8056054C, lbl_805604B4, lbl_805604B8);
        if (svals[i] != 8)
        {
          fn_80232BA4((int) buf, lbl_8055D64C, color, 0x12, (f28 + f24) - f29, f23, lbl_8056054C, lbl_805604B4, lbl_805604B8);
        }
        else
        {
          fn_80232BA4((int) buf, lbl_8055D650, color, 0x12, lbl_805604C4 + ((f28 + f24) - f29), arg1 + f23, lbl_80560550, lbl_805604B4, arg1);
        }
      }
    }

  }
}
#pragma ppc_psq_save reset

#pragma pop

extern int fn_80020184(void);
extern int fn_801E8838(void);
extern int fn_8020DE1C(void);
/* One of the module's lazily-created UI text objects.  fn_801312EC starts one
   from a "Page:Element" path, fn_80131318 resolves that path against the font
   set currently loaded (lbl_8055E044) and records its id, so the object is
   resolved again whenever the game switches font.  lbl_8035BAE4, the
   "Tips:LOADING" text drawn by fn_8001FF34, has the same layout. */
struct TipsTextObj {
    void *path;               /* +0 the "Page:Element" string it was built from */
    int text;                 /* +4 resolved text object, drawn by fn_80232BA4 */
    unsigned int resolvedFor; /* +8 id of the font set +4 was resolved for */
};
extern struct TipsTextObj lbl_8035BAFC; /* the "ResultsOverlay:PRESS_TO_CONTINUE" prompt */
extern struct TipsTextObj lbl_8035BB08; /* the "ResultsOverlay:PRESS_FOR_OPTIONS" prompt */
extern char lbl_802FE374[], lbl_802FE398[]; /* those two prompts' "Page:Element" paths */

/* Where the two prompts sit under the tips box, in UI screen coordinates. */
#define PROMPT_LAYOUT      20          /* fn_80232BA4 layout flags the prompts share */
#define PROMPT_LEFT_X      lbl_80560500 /* -107.0f: "PRESS_FOR_OPTIONS" */
#define PROMPT_RIGHT_X     lbl_8056055C /* +107.0f: "PRESS_TO_CONTINUE" */
#define PROMPT_Y           lbl_80560558 /* -190.0f, shared by both */
#define PROMPT_SCALE       lbl_805604B0 /* 0.7333333 */
#define ALPHA_OPAQUE       255          /* full alpha of the box / of the fade */
#define ALPHA_TO_UNIT      lbl_80560554 /* 255.0f: turns an 0..255 alpha into 0..1 */

/* What the globals fn_80021258 works on hold.  The game's symbols can't be
   renamed yet, so the rest of the file still uses the lbl_ names. */
#define OVERLAY_ACTIVE  lbl_8055D644 /* the tips/results overlay is being shown */
#define CONTINUE_MADE   lbl_8055D672 /* the "PRESS_TO_CONTINUE" text was built */
#define OPTIONS_MADE    lbl_8055D673 /* the "PRESS_FOR_OPTIONS" text was built */
#define UI_FONT         lbl_8055D64C /* the "uifnt_o.gtx" font fn_8001FD7C opened */
#define FONT_SET        lbl_8055E044 /* id of the font set loaded right now */
extern unsigned char lbl_8055D672, lbl_8055D673;
extern float lbl_80560554, lbl_80560500, lbl_80560558, lbl_8056055C;
#pragma dont_inline on
int fn_80021258(void) {
    /* Per-frame update of the results overlay shown over the tips box.
       Does nothing while the overlay is switched off (OVERLAY_ACTIVE).
       fn_80020184() is the overlay's own fade-out: still fully opaque for the
       first 300 ms of the results screen and gone a second later.  While it is
       up the "loadback" image is drawn over the box (fn_80020860) and the box
       itself gets no fade of its own; afterwards the box follows the race's own
       0..255 value (fn_801E8838), scaled down to 0..1.  Finally, unless the
       sound system is muted (fn_8020DE1C), the two "press a button" prompts are
       drawn under the box. */
    int fade;
    float boxAlpha;
    unsigned int fontSetId;
    if (!OVERLAY_ACTIVE) return 0;
    fade = fn_80020184();
    if (fade > 0) fn_80020860(fade);
    if (fade > 0) boxAlpha = lbl_805604B4; /* 0.0f */
    else boxAlpha = (float)fn_801E8838() / ALPHA_TO_UNIT;
    fn_800209A0(ALPHA_OPAQUE, boxAlpha);
    if (fn_8020DE1C() == 0) {
        /* the two prompts are built once, the first time they are needed */
        if ((signed char)CONTINUE_MADE == 0) {
            fn_801312EC(&lbl_8035BAFC, &lbl_802FE374); /* "ResultsOverlay:PRESS_TO_CONTINUE" */
            CONTINUE_MADE = 1;
        }
        if ((signed char)OPTIONS_MADE == 0) {
            fn_801312EC(&lbl_8035BB08, &lbl_802FE398); /* "ResultsOverlay:PRESS_FOR_OPTIONS" */
            OPTIONS_MADE = 1;
        }
        /* re-resolve each text when the font set changed, then draw it */
        fontSetId = lbl_8035BB08.resolvedFor;
        if (fontSetId != FONT_SET) fn_80131318(&lbl_8035BB08, fontSetId);
        fn_80232BA4(lbl_8035BB08.text, UI_FONT, -1 /* opaque white */, PROMPT_LAYOUT,
                    PROMPT_LEFT_X, PROMPT_Y, PROMPT_SCALE,
                    lbl_805604B4 /* 0.0f */, lbl_805604B8 /* 1.0f */);
        fontSetId = lbl_8035BAFC.resolvedFor;
        if (fontSetId != FONT_SET) fn_80131318(&lbl_8035BAFC, fontSetId);
        fn_80232BA4(lbl_8035BAFC.text, UI_FONT, -1 /* opaque white */, PROMPT_LAYOUT,
                    PROMPT_RIGHT_X, PROMPT_Y, PROMPT_SCALE,
                    lbl_805604B4 /* 0.0f */, lbl_805604B8 /* 1.0f */);
    }
    return 1;
}
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
int fn_800213DC(int keyCode) {
    /* Handles specific key presses when enabled and no blocking state is active. */
    int handled;
    if (lbl_8055D644) {
        if (!lbl_8055D645 && !fn_801E8838() && !fn_802E4A10()) {
            switch (keyCode) {
                case 0x58:
                    fn_8001FEB8();
                    break;
                case 0x1B:
                    fn_8002017C();
                    break;
            }
        }
        handled = 1;
    } else {
        handled = 0;
    }
    return handled;
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma scheduling invalid_target
void fn_80021464(KArg *a, int arg1) {
    KArg *p;
    int sp[6];
    int c, rk, vhh;
    char *base = lbl_802FE138;
    lbl_8055D62C = 1;
    fn_8001FEE8();
    fn_800081BC(fn_80012820(a->f4) + 8);
    lbl_8055D660 = fn_80008188();
    vhh = fn_80012910(a->f0);
    lbl_8055D664 = a->obj->vt->f18(a->obj, base + 0x284, vhh);
    lbl_8055D646 = a->obj->vt->f0C(a->obj, base + 0x294);
    if (lbl_8055D646 != 0) {
        lbl_8055D660 = fn_80131234(base + 0x2A0);
    }
    {
        int course = a->f0;
        c = a->f8;
        lbl_8055D66C = arg1;
        lbl_8055D668 = course;
        lbl_8055D647 = (c != 0x180302);
        p = fn_8001285C(course);
    }
    fn_80012820(p->f4);
    lbl_8035BAD8.f8 = p->fC;
    vhh = p->obj->vt->f5C(p->obj, getDifficultyProperty(base + 0x2B4, lbl_8055D66C, lbl_8055D668));
    if (vhh != 0) {
        fn_8001D884(sp, vhh);
        rk = fn_8027DED0();
        if (rk == -1) {
            rk = sp[5];
        }
        lbl_8035BAD8.f4 = fn_8001DA48(sp, rk);
    }
    lbl_8035BAD8.f0 = fn_8014E7DC(lbl_8055D668, arg1);
    vhh = 0;
    for (;;) {
        fn_8001FFD0(vhh, c, lbl_8035BB18, 0x40);
        if (fn_80131264(lbl_8035BB18) == 0) break;
        vhh++;
    }
    if (vhh == 0) vhh = 1;
    {
    int n = vhh;
    rk = 0;
    do {
        vhh = fn_80129D18(1, n);
        if (vhh != lbl_80558DA4) break;
        rk++;
    } while (rk < 10);
    }
    lbl_80558DA4 = vhh;
    fn_8001FFD0(vhh, c, lbl_8035BB18, 0x40);
    lbl_8055D65C = fn_80131234(lbl_8035BB18);
}
#pragma scheduling on
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma pop
void fn_8002167C(void) {
    #define HideOverlay fn_8001FF24
    /* Hide the tips/results overlay: clear the on-screen flag and any pending pause. */
    HideOverlay();
    #undef HideOverlay
}

void fn_80021680(void) {
    /* Audio-DSP case 1: redraw the loading/tips overlay — opaque white art, the overlay effect/message pass, then the "Tips:LOADING" text. */
    fn_80020860(0xFF);
    fn_800209A0(0xFF, lbl_805604B4);
    fn_8001FF34(-1);
}

/* Audio-DSP init callback: queue request kind 2, serviced by soundRunPendingRequest. */
void __AXDSPInitCallback_800216B8(void) {
    #define audioDspRequest lbl_8055D62C
    audioDspRequest = 2;
    #undef audioDspRequest
}

/* Empty counterpart of __AXDSPInitCallback_800216B8 (which queues tips-overlay
 * audio-DSP request 2): fn_80244738 calls it once that request has been drawn
 * and finalized, and the request needs no clean-up, so it does nothing. */
void fn_800216C4(void) {
}

#pragma push
#pragma inline_depth 0
void fn_800216C8(void) {
    /* Audio-DSP request case 2: redraw only the "Tips:LOADING" text overlay. */
    fn_8001FF34(-1);
}
extern int lbl_8055D668, lbl_8055D66C;
extern char *lbl_80558D8C;
extern int fn_8000DA10(void);
extern int fn_8001BA90(int, int, int, int, int);
extern void fn_8001BA70(int, int, unsigned char *, int);
#pragma dont_inline on
/* True while the tips/results overlay is being shown and is not paused. */
int fn_800216D0(void) {
    int active = 0;
    if (OVERLAY_ON) {
        if (!OVERLAY_PAUSED) active = 1;
    }
    return active;
}
/* Returns whether the tips/results overlay is currently being shown. */
unsigned char fn_800216F4(void) {
    return OVERLAY_ON;
}

int fn_800216FC(void) {
    /* Nonzero while the results/tips overlay is up and its fade-out (fn_80020184) has not finished. */
    if (OVERLAY_ACTIVE != 0)
        return fn_80020184() > 0;
    return 0;
}

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
int soundRunPendingRequest(void) {
    /* If an audio DSP request is pending, process it (state 2/1 run their handlers), finalize, and report handled. */
    extern void fn_80230B38_0(void);
    char buffer[0x38];

    if (lbl_8055D62C != 0) {
        fn_80230B5C(buffer);
        fn_80230AD8(buffer);
        switch (lbl_8055D62C) {
        case 2:
            fn_800216C8();
            break;
        case 1:
            fn_80021680();
            break;
        }
        {
            void (*finalize)(void) = (void (*)(void))fn_80230B38;
            finalize();
        }
        return 1;
    }
    return 0;
}
#pragma pop
int fn_800217AC(void) {
    int result;
    /* Ready to advance the tips overlay only when no camera zoom is running and
       the overlay is either hidden or paused. */
    if (TIPS_ZOOM_ACTIVE != 0)
        return 0;
    result = 0;
    if (OVERLAY_ON == 0 || OVERLAY_PAUSED != 0)
        result = 1;
    return result;
}

extern float lbl_80560560, lbl_80560564, lbl_805604B8, lbl_805604B4, lbl_80560568, lbl_80560554, lbl_805604FC;
extern int KERNEL_GetTimeMs(void);
extern void fn_80020860(int);
void fn_800217E4(void) {
    /* While active, updates a time-based value from elapsed ticks and applies it for up to 1500 ticks. */
    float computedValue;
    float convertedValue;
    float progress;
    int elapsed;
    int amount;

    if (lbl_8055D648 != 0) {
        elapsed = KERNEL_GetTimeMs() - lbl_8055D63C;
        if (elapsed < 0x5DC) {
            progress = lbl_805604B8;
            progress = progress < ((float)elapsed - lbl_80560560) / lbl_80560564
                ? progress
                : ((float)elapsed - lbl_80560560) / lbl_80560564;
            progress = progress > lbl_805604B4 ? progress : lbl_805604B4;
            computedValue = lbl_80560554 + (progress * lbl_80560568);
            if (computedValue < lbl_805604B4) {
                convertedValue = computedValue - lbl_805604FC;
            } else {
                convertedValue = lbl_805604FC + computedValue;
            }
            amount = (int)convertedValue;
            if (amount > 0) {
                fn_80020860(amount);
                fn_800209A0(amount, lbl_805604B4);
            }
        } else {
            lbl_8055D648 = 0;
        }
    }
}

void fn_800218F4(void) {
    #define InitOverlayConfig fn_8001FD7C
    /* Initialize the tips/results overlay config from the game's config block. */
    InitOverlayConfig();
    #undef InitOverlayConfig
}

void fn_800218F8(void) {
    #define ShutdownOverlay fn_8001FE20
    /* Tear down the tips/results overlay: clear its state and free its texture and UI handles. */
    ShutdownOverlay();
    #undef ShutdownOverlay
}
void fn_8001FF34(int arg0) {
    /* Lazily initialize the "Tips:LOADING" text object, re-resolve it if the font set changed, then draw it. */
    if ((char)lbl_8055D670 == 0) {
        fn_801312EC(&lbl_8035BAE4, &lbl_802FE1C0);
        lbl_8055D670 = 1;
    }
    if (lbl_8035BAE4.unk_8 != lbl_8055E044) {
        fn_80131318(&lbl_8035BAE4);
    }
    fn_80232BA4(lbl_8035BAE4.unk_4, lbl_8055D64C, arg0, 0x12, lbl_805604A8, lbl_805604AC, lbl_805604B0, lbl_805604B4, lbl_805604B8);
}

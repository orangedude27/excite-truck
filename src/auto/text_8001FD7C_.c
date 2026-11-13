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
extern int fn_80205268(void *, int, int);
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
extern int fn_80232578(void*);
extern int fn_8023512C(void*);
extern int fn_802CAC28(void*, int);
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
extern char lbl_802FE1C0[0x100];
int fn_802E2C20(void);
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
extern void fn_802E317C(const char *, ...);
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
    lbl_8055D64C = fn_80232578(p->f1);
    lbl_8055D650 = fn_80232578(p->f2);
    lbl_8055D654 = fn_8023512C(p->f3);
    lbl_8055D658 = fn_8023512C(p->f4);
    lbl_80558D78 = fn_802CAC28(p->f5, 0);
    lbl_80558D7C = fn_802CAC28(p->f6, 0);
    lbl_80558D80 = fn_802CAC28(p->f7, 0);
    lbl_80558D84 = fn_802CAC28(&p->f7[0x10], 0);
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

void fn_8001FEB8(void) {
    lbl_8055D645 = 1;
    lbl_8055D640 = fn_802E2C20();
    fn_80176734();
}

#pragma dont_inline on
void fn_8001FEE8(void) {
#pragma scheduling off
    int temp_r3;
    temp_r3 = fn_802E2C20();
    lbl_8055D63C = temp_r3;
    lbl_8055D638 = temp_r3;
    lbl_8055D640 = 0;
    lbl_8055D644 = 1;
    lbl_8055D645 = 0;
#pragma scheduling on
}
#pragma dont_inline off

#pragma dont_inline on
void fn_8001FF24(void) {
    lbl_8055D644 = 0;
    lbl_8055D645 = 0;
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
extern int fn_80232578(void*);
extern int fn_8023512C(void*);
extern int fn_802CAC28(void*, int);
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
#pragma push
#pragma scheduling on
void fn_80020070(float *arg0) {
    float axis[3];
    float vec2[3];
    float cross[3];
    float vec0[3];
    float b4 = lbl_805604B4;
    float b8 = lbl_805604B8;
    float x, y, z, a, b, c;

    axis[0] = b4;
    axis[1] = b8;
    axis[2] = b4;
    ((Cross3)PSVECCrossProduct)(axis, arg0 + 6, arg0);
    ((Cross3)PSVECCrossProduct)(arg0 + 6, arg0, arg0 + 3);

    z = arg0[2];
    y = arg0[1];
    x = arg0[0];
    vec0[0] = x;
    vec0[1] = y;
    vec0[2] = z;
    c = arg0[8];
    b = arg0[7];
    a = arg0[6];
    vec2[0] = a;
    vec2[1] = b;
    vec2[2] = c;
    ((Cross3)PSVECCrossProduct)(vec2, vec0, cross);
    PSVECNormalize(vec0, vec0);
    PSVECNormalize(cross, cross);
    ((Cross3)PSVECCrossProduct)(vec0, cross, vec2);

    arg0[0] = vec0[0];
    arg0[1] = vec0[1];
    arg0[2] = vec0[2];
    arg0[3] = cross[0];
    arg0[4] = cross[1];
    arg0[5] = cross[2];
    arg0[6] = vec2[0];
    arg0[7] = vec2[1];
    arg0[8] = vec2[2];
}
void fn_8002017C(void) {
    fn_8000B3DC(0);
}

int fn_80020184(void) {
    s32 temp_r3;
    u32 temp_r3_2;

    temp_r3_2 = (((fn_802E2C20() - lbl_8055D63C) - 0x12C) << 8) / 1000;
    temp_r3 = temp_r3_2 & ((s32) (-(s32) temp_r3_2 & ~temp_r3_2) >> 0x1F);
    temp_r3 = (temp_r3 < 0xFF) ? temp_r3 : 0xFF;
    return 0xFF - temp_r3;
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
                        fn_802E317C(TIPS_MSG_NO_CAM1, startName);
                    }
                    /* the game reports the start camera's name here, too */
                    if (fn_80277960(endName, entry->endCamera, &entry->endCameraParam) == 0) {
                        fn_802E317C(TIPS_MSG_NO_CAM2, startName);
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
void fn_80020430(void) {
    fn_8001FF24();
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
int fn_80020434(void* arg0, float* arg1) {
    float out1[2], out2[2];
    float mat[12];
    float dbl_tmp[2];
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

    mat[1] = lbl_805604B4;
    mat[0] = lbl_805604B8;
    mat[3] = lbl_805604B4;
    mat[2] = lbl_805604B4;
    mat[4] = lbl_805604B8;
    mat[5] = lbl_805604B4;
    mat[7] = lbl_805604B4;
    mat[6] = lbl_805604B4;
    mat[8] = lbl_805604B8;
    mat[10] = lbl_805604B4;
    mat[9] = lbl_805604B4;
    mat[11] = lbl_805604B4;
    fn_802A1120(out1, out2, lbl_805604B8);
    mat[9] = out1[0];
    mat[10] = lbl_805604B4;
    mat[11] = out1[1];
    mat[6] = out2[0];
    mat[7] = lbl_805604B4;
    mat[8] = out2[1];
    ((Cross7)PSVECCrossProduct)(&mat[3], &mat[6], &mat[0], out2[0], out1[1], lbl_805604B4, out1[0]);
    temp_r3 = fn_802E2C20();
    temp_r6 = temp_r3 - lbl_8055D63C;
    temp_r0 = temp_r6 / 50000;
    temp_r0 = temp_r6 - temp_r0 * 50000;
    dbl_tmp[0] = 176.0f;
    *(s32*)&dbl_tmp[1] = temp_r0 ^ 0x8000;
    temp_f2 = (float)(*(double*)&dbl_tmp[0] - lbl_805604E8) / lbl_805604BC * lbl_805604C0;
    temp_f7 = lbl_805604C4 + (lbl_805604C8 * (lbl_805604B8 - cos(temp_f2)));
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
        dbl_tmp[0] = 176.0f;
        temp_r3 = fn_802E2C20();
        temp_r0 = (temp_r3 - lbl_8055D638) ^ 0x8000;
        *(s32*)&dbl_tmp[1] = temp_r0;
        var_f31 = lbl_805604D4 * (float)(*(double*)&dbl_tmp[0] - lbl_805604E8);
        temp_f3 = *(float*)&((char*)temp_r28)[0x68];
        if (var_f31 > temp_f3) {
            temp_r4 = lbl_8055D634 + 1;
            lbl_8055D634 = (lbl_8055D634 + 1) % lbl_8055D630;
            lbl_8055D638 = fn_802E2C20();
        }
        var_f3 = lbl_805604B8;
        temp_f0 = (var_f31 - lbl_805604B4) / (temp_f3 - lbl_805604B4);
        if (var_f3 >= temp_f0) {
            var_f3 = temp_f0;
        }
        if (var_f3 <= lbl_805604B4) {
            var_f3 = lbl_805604B4;
        }
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
    return 0;
}
#pragma pop
extern int fn_80020434(void*, float*);
extern int fn_8026A2CC(void*, int, float);
extern int fn_8000C630(int, int);
/* Update timed overlay state and, while active, draw it and trigger sound 0x15. */
void fn_800207B0(void) {
    char overlayData[0x30];
    float overlayScale;

    if ((lbl_8055D644 != 0) && (lbl_8055D645 == 0)) {
        fn_802E2C20();
    }
    if ((lbl_8055D644 != 0) && (lbl_8055D645 != 0) && ((fn_801E8838() > 0xF0) || ((fn_802E2C20() - lbl_8055D640) > 0x4B0))) {
        lbl_8055D645 = 0;
        lbl_8055D644 = 0;
    }
    if (lbl_8055D644 != 0) {
        fn_80020434(&overlayData, &overlayScale);
        fn_8026A2CC(&overlayData, 0, overlayScale);
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
extern int fn_802354A0(int, int, s32, f32, f32, f32, f32, f32);
#pragma push
#pragma dont_inline on
void fn_80020860(int arg0) {
    f32 t4;
    f32 t5;

    t4 = lbl_805604F0 * (f32)lbl_8055CFF0 / lbl_805604F4;
    t5 = (f32)lbl_8055CFF4;
    fn_802354A0(lbl_8055D654, 0, (arg0 << 24) | 0xFF0000 | 0xFFFF,
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
int fn_800213DC(int arg0) {
    int r;
    if (lbl_8055D644) {
        if (!lbl_8055D645 && !fn_801E8838() && !fn_802E4A10()) {
            switch (arg0) {
                case 0x58:
                    fn_8001FEB8();
                    break;
                case 0x1B:
                    fn_8002017C();
                    break;
            }
        }
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

void fn_80021464(void *a_, int arg1) {
    KArg *a = (KArg *)a_;
    KArg *p;
    int sp[6];
    int c, n, rk, vhh;
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
    c = a->f8;
    lbl_8055D668 = a->f0;
    lbl_8055D66C = arg1;
    lbl_8055D647 = (c != 0x180302);
    p = fn_8001285C(a->f0);
    fn_80012820(p->f4);
    lbl_8035BAD8.f8 = p->fC;
    vhh = p->obj->vt->f5C(p->obj, fn_80205268(base + 0x2B4, lbl_8055D66C, lbl_8055D668));
    if (vhh != 0) {
        fn_8001D884(sp, vhh);
        rk = fn_8027DED0();
        if (rk == -1) {
            rk = sp[5];
        }
        lbl_8035BAD8.f4 = fn_8001DA48(sp, rk);
    }
    lbl_8035BAD8.f0 = fn_8014E7DC(lbl_8055D668, arg1);
    n = 0;
    for (;;) {
        fn_8001FFD0(n, c, lbl_8035BB18, 0x40);
        if (fn_80131264(lbl_8035BB18) == 0) break;
        n++;
    }
    if (n == 0) n = 1;
    rk = 0;
    do {
        vhh = fn_80129D18(1, n);
        if (vhh != lbl_80558DA4) break;
        rk++;
    } while (rk < 10);
    lbl_80558DA4 = vhh;
    fn_8001FFD0(vhh, c, lbl_8035BB18, 0x40);
    lbl_8055D65C = fn_80131234(lbl_8035BB18);
}

#pragma pop
void fn_8002167C(void) {
    fn_8001FF24();
}

void fn_80021680(void) {
    fn_80020860(0xFF);
    fn_800209A0(0xFF, lbl_805604B4);
    fn_8001FF34(-1);
}

void __AXDSPInitCallback_800216B8(void) { lbl_8055D62C = 2; }

void fn_800216C4(void) {

}

#pragma push
#pragma inline_depth 0
void fn_800216C8(void) {
    fn_8001FF34(-1);
}
extern int lbl_8055D668, lbl_8055D66C;
extern char *lbl_80558D8C;
extern int fn_8000DA10(void);
extern int fn_8001BA90(int, int, int, int, int);
extern void fn_8001BA70(int, int, unsigned char *, int);
#pragma dont_inline on
int fn_800216D0(void) {
    int result = 0;
    if (lbl_8055D644) {
        if (!lbl_8055D645) result = 1;
    }
    return result;
}
unsigned char fn_800216F4(void) {
    return lbl_8055D644;
}

int fn_800216FC(void) {
    if (lbl_8055D644 != 0)
        return fn_80020184() > 0;
    return 0;
}

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
int fn_8002173C(void) {
    extern void fn_80230B38_0(void);
    char sp8[0x38];
    if (lbl_8055D62C != 0) {
        fn_80230B5C(sp8);
        fn_80230AD8(sp8);
        switch (lbl_8055D62C) {
        case 2: fn_800216C8(); break;
        case 1: fn_80021680(); break;
        }
        {
            void (*f)(void) = (void (*)(void))fn_80230B38;
            f();
        }
        return 1;
    }
    return 0;
}
#pragma pop
int fn_800217AC(void) {
    int result;
    if (lbl_8055D648 != 0)
        return 0;
    result = 0;
    if (lbl_8055D644 == 0 || lbl_8055D645 != 0)
        result = 1;
    return result;
}

extern float lbl_80560560, lbl_80560564, lbl_805604B8, lbl_805604B4, lbl_80560568, lbl_80560554, lbl_805604FC;
extern int fn_802E2C20(void);
extern void fn_80020860(int);
void fn_800217E4(void) {
    /* While active, updates a time-based value from elapsed ticks and applies it for up to 1500 ticks. */
    float computedValue;
    float convertedValue;
    float progress;
    int elapsed;
    int amount;

    if (lbl_8055D648 != 0) {
        elapsed = fn_802E2C20() - lbl_8055D63C;
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
    fn_8001FD7C();
}

void fn_800218F8(void) {
    fn_8001FE20();
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

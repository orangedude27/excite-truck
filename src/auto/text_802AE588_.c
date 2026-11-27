#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802B4E44(int);
extern float fn_80203FF0(void);
extern float fn_802C8FEC(void);
extern float fn_802C973C(void);
extern double fn_8002EF30(double);
extern double atan(double);
extern double sin(double);
extern double fabs(double);
extern void *fn_802BE844();
extern void fn_802AFE64(int *, short, short, short, short, int, int, int, float, int);
extern void fn_802AFEA4(int *, short);
extern int fn_802AFEC0(int);
extern int fn_802AFF54(void *);
extern int fn_802AFF5C(int *, int);
extern void fn_802AFF6C(void *);
extern void fn_802AFF80(void *, short);
extern void fn_802B0024(void *, short);
extern unsigned short fn_802B0070(int);
extern void fn_802B009C(void *, int, int, int);
extern void fn_802B0114(void);
extern s32 fn_802B0118(void *);
extern s32 fn_802B0124(void *);
extern s32 fn_802B0130(void *);
extern float fn_801DCF48(int, float, float);
extern void fn_802DBE4C(void);
extern void fn_802BDD58(void);
extern void fn_802DBECC(void);
extern void fn_802B2D94(int);
extern void fn_802B4E30(void);
extern char lbl_8055F980;
extern char lbl_8055F984[4];
extern int lbl_8055F988;
extern float lbl_80564B38;
extern int lbl_804BDFF0[8];
extern int lbl_8055CD7C;
extern int fn_8012850C(int, void *);
extern double fn_8002F234(float, float, float);
extern void *lbl_8055CD78;
extern void fn_80128668(void*);
extern char lbl_8055F981;
extern int lbl_8055F97C;
extern const float lbl_80564AF0;
extern float lbl_80564B6C;
extern float lbl_80564B84;
extern float lbl_80564BB0;
extern float fn_801EA0E8(float, float);
extern unsigned int fn_802BBD38(short, short);
struct ETConfigPaths;
static char lbl_8034A020[] = "swlmap.tex";
static char lbl_8034A02C[] = "water_layer";
static char lbl_8034A038[] = "crystal_mode";
extern float lbl_804BE090[];
extern float lbl_80564B40;
extern float lbl_80564B44;
extern float lbl_80564B68;
extern float lbl_80564B48;
extern float lbl_80564B4C;
extern float lbl_80564B50;
extern float lbl_80564B54;
extern float lbl_80564B58;
extern float lbl_80564B5C;
extern float lbl_80564B60;
extern float lbl_80564B64;
extern float lbl_80564B6C;
extern double lbl_80564B70;
    extern unsigned char fn_8012C33C(void *);
    struct ETConfigPaths;
    struct ETConfigName {
    char text[0xC];
};
struct ETConfigPaths {
    struct ETConfigName name;
    char lookupKey[0xC];
    char statusKey[8];
};
extern void fn_802BE7F8(void);
extern void fn_802B40F8(void);
extern void fn_802B0914(void);
extern void fn_802C26F0(void);
extern void fn_802B1E28(void);
extern void fn_802B57B8(void);
extern void fn_802BBBC8(void);
extern void fn_802C2138(void);
extern void fn_802B9B68(void);
extern void fn_802BDBA8(void);
extern void fn_802C2298(void);
extern void fn_802BF350(void);
extern void fn_802B58E0(void);
extern void *fn_802B59CC(void);
extern void fn_802BEAB0(void);
#pragma cplusplus on
class ETConfigAccess {
public:
    virtual void unused00() = 0;
    virtual void unused04() = 0;
    virtual void unused08() = 0;
    virtual void unused0C() = 0;
    virtual void unused10() = 0;
    virtual void unused14() = 0;
    virtual void *lookup(char *, int) = 0;
    virtual void unused24() = 0;
    virtual void unused28() = 0;
    virtual void unused2C() = 0;
    virtual char status(char *, int) = 0;
};
#pragma cplusplus reset
void* fn_802AE588(void* object, s32 shouldDelete) {
    /* Clears a 3-word object header and frees it when requested (global destructor). */
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

#pragma scheduling invalid_target
void fn_802AE5E0(int arg0) {
    /* Build a bucket offset table and allocate a wave table buffer sized for it. */
    int *offsetPtr = &lbl_804BDFF0[1];
    int totalSize = 0;
    int bucket = 2;
    while (bucket <= arg0) {
        *offsetPtr = totalSize;
        totalSize += (bucket + 1) * 4;
        offsetPtr++;
        bucket *= 2;
    }
    *(int *)lbl_8055F984 = fn_8012850C(totalSize * 2, &lbl_8055CD7C);
}
#pragma scheduling on
extern void fn_802AE64C(void *);
extern void setDrawListColor(int);
extern void setLightAmbientColor(int);
extern void fn_802C10C4(void);
extern char fn_802B05E4(void);
extern void fn_802BF40C(void);
extern void fn_802C2410(void);
extern void fn_802BDC60(void);
extern void fn_802B9D08(void);
extern void fn_802C2A34(void);
extern void fn_802B5808(void);
extern void fn_802C217C(void);
extern void fn_802B1FD4(void);
extern void fn_802C2874(void);
extern void fn_802B0954(void);
extern void fn_802B4BDC(void);
extern void fn_802BBCC4(void);
extern void fn_802BE840(void);
extern void fn_802C10B8(void);
extern int KERNEL_GetTimeMs();
extern void fn_802BEB70(void);
extern int fn_802E30C8(char *, char *, ...);
extern void fn_802AE774(void);
extern int lbl_8055F970;
extern char lbl_8034A048[];
extern char lbl_8034A064[];
/* Release the wave-table workspace buffer: pass fn_802AE64C the address of the
 * global slot lbl_8055F984 that holds the buffer base (allocated by
 * fn_802AE5E0), so it frees the buffer and zeroes the slot.  Called from the
 * subsystem shutdown sequence in fn_802AE9D0. */
void fn_802AE644(void) { fn_802AE64C(lbl_8055F984); }

/* If the object holds a buffer pointer at offset 0, free it and clear the field. */
void fn_802AE64C(void *arg0) {
    void *buffer = *(void **)arg0;
    if (buffer != NULL) {
        fn_80128670(buffer);
        *(void **)arg0 = NULL;
    }
}

/* Classify the sign of obj's Y values (at +0x18, +0x20) and store a quadrant/state code in lbl_8055F988. */
void fn_802AE690(void *obj) {
    float y = *(float *)((char *)obj + 0x18);
    int state;
    if (y * *(float *)((char *)obj + 0x20) > lbl_80564B38) {
        if (y > lbl_80564B38) state = 3;
        else state = 0;
        lbl_8055F988 = state;
        return;
    }
    if (y > lbl_80564B38) state = 1;
    else state = 2;
    lbl_8055F988 = state;
}

#pragma scheduling invalid_target
float fn_802AE6E0(const void *pointA, const void *pointB) {
    /* Return the 2D distance between two points in the XZ plane (sqrt of dx^2 + dz^2). */
#define Sqrt fn_8002F234
    const float *a = (const float *)pointA;
    const float *b = (const float *)pointB;
    float dz = a[2] - b[2];
    float dx = a[0] - b[0];
    float dz2 = dz * dz;
    float dx2 = dx * dx;
    return (float)((double (*)(double))Sqrt)(dx2 + dz2);
#undef Sqrt
}
extern void beginModelBatch(void);
extern float lbl_80564B3C;
extern void fn_802C9648(float);
extern void fn_80287A34(int);
extern void DrawList_reapplyProjection(void);
extern void fn_802879E4(int);
extern void fn_801FA6B8(void);
extern void submitModelBatch(void);
extern void fn_802C9904(void);
extern void fn_801FA738(void);
void fn_802AE728(void) {
    /* Apply post-race/reset UI/view state: enable drawlist, scale camera by 1.1
       (lbl_80564B3C), toggle HUD/input modes, and run finalizers. */
    beginModelBatch();
    fn_802C9648(lbl_80564B3C);
    fn_80287A34(0);
    DrawList_reapplyProjection();
    fn_802879E4(0);
    fn_801FA6B8();
    submitModelBatch();
    fn_802C9904();
    fn_801FA738();
}

#pragma scheduling on
void fn_802BA004(void);
void fn_802BA348(void);
void fn_802C29A0(void);
void fn_802BAE50(void);
#pragma scheduling invalid_target
/* World-grid startup: reset the state flag (fn_802BA004), build the fallback
 * grid-entry list when the "swlmap.tex" present flag (fn_802B05E4) is clear,
 * then finish node accounting (fn_802C29A0) and build/sort the water list
 * (fn_802BAE50). */
void fn_802AE774(void) {
    fn_802BA004();
    if (((int (*)(void))fn_802B05E4)() == 0) {
        fn_802BA348();
    }
    fn_802C29A0();
    fn_802BAE50();
}
#pragma scheduling on
/* Nonzero when the wave-table workspace buffer has been allocated
   (lbl_8055F984 holds its base pointer). */
int fn_802AE7AC(void) {
    return *(int *)lbl_8055F984 != 0;
}
  #pragma dont_inline reset
  
void fn_802AE7C0(void) {
    /* Set the two packed RGB colors in the GX draw state: a muted blue-gray (0x555766) and a cream white (0xFFF5D9). */
    setDrawListColor(0x555766);
    setLightAmbientColor(0xFFF5D9);
}
  
#pragma dont_inline on
#pragma cplusplus on
#pragma push
#pragma processor 750
/* Default start-up of the world grid / water subsystems, used when the 'FRAG'
 * resource is missing (see loadEBResource).  It remembers whether the "swlmap.tex"
 * texture is in the archive (lbl_8055F980, read back by fn_802B05E4), builds the
 * grid pyramid's per-level offsets and allocates its buffer (fn_802AE5E0),
 * starts the subsystems, then takes the "water_layer" handle from the game
 * config (lbl_8055CD78, -1 when there is none) and the "crystal_mode" flag
 * (lbl_8055F981).  Last it lays out lbl_804BE090[1..7]: the running sum of the
 * eight tile footings below, i.e. where each level starts in the tile list.
 * The lbl_80564B40..lbl_80564B6C globals are the .sdata2 copies of the
 * literals 10, 2, 4, 8, 16, 32, 3, 64, 128, 256, sqrt(2) and 0.5;
 * lbl_80564AF0 is 2.0f, the world units per grid cell. */
/* Default start-up of the world-grid/water subsystems when the FRAG resource is missing: record whether swlmap.tex is present, build/allocate the grid pyramid, start each subsystem, read the water_layer and crystal_mode config values, lay out the seven level start offsets, then finish initialization. */ extern "C" void initWorldGridWaterFallback(void) {
    float footing[8];
    float start;
    int i;
    lbl_8055F980 = fn_8012C33C(lbl_8034A020); /* "swlmap.tex" present? */
    fn_802AE5E0(0x400); /* grid pyramid over the 1024-unit world */
    fn_802BE7F8();
    fn_802B40F8();
    fn_802B0914();
    fn_802C26F0();
    fn_802B1E28();
    fn_802B57B8();
    fn_802BBBC8();
    fn_802C2138();
    fn_802B9B68();
    fn_802BDBA8();
    fn_802C2298();
    if ((unsigned char)lbl_8055F980 == 0)
        fn_802BF350(); /* no swlmap texture: fall back */
    fn_802B58E0();
    {
        ETConfigAccess *config = (ETConfigAccess *)fn_802B59CC();
        lbl_8055CD78 = config->lookup(lbl_8034A02C, -1); /* "water_layer" */
    }
    {
        ETConfigAccess *config = (ETConfigAccess *)fn_802B59CC();
        lbl_8055F981 = config->status(lbl_8034A038, 0); /* "crystal_mode" */
    }
    footing[0] = lbl_80564B40 * (lbl_80564B44 * lbl_80564AF0);
    start = footing[0];
    footing[1] = lbl_80564B48 * (lbl_80564B48 * lbl_80564AF0);
    footing[2] = lbl_80564B48 * (lbl_80564B4C * lbl_80564AF0);
    footing[3] = lbl_80564B40 * (lbl_80564B50 * lbl_80564AF0);
    footing[4] = lbl_80564B48 * (lbl_80564B54 * lbl_80564AF0);
    footing[5] = lbl_80564B58 * (lbl_80564B5C * lbl_80564AF0);
    footing[6] = lbl_80564B44 * (lbl_80564B60 * lbl_80564AF0);
    footing[7] = lbl_80564B64 * lbl_80564AF0;
    {
        int tile = 2;
        float *slot = &lbl_804BE090[1];
        float *next = &footing[1];
        for (i = 0; i < 7; i++) {
            float size = *next;
            float diagonal = (lbl_80564B68 * (lbl_80564B6C * lbl_80564AF0)) * (float)((tile << 1) + tile);
            *slot = start;
            start += (diagonal > size) ? diagonal : size;
            tile *= 2;
            slot++;
            next++;
        }
    }
    fn_802BEAB0();
    lbl_8055F97C = 0xFA;
}
#pragma pop
#pragma cplusplus reset

#pragma scheduling invalid_target
/* Run the shutdown/cleanup sequence for the UI/view subsystems and clear their global state. */
void fn_802AE9D0(void) {
    lbl_8055CD78 = (void *)-1;
    fn_802C10C4();
    if (((int (*)(void))fn_802B05E4)() == 0)
        fn_802BF40C();
    fn_802C2410();
    fn_802BDC60();
    fn_802B9D08();
    fn_802C2A34();
    fn_802B5808();
    fn_802C217C();
    fn_802B1FD4();
    fn_802C2874();
    fn_802B0954();
    fn_802B4BDC();
    fn_802BBCC4();
    fn_802BE840();
    ((void (*)(void))fn_802AE644)();
    lbl_8055F970 = 0;
}
#pragma scheduling invalid_target
void fn_802AEA44(void) {
    /* Reset fan-info draw state, refresh visibility masks, and log if it takes too long. */
    volatile int startTime;
    char *volatile name;
    int elapsedMs;

    fn_802C10B8();
    startTime = KERNEL_GetTimeMs(name = lbl_8034A048);
    fn_802BEB70();
    elapsedMs = KERNEL_GetTimeMs() - startTime;
    if (elapsedMs > 0x1F4)
        fn_802E30C8(lbl_8034A064, name, elapsedMs);
    fn_802AE774();
}
#pragma scheduling on
extern void fn_802BDC3C(void);
extern void fn_802B59A4(int);
extern void fn_802B0288();
extern void fn_802BB674(int, int);
extern void fn_802C10CC(int);
extern int lbl_8055F974;
extern int lbl_8055F978;
/* Tail-call wrapper for fn_802BDC3C: runs the EB ("Simple Model") resource
 * fallback used by fn_801EC11C when the resource context was never loaded,
 * loading the "TLST" data and building the per-entry state. */
void fn_802AEAA8(void) { fn_802BDC3C(); }

#pragma dont_inline fn_802AEAAC
/* Initialize or refresh global UI/view state from the config object at lbl_8055F970 and dispatch per-slot and final setup calls. */
void fn_802AEAAC(void) {
    int offset;
    int i;
    if (lbl_8055F970 == 0) {
        fn_802B59A4(0);
        fn_802B0288();
    }
    i = 0;
    offset = 0;
    lbl_8055F974 = *(int *)(lbl_8055F970 + 4);
    lbl_8055F978 = *(int *)(lbl_8055F970 + 8);
    while (i < 4) {
        fn_802BB674(*(int *)((char *)lbl_8055F970 + offset + 0xC), i);
        i++;
        offset += 8;
    }
    fn_802C10CC(*(int *)(lbl_8055F970 + 0x2C));
}

extern char lbl_804BD8E8[];
extern float lbl_8055F98C;
extern u16 lbl_80564AF8;
extern u16 lbl_80564AFA;
extern u16 lbl_80564AFC;
extern u16 lbl_80564AFE;
extern u16 lbl_80564B00;
extern u16 lbl_80564B02;
extern u16 lbl_80564B04;
extern u16 lbl_80564B06;
extern u16 lbl_80564B08;
extern u16 lbl_80564B0A;
extern u16 lbl_80564B0C;
extern u16 lbl_80564B0E;
extern u16 lbl_80564B10;
extern u16 lbl_80564B12;
extern u16 lbl_80564B14;
extern u16 lbl_80564B16;
extern u16 lbl_80564B18;
extern u16 lbl_80564B1A;
extern u16 lbl_80564B1C;
extern u16 lbl_80564B1E;
extern u16 lbl_80564B20;
extern u16 lbl_80564B22;
extern u16 lbl_80564B24;
extern u16 lbl_80564B26;
extern u16 lbl_80564B28;
extern u16 lbl_80564B2A;
extern u16 lbl_80564B2C;
extern u16 lbl_80564B2E;
extern u16 lbl_80564B30;
extern u16 lbl_80564B32;
extern u16 lbl_80564B34;
extern u16 lbl_80564B36;
extern float lbl_80564B44;
extern float lbl_80564B68;
extern float lbl_80564B78;
extern float lbl_80564B7C;
extern float lbl_80564B80;
extern float lbl_80564B88;
extern float lbl_80564B8C;
extern float lbl_80564B90;
extern float lbl_80564B94;
extern float lbl_80564B98;
extern float lbl_80564B9C;
extern float lbl_80564BA0;
#pragma scheduling on
#pragma dont_inline on
void fn_802AEB3C(volatile u8 *arg0) {
    s16 sp148;
    u8 *sp144;
    u8 *sp140;
    s32 sp120;
    s32 sp114;
    s32 sp108;
    s32 spFC;
    s32 spF0;
    u16 *spEC;
    u16 *spE8;
    u16 *spE4;
    u16 *spE0;
    f32 spDC;
    s16 spDA;
    s16 spD8;
    s16 spD6;
    s16 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    s32 spB0;
    s32 spA4;
    s32 sp98;
    s32 sp8C;
    s32 sp80;
    s32 sp74;
    s32 sp68;
    u16 sp66;
    u16 sp64;
    u16 sp62;
    u16 sp60;
    u16 sp5E;
    u16 sp5C;
    u16 sp5A;
    u16 sp58;
    u16 sp56;
    u16 sp54;
    u16 sp52;
    u16 sp50;
    u16 sp4E;
    u16 sp4C;
    u16 sp4A;
    u16 sp48;
    u16 sp46;
    u16 sp44;
    u16 sp42;
    u16 sp40;
    u16 sp3E;
    u16 sp3C;
    u16 sp3A;
    u16 sp38;
    u16 sp36;
    u16 sp34;
    u16 sp32;
    u16 sp30;
    u16 sp2E;
    u16 sp2C;
    u16 sp2A;
    u16 sp28;
    s32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    s32 sp10;
    u16 *sp8;
    s32 *var_r20;
    s32 *var_r21;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f18;
    f32 temp_f18_2;
    f32 temp_f19;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f31;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f4;
    s32 temp_r4;
    s32 temp_r5;
    f32 var_f0;
    register f32 var_f17;
    f32 var_f17_2;
    register f32 var_f18;
    f32 var_f18_2;
    f32 var_f1;
    s16 temp_r0_2;
    s16 temp_r10_2;
    s16 temp_r14_10;
    s16 temp_r14_3;
    s16 temp_r14_5;
    s16 temp_r14_7;
    s16 temp_r14_8;
    s16 temp_r14_9;
    s16 temp_r21;
    s16 temp_r21_2;
    s16 temp_r21_3;
    s16 temp_r22;
    s16 temp_r22_2;
    s16 temp_r23;
    s16 temp_r24;
    s16 temp_r25;
    s16 temp_r25_2;
    s16 temp_r25_3;
    s16 temp_r27;
    s16 temp_r27_2;
    s16 temp_r30;
    s16 temp_r3_6;
    s16 temp_r3_7;
    s16 temp_r4_10;
    s16 temp_r4_5;
    s16 temp_r4_6;
    s16 temp_r4_7;
    s16 temp_r4_8;
    s16 temp_r4_9;
    s16 temp_r5_4;
    s16 temp_r5_5;
    s16 temp_r5_6;
    s16 temp_r6_4;
    s16 temp_r7_3;
    s16 temp_r7_4;
    s16 temp_r8_2;
    s16 temp_r9_2;
    s16 var_r0_4;
    s16 var_r14;
    s32 temp_r0;
    s32 temp_r10;
    s32 input0;
    s32 input4;
    s32 input8;
    s32 inputC;
    s32 input2C;
    s32 temp_r14_2;
    s32 temp_r14_4;
    s32 temp_r14_6;
    s32 temp_r15;
    s32 temp_r16;
    s32 temp_r31;
    s32 temp_r3_4;
    s32 temp_r3_8;
    s32 temp_r4_14;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r5_2;
    s32 temp_r5_8;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r6_6;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r9;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r15_3;
    s32 var_r25_2;
    s32 var_r27;
    s32 var_r28;
    u16 *temp_r16_2;
    u16 *temp_r17_2;
    u16 *temp_r18;
    u16 *temp_r19;
    u16 *temp_r3_12;
    u16 *temp_r4_13;
    u16 *temp_r5_7;
    u16 *temp_r6_5;
    u16 *temp_r7_5;
    u16 *var_r15;
    u16 *var_r15_2;
    u16 *var_r16;
    u16 *var_r17;
    u16 *var_r18;
    u16 *var_r19;
    u16 *var_r22;
    u16 *var_r23;
    u16 *var_r24;
    u16 *var_r25;
    u16 temp_r4_11;
    u16 temp_r4_12;
    u16 var_r0_5;
    u16 var_r0_6;
    u16 var_r4;
    register u8 *temp_r14;
    u8 *temp_r17;
    register u8 *temp_r26;
    u8 *temp_r3;
    u8 *temp_r3_10;
    u8 *temp_r3_11;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_5;
    u8 *temp_r3_9;
    u8 *temp_r4_4;
    u8 *temp_r5_3;
    u8 *temp_r6_3;
    u8 *temp_r7_2;

    u8 *workspace = (u8 *)lbl_804BD8E8;
    fn_802AEAAC();
    fn_802B11BC(lbl_8055F974);
    fn_802B2D24(lbl_8055F978);
    temp_r14 = workspace + 0x7C8;
    input0 = *(volatile s32 *)arg0;
    input4 = *(volatile s32 *)((volatile u8 *)arg0 + 4);
    input8 = *(volatile s32 *)((volatile u8 *)arg0 + 8);
    inputC = *(volatile s32 *)((volatile u8 *)arg0 + 0xC);
    input2C = *(volatile s32 *)((volatile u8 *)arg0 + 0x2C);
    temp_r10 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x10));
    temp_r9 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x14));
    temp_r8 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x18));
    temp_r7 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x1C));
    temp_r6 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x20));
    temp_r5 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x24));
    temp_r4 = *(volatile s32 *)((volatile u8 *)(arg0) + (0x28));
    *(volatile s32 *)((u8 *)(workspace) + (0x7C8)) = input0;
    *(volatile s32 *)((u8 *)(temp_r14) + (4)) = input4;
    *(volatile s32 *)((u8 *)(temp_r14) + (8)) = input8;
    *(volatile s32 *)((u8 *)(temp_r14) + (0xC)) = inputC;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x10)) = temp_r10;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x14)) = temp_r9;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x18)) = temp_r8;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x1C)) = temp_r7;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x20)) = temp_r6;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x24)) = temp_r5;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x28)) = temp_r4;
    *(volatile s32 *)((u8 *)(temp_r14) + (0x2C)) = input2C;
    fn_802AE690(temp_r14);
    var_f17 = lbl_80564B38;
    temp_f0 = (lbl_80564B78 + *(f32 *)((u8 *)(temp_r14) + (0x28))) - fn_801EA0E8(*(f32 *)((u8 *)(temp_r14) + (0x24)), *(f32 *)((u8 *)(temp_r14) + (0x2C)));
    if (var_f17 <= temp_f0) {
        var_f17 = temp_f0;
    }
    lbl_8055F98C = fn_80203FF0() + var_f17;
    temp_f18 = fn_802C8FEC();
    temp_f1 = fn_802C973C();
    temp_f2 = (f32) atan((f32) fn_8002EF30(temp_f1 * lbl_80564B6C) / temp_f18);
    temp_f18_2 = lbl_80564B44 * temp_f2;
    temp_f3 = (f32) fn_8002EF30(temp_f1 * lbl_80564B6C);
    temp_r3 = workspace + 0x7C8;
    *(f32 *)((u8 *)(temp_r3) + (0x30)) = temp_f3;
    temp_r3_2 = workspace + 0x7C8;
    temp_f2_2 = lbl_80564B80 / (f32) sin(lbl_80564B7C - (temp_f1 * lbl_80564B6C));
    *(f32 *)((u8 *)(temp_r3_2) + (0x34)) = temp_f2_2;
    temp_f3_2 = (f32) fn_8002EF30(temp_f18_2 * lbl_80564B6C);
    temp_r3_3 = workspace + 0x7C8;
    *(f32 *)((u8 *)(temp_r3_3) + (0x38)) = temp_f3_2;
    temp_f1_2 = (f32) sin(lbl_80564B7C - (temp_f18_2 * lbl_80564B6C));
    temp_r7_2 = workspace + 0x7C8;
    *(f32 *)((u8 *)(temp_r7_2) + (0x3C)) = (f32) (lbl_80564B80 / temp_f1_2);
    DrawList_getViewParams(&sp1C, workspace + 0x7C8 + 0x40, workspace + 0x7C8 + 0x44, &sp1C, temp_r7_2, temp_f1_2);
    sp18 = lbl_80564B84;
    temp_r6_2 = (*(u32 *)&(sp18) >> 0x17U) & 0x7F;
    temp_r14_2 = *(s32 *)lbl_8055F984 + (*(s32 *)(workspace + 0x708 + ((temp_r6_2 + 1) * 4)) * 2);
    memset((u8 *)temp_r14_2, -1, 0x2008);
    temp_f22 = lbl_80564B80;
    temp_r3_4 = *(s32 *)((u8 *)(workspace) + (0)) * 0x1C;
    temp_f27 = lbl_80564B38;
    temp_f31 = lbl_80564AF0;
    *(s32 *)((u8 *)(workspace) + (0)) = (s32) (*(s32 *)((u8 *)(workspace) + (0)) + 1);
    temp_r6_3 = workspace + temp_r3_4;
    *(s16 *)((u8 *)(temp_r6_3) + (4)) = 0;
    temp_f24 = lbl_80564B8C;
    *(s16 *)((u8 *)(temp_r6_3) + (6)) = 0;
    temp_f25 = lbl_80564B90;
    *(s16 *)((u8 *)(temp_r6_3) + (8)) = 0x400;
    temp_f19 = lbl_80564B94;
    *(s16 *)((u8 *)(temp_r6_3) + (0xA)) = 0;
    temp_f20 = lbl_80564B98;
    *(f32 *)((u8 *)(temp_r6_3) + (0xC)) = temp_f22;
    temp_f28 = lbl_80564B6C;
    *(s32 *)((u8 *)(temp_r6_3) + (0x10)) = temp_r14_2;
    temp_f29 = lbl_80564B68;
    *(s32 *)((u8 *)(temp_r6_3) + (0x14)) = (s32) (temp_r14_2 + 0x802);
    *(s32 *)((u8 *)(temp_r6_3) + (0x18)) = (s32) (temp_r14_2 + 0x1806);
    sp140 = NULL;
    *(s32 *)((u8 *)(temp_r6_3) + (0x1C)) = (s32) (temp_r14_2 + 0x1004);
    do {
        temp_r0 = *(s32 *)((u8 *)(workspace) + (0)) - 1;
        *(s32 *)((u8 *)(workspace) + (0)) = temp_r0;
        temp_r3_5 = workspace + (temp_r0 * 0x1C);
        temp_r26 = temp_r3_5 + 4;
        temp_r3_6 = *(s16 *)((u8 *)(temp_r3_5) + (8));
        if (temp_r3_6 >= 0) {
            temp_r5_2 = (s32) (((u32) temp_r3_6 >> 0x1FU) + temp_r3_6) >> 1;
            if ((temp_r5_2 >= 4) && (temp_r5_2 <= 0x40)) {
                sp140 = fn_802BE844(*(s16 *)((u8 *)temp_r3_5 + 4), *(s16 *)((u8 *)temp_r26 + 2));
            }
            temp_r3_7 = *(s16 *)((u8 *)(temp_r26) + (4));
            var_f17_2 = lbl_80564B38;
            temp_r4_2 = ((u32) temp_r3_7 >> 0x1FU) + temp_r3_7;
            temp_r3_8 = temp_r4_2 >> 1;
            if (temp_r3_8 > 0x40) {
                temp_f1_3 = (f32) *(s16 *)((u8 *)(temp_r3_5) + (4)) * temp_f31;
                temp_f2_3 = (f32) *(s16 *)((u8 *)(temp_r26) + (2)) * temp_f31;
                spC8 = temp_f1_3;
                spD0 = temp_f2_3;
                spCC = fn_801DCF48(0, temp_f1_3, temp_f2_3);
                var_f18 = lbl_80564B88;
            } else {
                temp_r4_3 = temp_r4_2 >> 1;
                spC8 = (f32) *(s16 *)((u8 *)(temp_r3_5) + (4)) * temp_f31;
                spD0 = (f32) *(s16 *)((u8 *)(temp_r26) + (2)) * temp_f31;
                spCC = temp_f24 + (f32) (((u32) *(u32 *)((u8 *)(sp140) + (8)) >> 0xEU) & 0x1FF);
                var_f18 = (f32) ((((u32) *(u32 *)((u8 *)(sp140) + (8)) >> 0xAU) & 0xF) + 1) * temp_f25;
                if (temp_r4_3 < 4) {
                    var_f18 *= (f32) (4 / temp_r4_3);
                }
            }
            temp_r4_4 = workspace + 0x7C8;
            temp_r5_3 = workspace + 0x7C8;
            temp_f4 = spC8 - *(f32 *)((u8 *)(temp_r4_4) + (0x24));
            temp_f2_4 = spCC - *(f32 *)((u8 *)(temp_r5_3) + (0x28));
            spBC = temp_f4;
            spC0 = temp_f2_4;
            spC4 = spD0 - *(f32 *)((u8 *)(temp_r5_3) + (0x2C));
            temp_f1_4 = PSVECDotProduct(&spBC, temp_r4_4 + 0x18, temp_r5_3, spD0, temp_f2_4, spCC, temp_f4);
            temp_f3_3 = temp_f31 * (f32) temp_r3_8 * var_f18;
            temp_r3_9 = workspace + 0x7C8;
            if (((temp_f1_4 + temp_f3_3) < *(f32 *)((u8 *)(temp_r3_9) + (0x40))) || ((temp_f1_4 - temp_f3_3) > *(f32 *)((u8 *)(temp_r3_9) + (0x44)))) {
                var_r0 = 0;
            } else {
                temp_f2_5 = (f32) fabs(PSVECDotProduct(&spBC, temp_r3_9));
                temp_f3 = temp_f1_4 * *(f32 *)((u8 *)((workspace + 0x7C8)) + (0x30));
                if (temp_f27 > temp_f3) temp_f3 = temp_f27;
                temp_f0 = temp_f3 + ((temp_f20 + temp_f21 * var_f18) * *(f32 *)((u8 *)((workspace + 0x7C8)) + (0x34)));
                var_r0 = (temp_f2_5 <= temp_f0);
                if (var_r0 != 0) {
                    temp_f2_6 = (f32) fabs(PSVECDotProduct(&spBC, workspace + 0x7C8 + 0xC));
                    temp_f3 = temp_f1_4 * *(f32 *)((u8 *)((workspace + 0x7C8)) + (0x38));
                    if (temp_f27 > temp_f3) temp_f3 = temp_f27;
                    temp_f0 = temp_f3 + ((temp_f19 + temp_f21 * var_f18) * *(f32 *)((u8 *)((workspace + 0x7C8)) + (0x3C)));
                    var_r0 = (temp_f2_6 <= temp_f0);
                    if (var_r0 != 0) {
                        var_f17_2 = fn_802AE6E0(&spC8, workspace + 0x7C8 + 0x24);
                        var_r0 = 1;
                    } else {
                        goto block_22;
                    }
                } else {
block_22:
                    var_r0 = 0;
                }
            }
            if (var_r0 != 0) {
                temp_r4_5 = *(s16 *)((u8 *)(temp_r26) + (4));
                var_f18_2 = lbl_80564B9C;
                if (temp_r4_5 > 0x80) {
                    var_f18_2 = lbl_80564B80;
                    var_r0_2 = 0;
                } else {
                    var_f1 = lbl_8055F98C + (var_f17_2 - (temp_f29 * ((f32) temp_r4_5 * temp_f31 * temp_f28)));
                    if (temp_f27 > var_f1) {
                        var_f1 = temp_f27;
                    }
                    if (temp_r4_5 >= 2) {
                        sp14 = (f32) temp_r4_5;
                        var_r0_3 = ((*(u32 *)&(sp14) >> 0x17U) & 0x7F) + 1;
                    } else {
                        var_r0_3 = 0;
                    }
                    temp_r3_10 = workspace + 0x7A8 + (var_r0_3 * 4);
                    temp_f0_2 = *(f32 *)((u8 *)(temp_r3_10) + (-4));
                    var_r0_3 = (var_f1 >= temp_f0_2);
                    if (var_r0_3 == 0) {
                        var_f0 = (var_f1 - temp_f0_2) / (*(f32 *)((u8 *)(temp_r3_10) + (-8)) - temp_f0_2);
                        if (temp_f22 < var_f0) {
                            var_f0 = temp_f22;
                            if (var_f0 > temp_f27) {
                            } else {
                                var_f0 = temp_f27;
                            }
                            var_f18_2 = temp_f27 + (var_f0 * temp_f22);
                        }
                    }
                }
                if (var_r0_2 != 0) {
                    if (fn_802B12E0(lbl_8055F974, &sp20, sp140, fn_802B0130(temp_r26)) != 0) {
                        sp28 = lbl_80564AF8;
                        sp2A = lbl_80564AFA;
                        sp2C = lbl_80564AFC;
                        sp2E = lbl_80564AFE;
                        sp30 = lbl_80564B00;
                        sp32 = lbl_80564B02;
                        sp34 = lbl_80564B04;
                        sp36 = lbl_80564B06;
                        sp38 = lbl_80564B08;
                        sp3A = lbl_80564B0A;
                        sp3C = lbl_80564B0C;
                        sp3E = lbl_80564B0E;
                        sp40 = lbl_80564B10;
                        sp42 = lbl_80564B12;
                        sp44 = lbl_80564B14;
                        sp46 = lbl_80564B16;
                        sp48 = lbl_80564B18;
                        sp4A = lbl_80564B1A;
                        sp4C = lbl_80564B1C;
                        sp4E = lbl_80564B1E;
                        sp50 = lbl_80564B20;
                        sp52 = lbl_80564B22;
                        sp54 = lbl_80564B24;
                        sp56 = lbl_80564B26;
                        temp_r30 = fn_802B0130(temp_r26);
                        if (fn_802B0130(temp_r26) >= 4) {
                            fn_802BDFBC(sp140, fn_802B0130(temp_r26), *(f32 *)((u8 *)(temp_r26) + (8)));
                        }
                        sp10 = 0;
                        var_r27 = 0;
                        if (fn_802B0124(sp140) == 0) {
                            temp_r4_6 = *(s16 *)((u8 *)(temp_r3_5) + (4)) - temp_r30;
                            temp_r14_3 = *(s16 *)((u8 *)(temp_r26) + (2)) - temp_r30;
                            var_r27 = fn_802B4F10(&sp10, temp_r4_6, temp_r14_3, (s16) (temp_r30 * 2), fn_802B0118(sp140));
                        }
                        temp_f21 = fn_8014C8B4(lbl_80564B38, lbl_80564BA0, lbl_80564B38, lbl_80564B80, *(f32 *)((u8 *)(temp_r26) + (8)));
                        fn_802B0114();
                        fn_802B0114();
                        fn_802B0114();
                        fn_802B0114();
                        fn_802B0114();
                        temp_r14_4 = (s32) &sp120 & ((s32) (-var_r27 | var_r27) >> 0x1F);
                        fn_8001BA68(&sp68);
                        fn_802B009C(&sp68, 0, (int)*(s16 *)((u8 *)(temp_r3_5) + 4), (int)*(s16 *)((u8 *)(temp_r26) + 2));
                        if (temp_r14_4 != 0) {
                            fn_80144DAC(temp_r14_4, &sp68);
                        }
                        if (temp_f22 != temp_f21) {
                            fn_8001BA68(&sp74);
                            temp_r4_7 = *(s16 *)((u8 *)(temp_r26) + (6));
                            if (temp_r4_7 < 2) {
                                var_r0_4 = 0;
                            } else {
                                var_r0_4 = *(s16 *)((u8 *)(temp_r26) + (4));
                            }
                            if ((u16) *(u16 *)((u8 *)(*(s32 *)((u8 *)(temp_r26 + (temp_r4_7 * 4)) + 0xC)) + ((var_r0_4 * 2) & 0x1FFFE)) > -3U) {
                                sp58 = lbl_80564B28;
                                sp5A = lbl_80564B2A;
                                sp5C = lbl_80564B2C;
                                sp5E = lbl_80564B2E;
                                sp60 = lbl_80564B30;
                                sp62 = lbl_80564B32;
                                sp64 = lbl_80564B34;
                                sp66 = lbl_80564B36;
                                temp_r4_8 = *(s16 *)((u8 *)(temp_r26) + (6));
                                temp_r4_9 = (s16) (&sp58)[temp_r4_8];
                                temp_r14_5 = *(s16 *)((u8 *)(temp_r3_5) + (4)) + (temp_r4_9 * fn_802B0130(temp_r26));
                                temp_r6_4 = *(s16 *)((u8 *)(temp_r26) + (6));
                                fn_802B009C(&sp74, 0, temp_r14_5, (s16) (*(s16 *)((u8 *)(temp_r26) + (2)) + ((s16) (&sp60)[temp_r6_4] * fn_802B0130(temp_r26))));
                            } else {
                                fn_802B1BF0(lbl_8055F974, &sp74);
                            }
                            fn_8025AD3C(&sp80, &sp74, &sp68, temp_f21);
                            var_r0_5 = fn_802B0070((int)&sp80);
                        } else {
                            var_r0_5 = fn_802B0070((int)&sp68);
                        }
                        fn_802B0024(&sp20, var_r0_5);
                        var_r21 = &spF0;
                        sp144 = temp_r26;
                        var_r20 = var_r21;
                        var_r4 = **(u16 **)((u8 *)(temp_r26) + (0x18));
                        var_r23 = &sp30;
                        var_r22 = &sp28;
                        var_r19 = &sp38;
                        var_r18 = &sp40;
                        var_r17 = &sp50;
                        var_r16 = &sp48;
                        var_r28 = 0;
                        do {
                            var_r15 = *(u16 **)((u8 *)(sp144) + (0xC));
                            if (var_r28 < 2) {
                                var_r25 = var_r15;
                            } else {
                                var_r25 = var_r15 + (*(s16 *)((u8 *)(temp_r26) + (4)) * 2);
                            }
                            if (var_r28 >= 2) {
                                var_r24 = var_r15;
                            } else {
                                var_r24 = var_r15 + (*(s16 *)((u8 *)(temp_r26) + (4)) * 2);
                            }
                            temp_r5_4 = *(s16 *)((u8 *)(temp_r26) + (4));
                            temp_r31 = (((u32) temp_r5_4 >> 0x1FU) + temp_r5_4) & 0xFFFFFFFE;
                            if ((u16) *var_r25 == -1U) {
                                if (var_r4 < -3U) {
                                    *var_r25 = var_r4;
                                } else {
                                    temp_r5_5 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                                    *var_r25 = fn_802AFFA8((s16) (temp_r5_5 + (temp_r30 * (s16) *var_r22)), (s16) (*(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r23)), temp_r5_5);
                                }
                            }
                            if (var_r27 != 0) {
                                if ((u16) *var_r25 == -2U) {
                                    var_r27 = 0;
                                } else {
                                    fn_802B1BF0(lbl_8055F974, var_r21);
                                    temp_r7_3 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                                    temp_f1_5 = temp_f31 * (f32) (temp_r7_3 + (temp_r30 * (s16) *var_r22));
                                    *(f32 *)((u8 *)(var_r21) + (0)) = temp_f1_5;
                                    *(f32 *)((u8 *)(var_r21) + (8)) = (f32) (temp_f31 * (f32) (*(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r23)));
                                    fn_801C0E60(var_r21, var_r20, &sp120, temp_r30, temp_r7_3, temp_f1_5);
                                }
                            }
                            if ((u16) *(var_r15 + temp_r31) == -1U) {
                                temp_r0_2 = *(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r18);
                                temp_r4_10 = *(s16 *)((u8 *)(temp_r3_5) + (4)) + (temp_r30 * (s16) *var_r19);
                                sp148 = temp_r0_2;
                                if (temp_f22 == temp_f21) {
                                    *(var_r15 + temp_r31) = fn_802AFFA8(temp_r4_10, temp_r0_2);
                                } else {
                                    fn_8001BA68(&sp8C);
                                    if ((u16) *var_r25 > -3U) {
                                        fn_802B1BF0(lbl_8055F974, &sp8C);
                                    } else {
                                        temp_r7_4 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                                        fn_802B009C(&sp8C, 0, (s16) (temp_r7_4 + (temp_r30 * (s16) *var_r22)), (s16) (*(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r23)));
                                    }
                                    fn_8001BA68(&sp98);
                                    fn_802B009C(&sp98, 0, temp_r4_10, sp148);
                                    fn_8025AD3C(&spA4, &sp8C, &sp98, temp_f21);
                                    *(var_r15 + temp_r31) = fn_802B0070((int)&spA4);
                                }
                            }
                            if ((u16) *var_r24 == -1U) {
                                var_r0_6 = 0;
                                switch (var_r28) {  /* switch 1; irregular */
                                case 0:             /* switch 1 */
                                    var_r0_6 = **(u16 **)((u8 *)(temp_r26) + (0x10));
                                    break;
                                case 1:             /* switch 1 */
                                    var_r0_6 = *(*(u16 **)((u8 *)(temp_r26) + (0x14)) + (*(s16 *)((u8 *)(temp_r26) + (4)) * 2));
                                    break;
                                case 2:             /* switch 1 */
                                    var_r0_6 = *(*(u16 **)((u8 *)(temp_r26) + (0x18)) + (*(s16 *)((u8 *)(temp_r26) + (4)) * 2));
                                    break;
                                case 3:             /* switch 1 */
                                    var_r0_6 = **(u16 **)((u8 *)(temp_r26) + (0xC));
                                    break;
                                }
                                if (var_r0_6 < -3U) {
                                    *var_r24 = var_r0_6;
                                } else {
                                    temp_r5_6 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                                    *var_r24 = fn_802AFFA8((s16) (temp_r5_6 + (temp_r30 * (s16) *var_r16)), (s16) (*(s16 *)((u8 *)(temp_r26) + (2)) + (temp_r30 * (s16) *var_r17)), temp_r5_6);
                                }
                            }
                            if (var_r28 < 2) {
                                var_r25_2 = 0;
loop_99:
                                if (var_r25_2 < (s16) *(s16 *)((u8 *)(temp_r26) + (4))) {
                                    temp_r4_11 = *var_r15;
                                    if (temp_r4_11 == -1U) {
                                        *var_r15 = 0xFFFE;
                                    } else if (temp_r4_11 != -2U) {
                                        fn_802AFF80(&sp20, (short)temp_r4_11);
                                    }
                                    var_r15 += 2;
                                    var_r25_2 += 1;
                                    goto loop_99;
                                }
                            } else {
                                var_r14 = *(s16 *)((u8 *)(temp_r26) + (4));
                                var_r15_2 = var_r15 + (var_r14 * 2);
loop_107:
                                if (var_r14 > 0) {
                                    temp_r4_12 = *var_r15_2;
                                    if (temp_r4_12 == -1U) {
                                        *var_r15_2 = 0xFFFE;
                                    } else if (temp_r4_12 != -2U) {
                                        fn_802AFF80(&sp20, (short)temp_r4_12);
                                    }
                                    var_r15_2 -= 2;
                                    var_r14 -= 1;
                                    goto loop_107;
                                }
                            }
                            var_r28 += 1;
                            var_r4 = *var_r24;
                            sp144 += 4;
                            var_r23 += 2;
                            var_r22 += 2;
                            var_r21 += 0xC;
                            var_r20 += 0xC;
                            var_r19 += 2;
                            var_r18 += 2;
                            var_r17 += 2;
                            var_r16 += 2;
                        } while (var_r28 < 4);
                        fn_802AFF80(&sp20, 0);
                        fn_802AFF6C(&sp20);
                        fn_802B13F8(lbl_8055F974, sp140, &sp20, fn_802B0130(temp_r26), temp_f21);
                        if ((var_r27 != 0) && ((fn_802B0130(temp_r26) < 8) || ((fn_802B0130(temp_r26) == 8) && (*(f32 *)((u8 *)(temp_r26) + (8)) > temp_f28)))) {
                            temp_r16 = fn_802B0118(sp140) * 4;
                            var_r15_3 = 0;
loop_119:
                            if (var_r15_3 < fn_802AFF54((void *)var_r27)) {
                                temp_r3_11 = (u8 *)fn_802AFF5C((int *)var_r27, var_r15_3);
                                temp_r17 = temp_r16 + temp_r3_11;
                                if ((s32) *(s32 *)((u8 *)(temp_r17) + (0xC)) != 0) {
                                    fn_8001BA68(&spB0);
                                    fn_801C2B9C(&spB0, &sp120, &spF0 + (*(u16 *)((u8 *)(temp_r3_11) + (0xA)) * 0xC), *(f32 *)((u8 *)(temp_r3_11) + (0)));
                                    fn_801C2B9C(&spB0, &spB0, &spF0 + (((*(u16 *)((u8 *)(temp_r3_11) + (0xA)) + 1) & 3) * 0xC), *(f32 *)((u8 *)(temp_r3_11) + (4)));
                                    if (var_r15_3 < sp10) {
                                        fn_802B3E00(*(s32 *)((u8 *)(temp_r17) + (0xC)), &spB0, *(u16 *)((u8 *)(temp_r3_11) + (8)), lbl_80564B80);
                                    } else {
                                        fn_802B3E00(*(s32 *)((u8 *)(temp_r17) + (0xC)), &spB0, *(u16 *)((u8 *)(temp_r3_11) + (8)), temp_f21);
                                    }
                                }
                                var_r15_3 += 1;
                                goto loop_119;
                            }
                        }
                    }
                } else {
                    if ((s32) ((s32) (((u32) temp_r4_5 >> 0x1FU) + temp_r4_5) >> 1) == 4) {
                        fn_802BDFBC(sp140, *(s16 *)&(*(f32 *)((u8 *)(temp_r26) + (8))));
                    }
                    temp_r9_2 = *(s16 *)((u8 *)(temp_r26) + (4));
                    temp_r10_2 = *(s16 *)((u8 *)(temp_r26) + (2));
                    temp_r8_2 = *(s16 *)((u8 *)(temp_r26) + (6));
                    temp_r15 = (s32) (((u32) temp_r9_2 >> 0x1FU) + temp_r9_2) >> 1;
                    temp_r7_5 = *(u16 **)((u8 *)(temp_r26) + (0xC));
                    temp_r6_5 = *(u16 **)((u8 *)(temp_r26) + (0x10));
                    temp_r5_7 = *(u16 **)((u8 *)(temp_r26) + (0x14));
                    temp_r4_13 = *(u16 **)((u8 *)(temp_r26) + (0x18));
                    temp_r14_6 = (s32) (((u32) temp_r15 >> 0x1FU) + temp_r15) >> 1;
                    spD4 = *(s16 *)((u8 *)(temp_r3_5) + (4));
                    spD6 = temp_r10_2;
                    spD8 = temp_r9_2;
                    spDA = temp_r8_2;
                    spDC = *(f32 *)((u8 *)(temp_r26) + (8));
                    spE0 = temp_r7_5;
                    spE4 = temp_r6_5;
                    spE8 = temp_r5_7;
                    spEC = temp_r4_13;
                    temp_r3_12 = (u16 *)fn_802AFEC0(temp_r15);
                    temp_r4_14 = temp_r15 + 1;
                    temp_r5_8 = temp_r4_14 * 4;
                    temp_r6_6 = temp_r4_14 * 2;
                    temp_r19 = temp_r3_12 + ((temp_r5_8 - temp_r4_14) * 2);
                    temp_r16_2 = temp_r3_12;
                    temp_r17_2 = temp_r3_12 + temp_r6_6;
                    temp_r18 = temp_r3_12 + temp_r5_8;
                    fn_802AFEA4((int *)&sp10, (s16) -temp_r15);
                    switch ((s32) lbl_8055F988) {   /* switch 2; irregular */
                    case 3:                         /* switch 2 */
                        temp_r25 = spD4 - temp_r14_6;
                        temp_r23 = spD6 - temp_r14_6;
                        sp8 = &spE8[temp_r15];
                        fn_802AFE64((int *)&sp10, temp_r25, temp_r23, temp_r15, 2, (int)(temp_r19), (int)(&spE4[temp_r15]), (int)(temp_r17_2), var_f18_2, (int)sp8);
                        temp_r27 = spD4 + temp_r14_6;
                        sp8 = spE8;
                        fn_802AFE64((int *)&sp10, temp_r27, temp_r23, temp_r15, 3, (int)(temp_r18), (int)(temp_r17_2), (int)(&spEC[temp_r15]), var_f18_2, (int)sp8);
                        temp_r14_7 = spD6 + temp_r14_6;
                        sp8 = temp_r19;
                        fn_802AFE64((int *)&sp10, temp_r25, temp_r14_7, temp_r15, 1, (int)(&spE0[temp_r15]), (int)(spE4), (int)(temp_r16_2), var_f18_2, (int)sp8);
                        sp8 = temp_r18;
                        fn_802AFE64((int *)&sp10, temp_r27, temp_r14_7, temp_r15, 0, (int)(spE0), (int)(temp_r16_2), (int)(spEC), var_f18_2, (int)sp8);
                        break;
                    case 2:                         /* switch 2 */
                        temp_r25_2 = spD6 - temp_r14_6;
                        sp8 = spE8;
                        temp_r22 = spD4 + temp_r14_6;
                        fn_802AFE64((int *)&sp10, temp_r22, temp_r25_2, temp_r15, 3, (int)(temp_r18), (int)(temp_r17_2), (int)(&spEC[temp_r15]), var_f18_2, (int)sp8);
                        temp_r21 = spD6 + temp_r14_6;
                        sp8 = temp_r18;
                        fn_802AFE64((int *)&sp10, temp_r22, temp_r21, temp_r15, 0, (int)(spE0), (int)(temp_r16_2), (int)(spEC), var_f18_2, (int)sp8);
                        temp_r14_8 = spD4 - temp_r14_6;
                        sp8 = &spE8[temp_r15];
                        fn_802AFE64((int *)&sp10, temp_r14_8, temp_r25_2, temp_r15, 2, (int)(temp_r19), (int)(&spE4[temp_r15]), (int)(temp_r17_2), var_f18_2, (int)sp8);
                        sp8 = temp_r19;
                        fn_802AFE64((int *)&sp10, temp_r14_8, temp_r21, temp_r15, 1, (int)(&spE0[temp_r15]), (int)(spE4), (int)(temp_r16_2), var_f18_2, (int)sp8);
                        break;
                    case 1:                         /* switch 2 */
                        temp_r24 = spD6 + temp_r14_6;
                        sp8 = temp_r19;
                        temp_r27_2 = spD4 - temp_r14_6;
                        fn_802AFE64((int *)&sp10, temp_r27_2, temp_r24, temp_r15, 1, (int)(&spE0[temp_r15]), (int)(spE4), (int)(temp_r16_2), var_f18_2, (int)sp8);
                        temp_r21_2 = spD4 + temp_r14_6;
                        sp8 = temp_r18;
                        fn_802AFE64((int *)&sp10, temp_r21_2, temp_r24, temp_r15, 0, (int)(spE0), (int)(temp_r16_2), (int)(spEC), var_f18_2, (int)sp8);
                        temp_r14_9 = spD6 - temp_r14_6;
                        sp8 = &spE8[temp_r15];
                        fn_802AFE64((int *)&sp10, temp_r27_2, temp_r14_9, temp_r15, 2, (int)(temp_r19), (int)(&spE4[temp_r15]), (int)(temp_r17_2), var_f18_2, (int)sp8);
                        sp8 = spE8;
                        fn_802AFE64((int *)&sp10, temp_r21_2, temp_r14_9, temp_r15, 3, (int)(temp_r18), (int)(temp_r17_2), (int)(&spEC[temp_r15]), var_f18_2, (int)sp8);
                        break;
                    case 0:                         /* switch 2 */
                        temp_r25_3 = spD6 + temp_r14_6;
                        sp8 = temp_r18;
                        temp_r22_2 = spD4 + temp_r14_6;
                        fn_802AFE64((int *)&sp10, temp_r22_2, temp_r25_3, temp_r15, 0, (int)(spE0), (int)(temp_r16_2), (int)(spEC), var_f18_2, (int)sp8);
                        temp_r21_3 = spD6 - temp_r14_6;
                        sp8 = spE8;
                        fn_802AFE64((int *)&sp10, temp_r22_2, temp_r21_3, temp_r15, 3, (int)(temp_r18), (int)(temp_r17_2), (int)(&spEC[temp_r15]), var_f18_2, (int)sp8);
                        temp_r14_10 = spD4 - temp_r14_6;
                        sp8 = temp_r19;
                        fn_802AFE64((int *)&sp10, temp_r14_10, temp_r25_3, temp_r15, 1, (int)(&spE0[temp_r15]), (int)(spE4), (int)(temp_r16_2), var_f18_2, (int)sp8);
                        sp8 = &spE8[temp_r15];
                        fn_802AFE64((int *)&sp10, temp_r14_10, temp_r21_3, temp_r15, 2, (int)(temp_r19), (int)(&spE4[temp_r15]), (int)(temp_r17_2), var_f18_2, (int)sp8);
                        break;
                    }
                }
            }
        }
    } while (*(s32 *)((u8 *)(workspace) + (0)) != 0);
}
#pragma scheduling on
#pragma dont_inline reset
/* Append a 0x1C-byte corner descriptor to the count-prefixed array in *list.
 * The record holds corner x/y, a size and corner id, a float value and four
 * per-corner attribute pointers; *list is the next append index. */
void fn_802AFE64(int *list, short x, short y, short size, short corner, int attrA, int attrB, int attrD, float value, int attrC) {
    int index = *list;
    char *entry;
    *list = index + 1;
    entry = (char *)list + index * 0x1C;
    *(short *)(entry + 4) = x;
    *(short *)(entry + 6) = y;
    *(short *)(entry + 8) = size;
    *(short *)(entry + 10) = corner;
    *(float *)(entry + 12) = value;
    *(int *)(entry + 16) = attrA;
    *(int *)(entry + 20) = attrB;
    *(int *)(entry + 24) = attrC;
    *(int *)(entry + 28) = attrD;
}

/* Appends a new corner descriptor to the count-prefixed array in *list, setting only
   its size field (+8) and advancing the append index. */
void fn_802AFEA4(int *list, short size) {
    int index = *list;
    *list = index + 1;
    *(short *)((char *)list + index * 0x1C + 8) = size;
}

/* Compute a bucketed slot from the count: uses the float exponent for counts >= 2
 * to index lbl_804BDFF0, offsets from the base in lbl_8055F984, fills (count+1)*8
 * bytes with 0xFF, and returns the slot pointer. */
int fn_802AFEC0(int count) {
    float countAsFloat;
    int bucketIndex;
    int slotPtr;
    if (count >= 2) {
        countAsFloat = (float)count;
        bucketIndex = (((*(unsigned int *)&countAsFloat) >> 23) & 0x7F) + 1;
    } else {
        bucketIndex = 0;
    }
    slotPtr = *(int *)lbl_8055F984 + lbl_804BDFF0[bucketIndex] * 2;
    memset((void *)slotPtr, -1, (count + 1) * 8);
    return slotPtr;
}

/* Return the entry count stored at +4 of a table descriptor (base pointer at +0). */
int fn_802AFF54(void *table) {
    return ((int *)table)[1];
}

/* Address of 0x24-byte element index in the table whose base pointer is stored at *basePtr. */
int fn_802AFF5C(int *basePtr, int index) { return *basePtr + index * 0x24; }

/* Finalize the u16 list builder: write the stored entry count into its reserved first slot. */
void fn_802AFF6C(void *list) {
    *(unsigned short *)*(void **)list = *(unsigned short *)((char *)list + 4) - 1;
}

#pragma opt_propagation off
/* Append value to a bounded short list: struct { short* items; u16 count; u16 capacity; }, ignoring writes past capacity. */
void fn_802AFF80(void *list, short value) {
    unsigned int count = *(unsigned short *)((char *)list + 4);
    u32 capacity = *(unsigned short *)((char *)list + 6);
    short *items;
    if (count < capacity) {
        items = *(short **)list;
        capacity = count << 1;
        items[capacity >> 1] = value;
        count = count + 1;
        *(unsigned short *)((char *)list + 4) = count;
    }
}
#pragma push
#pragma scheduling on
#pragma opt_propagation on
/* Sample the terrain height at grid cell (gridX, gridZ), scaled by lbl_80564AF0
 * into world space, append the (x, height, z) point to the point buffer
 * lbl_8055F974, and return the point's u16 index. */
/* Sample the terrain height at grid cell (arg0, arg1) scaled into world space, append the (x, height, z) point to the point buffer lbl_8055F974, and return its u16 index. */ int fn_802AFFA8(int gridX, int gridZ) {
    float point[3];
    float x = (float)gridX * lbl_80564AF0;
    float z = (float)gridZ * lbl_80564AF0;
    point[0] = x;
    point[2] = z;
    point[1] = fn_801DCF48(0, x, z);
    return (unsigned short)fn_802B127C(lbl_8055F974, (int)point);
}
#pragma pop
/* Reset a bounded short list { short* items; u16 count; u16 capacity; },
 * seed element 0 when capacity allows, then append value if space remains. */
void fn_802B0024(void *list, short value) {
    u32 count = 0;
    u32 temp;
    short *items;
    *(unsigned short *)((char *)list + 4) = count;
    if (count < *(unsigned short *)((char *)list + 6)) {
        *(short *)*(void **)list = count;
        *(unsigned short *)((char *)list + 4) = 1;
    }
    temp = *(unsigned short *)((char *)list + 4);
    if (temp < *(unsigned short *)((char *)list + 6)) {
        items = *(short **)list;
        items[temp] = value;
        temp = temp + 1;
        *(unsigned short *)((char *)list + 4) = temp;
    }
}

extern int fn_802B127C(int, int);
extern float fn_801DCF48(int, float, float);
extern double lbl_80564B70;
typedef union { double d; u32 u[2]; } Cvt802B;
unsigned short fn_802B0070(int point) {
    /* Append the 3-float point at `point` to the global object lbl_8055F974's
     * point array (fn_802B127C) and return the new entry's 16-bit index. */
    return fn_802B127C(lbl_8055F974, point);
}

#pragma scheduling on
void fn_802B009C(void *arg0, int arg1, int arg2, int arg3) {
    float *out = (float *)arg0;
    float x = (float)arg2 * 2.0f;
    float z;
    z = (float)arg3 * 2.0f;
    out[0] = x;
    out[2] = z;
    out[1] = fn_801DCF48(arg1, x, z);
}
#pragma scheduling reset
/* No-op hook: callers pass the address of a Vec-like slot to be initialized
 * (five 12-byte slots at the call site), but this build leaves them untouched. */
void fn_802B0114(void) {
}

/* Return the 3-bit field at bits 6-8 of the packed flags word at +8 of a map
   piece; callers use it as a row/layer index into a spatial region grid. */
s32 fn_802B0118(void *piece) {
    return (*(u32 *)((u8 *)piece + 8) >> 6) & 7;
}

/* Read flag bit 23 of the packed config word at +0x08 of an entry. */
s32 fn_802B0124(void *entry) {
    return (*(u32 *)((u8 *)entry + 8) >> 23) & 1;
}

s32 fn_802B0130(void *entry) {
    /* Return the signed 16-bit field at +4 of the entry, halved (rounded toward zero). */
    s16 field = *(s16 *)((u8 *)entry + 4);
    return (s32)(((u32)field >> 31) + field) >> 1;
}

extern int fn_801E8718(int);
extern void fn_802AEB3C();
/* fn_801E8718(-1) returns the active entry's 0x38-byte transform snapshot;
 * fn_802AEB3C consumes that pointer (still in r3) to rebuild its state. */
#define getActiveState fn_801E8718
#define rebuildState   fn_802AEB3C
/* Rebuild the active entry's state: fetch its transform snapshot, then run the
 * full state/geometry setup that consumes the returned pointer. */
void fn_802B0144(void) {
    getActiveState(-1);
    rebuildState();
}

/* Bracketed scene/state transition: set up GPU state, then load the active
 * material set's cached field data and caches around an intermediate update. */
void fn_802B016C(void) {
#define matFieldData lbl_8055F974 /* active material set +0x4 */
#define matCacheData lbl_8055F978 /* active material set +0x8 */
#define BeginScene   fn_802DBE4C
#define EndScene     fn_802DBECC

    BeginScene();
    drawLitBillboardPass(matFieldData);
    fn_802BDD54();
    fn_802B2D94(matCacheData);
    fn_802B4E30();
    EndScene();

#undef matFieldData
#undef matCacheData
#undef BeginScene
#undef EndScene
}

#pragma dont_inline on
/* Performs a timed/flagged scene/state transition sequence: brackets work with
 * begin/end helpers, chooses a mode from bit 1 of fn_801E87A8()->+0x10, toggles
 * fn_802C9C58 around drawLitBillboardPass, then runs finalization/update calls. */
void fn_802B01A8(void) {
    long temp;
    long value;
    fn_802DBE4C();
    value = *(unsigned long *)((char *)fn_801E87A8() + 0x10);
    temp = 1;
    if ((value >> 1) & 1)
        temp = 2;
    temp = fn_802C9C58(temp);
    drawLitBillboardPass(lbl_8055F974);
    fn_802C9C58(temp);
    fn_802DBECC();
    fn_802AE728();
    fn_80202718();
    fn_8029790C(0);
    fn_802AE7C0();
}
#pragma dont_inline on
/* Debug draw pass: if the buffer for the debug overlay is allocated, save GX
 * state, walk the item container drawing each entry, clear the active light,
 * then restore GX state. */
void fn_802B0218(void) {
#define isDebugDrawReady fn_802AE7AC
#define beginDebugDraw fn_802DBE4C
#define drawDebugItems fn_802B2D94
#define clearActiveLight fn_802B4E30
#define endDebugDraw fn_802DBECC
#define gDebugItems lbl_8055F978
    if (isDebugDrawReady() != 0) {
        beginDebugDraw();
        drawDebugItems(gDebugItems);
        clearActiveLight();
        endDebugDraw();
    }
#undef gDebugItems
#undef endDebugDraw
#undef clearActiveLight
#undef drawDebugItems
#undef beginDebugDraw
#undef isDebugDrawReady
}
#pragma dont_inline reset
void fn_802B0254(void) {
#define isDebugDrawReady fn_802AE7AC
#define beginDebugDraw fn_802DBE4C
#define drawEffectDebug fn_802BDD58
#define endDebugDraw fn_802DBECC
    /* Debug overlay pass: when the debug-draw buffer is allocated, save GX state,
     * update and draw the effect/particle debug entries, then restore GX state. */
    if (isDebugDrawReady() != 0) {
        beginDebugDraw();
        drawEffectDebug();
        endDebugDraw();
    }
#undef endDebugDraw
#undef drawEffectDebug
#undef beginDebugDraw
#undef isDebugDrawReady
}
#pragma dont_inline reset
void fn_802B0288(void *matSet) {
    /* Switch the active material set; when it changes, reload the skagbag field caches for its data container (+8). */
#define activeMatSet lbl_8055F970
    if ((void *)activeMatSet != matSet)
        fn_802B4E44(*(int *)((char *)matSet + 8));
    activeMatSet = (int)matSet;
#undef activeMatSet
}

extern int fn_802AE7AC(void);
extern void *fn_802BE844();
extern float lbl_80564B6C;
extern float lbl_80564B84;
#pragma dont_inline on
extern int __cntlzw(unsigned int);
#pragma scheduling invalid_target
/* Check a world position against the loaded map: within the play field, snap
 * x/z to the 8-cell grid, read that tile's flags and return whether its
 * 0x01000000 bit is clear (out-of-range positions also count as clear). */
s32 fn_802B02C8(void *position) {
    f32 scratch;
    f32 z;
    f32 negBound;
    f32 bound;
    s32 inRange;
    f32 x;
    f32 zCoord;
    s32 cellX;
    s32 cellZ;
    s16 blockX;
    s16 blockZ;
    u32 tileFlags;

    if (fn_802AE7AC() != 0) {
        inRange = 0;
        bound = lbl_80564B84;
        scratch = lbl_80564AF0;
        bound *= scratch;
        negBound = lbl_80564B6C;
        bound *= negBound;
        negBound = -bound;
        scratch = *(f32 *)position;
        if ((scratch > negBound) && (scratch < bound)) {
            z = *(f32 *)((u8 *)position + 8);
            if ((z > negBound) && (z < bound))
                inRange = 1;
        }
        if (inRange != 0) {
            x = *(f32 *)position;
            scratch = lbl_80564AF0;
            zCoord = *(f32 *)((u8 *)position + 8);
            cellX = (s32)(x / scratch);
            cellZ = (s32)(zCoord / scratch);
            blockX = (s16)((s16)(cellX & ~7) + 4);
            blockZ = (s16)((s16)(cellZ & ~7) + 4);
            tileFlags = *(u32 *)((u8 *)fn_802BE844(blockX, blockZ, 4) + 8);
            return (u32)__cntlzw(tileFlags & 0x01000000) >> 5;
        }
        return 1;
    }
    return 0;
}
#pragma scheduling on
extern s32 fn_802B1C50(s32, s32, s32);
s32 fn_802B03C0(void *position) {
    /* Look up the surface/material id at a world position: require the field to be
     * ready and the x/z coords inside the 1024-unit play area, snap them to the
     * 8-cell grid, then read the map tile flags and use them to index the active
     * material set's (lbl_8055F970) surface-row table. */
    f32 scratch;
    f32 z;
    f32 negBound;
    f32 bound;
    s32 inRange;
    f32 x;
    f32 zCoord;
    s32 cellX;
    s32 cellZ;
    s16 blockX;
    s16 blockZ;
    u32 tileFlags;
    s32 result;

    result = 0;
    if ((fn_802AE7AC() != 0) && (lbl_8055F970 != 0)) {
        inRange = 0;
        bound = lbl_80564B84;
        scratch = lbl_80564AF0;
        bound *= scratch;
        negBound = lbl_80564B6C;
        bound *= negBound;
        negBound = -bound;
        scratch = *(f32 *)position;
        if ((scratch > negBound) && (scratch < bound)) {
            z = *(f32 *)((u8 *)position + 8);
            if ((z > negBound) && (z < bound))
                inRange = 1;
        }
        if (inRange != 0) {
            x = *(f32 *)position;
            zCoord = *(f32 *)((u8 *)position + 8);
            cellX = (s32)(x / lbl_80564AF0);
            cellZ = (s32)(zCoord / lbl_80564AF0);
            blockX = (s16)((s16)(cellX & ~7) + 4);
            blockZ = (s16)((s16)(cellZ & ~7) + 4);
            tileFlags = *(u32 *)((u8 *)fn_802BE844(blockX, blockZ, 4) + 8);
            result = fn_802B1C50(*(s32 *)((char *)lbl_8055F970 + 4),
                                  (tileFlags >> 6) & 7,
                                  ((tileFlags >> 24) & 1) ^ 1);
        }
    }
    return result;
}
#pragma dont_inline reset
#pragma dont_inline off
s32 fn_802B04D4(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f2;
    s32 var_r0;
    void *modePtr;
    s16 intX;
    s16 intZ;

    if ((u8)lbl_8055F981 != 0) {
        return fn_801EA0E8(*(f32 *)arg0, *(f32 *)((char *)arg0 + 8)) < lbl_80564BB0;
    }
    modePtr = lbl_8055CD78;
    if ((s32)modePtr >= 0) {
        var_r0 = 0;
        temp_f2 = lbl_80564B84;
        temp_f0 = lbl_80564AF0;
        temp_f2 *= temp_f0;
        temp_f1 = lbl_80564B6C;
        temp_f2 *= temp_f1;
        temp_f1 = -temp_f2;
        temp_f0 = *(f32 *)arg0;
        if ((temp_f0 > temp_f1) && (temp_f0 < temp_f2)) {
            temp_f0_2 = *(f32 *)((char *)arg0 + 8);
            if ((temp_f0_2 > temp_f1) && (temp_f0_2 < temp_f2)) {
                var_r0 = 1;
            }
        }
        if (var_r0 != 0) {
            intX = (s16)(*(f32 *)arg0 / lbl_80564AF0);
            intZ = (s16)(*(f32 *)((char *)arg0 + 8) / lbl_80564AF0);
            return (u8)lbl_8055F97C < fn_802BBD38(intX, intZ);
        }
        return 1;
    }
    return 0;
}
extern void fn_802C10C8(void);
/* Fallback for the EB-disabled path of drawWeatherLayer (weather draw): tail-calls
 * fn_802C10C8 to run the sun/light per-frame tick (fn_802C1020) instead. */
void fn_802B05D8(void) { fn_802C10C8(); }

/* Get the "water_layer" handle from game config (lbl_8055CD78, -1 if none). */
void* fn_802B05DC(void) {
    return lbl_8055CD78;
}

char fn_802B05E4(void) {
    /* Returns lbl_8055F980, the startup flag (set by fn_8012C33C on
     * "swlmap.tex") recording whether the soft-water map texture is present;
     * callers use it to pick the no-texture fallback when it is 0. */
    return lbl_8055F980;
}

extern char lbl_8055F981;
/* Returns lbl_8055F981, the "crystal_mode" flag read from the game config at
 * startup: nonzero when crystal mode is enabled. */
char fn_802B05EC(void) {
    return lbl_8055F981;
}


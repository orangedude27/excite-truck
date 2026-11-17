// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_80499E60[];
extern float PSVECDotProduct(const void *, const void *);
extern void fn_80265DD8(void *);
extern void fn_80266120(void *);
/* Initialize a 0x228-byte camera object's two embedded state blocks - the one at
   +0x160 and the spline cursor at +0x178 - through their init helpers. */
void *fn_8026A600(void *camera) {
#define InitCameraBlock_160 fn_80265DD8 /* zeroes the 0x18-byte block at camera+0x160 */
#define InitCameraSplineCursor fn_80266120 /* zeroes the spline cursor at camera+0x178 */
    InitCameraBlock_160((char *)camera + 0x160);
    InitCameraSplineCursor((char *)camera + 0x178);
    return camera;
#undef InitCameraBlock_160
#undef InitCameraSplineCursor
}

#pragma scheduling invalid_target
float fn_8026A63C(const float * __restrict arg0, const float * __restrict arg1, const float * __restrict arg2) {
    float sp8[3];
    float x;
    float y;
    float z;
    x = arg0[0] - arg1[0];
    y = arg0[1] - arg1[1];
    z = arg0[2] - arg1[2];
    sp8[0] = x;
    sp8[1] = y;
    sp8[2] = z;
    return PSVECDotProduct(sp8, arg2);
}

extern float lbl_80558DC4;
extern int lbl_8055E3C4;
extern float lbl_80563D18;
extern float lbl_80563D10;
extern float lbl_80563D14;
extern float lbl_80563D20;
extern float lbl_80563D24;
extern float lbl_80563D28;
extern float lbl_80563D2C;
extern float lbl_80563D1C;
extern int fn_801CF064(void);
extern void fn_80176A00(int);
extern int fn_80178CA4(void);
extern int fn_801B8570(int);
extern int fn_8026A38C(void);
extern void *__AXFXGetLfoSinTable_801769CC(void);
int fn_8026A698(void *arg0, int arg1) {
    char *p = (char *)arg0;
    char *e;
    void *obj;
    int v;
    int flag = 1;
    obj = *(void **)(p + 0x140);
    e = (char *)lbl_80499E60 + arg1 * 0x6C;
    v = *(int *)((char *)obj + 0x10);
    if ((unsigned int)(v + 0xAFBD0000) == 0x4152U) {
        void *q = *(void **)((char *)obj + 0x270C);
        int (*f)(void *) = *(int (**)(void *))((char *)*(void **)q + 0x14);
        if ((f(q) & 0x20) != 0) flag = 0;
    }
    if (fn_801CF064() != 0) goto fail;
    if (*(int *)(p + 0x10) == 0x11) goto fail;
    if (*(int *)(p + 0x10) == 0x15) goto fail;
    if ((*(int *)((char *)__AXFXGetLfoSinTable_801769CC() + 4) & 0x4000) != 0) goto fail;
    if (flag != 0) goto fail;
    {
        int r = fn_80178CA4();
        int inv = r ^ 1;
        int q2 = (inv >> 1) - (inv & r);
        int s = (unsigned int)q2 >> 31;
        float fv;
        int use = 0;
        fv = *(float *)((char *)obj + 0x2690);
        if (fv < 0) fv = -fv;
        if (fv != lbl_80558DC4) {
            if (fn_801B8570(*(int *)((char *)obj + 0x1EC)) != 0) use = 1;
        }
        if (use == 0) {
            *(float *)(e + 0x60) = lbl_80563D18;
            if (e[0] != 0) {
                e[0] = 0;
                if (s == 0) *(char *)(p + 0x138) = 1;
                fn_80176A00(1);
            }
            return 0;
        }
        if (s != 0) {
            e[0] = 1;
            return 0;
        }
        if (fn_8026A38C() != 0) {
            e[0] = 0;
            fn_80176A00(1);
            return 0;
        }
        if (e[0] == 0) {
            *(char *)(p + 0x138) = 1;
            e[0] = 1;
        } else {
            *(char *)(p + 0x138) = 0;
        }
    }
    return 1;
fail:
    if (e[0] != 0) fn_80176A00(1);
    *(float *)(e + 0x60) = lbl_80563D18;
    e[0] = 0;
    return 0;
}

#pragma scheduling on
/* Returns the in-use flag of the given player's arena-event entry in the
   4-slot pool at lbl_80499E60; each entry is 0x6C bytes, flag at offset 0. */
unsigned char fn_8026B0C0(int playerIndex) {
#define ARENA_EVENT_SLOT_SIZE 0x6C
    extern unsigned char lbl_80499E60[];
    return lbl_80499E60[playerIndex * ARENA_EVENT_SLOT_SIZE];
#undef ARENA_EVENT_SLOT_SIZE
}


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma paired off
#pragma paired_single off
extern char lbl_8032BFA0[];
extern char lbl_8032BFAC[];
extern float lbl_805613E4;
extern float lbl_805613E8;
extern float lbl_805613EC;
extern void fn_80148134(float *, float *, int, float, float);
extern void fn_802C8E00(int, int, float, float, float, float, float);
typedef struct VT390 { int pad[4]; char *(*fn)(void *, void *); } VT390;
typedef struct Obj390 { VT390 *vt; } Obj390;
#pragma push
#pragma processor 750
void fn_801390B0(void *arg0, float *arg1, float *arg2, int arg3, float farg0, float farg1) {
    float d[4];
    float pos[2];
    char *obj;
    int color;
    float f3, f4;
    char *tbl = lbl_8032BFAC;
    if (arg3 != 0) tbl = lbl_8032BFA0;
    obj = ((Obj390 *)arg0)->vt->fn(arg0, tbl);
    f4 = lbl_805613E8 * (farg0 * *(float *)(obj + 0x10));
    f3 = lbl_805613E8 * (farg0 * *(float *)(obj + 0x14));
    d[2] = arg2[0] * f3;
    d[3] = arg2[1] * f3;
    d[0] = arg2[1] * f4;
    d[1] = -(arg2[0] * f4);
    if (obj != 0) {
        color = ((int)(lbl_805613EC * farg1) << 24) | 0xFFFFFF;
        fn_80148134(&pos[1], &pos[0], 0, d[2] + (arg1[0] - d[0]), d[3] + (arg1[1] - (float)d[1]));
        fn_802C8E00(color, 0, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x18), *(float *)(obj + 0x1C));
        fn_80148134(&pos[1], &pos[0], 0, d[2] + (arg1[0] + d[0]), d[3] + (arg1[1] + d[1]));
        fn_802C8E00(color, 0, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x20), *(float *)(obj + 0x1C));
        fn_80148134(&pos[1], &pos[0], 0, (arg1[0] - d[0]) - d[2], (arg1[1] - d[1]) - d[3]);
        fn_802C8E00(color, 1, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x18), *(float *)(obj + 0x24));
        fn_80148134(&pos[1], &pos[0], 0, (arg1[0] + d[0]) - d[2], (arg1[1] + d[1]) - d[3]);
        fn_802C8E00(color, 1, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x20), *(float *)(obj + 0x24));
    }
}
#pragma pop
/* Player slot of a racer vehicle: objects registered in the 8-entry object
 * table (lbl_80430830, see fn_8017960C/fn_801795D8) carry their type at +0x1F0
 * and, for a player/racer vehicle (type 0x50), their split-screen player slot
 * in the low two bits of +0x260.  Anything that is not a racer vehicle reports
 * slot 0; the caller turns the slot into that player's 0x38-byte record
 * (fn_801E8718). */
int fn_801392F8(void *vehicle) {
    if (*(int *)((unsigned char *)vehicle + 0x1F0) == 0x50) {
        return *(unsigned char *)((unsigned char *)vehicle + 0x260) & 3;
    }
    return 0;
}

extern char lbl_8032BFB8[];
extern char lbl_8032BFC8[];
extern float lbl_80558DC4;
extern int lbl_8055E4D0;
extern float lbl_805613E0;
extern float lbl_805613F0;
extern float lbl_805613F4;
extern float lbl_805613F8;
extern float lbl_805613FC;
extern float lbl_80561400;
extern float lbl_80561404;
extern float lbl_80561408;
extern void fn_801476D8(void *, int, int);
extern int fn_8017960C(int);
extern int fn_801392F8(void *);
extern void *fn_801E8718(long);
extern double fn_8002F234(float x);
extern float PSVECMag(void *);
extern int fn_801B8570(int);
extern void fn_802C8BD0(int);
extern int fn_802C8DBC(int);
extern void fn_802C8E48(void);
extern void fn_802C8D74(void);
extern void fn_801390B0(void *, float *, float *, int, float, float);
void fn_80139318(void *arg0, int arg1, int arg2, float farg0) {
    char *o1;
    char *o2;
    void *ip;
    void *cur;
    float a0, a1, b0, b1;
    float sx, sy;
    float f1, f2, f3;
    float stack10[2];
    float stack18[2];
    float m[8];
    int n;
    float lim0, lim1, c0, c1, c2, c3, c4, c5, c6;
    float t;
    o1 = ((Obj390 *)arg0)->vt->fn(arg0, lbl_8032BFB8);
    fn_801476D8(o1, -1, arg1);
    o2 = ((Obj390 *)arg0)->vt->fn(arg0, lbl_8032BFC8);
    a0 = *(float *)(o2 + 4);
    b0 = *(float *)(o2 + 8);
    sx = *(float *)(o2 + 0x10);
    sy = *(float *)(o2 + 0x14);
    a1 = a0 + sx;
    b1 = b0 + sy;
    m[0] = sx;
    m[1] = sy;
    m[5] = a1;
    m[6] = b1;
    ip = fn_801E8718(fn_801392F8((void *)fn_8017960C(arg2)));
    if (__builtin_fabsf(*(float *)((char *)ip + 0x18)) != lbl_80558DC4 || __builtin_fabsf(*(float *)((char *)ip + 0x20)) != lbl_80558DC4) {
        float ex = *(float *)((char *)ip + 0x18);
        float ey = *(float *)((char *)ip + 0x20);
        double s = fn_8002F234((double)(ex * ex + ey * ey));
        float inv = lbl_805613E0 / (float)s;
        float vx = ex * inv;
        float vy = ey * inv;
        fn_802C8BD0(arg1);
        if (fn_802C8DBC(0x20) != 0) {
            n = lbl_8055E4D0 - 1;
            lim0 = lbl_805613E0;
            lim1 = lbl_805613E4;
            c0 = lbl_805613F0;
            c1 = lbl_805613F4;
            c2 = lbl_805613F8;
            c3 = lbl_805613FC;
            c4 = lbl_80561400;
            c5 = lbl_80561404;
            c6 = lbl_80561408;
            for (; n >= 0; n--) {
                cur = (void *)fn_8017960C(n);
                if (fn_801B8570(n) != 0) {
                    float v0, v1, v2;
                    v0 = PSVECMag(stack18);
                    t = (v0 - c2 * farg0) / (c3 * farg0 - c2 * farg0);
                    if (t > lim0) t = lim0;
                    if (t < lim1) t = lim1;
                    f1 = (v0 - c2 * farg0) / (c5 * farg0 - c2 * farg0);
                    if (f1 > lim0) f1 = lim0;
                    if (f1 < lim1) f1 = lim1;
                    f2 = 0;
                    f3 = 0;
                    if (v0 > farg0) {
                        f2 = PSVECMag(stack18);
                        if (__builtin_fabsf(f2) != lbl_80558DC4) {
                            float k = farg0 / f2;
                            stack18[0] *= k;
                            stack18[1] *= k;
                        }
                    }
                    stack10[0] = a0 + t * (m[5] - a0);
                    stack10[1] = b0 + f3 * (m[6] - b0);
                    fn_801390B0(arg0, stack10, stack18, n == arg2, lim0 + t * c4, lim0 + f1 * c6);
                }
            }
            fn_802C8E48();
        }
        fn_802C8D74();
    }
}


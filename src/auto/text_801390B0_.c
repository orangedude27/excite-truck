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
static inline float ScaleF390(float v, float s) { return v * s; }
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801390B0(void *arg0, float *arg1, float *arg2, int arg3, float farg0, float farg1) {
    struct Obj390 {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual char *v2(void *) = 0;
    };
    float d[4];
    float pos[2];
    char *obj;
    int color;
    float f1, f2, f3, f4;
    char *tbl = lbl_8032BFAC;
    if (arg3 != 0) tbl = lbl_8032BFA0;
    obj = ((Obj390 *)arg0)->v2(tbl);
    f3 = farg0 * *(float *)(obj + 0x14) * lbl_805613E8;
    f4 = farg0 * *(float *)(obj + 0x10) * lbl_805613E8;
    d[2] = arg2[0] * f3;
    d[3] = arg2[1] * f3;
    d[0] = arg2[1] * f4;
    d[1] = -(arg2[0] * f4);
    if (obj != 0) {
        color = ((int)(lbl_805613EC * farg1) << 24) | 0xFFFFFF;
        fn_80148134(&pos[1], &pos[0], 0, d[2] + (arg1[0] - d[0]), d[3] + (arg1[1] - d[1]));
        fn_802C8E00(color, 0, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x18), *(float *)(obj + 0x1C));
        fn_80148134(&pos[1], &pos[0], 0, d[2] + (arg1[0] + d[0]), d[3] + (arg1[1] + d[1]));
        fn_802C8E00(color, 0, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x20), *(float *)(obj + 0x1C));
        fn_80148134(&pos[1], &pos[0], 0, (arg1[0] - d[0]) - d[2], (arg1[1] - d[1]) - d[3]);
        fn_802C8E00(color, 1, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x18), *(float *)(obj + 0x24));
        fn_80148134(&pos[1], &pos[0], 0, (arg1[0] + d[0]) - d[2], (arg1[1] + d[1]) - d[3]);
        fn_802C8E00(color, 1, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x20), *(float *)(obj + 0x24));
    }
}
#pragma cplusplus reset
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
__declspec(section ".data") extern float lbl_80558DC4;
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
extern void DrawList_RestoreNormalMode(void);
extern void fn_801390B0(void *, float *, float *, int, float, float);
extern double __fabs(double);
#pragma push
#pragma processor 750
void fn_80139318(void *arg0, int arg1, int arg2, float farg0) {
#pragma dont_inline on
    float v[30];
    float f25, f28, f23, f24, f26, f27, f29, f30, f31, f22, f21;
    float t0, t1, t2, t3, t4, t5, k, mag, ex, ey, ez, inv, vx, vy;
    float cl0, cl1, u, w;
    char *o1, *o2, *ip, *cur;
    int n;

    o1 = ((Obj390 *)arg0)->vt->fn(arg0, lbl_8032BFB8);
    fn_801476D8(o1, -1, arg1);
    o2 = ((Obj390 *)arg0)->vt->fn(arg0, lbl_8032BFC8);
    *(int *)&v[10] = *(int *)(o2 + 4);
    *(int *)&v[11] = *(int *)(o2 + 8);
    v[0] = *(float *)(o2 + 0x10);
    v[1] = *(float *)(o2 + 0x14);
    v[8] = v[10] + v[0];
    v[9] = v[11] + v[1];
    ip = fn_801E8718(fn_801392F8((void *)fn_8017960C(arg2)));
    if (lbl_80558DC4 <= (float)__fabs((double)*(float *)(ip + 0x18)) ||
        lbl_80558DC4 <= (float)__fabs((double)*(float *)(ip + 0x20))) {
        ex = *(float *)(ip + 0x18);
        ey = *(float *)(ip + 0x20);
        v[6] = ex;
        v[7] = ey;
        ez = *(float *)(ip + 0x24);
        inv = lbl_805613E0 / (float)fn_8002F234(ex * ex + ey * ey);
        vx = v[6] * inv;
        vy = v[7] * inv;
        v[25] = lbl_805613E4;
        v[24] = vx;
        v[26] = vy;
        v[6] = vy;
        v[7] = (float)-vx;
        v[18] = vy;
        v[19] = lbl_805613E4;
        v[20] = (float)-vx;
        v[21] = lbl_805613E4;
        v[22] = lbl_805613E0;
        v[23] = lbl_805613E4;
        v[27] = ez;
        v[28] = *(float *)(ip + 0x28);
        v[29] = *(float *)(ip + 0x2C);
        fn_802C8BD0(arg1);
        if (fn_802C8DBC(0x20) != 0) {
            f25 = lbl_805613E0;
            f28 = lbl_805613E4;
            f23 = lbl_805613F0;
            f24 = lbl_805613F4;
            f26 = lbl_805613F8;
            f27 = lbl_805613FC;
            f29 = lbl_80561400;
            f30 = lbl_80561404;
            f31 = lbl_80561408;
            for (n = lbl_8055E4D0 - 1; n >= 0; n--) {
                cur = (char *)fn_8017960C(n);
                if (fn_801B8570(n) != 0) {
                    if ((float *)&v[15] == (float *)((char *)cur + 0x54)) {
                        float c54 = *(float *)(cur + 0x54);
                        float c58 = *(float *)(cur + 0x58);
                        float c5c = *(float *)(cur + 0x5C);
                        v[15] = c5c * v[20] + (c54 * v[18] + c58 * v[19]);
                        v[16] = c5c * v[23] + (c54 * v[21] + c58 * v[22]);
                        v[17] = c5c * v[26] + (c54 * v[24] + c58 * v[25]);
                    } else {
                        v[15] = *(float *)(cur + 0x5C) * v[20] + (*(float *)(cur + 0x54) * v[18] + *(float *)(cur + 0x58) * v[19]);
                        v[16] = *(float *)(cur + 0x5C) * v[23] + (*(float *)(cur + 0x54) * v[21] + *(float *)(cur + 0x58) * v[22]);
                        v[17] = *(float *)(cur + 0x5C) * v[26] + (*(float *)(cur + 0x54) * v[24] + *(float *)(cur + 0x58) * v[25]);
                    }
                    v[4] = v[15];
                    v[5] = v[17] * f23;
                    mag = (float)fn_8002F234(v[15] * v[15] + v[5] * v[5]);
                    if (f24 > mag) mag = f24;
                    k = f25 / mag;
                    v[4] *= k;
                    v[5] *= k;
                    t0 = *(float *)(cur + 0x60) - v[27];
                    t1 = *(float *)(cur + 0x64) - v[28];
                    t2 = *(float *)(cur + 0x68) - v[29];
                    v[12] = t2 * v[20] + (t0 * v[18] + t1 * v[19]);
                    v[13] = t2 * v[23] + (t0 * v[21] + t1 * v[22]);
                    v[14] = t2 * v[26] + (t0 * v[24] + t1 * v[25]);
                    mag = PSVECMag((void *)&v[12]);
                    t3 = f26 * farg0;
                    cl0 = (mag - t3) / (f27 * farg0 - t3);
                    if (f25 < cl0) cl0 = f25;
                    if (cl0 <= f28) cl0 = f28;
                    f22 = f25 + cl0 * f29;
                    t3 = f27 * farg0;
                    cl1 = (mag - t3) / (f30 * farg0 - t3);
                    if (f25 < cl1) cl1 = f25;
                    if (cl1 <= f28) cl1 = f28;
                    f21 = f25 + cl1 * f31;
                    if (mag > farg0) {
                        t4 = PSVECMag((void *)&v[12]);
                        if (lbl_80558DC4 < (float)__fabs((double)t4)) {
                            k = farg0 / t4;
                            v[12] *= k;
                            v[13] *= k;
                            v[14] *= k;
                        }
                    }
                    t5 = -farg0;
                    u = (v[12] - t5) / (farg0 - t5);
                    if (f25 < u) u = f25;
                    if (u <= f28) u = f28;
                    w = (v[14] - farg0) / (-farg0 - farg0);
                    v[2] = v[10] + (u * (v[8] - v[10]));
                    if (f25 < w) w = f25;
                    if (w <= f28) w = f28;
                    v[3] = v[11] + (w * (v[9] - v[11]));
                    fn_801390B0(arg0, (float *)&v[2], (float *)&v[4], n == arg2, f22, f21);
                }
            }
            fn_802C8E48();
        }
        DrawList_RestoreNormalMode();
    }
}
#pragma pop


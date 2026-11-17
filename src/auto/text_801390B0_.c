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
extern float fabsf(float);
#pragma push
#pragma processor 750
void fn_80139318(void *arg0, int arg1, int arg2, float farg0) {
#pragma paired off
#pragma paired_single off
#pragma dont_inline on
    float sp8, spC, sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C;
    float sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54;
    float sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C;
    float f25, f28, f23, f24, f26, f27, f29, f30, f31, f22, f21;
    float t0, t1, t2, t3, t4, t5, k, mag, ex, ey, ez, inv, vx, vy;
    float cl0, cl1, u, w;
    char *o1, *o2, *ip, *cur;
    int n;

    o1 = ((Obj390 *)arg0)->vt->fn(arg0, lbl_8032BFB8);
    fn_801476D8(o1, -1, arg1);
    o2 = ((Obj390 *)arg0)->vt->fn(arg0, lbl_8032BFC8);
    sp30 = *(float *)(o2 + 4);
    sp34 = *(float *)(o2 + 8);
    sp8 = *(float *)(o2 + 0x10);
    spC = *(float *)(o2 + 0x14);
    sp28 = sp30 + sp8;
    sp2C = sp34 + spC;
    ip = fn_801E8718(fn_801392F8((void *)fn_8017960C(arg2)));
    if (__builtin_fabsf(*(float *)(ip + 0x18)) != lbl_80558DC4 ||
        __builtin_fabsf(*(float *)(ip + 0x20)) != lbl_80558DC4) {
        ex = *(float *)(ip + 0x18);
        ey = *(float *)(ip + 0x20);
        sp20 = ex;
        sp24 = ey;
        ez = *(float *)(ip + 0x24);
        inv = lbl_805613E0 / (float)fn_8002F234(ex * ex + ey * ey);
        vx = sp20 * inv;
        vy = sp24 * inv;
        sp6C = lbl_805613E4;
        sp68 = vx;
        sp70 = vy;
        sp20 = vy;
        sp24 = -vx;
        sp50 = vy;
        sp58 = -vx;
        sp5C = lbl_805613E4;
        sp60 = lbl_805613E0;
        sp64 = lbl_805613E4;
        sp74 = ez;
        sp78 = *(float *)(ip + 0x28);
        sp7C = *(float *)(ip + 0x2C);
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
                    sp44 = *(float *)(cur + 0x5C) * sp58 + (*(float *)(cur + 0x54) * sp50 + *(float *)(cur + 0x58) * sp54);
                    sp48 = *(float *)(cur + 0x5C) * sp64 + (*(float *)(cur + 0x54) * sp5C + *(float *)(cur + 0x58) * sp60);
                    sp4C = *(float *)(cur + 0x5C) * sp70 + (*(float *)(cur + 0x54) * sp68 + *(float *)(cur + 0x58) * sp6C);
                    sp18 = sp44;
                    sp1C = sp4C * f23;
                    mag = (float)fn_8002F234(sp44 * sp44 + sp1C * sp1C);
                    if (f24 > mag) mag = f24;
                    k = f25 / mag;
                    sp18 *= k;
                    sp1C *= k;
                    t0 = *(float *)(cur + 0x60) - sp74;
                    t1 = *(float *)(cur + 0x64) - sp78;
                    t2 = *(float *)(cur + 0x68) - sp7C;
                    sp38 = t2 * sp58 + (t0 * sp50 + t1 * sp54);
                    sp3C = t2 * sp64 + (t0 * sp5C + t1 * sp60);
                    sp40 = t2 * sp70 + (t0 * sp68 + t1 * sp6C);
                    mag = PSVECMag(&sp38);
                    t3 = f26 * farg0;
                    cl0 = (mag - t3) / (f27 * farg0 - t3);
                    if (f25 < cl0) cl0 = f25;
                    if (cl0 > f28) { } else { cl0 = f28; }
                    f22 = f25 + cl0 * f29;
                    t3 = f27 * farg0;
                    cl1 = (mag - t3) / (f30 * farg0 - t3);
                    if (f25 < cl1) cl1 = f25;
                    if (cl1 > f28) { } else { cl1 = f28; }
                    f21 = f25 + cl1 * f31;
                    if (mag > farg0) {
                        t4 = PSVECMag(&sp38);
                        if (__builtin_fabsf(t4) != lbl_80558DC4) {
                            k = farg0 / t4;
                            sp38 *= k;
                            sp3C *= k;
                            sp40 *= k;
                        }
                    }
                    t5 = -farg0;
                    u = (sp38 - t5) / (farg0 - t5);
                    if (f25 < u) u = f25;
                    if (u > f28) { } else { u = f28; }
                    w = (sp40 - farg0) / (-farg0 - farg0);
                    sp10 = sp30 + (u * (sp28 - sp30));
                    if (f25 < w) w = f25;
                    if (w > f28) { } else { w = f28; }
                    sp14 = sp34 + (w * (sp2C - sp34));
                    fn_801390B0(arg0, &sp10, &sp18, n == arg2, f22, f21);
                }
            }
            fn_802C8E48();
        }
        fn_802C8D74();
    }
}


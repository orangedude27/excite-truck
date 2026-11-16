#include "revolution/MTX/mtxtypes.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma ppc_psq_save off
#pragma paired_single off
extern float lbl_80563140;
extern float lbl_80563144;

extern void fn_80128668(void*);
void* fn_80203F88(void* object, int shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when
     * shouldDelete > 0 (deleting-destructor style helper). */
    if (object != 0) {
        if (object != 0) {
            *(int *)object = 0;
            *((int *)object + 1) = 0;
            *((int *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

float fn_80203FE0(void) { return lbl_80563140; }

void fn_80203FE8(void) {

}

void fn_80203FF8(void) {

}

void fn_80204000(void) {

}

void fn_80204008(void) {

}

int fn_8020400C(void) {
    return 0;
}

void fn_80204014(void) {

}

void fn_80204018(void) {

}

void fn_8020401C(void) {

}

void fn_80204020(void) {

}

int fn_80204024(void) {
    return 0;
}

int fn_8020402C(void) {
    return 0;
}

void fn_80204034(void) {

}

void fn_80204038(void) {

}

int fn_8020403C(void) {
    return 1;
}

void fn_80204044(void) {

}

void fn_80204048(void) {

}

void fn_8020404C(void) {

}

void fn_80204050(void) {

}

extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern float lbl_8055FC88;
extern float lbl_80563148;
extern float lbl_8056314C;
extern float lbl_80563150;
extern float lbl_80563154;
extern float lbl_80563158;
extern char lbl_8033BAD8[];
extern void PSVECNormalize(void *, void *);
extern void fn_801E9DC4(short *);
extern int fn_801E9E78(void *, void *, int, int);
extern void fn_802E30C8(const char *, ...);
extern double __fabs(double);
extern double lbl_80563160;
#pragma paired_single off
#pragma ppc_psq_save off
s32 fn_80204054(Vec *outPos, Vec *outNormal, s16 *context, f32 *m, s32 screenX, s32 screenY) {
    Vec dir;
    Vec pos;
    Vec hit;
    Vec orig;
    s32 info;
    s16 localContext;
    f32 scale, dx, dy;
    f32 a, b, c, p, q, r, x, y, z;
    f32 step, dist, minStep, maxDist, mult, tol;
    s32 noHit, flagB, found;

    scale = (f32)(lbl_8055CFF0 / 2) / lbl_8055FC88;
    dx = (f32)(screenX - lbl_8055CFF0 / 2);
    dy = -(f32)(screenY - lbl_8055CFF4 / 2);

    a = m[6] * scale;
    b = m[7] * scale;
    c = m[8] * scale;
    p = m[0] * dx;
    q = m[1] * dx;
    r = m[2] * dx;
    x = m[3] * dy;
    y = m[4] * dy;
    z = m[5] * dy;
    dir.x = a + p + x;
    dir.y = b + q + y;
    dir.z = c + r + z;
    PSVECNormalize(&dir, &dir);

    if (context == 0) {
        context = &localContext;
    }

    step = lbl_80563148;
    dist = step;
    minStep = lbl_80563158;
    maxDist = lbl_80563154;
    mult = lbl_80563150;
    tol = lbl_8056314C;
    flagB = 0;

    for (;;) {
        f32 d = dist;
        found = 0;
        pos.x = m[9] + dir.x * d;
        pos.y = m[10] + dir.y * d;
        pos.z = m[11] + dir.z * d;
        orig.x = pos.x;
        orig.y = pos.y;
        orig.z = pos.z;

        fn_801E9DC4(context);
        noHit = (fn_801E9E78(context, &pos, (s32)&hit, (s32)&info) == 0);
        if (noHit == 0) {
            if (pos.y > orig.y) {
                found = 1;
                goto block11;
            }
            if ((f32)__fabs((f64)(pos.y - orig.y)) > tol) {
                if (flagB != 0) {
                    step *= mult;
                }
                dist += step;
                goto block11;
            }
        } else {
            found = 1;
        block11:
            if (found != 0) {
                step *= mult;
                flagB = 1;
                dist -= step;
            }
            if (dist > maxDist) {
                noHit = 1;
                fn_802E30C8(lbl_8033BAD8, orig.x, orig.z);
            } else if (step > minStep) {
                continue;
            }
        }
        if (noHit == 0) {
            outPos->x = pos.x;
            outPos->y = pos.y;
            outPos->z = pos.z;
            if (outNormal != 0) {
                outNormal->x = hit.x;
                outNormal->y = hit.y;
                outNormal->z = hit.z;
            }
        }
        return noHit == 0;
    }
}
#pragma paired_single reset
#pragma ppc_psq_save reset
void fn_80204004(void) {

}

void fn_80203FFC(void) {

}

void fn_80203FEC(void) {

}

float fn_80203FF0(void) { return lbl_80563144; }

extern float lbl_80563140;
extern float lbl_80563144;

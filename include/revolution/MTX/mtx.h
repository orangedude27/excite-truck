#ifndef RVL_SDK_MTX_MTX_H
#define RVL_SDK_MTX_MTX_H
#include <types.h>

#include <revolution/MTX/mtxtypes.h>
#ifdef __cplusplus
extern "C" {
#endif

// TODO: Create macros for PS/C_ functions
void PSMTXIdentity(Mtx);
void PSMTXCopy(const Mtx, Mtx);
void PSMTXConcat(const Mtx, const Mtx, Mtx);
void PSMTXConcatArray(const Mtx, const Mtx, Mtx, u32);
void PSMTXTranspose(const Mtx, Mtx);
/* This build's matrix library carries SDK names that sit on other routines: what is
 * called PSMTXInverse here builds a rotation matrix about one coordinate axis, and
 * PSMTXInvXpose fills one from a sine and cosine already computed (the SDK's
 * PSMTXRotRad and PSMTXRotTrig, whose names this build uses for two other routines). */
u32 PSMTXInverse(Mtx mtx, char axis, f32 rad);
u32 PSMTXInvXpose(Mtx mtx, s32 axis, f64 sinA, f64 cosA);
void PSMTXRotRad(Mtx, f32, f32, f32);
void PSMTXRotTrig(Mtx, Mtx, f32, f32, f32);
void PSMTXRotAxisRad(Mtx, const Vec*, f32);
void PSMTXTrans(Mtx, f32, f32, f32);
void PSMTXTransApply(const Mtx, Mtx, f32, f32, f32);
void PSMTXScale(Mtx, f32, f32, f32);
void PSMTXScaleApply(const Mtx, Mtx, f32, f32, f32);
void PSMTXQuat(Mtx, const Quaternion*);

void C_MTXLookAt(Mtx, const Vec*, const Vec*, const Vec*);
void C_MTXLightFrustum(Mtx, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void C_MTXLightPerspective(Mtx, f32, f32, f32, f32, f32, f32);
void C_MTXLightOrtho(Mtx, f32, f32, f32, f32, f32, f32, f32, f32);

#ifdef __cplusplus
}
#endif
#endif

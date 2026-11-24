#include <revolution/MTX/mtxtypes.h>
#include "types.h"
extern f32 lbl_805639DC, lbl_805639E4, lbl_805639E0;
extern f32 lbl_80558DC4[];
extern f32 fn_8002F234(f32);
extern f32 PSVECDotProduct(void *, void *);
typedef struct { f32 x, y, z, w; } Vec4_80252;
extern f32 lbl_805639C8, lbl_805639D0, lbl_805639D4, lbl_805639D8;
extern f32 fn_80129DC4(s32, f32, f32);
extern f64 cos(void);
extern f64 sin(f32);
extern void PSVECCrossProduct(void *, void *, void *);
extern f32 fn_801DCF48(s32, u32, u32, u32, u32, u32, u32, u32, f32, f32);
extern s8 lbl_8055F308;
extern u8 lbl_80498D00[];
extern f32 lbl_8055F30C, lbl_805639CC, lbl_805639E0, lbl_805639F8, lbl_805639E8;
extern u8 lbl_8055F310;
extern const char lbl_803447A8[];
void fn_801BD808(void);
void fn_801BDA70(void *);
void fn_801BDA74(s32, void *);
void fn_80252B88(s32);
void fn_802526E0(void *);
void fn_801BE400(s32, void *, f32);
void fn_80252C90(void);
void fn_802E30C8(const char *, const char *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055EAA8, lbl_8055EAAC, lbl_8055F2F8;
void fn_801BD790(void);
#pragma push
#pragma processor 750
void fn_802526E0(void *arg0) {
    volatile f32 spC;
    volatile f32 sp8;
    volatile f32 *out = (volatile f32 *)arg0;
    f32 a = 0.0f, b = 6.28319f;
    f32 temp_f31, temp_f30, temp_f29, temp_f4, temp_f4_2, temp_f5;
    f32 temp_f1, temp_f2, temp_f3, temp_f2_2, temp_f4_3, temp_f5_2, temp_f6;
    f32 temp_f1_2;
    temp_f29 = fn_80129DC4(0, a, b);
    temp_f31 = lbl_805639D4;
    sp8 = temp_f31;
    spC = lbl_805639CC;
    temp_f30 = (f32)cos();
    temp_f4 = (f32)sin(temp_f29);
    out[10] = (f32)lbl_805639CC;
    temp_f4_2 = temp_f31 * temp_f4;
    temp_f5 = ((f32)temp_f31 * temp_f30) - (spC * temp_f4);
    temp_f1 = temp_f5 * lbl_805639C8;
    out[9] = temp_f5;
    temp_f3 = temp_f4_2 + (spC * temp_f30);
    sp8 = temp_f5;
    temp_f2 = temp_f3 * lbl_805639C8;
    out[11] = temp_f3;
    spC = temp_f3;
    out[9] = temp_f1;
    out[10] = (f32)(lbl_805639CC * lbl_805639C8);
    out[11] = temp_f2;
    temp_f2_2 = -spC;
    temp_f4_3 = sp8;
    temp_f5_2 = lbl_805639D8 + ((f32 (*)(s32, f32, f32, f32, f32, f32))fn_801DCF48)(0, temp_f1, temp_f2, temp_f3, temp_f4_2, temp_f5);
    temp_f6 = sp8;
    temp_f1_2 = spC;
    out[10] = temp_f5_2;
    out[0] = temp_f4_3;
    out[1] = (f32)lbl_805639CC;
    out[2] = temp_f1_2;
    sp8 = (f32)temp_f2_2;
    spC = temp_f6;
    out[6] = (f32)temp_f2_2;
    out[7] = (f32)lbl_805639CC;
    out[8] = temp_f6;
    ((void (*)(void *, void *, void *, f32, f32, f32, f32, f32, f32))PSVECCrossProduct)((void *)(out + 6), (void *)out, (void *)(out + 3), temp_f1_2, temp_f2_2, lbl_805639CC, temp_f4_3, temp_f5_2, temp_f6);
}

#pragma push
#pragma processor 750
void fn_8025280C(void *arg0,f32 amount) {
    Quaternion position, lateral, result, temp, lateralTemp;
    Vec normal, forward, right, velocity;
    Vec2 direction, unit, perpendicular;
    f32 length, scale, height, a, b, a3, b3;
    f32 len[1];
    f32 *self=arg0;
    position.z=self[2]; position.y=self[1]; position.x=self[0];
    direction.x=position.x; direction.y=position.z;
    if(direction.x*direction.x+direction.y*direction.y<1.0f) {
        direction.x=1.0f; direction.y=0.0f;
    }
    len[0]=(f32)fn_8002F234(direction.x*direction.x+direction.y*direction.y);
    if (!((f32)__fabs(len[0])<=lbl_80558DC4[0])) {
        scale=lbl_805639C8/len[0];
        direction.x*=scale; direction.y*=scale;
    }
    position.x=direction.x; position.z=direction.y;
    temp.x=position.x; temp.y=position.y; temp.z=position.z;
    self[0]=temp.x; self[1]=temp.y; self[2]=temp.z; self[3]=temp.w;
    unit.x=direction.x; unit.y=direction.y;
    len[0]=(f32)fn_8002F234(unit.x*unit.x+unit.y*unit.y);
    scale=1.0f/len[0];
    unit.x*=scale; unit.y*=scale;
    *(f64 *)&perpendicular=*(f64 *)&unit;
    perpendicular.x=-unit.y; perpendicular.y=unit.x;
    len[0]=(f32)fn_8002F234(perpendicular.x*perpendicular.x+perpendicular.y*perpendicular.y);
    if (!((f32)__fabs(len[0])<=lbl_80558DC4[0])) {
        scale=amount/len[0];
        perpendicular.x*=scale; perpendicular.y*=scale;
    }
    lateral.x=perpendicular.x; lateral.y=self[0x54/4]; lateral.z=perpendicular.y;
    lateralTemp.x=lateral.x; lateralTemp.y=lateral.y; lateralTemp.z=lateral.z;
    self[20]=lateralTemp.x; self[21]=lateralTemp.y; self[22]=lateralTemp.z; self[23]=lateralTemp.w;
    forward.x=self[12]; forward.y=self[13]; forward.z=self[14];
    velocity.x=self[24]; velocity.y=self[25]; velocity.z=self[26];
    right.x=self[4]; right.y=self[5]; right.z=self[6];
    velocity.y=lbl_805639DC*(forward.x*unit.x+forward.z*unit.y);
    height=position.y-((f32 (*)(void *, f32, f32))fn_801DCF48)(&normal,position.x,position.z);
    height=0.0f>height?0.0f:height;
    if(height>lbl_805639E0) {
        a=PSVECDotProduct(&normal,&forward);
        b=-PSVECDotProduct(&normal,&right);
        a3=a*a*a; b3=b*b*b;
        velocity.x=(velocity.x+right.x*a3+forward.x*b3)*lbl_805639E4;
        velocity.y=(velocity.y+right.y*a3+forward.y*b3)*lbl_805639E4;
        velocity.z=(velocity.z+right.z*a3+forward.z*b3)*lbl_805639E4;
    }
    result.x=velocity.x; result.y=velocity.y; result.z=velocity.z;
    self[24]=result.x; self[25]=result.y; self[26]=result.z; self[27]=result.w;
}
#pragma pop

#pragma pop
void fn_80252B88(s32 slotIndex) {
    u8 basis[0x28];
    /* Builds a camera slot's orientation basis and initializes its render
     * state: fills a 3x4 transform with fn_802526E0, then passes it and the
     * 30.0 scale (lbl_805639E8) to fn_801BE400 for the given slot. */
    fn_802526E0(basis);
    fn_801BE400(slotIndex, basis, lbl_805639E8);
}

/* Reset the camera system: release the camera state pools and rewind the next
 * camera slot index to zero. */
void fn_80252BC8(void) {
#define FreeCameraPools fn_801BD790
#define nextCameraSlot lbl_8055F2F8
    FreeCameraPools();
    nextCameraSlot = 0;
#undef FreeCameraPools
#undef nextCameraSlot
}

#pragma scheduling invalid_target
#pragma dont_inline on
/* Allocates the next camera slot, initializes its state, and marks it active. */
void fn_80252BF0(void) {
    u8 scratch[0x138];
    s32 slotIndex = lbl_8055F2F8;
    lbl_8055F2F8 = slotIndex + 1;
    fn_801BD808();
    fn_801BDA70(scratch);
    fn_801BDA74(slotIndex, scratch);
    memset(lbl_80498D00 + slotIndex * 0x78, 0, 0x78);
    fn_80252B88(slotIndex);
    lbl_80498D00[slotIndex * 0x78 + 0x30] = 1;
}
#pragma scheduling on
#pragma dont_inline reset

void fn_80252C78(void) {
    /* Release the most recently allocated camera slot: flag the camera state
     * dirty and rewind the next-slot index by one. */
    #define camerasDirty lbl_8055F308
    #define nextCameraSlot lbl_8055F2F8
    camerasDirty = 1;
    nextCameraSlot -= 1;
    #undef camerasDirty
    #undef nextCameraSlot
}

extern void fn_801BEDA8(int *, int *, int *, int *, int *);
extern void fn_801BEDD4(void);
extern void fn_801BF1B4(void);
extern void fn_8025280C(void *, float);
extern double fn_8002EFB4(float, double);
extern unsigned char lbl_8055F300;
extern double lbl_805639F0;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80252C90(void) {
    int a,b,c,d,count;
    int i,j;
    u8 *dst;
    float phase;
    fn_801BEDA8(&a,&b,&c,&d,&count);
    for (i=0;i<count;i++)
        fn_8025280C((void *)(a+i*0xb0), *(float *)(&lbl_8055F300+4));
    fn_801BEDD4();
    phase = lbl_805639D0;
    dst=lbl_80498D00;
    for(i=0;i<count;i++,dst+=0x78) {
        float *angles=(float *)(b+i*0x1f0);
        float *src=(float *)(a+i*0xb0);
        float *wheel=(float *)(c+i*0x190);
        Vec4_80252 previous; Vec4_80252 current;
        float *out=(float *)dst;
        { float z=src[2], y=src[1], x=src[0]; out[9]=x; out[10]=y; out[11]=z; }
        { float z=src[6], y=src[5], x=src[4]; out[0]=x; out[1]=y; out[2]=z; }
        { float z=src[10], y=src[9], x=src[8]; out[3]=x; out[4]=y; out[5]=z; }
        { float z=src[14], y=src[13], x=src[12]; out[6]=x; out[7]=y; out[8]=z; }
        { float z=src[22], y=src[21], x=src[20]; out[24]=x; out[25]=y; out[26]=z; }
        { float z=src[26], y=src[25], x=src[24]; out[27]=x; out[28]=y; out[29]=z; }
        current=*(Vec4_80252 *)(angles+4);
        previous=*(Vec4_80252 *)angles;
        out[20]=current.x; out[21]=current.y; out[22]=current.z; out[23]=current.w;
        for (j=0;j<4;j++) {
            out[20+j]=(float)fn_8002EFB4(phase+out[20+j],lbl_805639F0);
            out[16+j]=wheel[j*4+1]+((float *)&previous)[j];
        }
        { float w=out[23], z=out[22], y=out[21], x=out[20]; angles[4]=x; angles[5]=y; angles[6]=z; angles[7]=w; }
        dst[0x30]=1;
    }
    fn_801BF1B4();
}
#pragma pop

extern s8 lbl_8055F308;
extern void fn_801BD808(void);
extern void fn_801BDA70(void *);
extern void fn_801BDA74(s32, void *);
extern void fn_80252B88(s32);

extern u8 lbl_80498D00[];
extern void fn_802526E0(void *);
extern void fn_801BE400(s32, void *, f32);
extern f32 lbl_805639E8;
extern f32 lbl_8055F30C, lbl_805639CC, lbl_805639E0, lbl_805639F8;
extern u8 lbl_8055F310;
extern void fn_80252C90(void);
extern void fn_802E30C8(const char *, const char *);
extern const char lbl_803447A8[];
extern const char lbl_8055C120;
/* Fixed-timestep vehicle simulation state, run by fn_80252F50. */
#define gSimTimeOwed      lbl_8055F30C /* banked simulation time still to run, in seconds */
#define gSimTimeoutWarned lbl_8055F310 /* the loop-timeout warning has been logged */
#define kSimStep          0.0192f      /* one simulation step, in seconds */
#define kSimTimeScale     1.5f         /* simulation time banked per unit of frame time */
#define kSimMaxSteps      10           /* steps in one call before the backlog is dropped */
#define kLogFormat        lbl_8055C120 /* "%s": the shared log-line format */
#define kSimTimeoutMsg    lbl_803447A8 /* "minworld: loop timeout!" */
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Run the vehicle simulation in fixed steps.  The frame time, scaled by
 * kSimTimeScale, is banked in gSimTimeOwed and one step (fn_80252C90, which
 * advances every vehicle and refreshes the camera table from it) is run for
 * every kSimStep still owed.  Should that come to more than kSimMaxSteps, the
 * game is running too slowly to keep up: the "minworld: loop timeout!" warning
 * is logged once and the backlog is dropped instead of spiralling further
 * behind.  Called from the minworld update with the frame delta (or a fixed
 * 0.02 s while a replay-style mode is active). */
void fn_80252F50(f32 dt) {
    f32 threshold = 0.0f;
    f32 step = kSimStep;
    s32 steps = 0;
    gSimTimeOwed += kSimTimeScale * dt;
    while (gSimTimeOwed > threshold) {
        fn_80252C90();
        steps++;
        gSimTimeOwed -= step;
        if (steps > kSimMaxSteps) {
            if (!gSimTimeoutWarned) {
                gSimTimeoutWarned = 1;
                ((void (*)(const char *, const char *, ...))fn_802E30C8)((const char *)&kLogFormat, kSimTimeoutMsg);
            }
            gSimTimeOwed = 0.0f;
            break;
        }
    }
}
#pragma pop
// Copies a 0x78-byte entry from lbl_80498D00 (indexed by index) into out.
void fn_80253004(s32 index, void *out) {
    u8 *src = lbl_80498D00 + index * 0x78;
    u8 *dst = out;
    u32 b, a;
    a = *(u32 *)(src + 0); b = *(u32 *)(src + 4); *(u32 *)(dst + 0) = a; *(u32 *)(dst + 4) = b;
    b = *(u32 *)(src + 8); a = *(u32 *)(src + 12); *(u32 *)(dst + 8) = b; *(u32 *)(dst + 12) = a;
    b = *(u32 *)(src + 16); a = *(u32 *)(src + 20); *(u32 *)(dst + 16) = b; *(u32 *)(dst + 20) = a;
    b = *(u32 *)(src + 24); a = *(u32 *)(src + 28); *(u32 *)(dst + 24) = b; *(u32 *)(dst + 28) = a;
    b = *(u32 *)(src + 32); a = *(u32 *)(src + 36); *(u32 *)(dst + 32) = b; *(u32 *)(dst + 36) = a;
    b = *(u32 *)(src + 40); a = *(u32 *)(src + 44); *(u32 *)(dst + 40) = b; *(u32 *)(dst + 44) = a;
    dst[48] = src[48];
    b = *(u32 *)(src + 52); a = *(u32 *)(src + 56); *(u32 *)(dst + 52) = b; *(u32 *)(dst + 56) = a;
    *(u32 *)(dst + 60) = *(u32 *)(src + 60);
    {
        volatile u32 *vsrc = (volatile u32 *)(src + 64);
        volatile u32 *vdst = (volatile u32 *)(dst + 64);
        b = vsrc[0]; a = vsrc[1]; vdst[0] = b; vdst[1] = a;
    }
    b = *(u32 *)(src + 72); a = *(u32 *)(src + 76); *(u32 *)(dst + 72) = b; *(u32 *)(dst + 76) = a;
    b = *(u32 *)(src + 80); a = *(u32 *)(src + 84); *(u32 *)(dst + 80) = b; *(u32 *)(dst + 84) = a;
    b = *(u32 *)(src + 88); a = *(u32 *)(src + 92); *(u32 *)(dst + 88) = b; *(u32 *)(dst + 92) = a;
    {
        volatile u32 *vsrc = (volatile u32 *)(src + 96);
        volatile u32 *vdst = (volatile u32 *)(dst + 96);
        b = vsrc[0]; a = vsrc[1]; vdst[0] = b; vdst[1] = a;
    }
    *(u32 *)(dst + 104) = *(u32 *)(src + 104);
    {
        volatile u32 *vsrc = (volatile u32 *)(src + 108);
        volatile u32 *vdst = (volatile u32 *)(dst + 108);
        b = vsrc[0]; a = vsrc[1]; vdst[0] = b; vdst[1] = a;
    }
    *(u32 *)(dst + 116) = *(u32 *)(src + 116);
}

extern f32 lbl_805639FC;
typedef struct {
    f32 m[12];
} CamBasis80253104;
typedef struct {
    CamBasis80253104 basis;
    u8 flag30;
    u8 pad31[3];
    f32 f34, f38, f3c;
    u8 rest[0x38];
} CamEntry80253104;
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80253104(s32 arg0, void *arg1) {
    CamEntry80253104 *cam = (CamEntry80253104 *)lbl_80498D00;
    CamBasis80253104 basis;
    cam[arg0].f34 = *(volatile f32 *)((u8 *)arg1 + 0x12C);
    cam[arg0].f38 = *(volatile f32 *)((u8 *)arg1 + 0x130);
    cam[arg0].f3c = *(volatile f32 *)((u8 *)arg1 + 0x134);
    fn_801BDA74(arg0, arg1);
    if (cam[arg0].flag30 == 0) {
        fn_80252B88(arg0);
    } else {
        basis = cam[arg0].basis;
        basis.m[10] = lbl_805639FC + ((f32 (*)(void *, f32, f32))fn_801DCF48)(0, basis.m[9], basis.m[11]);
        fn_801BE400(arg0, &basis, lbl_805639E8);
    }
}
extern s8 lbl_8055F308;
extern u8 lbl_80498D00[];
extern f32 lbl_8055F30C, lbl_805639CC, lbl_805639E0, lbl_805639F8, lbl_805639E8;
extern u8 lbl_8055F310;
extern const char lbl_803447A8[];
void fn_801BD808(void);
void fn_801BDA70(void *);
void fn_801BDA74(s32, void *);
void fn_80252B88(s32);
void fn_802526E0(void *);
void fn_801BE400(s32, void *, f32);
void fn_80252C90(void);
void fn_802E30C8(const char *, const char *);

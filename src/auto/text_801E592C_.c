#include <types.h>
#include <revolution/MTX/mtxtypes.h> /* Vec */

extern void *fn_802C6C34(void);
struct Rec14 { s32 v[14]; };
struct SrcHdr { s32 unk[2]; s32 count; s32 unk2; struct Rec14 data[1]; };

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
s32 *fn_801E592C(void) {
    s32 i;
    s32 n;
    void *sp;

    sp = fn_802C6C34();
    n = *(s32 *)((s8 *)sp + 0x10);
    for (i = 0; i < n; i++) {
        s32 *entry = ((s32 ***)sp)[5][i];
        if ((u32)(entry[0] + 0xB2AE0000) == 0x424E) {
            return entry;
        }
    }
    return NULL;
}
#pragma scheduling on
void fn_801E598C(void) {

}

s32 fn_801E5990(void *arg0) {
    return ((s32 *)arg0)[2];
}

#pragma scheduling on
void fn_801E5998(void *src, void *dst, s32 *outCount) {
    s32 count = ((s32 *)src)[2];
    s32 i;
    for (i = 0; i < count; i++) {
        ((struct Rec14 *)dst)[i] = *(struct Rec14 *)((u8 *)src + i * 0x38 + 0x10);
    }
    *outCount = count;
}

void fn_801E5E24(void *arg0, void *arg1, s32 arg2, void *arg3, void *arg4) {
    (void)arg0; (void)arg1; (void)arg2; (void)arg3; (void)arg4;
}

extern void fn_80015B20(void *, void *, void *);
extern void fn_8001BA68(void *);
extern void fn_801BFE7C(void *, void *, void *);
extern void fn_801C0E60(void *, void *, void *);
extern void fn_801C7254(void *, s32, s32, s32, s32, s32, s32, s32);
extern void fn_801E67B4(void *, void *, void *);
extern void fn_802C7A38(s32, void *, s32);
#pragma use_lmw_stmw off
void fn_801E65BC(void *arg0, void *arg1, s32 arg2, void *arg3, s32 arg4) {
    s32 sp68[0x180];
    s32 sp38[12];
    struct Sp14 { s32 pad; s32 v[9]; } sp14box;
    s32 sp8[2];
    register s32 *b;
    register s32 *a;
    register s32 temp;
    register s32 i;
    register s32 idx;
    register s32 count;
    register s32 *base;
    register s32 *dst;
    register s32 *tail;
    s32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11;
    s32 b0, b1, b2, b3, b4, b5, b6, b7, b8;

    count = arg2;
    if (arg3 != 0) {
        a0=((s32 *)arg1)[0]; a1=((s32 *)arg1)[1];
        a2=((s32 *)arg1)[2]; a3=((s32 *)arg1)[3];
        a4=((s32 *)arg1)[4]; a5=((s32 *)arg1)[5];
        a6=((s32 *)arg1)[6]; a7=((s32 *)arg1)[7];
        a8=((s32 *)arg1)[8]; a9=((s32 *)arg1)[9];
        a10=((s32 *)arg1)[10]; a11=((s32 *)arg1)[11];
        ((s32 *)arg3)[0]=a0; ((s32 *)arg3)[1]=a1;
        ((s32 *)arg3)[2]=a2; ((s32 *)arg3)[3]=a3;
        ((s32 *)arg3)[4]=a4; ((s32 *)arg3)[5]=a5;
        ((s32 *)arg3)[6]=a6; ((s32 *)arg3)[7]=a7;
        ((s32 *)arg3)[8]=a8; ((s32 *)arg3)[9]=a9;
        ((s32 *)arg3)[10]=a10; ((s32 *)arg3)[11]=a11;
    }
    temp = ((s32 *)arg0)[3];
    a = (s32 *)arg1;
    b = (s32 *)((u8 *)arg0 + 0x10);
    i = 0;
    while (i < count) {
        idx = b[13];
        if (idx >= 0) {
            a0=a[0]; a1=a[1]; a2=a[2]; a3=a[3];
            a4=a[4]; a5=a[5]; a6=a[6]; a7=a[7];
            a8=a[8]; a9=a[9]; a10=a[10]; a11=a[11];
            b0=b[0]; b1=b[1]; b2=b[2]; b3=b[3];
            b4=b[4]; b5=b[5]; b6=b[6]; b7=b[7]; b8=b[8];
            sp38[0]=a0; sp38[1]=a1; sp38[2]=a2; sp38[3]=a3;
            sp38[4]=a4; sp38[5]=a5; sp38[6]=a6; sp38[7]=a7;
            sp38[8]=a8; sp38[9]=a9; sp38[10]=a10; sp38[11]=a11;
            sp14box.v[0]=b0; sp14box.v[1]=b1; sp14box.v[2]=b2;
            sp14box.v[3]=b3; sp14box.v[4]=b4; sp14box.v[5]=b5;
            sp14box.v[6]=b6; sp14box.v[7]=b7; sp14box.v[8]=b8;
            fn_801C7254(sp14box.v, b7, b6, b5, b4, b3, b2, b1);
            base = &sp68[idx * 12];
            dst = base;
            fn_80015B20(dst, sp38, sp14box.v);
            fn_8001BA68(sp8);
            fn_801E67B4(sp8, b + 9, dst);
            tail = base + 9;
            fn_801C0E60(tail, b + 9, sp8);
            dst = base + 9;
            fn_801BFE7C(tail, dst, &sp38[9]);
            fn_801C0E60(tail, dst, b + 9);
        }
        b += 14;
        a += 12;
        i++;
    }
    fn_802C7A38(0, sp68, temp);
}

#pragma fp_contract off
/* Mtx3MultVec: transform the vector in by the 3x3 matrix m (three rows of three
   floats, out = in * m) and store the result in out.  When out and in are the
   same vector the source is read into registers first, so it is safe to
   transform in place. */
void fn_801E67B4(void *argOut, void *argIn, void *argMtx) {
    float *out = (float *)argOut;
    float *in = (float *)argIn;
    const float *m = (const float *)argMtx;

    if (out == in) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = m[3]; m11 = m[4]; m12 = m[5]; m00 = m[0]; m01 = m[1]; m02 = m[2]; m20 = m[6]; m21 = m[7]; m22 = m[8];
        x = in[0]; y = in[1]; z = in[2];
        out[0] = z * m20 + (x * m00 + y * m10);
        out[1] = z * m21 + (x * m01 + y * m11);
        out[2] = z * m22 + (x * m02 + y * m12);
    } else {
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        float y;
        m10 = m[3]; m00 = m[0]; m20 = m[6]; m11 = m[4]; m01 = m[1]; m21 = m[7]; m12 = m[5]; m02 = m[2]; m22 = m[8];
        out[0] = in[2] * m20 + (in[0] * m00 + in[1] * m10);
        y = in[1];
        out[1] = in[2] * m21 + (in[0] * m01 + y * m11);
        y = in[1];
        out[2] = in[2] * m22 + (in[0] * m02 + y * m12);
    }
}
#pragma fp_contract on

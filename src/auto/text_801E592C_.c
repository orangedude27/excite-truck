#include <types.h>
#include <revolution/MTX/mtxtypes.h> /* Vec */

extern void *fn_802C6C34(void);
extern float fn_80144514(float, float, float, float, float, float);
extern void fn_801BFD34(void *, void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern void fn_802C7A38(s32, void *, s32);
struct Rec14 { s32 v[14]; };
struct Rec8 { s32 v[8][14]; };
struct SrcHdr { s32 unk[2]; s32 count; s32 unk2; struct Rec14 data[1]; };

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
s32 *fn_801E592C(void) {
    s32 i;
    s32 count;
    void *tableBase;
    s32 *entry;

    /* Find the first table entry whose tag dword is 'MRBN' (0x4D52424E). */
    tableBase = fn_802C6C34();
    count = *(s32 *)((s8 *)tableBase + 0x10);
    for (i = 0; i < count; i++) {
        entry = ((s32 ***)tableBase)[5][i];
        if ((u32)(entry[0] + 0xB2AE0000U) == 0x424EU) {
            return entry;
        }
    }
    return NULL;
}
#pragma scheduling on
/* No-op placeholder. */
void fn_801E598C(void) {
}

/* Return the record count stored in the MRBN table header. */
s32 fn_801E5990(void *header) {
    return ((struct SrcHdr *)header)->count;
}

#pragma scheduling on
void fn_801E5998(struct SrcHdr *src, struct Rec14 *dst, s32 *outCount) {
    s32 count = src->count;
    s32 i;
    for (i = 0; i < count; i++) {
        dst[i] = src->data[i];
    }
    *outCount = count;
}

s32 fn_801E5E24(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    float qx, qy, qz, qw;
    float xx2, yy2, zz2, wx2, wy2, wz2, xy2, xz2, yz2;
    float a00, a01, a02, a10, a11, a12, a20, a21, a22;
    float b00, b01, b02;
    float c00, c01, c02, c10, c11, c12, c20, c21, c22;
    float t0, t1, t2;
    float s0, s1, s2;
    float v0, v1, v2;
    float bufA[384];
    float bufB[384];
    float tmpM[12];
    float tmpV[12];
    float tmpR[12];
    s32 i;
    s32 idx;
    s32 *pBase = (s32 *)arg0;
    float *curQ = (float *)arg1;
    s32 count = arg2;
    float *pOut = (float *)arg3;
    float *curRec = (float *)(arg0 + 0x10);
    float *curDst = bufB;
    for (i = 0; i < count; i++) {
        qx = curQ[4];
        qy = curQ[5];
        qz = curQ[6];
        qw = curQ[7];
        xx2 = qx * (qx + qx);
        yy2 = qy * (qy + qy);
        zz2 = qz * (qz + qz);
        xy2 = qx * (qy + qy);
        xz2 = qx * (qz + qz);
        yz2 = qy * (qz + qz);
        wx2 = qw * (qx + qx);
        wy2 = qw * (qy + qy);
        wz2 = qw * (qz + qz);
        m00 = 1.0f - (yy2 + zz2);
        m01 = xy2 - wz2;
        m02 = xz2 + wy2;
        m10 = xy2 + wz2;
        m11 = 1.0f - (xx2 + zz2);
        m12 = yz2 - wx2;
        m20 = xz2 - wy2;
        m21 = yz2 + wx2;
        m22 = 1.0f - (xx2 + yy2);
        idx = ((s32 *)curRec)[12];
        a00 = curRec[0]; a01 = curRec[1]; a02 = curRec[2];
        a10 = curRec[3]; a11 = curRec[4]; a12 = curRec[5];
        a20 = curRec[6]; a21 = curRec[7]; a22 = curRec[8];
        b00 = curRec[9]; b01 = curRec[10]; b02 = curRec[11];
        if (idx < 1) {
            c00 = 1.0f; c01 = 0.0f; c02 = 0.0f;
            c10 = 0.0f; c11 = 1.0f; c12 = 0.0f;
            c20 = 0.0f; c21 = 0.0f; c22 = 1.0f;
        } else {
            float *src = (float *)((u8 *)bufB + idx * 0x30);
            c00 = src[0]; c01 = src[1]; c02 = src[2];
            c10 = src[3]; c11 = src[4]; c12 = src[5];
            c20 = src[6]; c21 = src[7]; c22 = src[8];
        }
        t0 = fn_80144514(m00, a00, m01, a10, m02, a20);
        t1 = fn_80144514(m00, a01, m01, a11, m02, a21);
        t2 = fn_80144514(m00, a02, m01, a12, m02, a22);
        s0 = fn_80144514(m10, a00, m11, a10, m12, a20);
        s1 = fn_80144514(m10, a01, m11, a11, m12, a21);
        s2 = fn_80144514(m10, a02, m11, a12, m12, a22);
        v0 = fn_80144514(m20, a00, m21, a10, m22, a20);
        v1 = fn_80144514(m20, a01, m21, a11, m22, a21);
        v2 = fn_80144514(m20, a02, m21, a12, m22, a22);
        tmpR[0] = t0; tmpR[1] = s0; tmpR[2] = v0;
        tmpR[3] = t1; tmpR[4] = s1; tmpR[5] = v1;
        tmpR[6] = t2; tmpR[7] = s2; tmpR[8] = v2;
        tmpV[0] = (b02 * v2) + ((b00 * t0) + (b01 * s0));
        tmpV[1] = (b02 * s2) + ((b00 * t1) + (b01 * s1));
        tmpV[2] = (b02 * v2) + ((b00 * v0) + (b01 * v1));
        tmpV[0] *= -1.0f; tmpV[1] *= -1.0f; tmpV[2] *= -1.0f;
        fn_801BFD34(tmpM, tmpV, tmpR);
        fn_80015B20(tmpV, tmpR, tmpR);
        fn_801BFD34((void *)((u8 *)curDst + 0x24), tmpM, tmpR);
        fn_80015B20(curDst, tmpV, tmpR);
        curRec += 14;
        curQ += 4;
        curDst += 12;
    }
    if (pOut != 0) {
        for (i = 0; i < 12; i++) ((s32 *)pOut)[i] = ((s32 *)bufB)[i];
    }
    {
        s32 n = pBase[3];
        float *src = bufB;
        s32 k;
        s32 base = arg0;
        for (k = 0; k < count; k++) {
            s32 id = *(s32 *)(base + 0x44);
            if (id >= 0) {
                float *dst = (float *)((u8 *)bufA + id * 0x30);
                dst[0]=src[0]; dst[1]=src[1]; dst[2]=src[2]; dst[3]=src[3];
                dst[4]=src[4]; dst[5]=src[5]; dst[6]=src[6]; dst[7]=src[7];
                dst[8]=src[8]; dst[9]=src[9]; dst[10]=src[10]; dst[11]=src[11];
            }
            base += 0x38;
            src += 12;
        }
        fn_802C7A38(0, bufA, n);
    }
    return 0;
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
    s32 a10, a9, a8, a7, a6, a5, a4, a1, a0, a2, a3, a11;
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
/* Mtx3MultVec: transform the vector in by the 3x3 matrix m (three rows of three
   floats, out = in * m) and store the result in out.  When out and in are the
   same vector the source is read into registers first, so it is safe to
   transform in place. */
void fn_801E67B4(void *argOut, void *argIn, void *argMtx) {
    Vec *out = (Vec *)argOut;
    float *in = (float *)argIn;
    const float *m = (const float *)argMtx;

    if (out == (Vec *)argIn) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = m[3]; m11 = m[4]; m12 = m[5]; m00 = m[0]; m01 = m[1]; m02 = m[2]; m20 = m[6]; m21 = m[7]; m22 = m[8];
        x = in[0]; y = in[1]; z = in[2];
        out->x = z * m20 + (x * m00 + y * m10);
        out->y = z * m21 + (x * m01 + y * m11);
        out->z = z * m22 + (x * m02 + y * m12);
    } else {
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        float y;
        m10 = m[3]; m00 = m[0]; m20 = m[6]; m11 = m[4]; m01 = m[1]; m21 = m[7]; m12 = m[5]; m02 = m[2]; m22 = m[8];
        out->x = in[2] * m20 + (in[0] * m00 + in[1] * m10);
        y = in[1];
        out->y = in[2] * m21 + (in[0] * m01 + y * m11);
        y = in[1];
        out->z = in[2] * m22 + (in[0] * m02 + y * m12);
    }
}
#pragma fp_contract on

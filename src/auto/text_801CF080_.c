#include "types.h"

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <math.h>
extern float PSVECDotProduct(const float *, const float *);
typedef struct { f32 x, y, z; } Vec801CF;
extern f32 lbl_80558DC4[];
extern f32 lbl_80562A38, lbl_80562A3C;
extern float PSVECSquareDistance(const float *, const float *);

static inline void fn_801CF080_xform(f32 *dst, f32 *src, f32 *m) {
    if (dst == src) {
        f32 x = src[0], y = src[1], z = src[2];
        dst[0] = x * m[0] + y * m[3] + z * m[6];
        dst[1] = x * m[1] + y * m[4] + z * m[7];
        dst[2] = x * m[2] + y * m[5] + z * m[8];
    } else {
        dst[0] = src[0] * m[0] + src[1] * m[3] + src[2] * m[6];
        dst[1] = src[0] * m[1] + src[1] * m[4] + src[2] * m[7];
        dst[2] = src[0] * m[2] + src[1] * m[5] + src[2] * m[8];
    }
}

static inline void fn_801CF080_rot(f32 *v, f32 *m) {
    f32 x = v[0], y = v[1], z = v[2];
    v[0] = x * m[0] + y * m[1] + z * m[2];
    v[1] = x * m[3] + y * m[4] + z * m[5];
    v[2] = x * m[6] + y * m[7] + z * m[8];
}

#pragma dont_inline on
#pragma scheduling invalid_target
#pragma dont_inline reset
#pragma scheduling reset
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801CF080(u8 *mesh, f32 *pos, f32 *out, s32 *count, f32 *mtx, f32 radius) {
    Vec801CF local;
    Vec801CF cp;
    f32 zero;
    s32 n;
    s32 maxCount;
    s32 node;
    s32 nodeOff;

    if (mtx != 0) {
        local.x = pos[0] - mtx[9];
        local.y = pos[1] - mtx[10];
        local.z = pos[2] - mtx[11];
        fn_801CF080_rot((f32 *)&local, mtx);
    } else {
        local.x = pos[0];
        local.y = pos[1];
        local.z = pos[2];
    }
    maxCount = *count;
    zero = lbl_80562A38;
    n = 0;
    for (node = 0, nodeOff = 0; node < *(s32 *)(mesh + 4); node++, nodeOff += 0x18) {
        u8 *nd = *(u8 **)mesh + nodeOff;
        f32 sq;
        f32 rr;
        s32 t;
        s32 triOff;
        sq = PSVECSquareDistance((f32 *)nd, (f32 *)&local);
        rr = *(f32 *)(nd + 0xC) + radius;
        if (sq > rr * rr) {
            continue;
        }
        t = *(s32 *)(nd + 0x10);
        triOff = t * 0x3C;
        for (; t < *(s32 *)(nd + 0x14); t++, triOff += 0x3C) {
            u8 *tri = *(u8 **)(mesh + 0x10) + triOff;
            f32 dist = *(f32 *)(tri + 0x14) - PSVECDotProduct((f32 *)&local, (f32 *)(tri + 8));
            f32 ad = -dist;
            f32 *edge;
            Vec801CF proj;
            f32 p[3][3];
            f32 d[3];
            s32 outs[3];
            s32 k;
            s32 nout;
            s32 last;
            u16 flags;
            f32 *pp;
            f32 *pe;
            f32 *dp;
            if (ad > radius || ad < zero) {
                continue;
            }
            edge = (f32 *)(tri + 0x18);
            proj.x = local.x + *(f32 *)(tri + 8) * dist;
            proj.y = local.y + *(f32 *)(tri + 0xC) * dist;
            proj.z = local.z + *(f32 *)(tri + 0x10) * dist;
            {
                f32 *v0 = (f32 *)(*(u8 **)(mesh + 8) + *(s16 *)(tri + 2) * 0xC);
                f32 *v1 = (f32 *)(*(u8 **)(mesh + 8) + *(s16 *)(tri + 4) * 0xC);
                f32 *v2 = (f32 *)(*(u8 **)(mesh + 8) + *(s16 *)(tri + 6) * 0xC);
                p[0][0] = v0[0]; p[0][1] = v0[1]; p[0][2] = v0[2];
                p[1][0] = v1[0]; p[1][1] = v1[1]; p[1][2] = v1[2];
                p[2][0] = v2[0]; p[2][1] = v2[1]; p[2][2] = v2[2];
            }
            nout = 0;
            last = -1;
            pp = p[0];
            pe = edge;
            dp = d;
            for (k = 0; k < 3; k++) {
                f32 e[3];
                f32 dd;
                e[0] = (f32)proj.x - pp[0];
                e[1] = (f32)proj.y - pp[1];
                e[2] = (f32)proj.z - pp[2];
                dd = PSVECDotProduct(e, pe);
                if (dd > radius) {
                    goto next;
                }
                if (dd >= zero) {
                    outs[nout] = k;
                    nout++;
                } else {
                    last = k;
                }
                *dp = dd;
                pp += 3;
                pe += 3;
                dp++;
            }
            if (nout == 3) {
                goto next;
            }
            flags = *(u16 *)tri;
            cp = proj;
            if (nout == 1) {
                s32 o = outs[0];
                s32 nx;
                Vec801CF a, b;
                f32 s = -d[o];
                f32 dAB, dA, dB;
                cp.x = proj.x + edge[o * 3] * s;
                nx = (o + 1) % 3;
                cp.y = proj.y + edge[o * 3 + 1] * s;
                a = *(Vec801CF *)p[o];
                b = *(Vec801CF *)p[nx];
                cp.z = proj.z + edge[o * 3 + 2] * s;
                dAB = PSVECSquareDistance((f32 *)&a, (f32 *)&b);
                dA = PSVECSquareDistance((f32 *)&cp, (f32 *)&a);
                dB = PSVECSquareDistance((f32 *)&cp, (f32 *)&b);
                if (dA > dAB) {
                    last = nx - 2;
                    nout = 2;
                } else if (dB > dAB) {
                    nout = 2;
                    last = o - 2;
                }
            }
            if (nout == 0) {
                cp.x = proj.x;
                cp.y = proj.y;
                cp.z = proj.z;
            } else if (nout == 2) {
                s32 m = (last + 2) % 3;
                if (!(flags & (1 << m))) {
                    goto next;
                }
                cp.x = p[m][0];
                cp.y = p[m][1];
                cp.z = p[m][2];
            } else if (nout == 1) {
                s32 o = outs[0];
                f32 s;
                if (!(flags & (1 << (o + 3)))) {
                    goto next;
                }
                s = -d[o];
                cp.x = proj.x + edge[o * 3] * s;
                cp.y = proj.y + edge[o * 3 + 1] * s;
                cp.z = proj.z + edge[o * 3 + 2] * s;
            }
            if (PSVECSquareDistance((f32 *)&cp, (f32 *)&local) < radius * radius && n < maxCount) {
                Vec801CF res;
                f32 *dst;
                if (mtx != 0) {
                    fn_801CF080_xform((f32 *)&res, (f32 *)&cp, mtx);
                    res.x += mtx[9];
                    res.y += mtx[10];
                    res.z += mtx[11];
                } else {
                    res.x = cp.x;
                    res.y = cp.y;
                    res.z = cp.z;
                }
                dst = out + n * 3;
                dst[0] = res.x;
                dst[1] = res.y;
                dst[2] = res.z;
                n++;
            }
        next:;
        }
    }
    *count = n;
}

#pragma pop
#pragma dont_inline on
#pragma scheduling invalid_target
f32 fn_801CF778(const float *point, const float *origin, const float *dir) {
    /* Returns the squared length of (point - origin) perpendicular to dir. */
    float delta[3];
    float dot;

    delta[0] = point[0] - origin[0];
    delta[1] = point[1] - origin[1];
    delta[2] = point[2] - origin[2];
    dot = -PSVECDotProduct(delta, dir);
    delta[0] += dir[0] * dot;
    delta[1] += dir[1] * dot;
    delta[2] += dir[2] * dot;
    return PSVECDotProduct(delta, delta);
}
#pragma dont_inline reset

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
s32 fn_801CF828(u8 *arg0, f32 *origin, f32 *dir, f32 *dist, f32 *out) {
    f32 *nrm;
    s32 n;
    s32 toff;
    f32 *edge;
    s32 hit;
    s32 off;
    u8 *node;
    s32 t;
    s32 k;
    s32 inside;
    u8 *tri;
    f32 zero = lbl_80562A38;
    f32 eps = lbl_80562A3C;
    hit = 0;
    off = 0;
    for (n = 0; n < *(s32 *)(arg0 + 4); n++, off += 0x18) {
        f32 r2;
        node = *(u8 **)arg0 + off;
        r2 = *(f32 *)(node + 0xC) * *(f32 *)(node + 0xC);
        if (fn_801CF778((f32 *)node, origin, dir) > r2) {
            continue;
        }
        t = *(s32 *)(node + 0x10);
        toff = t * 0x3C;
        for (; t < *(s32 *)(node + 0x14); t++, toff += 0x3C) {
            f32 d;
            f32 den;
            f32 u;
            tri = *(u8 **)(arg0 + 0x10) + toff;
            nrm = (f32 *)(tri + 8);
            d = *(f32 *)(tri + 0x14);
            den = PSVECDotProduct(dir, nrm);
            if ((f32)fabs(den) < eps) {
                continue;
            }
            u = (d - PSVECDotProduct(origin, nrm)) / den;
            if (u >= zero && u < *dist) {
                f32 pt[3];
                Vec801CF v;
                Vec801CF diff;
                s16 *ip = (s16 *)tri;
                edge = (f32 *)(tri + 0x18);
                inside = 1;
                pt[0] = origin[0] + dir[0] * u;
                pt[1] = origin[1] + dir[1] * u;
                pt[2] = origin[2] + dir[2] * u;
                for (k = 0; k < 3; k++) {
                    v = *(Vec801CF *)(*(u8 **)(arg0 + 8) + ip[1] * 0xC);
                    diff.x = pt[0] - v.x;
                    diff.y = pt[1] - v.y;
                    diff.z = pt[2] - v.z;
                    if (PSVECDotProduct((f32 *)&diff, edge) > lbl_80558DC4[0]) {
                        inside = 0;
                    }
                    ip++;
                    edge += 3;
                }
                if (inside) {
                    *dist = u;
                    hit = 1;
                    out[0] = nrm[0];
                    out[1] = nrm[1];
                    out[2] = nrm[2];
                }
            }
        }
    }
    return hit;
}
#pragma pop
void fn_801CFA48(void *arg0) {
 typedef struct { unsigned char *ptr1; int count1; unsigned char *ptr2; int count2; unsigned char *ptr3; int count3; } tFA48View;
 volatile unsigned char *b=(volatile unsigned char *)arg0;
 unsigned char temp;
 volatile unsigned char *base,*item;
 int offset,i1,i2,i3,count1,count2;
 temp=b[0]; item=b+0x18; i1=0; offset=0; b[0]=b[3]; b[3]=temp;
        temp=b[1]; b[1]=b[2]; b[2]=temp;
        temp=b[4]; b[4]=b[7]; b[7]=temp;
        temp=b[5]; b[5]=b[6]; b[6]=temp;
        temp=b[8]; b[8]=b[11]; b[11]=temp;
        temp=b[9]; b[9]=b[10]; b[10]=temp;
        temp=b[12]; b[12]=b[15]; b[15]=temp;
        temp=b[13]; b[13]=b[14]; b[14]=temp;
        temp=b[16]; b[16]=b[19]; b[19]=temp;
        temp=b[17]; b[17]=b[18]; b[18]=temp;
        temp=b[20]; b[20]=b[23]; b[23]=temp;
        temp=b[21]; b[21]=b[22]; b[22]=temp;
 count1=((volatile tFA48View *)b)->count1; count2=((volatile tFA48View *)b)->count2; count1*=0x18; ((volatile tFA48View *)b)->ptr1=(unsigned char *)item; item+=count1; ((volatile tFA48View *)b)->ptr2=(unsigned char *)item; count2*=0xC; item+=count2; ((volatile tFA48View *)b)->ptr3=(unsigned char *)item;
 goto check1;
loop1:
 base=((volatile tFA48View *)b)->ptr1; i1++; item=base+offset; temp=base[offset]; offset+=0x18; item[0]=item[3]; item[3]=temp;
        temp=item[1]; item[1]=item[2]; item[2]=temp;
        temp=item[4]; item[4]=item[7]; item[7]=temp;
        temp=item[5]; item[5]=item[6]; item[6]=temp;
        temp=item[8]; item[8]=item[11]; item[11]=temp;
        temp=item[9]; item[9]=item[10]; item[10]=temp;
        temp=item[12]; item[12]=item[15]; item[15]=temp;
        temp=item[13]; item[13]=item[14]; item[14]=temp;
        temp=item[16]; item[16]=item[19]; item[19]=temp;
        temp=item[17]; item[17]=item[18]; item[18]=temp;
        temp=item[20]; item[20]=item[23]; item[23]=temp;
        temp=item[21]; item[21]=item[22]; item[22]=temp;
check1:
 if(i1<((volatile tFA48View *)b)->count1) goto loop1;
 i2=0; offset=0; goto check2;
loop2:
 base=((volatile tFA48View *)b)->ptr2; i2++; item=base+offset; temp=base[offset]; offset+=0xC; item[0]=item[3]; item[3]=temp;
        temp=item[1]; item[1]=item[2]; item[2]=temp;
        temp=item[4]; item[4]=item[7]; item[7]=temp;
        temp=item[5]; item[5]=item[6]; item[6]=temp;
        temp=item[8]; item[8]=item[11]; item[11]=temp;
        temp=item[9]; item[9]=item[10]; item[10]=temp;
check2:
 if(i2<((volatile tFA48View *)b)->count2) goto loop2;
 i3=0; offset=0; goto check3;
loop3:
 base=((volatile tFA48View *)b)->ptr3; item=base+offset; temp=base[offset]; item[0]=item[1]; item[1]=temp; temp=item[2]; item[2]=item[3]; item[3]=temp;
        temp=item[24]; item[24]=item[27]; item[27]=temp;
        temp=item[25]; item[25]=item[26]; item[26]=temp;
        temp=item[28]; item[28]=item[31]; item[31]=temp;
        temp=item[29]; item[29]=item[30]; item[30]=temp;
        temp=item[32]; item[32]=item[35]; item[35]=temp;
        temp=item[33]; item[33]=item[34]; item[34]=temp;
        temp=item[4]; item[4]=item[5]; item[5]=temp;
        temp=item[36]; item[36]=item[39]; item[39]=temp;
        temp=item[37]; item[37]=item[38]; item[38]=temp;
        temp=item[40]; item[40]=item[43]; item[43]=temp;
        temp=item[41]; item[41]=item[42]; item[42]=temp;
        temp=item[44]; item[44]=item[47]; item[47]=temp;
        temp=item[45]; item[45]=item[46]; item[46]=temp;
        temp=item[6]; item[6]=item[7]; item[7]=temp;
        temp=item[48]; item[48]=item[51]; item[51]=temp;
        temp=item[49]; item[49]=item[50]; item[50]=temp;
        temp=item[52]; item[52]=item[55]; item[55]=temp;
        temp=item[53]; item[53]=item[54]; item[54]=temp;
        temp=item[56]; item[56]=item[59]; item[59]=temp;
        temp=item[57]; item[57]=item[58]; item[58]=temp;
 temp=item[8]; offset+=0x3C; i3++; item[8]=item[0xB]; item[0xB]=temp;
        temp=item[9]; item[9]=item[10]; item[10]=temp;
        temp=item[12]; item[12]=item[15]; item[15]=temp;
        temp=item[13]; item[13]=item[14]; item[14]=temp;
        temp=item[16]; item[16]=item[19]; item[19]=temp;
        temp=item[17]; item[17]=item[18]; item[18]=temp;
        temp=item[20]; item[20]=item[23]; item[23]=temp;
        temp=item[21]; item[21]=item[22]; item[22]=temp;
check3:
 if(i3<((volatile tFA48View *)b)->count3) goto loop3;
}

extern s32 fn_8012C370(s32, s32 *, s32, s32, u8 *);
extern void fn_801CFA48(void *);
#pragma scheduling invalid_target
void *fn_801CFEAC(void *arg0) {
    s32 spC;
    u8 sp8;
    void *res;

    spC = 1;
    sp8 = 0;
    res = ((void *(*)(void *, s32, s32 *, s32, s32, u8 *))fn_8012C370)(arg0, 0x504D7368, &spC, 0, 0, &sp8);
    if (sp8 != 0) {
        fn_801CFA48(res);
    }
    return res;
}
#pragma scheduling on
void fn_801CFF14(void) {
    fn_8012C4D8();
}

extern void fn_802C8B08(float *);
extern void PSVECCrossProduct(const float *, const float *, float *);

extern void fn_801E41D8(void *, void *, int, float);
extern float lbl_80562A38;
extern float lbl_80562A40;
extern float lbl_80562A44;
#pragma scheduling invalid_target
void fn_801CFF18(void *arg0, float *arg1) {
    unsigned int m[12];
    float scratch[12];
    float points[3][3];
    float tz, ty, tx;
    int offset, i;

    if (arg1 != 0) {
        unsigned int *src = (unsigned int *)arg1;
        m[0] = src[0]; m[1] = src[1]; m[2] = src[2]; m[3] = src[3];
        m[4] = src[4]; m[5] = src[5]; m[6] = src[6]; m[7] = src[7];
        m[8] = src[8]; m[9] = src[9]; m[10] = src[10]; m[11] = src[11];
    } else {
        float zero = lbl_80562A38;
        float one = lbl_80562A40;
        ((float *)m)[1] = zero;
        ((float *)m)[0] = one;
        ((float *)m)[2] = zero;
        ((float *)m)[3] = zero;
        ((float *)m)[4] = one;
        ((float *)m)[5] = zero;
        ((float *)m)[6] = zero;
        ((float *)m)[7] = zero;
        ((float *)m)[8] = one;
        ((float *)m)[9] = zero;
        ((float *)m)[10] = zero;
        ((float *)m)[11] = zero;
    }
    fn_802C8B08(scratch);
    tx = ((float *)m)[9];
    ty = ((float *)m)[10];
    tz = ((float *)m)[11];

    for (i = 0, offset = 0; i < *(int *)((char *)arg0 + 0x14); offset += 0x3C, i++) {
        char *index = (char *)*(void **)((char *)arg0 + 0x10) + offset;
        float *dst = &points[0][0];
        int j;
        for (j = 0; j < 3; j++) {
            int indexValue = *(short *)(index + 2);
            char *vertices = *(char **)((char *)arg0 + 8);
            float *src = (float *)(vertices + indexValue * 0xC);
            float *matrix = (float *)m;
            if (dst == src) {
                float x = matrix[3] * src[1] + matrix[0] * src[0] + matrix[6] * src[2];
                float y = matrix[4] * src[1] + matrix[1] * src[0] + matrix[7] * src[2];
                float z = matrix[5] * src[1] + matrix[2] * src[0] + matrix[8] * src[2];
                dst[0] = x;
                dst[1] = y;
                dst[2] = z;
            } else {
                dst[0] = matrix[3] * src[1] + matrix[0] * src[0] + matrix[6] * src[2];
                dst[1] = matrix[4] * src[1] + matrix[1] * src[0] + matrix[7] * src[2];
                dst[2] = matrix[5] * src[1] + matrix[2] * src[0] + matrix[8] * src[2];
            }
            dst[0] += tx;
            dst[1] += ty;
            dst[2] += tz;
            index += 2;
            dst += 3;
        }

        {
            float v1[3], v2[3], normal[3], eye[3];
            v1[0] = points[1][0] - points[0][0];
            v1[1] = points[1][1] - points[0][1];
            v1[2] = points[1][2] - points[0][2];
            v2[0] = points[2][0] - points[0][0];
            v2[1] = points[2][1] - points[0][1];
            v2[2] = points[2][2] - points[0][2];
            PSVECCrossProduct(v1, v2, normal);
            eye[0] = points[0][0] - scratch[9];
            eye[1] = points[0][1] - scratch[10];
            eye[2] = points[0][2] - scratch[11];
            if (!(PSVECDotProduct(normal, eye) > lbl_80562A38)) {
                fn_801E41D8(points[0], points[1], 0x80FFFF00, lbl_80562A44);
                fn_801E41D8(points[1], points[2], 0x80FFFF00, lbl_80562A44);
                fn_801E41D8(points[2], points[0], 0x80FFFF00, lbl_80562A44);
            }
        }
    }
}

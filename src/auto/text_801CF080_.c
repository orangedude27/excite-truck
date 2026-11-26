#include "types.h"

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <math.h>
#include <revolution/MTX/mtxtypes.h> /* Vec */
extern float PSVECDotProduct(const float *, const float *);
typedef Vec Vec801CF;
extern f32 lbl_80558DC4[]; /* [0] = 2^-23: "outside the triangle" tolerance */
extern f32 lbl_80562A38, lbl_80562A3C; /* 0.0f and 0.001f */
extern float PSVECSquareDistance(const float *, const float *);

/* 'PMSh' triangle mesh, read from "track.msh" by fn_801CFEAC; fn_801CFA48
 * byte-swaps this header and the three arrays it points at in place. */
typedef struct MeshNode {
    /* 0x00 */ Vec center;   /* bounding sphere centre */
    /* 0x0C */ f32 radius;   /* bounding sphere radius */
    /* 0x10 */ s32 triStart; /* first triangle of this node in Mesh::tris */
    /* 0x14 */ s32 triEnd;   /* one past the last */
} MeshNode; /* 0x18 */

typedef struct MeshTri {
    /* 0x00 */ u16 edgeFlags;     /* bit k: corner k may be a closest point;
                                   * bit 3+k: edge k may be one */
    /* 0x02 */ s16 vidx[3];       /* corners, indices into Mesh::verts */
    /* 0x08 */ Vec normal;        /* plane normal */
    /* 0x14 */ f32 planeDist;     /* dot(normal, corner) */
    /* 0x18 */ Vec edgeNormal[3]; /* inward normal of the edge plane through
                                   * corner k, used to test a point against the
                                   * triangle (fn_801CF080, fn_801CF828) */
} MeshTri; /* 0x3C */

typedef struct Mesh {
    /* 0x00 */ MeshNode *nodes;
    /* 0x04 */ s32 nodeCount;
    /* 0x08 */ Vec *verts;
    /* 0x0C */ s32 vertCount;
    /* 0x10 */ MeshTri *tris;
    /* 0x14 */ s32 triCount;
} Mesh; /* 0x18 */

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
/* Ray-cast a mesh (MeshRayCast): for every node whose bounding sphere the ray
 * passes through, intersect the ray with each triangle plane and keep the hits
 * that are inside all three edge planes.  Returns 1, shortens *ioDist to the
 * distance of the closest such hit and writes the plane normal of the triangle
 * it hit to normalOut; returns 0 when the ray misses the mesh. */
s32 fn_801CF828(Mesh *mesh, Vec *origin, Vec *dir, f32 *ioDist, Vec *normalOut) {
    Vec *nrm;
    s32 nodeOff;
    s32 triOff;
    Vec *edge;
    s32 hit;
    s32 n;
    MeshNode *node;
    s32 t;
    MeshTri *tri;
    f32 zero = lbl_80562A38;
    f32 eps = lbl_80562A3C;
    hit = 0;
    for (n = 0, nodeOff = 0; n < mesh->nodeCount; nodeOff += 0x18, n++) {
        f32 radiusSq;
        node = (MeshNode *)((u8 *)mesh->nodes + nodeOff);
        radiusSq = node->radius * node->radius;
        if (fn_801CF778((f32 *)&node->center, (f32 *)origin, (f32 *)dir) > radiusSq) {
            continue;
        }
        t = node->triStart;
        triOff = t * 0x3C;
        for (; t < node->triEnd; triOff += 0x3C, t++) {
            f32 planeDist;
            f32 denom;
            f32 dist;
            tri = (MeshTri *)((u8 *)mesh->tris + triOff);
            nrm = &tri->normal;
            planeDist = tri->planeDist;
            denom = PSVECDotProduct((f32 *)dir, (f32 *)nrm);
            if ((f32)fabs(denom) < eps) {
                continue;
            }
            dist = (planeDist - PSVECDotProduct((f32 *)origin, (f32 *)nrm)) / denom;
            if (dist >= zero && dist < *ioDist) {
                Vec point;
                Vec vert;
                Vec toPoint;
                s16 *vidx = (s16 *)tri; /* vidx[1]..vidx[3] are tri->vidx[0..2] */
                s32 inside;
                s32 k;
                edge = tri->edgeNormal;
                inside = 1;
                point.x = origin->x + dir->x * dist;
                point.y = origin->y + dir->y * dist;
                point.z = origin->z + dir->z * dist;
                for (k = 0; k < 3; k++) {
                    vert = mesh->verts[vidx[1]];
                    toPoint.x = point.x - vert.x;
                    toPoint.y = point.y - vert.y;
                    toPoint.z = point.z - vert.z;
                    if (PSVECDotProduct((f32 *)&toPoint, (f32 *)edge) > lbl_80558DC4[0]) {
                        inside = 0;
                    }
                    vidx++;
                    edge++;
                }
                if (inside) {
                    *ioDist = dist;
                    hit = 1;
                    normalOut->x = nrm->x;
                    normalOut->y = nrm->y;
                    normalOut->z = nrm->z;
                }
            }
        }
    }
    return hit;
}
#pragma pop
/* In-place byte swaps used to convert the big-endian mesh file. */
static inline void Mesh_SwapByte(volatile u8 *a, volatile u8 *b) {
    u8 t = *a;
    *a = *b;
    *b = t;
}

static inline void Mesh_Swap32(volatile void *p) {
    volatile u8 *b = (volatile u8 *)p;
    Mesh_SwapByte(&b[0], &b[3]);
    Mesh_SwapByte(&b[1], &b[2]);
}

static inline void Mesh_Swap16(volatile void *p) {
    volatile u8 *b = (volatile u8 *)p;
    Mesh_SwapByte(&b[0], &b[1]);
}

static inline void Mesh_SwapVec(volatile Vec *v) {
    Mesh_Swap32(&v->x);
    Mesh_Swap32(&v->y);
    Mesh_Swap32(&v->z);
}

#pragma push
void fn_801CFA48(void *arg0) {
    s32 i;
    s32 off;
    MeshNode *nodes;
    Vec *verts;
    volatile Mesh *mesh = (volatile Mesh *)arg0;

    Mesh_Swap32(&mesh->nodes);
    Mesh_Swap32(&mesh->nodeCount);
    Mesh_Swap32(&mesh->verts);
    Mesh_Swap32(&mesh->vertCount);
    Mesh_Swap32(&mesh->tris);
    Mesh_Swap32(&mesh->triCount);
    nodes = (MeshNode *)((u8 *)arg0 + sizeof(Mesh));
    {
        s32 nodeCount = mesh->nodeCount;
        s32 vertCount = mesh->vertCount;
        mesh->nodes = nodes;
        verts = (Vec *)(nodes + nodeCount);
        mesh->verts = verts;
        mesh->tris = (MeshTri *)(verts + vertCount);
    }

    for (i = 0, off = 0; i < mesh->nodeCount; i++, off += sizeof(MeshNode)) {
        volatile MeshNode *node = (volatile MeshNode *)((u8 *)mesh->nodes + off);
        Mesh_SwapVec(&node->center);
        Mesh_Swap32(&node->radius);
        Mesh_Swap32(&node->triStart);
        Mesh_Swap32(&node->triEnd);
    }
    for (i = 0, off = 0; i < mesh->vertCount; i++, off += sizeof(Vec)) {
        Mesh_SwapVec((volatile Vec *)((u8 *)mesh->verts + off));
    }
    for (i = 0, off = 0; i < mesh->triCount; i++, off += sizeof(MeshTri)) {
        volatile MeshTri *tri = (volatile MeshTri *)((u8 *)mesh->tris + off);
        Mesh_Swap16(&tri->edgeFlags);
        Mesh_Swap16(&tri->vidx[0]);
        Mesh_SwapVec(&tri->edgeNormal[0]);
        Mesh_Swap16(&tri->vidx[1]);
        Mesh_SwapVec(&tri->edgeNormal[1]);
        Mesh_Swap16(&tri->vidx[2]);
        Mesh_SwapVec(&tri->edgeNormal[2]);
        Mesh_SwapVec(&tri->normal);
        Mesh_Swap32(&tri->planeDist);
    }
}
#pragma pop


extern s32 getResourceData(s32, s32 *, s32, s32, u8 *);
extern void fn_801CFA48(void *);
#pragma scheduling invalid_target
/* Load a 'PMsh' mesh resource via getResourceData and byte-swap its header/arrays in place if a swap is requested. */
void *fn_801CFEAC(void *path) {
    s32 outValue;
    u8 needsSwap;
    void *mesh;

    outValue = 1;
    needsSwap = 0;
    mesh = ((void *(*)(void *, s32, s32 *, s32, s32, u8 *))getResourceData)(path, 0x504D7368, &outValue, 0, 0, &needsSwap);
    if (needsSwap != 0) {
        fn_801CFA48(mesh);
    }
    return mesh;
}
#pragma scheduling on
/* Release a resource reference (tail-calls the resource manager's release path). */
void fn_801CFF14(void) {
    releaseResource();
}

extern void DrawList_copyCurrentMatrix(float *);
extern void PSVECCrossProduct(const float *, const float *, float *);

extern void fn_801E41D8(void *, void *, int, float);
extern float lbl_80562A38;
extern float lbl_80562A40;
extern float lbl_80562A44;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801CFF18(void *arg0, float *arg1)
{
  unsigned int m[12];
  float scratch[12];
  float points[3][3];
  float tz;
  float ty;
  float tx;
  float threshold;
  float new_var;
  int offset;
  int i;
  if (arg1 != 0)
  {
    unsigned int *src = (unsigned int *) arg1;
    m[0] = src[0];
    m[1] = src[1];
    m[2] = src[2];
    m[3] = src[3];
    m[4] = src[4];
    m[5] = src[5];
    m[6] = src[6];
    m[7] = src[7];
    m[8] = src[8];
    m[9] = src[9];
    m[10] = src[10];
    m[11] = src[11];
  }
  else
  {
    float zero = lbl_80562A38;
    float one = lbl_80562A40;
    ((float *) m)[1] = zero;
    ((float *) m)[0] = lbl_80562A40;
    ((float *) m)[2] = zero;
    ((float *) m)[3] = zero;
    ((float *) m)[4] = one;
    ((float *) m)[5] = zero;
    ((float *) m)[6] = zero;
    ((float *) m)[7] = zero;
    ((float *) m)[8] = lbl_80562A40;
    ((float *) m)[9] = zero;
    ((float *) m)[10] = zero;
    ((float *) m)[11] = zero;
  }
  DrawList_copyCurrentMatrix(scratch);
  tx = ((float *) m)[9];
  ty = ((float *) m)[10];
  tz = ((float *) m)[11];
  threshold = 0.0f;
  for (i = 0, offset = 0; i < (*((int *) (((char *) arg0) + 0x14))); offset += 0x3C, i++)
  {
    char *index = ((char *) (*((void **) (((char *) arg0) + 0x10)))) + offset;
    float *dst = &points[0][0];
    int j;
    for (j = 0; j < 3; j++)
    {
      int indexValue = *((short *) (index - -2));
      char *vertices = *((char **) (((char *) arg0) + 8));
      float *src = (float *) (vertices + (indexValue * 0xC));
      float *matrix = (float *) m;
      if (dst == src)
      {
        float m10, x, m00, y, m11, m20, z, m01, m21, m02, m12, m22;
        m10 = matrix[3];
        y = src[1];
        m00 = matrix[0];
        x = src[0];
        m11 = matrix[4];
        m20 = matrix[6];
        z = src[2];
        m01 = matrix[1];
        m21 = matrix[7];
        m12 = matrix[5];
        m22 = matrix[8];
        dst[0] = (z * m20) + ((x * m00) + (y * m10));
        dst[1] = (z * m21) + ((x * m01) + (y * m11));
        m02 = matrix[2];
        dst[2] = (z * m22) + ((x * m02) + (y * m12));
      }
      else
      {
        float y, x, m00, m10, m20, z;
        m10 = matrix[3];
        y = src[1];
        m00 = matrix[0];
        x = src[0];
        m20 = matrix[6];
        z = src[2];
        new_var = matrix[8];
        dst[0] = (z * m20) + ((x * m00) + (y * m10));
        dst[1] = ((matrix[4] * src[1]) + (matrix[1] * src[0])) + (matrix[7] * src[2]);
        dst[2] = ((matrix[5] * src[1]) + (matrix[2] * src[0])) + (new_var * src[2]);
      }
      dst[0] += tx;
      dst[1] += ty;
      dst[2] += tz;
      index += 2;
      dst += 3;
    }

    {
      float v1[3];
      float v2[3];
      float normal[3];
      float eye[3];
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
      if (!(PSVECDotProduct(normal, eye) > threshold))
      {
        fn_801E41D8(points[0], points[1], 0x80FFFF00, lbl_80562A44);
        fn_801E41D8(points[1], points[2], 0x80FFFF00, lbl_80562A44);
        fn_801E41D8(points[2], points[0], 0x80FFFF00, lbl_80562A44);
      }
    }
  }

}
#pragma pop

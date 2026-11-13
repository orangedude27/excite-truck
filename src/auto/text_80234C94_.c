// Code of main that had no source file yet: decomp.wtf gave it this one.
#pragma ppc_psq_save off
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *);
static inline void CopyStr_8023512C(char *dst, const char *src, int n) {
    unsigned char c;
    goto body;
dec:
    if (--n > 0) goto body;
    dst[-1] = 0;
    goto end;
body:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0) goto dec;
end:;
}
static inline void CatStr_8023512C(char *dst, const char *src, int n) {
    while (*dst != 0) { n--; dst++; }
    if (n > 0) CopyStr_8023512C(dst, src, n);
}
static inline void CopyStrB_8023512C(const char *src, int n, char *dst) {
    unsigned char c;
    (void)*src;
    goto body;
dec:
    if (--n > 0) goto body;
    dst[-1] = 0;
    goto end;
body:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0) goto dec;
end:;
}
static inline void CopyStrD_8023512C(const char *src, char *dst, int n) {
    unsigned char c;
    goto body;
dec:
    if (--n > 0) goto body;
    dst[-1] = 0;
    goto end;
body:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0) goto dec;
end:;
}
static inline void CatStrD_8023512C(const char *src, char *dst, int n) {
    const char *s = src;
    while (*dst != 0) { n--; dst++; }
    if (n > 0) CopyStrD_8023512C(s, dst, n);
}
static inline void CatStrB_8023512C(const char *src, int n, char *dst) {
    while (*dst != 0) { n--; dst++; }
    if (n > 0) CopyStrB_8023512C(src, n, dst);
}
static inline void CatStrC_8023512C(const char *src, int n, char *dst) {
    const char *s = src;
    while (*dst != 0) { n--; dst++; }
    if (n > 0) CopyStrB_8023512C(s, n, dst);
}
extern void *fn_801284F8(int, const char *);
/* One picture of an art set, 0x1C bytes: the six floats of its row in the
 * "gArt" resource table (fn_80234EF4) -- the texture rectangle
 * (s0,t0)-(s1,t1) and the size to draw it at -- and the next picture. */
typedef struct ArtPicture {
    float s0, t0;                /* 0x00: top-left of the picture in the texture */
    float s1, t1;                /* 0x08: bottom-right */
    float height;                /* 0x10: column 5 of the table row */
    float width;                 /* 0x14: column 4 */
    struct ArtPicture *next;     /* 0x18 */
} ArtPicture;
/* An art set, 0x8C bytes: the art file it was loaded from, how many hold it,
 * the display list that file's textures were made into (fn_802CAC28) and the
 * pictures, in the file's order (fn_8023505C walks them by index). */
typedef struct ArtSet {
    char name[0x80];             /* 0x00 */
    int refCount;                /* 0x80 */
    int drawHandle;              /* 0x84 */
    ArtPicture *pictures;        /* 0x88 */
} ArtSet;
extern void fn_802E317C(const char *, ...);
extern char lbl_80340670[];
extern unsigned char lbl_80340680[];
extern void *lbl_8055F084;
void *fn_80234C94(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void *fn_80234CEC(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_80234D44(int value) {
    /* Append a value to the singly linked gArt-tracker list, allocating an 8-byte node if needed. */
    int *node;
    if (value != 0) {
        node = (int *)lbl_8055F084;
        if (node == 0) {
            node = fn_801284F8(8, lbl_80340670);
            lbl_8055F084 = node;
            *node = value;
            node = (int *)lbl_8055F084;
            node[1] = 0;
        } else {
            while (node[1] != 0)
                node = (int *)node[1];
            node[1] = (int)fn_801284F8(8, lbl_80340670);
            node = (int *)node[1];
            node[0] = value;
            node[1] = 0;
        }
    }
}
#pragma scheduling on

void fn_80234DE4(unsigned int artId) {
    /* Remove the node matching artId from the lbl_8055F084 linked list and
     * free it; if a NULL node is reached, report via fn_802E317C. */
    unsigned int *node;
    unsigned int *prev;
    node = (unsigned int *)lbl_8055F084;
    prev = 0;
    while (*node != artId) {
        if (node == 0)
            fn_802E317C((const char *)lbl_80340680, artId);
        prev = node;
        node = (unsigned int *)node[1];
    }
    if (prev == 0)
        lbl_8055F084 = (void *)node[1];
    else
        prev[1] = node[1];
    node[1] = 0;
    node[0] = 0;
    fn_80128668(node);
}

void *fn_80234E88(const char *arg0) {
    void *node = lbl_8055F084;
    while (node != 0 && stricmp(arg0, *(const char **)node) != 0)
        node = *(void **)((char *)node + 4);
    if (node == 0)
        return 0;
    return *(void **)node;
}

extern double atof(const char *);
extern void *fn_8012F150(const char *);
extern int fn_8012F2E4(void *);
extern int fn_8012F2E8(void);
extern char *fn_8012F2F0(void *, int, int);
extern char lbl_8055B9E0[5];
extern unsigned char lbl_803406B0[];
extern void fn_80265940(void);
#pragma scheduling invalid_target
/* Loads art/texture metadata rows for a named resource into a linked list at obj+0x88, or logs lbl_803406B0 when the resource is unavailable. */
void fn_80234EF4(void *artObject, const char *resourceName) {
    if (fn_8012C33C(resourceName)) {
        void *source = fn_8012F150(resourceName);
        int count = fn_8012F2E8();
        void *last = 0;
        int i;
        for (i = 0; i < count; i++) {
            void *item = fn_801284F8(0x1c, lbl_8055B9E0);
            *(float *)item = (float)atof(fn_8012F2F0(source, i, 0));
            *(float *)((char *)item + 4) = (float)atof(fn_8012F2F0(source, i, 1));
            *(float *)((char *)item + 8) = (float)atof(fn_8012F2F0(source, i, 2));
            *(float *)((char *)item + 0xc) = (float)atof(fn_8012F2F0(source, i, 3));
            *(float *)((char *)item + 0x14) = (float)atof(fn_8012F2F0(source, i, 4));
            *(float *)((char *)item + 0x10) = (float)atof(fn_8012F2F0(source, i, 5));
            if (!last) *(void **)((char *)artObject + 0x88) = item;
            else *(void **)((char *)last + 0x18) = item;
            last = item;
        }
        fn_8012F2E4(source);
        *(void **)((char *)last + 0x18) = 0;
    } else {
        fn_802E317C((const char *)lbl_803406B0, resourceName);
    }
}
#pragma scheduling on
#pragma dont_inline on
void *fn_8023505C(void *arg0, int arg1) {
    void *node;
    int i;

    if (arg1 == 0) {
        return *(void **)((char *)arg0 + 0x88);
    }
    node = *(void **)((char *)arg0 + 0x88);
    i = 0;
    while (node != 0 && i <= arg1) {
        if (i == arg1) {
            return node;
        }
        node = *(void **)((char *)node + 0x18);
        i++;
    }
    return node;
}
#pragma dont_inline reset

extern const char lbl_803406FC[];
extern const char lbl_80340724[];
extern const char lbl_80340760[];
extern int stricmp(const char *, const char *);
extern void fn_802E30C8(const char *, ...);
extern void fn_80235380(void *);
#pragma scheduling invalid_target
void fn_8023509C(void) {
    if (lbl_8055F084 != 0)
        fn_802E317C(lbl_803406FC);
}
#pragma scheduling on
void fn_802350BC(void) {
    if (lbl_8055F084 != 0)
        fn_802E30C8(lbl_80340724);
    while (lbl_8055F084 != 0) {
        fn_802E30C8(lbl_80340760, *(unsigned int *)lbl_8055F084);
        fn_80235380(*(void **)lbl_8055F084);
    }
}

extern char lbl_8055B9E8[4];
extern char lbl_8055B9F0[4];
extern char *fn_80029004(char *, int);
void *fn_8023512C(const char *arg0) {
    char *tbl = (char *)lbl_80340670;
    char full[0x80];
    char name[0x80];
    char *dot;
    int *obj;
    CopyStrB_8023512C(arg0, 0x80, full);
    if (fn_8012C33C(arg0) == 0) {
        fn_802E30C8(tbl + 0x120, arg0);
        CopyStrB_8023512C(tbl + 0x140, 0x80, full);
    }
    obj = ((void *(*)(char *))fn_80234E88)(full);
    if (obj != 0) {
        obj[0x80 / 4] += 1;
        return obj;
    }
    obj = fn_801284F8(0x8C, lbl_8055B9E8);
    obj[0x84 / 4] = fn_802CAC28(full, 0);
    if (obj[0x84 / 4] == -1)
        fn_802E317C(tbl + 0x14C, full);
    obj[0x80 / 4] = 1;
    obj[0x88 / 4] = 0;
    CopyStrB_8023512C(full, 0x80, (char *)obj);
    CopyStrB_8023512C(full, 0x80, name);
    dot = fn_80029004(name, 0x2E);
    if (dot != 0)
        *dot = 0;
    else
        fn_802E317C(tbl + 0x168, name);
    CatStrC_8023512C(lbl_8055B9F0, 0x80, name);
    fn_80234EF4(obj, name);
    fn_80234D44((int)obj);
    return obj;
}

void fn_80235380(void *arg0) {
    int count;
    void *node;
    void *next;

    count = *(int *)((char *)arg0 + 0x80) - 1;
    *(int *)((char *)arg0 + 0x80) = count;
    if (count <= 0) {
        node = *(void **)((char *)arg0 + 0x88);
        while (node != 0) {
            next = *(void **)((char *)node + 0x18);
            fn_80128668(node);
            node = next;
        }
        fn_802CAC54(*(int *)((char *)arg0 + 0x84));
        fn_80234DE4((unsigned int)arg0);
        fn_80128668(arg0);
    }
}

/* A draw-list vertex: x, y, z, an RGBA colour packed by fn_80230B9C and the
 * texture coordinates.  The frame copies move x and y together as one double,
 * which is what the double field stands for. */
typedef struct Vtx_80235CBC { double a; int b, c; float d, e; } Vtx_80235CBC;
/* The frame's four vertices as two triangles: {0, 1, 3, 3, 2, 0}. */
typedef struct Idx_80235CBC { unsigned short i[6]; } Idx_80235CBC;
extern Vtx_80235CBC fn_80230A68(int, float, float, float, float, float);
extern int fn_80230B9C(int);
extern void fn_802C8C04(int);
extern unsigned short lbl_802FA008[6];
extern Idx_80235CBC lbl_802FA020;
__declspec(section ".data") extern float lbl_80558DC4;
extern float lbl_805636B0;
extern float lbl_805636B4;
extern void *fn_8022EDC4(void);
static inline int is_close(float a, float b) {
    if ((float)__fabs(a - b) <= lbl_80558DC4)
        return 1;
    return 0;
}
extern void fn_802C8DB8(void *, int, unsigned short *, int);
extern void fn_802C8D74(void);
extern void fn_802C8B98(int, int);
#pragma push
#pragma processor 750
/* Draws a picture from an art set by index at (x, y, z), or logs if the index is not found. */
void fn_802353F4(int artSet, int pictureIndex, float x, float y, float z) {
    void *pictureNode;
    if (pictureIndex < 0) return;
    pictureNode = ((void *(*)(void *, int))fn_8023505C)((void *)artSet, pictureIndex);
    if (pictureNode == 0) {
        fn_802E30C8(lbl_80340808, pictureIndex, artSet);
        return;
    }
    fn_802354A0(artSet, pictureIndex, -1, x, y, z, *(float *)((char *)pictureNode + 0x14), *(float *)((char *)pictureNode + 0x10));
}

#pragma push
#pragma processor 750
void fn_802354A0(int arg0, int arg1, int arg2, float x, float y, float z, float dx, float dy) {
    Idx_80235CBC ids;
    Vtx_80235CBC t3, t2, t1, t0;
    struct Frame {
        Vtx_80235CBC v[4];
    } __attribute__((aligned(16))) frame;
    void *node;
    float sx, sy, n0, n1, n2, n3;
    int handle;
    void *obj;
    int index;
    float scale, one, diff;
    volatile int is_close;
    if (arg1 < 0)
        return;
    node = fn_8023505C((void *)arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340808, arg1, arg0);
        return;
    }
    sy = dy;
    n3 = *((float *)node + 3);
    sx = dx;
    n2 = *((float *)node + 2);
    n1 = *((float *)node + 1);
    n0 = *(float *)node;
    handle = *(int *)((char *)arg0 + 0x84);
    obj = fn_8022EDC4();
    fn_802C8B98(handle, (int)obj);
    index = fn_80230B9C(arg2);
    scale = *(float *)((char *)obj + 0x38);
    one = lbl_805636B0;
    diff = scale - one;
    if ((float)__fabs(diff) <= lbl_80558DC4) is_close = 1; else is_close = 0;
    if (is_close == 0) {
        float s = *(float *)((char *)obj + 0x38);
        sx = dx * s;
        sy = dy * s;
        x += lbl_805636B4 * (dx * (lbl_805636B0 - s));
        y -= lbl_805636B4 * (dy * (lbl_805636B0 - s));
    }
    t0 = fn_80230A68(index, x, y, z, n0, n1);
    frame.v[0].a = t0.a; frame.v[0].b = t0.b; frame.v[0].c = t0.c; frame.v[0].d = t0.d; frame.v[0].e = t0.e;
    t1 = fn_80230A68(index, x + sx, y, z, n2, n1);
    frame.v[1].a = t1.a; frame.v[1].b = t1.b; frame.v[1].c = t1.c; frame.v[1].d = t1.d; frame.v[1].e = t1.e;
    t2 = fn_80230A68(index, x, y - sy, z, n0, n3);
    frame.v[2].a = t2.a; frame.v[2].b = t2.b; frame.v[2].c = t2.c; frame.v[2].d = t2.d; frame.v[2].e = t2.e;
    t3 = fn_80230A68(index, x + sx, y - sy, z, n2, n3);
    frame.v[3].a = t3.a; frame.v[3].b = t3.b; frame.v[3].c = t3.c; frame.v[3].d = t3.d; frame.v[3].e = t3.e;
    ids = *(Idx_80235CBC *)lbl_802FA008;
    fn_802C8DB8(frame.v, 4, ids.i, 6);
    fn_802C8D74();
}

#pragma push
#pragma processor 750
void fn_80235758(int arg0, int arg1, int arg2, float x, float y, float dx, float dy, float u0, float v0, float u1, float v1) {
    Idx_80235CBC ids;
    Vtx_80235CBC t3, t2, t1, t0;
    struct Frame {
        Vtx_80235CBC v[4];
    } __attribute__((aligned(16))) frame;
    void *node;
    float sx, sy, n3, n2, n1, n0;
    int handle;
    void *obj;
    int index;
    float s;

    if (arg1 < 0)
        return;

    node = fn_8023505C((void *)arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340808, arg1, arg0);
        return;
    }

    {
        float hi, lo, a;
        hi = *((float *)node + 3); lo = *((float *)node + 1);
        a = lbl_805636B0 < v1 ? lbl_805636B0 : v1;
        a = a > lbl_805636B8 ? a : lbl_805636B8;
        n3 = lo + a * (hi - lo);
        hi = *((float *)node + 2); lo = *(float *)node;
        a = lbl_805636B0 < u1 ? lbl_805636B0 : u1;
        a = a > lbl_805636B8 ? a : lbl_805636B8;
        n2 = lo + a * (hi - lo);
        hi = *((float *)node + 3); lo = *((float *)node + 1);
        a = lbl_805636B0 < v0 ? lbl_805636B0 : v0;
        a = a > lbl_805636B8 ? a : lbl_805636B8;
        n1 = lo + a * (hi - lo);
        hi = *((float *)node + 2); lo = *(float *)node;
        a = lbl_805636B0 < u0 ? lbl_805636B0 : u0;
        a = a > lbl_805636B8 ? a : lbl_805636B8;
        n0 = lo + a * (hi - lo);
    }
    sy = dy; sx = dx;

    handle = *(int *)((char *)arg0 + 0x84);
    obj = fn_8022EDC4();
    fn_802C8B98(handle, (int)obj);
    index = fn_80230B9C(arg2);

    s = *(float *)((char *)obj + 0x38);
    if (!((float)__fabs(s - lbl_805636B0) <= lbl_80558DC4)) {
        sx = dx * s;
        sy = dy * s;
        x += lbl_805636B4 * (dx * (lbl_805636B0 - s));
        y -= lbl_805636B4 * (dy * (lbl_805636B0 - s));
    }

    t0 = fn_80230A68(index, x, y, lbl_805636B8, n0, n1);
    frame.v[0].a = t0.a; frame.v[0].b = t0.b; frame.v[0].c = t0.c; frame.v[0].d = t0.d; frame.v[0].e = t0.e;
    t1 = fn_80230A68(index, x + sx, y, lbl_805636B8, n2, n1);
    frame.v[1].a = t1.a; frame.v[1].b = t1.b; frame.v[1].c = t1.c; frame.v[1].d = t1.d; frame.v[1].e = t1.e;
    t2 = fn_80230A68(index, x, y - sy, lbl_805636B8, n0, n3);
    frame.v[2].a = t2.a; frame.v[2].b = t2.b; frame.v[2].c = t2.c; frame.v[2].d = t2.d; frame.v[2].e = t2.e;
    t3 = fn_80230A68(index, x + sx, y - sy, lbl_805636B8, n2, n3);
    frame.v[3].a = t3.a; frame.v[3].b = t3.b; frame.v[3].c = t3.c; frame.v[3].d = t3.d; frame.v[3].e = t3.e;

    ids = *(Idx_80235CBC *)lbl_802FA008;

    fn_802C8DB8(frame.v, 4, ids.i, 6);
    fn_802C8D74();
}
#pragma pop

#pragma pop

extern double cos(float);
extern double sin(float);
extern void fn_80231380(void *, int, float, float, float, float, float);
extern void fn_802C8B98(int, int);
extern float lbl_805636B0;
extern float lbl_805636B4;
extern unsigned short lbl_802FA014[];
#pragma paired_single off
void fn_80235AFC(void *arg0, int texNodeIndex, int vertexFlags,
                 float x, float y, float z,
                 float width, float height, float angle) {
    struct Frame {
        unsigned short indices[6];
        unsigned char pad1[4];
        float matrix[12];
        float vertices[4][6];
    } __attribute__((aligned(16))) frame;
    void *node;
    float *matrix;
    unsigned short *p;
    register int render;
    float c;
    float s;
    float zero;
    float halfWidth;
    float halfHeight;

    /* Build a transformed textured quad (2D matrix + 4 vertices) and submit it for rendering. */
    matrix = frame.matrix;
    matrix[9] = x;
    matrix[10] = y;
    matrix[11] = z;
    c = (float)cos(angle);
    s = (float)sin(angle);
    zero = lbl_805636B8;
    matrix[0] = c;
    matrix[1] = s;
    matrix[2] = zero;
    matrix[3] = -s;
    matrix[4] = c;
    matrix[5] = zero;
    matrix[6] = zero;
    matrix[7] = zero;
    matrix[8] = lbl_805636B0;

    node = ((void *(*)(void *, int))fn_8023505C)(arg0, texNodeIndex);
    halfWidth = width * lbl_805636B4;
    halfHeight = height * lbl_805636B4;
    fn_80231380(frame.vertices[0], vertexFlags, -halfWidth, halfHeight, zero,
                *(float *)node, *((float *)node + 1));
    fn_80231380(frame.vertices[1], vertexFlags, halfWidth, halfHeight, zero,
                *((float *)node + 2), *((float *)node + 1));
    fn_80231380(frame.vertices[2], vertexFlags, -halfWidth, -halfHeight, zero,
                *(float *)node, *((float *)node + 3));
    fn_80231380(frame.vertices[3], vertexFlags, halfWidth, -halfHeight, zero,
                *((float *)node + 2), *((float *)node + 3));

    render = *(volatile int *)((char *)arg0 + 0x84);
    p = lbl_802FA014;
    frame.indices[0] = *p++;
    frame.indices[1] = *p++;
    frame.indices[2] = *p++;
    frame.indices[3] = *p++;
    frame.indices[4] = *p++;
    frame.indices[5] = *p++;
    fn_802C8B98(render, (int)matrix);
    fn_802C8DB8(frame.vertices, 4, frame.indices, 6);
    fn_802C8D74();
}
#pragma push
#pragma paired_single off
/* Draws one picture of an art set as a textured quad width x height at
 * (x, y, z): the picture gives the texture rectangle, rgba gives the colour
 * with its alpha scaled by the current fade.  Logs and draws nothing when the
 * index is not in the set. */
void fn_80235CBC(ArtSet *artSet, int pictureIndex, int rgba, float x, float y, float z, float width, float height) {
    ArtPicture *picture;
    int color;
    float u0, v0, u1, v1;
    Idx_80235CBC ids;
    Vtx_80235CBC t3, t2, t1, t0;
    struct Frame {
        Vtx_80235CBC v[4];
    } __attribute__((aligned(16))) frame;
    if (pictureIndex < 0)
        return;
    picture = fn_8023505C(artSet, pictureIndex);
    if (picture == 0) {
        fn_802E30C8(lbl_80340808, pictureIndex, artSet);
        return;
    }
    u0 = picture->s0;
    v0 = picture->t0;
    u1 = picture->s1;
    v1 = picture->t1;
    fn_802C8C04(artSet->drawHandle);
    color = fn_80230B9C(rgba);
    t3 = fn_80230A68(color, x, y, z, u0, v0);
    frame.v[0].a = t3.a; frame.v[0].b = t3.b; frame.v[0].c = t3.c; frame.v[0].d = t3.d; frame.v[0].e = t3.e;
    t2 = fn_80230A68(color, x + width, y, z, u1, v0);
    frame.v[1].a = t2.a; frame.v[1].b = t2.b; frame.v[1].c = t2.c; frame.v[1].d = t2.d; frame.v[1].e = t2.e;
    t1 = fn_80230A68(color, x, y - height, z, u0, v1);
    frame.v[2].a = t1.a; frame.v[2].b = t1.b; frame.v[2].c = t1.c; frame.v[2].d = t1.d; frame.v[2].e = t1.e;
    t0 = fn_80230A68(color, x + width, y - height, z, u1, v1);
    frame.v[3].a = t0.a; frame.v[3].b = t0.b; frame.v[3].c = t0.c; frame.v[3].d = t0.d; frame.v[3].e = t0.e;
    ids = lbl_802FA020;
    fn_802C8DB8(frame.v, 4, ids.i, 6);
    fn_802C8D74();
}
#pragma pop
float fn_80235EF0(int arg0, int arg1) {
    void *node;

    if (arg0 == 0)
        return lbl_805636B8;
    node = fn_8023505C((void *)arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340834, arg0, arg1);
        return lbl_805636B8;
    }
    return *(float *)((char *)node + 0x14);
}
#pragma dont_inline reset
extern const char lbl_80340878[];
#pragma dont_inline on
float fn_80235F64(int arg0, int arg1) {
    void *node;

    if (arg0 == 0)
        return lbl_805636B8;
    node = fn_8023505C((void *)arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340878, arg0, arg1);
        return lbl_805636B8;
    }
    return *(float *)((char *)node + 0x10);
}

int fn_80235FD8(void *arg0) {
    void *p;
    int count;

    if (arg0 == 0) {
        return 0;
    }
    p = *(void **)((char *)arg0 + 0x88);
    count = 0;
    while (p != 0) {
        p = *(void **)((char *)p + 0x18);
        count++;
    }
    return count;
}

extern void *fn_8012850C(int, void *, int);
extern char lbl_803408CC[];
extern int lbl_8055B9F8;
void *fn_80236008(void *arg0, int arg1, int arg2) {
    *(int *)((char *)arg0 + 8) = arg1;
    *(void **)arg0 = lbl_803408CC;
    *(void **)((char *)arg0 + 4) = fn_8012850C(arg1 * 0x2C, &lbl_8055B9F8, arg2);
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x10) = -2;
    *((char *)arg0 + 0x14) = arg2;
    return arg0;
}

/* Destructor-like cleanup: clears vtable/entries, releases per-element resources and the backing array, optionally deletes the object when arg1 > 0. */
void *fn_80236074(void *object, int deleteFlag) {
    int offset;
    int i;
    int mode;
    if (object != 0) {
        *(void **)object = lbl_803408CC;
        i = 0;
        offset = 0;
        while (i < *(int *)((char *)object + 0xC)) {
            fn_802CAC54(*(void **)(*(char **)((char *)object + 4) + offset + 0x24));
            offset += 0x2C;
            i++;
        }
        fn_80128670(*(void **)((char *)object + 4));
        mode = *(int *)((char *)object + 0x10);
        *(int *)((char *)object + 8) = 0;
        *(int *)((char *)object + 0xC) = 0;
        if (mode != -2)
            fn_802CAC54();
        if (deleteFlag > 0)
            fn_80128668(object);
    }
    return object;
}

#pragma dont_inline reset
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);
#pragma scheduling invalid_target
/* If the name is valid, append a new 0x2C-byte entry to the pool: copy up to 0x21
 * bytes of the name (null-terminating on truncation), then store the resolved
 * resource id at +0x24 and the caller's value at +0x28. */
void fn_80236134(void *namePool, int userValue, const char *name) {
    unsigned char character;
    char *cursor;
    int remaining;
    char *entry;
    int resourceId;
    if (fn_8012C33C(name) != 0) {
        resourceId = fn_802CAC28(name, 0);
        entry = *(char **)((char *)namePool + 4) + (*(int *)((char *)namePool + 0xC))++ * 0x2C;
        cursor = entry;
        remaining = 0x21;
        goto loop_body;
    count_check:
        remaining -= 1;
        if (remaining > 0)
            goto loop_body;
        cursor[-1] = 0;
        goto finish;
    loop_body:
        character = *name++;
        *cursor = character;
        cursor++;
        if ((signed char)character != 0)
            goto count_check;
    finish:
        *(int *)(entry + 0x28) = userValue;
        *(int *)(entry + 0x24) = resourceId;
    }
}

#pragma push
#pragma processor 750
extern float lbl_805636C0;
extern float lbl_805636C8;
extern void* fn_802CC5B8(int);
extern float fn_802C9A4C(float);
#pragma push
#pragma processor 750
void fn_802361E8(void *obj, int key, int idx, float a, float b, float c, float d, float e) {
    Idx_80235CBC ids;
    Vtx_80235CBC t3, t2, t1, t0;
    struct Frame { Vtx_80235CBC v[4]; } __attribute__((aligned(16))) frame;
    int handle;
    void *nodePtr;
    int count;
    int i;
    void *entry;
    void *transform;
    int renderIdx;
    float sx, sy, n0, n1, n2, n3;
    float s;
    float scale;
    int ia, ib, ic, id;
    handle = *(int *)((char *)obj + 0x10);
    count = *(int *)((char *)obj + 0xC);
    i = 0;
    entry = *(void **)((char *)obj + 4);
    while (i < count) {
        if (*(int *)((char *)entry + 0x28) == key) {
            *((int **)&nodePtr) = (int *)fn_802CC5B8(*(int *)((char *)entry + 0x24));
            handle = *((int *)nodePtr + 0);
            break;
        }
        i++;
        entry = (char *)entry + 0x2C;
    }
    if (handle == -2) return;
    scale = fn_802C9A4C(lbl_805636C8);
    if (*(unsigned char *)((char *)obj + 0x14) != 0) {
        n2 = lbl_805636B8;
        n3 = lbl_805636B0;
    } else {
        n2 = lbl_805636B0;
        n3 = lbl_805636B8;
    }
    ia = *(int *)&a ^ 0x80000000;
    ix: ib = *(int *)&b ^ 0x80000000;
    ic = *(int *)&c ^ 0x80000000;
    id = *(int *)&d ^ 0x80000000;
    sx = *(float *)&ia;
    n0 = *(float *)&ib;
    sy = *(float *)&ic;
    n1 = *(float *)&id;
    (void)idx;
    transform = fn_8022EDC4();
    fn_802C8B98(handle, (int)transform);
    renderIdx = fn_80230B9C(-1);
    s = *(float *)((char *)transform + 0x38);
    {
        float diff = s - lbl_805636B0;
        float adiff = (float)__fabs(diff);
        if (!(adiff <= lbl_80558DC4)) {
            sx = c * s * 0;
            sy = d * s * 0;
        }
    }
    t0 = fn_80230A68(renderIdx, sx, sy, a, n0, n1);
    frame.v[0].a = t0.a; frame.v[0].b = t0.b; frame.v[0].c = t0.c; frame.v[0].d = t0.d; frame.v[0].e = t0.e;
    t1 = fn_80230A68(renderIdx, sx + sy, sy, a, n2, n1);
    frame.v[1].a = t1.a; frame.v[1].b = t1.b; frame.v[1].c = t1.c; frame.v[1].d = t1.d; frame.v[1].e = t1.e;
    t2 = fn_80230A68(renderIdx, sx, sy - n0, a, n0, n3);
    frame.v[2].a = t2.a; frame.v[2].b = t2.b; frame.v[2].c = t2.c; frame.v[2].d = t2.d; frame.v[2].e = t2.e;
    t3 = fn_80230A68(renderIdx, sx + sy, sy - n0, a, n2, n3);
    frame.v[3].a = t3.a; frame.v[3].b = t3.b; frame.v[3].c = t3.c; frame.v[3].d = t3.d; frame.v[3].e = t3.e;
    ids = *(Idx_80235CBC *)lbl_802FA008;
    fn_802C8DB8(frame.v, 4, ids.i, 6);
    fn_802C8D74();
    fn_802C9A4C(scale);
}
#pragma pop

#pragma scheduling on
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);

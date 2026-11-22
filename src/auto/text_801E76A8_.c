// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_801284F8(int, void *);
extern void *fn_801E76A8(void *, int);
extern void drawFifoTriangles(int, int, int, int);
extern void fn_80128670(void *);
extern void fn_80128668(void *);
#pragma small_data off
extern char lbl_80339B90[];
typedef struct { void *a; int b; int c; void *d; int e; int f; } S76;
void fn_801E7828();
void fn_801E7790(void *, int, int, float, float, float, float, float);
#pragma dont_inline on
extern void *fn_8012850C(int, void *);
extern char lbl_80339B70[]; /* "DrawList verts" */
extern char lbl_80339B80[]; /* "DrawList idxs" */
#define sDrawListVertsTag lbl_80339B70
#define sDrawListIdxsTag lbl_80339B80
void *fn_801E76A8(void *list, int vertexCapacity) {
    #pragma scheduling invalid_target
    /* Initialize a GenericDrawList: allocate the vertex buffer (0x18-byte
     * vertices) and the triangle-strip index buffer ((capacity-2)*3 u16 indices),
     * store their capacities, and reset both write cursors. */
    int span;
    int indexCapacity;
    *(void **)list = fn_8012850C(vertexCapacity * 0x18, sDrawListVertsTag);
    span = vertexCapacity - 2;
    *(int *)((char *)list + 8) = vertexCapacity;
    indexCapacity = (span * 4) - span;
    *(int *)((char *)list + 4) = 0;
    *(void **)((char *)list + 0xC) = fn_8012850C(indexCapacity * 2, sDrawListIdxsTag);
    *(int *)((char *)list + 0x10) = 0;
    *(int *)((char *)list + 0x14) = indexCapacity;
    return list;
}

/* Destroy a PhysicsWorld-like object by releasing owned buffers at offsets 0xC
 * and 0x0, then optionally freeing the object storage. */
void *__dt__12PhysicsWorldFv_801E7730(void *object, int shouldDelete) {
    if (object != 0) {
        fn_80128670(*(void **)((char *)object + 0xC));
        fn_80128670(*(void **)((char *)object + 0));
        if (shouldDelete > 0) fn_80128668(object);
    }
    return object;
}

#pragma push
#pragma scheduling invalid_target
void fn_801E7790(void *buf, int id, int emit, float x, float y, float z, float u, float v) {
    S76 *b = (S76 *)buf;
    float *dst;
    int ic;
    dst = (float *)((char *)b->a + b->b * 0x18);
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
    ((int *)dst)[3] = id;
    dst[4] = u;
    dst[5] = v;
    ic = b->e;
    b->b = b->b + 1;
    if (emit == 0) return;
    if (b->b <= 1) return;
    ((short *)b->d)[ic] = (short)(b->b - 3);
    b->e = ic + 1;
    ((short *)b->d)[ic + 1] = (short)(b->b - 2);
    b->e = ic + 2;
    ((short *)b->d)[ic + 2] = (short)(b->b - 1);
    b->e = ic + 3;
}
#pragma pop
/* GenericDrawList draw: unpacks the descriptor (vertices, vertexCount, cap, indices, indexCount) and forwards it to the immediate-mode triangle renderer. */
void fn_801E7828(drawList)
    void *drawList;
{
    int *fields = (int *)drawList;
    drawFifoTriangles(fields[0], fields[1], fields[3], fields[4]);
}

#pragma dont_inline off

/* RealName: GenericDrawList_Create
 * Allocates a 0x18-byte object tagged "GenericDrawList" and initializes it
 * with fn_801E76A8 when allocation succeeds.
 */
void fn_801E7840(void *arg0) {
#define sGenericDrawListTag lbl_80339B90
#define GenericDrawList_Alloc fn_801284F8
#define GenericDrawList_Init fn_801E76A8
    void *drawList;

    drawList = GenericDrawList_Alloc(0x18, sGenericDrawListTag);
    if (drawList != 0) {
        GenericDrawList_Init(drawList, (int)arg0);
    }
#undef sGenericDrawListTag
#undef GenericDrawList_Alloc
#undef GenericDrawList_Init
}

extern void *__dt__12PhysicsWorldFv_801E7730(void *object, int shouldDelete);
void *fn_801E7888(void *world) {
    /* Deleting-destructor thunk: destroy this PhysicsWorld and free it (shouldDelete = 1). */
    return __dt__12PhysicsWorldFv_801E7730(world, 1);
}

void fn_801E7890(void *buf, int id, int emit, float x, float y, float z, float u, float v) {
    /* Tail-call thunk forwarding to fn_801E7790. */
    fn_801E7790(buf, id, emit, x, y, z, u, v);
}

/* Tail-call wrapper for GenericDrawList draw. */
void fn_801E7894(void) {
    fn_801E7828();
}


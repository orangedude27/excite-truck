// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_801284F8(int, void *);
extern void *fn_801E76A8(void *, int);
extern void fn_802D68C4(int, int, int, int);
extern void fn_80128670(void *);
extern void fn_80128668(void *);
#pragma small_data off
extern char lbl_80339B90[];
typedef struct { void *a; int b; int c; void *d; int e; int f; } S76;
void fn_801E7828();
void fn_801E7790(void *, int, int, float, float, float, float, float);
#pragma dont_inline on
extern void *fn_8012850C(int, void *);
extern char lbl_80339B70[];
extern char lbl_80339B80[];
void *fn_801E76A8(void *arg0, int arg1) {
    S76 *o = (S76 *)arg0;
    int rem;
    o->a = fn_8012850C(arg1 * 0x18, lbl_80339B70);
    rem = arg1 - 2;
    o->c = arg1;
    arg1 = (rem * 4) - rem;
    o->b = 0;
    o->d = fn_8012850C(arg1 * 2, lbl_80339B80);
    o->e = 0;
    o->f = arg1;
    return arg0;
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

void fn_801E7790(void *buf, int id, int emit, float x, float y, float z, float u, float v) {
    int *b = (int *)buf;
    char *base = (char *)b[0];
    float *dst = (float *)(base + b[1] * 24);
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
    ((int *)dst)[3] = id;
    dst[4] = u;
    dst[5] = v;
    b[1]++;
    if (emit == 0) return;
    if (b[1] <= 1) return;
    {
        int ic = b[4];
        ((short *)b[3])[ic] = (short)(b[1] - 3);
        b[4] = ic + 1;
        ic++;
        ((short *)b[3])[ic] = (short)(b[1] - 2);
        b[4] = ic + 1;
        ic++;
        ((short *)b[3])[ic] = (short)(b[1] - 1);
        b[4] = ic + 1;
    }
}

/* GenericDrawList draw: unpacks the descriptor (vertices, vertexCount, cap, indices, indexCount) and forwards it to the immediate-mode triangle renderer. */
void fn_801E7828(drawList)
    void *drawList;
{
    int *fields = (int *)drawList;
    fn_802D68C4(fields[0], fields[1], fields[3], fields[4]);
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

void *fn_801E7888(void *arg0) {
    return __dt__12PhysicsWorldFv_801E7730(arg0, 1);
}

void fn_801E7890(void *a, int b, int c, float d, float e, float f, float g, float h) {
    fn_801E7790(a, b, c, d, e, f, g, h);
}

void fn_801E7894(void) {
    fn_801E7828();
}


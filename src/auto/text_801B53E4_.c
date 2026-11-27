// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <stddef.h>
#include <revolution/MTX/mtxtypes.h>

typedef struct QuadNode {
    s32 count;
    s32 p;
    s32 e6ec;
    s32 q;
    s32 tail;
    s32 callback;
} QuadNode;

/* One link of the object list fn_801B5D30 packs into a quad tree; the same
 * list fn_801B5D10 counts and fn_801B5BDC turns into an array. */
struct ObjectLink {
    u8 pad[0x3C];
    void *object;              /* +0x3C: the BPX object this link stands for */
    u8 pad_40[4];
    struct ObjectLink *next;   /* +0x44: the next link, NULL at the list's end */
};

/* A BPX scene object, as far as this unit reads it.  Its transform is twelve
 * floats in four rows of three: row 2 ([6..8]) is a direction and row 3
 * ([9..11]) the position.  fn_801B5410 walks the position by +-length along
 * that direction, with the height forced to zero, to get the two ends of the
 * straight segment the object stands for - so ends are matched on the ground. */
struct BpxObject {
    u8 pad[0x0C];
    f32 *matrix;  /* +0x0C */
    u8 pad_10[8];
    u32 magic;    /* +0x18: 'BPX ' */
    u8 pad_1C[4];
    u32 kind;     /* +0x20: what the object is; fn_801B53E4 filters on it */
    u8 pad_24[8];
    f32 length;   /* +0x2C: how far each end sits from the position */
    u8 pad_30[4];
    s32 links;    /* +0x34: bit 0 / bit 1 - the first / second end has a neighbour */
};

extern f32 lbl_80562690;
extern f32 lbl_805626A0;
extern f32 lbl_805626A4;
extern f32 lbl_805626A8;
extern f32 lbl_80435EB8[4];
extern void quadTreeAddObject(void *, s32, void *, s32, f32, f32, f32, f32, f32, f32);
extern f32 lbl_80562698, lbl_8056269C;
extern s32 lbl_8055E6EC;
extern s32 lbl_8055E6F0;
extern void *lbl_8055E6F4;
extern char lbl_80335E88[], lbl_80335EB4[];
extern void *fn_8012850C(s32, void *);
extern void *fn_8002F37C(void *, void *, void *, s32, s32);
extern void Abend_Panic(const char *, ...);
extern void *fn_801B5984(void *);
extern void *fn_801B591C(void *, s32);
extern void fn_8002F6AC(void *(*)(void *, s32));
extern void fn_80128668(void *);

/* Returns 1 for a linkable scene resource: its +0x18 fourCC equals 0x424F5820 ("BOX ",
 * written here as the add-and-compare the compiler produced) and its +0x20 kind is 0x6E. */
s32 fn_801B53E4(void *obj) {
    s32 isLinkable;

    isLinkable = 0;
    if (((u32)(*(s32 *)((u8 *)obj + 0x18) + 0xBDB10000) == 0x5820U) &&
        (*(s32 *)((u8 *)obj + 0x20) == 0x6E)) {
        isLinkable = 1;
    }
    return isLinkable;
}

void fn_801B5410(void *object, Vec *plusEnd, Vec *minusEnd) {
    f32 *matrix;
    f32 offset;
    f32 scaled;
    f32 component;
    f32 dirX;
    struct BpxObject *bpx = (struct BpxObject *)object;

    /* Compute the two ends of a linkable BPX object's ground segment: its
     * position (matrix [9..11]) offset by +-length along its direction
     * (matrix [6..8]), with the Y component forced to zero. */
    matrix = bpx->matrix;
    offset = bpx->length;
    dirX = matrix[6];
    scaled = dirX * offset;
    component = matrix[9] + scaled;
    plusEnd->x = component;
    scaled = matrix[7] * offset;
    component = matrix[10] + scaled;
    plusEnd->y = component;
    scaled = matrix[8] * offset;
    component = matrix[11] + scaled;
    plusEnd->z = component;
    offset = -bpx->length;
    scaled = matrix[6] * offset;
    component = matrix[9] + scaled;
    minusEnd->x = component;
    scaled = matrix[7] * offset;
    component = matrix[10] + scaled;
    minusEnd->y = component;
    scaled = matrix[8] * offset;
    component = matrix[11] + scaled;
    minusEnd->y = 0.0f;
    minusEnd->z = component;
    plusEnd->y = 0.0f;
}

/* Return the BPX object pointer held in this ObjectLink (at +0x3C), as an s32. */
s32 fn_801B54A8(void *link) {
    return (s32)((struct ObjectLink *)link)->object;
}

extern float lbl_80562694;
/* lbl_80562694: 0.01f - the squared distance two segment ends may be apart and
 * still count as touching, i.e. 0.1 world units. */
#define LINK_SQ_DISTANCE lbl_80562694
/* takes the two Vecs as void * so this unit's s32[3] temporaries pass too */
extern float PSVECSquareDistance(void *, void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
void linkNearbyBpxObjects(s32 listHead) {
    Vec start;
    Vec end;
    Vec otherStart;
    Vec otherEnd;
    f32 threshold;
    struct ObjectLink *link;
    struct ObjectLink *otherLink;
    struct BpxObject *a;
    struct BpxObject *b;

    /* Every pair of linkable BPX objects in the list: fn_801B5410 gives the two
     * ends of the straight segment each object stands for (on the ground, at
     * +-BpxObject.length from its position), and whenever any end of one lands
     * within LINK_SQ_DISTANCE of an end of the other both objects are told they
     * join there - bit 0 of BpxObject.links for a segment's first end, bit 1
     * for its second. */
    threshold = LINK_SQ_DISTANCE;
    link = (struct ObjectLink *)listHead;
    while (link != NULL) {
        if (fn_801B53E4(link->object) != 0) {
            a = (struct BpxObject *)fn_801B54A8(link);
            fn_801B5410(link->object, &start, &end);
            otherLink = (struct ObjectLink *)listHead;
            while (otherLink != NULL) {
                if (fn_801B53E4(otherLink->object) != 0) {
                    b = (struct BpxObject *)fn_801B54A8(otherLink);
                    fn_801B5410(otherLink->object, &otherStart, &otherEnd);
                    if (PSVECSquareDistance(&start, &otherStart) < threshold) {
                        a->links |= 1;
                        b->links |= 1;
                    }
                    if (PSVECSquareDistance(&start, &otherEnd) < threshold) {
                        a->links |= 1;
                        b->links |= 2;
                    }
                    if (PSVECSquareDistance(&end, &otherStart) < threshold) {
                        a->links |= 2;
                        b->links |= 1;
                    }
                    if (PSVECSquareDistance(&end, &otherEnd) < threshold) {
                        a->links |= 2;
                        b->links |= 2;
                    }
                }
                otherLink = otherLink->next;
            }
        }
        link = link->next;
    }
}
#pragma pop

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* sol: hang one object on the quad tree.  `square` is the node covering
 * x0,y0 - x1,y1 (fn_801B5B04 starts every object at the whole world box) and
 * `object`/`index` are the ObjectLink being added and its place in the array
 * that function walks.  The square is cut into four at its middle and the
 * quadrants overlapping the object's box (ObjectBox) are kept.  If none is
 * left the object lies outside the tree and is only reported.  If exactly one
 * is, the object goes straight down into it.  Otherwise, once the square is
 * too small to cut again (its longer side under MIN_SQUARE) the object is hung
 * on the square's object list and counted; else it goes into every kept
 * quadrant, so an object sitting on a border ends up in each square touching
 * it.  The last two floats are handed over by fn_801B5B04 but never read, and
 * the recursion drops them. */
void quadTreeAddObject(void *object, s32 index, void *node, s32 depth, f32 x0, f32 y0, f32 x1, f32 y1, f32 unused1, f32 unused2) {
    #define QUARTER        lbl_80562698 /* 0.5f: where a square is cut into four */
    #define MIN_SQUARE     lbl_8056269C /* 50.0f: a square this small is not cut again */
    #define ObjectBox      lbl_80435EB8 /* the object's box: minX, minY, maxX, maxY */
    #define NOT_IN_ANY     lbl_80335E88 /* "sol:add_object(): Object not in any square" */
    #define CHILDREN_TAG   lbl_80335EB4 /* "QuadTree::children": what a child array is called */
    #define LeafPool       lbl_8055E6F4 /* the records hung on squares come from here */
    #define LeafUsed       lbl_8055E6F0 /* how many of them have been handed out */
    #define LeafTotal      lbl_8055E6EC /* how many objects the tree holds */
    #define NewArray       fn_8002F37C  /* an array of items with init/destroy callbacks */
    #define AllocBlock     fn_8012850C  /* the block an array is carved from */
    #define Square_Init    fn_801B5984  /* a fresh square: no objects, no children */
    #define Square_Destroy fn_801B591C  /* a square, its children and its objects */

    typedef void (*AddObject)(void *, s32, void *, s32, f32, f32, f32, f32);
    /* One object hung on a square: the ObjectLink it stands for, its place in
     * the array being added, and the square's next object after it. */
    typedef struct QuadObject { void *object; s32 index; struct QuadObject *next; } QuadObject;
    /* One square of the tree: the objects it holds, how many there are, and its
     * four child squares once it has been cut. */
    typedef struct QuadSquare { QuadObject *objects; s32 count; struct QuadSquare *children; } QuadSquare;
    typedef struct { f32 x0, y0, x1, y1; } Rect;
    Rect r[4];
    u8 hit[4];
    s32 count;
    s32 lastHit;
    s32 i;
    s32 j;
    f32 mx, my, w, h;
    QuadObject *leaf;
    QuadSquare *square = (QuadSquare *)node;

    mx = QUARTER * (x0 + x1);
    my = QUARTER * (y0 + y1);
    count = 0;
    r[0].x0 = x0; r[0].y0 = y0; r[0].x1 = mx; r[0].y1 = my;
    r[1].x0 = mx; r[1].y0 = y0; r[1].x1 = x1; r[1].y1 = my;
    r[2].x0 = x0; r[2].y0 = my; r[2].x1 = mx; r[2].y1 = y1;
    r[3].x0 = mx; r[3].y0 = my; r[3].x1 = x1; r[3].y1 = y1;
    lastHit = -1;
    *(s32 *)hit = 0;
    for (i = 0; i < 4; i++) {
        if (ObjectBox[0] < r[i].x1 && ObjectBox[2] > r[i].x0
            && ObjectBox[1] < r[i].y1 && ObjectBox[3] > r[i].y0) {
            hit[i] = 1;
            lastHit = i;
            count++;
        }
    }
    if (count == 0) {
        Abend_Panic(NOT_IN_ANY);
        return;
    }
    if (count == 1) {
        if (square->children == 0) {
            square->children = (QuadSquare *)NewArray(AllocBlock(0x40, CHILDREN_TAG), Square_Init, Square_Destroy, 0xC, 4);
        }
        ((AddObject)quadTreeAddObject)(object, index, (char *)square->children + lastHit * 0xC, depth + 1,
                           r[lastHit].x0, r[lastHit].y0, r[lastHit].x1, r[lastHit].y1);
        return;
    }
    w = x1 - x0;
    h = y1 - y0;
    w = w > h ? w : h;
    if (w < MIN_SQUARE) {
        leaf = &((QuadObject *)LeafPool)[LeafUsed++];
        leaf->object = object;
        leaf->index = index;
        leaf->next = square->objects;
        square->objects = leaf;
        square->count++;
        LeafTotal++;
        return;
    }
    if (square->children == 0) {
        square->children = (QuadSquare *)NewArray(AllocBlock(0x40, CHILDREN_TAG), Square_Init, Square_Destroy, 0xC, 4);
    }
    for (j = 0; j < 4; j++) {
        if (hit[j] != 0) {
            ((AddObject)quadTreeAddObject)(object, index, (char *)square->children + j * 0xC, depth + 1,
                               r[j].x0, r[j].y0, r[j].x1, r[j].y1);
        }
    }
    #undef QUARTER
    #undef MIN_SQUARE
    #undef ObjectBox
    #undef NOT_IN_ANY
    #undef CHILDREN_TAG
    #undef LeafPool
    #undef LeafUsed
    #undef LeafTotal
    #undef NewArray
    #undef AllocBlock
    #undef Square_Init
    #undef Square_Destroy
}
#pragma scheduling on
void *fn_801B591C(void *self, s32 deleteFlag) {
    /* Recursively destroy the child array stored at offset 8, then optionally free this node. */
    if (self != NULL) {
        s32 child = *(s32 *)((u8 *)self + 8);
        if (child != 0) {
            ((void (*)(void *, void *(*)(void *, s32)))fn_8002F6AC)((void *)child, fn_801B591C);
        }
        if (deleteFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

extern s32 lbl_8055E6E8;
extern s32 lbl_8055E6EC;
extern u8 lbl_80435EC8[];
extern void fn_801A49FC(void *);
extern void fn_80128658(void *);
/* Init callback for fn_8002F37C: zero a quad-tree node's three words (nodes,
   count, children), bump the live-node counter lbl_8055E6E8, and return the node. */
void *fn_801B5984(void *node) {
    register s32 *fields = (s32 *)node;
    fields[1] = 0; fields[2] = 0; fields[0] = 0;
    lbl_8055E6E8 = lbl_8055E6E8 + 1;
    return node;
}

void fn_801B59A4(void *arg0, s32 arg1, s32 arg2) {
    extern u8 lbl_80435EC8[];
    struct Entry { struct Entry *nodes; s32 count; struct Entry *children; } *entry = (struct Entry *)arg0;
    struct Holder { s32 p; } idxHolder;
    s32 *idx = &idxHolder.p;
    u16 *records; u16 *record; struct Entry *node; u16 value;
    s32 offset; s32 childStart; s32 w;
    s32 max = *(s32 *)(lbl_80435EC8 + 4);
    if (arg2 >= max) { *(s32 *)(lbl_80435EC8 + 4) = arg2 + 1; }
    records = *(u16 **)(lbl_80435EC8 + 0xC);
    records[arg2 * 4] = *(s32 *)lbl_80435EC8;
    record = records + arg2 * 4;
    record[1] = *(s32 *)lbl_80435EC8 + (u16)entry->count;
    record[3] = 0;
    if (entry->children != NULL) { record[2] = *(s32 *)(lbl_80435EC8 + 4); } else { record[2] = 0; }
    node = entry->nodes;
    while (node != NULL) {
        value = (u16)node->count;
        *idx = *(s32 *)(lbl_80435EC8 + 0x10);
        (*(u16 **)(lbl_80435EC8 + 0x18))[(*idx)++] = value;
        *(s32 *)(lbl_80435EC8 + 0x10) = *idx;
        node = *(struct Entry **)((u8 *)node + 8);
    }
    *(s32 *)lbl_80435EC8 = *(s32 *)lbl_80435EC8 + entry->count;
    if (entry->children != NULL) {
        childStart = record[2];
        *(s32 *)(lbl_80435EC8 + 4) += 4;
        w = 0; offset = 0;
        do {
            fn_801B59A4((u8 *)entry->children + offset, arg1 + 1, childStart++);
            w++; offset += 0xC;
        } while (w < 4);
    }
}
#pragma dont_inline on
void fn_801B5AE4(void) {
    /* Reset the BPX quad-tree linking allocator: zero both node counters and clear its 0x1C-byte state block. */
    u8 *workspace;
    lbl_8055E6E8 = 0;
    workspace = lbl_80435EC8;
    lbl_8055E6EC = 0;
    memset(workspace, 0, 0x1C);
}
#pragma dont_inline reset

#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_801B5B04(void *arg0, void **arg1, s32 arg2) {
    class V {
    public:
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(float *, float *);
    };
    f32 outA[3];
    f32 outB[3];
    void **item;
    s32 i;
    void *obj;
    register f32 base = 4.0f;

    item = arg1;
    for (i = 0; i < arg2; i++) {
        obj = *item;
        obj = *(void **)((u8 *)obj + 0x3C);
        ((V *)obj)->m12(outA, outB);
        lbl_80435EB8[1] = outA[2] - base;
        lbl_80435EB8[0] = outA[0] - base;
        lbl_80435EB8[2] = base + outB[0];
        lbl_80435EB8[3] = base + outB[2];
        quadTreeAddObject(*item, i, arg0, 0, lbl_805626A4, lbl_805626A4, lbl_805626A8, lbl_805626A8, base + outB[0], outA[2] - base);
        item++;
    }
}
#pragma pop
/* Copies the first `count` links of an object list, starting at `link`,
 * into the array `out` (the list fn_801B5D10 counts). */
void fn_801B5BDC(void **out, s32 count, void *link) {
    void **dst = out;
    struct ObjectLink *node = link;
    for (; count > 0; count--) {
        *dst++ = node;
        node = node->next;
    }
}
#pragma push
#pragma cplusplus on
extern "C" void fn_801B5C58(void *container) {
    /* Destroy each entry's contents and owned subobject, then destroy the container. */
    class D {
    public:
        virtual void m0(int);
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9(int);
    };
    s32 offset = 0;
    s32 i = 0;
    void *entry;
    void *owned;

    while (i < *(s32 *)container) {
        entry = *(void **)((unsigned char *)container + 4);
        entry = *(void **)((unsigned char *)entry + offset);
        fn_801A49FC(entry);
        entry = *(void **)((unsigned char *)container + 4);
        entry = *(void **)((unsigned char *)entry + offset);
        owned = *(void **)((unsigned char *)entry + 0x3C);
        if (owned != 0) {
            ((D *)owned)->m0(1);
        }
        entry = *(void **)((unsigned char *)container + 4);
        entry = *(void **)((unsigned char *)entry + offset);
        if (entry != 0) {
            ((D *)entry)->m9(1);
        }
        offset += 4;
        i++;
    }
    fn_80128658(container);
}
#pragma pop
/* Count the links in the object list headed by `link`, following each
 * ObjectLink.next at +0x44 until the NULL terminator. */
s32 fn_801B5D10(struct ObjectLink *link) {
    s32 count = 0;
    goto check;
loop:
    link = link->next;
    count++;
check:
    if (link != NULL) goto loop;
    return count;
}

extern s32 lbl_8055E6F0;
extern void *lbl_8055E6F4;
extern u8 lbl_80335EC8[];
extern u8 lbl_80335ED4[];
extern u8 lbl_8055A8C8[1];
extern void *fn_8012850C(s32, void *);
extern void *fn_801284E8(void *, s32);
extern void fn_80128670(void *);
#pragma dont_inline on
void *fn_801B5D30(s32 *arg0)
{
  s32 tmp1[3];
  s32 tmp2[3];
  s32 size;
  s32 ec;
  void *buf;
  QuadNode *obj;
  void *p;
  s32 count;
  void *q;
  fn_801B5AE4();
  linkNearbyBpxObjects(*arg0);
  count = fn_801B5D10((void *) (*arg0));
  size = count * 4;
  buf = fn_8012850C(size, lbl_80335EC8);
  fn_801B5BDC(buf, count, (void *) (*arg0));
  tmp1[1] = 0;
  tmp1[2] = 0;
  tmp1[0] = 0;
  lbl_8055E6E8++;
  lbl_8055E6F0 = 0;
  lbl_8055E6F4 = fn_8012850C(0x60000, lbl_80335ED4);
  fn_801B5B04(tmp1, buf, count);
  fn_80128670(buf);
  fn_80128670(lbl_8055E6F4);
  lbl_8055E6F4 = NULL;
  if (tmp1[2] != 0)
  {
    ((void (*)(void *, void *(*)(void *, s32))) fn_8002F6AC)((void *) tmp1[2], fn_801B591C);
  }
  obj = (QuadNode *) fn_801284E8(lbl_8055A8C8, (((lbl_8055E6EC * 2) + (lbl_8055E6E8 * 8)) + size) + 0x18);
  obj->count = count;
  p = ((u8 *) obj) + 0x18;
  q = ((u8 *) p) + (count * 4U);
  ec = lbl_8055E6EC;
  obj->e6ec = ec;
  obj->p = (s32) p;
  obj->q = (s32) q;
  obj->tail = (s32) (((u8 *) q) + (ec * 2));
  obj->callback = (s32) fn_801B5C58;
  fn_801B5BDC(p, count, (void *) (*arg0));
  tmp2[1] = 0;
  tmp2[2] = 0;
  tmp2[0] = 0;
  lbl_8055E6E8++;
  lbl_8055E6F0 = 0;
  lbl_8055E6F4 = fn_8012850C(0x60000, lbl_80335ED4);
  fn_801B5B04(tmp2, (void **) obj->p, obj->count);
  memset(lbl_80435EC8, 0, 0x1C);
  *((s32 *) lbl_80435EC8) = 0;
  *((s32 *) (lbl_80435EC8 + 8)) = lbl_8055E6E8;
  *((s32 *) (lbl_80435EC8 + 0xC)) = obj->tail;
  *((s32 *) (lbl_80435EC8 + 0x14)) = obj->e6ec;
  *((s32 *) (lbl_80435EC8 + 0x18)) = obj->q;
  fn_801B59A4(tmp2, 0, 0);
  fn_80128670(lbl_8055E6F4);
  lbl_8055E6F4 = NULL;
  *arg0 = 0;
  if (tmp2[2] != 0)
  {
    ((void (*)(void *, void *(*)(void *, s32))) fn_8002F6AC)((void *) tmp2[2], fn_801B591C);
  }
  return obj;
}
#pragma dont_inline off

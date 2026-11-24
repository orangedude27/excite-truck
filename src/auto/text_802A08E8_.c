#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 *lbl_8055F834;
typedef struct Rec54 { u32 w[21]; } Rec54;
typedef struct Rec48 { u32 w[18]; } Rec48;
extern int lbl_8055CB68;
extern int fn_80128670(int);
extern long fn_801EF024(long (*)(void *));
extern void fn_802CAC54(int);
extern void fn_80128668(void*);
void *fn_802A08E8(void *object, s32 shouldDelete) {
    /* Clear three word fields and optionally free the object (destructor helper). */
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

// No-op callback registered by fn_802A086C via fn_8002F53C for the global at
// lbl_804B5070 (size 0x78, alignment 0x40); the object needs no cleanup, so it
// just returns.
void fn_802A0940(void) {
}

s32 fn_802A0944(void *arg0)
{
  char index;
  Rec54 *table = (Rec54 *) lbl_8055F834;
  volatile unsigned int pad;
  if ((*((s32 *) arg0)) != 1)
  {
    index = *(((s32 *) arg0) + 1);
  }
  else
  {
    index = 0x3F - (*(((s32 *) arg0) + 1));
  }
  table[index] = *((Rec54 *) arg0);
  return 0x54;
}

extern void fn_8012850C(void *, void *);
extern void *fn_8002F37C(void *, int, int, int);
extern int fn_802CAC28(void *, int);
extern void Event_RegisterHandler(int, unsigned int);
extern void fn_802A0AF8(void);
extern char lbl_803498E0[];
extern char lbl_803498EC[];
void fn_802A09B0(void) {
    s32 offset = 0;
    s32 zero = 0;
    s32 counter = 4;
    u8 *base;
    lbl_8055F834 = (u8 *)((void *(*)(void *, void (*)(void), int, int, int))fn_8002F37C)(
        (void *)((s32 (*)(void *, void *))fn_8012850C)((void *)0x1510, lbl_803498E0),
        fn_802A0AF8, 0, 0x54, 0x40);
    for (; counter != 0; --counter) {
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 8) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x5C) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0xB0) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x104) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x158) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x1AC) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x200) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x254) = zero;
        offset += 0x2A0;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 8) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x5C) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0xB0) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x104) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x158) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x1AC) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x200) = zero;
        base = *(u8 * volatile *)&lbl_8055F834 + offset;
        *(s32 *)(base + 0x254) = zero;
        offset += 0x2A0;
    }
    lbl_8055CB68 = fn_802CAC28(lbl_803498EC, 0);
    Event_RegisterHandler((int)fn_802A0944, 6);
}

void fn_802A0AF8(void) {
    /* Empty per-element initializer callback passed to fn_8002F37C when
       fn_802A09B0 allocates the 64-element array of 0x54-byte chain-link
       records (lbl_8055F834).  Invoked once per element, it does nothing;
       compiles to a bare 'blr'. */
}

/* Chain-link fence module shutdown (suggested name ChainLink_Shutdown;
 * rename_symbol is refused here, so the name only lives in this comment).
 * Counterpart of fn_802A09B0 and called from the game's subsystem teardown
 * list fn_802878A8: drops the module's event handler, releases its fence
 * texture and frees the record table the handler fills. */
void fn_802A0AFC(void) {
    /* The module's globals: the 64 0x54-byte chain-link records fn_802A0944
     * stores from event type 6 (heap block named "chainlink"), and the
     * "fencepol.tex" texture handle fn_802A0B54 draws those records with. */
#define chainLinkRecords lbl_8055F834
#define fenceTextureHandle lbl_8055CB68
#define ChainLinkEventHandler fn_802A0944 /* event type 6 handler set by fn_802A09B0 */
#define UnregisterEventHandler fn_801EF024
#define ReleaseTexture fn_802CAC54
#define FreeBlock fn_80128670
#define TEXTURE_HANDLE_FREE (-2) /* fn_802CAC28's "no texture" handle value */
#define BLOCK_HEADER 0x10        /* header fn_8012850C puts before the block it returns */

    UnregisterEventHandler(ChainLinkEventHandler);
    ReleaseTexture(fenceTextureHandle);
    {
        int tableAddress = (int)chainLinkRecords;
        fenceTextureHandle = TEXTURE_HANDLE_FREE;
        if (tableAddress != 0) FreeBlock(tableAddress - BLOCK_HEADER);
        chainLinkRecords = 0;
    }
#undef chainLinkRecords
#undef fenceTextureHandle
#undef ChainLinkEventHandler
#undef UnregisterEventHandler
#undef ReleaseTexture
#undef FreeBlock
#undef TEXTURE_HANDLE_FREE
#undef BLOCK_HEADER
}

/* No-op subsystem initialization step in fn_8028797C; this build leaves it empty. */
void fn_802A0B50(void) {
}

extern float lbl_805646D0, lbl_805646D4, lbl_805646D8, lbl_805646DC;
extern double lbl_805646E0;
extern void fn_802C8BD0(int);
extern void DrawList_RestoreNormalMode(void);
extern void fn_802C8DB8(void *, int, short *, int);
typedef struct {
    float f0;
    float f4;
    float f8;
    int unk0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    int unk24;
    float f28;
    float f2C;
} Fn802A0B54Vertex;

typedef union {
    double value;
    struct {
        u32 high;
        u32 low;
    } words;
} Fn802A0B54FloatConv;

typedef struct {
    short indices[0x20];
    Fn802A0B54Vertex vertices[6];
} Fn802A0B54Work;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma ppc_psq_save off
void fn_802A0B54(void) {
    Fn802A0B54Work work;
    int offset;
    int outer;
    int first;
    int count;

    float scale;
    float add;
    float size;
    float base;
    float f3;
    float f0;
    float f4;
    u8 *record;
    fn_802C8BD0(lbl_8055CB68);
    scale = lbl_805646D8;
    add = lbl_805646DC;
    size = lbl_805646D0;
    base = lbl_805646D4;
    offset = 0;
    outer = 0;
    do {
        record = lbl_8055F834 + offset;
        count = *(int *)(record + 8);
        if (count > 1) {
            first = *(int *)record;
            f3 = size * (float)first;
            f0 = size + f3;
            f4 = base + (float)(first * 6);
            for (first = 0; first < *(int *)(record + 8); first++) {
                Fn802A0B54Vertex *v = &work.vertices[first];
                float f = ((float)first / scale) * f4;
                v->f0 = *(float *)(record + 0xC);
                v->f4 = *(float *)(record + 0x10);
                v->f8 = *(float *)(record + 0x14);
                v->f10 = f;
                v->f14 = f3;
                v->unk0C = -1;
                *(int *)((u8 *)v + 0x18) = *(int *)((u8 *)v + 0x0);
                *(int *)((u8 *)v + 0x1C) = *(int *)((u8 *)v + 0x4);
                *(int *)((u8 *)v + 0x20) = *(int *)((u8 *)v + 0x8);
                v->unk24 = -1;
                v->f28 = (float)f;
                *(float *)((u8 *)v + 0x1C) = *(float *)((u8 *)v + 0x1C) + add;
                v->f2C = f0;
                if (first > 0) {
                    short *idx = work.indices + (first - 1) * 6;
                    int baseIdx = (first - 1) * 2;
                    idx[0] = (short)baseIdx;
                    idx[1] = (short)(baseIdx + 2);
                    idx[2] = (short)(baseIdx + 1);
                    idx[3] = (short)(baseIdx + 1);
                    idx[4] = (short)(baseIdx + 2);
                    idx[5] = (short)(baseIdx + 3);
                }
                record += 0xC;
            }
            fn_802C8DB8(work.vertices, count * 2, work.indices, (count - 1) * 6);
        }
        outer++;
        offset += 0x54;
    } while (outer < 0x40);
    DrawList_RestoreNormalMode();
}
#pragma pop

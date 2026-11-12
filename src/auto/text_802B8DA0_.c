#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_801602B0(void *);
extern float fn_80141C9C(float);
extern float lbl_80564CB0;
extern float lbl_80564CC8;
extern double lbl_80564CB8;
extern char lbl_8034AA74[];
extern char lbl_8034AA84[];
extern char lbl_8034AA90[];
extern char lbl_8055CF00[];
void fn_802B9B40(void *);
void fn_802B9B2C(void *);
void *fn_802B9AD4(void *, s32);
void fn_802B9964(void *, s32, s32, s32);
float fn_802B9A80(float);
void *fn_802BE844(s32, s32, s32);
void fn_802B9960(void);
void fn_802B9AC8(void);
int fn_802B9100(void);
void fn_802B98D0(void *);
s32 fn_802B9ACC(void *);
void fn_802B9AA4(void *, float *, float *);
int fn_802B9920(int);
short fn_802B9954(void *);
int fn_802B9914(void *);

typedef struct RenderBatch { u16 **items; int count; int unused; struct RenderBatch *next; } RenderBatch;
typedef struct RenderNode { RenderBatch *batches; int count; int type; u8 enabled; char pad[3]; struct RenderNode *next; char data[0x40]; } RenderNode;
typedef struct RenderEntry { void *name; int state; int kind; RenderNode *nodes; } RenderEntry;
typedef struct RenderList { RenderEntry **items; int count; } RenderList;
typedef struct RenderMatrix { int words[8]; } RenderMatrix;
extern int lbl_802FAB40[];
extern void fn_802C21B8(void), fn_802C28C0(void), fn_802C8BD0(void), fn_802C8D74(void), fn_802DC130(void), fn_802DC134(void), fn_802DC278(void), fn_802DC27C(void);
extern void fn_802CADD0(int,int), fn_802D3D94(int,void*,...);
extern void fn_802DC138(int,int,void*,int), fn_802DC280(int,int,void*,int);
int fn_8012C33C(void);
extern double cos(double);
extern double sin(double);
extern void *fn_801284F8(int, void *);
extern void fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, int, int, int);
extern void fn_802BAE30(void *);
extern char lbl_8034A9F4[];
extern int lbl_8055CEF0;
extern char lbl_8034A990[];
extern char lbl_8034AA1C[];
extern void fn_802B8AE0(void *, void *);
extern void fn_802B9CF4(void *);
extern void *fn_802B9C9C(void *, s32);
extern void *lbl_8055FA7C;
extern char lbl_804BFFF4[];
extern int lbl_8055FA6C, lbl_8055FA70;
extern void *lbl_8055FA74;
int fn_802CAC28(int, int);
void fn_802B9FC0(void *);
int fn_80128668(void *);
void fn_8002F6AC(int, void (*)(void));
extern char lbl_804BFFE8[];
extern int lbl_804C0088[];
extern char lbl_8055CEC8;
extern int lbl_8055CECC;
extern char lbl_8034AA2C[];
extern int fn_802B110C(void *, char *);
extern int fn_802E317C(const char *, ...);
extern void *lbl_8055FA78;
extern void *lbl_8055FA80;
void fn_802B9DD0(void *);
void fn_802B9E4C(void *);
void fn_802B9EC8(void *);
void fn_802B9F38(void **);
int fn_802CAC54(void);
void* fn_802B8DA0(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void* fn_802B8DF8(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_802B8E50(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void *fn_802BE844(s32, s32, s32);
void *fn_802B8EB8(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    s32 sign = (s32)(arg2 >> 31);
    s32 sum = sign + arg2;
    s32 half = sum >> 1;
    s32 x;
    s32 y;
    s16 shortX;
    x = arg0 - half;
    if (arg3 & 1) {
        x = arg0 + half;
    }
    shortX = (s16)x;
    y = arg1 - half;
    if (arg3 & 2) {
        y = arg1 + half;
    }
    return fn_802BE844(shortX, (s16)y, half);
}

#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void *fn_802B8EF0(int arg0, void *arg1) {
    struct Entry {
        char *name;
        int state;
        void *data;
        int reserved;
    };
    struct List {
        void **items;
        int count;
    };
    void **table = (void **)lbl_804C0088;
    struct Entry *entry = (struct Entry *)table[arg0];
    void *data;
    char *name;
    int state;
    struct List *list;
    int count;
    void **items;
    if (entry == 0) {
        name = (char *)&lbl_8055CEC8;
        entry = (struct Entry *)fn_801284F8(0x10, (void *)&lbl_8055CECC);
        if (entry != 0) {
            entry->name = name;
            data = *(void **)((char *)arg1 + 8);
            if ((signed char)*name != 0)
                state = fn_802B110C((void *)fn_802B8E50, name);
            else
                state = -2;
            entry->state = state;
            if (state == -2 && (signed char)*name != 0)
                fn_802E317C(lbl_8034AA2C, name);
            entry->reserved = 0;
            entry->data = data;
        }
        table[arg0] = entry;
        list = (struct List *)lbl_804BFFF4;
        items = list->items;
        count = list->count;
        list->count = count + 1;
        items[count] = (void *)entry;
    }
    return table[arg0];
}
#pragma pop
#pragma push
#pragma scheduling invalid_target

extern void *fn_802B59CC();
extern void fn_801345D8(void *, int, const char *, ...);
extern int lbl_804C004C[];
extern const float lbl_80564CC0;
extern float lbl_80564CC4;
extern char lbl_8055CED4;
extern char lbl_8055CEDC;
extern char lbl_8055CEE4;
extern char lbl_8034A990[];
#pragma cplusplus on
/* Takes the next free record out of the road-record pool at lbl_804C004C
 * ({ records, count }) and fills it in from the game's config access
 * (fn_802B59CC): the entry named "road<road+1>", or plain "road" when that one
 * is missing, supplies this road's texture scale ("tex_scale_v", default
 * lbl_80564CC0) and draw priority ("prio", default 0).  The record's first
 * word is a placeholder the caller replaces.
 */
extern "C" void *fn_802B8FE0(int road) {
    struct RoadRecord {
        float value;    /* set to lbl_80564CC4 here, overwritten by the caller */
        float texScaleV;
        int prio;
    };
    /* The game's config/parameter access object; slots the record uses are
       named, the rest only hold the vtable open (first method = 0x8). */
    class ETConfigAccess {
    public:
        virtual void unused08();
        virtual void unused0C();
        virtual void unused10();
        virtual void unused14();
        virtual void unused18();
        virtual void unused1C();
        virtual int getInteger(const char *, int);
        virtual void unused24();
        virtual float getFloat(const char *, float);
        virtual void unused2C();
        virtual void unused30();
        virtual void unused34();
        virtual void unused38();
        virtual void unused3C();
        virtual void unused40();
        virtual void unused44();
        virtual void unused48();
        virtual void unused4C();
        virtual void unused50();
        virtual void unused54();
        virtual void unused58();
        virtual ETConfigAccess *find(const char *);
    };
    float defaultTexScaleV = lbl_80564CC0;
    int defaultPrio = 0;
    int *pool;
    void *records;
    int index;
    int offset;
    int count;
    struct RoadRecord *record;
    void *rawConfig;
    char name[0x20];
    ETConfigAccess *config;
    ETConfigAccess *roadConfig;

    pool = lbl_804C004C;
    records = (void *)pool[0];
    index = pool[1];
    offset = index * 12;
    count = index + 1;
    pool[1] = count;
    record = (struct RoadRecord *)((char *)records + offset);
    record->prio = defaultPrio;
    record->texScaleV = defaultTexScaleV;

    rawConfig = fn_802B59CC();
    fn_801345D8(name, 0x20, (const char *)&lbl_8055CED4, road + 1);

    config = (ETConfigAccess *)rawConfig;
    roadConfig = config->find(name);
    if (roadConfig == 0)
        roadConfig = config->find((const char *)&lbl_8055CEDC);

    if (roadConfig != 0) {
        record->texScaleV = roadConfig->getFloat(lbl_8034A990, record->texScaleV);
        record->prio = roadConfig->getInteger((const char *)&lbl_8055CEE4, record->prio);
    }

    record->value = lbl_80564CC4;
    return record;
}
#pragma cplusplus reset

#pragma pop
int fn_802B9100(void) {
    return 0;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_802B9108(short arg0) {
    typedef struct Node {
        void *data;
        s32 used;
        s32 capacity;
        struct Node *next;
    } Node;
    typedef struct Pool {
        void *unused;
        Node *nodes;
        s32 used;
        s32 capacity;
    } Pool;
    struct Frame {
        float vec1[2];
        float vec2[2];
        short sz;
        void *grid;
        s32 gridCount;
        void *mgr;
        void **items;
        s32 itemCount;
        s32 itemCap;
        void *itemBuf[64];
    } frame;
    float k1;
    float k2;
    float f27;
    float f28;
    s32 denom;
    s32 i;
    s32 off;
    s32 idx;
    void *entry;
    s32 kind;
    void *node;
    s16 v1;
    s16 v2;
    s16 v3;
    s16 v4;
    s32 gx;
    s32 gy;
    s32 step;
    s32 t;
    void **cell;
    void **p;
    void *item;
    s32 found;
    s32 ii;
    s32 rows;
    s32 cellIdx;
    Node **cellPtr;
    Node *tail;
    void *slot;
    Node *newNode;
    s32 used;
    s32 fx;
    s32 fy;
    void *record;
    s32 savedCount;
    Node *cellNode;
    s32 flag;
    void *obj;
    void *glist;
    s32 cnt;
    s32 cnt2;
    s32 gc;
    s32 knd;
    void *pp;
    void *recs;
    frame.sz = arg0;
    denom = frame.sz * 2;
    frame.gridCount = (0x400 / denom) * (0x400 / denom);
    frame.grid = ((void *(*)(void *, void *, int, int, int))fn_8002F37C)(((void *(*)(int, void *))fn_8012850C)(frame.gridCount * 8 + 0x10, lbl_8055CF00), fn_802B9B40, 0, 8, frame.gridCount);
    frame.mgr = fn_801284F8(0x14, lbl_8034AA84);
    if (frame.mgr != 0) {
        cnt = (frame.gridCount * 6) / 4;
        recs = ((void *(*)(void *, void *, int, int, int))fn_8002F37C)(((void *(*)(int, void *))fn_8012850C)(cnt * 0x10 + 0x10, &lbl_8055CEF0), fn_802B9B2C, (int)fn_802B9AD4, 0x10, cnt);
        ((void **)frame.mgr)[1] = recs;
        ((s32 *)frame.mgr)[3] = cnt;
        ((s32 *)frame.mgr)[2] = 0;
        ((void **)frame.mgr)[4] = recs;
        ((void **)frame.mgr)[0] = ((void *(*)(int, void *))fn_8012850C)(cnt * 0x10, lbl_8034AA74);
        off = 0;
        for (i = 0; i < ((s32 *)frame.mgr)[3]; i++) {
            idx = ((s32 *)frame.mgr)[2];
            ((s32 *)frame.mgr)[2] = idx + 1;
            cell = (void **)((char *)recs + idx * 0x10);
            *cell = (char *)((void **)frame.mgr)[0] + off;
            off += 0x10;
            ((s32 *)cell)[2] = 4;
            ((s32 *)cell)[1] = 0;
        }
        ((s32 *)frame.mgr)[2] = 0;
    }
    k1 = lbl_80564CB0;
    k2 = lbl_80564CC8;
    for (i = 0, off = 0; i < *(s32 *)(lbl_804BFFF4 + 4); i++, off += 4) {
        entry = *(void **)(*(char **)lbl_804BFFF4 + off);
        kind = fn_802B9ACC((char *)entry + 0xC);
        if (kind != 2) {
            if (kind < 2) {
                if (kind >= 0) {
                    if (frame.sz == 4) {
                        node = *(void **)((char *)entry + 0xC);
                        f27 = (float)frame.sz * k1;
                        f28 = k2 * f27;
                        while (node != 0) {
                            fn_801602B0(frame.vec1);
                            fn_801602B0(frame.vec2);
                            fn_802B9AA4(((void *(*)(void *))fn_802B9AC8)(node), frame.vec1, frame.vec2);
                            v1 = (s16)((f27 + f28 * fn_80141C9C(frame.vec1[0] / f28)) / k1);
                            v2 = (s16)((f27 + f28 * fn_80141C9C(frame.vec1[1] / f28)) / k1);
                            v3 = (s16)((f28 * fn_802B9A80(frame.vec2[0] / f28) - f27) / k1);
                            v4 = (s16)((f28 * fn_802B9A80(frame.vec2[1] / f28) - f27) / k1);
                            for (v1 = v1; v1 <= v3; v1 = (s16)(v1 + frame.sz * 2)) {
                                for (v2 = v2; v2 <= v4; v2 = (s16)(v2 + frame.sz * 2)) {
                                    fn_802B9964(&frame.sz, (s32)node, v1, v2);
                                }
                            }
                            node = *(void **)((char *)node + 0x10);
                        }
                    }
                }
            }
        } else {
            node = *(void **)((char *)entry + 0xC);
            while (node != 0) {
                pp = ((void *(*)(void *))fn_802B9960)(node);
                if (frame.sz == fn_802B9920(fn_802B9954(pp))) {
                    fn_802B9964(&frame.sz, (s32)node, fn_802B9954(pp), fn_802B9914(pp));
                }
                node = *(void **)((char *)node + 0x10);
            }
        }
    }
    if (frame.sz > 4 && frame.sz <= 8) {
        step = denom;
        gx = frame.sz - 0x200;
        for (; gx < 0x200; gx += step) {
            gy = frame.sz - 0x200;
            for (; gy < 0x200; gy += step) {
                frame.items = frame.itemBuf;
                frame.itemCount = 0;
                frame.itemCap = 0x40;
                for (t = 0; t < 4; t++) {
                    cell = (void **)fn_802B8EB8((short)gx, (short)gy, frame.sz, t);
                    p = *cell;
                    while (*p != 0) {
                        item = *p;
                        kind = ((s32 *)item)[2];
                        if ((u32)kind <= 1U) {
                            found = -1;
                            for (ii = 0; ii < frame.itemCount; ii++) {
                                if (frame.items[ii] == item) { found = ii; break; }
                            }
                            if (found == -1 && frame.itemCount + 1 <= frame.itemCap && ((u32)kind != 1U || frame.sz <= 4)) {
                                frame.items[frame.itemCount] = item;
                                frame.itemCount++;
                            }
                        }
                        p++;
                    }
                }
                rows = 0x400 / denom;
                for (ii = 0; ii < frame.itemCount; ii++) {
                    cellIdx = ((gy - frame.sz + 0x200) / denom) * rows + ((gx - frame.sz + 0x200) / denom);
                    cellPtr = (Node **)((char *)frame.grid + cellIdx * 8);
                    tail = cellPtr[1];
                    slot = 0;
                    if (tail == 0 || tail->used + 1 > tail->capacity) {
                        newNode = 0;
                        if (((Pool *)frame.mgr)->used + 1 <= ((Pool *)frame.mgr)->capacity) {
                            used = ((Pool *)frame.mgr)->used;
                            newNode = &((Pool *)frame.mgr)->nodes[used];
                            ((Pool *)frame.mgr)->used = used + 1;
                            newNode->used = 0;
                            newNode->next = 0;
                        }
                        if (newNode != 0) {
                            if (cellPtr[0] == 0) cellPtr[0] = newNode;
                            if (cellPtr[1] != 0) cellPtr[1]->next = newNode;
                            cellPtr[1] = newNode;
                            newNode->next = 0;
                            tail = cellPtr[1];
                            slot = (char *)tail->data + tail->used * 4;
                            tail->used = tail->used + 1;
                        }
                    } else {
                        slot = (char *)tail->data + tail->used * 4;
                        tail->used = tail->used + 1;
                    }
                    if (slot != 0) *(void **)slot = frame.items[ii];
                }
                frame.items = 0;
                frame.itemCount = 0;
                frame.itemCap = 0;
            }
        }
    }
    fx = arg0 - 0x200;
    for (; fx < 0x200; fx += denom) {
        fy = arg0 - 0x200;
        for (; fy < 0x200; fy += denom) {
            record = fn_802BE844((short)fx, (short)fy, arg0);
            glist = lbl_8055FA80;
            savedCount = ((s32 *)glist)[1];
            rows = 0x400 / denom;
            cellIdx = ((fy - frame.sz + 0x200) / denom) * rows + ((fx - frame.sz + 0x200) / denom);
            cellNode = *(Node **)((char *)frame.grid + cellIdx * 8);
            while (cellNode != 0) {
                cnt2 = cellNode->used;
                for (ii = 0; ii < cnt2; ii++) {
                    item = ((void **)cellNode->data)[ii];
                    knd = ((s32 *)item)[2];
                    if ((u32)knd == 2U && ((int (*)(void *))fn_802B9100)(record) == 0) {
                        glist = lbl_8055FA80;
                        gc = ((s32 *)glist)[1];
                        ((s32 *)glist)[1] = gc + 1;
                        ((void ***)glist)[0][gc] = item;
                        flag = 0;
                        if ((u32)((s32 *)item)[2] == 2U) {
                            obj = ((void *(*)())fn_802B59CC)();
                            if (((s32 (**)(void *, void *, s32))(*(void **)obj))[12](obj, lbl_8034AA90, 1) != 0) flag = 1;
                        }
                        if (flag != 0) ((s32 *)record)[2] |= 0x800000;
                    }
                    if ((u32)((s32 *)item)[2] == 2U) ((s32 *)record)[2] |= 0x1000000;
                }
                cellNode = cellNode->next;
            }
            glist = lbl_8055FA80;
            gc = ((s32 *)glist)[1];
            ((s32 *)glist)[1] = gc + 1;
            ((void ***)glist)[0][gc] = 0;
            ((void **)record)[0] = (char *)((void ***)glist)[0] + savedCount * 4;
        }
    }
    if (frame.mgr != 0) {
        fn_802B98D0(frame.mgr);
        if ((char *)frame.mgr + 4 != 0) {
            fn_8002F6AC(((s32 *)frame.mgr)[4], (void (*)(void))fn_802B9AD4);
            if ((char *)frame.mgr + 4 != 0) {
                ((s32 *)frame.mgr)[1] = 0;
                ((s32 *)frame.mgr)[2] = 0;
                ((s32 *)frame.mgr)[3] = 0;
            }
        }
        fn_80128668(frame.mgr);
    }
    if (frame.grid != 0) {
        fn_80128670((s32)frame.grid - 0x10);
    }
}
#pragma dont_inline off
#pragma pop
void fn_802B98D0(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

int fn_802B9914(void *arg0) {
    return (short)((int *)arg0)[6];
}

extern short lbl_802FAB60[];
#pragma push
#pragma scheduling invalid_target
int fn_802B9920(int arg0) {
    short s = (short)(arg0 + 0x200);
    int v = arg0 + 0x200;
    int sign = (unsigned int)s >> 31;
    int t = (v << 27) - sign;
    int u = (t << 5) | ((unsigned int)t >> 27);
    int w = u + sign;
    short idx = (short)w;
    return lbl_802FAB60[idx];
}
#pragma scheduling on
#pragma pop
short fn_802B9954(void* arg0) {
    return (short)((int*)arg0)[5];
}

void fn_802B9960(void) {
}

void fn_802B9964(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct Node {
        s32 *data;
        volatile s32 used;
        s32 capacity;
        struct Node *next;
    } Node;
    typedef struct Pool {
        void *unused;
        Node *nodes;
        volatile s32 used;
        s32 capacity;
    } Pool;
    s32 size;
    s32 denom, y, rows, x, index, item, used;
    Node **cell;
    Pool *pool;
    Node *node, *new_node, *tail;
    s32 *data, *slot;
    size = *(s16 *)arg0;
    denom = size * 2;
    y = (arg3 - size + 0x200) / denom;
    rows = 1024 / denom;
    x = (arg2 - size + 0x200) / denom;
    index = x + y * rows;
    cell = (Node **)((char *)*(void **)((char *)arg0 + 4) + index * 8);
    pool = *(Pool **)((char *)arg0 + 0xC);
    node = cell[1];
    slot = 0;
    if (node == 0 || node->used + 1 > node->capacity) {
        node = 0;
        if (pool->used + 1 <= pool->capacity) {
            used = pool->used;
            new_node = &pool->nodes[used];
            pool->used = used + 1;
            node = new_node;
            node->used = 0;
            node->next = 0;
        }
        if (node != 0) {
            if (cell[0] == 0) cell[0] = node;
            if (cell[1] != 0) cell[1]->next = node;
            cell[1] = node;
            node->next = 0;
            tail = cell[1];
            item = tail->used;
            data = tail->data;
            tail->used = item + 1;
            slot = data + item;
        }
    } else {
        tail = node;
        item = tail->used;
        data = tail->data;
        tail->used = item + 1;
        slot = data + item;
    }
    if (slot != 0) *slot = arg1;
}

extern double ceil(double);
float fn_802B9A80(float arg0) {
    return ceil(arg0);
}

void fn_802B9AA4(void *arg0, float *arg1, float *arg2) {
    arg1[0] = *(float *)((char *)arg0 + 0x14);
    arg1[1] = *(float *)((char *)arg0 + 0x18);
    arg2[0] = *(float *)((char *)arg0 + 0x1C);
    arg2[1] = *(float *)((char *)arg0 + 0x20);
}

void fn_802B9AC8(void) {
}

s32 fn_802B9ACC(void *arg0) { return ((s32 *)arg0)[2]; }

void* fn_802B9AD4(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802B9B2C(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_802B9B40(void *arg0) {
    ((int *)arg0)[1] = 0;
    ((int *)arg0)[0] = 0;
}

int fn_802B9B50(int **arg0, int **arg1) {
    return (*arg0)[2] - (*arg1)[2];
}

void fn_802B9B68(void) {
    struct Manager {
        void *pool;
        void *records;
        int index;
        int count;
        void *allocation;
    };
    struct Manager *manager;
    void *memory;
    void *pool;
    void *records;
    void *entry;
    int i;
    int offset;
    int index;

    fn_802B8AE0(lbl_8034A990 + 0xC, &lbl_8055FA6C);
    fn_802B8AE0(lbl_8034A990 + 0x18, &lbl_8055FA70);
    memset(lbl_804C0088, 0, 0x10);
    manager = fn_801284F8(0x14, lbl_8034A990 + 0x24);
    if (manager != 0) {
        memory = ((void *(*)(int, void *))fn_8012850C)(0x5010, &lbl_8055CEF0);
        manager->records = ((void *(*)(void *, void (*)(void *),
                          void *(*)(void *, s32), int, int))fn_8002F37C)(
            memory, fn_802B9CF4, fn_802B9C9C, 0x10, 0x500);
        manager->count = 0x500;
        manager->index = 0;
        manager->allocation = manager->records;
        manager->pool = ((void *(*)(int, void *))fn_8012850C)(
            0x500 << 4, lbl_8034AA1C);
        i = 0;
        offset = 0;
        while (i < manager->count) {
            index = manager->index;
            i++;
            pool = manager->pool;
            records = manager->records;
            manager->index = index + 1;
            entry = (char *)records + index * 0x10;
            *(void **)entry = (char *)pool + offset;
            offset += 0x10;
            *(int *)((char *)entry + 8) = 4;
            *(int *)((char *)entry + 4) = 0;
        }
        manager->index = 0;
    }
    lbl_8055FA74 = manager;
    lbl_8055FA7C = 0;
    lbl_8055FA78 = 0;
}

void* fn_802B9C9C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802B9CF4(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

#pragma push
#pragma use_lmw_stmw off
void fn_802B9D08(void) {
    register volatile void **list;
    register unsigned long zero;
    register char *base;
    register void *node;
    register int offset;
    register long i;
    base = lbl_804BFFE8;
    fn_802B9DD0(&lbl_8055FA7C);
    fn_802B9E4C(&lbl_8055FA78);
    list = (volatile void **)(base + 0x0C);
    i = 0;
    offset = 0;
    zero = 0;
    while (i < ((volatile int *)list)[1]) {
        node = *(void **)((char *)list[0] + offset);
        if (node) {
            int v;
            *(int *)((char *)node + 0x0C) = zero;
            v = *(int *)((char *)node + 4);
            if (v != -2) {
                ((int (*)(int))fn_802CAC54)(v);
            }
            fn_80128668(node);
        }
        offset += 4;
        i += 1;
    }
    ((volatile int *)list)[1] = 0;
    {
        char *clear = base + 0x64;
        *(volatile int *)(clear + 4) = 0;
        ((void (*)(void *, void *))fn_802B9EC8)(&lbl_8055FA80, clear);
    }
    memset(base + 0xA0, 0, 0x10);
    fn_802B9F38(&lbl_8055FA74);
}
#pragma pop
void fn_802B9DD0(void* arg0) {
    void* p = *(void**)arg0;
    if (p != NULL) {
        if (p != NULL) {
            int x = ((int*)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != NULL) {
                ((int*)p)[0] = 0;
                ((int*)p)[1] = 0;
                ((int*)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void**)arg0 = NULL;
    }
}

void fn_802B9E4C(void *arg0) {
    void *p = *(void **)arg0;
    if (p != 0) {
        if (p != 0) {
            int x = ((int *)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != 0) {
                ((int *)p)[0] = 0;
                ((int *)p)[1] = 0;
                ((int *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = 0;
    }
}

void fn_802B9EC8(void *arg0) {
    void *p = *(void **)arg0;
    if (p != 0) {
        if (p != 0) {
            fn_80128670(((s32 *)p)[3]);
            if (p != 0) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = 0;
    }
}

#pragma push
#pragma opt_common_subs off
void fn_802B9F38(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            fn_802B9FC0(ptr);
            if ((char *)ptr + 4 != 0) {
                fn_8002F6AC(((int *)ptr)[4], (void (*)(void))fn_802B9C9C);
                if ((char *)ptr + 4 != 0) {
                    ((int *)ptr)[1] = 0;
                    ((int *)ptr)[2] = 0;
                    ((int *)ptr)[3] = 0;
                }
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
}
#pragma pop
void fn_802B9FC0(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

extern void *lbl_8055FA84;
void fn_802BA004(void) {
    lbl_8055FA84 = 0;
}

#pragma cplusplus on
extern "C" int fn_802E2C20(void *);
extern "C" void fn_801352B8(void *);
extern "C" void fn_80135D60(void *, void *);
extern "C" void *fn_80156A40(void);
extern "C" void *fn_802B8FE0(int);
extern "C" void *fn_80138B4C(void *, void *);
extern "C" void *fn_802B8EF0(int, void *);
extern "C" void fn_80136414(void *, void *, int);
extern "C" void fn_8013530C(void *, int);
extern "C" double fn_8002F234(void *, void *, short, float, float, float);
extern "C" double fn_8002EFB4(void *, float, double, float);
extern "C" void fn_802E30C8(void *, ...);
extern "C" void *lbl_8055FA78;
extern "C" void *lbl_8055FA84;
extern "C" char lbl_8034A9C0[];
extern "C" char lbl_8034A064[];
extern "C" double lbl_80564CD0;
extern "C" float lbl_80564CCC, lbl_80564CC4, lbl_80564CD8;
extern void fn_801352B8(void *);
extern void fn_80135D60(void *, void *);
extern void *fn_80156A40(void);
extern void *fn_802B8FE0(int);
extern void *fn_80138B4C(void *, void *);
extern void *fn_802B8EF0(int, void *);
extern void fn_80136414(void *, void *, int);
extern void fn_8013530C(void *, int);
extern double fn_8002F234(void *, void *, short, float, float, float);
extern double fn_8002EFB4(void *, float, double, float);
extern void *lbl_8055FA78;
extern char lbl_8034A9C0[];
extern char lbl_8034A064[];
extern double lbl_80564CD0;
extern float lbl_80564CCC, lbl_80564CC4, lbl_80564CD8;
#pragma push
#pragma processor 750
extern "C" void fn_802BA010(void *arg0, int arg1) {
    struct Dummy { virtual void v0(); virtual void *v1(int); };
    volatile char scratch[0x40];
    char *sp = (char *)scratch;
    int index, count;
    int state = 2;
    short radius, item;
    void *object = arg0;
    void *buffer, *current, *next, *entry, *record, *pool, *base;
    void *interp, *end;
    float f30, f31, f29;
    float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10;
    *(void *volatile *)(sp + 0x10) = lbl_8034A9C0;
    *(volatile int *)(sp + 0x14) = fn_802E2C20(arg0);
    if (object == 0) object = ((Dummy *)fn_80156A40())->v1(0);
    fn_801352B8(sp + 0x24);
    fn_80135D60(sp + 0x24, object);
    buffer = fn_802B8FE0(arg1);
    current = fn_80138B4C(object, 0);
    if (current != 0) {
        f0 = *(float *)((char *)current + 0x10);
        f31 = lbl_80564CCC;
        f30 = lbl_80564CD8;
        f29 = lbl_80564CC4;
        *(float *)buffer = f31 / f0;
        do {
            next = fn_802B8EF0(arg1, buffer);
            if (next != 0) {
                entry = (char *)current + 0x14;
                index = 0;
                while (index < *(int *)((char *)current + 8)) {
                    fn_80136414(sp + 0x18, sp + 0x24, *(int *)((char *)entry + 4));
                    pool = lbl_8055FA78;
                    count = *(int *)((char *)pool + 4);
                    base = *(void **)pool;
                    *(int *)((char *)pool + 4) = count + 1;
                    record = (char *)base + count * 0x54;
                    radius = *(short *)((char *)entry + 2);
                    item = *(short *)entry;
                    *(int *)((char *)record + 8) = state;
                    *(int *)((char *)record + 0x14) = item;
                    *(int *)((char *)record + 0x18) = radius;
                    *(void **)((char *)record + 0x30) = buffer;
                    interp = *(void **)(sp + 0x18);
                    end = *(void **)((char *)interp + 0x14);
                    f1 = *(float *)(sp + 0x1C);
                    f2 = *(float *)interp;
                    f2 += f1 * (*(float *)end - f2);
                    *(float *)((char *)record + 0x1C) = f2;
                    f2 = *((float *)interp + 1);
                    f2 += f1 * (*((float *)end + 1) - f2);
                    *(float *)((char *)record + 0x20) = f2;
                    f2 = *((float *)interp + 2);
                    f2 += f1 * (*((float *)end + 2) - f2);
                    *(float *)((char *)record + 0x24) = f2;
                    f3 = *((float *)interp + 3);
                    f2 = f3 + f1 * (*((float *)end + 3) - f3);
                    *(float *)((char *)record + 0x28) = f2;
                    f0 = *(float *)((char *)record + 0x24);
                    f1 = *(float *)((char *)record + 0x28);
                    f0 = (float)fn_8002F234(end, interp, radius, f0 * f0 + f1 * f1, f1, f3);
                    f0 = f31 / f0;
                    f1 = *(float *)((char *)record + 0x24) * f0;
                    *(float *)((char *)record + 0x24) = f1;
                    f1 = *(float *)((char *)record + 0x28) * f0;
                    *(float *)((char *)record + 0x28) = f1;
                    f2 = *((float *)((char *)interp + 0x18)) * *(float *)(sp + 0x1C);
                    f1 = *((float *)buffer + 1) * (*((float *)((char *)interp + 0x1C)) + f2);
                    f0 = (float)fn_8002EFB4(interp, f1, lbl_80564CD0, f2);
                    index++;
                    entry = (char *)entry + 8;
                    *(float *)((char *)record + 0x2C) = f0;
                    *(int *)(sp + 8) = *(int *)((char *)record + 0x1C);
                    *(void **)(sp + 0x30) = *(void **)((char *)record + 0x30);
                    *(int *)sp = *(int *)((char *)record + 0x24);
                    *(int *)(sp + 4) = *(int *)((char *)record + 0x28);
                    *(int *)(sp + 0xC) = *(int *)((char *)record + 0x20);
                    f0 = *(float *)(sp + 8);
                    f2 = -f0;
                    f10 = *(float *)*(void **)(sp + 0x30);
                    f6 = *(float *)sp;
                    f1 = f2 * f6;
                    f8 = *(float *)(sp + 4);
                    f3 = -f6;
                    *(int *)(sp + 0x14) = *(int *)(sp + 0xC);
                    f4 = f2 * f8;
                    f0 = *(float *)(sp + 0x14);
                    f7 = f8 * f10;
                    f9 = *((float *)*(void **)(sp + 0x30) + 1);
                    f5 = f3 * f10;
                    f2 = f0 * f6;
                    *(float *)((char *)record + 0x34) = f7;
                    f0 = f0 * f8;
                    *(float *)((char *)record + 0x38) = f30;
                    f3 = f6 * f9;
                    f4 = f4 + f2;
                    *(float *)((char *)record + 0x3C) = f5;
                    f0 = f1 - f0;
                    f2 = f8 * f9;
                    f4 = f10 * f4;
                    f1 = f9 * f0;
                    f0 = f29 + f4;
                    *(float *)((char *)record + 0x40) = f0;
                    *(float *)((char *)record + 0x44) = f3;
                    *(float *)((char *)record + 0x48) = f30;
                    *(float *)((char *)record + 0x4C) = f2;
                    f0 = *(float *)((char *)record + 0x2C);
                    f0 = f0 + f1;
                    *(float *)((char *)record + 0x50) = f0;
                    *(void **)((char *)record + 0x10) = *(void **)((char *)next + 0xC);
                    *(void **)((char *)next + 0xC) = record;
                    ++*(int *)&lbl_8055FA84;
                }
            }
            current = fn_80138B4C(object, current);
        } while (current != 0);
    }
    fn_8013530C(sp + 0x24, -1);
    if (fn_802E2C20(sp + 0x24) - *(volatile int *)(sp + 0x14) > 0x1F4) {
        fn_802E30C8(&lbl_8034A064, *(void *volatile *)(sp + 0x10));
    }
}
#pragma pop
extern "C" void fn_802BA560(void *);
extern "C" char lbl_8034A9D0[];
extern "C" char lbl_8034A9E4[];
extern "C" void fn_802BA348(void) {
    struct Dummy { virtual void v0(); virtual void *v1(int); };
    struct {
        char *name;
        int start;
        void **data;
        int count;
        int cap;
        void *buf[4];
    } s;
    int i, j, total, n;
    void *first, *cur, *p, *obj, *entry, *buffer, *items;
    s.name = lbl_8034A9D0;
    s.start = fn_802E2C20(lbl_8034A9D0);
    s.data = s.buf;
    s.cap = 4;
    s.count = 0;
    first = ((Dummy *)fn_80156A40())->v1(0);
    cur = first;
    for (i = 0; s.count + 1 <= s.cap && i < 3;) {
        if (cur != 0) {
            n = s.count++;
            s.data[n] = cur;
        }
        i++;
        cur = ((Dummy *)fn_80156A40())->v1(i);
        if (cur == first || cur == 0) break;
    }
    total = 0;
    for (i = 0; i < s.count; i++) {
        obj = s.data[i];
        p = fn_80138B4C(obj, 0);
        if (p != 0) {
            do {
                total += *(int *)((char *)p + 8);
                p = fn_80138B4C(obj, p);
            } while (p != 0);
        }
    }
    entry = fn_801284F8(0x10, lbl_8034A9E4);
    if (entry != 0) {
        buffer = ((void *(*)(int, void *))fn_8012850C)(total * 0x54 + 0x10, lbl_8034A9E4);
        items = fn_8002F37C(buffer, (void *)fn_802BA560, 0, 0x54, total);
        *(void **)entry = items;
        *(int *)((char *)entry + 8) = total;
        *(int *)((char *)entry + 4) = 0;
        *(void **)((char *)entry + 0xC) = items;
    }
    lbl_8055FA78 = entry;
    for (j = 0; j < s.count; j++)
        fn_802BA010(s.data[j], j);
    s.data = 0;
    s.count = 0;
    s.cap = 0;
    if (((int (*)(void))fn_802E2C20)() - s.start > 0x1F4)
        fn_802E30C8(&lbl_8034A064, s.name);
}

#pragma cplusplus reset

void fn_802BA560(void *arg0) {
    *(volatile int *)((char *)arg0 + 4) = 0;
    *(volatile int *)((char *)arg0 + 0) = 0;
    *(volatile int *)((char *)arg0 + 8) = 3;
    *(volatile unsigned char *)((char *)arg0 + 0xC) = 1;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
#pragma dont_inline on
extern "C" void *fn_802BA580(void **arg0, void *arg1, float scale) {
    class Object { public:
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual char *name(void *);
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual unsigned long long value(void *);
    };
    extern int fn_802E317C(const char *, ...);
    extern int fn_802B110C(void *, char *);
    extern int stricmp(const char *,const char *);
    extern void fn_801602B0(void *);
    extern void fn_8016029C(void *, void *);
    extern void fn_80160B18(void *);
    extern void fn_80160BA0(void *, void *, float);
    extern void fn_80144D64(void *, void *);
    extern void *fn_802C9A40(void);
    extern void fn_801E0F78(void *, void *, void *, float);
    extern void fn_8001BA68(void *);
    extern float fn_801DCF48(void *, float, float);
    extern float fn_801E0FA4(void *, void *);
    extern float fn_8014C8B4(float,float,float,float,float);
    extern void fn_802BAA50(void *);
    extern void fn_802BA848(void *,void *,void *,void *);
    extern float lbl_80564CDC, lbl_80564CC4, lbl_80564CD8;
    extern float lbl_80564CE0, lbl_80564CE4, lbl_80564CE8, lbl_80564CCC;
    extern int lbl_8055CF04, lbl_8055CEF8, lbl_8055CECC;
    float j[3], h[3];
    union { unsigned long long bits; float v[2]; } value;
    float g[2], f[2], e[2], d[2], c[2], b[2], a[2];
    char *result;
    char *name;
    int *entry;
    int **items;
    int index;
    int state;
    int count;
    result = *(char **)lbl_8055FA7C + (*(int *)((char *)lbl_8055FA7C+4))*0x44;
    ++*(int *)((char *)lbl_8055FA7C+4);
    fn_801602B0(a); fn_801602B0(b); fn_801602B0(c); fn_801602B0(d);
    value.bits = ((Object *)arg0)->value(&lbl_8055CF04);
    fn_80160BA0(d,&value,scale);
    fn_80144D64(h,fn_802C9A40());
    fn_801602B0(e);
    fn_8016029C(e,h);
    fn_80160B18(e);
    fn_80160BA0(b,e,d[1]);
    fn_80160BA0(c,e,d[0]);
    fn_802BAA50(c);
    fn_801E0F78(a,arg1,c,lbl_80564CDC);
    fn_801602B0(f);
    fn_801E0F78(f,arg1,b,lbl_80564CC4);
    fn_8001BA68(j);
    if (fn_801DCF48(j,f[0],f[1]) != lbl_80564CD8) {
        fn_801602B0(g);
        fn_8016029C(g,j);
        fn_80160BA0(b,b,fn_8014C8B4(lbl_80564CE0,lbl_80564CE4,lbl_80564CE8,lbl_80564CCC,fn_801E0FA4(g,e)));
    }
    fn_802BA848(result,c,b,a);
    *(int *)(result+8)=1;
    name=((Object *)arg0)->name(&lbl_8055CEF8);
    RenderList *list = (RenderList *)lbl_804BFFF4;
    for(index=0; index < list->count; index++) {
        entry=(int *)list->items[index];
        if (stricmp((char *)entry[0],name)==0) break;
    }
    if (index < list->count) goto found;
    count=list->count;
    items=(int **)list->items;
    list->count=count+1;
    entry=(int *)fn_801284F8(0x10,&lbl_8055CECC);
    if(entry) {
        entry[0]=(int)name;
        if ((signed char)*name) state=fn_802B110C((void *)fn_802B8E50,name);
        else state=-2;
        entry[1]=state;
        if(state==-2 && (signed char)*name) fn_802E317C((char *)lbl_8034AA2C,name);
        entry[3]=0;
        entry[2]=999;
    }
    items[count]=entry;
found:
    *(int *)(result+16)=entry[3];
    entry[3]=(int)result;
    lbl_8055FA84=(void *)((int)lbl_8055FA84+1);
    return result;
}

extern f32 lbl_80564CCC, lbl_80564CD8, lbl_80564CEC;
extern "C" f32 lbl_80564CCC, lbl_80564CD8, lbl_80564CEC;
extern "C" void fn_802BA848(f32 *out, f32 *a, f32 *b, f32 *c) {
    f32 x0 = b[0], y1 = a[1], y0 = a[0], x1 = b[1], z0 = c[0];
    f32 d = y0 * x1 - x0 * y1;
    f32 hi = x0 + (z0 + y0);
    f32 k1 = lbl_80564CEC;
    f32 z1 = c[1];
    f32 lo = z0 + x0;
    f32 u, v, w, q;
    f32 t;
    out[10] = lbl_80564CD8;
    u = y0 / d;
    v = -x0 / d;
    t = lbl_80564CD8 * k1;
    out[11] = v;
    w = -y1 / d;
    out[14] = t;
    q = x1 / d;
    out[9] = q;
    out[13] = w * k1;
    out[15] = u * k1;
    out[12] = -(z0 * q + z1 * v);
    out[16] = (f32)(-(double)(z1 * u + z0 * w)) * k1 + lbl_80564CCC;
    lo = (lo < hi) ? lo : hi;
    hi = c[0] + a[0];
    lo = (hi < lo) ? hi : lo;
    hi = c[0];
    out[5] = (hi < lo) ? hi : lo;
    lo = c[1] + b[1]; hi = b[1] + (c[1] + a[1]);
    lo = (lo < hi) ? lo : hi;
    hi = c[1] + a[1];
    lo = (hi < lo) ? hi : lo;
    hi = c[1];
    out[6] = (hi < lo) ? hi : lo;
    lo = c[0] + b[0]; hi = b[0] + (c[0] + a[0]);
    lo = (lo > hi) ? lo : hi;
    hi = c[0] + a[0];
    lo = (hi > lo) ? hi : lo;
    hi = c[0];
    out[7] = (hi > lo) ? hi : lo;
    lo = c[1] + b[1]; hi = b[1] + (c[1] + a[1]);
    lo = (lo > hi) ? lo : hi;
    hi = c[1] + a[1];
    lo = (hi > lo) ? hi : lo;
    hi = c[1];
    out[8] = (hi > lo) ? hi : lo;
}

#pragma cplusplus reset
#pragma pop

void fn_802BAA50(void *arg0) {
    float a = *(float *)arg0;
    float b = *((float *)arg0 + 1);
    *(float *)arg0 = b;
    *((float *)arg0 + 1) = -a;
}

#pragma cplusplus on
#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_802BAD0C(void *, float);
extern "C" float fn_802BAD90(float);
extern "C" void *fn_802BAA68(void **arg0, char *arg1) {
    class Object { public:
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual char *name(void *);
        virtual void v4(); virtual void v5();
        virtual int v6(void *, int);
        virtual void v7();
        virtual float v8(void *, float);
        virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual unsigned long long value(void *);
    };
    extern int fn_802E317C(const char *, ...);
    extern int fn_802B110C(void *, char *);
    extern int stricmp(const char *,const char *);
    extern void fn_801602B0(void *);
    extern void fn_8016029C(void *, void *);
    extern void fn_80160B18(void *);
    extern void fn_80160BA0(void *, void *, float);
    extern void fn_80160288(void *, void *);
    extern void fn_801E0F78(void *, void *, void *, float);
    extern float lbl_80564CDC, lbl_80564CD8, lbl_80564CEC;
    extern int lbl_8055CF10, lbl_8055CF0C, lbl_8055CEF8, lbl_8055CECC;
    union { unsigned long long bits; float v[2]; } value;
    float e[2], c[2], b[2], a[2];
    int extra;
    int index;
    int *entry;
    int off;
    int count;
    char *result;
    char *name;
    float angle;
    float k;
    result = *(char **)lbl_8055FA7C + (*(int *)((char *)lbl_8055FA7C+4))*0x44;
    ++*(int *)((char *)lbl_8055FA7C+4);
    fn_801602B0(a); fn_801602B0(b); fn_801602B0(c);
    fn_8016029C(b, arg1 + 0x18);
    fn_80160B18(b);
    fn_8016029C(c, arg1);
    fn_80160B18(c);
    fn_8016029C(a, arg1 + 0x24);
    value.bits = ((Object *)arg0)->value(&lbl_8055CF10);
    fn_80160288(e, &value);
    fn_80160BA0(b, b, e[1]);
    fn_80160BA0(c, c, e[1]);
    k = lbl_80564CEC;
    angle = fn_802BAD90(k * ((Object *)arg0)->v8(&lbl_8055CF0C, lbl_80564CD8));
    fn_802BAD0C(b, angle);
    fn_802BAD0C(c, angle);
    fn_801E0F78(a, a, c, lbl_80564CDC);
    fn_801E0F78(a, a, b, lbl_80564CDC);
    fn_802BA848((float *)result, c, b, a);
    *(int *)(result+8) = 0;
    name = ((Object *)arg0)->name(&lbl_8055CEF8);
    extra = ((Object *)arg0)->v6(&lbl_8055CEE4, 0x378);
    index = 0;
    off = 0;
    for(; index < *(int *)((char *)&lbl_804BFFF4+4); ) {
        entry = *(int **)(*(char **)&lbl_804BFFF4 + off);
        if (stricmp((char *)entry[0],name)==0) goto found;
        off += 4;
        index++;
    }
    count=*(int *)((char *)&lbl_804BFFF4+4);
    {
    char *items=*(char **)&lbl_804BFFF4;
    *(int *)((char *)&lbl_804BFFF4+4)=count+1;
    off = count << 2;
    entry=(int *)fn_801284F8(0x10,&lbl_8055CECC);
    if(entry) {
        entry[0]=(int)name;
        if ((signed char)*name) entry[1]=fn_802B110C((void *)fn_802B8E50,name);
        else entry[1]=-2;
        if(entry[1]==-2 && (signed char)*name) fn_802E317C((char *)&lbl_8034AA2C,name);
        entry[3]=0;
        entry[2]=extra;
    }
    *(int **)(items + off) = entry;
    }
found:
    *(int *)(result+16)=entry[3];
    entry[3]=(int)result;
    lbl_8055FA84=(void *)((int)lbl_8055FA84+1);
    return result;
}
#pragma pop
#pragma cplusplus reset

#pragma push
#pragma processor 750
void fn_802BAD0C(void *arg0, float angle) {
    float c;
    float x;
    float s;
    float y;
    x = *(float *)((char *)arg0 + 0);
    c = (float)cos(angle);
    s = (float)sin(angle);
    y = *(float *)((char *)arg0 + 4);
    *(float *)((char *)arg0 + 4) = y * c + x * s;
    *(float *)((char *)arg0 + 0) = *(float *)((char *)arg0 + 0) * c - y * s;
}
#pragma pop
int fn_80128668(void *);
int fn_80128670(int);
double cos(double);
double sin(double);
extern float lbl_80564CF0;
float fn_802BAD90(float farg0) {
    return lbl_80564CF0 * farg0;
}

#pragma cplusplus on
extern "C" void fn_802BAE30(void *);
extern "C" void fn_802BAD9C(s32 arg0) {
    void *entry = fn_801284F8(0x10, lbl_8034A9F4);
    if (entry != 0) {
        void *buffer = ((void *(*)(int, void *))fn_8012850C)(arg0 * 0x44 + 0x10, lbl_8034A9F4);
        void *items = fn_8002F37C(buffer, fn_802BAE30, 0, 0x44, arg0);
        *(void **)entry = items;
        *(s32 *)((char *)entry + 8) = arg0;
        *(s32 *)((char *)entry + 4) = 0;
        *(void **)((char *)entry + 0xC) = items;
    }
    lbl_8055FA7C = entry;
}
#pragma cplusplus reset

void fn_802BAE30(void *arg0) {
    *(volatile int *)((char *)arg0 + 4) = 0;
    *(volatile int *)((char *)arg0 + 0) = 0;
    *(volatile int *)((char *)arg0 + 8) = 3;
    *(volatile unsigned char *)((char *)arg0 + 0xC) = 1;
}

extern char lbl_8034AA00[];
extern char lbl_8034AA10[];
extern int lbl_8055CEF0;
extern void *lbl_8055FA80;
extern int fn_802E2C20(void *);
extern void fn_802B9108(short);
extern void fn_801286A0(void *, int);
extern void fn_80265DCC(void *, void *, int, int (**)(int **, int **));
extern void fn_802E30C8(void *, ...);
void fn_802BAE50(void) {
    int total;
    volatile int start;
    int n;
    void *table;
    void *items;
    char * volatile name;
    char *allocationName;
    short listSize;
    short passSize;
    name = (char *)&lbl_8034AA00;
    start = fn_802E2C20((char *)&lbl_8034AA00);
    total = 0;
    for (passSize = 4; passSize <= 0x40; passSize *= 2) {
        total += (0x400 / (passSize * 2)) * (0x400 / (passSize * 2)) * 5;
    }
    allocationName = (char *)&lbl_8034AA10;
    table = fn_801284F8(0x10, allocationName);
    if (table != 0) {
        items = ((void *(*)(int, void *))fn_8012850C)(total * 4, &lbl_8055CEF0);
        ((void **)table)[0] = items;
        ((int *)table)[2] = total;
        ((int *)table)[1] = 0;
        ((void **)table)[3] = items;
    }
    lbl_8055FA80 = table;
    for (listSize = 4; listSize <= 0x40; listSize *= 2)
        fn_802B9108(listSize);
    table = lbl_8055FA80;
    if (((int *)table)[1] < ((int *)table)[2]) {
        n = ((int *)table)[2] - ((int *)table)[1];
        fn_801286A0(((void **)table)[3], n * 4);
        ((int *)table)[2] = ((int *)table)[1];
    }
    fn_80265DCC(*(void **)lbl_804BFFF4, *((void **)lbl_804BFFF4 + 1), 4,
                (int (**)(int **, int **))fn_802B9B50);
    if (((int (*)(void))fn_802E2C20)() - start > 0x1F4)
        fn_802E30C8(&lbl_8034A064, name);
}

typedef signed char s8;
void fn_802BAF98(void* arg0, s8 arg1) {
    ((s8*)arg0)[0xC] = arg1;
}

#pragma push
#pragma scheduling invalid_target
void fn_802BAFA0(void) {
    void **entries = *(void ** volatile *)lbl_804BFFF4;
    int count = *(volatile int *)(lbl_804BFFF4 + 4);
    lbl_8055FA6C = 0;
    lbl_8055FA70 = 0;
    while (count > 0) {
        void *p = *(void **)((char *)*entries + 12);
        while (p != 0)
            p = *(void **)((char *)p + 16);
        entries++;
        count--;
    }
    *(int *)((char *)lbl_8055FA74 + 8) = 0;
}
#pragma scheduling on
#pragma pop
void fn_802BAFF8(void ***arg0, int *arg1) {
    int zero = 0;
    arg0 = (void ***)*arg0;
    while (*(void **)arg0 != 0) {
        void *queue;
        void *entry;
        int *slot = 0;
        void *pool;
        int count;
        entry = *(void **)arg0;
        queue = *(void **)((char *)entry + 4);
        pool = *(void * volatile *)&lbl_8055FA74;
        if (queue == 0 || *(volatile int *)((char *)queue + 4) + 1 > *(volatile int *)((char *)queue + 8)) {
            void *node = 0;
            if (*(volatile int *)((char *)pool + 8) + 1 <= *(volatile int *)((char *)pool + 0xC)) {
                node = (char *)*(void **)((char *)pool + 4) + (*(volatile int *)((char *)pool + 8))++ * 0x10;
                *(int *)((char *)node + 4) = zero;
                *(int *)((char *)node + 0xC) = zero;
            }
            if (node != 0) {
                if (*(void **)entry == 0)
                    *(void **)entry = node;
                queue = *(void **)((char *)entry + 4);
                if (queue != 0)
                    *(void **)((char *)queue + 0xC) = node;
                *(void **)((char *)entry + 4) = node;
                *(void **)((char *)node + 0xC) = (void *)zero;
                queue = *(void **)((char *)entry + 4);
                count = *(int *)((char *)queue + 4);
                slot = (int *)(*(int *)queue + count * 4);
                *(int *)((char *)queue + 4) = count + 1;
            }
        } else {
            count = *(int *)((char *)queue + 4);
            slot = (int *)(*(int *)queue + count * 4);
            *(int *)((char *)queue + 4) = count + 1;
        }
        if (slot != 0) {
            *slot = *arg1;
            lbl_8055FA70++;
        }
        arg0 = (void ***)((char *)arg0 + 4);
    }
}

#pragma scheduling invalid_target
void fn_802BB0FC(int a, int b) {
    /* Traverse pending render batches, draw them, and clear their lists. */
    RenderList *list = (RenderList *)lbl_804BFFF4;
    RenderBatch *batch;
    RenderNode *node;
    RenderEntry *entry;
    u16 **items;
    int i, j, v;
    RenderMatrix matrix;
    for (i = 0; i < list->count; i++) {
        entry = list->items[i];
        if (entry->kind != 999) continue;
        node = entry->nodes;
        if (!node) continue;
        if (entry->state == -2) goto clear_nodes;
        switch (node->type) { case 0: case 1: {
            fn_802C8BD0(); fn_802DC130();
            node = entry->nodes;
            while (node) {
                if (node->batches) {
                    if (node->enabled) {
                        ((void (*)(int,void *))fn_802D3D94)(0, (char *)node + 0x24);
                        batch = node->batches;
                        do {
                            for (j = 0; j < batch->count; j++) {
                                items = batch->items;
                                fn_802DC138(a,b,items[j],*items[j]+1);
                                v = *items[j] - 1;
                                lbl_8055FA6C += v & ~(v >> 31);
                            }
                            batch = batch->next;
                        } while (batch);
                    }
                    node->count = 0; node->batches = 0;
                }
                node = node->next;
            }
            fn_802DC134(); fn_802C8D74();
        break; } case 2: {
            fn_802C28C0(); fn_802C8BD0(); fn_802DC278();
            fn_802CADD0(entry->state,1);
            fn_802CADD0(((int (*)(void))fn_802C21B8)(),2);
            matrix = *(RenderMatrix *)lbl_802FAB40;
            ((void (*)(int,void *))fn_802D3D94)(2,&matrix);
            node = entry->nodes;
            while (node) {
                if (node->batches) {
                    ((void (*)(int,void *))fn_802D3D94)(0,(char *)node + 0x34);
                    batch = node->batches;
                    do {
                        for (j = 0; j < batch->count; j++) {
                            items = batch->items;
                            fn_802DC280(a,b,items[j],*items[j]+1);
                            v = *items[j] - 1;
                            lbl_8055FA6C += v & ~(v >> 31);
                        }
                        batch = batch->next;
                    } while (batch);
                    node->count = 0; node->batches = 0;
                }
                node = node->next;
            }
            fn_802CADD0(-1,1); fn_802CADD0(-1,2); fn_802DC27C(); fn_802C8D74();
        break; } }
        continue;
clear_nodes:
        while (node) { node->count = 0; node->batches = 0; node = node->next; }
    }
}
#pragma scheduling on
void fn_802BB3B8(int a, int b) {
    /* Traverse pending render batches, draw them, and clear their lists. */
    RenderList *list = (RenderList *)lbl_804BFFF4;
    RenderBatch *batch;
    RenderNode *node;
    RenderEntry *entry;
    u16 **items;
    int i, j, v;
    RenderMatrix matrix; int zero = 0;
    for (i = 0; i < list->count; i++) {
        entry = list->items[i];
        if (entry->kind == 999) continue;
        node = entry->nodes;
        if (!node) continue;
        if (entry->state == -2) goto clear_nodes;
        switch (node->type) { case 0: case 1: {
            fn_802C8BD0(); fn_802DC130();
            node = entry->nodes;
            while (node) {
                if (node->batches) {
                    if (node->enabled) {
                        ((void (*)(int,void *))fn_802D3D94)(0, (char *)node + 0x24);
                        batch = node->batches;
                        do {
                            for (j = 0; j < batch->count; j++) {
                                items = batch->items;
                                fn_802DC138(a,b,items[j],*items[j]+1);
                                v = *items[j] - 1;
                                lbl_8055FA6C += v & ~(v >> 31);
                            }
                            batch = batch->next;
                        } while (batch);
                    }
                    node->count = zero; node->batches = (RenderBatch *)zero;
                }
                node = node->next;
            }
            fn_802DC134(); fn_802C8D74();
        break; } case 2: {
            fn_802C28C0(); fn_802C8BD0(); fn_802DC278();
            fn_802CADD0(entry->state,1);
            fn_802CADD0(((int (*)(void))fn_802C21B8)(),2);
            matrix = *(RenderMatrix *)lbl_802FAB40;
            ((void (*)(int,void *))fn_802D3D94)(2,&matrix);
            node = entry->nodes;
            while (node) {
                if (node->batches) {
                    ((void (*)(int,void *))fn_802D3D94)(0,(char *)node + 0x34);
                    batch = node->batches;
                    do {
                        for (j = 0; j < batch->count; j++) {
                            items = batch->items;
                            fn_802DC280(a,b,items[j],*items[j]+1);
                            v = *items[j] - 1;
                            lbl_8055FA6C += v & ~(v >> 31);
                        }
                        batch = batch->next;
                    } while (batch);
                    node->count = zero; node->batches = (RenderBatch *)zero;
                }
                node = node->next;
            }
            fn_802CADD0(-1,1); fn_802CADD0(-1,2); fn_802DC27C(); fn_802C8D74();
        break; } }
        continue;
clear_nodes:
        while (node) { node->count = zero; node->batches = (RenderBatch *)zero; node = node->next; }
    }
}

extern int lbl_804C0088[];
extern char lbl_8034AA50[];
extern int fn_802B110C(void *, char *);
extern int fn_802CAC54(void);
extern int fn_802E317C(const char *, ...);
extern int stricmp(const char *, const char *);
extern int fn_802B8E50(int);
#pragma push
#pragma scheduling invalid_target
void fn_802BB674(char *arg0, int arg1) {
    struct Entry { char *name; int state; };
    register struct Entry *entry = ((struct Entry **)lbl_804C0088)[arg1];
    int result4;
    char first4;
    if (entry != 0 && stricmp(entry->name, arg0) != 0) {
        if (entry->state != -2) fn_802CAC54();
        first4 = *arg0;
        result4 = -2;
        entry->state = -2;
        if (first4 != 0) result4 = fn_802B110C(fn_802B8E50, arg0);
        entry->state = result4;
        entry->name = arg0;
        if (result4 == -2 && (signed char)entry->name[0] != 0)
            fn_802E317C(lbl_8034AA50);
    }
}


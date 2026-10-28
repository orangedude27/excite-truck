#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
extern double cos(double);
extern double sin(double);
extern void *fn_801284F8(int, void *);
extern void fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, int, int, int);
extern void fn_802BAE30(void *);
extern int lbl_8034A9F4;
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
    char *name;
    void *data;
    int state;
    struct List *list;
    int count;
    if (entry == 0) {
        name = &lbl_8055CEC8;
        entry = (struct Entry *)fn_801284F8(0x10, &lbl_8055CECC);
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
        count = list->count;
        list->count = count + 1;
        list->items[count] = (void *)entry;
    }
    return table[arg0];
}

extern void *fn_802B59CC(int, int, void *, void *);
extern void fn_801345D8(void *, int, const char *, ...);
extern int lbl_804C004C[];
extern float lbl_80564CC0;
extern float lbl_80564CC4;
extern char lbl_8055CED4;
extern char lbl_8055CEDC;
extern char lbl_8055CEE4;
extern char lbl_8034A990[];
#pragma cplusplus on
extern "C" void *fn_802B8FE0(int arg0) {
    struct Record {
        float value;
        float parameter;
        int flags;
    };
    struct Vtable {
        void *unknown0[8];
        int (*setInteger)(void *, const char *, int);
        void *unknown9;
        float (*setFloat)(void *, const char *, float);
        void *reserved[12];
        void *(*find)(void *, const char *);
    };
    struct Object {
        struct Vtable *vtable;
    };
    float initial = lbl_80564CC0;
    int *state;
    void *base;
    int index;
    int offset;
    int next;
    struct Record *record;
    void *object;
    char buffer[0x20];
    struct Object *finder;
    char *found;
    struct Object *settings;

    state = lbl_804C004C;
    base = (void *)state[0];
    index = state[1];
    offset = index * 12;
    next = index + 1;
    state[1] = next;
    record = (struct Record *)((char *)base + offset);
    record->flags = 0;
    record->parameter = initial;

    object = fn_802B59CC(offset, next, state, base);
    fn_801345D8(buffer, 0x20, (const char *)&lbl_8055CED4, arg0 + 1);

    finder = (struct Object *)object;
    found = (char *)finder->vtable->find(finder, buffer);
    if (found == 0)
        found = (char *)finder->vtable->find(finder, (const char *)&lbl_8055CEDC);

    if (found != 0) {
        settings = (struct Object *)found;
        record->parameter = settings->vtable->setFloat(settings, lbl_8034A990, record->parameter);
        record->flags = settings->vtable->setInteger(settings, (const char *)&lbl_8055CEE4, record->flags);
    }

    record->value = lbl_80564CC4;
    return record;
}
#pragma cplusplus reset

#pragma pop
int fn_802B9100(void) {
    return 0;
}

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
int fn_802B9920(int arg0) {
    int v = arg0 + 0x200;
    int idx = (v >> 31) + (v << 27) + ((v << 27) >> 27);
    return (short)lbl_802FAB60[idx];
}

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
    s32 *data, *slot;
    s32 denom, y, rows, x, index, item, used;
    Node **cell;
    Pool *pool;
    Node *node, *new_node, *tail;

    size = *(s16 *)arg0;
    denom = size * 2;
    y = (arg3 - size + 0x200) / denom;
    rows = 0x400 / denom;
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
            data = tail->data;
            item = tail->used;
            tail->used = item + 1;
            slot = data + item;
        }
    } else {
        tail = node;
        data = tail->data;
        item = tail->used;
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
    register int i;
    register int offset;
    register void *node;
    register char *base = lbl_804BFFE8;
    register int zero;
    register void **list;
    fn_802B9DD0(&lbl_8055FA7C);
    fn_802B9E4C(&lbl_8055FA78);
    list = (void **)(base + 0x0C);
    i = 0;
    offset = 0;
    zero = 0;
    while (i < ((int *)list)[1]) {
        node = *(void **)((char *)list[0] + offset);
        if (node != 0) {
            *(int *)((char *)node + 0x0C) = zero;
            if (*(int *)((char *)node + 4) != -2) {
                fn_802CAC54();
            }
            fn_80128668(node);
        }
        offset += 4;
        i++;
    }
    ((int *)list)[1] = zero;
    {
        char *clear = base + 0x64;
        *(int *)(clear + 4) = zero;
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
extern "C" int lbl_8034A064;
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
extern int lbl_8034A064;
extern double lbl_80564CD0;
extern float lbl_80564CCC, lbl_80564CC4, lbl_80564CD8;
extern "C" void fn_802BA010(void *arg0, int arg1) {
    struct Dummy { virtual void v0(); virtual void *v1(int); };
    volatile char scratch[0x40];
    char *sp = (char *)scratch;
    int index, count;
    int state = 2;
    short radius, item;
    void *buffer, *current, *next, *entry, *record, *pool, *base;
    void *object = arg0;
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
                    f0 = (float)fn_8002F234(end, interp, radius,
                                             f0 * f0 + f1 * f1, f1, f3);
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
    for(index=0; index < *(int *)((char *)&lbl_804BFFF4+4); index++) {
        entry=(*(int ***)&lbl_804BFFF4)[index];
        if (stricmp((char *)entry[0],name)==0) goto found;
    }
    count=*(int *)((char *)&lbl_804BFFF4+4);
    items=*(int ***)&lbl_804BFFF4;
    *(int *)((char *)&lbl_804BFFF4+4)=count+1;
    entry=(int *)fn_801284F8(0x10,&lbl_8055CECC);
    if(entry) {
        entry[0]=(int)name;
        if ((signed char)*name) state=fn_802B110C((void *)fn_802B8E50,name);
        else state=-2;
        entry[1]=state;
        if(state==-2 && (signed char)*name) fn_802E317C((char *)&lbl_8034AA2C,name);
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
void fn_802BA848(f32 *out, f32 *a, f32 *b, f32 *c) {
    f32 x0=b[0], x1=b[1], y0=a[0], y1=a[1], z0=c[0], z1=c[1];
    f32 d=y0*x1-x0*y1;
    f32 hi=x0+(z0+y0), lo=z0+x0;
    f32 u=y0/d, v=-x0/d, w=-y1/d, q=x1/d;
    out[10]=lbl_80564CD8; out[11]=v;
    out[14]=lbl_80564CD8*lbl_80564CEC;
    out[9]=q; out[13]=w*lbl_80564CEC; out[15]=u*lbl_80564CEC;
    out[12]=-(z0*q+z1*v);
    out[16]=(-((z1*u+z0*w))*lbl_80564CEC)+lbl_80564CCC;
    if(lo<hi) lo=hi;
    hi=z0+y0; if(hi<lo) hi=lo; lo=z0; if(lo<hi) lo=hi; out[5]=lo;
    lo=z1+x1; hi=x1+(z1+y1); if(lo<hi) lo=hi; hi=z1+y1; if(hi<lo) hi=lo; z1=c[1]; if(z1<hi) z1=hi; out[6]=z1;
    z0=c[0]; x0=b[0]; lo=z0+x0; hi=x0+(z0+a[0]); if(lo>hi) lo=hi; hi=z0+a[0]; if(hi>lo) hi=lo; z0=c[0]; if(z0>hi) z0=hi; out[7]=z0;
    z1=c[1]; x1=b[1]; lo=z1+x1; hi=x1+(z1+a[1]); if(lo>hi) lo=hi; hi=z1+a[1]; if(hi>lo) hi=lo; z1=c[1]; if(z1>hi) z1=hi; out[8]=z1;
}

#pragma cplusplus reset
#pragma pop

void fn_802BAA50(void *arg0) {
    float a = *(float *)arg0;
    float b = *((float *)arg0 + 1);
    *(float *)arg0 = b;
    *((float *)arg0 + 1) = -a;
}

void fn_802BAD0C(void *arg0, float angle) {
    register float c;
    register float x;
    register float s;
    register float y;
    x = *(float *)((char *)arg0 + 0);
    c = (float)cos(angle);
    s = (float)sin(angle);
    y = *(float *)((char *)arg0 + 4);
    *(float *)((char *)arg0 + 4) = x * s + y * c;
    *(float *)((char *)arg0 + 0) = *(float *)((char *)arg0 + 0) * c - y * s;
}

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
    char *label = (char *)&lbl_8034A9F4;
    void *entry = fn_801284F8(0x10, label);
    if (entry != 0) {
        void *buffer = ((void *(*)(int, void *))fn_8012850C)(arg0 * 0x44 + 0x10, label);
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

extern int lbl_8034AA00, lbl_8034AA10, lbl_8034A064, lbl_8055CEF0;
extern void *lbl_8055FA80;
extern int fn_802E2C20(void *);
extern void fn_802B9108(short);
extern void fn_801286A0(void *, int);
extern void fn_80265DCC(void *, void *, int, int (**)(int **, int **));
extern void fn_802E30C8(void *, ...);
void fn_802BAE50(void) {
    int start, total = 0, n;
    short size = 4;
    void *table;
    start = fn_802E2C20(&lbl_8034AA00);
    do { int dim = 0x400 / (size * 2); total += dim * dim * 5; size *= 2; } while (size <= 0x40);
    table = fn_801284F8(0x10, &lbl_8034AA10);
    if (table) {
        void *items = ((void *(*)(int, void *))fn_8012850C)(total * 4, &lbl_8055CEF0);
        ((void **)table)[0] = items; ((int *)table)[2] = total;
        ((int *)table)[1] = 0; ((void **)table)[3] = items;
    }
    lbl_8055FA80 = table;
    for (size = 4; size <= 0x40; size *= 2) fn_802B9108(size);
    table = lbl_8055FA80;
    if (((int *)table)[1] < ((int *)table)[2]) {
        n = ((int *)table)[2] - ((int *)table)[1];
        fn_801286A0(((void **)table)[3], n * 4);
        ((int *)table)[2] = ((int *)table)[1];
    }
    fn_80265DCC(*(void **)lbl_804BFFF4, *((void **)lbl_804BFFF4 + 1), 4, (int (**)(int **, int **))fn_802B9B50);
    if (fn_802E2C20(0) - start > 0x1F4) fn_802E30C8(&lbl_8034A064, &lbl_8034AA00);
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
    register int zero = 0;
    arg0 = (void ***)*arg0;
    while (*(void **)arg0 != 0) {
        register void *entry = *(void **)arg0;
        register void *queue = *(void **)((char *)entry + 4);
        register int *slot = 0;
        register void *pool = *(void * volatile *)&lbl_8055FA74;
        register int count;

        if (queue == 0 || *(int *)((char *)queue + 4) + 1 > *(int *)((char *)queue + 8)) {
            register void *node = 0;
            register int pool_count = *(int *)((char *)pool + 8);
            if (pool_count + 1 <= *(int *)((char *)pool + 0xC)) {
                node = (char *)*(void **)((char *)pool + 4) +
                       (*(int *)((char *)pool + 8))++ * 0x10;
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
        if (slot) { *slot = *arg1; lbl_8055FA70++; }
        arg0 = (void ***)((char *)arg0 + 4);
    }
}

extern void fn_802C21B8(void); extern void fn_802C28C0(void); extern void fn_802C8BD0(void); extern void fn_802C8D74(void); extern void fn_802CADD0(int,int); extern void fn_802D3D94(int,void*,...); extern void fn_802DC130(void); extern void fn_802DC134(void); extern void fn_802DC138(int,int,void*,int); extern void fn_802DC278(void); extern void fn_802DC27C(void); extern void fn_802DC280(int,int,void*,int); extern int lbl_802FAB40[]; void fn_802BB3B8(int a,int b,int c){ int i,j; void *item,*list,*node; for(i=0;i<((int*)lbl_804BFFF4)[1];i++){ item=((void**)((int*)lbl_804BFFF4)[0])[i]; if(*(int*)((char*)item+8)==999)continue; list=*(void**)((char*)item+12); if(!list)continue; if(*(int*)((char*)item+4)==-2){while(list){*(int*)((char*)list+4)=0;*(int*)list=0;list=*(void**)((char*)list+16);}continue;} j=*(int*)((char*)list+8); if(j==2){fn_802C28C0();fn_802C8BD0();fn_802DC278();fn_802CADD0(*(int*)((char*)item+4),1);fn_802C21B8();fn_802CADD0(2,0);fn_802D3D94(2,lbl_802FAB40);list=*(void**)((char*)item+12);while(list){node=*(void**)list;if(node){fn_802D3D94(0,(char*)list+52);while(node){int n=*(int*)((char*)node+4);for(j=0;j<n;j++){void*p=((void**)*(void**)node)[j];fn_802DC280(a,b,p,*(unsigned short*)p+1);lbl_8055FA6C+=(*(unsigned short*)p)-1>0?(*(unsigned short*)p)-1:0;}node=*(void**)((char*)node+12);}*(int*)((char*)list+4)=0;*(void**)list=0;}list=*(void**)((char*)list+16);}fn_802CADD0(-1,1);fn_802CADD0(-1,2);fn_802DC27C();fn_802C8D74();}else if(j>=0){fn_802C8BD0();fn_802DC130();while(list){node=*(void**)list;if(node&&*(unsigned char*)((char*)list+12)){fn_802D3D94(0,(char*)list+36);while(node){int n=*(int*)((char*)node+4);for(j=0;j<n;j++){void*p=((void**)*(void**)node)[j];fn_802DC138(a,b,p,*(unsigned short*)p+1);lbl_8055FA6C+=(*(unsigned short*)p)-1>0?(*(unsigned short*)p)-1:0;}node=*(void**)((char*)node+12);}*(int*)((char*)list+4)=0;*(void**)list=0;}list=*(void**)((char*)list+16);}fn_802DC134();fn_802C8D74();}}}

extern int lbl_804C0088[];
extern int lbl_8034AA50;
extern int fn_802B110C(void *, char *);
extern int fn_802CAC54(void);
extern int fn_802E317C(const char *, ...);
extern int stricmp(const char *, const char *);
extern int fn_802B8E50(int);
void fn_802BB674(char *arg0, int arg1) {
    struct Entry { char *name; int state; };
    struct Entry *entry = ((struct Entry **)lbl_804C0088)[arg1];
    int result;
    int first;
    if (entry != 0 && stricmp(entry->name, arg0) != 0) {
        if (*(volatile int *)&entry->state != -2) fn_802CAC54();
        first = (signed char)*arg0;
        result = -2;
        entry->state = -2;
        if (first != 0) result = fn_802B110C(fn_802B8E50, arg0);
        entry->state = result;
        entry->name = arg0;
        if (result == -2 && (signed char)*(volatile char *)entry->name != 0)
            fn_802E317C((char *)&lbl_8034AA50);
    }
}


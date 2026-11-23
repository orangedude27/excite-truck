// modpool — model pool ("modpool: oldest_model is NULL", loadpool).
// Recovered TU window 0x802CE3A4..0x802CE858+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CE858 (+ .ctors slot 0x802ED5B8) remains in
// auto/text_802CE858_.c pending a promotion pass.
int fn_80128668(void *);
int fn_80128670(int);
int fn_801342B0(int, int);
char *strcpy(char *, const char *);
void fn_802C6FB4(int);
void fn_802C703C(int);
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8013420C(int, int);
extern void *fn_8002F37C(void *, int, int, int);
extern char lbl_8034BCE4[]; /* "loadpool" - allocation name for the load pool */
extern char lbl_8034BCD8[]; /* "modelpool" - allocation name for model storage */
extern void fn_802CE474(void *);
__declspec(section ".sdata") extern char lbl_8055D0A8[]; /* "modpool" - allocation name for the manager */
/* Allocate and initialize a pooled manager: its inner load pool, backing slot storage, and a table of slotCount entries. */ void *fn_802CE3A4(int slotCount, int arg1, int arg2) {
    int count;
    void *manager;
    void *loadPool;
    void *slotStorage;

    /* Allocates and initializes a pooled manager: inner data block, backing storage, and a table of slotCount entries. */
    manager = fn_801284F8(0x14, lbl_8055D0A8);
    if (manager != 0) {
        *(int *)((char *)manager + 8) = slotCount;
        *(int *)((char *)manager + 0xC) = arg1;
        loadPool = fn_801284F8(0x10, lbl_8034BCE4);
        if (loadPool != 0) loadPool = ((void *(*)(void *, int, int))fn_8013420C)(loadPool, *(int *)((char *)manager + 0xC), arg2);
        *(void **)((char *)manager + 4) = loadPool;
        count = *(int *)((char *)manager + 8);
        slotStorage = fn_8012850C((count << 6) + 0x10, lbl_8034BCD8);
        *(void **)manager = ((void *(*)(void *, void *, int, int, int))fn_8002F37C)(slotStorage, fn_802CE474, 0, 0x40, count);
        *(int *)((char *)manager + 0x10) = 0;
    }
    return manager;
}

void fn_802CE474(void *slot) {
    /* Initialise one 0x40-byte model-pool slot to its empty state: clear the
     * manager pointer, in-use flag and state, and reset the load/model handles
     * and timestamp to their "none" values. */
    *(int *)((char *)slot + 4) = 0;
    *(unsigned char *)slot = 0;
    *(int *)((char *)slot + 0x38) = 0;
    *(int *)((char *)slot + 0x34) = -1;
    *(int *)((char *)slot + 0x30) = 0;
    *(int *)((char *)slot + 0x2C) = -1;
    *(int *)((char *)slot + 0x3C) = -1;
}

void fn_802CE49C(void *object) {
    int value;
    /* Destroys a modpool object: frees its data buffer, releases its load pool, and deletes the object. */
    if (object != 0) {
        value = *(int *)object;
        if (value != 0) {
            fn_80128670(value - 0x10);
        }
        fn_801342B0(*(int *)((char *)object + 4), 1);
        fn_80128668(object);
    }
}

int fn_801345A4(int, int);
void fn_8013436C(int);
void fn_802E30C8(const char *, ...);
extern char lbl_8034BCF0[]; /* "modpool: oldest_model is NULL (%d)" */
#pragma push
#pragma scheduling invalid_target
#pragma optimize_for_size on
#pragma use_lmw_stmw off
/* Reclaim a model-pool slot when the pool is full: clear entries whose load has
 * finished, pick the oldest idle (state 2) entry as a victim and evict it, then
 * poll the load pool. */
void fn_802CE4F4(void *arg0, int arg1) {
    void *entry;
    int best;
    int active;
    int i;
    int offset;
    void *manager = arg0;
    void *selected;
    active = 0;
    selected = 0;
    best = -1;
    i = 0;
    offset = 0;
    while (i < *(int *)((char *)manager + 8)) {
        entry = (char *)*(void **)manager + offset;
        if (*(int *)((char *)entry + 0x38) == 3 &&
            fn_801345A4(*(int *)((char *)manager + 4), *(int *)((char *)entry + 0x2C))) {
            *(int *)((char *)entry + 0x38) = 0;
            *(int *)((char *)entry + 0x2C) = -1;
        }
        if (*(int *)((char *)entry + 0x38) != 0) active++;
        if (*(int *)((char *)entry + 0x38) == 2) {
            int delta = *(int *)((char *)manager + 0x10) - *(int *)((char *)entry + 0x3C);
            if (delta > best || selected == 0) {
                best = delta;
                selected = entry;
            }
        }
        offset += 0x40;
        i++;
    }
    if (*(int *)((char *)manager + 0xC) - active < 1) {
        if (selected != 0) {
            if (*(int *)((char *)selected + 0x38) == 2) {
                fn_802C6FB4(*(int *)((char *)selected + 0x30));
                fn_802C703C(*(int *)((char *)selected + 0x34));
                *(int *)((char *)selected + 0x34) = -1;
                *(int *)((char *)selected + 0x30) = 0;
                *(int *)((char *)selected + 0x38) = 3;
            }
        } else {
            fn_802E30C8(lbl_8034BCF0, *(int *)((char *)manager + 0x10));
        }
    }
    fn_8013436C(*(int *)((char *)manager + 4));
}
#pragma pop
#pragma scheduling on

#pragma push
#pragma scheduling invalid_target
void *fn_802CE630(void *pool, const char *name, int value) {
    /* Find a free 0x40-byte pool entry, initialize it with name/value, and return it (or NULL if full). */
    int count = *(int *)((char *)pool + 8);
    int offset = 0;
    unsigned char *entry;
    while (count > 0) {
        entry = (unsigned char *)*(char **)pool + offset;
        if (*entry == 0 && *(int *)(entry + 0x38) == 0) {
            entry[0] = 1;
            *(void **)(entry + 4) = pool;
            strcpy((char *)entry + 8, name);
            *(int *)(entry + 0x28) = value;
            goto done;
        }
        offset += 0x40;
        count--;
    }
    entry = 0;
done:
    return entry;
}
#pragma pop
void fn_802CE6C0(void *slot) {
    /* Release a loaded modpool slot (state 2): destroy its model/handle, mark state 3, and clear the in-use flag. */
    if (*(int *)((char *)slot + 0x38) == 2 && *(int *)((char *)slot + 0x38) == 2) {
        fn_802C6FB4(*(int *)((char *)slot + 0x30));
        fn_802C703C(*(int *)((char *)slot + 0x34));
        *(volatile int *)((char *)slot + 0x34) = -1;
        *(volatile int *)((char *)slot + 0x30) = 0;
        *(volatile int *)((char *)slot + 0x38) = 3;
    }
    *(unsigned char *)slot = 0;
}

/* Returns the loaded model handle from a ready model-pool slot (state 2 at +0x38),
   or -1 when the slot is not in the loaded state. */
int fn_802CE728(void *slot) {
    if (*(int *)((char *)slot + 0x38) == 2) {
        return *(int *)((char *)slot + 0x34);
    }
    return -1;
}

extern void fn_802CE7D4(int, int, void *);
extern int fn_80134424(int, void *, int, int *, void *, void *, int, int);
#pragma push
#pragma scheduling invalid_target
void fn_802CE744(void *slot) {
    /* Stamp the slot with the pool's load counter and, if idle, start an async MODL load. */
    void *manager = *(void **)((char *)slot + 4);
    int requestId;
    int resultSize;

    *(int *)((char *)slot + 0x3C) = (*(int *)((char *)manager + 0x10))++;
    if (*(int *)((char *)slot + 0x38) == 0) {
        resultSize = 0;
        requestId = fn_80134424(
            *(int *)((char *)manager + 4),
            (char *)slot + 8,
            0x4D4F444C,
            &resultSize,
            (void *)fn_802CE7D4,
            slot,
            0,
            -1);
        if (requestId >= 0) {
            *(int *)((char *)slot + 0x2C) = requestId;
            *(int *)((char*)slot + 0x38) = 1;
        }
    }
}
#pragma pop
#pragma scheduling on
void fn_802CE7D4(int arg0, int arg1, void *arg2);
/* ModPool_onLoadComplete: async MODL load callback that fixes up the model resource, registers its textures, and creates a model instance if the slot is still in use. */
void fn_802CE7D4(int modelData, int dataSize, void *userData) {
#define mrModelFixupResource fn_802C61BC
#define mrModelRegisterTextures fn_802C6FA8
#define mrModelCreateInstance fn_802C6DC4
    unsigned char *slot = (unsigned char *)userData;
    if (*slot != 0) {
        *(int *)(slot + 0x30) = modelData;
        mrModelFixupResource(modelData, slot + 8);
        mrModelRegisterTextures(*(int *)(slot + 0x30));
        *(int *)(slot + 0x34) = mrModelCreateInstance(slot + 8, *(int *)(slot + 0x30), 0, 0);
        *(int *)(slot + 0x38) = 2;
    } else {
        *(int *)(slot + 0x38) = 0;
        *(int *)(slot + 0x2C) = -1;
    }
#undef mrModelCreateInstance
#undef mrModelRegisterTextures
#undef mrModelFixupResource
}

/* Return the load state of this ModPool slot (0 = unused, 1 = loading, 2 = loaded). */
int fn_802CE850(void *slot) {
    return *(int *)((char *)slot + 0x38);
}

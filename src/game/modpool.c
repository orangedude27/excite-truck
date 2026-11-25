// modpool — model pool ("modpool: oldest_model is NULL", loadpool).
// Recovered TU window 0x802CE3A4..0x802CE858+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CE858 (+ .ctors slot 0x802ED5B8) remains in
// auto/text_802CE858_.c pending a promotion pass.
int fn_80128668(void *);
int fn_80128670(int);
int fn_801342B0(int, int);
char *strcpy(char *, const char *);
void mrModelUnregisterTextures(int);
void fn_802C703C(int);
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8013420C(int, int);
extern void *fn_8002F37C(void *, int, int, int);
extern char lbl_8034BCE4[]; /* "loadpool" - allocation name for the load pool */
extern char lbl_8034BCD8[]; /* "modelpool" - allocation name for model storage */
extern void modPoolInitSlot(void *);
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
        *(void **)manager = ((void *(*)(void *, void *, int, int, int))fn_8002F37C)(slotStorage, modPoolInitSlot, 0, 0x40, count);
        *(int *)((char *)manager + 0x10) = 0;
    }
    return manager;
}

/* Reset one 0x40-byte model-pool slot: clear its in-use flag and state, drop its handles and request, and reset its timestamp. */ void modPoolInitSlot(void *modelSlot) {
    /* Initialise one 0x40-byte model-pool slot to its empty state: clear the
     * manager pointer, in-use flag and state, and reset the load/model handles
     * and timestamp to their "none" values. */
    *(int *)((char *)modelSlot + 4) = 0;
    *(unsigned char *)modelSlot = 0;
    *(int *)((char *)modelSlot + 0x38) = 0;
    *(int *)((char *)modelSlot + 0x34) = -1;
    *(int *)((char *)modelSlot + 0x30) = 0;
    *(int *)((char *)modelSlot + 0x2C) = -1;
    *(int *)((char *)modelSlot + 0x3C) = -1;
}

/* Destroy a model-pool manager: free its slot-storage block, delete the load pool, then free the manager itself. */ void modPoolDestroy(void *manager) {
    int slotStorage;
    /* Destroys a modpool object: frees its data buffer, releases its load pool, and deletes the object. */
    if (manager != 0) {
        slotStorage = *(int *)manager;
        if (slotStorage != 0) {
            fn_80128670(slotStorage - 0x10);
        }
        fn_801342B0(*(int *)((char *)manager + 4), 1);
        fn_80128668(manager);
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
                mrModelUnregisterTextures(*(int *)((char *)selected + 0x30));
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
    /* Reserve a free 0x40-byte slot in the model pool, filling in its name and
       value, or return NULL if every slot is taken. */
    struct ModelSlot {
        unsigned char inUse;      /* 0x00 */
        unsigned char pad0[3];    /* 0x01 */
        void *manager;            /* 0x04 */
        char name[0x20];          /* 0x08 */
        int value;                /* 0x28 */
        unsigned char pad2[0x0C]; /* 0x2C */
        int state;                /* 0x38 */
    };
    struct ModelPool {
        struct ModelSlot *slots;  /* 0x00 */
        void *loadPool;           /* 0x04 */
        int slotCount;            /* 0x08 */
    };
    struct ModelPool *mgr = (struct ModelPool *)pool;
    int remaining = mgr->slotCount;
    int offset = 0;
    struct ModelSlot *entry;

    while (remaining > 0) {
        entry = (struct ModelSlot *)((char *)mgr->slots + offset);
        if (entry->inUse == 0 && entry->state == 0) {
            entry->inUse = 1;
            entry->manager = mgr;
            strcpy(entry->name, name);
            entry->value = value;
            goto done;
        }
        offset += 0x40;
        remaining--;
    }
    entry = 0;
done:
    return entry;
}
#pragma pop
/* Release a loaded model-pool slot (state 2): drop its model data and instance, reset both handles to their none values, set state 3 (finished, awaiting reclaim), and clear its in-use flag. */ void modPoolReleaseLoadedSlot(void *modelSlot) {
    /* Release a loaded modpool slot (state 2): destroy its model/handle, mark state 3, and clear the in-use flag. */
    if (*(int *)((char *)modelSlot + 0x38) == 2 && *(int *)((char *)modelSlot + 0x38) == 2) {
        mrModelUnregisterTextures(*(int *)((char *)modelSlot + 0x30));
        fn_802C703C(*(int *)((char *)modelSlot + 0x34));
        *(volatile int *)((char *)modelSlot + 0x34) = -1;
        *(volatile int *)((char *)modelSlot + 0x30) = 0;
        *(volatile int *)((char *)modelSlot + 0x38) = 3;
    }
    *(unsigned char *)modelSlot = 0;
}

/* Returns the loaded model handle from a ready model-pool slot (state 2 at +0x38),
   or -1 when the slot is not in the loaded state. */
/* Return the loaded model id stored at +0x34 when this model-pool slot is loaded (state 2 at +0x38), otherwise -1. */ int modPoolGetLoadedModelId(void *slot) {
    if (*(int *)((char *)slot + 0x38) == 2) {
        return *(int *)((char *)slot + 0x34);
    }
    return -1;
}

extern void fn_802CE7D4(int, int, void *);
extern int fn_80134424(int, void *, int, int *, void *, void *, int, int);
#pragma push
#pragma scheduling invalid_target
/* Stamp a model-pool slot with the pool's request counter (+0x3C) and, when it is idle (+0x38 == 0), start an async 'MODL' load into it, saving the request id at +0x2C and marking the slot busy. */ void fn_802CE744(void *modelSlot) {
    /* Stamp the slot with the pool's load counter and, if idle, start an async MODL load. */
    void *pool = *(void **)((char *)modelSlot + 4);
    int requestId;
    int loadedSize;

    *(int *)((char *)modelSlot + 0x3C) = (*(int *)((char *)pool + 0x10))++;
    if (*(int *)((char *)modelSlot + 0x38) == 0) {
        loadedSize = 0;
        requestId = fn_80134424(
            *(int *)((char *)pool + 4),
            (char *)modelSlot + 8,
            0x4D4F444C,
            &loadedSize,
            (void *)fn_802CE7D4,
            modelSlot,
            0,
            -1);
        if (requestId >= 0) {
            *(int *)((char *)modelSlot + 0x2C) = requestId;
            *(int *)((char*)modelSlot + 0x38) = 1;
        }
    }
}
#pragma pop
#pragma scheduling on
void fn_802CE7D4(int arg0, int arg1, void *arg2);
/* ModPool_onLoadComplete: async MODL load callback that fixes up the model resource, registers its textures, and creates a model instance if the slot is still in use. */
/* Async MODL-load callback: if the model-pool slot is still busy, store the loaded resource, fix it up, register its textures and create a model instance (state 2); otherwise mark the slot idle with no request. */ /* Async MODL-load callback: if the model-pool slot is still busy, store the loaded resource, fix it up, register its textures and create a model instance (state 2); otherwise mark the slot idle with no request. */ void fn_802CE7D4(int modelData, int loadedSize, void *modelSlot) {
#define mrModelFixupResource fn_802C61BC
#define mrModelCreateInstance fn_802C6DC4
    unsigned char *slot = (unsigned char *)modelSlot;
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
#undef mrModelFixupResource
}

/* Return the load state of this ModPool slot (0 = unused, 1 = loading, 2 = loaded). */
int fn_802CE850(void *slot) {
    return *(int *)((char *)slot + 0x38);
}

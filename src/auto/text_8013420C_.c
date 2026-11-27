// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
// Load pool / async stream pool: init, destroy/cancel, poll, request, and release helpers.
// (fn_/lbl_ names kept: rename_symbol not available for this project yet.)

typedef int s32;
typedef unsigned int u32;

/* Slot in a load pool's entry table (0x18 bytes). */
typedef struct LoadPoolEntry {
    s32 state;                    /* 0 = free, 1 = loading, 2 = ready */
    s32 unk4;                     /* per-entry word (buffer/offset context) */
    void *obj;                    /* active stream/load object */
    void (*cb)(void *, void *, void *); /* completion callback */
    void *unk10;                  /* callback user data */
    s32 pad;                      /* reserved / request size */
} LoadPoolEntry;

/* Load pool container. */
typedef struct LoadPool {
    void *data;                   /* backing data buffer */
    s32 count;                    /* number of entries */
    s32 stride;                   /* bytes per data slot */
    LoadPoolEntry *entries;       /* entry array */
} LoadPool;

/* String constants used by the load pool: the "loadbuf" allocation tag and the
 * "loadlost..." family of diagnostic messages (selected by offsets from the base). */
extern void *lbl_80559BD0; /* "loadbuf" */
extern char lbl_8032BB18[]; /* "loadlost" - base of the diagnostic message table */
extern char lbl_8032BB24[]; /* "loadpool: canceling stream..." */
#define gLoadPoolBufferTag lbl_80559BD0
#define gLoadPoolErrorMsgs lbl_8032BB18
#define sLoadPoolCancelStreamMsg lbl_8032BB24

s32 fn_8012850C(s32, void *); /* allocate a tagged block (heap op 0) */
s32 fn_8012C7FC(void *, s32 *); /* poll a stream load for completion */
void fn_8012C958(void *); /* finalize/reset stream/load object */
void fn_8012C90C(void *); /* cancel/stop active stream/load object */
void fn_80128670(void *); /* free block (heap op 0) */
void fn_80128668(void *); /* free block (heap op 3) */
void fn_802E30C8(const char *, ...); /* formatted log/warning */
#pragma unroll off
#pragma scheduling invalid_target
/* Initializes a buffer and an entry table, storing per-entry pointers into the buffer. */
void *fn_8013420C(void *self, s32 count, s32 stride) {
    s32 *base = (s32 *)self;
    s32 byteOffset;
    s32 index;

    base[1] = count;
    base[2] = stride;
    base[0] = fn_8012850C(count * stride, (void *)&gLoadPoolBufferTag);
    count = base[1];
    base[3] = fn_8012850C(count * 0x18, gLoadPoolErrorMsgs);
    for (index = 0, byteOffset = 0; index < base[1]; byteOffset += 0x18, index++) {
        s32 *entry = (s32 *)((char *)base[3] + byteOffset);
        entry[1] = base[0] + index * base[2];
        entry[0] = 0;
        entry[2] = 0;
    }
    return self;
}
#pragma use_lmw_stmw off
/* Cancels any in-progress load/stream slots, frees pool buffers, and optionally deletes the pool. */
void *fn_801342B0(LoadPool *pool, s32 deletePool, s32 unused) {
    s32 i;
    LoadPoolEntry *entry;
    if (pool != 0) {
        for (i = 0; i < pool->count; i++) {
            entry = (LoadPoolEntry *)((char *)pool->entries + i * 0x18);
            if (entry->state != 0) {
                if (entry->state == 1) {
                    fn_802E30C8(sLoadPoolCancelStreamMsg);
                    fn_8012C90C(entry->obj);
                    fn_8012C958(entry->obj);
                }
            }
        }
        fn_80128670(pool->entries);
        fn_80128670(pool->data);
        if (deletePool > 0) fn_80128668(pool);
    }
    return pool;
}
/* Polls the load pool: for each entry in the loading state, check completion and invoke the callback if ready. */
void fn_8013436C(LoadPool *pool, s32 unused) {
    s32 i;
    LoadPoolEntry *entry;
    s32 result;
    s32 value;
    for (i = 0; i < pool->count; i++) {
        entry = (LoadPoolEntry *)((char *)pool->entries + i * 0x18);
        if (entry->state == 1) {
            value = 0;
            result = fn_8012C7FC(entry->obj, &value);
            if (result != 0) {
                entry->state = 2;
                fn_8012C958(entry->obj);
                entry->obj = 0;
                if (entry->cb != 0) entry->cb((void *)result, (void *)value, entry->unk10);
            }
        }
    }
}
#pragma use_lmw_stmw reset
s32 openResourceStream(s32, s32, s32); /* open a resource stream (path, tag, size) */
s32 fn_8012C6F0(void *); /* query a stream's resource size */
void fn_8012C720(void *, s32, s32, s32); /* start a stream transfer */
void Abend_Panic(const char *, ...); /* formatted log/warning */
#pragma use_lmw_stmw off
/* Reserve a load-pool slot for a resource stream: refuse if three loads are
 * already active, otherwise claim the first free entry, open the resource with
 * openResourceStream, set its callback/user data, validate the requested byte count
 * against the pool's slot stride and the resource size, and start the transfer.
 * Returns the slot index, or -1 if none is available. */
s32 loadPoolStartRequest(LoadPool *pool, s32 path, s32 dataTag, s32 outSize, s32 callback, s32 userData, s32 sourceOffset, s32 byteCount, s32 arg8) {
    struct Params {
        s32 sourceOffset;
        s32 userData;
        s32 callback;
        s32 path;
        LoadPool *pool;
        char *msgBase;
    } p;
    s32 slot;
    s32 activeCount;
    LoadPoolEntry *entry;
    s32 dataSize;

    p.pool = pool;
    p.path = path;
    p.callback = callback;
    p.userData = userData;
    p.sourceOffset = sourceOffset;
    p.msgBase = gLoadPoolErrorMsgs;
    activeCount = 0;
    for (slot = 0; slot < p.pool->count; slot++) {
        entry = (LoadPoolEntry *)((char *)p.pool->entries + slot * 0x18);
        if (entry->state == 1) activeCount++;
    }
    if (activeCount >= 3) return -1;

    for (slot = 0; slot < p.pool->count; slot++) {
        entry = (LoadPoolEntry *)((char *)p.pool->entries + slot * 0x18);
        if (entry->state == 0) {
            entry->state = 1;
            entry->obj = (void *)openResourceStream(p.path, dataTag, outSize);
            if (entry->obj == 0) Abend_Panic(p.msgBase + 0x30, p.path);
            entry->cb = (void (*)(void *, void *, void *))p.callback;
            entry->unk10 = (void *)p.userData;
            dataSize = fn_8012C6F0(entry->obj);
            if (byteCount <= 0) byteCount = dataSize;
            if (byteCount > p.pool->stride) Abend_Panic(p.msgBase + 0x48, p.path, byteCount, p.pool->stride);
            if (p.sourceOffset + byteCount > dataSize) Abend_Panic(p.msgBase + 0x70, dataSize, p.sourceOffset, byteCount);
            entry->pad = byteCount;
            fn_8012C720(entry->obj, entry->unk4, byteCount, p.sourceOffset);
            return slot;
        }
    }
    return -1;
}
#pragma use_lmw_stmw reset

#pragma scheduling invalid_target
/* Releases a load-pool slot by clearing its state, unless the slot is still
 * loading (state 1). Returns 1 on success, 0 if the load is in progress. */
s32 fn_801345A4(LoadPool *pool, s32 index) {
    if (pool->entries[index].state == 1) return 0;
    pool->entries[index].state = 0;
    return 1;
}
#pragma scheduling on

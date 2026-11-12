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

/* Compatibility aliases for other matched functions in this unit. */
typedef LoadPoolEntry Entry;
typedef LoadPool Container;

extern void *lbl_80559BD0;
extern char lbl_8032BB18[];
extern char lbl_8032BB24[]; /* "loadpool: canceling stream..." */
#define sLoadPoolCancelStreamMsg lbl_8032BB24

s32 fn_8012850C(s32, void *);
s32 fn_8012C7FC(void *, s32 *);
void fn_8012C958(void *); /* finalize/reset stream/load object */
void fn_8012C90C(void *); /* cancel/stop active stream/load object */
void fn_80128670(void *); /* free block (heap op 0) */
void fn_80128668(void *); /* free block (heap op 3) */
void fn_802E30C8(const char *, ...); /* formatted log/warning */
#pragma unroll off
#pragma scheduling invalid_target
void *fn_8013420C(void *arg0, s32 arg1, s32 arg2) {
    s32 *base = (s32 *)arg0;
    s32 offset;
    s32 i;

    base[1] = arg1;
    base[2] = arg2;
    base[0] = fn_8012850C(arg1 * arg2, (void *)&lbl_80559BD0);
    arg1 = base[1];
    base[3] = fn_8012850C(arg1 * 0x18, lbl_8032BB18);
    for (i = 0, offset = 0; i < base[1]; offset += 0x18, i++) {
        s32 *entry = (s32 *)((char *)base[3] + offset);
        entry[1] = base[0] + i * base[2];
        entry[0] = 0;
        entry[2] = 0;
    }
    return arg0;
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
s32 fn_8012C5B8(s32, s32, s32);
s32 fn_8012C6F0(void *);
void fn_8012C720(void *, s32, s32, s32);
void fn_802E317C(const char *, ...);
#pragma use_lmw_stmw off
s32 fn_80134424(Container *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 i;
    s32 active;
    Entry *entry;
    s32 size;
    char *message;

    message = lbl_8032BB18;
    active = 0;
    for (i = 0; i < arg0->count; i++) {
        entry = (Entry *)((char *)arg0->entries + i * 0x18);
        if (entry->state == 1) active++;
    }
    if (active >= 3) return -1;

    for (i = 0; i < arg0->count; i++) {
        entry = (Entry *)((char *)arg0->entries + i * 0x18);
        if (entry->state == 0) {
            entry->state = 1;
            entry->obj = (void *)fn_8012C5B8(arg1, arg2, arg3);
            if (entry->obj == 0) fn_802E317C(message + 0x30, arg1);
            entry->cb = (void (*)(void *, void *, void *))arg4;
            entry->unk10 = (void *)arg5;
            size = fn_8012C6F0(entry->obj);
            if (arg7 <= 0) arg7 = size;
            if (arg7 > arg0->stride) fn_802E317C(message + 0x48, arg1, arg7);
            if (arg6 + arg7 > size) fn_802E317C(message + 0x70, size, arg6, arg7);
            entry->pad = arg7;
            fn_8012C720(entry->obj, entry->unk4, arg7, arg6);
            return i;
        }
    }
    return -1;
}
#pragma use_lmw_stmw reset

#pragma scheduling invalid_target
s32 fn_801345A4(Container *arg0, s32 arg1) {
    if (arg0->entries[arg1].state == 1) return 0;
    arg0->entries[arg1].state = 0;
    return 1;
}
#pragma scheduling on

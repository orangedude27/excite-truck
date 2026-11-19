// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F730;
extern unsigned char lbl_804B34B0[];
extern char lbl_80349100[];
extern void fn_8000D838(void *);

typedef struct { char items[0x100]; int count; } EfListT;
typedef struct { char entries[0x600]; int count; void *table; } CacheT;

static inline void efClear(EfListT *list) {
    list->count = 0;
}
static inline void cacheInit(CacheT *cache, void *table) {
    cache->table = table;
    cache->count = 0;
}

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80291728(void) {
    unsigned char *p;
    volatile unsigned int *a;
    volatile unsigned int *b;
    volatile unsigned int *c;
    p = lbl_804B34B0;
    fn_8000D838(&lbl_8055F730);
    a = (volatile unsigned int *)p;
    a[64] = 0;
    b = (volatile unsigned int *)(p + 0x104);
    b[64] = 0;
    c = (volatile unsigned int *)(p + 0x208);
    c[385] = (unsigned int)lbl_80349100;
    c[384] = 0;
}

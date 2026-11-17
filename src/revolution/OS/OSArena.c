#include <revolution/OS.h>

static void* __OSArenaLo = (void*)-1;
static void* s_mem2ArenaLo = (void*)-1;
static void* __OSArenaHi = NULL;
static void* s_mem2ArenaHi = NULL;

/* Return the upper bound of the MEM1 arena. */
void* OSGetMEM1ArenaHi(void) {
    return __OSArenaHi;
}

void* OSGetMEM2ArenaHi(void) {
    /* Return the high bound of the MEM2 arena. */
    return s_mem2ArenaHi;
}

/* Return the upper bound of the default MEM1 arena. */
void* OSGetArenaHi(void) {
    return OSGetMEM1ArenaHi();
}

/* Return the lower bound of the MEM1 arena. */
void* OSGetMEM1ArenaLo(void) {
    return __OSArenaLo;
}

void* OSGetMEM2ArenaLo(void) {
    /* Return the low bound of the MEM2 arena. */
    return s_mem2ArenaLo;
}

/* Return the low bound of the default (MEM1) arena. */
void* OSGetArenaLo(void) {
    return OSGetMEM1ArenaLo();
}

/* Set the high bound of the MEM1 arena. */
void OSSetMEM1ArenaHi(void* arenaHi) {
    __OSArenaHi = arenaHi;
}

void OSSetMEM2ArenaHi(void* hi) {
    s_mem2ArenaHi = hi;
}

/* Set the high bound of the default (MEM1) arena. */
void OSSetArenaHi(void* arenaHi) {
    OSSetMEM1ArenaHi(arenaHi);
}

void OSSetMEM1ArenaLo(void* lo) {
    __OSArenaLo = lo;
}

/* Set the low bound of the MEM2 arena. */
void OSSetMEM2ArenaLo(void* arenaLo) {
    s_mem2ArenaLo = arenaLo;
}

/* Set the low bound of the default (MEM1) arena. */
void OSSetArenaLo(void* arenaLo) {
    OSSetMEM1ArenaLo(arenaLo);
}

void* OSAllocFromMEM1ArenaLo(size_t size, u32 align) {
    /* Bump-allocate size bytes from the low end of the MEM1 arena: align the
       start and the new arena bound, advance the bound, and return the start. */
    u8* begin = ROUND_UP_PTR(OSGetMEM1ArenaLo(), align);
    u8* end = begin + size;
    end = ROUND_UP_PTR(end, align);
    OSSetMEM1ArenaLo(end);
    return begin;
}

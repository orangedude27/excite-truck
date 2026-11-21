#include <revolution/OS.h>

static void* __OSArenaLo = (void*)-1;
static void* __OSArena2Lo = (void*)-1;
static void* __OSArenaHi = NULL;
static void* __OSArena2Hi = NULL;

/* Return the upper bound of the MEM1 arena. */
void* OSGetMEM1ArenaHi(void) {
    return __OSArenaHi;
}

/* Return the high bound of the MEM2 arena. */
void* OSGetMEM2ArenaHi(void) {
    return __OSArena2Hi;
}

/* Return the upper bound of the default (MEM1) arena. */
void* OSGetArenaHi(void) {
    return OSGetMEM1ArenaHi();
}

/* Return the lower bound of the MEM1 arena. */
void* OSGetMEM1ArenaLo(void) {
    return __OSArenaLo;
}

/* Return the low bound of the MEM2 arena. */
void* OSGetMEM2ArenaLo(void) {
    return __OSArena2Lo;
}

/* Return the low bound of the default (MEM1) arena. */
void* OSGetArenaLo(void) {
    return OSGetMEM1ArenaLo();
}

/* Set the high bound of the MEM1 arena. */
void OSSetMEM1ArenaHi(void* arenaHi) {
    __OSArenaHi = arenaHi;
}

/* Set the upper bound of the MEM2 arena. */
void OSSetMEM2ArenaHi(void* arenaHi) {
    __OSArena2Hi = arenaHi;
}

/* Set the high bound of the default (MEM1) arena. */
void OSSetArenaHi(void* arenaHi) {
    OSSetMEM1ArenaHi(arenaHi);
}

/* Set the lower bound of the MEM1 arena. */
void OSSetMEM1ArenaLo(void* arenaLo) {
    __OSArenaLo = arenaLo;
}

/* Set the low bound of the MEM2 arena. */
void OSSetMEM2ArenaLo(void* arenaLo) {
    __OSArena2Lo = arenaLo;
}

/* Set the low bound of the default (MEM1) arena. */
void OSSetArenaLo(void* arenaLo) {
    OSSetMEM1ArenaLo(arenaLo);
}

/* Bump-allocate size bytes from the low end of the MEM1 arena: align the start
   and the new arena bound, advance the bound, and return the start. */
void* OSAllocFromMEM1ArenaLo(size_t size, u32 align) {
    u8* begin = ROUND_UP_PTR(OSGetMEM1ArenaLo(), align);
    u8* end = begin + size;
    end = ROUND_UP_PTR(end, align);
    OSSetMEM1ArenaLo(end);
    return begin;
}

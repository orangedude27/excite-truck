// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
void fn_801279E0(void);
/* Header of the profiler's index list: data points just past this struct,
   capacity is the room in words, count is how many words are in use. */
struct State { void *data; int capacity; int count; };

extern int lbl_8055DF10;
extern struct State lbl_8041DEE0;
void fn_801279E0(void) {
    #pragma scheduling invalid_target
    /* RealName: ProfilerListInit — a .ctors entry. Register this unit's static-destructor
       record, then bring up the profiler's active-index list as an empty buffer with
       room for 16 32-bit words. */
#define dtorRecord   lbl_8055DF10
#define profilerList lbl_8041DEE0
    fn_8000D838(&dtorRecord);
    profilerList.data = (char *)&profilerList + 0xC;
    profilerList.capacity = 0x10;
    profilerList.count = 0;
#undef dtorRecord
#undef profilerList
}

#pragma section ".ctors$00"
DECL_SECTION(".ctors") funcptr_t D_802ED120 = fn_801279E0;

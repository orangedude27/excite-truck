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
    /* RealName: ProfilerListInit. Static constructor: register a static-destructor
       record for lbl_8055DF10 and bring up the profiler index list as an empty
       header with room for 16 words. */
    fn_8000D838(&lbl_8055DF10);
    lbl_8041DEE0.data = (char *)&lbl_8041DEE0 + 0xC;
    lbl_8041DEE0.capacity = 0x10;
    lbl_8041DEE0.count = 0;
}

#pragma section ".ctors$00"
DECL_SECTION(".ctors") funcptr_t D_802ED120 = fn_801279E0;

#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern s32 lbl_80498998[];
extern s32 lbl_8055F280;
extern s32 lbl_8055F288;
void fn_8000D838(void*);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8024BD8C(void) {
    #define INIT_STATE lbl_8055F280
    #define STATE_BLOCK lbl_80498998
    #define INIT_FLAGS lbl_8055F288

    /* Static initializer: sets up the state block and initializes the associated state object. */
    s32 value;
    s32 *block;

    fn_8000D838(&INIT_STATE);
    block = STATE_BLOCK + 1;
    STATE_BLOCK[0] = 0;
    value = 0x7B;
    STATE_BLOCK[1] = value;
    STATE_BLOCK[2] = 0;
    STATE_BLOCK[3] = 0;
    STATE_BLOCK[4] = 0;
    INIT_FLAGS = 0x7F000000;

    #undef INIT_STATE
    #undef STATE_BLOCK
    #undef INIT_FLAGS
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED434 = fn_8024BD8C;

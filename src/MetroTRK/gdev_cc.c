#include <types.h>
/* Review-source carve for the REXE01 MetroTRK gdev serial port cluster
 * (auto_03_800301FC_text, unattributed SDK-unknown region):
 *
 *   usr_puts_serial@80030D00      -> clears 3 sbss words
 *   gdev_cc_initialize@80031250   -> picks the next 0x300-byte CC buffer
 *   CircleBufferWriteBytes@80031C30 -> initializes the CC ring-buffer state
 *
 * Shared state: ring buffer at lbl_8035E820 (0x300 stride), sbss
 * lbl_8055D720..lbl_8055D748 (write/timing/count words).
 * TU stays unconfigured/review only.
 */

extern u8 lbl_8035E820[];

extern u32 lbl_8055D720;
extern u32 lbl_8055D724;
extern u32 lbl_8055D728;
extern u16 lbl_8055D730;
extern u16 lbl_8055D732;
extern u16 lbl_8055D734;
extern u32 lbl_8055D738;
extern u32 lbl_8055D740;
extern u32 lbl_8055D744;
extern u32 lbl_8055D748;

void usr_puts_serial(void) {
    lbl_8055D728 = 0;
    lbl_8055D724 = 0;
    lbl_8055D720 = 0;
}

void* gdev_cc_initialize(void) {
    u32 old = lbl_8055D748;
    u32 next = (old + 1) & 1;

    lbl_8055D748 = next;
    lbl_8055D744 = (u32)lbl_8035E820 + next * 0x300;

    return &lbl_8035E820[old * 0x300];
}

void CircleBufferWriteBytes(void) {
    u16 mask = 0x8000;

    lbl_8055D740 = 0;
    lbl_8055D748 = 0;
    lbl_8055D744 = (u32)lbl_8035E820;
    lbl_8055D738 = 1;
    lbl_8055D734 = mask;
    lbl_8055D732 = mask;
    lbl_8055D730 = mask;
}
/* Promotion TU for the single clean-promotion game-region AX accessor stub.
 *
 * __AXGetStudio_8000D82C is at a clean auto-unit boundary (the next
 * function starts at 0x8000D838), so the carve 0x8000D82C..0x8000D838 is
 * a strict 12-byte match with no remainder dependencies.
 *
 * Body is 3 instructions (lis; addi; blr) -- trivial accessor.
 *
 * The full carve of all 25 game-region AX/DSP accessor stubs is in
 * src/game/game_ax_stubs.c (review-only, unconfigured); this file is the
 * small configured subset promoted into the link.
 *
 * Strict-MATCH at promotion time.
 */
#include <types.h>

extern u8 lbl_802FC200[];  /* .data */

void* __AXGetStudio_8000D82C(void) {
    return &lbl_802FC200;
}

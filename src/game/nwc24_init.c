/* Review-source carve for the REXE01 game-region NWC24Data_Init clones.
 *
 * Both functions are 4-instruction stubs that zero the first 8 bytes of the
 * NWC24Data struct at this_. They differ only by address (game has multiple
 * NWC24 data init entry points, one per game module).
 *
 * Functions:
 *   NWC24Data_Init_801B6098  (auto_03_801B5F40_text)
 *   NWC24Data_Init_801E1028  (auto_03_801E0710_text)
 *
 * Review-only; not configured.
 */

#include <types.h>

void NWC24Data_Init_801B6098(void* this_) {
    ((u32*)this_)[0] = 0;
    ((u32*)this_)[1] = 0;
}

void NWC24Data_Init_801E1028(void* this_) {
    ((u32*)this_)[0] = 0;
    ((u32*)this_)[1] = 0;
}

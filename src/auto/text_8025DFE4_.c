// Code of main that had no source file yet: decomp.wtf gave it this one.
  // split_file divides it into the game's real files (file_status shows its range).
  
  #include <types.h>
  
  extern void *lbl_8055F3B8;
  extern s32 lbl_8055F3C0;
  extern s32 lbl_80498ED0[];
  void fn_8000D838(void *);

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_8025DFE4(void) {
    /* Initializes a 5-word global state block, its associated flag word, and registers lbl_8055F3B8. */
    s32 initValue;
    s32 *statePtr;
    fn_8000D838(&lbl_8055F3B8);
    statePtr = lbl_80498ED0 + 1;
    lbl_80498ED0[0] = 0;
    initValue = 0x7B;
    lbl_80498ED0[1] = initValue;
    lbl_80498ED0[2] = 0;
    lbl_80498ED0[3] = 0;
    lbl_80498ED0[4] = 0;
    lbl_8055F3C0 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on

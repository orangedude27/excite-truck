// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* No-op SPU idle hook (spuIdleNoop), called once before the reset callback is
 * registered in fn_802E6B04; this build leaves it empty. */
void fn_802E7770(void) {
}

/* Invokes callback if it is non-null, then returns 0. */
int fn_802E7774(int (*callback)(void)) {
    if (callback != 0) {
        callback();
    }
    return 0;
}

/* No-op subsystem startup hook, paired with the shutdown hook fn_802E77AC.
 * Called just after LCEnable during kernel boot; intentionally empty here. */
void fn_802E77A8(void) {
}

/* Final no-op teardown hook in the kernel shutdown sequence (fn_802E2B34);
 * this build leaves it empty. */
void fn_802E77AC(void) {
}


/* Empty SDK hooks and a trivial callback invoker that had no original source
 * file. The SPU code calls fn_802E7770 / fn_802E7774 through the local aliases
 * spuIdleNoop / invokeCallback. */

/* No-op SPU idle hook (spuIdleNoop): called once just before fn_802E6B04
 * registers the SPU reset callback; this build leaves it empty. */
void fn_802E7770(void) {}

/* Invokes callback if it is non-null, then returns 0; spu.c calls this
 * invokeCallback. */
int fn_802E7774(int (*callback)(void)) {
    if (callback != 0) {
        callback();
    }
    return 0;
}

/* No-op subsystem startup hook, paired with the shutdown hook fn_802E77AC.
 * Called just after LCEnable during kernel boot; intentionally empty here. */
void fn_802E77A8(void) {}

/* Final no-op teardown hook in the kernel shutdown sequence (KERNEL_Shutdown);
 * this build leaves it empty. */
void fn_802E77AC(void) {}


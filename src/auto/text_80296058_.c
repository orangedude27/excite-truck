/* Empty/default subsystem hooks that this build does not use: pool-element
 * constructor, init/teardown callbacks and a zero-returning query stub. */

/* No-op per-entry constructor for the 8-entry, 0x184-byte pool that
 * fn_80296014 sets up at lbl_804B42F0 via fn_8002F53C; entries need no
 * initialisation in this build. */
void fn_80296058(void) {
}

/* No-op subsystem init hook, called from fn_80287780's setup sequence
 * alongside the other subsystem initializers; does nothing in this build. */
void fn_8029605C(void) {
}

/* No-op subsystem init hook, called during the global startup sequence
 * (fn_80287914); does nothing in this build. */
void fn_80296060(void) {
}

/* No-op stub: subsystem hook called during the global teardown sequence; does nothing in this build. */
void fn_80296064(void) {
}

/* No-op stub callback that reports zero. */
int fn_80296068(void) {
    return 0;
}

/* No-op placeholder hook alongside the other subsystem stubs in this group; does nothing in this build. */
void fn_80296070(void) {
}


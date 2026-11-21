/* Empty subsystem hooks from code that had no original source file: two no-op
 * slots in the main game/menu init sequence and one in its shutdown sequence. */

/* No-op subsystem init hook: called once in the main game/menu init sequence
 * (fn_80004B5C); this build leaves it empty. */
void fn_802789A8(void) {}

/* No-op subsystem hook: called near the end of the main game/menu init
 * sequence (fn_80004B5C), after the scene handlers are registered. */
void fn_802789AC(void) {}

/* No-op subsystem hook: called during the game/menu shutdown sequence
 * (fn_80004CB4), between the road-sound and scene-handler teardown steps. */
void fn_802789B0(void) {}


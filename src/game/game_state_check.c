/* Recovered with m2c; verified against the original REXE01 instructions.
 * The returned object's concrete game type is not yet known.
 */
extern void* fn_801EA9CC(int index);

int fn_80005694(void) {
    return (*(int*)((char*)fn_801EA9CC(0) + 0x30) - 1) == 0;
}

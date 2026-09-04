/* Review-source carve for the REXE01 game-region DBPrintf save-area stubs.
 *
 * Each DBPrintf_* in the game region is a no-op function whose body is just
 * the standard PPC EABI variadic save area: spill gpr 3..10 and (conditionally
 * on cr1 NE) fpr 1..8 to a 0x70-byte caller frame. The save area is consumed
 * by the actual printf implementation (e.g. OSReport) when it does va_arg.
 *
 * The compiler generates this save area automatically for any function with
 * a `(...)` parameter list, so a trivial `void f(int, ...) { }` body is the
 * exact source shape.
 *
 * Functions:
 *   DBPrintf_8013B490  (auto_03_8013A660_text)
 *   DBPrintf_80179758  (auto_03_80177814_text)
 *   DBPrintf_801797A8  (auto_03_80177814_text)
 *   DBPrintf_80270B00  (auto_03_8026E25C_text)
 *
 * Review-only; not configured.
 */

/* Trivial variadic bodies — the compiler emits the save area prologue. */
void DBPrintf_8013B490(int fmt, ...) {
}

void DBPrintf_80179758(int fmt, ...) {
}

void DBPrintf_801797A8(int fmt, ...) {
}

void DBPrintf_80270B00(int fmt, ...) {
}

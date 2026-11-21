// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;

/* No operation. */
void fn_801B664C(void) {}

/* No operation. */
void fn_801B6650(void) {}

/* Stubbed notification hook.  fn_8018FE8C (the lbl_80333018 object's destructor)
 * calls it while tearing the object down, but only when the query fn_801B6668
 * reports the feature enabled -- which it never does in this build, so this
 * no-op is dead. */
void fn_801B6654(void) {}

/* No operation. */
void fn_801B6658(void) {}

/* No operation. */
void fn_801B665C(void) {}

/* No operation. */
void fn_801B6660(void) {}

/* No operation. */
void fn_801B6664(void) {}

/* Default/stub query hook: always reports false (zero) to the callers that gate optional callbacks on it. */
s32 fn_801B6668(void) {
    return 0;
}


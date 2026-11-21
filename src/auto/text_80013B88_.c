// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char gUnitStaticDtorRecord[4];
extern int gStateWords[5];
extern int fn_8000D838(void*);
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Initialize a small state block: chain this unit's static-destructor record
 * onto the global list, zero the five state words, and set the second to 123. */
void fn_80013B88(void) {
    int initialValue;
    fn_8000D838(&gUnitStaticDtorRecord);
    gStateWords[0] = 0;
    initialValue = 123;
    gStateWords[1] = initialValue;
    gStateWords[2] = 0;
    gStateWords[3] = 0;
    gStateWords[4] = 0;
}
#pragma opt_propagation reset
#pragma scheduling on

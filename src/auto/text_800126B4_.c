// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The carstate configuration block embedded in the game context at +0x3F8:
 * how many vehicles follow, then that many vehicle numbers. */
typedef struct {
    char pad[0x24];
    int vehicleCount;   /* 0x24 */
    int vehicleIds[1];  /* 0x28 */
} CarStateConfig;

/* fn_801EA4B4 is a tail-call thunk for fn_802797A8, which allocates and clears
 * the carstate ("cs_block") table in lbl_8055F618. */
extern void fn_801EA4B4(int *, int);

/* CarStateInit: build the carstate table from the counted vehicle array in
 * `config`.  The first argument (the game context) is unused. */
void fn_800126B4(void *context, CarStateConfig *config) {
    fn_801EA4B4(config->vehicleIds, config->vehicleCount);
}

/* fn_801EA4B8 is a tail-call thunk for fn_80279848, which frees the "cs_block"
 * held in lbl_8055F618 and clears the pointer. */
extern void fn_801EA4B8(void);

/* CarStateFree: release the current carstate allocation. */
void fn_800126C0(void) {
    fn_801EA4B8();
}


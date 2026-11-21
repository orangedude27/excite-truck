// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Tail-call thunks for the carstate routines in another unit. */
extern void fn_802797A8();  /* allocate/clear/seed the table */
extern void fn_80279848(void); /* free the table and clear its pointer */

/* Forward to the carstate table setup (fn_802797A8). */
void fn_801EA4B4(void) {
    fn_802797A8();
}

/* Forward to carstate teardown: fn_80279848 frees the table. */
void fn_801EA4B8(void) {
    fn_80279848();
}


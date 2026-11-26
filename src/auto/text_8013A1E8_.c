// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

void fn_8013A1E8(void) {

}

void fn_8013A1EC(void) {

}

void fn_8013A1F0(void) {

}

void fn_8013A1F4(void) {

}

s32 fn_8013A1F8(void) {
    // No-op stub among the adjacent empty functions; reports a zero/false result.
    return 0;
}

/* Per-AI-car hook run when a car's proximity record is re-armed after a restart
 * (fn_801349C4 passes the car index): the shipped game leaves it empty. */
void fn_8013A200(s32 carIndex) {

}

/* No-op hook notified with a proximity entry's value after its enabled/disabled
 * transition is applied (fn_80134A8C); the shipped game leaves it empty. */
void fn_8013A204(s32 value) {

}

/* Empty hook that Sound_start tail-calls right after it requests the sound/steering
 * reset (state 2 in lbl_8055E3C0); the shipped game leaves it doing nothing. */
void fn_8013A208(void) {

}


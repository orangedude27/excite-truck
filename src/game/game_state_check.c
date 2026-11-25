/* Recovered with m2c; verified against the original REXE01 instructions.
 * The returned object's concrete game type is not yet known.
 */
extern void* fn_801EA9CC(int index);

/* RaceNotGreen: true (1) while car 0's live state (CarMgrEntry+0x30) is 1, i.e. the race has not gone green yet; used by fn_800057D0 to hold the pre-race HUD overlay. */ /* RaceNotGreen: true (1) while car 0's live state (CarMgrEntry+0x30) is 1, i.e. the race has not gone green yet; used by fn_800057D0 to hold the pre-race HUD overlay. */ int fn_80005694(void) {
    /* Race-start check: true while the first car's live state at +0x30 is 1 (race not yet green). */
#define getCarMgrEntry fn_801EA9CC
    struct CarMgrEntry { char pad[0x30]; int state; } *firstCar;
    firstCar = (struct CarMgrEntry *)getCarMgrEntry(0);
    return (firstCar->state - 1) == 0;
#undef getCarMgrEntry
}

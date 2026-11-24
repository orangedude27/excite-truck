// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Race-event bootstrap reset: clear the four controller entries (fn_80279370),
 * then zero the event table (fn_80279CE4). The callback argument is unused. */
void fn_80279464(void* unused) {
    fn_80279CE4(fn_80279370(unused));
}

extern void* fn_80279D3C(void*);
extern void fn_802793AC(void*);
void fn_80279488(void* alarm) {
    /* Alarm callback: run the fn_80279D3C and fn_802793AC handlers (both currently no-ops). */
    fn_802793AC(fn_80279D3C(alarm));
}

extern void *fn_801E87A8(void);
extern void Abend_Panic(char *, ...);
extern char lbl_803477F0[]; // "CarTypeIsReal: Unrecognized CarType"
#pragma push
#pragma scheduling invalid_target
/* Return whether the given car type is considered "real"/valid (1) or not (0).
 * For type 0x53, checks bit 0 of the flag word at offset 0x10 in carInfo;
 * if carInfo is NULL, uses the default context from fn_801E87A8(). */
int fn_802794AC(int carType, void *carInfo) {
    switch (carType) {
    case 0x50:
    case 0x51:
    case 0x52:
        return 1;
    case 0x54:
        return 0;
    case 0x53:
        if (carInfo == 0) {
            carInfo = fn_801E87A8();
        }
        return *(unsigned int *)((char *)carInfo + 0x10) & 1;
    default:
        Abend_Panic(lbl_803477F0, carType);
        return 0;
    }
}
#pragma pop

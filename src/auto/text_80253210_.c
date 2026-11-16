// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_80253254(void);
extern int lbl_8055F2F0;
extern char lbl_80498D00[];
#pragma scheduling invalid_target
void fn_80253210(void) {
    /* Initialize the subsystem state and construct its fixed-size object array. */
    #define InitSubsystemState fn_8000D838
    #define ConstructArray     fn_8002F53C
    #define gSubsystemState    lbl_8055F2F0
    #define gObjectArray       lbl_80498D00
    #define ObjectCtor         fn_80253254

    InitSubsystemState(&gSubsystemState);
    ConstructArray(gObjectArray, ObjectCtor, 0, 0x78, 2);

    #undef InitSubsystemState
    #undef ConstructArray
    #undef gSubsystemState
    #undef gObjectArray
    #undef ObjectCtor
}
#pragma scheduling on

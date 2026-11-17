// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_80559C00;
extern void *lbl_8042F788[4];
extern int lbl_8042F798[4];
extern int fn_800167F4(void);
void fn_80137C84(int, int);
extern unsigned char lbl_8055E0E0;
extern void fn_80128668(void*);
extern int fn_802E317C(void*, ...);
extern char lbl_8032BEE4[];
extern char lbl_8032BEC0[];
extern char lbl_8032BECC[];
extern int lbl_80559C04;
extern int lbl_80559C08;
extern int lbl_80559C10;
char *fn_80137950(int arg0) {
    switch (arg0) {
    case 3:
        return (char *)&lbl_80559C04;
    case 1:
        return lbl_8032BEC0;
    case 2:
        return (char *)&lbl_80559C08;
    case 0:
        return (char *)&lbl_80559C10;
    default:
        fn_802E317C(lbl_8032BECC, arg0);
        return 0;
    }
}

#pragma push
#pragma scheduling invalid_target
/* Returns the data for the currently selected AI driver league, warning if none is set. */
int fn_801379CC(void) {
    if ((int)lbl_80559C00 == -1) {
        fn_802E317C(lbl_8032BEE4);
    }
    return (int)lbl_8042F788[(int)lbl_80559C00];
}
#pragma pop
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern int sprintf(char *, const char *, ...);
extern int stricmp(const char *, const char *);
extern char lbl_80559C18, lbl_80559C20, lbl_80559C28, lbl_80559C30;
#pragma inline_depth(0)
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80137A18(void) {
    /* Load "car_wid"/"car_len" for the current league's "Info" entry from "<name>.val". */
    struct ValList { virtual void v0(); virtual void *get(int); };
    struct ValItem {
        virtual const char *getName();
        virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6();
        virtual float getF(const char *);
    };
    char valPath[0x100];
    char *leagueData = (char *)fn_801379CC();
    void *valList;
    int index;
    void *item;
    const char *itemName;
    sprintf(valPath, (const char *)(void *)&lbl_80559C18, leagueData + 8);
    valList = fn_80131808(valPath);
    index = 0;
    for (;;) {
        item = ((ValList *)valList)->get(index++);
        if (item == 0)
            break;
        itemName = ((ValItem *)item)->getName();
        if (stricmp(itemName, (const char *)(void *)&lbl_80559C20) == 0) {
            *(float *)leagueData = ((ValItem *)item)->getF((const char *)(void *)&lbl_80559C28);
            *(float *)(leagueData + 4) = ((ValItem *)item)->getF((const char *)(void *)&lbl_80559C30);
        }
    }
    fn_80131818(valList);
}
#pragma cplusplus reset
#pragma scheduling on
/* Set the currently selected AI driver league index (0 Dirt, 1 Modified,
   2 Truck, 3 Cup; -1 for none). */
void fn_80137B0C(void* league) {
    lbl_80559C00 = league;
}

/* Clear the selected AI league: set the current-league index to -1 (none). */
#define s_currentLeague lbl_80559C00
void fn_80137B14(void) {
    /* -1 marks that no AI league is currently selected. */
    s_currentLeague = (void*)-1;
}
#undef s_currentLeague

__declspec(section ".sdata") extern char lbl_80559C38[];
extern void *fn_801284F8(int, const char *);
extern char *fn_80137950(int);
extern void fn_80137B0C(void *);
extern int fn_801379CC(void);
extern void fn_80137A18(void);
extern void fn_80137B14(void);
extern void *memset(void *, int, unsigned long);
extern char *strcpy(char *, const char *);
#pragma use_lmw_stmw off
/* Build the AI driver's four league entries: allocate one block per league
 * (Dirt, Modified, Truck, Cup) under the heap name "league", store the name
 * that fn_80137A18 opens as "<name>.val", and read that file's Info entry
 * (car_wid/car_len) into it.  Marks the table built (lbl_8055E0E0), leaves no
 * league selected and no context assigned to one; fn_80137BE4 frees it again. */
void fn_80137B20(void) {
    // One entry of the league table, as allocated here.
    typedef struct League {
        float carWidth;   // at 0x00  "car_wid" of the league's Info entry
        float carLength;  // at 0x04  "car_len" of the same entry
        char name[0x20];  // at 0x08  league name, also its "<name>.val" file
    } League;
    League **slot = (League **)lbl_8042F788;
    int league = 0;
    lbl_8055E0E0 = 1;
    lbl_80559C00 = (void *)-1;  // no league selected
    do {
        *slot = fn_801284F8(sizeof(League), lbl_80559C38);  // "league"
        memset(*slot, 0, sizeof(League));
        // fn_80137950: 0 Dirt, 1 Modified, 2 Truck, 3 Cup
        strcpy((char *)*slot + 8, fn_80137950(league));
        fn_80137B0C((void *)league);  // make it the current league
        fn_801379CC();                // warns "league not set" if none
        lbl_8042F798[0] = 4;          // 4 = no league for that context yet
        lbl_8042F798[1] = 4;
        lbl_8042F798[2] = 4;
        lbl_8042F798[3] = 4;
        fn_80137A18();  // read "<name>.val" into the current league
        fn_80137B14();  // and select no league again
        league++;
        slot++;
    } while (league < 4);
    fn_80137B0C((void *)0);  // Dirt is the league to start on
}
void fn_80137BE4(void) {
    // Free and clear a fixed table of four heap-allocated pointers, then mark it uninitialized.
    void **slot = lbl_8042F788;
    int index = 0;

    do {
        fn_80128668(*slot);
        index++;
        *slot = 0;
        slot++;
    } while (index < 4);

    lbl_8055E0E0 = 0;
}

/* Return the index of the currently selected AI driver league held in lbl_80559C00
 * (-1 means none is selected). */
void* fn_80137C4C(void) {
    return lbl_80559C00;
}

void* fn_80137C54(int league) {
    // Return the AI league data for 'league' (0 Dirt, 1 Modified, 2 Truck, 3 Cup)
    // from the table at lbl_8042F788; -1 substitutes the current one (lbl_80559C00).
    if (league == -1) {
        league = (int)lbl_80559C00;
    }
    return lbl_8042F788[league];
}

/* RealName: getBaseEntryCount. Forwards to fn_800167F4 (the base-table entry count, lbl_8055D554), whose return value passes through this tail call; callers use it as the player/record count. */
void fn_80137C74(void) {
    fn_800167F4();
}

/* RealName: setBaseEntryCount. Forwards to fn_800167FC, which writes the argument ('count', passed through in this tail call) into lbl_8055D554, the base-table entry/player count read by fn_80137C74 (getBaseEntryCount). */
void fn_80137C78(void) {
    fn_800167FC();
}

/* RealName: setupPlayerDriver. Forwards to fn_8001683C with the driver id and player-slot index (passed through in this tail call), which installs that driver's record into the given base-table slot. */
void fn_80137C7C(void) {
    fn_8001683C();
}

void fn_80137C80(int index) {
    fn_80016A44();
}

void fn_80137C84(int unused, int context) {
    /* Initialize one entry of the per-context league map to the identity: context 'context' maps to league 'context'. */
    lbl_8042F798[context] = context;
}

/* Searches the first fn_800167F4() entries of lbl_8042F798 for value and returns its index, or -1 if not found. */
int fn_80137C98(int value) {
    int count = fn_800167F4();
    int i;
    for (i = 0; i < count; i++) {
        if (value == lbl_8042F798[i])
            return i;
    }
    return -1;
}

int __AXGetStackHead_80137CFC(int slot) {
    /* Return the per-context league mapping stored at lbl_8042F798[slot]. */
    return lbl_8042F798[slot];
}

#pragma dont_inline fn_80137C84
void fn_80137D10(void) {
    /* Initialize the 4-entry table by setting each slot's mapping to its own index (via fn_80137C84). */
    int index = 0;
    do {
        fn_80137C84(index, index);
        index++;
    } while (index < 4);
}


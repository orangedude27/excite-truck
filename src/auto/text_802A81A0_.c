// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, unsigned long, unsigned long);
extern char lbl_8055F8B0;
extern int lbl_8055F8B8;
extern char lbl_804BD5D8[];
extern void fn_802A81EC(void);
#pragma scheduling invalid_target
/* Initializes the pool state at lbl_8055F8B0/lbl_8055F8B8 and constructs 8 entries
 * of 0x1C bytes in lbl_804BD5D8 using fn_802A81EC as the constructor. */
void fn_802A81A0(void) {
#define poolState lbl_8055F8B0
#define poolFlags lbl_8055F8B8
#define poolStorage lbl_804BD5D8
#define poolCtor fn_802A81EC

    fn_8000D838(&poolState);
    poolFlags = 0x7F000000;
    fn_8002F53C(poolStorage, poolCtor, 0, 0x1C, 8);

#undef poolState
#undef poolFlags
#undef poolStorage
#undef poolCtor
}
#pragma scheduling on

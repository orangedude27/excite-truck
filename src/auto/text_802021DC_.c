// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern unsigned char lbl_8055ECA0;
extern float lbl_804888A8[3];
extern float lbl_8056305C;
/* Register the tracked static node and clear the global direction vector to zero. */
void fn_802021DC(void) {
#define trackedNode     lbl_8055ECA0
#define globalDirection lbl_804888A8
#define zeroFloat       lbl_8056305C
#define RegisterNode    fn_8000D838

    RegisterNode(&trackedNode);
    globalDirection[0] = zeroFloat;
    globalDirection[1] = zeroFloat;
    globalDirection[2] = zeroFloat;

#undef trackedNode
#undef globalDirection
#undef zeroFloat
#undef RegisterNode
}

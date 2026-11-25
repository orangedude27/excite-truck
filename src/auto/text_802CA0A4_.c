// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055FC28;
extern float gGlobalDrawDirection[];
extern float lbl_80564F00;
extern float lbl_80564F1C;
// Registers a draw-list node and resets the global direction vector to (0, -1, 0).
void fn_802CA0A4(void) {
#define trackedNode     lbl_8055FC28
#define globalDirection gGlobalDrawDirection
#define zeroFloat       lbl_80564F00
#define minusOneFloat   lbl_80564F1C
#define RegisterNode    fn_8000D838

    RegisterNode(&trackedNode);
    globalDirection[0] = zeroFloat;
    globalDirection[1] = minusOneFloat;
    globalDirection[2] = zeroFloat;

#undef trackedNode
#undef globalDirection
#undef zeroFloat
#undef minusOneFloat
#undef RegisterNode
}

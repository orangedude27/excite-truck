// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern double fn_8002EF30(double);
extern unsigned char lbl_8055FCC8;
extern int lbl_8055FCD0;
extern float lbl_8055FCD4;
extern double lbl_80564F68;
/* Static initializer: register the tracked node, set a config color, and cache
 * the tangent of a fixed angle as a float. */
void fn_802CE308(void) {
#define trackedNode  lbl_8055FCC8
#define configColor  lbl_8055FCD0
#define tangentValue lbl_8055FCD4
#define tan          fn_8002EF30
#define angleRad     lbl_80564F68
#define RegisterNode fn_8000D838

    RegisterNode(&trackedNode);
    configColor = 0xFFFF0000;
    tangentValue = (float)tan(angleRad);

#undef trackedNode
#undef configColor
#undef tangentValue
#undef tan
#undef angleRad
#undef RegisterNode
}

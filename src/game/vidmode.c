// vidmode — video mode info (VidGetVideoModeInfo).
// Recovered TU window 0x802CE344..0x802CE39C+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CE39C (+ .ctors slot 0x802ED5B4) remains in
// auto/text_802CE39C_.c pending a promotion pass.
extern char lbl_8034BC00[];
extern char lbl_8034BCA8[];
extern void fn_802E317C(const char *, ...);
extern char lbl_8034BC00[];
extern char lbl_8034BCA8[];
extern void fn_802E317C(const char *, ...);
#pragma scheduling invalid_target
void *fn_802CE344(int arg0) {
    void *result;
    if (arg0 >= 0 && arg0 < 7) {
        result = lbl_8034BC00 + arg0 * 0x18;
    } else {
        fn_802E317C(lbl_8034BCA8, arg0);
        result = 0;
    }
    return result;
}
#pragma scheduling on

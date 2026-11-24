// vidmode — video mode info (VidGetVideoModeInfo).
// Recovered TU window 0x802CE344..0x802CE39C+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CE39C (+ .ctors slot 0x802ED5B4) remains in
// auto/text_802CE39C_.c pending a promotion pass.
extern char sVideoModeInfoTable[];
extern char sUnknownVideoModeFmt[];
extern void Abend_Panic(const char *, ...);
extern char sVideoModeInfoTable[];
extern char sUnknownVideoModeFmt[];
extern void Abend_Panic(const char *, ...);
#pragma scheduling invalid_target
void *Vid_GetVideoModeInfo(int arg0) {
    /* Return the video mode info entry (0x18 bytes each, 7 entries) for the given index, or log an error and return NULL if out of range. */
    void *result;

    if (arg0 >= 0 && arg0 < 7) {
        result = sVideoModeInfoTable + arg0 * 0x18;
    } else {
        Abend_Panic(sUnknownVideoModeFmt, arg0);
        result = 0;
    }
    return result;
}
#pragma scheduling on

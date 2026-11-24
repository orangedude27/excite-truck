// vidmode — video mode info (VidGetVideoModeInfo).
// Recovered TU window 0x802CE344..0x802CE39C+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CE39C (+ .ctors slot 0x802ED5B4) remains in
// auto/text_802CE39C_.c pending a promotion pass.
extern char sVideoModeInfoTable[];
extern char sUnknownVideoModeFmt[];
extern void Abend_Panic(const char *, ...);
#pragma scheduling invalid_target
/* Return the video-mode info entry for `mode` (7 entries, 0x18 bytes each in sVideoModeInfoTable), or panic with sUnknownVideoModeFmt and return NULL when out of range. */ void *Vid_GetVideoModeInfo(int mode) {
    void *result;

    if (mode >= 0 && mode < 7) {
        result = sVideoModeInfoTable + mode * 0x18;
    } else {
        Abend_Panic(sUnknownVideoModeFmt, mode);
        result = 0;
    }
    return result;
}
#pragma scheduling on

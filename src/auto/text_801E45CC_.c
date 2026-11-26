// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int lbl_8055AEC0;
extern float lbl_8055AEC4;
extern char lbl_8055AEDC, lbl_8055EA8C, lbl_8055EA8D, lbl_8055EA8E;
extern const char lbl_803399CC[];
extern float lbl_80562D30, lbl_80562D34, lbl_80562D38;
extern int fn_801769F8(void);
extern void fn_802E30C8(const char *, ...);
extern void fn_801EC1F8(void);
extern void fn_801EC204(void);
extern void fn_802E4CDC(void);

extern void fn_8023895C(void);
extern void fn_802389E4(void);
extern void fn_80238A74(int, int, const char *, int);
extern void fn_80238B44(int, int, int, int, int);
extern int fn_802CC744(void);
extern int fn_802CC74C(void);
extern char lbl_80339930[];
extern int lbl_804874F0[];
extern int lbl_8055AEC8, lbl_8055AED4, lbl_8055AECC, lbl_8055AED8;
__declspec(section ".sdata") extern char lbl_8055AEE0[], lbl_8055AEE8[];
extern int lbl_8055EA88;
extern unsigned char lbl_8055EA8F, lbl_8055EA90;
extern int sprintf(char *, const char *, ...);

/* The debug overlay's own statics; the two functions below draw and drive them.
 * These names stand in for the lbl_ addresses (the game's symbols can't be renamed). */
#define DBG_FORMAT_STR  lbl_80339930 /* the panel's format and status strings */
#define DBG_DMA_TEST    lbl_8055AEC0 /* 'A' while the DMA test is armed, 0 when off */
#define DBG_LOD_FACTOR  lbl_8055AEC4 /* the "LOD Factor:  %4.1f" the panel prints */
#define DBG_NEED_PAUSE  lbl_803399CC /* "physics must be paused to perform dma test." */
#define DBG_CAR_INDEX   lbl_8055AEC8 /* "Car:%2d:%s" device index */
#define DBG_CAR_NAME    lbl_8055AED4 /* "Car:%2d:%s" name pointer */
#define DBG_WHEEL_INDEX lbl_8055AECC /* "Wheel:%2d:%s" device index */
#define DBG_WHEEL_NAME  lbl_8055AED8 /* "Wheel:%2d:%s" name pointer */
#define DBG_WIRE_TEXT   lbl_8055AEE0 /* "WIRE", tinted by the wire flag */
#define DBG_CACHE_TEXT  lbl_8055AEE8 /* "CACHING" */
#define DBG_LOG_TEXT    lbl_8055EA88 /* the log line drawn beside the panel */
#define DBG_LOG_LINES   lbl_804874F0 /* log buffer; +0x80 holds its line count */
#define DBG_LOG_WINDOW  lbl_8055EA8F /* shows the log lines under the panel */
#define DBG_WIRE_FLAG   lbl_8055EA90 /* 'w': tints the WIRE label red when set */
#define DBG_FLAG_N      lbl_8055EA8C /* toggled by 'n' */
#define DBG_FLAG_C      lbl_8055AEDC /* toggled by 'c' */
#define DBG_FLAG_M      lbl_8055EA8E /* set by 'm' */
#define DBG_FLAG_E      lbl_8055EA8D /* toggled by 'E' */
#define LOD_STEP        lbl_80562D30 /* 0.2f: one press of '[' or ']', and the floor */
#define LOD_DEFAULT     lbl_80562D34 /* 1.0f: what ''' restores */
#define LOD_MAX         lbl_80562D38 /* 20.0: the ceiling */

#pragma scheduling invalid_target
/* Draws the debug/status overlay panel with device, recording, and log information. */
/* Draw the debug/status overlay panel: device, recording, and log info. */ void drawDebugPanel(void) {
    char textBuf[80];
    register char *textBase = DBG_FORMAT_STR;
    int y;
    int i;
    int statusColor;

    fn_8023895C();
    fn_80238B44(10, 10, 230, 84, 0x80000000);
    sprintf(textBuf, textBase + 0x4C, DBG_LOD_FACTOR);
    fn_80238A74(15, 15, textBuf, -1);
    fn_80238A74(15, 27, textBase + 0x60, -1);
    sprintf(textBuf, textBase + 0x74, DBG_CAR_INDEX, DBG_CAR_NAME);
    fn_80238A74(10, 39, textBuf, -1);
    sprintf(textBuf, textBase + 0x80, DBG_WHEEL_INDEX, DBG_WHEEL_NAME);
    fn_80238A74(10, 51, textBuf, -1);
    statusColor = DBG_WIRE_FLAG ? 0xFF2DC82D : 0xFF202020;
    fn_80238A74(10, 63, DBG_WIRE_TEXT, statusColor);
    if (fn_802CC744() == 0) {
        fn_80238A74(50, 63, textBase + 0x90, 0xFF2D2DC8);
    } else if (fn_802CC74C() == 0) {
        fn_80238A74(50, 63, DBG_CACHE_TEXT, 0xFF2DC82D);
    }
    if (DBG_LOG_TEXT) {
        fn_80238A74(150, 63, (const char *)DBG_LOG_TEXT, 0xFF2DC82D);
    }
    if (DBG_LOG_WINDOW) {
        y = 100;
        fn_80238B44(20, 100, 320, 112, 0x60000000);
        i = 0;
        while (i < *(int *)((char *)DBG_LOG_LINES + 0x80)) {
            fn_80238A74(20, y, (const char *)DBG_LOG_LINES, -1);
            y -= 12;
            i++;
        }
    }
    fn_802389E4();
}

/* Key handler of the debug overlay panel (drawDebugPanel): takes one typed key as
 * its ASCII code, adjusts the LOD factor or flips one of the debug flags, and
 * returns 0 when the key is not the panel's. */
int handleDebugPanelKey(int key) {
    double lod;
    int wasHandled = 1;
    int toggle;
    switch (key) {
    case 't': /* the DMA test, armed only while the physics are paused */
        if (fn_801769F8() != 0) {
            if (DBG_DMA_TEST == 'A') DBG_DMA_TEST = 0;
            else DBG_DMA_TEST = 'A';
        } else {
            fn_802E30C8(DBG_NEED_PAUSE);
        }
        break;
    case 'f': /* likewise needs the physics paused; it only complains otherwise */
        if (fn_801769F8() == 0) fn_802E30C8(DBG_NEED_PAUSE);
        break;
    case '[': DBG_LOD_FACTOR -= LOD_STEP; break;   /* finer LOD */
    case '\'': DBG_LOD_FACTOR = LOD_DEFAULT; break; /* back to 1.0 */
    case ']': DBG_LOD_FACTOR += LOD_STEP; break;   /* coarser LOD */
    case 'n': toggle = (unsigned char)DBG_FLAG_N; DBG_FLAG_N = toggle == 0; break;
    case 'c': toggle = (unsigned char)DBG_FLAG_C; DBG_FLAG_C = toggle == 0; break;
    case 'm': DBG_FLAG_M = 1; break;
    case 'l': toggle = DBG_LOG_WINDOW; *(char *)&DBG_LOG_WINDOW = toggle == 0; break; /* the log lines */
    case 'w': toggle = DBG_WIRE_FLAG; *(char *)&DBG_WIRE_FLAG = toggle == 0; break;   /* the "WIRE" line */
    case 'E': toggle = (unsigned char)DBG_FLAG_E; DBG_FLAG_E = toggle == 0; break;
    case 0xB: fn_801EC1F8(); fn_802E4CDC(); break; /* first cache table, then the vmem hook */
    case 0x4: fn_801EC204(); fn_802E4CDC(); break; /* the second one */
    case 0x9: break;                              /* tab: swallowed, nothing to do */
    default: wasHandled = 0; break;
    }
    /* the panel's factor stays inside [0.2, 20.0] however it was changed */
    lod = DBG_LOD_FACTOR;
    if (lod > LOD_MAX) {
        lod = LOD_MAX;
        DBG_LOD_FACTOR = LOD_MAX;
    }
    if ((float)lod < LOD_STEP) DBG_LOD_FACTOR = LOD_STEP;
    return wasHandled;
}

#pragma scheduling on

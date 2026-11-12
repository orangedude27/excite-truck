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
#pragma scheduling invalid_target
/* Draws the debug/status overlay panel with device, recording, and log information. */
void fn_801E45CC(void) {
    char textBuf[80];
    register char *textBase = lbl_80339930;
    int y;
    int i;
    int statusColor;

    fn_8023895C();
    fn_80238B44(10, 10, 230, 84, 0x80000000);
    sprintf(textBuf, textBase + 0x4C, lbl_8055AEC4);
    fn_80238A74(15, 15, textBuf, -1);
    fn_80238A74(15, 27, textBase + 0x60, -1);
    sprintf(textBuf, textBase + 0x74, lbl_8055AEC8, lbl_8055AED4);
    fn_80238A74(10, 39, textBuf, -1);
    sprintf(textBuf, textBase + 0x80, lbl_8055AECC, lbl_8055AED8);
    fn_80238A74(10, 51, textBuf, -1);
    statusColor = lbl_8055EA90 ? 0xFF2DC82D : 0xFF202020;
    fn_80238A74(10, 63, lbl_8055AEE0, statusColor);
    if (fn_802CC744() == 0) {
        fn_80238A74(50, 63, textBase + 0x90, 0xFF2D2DC8);
    } else if (fn_802CC74C() == 0) {
        fn_80238A74(50, 63, lbl_8055AEE8, 0xFF2DC82D);
    }
    if (lbl_8055EA88) {
        fn_80238A74(150, 63, (const char *)lbl_8055EA88, 0xFF2DC82D);
    }
    if (lbl_8055EA8F) {
        y = 100;
        fn_80238B44(20, 100, 320, 112, 0x60000000);
        i = 0;
        while (i < *(int *)((char *)lbl_804874F0 + 0x80)) {
            fn_80238A74(20, y, (const char *)lbl_804874F0, -1);
            y -= 12;
            i++;
        }
    }
    fn_802389E4();
}

/* The debug overlay's own statics; fn_801E45CC above draws them.  These names
 * stand in for the lbl_ addresses (the game's symbols can't be renamed yet). */
#define DBG_DMA_TEST   lbl_8055AEC0 /* 'A' while the DMA test is armed, 0 when off */
#define DBG_LOD_FACTOR lbl_8055AEC4 /* the "LOD Factor:  %4.1f" the panel prints */
#define DBG_NEED_PAUSE lbl_803399CC /* "physics must be paused to perform dma test." */
#define DBG_LOG_WINDOW lbl_8055EA8F /* shows the log lines under the panel */
#define LOD_STEP       lbl_80562D30 /* 0.2f: one press of '[' or ']', and the floor */
#define LOD_DEFAULT    lbl_80562D34 /* 1.0f: what ''' restores */
#define LOD_MAX        lbl_80562D38 /* 20.0: the ceiling */

/* Key handler of the debug overlay panel (fn_801E45CC): takes one typed key as
 * its ASCII code, adjusts the LOD factor or flips one of the debug flags, and
 * returns 0 when the key is not the panel's. */
int fn_801E47BC(int arg0) {
    double var_f1;
    int var_r31 = 1;
    int t;
    switch (arg0) {
    case 0x74:
        if (fn_801769F8() != 0) {
            if (lbl_8055AEC0 == 0x41) lbl_8055AEC0 = 0;
            else lbl_8055AEC0 = 0x41;
        } else {
            fn_802E30C8(lbl_803399CC);
        }
        break;
    case 0x66:
        if (fn_801769F8() == 0) fn_802E30C8(lbl_803399CC);
        break;
    case 0x5B: lbl_8055AEC4 -= lbl_80562D30; break;
    case 0x27: lbl_8055AEC4 = lbl_80562D34; break;
    case 0x5D: lbl_8055AEC4 += lbl_80562D30; break;
    case 0x6E: t = (unsigned char)lbl_8055EA8C; lbl_8055EA8C = t == 0; break;
    case 0x63: t = (unsigned char)lbl_8055AEDC; lbl_8055AEDC = t == 0; break;
    case 0x6D: lbl_8055EA8E = 1; break;
    case 0x6C: t = lbl_8055EA8F; *(char *)&lbl_8055EA8F = t == 0; break;
    case 0x77: t = lbl_8055EA90; *(char *)&lbl_8055EA90 = t == 0; break;
    case 0x45: t = (unsigned char)lbl_8055EA8D; lbl_8055EA8D = t == 0; break;
    case 0xB: fn_801EC1F8(); fn_802E4CDC(); break;
    case 0x4: fn_801EC204(); fn_802E4CDC(); break;
    case 0x9: break;
    default: var_r31 = 0; break;
    }
    var_f1 = lbl_8055AEC4;
    if (var_f1 > lbl_80562D38) {
        var_f1 = lbl_80562D38;
        lbl_8055AEC4 = lbl_80562D38;
    }
    if ((float)var_f1 < lbl_80562D30) lbl_8055AEC4 = lbl_80562D30;
    return var_r31;
}

#pragma scheduling on

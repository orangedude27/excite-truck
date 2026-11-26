#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"

extern char lbl_80342ED8[];
extern char lbl_80342E38[];
extern char lbl_802FA338[];
extern char lbl_80498878[];
extern char lbl_8055BE20, lbl_8055B860, lbl_8055BAB8;
extern void fn_80236914(void);
extern int loadFontTexture(void *);
extern int gxGetImageArt(void *);
extern int fn_80019088(void);
extern int fn_80019888(void);
extern int *fn_80019054(int);
extern int fn_802146BC(void *, int, int, int);
extern int sprintf(char *, const char *, ...);
extern void fn_802E30C8(const char *, ...);
typedef struct { int label, type, value, flags, id; } Ent2449;
typedef struct {
    int one;
    int hdr[5];
    Ent2449 e[6];
    char *p98;
    int pad9c[4];
    int spAC, spB0, spB4;
    char buf[0x80];
    int sp138, sp13C;
    int pad140[2];
    int sp148, sp14C;
} Frame2449;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Menu callback: resume the UI animation tail by clearing its suspend flag via
 * fn_80236900 (the argument is ignored); returns 1 to report it was handled. */
s32 fn_8024497C(void *unused) {
    fn_80236900(unused);
    return 1;
}

#pragma use_lmw_stmw off
void fn_802449A0(void) {
#pragma scheduling invalid_target
    Frame2449 f;
    int i;
    char *base = lbl_80342E38;
    f.p98 = lbl_80342ED8;
    f.spAC = 0;
    f.sp148 = loadFontTexture(base + 0xC);
    f.sp14C = gxGetImageArt(base + 0x18);
    f.spB0 = fn_80019088();
    f.spB4 = 0;
    sprintf(f.buf, base + 0x28, fn_80019888());
    f.sp13C = 0;
    f.sp138 = 0;
    fn_802E30C8(base + 0x48, f.spB0);
    for (i = 0; i < f.spB0; i++) {
        int *t = fn_80019054(i);
        fn_802E30C8(base + 0x68, i, t[0], t[1], t[2]);
    }
    {
        int *tbl = (int *)lbl_802FA338;
        int z = 0;
        f.one = 1;
        f.e[0].label = (int)(base + 0x80);
        f.e[0].type = 2;
        f.e[0].value = (int)&f.one;
        f.e[0].flags = z;
        f.e[0].id = z;
        f.e[1].label = (int)&lbl_8055BE20;
        f.e[1].type = 3;
        f.e[1].value = (int)f.buf;
        f.e[1].flags = 0x80;
        f.e[1].id = z;
        f.e[2].label = (int)(base + 0x90);
        f.e[2].type = 5;
        f.e[2].value = (int)&f.p98;
        f.e[2].flags = z;
        f.e[2].id = z;
        f.e[3].label = (int)&lbl_8055B860;
        f.e[3].type = 6;
        f.e[3].value = (int)fn_8024497C;
        f.e[3].flags = -1;
        f.e[3].id = 0x1B;
        f.e[4].label = (int)&lbl_8055BAB8;
        f.e[4].type = 8;
        f.e[4].value = (int)fn_80236914;
        f.e[4].flags = 2;
        f.e[4].id = z;
        f.e[5].label = ((int *)lbl_80498878)[0];
        f.e[5].type = ((int *)lbl_80498878)[1];
        f.e[5].value = ((int *)lbl_80498878)[2];
        f.e[5].flags = ((int *)lbl_80498878)[3];
        f.e[5].id = ((int *)lbl_80498878)[4];
        f.hdr[0] = tbl[0];
        f.hdr[1] = (int)f.e;
        f.hdr[2] = tbl[2];
        f.hdr[3] = tbl[3];
        f.hdr[4] = tbl[4];
        ((int (*)(void *, int, int, int, int, int, int, int))fn_802146BC)(f.hdr, -999, -999, 1, 2, (int)(base + 0x90), (int)f.e, tbl[4]);
    }
    f.p98 = lbl_80342ED8;
    fn_802328D4(f.sp148, lbl_80342ED8);
    f.sp148 = 0;
    fn_802C519C(f.sp14C);
    f.sp14C = 0;
}
/* Destructor-like cleanup: reset vtable/handlers, release owned subobjects at
 * +0xB0 and +0xB4, and free the object when freeFlag > 0. Returns the object. */
void *fn_80244BD0(void *obj, s32 freeFlag) {
    if (obj != 0) {
        *(void **)obj = lbl_80342ED8;
        fn_802328D4(*(s32 *)((char *)obj + 0xB0), lbl_80342ED8);
        *(s32 *)((char *)obj + 0xB0) = 0;
        fn_802C519C(*(s32 *)((char *)obj + 0xB4));
        *(s32 *)((char *)obj + 0xB4) = 0;
        if (freeFlag > 0) fn_80128668(obj);
    }
    return obj;
}

void fn_8013C804(void);
void fn_8013C8B8(void);
s32 KERNEL_GetTimeMs(void);
extern char lbl_80342ED8[];
/* Unlockable-list window thunk: load the car classes from "carclass.val" into
 * the class registry so car rows can resolve their display names. */
void fn_80244C50(void) { fn_8013C804(); }

/* Callback that tears down the car-class search manager used for car-name
 * lookups, delegating to fn_8013C8B8 (clear class cache, release the loaded
 * manager and null its global).  Pairs with fn_80244C50, which loads it. */
void fn_80244C54(void) { fn_8013C8B8(); }

/* Handle a seek/index command: record the current kernel timer tick into the state's
 * timestamp slot for command 0x126 (decrement index) or 0x128 (increment index),
 * then clamp the index at +0x1C to the range [0, *(s32*)(state+0x18) - 3].
 * Returns 1 if the command was handled, 0 otherwise. */
s32 fn_80244C58(void *state, s32 command)
{
#pragma scheduling invalid_target
    s32 *indexPtr = (s32 *)((char *)state + 0x1C);
    s32 indexValue;
    s32 upperBound;
    s32 clamped;

    switch (command) {
    case 0x126:
        *(s32 *)((char *)state + 0xA8) = KERNEL_GetTimeMs();
        *indexPtr = *indexPtr - 1;
        break;
    case 0x128:
        *(s32 *)((char *)state + 0xAC) = KERNEL_GetTimeMs();
        *indexPtr = *indexPtr + 1;
        break;
    default:
        return 0;
    }

    indexValue = *indexPtr;
    upperBound = *(s32 *)((char *)state + 0x18) - 3;
    clamped = indexValue & ((-indexValue & ~indexValue) >> 31);
    if (clamped < upperBound) {
        upperBound = clamped;
    }
    *indexPtr = upperBound;
    return 1;
}

/* Scroll auto-repeat.  fn_80244C58 stamps the time (+0xA8 for a scroll-up
 * message, +0xAC for scroll-down) it last received one; the two flags the
 * update below writes (+0xA0 up, +0xA4 down) stay set for SCROLL_REPEAT_MS
 * after it, which is what keeps the list scrolling while a direction is held. */
#define SCROLL_REPEAT_MS 250 /* ms one scroll step takes before it stops */
#pragma scheduling invalid_target
/* Window update (vtable slot 0x1C) of the unlockable list: refresh its two
 * scroll auto-repeat flags.  Each direction counts as still held while the
 * clock is within SCROLL_REPEAT_MS of the time fn_80244C58 stamped for its
 * last message (+0xA8 up, +0xAC down). */
void fn_80244D0C(void *window) {
    int now = KERNEL_GetTimeMs(); /* milliseconds since the clock started */
    int *repeat = (int *)((char *)window + 0xA0); /* [0]/[1]: up/down held, [2]/[3]: last pressed */
    int deadline;
    deadline = repeat[2] + SCROLL_REPEAT_MS;
    repeat[0] = now <= deadline;
    deadline = repeat[3] + SCROLL_REPEAT_MS;
    repeat[1] = now <= deadline;
}
#pragma scheduling reset
extern void fn_80230C30(float *, float *, int, int);
extern int gxGetImageWidth(int);
extern int fn_80232B70(int);
extern void fn_8013C8E8(int);
extern int fn_8013C9C8(void);
extern int stricmp(const char *, const char *);
extern char *strcpy(char *, const char *);
extern void fn_80232BA4(const char *, int, int, int, float, float, float, float, float);
extern void gxDrawPictureAt(int, int, float, float, float);
extern void fn_802337A0(int, int, int, const char *, ...);
extern char lbl_80342F98[];
extern char lbl_8055BE28, lbl_8055BE2C, lbl_8055BE34, lbl_8055BE3C, lbl_8055BE44;
extern float lbl_80563800, lbl_80563804, lbl_80563808, lbl_8056380C, lbl_80563810, lbl_80563814, lbl_80563818, lbl_8056381C, lbl_80563820, lbl_80563824;

/* ---------------------------------------------------------------------
 * The unlockable-list window.  fn_802449A0 opens it from the strings at
 * lbl_80342E38: the layout "unlock.lyt", the font "uifnt.gtx" (handle at
 * 0xB0) and the lock icon "chcklock.img" (handle at 0xB4), with the
 * player's Game Reputation Rating (fn_80019888) in its header.
 * fn_80244C58 scrolls the top row (0x1C) through the list and UnlockList_DrawRows
 * draws UNLOCK_ROWS of them: the unlockable's name on the left, a
 * description under it, the rating it costs and the lock icon, which
 * shows unlocked once the rating reaches the entry's requirement.
 *
 * A list entry is 0x14 bytes, fn_80019054 by index and fn_80019088 of
 * them:
 *   0x00 char *type;   "car" or "track"; anything else logs the error
 *   0x04 char *name;   the object's own name, drawn as the row's label
 *   0x08 int   rating; Game Reputation Rating needed to unlock it
 *   0x0C u8    flag;   shows the icon unlocked whatever the rating is
 *
 * The window's fields are read through these offsets; the game's symbols
 * cannot be named, so the accessors below are what the code uses.
 * ------------------------------------------------------------------- */
#define unl_screen_x(w)   (*(int *)((char *)(w) + 0x04)) /* window origin, screen pixels */
#define unl_screen_y(w)   (*(int *)((char *)(w) + 0x08))
#define unl_width(w)      (*(int *)((char *)(w) + 0x0C)) /* width of a row */
#define unl_count(w)      (*(int *)((char *)(w) + 0x18)) /* entries in the list */
#define unl_top(w)        (*(int *)((char *)(w) + 0x1C)) /* index of the top row */
#define unl_font(w)       (*(int *)((char *)(w) + 0xB0)) /* "uifnt.gtx" */
#define unl_icon_img(w)   (*(int *)((char *)(w) + 0xB4)) /* "chcklock.img" */

/* The two entry types the window can describe, and what it says. */
#define unl_type_car      lbl_8055BE28 /* "car" */
#define unl_desc_car      lbl_8055BE2C /* "%s Car", with the car's display name */
#define unl_type_track    lbl_8055BE34 /* "track" */
#define unl_desc_track    lbl_8055BE3C /* "Track" */
#define unl_fmt_rating    lbl_8055BE44 /* "%d Pts" */
#define unl_err_type      lbl_80342F98 /* "Unknown unlockable type %s for %s" */

/* Row layout in pixels.  The text sizes are divided by the font's own
 * height (byte 4 of the font object) to get the drawer's scale. */
#define UNLOCK_ROWS       3            /* rows drawn per frame */
#define unl_row_step      lbl_80563824 /* 33.0 from one row to the next */
#define unl_name_dy       lbl_80563810 /* 3.0: label above the row anchor */
#define unl_desc_dy       lbl_80563814 /* 4.0: description below it */
#define unl_icon_dy       lbl_80563818 /* 2.0: icon below it */
#define unl_name_size     lbl_80563808 /* 22.0 tall label */
#define unl_desc_size     lbl_8056380C /* 20.0 tall description and rating */
#define unl_desc_div      lbl_80563804 /* 2.8: description at x + width/2.8 */
#define unl_rating_inset  lbl_80563800 /* 15.0 left of the icon */
#define unl_angle         lbl_8056381C /* 0.0: nothing is rotated */
#define unl_unit          lbl_80563820 /* 1.0: the drawers' last transform */

#define unl_name_color    0xffdfdf20   /* colour of the label */
#define unl_color_auto    (-1)         /* the drawer's default colour */
#define unl_style_row     9            /* text style of label and description */
#define unl_style_rating  10           /* text style of the "%d Pts" */
#define unl_icon_locked   2            /* "chcklock.img" frame: still locked */
#define unl_icon_open     3            /* frame: unlocked */

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
#pragma scheduling invalid_target
/* Draws the visible rows of the unlockable list: for the UNLOCK_ROWS entries
 * from the top row down, the unlockable's name, its description, the Game
 * Reputation Rating it costs and the lock icon, unlocked once the player's
 * rating reaches the entry's.  Positions and sizes are the unl_* constants
 * above; the window's own fields are the unl_* accessors. */
/* Draws the visible rows of the unlockable list: each row's name, description, required Game Reputation Rating and lock icon (shown unlocked once the player's rating meets the entry's). */ void UnlockList_DrawRows(void *window) {
    char *win = (char *)window;
    float x, y;
    float xpos, mid, step, dy_icon, dy_desc, dy_name, width, xicon, xrating, name_scale, desc_scale, row;
    int rating, i;
    fn_80230C30(&x, &y, unl_screen_x(win), unl_screen_y(win)); /* origin, from the screen's centre */
    width = (float)unl_width(win);
    {
    float icon_width = (float)gxGetImageWidth(unl_icon_img(win));
    xpos = x;
    xicon = xpos + width - icon_width; /* icon flush with the row's right edge */
    }
    xrating = xicon - unl_rating_inset;
    mid = xpos + width / unl_desc_div;
    name_scale = unl_name_size / (float)fn_80232B70(unl_font(win));
    desc_scale = unl_desc_size / (float)fn_80232B70(unl_font(win));
    rating = fn_80019888(); /* the player's Game Reputation Rating */
    row = y;
    dy_name = unl_name_dy; dy_desc = unl_desc_dy; dy_icon = unl_icon_dy; step = unl_row_step;
    for (i=0; i<UNLOCK_ROWS; i++, row -= step) {
        int *entry;
        float y1, y2, y3;
        int icon;
        if (unl_top(win) + i >= unl_count(win)) break;
        entry = fn_80019054(unl_top(win) + i);
        {
        char desc[64] = {0};
        y2 = row - dy_desc;
        y1 = row - dy_name;
        y3 = dy_icon + row;
        if (stricmp((char *)entry[0], &unl_type_car) == 0) {
            /* the car's display name, through the object tables */
            fn_8013C8E8(entry[1]);
            sprintf(desc, &unl_desc_car, fn_8013C9C8());
        } else if (stricmp((char *)entry[0], &unl_type_track) == 0) {
            strcpy(desc, &unl_desc_track);
        } else {
            fn_802E30C8(unl_err_type, entry[0], entry[1]);
        }
        fn_80232BA4((char *)entry[1], unl_font(win), unl_name_color, unl_style_row, xpos, y1, name_scale, unl_angle, unl_unit);
        icon = unl_icon_locked;
        if (entry[2] <= rating || *((u8 *)entry + 0xc)) icon = unl_icon_open;
        gxDrawPictureAt(unl_icon_img(win), icon, xicon, y3, unl_angle);
        fn_802337A0(unl_font(win), unl_color_auto, unl_style_rating, &unl_fmt_rating, xrating, y2, unl_angle, desc_scale, unl_unit, entry[2]);
        fn_80232BA4(desc, unl_font(win), unl_color_auto, unl_style_row, mid, y2, desc_scale, unl_angle, unl_unit);
        }
    }
}
#pragma pop


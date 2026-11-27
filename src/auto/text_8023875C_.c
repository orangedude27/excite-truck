#include <stdarg.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8023875C(int, int, const char *, int, int);
extern int fn_80232B70(int); /* fontHeight: a font's height byte (u8 at font+4) */
extern int fn_802344B0(void);
extern int fn_802346C8(void);
extern int fn_802344C4(int);
extern int fn_802C8BD0(int);
extern int DrawList_RestoreNormalMode(void);
extern int fn_802C92DC(int, int, int, int, int);
extern int lbl_8055F0D4;   /* uiFont: UI font fn_8023889C loaded, 0 until then */
extern float lbl_805636F0; /* uiTextScale: 0.4f, the scale overlay text is drawn at */
extern float lbl_805636F4;
extern unsigned char lbl_8055F0D8;
__declspec(section ".sdata") extern unsigned int lbl_8055CFF0;
__declspec(section ".sdata") extern unsigned int lbl_8055CFF4;
extern int fn_802328D4(void);
extern int fn_80230B5C(void *);
extern int setCameraProjection(float, float, float);
extern int DrawList_loadMatrix(void *, unsigned int, float);
extern int fn_8012C33C(int);
extern int loadFontTexture(int);
extern unsigned char lbl_8055F0D9;
extern float lbl_8055FC88;
extern float lbl_805636F8;
extern float lbl_80563710;
extern float lbl_80563714;
extern double lbl_80563700;
extern int lbl_80563708;
extern int lbl_8056370C;
extern int fn_80232BA4(int, int, int, int, int, float, float, float, float, float);
extern int fn_802344CC(int, int, int, int, float, float, float);
#pragma scheduling invalid_target
/* Draw text centered at (x, y): queue via fn_802344CC for short strings when
   the text queue is ready, otherwise draw directly via fn_80232BA4. */
void fn_8023875C(int x, int y, const char *text, int arg3, int arg4)
{
  int halfWidth;
  int halfHeight;
  if (fn_802344B0() == 0)
  {
    goto long_text;
  }
  if (((unsigned int) (strlen(text) + 1)) >= 0x40U)
  {
    goto long_text;
  }
  halfWidth = ((int) lbl_8055CFF0) / 2;
  halfHeight = ((int) lbl_8055CFF4) / 2;
  fn_802344CC((int) text, arg3 & 0xFFFFFFFF, arg4, 0, (float) (x - halfWidth), (float) (halfHeight - y), lbl_805636F0);
  return;
  long_text:
  halfWidth = (int) (((unsigned int) lbl_8055CFF0 >> 31) + lbl_8055CFF0);
  halfWidth >>= 1;
  halfHeight = ((int) lbl_8055CFF4) / 2;
  fn_80232BA4((int) text, lbl_8055F0D4, arg3, arg4, halfWidth, (float) (x - halfWidth), (float) (halfHeight - y), lbl_805636F0, lbl_805636F4, lbl_805636F8);
}
/* Tries candidate UI font texture names in order and loads the first one that exists. */
void fn_8023889C(void) {
    int values[2];
    int *var_r31;
    unsigned int var_r30;
    var_r31 = values;
    var_r30 = 0U;
    lbl_8055F0D9 = 1;
    values[0] = lbl_80563708;
    values[1] = lbl_8056370C;
    do {
        if (fn_8012C33C(*var_r31) != 0) {
            lbl_8055F0D4 = loadFontTexture(values[var_r30]);
            return;
        }
        var_r30 += 1;
        var_r31++;
    } while (var_r30 < 2U);
}
#pragma scheduling on
/* Release the UI font loaded by fn_8023889C: clear the loaded flag, free the font's texture block if one was loaded, then clear the font handle. */
void fn_80238920(void) {
#define uiFont lbl_8055F0D4
#define uiFontLoaded lbl_8055F0D9
#define releaseFontTexture fn_802328D4
    int value = *(volatile int *)&uiFont;
    uiFontLoaded = 0;
    if (value != 0)
        releaseFontTexture();
    uiFont = 0;
#undef releaseFontTexture
#undef uiFontLoaded
#undef uiFont
}
#pragma scheduling dynamic
void fn_8023895C(void) {
    /* Open the overlay/debug text pass: set up the 2D view matrix and depth
     * range, mark the pass active and enable text queuing. The matching closer
     * is fn_802389E4. */
#define text_pass_active lbl_8055F0D8
#define text_queue_enable fn_802344C4
    float viewMatrix[12];

    setCameraProjection(1.0f, lbl_80563710, lbl_80563714);
    fn_80230B5C(&viewMatrix[0]);
    viewMatrix[11] = (float)(-((int)lbl_8055CFF0 / 2)) / lbl_8055FC88;
    ((void (*)(void *))DrawList_loadMatrix)(&viewMatrix[0]);
    text_pass_active = 1;
    text_queue_enable(1);
#undef text_pass_active
#undef text_queue_enable
}
/* Close the overlay/debug text pass: if any lines are still queued, render
 * (flush) them now, then clear the pass-active flag and disable queuing.
 * The matching opener is fn_8023895C. */
#define text_queue_has_lines fn_802344B0
#define text_queue_flush     fn_802346C8
#define text_pass_active     lbl_8055F0D8
#define text_queue_enable    fn_802344C4
void fn_802389E4(void) {
    if (text_queue_has_lines())
        text_queue_flush();
    text_pass_active = 0;
    text_queue_enable(0);
}
#undef text_queue_has_lines
#undef text_queue_flush
#undef text_pass_active
#undef text_queue_enable
#pragma scheduling on
/* TextLineHeight - how far down one line of overlay text steps.
 *
 * The overlay/debug text is always drawn at the same uiTextScale (0.4f), so a
 * line is that fraction of the UI font's height.  Callers add the result to a
 * y to draw the line under another (see the debug overlay's text blocks).
 * It comes out 0 while no UI font is loaded: fn_8023889C picks the font at
 * start-up and fn_80238920 hands it back.
 */
int fn_80238A20(void) {
    #define uiFont      lbl_8055F0D4 /* the UI font handle, 0 until loaded */
    #define uiTextScale lbl_805636F0 /* 0.4f */
    #define fontHeight  fn_80232B70  /* a font's height byte */

    return (int)(uiTextScale * (float)fontHeight(uiFont));

    #undef uiFont
    #undef uiTextScale
    #undef fontHeight
}

typedef int (*DrawCenteredTextFn)(int, int, int, int, int);
void fn_80238A74(int x, int y, int text, int color) {
    /* Draw text centered at (x, y) shifted up 3 pixels; fn_8023875C does the rendering. */
    ((DrawCenteredTextFn)fn_8023875C)(x, y - 3, text, color, 9);
}

void fn_80238A80(int arg0, int arg1, int arg2, const char *fmt, ...) {
    /* Format a printf-style string into a local buffer and pass it to fn_80238A74. */
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    ((void (*)(int, int, int, int))fn_80238A74)(arg0, arg1, (int)buffer, arg2);
}

#pragma use_lmw_stmw off
void fn_80238B44(int x0, int y0, int x1, int y1, int screen) {
    /* Draw a filled screen-space rectangle between (x0,y0) and (x1,y1): convert
     * top-left screen coordinates to the centered coordinates the quad drawer
     * expects, then flush the draw list. */
    int halfHeight;
    int halfWidth;
    fn_802C8BD0(-1);
    halfHeight = (int)lbl_8055CFF4 / 2;
    halfWidth = (int)lbl_8055CFF0 / 2;
    fn_802C92DC(x0 - halfWidth, halfHeight - y0, x1 - halfWidth, halfHeight - y1, screen);
    DrawList_RestoreNormalMode();
}
#pragma use_lmw_stmw on

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FE78;
extern int lbl_8055FE80;
int fn_802D8FB4(int);
int fn_80128658(int);
unsigned short OSGetFontEncode(void);
int OSInitFont(void);
int fn_801282EC(int);
int fn_801284E8(const void *, int);
int fn_802D8E9C(void *, void *);
void *OSGetFontTexture(void *, int *, int *, int *, int *);
int fn_802E30C8(const char *, ...);
void *memset(void *, int, unsigned int);
extern char lbl_8034C918[];
__declspec(section ".sdata") extern char lbl_8055D130[];
__declspec(section ".sdata") extern char lbl_8055D138[];
extern int lbl_8055FE78, lbl_8055FE7C, lbl_8055FE80;
/* lbl_8034C918: the debug font's name string followed by its log messages. */
typedef struct {
    char name[0xC];
    char sjisMessage[0x24];
    char romMessage[0x40];
} OSFontData;
#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802DACD4(void) {
 register const char (*message)[1]=(const char (*)[1])lbl_8034C918;
 volatile int b,c,d;
 int font;
 fn_801282EC(0x20);
 if ((unsigned short)OSGetFontEncode()==0) {
  font=0x20120;
 } else {
  font=0x120F00;
 }
 lbl_8055FE78=fn_801284E8((const void *)message[0],font);
 font=OSInitFont();
 if (OSGetFontEncode()==0x120F00) fn_802E30C8((const char *)(message+0xC));
 if (font==0) {
  fn_802E30C8((const char *)(message+0x30));
  fn_80128658(lbl_8055FE78);
  lbl_8055FE78=0;
  return;
 }
 b=0;
 *(volatile int *)&lbl_8055FE7C=0;
 c=0;
 d=0;
 OSGetFontTexture(lbl_8055D130,&lbl_8055FE7C,(int *)&c,(int *)&d,(int *)&b);
 {
  unsigned char config[0x34];
  unsigned char cfg2[0x20];
  memset(config,0,0x34);
  *(int *)(config+4)=1;
  *(int *)config=0x48;
  *(int *)(config+0x20)=1;
  *(int *)(config+0x24)=0x200;
  *(int *)(config+0x28)=0x200;
  memset(cfg2,0,0x20);
  *(int *)cfg2=0;
  *(int *)(cfg2+4)=lbl_8055FE7C;
  *(void **)(config+0x2c)=cfg2;
  lbl_8055FE80=fn_802D8E9C(config,lbl_8055D138);
 }
}
#pragma pop
#pragma scheduling on

/* Free debug font/text resources initialized by fn_802DACD4, if present. */
void fn_802DAE18(void) {
    if (lbl_8055FE78 != 0) {
        fn_802D8FB4(lbl_8055FE80);
        lbl_8055FE80 = 0;
        fn_80128658(lbl_8055FE78);
        lbl_8055FE78 = 0;
    }
}

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma use_lmw_stmw off
void OSGetFontWidth(char *, int *);
void gxPoint(int, int, unsigned int);

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma use_lmw_stmw off
/* Draw a string on the canvas the gx point plotter (gxPoint) is set to,
   using the font OSInitFont loaded: OSGetFontTexture hands out each character's
   texels in the font sheet - a 512 texel wide I4 image, one nibble per texel -
   and every non-empty texel is plotted as a gray pixel, the darker ones the
   denser the glyph.  The line wraps to the left margin when the word ahead no
   longer fits on the screen.  A negative x is the column to start at, taken as
   its absolute value; any other x starts at the left margin instead. */
void fn_802DAE64(int xStart, int yStart, char *str)
{
  int texX;        /* where the glyph starts in the sheet, across */
  int texY;        /* ... and down */
  int charWidth;   /* how far this character advances the pen */
  void *texels;    /* the glyph's texels in the font sheet */
  int width;       /* width OSGetFontWidth reports for one character */
  register int zeroWidth;   /* width a word's measurement starts from */
  register int yDst;
  register char *p;
  register unsigned char *sheet;
  register int row;
  register int col;
  register int y;
  register int x;
  int wordWidth;
  char *q;
  int tx;
  int ty;
  int tyPart;
  int txPart;
  int texelIndex;
  unsigned char byte;
  unsigned char nibble;
  unsigned int gray;
  texX = 0;
  y = yStart;
  texY = 0;
  charWidth = 0;
  texels = 0;
  if (xStart >= 0)
  {
    x = 0x46;      /* left margin of the text area */
  }
  else
  {
    x = (xStart < 0) ? (-xStart) : (xStart);
  }
  zeroWidth = 0;
  p = str;
  while ((*p) != 0)
  {
    /* At a space, measure the word that follows it; wrap if it runs off. */
    if ((*p) == 0x20)
    {
      wordWidth = x;
      q = p + 1;
      while (((*q) != 0) && ((*q) != 0x20))
      {
        width = zeroWidth;
        OSGetFontWidth(q, &width);
        q++;
        wordWidth += width;
      }

      if (wordWidth > 0x23A)   /* right edge of the text area */
      {
        x = 0x46;
        y += 0x20;             /* one line down */
        goto next_char;
      }
    }
    OSGetFontTexture(p, (int *) (&texels), &texX, &texY, &charWidth);
    sheet = texels;
    row = 0;
    do
    {
      yDst = row + y;
      col = 0;
      while (col < charWidth)
      {
        ty = row + texY;
        tx = col + texX;
        /* the texel in the sheet's I4 blocks, which are 8x8 texels over a
           sheet 512 texels wide: 64 texels (32 bytes) to the block */
        tyPart = (ty % 8) * 8;
        txPart = tx % 8;
        texelIndex = ((((tx / 8) + (((ty / 8) << 9) / 8)) << 6) + txPart) + tyPart;
        byte = sheet[texelIndex / 2];
        nibble = 0xF;
        nibble = byte & nibble;
        if (!(col & 1))
        {
          nibble = (byte >> 4) & 0xF;   /* the texel in the byte's high half */
        }
        if (nibble != 0)
        {
          /* a gray that grows with the texel's density, with the 16-bit value
             the plotter uses in both of its halves */
          gray = ((((nibble * 12) + 16) << 8) & 0xFFFF00) | 0x80;
          gxPoint(col + x, yDst, (gray << 16) | (gray & 0xFFFF));
        }
        col++;
      }

      row++;
    }
    while (row < 0x18);        /* the font's cell is 24 texels high */
    x += charWidth;
    next_char:
    p++;

  }

}
#pragma pop

extern void *GX_GetXFB(int *, int *);
extern void gxCanvasSwitch(void *, int, int, int);
extern void GX_ShowXFB(void);
extern char *strcpy(char *, const char *);
void fn_802DB03C(char *arg0) {
    struct {
        int outputB;
        int outputA;
        struct {
            unsigned char kind;
            unsigned char format;
            unsigned char pad2[2];
            void *buffer;
            int width;
            int height;
            int size;
            int pad14[2];
            int width2;
            int height2;
        } config;
        int padding;
        char text[0x400];
    } local;
    unsigned char *pixels;
    unsigned char *cursor;
    int row;
    int column;
    register char *p;
    char ch;
    volatile unsigned char *header;

    local.outputA = 0;
    local.outputB = 0;
    pixels = (unsigned char *)GX_GetXFB(&local.outputA, &local.outputB);
    row = (cursor = pixels, 0);
    for (; row < local.outputB; row++) {
        for (column = 0; column < local.outputA; column++) {
            *cursor++ = 0x10;
            *cursor++ = 0x80;
        }
    }

    memset(&local.config, 0, 0x24);
    header = (volatile unsigned char *)&local.config;
    header[0] = 4;
    header[1] = 0x80;
    local.config.buffer = pixels;
    local.config.width = local.outputA;
    local.config.height = local.outputB;
    local.config.size = local.outputA * 2;
    local.config.width2 = local.outputA;
    local.config.height2 = local.outputB;
    gxCanvasSwitch(&local.config, 0x80, local.outputA, local.outputB);

    strcpy(local.text, arg0);
    p = local.text;
    while ((ch = *p) != 0) {
        if (ch == '\n') {
            *p = 0x20;
        }
        p++;
    }
    fn_802DAE64(0x140, 0x78, local.text);
    GX_ShowXFB();
}

__declspec(section ".sdata") extern char lbl_8055D140[];
extern void fn_802CED50(int, int, int, int);
typedef struct {
    unsigned char kind;
    unsigned char format;
    unsigned char pad[2];
    void *buffer;
    int width;
    int height;
    int size;
    int pad2[2];
    int width2;
    int height2;
} CanvasConfig;
void fn_802DB168(void) {
    /* LOADING screen: clear the external framebuffer to a gray background, install a canvas over it, draw the centered "LOADING" label, then present the frame. */
    #pragma scheduling invalid_target
    CanvasConfig canvas;
    int fbWidth = 0, fbHeight = 0;
    unsigned char *framebuffer = GX_GetXFB(&fbWidth, &fbHeight);
    unsigned char *cursor = framebuffer;
    int row;
    for (row = 0; row < fbHeight; row++) {
        int col;
        for (col = 0; col < fbWidth; col++) {
            cursor[0] = 0x10;
            cursor[1] = 0x80;
            cursor += 2;
        }
    }
    memset(&canvas, 0, 0x24);
    canvas.kind = 4;
    canvas.format = 0x80;
    canvas.buffer = framebuffer;
    canvas.width = fbWidth;
    canvas.height = fbHeight;
    canvas.size = fbWidth * 2;
    canvas.width2 = fbWidth;
    canvas.height2 = fbHeight;
    ((void (*)(void *))gxCanvasSwitch)(&canvas);
    fn_802DAE64(-0x1C2, 0x17C, lbl_8055D140);
    GX_ShowXFB();
    fn_802CED50(0x1C2, 0x17C, 0x78, 0x1E);
}

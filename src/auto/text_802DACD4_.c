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
 register const char *message=lbl_8034C918;
 volatile int b,c,d;
 int font;
 fn_801282EC(0x20);
 if ((unsigned short)OSGetFontEncode()==0) {
  font=0x20120;
 } else {
  font=0x120F00;
 }
 lbl_8055FE78=fn_801284E8(message,font);
 font=OSInitFont();
 if (OSGetFontEncode()==0x120F00) fn_802E30C8(message+0xC);
 if (font==0) {
  fn_802E30C8(message+0x30);
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
void fn_802C32B8(int, int, unsigned int);

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma use_lmw_stmw off
void fn_802DAE64(int arg0, int arg1, char *arg2)
{
  int sp18;
  int sp14;
  int sp10;
  void *spC;
  int sp8;
  register int zero;
  register int ydst;
  register char *p;
  register unsigned char *base;
  register int row;
  register int col;
  register int y;
  register int x;
  int w;
  char *q;
  int tx;
  int ty;
  int typart;
  int txpart;
  int idx;
  unsigned char b;
  unsigned char nib;
  unsigned int color;
  sp18 = 0;
  y = arg1;
  sp14 = 0;
  sp10 = 0;
  spC = 0;
  if (arg0 >= 0)
  {
    x = 0x46;
  }
  else
  {
    x = (arg0 < 0) ? (-arg0) : (arg0);
  }
  zero = 0;
  p = arg2;
  while ((*p) != 0)
  {
    if ((*p) == 0x20)
    {
      w = x;
      q = p + 1;
      while (((*q) != 0) && ((*q) != 0x20))
      {
        sp8 = zero;
        OSGetFontWidth(q, &sp8);
        q++;
        w += sp8;
      }

      if (w > 0x23A)
      {
        x = 0x46;
        y += 0x20;
        goto next_char;
      }
    }
    OSGetFontTexture(p, (int *) (&spC), &sp18, &sp14, &sp10);
    base = spC;
    row = 0;
    do
    {
      ydst = row + y;
      col = 0;
      while (col < sp10)
      {
        ty = row + sp14;
        tx = col + sp18;
        typart = (ty % 8) * 8;
        txpart = tx % 8;
        idx = ((((tx / 8) + (((ty / 8) << 9) / 8)) << 6) + txpart) + typart;
        b = base[idx / 2];
        nib = 0xF;
        nib = b & nib;
        if (!(col & 1))
        {
          nib = (b >> 4) & 0xF;
        }
        if (nib != 0)
        {
          color = ((((nib * 12) + 16) << 8) & 0xFFFF00) | 0x80;
          fn_802C32B8(col + x, ydst, (color << 16) | (color & 0xFFFF));
        }
        col++;
      }

      row++;
    }
    while (row < 0x18);
    x += sp10;
    next_char:
    p++;

  }

}
#pragma pop

extern void *fn_802D2F78(int *, int *);
extern void fn_802C3034(void *, int, int, int);
extern void fn_802D2FD8(void);
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
    pixels = (unsigned char *)fn_802D2F78(&local.outputA, &local.outputB);
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
    fn_802C3034(&local.config, 0x80, local.outputA, local.outputB);

    strcpy(local.text, arg0);
    p = local.text;
    while ((ch = *p) != 0) {
        if (ch == '\n') {
            *p = 0x20;
        }
        p++;
    }
    fn_802DAE64(0x140, 0x78, local.text);
    fn_802D2FD8();
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
    unsigned char *framebuffer = fn_802D2F78(&fbWidth, &fbHeight);
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
    ((void (*)(void *))fn_802C3034)(&canvas);
    fn_802DAE64(-0x1C2, 0x17C, lbl_8055D140);
    fn_802D2FD8();
    fn_802CED50(0x1C2, 0x17C, 0x78, 0x1E);
}

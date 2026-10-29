// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FE78;
extern int lbl_8055FE80;
int fn_802D8FB4(int);
int fn_80128658(int);
unsigned short OSGetFontEncode(void);
int OSInitFont(void);
int fn_801282EC(int);
int fn_801284E8(void *, int);
int fn_802D8E9C(void *, void *);
void *OSGetFontTexture(void *, int *, int *, int *, int *);
int fn_802E30C8(const char *, ...);
void *memset(void *, int, unsigned int);
extern char lbl_8034C918[];
__declspec(section ".sdata") extern char lbl_8055D130[];
__declspec(section ".sdata") extern char lbl_8055D138[];
extern int lbl_8055FE78, lbl_8055FE7C, lbl_8055FE80;
#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802DACD4(void) {
 struct StringStart { volatile char first; };
 register const char *message=lbl_8034C918;
 volatile int b,c,d;
 int font;
 fn_801282EC(0x20);
 if ((unsigned short)OSGetFontEncode()==0) {
  font=0x20120;
 } else {
  font=0x120F00;
 }
 lbl_8055FE78=fn_801284E8((void *)&((volatile struct StringStart *)message)->first,font);
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

void fn_802DAE18(void) {
    if (lbl_8055FE78 != 0) {
        fn_802D8FB4(lbl_8055FE80);
        lbl_8055FE80 = 0;
        fn_80128658(lbl_8055FE78);
        lbl_8055FE78 = 0;
    }
}

#pragma scheduling invalid_target
void OSGetFontWidth(char *, int *);
void fn_802C32B8(int, int, unsigned int);

int fn_802DAE64(int arg0, int arg1, char *arg2) {
    int sp18;
    int sp14;
    int sp10;
    void *spC;
    int sp8;
    register int startX;
    register int baseY;
    register int value;
    register char *cursor;
    register char *text;
    register void *bitmap;
    register int screenY;
    register int zero;
    int color;
    int address;
    int pixel;
    int ch;

    zero = 0;
    sp18 = zero;
    baseY = arg1;
    sp14 = zero;
    sp10 = zero;
    spC = 0;
    if (arg0 < 0) {
        startX = (zero ^ arg0) - (arg0 >> 31);
    } else {
        startX = 0x46;
    }
    text = arg2;
    zero = 0;

text_loop:
    ch = (signed char)*text;
    if (ch == 0) return 0;
    if (ch == 0x20) {
        value = startX;
        cursor = text + 1;
word_loop:
        sp8 = 0;
        OSGetFontWidth(cursor, &sp8);
        cursor++;
        value += sp8;
        ch = (signed char)*cursor;
        if (ch != 0 && ch != 0x20) goto word_loop;
        if (value > 0x23A) {
            startX = 0x46;
            baseY += 0x20;
            goto advance;
        }
    }

    OSGetFontTexture(text, (int *)&spC, &sp18, &sp14, &sp10);
    bitmap = spC;
    screenY = baseY;
    for (value = 0; value < 0x18; value++) {
        screenY = value + baseY;
        for (pixel = 0; pixel < sp10; pixel++) {
            int px = pixel + sp18;
            int py = value + sp14;
            address = ((px / 8 + ((py / 8) << 9) / 8) << 6) + ((px % 8) * 8) + (py % 8);
            address = (address + ((unsigned int)address >> 31)) >> 1;
            ch = ((unsigned char *)bitmap)[address];
            if (pixel & 1) {
                color = ch & 0xF;
            } else {
                color = (ch >> 4) & 0xF;
            }
            if (color != 0) {
                unsigned int c = ((color * 0xC + 0x10) << 8 & 0xFFFF00) | 0x80;
                unsigned int packed = (c & ~0xFF800000) | ((c << 0x10) & 0xFF800000);
                fn_802C32B8(pixel + startX, screenY, packed);
            }
        }
    }
advance:
    startX += sp10;
    text++;
    goto text_loop;
}

extern void *fn_802D2F78(int *, int *);
extern void fn_802C3034(void *, int, int, int);
extern void fn_802D2FD8(void);
extern int fn_802DAE64(int, int, char *);
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
    register unsigned char *cursor;
    int row;
    int column;
    register char *p;
    char ch;
    volatile unsigned char *header;

    local.outputA = 0;
    local.outputB = 0;
    pixels = (unsigned char *)fn_802D2F78(&local.outputA, &local.outputB);
    cursor = pixels;
    row = 0;
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

typedef struct {
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
} DB168Config;

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

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void OSGetFontWidth(char *, int *);
void fn_802C32B8(int, int, unsigned int);

int fn_802DAE64(int arg0, int arg1, char *arg2) {
    int sp18;
    int sp14;
    int sp10;
    void *spC;
    int sp8;
    register int zero;
    register int screenY;
    register char *text;
    register void *bitmap;
    register int cursor;
    register int value;
    register int baseY;
    register int startX;
    int ch;
    int pixel;
    int address;
    int color;
    int x;
    int y;
    int temp;
    unsigned int colorData;
    unsigned int packed;

    zero = 0;
    sp18 = zero;
    baseY = arg1;
    sp14 = zero;
    sp10 = zero;
    spC = 0;
    if (arg0 < 0) {
        temp = arg0 >> 31;
        startX = (temp ^ arg0) - temp;
    } else {
        startX = 0x46;
    }
    text = arg2;
    zero = 0;
    goto advance;

text_loop:
    if (ch == 0x20) {
        value = startX;
        cursor = (int)(text + 1);
measure:
        sp8 = zero;
        OSGetFontWidth((char *)cursor, &sp8);
        cursor++;
        value += sp8;
        ch = (signed char)*(char *)cursor;
        if (ch != 0) {
            if (ch != 0x20) goto measure;
        }
        if (value > 0x23A) {
            startX = 0x46;
            baseY += 0x20;
            goto advance;
        }
    }

    OSGetFontTexture(text, (int *)&spC, &sp18, &sp14, &sp10);
    bitmap = spC;
    cursor = 0;
    screenY = cursor + baseY;
    value = 0;
    for (;;) {
        if (value < sp10) {
            x = value + sp18;
            y = cursor + sp14;
            address = ((x / 8 + ((y / 8) << 9) / 8) << 6) + ((x % 8) * 8) + (y % 8);
            address = (address + ((unsigned int)address >> 31)) >> 1;
            pixel = ((unsigned char *)bitmap)[address];
            if (value & 1) {
                color = pixel & 0xF;
            } else {
                color = (pixel >> 4) & 0xF;
            }
            if (color != 0) {
                colorData = ((color * 0xC + 0x10) << 8 & 0xFFFF00) | 0x80;
                packed = (colorData & ~0xFF800000) | ((colorData << 0x10) & 0xFF800000);
                fn_802C32B8(value + startX, screenY, packed);
            }
            value++;
            goto pixel_test;
        }
        cursor++;
        if (cursor < 0x18) {
            screenY = cursor + baseY;
            value = 0;
            goto pixel_test;
        }
        goto advance;
pixel_test:
        if (value < sp10) goto pixel_loop;
        continue;
pixel_loop:
        ;
    }
advance:
    startX += sp10;
    text++;
    ch = (signed char)*text;
    if (ch != 0) goto text_loop;
}
#pragma pop
#pragma scheduling on

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

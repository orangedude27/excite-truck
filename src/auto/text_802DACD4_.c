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
extern char lbl_8055D138[];
extern int lbl_8055FE78, lbl_8055FE7C, lbl_8055FE80;
void fn_802DACD4(void) {
 int a,b,c,d; int font;
 fn_801282EC(0x20);
 font=0x120F00;
 if(OSGetFontEncode()==0) font=0x20120;
 lbl_8055FE78=fn_801284E8(lbl_8034C918,font);
 font=OSInitFont();
 if(OSGetFontEncode()==0x12F00) fn_802E30C8(lbl_8034C918+0xC);
 if(font==0) {
  fn_802E30C8(lbl_8034C918+0x30);
  fn_80128658(lbl_8055FE78);
  lbl_8055FE78=0;
  return;
 }
 d=0; lbl_8055FE7C=0; b=0; c=0;
 OSGetFontTexture(lbl_8055D130,&lbl_8055FE7C,&b,&c,&d);
 {
  unsigned char config[0x34]; unsigned char cfg2[0x20];
  memset(config,0,0x34); *(int *)(config+4)=1; *(int *)config=0x48;
  *(int *)(config+0x20)=1; *(int *)(config+0x24)=0x200; *(int *)(config+0x28)=0x200;
  memset(cfg2,0,0x20); *(int *)(cfg2+4)=lbl_8055FE7C;
  *(void **)(config+0x2c)=cfg2;
  lbl_8055FE80=fn_802D8E9C(config,lbl_8055D138);
 }
}

void fn_802DAE18(void) {
    if (lbl_8055FE78 != 0) {
        fn_802D8FB4(lbl_8055FE80);
        lbl_8055FE80 = 0;
        fn_80128658(lbl_8055FE78);
        lbl_8055FE78 = 0;
    }
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

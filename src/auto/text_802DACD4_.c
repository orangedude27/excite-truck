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
#pragma use_lmw_stmw off
void OSGetFontWidth(char *, int *);
void fn_802C32B8(int, int, unsigned int);

int fn_802DAE64(int arg0, int arg1, char *arg2) {
    int sp18;
    int sp14;
    int sp10;
    int spC;
    int sp8;
    int temp_r4;
    int temp_r4_2;
    int temp_r6;
    int var_r24;
    int var_r25;
    int var_r26;
    int var_r26_2;
    int var_r27_2;
    unsigned short temp_r0_2;
    unsigned int temp_r3_2;
    unsigned int temp_r3_3;
    unsigned int temp_r3_4;
    unsigned int temp_r4_3;
    unsigned int temp_r4_4;
    char *var_r27;
    char *var_r29;
    unsigned char temp_r0;
    unsigned char temp_r3;
    unsigned char temp_r3_5;
    unsigned char var_r0;

    sp18 = 0;
    var_r25 = arg1;
    sp14 = 0;
    sp10 = 0;
    spC = 0;
    if (arg0 >= 0) {
        var_r24 = 0x46;
    } else {
        temp_r4 = arg0 >> 0x1F;
        var_r24 = (temp_r4 ^ arg0) - temp_r4;
    }
    var_r29 = arg2;
loop_22:
    temp_r3 = *var_r29;
    if ((signed char)temp_r3 != 0) {
        if ((signed char)temp_r3 == 0x20) {
            var_r26 = var_r24;
            var_r27 = var_r29 + 1;
loop_7:
            temp_r0 = *var_r27;
            if (((signed char)temp_r0 != 0) && ((signed char)temp_r0 != 0x20)) {
                sp8 = 0;
                OSGetFontWidth(var_r27, &sp8);
                var_r27 += 1;
                var_r26 += sp8;
                goto loop_7;
            }
            if (var_r26 > 0x23A) {
                var_r24 = 0x46;
                var_r25 += 0x20;
            } else {
                goto block_11;
            }
        } else {
block_11:
            OSGetFontTexture(var_r29, (int *)&spC, &sp18, &sp14, &sp10);
            var_r27_2 = 0;
            do {
                var_r26_2 = 0;
loop_18:
                if (var_r26_2 < sp10) {
                    temp_r6 = var_r26_2 + sp18;
                    temp_r4_2 = var_r27_2 + sp14;
                    temp_r4_3 = (unsigned int)temp_r4_2 >> 0x1F;
                    temp_r3_2 = (temp_r4_2 << 0x1D) - temp_r4_3;
                    temp_r4_4 = (unsigned int)temp_r6 >> 0x1F;
                    temp_r3_3 = (temp_r6 << 0x1D) - temp_r4_4;
                    temp_r3_4 = (((temp_r6 / 8) + ((int)((temp_r4_2 / 8) << 9) / 8)) << 6)
                        + (((((temp_r3_2 << 3) | (temp_r3_2 >> 0x1D)) + temp_r4_3) * 8)
                        + (((temp_r3_3 << 3) | (temp_r3_3 >> 0x1D)) + temp_r4_4));
                    temp_r3_5 = *((unsigned char *)spC + (int)(((temp_r3_4 >> 0x1F) + temp_r3_4) >> 1));
                    var_r0 = temp_r3_5 & 0xF;
                    if (!(var_r26_2 & 1)) {
                        var_r0 = (temp_r3_5 >> 4) & 0xF;
                    }
                    if (var_r0 != 0) {
                        temp_r0_2 = ((((var_r0 * 0xC) + 0x10) << 8) & 0xFFFF00) | 0x80;
                        fn_802C32B8(var_r26_2 + var_r24, var_r27_2 + var_r25,
                            (temp_r0_2 & ~0xFF800000) | ((temp_r0_2 << 0x10) & 0xFF800000));
                    }
                    var_r26_2 += 1;
                    goto loop_18;
                }
                var_r27_2 += 1;
            } while (var_r27_2 < 0x18);
            var_r24 += sp10;
        }
        var_r29 += 1;
        goto loop_22;
    }
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

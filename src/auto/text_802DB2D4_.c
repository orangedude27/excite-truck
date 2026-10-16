// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FEA8;
extern void *lbl_8055FEAC;
void fn_802DBDD8(void) {
    lbl_8055FEA8 = 0;
    lbl_8055FEAC = 0;
}

typedef unsigned char u8;
extern void fn_802DBDD8(void);
extern void fn_802DEE1C(void);
extern void fn_802DBD88(void);
extern void fn_802D3360(void);
extern void GXSetTevKAlphaSel(int, int);
extern void fn_802D0610(int);
extern void fn_802D68C4(int, int, int, int);
extern void GXSetZMode(int, int, int);
extern void GXSetNumChans(int);
extern void GXSetChanCtrl(int, int, int, int, int, int, int);
extern u8 lbl_8055FEBA;
extern u8 lbl_8055FEB8;
void fn_802DBF30(void) {
    fn_802DBDD8();
    fn_802DEE1C();
}

void fn_802DC278(void) { fn_802DBD88(); }

void fn_802DC27C(void) { fn_802DBDD8(); }

extern void fn_802DFCC0(void);
extern int GXGetTexObjMipMap(void *);
extern unsigned short GXGetTexObjWrapS(void *);
extern int GXGetTexObjFmt(void *);
extern void fn_802E317C(const char *);
extern char lbl_8034CB00[];
extern char lbl_8034CB24[];
extern void *lbl_804DB468;
extern unsigned int lbl_8055FEBC;

void fn_802DC440(void) {
    fn_802DBDD8();
    fn_802DFCC0();
}

extern int GXGetTexObjMipMap(void *);
extern unsigned short GXGetTexObjWrapS(void *);
extern int GXGetTexObjFmt(void *);
extern void fn_802E317C(const char *);
extern char lbl_8034CB00[];
extern char lbl_8034CB24[];
extern void *lbl_804DB468;
extern unsigned int lbl_8055FEBC;
extern unsigned int lbl_8055FEBC;
int fn_802DC6AC(int a, unsigned int b) {
    int i = a / 4;
    int j = (int)b / 4;
    unsigned int *base = (unsigned int *)lbl_8055FEBC;
    unsigned short v = *(unsigned short *)((char *)base + ((i + (j << 7)) << 6));
    return *(int *)((char *)base + ((i + (j << 7)) << 6) + 0x20) & 0xffff | (v << 16);
}


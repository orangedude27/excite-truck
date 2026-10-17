// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055FEC0;
extern void *lbl_8055FEA8;
extern void *lbl_8055FEAC;
extern void GXLoadTexMtxImm(float *, unsigned int, unsigned char);
extern float lbl_8055D148;
extern unsigned char lbl_804DB068[];
extern unsigned char lbl_802FACF8[];
extern unsigned char lbl_802FACD8[];
int fn_802DB378(int arg0, int arg1) { int result = 0xFF; if (arg0 == 2) { if (arg1 == 0) result = 4; } return result; }

void fn_802DB394(void) { GXSetTevOp(0, 3); GXSetTevOp(1, 3); GXSetTevAlphaOp(1, 0, 0, 0, 1, 0); GXSetTevAlphaIn(1, 0, 7, 7, 7); }

void fn_802DB4E4(void) {
    float m[12] = {0};
    m[0] = *(float *)(lbl_804DB068 + 0xc);
    m[6] = *(float *)(lbl_804DB068 + 0x10);
    m[2] = *(float *)(lbl_804DB068 + 0x18);
    m[8] = *(float *)(lbl_804DB068 + 0x1c);
    GXLoadTexMtxImm(m, 0x1e, 1);
    GXLoadTexMtxImm(&m[2], 0x21, 1);
}

void fn_802DB58C(void) {
    int m[12];
    int *p = (int *)lbl_802FACD8;
    m[0] = p[0]; m[1] = p[1]; m[2] = p[2]; m[3] = p[3];
    m[4] = p[4]; m[5] = p[5]; m[6] = p[6]; m[7] = p[7];
    m[8] = p[8]; m[9] = p[9]; m[10] = p[10]; m[11] = p[11];
    *(float *)&m[0] = *(float *)(lbl_804DB068 + 0xc);
    *(float *)&m[6] = *(float *)(lbl_804DB068 + 0xc);
    GXLoadTexMtxImm((float *)m, 0x1e, 1);
}

void fn_802DB620(void) {
    int m[12];
    int *p = (int *)lbl_802FACF8;
    m[0] = p[0]; m[1] = p[1]; m[2] = p[2]; m[3] = p[3];
    m[4] = p[4]; m[5] = p[5]; m[6] = p[6]; m[7] = p[7];
    m[8] = p[8]; m[9] = p[9]; m[10] = p[10]; m[11] = p[11];
    *(float *)&m[0] = lbl_8055D148;
    *(float *)&m[6] = lbl_8055D148;
    GXLoadTexMtxImm((float *)m, 0x1e, 1);
}

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
extern int lbl_8055FD30, lbl_8055FEA4;
extern signed char lbl_8055FE9E;
extern int lbl_8055FEA0;
extern void *lbl_8055FEA8, *lbl_8055FEAC;
extern void fn_802D94DC(int);
extern void fn_802DBA1C(unsigned char);
extern void fn_802DB9DC(int);
extern void fn_802DBBE4(int,int);
extern void fn_802DBF54(int,int);
extern void GXSetAlphaCompare(int,int,int,int,int);
extern void GXSetColorUpdate(int);
extern void GXSetZMode(int,int,int);
extern unsigned char lbl_8055FEBA;
#pragma dont_inline on
void fn_802DBF30(void) {
    fn_802DBDD8();
    fn_802DEE1C();
}
void fn_802DC078(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    fn_802DBA1C(lbl_8055FEBA);
    fn_802DB9DC(arg4);
    fn_802DBBE4(arg0, arg1);
    fn_802DBF54(arg2, arg3);
    if (lbl_8055FEBA != 0) {
        GXSetZMode(1, 3, 1);
        GXSetAlphaCompare(7, 0, 1, 7, 0);
        GXSetColorUpdate(0);
        fn_802DBF54(arg2, arg3);
        GXSetColorUpdate(1);
    }
}

extern void GXClearVtxDesc();
extern void GXSetVtxDesc(int, int);
extern void GXSetVtxAttrFmt(int, int, int, int, int);
extern void GXSetArray(int, void *, int);
extern void DCFlushRange(void *, int);
extern void GXSetBlendMode(int, int, int, int);
void fn_802DC130(void) {
    fn_802DBD88();
}

void fn_802DC134(void) {
    fn_802DBDD8();
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

void fn_802DC440(void) { ((void (*)(void))fn_802DBDD8)(); fn_802DFCC0(); }

void fn_802DC628(void) {}

void fn_802DC62C(void) {
    volatile unsigned char *p = (volatile unsigned char *)lbl_804DB468;
    if (GXGetTexObjMipMap((void *)(p + 0x24)) != 6)
        fn_802E317C(lbl_8034CB00);
    if (GXGetTexObjWrapS((void *)(p + 0x24)) != 0x200)
        fn_802E317C(lbl_8034CB24);
    lbl_8055FEBC = GXGetTexObjFmt((void *)(p + 0x24)) + 0x80000000;
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
    return (*(int *)((char *)base + ((i + (j << 7)) << 6) + 0x20) & 0xffff) | ((unsigned int)v << 16);
}

void fn_802DD228(void) { if (lbl_8055FEC0 != 0) { fn_802D3E88(); lbl_8055FEC0 = 0; } fn_802DBDD8(); fn_802CADD0(-1, 1); GXSetNumIndStages(0); GXSetTevDirect(0); }

void fn_802DD42C(void) { fn_802CFF64(); }


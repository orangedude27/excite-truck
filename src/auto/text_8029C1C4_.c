// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8029CD14(void);
extern void fn_8029C934(void);
extern void fn_8029C650(void);
extern void *fn_8029D464(void *, int);
extern int lbl_8055F7F8;
extern int lbl_8055F7F0;
extern int lbl_804B5010;
extern int lbl_8055CAA8;
extern void fn_8028E398(void);
extern void fn_802C6CF8(void);
extern void fn_802CAC54(int);
extern void fn_80128670(int);
extern void fn_80128668(void *);

void fn_8029C22C(void) {
    fn_8029CD14();
    fn_8029CB3C();
    fn_8029C934();
    fn_8029C650();
    fn_8029C3EC();
}

void fn_8029C650(void) { int value=lbl_8055CAA8; if(value != -1) fn_802C6CF8(); }

void fn_8029C934(void) {
 int i=0; int *p=&lbl_804B5010;
 while(i<lbl_8055F7F0) { fn_8029D464((void *)*p,1); ++p; ++i; }
 lbl_8055F7F0=0;
}

void fn_8029CD14(void) { int value=lbl_8055F7F8; if(value) { fn_8028E398(); lbl_8055F7F8=0; } }

void *fn_8029D464(void *arg0,int arg1) {
 if(arg0) { fn_802CAC54(*(int *)((unsigned char *)arg0+0x74)); fn_80128670(*(int *)((unsigned char *)arg0+0x70)); fn_80128670(*(int *)arg0); if(arg1>0) fn_80128668(arg0); }
 return arg0;
}

int fn_8029EF1C(void) {
    return 0;
}

void fn_8029EF24(void) {
}

void fn_8029EF28(void) {
}

void fn_8029EF2C(void) {
}

int fn_8029EF30(void *arg0) {
    return ((int *)arg0)[4];
}

int fn_8029EF60(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x68);
}


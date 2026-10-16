// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FD3C;
void fn_802CEC44(void) {
    lbl_8055FD3C = 1;
}

void fn_802CF104(void) {
    fn_802CF048(1);
}

void fn_802CFEEC(void* alarm) {
    fn_802CFDE0(fn_802CFCA0(alarm));
}

extern void *lbl_8055FD20;
void fn_802CFF50(void) {
    lbl_8055FD20 = (void*)-1;
}

extern void *lbl_8055FD1C;
void fn_802CFF5C(void* hi) {
    lbl_8055FD1C = hi;
}

extern void *lbl_8055FD54;
extern void fn_802D30F0(void);
extern void fn_802D307C(void);
void fn_802D050C(void* hi) {
    lbl_8055FD54 = hi;
}

extern unsigned char lbl_8055FD78;
extern int GXSetCullMode(int);
extern int lbl_8055D0BC;
extern int lbl_8055D0C0;
extern unsigned char lbl_8055FD18;
void fn_802D08B4(int arg0, int arg1, unsigned char arg2) {
    lbl_8055FD18 = arg2;
    lbl_8055D0BC = arg0;
    lbl_8055D0C0 = arg1;
}

void fn_802D0910(void) {
}

void fn_802D2614(void) {
    fn_802D14D8();
    fn_802D1678();
    fn_802D2218();
    fn_802D0EEC();
}

extern void *lbl_8055FD64;
void* fn_802D2D14(void) {
    return lbl_8055FD64;
}

extern void *lbl_8055FD5C;
void fn_802D30DC(void* hi) {
    lbl_8055FD5C = hi;
}

void* fn_802D30E4(void) {
    return (char*)lbl_8055FD54 + 0x24;
}

void fn_802D30FC(void) {
    fn_802D30F0();
}

void fn_802D3100(void) {
    fn_802D30F0();
}

extern void fn_802D30F0(void);
extern void fn_802D307C(void);
void* fn_802D3104(void) {
    struct { char pad[0x24]; char m; } *p;
    fn_802D307C();
    p = lbl_8055FD5C;
    return &p->m;
}

extern void *lbl_8055FD58;
void* fn_802D3138(void) {
    return (char*)lbl_8055FD58 + 0x24;
}
extern unsigned short lbl_8055FD86;
extern unsigned long lbl_8055FD94;
extern unsigned char lbl_8055FDA0[];
extern unsigned char lbl_804C97B0[];
extern unsigned long fn_802CE9FC(unsigned long);
extern void fn_802CFF64(void);
extern unsigned char lbl_8055FD78;
extern int lbl_8055D0BC;
extern int lbl_8055D0C0;
extern unsigned char lbl_8055FD18;
extern int GXSetCullMode(int);

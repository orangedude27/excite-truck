// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FD3C;
void fn_802CEC44(void) {
    lbl_8055FD3C = 1;
}

void fn_802CF104(void) {
    fn_802CF048(1);
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
    fn_802D307C();
    return (char*)lbl_8055FD5C + 0x24;
}


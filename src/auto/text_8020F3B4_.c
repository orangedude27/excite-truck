// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern long fn_801345D8(long, long, long *, long);
extern long lbl_8055B664;
extern signed char lbl_8055EEF4;
extern signed char lbl_8055EEF5;
extern signed char lbl_8055EEF6;
extern char lbl_80489CA0;
extern long fn_8020F608(long, long);
extern struct Unk_804902C4 {
    long *m_entries;
    long m_count;
} lbl_804902C4;
extern long lbl_8055EEC4;
long fn_8020F3B4(void) { return -1; }

long fn_8020F3BC(long arg0, long arg1, long arg2) {
    fn_801345D8(arg1, arg2, &lbl_8055B664, arg0);
    return arg1;
}

#pragma dont_inline on
void fn_8020F5C8(void) {
    lbl_8055EEF6 = 1;
    lbl_8055EEF5 = 1;
    lbl_8055EEF4 = 1;
}
#pragma dont_inline reset

void fn_8020F5DC(void) {
    lbl_8055EEF6 = 0;
    lbl_8055EEF5 = 0;
    lbl_8055EEF4 = 0;
}

void *fn_8020F5F0(long arg0) {
    return (void *)((char *)&lbl_80489CA0 + ((arg0 << 6) * 100));
}

void fn_8020F6E0(long arg0, long arg1) {
    if (arg1 != 0) {
        return;
    }
    fn_8020F608(0, arg0);
}

void fn_8020F6F8(void) {
    fn_802EC0FC();
}

void fn_802103B8(void) {
    fn_8020F5C8();
}

void fn_80210510(void) {
    fn_802EC1C0();
}

extern void *lbl_8055EED8;
extern void *lbl_8055EEDC;
void AXFXSetHooks_80210950(void *arg0, void *arg1) {
    lbl_8055EED8 = arg0;
    lbl_8055EEDC = arg1;
}
extern long fn_801345D8(long, long, long *, long);
extern long lbl_8055B664;
extern signed char lbl_8055EEF4;
extern signed char lbl_8055EEF5;
extern signed char lbl_8055EEF6;


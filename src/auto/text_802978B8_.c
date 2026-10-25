extern void *lbl_8055F7A4;
void fn_80297998(void);
extern int lbl_8055F7B4;
extern void *lbl_8055CA60;
extern const char lbl_803493D8[];
extern int fn_802C9C8C(void *);
extern void fn_802C7ADC(int);
extern void *fn_801E87A8(void);
extern void fn_802979A4(void);
extern void fn_80297AFC(void);
extern void fn_802C9CE0(void);
extern void fn_802E30C8(void *, const char *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F7B0;
void fn_80297A84(void);
extern void fn_80297A30(void);
void fn_802978B8(void) {
    fn_80297998();
    fn_80297A30();
    lbl_8055F7B0 = (void*)0x50000000;
}

void fn_802978E4(void) {
    fn_80297A84();
    lbl_8055F7A4 = 0;
}

void fn_8029790C(void) {
    if (fn_802C9C8C(lbl_8055F7B0)) {
        fn_802C7ADC((*(unsigned int *)((char *)fn_801E87A8() + 0x10) >> 1) & 1);
        fn_802979A4();
        fn_80297AFC();
        fn_802C9CE0();
    } else if (lbl_8055F7B4 == 0) {
        lbl_8055F7B4 = 1;
        fn_802E30C8(lbl_8055CA60, lbl_803493D8);
    }
}

void fn_80297980(void) {
}

void fn_80297984(void) {
}

void fn_80297A08();
void fn_80297C3C(void);
void fn_80297988(void) {
    fn_80297A08();
}

void fn_8029798C(void) {
    fn_80297C3C();
}

void fn_80297990(void* hi) {
    lbl_8055F7B0 = hi;
}

extern void *lbl_8055F7A4;
void fn_80297998(void) {
    lbl_8055F7A4 = 0;
}

extern void *lbl_8055F7A8;
extern int lbl_8055F7AC;
extern void *lbl_804B4F10;
extern const char lbl_803493F8[];
extern void fn_80128670(void *);
extern void fn_802C6CF8(void *);
extern void *fn_8012850C(int, const char *);
extern void *fn_8002F37C(void (*)(void), int, int, int);
void fn_80297A80(void) {}


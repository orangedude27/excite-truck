// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E490;
extern int lbl_8055E488;
extern int lbl_8055E48C;
extern void fn_80128670(void*);
extern void fn_8012850C(void*, void*);
extern int fn_8002F37C(void*, int, int, int);
extern char lbl_80331CB8[16];
extern void fn_8017D330(void);
extern void fn_80179E00(void*);
extern void fn_8017B198(void*);
extern void fn_80179D94(void);
extern void fn_8017B2D0(void*, float, float, float, float);
extern void fn_80179D08(void);
extern char lbl_80331CC4[];

void fn_8017B164(void *arg0) {
    fn_80179E00(arg0);
    fn_8017B198(arg0);
}

void fn_8017C7BC(void) {

}

void fn_8017C7C0(void) {

}

void fn_8017C7C4(void) {

}

void fn_8017D140(unsigned char *dst, unsigned char *src, int count) {
    goto check;
loop:
    *dst++ = *src++;
check:
    if (--count >= 0) goto loop;
}

void fn_8017D2C8(void) {
    fn_8017B3A8();
}

void fn_8017D2CC(int arg0) {
    lbl_8055E48C = arg0;
    lbl_8055E488 = 0;
    fn_8012850C((char*)(arg0 * 0x28 + 0x10), &lbl_80331CB8);
    lbl_8055E490 = fn_8002F37C(fn_8017D330, 0, 0x28, arg0);
}

void fn_8017D330(void) {

}

void fn_8017D334(void) {
    int value = lbl_8055E490;
    lbl_8055E488 = 0;
    lbl_8055E48C = 0;
    if (value != 0) fn_80128670((char*)value - 0x10);
}

void fn_8017D358(void) {

}

int fn_8017D35C(void) { return 0x20; }

unsigned int fn_8017D364(void) { return 1; }

void fn_8017D36C(void) {

}


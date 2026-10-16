// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E6D0;
extern char lbl_80435C70;
extern char lbl_80335E48;
extern void fn_802E317C(const char *, int);
extern int __dt__15shdStateMachineFv_801B496C(int);
extern void *lbl_8055E6D8;
extern int *fn_801B479C();
extern int fn_801B47BC();
extern unsigned int fn_801B4BDC(void);
extern int fn_801B4B9C(int);
extern int fn_801B47AC(int);
int fn_801B4B9C(int arg0) {
    return *fn_801B479C(arg0 + 4, fn_801B47AC(arg0 + 4));
}

int fn_801B4C1C(int arg0, int arg1) {
    int result;
    result = (int)fn_801B4BDC();
    return arg1 >= result;
}

void fn_801B4C58(int arg0) {
    fn_801B479C(arg0 + 4);
}

void fn_801B4C60(int arg0) {
    fn_801B479C(arg0 + 4, fn_801B47BC(arg0 + 4));
}

void fn_801B4C9C(int arg0, int arg1) {
    int count;
    int value;

    count = arg1 - fn_801B4B9C(arg0);
    value = fn_801B47AC(arg0 + 4);
    count /= 6;
    do {
        fn_801B47BC(arg0 + 4, value);
        count--;
    } while (count != 0);
}

char fn_801B526C(void) {
    return lbl_8055E6D0;
}

void fn_801B5318(void) {

}

extern void *lbl_8055E6D8;
extern void fn_801B49C8(void *);
extern char lbl_80435C70;
extern char lbl_80335E48;
extern void fn_802E317C(const char *, int);
extern int __dt__15shdStateMachineFv_801B496C(int);
void fn_801B531C(void) {
    if (lbl_8055E6D8 != 0) {
        __dt__15shdStateMachineFv_801B496C(1);
        lbl_8055E6D8 = 0;
    }
}

void fn_801B535C(void) {

}

void fn_801B5360(void) {

}


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801D153C(void) {
    fn_801D1540();
}

void fn_801D1008(void*, unsigned int);
void fn_80128668(void*);
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801D1AB4(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_801D1008((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

extern int lbl_8055E918;
extern float lbl_80562A58;
extern int fn_80128670(int);
void fn_801D1B0C(void) {
    if (lbl_8055E918 != 0) {
        fn_80128670(lbl_8055E918 - 0x10);
    }
    lbl_8055E918 = 0;
}

void fn_801D1B44(void) {

}

extern int lbl_8055E8F8;
extern int lbl_8055ABD8;
extern float lbl_80562A58;
void fn_801D183C(int, int);
void fn_801D153C(void);
int fn_8012850C(int, int *);
int fn_8002F37C(int, int, int, int);
void fn_801D1B48(void) {
    int offset = 0;
    int i = 0;
    while (i < lbl_8055E8F8) {
        fn_801D183C(lbl_8055E918 + offset, i);
        offset += 0x9c;
        i++;
    }
}

void fn_801D1810(int, int);
void fn_801D1BA4(void) {
    int offset = 0;
    int i = 0;
    while (i < lbl_8055E8F8) {
        fn_801D1810(lbl_8055E918 + offset, i);
        offset += 0x9c;
        i++;
    }
}

void fn_801D1C10(void) {
    int count = lbl_8055E8F8;
    fn_8012850C(count * 0x9c + 0x10, &lbl_8055ABD8);
    lbl_8055E918 = fn_8002F37C(0, 0, 0x9c, count);
}


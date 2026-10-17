// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FE78;
extern int lbl_8055FE80;
int fn_802D8FB4(int);
int fn_80128658(int);
void fn_802DAE18(void) {
    if (lbl_8055FE78 != 0) {
        fn_802D8FB4(lbl_8055FE80);
        lbl_8055FE80 = 0;
        fn_80128658(lbl_8055FE78);
        lbl_8055FE78 = 0;
    }
}
typedef struct {
    unsigned char kind;
    unsigned char format;
    unsigned char pad2[2];
    void *buffer;
    int width;
    int height;
    int size;
    int pad14[2];
    int width2;
    int height2;
} DB168Config;

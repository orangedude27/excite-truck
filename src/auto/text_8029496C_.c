// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_80287B14(void);
int fn_802CAC54(int);
extern int lbl_8055C990;
extern int lbl_8055C994;
void fn_80294C68(void) {
    int i;
    fn_802CAC54(lbl_8055C990);
    fn_802CAC54(lbl_8055C994);
    lbl_8055C990 = -1;
    i = 0;
    lbl_8055C994 = -1;
    do { i++; } while (i < fn_80287B14());
}

void fn_80294CC0(void) {}

void fn_80294CC4(void) {}


extern char lbl_8055F5BA;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F5B8;
char fn_80278358(void) {
    return lbl_8055F5B8;
}

extern char lbl_8055F5B9;
void fn_802787E4(void) {
    lbl_8055F5BA = 0;
    lbl_8055F5B9 = 0;
}

extern char lbl_8055F5BA;
char fn_802787F4(void) {
    return lbl_8055F5BA;
}

extern char lbl_8055F5BB;
extern char lbl_8055F5C8;
extern int lbl_8055F5C0;
extern int lbl_8055E3C4;
extern float lbl_805640A8;
extern float lbl_805640B8;
extern float lbl_805640BC;
void *fn_802678E4(int);

void fn_8027889C(float farg0) {
    float temp_f1 = farg0 / lbl_805640B8;
    float var_f0;

    if (temp_f1 < lbl_805640A8) {
        var_f0 = temp_f1 - lbl_805640BC;
    } else {
        var_f0 = lbl_805640BC + temp_f1;
    }
    lbl_8055F5C0 = (int)var_f0;
}


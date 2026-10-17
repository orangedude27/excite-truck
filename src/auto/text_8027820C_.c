extern char lbl_8055F5BA;
extern char lbl_8055F5BB;
extern char lbl_8055F5B9;
extern char lbl_8055F5C8;
extern int lbl_8055E3C4;
extern int lbl_8055F5B4;
extern int lbl_8055F5BC;
extern char lbl_8055F5B8;
extern int fn_802E30C8(const char *, ...);
extern const char lbl_80347590[];
extern const char lbl_803475B4[];
extern const char lbl_80347660[];
extern char lbl_804A15D0[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F5B8;
void fn_8027820C(void) {}

void fn_80278210(void) {}

void fn_80278284(void) {}

void fn_80278318(void) {
    fn_802E30C8(lbl_803475B4, lbl_8055E3C4);
    lbl_8055F5B8 = 0; lbl_8055F5BA = 0; lbl_8055F5B9 = 0;
}

char fn_80278358(void) {
    return lbl_8055F5B8;
}

void fn_80278778(char *arg0) {
    int i;
    char *dst;
    if (lbl_8055F5B8 != 0) { fn_802E30C8(lbl_80347660); return; }
    dst = lbl_804A15D0;
    for (i = 0; i < 0x100; i++) {
        char c = *arg0++;
        *dst++ = c;
        if (c == 0) { lbl_8055F5B9 = 1; lbl_8055F5BA = 0; return; }
    }
    dst[-1] = 0;
    lbl_8055F5B9 = 1;
    lbl_8055F5BA = 0;
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

int fn_802787FC(void) {
    if (lbl_8055F5BA != 0) return 0;
    if (lbl_8055F5BB == 0) return 0;
    return 1;
}

extern char lbl_8055F5BB;
extern char lbl_8055F5B9;
extern char lbl_8055F5C8;
extern int lbl_8055E3C4;
extern char lbl_8055F5C8;
extern int lbl_8055F5C0;
extern int lbl_8055E3C4;
extern float lbl_805640A8;
extern float lbl_805640B8;
extern float lbl_805640BC;
void *fn_802678E4(int);

extern int lbl_8055F5BC;
extern float lbl_805640B0;
void fn_8027889C(float arg0) {
    float t = arg0 / lbl_805640B8;
    float result;
    if (t < lbl_805640A8) result = t - lbl_805640BC;
    else result = lbl_805640BC + t;
    lbl_8055F5C0 = (int)result;
}

int fn_80278924(float *arg0, float *arg1) {
    int result = 0;
    float scale = lbl_805640B8;
    *arg0 = scale * (float)lbl_8055F5C0;
    *arg1 = scale * (float)lbl_8055F5BC;
    if (lbl_8055F5C0 >= 0 && lbl_8055F5BC >= lbl_8055F5C0) result = 1;
    return result;
}

void fn_8027888C(char arg0) {
    lbl_8055F5C8 = arg0;
}

void fn_80278894(char arg0) {
    lbl_8055F5BB = arg0;
}
extern int lbl_8055F5B4;
extern char lbl_8055F5B8;
extern int fn_802E30C8(const char *, ...);
extern const char lbl_80347590[];
extern const char lbl_803475B4[];
extern const char lbl_80347660[];
extern char lbl_804A15D0[];
extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
extern const char lbl_80347580[];
extern int fn_8012850C(int, const char *, int);
extern void *fn_8002F37C(void *, int, int, int);
extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
extern void fn_80128670(int);

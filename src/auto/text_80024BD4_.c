// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_802FE850[];
#pragma scheduling invalid_target
/* mbtowc: tail-call the current locale's mbtowc hook at ctype_cmpts+0x20. */
int fn_80024BD4(short *pwc, const char *s, int n) {
    return (*(int (**)(short *, const char *, int))(*(unsigned int *)(lbl_802FE850 + 0x38) + 0x20))(pwc, s, n);
}
#pragma scheduling on
/* RealName: mbtowc_noconv (single-byte to wide char, no charset conversion) */
int fn_80024BEC(short *arg0, unsigned char *arg1, int arg2) {
#define mbtowc_noconv fn_80024BEC
#define pwc arg0
#define s arg1
#define n arg2
    /* Convert a single-byte character to a wide char without charset conversion. */
    if (s == 0) return 0;
    if (n == 0) return -1;
    if (pwc != 0) *pwc = *s;
    if ((signed char)*s == 0) return 0;
    return 1;
#undef pwc
#undef s
#undef n
#undef mbtowc_noconv
}

int fn_80024C38(signed char *s, signed char wchar) {
    /* wctomb for the no-conversion locale: store the wide char as one byte and return 1, or 0 if s is null. */
    if (s == 0) return 0;
    *s = wchar;
    return 1;
}


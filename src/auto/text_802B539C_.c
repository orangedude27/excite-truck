// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9E8;
int fn_8012C33C(void);
int fn_802CAC28(int, int);
int fn_802B539C(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void fn_802B5404(int *arg0) { int temp = *arg0; if (temp != -2) { fn_802CAC54(temp); *arg0 = -2; } }

void* fn_802B59CC(void) {
    return lbl_8055F9E8;
}
extern int stricmp(const char *, const char *);
extern const char lbl_8034A510[];
extern int fn_8012E96C(const char *);
extern int fn_802B5510(const char *);
extern int fn_8013184C(void);
extern const char lbl_8034A588[];
struct TplLike { void *entries; unsigned int count; };
extern struct TplLike lbl_804BE4AC;

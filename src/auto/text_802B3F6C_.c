#define NULL 0
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9C8;
extern void fn_80128668(void *);
extern void fn_80128670(int);
extern void fn_802B4D40(void *);
extern int fn_802B40B0(int, int);
void fn_802B4DC0(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((int *)p)[3]);
            if (p != NULL) {
                ((int *)p)[0] = 0;
                ((int *)p)[1] = 0;
                ((int *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

void fn_802B4E30(void) {
    lbl_8055F9C8 = (void*)-1;
}

void fn_802B4E3C(void* hi) {
    lbl_8055F9C8 = hi;
}

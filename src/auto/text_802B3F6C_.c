#define NULL 0
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9C8;
extern void fn_80128668(void *);
extern void fn_80128670(int);
extern void fn_802B4D40(void *);
extern int fn_802B40B0(int, int);
void fn_802B4D40(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            if (p != NULL) {
                int x = ((int *)p)[3];
                if (x != 0) {
                    fn_80128670(x - 0x10);
                }
                if (p != NULL) {
                    ((int *)p)[0] = 0;
                    ((int *)p)[1] = 0;
                    ((int *)p)[2] = 0;
                }
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

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

void *fn_802B4F10(void *out, int x, int y, int a, int b) {
    int r = fn_802B40B0(a, b);
    void *res = NULL;
    if (r != 0) {
        int idx = (((x & 0x1F) + ((y << 5) & 0x3E0)) << 3);
        void *p = (void *)(r + idx);
        *(int *)out = ((int *)p)[1];
        res = (void *)r;
        if (((int *)r)[1] <= 0) {
            res = NULL;
        }
    }
    return res;
}


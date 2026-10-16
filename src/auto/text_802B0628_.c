// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9A0;
void fn_802B087C(void **arg0);
void fn_802AE64C(void *);
void fn_8002F6AC(int, void (*)(void));
void fn_802B0808(void);
void fn_80128668(void *);
void fn_802B0860(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_802B0874(void) {
    fn_802B087C(&lbl_8055F9A0);
}

#pragma push
#pragma opt_common_subs off
void fn_802B087C(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            fn_802AE64C(ptr);
            if ((char *)ptr + 4 != 0) {
                fn_8002F6AC(((int *)ptr)[4], fn_802B0808);
                if ((char *)ptr + 4 != 0) {
                    ((int *)ptr)[1] = 0;
                    ((int *)ptr)[2] = 0;
                    ((int *)ptr)[3] = 0;
                }
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
}
#pragma pop
void fn_802B0904(void) {
    ((int *)lbl_8055F9A0)[2] = 0;
}

int fn_802B1C14(void *arg0) {
    return ((int *)arg0)[4];
}

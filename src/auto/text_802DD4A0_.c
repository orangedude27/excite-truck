// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void *fn_80128668(void *);
void fn_80128670(int);
extern void *lbl_8055FED8;
extern float lbl_804DB6A0[];
void *fn_802DD4A0(void *arg0, int arg1) {
    void *local = arg0;
    if (arg0 != (void*)0) {
        if ((arg0 != (void*)0) && (arg0 != (void*)0)) {
            *(int*)arg0 = 0;
            *(int*)((char*)arg0 + 4) = 0;
            *(int*)((char*)arg0 + 8) = 0;
        }
        if (arg1 > 0) {
            fn_80128668(local);
        }
    }
    return local;
}

void fn_802DD738(int arg0, float farg0) {
    *(float *)((char *)lbl_804DB6A0 + (arg0 * 0x24) + 0x20) = farg0;
}

void fn_802DD750(void) {
}

void fn_802DEA6C(void* alarm) {
    fn_802D3360(fn_802DEF70(alarm));
}

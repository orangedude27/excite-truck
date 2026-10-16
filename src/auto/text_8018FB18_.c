// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_804349A0[];
extern int lbl_8055E518;
extern float lbl_80562080, lbl_8056208C, lbl_80562090, lbl_805620AC;
int fn_801B665C();
void fn_80191084();
void fn_801B6650();
void fn_80191100();
void fn_802793B0();
void fn_801902A0(void *arg0) {
    ((void (**)(void))(*(void **)*(void **)((char *)arg0 + 4)))[30]();
}

void fn_801902B4(void *arg0) {
    unsigned int temp_r3;
    int (*callback)(void *);

    fn_80191084(arg0, 0);
    fn_801B6650(*(int *)((char *)arg0 + 0x20));
    callback = (int (*)(void *))fn_80191100;
    temp_r3 = callback(arg0);
    if (temp_r3 != *(unsigned int *)((char *)arg0 + 8)) {
        fn_80191084(arg0);
    } else {
        fn_80191084(arg0, *(unsigned int *)((char *)arg0 + 0xC));
    }
    fn_80191084(arg0, temp_r3);
    if (*(unsigned char *)((char *)arg0 + 0x38) != 0) {
        *(unsigned char *)((char *)arg0 + 0x38) = 0;
        fn_802793B0(*(int *)((char *)arg0 + 0x28));
    }
    ((void (**)(void *))(*(void ***)arg0))[12](arg0);
}

void fn_80190360(int arg0) {
    fn_80191084(arg0, 0);
}

int fn_80190368(int arg0) {
    int result = 0;
    if (arg0 != 1) {
        if (arg0 == 0) {
            result = 1;
        }
    }
    return result;
}

extern void *lbl_804349A0[];
extern int lbl_8055E518;
int fn_801B665C();
extern float lbl_80562080, lbl_8056208C, lbl_80562090, lbl_805620AC;
int fn_80190D38(float a, float b, float c) {
    float x = (a - b) / (c - b);
    if (lbl_80562090 >= x) {
        lbl_80562090 = lbl_80562090;
    } else {
        lbl_80562090 = x;
    }
    if (lbl_80562090 <= lbl_8056208C) {
        lbl_80562090 = lbl_80562090;
    } else {
        lbl_80562090 = lbl_8056208C;
    }
    return (int)(lbl_80562080 + (lbl_8056208C + (lbl_80562090 * lbl_805620AC)));
}

void fn_80190E6C(void) {
    fn_80190E08();
}

void fn_80190F90(void) {
    fn_80191758();
}

void fn_80191060(void) {
    fn_801B6664();
}

void fn_80192BE4(void) {

}

void fn_80193058(void) {
}


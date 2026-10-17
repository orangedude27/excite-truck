// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8024CC54(void *, void *, int);
extern void fn_8024C768(void);
extern signed char lbl_8055F2C8;
extern int fn_8024CEF0;
extern int fn_8000D984(int);
extern void fn_8000DA80(void);
extern int fn_8000DC70(int);
extern void fn_8000DA1C(void *);
extern int fn_802E8D84(void);
extern void fn_802E7128(void);
void fn_802328D4(void *);
void fn_80128668(void *);
int fn_8000DA10(void);
int fn_8000DB34(int);
int fn_8000DB8C(int);
int fn_8000DBAC(int);
void fn_801345D8(void *, int, const char *, int);
extern char lbl_80498A00[];
extern int lbl_80498A48[];
extern char lbl_8055C018[];
void fn_8024C370(void) {}

void *fn_8024C374(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((char *)arg0 + 0x78 != 0) {
            fn_802328D4(*(void **)((char *)arg0 + 0x78));
            *(void **)((char *)arg0 + 0x78) = 0;
        }
        if ((char *)arg0 + 0x18 != 0 && (char *)arg0 + 0x4C != 0) {
            fn_802328D4(*(void **)((char *)arg0 + 0x4C));
            *(void **)((char *)arg0 + 0x4C) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void *fn_8024C3FC(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (*(void **)((char *)arg0 + 0x34) != 0) {
            fn_802328D4(*(void **)((char *)arg0 + 0x34));
            *(void **)((char *)arg0 + 0x34) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_8024C464(void) {
    int i;
    int state;
    for (i = 0; i < 4; ++i) {
        fn_801345D8(&lbl_80498A00[i * 0x12], 0x12, lbl_8055C018, fn_8000DB34(i));
        if (fn_8000DBAC(i) == 0 && i == fn_8000DA10()) {
            if (fn_8000DB8C(i) != 0)
                lbl_80498A48[i] = 2;
            else
                lbl_80498A48[i] = 1;
        } else {
            lbl_80498A48[i] = 0;
        }
    }
}

void fn_8024CF38(void) {
    fn_8024CC54(&fn_8024CEF0, 0, 1);
}

void fn_8024CF48(void *arg0) {
    fn_8024CC54(arg0, 0, 0);
}

void fn_8024CF54(void) {
    lbl_8055F2C8 = 1;
    fn_8024C768();
}




extern float lbl_8056208C;
extern int lbl_8055E3C4;
int fn_80191100(void *arg0) { return ((int *)arg0)[3]; }

void fn_8019169C(void *arg0, void *arg1) {
    *(void **)((char *)arg0 + 0x34) = arg1;
    *(int *)((char *)arg0 + 0x3C) = *(int *)((char *)arg1 + 0x1EC);
}

void *fn_801916AC(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(int *)((char *)arg0 + 0x38) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

int fn_80192C68(void *arg0) {
    return (((unsigned char)*(unsigned char *)((char *)*(void **)((char *)arg0 + 8) + 7) >> 5) & 7) - 1;
}

unsigned char fn_80192F6C(void *arg0) {
    return *((unsigned char *)arg0 + 0x12);
}

void fn_80192F74(void *arg0) {
    *(int *)((char *)arg0 + 0xC) = lbl_8055E3C4;
}

int fn_80193010(void) { return 0x20; }

void fn_8019304C(void *arg0) {
    *(float *)((char *)arg0 + 0x40) = lbl_8056208C;
}

void fn_80193058(void) {
}

unsigned char fn_8019305C(void *arg0) {
    return *((unsigned char *)arg0 + 0x11);
}

unsigned char fn_80193064(void *arg0) {
    return *((unsigned char *)arg0 + 0x13);
}


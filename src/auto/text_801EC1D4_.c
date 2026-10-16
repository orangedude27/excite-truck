// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801EC9CC(void*, unsigned int);
void fn_80128668(void*);
void fn_801ECCE0(long, long);
long fn_801E866C(long);
long fn_801E89C8(long);
float fn_802C99E8(void *, float);
void fn_801ED718(void *);
void fn_801ECC70(void);
void fn_801F131C(void *, long, void *, float);
void fn_801EFC90(long, long, void *);
extern float lbl_80488668[3];
void fn_801ED2D0(void *arg0) {
    long flag;
    long i;
    long offset;
    char *p;
    fn_801ECC70();
    flag = *(long *)((char *)arg0 + 0x40) == fn_801E866C(-1);
    i = 0;
    offset = 0;
    do {
        p = (char *)*(void **)((char *)arg0 + 0x3C) + offset;
        fn_801F131C(*(void **)((char *)arg0 + 0x4D4 + i * 4), flag, p,
                    *(float *)(p + 0xB0));
        i++;
        offset += 0x6C;
    } while (i < 4);
}

void fn_801ED694(long arg0) {
    fn_801ECCE0(arg0, 0);
}

void fn_801ED69C(void *arg0) {
    void *ptr;
    if (*(long *)((char *)arg0 + 0x40) == fn_801E866C(-1) &&
        fn_801E89C8(-1) != 0) {
        ptr = *(void **)((char *)arg0 + 0x3C);
        lbl_80488668[2] = fn_802C99E8(ptr, *(float *)((char *)ptr + 0x2CC));
        fn_801ED718(arg0);
        fn_802C99E8(arg0, lbl_80488668[2]);
    }
}

void fn_801EDD68(void *arg0) {
    fn_801EFC90(*(long *)((char *)arg0 + 0x3F0),
                *(long *)((char *)arg0 + 0x3C), (char *)arg0 + 0x4D4);
}

void fn_801EDD7C(void *, long);
long fn_80179CB0(void);
void fn_801EECAC(long, long);
void fn_802C6CF8(long);
void fn_801EEC68(void *arg0) {
    long value;
    value = *(long *)((char *)arg0 + 0x488);
    if (value != -1) {
        fn_802C6CF8(value);
        *(long *)((char *)arg0 + 0x488) = -1;
    }
}

long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801EEEEC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_801EC9CC((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

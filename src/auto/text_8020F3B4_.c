// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
  
extern struct Unk_804900AC { long *m_entries; long m_count; long m_capacity; } lbl_804900AC;
extern long fn_801345D8(long, long, long *, long);
extern long lbl_8055B664;
extern signed char lbl_8055EEF4;
extern signed char lbl_8055EEF5;
extern signed char lbl_8055EEF6;
extern char lbl_80489CA0[16];
extern long fn_8020F608(long, long);
extern struct Unk_804902C4 {
    long *m_entries;
    long m_count;
    long m_pad;
} lbl_804902C4;
extern long lbl_8055EEC4;
long fn_8020F3B4(void) { return -1; }

long fn_8020F3BC(long arg0, long arg1, long arg2) {
    long result = arg1;
    fn_801345D8(arg1, arg2, &lbl_8055B664, arg0);
    return result;
}

#pragma dont_inline on
void fn_8020F5C8(void) {
    lbl_8055EEF6 = 1;
    lbl_8055EEF5 = 1;
    lbl_8055EEF4 = 1;
}
#pragma dont_inline reset

void fn_8020F5DC(void) {
    lbl_8055EEF6 = 0;
    lbl_8055EEF5 = 0;
    lbl_8055EEF4 = 0;
}

void *fn_8020F5F0(long arg0) {
    long offset = (arg0 << 6) * 100;
    return (void *)((char *)&lbl_80489CA0 + offset);
}

void fn_8020F6E0(long arg0, long arg1) {
    if (arg1 != 0) {
        return;
    }
    fn_8020F608(0, arg0);
}

void fn_8020F6F8(void) {
    fn_802EC0FC();
}

long fn_8020F6FC(void) {
    long index = lbl_8055EEC4;
    long *entries = lbl_804902C4.m_entries;
    long count = lbl_804902C4.m_count;
    long value = entries[index];
    lbl_8055EEC4 = (index + 1) % count;
    return value;
}

void fn_8021031C(void) {
    memset(&lbl_80489CA0, 0, 0x6400);
    fn_802E6BD8(0x546D7573, 0, &lbl_80489CA0, 0x6400, 0);
    fn_8000DBC8(&fn_8020F6E0);
}

extern long fn_80207848(void *, long);
extern long fn_802EC1D8(void);
extern long fn_802EC12C(void);
extern long fn_8020FCC4(void);
extern long lbl_8033C9AC;
extern long lbl_8055EED0;
void fn_8021037C(void) {
    lbl_8055EED0 = fn_80207848(&lbl_8033C9AC, 1);
    fn_802EC1D8();
    fn_802EC12C();
    fn_8020FCC4();
}

void fn_802103B8(void) {
    fn_8020F5C8();
}

void fn_80210510(void) {
    fn_802EC1C0();
}

extern long fn_80145E70(void *);
extern long fn_802090D4(void *);
extern long fn_80209110(void *);
extern long fn_8000DA10(void);
extern long lbl_8033C9BC[];
extern long lbl_8033C9C8[];
extern long lbl_8055EED4;
extern long lbl_8055EEF0;
extern long lbl_8055B658;
void fn_802108C8(void) {
    lbl_8055EED4 = fn_80145E70(&lbl_8033C9BC[0]);
    lbl_8055EEF0 = fn_802090D4(&lbl_8033C9C8[0]);
}

void fn_80210904(void) {
    fn_80209110(&lbl_8055EEF0);
    if (lbl_8055EED4 != 0) {
        (*(void (**)(long, long))(*(long *)lbl_8055EED4 + 8))(lbl_8055EED4, 1);
    }
    lbl_8055EED4 = 0;
}

extern void *lbl_8055EED8;
extern void *lbl_8055EEDC;
void AXFXSetHooks_80210950(void *arg0, void *arg1) {
    lbl_8055EED8 = arg0;
    lbl_8055EEDC = arg1;
}
extern long fn_801345D8(long, long, long *, long);
extern long lbl_8055B664;
extern signed char lbl_8055EEF4;
extern signed char lbl_8055EEF5;
extern signed char lbl_8055EEF6;
// Code of main that had no source file yet: decomp.wtf gave it this one.
 // split_file divides it into the game's real files (file_status shows its range).

    extern long fn_802EC104(long);
extern void fn_8020F730(void);
extern long fn_8020F9F4(void);
extern int stricmp(const char *, const char *);
extern int fn_8002B1D8(const char *, const char *, int);

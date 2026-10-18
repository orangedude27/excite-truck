// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
  
extern struct Unk_804900AC { long *m_entries; long m_count; long m_capacity; } lbl_804900AC;
extern void fn_801345D8(void *, ...);
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
extern long lbl_8055EED0;
extern long lbl_8055EED4;
extern long lbl_8055B658;
extern float lbl_80563400;
extern void fn_802EC1C0();
extern void fn_802EC1E4();
extern long fn_802EC12C();
long fn_8020F3B4(void) { return -1; }
 
long fn_8020F3BC(long arg0, long arg1, long arg2) {
    long result = arg1;
    ((void (*)(long, long, long *, ...))fn_801345D8)(arg1, arg2, &lbl_8055B664, arg0);
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

extern void *memset(void *, int, unsigned long);
#pragma dont_inline on
long fn_8020F608(long arg0, long arg1) {
    long i;
    char *ptr;

    ptr = (char *)fn_8020F5F0(arg1);
    memset(ptr, 0, 0x1900);
    for (i = 0; i < 2; i++) {
        *(long *)(ptr + 0x000) = arg0;
        *(long *)(ptr + 0x064) = arg0;
        *(long *)(ptr + 0x0C8) = arg0;
        *(long *)(ptr + 0x12C) = arg0;
        *(long *)(ptr + 0x190) = arg0;
        *(long *)(ptr + 0x1F4) = arg0;
        *(long *)(ptr + 0x258) = arg0;
        *(long *)(ptr + 0x2BC) = arg0;
        *(long *)(ptr + 0x320) = arg0;
        *(long *)(ptr + 0x384) = arg0;
        *(long *)(ptr + 0x3E8) = arg0;
        *(long *)(ptr + 0x44C) = arg0;
        *(long *)(ptr + 0x4B0) = arg0;
        *(long *)(ptr + 0x514) = arg0;
        *(long *)(ptr + 0x578) = arg0;
        *(long *)(ptr + 0x5DC) = arg0;
        *(long *)(ptr + 0x640) = arg0;
        *(long *)(ptr + 0x6A4) = arg0;
        *(long *)(ptr + 0x708) = arg0;
        *(long *)(ptr + 0x76C) = arg0;
        *(long *)(ptr + 0x7D0) = arg0;
        *(long *)(ptr + 0x834) = arg0;
        *(long *)(ptr + 0x898) = arg0;
        *(long *)(ptr + 0x8FC) = arg0;
        *(long *)(ptr + 0x960) = arg0;
        *(long *)(ptr + 0x9C4) = arg0;
        *(long *)(ptr + 0xA28) = arg0;
        *(long *)(ptr + 0xA8C) = arg0;
        *(long *)(ptr + 0xAF0) = arg0;
        *(long *)(ptr + 0xB54) = arg0;
        *(long *)(ptr + 0xBB8) = arg0;
        *(long *)(ptr + 0xC1C) = arg0;
        ptr += 0xC80;
    }
}
#pragma dont_inline reset
 
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

void fn_8020FC6C(void) {
    struct Unk_804900AC *state = &lbl_804900AC;
    if (state->m_count == 0) {
        ((long (*)(long))fn_8020F3B4)(0);
    } else if (fn_8020FC04() != 0) {
        fn_8020FB80();
    } else {
        ((long (*)(long))fn_8020F3B4)(0);
    }
}

extern long lbl_8055EEBC;
extern long lbl_8055EEE0;
extern long lbl_8055EEE4;
extern void fn_8020FE90(void);
void fn_8020FFE4(long arg0) {
    long old = lbl_8055EEE0;
    long value = lbl_8055EEBC;
    long digit;
    if (value == 0) lbl_8055EEE0 = -2;
    else {
        digit = 9;
        if ((lbl_8055EEE4 + 1) * 10 >= value) digit = (value - 1) % 10;
        if (old == -2) { if (arg0 == 1) lbl_8055EEE0 = 0; }
        else if (old == -1) { if (arg0 == 1) lbl_8055EEE0 = 0; }
        else {
            lbl_8055EEE0 = (*(volatile long *)&lbl_8055EEE0) + arg0;
            if (lbl_8055EEE0 < 0) lbl_8055EEE0 = -2;
            if (lbl_8055EEE0 > digit) lbl_8055EEE0 = digit;
        }
    }
    if (old != lbl_8055EEE0) fn_8020FE90();
}

 
void fn_8021031C(void) {
    long type;
    char *buffer;
    type = 0x546D7573;
    buffer = lbl_80489CA0;
    memset(&lbl_80489CA0, 0, 0x6400);
    fn_802E6BD8(type, 0, buffer, 0x6400, 0);
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

extern long fn_80009C84(long);
extern signed char lbl_8055EEC0, lbl_8055EEC8, lbl_8055B660;
extern long lbl_8055EECC, lbl_8055B658;
void fn_80210444(void) {
    lbl_8055EEC0 = 0;
    lbl_8055B660 = 1;
    lbl_8055EEC8 = 0;
    lbl_8055EECC = 0;
    if (fn_80009C84(1) == 0 && fn_801B85CC() == 0 &&
        lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(1)) {
        lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(0);
        fn_802EC12C();
        fn_802EC1D8();
    }
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
    struct Fn80210904VTable { void *pad[2]; void (*call)(void *, long); };
    struct Fn80210904Object { struct Fn80210904VTable *vtable; };
    fn_80209110(&lbl_8055EEF0);
    if (lbl_8055EED4 != 0) {
        ((struct Fn80210904Object *)lbl_8055EED4)->vtable->call(
            (struct Fn80210904Object *)lbl_8055EED4, 1);
    }
    lbl_8055EED4 = 0;
}
 
extern void *lbl_8055EED8;
extern void *lbl_8055EEDC;
void AXFXSetHooks_80210950(void *arg0, void *arg1) {
    lbl_8055EED8 = arg0;
    lbl_8055EEDC = arg1;
}

extern long fn_8020FEF0(long);
extern long fn_802100AC(void);
extern long fn_80012158(void);
long fn_802111E4(long arg0) {
    switch (arg0) {
    case 0x126:
        fn_8020FFE4(-1);
        break;
    case 0x128:
        fn_8020FFE4(1);
        break;
    case 0x127:
        fn_8020FEF0(1);
        break;
    case 0x125:
        fn_8020FEF0(-1);
        break;
    case 0x53: {
        long (*hook)(long) = (long (*)(long))lbl_8055EED8;
        long value = (arg0 - 0x58) == 0;
        hook(value);
        fn_802100AC();
        break;
    }
    case 0x113:
    case 0x1B:
        break;
    default:
        return 0;
    }
    fn_80012158();
    return 1;
}

extern long fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206444(void);
extern void fn_80209190(long, float);
extern long __AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(long);
extern void *fn_8020FAF0(void);
extern long lbl_8033C970;
extern long lbl_8055B65C;
extern long lbl_8055B674;
extern signed char lbl_8055EEEC;
extern signed char lbl_8055EEED;
extern float lbl_80563400;
void fn_802113D8(void) {
    long mode;
    long n;
    long q;
    long r;
    long zero = 0;
    long minusTwo = -2;
    long *object;

    if (fn_80265D64() == 0) {
        __AXDSPInitCallback_801769E0();
    }
    fn_80206444();
    fn_80209190(lbl_8055EEF0, lbl_80563400);
    lbl_8055EEE4 = zero;
    lbl_8055EEE0 = minusTwo;
    lbl_8055B65C = lbl_8055B658;
    lbl_8055EEEC = zero;
    lbl_8055EEED = zero;
    object = (long *)fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC()) + 8;
    (*(void (**)(long *, long, long))(*(long **)object)[6])(object, (long)&lbl_8055B674, (long)&lbl_8033C970);
    mode = *(long *)fn_8020FAF0();
    if (mode == 1) {
        lbl_8055EEE0 = -1;
    } else if (mode == 2) {
        n = lbl_8055B658;
        if (n >= 0) {
            q = n / 10;
            r = n % 10;
            lbl_8055EEE4 = q;
            lbl_8055EEE0 = r;
        }
    }
}

extern void fn_801345D8(void *, ...);
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

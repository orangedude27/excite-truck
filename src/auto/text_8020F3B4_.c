extern long fn_802EC104(long);
#pragma cplusplus on
struct Dummy_802113D8 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual long f6(long *, char *);
};
#pragma cplusplus off
extern long lbl_8055EEE0;
extern long lbl_8055EEE4;
extern long lbl_8055EEBC;
extern long lbl_8055EEE8;
extern long lbl_8055B658;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
  
extern void *fn_8020FAF0(void);
extern long fn_8000DA10(void);
extern long fn_8020F9F4(void);
extern int stricmp(const char *, const char *);
extern struct Unk_804900AC { long *m_entries; long m_count; long m_capacity; } lbl_804900AC;
extern void fn_801345D8(void *, ...);
extern long lbl_8055B664;
extern signed char lbl_8055EEF4;
extern signed char lbl_8055EEF5;
extern signed char lbl_8055EEF6;
extern char lbl_804904D0[];
extern char lbl_8033C95C[];
extern long *lbl_8055B650;
extern long *lbl_8055B654;
extern int fn_8012E938(int);
extern void fn_8012E81C(void);
extern long fn_802EC294(long, long);
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
extern long __AXFXGetLfoSinTable_801769CC();
extern long lbl_8055B674;
extern char lbl_8033C970[];
extern char lbl_8033C980[];
extern void *fn_8001285C(long);
extern void fn_802E30C8(const char *, ...);
extern void fn_802EC1D8(void);
extern float lbl_80563400;
extern void fn_802EC1C0();
extern void fn_802EC1E4();
extern long fn_802EC12C();
extern long fn_802EC0FC(void);
long fn_8020F3B4(void) { return -1; }
 
int fn_8020F3BC(int arg0, int arg1, int arg2) {
    int result = arg1;
    ((void (*)(int, int, int *, int))fn_801345D8)(arg1, arg2, (int *)&lbl_8055B664, arg0);
    return result;
}

#pragma scheduling invalid_target
long fn_8020F400(long arg0, long arg1, long arg2) {
    long result = arg1;
    ((void (*)(long, long, long *, long))fn_801345D8)(arg1, arg2, (long *)&lbl_8055B664, arg0);
    return result;
}

#pragma dont_inline on
void fn_8020F444(void) {
    char temp[0x40];
    if ((unsigned char)lbl_8055EEF4 == 0) {
        if (fn_8012E938(fn_8020F400((long)lbl_804904D0, (long)temp, 0x40)) != 0) {
            fn_8020F400((long)lbl_804904D0, (long)temp, 0x40);
            fn_8012E81C();
            fn_802EC294(0, fn_8020F3BC((int)lbl_804904D0, (int)temp, 0x40));
            fn_802E30C8(lbl_8033C95C, temp);
            lbl_8055EEF4 = 1;
        }
    }
    if ((unsigned char)lbl_8055EEF5 == 0) {
        if (fn_8012E938(fn_8020F400((long)lbl_8055B650, (long)temp, 0x40)) != 0) {
            fn_8020F400((long)lbl_8055B650, (long)temp, 0x40);
            fn_8012E81C();
            fn_802EC294(1, fn_8020F3BC((int)lbl_8055B650, (int)temp, 0x40));
            fn_802E30C8(lbl_8033C95C, temp);
            lbl_8055EEF5 = 1;
        }
    }
    if ((unsigned char)lbl_8055EEF6 == 0) {
        if (fn_8012E938(fn_8020F400((long)lbl_8055B654, (long)temp, 0x40)) != 0) {
            fn_8020F400((long)lbl_8055B654, (long)temp, 0x40);
            fn_8012E81C();
            fn_802EC294(2, fn_8020F3BC((int)lbl_8055B654, (int)temp, 0x40));
            fn_802E30C8(lbl_8033C95C, temp);
            lbl_8055EEF6 = 1;
        }
    }
}
#pragma dont_inline reset

#pragma scheduling on
 
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
 
#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_8020F5F0(long arg0) {
    long offset = (arg0 << 6) * 100;
    return (void *)((char *)&lbl_80489CA0 + offset);
}
#pragma scheduling on
#pragma dont_inline reset
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
    return 0;
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
 
#pragma dont_inline on
long fn_8020F6FC(void) {
    long index = lbl_8055EEC4;
    long *entries = lbl_804902C4.m_entries;
    long count = lbl_804902C4.m_count;
    long value = entries[index];
    lbl_8055EEC4 = (index + 1) % count;
    return value;
}
#pragma dont_inline reset

void fn_8020F730(void) {
    long i;
    long count = lbl_804900AC.m_count;
    long *entries = lbl_804902C4.m_entries;
    lbl_804902C4.m_count = 0;
    for (i = 0; i < count; i++) {
        entries[lbl_804902C4.m_count++] = i;
    }
    for (i = 0; i < lbl_804902C4.m_count; i++) {
        long index = fn_80129D18(6);
        long temp = entries[i];
        entries[i] = entries[index];
        entries[index] = temp;
    }
    lbl_8055EEC4 = 0;
}

#pragma use_lmw_stmw off
void fn_8020F950(void) {
    long capacity;
    long limit;
    long i;
    long index;
    long value;
    long *entries;
    capacity = lbl_804900AC.m_capacity;
    lbl_804900AC.m_count = 0;
    limit = ((long (*)(void *))fn_802EC0FC)(&lbl_804900AC);
    if (capacity < limit) {
        limit = capacity;
    }
    i = 0;
    while (i < limit) {
        value = fn_802EC104(i);
        index = lbl_804900AC.m_count;
        i++;
        entries = lbl_804900AC.m_entries;
        lbl_804900AC.m_count = index + 1;
        entries[index] = value;
    }
    fn_8020F730();
}

#pragma scheduling invalid_target
long fn_8020F9F4(void) {
    long i;
    char *base;

    fn_8000DA10();
    base = (char *)fn_8020F5F0(0);
    i = 0;
    do {
        if ((signed char)base[4] == 0) return i;
        i++;
        if ((signed char)base[0x68] == 0) return i;
        i++;
        if ((signed char)base[0xCC] == 0) return i;
        i++;
        if ((signed char)base[0x130] == 0) return i;
        i++;
        if ((signed char)base[0x194] == 0) return i;
        i++;
        if ((signed char)base[0x1F8] == 0) return i;
        i++;
        if ((signed char)base[0x25C] == 0) return i;
        i++;
        if ((signed char)base[0x2C0] == 0) return i;
        i++;
        base += 0x320;
    } while (i < 8);
    return 0;
}
#pragma scheduling on

#pragma use_lmw_stmw off
#pragma dont_inline on
int fn_8020FB80(void *arg0) {
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_804900AC.m_count) {
        if (fn_8002B1D8(*(char **)((char *)lbl_804900AC.m_entries + offset), (char *)arg0, 0x3F) == 0) {
            return i;
        }
        offset += 4;
        i++;
    }
    return ((int (*)(int))fn_8020F3B4)(0);
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma dont_inline on
void *fn_8020FC04(void) {
    char *data = (char *)fn_8020FAF0();
    long type;
    if (data == 0) {
        goto null_result;
    }
    type = *(long *)data;
    if (type == 0) {
        return (void *)0;
    }
    if (type == 1) {
        return (void *)lbl_804900AC.m_entries[fn_8020F6FC()];
    }
    return data + 0x24;
null_result:
    return 0;
}
#pragma dont_inline reset

extern int fn_8020FB80(void *);
#pragma scheduling invalid_target
void fn_8020FC6C(void) {
    volatile long *count;
    void *data;
    count = &lbl_804900AC.m_count;
    if (*count == 0) {
        ((long (*)(long))fn_8020F3B4)(0);
    } else {
        data = fn_8020FC04();
        if (data != 0) {
            fn_8020FB80(data);
        } else {
            ((long (*)(long))fn_8020F3B4)(0);
        }
    }
}

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8020FCC4(void) {
    long result;
    long index;
    long current;
    void *base;
    struct Dummy_802113D8 *object;

    base = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
    object = *(struct Dummy_802113D8 **)((char *)base + 0x20);
    result = object->f6(&lbl_8055B674, lbl_8033C970);
    index = ((long (*)(void))fn_8020FC6C)();
    if (index >= 0 && index < lbl_804900AC.m_count) {
        fn_802E30C8(lbl_8033C980, index, lbl_804900AC.m_entries[index], result);
    }
    if (index == ((long (*)(long))fn_8020F3B4)(0)) {
        if (lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(1)) {
            index = ((long (*)(long))fn_8020F3B4)(1);
        }
    }
    if (index == ((long (*)(long))fn_8020F3B4)(0)) {
        if (lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(2)) {
            index = ((long (*)(long))fn_8020F3B4)(2);
        }
    }
#pragma scheduling off
    current = lbl_8055B658;
    if (current != -1 && current != index) {
        fn_802EC1D8();
        lbl_8055B658 = index;
    }
#pragma scheduling on
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop

extern char *strncpy(char *, const char *, unsigned long);
void fn_8020FDE4(long arg0, const char *arg1, register char *arg2) {
    char *block;
    long remaining;
    char *dst;
    unsigned char value;

    block = (char *)((void *(*)(char *))fn_8020FAF0)(arg2);
    memset(block, 0, 4);
    *(long *)block = arg0;
    strncpy(block + 0x24, arg1, 0x3F);
    dst = block + 4;
    remaining = 0x20;
    do {
        remaining--;
        if (remaining <= 0) {
            dst[-1] = 0;
            return;
        }
        value = (unsigned char)*arg2;
        arg2++;
        *dst = value;
        dst++;
    } while ((signed char)value != 0);
}

#pragma dont_inline on
void fn_8020FE90(void) {
    long result;

    fn_802EC12C();
    fn_802EC1D8();
    if (lbl_8055EEE0 == -2) {
        lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(0);
        return;
    }
    if (lbl_8055EEE0 == -1) {
        result = fn_8020F6FC();
    } else {
        result = lbl_8055EEE0 + (lbl_8055EEE4 * 0xA);
    }
    lbl_8055B658 = result;
}

long fn_8020FEF0(long arg0) {
    long state = lbl_8055EEE0;
    long count;
    long pos;
    long max;

    if (state == -2) {
        count = lbl_8055EEBC;
        if (count > 0) {
            if (arg0 == 1) {
                lbl_8055EEE0 = -1;
                fn_8020FE90();
            }
            return;
        }
    }
    if (state == -1) {
        if (arg0 != -1) {
            return;
        }
        lbl_8055EEE0 = -2;
        fn_8020FE90();
        return;
    }

    pos = lbl_8055EEE4;
    max = lbl_8055EEE8 - 1;
    arg0 += pos;
    arg0 &= ((-arg0 & ~arg0) >> 31);
    if (arg0 < max) {
        max = arg0;
    }
    lbl_8055EEE4 = max;
    count = lbl_8055EEBC;
    if (pos == max) {
        return;
    }
    if (count == 0) {
        lbl_8055EEE0 = -2;
    } else if (state >= 0 && state + max * 10 >= count) {
        lbl_8055EEE0 = (count - 1) % 10;
    }
    if (lbl_8055EEE0 >= 0) {
        fn_8020FE90();
    }
}

#pragma dont_inline reset

#pragma scheduling on
extern long lbl_8055EEBC;
extern long lbl_8055EEE0;
extern long lbl_8055EEE4;
extern long lbl_8055EEE8;
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

extern long lbl_8055B67C;
extern signed char lbl_8055EEEC, lbl_8055EEED;
long fn_802100AC(void) {
    long state;
    long index;
    void *base;
    struct Dummy_802113D8 *object;

    fn_802EC12C();
    state = lbl_8055EEE0;
    if (state == -2) {
        base = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        object = *(struct Dummy_802113D8 **)((char *)base + 0x20);
        fn_8020FDE4(0, (const char *)&lbl_8055B67C,
                    (char *)object->f6(&lbl_8055B674, lbl_8033C970));
        if ((unsigned char)lbl_8055EEEC != 0) {
            fn_8020F608(0, fn_8000DA10());
        }
    } else if (state == -1) {
        base = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        object = *(struct Dummy_802113D8 **)((char *)base + 0x20);
        fn_8020FDE4(1, (const char *)&lbl_8055B67C,
                    (char *)object->f6(&lbl_8055B674, lbl_8033C970));
        if ((unsigned char)lbl_8055EEED != 0) {
            fn_8020F608(1, fn_8000DA10());
        }
    } else {
        index = state + lbl_8055EEE4 * 10;
        base = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        object = *(struct Dummy_802113D8 **)((char *)base + 0x20);
        fn_8020FDE4(2, (const char *)lbl_804900AC.m_entries[index],
                    (char *)object->f6(&lbl_8055B674, lbl_8033C970));
        lbl_8055B658 = index;
    }
}

extern float fn_80235EF0(long, long);
extern void fn_80147940(void *, void *, long, long);
#pragma cplusplus on
struct Dummy_802101F8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual long v4();
};
#pragma cplusplus reset
struct Record_802101F8 {
    long f0;
    long f4;
    long f8;
    long fC;
    float f10;
    float f14;
    long f18;
};
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_802101F8(Dummy_802101F8 *arg0, long arg1, long arg2, struct Record_802101F8 *arg3) {
    long temp_r31;
    struct Record_802101F8 rec;
    long i;

    if (arg0 == 0 || arg3 == 0) {
    } else {
        temp_r31 = arg0->v4();
        rec.f0 = arg3->f0;
        {
            long f4 = arg3->f4;
            long f8 = arg3->f8;
            rec.f4 = f4;
            rec.f8 = f8;
        }
        rec.fC = arg3->fC;
        rec.f10 = arg3->f10;
        rec.f14 = arg3->f14;
        rec.f18 = arg3->f18;
        for (i = 0; i < 3; i++) {
            long step = arg2 + i;
            if (i == 1) {
                float temp_f31 = fn_80235EF0(temp_r31, arg2 + 2);
                rec.f10 = (arg3->f10 - fn_80235EF0(temp_r31, arg2)) - temp_f31;
            } else {
                rec.f10 = fn_80235EF0(temp_r31, step);
            }
            fn_80147940(arg0, &rec, arg1, step);
            *(float *)&rec.f4 += rec.f10;
        }
    }
}
#pragma cplusplus reset
 
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
extern long fn_802EC12C(void);
extern void fn_8020FCC4(void);
extern char lbl_8033C9AC[];
extern long lbl_8055EED0;
#pragma scheduling invalid_target
void fn_8021037C(void) {
    lbl_8055EED0 = fn_80207848(lbl_8033C9AC, 1);
    fn_802EC1D8();
    fn_802EC12C();
    fn_8020FCC4();
}
#pragma scheduling on
void fn_802103B8(void) {
    fn_8020F5C8();
}

#pragma dont_inline on
void fn_802103BC(void) {
    struct VTable { void *pad[2]; void (*call)(void *, long); };
    struct Object { struct VTable *vtable; };
    fn_802EC1C0(lbl_80563400);
    fn_802EC12C();
    fn_802EC1E4();
    if (lbl_8055EED4 != 0) {
        ((struct Object *)lbl_8055EED4)->vtable->call((struct Object *)lbl_8055EED4, 1);
    }
    lbl_8055EED4 = 0;
    lbl_8055B658 = -1;
    fn_8020F5DC();
    if (lbl_8055EED0 != 0) {
        ((struct Object *)lbl_8055EED0)->vtable->call((struct Object *)lbl_8055EED0, 1);
    }
    lbl_8055EED0 = 0;
}
#pragma dont_inline reset
extern long fn_80009C84(long);
extern unsigned char lbl_8055EEC0;
extern signed char lbl_8055EEC8, lbl_8055B660;
extern long lbl_8055EECC, lbl_8055B658;
void fn_80210444(void) {
    register lbl_8055B660 = 1;
    lbl_8055EEC0 = 0;
    lbl_8055EEC8 = 0;
    lbl_8055EECC = 0;
    if (fn_80009C84(1) == 0 && fn_801B85CC() == 0 &&
        lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(1)) {
        lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(0);
        fn_802EC12C();
        fn_802EC1D8();
    }
}

long fn_802104B8(void) {
    return (unsigned long)((-1 - lbl_8055B658) | (lbl_8055B658 + 1)) >> 31;
}

long fn_802104D0(void) {
    return fn_802EC0FC() > 0;
}

long fn_802104FC(void) {
    return (lbl_8055B658 + 1) == 0;
}

 
void fn_80210510(void) {
    fn_802EC1C0();
}

long fn_80210570(void) {
    long val = 3;
    char *ptr = (char *)fn_8020F5F0(fn_8000DA10());
    long i;

    for (i = 0; i < 48; i += 3) {
        if (val == 3) {
            val = *(long *)(ptr + 0x000);
        } else if (*(long *)(ptr + 0x000) != val) {
            return 2;
        }

        if (val == 3) {
            val = *(long *)(ptr + 0x064);
        } else if (*(long *)(ptr + 0x064) != val) {
            return 2;
        }

        if (val == 3) {
            val = *(long *)(ptr + 0x0C8);
        } else if (*(long *)(ptr + 0x0C8) != val) {
            return 2;
        }

        if (val == 3) {
            val = *(long *)(ptr + 0x12C);
        } else if (*(long *)(ptr + 0x12C) != val) {
            return 2;
        }

        ptr += 0x190;
    }

    switch (val) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 0;
    }
}

 
extern long fn_80145E70(void *);
extern long fn_802090D4(void *);
extern long fn_80209110(void *);
#pragma cplusplus on
struct Dummy_80210904 {
      virtual void f1(long);
  };
#pragma cplusplus off
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
 
#pragma cplusplus on
extern "C" void fn_80210904(void) {
    fn_80209110(&lbl_8055EEF0);
    struct Dummy_80210904 *obj = (struct Dummy_80210904 *)lbl_8055EED4;
    if (obj != 0) {
        obj->f1(1);
    }
    lbl_8055EED4 = 0;
}
#pragma cplusplus off
extern void *lbl_8055EED8;
extern void *lbl_8055EEDC;
void AXFXSetHooks_80210950(void *arg0, void *arg1) {
    lbl_8055EED8 = arg0;
    lbl_8055EEDC = arg1;
}

extern long fn_8020FEF0(long);
extern long fn_802100AC(void);
extern long fn_80012158(void);
#pragma scheduling invalid_target
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
    case 0x53:
        ((long (* volatile)(long))lbl_8055EED8)((arg0 - 0x58) == 0);
        fn_802100AC();
        break;
    case 0x113:
    case 0x1B:
        break;
    default:
        return 0;
    }
    fn_80012158();
    return 1;
}

void fn_802112AC(void) {
    long mode;
    long n;
    long quotient;
    long remainder;
    long count;
    void *base;
    struct Dummy_802113D8 *object;

    if (lbl_8055EEC0 != 0) {
        lbl_8055EEE0 = -2;
        if (lbl_8055EEBC > 0) {
            fn_8020FCC4();
            base = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
            object = *(struct Dummy_802113D8 **)((char *)base + 0x20);
            object->f6(&lbl_8055B674, lbl_8033C970);
            mode = *(long *)fn_8020FAF0();
            if (mode == 1) {
                lbl_8055EEE0 = -1;
            } else if (mode == 2) {
                n = lbl_8055B658;
                if (n >= 0) {
                    quotient = n / 10;
                    remainder = n % 10;
                    lbl_8055EEE4 = quotient;
                    lbl_8055EEE0 = remainder;
                }
            }
        }
    }
    count = lbl_8055EEBC / 10;
    lbl_8055EEE8 = count;
    if ((lbl_8055EEBC % 10) != 0 || lbl_8055EEBC == 0) {
        count++;
        lbl_8055EEE8 = count;
    }
    if (lbl_8055EEE4 >= count) {
        lbl_8055EEE4 = 0;
    }
}

#pragma scheduling on
extern long fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206444(void);
extern void fn_80209190(long, float);
extern long __AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(long);
extern void *fn_8020FAF0(void);
extern char lbl_8033C970[];
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
    void *base;
    struct Dummy_802113D8 *object;

    if (fn_80265D64() == 0) {
        __AXDSPInitCallback_801769E0();
    }
    fn_80206444();
    fn_80209190(lbl_8055EEF0, lbl_80563400);
    lbl_8055EEE0 = minusTwo;
    lbl_8055EEE4 = zero;
    lbl_8055B65C = lbl_8055B658;
    lbl_8055EEEC = zero;
    lbl_8055EEED = zero;
    base = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
    object = *(struct Dummy_802113D8 **)((char *)base + 0x20);
    object->f6(&lbl_8055B674, lbl_8033C970);
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

extern float lbl_80563404;
extern void fn_80206454(void);
extern void fn_801769EC(void);
#pragma scheduling invalid_target
void fn_802114C4(void) {
    ((void (*)(float, long))fn_80209190)(lbl_80563404, lbl_8055EEF0);
    fn_80206454();
    fn_801769EC();
}
#pragma scheduling on
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
#pragma dont_inline on

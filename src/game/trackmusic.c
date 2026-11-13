// trackmusic — track music ("TrackMusic: Found song", TrkMusDash).
// Recovered TU window 0x8020F3B4..0x802114F4+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802114F4 (+ .ctors slot 0x802ED3A8) remains in
// auto/text_802114F4_.c pending a promotion pass.
extern char *fn_802EC104(long);  // path of entry i of the dash's scanned music table
#pragma cplusplus on
struct Dummy_802113D8 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual long f6(long *, char *);
};
struct Dummy10688 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void *, void *);
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
// Track-music file list: m_entries is an array of m_count char* song paths
// (fn_8020F950 fills it from the dash's scanned music table), m_capacity is how
// many of them fit in the buffer.
extern struct TrackMusicList { char **m_entries; long m_count; long m_capacity; } lbl_804900AC;
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
 
#pragma scheduling invalid_target
int fn_8020F3BC(int arg0, int arg1, int arg2) {
    fn_801345D8((void *)arg1, arg2, (void *)&lbl_8055B664, arg0);
    return arg1;
}
#pragma scheduling on
extern long lbl_8055B66C;
int fn_8020F400(int arg0, int arg1, int arg2) {
    fn_801345D8((void *)arg1, arg2, (void *)&lbl_8055B66C, arg0);
    return arg1;
}

#pragma dont_inline on
void fn_8020F444(void) {
    /* Load and register track music paths into three slots once each, logging the loaded path. */
    char pathBuffer[0x40];
    if ((unsigned char)lbl_8055EEF4 == 0) {
        if (fn_8012E938(fn_8020F400((long)lbl_804904D0, (long)pathBuffer, 0x40)) != 0) {
            fn_8020F400((long)lbl_804904D0, (long)pathBuffer, 0x40);
            fn_8012E81C();
            fn_802EC294(0, fn_8020F3BC((int)lbl_804904D0, (int)pathBuffer, 0x40));
            fn_802E30C8(lbl_8033C95C, pathBuffer);
            lbl_8055EEF4 = 1;
        }
    }
    if ((unsigned char)lbl_8055EEF5 == 0) {
        if (fn_8012E938(fn_8020F400((long)lbl_8055B650, (long)pathBuffer, 0x40)) != 0) {
            fn_8020F400((long)lbl_8055B650, (long)pathBuffer, 0x40);
            fn_8012E81C();
            fn_802EC294(1, fn_8020F3BC((int)lbl_8055B650, (int)pathBuffer, 0x40));
            fn_802E30C8(lbl_8033C95C, pathBuffer);
            lbl_8055EEF5 = 1;
        }
    }
    if ((unsigned char)lbl_8055EEF6 == 0) {
        if (fn_8012E938(fn_8020F400((long)lbl_8055B654, (long)pathBuffer, 0x40)) != 0) {
            fn_8020F400((long)lbl_8055B654, (long)pathBuffer, 0x40);
            fn_8012E81C();
            fn_802EC294(2, fn_8020F3BC((int)lbl_8055B654, (int)pathBuffer, 0x40));
            fn_802E30C8(lbl_8033C95C, pathBuffer);
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
    long i = 2;
    char *ptr;
    ptr = (char *)fn_8020F5F0(arg1);
    memset(ptr, 0, 0x1900);
loop:
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
    if (--i != 0) goto loop;
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

#pragma use_lmw_stmw off
void fn_8020F730(void) {
    long count = lbl_804900AC.m_count;
    long i;
    lbl_804902C4.m_count = 0;
    if (count != 0) {
        for (i = 0; i < count; i++) {
            long index = lbl_804902C4.m_count;
            lbl_804902C4.m_count = index + 1;
            lbl_804902C4.m_entries[index] = i;
        }
        for (i = 0; i < lbl_804902C4.m_count; i++) {
            long index = fn_80129D18(6);
            long *e = lbl_804902C4.m_entries;
            long temp = e[i];
            e[i] = e[index];
            e[index] = temp;
        }
    }
    lbl_8055EEC4 = 0;
}
#pragma use_lmw_stmw reset
void fn_8020F950(void) {
    /* Rebuild the track-music list from the dash's scanned music table - one
       path per scanned song, as many as the list's buffer holds - and rebuild
       the shuffled play order from the new count. */
    long capacity;
    long limit;
    long i;
    long index;
    char *path;
    char **entries;
    capacity = lbl_804900AC.m_capacity;
    lbl_804900AC.m_count = 0;
    limit = ((long (*)(struct TrackMusicList *))fn_802EC0FC)(&lbl_804900AC);
    if (capacity < limit) {
        limit = capacity;
    }
    i = 0;
    while (i < limit) {
        path = fn_802EC104(i);
        index = lbl_804900AC.m_count;
        i++;
        entries = lbl_804900AC.m_entries;
        lbl_804900AC.m_count = index + 1;
        entries[index] = path;
    }
    fn_8020F730();
}

#pragma scheduling invalid_target
long fn_8020F9F4(void) {
    char *groupBase;
    long slotIndex;
    long group;
    long nextIndex0;
    long nextIndex1;
    long nextIndex2;
    long nextIndex3;
    long nextIndex4;
    long nextIndex5;
    long nextIndex6;

    /* Return the index of the first free track-music slot in the current context's 8x8 table, or 0 if none are free. */
    groupBase = (char *)fn_8020F5F0(fn_8000DA10());
    slotIndex = 0;
    for (group = 0; group < 8; group++) {
        if ((signed char)groupBase[4] == 0) {
            return slotIndex;
        }
        nextIndex0 = slotIndex + 1;
        if ((signed char)groupBase[0x68] == 0) {
            return nextIndex0;
        }
        nextIndex1 = nextIndex0 + 1;
        if ((signed char)groupBase[0xCC] == 0) {
            return nextIndex1;
        }
        nextIndex2 = nextIndex1 + 1;
        if ((signed char)groupBase[0x130] == 0) {
            return nextIndex2;
        }
        nextIndex3 = nextIndex2 + 1;
        if ((signed char)groupBase[0x194] == 0) {
            return nextIndex3;
        }
        nextIndex4 = nextIndex3 + 1;
        if ((signed char)groupBase[0x1F8] == 0) {
            return nextIndex4;
        }
        nextIndex5 = nextIndex4 + 1;
        if ((signed char)groupBase[0x25C] == 0) {
            return nextIndex5;
        }
        nextIndex6 = nextIndex5 + 1;
        if ((signed char)groupBase[0x2C0] == 0) {
            return nextIndex6;
        }
        groupBase += 0x320;
        slotIndex = nextIndex6 + 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline on
void *fn_8020FAF0(void) {
    char *entry;
    char *base = (char *)fn_8020F5F0(fn_8000DA10());
    long i = 0;
    entry = base;
    for (;;) {
        if (stricmp(entry + 4, entry) == 0) {
            return base + i * 0x64;
        }
        i++;
        entry += 0x64;
        if (i >= 0x40) break;
    }
    return base + fn_8020F9F4() * 0x64;
}
#pragma dont_inline reset
#pragma pop

#pragma scheduling on

#pragma use_lmw_stmw off
#pragma dont_inline on
/* Find the index of a track-music entry matching the given name, or -1 if not found. */
int fn_8020FB80(void *name) {
    int entryOffset;
    int index;
    index = 0;
    entryOffset = 0;
    while (index < lbl_804900AC.m_count) {
        if (fn_8002B1D8(*(char **)((char *)lbl_804900AC.m_entries + entryOffset), (char *)name, 0x3F) == 0) {
            return index;
        }
        entryOffset += 4;
        index++;
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
long fn_8020FC6C(void) {
    extern int fn_8020FB80(void *);
    extern void *fn_8020FC04(void);
    extern long fn_8020F3B4();
    long count = lbl_804900AC.m_count;
    void *p;
    if (count == 0) {
        return ((long (*)(long))fn_8020F3B4)(0);
    }
    p = fn_8020FC04();
    if (p != 0) {
        return ((int (*)(void *))fn_8020FB80)(p);
    } else {
        return ((long (*)(long))fn_8020F3B4)(0);
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
    current = lbl_8055B658;
    if (current != -1 && current != index) {
        fn_802EC1D8();
        lbl_8055B658 = index;
    }
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
    while (1) {
        remaining--;
        if (remaining <= 0) {
            dst[-1] = 0;
            return;
        }
        value = (unsigned char)*arg2;
        arg2++;
        *dst = value;
        dst++;
        if ((signed char)value == 0) {
            return;
        }
    }
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
    long tmp;

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
    tmp = pos + arg0;
    tmp &= ((-tmp & ~tmp) >> 31);
    if (tmp < max) {
        max = tmp;
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
/* Adjusts the track-music digit selection state by delta, clamping to valid range and refreshing on change. */
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
    long trackState;
    long trackIndex;
    void *container;
    struct Dummy_802113D8 *resource;

    /* Selects/prepares track music entry based on lbl_8055EEE0 state and updates related globals. */
    fn_802EC12C();
    trackState = lbl_8055EEE0;
    if (trackState == -2) {
        container = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        resource = *(struct Dummy_802113D8 **)((char *)container + 0x20);
        fn_8020FDE4(0, (const char *)&lbl_8055B67C,
                    (char *)resource->f6(&lbl_8055B674, lbl_8033C970));
        if ((unsigned char)lbl_8055EEEC != 0) {
            fn_8020F608(0, fn_8000DA10());
        }
    } else if (trackState == -1) {
        container = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        resource = *(struct Dummy_802113D8 **)((char *)container + 0x20);
        fn_8020FDE4(1, (const char *)&lbl_8055B67C,
                    (char *)resource->f6(&lbl_8055B674, lbl_8033C970));
        if ((unsigned char)lbl_8055EEED != 0) {
            fn_8020F608(1, fn_8000DA10());
        }
    } else {
        trackIndex = trackState + lbl_8055EEE4 * 10;
        container = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        resource = *(struct Dummy_802113D8 **)((char *)container + 0x20);
        fn_8020FDE4(2, (const char *)lbl_804900AC.m_entries[trackIndex],
                    (char *)resource->f6(&lbl_8055B674, lbl_8033C970));
        lbl_8055B658 = trackIndex;
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
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_802101F8(Dummy_802101F8 *arg0, long arg1, long arg2, struct Record_802101F8 *arg3) {
    long temp_r31;
    struct Record_802101F8 rec;
    long i;
    if (arg0 == 0) goto exit;
    if (arg3 != 0) goto body;
    goto exit;
body:
    temp_r31 = arg0->v4();
    rec.f0 = arg3->f0;
    {
        long f4;
        long f8;
        f4 = arg3->f4;
        f8 = arg3->f8;
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
exit:
    return;
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

#pragma push
#pragma cplusplus on
#pragma dont_inline on
extern "C" void fn_802103BC(void) {
    class Obj { public: virtual void f(int); };
    float f = lbl_80563400;
    fn_802EC1C0(f);
    fn_802EC12C();
    fn_802EC1E4();
    if (lbl_8055EED4 != 0) {
        ((Obj *)lbl_8055EED4)->f(1);
    }
    lbl_8055EED4 = 0;
    lbl_8055B658 = -1;
    fn_8020F5DC();
    if (lbl_8055EED0 != 0) {
        ((Obj *)lbl_8055EED0)->f(1);
    }
    lbl_8055EED0 = 0;
}
#pragma dont_inline reset
#pragma cplusplus off
#pragma pop
extern long fn_80009C84(void);
extern unsigned char lbl_8055EEC0;
extern signed char lbl_8055EEC8, lbl_8055B660;
extern long lbl_8055EECC, lbl_8055B658;
void fn_80210444(void) {
    lbl_8055B660 = 1;
    lbl_8055EEC0 = 0;
    lbl_8055EEC8 = 0;
    lbl_8055EECC = 0;
    if (fn_80009C84() == 0 && fn_801B85CC() == 0 &&
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

void fn_80210514(int x){switch(x){case 0: fn_8020F608(0,fn_8000DA10()); break; case 1: fn_8020F608(1,fn_8000DA10()); break; case 2: break;}}

long fn_80210570(void) {
    register long val = 3;
    char *ptr = (char *)fn_8020F5F0(fn_8000DA10());
    register long i;
    long k;
    for (i = 0; i < 48; i += 3) {
        for (k = 0; k < 1; k++) {
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

void fn_80210688(unsigned char arg0) {
    long tmp;
    long tmp2;
    long r30;
    long r29;
    long late;
    struct Dummy_802113D8 *obj;
    if ((unsigned char)lbl_8055EEF4 == 0 || (unsigned char)lbl_8055EEF5 == 0 || (unsigned char)lbl_8055EEF6 == 0) {
        fn_8020F444();
    }
    tmp = fn_802EC0FC();
    if (tmp != lbl_8055EEBC) {
        fn_802EC12C();
        fn_8020F950();
        fn_8020FCC4();
        lbl_8055EEC0 = 1;
    } else {
        lbl_8055EEC0 = 0;
    }
    lbl_8055EEBC = tmp;
    r30 = 0;
    if (fn_800216D0() != 0 && fn_80009C84() == 0) {
        r30 = 1;
    }
    r29 = 1;
    if (fn_801B85CC() == 0 && fn_80009C84() == 0) {
        r29 = 0;
    }
    if (lbl_8055B658 != -1) {
        if (lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(0) && r30 != 0) {
            lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(2);
            fn_802EC12C();
            fn_802EC1D8();
        } else if (lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(2) && r30 == 0) {
            lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(0);
            fn_802EC12C();
            fn_802EC1D8();
        } else if (lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(0) && r29 != 0) {
            lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(1);
            fn_802EC12C();
            fn_802EC1D8();
        }
        late = 0;
        if ((unsigned char)lbl_8055EEC8 != 0) {
            tmp2 = fn_802E2C20();
            if (tmp2 >= lbl_8055EECC && tmp2 < lbl_8055EECC + 0xFA0) {
                late = 1;
            }
        }
        if (fn_802EC124() == -1 && late == 0) {
            fn_802EC11C(lbl_8055B658);
            fn_802EC138();
            obj = *(struct Dummy_802113D8 **)((char *)fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC()) + 0x20);
            obj->f6(&lbl_8055B674, lbl_8033C970);
            if (*(long *)fn_8020FAF0() == 1 && lbl_8055EEBC > 0) {
                lbl_8055B658 = fn_8020F6FC();
            }
        }
        if ((unsigned char)lbl_8055B660 != arg0) {
            if (arg0 != 0) {
                fn_802EC158();
            } else {
                fn_802EC138();
            }
        }
        lbl_8055B660 = arg0;
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

void fn_8021095C(void) {
}

extern long fn_8020FEF0(long);
extern long fn_802100AC(void);
extern long fn_80012158(void);
#pragma scheduling invalid_target
long fn_802111E4(long keyCode) {
    /* Handle track-music menu key/input codes: navigate selection, invoke a
     * callback on confirm, refresh state, and return whether the key was handled. */
    switch (keyCode) {
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
        ((long (* volatile)(long))lbl_8055EED8)((keyCode - 0x58) == 0);
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
    long trackIndex;
    long quotient;
    long remainder;
    long trackCount;
    void *base;
    struct Dummy_802113D8 *object;

    /* Initialize track selection state and update display counters from current track data. */
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
                trackIndex = lbl_8055B658;
                if (trackIndex >= 0) {
                    quotient = trackIndex / 10;
                    remainder = trackIndex % 10;
                    lbl_8055EEE4 = quotient;
                    lbl_8055EEE0 = remainder;
                }
            }
        }
    }
    trackCount = lbl_8055EEBC / 10;
    lbl_8055EEE8 = trackCount;
    if ((lbl_8055EEBC % 10) != 0 || lbl_8055EEBC == 0) {
        trackCount++;
        lbl_8055EEE8 = trackCount;
    }
    if (lbl_8055EEE4 >= trackCount) {
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
    long trackIndex;
    long pageIndex;
    long digitIndex;
    long zero = 0;
    long minusTwo = -2;
    void *container;
    struct Dummy_802113D8 *resource;

    /* Initializes track-music selection state, refreshes the current track resource, and decodes the saved track index into page/digit selection. */
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
    container = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
    resource = *(struct Dummy_802113D8 **)((char *)container + 0x20);
    resource->f6(&lbl_8055B674, lbl_8033C970);
    mode = *(long *)fn_8020FAF0();
    if (mode == 1) {
        lbl_8055EEE0 = -1;
    } else if (mode == 2) {
        trackIndex = lbl_8055B658;
        if (trackIndex >= 0) {
            pageIndex = trackIndex / 10;
            digitIndex = trackIndex % 10;
            lbl_8055EEE4 = pageIndex;
            lbl_8055EEE0 = digitIndex;
        }
    }
}

extern float lbl_80563404;
extern void fn_80206454(void);
extern void fn_801769EC(void);
#pragma scheduling on
void fn_802114C4(void) {
    float value = lbl_80563404;
    fn_80209190(lbl_8055EEF0, value);
    fn_80206454();
    fn_801769EC();
}
extern void fn_801345D8(void *, ...);
extern long lbl_8055B664;
extern signed char lbl_8055EEF4;
extern signed char lbl_8055EEF5;
extern signed char lbl_8055EEF6;
// Code of main that had no source file yet: decomp.wtf gave it this one.
 // split_file divides it into the game's real files (file_status shows its range).

extern void fn_8020F730(void);
extern long fn_8020F9F4(void);
extern int stricmp(const char *, const char *);
extern int fn_8002B1D8(const char *, const char *, int);

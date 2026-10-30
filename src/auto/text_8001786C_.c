typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
typedef struct Unk18440 {
    s32 unk_0x00;
    s32 unk_0x04[8];
    s32 unk_0x24;
    s32 unk_0x28[8];
} Unk18440;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* fn_80016544(s32);
extern void fn_802E30C8(const char*, ...);
extern s32 fn_8013C8E8(s32);
extern const char lbl_802FD088[];
extern s32 fn_800168B0(s32, s32);
extern s32 fn_800167F4(void);
extern void* fn_800167B8(s32);
extern void* fn_80016510(s32);
extern void fn_8001786C(s32);
extern char lbl_8055D564;
extern void* lbl_8055D560;
s32 atoi(void);
#pragma scheduling invalid_target
void fn_8001786C(s32 arg0) {
    void* object;
    object = (void*)((char*)fn_80016544(arg0) + 0x2C);
    if (fn_8013C8E8((s32)object) == 6) {
        fn_802E30C8(lbl_802FD088, object);
    }
}

void fn_800178BC(void* arg0, s32 arg1, s32 arg2) {
    s32 index1;
    s32 index2;
    index1 = *(s32*)arg0;
    *(s32*)((char*)arg0 + (index1 << 2) + 4) = arg1;
    index2 = *(s32*)((char*)arg0 + 0x24);
    *(s32*)arg0 = index1 + 1;
    *(s32*)((char*)arg0 + (index2 << 2) + 0x28) = arg2;
    *(s32*)((char*)arg0 + 0x24) = index2 + 1;
}
#pragma scheduling on
int fn_800178F0(void) { return 0; }

void fn_800178F8(s32 arg0, s32 arg1) {
    void* temp = fn_80016544(arg1);
    volatile s32* pIndex = (volatile s32*)((char*)temp + 0x94);
    s32 index = *pIndex;
    fn_800168B0(arg0, *(s32*)((char*)temp + index * 4 + 0x64));
}

#pragma use_lmw_stmw off
#pragma dont_inline on
/* Match note: register count, index, id, and kind as r31-r28; disable lmw/stmw and auto-inlining to preserve the target save sequence and helper calls. */
void fn_80017944(s32 *arg0) {
    register s32 count;
    register s32 i;
    register s32 id;
    register s32 kind;
    void *object;
    void *resource;

    count = fn_800167F4();
    *(s32 *)((char *)arg0 + 0x24) = 0;
    i = 0;
    *(s32 *)arg0 = 0;
    for (; i < count; i++) {
        object = fn_800167B8(i);
        id = *(s32 *)((char *)object + 4);
        resource = fn_80016510(*(s32 *)((char *)object + 0x4C));
        kind = *(s32 *)((char *)resource + 4);
        fn_800178BC(arg0, id, kind);
        fn_8001786C(kind);
        if (fn_800178F0() != 0) {
            fn_800178F8(id, kind);
        }
    }
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset

#pragma dont_inline on
s32 fn_800179E4(void *value, s32 array, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        if ((s32)value == *(s32 *)(array + i * 4)) return 1;
    }
    return 0;
}

s32 fn_80017A14(s32 arg0, s32 arg1) {
    return fn_800179E4((void *)arg0, arg1 + 0x28, *(s32 *)(arg1 + 0x24));
}

#pragma dont_inline off

extern s32 fn_800179E4(void *, s32, s32);
void fn_80017A20(void *arg0, s32 *arg1) {
    fn_800179E4(arg0, (s32)(arg1 + 1), arg1[0]);
}

extern void *fn_80016464(s32);
extern s32 fn_80016508(void);
extern void fn_80017AC8(void *);
#pragma scheduling invalid_target
void fn_80017A2C(void *arg0, s32 arg1) {
    s32 i = 0;
    s32 *p = (s32 *)(arg1 + 4);
    while (i < fn_80016508()) {
        void *obj = fn_80016464(i);
        if (!*p) {
            s32 n = *(s32 *)((char *)arg0 + 4);
            *(s32 *)((char *)arg0 + 4) = n + 1;
            *(s32 **)((char *)*(s32 *)arg0 + n * 4) = obj;
        }
        i++;
    }
    fn_80017AC8(arg0);
}
#pragma scheduling on
void fn_80017AC8(void* arg0) {
    s32 offset, i;
    register s32 count;
    extern s32 fn_80129D18(s32);
    i = 0;
    offset = 0;
    while (i < (count = *(s32*)((char*)arg0 + 4))) {
        s32 left;
        s32 right;
        s32* items;
        s32 index;
        index = fn_80129D18(1);
        items = *(s32**)arg0;
        i++;
        left = *(s32*)((char*)items + offset);
        right = items[index];
        *(s32*)((char*)items + offset) = right;
        offset += 4;
        items[index] = left;
    }
}

extern s32 fn_800165D4(void);
extern s32 fn_80017A14(s32, s32);
extern void fn_80017AC8(void*);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80017B40(void *arg0, s32 arg1) {
    register s32 i;
    register s32 a;
    register s32 b;
    register s32 skip;
    register unsigned long flags;
    register s32 bit2;
    register s32 bit3;
    register s32 n;
    register void **items;
    void *obj;

    i = 0;
    while (i < fn_800165D4()) {
        obj = fn_80016510(i);
        flags = *(unsigned long *)((char *)obj + 0xA0);
        skip = 0;
        a = *(s32 *)((char *)obj + 4);
        b = *(s32 *)((char *)obj + 8);
        bit2 = (flags >> 2) & 1;
        bit3 = (flags >> 3) & 1;
        if ((flags & 2) || bit2 || bit3) skip = 1;
        if (!skip && fn_80017A14(a, arg1) == 0 && fn_80017A14(b, arg1) == 0) {
            n = *(s32 *)((char *)arg0 + 4);
            items = *(void ***)arg0;
            *(s32 *)((char *)arg0 + 4) = n + 1;
            items[n] = (void *)a;
        }
        i++;
    }
    fn_80017AC8(arg0);
}
extern void *fn_80016510(s32);
extern void *fn_80016474(s32);
extern void fn_80017D5C(void *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80017C18(void *arg0, s32 *arg1) {
    register s32 i;
    register s32 n;
    register void *object;
    register void *cursor;
    register s32 *items;
    s32 j;
    s32 found;
    s32 offset;
    register s32 *entry;

    object = fn_80016510(0);
    cursor = object;
    i = 0;
    do {
        n = *(s32 *)((char *)arg0 + 4);
        i++;
        items = *(s32 **)arg0;
        *(s32 *)((char *)arg0 + 4) = n + 1;
        items[n] = *(s32 *)((char *)cursor + 0x64);
        cursor = (char *)cursor + 4;
    } while (i < *(s32 *)((char *)object + 0x98));

    entry = arg1;
    i = 0;
    while (i < arg1[0]) {
        object = fn_80016474(entry[1]);
        n = *(s32 *)((char *)arg0 + 4);
        j = 0;
        offset = 0;
        found = -1;
        while (j < n) {
            if (*(void **)((char *)object + 0x50) == *(void **)(*(s32 **)arg0 + offset / 4)) {
                found = j;
                break;
            }
            offset += 4;
            j++;
        }
        if (found == -1) {
            found = -1;
        }
        if (found < 0) {
        } else if (found < n) {
            if (found != n - 1) {
                items = *(s32 **)arg0;
                items[found] = items[n - 1];
            }
            *(s32 *)((char *)arg0 + 4) = n - 1;
        }
        entry++;
        i++;
    }
    fn_80017D5C(arg0);
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma scheduling on
extern void fn_80017A2C(void *, s32);
extern void fn_800178BC(void *, s32, s32);
extern void fn_80016928(s32, s32);
#pragma scheduling invalid_target
void fn_80017DD4(s32 *arg0, s32 arg1, s32 *arg2) {
    struct { s32 *items; s32 count; s32 capacity; s32 buf[50]; } a, b, c;
    s32 i, x, y, z;
    *(s32 *)((char *)arg0 + 0x24) = 0;
    *arg0 = 0;
    if (arg1 > 0) {
        a.items = a.buf; a.count = 0; a.capacity = 50;
        fn_80017A2C(&a, (s32)arg2);
        b.capacity = 50; b.items = b.buf; b.count = 0;
        fn_80017B40(&b, (s32)arg2);
        c.capacity = 50; c.items = c.buf; c.count = 0;
        fn_80017C18(&c, arg2);
        for (i = 0; i < arg1; i++) {
            x = a.items[i % a.count];
            y = b.items[i % b.count];
            z = c.items[i % c.count];
            fn_800178BC(arg0, x, y);
            if (fn_800178F0()) fn_800178F8(x, y);
            else fn_80016928(x, z);
        }
        c.items = 0; c.count = 0; c.capacity = 0;
        b.items = 0; b.count = 0; b.capacity = 0;
        a.items = 0; a.count = 0; a.capacity = 0;
    }
}
#pragma scheduling reset
s32 fn_80017F40(void) {
    return fn_800167F4() == 1;
}

extern void* fn_80012820(s32);
extern void* fn_80012870(s32, s32);
extern s32 fn_80017F40(void);
#pragma scheduling invalid_target
#pragma dont_inline on
s32 fn_80017F6C(s32 arg0) {
    s32 temp, max, i;
    void *obj;
    if ((s32)lbl_8055D560 != 0) {
        temp = fn_800167F4();
        max = (s32)lbl_8055D560;
        if (temp > max) max = temp;
        return max;
    }
    if (fn_80017F40() == 0) return fn_800167F4();
    max = 0;
    obj = fn_80012820(arg0);
    i = 0;
    while (i < *(s32*)((char*)obj + 0x70)) {
        temp = *(s32*)((char*)fn_80012870(arg0, i) + 0x10);
        if (temp > max) max = temp;
        i++;
    }
    return max;
}
#pragma dont_inline off
#pragma scheduling on
extern void* fn_8001668C(void*, s32);
extern const char lbl_802FD0C8[];
extern const char lbl_802FD0D8[];
extern const char lbl_80357DC0[];
#pragma cplusplus on
extern "C" void fn_80018030(void *arg0, s32 arg1) {
    struct V {
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual char *m4(const char *, const char *);
    };
    struct H {
        char pad[0x80];
        V *iface;
    };
    char *str;
    s32 i;
    H *obj = (H *)fn_80012820(arg1);
    str = obj->iface->m4(lbl_802FD0C8, lbl_80357DC0);
    if (str != 0 && (signed char)*str != 0) {
        fn_802E30C8(lbl_802FD0D8, str);
        for (i = 0; i < *(s32 *)((char *)arg0 + 0x24); i++) {
            *(s32 *)((char *)arg0 + i * 4 + 0x28) = *(s32 *)((char *)fn_8001668C(str, 0) + 4);
        }
    }
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_800180FC(void *arg0, s32 arg1) {
    struct V1 {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20();
        virtual void *get(const char *);
    };
    struct V2 {
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual char *get(const char *, void *);
    };
    struct H { char pad[0x80]; V1 *iface; };
    extern char lbl_80558C18;
    extern char lbl_80558C1C;
    extern void fn_801345D8(void *, s32, const char *, ...);
    extern int stricmp(const char *, const char *);
    register const char *strings;
    register s32 *out;
    register V2 *names;
    register char *typeName;
    register char *mapped;
    register s32 i;
    register s32 found;
    register s32 j;
    strings = lbl_802FD088;
    names = (V2 *)((H *)fn_80012820(arg1))->iface->get(strings + 0x74);
    if (names == 0) return;
    fn_802E30C8(strings + 0x80);
    typeName = names->get(strings + 0xB0, 0);
    mapped = names->get(strings + 0xC0, 0);
    out = (s32 *)arg0;
    for (i = 0; i < *(s32 *)((char *)arg0 + 0x24); out++, i++) {
        found = 0;
        for (j = 0; j < fn_800167F4(); j++) {
            if (*(s32 *)((char *)fn_800167B8(j) + 4) == out[1]) {
                found = 1;
                break;
            }
        }
        if (mapped != 0 && found != 0) {
            if (stricmp(mapped, &lbl_80558C18) != 0) {
                out[10] = *(s32 *)((char *)fn_8001668C(mapped, 0) + 4);
            }
        } else {
            char buffer[0x20];
            char *result;
            fn_801345D8(buffer, 0x20, &lbl_80558C1C, i + 1);
            result = names->get(buffer, typeName);
            if (stricmp(result, &lbl_80558C18) != 0) {
                out[10] = *(s32 *)((char *)fn_8001668C(result, 0) + 4);
            }
        }
    }
}
#pragma scheduling on
#pragma cplusplus reset

#pragma cplusplus reset
void fn_800182A0(void* arg0, void* arg1) {
    s32 index;
    s32 i;
    s32 value;

    for (i = 0; i < *(s32*)((char*)arg1); i++) {
        index = *(s32*)((char*)arg0);
        value = *(s32*)((char*)arg1 + i * 4 + 4);
        *(s32*)((char*)arg0 + index * 4 + 4) = value;
        *(s32*)((char*)arg0) = index + 1;
    }
    for (i = 0; i < *(s32*)((char*)arg1 + 0x24); i++) {
        index = *(s32*)((char*)arg0 + 0x24);
        value = *(s32*)((char*)arg1 + i * 4 + 0x28);
        *(s32*)((char*)arg0 + index * 4 + 0x28) = value;
        *(s32*)((char*)arg0 + 0x24) = index + 1;
    }
}

#pragma push
#pragma dont_inline on
void fn_80018318(void* arg0, s32 arg1) {
    s32 pad[17];
    s32 sp50;
    s32 sp8;
    s32 temp;
    extern void fn_8013C804(void);
    extern void fn_80017944(s32*);
    extern s32 fn_80017F6C(s32);
    extern void fn_80017DD4(s32*, s32, s32*);
    extern void fn_80018030(void*, s32);
    extern void fn_800180FC(void*, s32);
    extern void fn_8013C8B8(void);
    fn_8013C804();
    fn_80017944(&sp50);
    temp = fn_80017F6C(arg1) - sp50;
    fn_80017DD4(&sp8, temp & ~(temp >> 31), &sp50);
    memset(arg0, 0, 0x48);
    fn_800182A0(arg0, &sp8);
    fn_800182A0(arg0, &sp50);
    fn_80018030(arg0, arg1);
    fn_800180FC(arg0, arg1);
    fn_8013C8B8();
}
#pragma push
#pragma dont_inline on
s32 fn_800183C0(void *arg0) {
    s32 value;
    s32 best;

    if (lbl_8055D560 != 0) {
        value = fn_800167F4();
        best = (s32)lbl_8055D560;
        if (value > best) best = value;
        return best;
    }
    if (fn_80017F40() != 0) {
        value = fn_800167F4();
        best = *(s32 *)((char *)arg0 + 0x10);
        if (value > best) best = value;
    } else {
        best = fn_800167F4();
    }
    return best;
}
#pragma pop
extern void *fn_8001285C(s32);
#pragma push
#pragma dont_inline on
void fn_80018440(Unk18440 *arg0, s32 arg1, Unk18440 *arg2) {
    s32 count, i, n, m;
    count = fn_800183C0(fn_8001285C(arg1));
    memset(arg0, 0, 0x48);
    n = arg2->unk_0x00;
    m = arg2->unk_0x24;
    for (i = 0; i < count; i++) {
        arg0->unk_0x04[i] = arg2->unk_0x04[n - 1 - i];
        arg0->unk_0x00++;
        arg0->unk_0x28[i] = arg2->unk_0x28[m - 1 - i];
        arg0->unk_0x24++;
    }
}
#pragma pop

void fn_80018794(void) {
    lbl_8055D560 = (void*)atoi();
}

void fn_800187B8(const char* source) {
    int remaining = 0x40;
    volatile char* destination = (volatile char*)lbl_80357DC0;
    while ((*destination++ = *source++) != '\0') {
        if (--remaining > 0) {
            continue;
        }
        destination[-1] = '\0';
        return;
    }
}

void fn_800187F8(void) {
    lbl_8055D564 = 1;
}

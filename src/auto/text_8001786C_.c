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
extern s32 fn_800168B0(s32, s32);
extern s32 fn_800167F4(void);
extern void* fn_800167B8(s32);
extern void* fn_80016510(s32);
extern s32 fn_8001786C(s32);
extern char lbl_8055D564;
extern void* lbl_8055D560;
s32 atoi(void);
void fn_800178BC(void* arg0, s32 arg1, s32 arg2) {
    s32 index1;
    s32 index2;
    index1 = *(s32*)((char*)arg0);
    *(s32*)((char*)arg0 + index1 * 4 + 4) = arg1;
    index2 = *(s32*)((char*)arg0 + 0x24);
    *(s32*)((char*)arg0) = index1 + 1;
    *(s32*)((char*)arg0 + index2 * 4 + 0x28) = arg2;
    *(s32*)((char*)arg0 + 0x24) = index2 + 1;
}

int fn_800178F0(void) { return 0; }

void fn_800178F8(s32 arg0, s32 arg1) {
    void* temp = fn_80016544(arg1);
    volatile s32* pIndex = (volatile s32*)((char*)temp + 0x94);
    s32 index = *pIndex;
    fn_800168B0(arg0, *(s32*)((char*)temp + index * 4 + 0x64));
}

#pragma dont_inline on
s32 fn_800179E4(void *value, s32 array, s32 count) {
    while (count > 0) {
        if (value == *(void **)array) return 1;
        array += 4;
        count--;
    }
    return 0;
}
#pragma dont_inline off

extern s32 fn_800179E4(void *, s32, s32);
void fn_80017A20(void *arg0, s32 *arg1) {
    fn_800179E4(arg0, (s32)(arg1 + 1), arg1[0]);
}

void fn_80017AC8(void* arg0) {
    s32 offset, i;
    extern s32 fn_80129D18(s32);
    i = 0;
    offset = 0;
    while (i < *(s32*)((char*)arg0 + 4)) {
        s32 left;
        s32* items;
        s32 index;
        index = fn_80129D18(1);
        items = *(s32**)arg0;
        i++;
        left = *(s32*)((char*)items + offset);
        *(s32*)((char*)items + offset) = items[index];
        offset += 4;
        items[index] = left;
    }
    *(s32*)((char*)arg0 + 4);
}

extern s32 fn_800165D4(void);
extern s32 fn_80017A14(s32, s32);
extern void fn_80017AC8(void*);
#pragma dont_inline on
void fn_80017B40(void *arg0, s32 arg1) {
    s32 i = 0;
    while (i < fn_800165D4()) {
        void *obj = fn_80016510(i);
        unsigned long flags = *(unsigned long *)((char *)obj + 0xA0);
        s32 a = *(s32 *)((char *)obj + 4);
        s32 b = *(s32 *)((char *)obj + 8);
        s32 skip = 0;
        if ((flags & 2) || ((flags >> 2) & 1) || ((flags >> 3) & 1)) skip = 1;
        if (!skip && fn_80017A14(a, arg1) == 0 && fn_80017A14(b, arg1) == 0) {
            s32 n = *(s32 *)((char *)arg0 + 4);
            void **items = *(void ***)arg0;
            *(s32 *)((char *)arg0 + 4) = n + 1;
            items[n] = (void *)a;
        }
        i++;
    }
    fn_80017AC8(arg0);
}
#pragma dont_inline off
s32 fn_80017F40(void) {
    return fn_800167F4() == 1;
}

extern void* fn_80012820(s32);
extern void* fn_80012870(s32, s32);
extern s32 fn_80017F40(void);
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
extern void* fn_8001668C(void*, s32);
extern s32 fn_802E30C8(const char*, const char*);
extern const char lbl_802FD0C8[];
extern const char lbl_802FD0D8[];
extern const char lbl_80357DC0[];
void fn_80018030(void *arg0, s32 arg1) {
    s32 i;
    char *str;
    void *obj;
    void **iface;
    void ***vt;
    obj = fn_80012820(arg1);
    iface = (void **)((char *)obj + 0x80);
    vt = (void ***)*iface;
    str = ((char *(*)(void *, const char *, const char *))(*vt)[6])(iface, lbl_802FD0C8, lbl_80357DC0);
    if (str != 0 && (signed char)*str != 0) {
        fn_802E30C8(lbl_802FD0D8, str);
        for (i = 0; i < *(s32 *)((char *)arg0 + 0x24); i++) {
            *(s32 *)((char *)arg0 + i * 4 + 0x28) = *(s32 *)((char *)fn_8001668C(str, 0) + 4);
        }
    }
}

#pragma dont_inline off
void fn_800182A0(void* arg0, void* arg1) {
    s32 i;
    s32 index;
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
#pragma pop
s32 fn_800183C0(void *arg0) {
    s32 value;
    s32 (*is_one)(void) = fn_80017F40;
    if (lbl_8055D560 != 0) {
        value = fn_800167F4();
        if (value > (s32)lbl_8055D560) {
            return value;
        }
        return (s32)lbl_8055D560;
    }
    if (is_one() != 0) {
        value = fn_800167F4();
        if (value > *(s32 *)((char *)arg0 + 0x10)) {
            return value;
        }
        return *(s32 *)((char *)arg0 + 0x10);
    }
    return fn_800167F4();
}

extern void *fn_8001285C(s32);
#pragma push
#pragma dont_inline on
void fn_80018440(void *arg0, s32 arg1, void *arg2) {
    s32 count, i;
    count = fn_800183C0(fn_8001285C(arg1));
    memset(arg0, 0, 0x48);
    for (i = 0; i < count; i++) {
        s32 a = *(s32*)((char*)arg2 + (*(s32*)arg2 - 1 - i)*4 + 4);
        s32 b = *(s32*)((char*)arg2 + (*(s32*)((char*)arg2+0x24) - 1 - i)*4 + 0x28);
        *(s32*)((char*)arg0+i*4+4) = a;
        (*(s32*)arg0)++;
        *(s32*)((char*)arg0+i*4+0x28) = b;
        (*(s32*)((char*)arg0+0x24))++;
    }
}
#pragma pop

void fn_80018794(void) {
    lbl_8055D560 = (void*)atoi();
}

void fn_800187F8(void) {
    lbl_8055D564 = 1;
}

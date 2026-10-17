// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
s32 fn_802407B0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

s32 fn_802407F0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern char lbl_80342618[];
extern char lbl_803426B0[];
extern s32 lbl_8055F1F4;
extern s32 fn_80235380(s32, s32);
void *fn_802408B0(void *arg0, s32 arg1) {
    s32 temp_r4;
    if (arg0 != 0) {
        *(void **)((char *)arg0 + 0xC) = lbl_803426B0;
        *(void **)((char *)arg0 + 0x10) = lbl_803426B0 + 0x18;
        temp_r4 = lbl_8055F1F4;
        lbl_8055F1F4 = temp_r4 - 1;
        fn_80235380(*(s32 *)((char *)arg0 + 0x44), temp_r4);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern char lbl_80342734[];
extern s32 fn_802328D4(s32, s32);
void *fn_80240928(void *arg0, s32 arg1) {
    s32 zero = 0;
    if (arg0 != 0) {
        *(s32 *)((char *)arg0 + 0x24) = 0;
        *(void **)arg0 = lbl_80342734;
        *(s32 *)((char *)arg0 + 0x20) = 0;
        fn_802328D4(*(s32 *)((char *)arg0 + 0x18), 0);
        *(s32 *)((char *)arg0 + 0x18) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_802409A4(void *arg0, signed char arg1) {
    *(signed char *)((char *)arg0 + 0x2E8) = arg1;
}

void fn_802409AC(void *arg0, s32 arg1) {
    s32 i;
    void *entry;
    void *item;
    s32 count;
    count = *(s32 *)((char *)arg0 + 0x2C);
    entry = arg0;
    *(s32 *)((char *)arg0 + 0x18 + count * 4) = arg1;
    *(s32 *)((char *)arg0 + 0x2C) = count + 1;
    for (i = 0; i < *(s32 *)((char *)arg0 + 0x2C); i++) {
        item = *(void **)((char *)entry + 0x18);
        *(u8 *)item = (*(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30));
        *(s32 *)((char *)item + 4) = *(s32 *)((char *)arg0 + 0x34);
        entry = (char *)entry + 4;
    }
}

void fn_802411C8(void) { fn_8023FE20(); }

void fn_802411CC(void) { fn_8023FE34(); }

void fn_80241228(void) {
}

void fn_80241DE8(void *arg0) {
    s32 i;
    void *entry;

    for (i = 0, entry = arg0; i < *(s32 *)((char *)arg0 + 0x2C); i++, entry = (char *)entry + 4) {
        *(u8 *)*(void **)((char *)entry + 0x18) = (*(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30));
        *(s32 *)((char *)*(void **)((char *)arg0 + 0x18) + 4) = *(s32 *)((char *)arg0 + 0x34);
    }
}

s32 fn_80241E40(void *arg0) {
    s32 i;
    s32 result;
    void *entry;
    s32 value;

    value = fn_802E4A10();
    if (*(s32 *)((char *)arg0 + 0x34) != value) {
        return 0;
    }
    if (*(u8 *)((char *)arg0 + 0x38) == 0) {
        return 0;
    }
    result = 1;
    for (i = 0, entry = arg0; i < *(s32 *)((char *)arg0 + 0x2C); i++, entry = (char *)entry + 4) {
        *(u8 *)*(void **)((char *)entry + 0x18) = (*(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30));
        *(s32 *)((char *)*(void **)((char *)arg0 + 0x18) + 4) = *(s32 *)((char *)arg0 + 0x34);
    }
    return result;
}

s32 fn_80241EE8(s32 arg0) {
    return arg0 + 0x4C;
}

s32 fn_802426C0(void *arg0) {
    s32 index = *(s32 *)((char *)arg0 + 0x28);
    void *object;
    s32 count;
    struct Vtable { char pad[0x14]; s32 (*get_count)(void *); char pad2[4]; s32 (*get_item)(void *, s32); };

    if (index >= 0) {
        object = *(void **)((char *)arg0 + 0x24);
        count = ((struct Vtable *)*(void **)object)->get_count(object);
        if (index < count) {
            object = *(void **)((char *)arg0 + 0x24);
            return ((struct Vtable *)*(void **)object)->get_item(object, index);
        }
    }
    return 0;
}


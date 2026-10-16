// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
void fn_80241228(void) {
}

void fn_80241DE8(void *arg0) {
    s32 i;
    void *entry;
    s32 value;
    void *out;

    value = **(s32 **)((char *)arg0 + 0x34);
    for (i = 0, entry = arg0; i < *(s32 *)((char *)arg0 + 0x2C); i++, entry = (char *)entry + 4) {
        out = *(void **)((char *)entry + 0x18);
        *(u8 *)out = (*(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30));
        *(s32 *)((char *)out + 4) = value;
    }
}

s32 fn_80241E40(void *arg0) {
    s32 i;
    void *entry;
    s32 value;
    void *out;

    if (**(s32 **)((char *)arg0 + 0x34) != fn_802E4A10()) {
        return 0;
    }
    if (*(u8 *)((char *)arg0 + 0x38) == 0) {
        return 0;
    }
    for (i = 0, entry = arg0; i < *(s32 *)((char *)arg0 + 0x2C); i++, entry = (char *)entry + 4) {
        value = **(s32 **)((char *)arg0 + 0x34);
        out = *(void **)((char *)entry + 0x18);
        *(u8 *)out = (*(u8 *)((char *)arg0 + 0x38) != 0 && i == *(s32 *)((char *)arg0 + 0x30));
        *(s32 *)((char *)out + 4) = value;
    }
    return 1;
}

s32 fn_80241EE8(s32 arg0) {
    return arg0 + 0x4C;
}

s32 fn_802426C0(void *arg0) {
    s32 index = *(s32 *)((char *)arg0 + 0x28);
    void *object;
    void **vtable;
    s32 count;

    if (index >= 0) {
        object = *(void **)((char *)arg0 + 0x24);
        vtable = *(void ***)object;
        count = ((s32 (*)(void *))vtable[5])(object);
        if (index < count) {
            object = *(void **)((char *)arg0 + 0x24);
            vtable = *(void ***)object;
            return ((s32 (*)(void *, s32))vtable[7])(object, index);
        }
    }
    return 0;
}


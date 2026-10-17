// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef unsigned char u8;
typedef signed int s32;
extern s32 fn_80296D28(s32);
extern s32 fn_80128668(void *);
extern s32 fn_8002F6AC(s32, void *);
extern s32 fn_80297654;
extern char lbl_803493C0[];
extern float lbl_80564578;

extern void *fn_801284F8(s32, const char *);
extern s32 fn_80296B10(s32, s32);
extern char lbl_80349368[];
extern char lbl_80349378[];
__declspec(section ".sdata") extern char lbl_8055CA30[];
void *fn_802971B0(void *arg0) {
    s32 value;
    void *obj;
    obj = fn_801284F8(8, lbl_80349368);
    if (obj != 0) {
        *(void **)obj = &lbl_803493C0;
        value = ((s32 (*)(void *, char *))(*(void **)(*(void ***)arg0 + 5)))(arg0, lbl_80349378);
        *(s32 *)((u8 *)obj + 4) = fn_80296B10(value,
            ((s32 (*)(void *, char *))(*(void **)(*(void ***)arg0 + 23)))(arg0, lbl_8055CA30));
    }
    if (obj != 0 && ((s32 (*)(void *))(*(void **)(*(void ***)obj + 3)))(obj) == 0) {
        if (obj != 0)
            ((void (*)(void *, s32))(*(void **)(*(void ***)obj + 2)))(obj, 1);
        obj = 0;
    }
    return obj;
}

float fn_8029748C(void *arg0) {
    s32 count = *(s32 *)((u8 *)arg0 + 4);
    float max = lbl_80564578;
    s32 offset = 0;
    while (count > 0) {
        float value = *(float *)(*(u8 **)arg0 + offset + 0x14);
        if (max <= value) max = value;
        offset += 0x18;
        count--;
    }
    return max;
}

void fn_802976D0(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
}

void fn_802976DC(s32 *arg0) {
    fn_8002F6AC(*arg0, &fn_80297654);
    fn_80128668(arg0);
}

s32 fn_8029771C(void *arg0, void *arg1, float arg2) {
    s32 i;
    s32 offset;
    u8 *entry;
    float a, b, c;

    offset = 0;
    i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        entry = *(u8 **)arg0 + offset;
        if (arg2 >= *(float *)entry && arg2 <= *(float *)(entry + 0x14)) {
            a = *(float *)arg1 + *(float *)(entry + 4);
            b = *(float *)((u8 *)arg1 + 4) + *(float *)(entry + 8);
            c = *(float *)((u8 *)arg1 + 8) + *(float *)(entry + 0xc);
            ((void (*)(void *, float *, float))(*(void (***)(void))*(void **)(entry + 0x10))[5])(*(void **)(entry + 0x10), &a, arg2 - *(float *)entry);
        }
        offset += 0x18;
        i++;
    }
    return arg2 < *(float *)((u8 *)arg0 + 8);
}

void *fn_80297814(void *arg0, s32 arg1) {
    s32 value;
    if (arg0 != 0) {
        value = *(s32 *)((u8 *)arg0 + 4);
        *(void **)arg0 = &lbl_803493C0;
        if (value != 0) fn_80296D28(value);
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_8029788C(void *arg0) {
    s32 val = *(s32 *)((u8 *)arg0 + 4);
    s32 neg = -val;
    return (neg | val) >> 31 & 1;
}

extern s32 fn_80296D2C(s32);
extern s32 fn_802970C8(s32);
extern float lbl_80564578;
extern char lbl_8055CA40[];
extern char *lbl_8055CA38[];
extern char lbl_80349384[];
extern int stricmp(const char *, const char *);
extern int fn_802E317C(char *, ...);
s32 fn_802978A0(void *arg0) {
    return fn_80296D2C(*(s32 *)((u8 *)arg0 + 4));
}

s32 fn_802978A8(void *arg0) {
    return fn_802970C8(*(s32 *)((u8 *)arg0 + 4));
}


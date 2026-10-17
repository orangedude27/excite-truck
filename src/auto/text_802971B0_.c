// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef unsigned char u8;
typedef signed int s32;
extern s32 fn_80296D28(s32);
extern s32 fn_80128668(void *);
extern s32 fn_8002F6AC(s32, void *);
extern s32 fn_80297654;
extern void *lbl_803493C0;
extern float lbl_80564578;

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


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef unsigned char u8;
typedef signed int s32;
extern s32 fn_80296D28(s32);
extern s32 fn_80128668(void *);
extern s32 fn_8002F6AC(s32, void *);
extern s32 fn_80297654;
extern void *lbl_803493C0;

s32 fn_8029788C(void *arg0) {
    s32 val = *(s32 *)((u8 *)arg0 + 4);
    s32 neg = -val;
    return (neg | val) >> 31 & 1;
}

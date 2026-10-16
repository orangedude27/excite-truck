// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 fn_80128668(void);
extern void fn_8000BF20(void *);
extern void fn_8000C0E8(void);
extern u8 lbl_803413A8[];
void fn_8023B8AC(s32 arg0) {
    fn_8000ABE0();
    fn_800126C0(arg0, arg0 + 0x3F8);
    fn_80244738();
    fn_8023B77C();
    fn_80211F44();
    if (fn_80019B3C() == 0) fn_8027B690();
    fn_8020A600();
}

void fn_8023B904(void *arg0, void *dest, s32 flag) {
    if (flag == 0) {
        u8 *p = lbl_803413A8;
        fn_8000BF20(&p);
        if (dest != 0) {
            *(s32 *)((u8 *)dest) = *(s32 *)(p + 0);
            *(s32 *)((u8 *)dest + 4) = *(s32 *)(p + 4);
            *(s32 *)((u8 *)dest + 8) = *(s32 *)(p + 8);
            *(u8 *)((u8 *)dest + 0xC) = p[0xC];
            *(u8 *)((u8 *)dest + 0xD) = p[0xD];
            *(u8 *)((u8 *)dest + 0xE) = p[0xE];
            __builtin_memcpy((u8 *)dest + 0x10, p + 0x10, 0xA0);
        }
    } else fn_8000C0E8();
}

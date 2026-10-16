typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
extern void fn_802E317C(const char *, s32, s32, s32);
extern char lbl_8034CF40[];
extern char lbl_8034CF60[];
extern char lbl_804DB810[];
extern s32 fn_802E32C4();
extern s32 lbl_8055FF18;
extern s32 fn_802E333C(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FF24;
s32 fn_802E98C8(void);
s32 fn_802E333C(void) {
    s32 value = fn_802E32C4();
    if (value != 0) return value;
    return lbl_8055FF18;
}

void fn_802E339C(void) {
    s32 *p = (s32 *)fn_802E333C();
    ((void (*)(void))(*(s32 **)((char *)*p + 0x24)))();
}

s32 fn_802E33D0(void) { return 0; }

void fn_802E3498(void) {
    memset(lbl_804DB810, 0, 0x280);
    if (lbl_8055FF18 == 0) {
        lbl_8055FF18 = fn_802E3F94();
    }
}

void fn_802E3DCC(void) {
    lbl_8055FF24 = (void*)fn_802E98C8();
}


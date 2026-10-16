typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FF24;
s32 fn_802E98C8(void);
s32 fn_802E33D0(void) { return 0; }

void fn_802E3DCC(void) {
    lbl_8055FF24 = (void*)fn_802E98C8();
}

